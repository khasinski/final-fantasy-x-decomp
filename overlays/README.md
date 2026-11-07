# Battle-Effect Overlays (`group 0x11`)

Byte-matching C89 decompilations of battle-effect overlays loaded at `0x01B00000` (`baserom/Final Fantasy X (Europe, Australia).iso`, PAL `SCES_504.90`).

## Verification

Run the standalone overlay verifier (automatically uses the `ffx-decomp` Docker container when invoked on macOS):

```bash
python3 overlays/verify_overlays.py                      # all units (~25 s)
python3 overlays/verify_overlays.py --unit ovl_09403     # one unit (substring of the source stem)
python3 overlays/verify_overlays.py --unit 09053_pool --container 9053   # one unit, one container
python3 overlays/verify_overlays.py --list               # registered units
python3 overlays/verify_overlays.py --list-open 40       # top OPEN candidate TUs (needs tools/overlay_map.py output)
```

For each unit, [`overlays/verify_overlays.py`](verify_overlays.py):
1. Compiles the C source with `ee-gcc 2.9-991111-01 -c -O2 -G0 -g0 -Iinclude -Ioverlays`.
2. Links the object at its fixed `.text` virtual address (`0x01B00xxx`) against resident ELF symbols (`SCES_504.90`) and overlay-local `.data`/`.bss` addresses.
3. Verifies 100% byte-for-byte `.text` identity against `build/overlay-audit/overlay-group11-fileXXXXX.bin` and confirms the reconstructed container matches the original SHA-256.

## Matched Units (29 C Units; 30 Containers Fully Matched, 343 Partially)

