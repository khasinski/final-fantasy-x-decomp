#!/usr/bin/env python3
"""Function map, shared-code ranking and progress for the group 0x11 effect overlays.

usage: python3 -P tools/overlay_map.py [--jobs N] [--top N]
       python3 -P tools/overlay_map.py --layout RANK   # overlays/units/*.py skeleton for TU RANK

Inputs (from tools/audit_overlays.py): build/overlay-audit/code-size.json and the
584 build/overlay-audit/overlay-group11-fileNNNNN.bin containers (fixed base
0x01B00000). Matched ranges come from OVERLAY_UNITS in overlays/verify_overlays.py
(including drop-in overlays/units/*.py). Runs in a few seconds; rerun after adding a unit.

Outputs
  build/overlay-map/functions.json  every function: container, offset, size, hash, covered, callees
  build/overlay-map/tus.json        candidate translation units (all, with per-container starts)
  build/overlay-map/ranking.tsv     all OPEN function groups
  docs/overlay-ranking.tsv          top 500 OPEN function groups, sorted by size x containers
  docs/overlay-tus.tsv              top 100 candidate TUs, sorted by bytes x containers
  docs/overlay-families.tsv         chains of adjacent TUs sharing >= 80% of containers
  docs/overlay-progress.json        function-based matched/open bytes (total + per container),
                                    read by tools/status.py for docs/progress.json

Method
  1. Code discovery: control flow traced from the header vectors (0x00..0x18, 0x20..0x3C),
     stack prologues (addiu sp,-N followed by a ra save), every 0x01B0xxxx word in the
     pre-resource prefix that lands in the code hull (pointer tables in .data), and
     lui/addiu pairs that build a code address (task callbacks). Iterated to a fixed point.
  2. Code hull = [lowest, highest+4) discovered instruction. ee-gcc links all .text
     contiguously, so the hull is swept linearly.
  3. Function split: a function starts at an entry (jal/j-tail target, vector, pointer,
     prologue) or at the first non-nop word after the previous function ended. It ends after
     the delay slot of `jr ra`, or of a `j` to a known entry / to resident code (tail call),
     once no forward branch of the function reaches further. Alignment nops are not counted.
  4. Hashes over the function words with:
       hash      j/jal targets and every lui imm in 0x0010..0x020F plus the %lo users of
                 that register (addiu/ori/loads/stores) zeroed -> position- and resident-
                 address independent ("loose").
       hash_res  same, but resident (non 0x01Bx..0x020x) j/jal targets and %hi/%lo are kept;
                 only overlay-internal addresses are masked. Functions with equal hash_res
                 can be produced by one C body; groups/TUs below are keyed on hash_res.
  5. COVERED = function lies inside a .text range a verify_overlays.py unit matches for that
     container; PARTIAL = overlaps one; OPEN otherwise.

Limits (heuristic, not a certified disassembly)
  - %hi/%lo pairing is linear within a function (register-tracked, reset on overwrite);
    gcc may hoist a lui across blocks, a wrong pairing only makes hashes stricter.
  - Code reachable only through computed pointers not stored as a 0x01B0xxxx word is still
    swept as part of the hull, but its start may merge into the previous function.
  - `j` inside a function to a forward label that is also a separately discovered entry
    is read as a tail call (rare in gcc 2.9 output).
  - Integer constants 0x00100000..0x020FFFFF built with lui are masked as if addresses.
"""
import argparse, bisect, collections, hashlib, importlib.util, json, os, struct, sys
from concurrent.futures import ProcessPoolExecutor
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
BASE = 0x01B00000
AUDIT = ROOT / "build/overlay-audit"
OUT = ROOT / "build/overlay-map"
HI_ANY = (0x0010, 0x0210)        # lui immediates treated as absolute addresses
HI_OVL = (0x01B0, 0x0210)        # ... of which overlay-internal (container + its bss)
LO_USERS = {9, 13, 25, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 46, 49, 55, 57, 63, 30, 31}
NOP = 0


def load_verify():
    spec = importlib.util.spec_from_file_location("verify_overlays", ROOT / "overlays/verify_overlays.py")
    mod = importlib.util.module_from_spec(spec)
    spec.loader.exec_module(mod)
    return mod


def unit_ranges(vo):
    """{cid: [(start_off, end_off, unit_stem)]} of matched .text ranges."""
    cov = collections.defaultdict(set)
    for unit in vo.OVERLAY_UNITS:
        stem = Path(unit["src"]).stem
        layouts = unit.get("container_layouts") or [
            {"cid": c, "text_start": unit["text_start"], "text_end": unit["text_end"]} for c in unit["containers"]]
        for item in layouts:
            cov[item["cid"]].add((item["text_start"] - BASE, item["text_end"] - BASE, stem))
    return {c: sorted(v) for c, v in cov.items()}


