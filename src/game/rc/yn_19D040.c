/* tu_163 0x19d040-0x19d3c0: low; ~Yn (config/tu_map.tsv) */
#include "common.h"
#include "ffx/r2.h"
#include "ffx/q3.h"
#include "ffx/w3.h"
#include "ffx/s2.h"
#include "ffx/v2.h"

int func_0019D040(int a)
{
    return func_0019AB50(a + 0x5B, 6, 2)->w00;
}

int func_0019D068(void)
{
    return 1;
}

int func_0019D070(int a)
{
    return func_0019D040(a);
}

void func_0019D090(void *p, int a, float *v)
{
    if (p != 0 && a < 2) {
        func_00198760(p, a, v);
    }
}

void func_0019D0B0(void) {
}

void func_0019D0B8(void) {
}

W3Obj *func_0019D0C0(void)
{
    return func_0019AB50(0x5A, 6, 2);
}

void func_0019D0E8(int a)
{
    W3Obj *obj;

    obj = func_0019D0C0();
    if (obj != 0) {
        func_002DD948(&obj->blk50, a);
    }
}

W3Blk *Yn_SeaGetAng(void)
{
    W3Obj *obj;

    obj = func_0019D0C0();
    if (obj != 0) {
        return &obj->blk50;
    }
    return 0;
}

void func_0019D150(int a)
{
    W3Obj *obj;

    obj = func_0019D0C0();
    if (obj != 0) {
        func_002DD948(&obj->blk40, a);
    }
}

W3Blk *Yn_SeaGetPos(void)
{
    W3Obj *obj;

    obj = func_0019D0C0();
    if (obj != 0) {
        return &obj->blk40;
    }
    return 0;
}

void func_0019D1B8(void *a)
{
    func_002DD0C0(&D_0065FD40, a);
}

void Yn_SeaResetMatrix(void)
{
    func_002DD128(&D_0065FD40);
}

struct W3Whole *Yn_SeaGetMatrix(void)
{
    return &D_0065FD40;
}

void func_0019D1E8(float x, float y)
{
    W3Obj *obj;

    obj = func_0019D0C0();
    if (obj != 0) {
        obj->f60 = x;
        obj->f64 = y;
        obj->enableE4 = 1;
    }
}

float *func_0019D230(void)
{
    W3Obj *obj;

    obj = func_0019D0C0();
    if (obj != 0) {
        return &obj->f60;
    }
    return 0;
}

void func_0019D258(void)
{
    W3Obj *obj;

    obj = func_0019D0C0();
    if (obj != 0) {
        obj->flagsE3 &= ~4;
    }
}

void func_0019D288(void)
{
    W3Obj *obj;

    obj = func_0019D0C0();
    if (obj != 0) {
        obj->flagsE3 |= 4;
    }
}

void func_0019D2B8(void)
{
}

void func_0019D2C0(void)
{
}

void func_0019D2C8(void)
{
}

void func_0019D2D0(void)
{
}

void func_0019D2D8(int a, int b, int c)
{
    void *p;

    p = func_00194AB0(0x20008, 0);
    if (p != 0) {
        func_0019B810(p, a, b, c);
    }
}

void func_0019D348(void)
{
    void *p;

    p = func_00194AB0(0x20008, 0);
    if (p != 0) {
        func_0019B878(p);
    }
}

void Yn_BattleBegin(void)
{
    if (g_pMainWork != 0) {
        func_00197CD8(g_pMainWork->sub);
    }
}

void Yn_Dummy(void)
{
    if (g_pMainWork != 0) {
        func_00197CE8(g_pMainWork->sub);
    }
}
