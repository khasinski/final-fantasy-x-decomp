# Building

Requires Python 3, Docker and a PAL game ISO (`SCES_504.90`).
Download `ee-gcc2.9-991111-01` from
[decompme/compilers](https://github.com/decompme/compilers/releases) and unpack it into
`tools/cc/ee-gcc2.9-991111-01/`.

Run from the repository root:

```sh
python3 -m venv .venv
.venv/bin/pip install -r requirements.txt
mkdir -p baserom
.venv/bin/python tools/extract_iso.py "/path/to/Final Fantasy X.iso"
make image
make build
```

The build compares the main executable with the original.
For overlays, see the [overlay guide](../overlays/README.md).

## Checking a change

Replace a function's `INCLUDE_ASM` in `src/` with C.
Check it with `tools/m.sh <function>`, then run `tools/m.sh` for the full executable.

- [Coding style](STYLE.md) and [assembly policy](ASM_POLICY.md)
- [Function names](NAMES.md) and [translation units](TU.md)
