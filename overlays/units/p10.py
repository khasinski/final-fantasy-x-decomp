# Package p10: overlay init + ppp shell (file09044, file09335 at +0x3E0).
# Only the byte-exact functions are registered, as 5 contiguous runs; the other
# 10 functions of the block are parked in overlays/wip/ovl_09044_init_wip.c
# (gcc-2.9 scheduling/regalloc diffs - see LOCAL_NOTES.md).

RESIDENT_SYMS = {
    "D_0054D5EC": 0x0054D5EC,
    "D_00703E24": 0x00703E24,
    "func_206C440": 0x0206C440,
}

# (cid, text_start, D_01B09BB0, D_01B09DB0, D_01B09EB0, D_01B0BEB0)
LAYOUTS = [
    (9044, 0x01B00438, 0x01B09BB0, 0x01B09DB0, 0x01B09EB0, 0x01B0BEB0),
    (9335, 0x01B00818, 0x01B085D0, 0x01B087D0, 0x01B088D0, 0x01B0A8D0),
]

# per-container data syms: (cid, D_01B09B68, D_01B09B98, D_01B09CB8, D_01B00210, D_01B00260,
#                           D_01B0C520, D_01B0CBC0)
DATA = [
    (9044, 0x01B09B68, 0x01B09B98, 0x01B09CB0, 0x01B00210, 0x01B00260, 0x01B0C520, 0x01B0CBC0),
    (9335, 0x01B07988, 0x01B079B8, 0x01B086D0, 0x01B005F8, 0x01B00650, 0x01B0AE90, 0x01BB0930),
]

# (src suffix, 9044 start, 9044 end, functions, discovered code bytes)
RUNS = [
    ("a", 0x01B00438, 0x01B005A8, 3, 364),   # 438 550 5A0
    ("b", 0x01B00658, 0x01B00760, 2, 260),   # 658 758
    ("c", 0x01B009F8, 0x01B00A74, 2, 120),   # 9F8 A38 (excludes A38's 4B tail pad)
    ("d", 0x01B00BB0, 0x01B00C54, 1, 164),   # BB0 (excludes 4B tail pad)
    ("e", 0x01B00DD8, 0x01B00E60, 2, 136),   # DD8 DE0
]
DELTA_9335 = 0x3E0


def _syms(row, drow):
    return {
        "D_01B00000": 0x01B00000,
        "func_01B00A78": row[1] + 0x01B00A78 - 0x01B00438,
        "D_01B09BB0": row[2],
        "D_01B09DB0": row[3],
        "D_01B09EB0": row[4],
        "D_01B0BEB0": row[5],
        "D_01B09B68": drow[1],
        "D_01B09B98": drow[2],
        "D_01B09CB8": drow[3],
        "D_01B00210": drow[4],
        "D_01B00260": drow[5],
        "D_01B0C520": drow[6],
        "D_01B0CBC0": drow[7],
    }


UNITS = []
for suffix, start, end, nfuncs, code_bytes in RUNS:
    UNITS.append({
        "src": "overlays/group11/ovl_09044_init_%s.c" % suffix,
        "containers": [row[0] for row in LAYOUTS],
        "text_start": start,
        "text_end": end,
        "discovered_code_bytes": code_bytes,
        "functions": nfuncs,
        "syms": _syms(LAYOUTS[0], DATA[0]),
        "container_layouts": [
            {"cid": row[0], "text_start": start + (row[1] - LAYOUTS[0][1]),
             "text_end": end + (row[1] - LAYOUTS[0][1]),
             "syms": _syms(row, drow)}
            for row, drow in zip(LAYOUTS, DATA)
        ],
    })
