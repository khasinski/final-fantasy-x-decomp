#!/usr/bin/env python3
"""Diff one overlay C file against its original container.

usage: tools/ovdiff.py <src.c> <container> <text_start> <text_end> [SYM=ADDR ...] [--ctx N]

Compiles with the project flags inside the ffx-decomp image (re-execs through docker
on non-Linux hosts), links at text_start with the same symbol rules as
overlays/verify_overlays.py and prints a disassembly diff against
build/overlay-audit/overlay-group11-file<container>.bin. In the diff '-' lines are
the original, '+' lines are the build. Exit status 0 means byte-identical.
"""
import difflib
import os
import shutil
import subprocess
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
BASE = 0x01B00000


def main(argv):
    ctx = 2
    if "--ctx" in argv:
        i = argv.index("--ctx")
        ctx = int(argv[i + 1])
        del argv[i:i + 2]
    if len(argv) < 4:
        print(__doc__)
        return 2
    if sys.platform != "linux":
        cmd = ["docker", "run", "--rm", "-v", f"{ROOT}:/work", "-w", "/work", "ffx-decomp",
               "python3", "tools/ovdiff.py", *argv, "--ctx", str(ctx)]
        r = subprocess.run(cmd, capture_output=True, text=True)
        sys.stdout.write("".join(l + "\n" for l in r.stdout.splitlines() if not l.startswith("WARNING")))
        sys.stderr.write("".join(l + "\n" for l in r.stderr.splitlines() if not l.startswith("WARNING")))
        return r.returncode

    os.chdir(ROOT)
    sys.path.insert(0, str(ROOT / "overlays"))
    import verify_overlays as V

    src, cid, ts, te = argv[0], int(argv[1], 0), int(argv[2], 0), int(argv[3], 0)
    syms = {}
    for a in argv[4:]:
        k, v = a.split("=")
        syms[k] = int(v, 0)

    import tempfile
    (ROOT / "build" / "overlays").mkdir(parents=True, exist_ok=True)
    out = Path(tempfile.mkdtemp(prefix="diff", dir=ROOT / "build" / "overlays"))  # pid is always 1 in docker
    try:
        cc = "tools/cc/ee-gcc2.9-991111-01/bin/ee-gcc"
        obj, elf, ld, tbin = out / "u.o", out / "u.elf", out / "u.ld", out / "u.bin"
        r = subprocess.run([cc, "-c", "-O2", "-G0", "-g0", "-Iinclude", "-Ioverlays", src, "-o", str(obj)],
                           capture_output=True, text=True)
        sys.stdout.write(r.stderr)
        if r.returncode:
            print("COMPILE FAILED")
            return 1
        subprocess.run(["mipsel-linux-gnu-objcopy", str(obj), str(obj)], check=True)
        undef = subprocess.run(["mipsel-linux-gnu-nm", "-u", str(obj)], check=True,
                               capture_output=True, text=True).stdout.split()
        funcs = V.load_funcs_txt()
        resident = {}
        for n in undef:
            if n == "U":
                continue
            a = V.resident_symbol(n, funcs)
            if a is not None:
                resident[n] = a
        allsyms = {**V.RESIDENT_SYMS, **resident, **syms}
        lines = [f"{k} = 0x{v:08x};" for k, v in sorted(allsyms.items())]
        ld.write_text("SECTIONS\n{\n"
                      f"    . = 0x{ts:08x};\n"
                      f"    .text : {{ {obj.as_posix()}(.text) }}\n"
                      "    /DISCARD/ : { *(*) }\n}\n" + "\n".join(lines) + "\n")
        r = subprocess.run(["mipsel-linux-gnu-ld", "-EL", "-T", str(ld), "-o", str(elf)],
                           capture_output=True, text=True)
        un = sorted({l.split("`")[-1].rstrip("'") for l in r.stderr.splitlines() if "undefined reference" in l})
        if un:
            print("UNRESOLVED:", " ".join(un))
        if r.returncode:
            print(r.stderr[-600:])
            return 1
        subprocess.run(["mipsel-linux-gnu-objcopy", "-O", "binary", str(elf), str(tbin)], check=True)
        built = tbin.read_bytes()
        orig = (ROOT / "build" / "overlay-audit" / f"overlay-group11-file{cid:05d}.bin").read_bytes()[ts - BASE:te - BASE]
        print(f"built {len(built):#x} bytes, expected {len(orig):#x}")
        if built == orig:
            print("IDENTICAL")
            return 0

        def dis(data, name):
            p = out / name
            p.write_bytes(data)
            t = subprocess.run(["mipsel-linux-gnu-objdump", "-D", "-b", "binary", "-m", "mips:5900", "-EL",
                                f"--adjust-vma={ts}", str(p)], capture_output=True, text=True).stdout
            res = []
            for l in t.splitlines():
                parts = l.split("\t")
                if len(parts) >= 3 and parts[0].strip().endswith(":"):
                    res.append(f"{parts[0].strip():>9} {parts[1].strip()} {parts[2].strip()} {' '.join(parts[3:]).strip()}")
            return res

        a, b = dis(orig, "o.bin"), dis(built, "b.bin")
        # compare without addresses so that a shift does not hide the real diff
        strip = lambda ls: [l.split(" ", 2)[-1] if False else l.split(None, 1)[1] if len(l.split(None, 1)) > 1 else l for l in ls]
        sa, sb = strip(a), strip(b)
        n = 0
        for l in difflib.unified_diff(sa, sb, "orig", "built", n=ctx, lineterm=""):
            print(l)
            n += 1
            if n > 400:
                print("... truncated")
                break
        return 1
    finally:
        shutil.rmtree(out, True)


if __name__ == "__main__":
    sys.exit(main(sys.argv[1:]))
