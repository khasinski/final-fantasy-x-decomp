#!/usr/bin/env python3
"""Compile decompiled EE battle-effect overlays with ee-gcc 2.9-991111-01 (-O2 -G0)
and verify byte-identical .text and full container reconstruction against
build/overlay-audit/overlay-group11-fileXXXXX.bin.

Can be run either on the host (automatically invokes Docker ffx-decomp) or inside
the ffx-decomp container.
"""
import hashlib
import os
from pathlib import Path
import re
import shutil
import subprocess
import sys
import tempfile

ROOT = Path(__file__).resolve().parent.parent
BASE = 0x01B00000

def _decode_addresses(value):
    if isinstance(value, dict):
        return {key: _decode_addresses(item) for key, item in value.items()}
    if isinstance(value, list):
        return [_decode_addresses(item) for item in value]
    if isinstance(value, str) and re.fullmatch(r"0x[0-9a-fA-F]+", value):
        return int(value, 16)
    return value


def load_registry():
    """Load unit data without executing registration scripts."""
    import json
    resident = _decode_addresses(json.loads(
        (ROOT / "overlays/resident_symbols.json").read_text()))
    units = []
    for path in sorted((ROOT / "overlays/group11").glob("*/units.json")):
        for unit in _decode_addresses(json.loads(path.read_text())):
            unit["src"] = (path.parent / unit["src"]).relative_to(ROOT).as_posix()
            if not (ROOT / unit["src"]).is_file():
                raise ValueError(f"{path}: missing source {unit['src']}")
            units.append(unit)
    return resident, units


RESIDENT_SYMS, OVERLAY_UNITS = load_registry()


def resident_symbol(name: str, funcs_txt: dict[str, int]):
    """Address of an undefined resident symbol: RESIDENT_SYMS, then config/funcs.txt names, then
    the func_XXXXXXXX / D_XXXXXXXX spelling. Overlay-internal (>= 0x01B00000) names are never
    guessed: they must come from the unit's syms / container_layouts."""
    if name in RESIDENT_SYMS:
        return RESIDENT_SYMS[name]
    if name in funcs_txt:
        return funcs_txt[name]
    m = re.fullmatch(r"(?:func|D)_([0-9A-Fa-f]{6,8})", name)
    if m and int(m.group(1), 16) < BASE:
        return int(m.group(1), 16)
    return None


def load_funcs_txt() -> dict[str, int]:
    out = {}
    path = ROOT / "config" / "funcs.txt"
    if path.exists():
        for line in path.read_text().splitlines():
            parts = line.split()
            if len(parts) >= 2:
                out[parts[0]] = int(parts[1], 16)
    return out


def unit_stem(unit: dict) -> str:
    return Path(unit["src"]).stem


def parse_args(argv: list[str]):
    import argparse
    ap = argparse.ArgumentParser(description="Verify decompiled group 0x11 overlay units byte-for-byte.")
    ap.add_argument("--unit", action="append", default=[],
                    help="only units whose source stem contains this text (e.g. ovl_09403, 09053_pool); repeatable")
    ap.add_argument("--container", action="append", type=int, default=[],
                    help="only check these container ids (e.g. 9053); repeatable")
    ap.add_argument("--list", action="store_true", help="list registered units and exit (no compiler needed)")
    ap.add_argument("--list-open", nargs="?", const=20, type=int, metavar="N",
                    help="print the top N candidate TUs still OPEN (from tools/overlay_map.py output) and exit")
    return ap.parse_args(argv)


def list_units() -> int:
    for unit in OVERLAY_UNITS:
        cids = unit["containers"]
        span = unit["text_end"] - unit["text_start"]
        more = f" (+{len(cids) - 3} more)" if len(cids) > 3 else ""
        print(f"{unit_stem(unit):18} {len(cids):4} containers  {span:6}B span  {unit['functions']:3} funcs  "
              f"{','.join(map(str, cids[:3]))}{more}")
    return 0


def list_open(n: int) -> int:
    import json
    path = ROOT / "build" / "overlay-map" / "tus.json"
    if not path.exists():
        print("missing build/overlay-map/tus.json: run python3 -P tools/overlay_map.py first")
        return 1
    rows = json.loads(path.read_text())
    print("rank family  score    bytes funcs conts  reference range                  sibling unit")
    for i, r in enumerate(rows[:n], 1):
        print(f"{i:4} {r['family']:6} {r['score']:8} {r['bytes']:6} {r['functions']:5} {len(r['containers']):5}  "
              f"{r['ref']:32} {r['sibling_unit'] or '-'}")
    return 0


