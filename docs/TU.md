# Translation Units (`config/tu_map.tsv`)

`config/tu_map.tsv` and `config/units.txt` reconstruct the original object boundaries (`.o` translation units) across `.text` (`0x001008D8..0x00300500`). Each unit in `config/units.txt` corresponds to a source file under `src/game/` or `src/sdk/` (see [docs/LAYOUT.md](LAYOUT.md)).

The boundary analysis is implemented in `tools/find_tus.py` (`python3 -P tools/find_tus.py`), which partitions the 11,610 catalogued resident functions into **375 translation units** (median size `0xDE0` bytes).

## Signals Used for Boundary Detection

- **Section monotonicity**: The linker concatenates `.text`, `.data` (`0x00300500`), `.rodata` (`0x00568F00`), `.lit4` (`0x0057C680`, `$gp = 0x00584670`), `.sbss`, and `.bss` in the same object order. Each translation unit owns a contiguous, monotonically advancing pool in each section.
- **String literal pooling**: `ee-gcc 2.9` pools identical string literals within a single translation unit, while `ee-ld` does not merge literals across `.o` files. Two functions referencing the same string literal address must belong to the same TU (139 no-cut intervals), whereas two copies of the same string literal in `.rodata` must belong to different TUs (103 hard separations).
- **`__FILE__` assertions**: 41 distinct source filenames (`src/chr/chr.c`, `tklib.c`, `rcbg*.c`, `meswin.c`, `eiProg/pppYanagi.c`, etc.) appear in `.rodata` and anchor exact TU names and boundaries.
- **Handwritten `.align 2` assembly objects**: `ee-gcc` aligns every function to 8 bytes (`.align 3`). Functions starting at `4 mod 8` come from handwritten `.align 2` assembly objects (`0x00123844`, `0x00170BC4`, `0x00255EA4`, `0x002EEF1C`, `0x002F032C`, `0x002FAC84`), each forming an exact object boundary.
- **Local data inversions and private callees**: Within a single TU, a later function may reference an earlier local datum (`i < i'` with `data(i) > data(i')`), and static helper calls cluster tightly within the unit.

## Segmentation and Confidence

`tools/find_tus.py` solves a dynamic program maximizing modularity subject to the hard separation and no-cut constraints:

- **`high` (15 TUs)**: Bracketed by hard separations (`__FILE__` transitions, duplicate string literals, or `.align 2` assembly objects) with zero positional slack.
- **`medium` (97 TUs)**: Bracketed by hard evidence or stable across resolution parameters (`gamma = 5..80`) within `0x100` bytes.
- **`low` (263 TUs)**: Inferred from soft locality edges (data pools, call locality, and symbol prefix runs in `config/names_map.tsv`).

## Build Units (`config/units.txt`)

`config/units.txt` lists the **381** resident build objects in link order. This matches the 375 TUs from `config/tu_map.tsv` plus 6 byte-neutral object splits recorded in `config/unit_splits.tsv`:

- **Library boundary splits (2)**: `0x002D98A8` (`game/platform/ffx_2D9730` vs `sdk/libgraph/libgraph`) and `0x002E2830` (`sdk/libipu/libipu_2E2220` vs `sdk/newlib/libm/libm_2E2830`).
- **Compiler flag splits (4)**: Units where a subset of functions requires distinct compiler flags in `config/cflags.txt` (`particle_266A48`, `opu_29DC40`, `libc_2F3A70`).
