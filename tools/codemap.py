#!/usr/bin/env python3
"""Generate a visual decompilation code map (docs/codemap.svg) for FFX PAL (SCES_504.90).

Zero external dependencies. Reads config/funcs.txt, config/handwritten.txt, config/units.txt,
src/**/*.c, docs/overlay-progress.json, and docs/iop-vu-inventory.json.
"""
import collections
import glob
import html
import json
import os
import re
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
DATA_ADDRS = {0x17A600, 0x186C00}
TEXT_START = 0x100000
TEXT_END = 0x300500
ROW_BYTES = 0x10000  # 64 KB per row -> 32 rows


def load_main_elf():
    funcs = []
    for line in (ROOT / "config/funcs.txt").read_text().splitlines():
        if not line.strip() or line.startswith("#"):
            continue
        name, addr_s, size_s = line.split()
        addr, size = int(addr_s, 16), int(size_s, 16)
        funcs.append((addr, size, name))
    funcs.sort()

    hand = {}
    hpath = ROOT / "config/handwritten.txt"
    if hpath.exists():
        for line in hpath.read_text().splitlines():
            parts = line.split()
            if parts and not line.startswith("#"):
                hand[parts[0]] = parts[1]

    # Fast O(N) scan: any function NOT in an INCLUDE_ASM(...) is defined in C
    # (and check inline-asm wrappers only for functions in handwritten.txt)
    src_files = sorted(glob.glob(str(ROOT / "src/**/*.c"), recursive=True))
    inc_asm = set()
    bodies = {}
    inc_pat = re.compile(r'INCLUDE_ASM\("[^"]+",\s*([A-Za-z_]\w*)\)')
    for p in src_files:
        t = Path(p).read_text()
        inc_asm.update(inc_pat.findall(t))
        for fn in hand:
            if fn in t and fn not in inc_asm:
                m = re.search(r'\b' + re.escape(fn) + r'\s*\([^;{]*\)\s*\{', t)
                if m:
                    depth, i = 1, m.end()
                    while i < len(t) and depth:
                        ch = t[i]
                        if ch == "{":
                            depth += 1
                        elif ch == "}":
                            depth -= 1
                        i += 1
                    bodies[fn] = t[m.end():i - 1]
    defined = {name for _, _, name in funcs if name not in inc_asm}

    def is_wrapper(fn):
        body = bodies.get(fn)
        if body is None:
            return False
        rest = re.sub(r'__asm__\s+volatile\s*\((?:[^;]|"(?:\\.|[^"\\])*")*\)\s*;', "", body, flags=re.S)
        return rest.strip() == ""

    # Unit address ranges -> subsystem name
    units = []
    for line in (ROOT / "config/units.txt").read_text().splitlines():
        if not line.strip() or line.startswith("#"):
            continue
        parts = line.split()
        u, s, e = parts[0], int(parts[1], 16), int(parts[2], 16)
        units.append((s, e, u))
    units.sort()

    def unit_for(addr):
        lo, hi = 0, len(units) - 1
        while lo <= hi:
            mid = (lo + hi) // 2
            s, e, u = units[mid]
            if addr < s:
                hi = mid - 1
            elif addr >= e:
                lo = mid + 1
            else:
                return u
        return "crt0/other"

    def subsys_for(u):
        parts = u.split("/")
        if parts[0] == "sdk":
            return "sdk/" + parts[1]
        if parts[0] == "game" and len(parts) >= 2:
            if parts[1] == "menu" and len(parts) >= 3 and parts[2] in ("to", "tk"):
                return f"menu/{parts[2]}"
            return parts[1]
        return parts[0]

    items = []
    stats = collections.Counter()
    subsys_stats = collections.defaultdict(lambda: [0, 0, 0])  # c, open_decomp, policy

    for addr, size, name in funcs:
        u = unit_for(addr)
        sub = subsys_for(u)
        if addr < 0x1008D8 or addr in DATA_ADDRS:
            status = "data"
        elif name in defined and (name not in hand or not is_wrapper(name)):
            status = "c"
            stats["c_bytes"] += size
            stats["c_funcs"] += 1
            subsys_stats[sub][0] += size
        elif name in hand:
            status = "policy"
            stats["policy_bytes"] += size
            stats["policy_funcs"] += 1
            subsys_stats[sub][2] += size
        else:
            status = "open"
            stats["open_bytes"] += size
            stats["open_funcs"] += 1
            subsys_stats[sub][1] += size
        if status != "data":
            stats["total_bytes"] += size
            stats["total_funcs"] += 1
        items.append((addr, size, name, status, sub))

    return items, stats, subsys_stats, units


