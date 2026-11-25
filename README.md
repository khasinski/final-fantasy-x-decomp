# Final Fantasy X decompilation

Recreating Final Fantasy X for PS2 (PAL, `SCES_504.90`) in C,
with compiled code that matches the original game.

## Progress

| Part | Files | Code in C | Decompilable C | Functions in C |
|---|---:|---:|---:|---:|
| Main ELF | 1 | 75.04% | 88.94% | 10,751 / 11,612 (92.59%) |
| Completed overlays | 331 | 100% | 100% | 58,711 / 58,711 (100%) |
| Partially decompiled overlays | 253 | 67.23% | 91.49% | 37,398 / 40,839 (91.57%) |

**About 80.29% of known EE code** (**94.97%** excluding handwritten policy assembly) by code size and **96.13% of functions** (106,860 / 111,162; 2,746 / 4,220 distinct overlay functions).
All 584 overlays combined are **80.91%** matched in C (**95.69%** of decompilable overlay code, excluding 2.68 MB of handwritten VU0/MMI policy assembly).
Overlay sizes and function counts are estimates; shared code counts in each overlay. This excludes IOP and VU code.

Every one of the 584 known overlays now has matching C code.
Run `python3 -P tools/status.py` for current numbers.

## Getting started

You'll need Python 3, Docker and your own PAL game ISO.
See the [build instructions](docs/BUILD.md).

For contributors: [source layout](docs/LAYOUT.md), [coding style](docs/STYLE.md)
and [overlay guide](overlays/README.md).
