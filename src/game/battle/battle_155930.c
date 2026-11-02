/* tu_098 0x155930-0x1561a0: low; unk_155930 (config/tu_map.tsv) */
#include "common.h"
#include "ffx/q2.h"
#include "ffx/r1.h"
#include "ffx/s1.h"
#include "ffx/u1.h"

int func_00155930(int a)
{
    int v1;

    v1 = func_00154218(a, 0, 0);
    func_001A9B38(v1, 0);
    return v1;
}

int func_00155970(int a)
{
    int v1;

    v1 = func_00154218(a, 0, 0);
    MsCameraResetMove(v1, 0);
    return v1;
}

int func_001559B0(int a)
{
    int r = 5;

    if (func_001A9C98(func_00154218(a, 0, 0), 0)) {
        r = 0;
    }
    return r;
}

int func_001559F0(int a)
{
    return func_001A9C98(func_00154218(a, 0, 0), 0);
}

int func_00155A20(Actor *a, void *op, ScriptCtx *ctx)
{
    int h = func_00154218((int)a, 0, 0); /* DEBT(CAST): q2.h declares an int parameter */
    float r = AtelPopStackFloat(a, ctx) * 3.1415927f / 180.0f;

    func_001A83F0(h, 1, 1, AtelGetRealVarAdrs(a, AtelPopStackInteger(a, ctx)), r);
    return h;
}

int func_00155AD0(Actor *a, void *op, ScriptCtx *ctx)
{
    int h = func_00154218((int)a, 0, 0); /* DEBT(CAST): q2.h declares an int parameter */
    float r = AtelPopStackFloat(a, ctx) * 3.1415927f / 180.0f;

    func_001A83F0(h, 1, 0, AtelGetRealVarAdrs(a, AtelPopStackInteger(a, ctx)), r);
    return h;
}

int func_00155B80(Actor *a, void *op, ScriptCtx *ctx)
{
    int h = func_00154218((int)a, 0, 0); /* DEBT(CAST): q2.h declares an int parameter */
    float z = AtelPopStackFloat(a, ctx);
    float y = AtelPopStackFloat(a, ctx);
    float r = AtelPopStackFloat(a, ctx) * 3.1415927f / 180.0f;

    func_001A8850(h, 1, 1, AtelGetRealVarAdrs(a, AtelPopStackInteger(a, ctx)), r, y, z);
    return h;
}

int func_00155C68(Actor *a, void *op, ScriptCtx *ctx)
{
    int h = func_00154218((int)a, 0, 0); /* DEBT(CAST): q2.h declares an int parameter */
    float z = AtelPopStackFloat(a, ctx);
    float y = AtelPopStackFloat(a, ctx);
    float r = AtelPopStackFloat(a, ctx) * 3.1415927f / 180.0f;

    func_001A8850(h, 1, 0, AtelGetRealVarAdrs(a, AtelPopStackInteger(a, ctx)), r, y, z);
    return h;
}

int func_00155D50(Actor *a, void *op, ScriptCtx *ctx)
{
    int h = func_00154218((int)a, 0, 0); /* DEBT(CAST): q2.h declares an int parameter */

    func_001A6E10(h, 0, AtelPopStackInteger(a, ctx) ^ 0xFFFF);
    return h;
}

int func_00155DB8(Actor *a, void *op, ScriptCtx *ctx)
{
    int h = func_00154218((int)a, 0, 0); /* DEBT(CAST): q2.h declares an int parameter */

    func_001A6E10(h, 1, AtelPopStackInteger(a, ctx) ^ 0xFFFF);
    return h;
}

int func_00155E20(int a, int op, int ctx, int which) /* DEBT(TYPE): q2.h declares ints for (Actor *, op, ScriptCtx *, which) */
{
    u8 *id = func_00144158((Actor *)a);
    int h = func_00154218(a, 2, 0);
    float scale = AtelPopStackFloat((Actor *)a, (ScriptCtx *)ctx) / 100.0f;
    int n1 = AtelPopStackInteger((Actor *)a, (ScriptCtx *)ctx);
    int n2 = AtelPopStackInteger((Actor *)a, (ScriptCtx *)ctx);

    MsCameraSetBtl(h, which, *id, 0, n2, n1, scale, 0.0f, 0.0f, 0.0f);
    return h;
}

int func_00155F00(int a, int op, int ctx, int which, int mode) /* DEBT(TYPE): q2.h declares ints for (Actor *, op, ScriptCtx *, which, mode) */
{
    u8 *id = func_00144158((Actor *)a);
    int h = func_00154218(a, 2, 0);
    float w = AtelPopStackFloat((Actor *)a, (ScriptCtx *)ctx) / 100.0f;
    float z = AtelPopStackFloat((Actor *)a, (ScriptCtx *)ctx);
    float y = AtelPopStackFloat((Actor *)a, (ScriptCtx *)ctx);
    float x = AtelPopStackFloat((Actor *)a, (ScriptCtx *)ctx) / 100.0f;
    int n1 = AtelPopStackInteger((Actor *)a, (ScriptCtx *)ctx);
    int n2 = AtelPopStackInteger((Actor *)a, (ScriptCtx *)ctx);

    z = z * 3.1415927f / 180.0f;
    y = y * 3.1415927f / 180.0f;
    MsCameraSetBtl(h, which, *id, mode, n2, n1, x, y, z, w);
    return h;
}

int func_00156070(int a, int b, int c)
{
    func_00155E20(a, b, c, 1);
    return 0;
}

int func_00156090(int a, int b, int c)
{
    func_00155E20(a, b, c, 0);
    return 0;
}

int func_001560B0(int a, int b, int c)
{
    func_00155F00(a, b, c, 1, 1);
    return 0;
}

int func_001560D8(int a, int b, int c)
{
    func_00155F00(a, b, c, 0, 1);
    return 0;
}

int func_00156100(int a, int b, int c)
{
    func_00155F00(a, b, c, 1, 2);
    return 0;
}

int func_00156128(int a, int b, int c)
{
    func_00155F00(a, b, c, 0, 2);
    return 0;
}

int func_00156150(int a, int b, int c)
{
    func_00155F00(a, b, c, 1, 3);
    return 0;
}

int func_00156178(int a, int b, int c)
{
    func_00155F00(a, b, c, 1, 4);
    return 0;
}
