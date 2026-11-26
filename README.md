# Final Fantasy X decompilation

Recreating Final Fantasy X for PS2 (PAL, `SCES_504.90`) in C,
with compiled code that matches the original game.

## Progress

| Part | Files | Code in C | Decompilable C | Functions in C |
|---|---:|---:|---:|---:|
| Main ELF | 1 | 77.02% | 91.05% | 10,808 / 11,612 (93.08%) |
| Completed overlays | 331 | 100% | 100% | 58,711 / 58,711 (100%) |
| Partially decompiled overlays | 253 | 67.23% | 91.49% | 37,398 / 40,839 (91.57%) |
| IOP (`IOPSOUND.IRX`) | 1 (+24 SDK) | 51.23% | 51.74% | 301 / 422 (71.33%) — 81 C89 units; + 24 SDK IRX (341.0 KB) |
| VU1 (`.vutext`) | 2 | 100% | 100% | 1,788 / 1,788 insns (14.0 KB microcode, built from `vu/*.vsm`) |

**About 80.50% of known EE code** (**95.20%** excluding handwritten policy assembly) by code size and **96.18% of EE functions** (106,917 / 111,162; 2,746 / 4,220 distinct overlay functions).
All 584 overlays combined are **80.91%** matched in C (**95.69%** of decompilable overlay code, excluding 2.68 MB of handwritten VU0/MMI policy assembly).
Overlay sizes and function counts are estimates; shared code counts in each overlay. See the [IOP & VU1 inventory](docs/IOP_VU_INVENTORY.md) and visual [code map](docs/codemap.svg).

Every one of the 584 known overlays now has matching C code.
Run `python3 -P tools/status.py` for current numbers.

## Getting started

You'll need Python 3, Docker and your own PAL game ISO.
See the [build instructions](docs/BUILD.md).

For contributors: [source layout](docs/LAYOUT.md), [coding style](docs/STYLE.md)
and [overlay guide](overlays/README.md).
