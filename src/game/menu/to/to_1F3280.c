/* tu_219 0x1f3280-0x1f4818: low; ~TOBtlDrawWeaponAbilityWindow (config/tu_map.tsv) */
#include "common.h"
#include "ffx/q5.h"
#include "ffx/r4.h"
#include "ffx/v4.h"
#define func_001F3808 s4_func_001F3808 /* DEBT(TYPE): this header's guess conflicts with the TU */
#include "ffx/s4.h"
#undef func_001F3808
#include "ffx/t4.h"

INCLUDE_ASM("build/ee_asm/game/menu/to/to_1F3280", TOBtlDrawWeaponAbilityWindow);

void func_001F34A8(int a, int b, int c, int d)
{
    InvokedFromSelectCursor = func_001F8ED8(InvokedFromSelectCursor, a, b, c, d);
    func_001EFA30();
}

void func_001F34F0(int a, int b, int c, int d)
{
    InvokedFromSelectCursor = func_001F3DE8(InvokedFromSelectCursor, a, b, c, d);
    func_001EFA30();
}

void func_001F3538(int a, int b, int c, int d)
{
    InvokedFromSelectCursor = func_001F3C58(InvokedFromSelectCursor, a, b, c, d);
    func_001EFA30();
}

void func_001F3580(int a, int b, int c, int d, int e)
{
    InvokedFromSelectCursor = func_001F3F28(InvokedFromSelectCursor, a, b, c, d, e);
    func_001EFA30();
}

void func_001F35D0(int a, int b, int c, int d, int e)
{
    InvokedFromSelectCursor = func_001F40A0(InvokedFromSelectCursor, a, b, c, d, e);
    func_001EFA30();
}

void TOMkpEasyMesFontLCenter(int a, int b, int c)
{
    s16 v[2];

    _TOGetMessageWH(0, (u8 *)a, &v[0], &v[1], 0, 0); /* DEBT(CAST): the string comes in as int */
    InvokedFromSelectCursor = func_001F4178(InvokedFromSelectCursor, a, b - v[0] / 2, c);
    func_001EFA30();
}

void func_001F36B8(int a, int b, int c)
{
    s16 v[2];

    _TOGetMessageWH(0, (u8 *)a, &v[0], &v[1], 0, 0); /* DEBT(CAST): the string comes in as int */
    InvokedFromSelectCursor = func_001F4178(InvokedFromSelectCursor, a, b - v[0], c);
    func_001EFA30();
}

void func_001F3738(int a, int b, int c, int d)
{
    s16 v[2];

    _TOGetMessageWH(0, (u8 *)a, &v[0], &v[1], 0, 0); /* DEBT(CAST): the string comes in as int */
    InvokedFromSelectCursor = func_001F41C0(InvokedFromSelectCursor, a, b - v[0], c, d);
    func_001EFA30();
}

void func_001F37C8(int a, int b, int c)
{
    InvokedFromSelectCursor = func_001F4178(InvokedFromSelectCursor, a, b, c);
    func_001EFA30();
}

void func_001F3808(int a, int b, int c, int d)
{
    InvokedFromSelectCursor = func_001F41C0(InvokedFromSelectCursor, a, b, c, d);
    func_001EFA30();
}

void func_001F3850(int a, int b, int c, int d, int e)
{
    InvokedFromSelectCursor = func_001F4210(InvokedFromSelectCursor, a, b, c, d, e);
    func_001EFA30();
}

void func_001F38A0(int a, int b, int c, int d, int e, int f, int g, int h)
{
    InvokedFromSelectCursor = func_001F4260(InvokedFromSelectCursor, a, b, c, d, e, f, g, h);
    func_001EFA30();
}

void func_001F3910(int a, int b, int c, int d)
{
    InvokedFromSelectCursor = func_001F42B8(InvokedFromSelectCursor, a, b, c, d);
    func_001EFA30();
}

void func_001F3958(int a, int b, int c, int d, int e)
{
    InvokedFromSelectCursor = func_001F42F0(InvokedFromSelectCursor, a, b, c, d, e);
    func_001EFA30();
}

void func_001F39A8(int a, int b, int c, int d, int e, int f)
{
    InvokedFromSelectCursor = func_001F4320(InvokedFromSelectCursor, a, b, c, d, e, f);
    func_001EFA30();
}

void func_001F3A00(int a, int b, int c, int d, int e, int f, int g, int h, int i)
{
    InvokedFromSelectCursor = func_001F4350(InvokedFromSelectCursor, a, b, c, d, e, f, g, h, i);
    func_001EFA30();
}

void func_001F3A80(int a, int b, int c, int d, int e, int f, int g, int h, int i, int j)
{
    InvokedFromSelectCursor = TOAddPktBaseMesFontLClutTypeRGBA(InvokedFromSelectCursor, a, b, c, d, e, f, g, h, i, j);
    func_001EFA30();
}

void func_001F3B10(int a, int b, int c, int d, int e)
{
    InvokedFromSelectCursor = func_001F46A0(InvokedFromSelectCursor, a, b, c, d, e);
    func_001EFA30();
}

void *func_001F3B60(void *list, int id, int x, int y, int d, int e, int f, int g, int h)
{
    char buf[32];

    func_00207648(id, buf, 0);
    if (func_0020B850() == 0 && func_001BD360() == 0) {
        x -= func_002F0840(buf) * 12;
    } else {
        x -= func_002F0840(buf) * 9;
    }
    return TOAddPktBaseMesFontLClutTypeRGBA(list, -1, (int)buf, x, y, d, 0, e, f, g, h); /* DEBT(CAST): prototype takes the record as int */
}

