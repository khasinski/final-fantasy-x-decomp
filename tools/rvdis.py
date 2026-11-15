#!/usr/bin/env python3
"""Disassemble a resident-ELF range: rvdis.py <start> [end] (vram>=0x100000)."""
import sys
from pathlib import Path
import rabbitizer

rabbitizer.config.regNames_gprAbiNames = rabbitizer.Abi.O32
rabbitizer.config.regNames_fprAbiNames = rabbitizer.Abi.fromStr("o32")
rabbitizer.config.regNames_namedRegisters = True
rabbitizer.config.toolchainTweaks_gnuMode = True
rabbitizer.config.pseudos_enablePseudos = True
rabbitizer.config.misc_upperCaseImm = True
rabbitizer.config.misc_opcodeLJust = 7

orig = Path("baserom/SCES_504.90").read_bytes()
off, filesz = 0x1000, None
import struct
data = orig[off:off + 0x47cb0c]

def disasm(start, end):
    for a in range(start, end, 4):
        w = int.from_bytes(data[a - 0x100000: a - 0x100000 + 4], "little")
        i = rabbitizer.Instruction(w, vram=a)
        print(f"{a:08x}: {i.disassemble():36s} ; {w:08x}")

if __name__ == "__main__":
    s = int(sys.argv[1], 16)
    e = int(sys.argv[2], 16) if len(sys.argv) > 2 else s + 0x60
    disasm(s, e)