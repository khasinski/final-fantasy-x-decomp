/* tu_045 0x126768-0x126d68: medium; unk_126768 (config/tu_map.tsv) */
#include "common.h"
#include "ffx/q0.h"
#include "ffx/r0.h"
#include "ffx/u0.h"
#include "ffx/v0.h"
#include "ffx/s0.h"

int func_00126768(Actor *a, void *op, ScriptCtx *ctx)
{
    float f6 = AtelPopStackFloat(a, ctx);
    float f5 = AtelPopStackFloat(a, ctx);
    float f4 = AtelPopStackFloat(a, ctx);
    float f3 = AtelPopStackFloat(a, ctx);
    float f2 = AtelPopStackFloat(a, ctx);
    float f1 = AtelPopStackFloat(a, ctx);

    return func_002D47E8(f1, f2, f3, f4, f5, f6);
}

int func_00126830(Actor *a, void *op, ScriptCtx *ctx)
{
    float a0 = AtelPopStackFloat(a, ctx);
    float b0 = AtelPopStackFloat(a, ctx);
    float c0 = AtelPopStackFloat(a, ctx);
    float a1 = AtelPopStackFloat(a, ctx);
    float b1 = AtelPopStackFloat(a, ctx);
    float c1 = AtelPopStackFloat(a, ctx);

    return func_002D4850(AtelPopStackFloat(a, ctx), c0 - c1, b0 - b1, a0 - a1);
}

float func_00126908(Actor *a, void *op, ScriptCtx *ctx)
{
    float f = AtelPopStackFloat(a, ctx);
    int c = AtelPopStackInteger(a, ctx);
    int x = AtelPopStackInteger(a, ctx);
    int y = AtelPopStackInteger(a, ctx);

    x = AtelGetRealVarAdrs(a, x);
    ((void (*)(int, int, int, float))TkMtCalcSpline)(AtelGetRealVarAdrs(a, y), x, c, f); /* DEBT(CAST): declared without the float argument */
    return 0.0f;
}

float func_001269C0(Actor *a, void *op, ScriptCtx *ctx)
{
    float z = AtelPopStackFloat(a, ctx);
    float y = AtelPopStackFloat(a, ctx);
    float x = AtelPopStackFloat(a, ctx);

    func_002D4D58(AtelGetRealVarAdrs(a, AtelPopStackInteger(a, ctx)), x, y, z);
    return 0.0f;
}

float func_00126A60(Actor *a, void *op, ScriptCtx *ctx) {
    return __builtin_fabsf(AtelPopStackFloat(a, ctx));
}

float func_00126A80(Actor *a, void *op, ScriptCtx *ctx)
{
    float x0 = AtelPopStackFloat(a, ctx);
    float z0 = AtelPopStackFloat(a, ctx);
    float x1 = AtelPopStackFloat(a, ctx);
    float z1 = AtelPopStackFloat(a, ctx);

    x1 -= x0;
    z1 -= z0;
    return sqrtf(z1 * z1 + x1 * x1);
}

float func_00126B38(Actor *a, void *op, ScriptCtx *ctx)
{
    float x0 = AtelPopStackFloat(a, ctx);
    float y0 = AtelPopStackFloat(a, ctx);
    float z0 = AtelPopStackFloat(a, ctx);
    float x1 = AtelPopStackFloat(a, ctx);
    float y1 = AtelPopStackFloat(a, ctx);
    float z1 = AtelPopStackFloat(a, ctx);

    x1 -= x0;
    y1 -= y0;
    z1 -= z0;
    return sqrtf(z1 * z1 + y1 * y1 + x1 * x1);
}

static inline int Clamp8(int i)
{
    int k;

    if (i >= 0) {
        if (i > 7) {
            k = 7;
        } else {
            k = i;
        }
    } else {
        k = 0;
    }
    return k;
}

Pair32 *func_00126C20(Actor *a, void *op, ScriptCtx *ctx)
{
    int v = AtelPopStackInteger(a, ctx);
    int i = AtelPopStackInteger(a, ctx);
    Pair32 *p;

    i = Clamp8(i);
    p = &AtelGetCurCtrlWork()->pairs1A4[i];

    if (v != 0) {
        v = AtelGetRealVarAdrs(a, v);
    }
    p->w0 = v;
    return p;
}

s32 func_00126CB8(Actor *a, void *op, ScriptCtx *ctx)
{
    func_00126C20(a, op, ctx)->w4 = 0;
    return 0;
}

s32 func_00126CE0(Actor *a, void *op, ScriptCtx *ctx)
{
    func_00126C20(a, op, ctx)->w4 = 1;
    return 0;
}

s32 *func_00126D08(void)
{
    return &D_0056A408;
}

s32 func_00126D18(void)
{
    return 0;
}

void func_00126D20(Actor *a, s32 *out, ScriptCtx *ctx)
{
    *out = AtelPopStackInteger(a, ctx);
}

s32 func_00126D50(s32 unused, s32 *p)
{
    return --*p < 1;
}
