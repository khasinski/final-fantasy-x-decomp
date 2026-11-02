#!/usr/bin/env python3
"""Compile one chunk with ee-gcc, giving every gcc-emitted jump table its own input section.

usage: ccwrap.py <cc> <src.c> <out.o> <cflags...>

gcc 2.9 emits each `switch` table as a `.rdata` block (`.align 4`, `$Ln:`, `.word $Lm`...) in the middle of
the function, so a chunk's tables all end up in one .rodata input section and the linker could only place
them together.  This wrapper runs `gcc -S`, renames the k-th table block of the chunk to
`.rodata.cjt<k>` (k counts from 0 in emission order = source order) and assembles the result.  The object
is otherwise byte-identical to a direct `gcc -c` (checked).  configure.py maps `.rodata.cjt<k>` to the
k-th C-owned table of the chunk in config/rodata_layout.txt, so tables of one chunk may be separated
by any amount of other rodata.

Any other .rdata block (string literal, float constant, non-table data) is left in plain `.rodata`;
configure.py cannot place it, so this wrapper fails the build with a clear message instead.
"""
import os, re, subprocess, sys, tempfile

cc, src, out, *flags = sys.argv[1:]
tmp = tempfile.mkdtemp()
s = os.path.join(tmp, "x.s")
subprocess.run([cc, "-S", *flags, src, "-o", s], check=True)
lines = open(s).read().split("\n")
res, k, i = [], 0, 0
other = False
while i < len(lines):
    l = lines[i]
    if l.strip() in (".rdata", ".section .rodata", ".section\t.rodata"):
        j = i + 1
        while j < len(lines) and not re.match(r"\s*(\.text|\.section|\.data|\.sdata|\.rdata|\.lit4|\.lit8|\.bss|\.sbss)\b", lines[j]):
            j += 1
        body = lines[i + 1:j]
        body_nc = [b for b in body if b.strip()]
        table = body_nc and all(re.match(r"\s*(\.align\s+\d+|\$L\d+:|\.word\s+\$L\d+)\s*$", b) for b in body_nc) \
            and any(b.strip().startswith(".word") for b in body_nc)
        if table:
            res.append(f'\t.section .rodata.cjt{k},"a"')
            k += 1
        else:
            other = True
            res.append(l)
        res.extend(body)
        i = j
        continue
    res.append(l)
    i += 1
if other:
    sys.stderr.write(f"ccwrap: {src}: non-jump-table .rodata emitted by gcc (string literal / float constant?); "
                     "configure.py cannot place it. Use extern data from the existing rodata.\n")
    sys.exit(1)
open(s, "w").write("\n".join(res))
r = subprocess.run([cc, "-c", *[f for f in flags if not f.startswith("-I") and not f.startswith("-D")], s, "-o", out])
sys.exit(r.returncode)
