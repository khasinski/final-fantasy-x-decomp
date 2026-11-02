/* tu_216 0x1ef4e8-0x1ef910: low; unk_1EF4E8 (config/tu_map.tsv) */
#include "common.h"
#include "ffx/q5.h"
#include "ffx/w5.h"
#include "ffx/r4.h"
#include "ffx/u3.h"
#include "ffx/v4.h"

int func_001EF4E8(Actor *a, int *p, ScriptCtx *ctx)
{
    int v = AtelPopStackInteger(a, ctx);

    return *p = func_001B8198(*func_00144158(a), v, 0, 1);
}

int func_001EF548(Actor *ctx, int *p)
{
    int r = 5;

    if (MsGetChr(*p)->fAD2 != 0) {
        r = 0;
    }
    return r;
}

int func_001EF580(Actor *a, void *op, ScriptCtx *ctx)
{
    int v = AtelPopStackInteger(a, ctx);

    return MsGetChr(func_001B8198(*func_00144158(a), v, 0, 1))->fAD2;
}

int func_001EF5E0(Actor *ctx)
{
    int r = 5;

    if (MsGetChr(*func_00144158(ctx))->fAD3 != 0) {
        r = 0;
    }
    return r;
}

int func_001EF618(Actor *a, int *p, ScriptCtx *ctx)
{
    int v = AtelPopStackInteger(a, ctx);

    return *p = func_001B8198(*func_00144158(a), v, 0, 1);
}

int func_001EF678(Actor *ctx, int *p)
{
    int r = 5;

    if (MsGetChr(*p)->fAD3 != 0) {
        r = 0;
    }
    return r;
}

int func_001EF6B0(Actor *a, void *op, ScriptCtx *ctx)
{
    int v = AtelPopStackInteger(a, ctx);

    return MsGetChr(func_001B8198(*func_00144158(a), v, 0, 1))->fAD3;
}

int func_001EF710(Actor *ctx)
{
    u8 id = *func_00144158(ctx);

    if (id != 0xFF) {
        MsStatusEffectCheck(id);
    }
    return 0;
}

int func_001EF748(Actor *ctx)
{
    u8 id = *func_00144158(ctx);

    if (id != 0xFF) {
        MsStatusEffectClear(id);
    }
    return 0;
}

int func_001EF780(Actor *a, void *op, ScriptCtx *ctx)
{
    int x = AtelPopStackInteger(a, ctx);
    int y = AtelPopStackInteger(a, ctx);

    func_001CFE80(func_001B8198(*func_00144158(a), y, 0, 1), x);
    return 0;
}

int func_001EF800(Actor *a, void *op, ScriptCtx *ctx)
{
    int x = AtelPopStackInteger(a, ctx);
    int y = AtelPopStackInteger(a, ctx);

    return func_001D1FA8(AtelPopStackInteger(a, ctx), y, x);
}

int func_001EF878(Actor *ctx)
{
    int r = 5;

    if (MsGetChr(*func_00144158(ctx))->fAD7 == 0) {
        r = 0;
    }
    return r;
}

int func_001EF8B0(Actor *a)
{
    return func_001CFEC0(*func_00144158(a));
}

int func_001EF8D8(void)
{
    func_002EF240(D_0056FE48);
    return 0;
}

void *func_001EF900(void)
{
    return &D_0056FE60;
}
