/* tu_089 0x150550-0x1508a0: low; unk_150550 (config/tu_map.tsv) */
#include "common.h"
#include "ffx/q2.h"
#include "ffx/w2.h"
#include "ffx/r1.h"
#include "ffx/s1.h"
#include "ffx/u1.h"

int func_00150550(Actor *a, void *op, ScriptCtx *ctx)
{
    func_00118A70(AtelPopStackInteger(a, ctx));
    return 0;
}

int func_00150578(Actor *a, void *op, ScriptCtx *ctx)
{
    int v1;

    v1 = AtelPopStackInteger(a, ctx);
    func_00121C28(AtelPopStackInteger(a, ctx), v1);
    return 0;
}

int func_001505D8(Actor *a, void *op, ScriptCtx *ctx)
{
    func_001078B0(AtelPopStackFloat(a, ctx));
    return 0;
}

int func_00150600(Actor *a, void *op, ScriptCtx *ctx)
{
    ((void (*)(double))func_00107888)(func_002ED038(AtelPopStackFloat(a, ctx))); /* DEBT(CAST): called unprototyped in the original (float promoted to double) */
    return 0;
}

int func_00150630(Actor *a, void *op, ScriptCtx *ctx)
{
    func_0011BD80(AtelPopStackInteger(a, ctx));
    return 0;
}

int func_00150658(Actor *a, void *op, ScriptCtx *ctx)
{
    float v1;

    v1 = AtelPopStackFloat(a, ctx);
    Sg_PlayerSetDirFix(AtelPopStackInteger(a, ctx), v1);
    return 0;
}

int func_001506B8(void) {
    func_00116388();
    return 0;
}

int func_001506D8(Actor *a, void *op, ScriptCtx *ctx)
{
    func_001163C8(AtelPopStackFloat(a, ctx));
    return 0;
}

int func_00150700(void) {
    return 0;
}

int func_00150708(void) {
    return 0;
}

int func_00150710(Actor *a, void *op, ScriptCtx *ctx)
{
    int v1;

    v1 = AtelPopStackInteger(a, ctx);
    func_0010C198(AtelPopStackInteger(a, ctx), v1);
    return 0;
}

int func_00150770(Actor *a, void *op, ScriptCtx *ctx)
{
    AtelPopStackInteger(a, ctx);
    AtelPopStackInteger(a, ctx);
    AtelPopStackInteger(a, ctx);
    return 0;
}

int func_001507C0(Actor *a, void *op, ScriptCtx *ctx)
{
    func_001163B8(AtelPopStackInteger(a, ctx));
    return 0;
}

int func_001507E8(Actor *a, void *op, ScriptCtx *ctx)
{
    Sg_SetMovieGomiAvoid(AtelPopStackInteger(a, ctx));
    return 0;
}

int func_00150810(Actor *a, void *op, ScriptCtx *ctx)
{
    func_001521D8(a, ctx, 0);
    return 0;
}

int func_00150838(Actor *a, void *op, ScriptCtx *ctx)
{
    func_001521D8(a, ctx, 0);
    return 0;
}

void func_00150860(void)
{
    AtelGetCharHandle();
}

int func_00150868(void)
{
    Chr *c = AtelGetCharHandle();

    if (c == 0) {
        return 0;
    }
    return c->b742 != 0 ? 0 : 5;
}
