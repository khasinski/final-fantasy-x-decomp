# Final Fantasy X decompilation

Recreating Final Fantasy X for PS2 (PAL, `SCES_504.90`) in C,
with compiled code that matches the original game.

## Progress

| Part | Files | Code in C |
|---|---:|---:|
| Main ELF | 1 | 46.39% |
| Completed overlays | 47 | 100% |
| Partially decompiled overlays | 528 | 38.37% |
| Untouched overlays | 9 | 0% |

**About 39.47% of known EE code**, measured by code size. Overlay sizes are estimates;
shared code counts in each overlay. This excludes IOP and VU code.

Run `python3 -P tools/status.py` for current numbers.

## Getting started

You'll need Python 3, Docker and your own PAL game ISO.
See the [build instructions](docs/BUILD.md).

For contributors: [source layout](docs/LAYOUT.md), [coding style](docs/STYLE.md)
and [overlay guide](overlays/README.md).
