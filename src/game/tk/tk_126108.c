/* tu_044 0x126108-0x126768: medium; unk_126108 (config/tu_map.tsv) */
#include "common.h"
#include "ffx/q0.h"
#include "ffx/r0.h"
#include "ffx/u0.h"
#include "ffx/v0.h"

s32 *func_00126108(void)
{
    return &D_0056A3C8;
}

s32 func_00126118(Actor *a, s32 unused, ScriptCtx *ctx)
{
    return AtelPopStackInteger(a, ctx);
}

s32 func_00126138(Actor *a, s32 unused, ScriptCtx *ctx)
{
    return AtelPopStackInteger(a, ctx) << 15;
}

s32 func_00126158(Actor *a, s32 unused, ScriptCtx *ctx)
{
    return (s32)(AtelPopStackFloat(a, ctx) * 32768.0f);
}

s32 func_00126188(Actor *a, s32 unused, ScriptCtx *ctx)
{
    return func_002D4888(AtelPopStackFloat(a, ctx));
}

s32 func_001261B0(Actor *a, s32 unused, ScriptCtx *ctx)
{
    return func_002D48F8(AtelPopStackFloat(a, ctx));
}

s32 func_001261D8(Actor *a, s32 unused, ScriptCtx *ctx)
{
    return func_002D4968(AtelPopStackInteger(a, ctx));
}

s32 func_00126200(Actor *a, s32 unused, ScriptCtx *ctx)
{
    return func_002D49A8(AtelPopStackInteger(a, ctx));
}

typedef struct {
    u8 a;
    u8 b;
    u16 c;
    s32 d;
} Entry126228;

typedef struct {
    u8 pad[0xA4];
    Entry126228 e[32];
} CtrlWork126228;

s32 func_00126228(Actor *a, s32 unused, ScriptCtx *ctx)
{
    s32 s4 = AtelPopStackInteger(a, ctx);
    s32 s2 = AtelPopStackInteger(a, ctx);
    s32 s1 = AtelPopStackInteger(a, ctx);
    s32 s0 = AtelPopStackInteger(a, ctx);
    Entry126228 *p;

    s0 = (s0 >= 0) ? ((s0 < 0x20) ? s0 : 0x1F) : 0;
    p = &((CtrlWork126228 *)AtelGetCurCtrlWork())->e[s0];
    if (s1 < 0 || s2 < 0) {
        p->a = 0;
        p->b = 0;
    } else {
        s1 /= 8;
        s2 /= 4;
        p->a = (s1 & 0x3F) | 0x80;
        p->b = s2 & 0x7F;
        p->d = s4;
        p->c = *(u16 *)((u8 *)a + 0x2E);
    }
    return 1;
}

float func_00126330(Actor *a, void *op, ScriptCtx *ctx) {
    return func_002D4218(AtelPopStackFloat(a, ctx));
}

float func_00126358(Actor *a, void *op, ScriptCtx *ctx) {
    return func_002D4238(AtelPopStackFloat(a, ctx));
}

float func_00126380(Actor *a, void *op, ScriptCtx *ctx) {
    return func_002D4258(AtelPopStackFloat(a, ctx));
}

s32 func_001263A8(Actor *a, s32 unused, ScriptCtx *ctx)
{
    return func_002E8370(AtelPopStackFloat(a, ctx));
}

float func_001263D0(Actor *a, void *op, ScriptCtx *ctx) {
    float x = AtelPopStackFloat(a, ctx);

    return ((float (*)(float, float))func_002E94A0)(AtelPopStackFloat(a, ctx), x); /* DEBT(CAST): atan2-like (y, x) */
}

float func_00126428(Actor *a, void *op, ScriptCtx *ctx)
{
    float v = AtelPopStackFloat(a, ctx);

    return sqrtf(v);
}

float func_00126470(Actor *a, void *op, ScriptCtx *ctx) {
    float v = AtelPopStackFloat(a, ctx);

    return 1.0f / sqrtf(v);
}

s32 func_001264C8(Actor *a, s32 unused, ScriptCtx *ctx)
{
    return func_002D44E0(AtelPopStackInteger(a, ctx));
}

s32 func_001264F0(Actor *a, s32 unused, ScriptCtx *ctx)
{
    return func_002D4500(AtelPopStackInteger(a, ctx));
}

float func_00126518(Actor *a, void *op, ScriptCtx *ctx)
{
    float w = AtelPopStackFloat(a, ctx);
    float z = AtelPopStackFloat(a, ctx);
    float y = AtelPopStackFloat(a, ctx);

    return func_002D4520(AtelPopStackFloat(a, ctx), y, z, w);
}

float func_001265A8(Actor *a, void *op, ScriptCtx *ctx)
{
    float f25 = AtelPopStackFloat(a, ctx);
    float f24 = AtelPopStackFloat(a, ctx);
    float f23 = AtelPopStackFloat(a, ctx);
    float f22 = AtelPopStackFloat(a, ctx);
    float f21 = AtelPopStackFloat(a, ctx);
    float f20 = AtelPopStackFloat(a, ctx);
    s32 s2 = AtelPopStackInteger(a, ctx);
    float *s0 = (float *)AtelGetRealVarAdrs(a, AtelPopStackInteger(a, ctx));

    func_002D45C0(s0, (float *)AtelGetRealVarAdrs(a, s2), f20, f21, f22, f23, f24, f25);
    return *s0;
}

float func_001266C8(Actor *a, s32 unused, ScriptCtx *ctx)
{
    return func_002D4338(AtelPopStackFloat(a, ctx));
}

float func_001266F0(Actor *a, void *op, ScriptCtx *ctx) {
    float x = AtelPopStackFloat(a, ctx);
    float y = AtelPopStackFloat(a, ctx);

    return func_002D46B0(AtelPopStackFloat(a, ctx), y, x);
}
