#!/usr/bin/env python3
"""List every jump-table (switch) function and whether it is still asm or already C.

usage: tools/switch_status.py [--todo] [--unit <unit>]      (--chunk is an alias of --unit)

<unit> is a config/units.txt name (e.g. game/rc/bg/rcbgFP, game/menu/tk/tk_22CE70) = the owner column of
config/rodata_layout.txt.  Since tools/ccwrap.py puts each gcc table in its own section, every asm
switch function is convertible regardless of the rodata between the tables; the remaining
constraints are checked here:
  * source order: the k-th C-owned table of a unit (layout order) must belong to the k-th C switch
    function in the unit's .c file (gcc emits tables in source order) -> 'ORDER' error if not;
  * a table used by more than one function ('shared') cannot be emitted by one gcc switch;
  * function size is shown to help pick easy ones.
"""
import glob, os, re, sys

todo = "--todo" in sys.argv
opt = "--unit" if "--unit" in sys.argv else "--chunk"
only = sys.argv[sys.argv.index(opt) + 1] if opt in sys.argv else None
lay = [l.split() for l in open("config/rodata_layout.txt")]
tbls = [(f[1], f[2], int(f[3], 16)) for f in lay if f and f[0] == "jtbl"]
users = {}
# function files: any name (splat func_XXXXXXXX or a real name, config/names_applied.tsv); not rodata/
files = [p for p in glob.glob("asm/nonmatchings/**/*.s", recursive=True) if "/rodata/" not in p]
have = {os.path.basename(p) for p in files}
files += [p for p in glob.glob("build/ee_asm/**/*.s", recursive=True) if "/rodata/" not in p and os.path.basename(p) not in have]
for p in files:                     # build/ee_asm keeps the asm of functions whose .s was dropped
    for j in set(re.findall(r"jtbl_[0-9A-F]{8}", open(p).read())):
        users.setdefault(j, []).append(os.path.basename(p)[:-2])
sizes = {l.split()[0]: int(l.split()[2], 16) for l in open("config/funcs.txt")}
rows, errors, nasm, nc, ksz = [], [], 0, 0, 0
for unit in sorted({t[1] for t in tbls}):
    if only and unit != only:
        continue
    src = open(f"src/{unit}.c").read()
    own = [t for t in tbls if t[1] == unit and f'rodata", {t[0]})' not in src]
    # function order in the source for C-owned tables
    pos = lambda fn: (re.search(rf"^[^\n;]*\b{fn}\s*\([^;]*?\)\s*\n?\s*\{{", src, re.M) or re.search(fn, src)).start()
    try:
        fo = [pos(users[t[0]][0]) for t in own]
        if fo != sorted(fo):
            errors.append(f"ORDER {unit}: C-owned tables are not in source order of their functions")
    except (AttributeError, KeyError):
        pass
    for t, j, a in [x for x in tbls if x[1] == unit]:
        fs = users.get(t, ["?"])
        asm = f'rodata", {t})' in src
        st = "asm" if asm else "C"
        note = "shared" if len(fs) > 1 else ""
        nasm += asm; nc += not asm
        if asm:
            ksz += sum(sizes.get(f, 0) for f in fs[:1])
        if not (todo and not asm):
            rows.append(f"{unit:24s} {fs[0]:14s} {t} {st:4s} {sizes.get(fs[0], 0):#7x} {note}")
print("\n".join(rows))
print(f"# {nc} C, {nasm} asm (convertible: all asm without a 'shared' note); asm code {ksz} bytes")
for e in errors:
    print(e)
