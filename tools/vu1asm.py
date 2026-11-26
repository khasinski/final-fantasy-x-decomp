#!/usr/bin/env python3
"""PlayStation 2 VU1 microcode disassembler and assembler for FFX PAL (SCES_504.90).

Zero-dependency Python 3 tool supporting the complete PS2 VU1 64-bit VLIW ISA
(32-bit Upper + 32-bit Lower / LOI float immediate), symbolic branch labels,
and EE DMA/VIF packet directives (.dma_ref, .dma_next, .dma_cnt, .dma_end,
.vif_nop, .vif_flush, .vif_mpg, .pad).

Usage:
  python3 tools/vu1asm.py disasm assets/vutext.bin vu/
  python3 tools/vu1asm.py build vu/vu1_prog1.vsm vu/vu1_prog2.vsm -o build/vu/vutext.bin
  python3 tools/vu1asm.py verify vu/vu1_prog1.vsm vu/vu1_prog2.vsm assets/vutext.bin
"""

import hashlib
import os
import re
import struct
import sys

# ---------------------------------------------------------------------------
# PS2 VU1 ISA Tables
# ---------------------------------------------------------------------------

BC_CHARS = "xyzw"
FLAG_BITS = [
    ("I", 31),
    ("E", 30),
    ("M", 29),
    ("D", 28),
    ("T", 27),
]


def fmt_dest(dest: int) -> str:
    s = ""
    if dest & 8:
        s += "x"
    if dest & 4:
        s += "y"
    if dest & 2:
        s += "z"
    if dest & 1:
        s += "w"
    return s


def parse_dest(s: str) -> int:
    if not s:
        return 0
    dest = 0
    for ch in s:
        if ch == "x":
            dest |= 8
        elif ch == "y":
            dest |= 4
        elif ch == "z":
            dest |= 2
        elif ch == "w":
            dest |= 1
        else:
            raise ValueError(f"Invalid dest mask character: {ch!r}")
    return dest


def fmt_flags(hi: int) -> str:
    fl = "".join(name for name, bit in FLAG_BITS if (hi >> bit) & 1)
    return f"[{fl}]" if fl else ""


def parse_flags(fl: str) -> int:
    bits = 0
    for ch in fl:
        for name, bit in FLAG_BITS:
            if ch == name:
                bits |= 1 << bit
                break
        else:
            raise ValueError(f"Invalid Upper flag: {ch!r}")
    return bits


def sext(val: int, bits: int) -> int:
    sign = 1 << (bits - 1)
    return (val & (sign - 1)) - (val & sign)


def vf(n: int) -> str:
    return f"vf{n:02d}"


def vi(n: int) -> str:
    return f"vi{n:02d}"


def parse_vf(tok: str) -> int:
    m = re.fullmatch(r"vf(\d+)", tok.lower())
    if not m:
        raise ValueError(f"Expected vf register, got {tok!r}")
    n = int(m.group(1))
    if not (0 <= n <= 31):
        raise ValueError(f"vf register out of range: {tok!r}")
    return n


def parse_vi(tok: str) -> int:
    m = re.fullmatch(r"vi(\d+)", tok.lower())
    if not m:
        raise ValueError(f"Expected vi register, got {tok!r}")
    n = int(m.group(1))
    if not (0 <= n <= 15):
        raise ValueError(f"vi register out of range: {tok!r}")
    return n


def parse_vf_field(tok: str) -> tuple[int, int]:
    m = re.fullmatch(r"vf(\d+)\.?([xyzw])", tok.lower())
    if not m:
        raise ValueError(f"Expected vf register with field (e.g. vf01x), got {tok!r}")
    n = int(m.group(1))
    if not (0 <= n <= 31):
        raise ValueError(f"vf register out of range: {tok!r}")
    return n, BC_CHARS.index(m.group(2))


def parse_int(tok: str) -> int:
    return int(tok.strip(), 0)


# Upper normal opcodes (bits 5..0 < 0x3c)
# kind:
#   "3r":  fd, fs, ft
#   "q":   fd, fs, Q
#   "i":   fd, fs, I
UPPER_NORM_DEC: dict[int, tuple[str, str]] = {
    0x00: ("ADDx", "3r"), 0x01: ("ADDy", "3r"), 0x02: ("ADDz", "3r"), 0x03: ("ADDw", "3r"),
    0x04: ("SUBx", "3r"), 0x05: ("SUBy", "3r"), 0x06: ("SUBz", "3r"), 0x07: ("SUBw", "3r"),
    0x08: ("MADDx", "3r"), 0x09: ("MADDy", "3r"), 0x0A: ("MADDz", "3r"), 0x0B: ("MADDw", "3r"),
    0x0C: ("MSUBx", "3r"), 0x0D: ("MSUBy", "3r"), 0x0E: ("MSUBz", "3r"), 0x0F: ("MSUBw", "3r"),
    0x10: ("MAXx", "3r"), 0x11: ("MAXy", "3r"), 0x12: ("MAXz", "3r"), 0x13: ("MAXw", "3r"),
    0x14: ("MINIx", "3r"), 0x15: ("MINIy", "3r"), 0x16: ("MINIz", "3r"), 0x17: ("MINIw", "3r"),
    0x18: ("MULx", "3r"), 0x19: ("MULy", "3r"), 0x1A: ("MULz", "3r"), 0x1B: ("MULw", "3r"),
    0x1C: ("MULq", "q"),
    0x1D: ("MAXi", "i"),
    0x1E: ("MULi", "i"),
    0x1F: ("MINIi", "i"),
    0x20: ("ADDq", "q"),
    0x21: ("MADDq", "q"),
    0x22: ("ADDi", "i"),
    0x23: ("MADDi", "i"),
    0x24: ("SUBq", "q"),
    0x25: ("MSUBq", "q"),
    0x26: ("SUBi", "i"),
    0x27: ("MSUBi", "i"),
    0x28: ("ADD", "3r"),
    0x29: ("MADD", "3r"),
    0x2A: ("MUL", "3r"),
    0x2B: ("MAX", "3r"),
    0x2C: ("SUB", "3r"),
    0x2D: ("MSUB", "3r"),
    0x2E: ("OPMSUB", "3r"),
    0x2F: ("MINI", "3r"),
}
UPPER_NORM_ENC = {mnem.upper(): (op, kind) for op, (mnem, kind) in UPPER_NORM_DEC.items()}

