#!/usr/bin/env python3
"""Side-by-side diff of one function: original vs what we built.   (run inside the container)

usage: fdiff.py func_001234AB|RealName [...]      exit 0 if every named function is byte-identical.
A splat name of a function that has a real name now (config/names_applied.tsv) is accepted too.
Looks the function up in the linked ELF (build/SCES_504.90.elf) so a size change earlier in the
image does not confuse it; calls/addresses of later code can still differ if the layout shifted.
"""
import os, re, struct, subprocess, sys
sys.path.append(os.path.dirname(os.path.abspath(__file__)))   # append: tools/dis.py must not shadow `dis`
import ffxsyms  # noqa: E402

OBJDUMP = "mipsel-linux-gnu-objdump"
orig = open("baserom/SCES_504.90", "rb").read()
rom = open("build/SCES_504.90.rom", "rb").read()
funcs = {l.split()[0]: (int(l.split()[1], 16), int(l.split()[2], 16)) for l in open("config/funcs.txt")}
syms = {}
for l in subprocess.run(["mipsel-linux-gnu-nm", "build/SCES_504.90.elf"], capture_output=True, text=True).stdout.splitlines():
    p = l.split()
    if len(p) == 3 and p[1] in "Tt":
        syms[p[2]] = int(p[0], 16)

def dis(blob, vma):
    open("/tmp/_f.bin", "wb").write(blob)
    out = subprocess.run([OBJDUMP, "-D", "-b", "binary", "-m", "mips:5900", "-EL", f"--adjust-vma={vma:#x}", "/tmp/_f.bin"],
                         capture_output=True, text=True).stdout
    rows = []
    for l in out.splitlines():
        m = re.match(r"\s*([0-9a-f]+):\t([0-9a-f]{8})\s+(.*)", l)
        if m:
            rows.append((m[2], m[3].strip()))
    return rows

rc = 0
S = ffxsyms.Syms(".")
for name in sys.argv[1:]:
    if name not in funcs and S.cur(name) in funcs:
        print(f"{name} is {S.cur(name)} (config/names_applied.tsv)")
        name = S.cur(name)
    addr, size = funcs[name]
    got_addr = syms.get(name)
    if got_addr is None:
        print(f"{name}: not defined in the built ELF (still INCLUDE_ASM or misnamed)"); rc = 1; continue
    # compare up to the padded size: the original function slot runs to the next 8-byte boundary
    want = orig[addr - 0xFF000: addr - 0xFF000 + size]
    have = rom[got_addr - 0x100000: got_addr - 0x100000 + size]
    if want == have:
        print(f"{name}: MATCH ({size:#x} bytes)"); continue
    rc = 1
    print(f"{name}: DIFF  orig {addr:#x} size {size:#x}   built {got_addr:#x}")
    a, b = dis(want, addr), dis(have, got_addr)
    for i in range(max(len(a), len(b))):
        x = a[i] if i < len(a) else ("", "")
        y = b[i] if i < len(b) else ("", "")
        flag = " " if x[0] == y[0] else "*"
        print(f" {flag} {x[0]:8} {x[1]:34} | {y[0]:8} {y[1]}")
sys.exit(rc)