void *func_001F3C58(void *list, int id, int x, int y, int d)
{
    char buf[32];

    func_00207648(id, buf, 0);
    if (func_0020B850() == 0 && func_001BD360() == 0) {
        x -= func_002F0840(buf) * 12;
    } else {
        x -= func_002F0840(buf) * 9;
    }
    return TOAddPktBaseMesFontLClutTypeRGBA(list, -1, (int)buf, x, y, d, 0, 0x80, 0x80, 0x80, 0x80); /* DEBT(CAST): prototype takes the record as int */
}

void *func_001F3D30(void *list, int id, int x, int y, int d, int e, int f, int g, int h)
{
    char buf[32];

    func_00207648(id, buf, 0);
    return TOAddPktBaseMesFontLClutTypeRGBA(list, -1, (int)buf, x, y, d, 0, e, f, g, h); /* DEBT(CAST): prototype takes the record as int */
}

void *func_001F3DE8(void *list, int id, int x, int y, int d)
{
    char buf[32];

    func_00207648(id, buf, 0);
    return TOAddPktBaseMesFontLClutTypeRGBA(list, -1, (int)buf, x, y, d, 0, 0x80, 0x80, 0x80, 0x80); /* DEBT(CAST): prototype takes the record as int */
}

void *func_001F3E70(void *list, int a, int id, int x, int y, int d, int e, int f, int g, int h)
{
    char buf[32];

    func_00207648(id, buf, a);
    return TOAddPktBaseMesFontLClutTypeRGBA(list, -1, (int)buf, x, y, d, 0, e, f, g, h); /* DEBT(CAST): prototype takes the record as int */
}

void *func_001F3F28(void *list, int a, int id, int x, int y, int d)
{
    char buf[32];

    func_00207648(id, buf, a);
    return TOAddPktBaseMesFontLClutTypeRGBA(list, -1, (int)buf, x, y, d, 0, 0x80, 0x80, 0x80, 0x80); /* DEBT(CAST): prototype takes the record as int */
}

void *func_001F3FB0(void *list, int a, int id, int x, int y, int d, int e, int f, int g, int h)
{
    char buf[32];

    func_00207648(id, buf, a);
    if (func_0020B850() == 0 && func_001BD360() == 0) {
        x -= func_002F0840(buf) * 12;
    } else {
        x -= func_002F0840(buf) * 9;
    }
    return TOAddPktBaseMesFontLClutTypeRGBA(list, -1, (int)buf, x, y, d, 0, e, f, g, h); /* DEBT(CAST): prototype takes the record as int */
}

void *func_001F40A0(void *list, int a, int id, int x, int y, int d)
{
    char buf[32];

    func_00207648(id, buf, a);
    if (func_0020B850() == 0 && func_001BD360() == 0) {
        x -= func_002F0840(buf) * 12;
    } else {
        x -= func_002F0840(buf) * 9;
    }
    return TOAddPktBaseMesFontLClutTypeRGBA(list, -1, (int)buf, x, y, d, 0, 0x80, 0x80, 0x80, 0x80); /* DEBT(CAST): prototype takes the record as int */
}

void *func_001F4178(void *list, int a, int b, int c)
{
    return TOAddPktBaseMesFontLClutTypeRGBA(list, 0, a, b, c, 0, 0, 0x80, 0x80, 0x80, 0x80);
}

void *func_001F41C0(void *list, int a, int b, int c, int d)
{
    return TOAddPktBaseMesFontLClutTypeRGBA(list, -1, a, b, c, d, 0, 0x80, 0x80, 0x80, 0x80);
}

void *func_001F4210(void *list, int a, int b, int c, int d, int e)
{
    return TOAddPktBaseMesFontLClutTypeRGBA(list, -1, a, b, c, d, 0, 0x80, 0x80, 0x80, e);
}

void *func_001F4260(void *list, int a, int b, int c, int d, int e, int f, int g, int h)
{
    return TOAddPktBaseMesFontLClutTypeRGBA(list, -1, a, b, c, d, 0, e, f, g, h);
}

void *func_001F42B8(void *list, int a, int b, int c, int d)
{
    return TOAddPktBaseMesFontLClutTypeRGBA(list, a, b, c, d, 0, 0, 0x80, 0x80, 0x80, 0x80);
}

void *func_001F42F0(void *list, int a, int b, int c, int d, int e)
{
    return TOAddPktBaseMesFontLClutTypeRGBA(list, a, b, c, d, e, 0, 0x80, 0x80, 0x80, 0x80);
}

void *func_001F4320(void *list, int a, int b, int c, int d, int e, int f)
{
    return TOAddPktBaseMesFontLClutTypeRGBA(list, a, b, c, d, e, 0, 0x80, 0x80, 0x80, f);
}

void *func_001F4350(void *list, int a, int b, int c, int d, int e, int f, int g, int h, int i)
{
    return TOAddPktBaseMesFontLClutTypeRGBA(list, a, b, c, d, e, 0, f, g, h, i);
}

void *func_001F4388(void *list, int a, int b, int c, int d, int e, int f, int g, int h, int i)
{
    return TOAddPktBaseMesFontLClutTypeRGBA(list, a, b, c, d, e, 0, f, g, h, i);
}

INCLUDE_ASM("build/ee_asm/game/menu/to/to_1F3280", TOAddPktBaseMesFontLClutTypeRGBA);

void *func_001F46A0(void *list, int a, int b, int c, int d, int e)
{
    return func_001F46D0(list, a, b, c, d, 0x80, 0x80, 0x80, 0x80, e);
}

INCLUDE_ASM("build/ee_asm/game/menu/to/to_1F3280", func_001F46D0);
