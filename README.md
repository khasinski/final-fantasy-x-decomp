# Final Fantasy X decompilation

Recreating Final Fantasy X for PS2 (PAL, `SCES_504.90`) in C,
with compiled code that matches the original game.

## Progress

| Part | Files | Code in C | Functions in C |
|---|---:|---:|---:|
| Main ELF | 1 | 60.04% | 10,410 / 11,612 (89.65%) |
| Completed overlays | 220 | 100% | 32,774 / 32,774 (100%) |
| Partially decompiled overlays | 364 | 58.55% | 58,130 / 66,776 (87.05%) |

**About 67.33% of known EE code** by code size and **91.14% of functions** (101,314 / 111,162; 1,672 / 4,220 distinct overlay functions).
Overlay sizes and function counts are estimates; shared code counts in each overlay. This excludes IOP and VU code.

Every one of the 584 known overlays now has matching C code.
Run `python3 -P tools/status.py` for current numbers.

## Getting started

You'll need Python 3, Docker and your own PAL game ISO.
See the [build instructions](docs/BUILD.md).

For contributors: [source layout](docs/LAYOUT.md), [coding style](docs/STYLE.md)
and [overlay guide](overlays/README.md).
