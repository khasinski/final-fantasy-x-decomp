#!/usr/bin/env python3
"""Generate build.ninja for SCES_504.90 (FFX PAL).

Pipeline: splat -> asm/*.s (+ src/*.c as functions get matched) -> objects -> ld -> objcopy -> sha1 check.
Compiler: ee-gcc 2.9-991111-01, -O2 -G0 (confirmed by matching real functions).
Run the generated build inside the Docker image: `make build`.
"""
import glob, os, re, json
import ninja_syntax

CC = "tools/cc/ee-gcc2.9-991111-01/bin/ee-gcc"
CROSS = "mipsel-linux-gnu-"
CFLAGS = "-O2 -G0 -g0 -Iinclude -DINCLUDE_ASM_USE_MACRO_INC=0"
ASFLAGS = "-EL -march=r5900 -mabi=eabi -G0 -no-pad-sections -I include"

# link script: .text lists the units (translation units and assembler objects, config/units.txt,
# src/game/... and src/sdk/..., docs/LAYOUT.md) in address order; every src/**/*.c must be one of them
chunks = [l.split("\t")[0] for l in open("config/units.txt") if l.strip() and not l.startswith("#")]
_srcs = {os.path.relpath(c, "src")[:-2] for c in glob.glob("src/**/*.c", recursive=True)}
if _srcs != set(chunks):
    raise SystemExit(f"configure.py: src/ and config/units.txt disagree: only in src {sorted(_srcs - set(chunks))[:5]}, "
                     f"only in units {sorted(set(chunks) - _srcs)[:5]}")
text_objs = "\n".join(f"        build/{p}.o(.text)" for p in ["asm/text.s"] + [f"src/{c}.c" for c in chunks])


# Explicit ownership of compiler-emitted literal blocks, verified by ccwrap.
C_RODATA = json.load(open("config/c_rodata.json")) if os.path.exists("config/c_rodata.json") else {}
C_PIECES = {}
C_SKIP_PIECES = set()
for _unit, _v in C_RODATA.items():
    _plist = _v["piece"] if isinstance(_v["piece"], list) else [_v["piece"]]
    C_PIECES[_plist[0]] = (_unit, _v)
    C_SKIP_PIECES.update(_plist[1:])


def rodata_objs():
    """.rodata in original order: blob pieces, and each jump table either from its INCLUDE_RODATA
    section (function still asm) or from the chunk's own .rodata (function is C: gcc emitted it)."""
    src = {c: open(f"src/{c}.c").read() for c in chunks}
    out, nown = [], {}
    for l in open("config/rodata_layout.txt"):
        f = l.split()
        if f[0] == "piece":
            if f[1] in C_SKIP_PIECES:
                continue
            if f[1] in C_PIECES:
                unit, literal = C_PIECES[f[1]]
                assert int(f[2], 16) == literal["address"]
                out.append(f"        . = {f[2]} - 0x568f00;\n        build/src/{unit}.c.o(.rodata)")
            else:
                out.append(f"        . = {f[2]} - 0x568f00;\n        build/asm/data/rodata/{f[1]}.s.o(.rodata)")
            continue
        _, tbl, chunk, addr = f
        # Split units may still include assembly from their original directory.
        if re.search(r'\bINCLUDE_RODATA\("[^"\n]+",\s*' + re.escape(tbl) + r'\)', src[chunk]):
            out.append(f"        . = {addr} - 0x568f00;\n        build/src/{chunk}.c.o(.rodata.{tbl})")
        else:   # C function: tools/ccwrap.py names the k-th gcc table of the chunk .rodata.cjt<k> (source order)
            k = nown.get(chunk, 0); nown[chunk] = k + 1
            out.append(f"        . = {addr} - 0x568f00;\n        build/src/{chunk}.c.o(.rodata.cjt{k})")
    return "\n".join(out)


