/* tu_088 0x150200-0x150550: medium; unk_150200 (config/tu_map.tsv) */
#include "common.h"
#include "ffx/q2.h"
#include "ffx/w2.h"
#include "ffx/r1.h"
#include "ffx/s1.h"
#include "ffx/u1.h"

int func_00150200(Actor *a, void *op, ScriptCtx *ctx)
{
    int v1;

    v1 = AtelPopStackInteger(a, ctx);
    func_0010DAE8(AtelPopStackInteger(a, ctx), v1);
    return 0;
}

int func_00150260(Actor *a, void *op, ScriptCtx *ctx)
{
    return Sg_PLightGetLight(AtelPopStackInteger(a, ctx));
}

int func_00150288(Actor *a, void *op, ScriptCtx *ctx)
{
    func_00115F70(AtelPopStackInteger(a, ctx));
    return 0;
}

int func_001502B0(void) {
    return func_00115F98();
}

int func_001502D0(Actor *a, void *op, ScriptCtx *ctx)
{
    float r1;
    int r2;

    r1 = AtelPopStackFloat(a, ctx);
    r2 = AtelPopStackInteger(a, ctx);
    Sg_PLightSetAttenuation(r2, r1);
    return 0;
}

float func_00150330(Actor *a, void *op, ScriptCtx *ctx)
{
    return Sg_PLightGetAttenuation(AtelPopStackInteger(a, ctx));
}

float func_00150358(Actor *a, void *op, ScriptCtx *ctx)
{
    Sg_SetMapAlphaFast(AtelPopStackInteger(a, ctx));
    return 0;
}

float func_00150380(void)
{
    return func_0011AAA8();
}

int func_001503A8(Actor *a, void *op, ScriptCtx *ctx)
{
    float r1;
    float r2;
    float r3;

    r1 = AtelPopStackFloat(a, ctx);
    r2 = AtelPopStackFloat(a, ctx);
    r3 = AtelPopStackFloat(a, ctx);
    func_001148F0(r3, r2, r1);
    return 0;
}

int func_00150420(Actor *a, void *op, ScriptCtx *ctx)
{
    int v1;
    int v2;

    v1 = AtelPopStackInteger(a, ctx);
    v2 = AtelPopStackInteger(a, ctx);
    func_00114910(AtelPopStackInteger(a, ctx), v2, v1);
    return 0;
}

int func_00150498(void) {
    Sg_MemDump();
    return 0;
}

float func_001504B8(Actor *a, void *op, ScriptCtx *ctx)
{
    int v1;
    int v2;
    int v3;

    v1 = AtelPopStackInteger(a, ctx);
    v2 = AtelPopStackInteger(a, ctx);
    v3 = AtelPopStackInteger(a, ctx);
    Sg_AccSetClear(AtelPopStackInteger(a, ctx), v3, v2, v1);
    return 0.0f;
}
