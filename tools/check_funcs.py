#!/usr/bin/env python3
"""List the functions whose built bytes differ from the original (host or container, no docker needed).

usage: python3 -P tools/check_funcs.py [--units]

Reads build/SCES_504.90.elf (symbol addresses) and build/SCES_504.90.rom, so a size change of one
object does not hide the others: every config/funcs.txt function is looked up by its own symbol and
compared with j/jal targets masked; the first function that moved is reported too.
--units groups the differing functions by config/units.txt unit.
"""
import bisect, os, struct, sys

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))


def elf_symbols(path):
    d = open(path, "rb").read()
    shoff, = struct.unpack_from("<I", d, 0x20)
    shentsize, shnum, _ = struct.unpack_from("<HHH", d, 0x2E)
    sh = [struct.unpack_from("<IIIIIIIIII", d, shoff + i * shentsize) for i in range(shnum)]
    out = {}
    for s in sh:
        if s[1] != 2:                      # SHT_SYMTAB
            continue
        strtab = sh[s[6]]
        for k in range(s[5] // 16):
            nm, val, size, info, oth, shndx = struct.unpack_from("<IIIBBH", d, s[4] + k * 16)
            e = d.index(b"\0", strtab[4] + nm)
            out.setdefault(d[strtab[4] + nm:e].decode(), val)
    return out


def main():
    orig = open(os.path.join(ROOT, "baserom/SCES_504.90"), "rb").read()
    rom = open(os.path.join(ROOT, "build/SCES_504.90.rom"), "rb").read()
    syms = elf_symbols(os.path.join(ROOT, "build/SCES_504.90.elf"))
    def masked(blob):
        """words with the target field of j/jal cleared: a size change shifts every later call"""
        ws = struct.unpack("<%dI" % (len(blob) // 4), blob[:len(blob) // 4 * 4])
        return [w & 0xFC000000 if w >> 26 in (2, 3) else w for w in ws]

    fl = sorted((int(a, 16), int(s, 16), n) for n, a, s in (l.split() for l in open(os.path.join(ROOT, "config/funcs.txt"))))
    bad, moved = [], None
    for i, (a, s, n) in enumerate(fl):
        if a < 0x1008D8 or n not in syms:
            continue
        b = syms[n]
        if b != a and moved is None:
            moved = (n, a, b, fl[i - 1][2])
        if masked(orig[a - 0xFF000:a - 0xFF000 + s]) != masked(rom[b - 0x100000:b - 0x100000 + s]):
            bad.append((a, n, b))
    if moved:
        print(f"layout shifts from {moved[0]} ({moved[1]:#x} -> {moved[2]:#x}); check {moved[3]} and the functions before it")
    if "--units" in sys.argv:
        us = [l.split("\t") for l in open(os.path.join(ROOT, "config/units.txt")) if l.strip() and not l.startswith("#")]
        st = [int(u[1], 16) for u in us]
        grp = {}
        for a, n, b in bad:
            grp.setdefault(us[bisect.bisect_right(st, a) - 1][0], []).append(n)
        for u, ns in grp.items():
            print(f"{u}: {len(ns)} differ: {' '.join(ns[:8])}{' ...' if len(ns) > 8 else ''}")
    else:
        for a, n, b in bad:
            print(f"{n} orig {a:#x} built {b:#x}")
    print(f"{len(bad)} functions differ")
    sys.exit(1 if bad else 0)


if __name__ == "__main__":
    main()
