# EE Battle-Effect Overlays (`group 0x11`)

Byte-matching C89 decompilations of PlayStation 2 Emotion Engine (EE) battle-effect overlays loaded at `0x01B00000` (`baserom/Final Fantasy X (Europe, Australia).iso`, PAL `SCES_504.90`).

## Verification

Run the standalone overlay verifier (automatically uses the `ffx-decomp` Docker container when invoked on macOS):

```bash
python3 overlays/verify_overlays.py
```

For each unit, [`overlays/verify_overlays.py`](verify_overlays.py):
1. Compiles the C source with `ee-gcc 2.9-991111-01 -c -O2 -G0 -g0 -Iinclude -Ioverlays`.
2. Links the object at its fixed `.text` virtual address (`0x01B00xxx`) against resident ELF symbols (`SCES_504.90`) and overlay-local `.data`/`.bss` addresses.
3. Verifies 100% byte-for-byte `.text` identity against `build/overlay-audit/overlay-group11-fileXXXXX.bin` and confirms the reconstructed container matches the original SHA-256.

## Matched Units (15 Unique C Units / 20 Containers)

| C Unit | Containers (`group 0x11`) | `.text` Range | `.text` Span | Discovered Insns | Functions | Subsystem |
|---|---|---|---:|---:|---:|---|
| [`overlays/group11/ovl_09551.c`](group11/ovl_09551.c) | `file09551` | `0x01B00530..0x01B00720` | 496 B | 460 B | 13 | `rcef` |
| [`overlays/group11/ovl_09380.c`](group11/ovl_09380.c) | `file09380`, `file09407` | `0x01B00468..0x01B007B0` | 840 B | 792 B | 16 | `rcef` |
| [`overlays/group11/ovl_09379.c`](group11/ovl_09379.c) | `file09379`, `file09406` | `0x01B00558..0x01B008E0` | 904 B | 856 B | 17 | `rcef` |
| [`overlays/group11/ovl_09383.c`](group11/ovl_09383.c) | `file09383`, `file09410` | `0x01B004E0..0x01B00868` | 904 B | 856 B | 17 | `rcef` |
| [`overlays/group11/ovl_09240.c`](group11/ovl_09240.c) | `file09240`, `file09378` | `0x01B005D0..0x01B00968` | 920 B | 872 B | 17 | `rcef` |
| [`overlays/group11/ovl_09381.c`](group11/ovl_09381.c) | `file09381`, `file09408` | `0x01B004B8..0x01B00858` | 928 B | 884 B | 17 | `rcef` |
| [`overlays/group11/ovl_09422.c`](group11/ovl_09422.c) | `file09422` | `0x01B00530..0x01B00930` | 1,024 B | 976 B | 18 | `rcef` |
| [`overlays/group11/ovl_09231.c`](group11/ovl_09231.c) | `file09231` | `0x01B004b8..0x01B009D8` | 1,312 B | 1,264 B | 18 | `rcef` |
| [`overlays/group11/ovl_09565.c`](group11/ovl_09565.c) | `file09565` | `0x01B00558..0x01B00A88` | 1,328 B | 1,268 B | 21 | `rcef` |
| [`overlays/group11/ovl_09746.c`](group11/ovl_09746.c) | `file09746` | `0x01B00508..0x01B00B00` | 1,528 B | 1,504 B | 10 | `oef` / `ppp` |
| [`overlays/group11/ovl_09747.c`](group11/ovl_09747.c) | `file09747` | `0x01B00508..0x01B00B00` | 1,528 B | 1,504 B | 10 | `oef` / `ppp` |
| [`overlays/group11/ovl_09744.c`](group11/ovl_09744.c) | `file09744` | `0x01B00508..0x01B00B10` | 1,544 B | 1,524 B | 10 | `oef` / `ppp` |
| [`overlays/group11/ovl_09745.c`](group11/ovl_09745.c) | `file09745` | `0x01B00508..0x01B00B10` | 1,544 B | 1,524 B | 10 | `oef` / `ppp` |
| [`overlays/group11/ovl_09242.c`](group11/ovl_09242.c) | `file09242` | `0x01B00508..0x01B00CA8` | 1,952 B | 1,936 B | 9 | `oef` / `ppp` |
| [`overlays/group11/ovl_09543.c`](group11/ovl_09543.c) | `file09543` | `0x01B00450..0x01B00C58` | 2,056 B | 2,040 B | 12 | `oef` / `ppp` |
| **Total (20 containers)** | **20 files** | | **23,304 B** | **22,520 B** | **299** | |
