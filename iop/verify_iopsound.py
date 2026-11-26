#!/usr/bin/env python3
"""IOPSOUND.IRX scanner, disassembler, and byte-exact build verifier.

Compiles decompiled C units with the period IOP compiler
(tools/cc/iop-gcc2.8.1/bin/iop-gcc -O2 -G0) + mipsel-linux-gnu-as (-march=r3000)
+ mipsel-linux-gnu-ld and verifies 100% byte-for-byte .text match against
baserom/IOPSOUND.IRX.

Can be run on the host (scan/disasm run natively in Python 3; compile/verify
automatically invokes Docker `ffx-decomp`) or directly inside Docker.
"""
from __future__ import annotations

import argparse
import atexit
import bisect
import hashlib
import json
import os
from pathlib import Path
import re
import shutil
import struct
import subprocess
import sys
import tempfile

ROOT = Path(__file__).resolve().parent.parent
IRX_PATH = ROOT / "baserom" / "IOPSOUND.IRX"
IOP_DIR = ROOT / "iop" / "iopsound"
FUNCS_TSV = IOP_DIR / "funcs.tsv"
UNITS_JSON = IOP_DIR / "units.json"
PROGRESS_JSON = ROOT / "docs" / "iopsound-progress.json"

IOP_GCC = "tools/cc/iop-gcc2.8.1/bin/iop-gcc"
IOP_GCC_B = "tools/cc/iop-gcc2.8.1/lib/gcc-lib/mipsel-scei-elfl/2.8.1/"

R_MIPS_32 = 2
R_MIPS_26 = 4
R_MIPS_HI16 = 5
R_MIPS_LO16 = 6

REG_NAMES = [
    "$zero", "$at", "$v0", "$v1", "$a0", "$a1", "$a2", "$a3",
    "$t0", "$t1", "$t2", "$t3", "$t4", "$t5", "$t6", "$t7",
    "$s0", "$s1", "$s2", "$s3", "$s4", "$s5", "$s6", "$s7",
    "$t8", "$t9", "$k0", "$k1", "$gp", "$sp", "$fp", "$ra",
]


def _s16(val: int) -> int:
    val &= 0xFFFF
    return val - 0x10000 if val >= 0x8000 else val


