/* tu_097 0x1543e0-0x155930: low; unk_1543E0 (config/tu_map.tsv) */
#include "common.h"
#include "ffx/q2.h"
#include "ffx/w2.h"
#include "ffx/r1.h"
#include "ffx/s1.h"
#include "ffx/u1.h"

void func_001543E0(int a, int op, int ctx, int which) /* DEBT(TYPE): q2.h declares ints for (Actor *, op, ScriptCtx *, which) */
{
    int h = func_00154218(a, 0, 0);
    float v[3];

    v[2] = AtelPopStackFloat((Actor *)a, (ScriptCtx *)ctx);
    v[1] = AtelPopStackFloat((Actor *)a, (ScriptCtx *)ctx);
    v[0] = AtelPopStackFloat((Actor *)a, (ScriptCtx *)ctx);
    MsCameraSetRect(h, which, v);
}

void func_00154470(int a, int op, int ctx, int which) /* DEBT(TYPE): q2.h declares ints for (Actor *, op, ScriptCtx *, which) */
{
    Actor *actor = (Actor *)a;
    ScriptCtx *sc = (ScriptCtx *)ctx;
    int z = AtelGetRealVarAdrs(actor, AtelPopStackInteger(actor, sc));
    int y = AtelGetRealVarAdrs(actor, AtelPopStackInteger(actor, sc));
    int x = AtelGetRealVarAdrs(actor, AtelPopStackInteger(actor, sc));

    func_001A9EF0(func_00154218(a, 0, 0), which, (float *)x, (float *)y, (float *)z); /* DEBT(CAST): AtelGetRealVarAdrs returns the address as int */
}

void func_00154530(int a, int op, int ctx, int which) /* DEBT(TYPE): q2.h declares ints for (Actor *, op, ScriptCtx *, which) */
{
    Actor *actor = (Actor *)a;
    ScriptCtx *sc = (ScriptCtx *)ctx;
    int z = AtelGetRealVarAdrs(actor, AtelPopStackInteger(actor, sc));
    int y = AtelGetRealVarAdrs(actor, AtelPopStackInteger(actor, sc));
    int x = AtelGetRealVarAdrs(actor, AtelPopStackInteger(actor, sc));

    func_001A9F50(func_00154218(a, 0, 0), which, (float *)x, (float *)y, (float *)z); /* DEBT(CAST): AtelGetRealVarAdrs returns the address as int */
}

void func_001545F0(int a, int op, int ctx, int which, int mode) /* DEBT(TYPE): q2.h declares ints for (Actor *, op, ScriptCtx *, which, mode) */
{
    int h = func_00154218(a, 0, 0);
    float z = AtelPopStackFloat((Actor *)a, (ScriptCtx *)ctx);
    float y = AtelPopStackFloat((Actor *)a, (ScriptCtx *)ctx);
    float x = AtelPopStackFloat((Actor *)a, (ScriptCtx *)ctx);

    y = y * 3.1415927f / 180.0f;
    x = x * 3.1415927f / 180.0f;
    if (mode == 0) {
        func_001A6E90(h, which, x, y, z);
    } else {
        func_001A76E0(h, which, x, y, z);
    }
}

void func_00154708(int a, int op, int ctx, int which, int mode) /* DEBT(TYPE): q2.h declares ints for (Actor *, op, ScriptCtx *, which, mode) */
{
    int h = func_00154218(a, 0, 0);
    float f6 = AtelPopStackFloat((Actor *)a, (ScriptCtx *)ctx);
    float f5 = AtelPopStackFloat((Actor *)a, (ScriptCtx *)ctx);
    float f4 = AtelPopStackFloat((Actor *)a, (ScriptCtx *)ctx);
    float f3 = AtelPopStackFloat((Actor *)a, (ScriptCtx *)ctx);
    float f2 = AtelPopStackFloat((Actor *)a, (ScriptCtx *)ctx);
    float f1 = AtelPopStackFloat((Actor *)a, (ScriptCtx *)ctx);

    if (mode < 0) {
        func_001A7BC0(h, which, f1, f2, f3 * 3.1415927f / 180.0f, f4, f5, f6);
    } else {
        func_001A7E00(h, which, mode, f1, f2, f3, f4, f5, f6);
    }
}