# Upper special opcodes (op in 0x3c..0x3f, keyed by (fd, op))
# kind:
#   "acc2": ACC, fs, ft
#   "accq": ACC, fs, Q
#   "acci": ACC, fs, I
#   "2r":   ft, fs
#   "clip": fs, ft
#   "nop":  (none)
UPPER_SPEC_DEC: dict[tuple[int, int], tuple[str, str]] = {
    (0x00, 0x3C): ("ADDAx", "acc2"), (0x00, 0x3D): ("ADDAy", "acc2"),
    (0x00, 0x3E): ("ADDAz", "acc2"), (0x00, 0x3F): ("ADDAw", "acc2"),
    (0x01, 0x3C): ("SUBAx", "acc2"), (0x01, 0x3D): ("SUBAy", "acc2"),
    (0x01, 0x3E): ("SUBAz", "acc2"), (0x01, 0x3F): ("SUBAw", "acc2"),
    (0x02, 0x3C): ("MADDAx", "acc2"), (0x02, 0x3D): ("MADDAy", "acc2"),
    (0x02, 0x3E): ("MADDAz", "acc2"), (0x02, 0x3F): ("MADDAw", "acc2"),
    (0x03, 0x3C): ("MSUBAx", "acc2"), (0x03, 0x3D): ("MSUBAy", "acc2"),
    (0x03, 0x3E): ("MSUBAz", "acc2"), (0x03, 0x3F): ("MSUBAw", "acc2"),
    (0x04, 0x3C): ("ITOF0", "2r"), (0x04, 0x3D): ("ITOF4", "2r"),
    (0x04, 0x3E): ("ITOF12", "2r"), (0x04, 0x3F): ("ITOF15", "2r"),
    (0x05, 0x3C): ("FTOI0", "2r"), (0x05, 0x3D): ("FTOI4", "2r"),
    (0x05, 0x3E): ("FTOI12", "2r"), (0x05, 0x3F): ("FTOI15", "2r"),
    (0x06, 0x3C): ("MULAx", "acc2"), (0x06, 0x3D): ("MULAy", "acc2"),
    (0x06, 0x3E): ("MULAz", "acc2"), (0x06, 0x3F): ("MULAw", "acc2"),
    (0x07, 0x3C): ("MULAq", "accq"), (0x07, 0x3D): ("ABS", "2r"),
    (0x07, 0x3E): ("MULAi", "acci"), (0x07, 0x3F): ("CLIPw", "clip"),
    (0x08, 0x3C): ("ADDAq", "accq"), (0x08, 0x3D): ("MADDAq", "accq"),
    (0x08, 0x3E): ("ADDAi", "acci"), (0x08, 0x3F): ("MADDAi", "acci"),
    (0x09, 0x3C): ("SUBAq", "accq"), (0x09, 0x3D): ("MSUBAq", "accq"),
    (0x09, 0x3E): ("SUBAi", "acci"), (0x09, 0x3F): ("MSUBAi", "acci"),
    (0x0A, 0x3C): ("ADDA", "acc2"), (0x0A, 0x3D): ("MADDA", "acc2"),
    (0x0A, 0x3E): ("MULA", "acc2"),
    (0x0B, 0x3C): ("SUBA", "acc2"), (0x0B, 0x3D): ("MSUBA", "acc2"),
    (0x0B, 0x3E): ("OPMULA", "acc2"), (0x0B, 0x3F): ("NOP", "nop"),
}
UPPER_SPEC_ENC = {mnem.upper(): (fd, op, kind) for (fd, op), (mnem, kind) in UPPER_SPEC_DEC.items()}


# ---------------------------------------------------------------------------
# Disassembly
# ---------------------------------------------------------------------------

def disasm_upper(hi: int) -> str:
    if (hi >> 25) & 3:
        raise ValueError(f"Upper reserved bits 26..25 non-zero: 0x{hi:08x}")
    flags = fmt_flags(hi)
    dest = (hi >> 21) & 0xF
    ft = (hi >> 16) & 0x1F
    fs = (hi >> 11) & 0x1F
    fd = (hi >> 6) & 0x1F
    op = hi & 0x3F
    dstr = fmt_dest(dest)

    if op < 0x3C:
        if op not in UPPER_NORM_DEC:
            raise ValueError(f"Unknown Upper opcode 0x{op:02x} in 0x{hi:08x}")
        mnem, kind = UPPER_NORM_DEC[op]
        head = f"{mnem}.{dstr}{flags}" if dstr else f"{mnem}{flags}"
        if kind == "3r":
            return f"{head} {vf(fd)}, {vf(fs)}, {vf(ft)}"
        elif kind == "q":
            return f"{head} {vf(fd)}, {vf(fs)}, Q"
        elif kind == "i":
            return f"{head} {vf(fd)}, {vf(fs)}, I"
        raise AssertionError(kind)

    key = (fd, op)
    if key not in UPPER_SPEC_DEC:
        raise ValueError(f"Unknown Upper special (fd=0x{fd:02x}, op=0x{op:02x}) in 0x{hi:08x}")
    mnem, kind = UPPER_SPEC_DEC[key]
    if kind == "nop":
        if dest or ft or fs:
            raise ValueError(f"Non-canonical Upper NOP: 0x{hi:08x}")
        return f"NOP{flags}"
    head = f"{mnem}.{dstr}{flags}" if dstr else f"{mnem}{flags}"
    if kind == "acc2":
        return f"{head} ACC, {vf(fs)}, {vf(ft)}"
    elif kind == "accq":
        return f"{head} ACC, {vf(fs)}, Q"
    elif kind == "acci":
        return f"{head} ACC, {vf(fs)}, I"
    elif kind == "2r":
        return f"{head} {vf(ft)}, {vf(fs)}"
    elif kind == "clip":
        return f"{head} {vf(fs)}, {vf(ft)}"
    raise AssertionError(kind)


def fmt_loi(lo: int) -> str:
    fval = struct.unpack("<f", struct.pack("<I", lo))[0]
    # Check if repr(fval) round-trips bit-for-bit
    s = repr(fval)
    try:
        rt = struct.unpack("<I", struct.pack("<f", float(s)))[0]
        if rt == lo:
            return f"LOI {s}"
    except (ValueError, OverflowError):
        pass
    return f"LOI 0x{lo:08x}"


def branch_target(lo: int, pc: int) -> int | None:
    lop = (lo >> 25) & 0x7F
    if lop in (0x20, 0x21, 0x28, 0x29, 0x2C, 0x2D, 0x2E, 0x2F):
        off = sext(lo & 0x7FF, 11)
        return pc + 1 + off
    return None


