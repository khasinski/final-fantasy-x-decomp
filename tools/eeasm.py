#!/usr/bin/env python3
"""Rewrite splat asm into the dialect of the period ee-as (numeric GPR names).

usage: eeasm.py <in_dir> <out_dir> [--prune]
"""
import os, re, sys

R = {"zero": 0, "at": 1, "v0": 2, "v1": 3, "a0": 4, "a1": 5, "a2": 6, "a3": 7,
     "t0": 8, "t1": 9, "t2": 10, "t3": 11, "t4": 12, "t5": 13, "t6": 14, "t7": 15,
     "s0": 16, "s1": 17, "s2": 18, "s3": 19, "s4": 20, "s5": 21, "s6": 22, "s7": 23,
     "t8": 24, "t9": 25, "k0": 26, "k1": 27, "gp": 28, "sp": 29, "fp": 30, "s8": 30, "ra": 31}
NO_ALIGN3_UNITS = set()
if os.path.exists("config/units.txt"):
    for l in open("config/units.txt"):
        if not l.startswith("#") and l.strip():
            f = l.rstrip("\n").split("\t")
            if len(f) > 3 and f[3] == "asm":
                NO_ALIGN3_UNITS.add(f[0])
rx = re.compile(r"\$(" + "|".join(R) + r")\b")
src, dst = sys.argv[1:3]
if "--prune" in sys.argv and os.path.isdir(dst):
    for root, dirs, files in os.walk(dst, topdown=False):
        for f in files:
            o = os.path.join(root, f)
            if f.endswith(".s") and not os.path.exists(os.path.join(src, os.path.relpath(o, dst))):
                os.remove(o)
        if root != dst and not os.listdir(root):
            os.rmdir(root)
for root, _, files in os.walk(src):
    for f in files:
        if not f.endswith(".s"):
            continue
        p = os.path.join(root, f)
        rel = os.path.relpath(p, src)
        unit = os.path.dirname(rel).replace("\\", "/")
        o = os.path.join(dst, rel)
        os.makedirs(os.path.dirname(o), exist_ok=True)
        text = rx.sub(lambda m: f"${R[m[1]]}", open(p).read())
        if unit in NO_ALIGN3_UNITS:
            text = re.sub(r"^\.align 3\n", "", text, flags=re.M)
        # data blobs declared as functions open an .ent with glabel but close with enddlabel
        text = re.sub(r"enddlabel (\w+)", lambda m: ("endlabel " if f"glabel {m[1]}" in text else "enddlabel ") + m[1], text)
        if not os.path.exists(o) or open(o).read() != text:
            open(o, "w").write(text)
