# Symbol Names (`config/names_map.tsv`)

The PS2 PAL executable (`SCES_504.90`) strips symbol names from its loadable image. Original function and global variable names in `config/names_map.tsv` and `config/names_data.tsv` were recovered by matching the PS2 call graph, string literals, dispatch tables, and translation-unit ordering against symbols preserved in later ports of the game (Nintendo Switch and PC/Steam).

High-confidence game symbols are applied across the source tree (`config/names_applied.tsv`); medium- and low-confidence matches remain in `config/names_map.tsv` as reference hints.

## Files

| File | Description |
|---|---|
| `config/names_map.tsv` | Function name mapping (`ps2_symbol`, `real_name`, `source`, `method`, `confidence`, `notes`) |
| `config/names_data.tsv` | Global data symbol mapping (`D_XXXXXXXX` -> original name) |
| `config/names_applied.tsv` | Currently applied renames (`addr`, `old`, `new`, `kind`, `unit`) |
| `config/names_skipped.tsv` | High-confidence candidates skipped due to collisions or reserved names |
| `config/name_prefix_ranges.tsv` | Address ranges of dominant symbol prefixes across `.text` |
| `tools/apply_names.py` | Applies, reverts, or verifies symbol renames (`--plan`, `--apply`, `--revert`, `--check`) |
| `tools/ffxsyms.py` | Symbol/address resolution helper used by build and analysis scripts |

## Matching Methodology

1. **String anchors**: Functions referencing identical rare string literals are paired using IDF-weighted mutual-best matching.
2. **Call-graph propagation**: Matched function pairs vote for unmatched callers, callees, and function-pointer callbacks, weighted by ordered call-sequence alignment, shared global data references, and instruction-count ratios.
3. **Dispatch tables**: Contiguous function-pointer arrays in `.data`/`.rodata` with at least two anchored entries at a consistent offset are paired by index.
4. **Intra-TU order fill**: Unmatched gaps between consecutive anchors within the same translation unit that contain an equal number of functions on both targets are paired in address order.

### Confidence Levels

- **`high`**: Supported by at least two independent signals (e.g., unique string literal plus call-graph agreement, or 3+ structural neighbour votes with matching size).
- **`medium`**: Supported by two weaker structural signals.
- **`low`**: Single signal (such as order-fill without independent call/data confirmation); kept as a hint only.

In total, `config/names_map.tsv` catalogues **3,304** PS2 functions (**2,147 high**, **743 medium**, **414 low**), and `config/names_data.tsv` catalogues **79** globals (**27 high**, **32 medium**, **20 low**).

## Applied Names (`tools/apply_names.py`)

`tools/apply_names.py` applies high-confidence game symbol names (`0x00100000..0x002DDA00`) across `src/`, `include/`, `asm/`, and `config/`. Currently **2,125** symbols (**2,099 functions** and **26 globals**) are applied.

Selection rules enforced by `tools/apply_names.py`:
- Only `confidence=high` entries in `game/` units are applied (SDK units and `sce*` symbols are excluded).
- Compiler builtins, standard C library names (`main`, `memcpy`, `memcmp`, `setjmp`, etc.), C keywords, duplicate mappings (`DUPNAME`), conflicts (`CONFLICT`), and case-insensitive filename collisions are skipped and logged in `config/names_skipped.tsv`.
- All tools (`tools/m.sh`, `tools/fdiff.py`, `tools/draft.sh`) accept both the applied name and the original `func_XXXXXXXX` / `D_XXXXXXXX` identifier via `tools/ffxsyms.py`.

```sh
python3 -P tools/apply_names.py --plan      # preview candidates and skip reasons
python3 -P tools/apply_names.py --check     # verify consistency of applied names
```
