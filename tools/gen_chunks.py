#!/usr/bin/env python3
"""Write config/symbol_addrs.txt and the splat segment list from config/funcs.txt and config/units.txt."""
import os

OFF = 0xFF000  # vram - file offset
funcs = [(n, int(a, 16), int(s, 16)) for n, a, s in (l.split() for l in open("config/funcs.txt"))]
chunks = [
    (f[0], int(f[1], 16), int(f[2], 16))
    for f in (l.rstrip("\n").split("\t") for l in open("config/units.txt") if l.strip() and not l.startswith("#"))
]

with open("config/symbol_addrs.txt", "w") as f:
    for n, a, s in funcs:
        f.write(f"{n} = {a:#010x}; // type:func size:{s:#x}\n")
    f.write(open("config/symbols_extra.txt").read())
    if os.path.exists("config/names_applied.tsv"):
        for l in open("config/names_applied.tsv"):
            r = l.rstrip("\n").split("\t")
            if not l.startswith("#") and len(r) > 3 and r[3] == "data":
                f.write(f"{r[2]} = {int(r[0], 16):#010x};\n")

y = open("config/SCES_504.90.yaml").read()
head = y[: y.index("subsegments:") + len("subsegments:")]
tail = y[y.index("      - [0x201500, data, data]") :]
seg = "\n      - [0x1000, asm, text]\n"
for n, a, _b in chunks:
    seg += f"      - [{a - OFF:#x}, c, {n}]\n"
open("config/SCES_504.90.yaml", "w").write(head + seg + tail)
print(len(chunks), "units")
