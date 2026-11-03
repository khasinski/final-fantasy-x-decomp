# Assembly Policy

The resident ELF (`SCES_504.90`) contains C code compiled with `ee-gcc 2.9-991111-01` alongside handwritten assembly routines (kernel stubs, VU0 macro-mode routines, R5900 MMI routines, and Sony SDK assembly).

The rule is simple: **write C where `ee-gcc` produces the exact bytes from C, and keep assembly as `INCLUDE_ASM` where it cannot.** Never wrap assembly bodies inside C functions via `__asm__`.

## 1. Function Classification

| Kind | Description | Representation | Progress Accounting |
|---|---|---|---|
| **C** | Matches from C89 source | Function body in `src/<unit>.c` | Counted as matched C |
| **Switch** | Uses a `.rodata` jump table | `INCLUDE_ASM` + `INCLUDE_RODATA` until decompiled | Counted as remaining convertible code |
| **Handwritten** | Uses instructions `ee-gcc` never emits, or handwritten SDK/kernel asm | `INCLUDE_ASM`, listed in `config/handwritten.txt` | Reported separately as policy assembly |

Functions that simply have not been matched yet remain plain `INCLUDE_ASM` and are **not** listed in `config/handwritten.txt`.

## 2. Switch Statements and Jump Tables

`ee-gcc 2.9` emits `switch` jump tables into the `.rodata` section of the translation unit. `tools/split_rodata.py` (invoked by `make split` after `splat split`) separates jump tables from the `.rodata` blob:

- Jump tables are written to `asm/nonmatchings/<unit>/rodata/jtbl_XXXXXXXX.s`.
- Intervening `.rodata` slices are written to `asm/data/rodata/piece_XXXXXXXX.s`.
- Section ordering and VMA addresses are recorded in `config/rodata_layout.txt`.
- Each assembly switch function is followed by `INCLUDE_RODATA("build/ee_asm/<unit>/rodata", jtbl_XXXXXXXX);`.

When compiling a C unit, `tools/ccwrap.py` renames the `k`-th compiler-emitted jump table in the object to `.rodata.cjt<k>`, and `configure.py` places either `.rodata.jtbl_XXXXXXXX` (when still in assembly) or `.rodata.cjt<k>` (when decompiled to C) at its exact address in the linker script.

### Decompiling a Switch Function

1. Inspect `asm/nonmatchings/<unit>/rodata/jtbl_XXXXXXXX.s` to determine the `case` targets and `default` bounds check.
2. Replace both `INCLUDE_ASM` and `INCLUDE_RODATA` with the C function in `src/<unit>.c`.
3. Keep C functions within a unit in address order so `.rodata.cjt<k>` matches `config/rodata_layout.txt` (`python3 -P tools/switch_status.py` checks ordering).
4. Declare string literals and `.rodata` constants referenced in that unit as `extern` symbols (`D_XXXXXXXX`) rather than inline literals so no extra `.rodata` sections are emitted before the jump tables.

## 3. Handwritten Assembly (`config/handwritten.txt`)

`tools/classify_asm.py` identifies functions containing instructions that `ee-gcc 2.9` does not generate from C:

| Category | Instructions / Criteria |
|---|---|
| `syscall` | `syscall` (EE kernel stubs) |
| `cop0` | `mfc0`, `mtc0`, `ei`, `di`, `eret`, `cache`, `tlb*` |
| `cop2` | `lqc2`, `sqc2`, `qmfc2`, `qmtc2`, `cfc2`, `ctc2`, `v*` (VU0 macro mode) |
| `mmi` | R5900 multimedia instructions (`p*`, `mult1`/`div1`/`mflo1`, `qfsrv`, `mfsa`/`mtsa`) |
| `sq-zero` | `sq $zero, ...` (`movti_internal` in `ee-gcc 2.9` requires a general-purpose register `d` for TI-mode stores and emits `por` + `sq` for zero stores) |
| `nop-loop` | Explicit `nop` delay loops |
| `sdk` | Handwritten Sony library routines |

Note that ordinary `lq`/`sq` instructions are **not** handwritten markers: `ee-gcc 2.9` emits them for 128-bit `u_long128` (`__attribute__((mode(TI)))`) copies and struct moves.

## 4. Hardware Intrinsics

Single-instruction hardware primitives that appear inside ordinary C functions are provided as macros in `include/common.h`:

- `SYNC()` (`sync.l`) and `SYNC_P()` (`sync.p`)
- `EI()` and `DI()`
- `BREAK()` (`break 0`)
- `VU0_STORE_VF0(p)` (`sqc2 $vf0, 0(reg)`: store the constant vector 0,0,0,1; only for the single store, VU0 arithmetic stays handwritten)
- `u_long128` (`typedef unsigned int u_long128 __attribute__((mode(TI)))`)
