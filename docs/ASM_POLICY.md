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
- `VU0_STORE_VF0(p)` (`sqc2 $vf0, 0(reg)`: store the constant vector 0,0,0,1)
- `u_long128` (`typedef unsigned int u_long128 __attribute__((mode(TI)))`)

### Tier 1: one instruction, one macro (`include/vu0.h`)

VU0 macro-mode and R5900 MMI instructions may be written as **one macro per instruction** inside an otherwise ordinary C
function. The control flow, integer work, calls and register allocation stay C; the macro only names the single
instruction (`VU0_LQC2(4, 0, p)`, `VU0_OP("vmulax.xyzw ACC, $vf4, $vf8x")`, `MMI_OP3("pextlw", d, a, b)`).
Several macros in a row are fine; they are ordinary `asm volatile` statements and keep their order.
A function written this way counts as C (and leaves `config/handwritten.txt`).

Not allowed under tier 1: one `asm` statement that carries several instructions, branches or labels, or that moves the
function's real work into text.

## 5. Tier 2: whole-function inline asm (library code only)

Some functions are a single asm block by construction: the Sony `libvu0` leaf routines (`sceVu0ApplyMatrix`,
`sceVu0OuterProduct`, `sceVu0TransposeMatrix`, ...) were written in C files as one `__asm__ volatile(...)` each, and the
game's own tiny VU0 helpers follow the same pattern. For such a function (a straight-line or looping **leaf** routine
whose whole body is VU0/MMI code, no calls, no stack) the project may keep the body as one inline-asm block, generated
by `tools/vu0lift.py`.

Rules:

1. Only whole functions that are leaves and contain at least one VU0/MMI instruction. Nothing that C can express.
2. The function stays in `config/handwritten.txt`; `tools/status.py` reports it as an **inline-asm wrapper**
   (byte-exact, listed separately, never counted as C coverage).
3. Verification is bytes, as for everything else: `tools/vu0lift.py --check` compares each wrapper with the original
   encoding and exact size before `--apply` touches `src/`.
4. Translation units whose wrappers need the period assembler (it fills the `jr $ra` delay slot with the last asm
   instruction) get `-Btools/cc/ee-as-delay/` in `config/cflags.txt`; this is only kept when the whole TU still matches.
5. `lq`/`sq` alone is not a reason for asm (see §3); functions that contain nothing else are C candidates.
