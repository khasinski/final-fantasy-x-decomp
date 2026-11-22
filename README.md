# Final Fantasy X decompilation

Recreating Final Fantasy X for PS2 (PAL, `SCES_504.90`) in C,
with compiled code that matches the original game.

## Progress

| Part | Files | Code in C | Functions in C |
|---|---:|---:|---:|
| Main ELF | 1 | 54.68% | 10,263 / 11,612 (88.38%) |
| Completed overlays | 200 | 100% | 28,291 / 28,291 (100%) |
| Partially decompiled overlays | 384 | 51.75% | 56,040 / 71,259 (78.64%) |

**About 60.96% of known EE code** by code size and **85.10% of functions** (94,594 / 111,162; 1,490 / 4,220 distinct overlay functions).
Overlay sizes and function counts are estimates; shared code counts in each overlay. This excludes IOP and VU code.

Every one of the 584 known overlays now has matching C code.
Run `python3 -P tools/status.py` for current numbers.

## Getting started

You'll need Python 3, Docker and your own PAL game ISO.
See the [build instructions](docs/BUILD.md).

For contributors: [source layout](docs/LAYOUT.md), [coding style](docs/STYLE.md)
and [overlay guide](overlays/README.md).