class IrxImage:
    """Parsed ELF32 IOP IRX image (sections, relocations, import tables, functions)."""

    def __init__(self, path: Path = IRX_PATH):
        if not path.is_file():
            raise FileNotFoundError(f"Missing IRX binary: {path}")
        self.path = path
        self.raw = path.read_bytes()
        if self.raw[:4] != b"\x7fELF":
            raise ValueError(f"{path} is not an ELF file")

        self.e_entry, e_phoff, e_shoff = struct.unpack_from("<III", self.raw, 24)
        e_shentsize, e_shnum, e_shstrndx = struct.unpack_from("<HHH", self.raw, 46)
        shstr_off = struct.unpack_from("<I", self.raw, e_shoff + e_shstrndx * e_shentsize + 16)[0]

        self.sections: dict[str, dict] = {}
        for i in range(e_shnum):
            off = e_shoff + i * e_shentsize
            (
                name_idx, sh_type, sh_flags, sh_addr, sh_file_off,
                sh_size, sh_link, sh_info, sh_align, sh_entsize,
            ) = struct.unpack_from("<10I", self.raw, off)
            end = self.raw.index(b"\0", shstr_off + name_idx)
            name = self.raw[shstr_off + name_idx:end].decode("ascii", errors="replace")
            self.sections[name] = {
                "addr": sh_addr,
                "off": sh_file_off,
                "size": sh_size,
                "type": sh_type,
                "flags": sh_flags,
            }

        self.text = self._sec_bytes(".text")
        self.text_vma = self.sections[".text"]["addr"]
        self.text_size = self.sections[".text"]["size"]

        self.rodata = self._sec_bytes(".rodata") if ".rodata" in self.sections else b""
        self.rodata_vma = self.sections[".rodata"]["addr"] if ".rodata" in self.sections else 0

        self.data = self._sec_bytes(".data") if ".data" in self.sections else b""
        self.data_vma = self.sections[".data"]["addr"] if ".data" in self.sections else 0

        self.iopmod = self._parse_iopmod()
        self.rel_text = self._parse_rel(".rel.text")
        self.rel_data = self._parse_rel(".rel.data")
        self.import_tables, self.import_stubs = self._parse_import_tables()
        self.code_end = self.import_tables[0]["addr"] if self.import_tables else self.text_size
        self.hi_lo_targets = self._resolve_hi_lo_map()

    def _sec_bytes(self, name: str) -> bytes:
        s = self.sections[name]
        return self.raw[s["off"]:s["off"] + s["size"]]

    def _parse_iopmod(self) -> dict:
        if ".iopmod" not in self.sections:
            return {}
        b = self._sec_bytes(".iopmod")
        modinfo, entry, gp, text_sz, data_sz, bss_sz, version = struct.unpack_from("<6IH", b, 0)
        name = b[26:].split(b"\0")[0].decode("ascii", errors="replace")
        return {
            "modinfo": modinfo,
            "entry": entry,
            "gp": gp,
            "text_size": text_sz,
            "data_size": data_sz,
            "bss_size": bss_sz,
            "version": version,
            "name": name,
        }

    def _parse_rel(self, name: str) -> list[tuple[int, int]]:
        if name not in self.sections:
            return []
        b = self._sec_bytes(name)
        out = []
        for i in range(0, len(b), 8):
            r_off, r_info = struct.unpack_from("<II", b, i)
            out.append((r_off, r_info & 0xFF))
        return out

    def _parse_import_tables(self) -> tuple[list[dict], list[dict]]:
        """Parse IOP IRX import tables (magic 0x41E00000) in .text."""
        tables = []
        stubs = []
        off = 0
        while off + 20 <= self.text_size:
            w = struct.unpack_from("<I", self.text, off)[0]
            if w == 0x41E00000:
                _nxt, ver_flags = struct.unpack_from("<II", self.text, off + 4)
                libname = self.text[off + 12:off + 20].rstrip(b"\0").decode("ascii", errors="replace")
                p = off + 20
                tbl_stubs = []
                while p + 8 <= self.text_size:
                    w0, w1 = struct.unpack_from("<II", self.text, p)
                    if w0 == 0 and w1 == 0:
                        p += 8
                        break
                    if w0 == 0x03E00008 and (w1 & 0xFFFF0000) == 0x24000000:
                        idx = w1 & 0xFFFF
                        stub = {
                            "name": f"imp_{libname}_{idx}",
                            "lib": libname,
                            "idx": idx,
                            "addr": self.text_vma + p,
                            "size": 8,
                            "kind": "import_stub",
                        }
                        tbl_stubs.append(stub)
                        stubs.append(stub)
                        p += 8
                    else:
                        break
                tables.append({
                    "lib": libname,
                    "version": ver_flags & 0xFFFF,
                    "addr": self.text_vma + off,
                    "end": self.text_vma + p,
                    "stubs": tbl_stubs,
                })
                off = p
                continue
            off += 4
        return tables, stubs

    def _resolve_hi_lo_map(self) -> dict[int, int]:
        """Map both HI16 and LO16 instruction addresses to their resolved 32-bit target."""
        resolved: dict[int, int] = {}
        pending_hi: list[tuple[int, int]] = []
        for r_off, r_type in self.rel_text:
            if r_type == R_MIPS_HI16:
                hi = struct.unpack_from("<I", self.text, r_off)[0] & 0xFFFF
                pending_hi.append((r_off, hi))
            elif r_type == R_MIPS_LO16:
                lo = _s16(struct.unpack_from("<I", self.text, r_off)[0])
                if pending_hi:
                    for hi_off, hi in pending_hi:
                        addr = ((hi << 16) + lo) & 0xFFFFFFFF
                        resolved[hi_off] = addr
                        resolved[r_off] = addr
                    pending_hi.clear()
        return resolved

    def read_rodata_cstr(self, addr: int) -> str | None:
        """If addr points to a printable ASCII C string in .rodata, return it."""
        if not (self.rodata_vma <= addr < self.rodata_vma + len(self.rodata)):
            return None
        off = addr - self.rodata_vma
        try:
            nul = self.rodata.index(0, off)
        except ValueError:
            return None
        raw = self.rodata[off:nul]
        if not raw or len(raw) > 120:
            return None
        if all(b in (9, 10, 13) or 32 <= b < 127 for b in raw):
            return raw.decode("ascii")
        return None

    def discover_functions(self) -> list[dict]:
        """Discover all code functions in 0..code_end plus import stubs."""
        code_end = self.code_end
        starts: set[int] = {0, self.e_entry}

        # 1. R_MIPS_26 jal targets
        for r_off, r_type in self.rel_text:
            if r_type == R_MIPS_26:
                w = struct.unpack_from("<I", self.text, r_off)[0]
                if (w >> 26) == 3:  # jal
                    tgt = (w & 0x03FFFFFF) << 2
                    if tgt < code_end:
                        starts.add(tgt)

        # 2. .rel.data pointers into .text
        for r_off, r_type in self.rel_data:
            if r_type == R_MIPS_32:
                rel_off = r_off - self.data_vma
                if 0 <= rel_off <= len(self.data) - 4:
                    val = struct.unpack_from("<I", self.data, rel_off)[0]
                    if val < code_end and (val & 3) == 0:
                        starts.add(val)

        # 3. HI16/LO16 targets inside code
        for tgt in self.hi_lo_targets.values():
            if tgt < code_end and (tgt & 3) == 0:
                starts.add(tgt)

        # 4. Branch coverage (to avoid splitting inside functions)
        inside_branch = bytearray(code_end // 4)
        for off in range(0, code_end, 4):
            w = struct.unpack_from("<I", self.text, off)[0]
            op = w >> 26
            if op in (1, 4, 5, 6, 7):
                tgt = off + 4 + (_s16(w) << 2)
                if 0 <= tgt < code_end:
                    lo, hi = min(off, tgt), max(off, tgt)
                    for idx in range(lo // 4 + 1, hi // 4 + 1):
                        inside_branch[idx] = 1

        # 5. Unreferenced functions following jr $ra + delay slot + optional nop padding
        for off in range(0, code_end, 4):
            if struct.unpack_from("<I", self.text, off)[0] == 0x03E00008:
                nxt = off + 8
                while nxt < code_end and struct.unpack_from("<I", self.text, nxt)[0] == 0:
                    nxt += 4
                if nxt < code_end and not inside_branch[nxt // 4]:
                    starts.add(nxt)

        sorted_starts = sorted(starts)
        funcs: list[dict] = []
        for i, s in enumerate(sorted_starts):
            e = sorted_starts[i + 1] if i + 1 < len(sorted_starts) else code_end
            funcs.append({
                "name": f"func_{s:06X}",
                "addr": s,
                "size": e - s,
                "kind": "code",
            })

        funcs.extend(self.import_stubs)
        funcs.sort(key=lambda f: f["addr"])
        return funcs


def decode_mips_r3000(word: int, pc: int, sym_by_addr: dict[int, str] | None = None) -> str:
    """Decode a single 32-bit MIPS-I / R3000 instruction."""
    if word == 0:
        return "nop"
    op = (word >> 26) & 0x3F
    rs = (word >> 21) & 0x1F
    rt = (word >> 16) & 0x1F
    rd = (word >> 11) & 0x1F
    sa = (word >> 6) & 0x1F
    fn = word & 0x3F
    imm = word & 0xFFFF
    simm = _s16(imm)
    R = REG_NAMES

    def _fmt_target(addr: int) -> str:
        if sym_by_addr and addr in sym_by_addr:
            return f"{sym_by_addr[addr]} (0x{addr:06x})"
        return f"0x{addr:06x}"

    if op == 0:  # SPECIAL
        if fn == 0x00:
            return f"sll     {R[rd]}, {R[rt]}, {sa}"
        if fn == 0x02:
            return f"srl     {R[rd]}, {R[rt]}, {sa}"
        if fn == 0x03:
            return f"sra     {R[rd]}, {R[rt]}, {sa}"
        if fn == 0x04:
            return f"sllv    {R[rd]}, {R[rt]}, {R[rs]}"
        if fn == 0x06:
            return f"srlv    {R[rd]}, {R[rt]}, {R[rs]}"
        if fn == 0x07:
            return f"srav    {R[rd]}, {R[rt]}, {R[rs]}"
        if fn == 0x08:
            return f"jr      {R[rs]}"
        if fn == 0x09:
            return f"jalr    {R[rs]}" if rd == 31 else f"jalr    {R[rd]}, {R[rs]}"
        if fn == 0x0C:
            return f"syscall 0x{(word >> 6) & 0xFFFFF:x}"
        if fn == 0x0D:
            return f"break   0x{(word >> 6) & 0xFFFFF:x}"
        if fn == 0x10:
            return f"mfhi    {R[rd]}"
        if fn == 0x11:
            return f"mthi    {R[rs]}"
        if fn == 0x12:
            return f"mflo    {R[rd]}"
        if fn == 0x13:
            return f"mtlo    {R[rs]}"
        if fn == 0x18:
            return f"mult    {R[rs]}, {R[rt]}"
        if fn == 0x19:
            return f"multu   {R[rs]}, {R[rt]}"
        if fn == 0x1A:
            return f"div     {R[rs]}, {R[rt]}"
        if fn == 0x1B:
            return f"divu    {R[rs]}, {R[rt]}"
        alu_map = {
            0x20: "add", 0x21: "addu", 0x22: "sub", 0x23: "subu",
            0x24: "and", 0x25: "or", 0x26: "xor", 0x27: "nor",
            0x2A: "slt", 0x2B: "sltu",
        }
        if fn in alu_map:
            if fn == 0x21 and rt == 0:
                return f"move    {R[rd]}, {R[rs]}"
            return f"{alu_map[fn]:7s} {R[rd]}, {R[rs]}, {R[rt]}"
        return f".word   0x{word:08x}"

    if op == 1:  # REGIMM
        tgt = pc + 4 + (simm << 2)
        ri_map = {0: "bltz", 1: "bgez", 16: "bltzal", 17: "bgezal"}
        mnem = ri_map.get(rt, f"regimm{rt}")
        return f"{mnem:7s} {R[rs]}, 0x{tgt:06x}"

    if op == 2:
        tgt = ((pc + 4) & 0xF0000000) | ((word & 0x03FFFFFF) << 2)
        return f"j       {_fmt_target(tgt)}"
    if op == 3:
        tgt = ((pc + 4) & 0xF0000000) | ((word & 0x03FFFFFF) << 2)
        return f"jal     {_fmt_target(tgt)}"

    if op in (4, 5):
        tgt = pc + 4 + (simm << 2)
        if op == 4 and rs == 0 and rt == 0:
            return f"b       0x{tgt:06x}"
        mnem = "beq" if op == 4 else "bne"
        return f"{mnem:7s} {R[rs]}, {R[rt]}, 0x{tgt:06x}"
    if op in (6, 7):
        tgt = pc + 4 + (simm << 2)
        mnem = "blez" if op == 6 else "bgtz"
        return f"{mnem:7s} {R[rs]}, 0x{tgt:06x}"

    if op == 0x0F:
        return f"lui     {R[rt]}, 0x{imm:04x}"
    if op == 0x09 and rs == 0:
        return f"li      {R[rt]}, {simm}"

    imm_signed = {0x08: "addi", 0x09: "addiu", 0x0A: "slti", 0x0B: "sltiu"}
    if op in imm_signed:
        return f"{imm_signed[op]:7s} {R[rt]}, {R[rs]}, {simm}"

    imm_unsigned = {0x0C: "andi", 0x0D: "ori", 0x0E: "xori"}
    if op in imm_unsigned:
        return f"{imm_unsigned[op]:7s} {R[rt]}, {R[rs]}, 0x{imm:04x}"

    mem_ops = {
        0x20: "lb", 0x21: "lh", 0x22: "lwl", 0x23: "lw",
        0x24: "lbu", 0x25: "lhu", 0x26: "lwr",
        0x28: "sb", 0x29: "sh", 0x2A: "swl", 0x2B: "sw", 0x2E: "swr",
    }
    if op in mem_ops:
        return f"{mem_ops[op]:7s} {R[rt]}, {simm}({R[rs]})"

    return f".word   0x{word:08x}"


def write_funcs_tsv(funcs: list[dict], path: Path = FUNCS_TSV) -> None:
    path.parent.mkdir(parents=True, exist_ok=True)
    lines = ["name\taddr\tsize\tkind"]
    for f in funcs:
        lines.append(f"{f['name']}\t0x{f['addr']:06x}\t{f['size']}\t{f['kind']}")
    path.write_text("\n".join(lines) + "\n")


def load_funcs_tsv(path: Path = FUNCS_TSV) -> list[dict]:
    if not path.is_file():
        irx = IrxImage()
        funcs = irx.discover_functions()
        write_funcs_tsv(funcs, path)
        return funcs
    out = []
    for line in path.read_text().splitlines()[1:]:
        if not line.strip():
            continue
        name, addr_s, size_s, kind = line.split("\t")
        out.append({
            "name": name,
            "addr": int(addr_s, 16),
            "size": int(size_s),
            "kind": kind,
        })
    return out


def _decode_hex_fields(obj):
    if isinstance(obj, dict):
        return {k: _decode_hex_fields(v) for k, v in obj.items()}
    if isinstance(obj, list):
        return [_decode_hex_fields(v) for v in obj]
    if isinstance(obj, str) and re.fullmatch(r"0x[0-9a-fA-F]+", obj):
        return int(obj, 16)
    return obj


def load_units(units_path: Path | None = None) -> list[dict]:
    path = units_path if units_path is not None else UNITS_JSON
    if not path.is_file():
        return []
    raw = _decode_hex_fields(json.loads(path.read_text()))
    units = []
    for u in raw:
        src = Path(u["src"])
        if not src.is_absolute():
            candidate = IOP_DIR / src
            if candidate.is_file():
                u["src"] = candidate.relative_to(ROOT).as_posix()
            else:
                u["src"] = src.as_posix()
        units.append(u)
    return units


def cmd_scan() -> int:
    irx = IrxImage()
    funcs = irx.discover_functions()
    write_funcs_tsv(funcs)

    code_funcs = [f for f in funcs if f["kind"] == "code"]
    stub_funcs = [f for f in funcs if f["kind"] == "import_stub"]
    code_bytes = sum(f["size"] for f in code_funcs)
    import_stub_bytes = irx.text_size - code_bytes

    print(f"Scanned {irx.path.relative_to(ROOT)} ({irx.iopmod.get('name', '?')} v{irx.iopmod.get('version', 0):#x})")
    print(f"  .text total      : {irx.text_size:,} B (0x000000..0x{irx.text_size:06x})")
    print(f"  code bytes       : {code_bytes:,} B ({len(code_funcs)} functions, 0x000000..0x{irx.code_end:06x})")
    print(f"  import stub bytes: {import_stub_bytes:,} B ({len(irx.import_tables)} libraries, {len(stub_funcs)} stubs, 0x{irx.code_end:06x}..0x{irx.text_size:06x})")
    print(f"  relocations      : {len(irx.rel_text):,} in .rel.text, {len(irx.rel_data):,} in .rel.data")
    print(f"  wrote            : {FUNCS_TSV.relative_to(ROOT)}")
    print("\nTop 30 functions by size:")
    print(f"  {'Rank':>4}  {'Name':14s}  {'Addr':10s}  {'Size':>7s}")
    for rank, f in enumerate(sorted(code_funcs, key=lambda x: (-x["size"], x["addr"]))[:30], 1):
        print(f"  {rank:4d}  {f['name']:14s}  0x{f['addr']:06x}    {f['size']:6d} B")
    return 0


def _resolve_func_target(query: str, funcs: list[dict]) -> dict | None:
    for f in funcs:
        if f["name"] == query:
            return f
    try:
        addr = int(query, 16)
    except ValueError:
        return None
    for f in funcs:
        if f["addr"] <= addr < f["addr"] + f["size"]:
            return f
    return None


def cmd_disasm(query: str) -> int:
    irx = IrxImage()
    funcs = load_funcs_tsv()
    target = _resolve_func_target(query, funcs)
    if target is None:
        print(f"Function not found: {query}", file=sys.stderr)
        return 1

    sym_by_addr = {f["addr"]: f["name"] for f in funcs}
    start = target["addr"]
    end = start + target["size"]
    print(f"; {target['name']}  0x{start:06x}..0x{end:06x} ({target['size']} B, {target['kind']})")

    for off in range(start, end, 4):
        word = struct.unpack_from("<I", irx.text, off)[0]
        asm = decode_mips_r3000(word, off, sym_by_addr)
        notes = []
        if off in irx.hi_lo_targets:
            taddr = irx.hi_lo_targets[off]
            tname = sym_by_addr.get(taddr, f"D_{taddr:06X}")
            notes.append(f"addr={tname} (0x{taddr:06x})")
            s = irx.read_rodata_cstr(taddr)
            if s is not None:
                notes.append(f"str={s!r}")
        comment = f"  # {'; '.join(notes)}" if notes else ""
        print(f"  {off:06x}:  {word:08x}  {asm}{comment}")
    return 0


def _compile_and_link_unit(
    unit: dict,
    out_dir: Path,
    sym_table: dict[str, int],
) -> tuple[bytes, bytes | None]:
    src = Path(unit["src"])
    stem = src.stem
    asm_s = out_dir / f"{stem}.s"
    obj = out_dir / f"{stem}.o"
    ld_path = out_dir / f"{stem}.ld"
    elf = out_dir / f"{stem}.elf"
    text_bin = out_dir / f"{stem}.text.bin"

    cflags = list(unit.get("cflags", ["-O2"]))
    if "-G0" not in cflags:
        cflags.append("-G0")

    subprocess.run(
        [
            IOP_GCC,
            f"-B{IOP_GCC_B}",
            "-S",
            *cflags,
            "-Iiop/iopsound",
            str(src),
            "-o",
            str(asm_s),
        ],
        check=True,
    )
    # Period Sony iop-as (binutils 2.9) shims for modern mipsel-linux-gnu-as:
    # 1. Always: `move rd, rs` -> `addu rd, rs, $0`.
    # 2. Per-unit `no_split_macro`: prevent modern gas from splitting `sw/sh/sb/la reg, sym`
    #    across a following jump/branch delay slot.
    # 3. Per-unit `load_delay_nop`: preserve R3000A load-delay `nop` between a load into `$r`
    #    and a `sw/sh/sb $r, sym` macro (which expands to `lui $at; sw $r, lo($at)`).
    asm_text = asm_s.read_text()
    asm_text = re.sub(
        r"^(\s+)move(\s+\$[0-9a-zA-Z]+,\s*\$[0-9a-zA-Z]+)\b",
        r"\1addu\2,$0",
        asm_text,
        flags=re.MULTILINE,
    )
    if (
        unit.get("no_split_macro")
        or unit.get("no_split_store_only")
        or unit.get("no_split_bss_macro")
        or unit.get("no_split_syms")
        or unit.get("load_delay_nop")
    ):
        _sym_store_re = re.compile(
            r"^\s+(?:sw|sh|sb)\s+(\$[0-9a-zA-Z]+),\s*([A-Za-z_.$][A-Za-z0-9_.$+-]*)(?:\(\$[0-9a-zA-Z]+\))?\s*$"
        )
        _sym_macro_re = re.compile(
            r"^\s+(sw|sh|sb|la)\s+\$[0-9a-zA-Z]+,\s*([A-Za-z_.$][A-Za-z0-9_.$+-]*)(?:\(\$[0-9a-zA-Z]+\))?\s*$"
        )
        _load_re = re.compile(
            r"^\s+(?:lw|lh|lb|lhu|lbu)\s+(\$[0-9a-zA-Z]+),"
        )
        _branch_re = re.compile(
            r"^\s+(?:jal|j|jr|b|beq|bne|beqz|bnez|bgez|bgtz|blez|bltz)\b"
        )
        no_split = bool(unit.get("no_split_macro"))
        no_split_store = bool(unit.get("no_split_store_only"))
        no_split_bss = bool(unit.get("no_split_bss_macro"))
        no_split_syms = set(unit.get("no_split_syms", []))
        ld_nop = bool(unit.get("load_delay_nop"))
        out_lines: list[str] = []
        noreorder = False
        prev_was_sym_macro = False
        prev_load_reg: str | None = None
        for line in asm_text.splitlines(keepends=True):
            s = line.strip()
            if s.startswith(".set"):
                parts = s.split()
                if len(parts) >= 2:
                    if parts[1] == "noreorder":
                        noreorder = True
                    elif parts[1] == "reorder":
                        noreorder = False
                out_lines.append(line)
                prev_was_sym_macro = False
                prev_load_reg = None
                continue
            if not s or s.startswith("#") or s.startswith(".") or s.endswith(":"):
                out_lines.append(line)
                if s.endswith(":"):
                    prev_was_sym_macro = False
                    prev_load_reg = None
                continue
            if not noreorder and ld_nop and prev_load_reg is not None:
                ms = _sym_store_re.match(line)
                if ms and ms.group(1) == prev_load_reg:
                    out_lines.append("\tnop\n")
            if not noreorder and prev_was_sym_macro and _branch_re.match(line):
                out_lines.append("\t.set\tnoreorder\n\t.set\tnomacro\n")
                out_lines.append(line)
                out_lines.append("\tnop\n\t.set\tmacro\n\t.set\treorder\n")
                prev_was_sym_macro = False
                prev_load_reg = None
                continue
            out_lines.append(line)
            prev_was_sym_macro = False
            if not noreorder:
                mm = _sym_macro_re.match(line)
                if mm:
                    op, sym = mm.group(1), mm.group(2).split("+")[0].split("-")[0]
                    if no_split:
                        prev_was_sym_macro = True
                    elif no_split_store and op in ("sw", "sh", "sb"):
                        prev_was_sym_macro = True
                    elif sym in no_split_syms:
                        prev_was_sym_macro = True
                    elif no_split_bss:
                        mhex = re.fullmatch(r"D_([0-9A-Fa-f]{6})", sym)
                        if mhex and int(mhex.group(1), 16) >= 0x0192F0:
                            prev_was_sym_macro = True
            ml = _load_re.match(line)
            prev_load_reg = ml.group(1) if (not noreorder and ml) else None
        asm_text = "".join(out_lines)
    asm_s.write_text(asm_text)

    subprocess.run(
        [
            "mipsel-linux-gnu-as",
            "-EL",
            "-march=r3000",
            "-mabi=32",
            "-G0",
            "--no-pad-sections",
            str(asm_s),
            "-o",
            str(obj),
        ],
        check=True,
    )
    subprocess.run(
        ["mipsel-linux-gnu-objcopy", "--set-section-alignment", ".text=4", str(obj), str(obj)],
        check=True,
    )

    # Resolve undefined symbols
    nm_out = subprocess.run(
        ["mipsel-linux-gnu-nm", "-u", str(obj)],
        check=True,
        capture_output=True,
        text=True,
    ).stdout.split()

    unit_syms = dict(unit.get("syms", {}))
    resolved_syms: dict[str, int] = {}
    for name in nm_out:
        if name == "U":
            continue
        if name in unit_syms:
            resolved_syms[name] = unit_syms[name]
        elif name in sym_table:
            resolved_syms[name] = sym_table[name]
        else:
            m = re.fullmatch(r"(?:func|D)_([0-9A-Fa-f]{6,8})", name)
            if m:
                resolved_syms[name] = int(m.group(1), 16)
    # Also include any explicit unit syms
    for k, v in unit_syms.items():
        resolved_syms[k] = v

    ts = unit["text_start"]
    rs = unit.get("rodata_start")
    sym_lines = [f"{k} = 0x{v:08x};" for k, v in sorted(resolved_syms.items())]
    ro_sec = f"    . = 0x{rs:08x};\n    .rodata : {{ {obj.as_posix()}(.rodata) }}\n" if rs is not None else ""
    ld_script = (
        "SECTIONS\n{\n"
        f"    . = 0x{ts:08x};\n"
        f"    .text 0x{ts:08x} : SUBALIGN(4) {{ {obj.as_posix()}(.text) }}\n"
        f"{ro_sec}"
        "    /DISCARD/ : { *(*) }\n"
        "}\n"
        + "\n".join(sym_lines)
        + "\n"
    )
    ld_path.write_text(ld_script)

    subprocess.run(["mipsel-linux-gnu-ld", "-EL", "-T", str(ld_path), "-o", str(elf)], check=True)
    subprocess.run(["mipsel-linux-gnu-objcopy", "-O", "binary", "-j", ".text", str(elf), str(text_bin)], check=True)

    ro_bytes = None
    if rs is not None:
        ro_bin = out_dir / f"{stem}.rodata.bin"
        subprocess.run(["mipsel-linux-gnu-objcopy", "-O", "binary", "-j", ".rodata", str(elf), str(ro_bin)], check=True)
        ro_bytes = ro_bin.read_bytes()

    return text_bin.read_bytes(), ro_bytes


def _print_side_by_side_diff(
    expected: bytes,
    actual: bytes,
    base_addr: int,
    sym_by_addr: dict[int, str],
) -> None:
    n = max(len(expected), len(actual))
    print(f"{'Addr':>8s}  {'Expected':44s}  {'Actual':44s}")
    print("-" * 102)
    mismatches = 0
    for off in range(0, n, 4):
        pc = base_addr + off
        if off + 4 <= len(expected):
            ew = struct.unpack_from("<I", expected, off)[0]
            es = f"{ew:08x} {decode_mips_r3000(ew, pc, sym_by_addr)}"
        else:
            ew = None
            es = "<EOF>"
        if off + 4 <= len(actual):
            aw = struct.unpack_from("<I", actual, off)[0]
            as_ = f"{aw:08x} {decode_mips_r3000(aw, pc, sym_by_addr)}"
        else:
            aw = None
            as_ = "<EOF>"
        mark = "  " if ew == aw else "!="
        if ew != aw:
            mismatches += 1
        print(f"{pc:06x}{mark}  {es:44s}  {as_:44s}")
    print(f"\nTotal mismatched words: {mismatches} (expected {len(expected)} B, actual {len(actual)} B)")


def _write_progress(
    irx: IrxImage,
    funcs: list[dict],
    matched_units: list[dict],
) -> None:
    code_funcs = [f for f in funcs if f["kind"] == "code"]
    stub_funcs = [f for f in funcs if f["kind"] == "import_stub"]
    code_bytes = sum(f["size"] for f in code_funcs)
    import_stub_bytes = irx.text_size - code_bytes

    matched_ranges = [(u["text_start"], u["text_end"]) for u in matched_units]
    matched_func_list = []
    for f in code_funcs:
        f_start = f["addr"]
        f_end = f_start + f["size"]
        # Strip trailing inter-function alignment NOP words (0x00000000) when checking unit coverage
        eff_end = f_end
        while eff_end - 4 > f_start and irx.text[eff_end - 4:eff_end] == b"\x00\x00\x00\x00":
            eff_end -= 4
        if any(ts <= f_start and eff_end <= te for ts, te in matched_ranges):
            matched_func_list.append(f)

    matched_bytes = sum(f["size"] for f in matched_func_list)
    matched_functions = len(matched_func_list)
    total_functions = len(code_funcs)
    matched_pct = round(100.0 * matched_bytes / irx.text_size, 4) if irx.text_size else 0.0
    decomp_pct = round(100.0 * matched_bytes / code_bytes, 4) if code_bytes else 0.0

    payload = {
        "module": irx.iopmod.get("name", "IopSoundDriver"),
        "irx_file": "baserom/IOPSOUND.IRX",
        "total_text_bytes": irx.text_size,
        "code_bytes": code_bytes,
        "import_stub_bytes": import_stub_bytes,
        "matched_bytes": matched_bytes,
        "matched_functions": matched_functions,
        "total_functions": total_functions,
        "import_stubs": len(stub_funcs),
        "matched_percent": matched_pct,
        "decompilable_matched_percent": decomp_pct,
        "units": [
            {
                "name": u.get("name", Path(u["src"]).stem),
                "src": u["src"],
                "text_start": f"0x{u['text_start']:06x}",
                "text_end": f"0x{u['text_end']:06x}",
                "bytes": u["text_end"] - u["text_start"],
            }
            for u in matched_units
        ],
    }
    PROGRESS_JSON.parent.mkdir(parents=True, exist_ok=True)
    PROGRESS_JSON.write_text(json.dumps(payload, indent=2) + "\n")
    print(f"Wrote {PROGRESS_JSON.relative_to(ROOT)} ({matched_bytes}/{code_bytes} B = {decomp_pct:.2f}% decompilable)")


def parse_args(argv: list[str]) -> argparse.Namespace:
    ap = argparse.ArgumentParser(description="IOPSOUND.IRX scan, disasm, and byte-exact verifier.")
    ap.add_argument("--scan", action="store_true", help="Scan baserom/IOPSOUND.IRX and write iop/iopsound/funcs.tsv")
    ap.add_argument("--disasm", metavar="ADDR_OR_NAME", help="Disassemble a function by name or hex address")
    ap.add_argument("--list", action="store_true", help="List registered units in iop/iopsound/units.json")
    ap.add_argument("--units-file", metavar="PATH", help="Alternate units JSON file (for isolated worker runs)")
    ap.add_argument("--unit", action="append", default=[], help="Verify only units matching this name/stem (repeatable)")
    ap.add_argument("--diff", metavar="UNIT", help="Compile a unit and print side-by-side disassembly diff")
    ap.add_argument("--write-progress", action="store_true", help="Write docs/iopsound-progress.json")
    return ap.parse_args(argv)


def main(argv: list[str] | None = None) -> int:
    os.chdir(ROOT)
    argv = sys.argv[1:] if argv is None else argv
    args = parse_args(argv)

    if args.scan:
        return cmd_scan()

    if args.disasm:
        return cmd_disasm(args.disasm)

    units_path = Path(args.units_file) if args.units_file else None
    units = load_units(units_path)
    if args.list:
        for u in units:
            name = u.get("name", Path(u["src"]).stem)
            span = u["text_end"] - u["text_start"]
            print(f"{name:20s} 0x{u['text_start']:06x}..0x{u['text_end']:06x} ({span:5d} B)  {u['src']}")
        return 0

    # Compilation / linking requires Linux container with iop-gcc and mipsel-linux-gnu-*
    if sys.platform != "linux":
        cmd = [
            "docker", "run", "--rm", "-v", f"{ROOT}:/work", "ffx-decomp",
            "python3", "iop/verify_iopsound.py", *argv,
        ]
        return subprocess.run(cmd).returncode

    irx = IrxImage()
    funcs = load_funcs_tsv()
    sym_table = {f["name"]: f["addr"] for f in funcs}
    sym_by_addr = {f["addr"]: f["name"] for f in funcs}

    out_root = ROOT / "build" / "iopsound"
    out_root.mkdir(parents=True, exist_ok=True)
    out_dir = Path(tempfile.mkdtemp(prefix="run-", dir=out_root))
    atexit.register(shutil.rmtree, out_dir, True)

    if args.diff:
        matches = [
            u for u in units
            if args.diff in u.get("name", "") or args.diff in Path(u["src"]).stem
        ]
        if not matches:
            print(f"No unit matches --diff {args.diff}", file=sys.stderr)
            return 1
        unit = matches[0]
        ts, te = unit["text_start"], unit["text_end"]
        built_text, _ = _compile_and_link_unit(unit, out_dir, sym_table)
        orig_text = irx.text[ts:te]
        _print_side_by_side_diff(orig_text, built_text, ts, sym_by_addr)
        return 0 if built_text == orig_text else 1

    selected = [
        u for u in units
        if not args.unit or any(k in u.get("name", "") or k in Path(u["src"]).stem for k in args.unit)
    ]
    if not selected:
        print("No units registered or matching --unit filter.", file=sys.stderr)
        return 1

    failed = False
    matched_units = []
    total_bytes = 0
    for unit in selected:
        name = unit.get("name", Path(unit["src"]).stem)
        ts, te = unit["text_start"], unit["text_end"]
        rs = unit.get("rodata_start")
        built_text, built_rodata = _compile_and_link_unit(unit, out_dir, sym_table)
        orig_text = irx.text[ts:te]

        # GCC 2.8.1 MIPS may pad trailing 4 bytes for 8-byte section alignment if unit ends at 4 mod 8
        if len(built_text) == len(orig_text) + 4 and built_text[-4:] == b"\x00\x00\x00\x00" and built_text[:-4] == orig_text:
            built_text = built_text[:-4]

        if built_text != orig_text:
            print(f"FAIL {name} ({unit['src']}): .text mismatch at 0x{ts:06x}..0x{te:06x} "
                  f"(expected {len(orig_text)} B, got {len(built_text)} B)")
            failed = True
            continue

        if built_rodata is not None and rs is not None:
            ro_off = rs - irx.rodata_vma
            orig_ro = irx.rodata[ro_off:ro_off + len(built_rodata)]
            if built_rodata != orig_ro:
                print(f"FAIL {name} ({unit['src']}): .rodata mismatch at 0x{rs:06x}")
                failed = True
                continue

        sha = hashlib.sha256(built_text).hexdigest()[:12]
        print(f"MATCH {name} ({unit['src']}): .text 0x{ts:06x}..0x{te:06x} ({len(built_text)} B) sha256={sha}...")
        matched_units.append(unit)
        total_bytes += len(built_text)

    if failed:
        return 1

    print(f"\nOK: {len(matched_units)}/{len(selected)} IOPSOUND.IRX unit(s) matched ({total_bytes:,} B .text byte-identical).")
    if (not args.unit and not args.units_file) or args.write_progress:
        _write_progress(irx, funcs, matched_units)
    return 0


if __name__ == "__main__":
    sys.exit(main())
