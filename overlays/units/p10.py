# Package p10: overlay init + ppp shell (file09044 0x01B00438..0x01B00FB0, file09335 +0x3E0).
# Layouts from: python3 -P tools/overlay_map.py --layout 992 / 677 / 1268 / 1239.

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

UNIT_START = 0x01B00438
UNIT_END = 0x01B00FB0
TEXT_SIZE = UNIT_END - UNIT_START


def _syms(row, drow):
    s = {
        "D_01B00000": 0x01B00000,
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
    return s


UNITS = [{
    "src": "overlays/group11/ovl_09044_init_shell.c",
    "containers": [row[0] for row in LAYOUTS],
    "text_start": UNIT_START,
    "text_end": UNIT_END,
    "discovered_code_bytes": 2896,
    "functions": 19,
    "syms": _syms(LAYOUTS[0], DATA[0]),
    "container_layouts": [
        {"cid": row[0], "text_start": row[1], "text_end": row[1] + TEXT_SIZE,
         "syms": _syms(row, drow)}
        for row, drow in zip(LAYOUTS, DATA)
    ],
}]