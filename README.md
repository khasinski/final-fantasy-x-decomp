# Final Fantasy X decompilation

Recreating Final Fantasy X for PS2 (PAL, `SCES_504.90`) in C,
with compiled code that matches the original game.

## Progress

| Part | Files | Code in C | Decompilable C | Functions in C |
|---|---:|---:|---:|---:|
| Main ELF | 1 | 67.32% | 81.13% | 10,565 / 11,612 (90.98%) |
| Completed overlays | 301 | 100% | 100% | 51,208 / 51,208 (100%) |
| Partially decompiled overlays | 283 | 68.90% | 91.14% | 44,123 / 48,342 (91.27%) |

**About 78.70% of known EE code** (**93.46%** excluding handwritten policy assembly) by code size and **95.26% of functions** (105,896 / 111,162; 2,472 / 4,220 distinct overlay functions).
All 584 overlays combined are **80.06%** matched in C (**94.91%** of decompilable overlay code, excluding 2.71 MB of handwritten VU0/MMI policy assembly).
Overlay sizes and function counts are estimates; shared code counts in each overlay. This excludes IOP and VU code.

Every one of the 584 known overlays now has matching C code.
Run `python3 -P tools/status.py` for current numbers.

## Getting started

You'll need Python 3, Docker and your own PAL game ISO.
See the [build instructions](docs/BUILD.md).

For contributors: [source layout](docs/LAYOUT.md), [coding style](docs/STYLE.md)
and [overlay guide](overlays/README.md).
