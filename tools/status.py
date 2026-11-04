#!/usr/bin/env python3
"""Decompilation progress and decompilation debt.

Resident progress: bytes of C bodies / catalogued main-ELF function bytes.
Known EE progress: resident bytes plus estimated effect-overlay instruction bytes.
This is not an exact whole-game percentage; IOP/VU coverage is not inventoried.
Debt:     every `DEBT(kind)` marker left in src/ and include/ (see docs/STYLE.md), plus
          shortcuts we can detect mechanically (raw casts to fixed offsets, `unkXX` fields).
usage: status.py [--debt] [--root DIR] [--json] [--write-report PATH]
"""
import collections, glob, hashlib, json, os, re, sys
from pathlib import Path

root = sys.argv[sys.argv.index("--root") + 1] if "--root" in sys.argv else "."
json_output = "--json" in sys.argv
DATA = {0x17A600, 0x186C00}          # font bitmaps stored inside .text (by address: names may be real names)
funcs = {}
for l in open(f"{root}/config/funcs.txt"):
    n, a, s = l.split()
    if int(a, 16) not in DATA and int(a, 16) >= 0x1008D8:      # earlier code (crt0, syscall stubs) is not in a C chunk
        funcs[n] = int(s, 16)
total = sum(funcs.values())
src_files = sorted(glob.glob(f"{root}/src/**/*.c", recursive=True))
defined = set()      # functions with a C body in src/ (a name may be merged into its neighbour's INCLUDE_ASM otherwise)
for p in src_files:
    # `name(...) {` or an old-style `name(a, b)  T a; T b; {`
    # (any identifier: func_XXXXXXXX or an applied real name such as _rcFree, config/names_applied.tsv)
    defined.update(re.findall(r"^[A-Za-z_][\w \*]*?\b([A-Za-z_]\w*)\s*\([^;{]*\)\s*(?:[^;{}()]*;\s*)*\{", open(p).read(), re.M))
# functions ee-gcc cannot produce from C (docs/ASM_POLICY.md): kept as asm, reported on their own
hand = {}
if os.path.exists(f"{root}/config/handwritten.txt"):
    for l in open(f"{root}/config/handwritten.txt"):
        f = l.split()
        if f and not l.startswith("#") and f[0] in funcs:
            hand[f[0]] = f[1]
# a handwritten function that has a body in src/ is either
#   - a whole-function inline-asm wrapper (tools/vu0lift.py): the body is a single `__asm__` statement. It is byte-exact
#     but still hand-written asm, so it is never counted as C; or
#   - C using single-instruction hardware macros (include/vu0.h, docs/ASM_POLICY.md tier 1): counted as C and no
#     longer reported as policy assembly.
def _bodies():
    out = {}
    for p in src_files:
        t = open(p).read()
        for m in re.finditer(r"^[A-Za-z_][\w \*]*?\b([A-Za-z_]\w*)\s*\([^;{]*\)\s*(?:[^;{}()]*;\s*)*\{", t, re.M):
            depth, i = 1, m.end()
            while i < len(t) and depth:
                depth += {"{": 1, "}": -1}.get(t[i], 0)
                i += 1
            out[m.group(1)] = t[m.end():i - 1]
    return out
_b = _bodies() if hand else {}
def _is_wrapper(name):
    body = _b.get(name)
    if body is None:
        return False
    rest = re.sub(r'__asm__\s+volatile\s*\((?:[^;]|"(?:\\.|[^"\\])*")*\)\s*;', "", body, flags=re.S)
    return rest.strip() == ""
wrapped = {n: s for n, s in funcs.items() if n in hand and n in defined and _is_wrapper(n)}
tier1 = {n for n in hand if n in defined and n not in wrapped}
for n in tier1:
    hand.pop(n)
done = {n: s for n, s in funcs.items() if n in defined and (n not in hand or n in tier1)}
dbytes = sum(done.values())
if not json_output:
    print(f"resident ELF C coverage: {len(done)}/{len(funcs)} functions, {dbytes:#x}/{total:#x} bytes = {100*dbytes/total:.2f}% (main ELF only)")