def main(argv=None) -> int:
    os.chdir(ROOT)
    argv = sys.argv[1:] if argv is None else argv
    args = parse_args(argv)
    if args.list:
        return list_units()
    if args.list_open is not None:
        return list_open(args.list_open)
    if sys.platform != "linux":
        cmd = [
            "docker", "run", "--rm", "-v", f"{ROOT}:/work", "ffx-decomp",
            "python3", "overlays/verify_overlays.py", *argv,
        ]
        return subprocess.run(cmd).returncode

    units = [u for u in OVERLAY_UNITS if not args.unit or any(k in unit_stem(u) for k in args.unit)]
    if args.container:
        units = [u for u in units if set(u["containers"]) & set(args.container)]
    if not units:
        print("no unit matches the given --unit/--container filter (see --list)")
        return 1

    cc = "tools/cc/ee-gcc2.9-991111-01/bin/ee-gcc"
    out_root = ROOT / "build" / "overlays"
    out_root.mkdir(parents=True, exist_ok=True)
    # Docker processes can all have PID 1 while sharing the same mounted build tree.
    out_dir = Path(tempfile.mkdtemp(prefix="run-", dir=out_root))
    import atexit; atexit.register(shutil.rmtree, out_dir, True)
    funcs_txt = load_funcs_txt()

    matched_cids: set[int] = set()
    total_containers = 0
    total_text_bytes = 0
    total_discovered_bytes = 0
    total_funcs = 0

    for unit in units:
        src = Path(unit["src"])
        stem = src.stem
        obj = out_dir / f"{stem}.o"
        ld = out_dir / f"{stem}.ld"
        elf = out_dir / f"{stem}.elf"
        text_bin = out_dir / f"{stem}.text.bin"

        subprocess.run(
            [unit.get("cc", cc), "-c", *unit.get("cflags", ["-O2"]), "-G0", "-g0", "-Iinclude", "-Ioverlays", str(src), "-o", str(obj)],
            check=True,
        )
        subprocess.run(["mipsel-linux-gnu-objcopy", str(obj), str(obj)], check=True)
        undefined = subprocess.run(["mipsel-linux-gnu-nm", "-u", str(obj)], check=True,
                                   capture_output=True, text=True).stdout.split()
        resident = {}
        for name in undefined:
            if name == "U":
                continue
            addr = resident_symbol(name, funcs_txt)
            if addr is not None:
                resident[name] = addr

        layouts = unit.get("container_layouts") or [
            {
                "cid": cid,
                "text_start": unit["text_start"],
                "text_end": unit["text_end"],
                "syms": unit["syms"],
            }
            for cid in unit["containers"]
        ]
        if args.container:
            layouts = [item for item in layouts if item["cid"] in args.container]

        link_cache: dict[tuple, bytes] = {}
        for item in layouts:
            cid = item["cid"]
            ts = item["text_start"]
            te = item["text_end"]
            syms = item["syms"]
            cache_key = (ts, te, tuple(sorted(syms.items())))
            if cache_key not in link_cache:
                sym_lines = [f"{k} = 0x{v:08x};" for k, v in sorted({**RESIDENT_SYMS, **resident, **syms}.items())]
                ld_script = (
                    "SECTIONS\n{\n"
                    f"    . = 0x{ts:08x};\n"
                    f"    .text : {{ {obj.as_posix()}(.text) }}\n"
                    "    /DISCARD/ : { *(*) }\n"
                    "}\n" + "\n".join(sym_lines) + "\n"
                )
                ld.write_text(ld_script)
                subprocess.run(["mipsel-linux-gnu-ld", "-EL", "-T", str(ld), "-o", str(elf)], check=True)
                subprocess.run(["mipsel-linux-gnu-objcopy", "-O", "binary", str(elf), str(text_bin)], check=True)
                link_cache[cache_key] = text_bin.read_bytes()

            built_text = link_cache[cache_key]
            off_start = ts - BASE
            off_end = te - BASE
            expected_len = off_end - off_start
            if len(built_text) != expected_len:
                print(f"FAIL {stem}: expected .text size {expected_len:#x}, got {len(built_text):#x}")
                return 1

            orig_path = ROOT / "build" / "overlay-audit" / f"overlay-group11-file{cid:05d}.bin"
            orig = orig_path.read_bytes()
            orig_text = orig[off_start:off_end]
            if built_text != orig_text:
                print(f"FAIL {stem} against container {cid}: .text mismatch")
                return 1
            rebuilt = orig[:off_start] + built_text + orig[off_end:]
            rebuilt_sha = hashlib.sha256(rebuilt).hexdigest()
            orig_sha = hashlib.sha256(orig).hexdigest()
            assert rebuilt_sha == orig_sha
            print(
                f"MATCH file{cid:05d} ({src.as_posix()}): "
                f".text 0x{ts:08x}..0x{te:08x} "
                f"({len(built_text)}B span / {unit['discovered_code_bytes']}B insns, "
                f"{unit['functions']} funcs) sha256={rebuilt_sha[:12]}..."
            )
            matched_cids.add(cid)
            total_containers += 1
            total_text_bytes += len(built_text)
            total_discovered_bytes += unit["discovered_code_bytes"]
            total_funcs += unit["functions"]

    print(
        f"\nOK: {len(units)} registered overlay units -> {len(matched_cids)} battle-effect containers with at least "
        f"one matched unit ({total_containers} unit-container matches, {total_funcs} function instances, "
        f"{total_text_bytes} .text bytes / {total_discovered_bytes} instruction bytes). Containers fully matched vs "
        f"partially: see docs/overlay-progress.json (tools/overlay_map.py)."
    )
    return 0


if __name__ == "__main__":
    sys.exit(main())