def disasm_lower(lo: int, hi: int, pc: int, labels: dict[int, str]) -> str:
    if (hi >> 31) & 1:
        return fmt_loi(lo)

    lop = (lo >> 25) & 0x7F
    dest = (lo >> 21) & 0xF
    ft = (lo >> 16) & 0x1F
    fs = (lo >> 11) & 0x1F
    fd = (lo >> 6) & 0x1F
    op = lo & 0x3F
    imm11 = sext(lo & 0x7FF, 11)
    dstr = fmt_dest(dest)

    def lbl(target_pc: int) -> str:
        return labels.get(target_pc, str(target_pc - (pc + 1)))

    if lop == 0x00:  # LQ
        return f"LQ.{dstr} {vf(ft)}, {imm11}({vi(fs)})"
    if lop == 0x01:  # SQ
        return f"SQ.{dstr} {vf(fs)}, {imm11}({vi(ft)})"
    if lop == 0x04:  # ILW
        return f"ILW.{dstr} {vi(ft)}, {imm11}({vi(fs)})"
    if lop == 0x05:  # ISW
        return f"ISW.{dstr} {vi(ft)}, {imm11}({vi(fs)})"
    if lop == 0x08:  # IADDIU
        imm15 = ((lo >> 21) & 0xF) << 11 | (lo & 0x7FF)
        return f"IADDIU {vi(ft)}, {vi(fs)}, 0x{imm15:04x}"
    if lop == 0x09:  # ISUBIU
        imm15 = ((lo >> 21) & 0xF) << 11 | (lo & 0x7FF)
        return f"ISUBIU {vi(ft)}, {vi(fs)}, 0x{imm15:04x}"
    if lop == 0x10:  # FCEQ
        return f"FCEQ vi01, 0x{lo & 0xFFFFFF:06x}"
    if lop == 0x11:  # FCSET
        return f"FCSET 0x{lo & 0xFFFFFF:06x}"
    if lop == 0x12:  # FCAND
        return f"FCAND vi01, 0x{lo & 0xFFFFFF:06x}"
    if lop == 0x13:  # FCOR
        return f"FCOR vi01, 0x{lo & 0xFFFFFF:06x}"
    if lop == 0x14:  # FSEQ
        imm12 = (((lo >> 21) & 1) << 11) | (lo & 0x7FF)
        return f"FSEQ {vi(ft)}, 0x{imm12:03x}"
    if lop == 0x15:  # FSSET
        imm12 = (((lo >> 21) & 1) << 11) | (lo & 0x7FF)
        return f"FSSET 0x{imm12:03x}"
    if lop == 0x16:  # FSAND
        imm12 = (((lo >> 21) & 1) << 11) | (lo & 0x7FF)
        return f"FSAND {vi(ft)}, 0x{imm12:03x}"
    if lop == 0x17:  # FSOR
        imm12 = (((lo >> 21) & 1) << 11) | (lo & 0x7FF)
        return f"FSOR {vi(ft)}, 0x{imm12:03x}"
    if lop == 0x18:  # FMEQ
        return f"FMEQ {vi(ft)}, {vi(fs)}"
    if lop == 0x1A:  # FMAND
        return f"FMAND {vi(ft)}, {vi(fs)}"
    if lop == 0x1B:  # FMOR
        return f"FMOR {vi(ft)}, {vi(fs)}"
    if lop == 0x1C:  # FCGET
        return f"FCGET {vi(ft)}"
    if lop == 0x20:  # B
        return f"B {lbl(pc + 1 + imm11)}"
    if lop == 0x21:  # BAL
        return f"BAL {vi(ft)}, {lbl(pc + 1 + imm11)}"
    if lop == 0x24:  # JR
        return f"JR {vi(fs)}"
    if lop == 0x25:  # JALR
        return f"JALR {vi(ft)}, {vi(fs)}"
    if lop == 0x28:  # IBEQ
        return f"IBEQ {vi(ft)}, {vi(fs)}, {lbl(pc + 1 + imm11)}"
    if lop == 0x29:  # IBNE
        return f"IBNE {vi(ft)}, {vi(fs)}, {lbl(pc + 1 + imm11)}"
    if lop == 0x2C:  # IBLTZ
        return f"IBLTZ {vi(fs)}, {lbl(pc + 1 + imm11)}"
    if lop == 0x2D:  # IBGTZ
        return f"IBGTZ {vi(fs)}, {lbl(pc + 1 + imm11)}"
    if lop == 0x2E:  # IBLEZ
        return f"IBLEZ {vi(fs)}, {lbl(pc + 1 + imm11)}"
    if lop == 0x2F:  # IBGEZ
        return f"IBGEZ {vi(fs)}, {lbl(pc + 1 + imm11)}"

    if lop == 0x40:
        if op == 0x30:
            return f"IADD {vi(fd)}, {vi(fs)}, {vi(ft)}"
        if op == 0x31:
            return f"ISUB {vi(fd)}, {vi(fs)}, {vi(ft)}"
        if op == 0x32:
            imm5 = sext(fd, 5)
            return f"IADDI {vi(ft)}, {vi(fs)}, {imm5}"
        if op == 0x34:
            return f"IAND {vi(fd)}, {vi(fs)}, {vi(ft)}"
        if op == 0x35:
            return f"IOR {vi(fd)}, {vi(fs)}, {vi(ft)}"

        if op >= 0x3C:
            fsf = (lo >> 21) & 3
            ftf = (lo >> 23) & 3
            key = (fd, op)
            if key == (0x0C, 0x3C):
                if lo == 0x8000033C:
                    return "NOP"
                return f"MOVE.{dstr} {vf(ft)}, {vf(fs)}"
            if key == (0x0C, 0x3D):
                return f"MR32.{dstr} {vf(ft)}, {vf(fs)}"
            if key == (0x0D, 0x3C):
                return f"LQI.{dstr} {vf(ft)}, ({vi(fs)}++)"
            if key == (0x0D, 0x3D):
                return f"SQI.{dstr} {vf(fs)}, ({vi(ft)}++)"
            if key == (0x0D, 0x3E):
                return f"LQD.{dstr} {vf(ft)}, (--{vi(fs)})"
            if key == (0x0D, 0x3F):
                return f"SQD.{dstr} {vf(fs)}, (--{vi(ft)})"
            if key == (0x0E, 0x3C):
                return f"DIV Q, {vf(fs)}{BC_CHARS[fsf]}, {vf(ft)}{BC_CHARS[ftf]}"
            if key == (0x0E, 0x3D):
                return f"SQRT Q, {vf(ft)}{BC_CHARS[ftf]}"
            if key == (0x0E, 0x3E):
                return f"RSQRT Q, {vf(fs)}{BC_CHARS[fsf]}, {vf(ft)}{BC_CHARS[ftf]}"
            if key == (0x0E, 0x3F):
                return "WAITQ"
            if key == (0x0F, 0x3C):
                return f"MTIR {vi(ft)}, {vf(fs)}{BC_CHARS[fsf]}"
            if key == (0x0F, 0x3D):
                return f"MFIR.{dstr} {vf(ft)}, {vi(fs)}"
            if key == (0x0F, 0x3E):
                return f"ILWR.{dstr} {vi(ft)}, ({vi(fs)})"
            if key == (0x0F, 0x3F):
                return f"ISWR.{dstr} {vi(ft)}, ({vi(fs)})"
            if key == (0x10, 0x3C):
                return f"RNEXT.{dstr} {vf(ft)}, R"
            if key == (0x10, 0x3D):
                return f"RGET.{dstr} {vf(ft)}, R"
            if key == (0x10, 0x3E):
                return f"RINIT R, {vf(fs)}{BC_CHARS[fsf]}"
            if key == (0x10, 0x3F):
                return f"RXOR R, {vf(fs)}{BC_CHARS[fsf]}"
            if key == (0x19, 0x3C):
                return f"MFP.{dstr} {vf(ft)}, P"
            if key == (0x1A, 0x3C):
                return f"XTOP {vi(ft)}"
            if key == (0x1A, 0x3D):
                return f"XITOP {vi(ft)}"
            if key == (0x1B, 0x3C):
                return f"XGKICK {vi(fs)}"
            if key == (0x1C, 0x3C):
                return f"ESADD P, {vf(fs)}"
            if key == (0x1C, 0x3D):
                return f"ERSADD P, {vf(fs)}"
            if key == (0x1C, 0x3E):
                return f"ELENG P, {vf(fs)}"
            if key == (0x1C, 0x3F):
                return f"ERLENG P, {vf(fs)}"
            if key == (0x1D, 0x3C):
                return f"EATANxy P, {vf(fs)}"
            if key == (0x1D, 0x3D):
                return f"EATANxz P, {vf(fs)}"
            if key == (0x1D, 0x3E):
                return f"ESUM P, {vf(fs)}"
            if key == (0x1D, 0x3F):
                return f"ERCPR P, {vf(fs)}{BC_CHARS[fsf]}"
            if key == (0x1E, 0x3C):
                return f"ESQRT P, {vf(fs)}{BC_CHARS[fsf]}"
            if key == (0x1E, 0x3D):
                return f"ERSQRT P, {vf(fs)}{BC_CHARS[fsf]}"
            if key == (0x1E, 0x3E):
                return f"ESIN P, {vf(fs)}{BC_CHARS[fsf]}"
            if key == (0x1E, 0x3F):
                return f"EATAN P, {vf(fs)}{BC_CHARS[fsf]}"
            if key == (0x1F, 0x3C):
                return f"EEXP P, {vf(fs)}{BC_CHARS[fsf]}"
            if key == (0x1F, 0x3F):
                return "WAITP"

    raise ValueError(f"Unknown Lower instruction 0x{lo:08x} (lop=0x{lop:02x}, fd=0x{fd:02x}, op=0x{op:02x})")