| C Unit | Containers (`group 0x11`) | `.text` Range | `.text` Span | Discovered Insns | Functions | Subsystem |
|---|---|---|---:|---:|---:|---|
| [`overlays/group11/ovl_09551.c`](group11/ovl_09551.c) | `file09551` | `0x01B00530..0x01B00720` | 496 B | 460 B | 13 | `rcef` |
| [`overlays/group11/ovl_09380.c`](group11/ovl_09380.c) | `file09380`, `file09407` | `0x01B00468..0x01B007B0` | 840 B | 792 B | 16 | `rcef` |
| [`overlays/group11/ovl_09379.c`](group11/ovl_09379.c) | `file09379`, `file09406` | `0x01B00558..0x01B008E0` | 904 B | 856 B | 17 | `rcef` |
| [`overlays/group11/ovl_09383.c`](group11/ovl_09383.c) | `file09383`, `file09410` | `0x01B004E0..0x01B00868` | 904 B | 856 B | 17 | `rcef` |
| [`overlays/group11/ovl_09240.c`](group11/ovl_09240.c) | `file09240`, `file09378` | `0x01B005D0..0x01B00968` | 920 B | 872 B | 17 | `rcef` |
| [`overlays/group11/ovl_09381.c`](group11/ovl_09381.c) | `file09381`, `file09408` | `0x01B004B8..0x01B00858` | 928 B | 884 B | 17 | `rcef` |
| [`overlays/group11/ovl_09422.c`](group11/ovl_09422.c) | `file09422` | `0x01B00530..0x01B00930` | 1,024 B | 976 B | 18 | `rcef` |
| [`overlays/group11/ovl_09231.c`](group11/ovl_09231.c) | `file09231` | `0x01B004b8..0x01B009D8` | 1,312 B | 1,264 B | 19 | `rcef` |
| [`overlays/group11/ovl_09565.c`](group11/ovl_09565.c) | `file09565` | `0x01B00558..0x01B00A88` | 1,328 B | 1,268 B | 21 | `rcef` |
| [`overlays/group11/ovl_09746.c`](group11/ovl_09746.c) | `file09746` | `0x01B00508..0x01B00B00` | 1,528 B | 1,504 B | 11 | `oef` / `ppp` |
| [`overlays/group11/ovl_09747.c`](group11/ovl_09747.c) | `file09747` | `0x01B00508..0x01B00B00` | 1,528 B | 1,504 B | 11 | `oef` / `ppp` |
| [`overlays/group11/ovl_09744.c`](group11/ovl_09744.c) | `file09744` | `0x01B00508..0x01B00B10` | 1,544 B | 1,524 B | 11 | `oef` / `ppp` |
| [`overlays/group11/ovl_09745.c`](group11/ovl_09745.c) | `file09745` | `0x01B00508..0x01B00B10` | 1,544 B | 1,524 B | 11 | `oef` / `ppp` |
| [`overlays/group11/ovl_09242.c`](group11/ovl_09242.c) | `file09242` | `0x01B00508..0x01B00CA8` | 1,952 B | 1,936 B | 9 | `oef` / `ppp` |
| [`overlays/group11/ovl_09572.c`](group11/ovl_09572.c) | `file09572` | `0x01B00580..0x01B00CB8` | 1,848 B | 1,364 B | 19 | `rcef` |
| [`overlays/group11/ovl_09527.c`](group11/ovl_09527.c) | `file09527` (complete container) | `0x01B005F8..0x01B011D0` | 3,032 B | 3,016 B | 9 | oef effect (part objects, double constants via DK macro) |
| [`overlays/group11/ovl_09385.c`](group11/ovl_09385.c) | `file09385` (complete container) | `0x01B00698..0x01B01220` | 2,952 B | 2,936 B | 11 | ppp/oef2 effect |
| [`overlays/group11/ovl_09573.c`](group11/ovl_09573.c) | `file09573` (complete container) | `0x01B006C0..0x01B01130` | 2,672 B | 2,624 B | 25 | rcef screen-effect/resource effect |
| [`overlays/group11/ovl_09569.c`](group11/ovl_09569.c) | `file09569` (complete container) | `0x01B00580..0x01B00EB8` | 2,360 B | 2,300 B | 31 | rcef bind-motes effect (caster/target motions, ring flash) |
| [`overlays/group11/ovl_09566.c`](group11/ovl_09566.c) | `file09566` (complete container) | `0x01B005D0..0x01B00EC0` | 2,288 B | 2,244 B | 24 | rcef charge-up effect (pulse counter, per-target visibility) |
| [`overlays/group11/ovl_09570.c`](group11/ovl_09570.c) | `file09570` (complete container) | `0x01B00580..0x01B00DD8` | 2,136 B | 2,084 B | 24 | rcef multi-target projectile effect (VU0 vector setup) |
| [`overlays/group11/ovl_09238.c`](group11/ovl_09238.c) | `file09238` (complete container) | `0x01B00490..0x01B00C70` | 2,016 B | 1,980 B | 23 | rcef effect state machine (lance-like projectile, VU0 vector setup) |
| [`overlays/group11/ovl_09412.c`](group11/ovl_09412.c) | `file09412` (complete container) | `0x01B005C0..0x01B00E5C` | 2,204 B | 2,172 B | 21 | `tt_scene` (ppp part shell + timed-callback ring) |
| [`overlays/group11/ovl_09543.c`](group11/ovl_09543.c) | `file09543` | `0x01B00450..0x01B00C58` | 2,056 B | 2,040 B | 12 | `oef` / `ppp` |
| [`overlays/group11/ovl_09403.c`](group11/ovl_09403.c) | `file09403` | `0x01B00530..0x01B00F28` | 2,544 B | 2,544 B | 24 | `rcef` |
| [`overlays/group11/ovl_09053_tu0.c`](group11/ovl_09053_tu0.c) | 40 containers (`file09053`..`file09725`) | `0x01B007D8..0x01B009B8` (relocated per container) | 480 B | 468 B | 6 | `oef` (`TU0`) |
| [`overlays/group11/ovl_09088_pool.c`](group11/ovl_09088_pool.c) | 11 containers (`file09088`..`file09603`) | `0x01B025D0..0x01B02AA8` (relocated per container) | 1,240 B | 1,104 B | 17 | `oef` (list/pool allocator TU) |
| [`overlays/group11/ovl_09053_pool.c`](group11/ovl_09053_pool.c) | 215 containers (`file09053`..`file09757`) | `0x01B046F8..0x01B04BF0` (relocated per container) | 1,272 B | 1,136 B | 17 | `oef` (list/pool allocator TU) |
| [`overlays/group11/ovl_09065_tu0.c`](group11/ovl_09065_tu0.c) | 117 containers (`file09065`..`file09756`) | `0x01B00878..0x01B01420` (relocated per container) | 2,984 B | 2,676 B | 21 | `opu` / `oef` / `ppp` (`TU0`) |
| **Total** | **365 containers with a matched unit (405 unit matches)** | | **683,152 B** | **614,624 B** | **6,886** | |

