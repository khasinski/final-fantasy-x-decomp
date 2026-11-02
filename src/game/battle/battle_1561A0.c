/* tu_099 0x1561a0-0x1570a0: low; unk_1561A0 (config/tu_map.tsv) */
#include "common.h"
#include "ffx/q2.h"
#include "ffx/r1.h"
#include "ffx/s1.h"
#include "ffx/u1.h"
#include "ffx/w2.h"
#include "ffx/b0.h"
#include "ffx/q3.h"

int func_001561A0(Actor *a, void *op, ScriptCtx *ctx)
{
    int v1;

    v1 = func_00154218(a, 0, 0);
    MsCameraPriority(v1, AtelPopStackInteger(a, ctx));
    return v1;
}

int func_00156200(Actor *a, void *op, ScriptCtx *ctx)
{
    int v1;

    v1 = func_00154218(a, 0, 0);
    func_001AA150(v1, AtelPopStackInteger(a, ctx));
    return v1;
}

int func_00156260(Actor *a, void *op, ScriptCtx *ctx)
{
    int v1;

    v1 = func_00154218(a, 0, 0);
    func_001A82A8(v1, AtelPopStackInteger(a, ctx));
    return v1;
}

int func_001562C0(Actor *a, void *op, ScriptCtx *ctx)
{
    int v1;
    int v2;

    v1 = func_00154218(a, 0, 0);
    v2 = AtelPopStackInteger(a, ctx);
    func_001A8340(v1, AtelPopStackInteger(a, ctx), v2);
    return v1;
}

int func_00156340(Actor *a, void *op, ScriptCtx *ctx)
{
    return brnd((AtelPopStackInteger(a, ctx) & 1) | 0xE);
}

int func_00156368(int a)
{
    int v1;

    v1 = func_00154218(a, 0, 0);
    MsCameraReset(v1, 0);
    return v1;
}

int func_001563A8(int a)
{
    int v1;

    v1 = func_00154218(a, 0, 0);
    MsCameraReset(v1, 1);
    return v1;
}

int func_001563E8(Actor *a, void *op, ScriptCtx *ctx)
{
    int p1;
    int p2;
    int p3;
    int p4;
    int p5;
    int p6;

    p1 = AtelPopStackInteger(a, ctx);
    p2 = AtelPopStackInteger(a, ctx);
    p3 = AtelPopStackInteger(a, ctx);
    p4 = AtelPopStackInteger(a, ctx);
    p5 = AtelPopStackInteger(a, ctx);
    p6 = AtelPopStackInteger(a, ctx);
    func_001AA850(p6, 1);
    MsSetScreenData(p6, p5, p4, p3, p2, p1, 0);
    return 0;
}

int func_001564C8(Actor *a, void *op, ScriptCtx *ctx)
{
    int v1;

    v1 = AtelPopStackInteger(a, ctx);
    func_001AA878(AtelPopStackInteger(a, ctx), v1);
    return 0;
}

int func_00156528(Actor *a, void *op, ScriptCtx *ctx)
{
    int v1;

    v1 = AtelPopStackInteger(a, ctx);
    MsSetScreenInfo(v1, 0, v1);
    return 0;
}

int func_00156558(Actor *a, void *op, ScriptCtx *ctx)
{
    int p1;
    int p2;
    int p3;
    int p4;
    int p5;

    p1 = AtelPopStackInteger(a, ctx);
    p2 = AtelPopStackInteger(a, ctx);
    p3 = AtelPopStackInteger(a, ctx);
    p4 = AtelPopStackInteger(a, ctx);
    p5 = AtelPopStackInteger(a, ctx);
    MsSetDrawData(p5, p4, p3, p2, p1);
    return 0;
}

int func_00156608(Actor *a, void *op, ScriptCtx *ctx)
{
    int v1;

    v1 = AtelPopStackInteger(a, ctx);
    func_001AAD48(AtelPopStackInteger(a, ctx), 0, v1);
    return 0;
}