# ---------------------------------------------------------------------------
# Assembly
# ---------------------------------------------------------------------------

UPPER_HEAD_RE = re.compile(r"^([A-Za-z0-9]+)(?:\.([xyzw]+))?(?:\[([IEMDT]+)\])?$")
LOWER_HEAD_RE = re.compile(r"^([A-Za-z0-9]+)(?:\.([xyzw]+))?$")


def split_ops(s: str) -> list[str]:
    s = s.strip()
    if not s:
        return []
    return [p.strip() for p in s.split(",")]


def asm_upper(text: str) -> int:
    parts = text.strip().split(None, 1)
    if not parts:
        raise ValueError("Empty Upper instruction")
    head = parts[0]
    ops = split_ops(parts[1]) if len(parts) > 1 else []
    m = UPPER_HEAD_RE.match(head)
    if not m:
        raise ValueError(f"Malformed Upper mnemonic: {head!r}")
    mnem = m.group(1).upper()
    dest = parse_dest(m.group(2) or "")
    flags = parse_flags(m.group(3) or "")

    if mnem in UPPER_NORM_ENC:
        op, kind = UPPER_NORM_ENC[mnem]
        if kind == "3r":
            if len(ops) != 3:
                raise ValueError(f"{mnem} expects 3 operands, got {ops}")
            fd, fs, ft = parse_vf(ops[0]), parse_vf(ops[1]), parse_vf(ops[2])
        elif kind == "q":
            if len(ops) != 3 or ops[2].upper() != "Q":
                raise ValueError(f"{mnem} expects (fd, fs, Q), got {ops}")
            fd, fs, ft = parse_vf(ops[0]), parse_vf(ops[1]), 0
        elif kind == "i":
            if len(ops) != 3 or ops[2].upper() != "I":
                raise ValueError(f"{mnem} expects (fd, fs, I), got {ops}")
            fd, fs, ft = parse_vf(ops[0]), parse_vf(ops[1]), 0
        else:
            raise AssertionError(kind)
        return flags | (dest << 21) | (ft << 16) | (fs << 11) | (fd << 6) | op

    if mnem in UPPER_SPEC_ENC:
        fd, op, kind = UPPER_SPEC_ENC[mnem]
        if kind == "nop":
            if ops or dest:
                raise ValueError(f"Upper NOP takes no dest/operands, got {text!r}")
            return flags | (fd << 6) | op
        elif kind == "acc2":
            if len(ops) != 3 or ops[0].upper() != "ACC":
                raise ValueError(f"{mnem} expects (ACC, fs, ft), got {ops}")
            fs, ft = parse_vf(ops[1]), parse_vf(ops[2])
        elif kind == "accq":
            if len(ops) != 3 or ops[0].upper() != "ACC" or ops[2].upper() != "Q":
                raise ValueError(f"{mnem} expects (ACC, fs, Q), got {ops}")
            fs, ft = parse_vf(ops[1]), 0
        elif kind == "acci":
            if len(ops) != 3 or ops[0].upper() != "ACC" or ops[2].upper() != "I":
                raise ValueError(f"{mnem} expects (ACC, fs, I), got {ops}")
            fs, ft = parse_vf(ops[1]), 0
        elif kind == "2r":
            if len(ops) != 2:
                raise ValueError(f"{mnem} expects (ft, fs), got {ops}")
            ft, fs = parse_vf(ops[0]), parse_vf(ops[1])
        elif kind == "clip":
            if len(ops) != 2:
                raise ValueError(f"{mnem} expects (fs, ft), got {ops}")
            fs, ft = parse_vf(ops[0]), parse_vf(ops[1])
        else:
            raise AssertionError(kind)
        return flags | (dest << 21) | (ft << 16) | (fs << 11) | (fd << 6) | op

    raise ValueError(f"Unknown Upper mnemonic: {mnem!r}")


