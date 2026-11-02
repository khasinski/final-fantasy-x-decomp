# Period EE Assembler (`2.9-ee-991111b` Branch-Delay Fix)

This directory contains GNU `gas` from Sony's GPL `gnu-ee-binutils-gcc-1.1.tar.gz` (`2.9-ee-991111b`), built as a 32-bit x86 Linux executable (`as`). The C compiler itself remains the unmodified `ee-gcc 2.9-991111-01`.

One generic bug is corrected in `gas/config/tc-mips.c`: the branch-delay scheduler tests `prev_pinfo & INSN_SYNC` instead of `prev_pinfo && INSN_SYNC`. The logical `&&` in `2.9-ee-991111-01` treats any non-zero `prev_pinfo` flag as a `sync` instruction and prevents filling an eligible branch delay slot.

## Rebuilding from Source

Source archive: `gnu-ee-binutils-gcc-1.1.tar.gz`
- SHA-256: `1f518043e252d6eda726386971d52eda26541ab936ea73a9783d73712b595f92`
- Archive URL: `https://web.archive.org/web/20060518234647id_/http://ps2dev.sourceforge.net:80/downloads/ee/gnu-ee-binutils-gcc-1.1.tar.gz`

To rebuild `as` inside Linux (with `gcc-multilib`, `make`, `flex`, `bison`, and `python3`):

```sh
python3 tools/cc/ee-as-delay/build.py /path/to/gnu-ee-binutils-gcc-1.1.tar.gz
```

`config/cflags.txt` selects this assembler for specific units via `-Btools/cc/ee-as-delay/`. The GPLv2 license is included in [`COPYING`](COPYING).
