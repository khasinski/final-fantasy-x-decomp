# Final Fantasy X decompilation

Recreating Final Fantasy X for PS2 (PAL, `SCES_504.90`) in C,
with compiled code that matches the original game.

## Progress

| Part | Files | Code in C | Functions in C |
|---|---:|---:|---:|
| Main ELF | 1 | 50.02% | 10,091 / 11,612 (86.90%) |
| Completed overlays | 58 | 100% | 1,222 / 1,222 (100%) |
| Partially decompiled overlays | 526 | 38.24% | 51,239 / 98,328 (52.11%) |

**About 39.92% of known EE code** by code size and **56.27% of functions** (62,552 / 111,162; 789 / 4,220 distinct overlay functions).
Overlay sizes and function counts are estimates; shared code counts in each overlay. This excludes IOP and VU code.

Every one of the 584 known overlays now has matching C code.
Run `python3 -P tools/status.py` for current numbers.

## Getting started

You'll need Python 3, Docker and your own PAL game ISO.
See the [build instructions](docs/BUILD.md).

For contributors: [source layout](docs/LAYOUT.md), [coding style](docs/STYLE.md)
and [overlay guide](overlays/README.md).
