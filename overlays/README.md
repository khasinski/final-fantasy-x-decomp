# Battle-effect overlays

584 overlays from disc group `0x11`, loaded at `0x01B00000`.
301 are complete and 283 have some matching C code. None are untouched.
Overall overlay coverage is 80.06% of code bytes (94.91% of decompilable code, excluding handwritten VU0/MMI policy assembly).

## Files

- `group11/<reference>/`: matching C sources and a `units.json` manifest.
- `wip/<reference>/`: unfinished drafts, excluded from progress.
- `resident_symbols.json`: extra names for symbols in the main ELF.
- `*_overlay.h`: shared types and declarations.

The directory number identifies the reference container. Shared code lives in
one directory; its manifest lists every container and address where it matches.
For example, [09237](group11/09237/units.json) contains a callback shared by five overlays.

## Verify

Run from the repository root. On macOS, the verifier uses the `ffx-decomp` Docker image.
It requires the extracted containers from `tools/audit_overlays.py`.
Most units use `ee-gcc2.9-991111-01`; some need `ee-gcc2.96`, installed
under `tools/cc/`. Each manifest records any compiler override.

```sh
python3 overlays/verify_overlays.py --container 9227
python3 overlays/verify_overlays.py --unit ovl_09228_particle_slot
python3 overlays/verify_overlays.py                 # all registered units
```

Each check compiles and links the C code at the original address, then compares
its bytes with the original container. The rest of the container is preserved;
a successful check of one unit does not mean the whole overlay is decompiled.

## Add code

Find candidates in [overlay-tus.tsv](../docs/overlay-tus.tsv), or run:

```sh
python3 overlays/verify_overlays.py --list-open 20
python3 -P tools/overlay_map.py --layout 1
```

`--layout` prints a JSON skeleton. Add the entry to the reference directory's
`units.json` and put the C file beside it. `src` is a filename relative to that
directory. Addresses may be hexadecimal strings; `container_layouts` records
addresses that differ between containers. Set `text_end` to the actual end of
the compiled `.text` section, including any compiler padding.

Keep unfinished code in `wip/`. Register it only after `tools/ovdiff.py` confirms
that it matches, then run the verifier for every container it covers.
`tools/ovldis.py` disassembles original overlay code.

After verification, refresh the reports:

```sh
python3 -P tools/overlay_map.py
python3 -P tools/status.py --write-report docs/progress.json
```

Coverage counts function bytes, with shared code counted in each container.
Function boundaries are estimated. Full figures are in
[overlay-progress.json](../docs/overlay-progress.json); the main [README](../README.md)
combines overlays with the resident ELF.
