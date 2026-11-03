"""Package p3: F1 shared effect-draw library (opus / rcefChrDraw users), see overlays/p3_overlay.h.

Every F1 TU sits at the same per-container displacement from its file09044 address
(F1_DELTA), except file09335, which lacks TUs 6/10 and is listed in F1_9335."""

# (cid, displacement of the F1 library from its file09044 position)
F1_DELTA = [
    (9044, +0x0), (9065, +0x420), (9066, +0x350), (9067, +0x350), (9068, +0x290), (9069, +0x380),
    (9070, +0x2e0), (9071, +0x2e0), (9072, +0x300), (9073, +0x300), (9074, +0x330), (9075, +0x350),
    (9078, +0x350), (9079, +0x350), (9080, +0x260), (9081, +0x2b0), (9082, +0x2e0), (9083, +0x2e0),
    (9113, +0x6f0), (9117, +0x3d0), (9162, +0x3d0), (9163, +0x3a0), (9166, +0x670), (9167, +0x210),
    (9168, +0x348), (9169, +0x348), (9174, +0x260), (9175, +0x260), (9180, +0x350), (9181, +0x350),
    (9182, +0x2e0), (9183, +0x2e0), (9184, +0x330), (9185, +0x330), (9186, +0x2b0), (9187, +0x2b0),
    (9192, +0x4f0), (9195, +0x440), (9198, +0x610), (9201, +0x3d0), (9202, +0x3d0), (9204, +0x2b0),
    (9205, +0x2b0), (9211, +0x2b0), (9213, +0x4e0), (9214, +0x700), (9219, +0x260), (9234, +0x2e0),
    (9252, +0x8a0), (9279, +0x170), (9280, +0x170), (9281, +0x300), (9282, +0x300), (9300, +0x2b0),
    (9303, +0x2e0), (9305, +0x2e0), (9308, +0x3d0), (9309, +0x3a0), (9321, +0x3a0), (9322, +0x380),
    (9323, +0x2b0), (9324, +0x380), (9325, +0x600), (9326, +0x440), (9327, +0x570), (9333, +0x420),
    (9334, +0x3f0), (9335, -0x170), (9338, +0x3a0), (9340, +0x3a0), (9346, +0x2b0), (9350, +0x440),
    (9353, +0x240), (9359, +0x3d0), (9363, +0x420), (9364, +0x3d0), (9365, +0x490), (9367, +0x240),
    (9368, +0x2b0), (9370, +0x420), (9371, +0x420), (9372, +0x3d0), (9373, +0x490), (9384, +0x3d0),
    (9388, +0x530), (9389, +0x3d0), (9390, +0x350), (9399, +0x3a0), (9402, +0x3a0), (9430, +0x580),
    (9462, +0x260), (9466, +0x570), (9480, +0x2b0), (9481, +0x490), (9482, +0x490), (9529, +0x2e0),
    (9560, +0x2b0), (9597, +0x3d0), (9613, +0x4f0), (9625, +0x4e0), (9626, +0x510), (9636, +0x2e0),
    (9637, +0x440), (9639, +0x4c0), (9648, +0x440), (9651, +0x700), (9652, +0x618), (9659, +0x440),
    (9666, +0x4e0), (9667, +0x4e0), (9668, +0x4e0), (9669, +0x4e0), (9670, +0x4e0), (9671, +0x4e0),
    (9672, +0x4e0), (9673, +0x4e0), (9674, +0x4e0), (9675, +0x4e0), (9676, +0x4e0), (9677, +0x4e0),
    (9678, +0x4e0), (9679, +0x4e0), (9680, +0x4e0), (9681, +0x4e0), (9684, +0xb70), (9714, +0x120),
    (9743, +0x420), (9750, +0x3e0), (9753, -0x1b0), (9754, +0x3e0), (9756, +0x120),
]

# file09335: text_start of each F1 function block, keyed by its file09044 address
F1_9335 = {
    0x01B06808: 0x01B06698,  # TU rank 4
    0x01B026F8: 0x01B02660,  # TU rank 11
    0x01B05810: 0x01B05708,  # TU rank 25
    0x01B04478: 0x01B043B0,  # TU rank 30
    0x01B03A70: 0x01B03A08,  # TU rank 47
}
_9335_BLOCKS = sorted(F1_9335.items())


def _addr(cid, a):
    """Address in container cid of the F1 code/symbol at file09044 address a."""
    if cid == 9335:
        delta = None
        for ref, at in _9335_BLOCKS:
            if ref <= a:
                delta = at - ref
        return a + delta
    return a + dict(F1_DELTA)[cid]


def _unit(src, start, end, funcs, code_bytes, syms=(), skip=(), cflags=None):
    """Unit for file09044 .text [start, end); syms are overlay names spelled by their 09044 address."""
    cids = [c for c, _ in F1_DELTA if c not in skip]
    def lay(cid):
        ts = _addr(cid, start)
        return {"cid": cid, "text_start": ts, "text_end": ts + (end - start),
                "syms": {n: _addr(cid, int(n.split("_")[1], 16)) for n in syms}}
    u = {
        "src": src,
        "containers": cids,
        "text_start": start,
        "text_end": end,
        "discovered_code_bytes": code_bytes,
        "functions": funcs,
        "syms": lay(9044)["syms"],
        "container_layouts": [lay(c) for c in cids],
    }
    if cflags:
        u["cflags"] = list(cflags)
    return u

UNITS = [
    _unit("overlays/group11/ovl_09044_edge26f8.c", 0x01B026F8, 0x01B02974, 1, 636),
    _unit("overlays/group11/ovl_09044_ops3950.c", 0x01B03950, 0x01B03A6C, 1, 284, ["func_01B03A70"], skip=(9335,)),
    _unit("overlays/group11/ovl_09044_ops5810.c", 0x01B05810, 0x01B0586C, 1, 92, ["func_01B05870"]),
    _unit("overlays/group11/ovl_09044_pool6fd0.c", 0x01B06FD0, 0x01B07110, 2, 316),
    _unit("overlays/group11/ovl_09044_pool7490.c", 0x01B07490, 0x01B07518, 1, 136),
]