Byte totals are summed over unit-container matches. For function-based progress (22
containers fully matched, 343 partially, 219 not at all) see
[`docs/overlay-progress.json`](../docs/overlay-progress.json).

## Shared-Code Map

`python3 -P tools/overlay_map.py` (a few seconds) splits every container's code into
functions and hashes each one with absolute addresses masked. It marks each function
COVERED (inside a matched unit range for that container) or OPEN. Most overlay code is
repeated: the 17.3 MB of per-container function bytes hold about 1.6 MB of distinct bodies.
Decompiling a shared TU once therefore covers every container that contains it.

- [`docs/overlay-tus.tsv`](../docs/overlay-tus.tsv): candidate TUs (OPEN functions that occur in exactly the
  same containers and are adjacent in all of them), ranked by bytes x containers. Columns:
  `layout` (identical, or relocated and by how much), `raw_variants` (how many byte variants exist,
  where 1 means the code is position-independent), `sibling_unit` (the matched unit present in the
  most of these containers, plus the TU's offset from that unit's `text_start`), and resident refs.
- [`docs/overlay-families.tsv`](../docs/overlay-families.tsv): chains of TUs that belong to the same shared library.
- [`docs/overlay-ranking.tsv`](../docs/overlay-ranking.tsv): single OPEN function groups.
- `build/overlay-map/functions.json` / `tus.json`: full data, including each TU's start in every container.

Limits: the function split is heuristic, and the docstring of `tools/overlay_map.py` lists them.
It reproduces the function count of every matched unit's C file.

## Adding a Unit

1. **Pick a TU.** Run `python3 overlays/verify_overlays.py --list-open 40` or read `docs/overlay-tus.tsv`.
   The reference container is the lowest container id. Function boundaries and resident callees
   are in `build/overlay-map/functions.json`.
2. **Write the C file** at `overlays/group11/ovl_<refcid>_<name>.c`. Name functions `func_01Bxxxxx` and
   overlay data `D_01Bxxxxx` by their address in the reference container. Match the style of the
   closest existing unit:
   - single-container rcef effects: `ovl_09403.c`, `ovl_09572.c` (`#include "rcef_overlay.h"`)
   - single-container oef/ppp effects: `ovl_09242.c`, `ovl_09543.c` (`#include "oef_overlay.h"`)
   - relocated shared TUs: `ovl_09053_pool.c`, `ovl_09065_tu0.c` (own structs, plain `extern`s)
   Do not add declarations to the shared `rcef_overlay.h` / `oef_overlay.h` from parallel work.
   Put new types and prototypes in the C file or in a package header
   `overlays/<package>_overlay.h`, and merge them into the shared headers later in one pass.
3. **Register it** in its own file `overlays/units/<stem>.py`, which defines `UNITS = [...]` in the
   `OVERLAY_UNITS` format and optionally `RESIDENT_SYMS = {...}`. `verify_overlays.py` loads these
   files, so packages do not edit the same list. To generate a skeleton with the per-container
   `.text` ranges and overlay-internal symbol addresses (the equivalent of `POOL_9053_LAYOUTS` /
   `_pool_9053_syms`), run:
   ```bash
   python3 -P tools/overlay_map.py --layout <rank> > overlays/units/<stem>.py
   ```
   Symbols that keep a fixed distance from the TU start go in `BASE_SYMS`. The others get a
   column in `LAYOUTS`. Rename symbols to the names the C file uses. If the C file addresses data
   as `base + offset`, only the base symbol is needed. `text_end - text_start` must equal the
   object's `.text` size: the end of the last function, rounded up to 8.
4. **Resident symbols** resolve automatically: `func_XXXXXXXX` / `D_XXXXXXXX` (below `0x01B00000`)
   by their spelling, and real names via `config/funcs.txt`. Only names missing from both, such
   as libgcc `dpadd`, need `RESIDENT_SYMS`. Overlay-internal names are never guessed.
5. **Verify quickly**, then fully:
   ```bash
   python3 overlays/verify_overlays.py --unit <stem> --container <refcid>   # iterate
   python3 overlays/verify_overlays.py --unit <stem>                        # all its containers
   python3 overlays/verify_overlays.py                                      # everything, before commit
   python3 -P tools/overlay_map.py && python3 -P tools/status.py --write-report docs/progress.json
   ```
