# Final Fantasy X decompilation

Recreating Final Fantasy X for PS2 (PAL, `SCES_504.90`) in C,
with compiled code that matches the original game.

## Progress

| Part | Files | Code in C | Decompilable C | Functions in C |
|---|---:|---:|---:|---:|
| Main ELF | 1 | 64.52% | 78.52% | 10,486 / 11,612 (90.30%) |
| Completed overlays | 283 | 100% | 100% | 47,146 / 47,146 (100%) |
| Partially decompiled overlays | 301 | 68.63% | 89.58% | 47,740 / 52,404 (91.10%) |

**About 77.46% of known EE code** (**92.09%** excluding handwritten policy assembly) by code size and **94.79% of functions** (105,372 / 111,162; 2,198 / 4,220 distinct overlay functions).
All 584 overlays combined are **79.01%** matched in C (**93.66%** of decompilable overlay code, excluding 2.71 MB of handwritten VU0/MMI policy assembly).
Overlay sizes and function counts are estimates; shared code counts in each overlay. This excludes IOP and VU code.

Every one of the 584 known overlays now has matching C code.
Run `python3 -P tools/status.py` for current numbers.

## Getting started

You'll need Python 3, Docker and your own PAL game ISO.
See the [build instructions](docs/BUILD.md).

For contributors: [source layout](docs/LAYOUT.md), [coding style](docs/STYLE.md)
and [overlay guide](overlays/README.md).