def parse_mem_op(tok: str) -> tuple[int, int]:
    m = re.fullmatch(r"(-?(?:0x[0-9a-fA-F]+|\d+))\s*\(\s*(vi\d+)\s*\)", tok.strip(), re.IGNORECASE)
    if not m:
        raise ValueError(f"Expected imm11(viXX), got {tok!r}")
    imm = parse_int(m.group(1))
    reg = parse_vi(m.group(2))
    if not (-1024 <= imm <= 1023):
        raise ValueError(f"imm11 out of range: {imm}")
    return imm & 0x7FF, reg


def resolve_branch(tok: str, pc: int, labels: dict[str, int]) -> int:
    tok = tok.strip()
    if tok in labels:
        off = labels[tok] - (pc + 1)
    else:
        off = parse_int(tok)
    if not (-1024 <= off <= 1023):
        raise ValueError(f"Branch offset out of 11-bit signed range for {tok!r}: {off}")
    return off & 0x7FF


def asm_lower(text: str, hi: int, pc: int, labels: dict[str, int]) -> int:
    parts = text.strip().split(None, 1)
    if not parts:
        raise ValueError("Empty Lower instruction")
    head = parts[0]
    ops = split_ops(parts[1]) if len(parts) > 1 else []
    m = LOWER_HEAD_RE.match(head)
    if not m:
        raise ValueError(f"Malformed Lower mnemonic: {head!r}")
    mnem = m.group(1).upper()
    dest = parse_dest(m.group(2) or "")

    if mnem == "LOI":
        if not ((hi >> 31) & 1):
            raise ValueError("LOI requires [I] flag on Upper instruction")
        if len(ops) != 1:
            raise ValueError(f"LOI expects 1 operand, got {ops}")
        tok = ops[0]
        if tok.lower().startswith("0x"):
            return int(tok, 16) & 0xFFFFFFFF
        return struct.unpack("<I", struct.pack("<f", float(tok)))[0]

    if (hi >> 31) & 1:
        raise ValueError(f"Upper has [I] flag set, expected LOI in Lower, got {text!r}")

    if mnem == "NOP":
        return 0x8000033C
    if mnem == "LQ":
        ft = parse_vf(ops[0])
        imm11, is_r = parse_mem_op(ops[1])
        return (0x00 << 25) | (dest << 21) | (ft << 16) | (is_r << 11) | imm11
    if mnem == "SQ":
        fs = parse_vf(ops[0])
        imm11, it_r = parse_mem_op(ops[1])
        return (0x01 << 25) | (dest << 21) | (it_r << 16) | (fs << 11) | imm11
    if mnem == "ILW":
        it_r = parse_vi(ops[0])
        imm11, is_r = parse_mem_op(ops[1])
        return (0x04 << 25) | (dest << 21) | (it_r << 16) | (is_r << 11) | imm11
    if mnem == "ISW":
        it_r = parse_vi(ops[0])
        imm11, is_r = parse_mem_op(ops[1])
        return (0x05 << 25) | (dest << 21) | (it_r << 16) | (is_r << 11) | imm11
    if mnem in ("IADDIU", "ISUBIU"):
        lop = 0x08 if mnem == "IADDIU" else 0x09
        it_r, is_r, imm15 = parse_vi(ops[0]), parse_vi(ops[1]), parse_int(ops[2])
        if not (0 <= imm15 <= 0x7FFF):
            raise ValueError(f"{mnem} imm15 out of range: {imm15}")
        return (lop << 25) | (((imm15 >> 11) & 0xF) << 21) | (it_r << 16) | (is_r << 11) | (imm15 & 0x7FF)
    if mnem in ("FCEQ", "FCAND", "FCOR"):
        lop = {"FCEQ": 0x10, "FCAND": 0x12, "FCOR": 0x13}[mnem]
        if parse_vi(ops[0]) != 1:
            raise ValueError(f"{mnem} destination must be vi01")
        imm24 = parse_int(ops[1]) & 0xFFFFFF
        return (lop << 25) | imm24
    if mnem == "FCSET":
        imm24 = parse_int(ops[0]) & 0xFFFFFF
        return (0x11 << 25) | imm24
    if mnem in ("FSEQ", "FSAND", "FSOR"):
        lop = {"FSEQ": 0x14, "FSAND": 0x16, "FSOR": 0x17}[mnem]
        it_r, imm12 = parse_vi(ops[0]), parse_int(ops[1]) & 0xFFF
        return (lop << 25) | (((imm12 >> 11) & 1) << 21) | (it_r << 16) | (imm12 & 0x7FF)
    if mnem == "FSSET":
        imm12 = parse_int(ops[0]) & 0xFFF
        return (0x15 << 25) | (((imm12 >> 11) & 1) << 21) | (imm12 & 0x7FF)
    if mnem in ("FMEQ", "FMAND", "FMOR"):
        lop = {"FMEQ": 0x18, "FMAND": 0x1A, "FMOR": 0x1B}[mnem]
        return (lop << 25) | (parse_vi(ops[0]) << 16) | (parse_vi(ops[1]) << 11)
    if mnem == "FCGET":
        return (0x1C << 25) | (parse_vi(ops[0]) << 16)
    if mnem == "B":
        return (0x20 << 25) | resolve_branch(ops[0], pc, labels)
    if mnem == "BAL":
        return (0x21 << 25) | (parse_vi(ops[0]) << 16) | resolve_branch(ops[1], pc, labels)
    if mnem == "JR":
        return (0x24 << 25) | (parse_vi(ops[0]) << 11)
    if mnem == "JALR":
        return (0x25 << 25) | (parse_vi(ops[0]) << 16) | (parse_vi(ops[1]) << 11)
    if mnem in ("IBEQ", "IBNE"):
        lop = 0x28 if mnem == "IBEQ" else 0x29
        return (lop << 25) | (parse_vi(ops[0]) << 16) | (parse_vi(ops[1]) << 11) | resolve_branch(ops[2], pc, labels)
    if mnem in ("IBLTZ", "IBGTZ", "IBLEZ", "IBGEZ"):
        lop = {"IBLTZ": 0x2C, "IBGTZ": 0x2D, "IBLEZ": 0x2E, "IBGEZ": 0x2F}[mnem]
        return (lop << 25) | (parse_vi(ops[0]) << 11) | resolve_branch(ops[1], pc, labels)

    # Lower 0x40 special instructions
    base = 0x40 << 25
    if mnem in ("IADD", "ISUB", "IAND", "IOR"):
        op = {"IADD": 0x30, "ISUB": 0x31, "IAND": 0x34, "IOR": 0x35}[mnem]
        return base | (parse_vi(ops[2]) << 16) | (parse_vi(ops[1]) << 11) | (parse_vi(ops[0]) << 6) | op
    if mnem == "IADDI":
        imm5 = parse_int(ops[2])
        if not (-16 <= imm5 <= 15):
            raise ValueError(f"IADDI imm5 out of range: {imm5}")
        return base | (parse_vi(ops[0]) << 16) | (parse_vi(ops[1]) << 11) | ((imm5 & 0x1F) << 6) | 0x32
    if mnem in ("MOVE", "MR32"):
        op = 0x3C if mnem == "MOVE" else 0x3D
        return base | (dest << 21) | (parse_vf(ops[0]) << 16) | (parse_vf(ops[1]) << 11) | (0x0C << 6) | op
    if mnem in ("LQI", "LQD"):
        op = 0x3C if mnem == "LQI" else 0x3E
        pat = r"\(\s*(vi\d+)\s*\+\+\s*\)" if mnem == "LQI" else r"\(\s*--\s*(vi\d+)\s*\)"
        m2 = re.fullmatch(pat, ops[1], re.IGNORECASE)
        if not m2:
            raise ValueError(f"{mnem} invalid address operand: {ops[1]!r}")
        return base | (dest << 21) | (parse_vf(ops[0]) << 16) | (parse_vi(m2.group(1)) << 11) | (0x0D << 6) | op
    if mnem in ("SQI", "SQD"):
        op = 0x3D if mnem == "SQI" else 0x3F
        pat = r"\(\s*(vi\d+)\s*\+\+\s*\)" if mnem == "SQI" else r"\(\s*--\s*(vi\d+)\s*\)"
        m2 = re.fullmatch(pat, ops[1], re.IGNORECASE)
        if not m2:
            raise ValueError(f"{mnem} invalid address operand: {ops[1]!r}")
        return base | (dest << 21) | (parse_vi(m2.group(1)) << 16) | (parse_vf(ops[0]) << 11) | (0x0D << 6) | op
    if mnem in ("DIV", "RSQRT"):
        op = 0x3C if mnem == "DIV" else 0x3E
        if ops[0].upper() != "Q":
            raise ValueError(f"{mnem} first operand must be Q")
        fs, fsf = parse_vf_field(ops[1])
        ft, ftf = parse_vf_field(ops[2])
        return base | (ftf << 23) | (fsf << 21) | (ft << 16) | (fs << 11) | (0x0E << 6) | op
    if mnem == "SQRT":
        if ops[0].upper() != "Q":
            raise ValueError("SQRT first operand must be Q")
        ft, ftf = parse_vf_field(ops[1])
        return base | (ftf << 23) | (ft << 16) | (0x0E << 6) | 0x3D
    if mnem == "WAITQ":
        return base | (0x0E << 6) | 0x3F
    if mnem == "MTIR":
        it_r = parse_vi(ops[0])
        fs, fsf = parse_vf_field(ops[1])
        return base | (fsf << 21) | (it_r << 16) | (fs << 11) | (0x0F << 6) | 0x3C
    if mnem == "MFIR":
        return base | (dest << 21) | (parse_vf(ops[0]) << 16) | (parse_vi(ops[1]) << 11) | (0x0F << 6) | 0x3D
    if mnem in ("ILWR", "ISWR"):
        op = 0x3E if mnem == "ILWR" else 0x3F
        m2 = re.fullmatch(r"\(\s*(vi\d+)\s*\)", ops[1], re.IGNORECASE)
        if not m2:
            raise ValueError(f"{mnem} expects (viXX), got {ops[1]!r}")
        return base | (dest << 21) | (parse_vi(ops[0]) << 16) | (parse_vi(m2.group(1)) << 11) | (0x0F << 6) | op
    if mnem in ("RNEXT", "RGET"):
        op = 0x3C if mnem == "RNEXT" else 0x3D
        return base | (dest << 21) | (parse_vf(ops[0]) << 16) | (0x10 << 6) | op
    if mnem in ("RINIT", "RXOR"):
        op = 0x3E if mnem == "RINIT" else 0x3F
        fs, fsf = parse_vf_field(ops[1])
        return base | (fsf << 21) | (fs << 11) | (0x10 << 6) | op
    if mnem == "MFP":
        return base | (dest << 21) | (parse_vf(ops[0]) << 16) | (0x19 << 6) | 0x3C
    if mnem in ("XTOP", "XITOP"):
        op = 0x3C if mnem == "XTOP" else 0x3D
        return base | (parse_vi(ops[0]) << 16) | (0x1A << 6) | op
    if mnem == "XGKICK":
        return base | (parse_vi(ops[0]) << 11) | (0x1B << 6) | 0x3C
    if mnem in ("ESADD", "ERSADD", "ELENG", "ERLENG"):
        op = {"ESADD": 0x3C, "ERSADD": 0x3D, "ELENG": 0x3E, "ERLENG": 0x3F}[mnem]
        return base | (0xE << 21) | (parse_vf(ops[1]) << 11) | (0x1C << 6) | op
    if mnem in ("EATANXY", "EATANXZ", "ESUM"):
        op = {"EATANXY": 0x3C, "EATANXZ": 0x3D, "ESUM": 0x3E}[mnem]
        d = 0xF if mnem == "ESUM" else 0xE
        return base | (d << 21) | (parse_vf(ops[1]) << 11) | (0x1D << 6) | op
    if mnem in ("ERCPR", "ESQRT", "ERSQRT", "ESIN", "EATAN", "EEXP"):
        fd, op = {
            "ERCPR": (0x1D, 0x3F),
            "ESQRT": (0x1E, 0x3C),
            "ERSQRT": (0x1E, 0x3D),
            "ESIN": (0x1E, 0x3E),
            "EATAN": (0x1E, 0x3F),
            "EEXP": (0x1F, 0x3C),
        }[mnem]
        fs, fsf = parse_vf_field(ops[1])
        return base | (fsf << 21) | (fs << 11) | (fd << 6) | op
    if mnem == "WAITP":
        return base | (0x1F << 6) | 0x3F

    raise ValueError(f"Unknown Lower mnemonic: {mnem!r}")


