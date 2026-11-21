# Final Fantasy X decompilation

Recreating Final Fantasy X for PS2 (PAL, `SCES_504.90`) in C,
with compiled code that matches the original game.

## Progress

| Part | Files | Code in C | Functions in C |
|---|---:|---:|---:|
| Main ELF | 1 | 50.02% | 10,091 / 11,612 (86.90%) |
| Completed overlays | 100 | 100% | 7,486 / 7,486 (100%) |
| Partially decompiled overlays | 484 | 42.23% | 74,041 / 92,064 (80.42%) |

**About 46.21% of known EE code** by code size and **82.42% of functions** (91,618 / 111,162; 1,087 / 4,220 distinct overlay functions).
Overlay sizes and function counts are estimates; shared code counts in each overlay. This excludes IOP and VU code.

Every one of the 584 known overlays now has matching C code.
Run `python3 -P tools/status.py` for current numbers.

## Getting started

You'll need Python 3, Docker and your own PAL game ISO.
See the [build instructions](docs/BUILD.md).

For contributors: [source layout](docs/LAYOUT.md), [coding style](docs/STYLE.md)
and [overlay guide](overlays/README.md).