void func_00154880(int a, int op, int ctx, int which) /* DEBT(TYPE): q2.h declares ints for (Actor *, op, ScriptCtx *, which) */
{
    int h = func_00154218(a, 0, 0);
    float v[3];
    int n1;

    v[0] = 0.0f;
    v[1] = AtelPopStackFloat((Actor *)a, (ScriptCtx *)ctx);
    v[2] = 0.0f;
    n1 = AtelPopStackInteger((Actor *)a, (ScriptCtx *)ctx);
    MsCameraSetAct(h, which, AtelPopStackInteger((Actor *)a, (ScriptCtx *)ctx), n1, v);
}

void func_00154928(int a, int op, int ctx, int which) /* DEBT(TYPE): q2.h declares ints for (Actor *, op, ScriptCtx *, which) */
{
    int h = func_00154218(a, 0, 0);
    float f4 = AtelPopStackFloat((Actor *)a, (ScriptCtx *)ctx);
    float f3 = AtelPopStackFloat((Actor *)a, (ScriptCtx *)ctx);
    float f2 = AtelPopStackFloat((Actor *)a, (ScriptCtx *)ctx) * 3.1415927f / 180.0f;
    float f1 = AtelPopStackFloat((Actor *)a, (ScriptCtx *)ctx) * 3.1415927f / 180.0f;

    func_001A6FA0(h, which, f1, f2, f3, f4);
}

void func_00154A20(int a, int op, int ctx, int which, int mode) /* DEBT(TYPE): q2.h declares ints for (Actor *, op, ScriptCtx *, which, mode) */
{
    int h = func_00154218(a, 0, 0);
    float f5 = AtelPopStackFloat((Actor *)a, (ScriptCtx *)ctx);
    float f4 = AtelPopStackFloat((Actor *)a, (ScriptCtx *)ctx);
    float f3 = AtelPopStackFloat((Actor *)a, (ScriptCtx *)ctx);
    float f2 = AtelPopStackFloat((Actor *)a, (ScriptCtx *)ctx);

    func_001A89F8(h, which, mode, AtelPopStackFloat((Actor *)a, (ScriptCtx *)ctx), f2, f3, f4, f5);
}

void func_00154B08(int a, int op, int ctx, int which, int mode) /* DEBT(TYPE): q2.h declares ints for (Actor *, op, ScriptCtx *, which, mode) */
{
    int h = func_00154218(a, 0, 0);
    float f3 = AtelPopStackFloat((Actor *)a, (ScriptCtx *)ctx);
    float f2 = AtelPopStackFloat((Actor *)a, (ScriptCtx *)ctx);

    func_001A8B38(h, which, mode, AtelPopStackFloat((Actor *)a, (ScriptCtx *)ctx), f2, f3);
}

void func_00154BB8(int a, int op, int ctx, int which, int mode, int total) /* DEBT(TYPE): q2.h declares ints for (Actor *, op, ScriptCtx *, ...) */
{
    int h = func_00154218(a, 0, 0);

    func_001A9550(h, which, mode, AtelPopStackInteger((Actor *)a, (ScriptCtx *)ctx), total);
}

void func_00154C40(int a, int op, int ctx, int which, int mode) /* DEBT(TYPE): q2.h declares ints for (Actor *, op, ScriptCtx *, which, mode) */
{
    int h = func_00154218(a, 0, 0);
    int n4 = AtelPopStackInteger((Actor *)a, (ScriptCtx *)ctx);
    int n3 = AtelPopStackInteger((Actor *)a, (ScriptCtx *)ctx);
    int n2 = AtelPopStackInteger((Actor *)a, (ScriptCtx *)ctx);

    func_001A96A8(h, which, mode, AtelPopStackInteger((Actor *)a, (ScriptCtx *)ctx), n2, n3, n4);
}

void func_00154D10(int a, int op, int ctx, int which) /* DEBT(TYPE): q2.h declares ints for (Actor *, op, ScriptCtx *, which) */
{
    int h = func_00154218(a, 0, 0);
    float f4 = AtelPopStackFloat((Actor *)a, (ScriptCtx *)ctx);
    float f3 = AtelPopStackFloat((Actor *)a, (ScriptCtx *)ctx);
    float f2 = AtelPopStackFloat((Actor *)a, (ScriptCtx *)ctx);

    func_001A9860(h, which, AtelPopStackFloat((Actor *)a, (ScriptCtx *)ctx), f2, f3, f4);
}

