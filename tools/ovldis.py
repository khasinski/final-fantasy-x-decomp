#!/usr/bin/env python3
"""Disassemble a group-0x11 overlay container range: ovldis.py <cid> <start> [end]
Addresses like 01B04818 (0x01B00000 base). Gas-style ABI register names."""
import sys
from pathlib import Path
import rabbitizer

BASE = 0x01B00000
rabbitizer.config.regNames_gprAbiNames = rabbitizer.Abi.O32
rabbitizer.config.regNames_fprAbiNames = rabbitizer.Abi.fromStr("o32")
rabbitizer.config.regNames_namedRegisters = True
rabbitizer.config.toolchainTweaks_gnuMode = True
rabbitizer.config.pseudos_enablePseudos = True
rabbitizer.config.misc_upperCaseImm = True
rabbitizer.config.misc_opcodeLJust = 7

def load(cid):
    return Path(f"build/overlay-audit/overlay-group11-file{cid:05d}.bin").read_bytes()

def disasm(data, start, end):
    off = start - BASE
    for a in range(start, end, 4):
        w = int.from_bytes(data[a - BASE: a - BASE + 4], "little")
        i = rabbitizer.Instruction(w, vram=a)
        d = i.disassemble()
        print(f"{a:08x}: {d:36s} ; {w:08x}")

if __name__ == "__main__":
    cid = int(sys.argv[1], 0)
    start = int(sys.argv[2], 16)
    end = int(sys.argv[3], 16) if len(sys.argv) > 3 else start + 160
    disasm(load(cid), start, end)
