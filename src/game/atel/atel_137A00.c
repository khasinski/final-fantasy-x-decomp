/* tu_066 0x137a00-0x138220: low; unk_137A00 (config/tu_map.tsv) */
#include "common.h"
#include "ffx/q1.h"
#include "ffx/r0.h"
#include "ffx/u0.h"
#include "ffx/v0.h"

int func_00137A00(void) {
    return func_002D6020();
}

int func_00137A20(void) {
    SndSepClearAll();
    return 1;
}

int func_00137A40(Actor *a, void *op, ScriptCtx *ctx) {
    func_002D41F0(AtelPopStackInteger(a, ctx));
    return 0;
}

int func_00137A68(Actor *a, void *op, ScriptCtx *ctx) {
    return TkGetSyncH(AtelPopStackInteger(a, ctx));
}

int func_00137A90(Actor *a, void *op, ScriptCtx *ctx) {
    func_002D41E8(AtelPopStackInteger(a, ctx));
    return 0;
}

float func_00137AB8(Actor *a, void *op, ScriptCtx *ctx) {
    int off = AtelPopStackInteger(a, ctx);

    return *(float *)(REC124828_BASE() + off);
}

int func_00137AF0(Actor *a, void *op, ScriptCtx *ctx) {
    int off = AtelPopStackInteger(a, ctx);

    return *(int *)(REC124828_BASE() + off);
}

int func_00137B28(Actor *a, void *op, ScriptCtx *ctx) {
    int off = AtelPopStackInteger(a, ctx);

    return *(s16 *)(REC124828_BASE() + off);
}

int func_00137B60(Actor *a, void *op, ScriptCtx *ctx) {
    int off = AtelPopStackInteger(a, ctx);

    return *(s8 *)(REC124828_BASE() + off);
}

float func_00137B98(Actor *a, void *op, ScriptCtx *ctx) {
    float f = AtelPopStackFloat(a, ctx);
    int off = AtelPopStackInteger(a, ctx);

    *(float *)(REC124828_BASE() + off) = f;
    return f;
}

int func_00137BF8(Actor *a, void *op, ScriptCtx *ctx) {
    int v = (int)AtelPopStackFloat(a, ctx);
    int off = AtelPopStackInteger(a, ctx);

    *(int *)(REC124828_BASE() + off) = v;
    return v;
}

int func_00137C60(Actor *a, void *op, ScriptCtx *ctx) {
    int v = (int)AtelPopStackFloat(a, ctx);
    int off = AtelPopStackInteger(a, ctx);

    *(s16 *)(REC124828_BASE() + off) = v;
    return v;
}

int func_00137CC8(Actor *a, void *op, ScriptCtx *ctx) {
    int v = (int)AtelPopStackFloat(a, ctx);
    int off = AtelPopStackInteger(a, ctx);

    *(s8 *)(REC124828_BASE() + off) = v;
    return v;
}

int func_00137D30(void) {
    return 1;
}

int func_00137D38(void) {
    if (func_0015A550() != 0) {
        func_00158D60();
    }
    return 1;
}

int func_00137D68(Actor *a, void *op, ScriptCtx *ctx) {
    int on = AtelPopStackInteger(a, ctx) != 0;

    func_001244A8(on);
    return on;
}

int func_00137DA0(void) {
    return TkGetTGS();
}

int func_00137DC0(Actor *a, void *op, ScriptCtx *ctx) {
    char buf[0x200]; /* DEBT(PADDING): unused local buffer, only reserves the frame */

    AtelPopStackInteger(a, ctx);
    AtelPopStackInteger(a, ctx);
    AtelPopStackInteger(a, ctx);
    AtelPopStackInteger(a, ctx);
    return 0;
}

int func_00137E20(Actor *a, void *op, ScriptCtx *ctx) {
    return TkMalloc(AtelPopStackInteger(a, ctx));
}

int func_00137E48(Actor *a, void *op, ScriptCtx *ctx) {
    TkFree(AtelPopStackInteger(a, ctx));
    return 1;
}

int func_00137E70(Actor *a, void *op, ScriptCtx *ctx) {
    char *src = (char *)AtelPopStackInteger(a, ctx);

    func_002EF240(D_0056A5E0);
    __builtin_memcpy(&D_003194D0, src + 0x40, 0x64B8); /* DEBT(CAST): script-supplied buffer */
    func_002560C0();
    return 1;
}

int func_00137F88(Actor *a, void *op, ScriptCtx *ctx) {
    int x = AtelPopStackInteger(a, ctx);
    int y = AtelPopStackInteger(a, ctx);
    int z = AtelPopStackInteger(a, ctx);

    func_002EF240(D_0056A5F8, z, y, x);
    func_00125268(z, y, x);
    return 1;
}

int func_00138020(Actor *a, void *op, ScriptCtx *ctx) {
    int v = AtelPopStackInteger(a, ctx);

    return AtelGetRealVarAdrs(a, v);
}

int func_00138058(Actor *a, void *op, ScriptCtx *ctx) {
    int x = AtelPopStackInteger(a, ctx);
    int y = AtelPopStackInteger(a, ctx);
    int r;

    if (x != 0) {
        x = 1;
    }
    r = MsGetSaveCommandMenuPanel(y);
    func_001BF888(y, x);
    return r;
}

int func_001380D0(Actor *a, void *op, ScriptCtx *ctx) {
    int x = AtelPopStackInteger(a, ctx);
    int y = AtelPopStackInteger(a, ctx);

    func_002D6E48(0xFF, y, 0, x);
    return 1;
}

int func_00138138(Actor *a, void *op, ScriptCtx *ctx) {
    char buf[32];
    int v = AtelPopStackInteger(a, ctx);

    func_002F0008(buf, D_0056A628, a->id, v);
    func_0014D7B8(buf);
    return v;
}

int func_00138190(Actor *a, void *op, ScriptCtx *ctx) {
    char buf[32];
    int v = AtelPopStackInteger(a, ctx);

    func_002F0008(buf, D_0056A638, a->id, v);
    func_0014D7B8(buf);
    return v;
}

int func_001381E8(Actor *a, void *op, ScriptCtx *ctx) {
    int v = AtelPopStackInteger(a, ctx);

    func_002D97C8(v);
    return v;
}
