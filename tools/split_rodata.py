#!/usr/bin/env python3
"""Cut splat's single rodata blob into link-order pieces so jump tables can follow their functions.

splat emits asm/data/rodata.rodata.s as one object.  gcc puts the jump table of a `switch` in the
.rodata of the same translation unit, so a function with a switch can only become C if its table
is no longer part of that blob.  This script (run after `splat split`, see Makefile):

  * writes every jump table to asm/nonmatchings/<unit>/rodata/jtbl_XXXXXXXX.s (unit = config/units.txt name),
  * writes the runs of other rodata between the tables to asm/data/rodata/piece_XXXXXXXX.s,
  * records the original order in config/rodata_layout.txt   ("piece <name>" / "jtbl <name> <chunk>"),
  * inserts INCLUDE_RODATA lines after the INCLUDE_ASM of each function that uses a table,
  * deletes the blob.

configure.py turns the layout into the .rodata part of the link script.  Idempotent: it does nothing
when the blob is already gone.
"""
import glob, os, re, sys

sys.path.append(os.path.dirname(os.path.abspath(__file__)))   # append: tools/dis.py must not shadow `dis`
import ffxsyms  # noqa: E402  (rodata items may carry applied real data names, config/names_applied.tsv)
SYMS = ffxsyms.Syms(".")

BLOB = "asm/data/rodata.rodata.s"
if not os.path.exists(BLOB):
    sys.exit("rodata already split")

lines = open(BLOB).read().split("\n")
first = next(i for i, l in enumerate(lines) if l.startswith("nonmatching "))
# the .align line(s) in front of an item belong to that item
while first > 0 and lines[first - 1].strip().startswith(".align"):
    first -= 1
header = "\n".join(lines[:first]).rstrip("\n") + "\n"

items = []  # (name, text)
cur = []
for l in lines[first:]:
    cur.append(l)
    m = re.match(r"enddlabel (\w+)", l)
    if m:
        items.append((m[1], "\n".join(cur) + "\n"))
        cur = []
assert not "".join(cur).strip(), "text after the last rodata item"

# which function uses which table (fall back to config/rodata_layout.txt when function is already C)
users = {}
for p in sorted(glob.glob("asm/nonmatchings/**/*.s", recursive=True)):
    if "/rodata/" in p:
        continue
    for j in set(re.findall(r"jtbl_[0-9A-F]{8}", open(p).read())):
        users.setdefault(j, []).append(p)
known_owners = {}
if os.path.exists("config/rodata_layout.txt"):
    for l in open("config/rodata_layout.txt"):
        f = l.split()
        if len(f) >= 3 and f[0] == "jtbl":
            known_owners[f[1]] = f[2]

os.makedirs("asm/data/rodata", exist_ok=True)
layout, run, run_start = [], [], None


def addr_of(name):
    a = SYMS.addr(name)
    if a is None:
        raise SystemExit(f"split_rodata: no address for {name} (not a splat name, not in config/names_applied.tsv)")
    return a


ADDR_RX = re.compile(r"/\* [0-9A-F]+ ([0-9A-F]{8})")


def absolute(text, base):
    """Placement is explicit (`. = ADDR` in the link script, SUBALIGN(1)), so an .align must not depend
    on where a piece happens to start: turn each one into `.org <offset of the next data line>`,
    or drop it when no data follows inside the item (the gap is zero-filled by the next placement)."""
    out, ls = [], text.split("\n")
    for i, l in enumerate(ls):
        if not l.startswith(".align"):
            out.append(l)
            continue
        for k in ls[i + 1:]:
            m = ADDR_RX.search(k)
            if m:
                out.append(f".org {int(m[1], 16) - base:#x}")
                break
            if k.startswith("enddlabel"):
                break
    return "\n".join(out)


def flush():
    global run, run_start
    if run:
        name = f"piece_{run_start}"
        base = int(run_start, 16)
        body = "".join((f".org {addr_of(n) - base:#x}\n" if addr_of(n) > base else "") + absolute(t, base)
                       for n, t in run)
        open(f"asm/data/rodata/{name}.s", "w").write(header + "\n" + body)
        layout.append(f"piece {name} {base:#x}")
        run = []


func_tables = {}
for name, text in items:
    if not name.startswith("jtbl_"):
        if not run:
            run_start = f"{addr_of(name):08X}"
        run.append((name, text))
        continue
    flush()
    if name in users:
        (path,) = users[name]          # a table is used by exactly one function
        chunk = os.path.relpath(os.path.dirname(path), "asm/nonmatchings")   # the unit name
        func_tables.setdefault((chunk, os.path.basename(path)[:-2]), []).append(name)
    else:
        chunk = known_owners[name]
    d = f"asm/nonmatchings/{chunk}/rodata"
    os.makedirs(d, exist_ok=True)
    open(f"{d}/{name}.s", "w").write(absolute(text, addr_of(name)))
    layout.append(f"jtbl {name} {chunk} {addr_of(name):#x}")
flush()
open("config/rodata_layout.txt", "w").write("\n".join(layout) + "\n")

# INCLUDE_RODATA after each INCLUDE_ASM that owns tables
for (chunk, func), tbls in func_tables.items():
    src = f"src/{chunk}.c"
    t = open(src).read()
    m = re.search(rf'INCLUDE_ASM\("[^"]+",\s*{func}\);\n', t)
    if not m:
        continue  # function already C, its gcc table lands in the chunk's own .rodata
    add = "".join(
        f'INCLUDE_RODATA("build/ee_asm/{chunk}/rodata", {j});\n'
        for j in sorted(tbls)
        if f'INCLUDE_RODATA("build/ee_asm/{chunk}/rodata", {j});' not in t
    )
    if add:
        t = t[:m.end()] + add + t[m.end():]
        open(src, "w").write(t)

os.remove(BLOB)
print(f"{len(items)} items -> {sum(1 for l in layout if l.startswith('piece'))} pieces, "
      f"{sum(1 for l in layout if l.startswith('jtbl'))} jump tables")