# ---------------------------------------------------------------------------
# .vsm Assembler (two-pass per file)
# ---------------------------------------------------------------------------

def strip_comment(line: str) -> str:
    for sep in (";", "//", "#"):
        idx = line.find(sep)
        if idx != -1:
            line = line[:idx]
    return line.strip()


def assemble_vsm(path: str) -> tuple[bytes, int]:
    """Assemble a single .vsm file into raw bytes and return (bytes, insn_count)."""
    with open(path, "r", encoding="utf-8") as f:
        raw_lines = f.readlines()

    # Pass 1: parse directives/labels/instructions and record label PCs
    items = []
    labels: dict[str, int] = {}
    pc = 0

    for lineno, raw in enumerate(raw_lines, 1):
        line = strip_comment(raw)
        if not line:
            continue

        # Support label on its own line or prefixed to a line
        while True:
            lm = re.match(r"^([A-Za-z_][A-Za-z0-9_]*):\s*(.*)$", line)
            if not lm:
                break
            lname = lm.group(1)
            if lname in labels:
                raise ValueError(f"{path}:{lineno}: duplicate label {lname!r}")
            labels[lname] = pc
            line = lm.group(2).strip()
            if not line:
                break
        if not line:
            continue

        if line.startswith("."):
            parts = line.split(None, 1)
            directive = parts[0].lower()
            args = split_ops(parts[1]) if len(parts) > 1 else []
            if directive == ".vif_mpg":
                vu_addr = parse_int(args[0])
                count = parse_int(args[1])
                pc = vu_addr
                items.append(("directive", lineno, directive, (vu_addr, count)))
            else:
                items.append(("directive", lineno, directive, args))
            continue

        if "|" not in line:
            raise ValueError(f"{path}:{lineno}: expected 'UPPER | LOWER', got {line!r}")
        up_str, lo_str = line.split("|", 1)
        items.append(("insn", lineno, pc, up_str.strip(), lo_str.strip()))
        pc += 1

    # Pass 2: emit bytes
    out = bytearray()
    insn_count = 0

    for item in items:
        if item[0] == "directive":
            _, lineno, directive, args = item
            if directive == ".dma_ref":
                qwc = parse_int(args[0])
                addr = parse_int(args[1])
                vif0 = parse_int(args[2]) if len(args) > 2 else 0
                vif1 = parse_int(args[3]) if len(args) > 3 else 0
                out += struct.pack("<IIII", (3 << 28) | (qwc & 0xFFFF), addr, vif0, vif1)
            elif directive == ".dma_next":
                qwc = parse_int(args[0])
                addr = parse_int(args[1]) if len(args) > 1 else 0
                vif0 = parse_int(args[2]) if len(args) > 2 else 0
                vif1 = parse_int(args[3]) if len(args) > 3 else 0
                out += struct.pack("<IIII", (2 << 28) | (qwc & 0xFFFF), addr, vif0, vif1)
            elif directive == ".dma_cnt":
                qwc = parse_int(args[0])
                vif0 = parse_int(args[1]) if len(args) > 1 else 0
                vif1 = parse_int(args[2]) if len(args) > 2 else 0
                out += struct.pack("<IIII", (1 << 28) | (qwc & 0xFFFF), 0, vif0, vif1)
            elif directive == ".dma_end":
                qwc = parse_int(args[0])
                vif0 = parse_int(args[1]) if len(args) > 1 else 0
                vif1 = parse_int(args[2]) if len(args) > 2 else 0
                out += struct.pack("<IIII", (7 << 28) | (qwc & 0xFFFF), 0, vif0, vif1)
            elif directive == ".vif_nop":
                out += struct.pack("<I", 0x00000000)
            elif directive == ".vif_flush":
                out += struct.pack("<I", 0x11000000)
            elif directive == ".vif_mpg":
                vu_addr, count = args
                num = 0 if count == 256 else count
                out += struct.pack("<I", 0x4A000000 | ((num & 0xFF) << 16) | (vu_addr & 0xFFFF))
            elif directive == ".pad":
                nbytes = parse_int(args[0])
                out += bytes(nbytes)
            else:
                raise ValueError(f"{path}:{lineno}: unknown directive {directive!r}")
        else:
            _, lineno, insn_pc, up_str, lo_str = item
            try:
                hi = asm_upper(up_str)
                lo = asm_lower(lo_str, hi, insn_pc, labels)
            except Exception as exc:
                raise ValueError(f"{path}:{lineno}: {exc}") from exc
            out += struct.pack("<II", lo, hi)
            insn_count += 1

    return bytes(out), insn_count


