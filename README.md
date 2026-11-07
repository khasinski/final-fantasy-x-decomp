# Final Fantasy X decompilation

A matching C decompilation of the PS2 PAL version, `SCES_504.90`.
Uses **ee-gcc 2.9-991111-01** with `-O2 -G0`.

## Progress

| Part | Code size | In C |
|---|---:|---:|
| Main ELF | 1.98 MiB | **34.16%** |
| Overlays — 584 battle-effect files | 16.54 MiB | **37.34%** (by container) · **4.67%** (distinct code) |

Together, that is **about 37.0% of the known EE code** when repeated overlay code is counted once per
container in which it appears. Progress is measured by
code bytes; IOP modules and VU microcode are not yet counted.

Overlay bytes are function bytes from a heuristic split of every container
(`tools/overlay_map.py`), counted once per container. 29 of the 584 containers are
fully matched, 530 contain at least one matched unit, and 25 have none. Much of the
overlay code is repeated across containers: by relocation-normalized function body, the
distinct code is 1.50 MiB, of which 4.52% is matched. Shared code is ranked in
[docs/overlay-tus.tsv](docs/overlay-tus.tsv).

Run `python3 -P tools/status.py` for current numbers, or see the
[progress report](docs/progress.json). Overlay findings:
[inventory](docs/ee-overlay-audit.json) · [size estimate](docs/ee-overlay-code-size.json) ·
[function-based progress](docs/overlay-progress.json) · [shared TU ranking](docs/overlay-tus.tsv) ·
[decompiled overlays](overlays/README.md).

## Verification

The rebuilt main image is byte-identical to the original:
`OK a553c3d3380a8baea9be4db6f972185d39f448e5 (0x47cb0c bytes)` (tools/check.py).

## Build

Requires Python 3 and Docker. Download `ee-gcc2.9-991111-01` from
[decompme/compilers](https://github.com/decompme/compilers/releases) and place it in
`tools/cc/ee-gcc2.9-991111-01/`.

```sh
python3 -m venv .venv
.venv/bin/pip install -r requirements.txt
mkdir -p baserom
.venv/bin/python tools/extract_iso.py "/path/to/Final Fantasy X.iso"
make image
make build
```

`make build` verifies the resident executable (`SCES_504.90`) against the original SHA-1. To extract and verify the decompiled battle-effect overlays:

```sh
python3 -P tools/audit_overlays.py "/path/to/Final Fantasy X.iso"
python3 overlays/verify_overlays.py
```

## Working on a function

1. Find it in `src/game/` or `src/sdk/`.
2. Replace its `INCLUDE_ASM` with C.
3. Run `tools/m.sh <function>` until it reports `MATCH`.
4. Run `tools/m.sh` to check the whole resident executable.

Both real names and `func_XXXXXXXX` names are accepted by the tools. About 2100 game functions and
26 globals carry real HD-port names. `config/names_applied.tsv` maps address, splat name and real
name; [docs/NAMES.md](docs/NAMES.md) ("Applied names") explains how to apply or revert names with
`tools/apply_names.py`.

## Documentation

- [Source layout](docs/LAYOUT.md)
- [Battle-effect overlays](overlays/README.md)
- [Function names](docs/NAMES.md)
- [Coding style](docs/STYLE.md)
- [Assembly policy](docs/ASM_POLICY.md)
- [Translation units](docs/TU.md)
