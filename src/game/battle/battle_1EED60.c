/* tu_215 0x1ea000-0x1ef4e8: low; unk_1EA000 (config/tu_map.tsv) */
#define func_001EA718 _hdr_func_001EA718
#define func_001EE8E0 _hdr_func_001EE8E0
#define func_001EE9E8 _hdr_func_001EE9E8
#define func_001EBF18 _hdr_func_001EBF18
#include "common.h"
#include "ffx/q4.h"
#include "ffx/r3.h"
#include "ffx/u2.h"
#include "ffx/v3.h"
#include "ffx/u3.h"
#include "ffx/v4.h"
#include "ffx/q5.h"
#include "ffx/w5.h"
#include "ffx/r4.h"
#include "ffx/s4.h"
#undef func_001EBF18
#undef func_001EA718
#undef func_001EE8E0
#undef func_001EE9E8

int func_001EED60(void)
{
    int i;
    u8 *p;

    for (i = 0; i < 4; i++) {
        p = func_001E4A30(i);
        if (*p) {
            return *p;
        }
    }
    return 0;
}

int func_001EEDA8(void)
{
    int i;
    u8 *p;

    for (i = 0; i < 4; i++) {
        p = func_001E4A30(i);
        if (p[0] != 0) {
            return p[1];
        }
    }
    return 0;
}

int func_001EEDF8(Actor *a, void *op, ScriptCtx *ctx)
{
    int v = AtelPopStackInteger(a, ctx);

    D_00319433 = v & 1;
}

s8 func_001EEE20(void)
{
    return D_00319435;
}

int func_001EEE30(Actor *a, void *op, ScriptCtx *ctx)
{
    int x = AtelPopStackInteger(a, ctx);
    int y = AtelPopStackInteger(a, ctx);
    int id = *func_00144158(a);

    if (func_001CF6F8(id, y, 7, x, 1) != 0) {
        MsGetChr(id)->fAD2++;
    }
    return 0;
}

int func_001EEEC8(Actor *a, void *op, ScriptCtx *ctx)
{
    int x = AtelPopStackInteger(a, ctx);
    int y = AtelPopStackInteger(a, ctx);

    return func_001CF6F8(*func_00144158(a), y, 1, x, 1);
}

int func_001EEF38(Actor *a, void *op, ScriptCtx *ctx)
{
    int n = AtelPopStackInteger(a, ctx);
    BtlChr *c;
    int v;

    AtelPopStackInteger(a, ctx);
    c = MsGetChr(*func_00144158(a));
    if (n > 0 && c->fAD5 != 0 && c->fB68 == 0) {
        v = op_et_weapon_afterimage(c->chr, 0, 0, 0, 0, 0, 0);
        if (v != 0) {
            c->fB68 = v;
        }
    }
    return 0;
}

int func_001EEFE0(Actor *ctx)
{
    MsResetAfterImage(MsGetChr(*func_00144158(ctx)));
    return 0;
}

int func_001EF010(Actor *a, void *op, ScriptCtx *ctx)
{
    int x = AtelPopStackInteger(a, ctx);
    int y = AtelPopStackInteger(a, ctx);

    return func_001CF458(*func_00144158(a), y, x, 1);
}

int func_001EF080(Actor *a, void *op, ScriptCtx *ctx)
{
    int v = AtelPopStackInteger(a, ctx);

    func_001CF0C0(*func_00144158(a), v);
    return 0;
}

int func_001EF0D0(Actor *a, void *unused, ScriptCtx *ctx)
{
    int x = AtelPopStackInteger(a, ctx);
    int y = AtelPopStackInteger(a, ctx);
    int i = AtelPopStackInteger(a, ctx);

    i = func_001B8198(*func_00144158(a), i, 0, 1);
    if (func_001CF6F8(i, y, 7, x, 1) != 0) {
        MsGetChr(i)->fAD2++;
    }
    return 0;
}

int func_001EF190(Actor *a, void *op, ScriptCtx *ctx)
{
    int x = AtelPopStackInteger(a, ctx);
    int y = AtelPopStackInteger(a, ctx);
    int z = AtelPopStackInteger(a, ctx);

    func_001CF4B0(func_001B8198(*func_00144158(a), z, 0, 1), y, x);
    return 0;
}

int func_001EF228(Actor *a, void *op, ScriptCtx *ctx)
{
    int x = AtelPopStackInteger(a, ctx);
    int y = AtelPopStackInteger(a, ctx);
    int z = AtelPopStackInteger(a, ctx);

    func_001CF558(func_001B8198(*func_00144158(a), z, 0, 1), y, x);
    return 0;
}

int func_001EF2C0(Actor *a, void *op, ScriptCtx *ctx)
{
    int x = AtelPopStackInteger(a, ctx);
    int y = AtelPopStackInteger(a, ctx);
    int z = AtelPopStackInteger(a, ctx);

    return func_001CF458(func_001B8198(*func_00144158(a), z, 0, 1), y, x, 1);
}

int func_001EF358(Actor *a, void *op, ScriptCtx *ctx)
{
    int id;

    AtelPopStackInteger(a, ctx);
    AtelPopStackInteger(a, ctx);
    id = *func_00144158(a);
    MsGetChr(id)->f36 = 1;
    return id;
}

int func_001EF3B8(Actor *a)
{
    MsResetBindEffect(*func_00144158(a));
    return 0;
}

int func_001EF3E0(Actor *a)
{
    int id = *func_00144158(a);

    return id == 255 ? 0 : MsCheckStartEffect(id, MsGetChr(id)->fA80);
}

int func_001EF430(Actor *a, void *op, ScriptCtx *ctx)
{
    int v = AtelPopStackInteger(a, ctx);
    int id = *func_00144158(a);

    return id == 255 ? 0 : func_001CFA38(id, v);
}

int func_001EF490(Actor *a)
{
    func_00144158(a);
    return 0;
}

int func_001EF4B0(Actor *ctx)
{
    int r = 5;

    if (MsGetChr(*func_00144158(ctx))->fAD2 != 0) {
        r = 0;
    }
    return r;
}