def resident_names():
    names = {}
    for line in open(ROOT / "config/funcs.txt"):
        n, a, _ = line.split()
        names[int(a, 16)] = n
    try:
        vo = load_verify()
        for n, a in vo.RESIDENT_SYMS.items():
            if not n.startswith("func_"):
                names[a] = n
    except Exception:
        pass
    return names


# ---------------------------------------------------------------------------- discovery
def plausible(x):
    """Rough 'could be an instruction gcc emitted' test (mirrors tools/audit_overlays.py)."""
    op = x >> 26; rs = (x >> 21) & 31; rt = (x >> 16) & 31; fn = x & 63
    if x == 0xFFFFFFFF or op in (0x13, 0x1D, 0x3B):
        return False
    if op == 15 and (rs != 0 or rt == 0):
        return False
    if op == 0 and fn not in {0, 2, 3, 4, 6, 7, 8, 9, 10, 11, 12, 13, 15, 16, 17, 18, 19, 20, 22, 23, 24, 25, 26, 27,
                              28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 42, 43, 44, 45, 46, 47, 56, 58, 59, 60, 62, 63}:
        return False
    return True


def trace(w, end, seeds):
    def inside(p):
        return 0x40 <= p < end and p % 4 == 0
    seen = set(); calls = set(); todo = [s for s in seeds if inside(s)]
    while todo:
        p = todo.pop()
        while inside(p) and p not in seen:
            x = w[p // 4]
            if not plausible(x) or (x == 0 and not any(w[p // 4:p // 4 + 8])):
                break
            seen.add(p)
            op = x >> 26; fn = x & 63; rs = (x >> 21) & 31; rt = (x >> 16) & 31
            direct = op in (2, 3); jr = op == 0 and fn in (8, 9)
            branch = op in (4, 5, 6, 7, 20, 21, 22, 23) or (op == 1 and rt in (0, 1, 2, 3, 16, 17, 18, 19)) or (op in (16, 17, 18) and rs == 8)
            if direct or jr or branch:
                if inside(p + 4):
                    seen.add(p + 4)
                if direct:
                    dest = ((x & 0x3FFFFFF) << 2) - BASE
                    if inside(dest):
                        todo.append(dest)
                        calls.add(dest)
                    if op == 2:
                        break
                elif jr:
                    if fn == 8:
                        break
                else:
                    imm = x & 0xFFFF; imm -= 0x10000 if imm & 0x8000 else 0
                    dest = p + 4 + imm * 4
                    if inside(dest):
                        todo.append(dest)
                    if op == 4 and rs == rt:
                        break
                p += 8
            else:
                p += 4
    return seen, calls


def lohi_pointers(w, lo, hi):
    """Addresses built by lui r,hi / addiu r',r,lo pairs inside [lo, hi)."""
    out = set(); last = {}
    for p in range(lo, hi, 4):
        x = w[p // 4]; op = x >> 26; rs = (x >> 21) & 31; rt = (x >> 16) & 31
        if op == 15:
            last[rt] = (x & 0xFFFF) << 16
        elif op == 9 and rs in last:
            imm = x & 0xFFFF; imm -= 0x10000 if imm & 0x8000 else 0
            out.add(last[rs] + imm - BASE)
    return out


def discover(w, end):
    hdr = [x - BASE for i, x in enumerate(w[:16]) if i != 7]
    pro = set()
    for p in range(0x40, end - 32, 4):
        x = w[p // 4]
        if x >> 16 == 0x27BD and (x & 0xFFFF) >= 0xF000 and (x & 0xFFFF) % 8 == 0 and \
                any(z >> 16 in (0xFFBF, 0xAFBF, 0x7FBF) for z in w[p // 4 + 1:p // 4 + 12]):
            pro.add(p)
    # gcc may schedule e.g. a lui before the sp adjust: a prologue seeds tracing, but is only
    # trusted as a function start when it follows padding or the delay slot of a jr ra / j.
    trusted = {p for p in pro if w[p // 4 - 1] == NOP or w[p // 4 - 2] == 0x03E00008 or w[p // 4 - 2] >> 26 == 2}
    words = {x - BASE for x in w[:end // 4] if BASE <= x < BASE + end and x % 4 == 0}
    seeds = set(hdr) | pro
    seen, calls = trace(w, end, seeds)
    datawords = set(); codeptrs = set()
    for _ in range(4):
        if not seen:
            break
        lo, hi = min(seen), max(seen) + 4
        ok = lambda p: lo <= p < hi and p not in seen and p % 4 == 0 and w[p // 4] and plausible(w[p // 4])
        dw = {p for p in words if ok(p)}
        cp = {p for p in lohi_pointers(w, lo, hi) if ok(p)}
        if not dw and not cp:
            break
        datawords |= dw; codeptrs |= cp
        seeds |= dw | cp
        seen, calls = trace(w, end, seeds)

    def start_like(p):
        # data words also hold switch tables (case labels): only a word that points right after
        # a function end (jr ra / j + delay slot, optionally one alignment nop) or at a trusted
        # prologue is taken as a function start; the others only seed tracing.
        if p in trusted:
            return True
        for k in (2, 3):
            if k == 3 and w[p // 4 - 1] != NOP:
                continue
            y = w[p // 4 - k]
            if y == 0x03E00008 or (y >> 26 == 2 and not (BASE <= (y & 0x3FFFFFF) << 2 < BASE + end)):
                return True
        return False
    entries = ({s for s in set(hdr) | codeptrs | trusted if s in seen} | {s for s in datawords if s in seen and start_like(s)}
               | {c for c in calls if c in seen})
    return seen, entries, pro


# ---------------------------------------------------------------------------- split + hash
def branch_dest(x, p):
    op = x >> 26; rt = (x >> 16) & 31; rs = (x >> 21) & 31
    if op in (4, 5, 6, 7, 20, 21, 22, 23) or (op == 1 and rt in (0, 1, 2, 3, 16, 17, 18, 19)) or (op in (16, 17, 18) and rs == 8):
        imm = x & 0xFFFF; imm -= 0x10000 if imm & 0x8000 else 0
        return p + 4 + imm * 4
    return None


def split(w, lo, hi, entries):
    ent = sorted(e for e in entries if lo <= e < hi)
    funcs = []; p = lo
    while p < hi:
        while p < hi and w[p // 4] == NOP and p not in entries:
            p += 4
        if p >= hi:
            break
        start = p; reach = p
        k = bisect.bisect_right(ent, start)
        nxt = ent[k] if k < len(ent) else hi
        q = p; stop = None
        while q < min(nxt, hi):
            x = w[q // 4]; op = x >> 26; fn = x & 63; rs = (x >> 21) & 31
            d = branch_dest(x, q)
            if d is not None:
                if start <= d < nxt:
                    reach = max(reach, d)
                q += 8; continue
            if op == 2:
                t = ((x & 0x3FFFFFF) << 2) - BASE
                tail = t in entries and t != start or not (lo <= t < hi)
                if not tail and start <= t < nxt:
                    reach = max(reach, t)
                if tail and q + 8 > reach:
                    stop = q + 8; break
                q += 8; continue
            if op == 3 or (op == 0 and fn == 9):
                q += 8; continue
            if op == 0 and fn == 8:
                if rs == 31 and q + 8 > reach:
                    stop = q + 8; break
                q += 8; continue
            q += 4
        if stop is None:
            stop = min(q, nxt, hi)
            while stop - 4 > start and w[stop // 4 - 1] == NOP:
                stop -= 4
        stop = min(stop, hi)
        funcs.append((start, stop))
        p = stop
    return funcs


def is_ovl(hi16):
    return HI_OVL[0] <= hi16 < HI_OVL[1]


GPR_WRITERS_RT = {8, 9, 10, 11, 12, 13, 14, 15, 24, 25, 26, 27, 30, 32, 33, 34, 35, 36, 37, 38, 39, 55}


def written_gpr(x):
    op = x >> 26
    if op in (0, 28):
        return (x >> 11) & 31
    if op in GPR_WRITERS_RT:
        return (x >> 16) & 31
    if op == 3:
        return 31
    if op in (16, 17, 18) and ((x >> 21) & 31) in (0, 1, 2):   # mfc/dmfc/cfc
        return (x >> 16) & 31
    return None


def normalize(w, start, stop):
    """-> (loose words, resident-keeping words, resident refs, overlay-internal ref count)."""
    loose = []; strict = []; callees = []; internal = 0; marks = {}
    for p in range(start, stop, 4):
        x = w[p // 4]; op = x >> 26; rs = (x >> 21) & 31; rt = (x >> 16) & 31
        lx = sx = x
        dst = written_gpr(x)
        if op in (2, 3):
            t = (x & 0x3FFFFFF) << 2
            lx = x & 0xFC000000
            if BASE <= t < 0x02100000:
                sx = lx; internal += 1
            else:
                callees.append(("jal" if op == 3 else "j", t))
        elif op == 15 and HI_ANY[0] <= (x & 0xFFFF) < HI_ANY[1]:
            lx = x & 0xFFFF0000
            ov = is_ovl(x & 0xFFFF)
            if ov:
                sx = lx; internal += 1
            marks[rt] = (ov, x & 0xFFFF)
            dst = None                      # this write *is* the mark
        elif op in LO_USERS and rs in marks:
            ov, h = marks[rs]
            lx = x & 0xFFFF0000
            if ov:
                sx = lx
            else:
                imm = x & 0xFFFF; imm -= 0x10000 if imm & 0x8000 else 0
                callees.append(("ref", (h << 16) + imm))
        if dst is not None:
            marks.pop(dst, None)
        loose.append(lx); strict.append(sx)
    return loose, strict, callees, internal


def internal_refs(w, start, stop):
    """Overlay-internal addresses a function references, in instruction order:
    j/jal targets and resolved %hi/%lo pairs (same register tracking as normalize())."""
    out = []; marks = {}
    for p in range(start, stop, 4):
        x = w[p // 4]; op = x >> 26; rs = (x >> 21) & 31; rt = (x >> 16) & 31
        dst = written_gpr(x)
        if op in (2, 3):
            t = (x & 0x3FFFFFF) << 2
            if BASE <= t < 0x02100000:
                out.append(("func", t))
        elif op == 15 and HI_ANY[0] <= (x & 0xFFFF) < HI_ANY[1]:
            if is_ovl(x & 0xFFFF):
                marks[rt] = (x & 0xFFFF) << 16
            else:
                marks.pop(rt, None)
            dst = None
        elif op in LO_USERS and rs in marks:
            imm = x & 0xFFFF; imm -= 0x10000 if imm & 0x8000 else 0
            out.append(("data", marks[rs] + imm))
        if dst is not None:
            marks.pop(dst, None)
    return out


def layout_snippet(rank):
    """Python text for overlays/units/<stem>.py: per-container text range + overlay-internal symbols."""
    rows = json.loads((OUT / "tus.json").read_text())
    r = rows[rank - 1]
    flat = json.loads((OUT / "functions.json").read_text())["functions"]
    byc = collections.defaultdict(dict)
    for f in flat:
        byc[f["container"]].setdefault(f["hash_res"], f)
    conts = r["containers"]; ref = conts[0]
    words = {}
    for c in conts:
        b = (AUDIT / f"overlay-group11-file{c:05d}.bin").read_bytes()
        words[c] = struct.unpack("<%dI" % (len(b) // 4), b[:len(b) // 4 * 4])
    spans = {}; refs = {}
    for c in conts:
        fs = [byc[c][h] for h in r["hashes"]]
        lo = fs[0]["offset"]; hi = fs[-1]["offset"] + fs[-1]["size"]
        spans[c] = (lo, (hi + 7) & ~7)
        refs[c] = [x for f in fs for x in internal_refs(words[c], f["offset"], f["offset"] + f["size"])]
    lo_r, hi_r = spans[ref]
    names = {}
    for k, a in refs[ref]:
        if not (BASE + lo_r <= a < BASE + hi_r):
            names.setdefault(a, ("func_%08X" if k == "func" else "D_%08X") % a)
    table = []; bad = []
    for c in conts:
        if len(refs[c]) != len(refs[ref]):
            bad.append(c); continue
        m = {}
        for (k, a0), (_, a1) in zip(refs[ref], refs[c]):
            if a0 in names:
                if m.setdefault(names[a0], a1) != a1:
                    bad.append(c)
        table.append((c, spans[c], m))
    rel = {}   # symbols that keep a fixed distance to the TU start in every container
    for n in sorted(set(names.values())):
        ds = {m[n] - (BASE + sp[0]) for c, sp, m in table if n in m}
        rel[n] = ds.pop() if len(ds) == 1 else None
    stem = f"ovl_{ref:05d}_{BASE + lo_r:08x}"
    size = hi_r - lo_r
    var = [n for n in sorted(rel) if rel[n] is None]
    lines = [f"# TU rank {rank} ({r['family']}): {r['functions']} functions, {r['bytes']} B, {len(conts)} containers.",
             f"# Generated by: python3 -P tools/overlay_map.py --layout {rank}. Symbols are named by their address in",
             f"# file{ref:05d}; text_end = end of last function rounded up to 8 (the object's .text size).",
             "# Check the C .text size matches; adjust symbol names to what the C file declares.",
             "", "BASE_SYMS = {  # fixed offset from text_start in every container"]
    lines += [f"    {n!r}: {d:+#x}," for n, d in sorted(rel.items()) if d is not None]
    lines += ["}", "", f"# (cid, text_start{''.join(', ' + n for n in var)})", "LAYOUTS = ["]
    for c, sp, m in table:
        lines.append(f"    ({c}, 0x{BASE + sp[0]:08X}" + "".join(f", 0x{m.get(n, 0):08X}" for n in var) + "),")
    lines += ["]", "", "",
              "def _syms(ts" + "".join(", " + n.lower() for n in var) + "):",
              "    s = {n: ts + d for n, d in BASE_SYMS.items()}"]
    for n in var:
        lines.append(f"    s[{n!r}] = {n.lower()}")
    lines += ["    return s", "", "",
              "UNITS = [{",
              f"    \"src\": \"overlays/group11/{stem}.c\",  # rename as you like",
              "    \"containers\": [row[0] for row in LAYOUTS],",
              f"    \"text_start\": LAYOUTS[0][1],",
              f"    \"text_end\": LAYOUTS[0][1] + 0x{size:X},",
              f"    \"discovered_code_bytes\": {r['bytes']},",
              f"    \"functions\": {r['functions']},",
              "    \"syms\": _syms(*LAYOUTS[0][1:]),",
              "    \"container_layouts\": [",
              f"        {{\"cid\": row[0], \"text_start\": row[1], \"text_end\": row[1] + 0x{size:X}, \"syms\": _syms(*row[1:])}}",
              "        for row in LAYOUTS",
              "    ],",
              "}]"]
    if bad:
        lines.insert(4, f"# WARNING: reference pattern differs in containers {sorted(set(bad))}; they are left out or need a check.")
    return "\n".join(lines) + "\n"


def sha(words):
    return hashlib.sha1(struct.pack("<%dI" % len(words), *words)).hexdigest()[:16]


def analyze(arg):
    cid, end, ranges = arg
    b = (AUDIT / f"overlay-group11-file{cid:05d}.bin").read_bytes()
    n = len(b) // 4
    w = struct.unpack("<%dI" % n, b[:n * 4])
    end = min(end, n * 4)
    seen, entries, _ = discover(w, end)
    if not seen:
        return cid, []
    lo, hi = min(seen), max(seen) + 4
    for _ in range(3):   # instructions scheduled before the first (unreferenced) prologue
        x = w[lo // 4 - 1]
        if lo - 4 >= 0x40 and x >> 26 in (9, 13, 15, 35) and plausible(x):
            lo -= 4
        else:
            break
    out = []
    for start, stop in split(w, lo, hi, entries | {lo}):
        if stop <= start:
            continue
        loose, strict, callees, internal = normalize(w, start, stop)
        cov = "OPEN"; unit = None
        for a, z, stem in ranges:
            if a <= start and stop <= z:
                cov = "COVERED"; unit = stem; break
            if start < z and a < stop:
                cov = "PARTIAL"; unit = stem
        reached = sum(1 for p in range(start, stop, 4) if p in seen)
        out.append(dict(off=start, size=stop - start, hash=sha(loose), hash_res=sha(strict),
                        raw=sha(list(w[start // 4:stop // 4])), covered=cov, unit=unit,
                        callees=callees, internal_refs=internal, entry=start in entries,
                        reached=reached * 4))
    return cid, out


# ---------------------------------------------------------------------------- reports
def subsystem(names):
    s = set()
    for n in names:
        a = n[1]
        if 0x0019F000 <= a < 0x001A5000:
            s.add("rcef")
        elif 0x00266000 <= a < 0x00270000:
            s.add("ppp")
        elif 0x00290000 <= a < 0x002D1000:
            s.add("oef")
        elif 0x001B0000 <= a < 0x001F0000:
            s.add("ms")
        elif 0x00100000 <= a < 0x00120000:
            s.add("ch")
        elif 0x002D1000 <= a < 0x002F0000:
            s.add("math")
    return "/".join(sorted(s)) or "-"


def main():
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("--jobs", type=int, default=os.cpu_count())
    ap.add_argument("--top", type=int, default=40)
    ap.add_argument("--layout", type=int, metavar="RANK",
                    help="print an overlays/units/<stem>.py skeleton (per-container text ranges and overlay-internal "
                         "symbols) for TU RANK of docs/overlay-tus.tsv, using the last map run, and exit")
    args = ap.parse_args()
    if args.layout:
        sys.stdout.write(layout_snippet(args.layout))
        return 0
    size_json = json.loads((AUDIT / "code-size.json").read_text())
    vo = load_verify()
    cov = unit_ranges(vo)
    names = resident_names()
    rows = [(f["index"], f["prefix_before_embedded_resource"], cov.get(f["index"], [])) for f in size_json["files"]]
    with ProcessPoolExecutor(args.jobs) as ex:
        results = dict(ex.map(analyze, rows, chunksize=8))
    cids = [r[0] for r in rows]

    def nm(a):
        return names.get(a, f"D_{a:08X}")     # funcs.txt holds every resident function start

    OUT.mkdir(parents=True, exist_ok=True)
    flat = []
    for cid in cids:
        for f in results[cid]:
            flat.append(dict(container=cid, offset=f["off"], addr=f"0x{BASE + f['off']:08X}", size=f["size"],
                             hash=f["hash"], hash_res=f["hash_res"], raw=f["raw"], covered=f["covered"], unit=f["unit"],
                             entry=f["entry"], reached_bytes=f["reached"], internal_refs=f["internal_refs"],
                             callees=sorted({f"{k}:{nm(a)}" for k, a in f["callees"]})))
    (OUT / "functions.json").write_text(json.dumps(dict(
        note="See tools/overlay_map.py docstring for method and limits. offset is container-relative; "
             "hash masks all absolute addresses, hash_res keeps resident ones.", functions=flat)) + "\n")

    # --- progress
    per = []
    tot = collections.Counter()
    for cid in cids:
        fs = results[cid]
        c = collections.Counter()
        for f in fs:
            c[f["covered"]] += f["size"]
        total = sum(c.values())
        state = "full" if total and c["COVERED"] == total else ("partial" if c["COVERED"] or c["PARTIAL"] else "none")
        per.append(dict(container=cid, functions=len(fs), code_bytes=total, matched_bytes=c["COVERED"],
                        partial_bytes=c["PARTIAL"], open_bytes=c["OPEN"], state=state))
        tot.update(c); tot[state] += 1
    code_total = sum(p["code_bytes"] for p in per)
    groups = collections.defaultdict(list)
    for cid in cids:
        for f in results[cid]:
            groups[f["hash_res"]].append((cid, f))
    distinct_bytes = sum(v[0][1]["size"] for v in groups.values())
    distinct_matched = sum(v[0][1]["size"] for v in groups.values() if any(f["covered"] == "COVERED" for _, f in v))
    progress = dict(
        metric="Function bytes from tools/overlay_map.py (heuristic split). matched = function inside a "
               "byte-identical verify_overlays.py unit range for that container.",
        containers=len(cids), functions=len(flat), code_bytes=code_total,
        matched_bytes=tot["COVERED"], partial_bytes=tot["PARTIAL"], open_bytes=tot["OPEN"],
        matched_percent=100 * tot["COVERED"] / code_total,
        containers_fully_matched=tot["full"], containers_partially_matched=tot["partial"],
        containers_unmatched=tot["none"],
        distinct_function_bodies=len(groups), distinct_function_bytes=distinct_bytes,
        distinct_matched_bytes=distinct_matched, distinct_matched_percent=100 * distinct_matched / distinct_bytes,
        per_container=per)
    head = json.dumps({k: v for k, v in progress.items() if k != "per_container"}, indent=1)[:-2]
    body = ",\n".join("  " + json.dumps(row) for row in per)
    (ROOT / "docs/overlay-progress.json").write_text(head + ',\n "per_container": [\n' + body + "\n ]\n}\n")

    # --- ranking of OPEN groups
    rank = []
    for h, inst in groups.items():
        if any(f["covered"] != "OPEN" for _, f in inst):
            continue
        conts = sorted({c for c, _ in inst})
        f0 = inst[0][1]
        rank.append(dict(hash_res=h, hash=f0["hash"], size=f0["size"], containers=conts, instances=len(inst),
                         score=f0["size"] * len(conts), example=f"{inst[0][0]}:0x{BASE + f0['off']:08X}",
                         callees=sorted({nm(a) for k, a in f0["callees"]}),
                         raw_variants=len({f['raw'] for _, f in inst})))
    rank.sort(key=lambda r: (-r["score"], r["example"]))
    loose_groups = collections.defaultdict(set)
    for r in rank:
        loose_groups[r["hash"]].add(r["hash_res"])
    for path, limit in ((OUT / "ranking.tsv", None), (ROOT / "docs/overlay-ranking.tsv", 500)):
      with open(path, "w") as fh:
        fh.write("# OPEN function groups (tools/overlay_map.py). score = size x containers. key = hash_res "
                 "(overlay addresses masked, resident kept); loose_siblings = other hash_res groups with the same loose hash."
                 + (f" Top {limit}; full list: build/overlay-map/ranking.tsv." if limit else "") + "\n")
        fh.write("rank\tscore\tsize\tcontainers\tinstances\traw_variants\thash_res\thash\tloose_siblings\texample\tresident_refs\tcontainer_list\n")
        for i, r in enumerate(rank[:limit], 1):
            fh.write(f"{i}\t{r['score']}\t{r['size']}\t{len(r['containers'])}\t{r['instances']}\t{r['raw_variants']}\t"
                     f"{r['hash_res']}\t{r['hash']}\t{len(loose_groups[r['hash']]) - 1}\t{r['example']}\t"
                     f"{','.join(r['callees'])}\t{','.join(map(str, r['containers']))}\n")

    # --- TU clustering
    gset = {r["hash_res"]: frozenset(r["containers"]) for r in rank}
    order = {}  # cid -> list of hash_res in address order (all functions)
    pos = {}    # (cid, hash_res) -> first index
    for cid in cids:
        order[cid] = [f["hash_res"] for f in results[cid]]
        for i, h in enumerate(order[cid]):
            pos.setdefault((cid, h), i)
    by_sig = collections.defaultdict(list)
    for h, s in gset.items():
        by_sig[s].append(h)
    tus = []
    for sig, hs in by_sig.items():
        ref = min(sig)
        hs.sort(key=lambda h: pos[(ref, h)])
        run = [hs[0]]
        runs = []
        for a, b2 in zip(hs, hs[1:]):
            if all(pos[(c, b2)] == pos[(c, a)] + 1 for c in sig):
                run.append(b2)
            else:
                runs.append(run); run = [b2]
        runs.append(run)
        for run in runs:
            tus.append((sig, run))
    unit_callees = collections.defaultdict(set); unit_cids = collections.defaultdict(set)
    for cid in cids:
        for f in results[cid]:
            if f["unit"] and f["covered"] == "COVERED":
                unit_callees[f["unit"]] |= {a for _, a in f["callees"] if a < BASE}
                unit_cids[f["unit"]].add(cid)
    byh = {}
    for cid in cids:
        for f in results[cid]:
            byh.setdefault((cid, f["hash_res"]), f)
    unit_start = collections.defaultdict(dict)   # stem -> {cid: text_start offset}
    for cid, rs in cov.items():
        for st, _, stem in rs:
            unit_start[stem][cid] = st
    tu_rows = []
    for sig, run in tus:
        ref = min(sig)
        fs = [byh[(ref, h)] for h in run]
        size = sum(f["size"] for f in fs)
        starts = {c: byh[(c, run[0])]["off"] for c in sig}
        raws = {tuple(byh[(c, h)]["raw"] for h in run) for c in sig}
        dups = sum(1 for c in sig for h in run if order[c].count(h) > 1)
        callees = sorted({a for f in fs for k, a in f["callees"] if a < BASE})
        best = None
        for u, uc in unit_callees.items():
            j = len(uc & set(callees)) / max(len(uc | set(callees)), 1)
            if best is None or j > best[1]:
                best = (u, j)
        # matched unit present in most of this TU's containers, and the TU's offset from it
        sib = None
        for u, starts_u in unit_start.items():
            common = sig & starts_u.keys()
            if common and (sib is None or len(common) > sib[1]):
                deltas = collections.Counter(starts[c] - starts_u[c] for c in common)
                sib = (u, len(common), deltas)
        if sib:
            d0, n0 = sib[2].most_common(1)[0]
            sib_txt = (f"{sib[0]} in {sib[1]}/{len(sig)}; tu_start = unit_start {d0:+#x}"
                       + ("" if n0 == sib[1] else f" in {n0}/{sib[1]} ({len(sib[2])} distinct deltas)"))
        else:
            sib_txt = None
        first = BASE + starts[ref]
        lo_off, hi_off = min(starts.values()), max(starts.values())
        idx = pos[(ref, run[0])]
        neigh = []
        for k in (idx - 1, idx + len(run)):
            if 0 <= k < len(results[ref]):
                g = results[ref][k]
                neigh.append(f"{g['covered']}:{g['unit'] or ''}@0x{BASE + g['off']:08X}")
        tu_rows.append(dict(
            score=size * len(sig), bytes=size, functions=len(run), containers=sorted(sig),
            ref=f"{ref}:0x{first:08X}..0x{BASE + fs[-1]['off'] + fs[-1]['size']:08X}",
            layout="identical" if lo_off == hi_off else f"relocated {lo_off - starts[ref]:+#x}..{hi_off - starts[ref]:+#x} (start 0x{BASE+lo_off:08X}..0x{BASE+hi_off:08X})",
            distinct_offsets=len(set(starts.values())), raw_variants=len(raws), internal_refs=sum(f["internal_refs"] for f in fs),
            subsystem=subsystem([(None, a) for a in callees]), resident_callees=[nm(a) for a in callees],
            closest_unit_by_callees=f"{best[0]} (jaccard {best[1]:.2f})" if best else None,
            sibling_unit=sib_txt, neighbours=neigh, dup_instances=dups, hashes=run,
            starts={str(c): f"0x{BASE + o:08X}" for c, o in sorted(starts.items())}))
    # families: chain TUs that follow each other in the reference container and share >= 80% containers
    tu_of = {h: i for i, r in enumerate(tu_rows) for h in r["hashes"]}
    parent = list(range(len(tu_rows)))

    def find(i):
        while parent[i] != i:
            parent[i] = parent[parent[i]]; i = parent[i]
        return i
    for i, r in enumerate(tu_rows):
        sig = set(r["containers"]); ref = min(sig)
        k = pos[(ref, r["hashes"][-1])] + 1
        if k < len(results[ref]) and results[ref][k]["hash_res"] in tu_of:
            j = tu_of[results[ref][k]["hash_res"]]
            other = set(tu_rows[j]["containers"])
            if len(sig & other) / len(sig | other) >= 0.8:
                parent[find(i)] = find(j)
    fam = collections.defaultdict(list)
    for i in range(len(tu_rows)):
        fam[find(i)].append(i)
    fam_rows = []
    for members in fam.values():
        rs = [tu_rows[i] for i in members]
        union = set().union(*(set(r["containers"]) for r in rs)); inter = set.intersection(*(set(r["containers"]) for r in rs))
        fam_rows.append(dict(members=members, score=sum(r["score"] for r in rs), bytes=sum(r["bytes"] for r in rs),
                             functions=sum(r["functions"] for r in rs), union=len(union), inter=len(inter),
                             ref=min(rs, key=lambda r: r["ref"])["ref"].split("..")[0]))
    fam_rows.sort(key=lambda f: -f["score"])
    for n, f in enumerate(fam_rows, 1):
        for i in f["members"]:
            tu_rows[i]["family"] = f"F{n}"
    tu_rows.sort(key=lambda r: (-r["score"], r["ref"]))
    (OUT / "tus.json").write_text(json.dumps(tu_rows, indent=1) + "\n")
    with open(ROOT / "docs/overlay-tus.tsv", "w") as fh:
        fh.write("# Candidate TUs: OPEN function groups that occur in exactly the same container set and are adjacent "
                 "in all of them (tools/overlay_map.py). Full list incl. per-container starts: build/overlay-map/tus.json.\n")
        fh.write("rank\tfamily\tscore\tbytes\tfuncs\tncont\tref_range\tlayout\traw_variants\tinternal_refs\tsubsystem\t"
                 "sibling_unit\tclosest_unit_by_callees\tneighbours\tresident_refs\tcontainers\n")
        for i, r in enumerate(tu_rows[:max(args.top, 100)], 1):
            fh.write(f"{i}\t{r['family']}\t{r['score']}\t{r['bytes']}\t{r['functions']}\t{len(r['containers'])}\t{r['ref']}\t{r['layout']}\t"
                     f"{r['raw_variants']}\t{r['internal_refs']}\t{r['subsystem']}\t{r['sibling_unit']}\t{r['closest_unit_by_callees']}\t"
                     f"{' '.join(r['neighbours'])}\t{','.join(r['resident_callees'])}\t{','.join(map(str, r['containers']))}\n")
    with open(ROOT / "docs/overlay-families.tsv", "w") as fh:
        fh.write("# TU families: candidate TUs adjacent in the reference container with >= 80% container overlap "
                 "(a likely shared library linked into many overlays). tu_ranks = rank in docs/overlay-tus.tsv.\n")
        fh.write("family\tscore\tbytes\tfuncs\ttus\tcontainers_union\tcontainers_all\tref_start\ttu_ranks\n")
        ranks = collections.defaultdict(list)
        for i, r in enumerate(tu_rows, 1):
            ranks[r["family"]].append(i)
        for n, f in enumerate(fam_rows[:50], 1):
            rk = ranks[f"F{n}"]
            fh.write(f"F{n}\t{f['score']}\t{f['bytes']}\t{f['functions']}\t{len(f['members'])}\t{f['union']}\t{f['inter']}\t{f['ref']}\t"
                     f"{','.join(map(str, rk[:30]))}{',...' if len(rk) > 30 else ''}\n")

    print(f"{len(cids)} containers, {len(flat)} functions, {code_total} code bytes "
          f"({len(groups)} distinct bodies, {distinct_bytes} distinct bytes)")
    print(f"matched {tot['COVERED']} B ({progress['matched_percent']:.2f}%), partial {tot['PARTIAL']} B, open {tot['OPEN']} B; "
          f"containers full {tot['full']} / partial {tot['partial']} / none {tot['none']}")
    print(f"distinct-body coverage: {distinct_matched}/{distinct_bytes} B ({progress['distinct_matched_percent']:.2f}%)")
    print(f"{len(rank)} OPEN groups, {len(tu_rows)} candidate TUs -> docs/overlay-ranking.tsv, docs/overlay-tus.tsv")
    return 0


if __name__ == "__main__":
    sys.exit(main())