hbytes = sum(funcs[n] for n in hand)
cats = collections.Counter()
for n, c in hand.items():
    cats[c] += funcs[n]
if hand and not json_output:
    print(f"  handwritten (asm by policy): {len(hand)} functions, {hbytes:#x} bytes = {100*hbytes/total:.2f}% of all code")
    print(f"    of which as inline-asm wrappers (byte-exact, not counted as C): {len(wrapped)} functions, {sum(wrapped.values()):#x} bytes")
    print(f"  resident decompilable C coverage: {100*dbytes/max(total-hbytes,1):.2f}% of {total-hbytes:#x} bytes")

# switch functions: a jump table still owned by an INCLUDE_RODATA line means the function is asm
jt_total = sum(1 for l in open(f"{root}/config/rodata_layout.txt") if l.startswith("jtbl")) if os.path.exists(f"{root}/config/rodata_layout.txt") else 0
jt_asm = sum(open(p).read().count("INCLUDE_RODATA(") for p in src_files)
if jt_total and not json_output:
    print(f"  jump-table functions: {jt_total - jt_asm}/{jt_total} are C, {jt_asm} still INCLUDE_ASM+INCLUDE_RODATA")

debt = collections.Counter(); where = collections.defaultdict(list)
for p in src_files + sorted(glob.glob(f"{root}/include/**/*.h", recursive=True)):
    for i, line in enumerate(open(p), 1):
        for kind in re.findall(r"DEBT\((\w+)\)", line):
            debt[kind] += 1; where[kind].append(f"{os.path.relpath(p, root)}:{i}")
        if re.search(r"\bunk[0-9A-Fa-f]+\b", line) and p.endswith(".h"):
            debt["UNKNOWN_FIELD"] += 1
n_funcs_with_debt = sum(1 for k in debt)
report = {
    "metric": "C-body byte coverage; full-game completion is not yet measurable",
    "resident_elf": {
        "catalogued_functions": len(funcs), "c_functions": len(done),
        "catalogued_function_bytes": total, "c_function_bytes": dbytes,
        "coverage_percent": 100*dbytes/total,
        "policy_assembly_bytes": hbytes,
        "inline_asm_wrapper_functions": len(wrapped),
        "inline_asm_wrapper_bytes": sum(wrapped.values()),
        "decompilable_coverage_percent": 100*dbytes/max(total-hbytes,1),
    },
    "ee_overlays": None, "known_ee_estimate": None,
    "whole_game_coverage_percent": None,
    "other_scopes": {
        "IOP": {"coverage_percent": None, "status": "not inventoried"},
        "VU": {"coverage_percent": None, "status": "not inventoried"},
    },
    "debt_markers": dict(sorted(debt.items())),
}
estimate_path = Path(root)/"docs/ee-overlay-code-size.json"
audit_path = Path(root)/"docs/ee-overlay-audit.json"
if estimate_path.exists() and audit_path.exists():
    estimate = json.loads(estimate_path.read_text())["measurements"]
    audit = json.loads(audit_path.read_text())
    inventory = audit["conclusions"]
    progress = audit.get("build_status", {})
    fmap_path = Path(root)/"docs/overlay-progress.json"   # written by tools/overlay_map.py
    fmap = json.loads(fmap_path.read_text()) if fmap_path.exists() else None
    if fmap:
        overlay_bytes = fmap["code_bytes"]
        overlay_done = fmap["matched_bytes"]
    else:
        overlay_bytes = estimate["detected_instruction_bytes"]
        overlay_done = progress.get("matched_code_bytes", 0)
    assert 0 <= overlay_done <= overlay_bytes
    numerator = dbytes + overlay_done
    report["ee_overlays"] = {
        "containers": inventory["battle_containers"],
        "distinct_payloads": inventory["unique_battle_payload_sha256"],
        "matched_units": progress.get("matched_unique_units"),
        "containers_with_any_match": fmap["containers"] - fmap["containers_unmatched"] if fmap else progress.get("matched_containers", 0),
        "containers_fully_matched": fmap["containers_fully_matched"] if fmap else None,
        "containers_partially_matched": fmap["containers_partially_matched"] if fmap else None,
        "matched_code_bytes": overlay_done,
        "code_bytes": overlay_bytes,
        "coverage_percent": 100*overlay_done/overlay_bytes,
        "distinct_function_bytes": fmap["distinct_function_bytes"] if fmap else None,
        "distinct_matched_bytes": fmap["distinct_matched_bytes"] if fmap else None,
        "distinct_coverage_percent": fmap["distinct_matched_percent"] if fmap else None,
        "basis": ("function bytes from tools/overlay_map.py (linear sweep of each container's code hull; repeated code "
                  "counted once per container; distinct_* counts each relocation-normalized body once)") if fmap
                 else "detected instruction estimate from tools/audit_overlays.py",
        "heuristic_detected_instruction_bytes": estimate["detected_instruction_bytes"],
        "inventory_is_heuristic": True,
    }
    report["known_ee_estimate"] = {
        "c_or_matched_bytes": numerator,
        "estimated_total_bytes": total+overlay_bytes,
        "coverage_percent": 100*numerator/(total+overlay_bytes),
        "span_scenario_percent": 100*numerator/(total+max(overlay_bytes, estimate["code_region_span_bytes"])),
        "span_scenario_is_confidence_interval": False,
        "basis": "Resident catalogued function bytes plus overlay function bytes, with repeated code counted in both scopes. Span scenario also counts gaps/data within identified code spans; neither is an exact whole-game percentage.",
        "excluded_scopes": ["IOP", "VU", "undiscovered EE code"],
    }