int func_00156668(Actor *a, void *op, ScriptCtx *ctx)
{
    int v1;

    v1 = AtelPopStackInteger(a, ctx);
    func_001AAD48(AtelPopStackInteger(a, ctx), 1, v1);
    return 0;
}

int func_001566C8(Actor *a, void *op, ScriptCtx *ctx)
{
    int v1;

    v1 = AtelPopStackInteger(a, ctx);
    func_001AAB10(AtelPopStackInteger(a, ctx), 0, v1, 1);
    return 0;
}

int func_00156730(Actor *a, void *op, ScriptCtx *ctx)
{
    int v1;

    v1 = AtelPopStackInteger(a, ctx);
    func_001AAB10(AtelPopStackInteger(a, ctx), 0, v1, 3);
    return 0;
}

int func_00156798(Actor *a, void *op, ScriptCtx *ctx)
{
    int p1;
    int p2;
    int p3;
    int p4;

    p1 = AtelPopStackInteger(a, ctx);
    p2 = AtelPopStackInteger(a, ctx);
    p3 = AtelPopStackInteger(a, ctx);
    p4 = AtelPopStackInteger(a, ctx);
    func_001AAB88(p4, 0, p3, p2, p1);
    return 0;
}

int func_00156830(Actor *a, void *op, ScriptCtx *ctx)
{
    int v1;

    v1 = AtelPopStackInteger(a, ctx);
    func_001AAB10(AtelPopStackInteger(a, ctx), 1, v1, 1);
    return 0;
}

int func_00156898(Actor *a, void *op, ScriptCtx *ctx)
{
    int v1;

    v1 = AtelPopStackInteger(a, ctx);
    func_001AAB10(AtelPopStackInteger(a, ctx), 1, v1, 3);
    return 0;
}

int func_00156900(Actor *a, void *op, ScriptCtx *ctx)
{
    int p1;
    int p2;
    int p3;
    int p4;

    p1 = AtelPopStackInteger(a, ctx);
    p2 = AtelPopStackInteger(a, ctx);
    p3 = AtelPopStackInteger(a, ctx);
    p4 = AtelPopStackInteger(a, ctx);
    func_001AAB88(p4, 1, p3, p2, p1);
    return 0;
}

int func_00156998(Actor *a, void *op, ScriptCtx *ctx)
{
    func_001AAA38(AtelPopStackInteger(a, ctx), 0);
    return 0;
}

int func_001569C8(Actor *a, void *op, ScriptCtx *ctx)
{
    func_001AAA38(AtelPopStackInteger(a, ctx), 1);
    return 0;
}

int func_001569F8(Actor *a, int *p, ScriptCtx *ctx)
{
    func_00144158(a);
    return *p = AtelPopStackInteger(a, ctx);
}

int func_00156A48(int a, int *p)
{
    int r = 5;

    if (func_001AAAB0(*p, 1)) {
        r = 0;
    }
    return r;
}

int func_00156A80(Actor *a, int *p, ScriptCtx *ctx)
{
    func_00144158(a);
    return *p = AtelPopStackInteger(a, ctx);
}

int func_00156AD0(int a, int *p)
{
    int r = 5;

    if (func_001AAAB0(*p, 0)) {
        r = 0;
    }
    return r;
}

int func_00156B08(int a, int op, int ctx, int d, int e) /* DEBT(TYPE): q2.h declares ints for (Actor *, op, ScriptCtx *, d, e) */
{
    int h = func_00154218(a, 0, 0);
    int v1 = AtelPopStackInteger((Actor *)a, (ScriptCtx *)ctx);
    int v2 = AtelPopStackInteger((Actor *)a, (ScriptCtx *)ctx);
    int v3 = AtelPopStackInteger((Actor *)a, (ScriptCtx *)ctx);
    float f = AtelPopStackFloat((Actor *)a, (ScriptCtx *)ctx);

    func_001AB568(h, d, AtelPopStackInteger((Actor *)a, (ScriptCtx *)ctx), e, f, v3, v2, v1);
    return h;
}