void func_00154DD0(int a, int op, int ctx, int which) /* DEBT(TYPE): q2.h declares ints for (Actor *, op, ScriptCtx *, which) */
{
    int h = func_00154218(a, 0, 0);
    float f3 = AtelPopStackFloat((Actor *)a, (ScriptCtx *)ctx);
    float f2 = AtelPopStackFloat((Actor *)a, (ScriptCtx *)ctx);

    func_001A99D0(h, which, AtelPopStackFloat((Actor *)a, (ScriptCtx *)ctx), f2, f3);
}

int func_00154E70(Actor *a, void *op, ScriptCtx *ctx)
{
    int v1;

    v1 = func_00154218(AtelGetBasicWork(AtelPopStackInteger(a, ctx)), 0, 0);
    func_001A6BE0(v1, 1);
    return v1;
}

int func_00154EC0(Actor *a, void *op, ScriptCtx *ctx)
{
    int v1;

    v1 = func_00154218(AtelGetBasicWork(AtelPopStackInteger(a, ctx)), 0, 0);
    func_001A6BE0(v1, 0);
    return v1;
}

int func_00154F10(void) {
    func_00154390();
    return 0;
}

int func_00154F30(Actor *a, void *op, ScriptCtx *ctx)
{
    int h = func_00154218((int)a, 0, 0); /* DEBT(CAST): q2.h declares an int parameter */

    MsCameraSetRoll(h, AtelPopStackFloat(a, ctx) * 3.1415927f / 180.0f);
    return h;
}

int func_00154FB0(Actor *a, void *op, ScriptCtx *ctx)
{
    int v1;

    v1 = func_00154218(a, 0, 0);
    MsCameraSetScrDpt(v1, AtelPopStackFloat(a, ctx));
    return v1;
}

float func_00155010(void)
{
    return MsNearRag(0.0f, func_001AA028()) * 180.0f / 3.1415927f;
}

float func_00155060(void) {
    return MsCameraGetScrDpt();
}

int func_00155080(int a, int b, int c)
{
    func_001543E0(a, b, c, 1);
    return 0;
}

int func_001550A0(int a, int b, int c)
{
    func_00154470(a, b, c, 1);
    return 0;
}

int func_001550C0(int a, int b, int c)
{
    func_00154530(a, b, c, 1);
    return 0;
}

int func_001550E0(int a, int b, int c)
{
    func_001545F0(a, b, c, 1, 0);
    return 0;
}

int func_00155108(int a, int b, int c)
{
    func_001545F0(a, b, c, 1, -1);
    return 0;
}

int func_00155130(int a, int b, int c)
{
    func_00154708(a, b, c, 1, -1);
    return 0;
}

int func_00155158(int a, int b, int c)
{
    func_00154708(a, b, c, 1, 0);
    return 0;
}

int func_00155180(int a, int b, int c)
{
    func_00154708(a, b, c, 1, 1);
    return 0;
}

int func_001551A8(int a, int b, int c)
{
    func_00154880(a, b, c, 1);
    return 0;
}

int func_001551C8(int a, int b, int c)
{
    func_00154928(a, b, c, 1);
    return 0;
}

int func_001551E8(int a, int b, int c)
{
    func_00154A20(a, b, c, 1, 0);
    return 0;
}

int func_00155210(int a, int b, int c)
{
    func_00154A20(a, b, c, 1, 1);
    return 0;
}

int func_00155238(int a, int b, int c)
{
    func_00154B08(a, b, c, 1, 0);
    return 0;
}

int func_00155260(int a, int b, int c)
{
    func_00154B08(a, b, c, 1, 1);
    return 0;
}

int func_00155288(int a)
{
    int v1;

    v1 = func_00154218(a, 0, 0);
    func_001A8D28(v1, 1);
    return v1;
}

int func_001552C8(Actor *a, void *op, ScriptCtx *ctx)
{
    int h = func_00154218((int)a, 0, 0); /* DEBT(CAST): q2.h declares an int parameter */

    func_001A8DA0(h, 1, AtelPopStackInteger(a, ctx) & 1);
    return h;
}

int func_00155330(int a, int b, int c)
{
    func_00154BB8(a, b, c, 1, 0, 1);
    return 0;
}

int func_00155358(int a, int b, int c)
{
    func_00154BB8(a, b, c, 1, 1, 1);
    return 0;
}

int func_00155380(int a, int b, int c)
{
    func_00154BB8(a, b, c, 1, 0, 3);
    return 0;
}

