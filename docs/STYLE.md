# Coding Style

Source code targets plain C89 compiled with `ee-gcc 2.9-991111-01 -O2 -G0`. Functions must compile to byte-identical machine code without `#if 0`, `NON_MATCHING`, or inline assembly workarounds.

## Guidelines

- **Types and structs**: Define structs with meaningful member names when usage makes the layout clear. Use `u8 pad[N]` only for unused padding, and avoid raw byte-offset pointer arithmetic (`*(int *)((char *)p + 0x60)`) when a struct member can represent the access.
- **Function and global names**: Use applied symbol names from `config/names_applied.tsv` (see [docs/NAMES.md](NAMES.md)). Do not rename applied symbols manually or via `#define` aliases. Unidentified symbols retain their address-based names (`func_XXXXXXXX`, `D_XXXXXXXX`).
- **Control flow**: Prefer structured C (`if`/`else`, `for`, `while`, `switch`). Use `goto` only when structured control flow cannot reproduce the target control-flow graph.
- **Headers**: Basic fixed-width and 128-bit types live in `include/common.h`. Subsystem declarations live in `include/ffx/`. Keep a single struct definition per type in `include/`.
- **Comments**: Document only non-obvious hardware, ABI, or codegen constraints.

## Debt Markers

When a byte match currently relies on a workaround, mark it on the same line or immediately above with `/* DEBT(KIND): reason */` so `python3 -P tools/status.py --debt` can track it:

| Kind | Meaning |
|---|---|
| `CAST` | Raw cast or offset arithmetic where the underlying struct type is not yet modeled |
| `FAKE` | Temporary variable, parameter, or qualifier introduced solely to steer register allocation |
| `ORDER` | Statements or declarations ordered specifically to match instruction scheduling or register allocation |
| `PADDING` | Dummy stack locals or struct fields needed only to match frame or struct size |
| `GOTO` | `goto` used where structured control flow is likely the original form |
| `TYPE` | Parameter, local, or return type width/signedness is provisional |
| `NAME` | Symbol or field name is provisional |

Unmatched functions remain `INCLUDE_ASM` (see [docs/ASM_POLICY.md](ASM_POLICY.md)).

## Verification

- Single function: `tools/m.sh <function_name>`
- Full resident ELF: `tools/m.sh`
- Battle-effect overlays: `python3 overlays/verify_overlays.py`
