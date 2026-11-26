# VU1 Microcode (`vu/`)

This directory contains the disassembled, human-readable, 100% byte-matching PS2 VU1 microcode for **Final Fantasy X PAL (`SCES_504.90`)** (`.vutext`, `0x00578e00..0x0057c650` + 48 B alignment padding = `assets/vutext.bin`, 14,464 B).

## Microprograms

| File | Symbol / VMA | Packet Size | VIF MPG Chunks | VU1 Insns | Purpose |
| :--- | :--- | ---: | ---: | ---: | :--- |
| [`vu1_prog1.vsm`](vu1_prog1.vsm) | `D_00578E00` (`0x00578e00..0x00579b00`) | 3,328 B | 2 (`0x0000..0x0ce0`) | 412 | **Character Renderer** (referenced in `src/game/chr/chr_10EA50.c`). Supports culled/double-sided lit meshes, shadow projection (`L_08a8`), and reflection/environment-mapped UV generation (`L_0aa8`). |
| [`vu1_prog2.vsm`](vu1_prog2.vsm) | `D_00579B00` (`0x00579b00..0x0057c640`) | 11,072 B (+ 64 B pad) | 6 (`0x0000..0x2b00`) | 1,376 | **Scene / Map Renderer & 3D Frustum Clipper**. Includes 3 triangle-list pipelines (`L_01b0`, `L_0e38`, `L_14e8`), 4x4 matrix multiply (`L_0d58`), VU1 memory clear (`L_00b0`), direct GS passthrough (`L_0160`), and a full 5-plane Sutherland-Hodgman frustum clipper (`L_1d90..L_2af8`). |
| **Total** | | **14,464 B** | **8** | **1,788** | **100% symbolic VU1 ISA (0 unknown/raw instructions)** |

## Assembling & Verifying

Use [`tools/vu1asm.py`](../tools/vu1asm.py) (zero external dependencies, Python 3):

```bash
# Assemble both microprograms into build/vu/vutext.bin
python3 tools/vu1asm.py build vu/vu1_prog1.vsm vu/vu1_prog2.vsm -o build/vu/vutext.bin

# Verify 100% byte-for-byte + SHA-256 match against assets/vutext.bin
python3 tools/vu1asm.py verify vu/vu1_prog1.vsm vu/vu1_prog2.vsm assets/vutext.bin

# Re-disassemble from assets/vutext.bin (if needed)
python3 tools/vu1asm.py disasm assets/vutext.bin vu/
```

Expected verification SHA-256:
`f69478f81de13637c66f9ae803dc8cd83fcafeb3acc69d300f94899309805f6c`