# ---------------------------------------------------------------------------
# Disassembler for vutext.bin -> vu/vu1_prog1.vsm, vu/vu1_prog2.vsm
# ---------------------------------------------------------------------------

def parse_vutext_programs(data: bytes) -> list[dict]:
    """Parse DMA/VIF packets from assets/vutext.bin into structured program descriptors."""
    programs = []
    off = 0
    while off + 16 <= len(data):
        w0, w1, w2, w3 = struct.unpack_from("<4I", data, off)
        if w0 == 0 and w1 == 0 and w2 == 0 and w3 == 0:
            break
        dma_id = (w0 >> 28) & 7
        qwc = w0 & 0xFFFF
        pkt_start = off
        pkt_end = off + 16 + qwc * 16
        if pkt_end > len(data):
            raise ValueError(f"DMA packet at 0x{off:x} exceeds file size")

        events = []
        p = off + 16
        while p < pkt_end:
            w = struct.unpack_from("<I", data, p)[0]
            cmd = (w >> 24) & 0x7F
            num = (w >> 16) & 0xFF
            imm = w & 0xFFFF
            if cmd == 0x00 and w == 0:
                events.append(("vif_nop",))
                p += 4
            elif cmd == 0x11 and w == 0x11000000:
                events.append(("vif_flush",))
                p += 4
            elif cmd == 0x4A:
                count = 256 if num == 0 else num
                insns = [
                    struct.unpack_from("<II", data, p + 4 + i * 8)
                    for i in range(count)
                ]
                events.append(("vif_mpg", imm, count, insns))
                p += 4 + count * 8
            else:
                raise ValueError(f"Unsupported VIF command 0x{w:08x} at 0x{p:x}")

        programs.append({
            "offset": pkt_start,
            "end": pkt_end,
            "dma_id": dma_id,
            "qwc": qwc,
            "addr": w1,
            "vif0": w2,
            "vif1": w3,
            "events": events,
            "trailing_pad": 0,
        })
        off = pkt_end

    if off < len(data):
        if any(b != 0 for b in data[off:]):
            raise ValueError(f"Non-zero trailing bytes at 0x{off:x}")
        programs[-1]["trailing_pad"] = len(data) - off

    return programs


