# Final Fantasy X decompilation

Recreating Final Fantasy X for PS2 (PAL, `SCES_504.90`) in C,
with compiled code that matches the original game.

## Progress

| Part | Files | Code in C | Functions in C |
|---|---:|---:|---:|
| Main ELF | 1 | 50.02% | 10,091 / 11,612 (86.90%) |
| Completed overlays | 200 | 100% | 28,291 / 28,291 (100%) |
| Partially decompiled overlays | 384 | 51.75% | 56,040 / 71,259 (78.64%) |

**About 60.46% of known EE code** by code size and **84.94% of functions** (94,422 / 111,162; 1,490 / 4,220 distinct overlay functions).
Overlay sizes and function counts are estimates; shared code counts in each overlay. This excludes IOP and VU code.

Every one of the 584 known overlays now has matching C code.
Run `python3 -P tools/status.py` for current numbers.

## Getting started

You'll need Python 3, Docker and your own PAL game ISO.
See the [build instructions](docs/BUILD.md).

For contributors: [source layout](docs/LAYOUT.md), [coding style](docs/STYLE.md)
and [overlay guide](overlays/README.md).
