# Final Fantasy X decompilation

Recreating Final Fantasy X for PS2 (PAL, `SCES_504.90`) in C,
with compiled code that matches the original game.

## Progress

| Part | Files | Code in C | Functions in C |
|---|---:|---:|---:|
| Main ELF | 1 | 56.20% | 10,329 / 11,612 (88.95%) |
| Completed overlays | 200 | 100% | 28,291 / 28,291 (100%) |
| Partially decompiled overlays | 384 | 57.13% | 60,851 / 71,259 (85.39%) |

**About 64.94% of known EE code** by code size and **89.48% of functions** (99,471 / 111,162; 1,534 / 4,220 distinct overlay functions).
Overlay sizes and function counts are estimates; shared code counts in each overlay. This excludes IOP and VU code.

Every one of the 584 known overlays now has matching C code.
Run `python3 -P tools/status.py` for current numbers.

## Getting started

You'll need Python 3, Docker and your own PAL game ISO.
See the [build instructions](docs/BUILD.md).

For contributors: [source layout](docs/LAYOUT.md), [coding style](docs/STYLE.md)
and [overlay guide](overlays/README.md).
