/* tu_040 0x1229d0-0x123844: low; ~Sg (config/tu_map.tsv) */
#include "common.h"
#include "ffx/q0.h"
#include "ffx/r0.h"
#include "ffx/u0.h"

u32 func_001229D0(u32 v)
{
    if (Sg_IdExistShade()) {
        return v >> 17;
    }
    return 0x4210;
}

u32 func_00122A00(Chr *chr)
{
    u32 v = chr->w830; /* DEBT(TYPE): w830 is read unsigned here */

    if (Sg_IdExistShade()) {
        return v >> 17;
    }
    return 0x4210;
}

s8 Sg_IdExistShade(void)
{
    return D_00580C50;
}

INCLUDE_ASM("build/ee_asm/game/main/sg_1229D0", func_00122A40);

void Sg_MapSetPtr(s32 a)
{
    func_00122A40(a);
}

s32 func_00122AD8(void)
{
    D_0030890C++;
    if (D_0030890C >= 4) {
        D_0030890C = 0;
    }
    return D_0030890C;
}

void func_00122B00(void)
{
    func_00120D18(0);
}

void func_00122B08(void)
{
    u8 *value0;
    u8 *value1;
    u8 *value2;
    u8 *value3;
    u8 *value4;
    u8 *value5;

    if (ffx_debugmode == 0)
    {
        func_0011AAB8(1);
        return;
    }
    value0 = func_001042C0(5);
    if (value0 != 0)
    {
        func_002F072C((s8 *) D_00580D18, (s8 *) value0);
    }
    value1 = func_001042C0(7);
    if (value1 != 0)
    {
        func_002F072C(D_00580D58, (s8 *) value1);
    }
    value2 = func_001042C0(6);
    if (value2 != 0)
    {
        func_002F072C((s8 *) D_00580C58, (s8 *) value2);
    }
    value3 = func_001042C0(8);
    if (value3 != 0)
    {
        func_002F072C(D_00580C98, (s8 *) value3);
    }
    value4 = func_001042C0(0xC);
    if (value4 != 0)
    {
        func_002F072C(D_00580D98, (s8 *) value4);
    }
    value5 = func_001042C0(0xD);
    if (value5 != 0)
    {
        func_002F072C(D_00580CD8, (s8 *) value5);
    }
    func_0011AAB8(1 - func_001042E8(9));
}

void func_00122BF0(void)
{
    func_00104248(5, D_00580D18[0].b);
    func_00104248(7, D_00580D18[1].b);
    func_00104248(6, D_00580C58[0].b);
    func_00104248(8, D_00580C58[1].b);
    func_00104248(0xC, D_00580D18[2].b);
    func_00104248(0xD, D_00580C58[2].b);
}

void func_00122C68(s32 a)
{
    D_00308910 = a;
    func_001041C8(14, a);
}

s32 func_00122C80(void)
{
    return D_00308910;
}

Rec64 *func_00122C90(s32 which)
{
    if (which != 0) {
        return &D_00580C58[D_00308910];
    }
    return &D_00580D18[D_00308910];
}

void func_00122CC8(const char *s, int on)
{
    if (on) {
        func_002F072C(D_00580C58[D_00308910].b, s);
    } else {
        func_002F072C(D_00580D18[D_00308910].b, s);
    }
    func_00122BF0();
}

void func_00122D30(s8 v)
{
    D_00580DE0 = v;
}

s8 func_00122D40(void)
{
    return D_00580DE0;
}

void func_00122D50(void) {
}

INCLUDE_ASM("build/ee_asm/game/main/sg_1229D0", Sg_MapInit);

INCLUDE_ASM("build/ee_asm/game/main/sg_1229D0", func_00122F78);

void func_00123010(void)
{
    D_00308914 = (D_00308914 + 1) & 1;
}

INCLUDE_ASM("build/ee_asm/game/main/sg_1229D0", func_00123028);

INCLUDE_ASM("build/ee_asm/game/main/sg_1229D0", func_00123368);

INCLUDE_ASM("build/ee_asm/game/main/sg_1229D0", Sg_IdDrawMain);