int func_00156BF8(int a, int b, int c)
{
    return func_00156B08(a, b, c, 0, 1);
}

int func_00156C18(int a, int b, int c)
{
    return func_00156B08(a, b, c, 1, 1);
}

int func_00156C38(int a, int b, int c)
{
    return func_00156B08(a, b, c, 0, 2);
}

int func_00156C58(int a, int b, int c)
{
    return func_00156B08(a, b, c, 1, 2);
}

int func_00156C78(int a, int b, int c)
{
    return func_00156B08(a, b, c, 0, 3);
}

int func_00156C98(int a, int b, int c)
{
    return func_00156B08(a, b, c, 1, 3);
}

int func_00156CB8(int a, int b, int c)
{
    return func_00156B08(a, b, c, 0, 4);
}

int func_00156CD8(int a, int b, int c)
{
    return func_00156B08(a, b, c, 1, 4);
}

int func_00156CF8(int a, int b, int c)
{
    return func_00156B08(a, b, c, 0, 5);
}

int func_00156D18(int a, int b, int c)
{
    return func_00156B08(a, b, c, 1, 5);
}

int func_00156D38(int a, int b, int c)
{
    return func_00156B08(a, b, c, 0, 6);
}

int func_00156D58(int a, int b, int c)
{
    return func_00156B08(a, b, c, 1, 6);
}

int func_00156D78(int a, int b, int c)
{
    return func_00156B08(a, b, c, 0, 7);
}

int func_00156D98(int a, int b, int c)
{
    return func_00156B08(a, b, c, 1, 7);
}

int func_00156DB8(int a, int b, int c)
{
    return func_00156B08(a, b, c, 0, 8);
}

int func_00156DD8(int a, int b, int c)
{
    return func_00156B08(a, b, c, 1, 8);
}

int func_00156DF8(int a, int op, int ctx, int d) /* DEBT(TYPE): q2.h declares ints for (Actor *, op, ScriptCtx *, d) */
{
    int v1 = AtelPopStackInteger((Actor *)a, (ScriptCtx *)ctx);
    int v2 = AtelPopStackInteger((Actor *)a, (ScriptCtx *)ctx);
    int v3 = AtelPopStackInteger((Actor *)a, (ScriptCtx *)ctx);
    float f = AtelPopStackFloat((Actor *)a, (ScriptCtx *)ctx);
    int v5 = AtelPopStackInteger((Actor *)a, (ScriptCtx *)ctx);

    func_001AB668(AtelPopStackInteger((Actor *)a, (ScriptCtx *)ctx), v5, d, f, v3, v2, v1);
    return 0;
}

int func_00156ED8(int a, int b, int c)
{
    func_00156DF8(a, b, c, 1);
    return 0;
}

int func_00156EF8(int a, int b, int c)
{
    func_00156DF8(a, b, c, 2);
    return 0;
}

int func_00156F18(int a, int b, int c)
{
    func_00156DF8(a, b, c, 3);
    return 0;
}

int func_00156F38(int a, int b, int c)
{
    func_00156DF8(a, b, c, 4);
    return 0;
}

int func_00156F58(int a, int b, int c)
{
    func_00156DF8(a, b, c, 5);
    return 0;
}

int func_00156F78(int a, int b, int c)
{
    func_00156DF8(a, b, c, 6);
    return 0;
}

int func_00156F98(Actor *a, void *op, ScriptCtx *ctx)
{
    int v1 = AtelPopStackInteger(a, ctx);
    float f2 = AtelPopStackFloat(a, ctx);
    int v3 = AtelPopStackInteger(a, ctx);
    float f4 = AtelPopStackFloat(a, ctx);
    int v5 = AtelPopStackInteger(a, ctx);
    int v6 = AtelPopStackInteger(a, ctx);
    int v7 = AtelPopStackInteger(a, ctx);

    func_001AB6D8(AtelPopStackInteger(a, ctx), v7, 9, v6, v5, f4, v3, f2, v1);
    return 0;
}