open("config/SCES_504.90.link.ld", "w").write(
    open("config/SCES_504.90.link.ld.in").read().replace("@TEXT_OBJS@", text_objs)
    .replace("@RODATA_OBJS@", rodata_objs()) + "\n" + "\n".join(
        f"{symbol} = {literal['address'] + offset:#x};"
        for literal in C_RODATA.values() for symbol, offset in literal["symbols"].items()))

# per-file compiler flag overrides: "<unit> <flags...>" (a few objects were built with other options)
EXTRA = {}
if os.path.exists("config/cflags.txt"):
    for l in open("config/cflags.txt"):
        if l.strip() and not l.startswith("#"):
            k, _, v = l.strip().partition(" "); EXTRA[k] = v

n = ninja_syntax.Writer(open("build.ninja", "w"))
n.variable("ld_script", "config/SCES_504.90.link.ld")
n.rule("as", command=f"{CROSS}as {ASFLAGS} $in -o $out", description="as $in")
# the period as writes a symtab modern ld rejects; objcopy rewrites it
n.rule("cc", command=f"python3 tools/ccwrap.py {CC} $in $out {CFLAGS} $extra && {CROSS}objcopy $out $out", description="cc $in")
n.rule("ld", command=f"{CROSS}ld -EL -T $ld_script -Map $map --no-check-sections -o $out",
       description="ld $out")
# gas rounds the last .data object up to 16 bytes (lit4 is 0x48c long), so cut the
# image to the original LOAD segment size.
ROM_SIZE = 0x47CB0C
n.rule("rom", command=f"{CROSS}objcopy -O binary $in $out && truncate -s {ROM_SIZE} $out",
       description="rom $out")
n.rule("check", command="python3 tools/check.py $in", description="sha1 check")

objs = []
for s in sorted(glob.glob("asm/**/*.s", recursive=True)):
    if s in {f"asm/data/rodata/{piece}.s" for piece in (set(C_PIECES) | C_SKIP_PIECES)}:
        continue  # this exact block now comes from the compiler
    if s.startswith("asm/nonmatchings/"):
        continue  # pulled into src/*.c through INCLUDE_ASM
    o = f"build/{s}.o"; n.build(o, "as", s); objs.append(o)
for c in sorted(glob.glob("src/**/*.c", recursive=True)):
    o = f"build/{c}.o"
    stem = os.path.relpath(c, "src")[:-2]          # unit name, the key of config/cflags.txt
    deps = ["include/ee_labels.inc", "include/asm_include.h", "include/common.h"] + glob.glob("include/ffx/*.h")
    # A split chunk may retain INCLUDE_ASM bodies in its original folder.
    folders = set(re.findall(r'INCLUDE_(?:ASM|RODATA)\("([^\"]+)"', open(c).read()))
    for folder in folders:
        deps += glob.glob(f"{folder}/**/*.s", recursive=True)
    if "-Btools/cc/ee-as-delay/" in EXTRA.get(stem, ""):
        deps.append("tools/cc/ee-as-delay/as")
    n.build(o, "cc", c, implicit=deps + ["config/cflags.txt", "tools/ccwrap.py"] + (["config/c_rodata.json"] if C_RODATA else []), variables={"extra": EXTRA.get(stem, "")}); objs.append(o)
for b in sorted(glob.glob("assets/*.bin")):
    # wrap raw blobs in a tiny .s so they get the same r5900/eabi flags as everything else
    wrap = f"build/{b}.s"
    os.makedirs(os.path.dirname(wrap), exist_ok=True)
    with open(wrap, "w") as f:
        f.write(f'.section .data\n.incbin "{b}"\n')
    o = f"build/{b}.o"; n.build(o, "as", wrap, implicit=[b]); objs.append(o)

n.build("build/SCES_504.90.elf", "ld", objs, implicit=["config/SCES_504.90.link.ld",
        "config/undefined_syms_auto.txt", "config/undefined_funcs_auto.txt"],
        variables={"map": "build/SCES_504.90.map"})
n.build("build/SCES_504.90.rom", "rom", "build/SCES_504.90.elf")
n.build("check", "check", "build/SCES_504.90.rom", implicit_outputs=[])
n.default("check")