def emit_program_vsm(prog: dict, prog_idx: int) -> tuple[str, int]:
    """Disassemble a parsed VU1 program into clean, labeled .vsm text."""
    # First pass: collect branch targets for labels
    labels: dict[int, str] = {}
    total_insns = 0
    for ev in prog["events"]:
        if ev[0] == "vif_mpg":
            _, vu_addr, count, insns = ev
            total_insns += count
            for i, (lo, hi) in enumerate(insns):
                pc = vu_addr + i
                if not ((hi >> 31) & 1):
                    tgt = branch_target(lo, pc)
                    if tgt is not None:
                        labels[tgt] = f"L_{tgt * 8:04x}"

    # Always label VU address 0x0000 if code starts there
    if 0 not in labels:
        labels[0] = "L_0000"

    lines = []
    vma = 0x00578E00 + prog["offset"]
    dma_name = {1: "cnt", 2: "next", 3: "ref", 7: "end"}.get(prog["dma_id"], str(prog["dma_id"]))
    lines.append(f"; ============================================================================")
    lines.append(f"; FFX PAL (SCES_504.90) VU1 Microprogram {prog_idx}")
    lines.append(f"; VMA: 0x{vma:08x}..0x{vma + (prog['end'] - prog['offset']):08x} "
                 f"({prog['end'] - prog['offset']} B packet, {total_insns} VU1 instructions)")
    lines.append(f"; DMA tag: {dma_name} qwc={prog['qwc']} addr=0x{prog['addr']:08x}")
    lines.append(f"; ============================================================================")
    lines.append("")

    if prog["dma_id"] == 3:
        lines.append(f".dma_ref {prog['qwc']}, 0x{prog['addr']:08x}")
    elif prog["dma_id"] == 2:
        lines.append(f".dma_next {prog['qwc']}, 0x{prog['addr']:08x}")
    elif prog["dma_id"] == 1:
        lines.append(f".dma_cnt {prog['qwc']}")
    elif prog["dma_id"] == 7:
        lines.append(f".dma_end {prog['qwc']}")
    else:
        raise ValueError(f"Unsupported DMA tag id {prog['dma_id']}")

    for ev in prog["events"]:
        if ev[0] == "vif_nop":
            lines.append(".vif_nop")
        elif ev[0] == "vif_flush":
            lines.append(".vif_flush")
        elif ev[0] == "vif_mpg":
            _, vu_addr, count, insns = ev
            lines.append(f".vif_mpg 0x{vu_addr:04x}, {count}")
            for i, (lo, hi) in enumerate(insns):
                pc = vu_addr + i
                if pc in labels:
                    lines.append(f"{labels[pc]}:")
                up_s = disasm_upper(hi)
                lo_s = disasm_lower(lo, hi, pc, labels)
                lines.append(f"    {up_s:<30} | {lo_s:<28} ; {pc * 8:04x}")

    if prog["trailing_pad"]:
        lines.append("")
        lines.append(f"; Trailing zero padding ({prog['trailing_pad']} B: 16 B .vutext trailer + 48 B alignment)")
        lines.append(f".pad {prog['trailing_pad']}")

    lines.append("")
    return "\n".join(lines), total_insns


# ---------------------------------------------------------------------------
# CLI
# ---------------------------------------------------------------------------

def cmd_disasm(bin_path: str, out_dir: str) -> int:
    data = open(bin_path, "rb").read()
    programs = parse_vutext_programs(data)
    os.makedirs(out_dir, exist_ok=True)
    total = 0
    for idx, prog in enumerate(programs, 1):
        text, n_insns = emit_program_vsm(prog, idx)
        total += n_insns
        out_path = os.path.join(out_dir, f"vu1_prog{idx}.vsm")
        with open(out_path, "w", encoding="utf-8") as f:
            f.write(text)
        print(f"Wrote {out_path}: {n_insns} instructions, {prog['end'] - prog['offset']} B packet")
    print(f"Disassembled {len(programs)} VU1 programs, {total} instructions total, 0 unknown instructions.")
    return 0


def cmd_build(vsm_paths: list[str], out_path: str) -> int:
    out = bytearray()
    total_insns = 0
    for p in vsm_paths:
        blob, n = assemble_vsm(p)
        out += blob
        total_insns += n
    parent = os.path.dirname(out_path)
    if parent:
        os.makedirs(parent, exist_ok=True)
    with open(out_path, "wb") as f:
        f.write(out)
    sha = hashlib.sha256(out).hexdigest()
    print(f"Assembled {len(vsm_paths)} files -> {out_path} ({len(out)} B, {total_insns} instructions, sha256={sha})")
    return 0


def cmd_verify(vsm_paths: list[str], ref_path: str) -> int:
    out = bytearray()
    total_insns = 0
    for p in vsm_paths:
        blob, n = assemble_vsm(p)
        out += blob
        total_insns += n
    ref = open(ref_path, "rb").read()
    sha_got = hashlib.sha256(out).hexdigest()
    sha_ref = hashlib.sha256(ref).hexdigest()

    if out == ref:
        print(f"MATCH 100.000% ({len(out)} B, {total_insns} VU1 instructions, 0 unknown)")
        print(f"SHA-256: {sha_got}")
        return 0

    print(f"MISMATCH! got {len(out)} B (sha256={sha_got}), expected {len(ref)} B (sha256={sha_ref})")
    n_cmp = min(len(out), len(ref))
    diffs = 0
    for i in range(n_cmp):
        if out[i] != ref[i]:
            print(f"  diff at 0x{i:04x}: got 0x{out[i]:02x}, expected 0x{ref[i]:02x}")
            diffs += 1
            if diffs >= 16:
                break
    return 1


def main(argv: list[str]) -> int:
    if len(argv) < 2:
        print(__doc__.strip())
        return 2
    cmd = argv[1]
    if cmd == "disasm":
        if len(argv) != 4:
            print("Usage: vu1asm.py disasm <vutext.bin> <out_dir>")
            return 2
        return cmd_disasm(argv[2], argv[3])
    if cmd == "build":
        if "-o" not in argv:
            print("Usage: vu1asm.py build <prog1.vsm> [...] -o <out.bin>")
            return 2
        oi = argv.index("-o")
        vsm_paths = argv[2:oi]
        out_path = argv[oi + 1]
        return cmd_build(vsm_paths, out_path)
    if cmd == "verify":
        if len(argv) < 4:
            print("Usage: vu1asm.py verify <prog1.vsm> [...] <ref.bin>")
            return 2
        return cmd_verify(argv[2:-1], argv[-1])
    print(f"Unknown command: {cmd}")
    return 2


if __name__ == "__main__":
    sys.exit(main(sys.argv))
