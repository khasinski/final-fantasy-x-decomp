/* tu_051 0x12b4f0-0x12bc40: low; unk_12B4F0 (config/tu_map.tsv) */
/* Field-script opcode handlers (module name unknown; no source-file string found). See ffx/w1.h. */
#include "common.h"
#include "ffx/q0.h"
#include "ffx/w1.h"
#include "ffx/r0.h"
#include "ffx/u0.h"
#include "ffx/v0.h"

u16 func_0012B4F0(Actor *a, s32 unused, ScriptCtx *ctx)
{
    return AtelGetMesWinWork(AtelPopStackInteger(a, ctx))->kind;
}

int func_0012B518(Actor *a, void *op, ScriptCtx *ctx)
{
    float f = AtelPopStackInteger(a, ctx);

    func_0013B458(a, AtelGetRealVarAdrs(a, AtelPopStackInteger(a, ctx)));
    func_0013B470(a, f);
    func_0013B488(a, 0.0f);
    return 1;
}

int func_0012B5A0(Actor *a, void *op, ScriptCtx *ctx)
{
    float v[4];
    float f = AtelPopStackInteger(a, ctx);

    func_0013D928((int)v, (int *)AtelGetRealVarAdrs(a, AtelPopStackInteger(a, ctx)), f); /* DEBT(CAST): q1.h declares (int, int *, float) */
    AtelSetPos3d(a, 0, v[0], v[1], v[2]);
    return 1;
}

int func_0012B628(Actor *a, void *op, ScriptCtx *ctx)
{
    float v[4];
    float f = AtelPopStackInteger(a, ctx);

    func_0013D9D0((int)v, (int *)AtelGetRealVarAdrs(a, AtelPopStackInteger(a, ctx)), f); /* DEBT(CAST): q1.h declares (int, int *, float) */
    AtelSetPos3d(a, 0, v[0], v[1], v[2]);
    return 1;
}

int func_0012B6B0(Actor *a, void *op, ScriptCtx *ctx) {
    int v = AtelPopStackInteger(a, ctx);
    ActorState *st = AtelGetPosWorkAdrs(a);
    int t = a->hdr->type;

    if (t < 7) {
        if (t >= 5) {
            st->h28 = v;
        }
    }
    return v;
}

int func_0012B710(Actor *a, void *op, ScriptCtx *ctx)
{
    int d = AtelPopStackInteger(a, ctx);
    int c = AtelPopStackInteger(a, ctx);
    int b = AtelPopStackInteger(a, ctx);
    int v = AtelPopStackInteger(a, ctx);

    func_00206860(v, b, c);
    func_00206888(v, b, d);
    return v;
}

int func_0012B7B8(Actor *a, void *op, ScriptCtx *ctx)
{
    int c = AtelPopStackInteger(a, ctx);
    int b = AtelPopStackInteger(a, ctx);
    int v = AtelPopStackInteger(a, ctx);

    func_00206860(v, b, c);
    return v;
}

int func_0012B838(Actor *a, void *op, ScriptCtx *ctx)
{
    int c = AtelPopStackInteger(a, ctx);
    int b = AtelPopStackInteger(a, ctx);
    int v = AtelPopStackInteger(a, ctx);

    func_00206888(v, b, c);
    return v;
}

s32 func_0012B8B8(Actor *a, void *op, ScriptCtx *ctx)
{
    s32 v = AtelPopStackInteger(a, ctx);

    AtelGetMesWinWork(AtelPopStackInteger(a, ctx))->w10 = v;
    return v;
}

INCLUDE_ASM("build/ee_asm/game/atel/atel_12B4F0", func_0012B918);

float func_0012B9E0(Actor *a, void *op, ScriptCtx *ctx)
{
    int id = AtelPopStackInteger(a, ctx);
    Actor *o = AtelGetBasicWork(AtelPopStackInteger(a, ctx));
    Actor *p = AtelGetBasicWork(id);
    ActorState *s = AtelGetPosWorkAdrs(o);
    ActorState *t = AtelGetPosWorkAdrs(p);
    float dx = s->x - t->x;
    float dy = s->y - t->y;
    float dz = s->z - t->z;

    return sqrtf(dx * dx + dy * dy + dz * dz);
}

float func_0012BAB8(Actor *a, void *op, ScriptCtx *ctx)
{
    int id = AtelPopStackInteger(a, ctx);
    Actor *o = AtelGetBasicWork(AtelPopStackInteger(a, ctx));
    Actor *p = AtelGetBasicWork(id);
    ActorState *s = AtelGetPosWorkAdrs(o);
    ActorState *t = AtelGetPosWorkAdrs(p);
    float dx = s->x - t->x;
    float dz = s->z - t->z;

    return sqrtf(dx * dx + dz * dz);
}

int func_0012BB78(Actor *a, void *op, ScriptCtx *ctx)
{
    int p = AtelPopStackInteger(a, ctx);
    int q = AtelPopStackInteger(a, ctx);
    int r = AtelPopStackInteger(a, ctx);
    int v = AtelPopStackInteger(a, ctx);

    r = AtelGetRealVarAdrs(a, r);
    q = AtelGetRealVarAdrs(a, q);
    func_001495A8(v, r, q, AtelGetRealVarAdrs(a, p));
    return 0;
}