rom = Path(root)/"build/SCES_504.90.rom"
rom_hash = hashlib.sha1(rom.read_bytes()).hexdigest() if rom.exists() else None
report["rom_verified"] = rom_hash == "a553c3d3380a8baea9be4db6f972185d39f448e5"
if "--write-report" in sys.argv:
    destination = Path(sys.argv[sys.argv.index("--write-report")+1])
    destination.parent.mkdir(parents=True, exist_ok=True)
    destination.write_text(json.dumps(report, indent=2)+"\n")
if json_output:
    print(json.dumps(report, indent=2))
else:
    if report["known_ee_estimate"]:
        overall = report["known_ee_estimate"]
        overlays = report["ee_overlays"]
        if overlays["containers_fully_matched"] is not None:
            print(f"  EE effect overlays: {overlay_done}/{overlay_bytes} function bytes = {overlays['coverage_percent']:.2f}%; "
                  f"containers fully matched {overlays['containers_fully_matched']}, partially {overlays['containers_partially_matched']}, "
                  f"none {overlays['containers'] - overlays['containers_with_any_match']} of {overlays['containers']}")
            print(f"    distinct bodies: {overlays['distinct_matched_bytes']}/{overlays['distinct_function_bytes']} bytes = "
                  f"{overlays['distinct_coverage_percent']:.2f}% (tools/overlay_map.py)")
        else:
            print(f"  EE effect overlays: {overlays['containers_with_any_match']}/{overlays['containers']} containers with a matched unit; ~{overlay_bytes/1048576:.2f} MiB detected instructions (heuristic)")
        print(f"known EE C coverage estimate: ~{overall['coverage_percent']:.2f}% (ELF + overlays; repeated code counted)")
        print(f"  code-span scenario: ~{overall['span_scenario_percent']:.2f}% (includes gaps/data; not a confidence interval)")
    else:
        print("known EE estimate: unavailable (overlay audit missing)")
    print("whole-game coverage: unknown (IOP/VU and undiscovered EE code not inventoried)")
    print("debt markers: " + (", ".join(f"{k}={v}" for k, v in sorted(debt.items())) or "none") +
          f"   (per C-body KB: {sum(debt.values())/max(dbytes/1024,1):.2f})")
if "--debt" in sys.argv and not json_output:
    for k, v in where.items():
        print(f"\n{k}:"); [print("  ", w) for w in v]