def build_svg():
    items, stats, subsys_stats, units = load_main_elf()
    ovl = json.loads((ROOT / "docs/overlay-progress.json").read_text())
    iop_vu = json.loads((ROOT / "docs/iop-vu-inventory.json").read_text())

    # Colors (GitHub-dark inspired palette)
    BG = "#0d1117"
    CARD = "#161b22"
    BORDER = "#30363d"
    TXT = "#e6edf3"
    MUTED = "#8b949e"
    C_MATCH = "#22c55e"      # emerald green
    C_OPEN = "#ef4444"       # bright red
    C_POLICY = "#475569"     # slate blue-gray
    C_DATA = "#1e293b"       # dark slate
    C_CYAN = "#06b6d4"       # 90-99% overlay
    C_AMBER = "#f59e0b"      # 70-89% overlay
    C_PURPLE = "#a855f7"     # IOP/VU scope

    W = 1400
    # Compute Main ELF metrics
    elf_raw = 100.0 * stats["c_bytes"] / stats["total_bytes"]
    elf_decomp_tot = stats["total_bytes"] - stats["policy_bytes"]
    elf_decomp = 100.0 * stats["c_bytes"] / elf_decomp_tot

    ovl_raw = ovl["matched_percent"]
    ovl_decomp = ovl["decompilable_matched_percent"]
    ovl_full = ovl["containers_fully_matched"]
    ovl_tot = ovl["containers"]

    comb_num = stats["c_bytes"] + ovl["matched_bytes"]
    comb_tot = stats["total_bytes"] + ovl["code_bytes"]
    comb_decomp_tot = elf_decomp_tot + (ovl["code_bytes"] - ovl["policy_assembly_bytes"])
    comb_raw = 100.0 * comb_num / comb_tot
    comb_decomp = 100.0 * comb_num / comb_decomp_tot

    isum = iop_vu["iop"]["summary"]
    vu = iop_vu["vu"]

    svg = []
    svg.append(f'<svg xmlns="http://www.w3.org/2000/svg" width="{W}" height="1860" viewBox="0 0 {W} 1860">')
    svg.append(f"""<style>
      text {{ font-family: -apple-system, BlinkMacSystemFont, "Segoe UI", Roboto, Helvetica, Arial, sans-serif; fill: {TXT}; }}
      .mono {{ font-family: ui-monospace, SFMono-Regular, Menlo, Monaco, Consolas, monospace; }}
      .muted {{ fill: {MUTED}; }}
      .title {{ font-size: 24px; font-weight: 700; }}
      .h2 {{ font-size: 16px; font-weight: 700; }}
      .kpi-val {{ font-size: 26px; font-weight: 700; }}
      .kpi-lbl {{ font-size: 12px; fill: {MUTED}; }}
      .kpi-sub {{ font-size: 12px; fill: #94a3b8; }}
      .small {{ font-size: 11px; }}
      .tiny {{ font-size: 10px; }}
    </style>""")
    svg.append(f'<rect width="{W}" height="1860" fill="{BG}"/>')

    # Header
    svg.append(f'<text x="32" y="42" class="title">Final Fantasy X (PAL SCES_504.90) — Decompilation Code Map</text>')
    svg.append(f'<text x="32" y="64" class="small muted">Byte-accurate memory map of Main ELF .text (2.0 MB), subsystem progress, 584 EE battle-effect overlays, and IOP/VU1 inventory</text>')

    # Legend (top right)
    leg_x = 760
    legend = [
        (C_MATCH, "Matched C89"),
        (C_OPEN, "Open Decompilable"),
        (C_POLICY, "Handwritten Policy-ASM (VU0/MMI/SDK)"),
        (C_DATA, "Data / crt0"),
    ]
    cx = leg_x
    for col, lbl in legend:
        svg.append(f'<rect x="{cx}" y="30" width="12" height="12" rx="2" fill="{col}"/>')
        svg.append(f'<text x="{cx+18}" y="40" class="small">{html.escape(lbl)}</text>')
        cx += 28 + len(lbl) * 6.5

    # IOP & VU1 live progress
    iop_prog_path = ROOT / "docs/iopsound-progress.json"
    iop_prog = json.loads(iop_prog_path.read_text()) if iop_prog_path.exists() else None
    iop_mbytes = iop_prog["matched_bytes"] if iop_prog else 0
    iop_cbytes = iop_prog["code_bytes"] if iop_prog else isum["standalone_game_text_bytes"]
    iop_stub_bytes = iop_prog["import_stub_bytes"] if iop_prog else 0
    iop_mfuncs = iop_prog["matched_functions"] if iop_prog else 0
    iop_tfuncs = iop_prog["total_functions"] if iop_prog else 0
    iop_decomp = 100.0 * iop_mbytes / iop_cbytes if iop_cbytes else 0.0
    vu_from_src = (ROOT / "vu/vu1_prog1.vsm").exists() and (ROOT / "vu/vu1_prog2.vsm").exists()
    vu_done = vu["total_code_bytes"] if vu_from_src else 0
    vu_pct = 100.0 if vu_from_src else 0.0

    # KPI Cards
    cards = [
        ("Main ELF (SCES_504.90)", f"{elf_decomp:.2f}%", f"decompilable C ({elf_raw:.2f}% raw)", f"{stats['c_funcs']:,} / {stats['total_funcs']:,} funcs  |  {stats['open_bytes']/1024:.1f} KB open", C_MATCH),
        ("584 EE Overlays", f"{ovl_decomp:.2f}%", f"decompilable C ({ovl_raw:.2f}% raw)", f"{ovl_full} / {ovl_tot} full containers ({100*ovl_full/ovl_tot:.1f}%)", C_CYAN),
        ("Combined Known EE", f"~{comb_decomp:.2f}%", f"decompilable C (~{comb_raw:.2f}% raw)", f"15.59 MB matched / 19.41 MB total EE", "#38bdf8"),
        ("IOP & VU1", f"VU1 {vu_pct:.0f}% · IOP {iop_decomp:.1f}%", f"VU1: {vu['total_instructions']:,} insns | IOP: {iop_mfuncs}/{iop_tfuncs} funcs", f"IOPSOUND {iop_mbytes/1024:.1f}/{iop_cbytes/1024:.1f} KB C89  |  + 24 SDK IRX", C_MATCH if vu_from_src else C_PURPLE),
    ]
    cw = 322
    for idx, (title, val, sub1, sub2, accent) in enumerate(cards):
        x = 32 + idx * (cw + 16)
        y = 84
        svg.append(f'<rect x="{x}" y="{y}" width="{cw}" height="104" rx="8" fill="{CARD}" stroke="{BORDER}"/>')
        svg.append(f'<rect x="{x}" y="{y}" width="{cw}" height="4" rx="2" fill="{accent}"/>')
        svg.append(f'<text x="{x+16}" y="{y+26}" class="kpi-lbl">{html.escape(title)}</text>')
        svg.append(f'<text x="{x+16}" y="{y+58}" class="kpi-val" style="fill:{accent}">{html.escape(val)}</text>')
        svg.append(f'<text x="{x+16}" y="{y+78}" class="kpi-sub">{html.escape(sub1)}</text>')
        svg.append(f'<text x="{x+16}" y="{y+94}" class="tiny muted">{html.escape(sub2)}</text>')

    # SECTION 1: Main ELF .text 2D Memory Map (32 rows x 64 KB = 2 MB)
    y0 = 216
    svg.append(f'<rect x="32" y="{y0}" width="{W-64}" height="568" rx="8" fill="{CARD}" stroke="{BORDER}"/>')
    svg.append(f'<text x="48" y="{y0+28}" class="h2">1. Main ELF .text Memory Map (0x00100000 – 0x0030049C, 64 KB per row)</text>')
    svg.append(f'<text x="48" y="{y0+46}" class="small muted">Every colored block is drawn at its exact byte address and length. Hover any block in a browser to see function name, address, and size.</text>')

    map_x = 122
    map_y = y0 + 62
    map_w = 1040
    row_h = 13
    row_gap = 2
    num_rows = 32

    # Dominant subsystem label per 64 KB row
    row_subs = [collections.Counter() for _ in range(num_rows)]
    for addr, size, name, status, sub in items:
        r = (addr - TEXT_START) // ROW_BYTES
        if 0 <= r < num_rows:
            row_subs[r][sub] += size

    # Draw row backgrounds & axis labels
    for r in range(num_rows):
        ry = map_y + r * (row_h + row_gap)
        raddr = TEXT_START + r * ROW_BYTES
        svg.append(f'<text x="{map_x - 10}" y="{ry + 10}" text-anchor="end" class="tiny mono muted">0x{raddr:06X}</text>')
        svg.append(f'<rect x="{map_x}" y="{ry}" width="{map_w}" height="{row_h}" fill="#0b0f14" rx="1"/>')
        top_subs = ", ".join(k for k, _ in row_subs[r].most_common(2))
        svg.append(f'<text x="{map_x + map_w + 10}" y="{ry + 10}" class="tiny mono muted">{html.escape(top_subs)}</text>')

    # Draw functions (merge tiny adjacent same-status functions < 32 B? No, only ~11k rects, or merge contiguous same-status runs for ultra-fast SVG rendering!)
    # Let's merge contiguous runs of same status within each row EXCEPT keep open/policy tooltips crisp, or merge runs within same (row, status, subsys) so SVG stays < 250 KB and super snappy!
    runs = []
    for addr, size, name, status, sub in items:
        cur_a = addr
        rem = size
        while rem > 0:
            r = (cur_a - TEXT_START) // ROW_BYTES
            if r < 0 or r >= num_rows:
                break
            row_end = TEXT_START + (r + 1) * ROW_BYTES
            chunk = min(rem, row_end - cur_a)
            if runs and runs[-1][0] == r and runs[-1][3] == status and runs[-1][4] == sub and runs[-1][1] + runs[-1][2] == cur_a:
                runs[-1][2] += chunk
                runs[-1][5] += 1
                if len(runs[-1][6]) < 3:
                    runs[-1][6].append(name)
            else:
                runs.append([r, cur_a, chunk, status, sub, 1, [name]])
            cur_a += chunk
            rem -= chunk

    col_map = {"c": C_MATCH, "open": C_OPEN, "policy": C_POLICY, "data": C_DATA}
    for r, a, sz, status, sub, cnt, names in runs:
        ry = map_y + r * (row_h + row_gap)
        rx = map_x + ((a - (TEXT_START + r * ROW_BYTES)) / ROW_BYTES) * map_w
        rw = max(0.8, (sz / ROW_BYTES) * map_w)
        label = names[0] if cnt == 1 else f"{names[0]} (+{cnt-1} more)"
        tip = f"{label} | {sub} | 0x{a:06X} ({sz:,} B) | {status.upper()}"
        svg.append(f'<rect x="{rx:.2f}" y="{ry}" width="{rw:.2f}" height="{row_h}" fill="{col_map[status]}"><title>{html.escape(tip)}</title></rect>')

    # SECTION 2: Subsystem Breakdown (Left) + 584 Overlays Grid (Right)
    y1 = 804
    left_w = 656
    right_x = 32 + left_w + 16
    right_w = W - 64 - left_w - 16
    sec2_h = 680

    # Left card: Subsystem breakdown
    svg.append(f'<rect x="32" y="{y1}" width="{left_w}" height="{sec2_h}" rx="8" fill="{CARD}" stroke="{BORDER}"/>')
    svg.append(f'<text x="48" y="{y1+28}" class="h2">2. Main ELF Breakdown by Subsystem</text>')
    svg.append(f'<text x="48" y="{y1+46}" class="small muted">Sorted by total code size. Percentage shown is decompilable C coverage (excl. policy-asm).</text>')

    sorted_subs = sorted(subsys_stats.items(), key=lambda kv: sum(kv[1]), reverse=True)
    # Keep top 22 subsystems
    bar_x = 178
    bar_w = 340
    by = y1 + 68
    for sub, (cb, ob, pb) in sorted_subs[:22]:
        tot = cb + ob + pb
        if tot == 0:
            continue
        dec_tot = cb + ob
        dec_pct = 100.0 * cb / dec_tot if dec_tot > 0 else 100.0
        svg.append(f'<text x="{bar_x - 10}" y="{by + 12}" text-anchor="end" class="small mono">{html.escape(sub)}</text>')
        w_c = bar_w * cb / tot
        w_o = bar_w * ob / tot
        w_p = bar_w * pb / tot
        svg.append(f'<rect x="{bar_x}" y="{by}" width="{bar_w}" height="15" rx="2" fill="#0b0f14"/>')
        if w_c > 0:
            svg.append(f'<rect x="{bar_x}" y="{by}" width="{w_c:.2f}" height="15" fill="{C_MATCH}"/>')
        if w_o > 0:
            svg.append(f'<rect x="{bar_x+w_c:.2f}" y="{by}" width="{w_o:.2f}" height="15" fill="{C_OPEN}"/>')
        if w_p > 0:
            svg.append(f'<rect x="{bar_x+w_c+w_o:.2f}" y="{by}" width="{w_p:.2f}" height="15" fill="{C_POLICY}"/>')
        info = f"{dec_pct:5.1f}%  ({ob/1024:4.1f} KB open / {tot/1024:5.1f} KB)"
        svg.append(f'<text x="{bar_x + bar_w + 10}" y="{by + 12}" class="tiny mono muted">{html.escape(info)}</text>')
        by += 27

    # Right card: 584 Battle-Effect Overlays Tile Matrix
    ovl_100c = sum(1 for c in ovl["per_container"] if c["open_bytes"] - c["policy_asm_bytes"] <= 0)
    ovl_pol_only = ovl_100c - ovl_full
    svg.append(f'<rect x="{right_x}" y="{y1}" width="{right_w}" height="{sec2_h}" rx="8" fill="{CARD}" stroke="{BORDER}"/>')
    svg.append(f'<text x="{right_x+16}" y="{y1+28}" class="h2">3. 584 EE Battle-Effect Overlays (group11)</text>')
    svg.append(f'<text x="{right_x+16}" y="{y1+46}" class="small muted">Each tile = 1 container. {ovl_100c}/584 ({100*ovl_100c/ovl_tot:.1f}%) are 100% C ({ovl_full} full + {ovl_pol_only} policy-only); 0 untouched.</text>')

    # Tile legend
    tleg = [(C_MATCH, f"100% Full ({ovl_full})"), ("#10b981", f"100% C ({ovl_pol_only})"), (C_CYAN, "90–99.9%"), (C_AMBER, "70–89.9%"), (C_OPEN, "<70%")]
    tx = right_x + 16
    for col, lbl in tleg:
        svg.append(f'<rect x="{tx}" y="{y1+58}" width="10" height="10" rx="2" fill="{col}"/>')
        svg.append(f'<text x="{tx+15}" y="{y1+67}" class="tiny">{html.escape(lbl)}</text>')
        tx += 24 + len(lbl) * 6.0

    # Sort containers: full first, then 100% C, then by decompilable % descending
    def ovl_decomp_pct(c):
        dt = c["code_bytes"] - c["policy_asm_bytes"]
        return 100.0 * c["matched_bytes"] / dt if dt > 0 else 100.0

    per_c = sorted(ovl["per_container"], key=lambda c: (c["state"] == "full", c["open_bytes"] - c["policy_asm_bytes"] <= 0, ovl_decomp_pct(c), -c["open_bytes"]), reverse=True)
    cols = 25
    tile = 21
    gap = 4
    gx0 = right_x + 18
    gy0 = y1 + 82
    for idx, c in enumerate(per_c):
        r, col_i = divmod(idx, cols)
        x = gx0 + col_i * (tile + gap)
        y = gy0 + r * (tile + gap)
        dp = ovl_decomp_pct(c)
        if c["state"] == "full":
            fill = C_MATCH
        elif c["open_bytes"] - c["policy_asm_bytes"] <= 0:
            fill = "#10b981"
        elif dp >= 90.0:
            fill = C_CYAN
        elif dp >= 70.0:
            fill = C_AMBER
        else:
            fill = C_OPEN
        tip = f"file0{c['container']} | {c['state'].upper()} | {dp:.1f}% decomp | matched {c['matched_bytes']:,}B / open {c['open_bytes']:,}B (policy {c['policy_asm_bytes']:,}B)"
        svg.append(f'<rect x="{x}" y="{y}" width="{tile}" height="{tile}" rx="3" fill="{fill}" opacity="0.92"><title>{html.escape(tip)}</title></rect>')

    # SECTION 4: Whole-Game Scope Map (Unique Code Bytes across EE + Overlays + IOP + VU1)
    y2 = y1 + sec2_h + 20
    sec3_h = 330
    svg.append(f'<rect x="32" y="{y2}" width="{W-64}" height="{sec3_h}" rx="8" fill="{CARD}" stroke="{BORDER}"/>')
    svg.append(f'<text x="48" y="{y2+28}" class="h2">4. Whole-Game Inventoried Code Scope (Unique Code Bytes, Deduplicated)</text>')
    svg.append(f'<text x="48" y="{y2+46}" class="small muted">Proportional view of all known executable code across EE, deduplicated battle-effect overlays, IOP IRX modules, and VU1 microcode.</text>')

    scopes = [
        ("Main ELF (.text)", stats["c_bytes"], stats["open_bytes"], stats["policy_bytes"], "EE Resident Executable"),
        ("EE Overlays (distinct)", ovl["distinct_matched_bytes"], ovl["distinct_function_bytes"] - ovl["distinct_matched_bytes"] - ovl["distinct_policy_assembly_bytes"], ovl["distinct_policy_assembly_bytes"], "4,220 unique functions across 584 containers"),
        ("IOP Game (IOPSOUND.IRX)", iop_mbytes, max(iop_cbytes - iop_mbytes, 0), iop_stub_bytes, f"IopSoundDriver v2.20 ({iop_decomp:.1f}% C89, {iop_mfuncs}/{iop_tfuncs} funcs)"),
        ("IOP Sony SDK (24 IRX)", 0, 0, isum["all_sdk_iop_text_bytes"], "9 standalone + 15 in IOPRP234.IMG (.text)"),
        ("VU1 Microcode (.vutext)", vu_done, vu["total_code_bytes"] - vu_done, 0, f"2 microprograms, 1,788 insns ({vu_pct:.0f}% built from .vsm)"),
    ]
    max_scope = max(c + o + p for _, c, o, p, _ in scopes)
    sx = 250
    sw = 760
    sy = y2 + 74
    for name, cb, ob, pb, desc in scopes:
        tot = cb + ob + pb
        svg.append(f'<text x="{sx - 12}" y="{sy + 16}" text-anchor="end" class="small" style="font-weight:600">{html.escape(name)}</text>')
        w_tot = max(6.0, sw * tot / max_scope)
        w_c = w_tot * cb / tot if tot else 0
        w_o = w_tot * ob / tot if tot else 0
        w_p = w_tot * pb / tot if tot else 0
        svg.append(f'<rect x="{sx}" y="{sy}" width="{w_tot:.2f}" height="24" rx="3" fill="#0b0f14"/>')
        if w_c > 0:
            svg.append(f'<rect x="{sx}" y="{sy}" width="{w_c:.2f}" height="24" fill="{C_MATCH}"/>')
        if w_o > 0:
            col_o = C_PURPLE if ("IOP" in name or "VU1" in name) else C_OPEN
            svg.append(f'<rect x="{sx+w_c:.2f}" y="{sy}" width="{w_o:.2f}" height="24" fill="{col_o}"/>')
        if w_p > 0:
            svg.append(f'<rect x="{sx+w_c+w_o:.2f}" y="{sy}" width="{w_p:.2f}" height="24" fill="{C_POLICY}"/>')
        svg.append(f'<text x="{sx + w_tot + 12}" y="{sy + 16}" class="small mono muted">{tot/1024:,.1f} KB — {html.escape(desc)}</text>')
        sy += 48

    svg.append("</svg>\n")
    out_path = ROOT / "docs/codemap.svg"
    out_path.write_text("\n".join(svg))
    print(f"Wrote {out_path} ({out_path.stat().st_size:,} B)")


if __name__ == "__main__":
    build_svg()
