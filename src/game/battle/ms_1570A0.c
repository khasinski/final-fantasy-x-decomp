/* tu_100 0x1570a0-0x157798: low; ~Ms (config/tu_map.tsv) */
#include "common.h"
#include "ffx/q2.h"
#include "ffx/w2.h"
#include "ffx/r1.h"
#include "ffx/s1.h"
#include "ffx/b0.h"
#include "ffx/q3.h"
#include "ffx/u1.h"

int func_001570A0(int a)
{
    func_001ABFD8(func_00154218(a, 0, 0), 0);
    return 0;
}

int func_001570D0(int a)
{
    func_001ABFD8(func_00154218(a, 0, 0), 1);
    return 0;
}

int func_00157100(Actor *a, void *op, ScriptCtx *ctx)
{
    MsScreenResetShake(AtelPopStackInteger(a, ctx));
    return 0;
}

int func_00157128(int a)
{
    int r = 5;

    if (func_001AC0B8(func_00154218(a, 0, 0), 1)) {
        r = 0;
    }
    return r;
}

int func_00157168(int a)
{
    int r = 5;

    if (func_001AC0B8(func_00154218(a, 0, 0), 0)) {
        r = 0;
    }
    return r;
}

int func_001571A8(Actor *a, int *p, ScriptCtx *ctx)
{
    return *p = AtelPopStackInteger(a, ctx);
}

int func_001571D8(Actor *a, int *p, ScriptCtx *ctx)
{
    int r = 5;

    if (func_001AC128(*p)) {
        r = 0;
    }
    return r;
}

int func_00157208(int a, int i)
{
    Rec58F9F0 *rec;

    if ((u32)i < 2) {
        rec = &D_0058F9F0[i];
        if (D_0058F9E0[i] < 3) {
            return 0;
        }
        rec->n = D_0058F9E0[i];
    } else {
        rec = (Rec58F9F0 *)AtelGetRealVarAdrs((Actor *)a, i); /* DEBT(CAST): AtelGetRealVarAdrs returns a variable address as int */
    }
    return (int)rec; /* DEBT(CAST): q2.h declares an int result */
}

int func_00157278(int a, int op, int ctx, int which) /* DEBT(TYPE): q2.h declares ints for (Actor *, op, ScriptCtx *, which) */
{
    int h = func_00154218(a, 0, 0);
    int n = AtelPopStackInteger((Actor *)a, (ScriptCtx *)ctx);
    float y = AtelPopStackFloat((Actor *)a, (ScriptCtx *)ctx);
    float x = AtelPopStackFloat((Actor *)a, (ScriptCtx *)ctx);
    int v = func_00157208(a, AtelPopStackInteger((Actor *)a, (ScriptCtx *)ctx));

    if (v) {
        MsCameraSetSpline(h, which, v, x, y, n);
    }
    return h;
}

int func_00157350(int a, int b, int c)
{
    return func_00157278(a, b, c, 1);
}

int func_00157370(int a, int b, int c)
{
    return func_00157278(a, b, c, 0);
}

int func_00157390(int a)
{
    int v1;

    v1 = func_00154218(a, 0, 0);
    func_001574A8(v1, 1);
    return v1;
}

int func_001573D0(int a)
{
    int v1;

    v1 = func_00154218(a, 0, 0);
    func_001574F8(v1, 1);
    return v1;
}

int func_00157410(int a)
{
    int v1;

    v1 = func_00154218(a, 0, 0);
    func_001574A8(v1, 0);
    return v1;
}

int func_00157450(int a)
{
    int v1;

    v1 = func_00154218(a, 0, 0);
    func_001574F8(v1, 0);
    return v1;
}

void MsSplineInit(void)
{
    D_0058F9E0[0] = 0;
    D_0058F9E0[1] = 0;
}

void func_001574A8(int h, int which)
{
    if (func_001A6738(h) == h) {
        which &= 1;
        D_0058F9E0[which] = 0;
    }
}

INCLUDE_ASM("build/ee_asm/game/battle/ms_1570A0", func_001574F8);

int func_001575D8(Actor *a, void *op, ScriptCtx *ctx)
{
    int v1;
    int v2;

    v1 = AtelPopStackInteger(a, ctx);
    v2 = func_00157208(a, AtelPopStackInteger(a, ctx));
    if (v2) {
        func_001A8C28(func_00154218(a, 0, 0), 0, (R2AreaObj *)v2, 0.0f, v1); /* DEBT(CAST): v2 is a variable address returned as int */
    }
    return 0;
}

int func_00157668(Actor *a, void *op, ScriptCtx *ctx)
{
    int v1;
    float f;
    int v2;

    v1 = AtelPopStackInteger(a, ctx);
    f = AtelPopStackFloat(a, ctx);
    v2 = func_00157208(a, AtelPopStackInteger(a, ctx));
    if (v2) {
        func_001A8C28(func_00154218(a, 0, 0), 0, (R2AreaObj *)v2, f, v1); /* DEBT(CAST): v2 is a variable address returned as int */
    }
    return 0;
}

int func_00157710(Actor *a, void *op, ScriptCtx *ctx)
{
    int v1;
    int v2;

    v1 = AtelPopStackInteger(a, ctx);
    v2 = func_00157208(a, AtelPopStackInteger(a, ctx));
    if (v2) {
        func_001A7530(func_00154218(a, 0, 0), 1, v2, v1);
    }
    return 0;
}
