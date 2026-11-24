# Final Fantasy X decompilation

Recreating Final Fantasy X for PS2 (PAL, `SCES_504.90`) in C,
with compiled code that matches the original game.

## Progress

| Part | Files | Code in C | Decompilable C | Functions in C |
|---|---:|---:|---:|---:|
| Main ELF | 1 | 70.04% | 84.02% | 10,617 / 11,612 (91.43%) |
| Completed overlays | 316 | 100% | 100% | 54,023 / 54,023 (100%) |
| Partially decompiled overlays | 268 | 68.73% | 91.95% | 41,686 / 45,527 (91.56%) |

**About 79.50% of known EE code** (**94.36%** excluding handwritten policy assembly) by code size and **95.65% of functions** (106,326 / 111,162; 2,725 / 4,220 distinct overlay functions).
All 584 overlays combined are **80.62%** matched in C (**95.58%** of decompilable overlay code, excluding 2.71 MB of handwritten VU0/MMI policy assembly).
Overlay sizes and function counts are estimates; shared code counts in each overlay. This excludes IOP and VU code.

Every one of the 584 known overlays now has matching C code.
Run `python3 -P tools/status.py` for current numbers.

## Getting started

You'll need Python 3, Docker and your own PAL game ISO.
See the [build instructions](docs/BUILD.md).

For contributors: [source layout](docs/LAYOUT.md), [coding style](docs/STYLE.md)
and [overlay guide](overlays/README.md).
