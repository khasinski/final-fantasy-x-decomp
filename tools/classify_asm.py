#!/usr/bin/env python3
"""Seed config/handwritten.txt: functions whose asm uses instructions ee-gcc 2.9 does not emit from C.

usage: classify_asm.py [--write | --add]
  (prints a summary; --write rewrites config/handwritten.txt, --add only appends functions that are
   flagged but not listed yet, e.g. after tools/split_funcs.py, and reports listed functions that
   the classifier no longer flags without touching them)

Categories (see docs/ASM_POLICY.md):
  syscall   `syscall`                                     -> never C
  cop0      mfc0 mtc0 ei di eret cache tlb* bc0*          -> never C
  cop2      lqc2 sqc2 qmfc2 qmtc2 cfc2 ctc2 v* bc2*       -> VU0 macro mode, inline-asm candidate
  mmi       lq sq and the R5900 multimedia ops (p*, *1)   -> inline-asm candidate
  sdk       splat marked it `Handwritten function`        -> never C
An instruction counts only if no function we already matched from C contains it (lq/sq, for example,
are ordinary compiler output for 128-bit copies).
Functions that are already C are skipped.  A function can carry several categories.
Entries already in the file keep their hand-written note (third column); entries with a category the
classifier cannot detect (nop-loop, convention, noreturn, sq-zero) are kept as they are.
"""
import glob, os, re, sys

MMI = (r"lq|sq|madd1|maddu1|mult1|multu1|div1|divu1|mfhi1|mflo1|mthi1|mtlo1|mfsa|mtsa|plzcw|pmfhl|pmthl|"
       r"pabs[hw]|padd(?:[bhw]|s[bhw]|u[bhw]|sb|sh|sw|ub|uh|uw)|psub(?:[bhw]|s[bhw]|u[bhw])|pcgt[bhw]|pceq[bhw]|"
       r"pmax[hw]|pmin[hw]|pand|por|pxor|pnor|pext[lu][bhw]|ppac[bhw]|pcpy(?:ld|ud|h)|pinth|pinteh|prev[h]?|"
       r"pexch|pexeh|pexew|pexcw|prot3w|psll[hvw]|psra[hvw]|psrl[hvw]|pmadd[hwu]*|pmsub[hw]|pmult[hwu]*|pdiv[bwu]*|"
       r"phmadh|phmsbh|pmfhi|pmflo|pmthi|pmtlo|qfsrv")
RX = {
    "syscall": re.compile(r"^syscall$"),
    "cop0": re.compile(r"^(mfc0|mtc0|ei|di|eret|cache|tlb\w+|bc0\w*|mfbpc|mtbpc|mfps|mtps|mfpc|mtpc)$"),
    "cop2": re.compile(r"^(lqc2|sqc2|qmfc2|qmtc2|cfc2|ctc2|mfc2|mtc2|bc2\w+|v[a-z0-9]+(\.\w+)?)$"),
    "mmi": re.compile(rf"^({MMI})$"),
}
INSN = re.compile(r"\*/\s+([a-z][a-z0-9.]*)\b")

funcs = {l.split()[0]: int(l.split()[2], 16) for l in open("config/funcs.txt")}
c_defined = set()
for p in glob.glob("src/**/*.c", recursive=True):
    c_defined.update(n for n in re.findall(r"^[A-Za-z_][\w \*]*?\b([A-Za-z_]\w*)\s*\([^;{]*\)\s*(?:[^;{}()]*;\s*)*\{", open(p).read(), re.M)
                     if n in funcs)     # any funcs.txt name: func_XXXXXXXX or an applied real name

MANUAL = {"nop-loop", "convention", "noreturn", "sq-zero"}   # categories the classifier cannot detect: added by hand, kept
old, manual = {}, {}
if os.path.exists("config/handwritten.txt"):
    for l in open("config/handwritten.txt"):
        f = l.rstrip("\n").split(None, 2)
        if len(f) >= 2 and not l.startswith("#"):
            old[f[0]] = f[2] if len(f) > 2 else ""
            if f[1] in MANUAL:
                manual[f[0]] = (f[1], f[2] if len(f) > 2 else "")

# instructions ee-gcc demonstrably emits: everything that occurs in a function we matched from C
compiler = set()
ASM = [p for p in glob.glob("asm/nonmatchings/**/*.s", recursive=True) if os.path.basename(p)[:-2] in funcs]
for p in ASM:
    if os.path.basename(p)[:-2] in c_defined:
        compiler.update(INSN.findall(open(p).read()))

found = {}
for p in sorted(ASM):
    name = os.path.basename(p)[:-2]
    if name in c_defined:
        continue
    text = open(p).read()
    cats = set()
    if "Handwritten function" in text:
        cats.add("sdk")
    for line in text.split("\n"):
        m = INSN.search(line)
        if not m:
            continue
        ins = m[1]
        if ins in compiler:
            continue
        for cat, rx in RX.items():
            if rx.match(ins):
                cats.add(cat)
    if cats:
        found[name] = cats

by = {}
for n, c in found.items():
    by.setdefault(",".join(sorted(c)), []).append(n)
for k, v in sorted(by.items(), key=lambda kv: -len(kv[1])):
    print(f"{k:16} {len(v):5} funcs {sum(funcs.get(n, 0) for n in v):#8x} bytes")
print(f"total {len(found)} funcs, {sum(funcs.get(n, 0) for n in found):#x} bytes")

if "--write" in sys.argv:
    with open("config/handwritten.txt", "w") as f:
        f.write("# Functions that ee-gcc 2.9 cannot produce from C (see docs/ASM_POLICY.md).\n"
                "# <function> <categories> [note].  Regenerate with `tools/classify_asm.py --write`;\n"
                "# the note column is kept.  These stay INCLUDE_ASM and are reported separately by status.py.\n")
        for n in sorted(set(found) | set(manual)):
            if n in manual:
                f.write(f"{n} {manual[n][0]} {manual[n][1]}".rstrip() + "\n")
            else:
                f.write(f"{n} {','.join(sorted(found[n]))}" + (f" {old[n]}" if old.get(n) else "") + "\n")

if "--add" in sys.argv:
    lines = open("config/handwritten.txt").read().rstrip("\n").split("\n")
    listed = {l.split()[0] for l in lines if l.strip() and not l.startswith("#")}
    add = sorted(n for n in found if n not in listed)
    stale = sorted(n for n in listed if n not in found and n not in manual and n in funcs)
    head = [l for l in lines if l.startswith("#")]
    body = [l for l in lines if l.strip() and not l.startswith("#")] + [f"{n} {','.join(sorted(found[n]))}" for n in add]
    body.sort(key=lambda l: l.split()[0])
    open("config/handwritten.txt", "w").write("\n".join(head + body) + "\n")
    print(f"added {len(add)}: {' '.join(add)}")
    print(f"listed but not flagged any more ({len(stale)}): {' '.join(stale)}")