int func_001553A8(int a, int b, int c)
{
    func_00154BB8(a, b, c, 1, 1, 3);
    return 0;
}

int func_001553D0(int a, int b, int c)
{
    func_00154C40(a, b, c, 1, 0);
    return 0;
}

int func_001553F8(int a, int b, int c)
{
    func_00154C40(a, b, c, 1, 1);
    return 0;
}

int func_00155420(int a, int b, int c)
{
    func_00154D10(a, b, c, 1);
    return 0;
}

int func_00155440(int a, int b, int c)
{
    func_00154DD0(a, b, c, 1);
    return 0;
}

int func_00155460(int a)
{
    int v1;

    v1 = func_00154218(a, 0, 0);
    func_001A9B38(v1, 1);
    return v1;
}

int func_001554A0(int a)
{
    int v1;

    v1 = func_00154218(a, 0, 0);
    MsCameraResetMove(v1, 1);
    return v1;
}

int func_001554E0(int a)
{
    int r = 5;

    if (func_001A9C98(func_00154218(a, 0, 0), 1)) {
        r = 0;
    }
    return r;
}

int func_00155520(int a)
{
    return func_001A9C98(func_00154218(a, 0, 0), 1);
}

int func_00155550(int a, int b, int c)
{
    func_001543E0(a, b, c, 0);
    return 0;
}

int func_00155570(int a, int b, int c)
{
    func_00154470(a, b, c, 0);
    return 0;
}

int func_00155590(int a, int b, int c)
{
    func_00154530(a, b, c, 0);
    return 0;
}

int func_001555B0(int a, int b, int c)
{
    func_001545F0(a, b, c, 0, 0);
    return 0;
}

int func_001555D8(int a, int b, int c)
{
    func_001545F0(a, b, c, 0, -1);
    return 0;
}

int func_00155600(int a, int b, int c)
{
    func_00154708(a, b, c, 0, -1);
    return 0;
}

int func_00155628(int a, int b, int c)
{
    func_00154708(a, b, c, 0, 0);
    return 0;
}

int func_00155650(int a, int b, int c)
{
    func_00154708(a, b, c, 0, 1);
    return 0;
}

int func_00155678(int a, int b, int c)
{
    func_00154880(a, b, c, 0);
    return 0;
}

int func_00155698(int a, int b, int c)
{
    func_00154928(a, b, c, 0);
    return 0;
}

int func_001556B8(int a, int b, int c)
{
    func_00154A20(a, b, c, 0, 0);
    return 0;
}

int func_001556E0(int a, int b, int c)
{
    func_00154A20(a, b, c, 0, 1);
    return 0;
}

int func_00155708(int a, int b, int c)
{
    func_00154B08(a, b, c, 0, 0);
    return 0;
}

int func_00155730(int a, int b, int c)
{
    func_00154B08(a, b, c, 0, 1);
    return 0;
}

int func_00155758(int a)
{
    int v1;

    v1 = func_00154218(a, 0, 0);
    func_001A8D28(v1, 0);
    return v1;
}

int func_00155798(Actor *a, void *op, ScriptCtx *ctx)
{
    int h = func_00154218((int)a, 0, 0); /* DEBT(CAST): q2.h declares an int parameter */

    func_001A8DA0(h, 0, AtelPopStackInteger(a, ctx) & 1);
    return h;
}

int func_00155800(int a, int b, int c)
{
    func_00154BB8(a, b, c, 0, 0, 1);
    return 0;
}

int func_00155828(int a, int b, int c)
{
    func_00154BB8(a, b, c, 0, 1, 1);
    return 0;
}

int func_00155850(int a, int b, int c)
{
    func_00154BB8(a, b, c, 0, 0, 3);
    return 0;
}

int func_00155878(int a, int b, int c)
{
    func_00154BB8(a, b, c, 0, 1, 3);
    return 0;
}

int func_001558A0(int a, int b, int c)
{
    func_00154C40(a, b, c, 0, 0);
    return 0;
}

int func_001558C8(int a, int b, int c)
{
    func_00154C40(a, b, c, 0, 1);
    return 0;
}

int func_001558F0(int a, int b, int c)
{
    func_00154D10(a, b, c, 0);
    return 0;
}

int func_00155910(int a, int b, int c)
{
    func_00154DD0(a, b, c, 0);
    return 0;
}
