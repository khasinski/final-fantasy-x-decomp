/* tu_086 0x14f3e0-0x14f708: medium; unk_14F3E0 (config/tu_map.tsv) */
#include "common.h"
#include "ffx/q2.h"
#include "ffx/r1.h"
#include "ffx/u1.h"
#include "ffx/w2.h"
#include "ffx/s1.h"

void func_0014F3E0(void) {
}

int func_0014F3E8(void)
{
    return 0;
}

int func_0014F3F0(Actor *a, void *op, ScriptCtx *ctx)
{
    int v1;
    int v2;
    int v3;

    v1 = AtelPopStackInteger(a, ctx);
    v2 = AtelPopStackInteger(a, ctx);
    v3 = AtelPopStackInteger(a, ctx);
    Sg_Flash(AtelPopStackInteger(a, ctx), v3, v2, v1);
    return 0;
}

int func_0014F488(Actor *a, void *op, ScriptCtx *ctx)
{
    func_00117DB0(AtelPopStackInteger(a, ctx), 1, 0);
    return 0;
}

int func_0014F4B8(Actor *a, void *op, ScriptCtx *ctx)
{
    func_00117DB0(AtelPopStackInteger(a, ctx), 0, 0);
    return 0;
}

int func_0014F4E8(Actor *a, void *op, ScriptCtx *ctx)
{
    func_00117DB0(AtelPopStackInteger(a, ctx), 1, 1);
    return 0;
}

int func_0014F518(Actor *a, void *op, ScriptCtx *ctx)
{
    func_00117DB0(AtelPopStackInteger(a, ctx), 0, 1);
    return 0;
}

int func_0014F548(Actor *a, void *op, ScriptCtx *ctx)
{
    Sg_Blur(AtelPopStackInteger(a, ctx));
    return 0;
}

int func_0014F570(void)
{
    Sg_FadeReset();
    return 0;
}

int func_0014F590(Actor *a, void *op, ScriptCtx *ctx)
{
    int v1;
    int v2;
    int v3;

    v1 = AtelPopStackInteger(a, ctx);
    v2 = AtelPopStackInteger(a, ctx);
    v3 = AtelPopStackInteger(a, ctx);
    Sg_FilterAdd(AtelPopStackInteger(a, ctx), v3, v2, v1);
    return 0;
}

/* Script/event opcode stubs: thin handlers that forward to a helper and return 0 or its result. */

int func_0014F628(Actor *a, void *op, ScriptCtx *ctx)
{
    int v1;
    int v2;
    int v3;

    v1 = AtelPopStackInteger(a, ctx);
    v2 = AtelPopStackInteger(a, ctx);
    v3 = AtelPopStackInteger(a, ctx);
    Sg_FilterSub(AtelPopStackInteger(a, ctx), v3, v2, v1);
    return 0;
}

int func_0014F6C0(void) {
    Sg_FilterReset();
    return 0;
}

void func_0014F6E0(void) {
}

int func_0014F6E8(void)
{
    return func_00117FF8() == 0;
}
