#!/usr/bin/env python3
"""Register an overlay C unit in overlays/verify_overlays.py.

usage: tools/ovreg.py <container> <text_start> <text_end> <discovered_code_bytes> <functions> [SYM=ADDR ...]
The source is overlays/group11/ovl_<container:05d>.c. Inserts the entry at the top of OVERLAY_UNITS.
"""
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent


def main(a):
    if len(a) < 5:
        print(__doc__)
        return 2
    cid, ts, te = int(a[0]), int(a[1], 0), int(a[2], 0)
    code, nf = int(a[3]), int(a[4])
    syms = [x.split("=") for x in a[5:]]
    p = ROOT / "overlays" / "verify_overlays.py"
    s = p.read_text()
    src = f"overlays/group11/ovl_{cid:05d}.c"
    if f'"{src}"' in s:
        print("already registered")
        return 1
    body = "".join(f'            "{n}": 0x{int(v, 0):08X},\n' for n, v in syms)
    entry = (f'    {{\n        "src": "{src}",\n        "containers": [{cid}],\n'
             f'        "text_start": 0x{ts:08X},\n        "text_end": 0x{te:08X},\n'
             f'        "discovered_code_bytes": {code},\n        "functions": {nf},\n'
             f'        "syms": {{\n{body}        }},\n    }},\n')
    k = "OVERLAY_UNITS = [\n"
    assert s.count(k) == 1
    p.write_text(s.replace(k, k + entry))
    return 0


if __name__ == "__main__":
    sys.exit(main(sys.argv[1:]))
