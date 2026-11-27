# Final Fantasy X decompilation

Recreating Final Fantasy X for PS2 (PAL, `SCES_504.90`) in C,
with compiled code that matches the original game.

## Progress

| Part | Files | Code in C | Decompilable C | Functions in C |
|---|---:|---:|---:|---:|
| Main ELF | 1 | 77.40% | 91.48% | 10,821 / 11,612 (93.19%) |
| Completed overlays | 335 | 100% | 100% | 335 / 584 full (+174 100% C policy-only = 509 / 584) |
| Partially decompiled overlays | 249 | 69.42% | 94.81% | 56.95% distinct bytes (72.06% decompilable distinct) |
| IOP (`IOPSOUND.IRX`) | 1 (+24 SDK) | 91.74% | 92.65% | 413 / 422 (97.87%) — 183 C89 units (`binutils 2.9.1`, zero `.s` shims); + 24 SDK IRX |
| VU1 (`.vutext`) | 2 | 100% | 100% | 1,788 / 1,788 insns (14.0 KB microcode, built from `vu/*.vsm`) |

**About 81.90% of known EE code** (**96.79%** excluding handwritten policy assembly) by code size across Main ELF + 584 battle-effect overlays.
All 584 overlays combined are **82.44%** matched in C (**97.42%** of decompilable overlay code, excluding 2.67 MB of handwritten VU0/MMI policy assembly; **509 / 584 = 87.2%** of containers have 0 open C bytes).
Overlay sizes and function counts are estimates; shared code counts in each overlay. See the [IOP & VU1 inventory](docs/IOP_VU_INVENTORY.md) and visual [code map](docs/codemap.svg).

Every one of the 584 known overlays now has matching C code.
Run `python3 -P tools/status.py` for current numbers.

## Getting started

You'll need Python 3, Docker and your own PAL game ISO.
See the [build instructions](docs/BUILD.md).

For contributors: [source layout](docs/LAYOUT.md), [coding style](docs/STYLE.md)
and [overlay guide](overlays/README.md).
