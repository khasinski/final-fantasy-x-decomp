/* tu_238 0x210340-0x212ea8: low; ~TOBtlInitAnm (config/tu_map.tsv) */
#include "common.h"
#include "ffx/g3.h"
#include "ffx/q5.h"
#include "ffx/w6.h"
#include "ffx/r4.h"
#include "ffx/t4.h"
#include "ffx/u3.h"
#include "ffx/s4.h"

void TOBtlInitAnm(void)
{
    D_00690298 = 1;
}

int func_00210350(void)
{
    return -1;
}

void func_00210358(R4Task *o)
{
    o->f88 = func_00212EB0;
    o->f8C = func_00212ED8;
    o->f90 = func_00212EF8;
    o->f84 = 0;
    o->f80 = func_00212F08;
}

void TOBtlSetCallback(R4Task *o)
{
    switch (o->h6) {
    case 0:
        if (MsCheckLeftWindow(o->h8) > 0 && D_00690298 == 1) {
            o->f88 = func_00212F30;
        } else {
            o->f88 = func_00210898;
        }
        o->f8C = func_002109C0;
        o->f90 = func_00210A10;
        o->f84 = 0;
        o->f80 = func_00210A38;
        break;
    case 13:
        o->f88 = func_002114A0;
        o->f8C = func_002114D8;
        o->f90 = func_002114F8;
        o->f84 = 0;
        o->f80 = func_00211520;
        break;
    case 12:
        o->f88 = func_00210D18;
        o->f8C = func_00210D50;
        o->f90 = func_00210D70;
        o->f84 = 0;
        o->f80 = func_00210D98;
        break;
    case 1:
    case 2:
    case 3:
    case 4:
    case 14:
        o->f88 = func_00211C38;
        o->f8C = func_00211C70;
        o->f90 = func_00211C90;
        o->f84 = 0;
        o->f80 = func_00211CB8;
        break;
    case 6:
    case 17:
        o->f88 = func_00211C38;
        o->f8C = func_00211C70;
        o->f90 = func_00211C90;
        o->f84 = 0;
        o->f80 = func_00211CB8;
        break;
    case 7:
    case 15:
        o->f88 = func_002124F8;
        o->f8C = func_00212530;
        o->f90 = func_00212550;
        o->f84 = 0;
        o->f80 = func_00212578;
        break;
    case 5:
        o->f88 = func_00212338;
        o->f8C = func_00212370;
        o->f90 = func_00212390;
        o->f84 = 0;
        o->f80 = func_002123B8;
        break;
    case 10:
        o->f84 = func_00214210;
        o->f88 = func_002142E8;
        o->f8C = func_002142F0;
        o->f90 = func_00214310;
        o->f80 = func_00214320;
        break;
    case 20:
        o->f88 = func_00212640;
        o->f8C = func_00212678;
        o->f90 = func_00212698;
        o->f84 = 0;
        o->f80 = func_002126C0;
        break;
    case 21:
    case 22:
        if (o->hC == 0x3024) {
            func_00212888(100000);
        } else {
            func_00212888(-1);
        }
        o->f88 = func_00212938;
        o->f8C = func_00212970;
        o->f90 = func_00212BD0;
        o->f84 = 0;
        o->f80 = func_00212BF8;
        break;
    }
}

INCLUDE_ASM("build/ee_asm/game/menu/to/to_210340", func_002105D0);
INCLUDE_RODATA("build/ee_asm/game/menu/to/to_210340/rodata", jtbl_00570B30);

INCLUDE_ASM("build/ee_asm/game/menu/to/to_210340", func_00210898);

int func_002109C0(void *o)
{
    if (D_00690298 == 1) {
        func_002D70D8(2);
        D_00690298 = 0;
    }
    _TOBtlGetMainPad(o);
    return 1;
}

int func_00210A10(void)
{
    func_0020DBC8(2);
    return 1;
}

int func_00210A30(void)
{
    return 0;
}

INCLUDE_ASM("build/ee_asm/game/menu/to/to_210340", func_00210A38);

int func_00210D10(void)
{
    return 0;
}

/* DEBT(CAST): message strings are passed to int parameters (prototype not yet typed) */
int func_00210D18(void)
{
    TOSeqStartScene(2, D_00570C08);
    TOSeqStartScene(2, D_00570C10);
    return 1;
}

int func_00210D50(void)
{
    _TOBtlGetLeftPad();
    return 0;
}

int func_00210D70(void)
{
    func_0020DBC8(2);
    return 1;
}

int func_00210D90(void)
{
    return 0;
}

INCLUDE_ASM("build/ee_asm/game/menu/to/to_210340", func_00210D98);

int func_00210F58(void)
{
    return 0;
}

INCLUDE_ASM("build/ee_asm/game/menu/to/to_210340", _TOBtlGetLeftPad);

/* DEBT(CAST): message strings are passed to int parameters (prototype not yet typed) */
int func_002114A0(void)
{
    TOSeqStartScene(2, D_00570C20);
    TOSeqStartScene(2, D_00570C28);
    return 1;
}

int func_002114D8(void)
{
    _TOBtlGetRightPad();
    return 0;
}

int func_002114F8(void)
{
    func_0020DBC8(2);
    return 1;
}

int func_00211518(void)
{
    return 0;
}

INCLUDE_ASM("build/ee_asm/game/menu/to/to_210340", func_00211520);

int func_002116E0(void)
{
    return 0;
}

INCLUDE_ASM("build/ee_asm/game/menu/to/to_210340", _TOBtlGetRightPad);

int func_00211C28(void)
{
    return 0;
}

int func_00211C30(void)
{
    return 0;
}

/* DEBT(CAST): message strings are passed to int parameters (prototype not yet typed) */
int func_00211C38(void)
{
    TOSeqStartScene(2, D_00570C38);
    TOSeqStartScene(2, D_00570C40);
    return 1;
}

int func_00211C70(void)
{
    _TOBtlGetStdPad();
    return 0;
}

int func_00211C90(void)
{
    func_0020DBC8(2);
    return 1;
}

int func_00211CB0(void)
{
    return 0;
}

INCLUDE_ASM("build/ee_asm/game/menu/to/to_210340", func_00211CB8);

int func_00211E78(void)
{
    return 0;
}

INCLUDE_ASM("build/ee_asm/game/menu/to/to_210340", func_00211E80);
INCLUDE_RODATA("build/ee_asm/game/menu/to/to_210340/rodata", jtbl_00570C50);

void func_00212288(int p, int x, int y)
{
    func_001FA7D0(x, y, D_0032435C, D_0032435E);
    TOMkpEasyMesFontLCenter(func_0021F940(p), x + D_0032435C / 2, y + D_00324364);
    TOBtlDrawParamPlate(p, x + D_0032436A, y + D_0032436C);
}

/* DEBT(CAST): message strings are passed to int parameters (prototype not yet typed) */
int func_00212338(void)
{
    TOSeqStartScene(2, D_00570C38);
    TOSeqStartScene(2, D_00570C40);
    return 1;
}

int func_00212370(void)
{
    _TOBtlGetStdPad();
    return 1;
}

int func_00212390(void)
{
    func_0020DBC8(2);
    return 1;
}

int func_002123B0(void)
{
    return 0;
}

INCLUDE_ASM("build/ee_asm/game/menu/to/to_210340", func_002123B8);

int func_002124F0(void)
{
    return 0;
}

/* DEBT(CAST): message strings are passed to int parameters (prototype not yet typed) */
int func_002124F8(void)
{
    TOSeqStartScene(2, D_00570C38);
    TOSeqStartScene(2, D_00570C40);
    return 1;
}

int func_00212530(void)
{
    _TOBtlGetStdPad();
    return 1;
}

int func_00212550(void)
{
    func_0020DBC8(2);
    return 1;
}

int func_00212570(void)
{
    return 0;
}

INCLUDE_ASM("build/ee_asm/game/menu/to/to_210340", func_00212578);

int func_00212638(void)
{
    return 0;
}

/* DEBT(CAST): message strings are passed to int parameters (prototype not yet typed) */
int func_00212640(void)
{
    TOSeqStartScene(2, D_00570C38);
    TOSeqStartScene(2, D_00570C40);
    return 1;
}

int func_00212678(void)
{
    _TOGetPadStatusPrepare();
    return 1;
}

int func_00212698(void)
{
    func_0020DBC8(2);
    return 1;
}

int func_002126B8(void)
{
    return 0;
}

INCLUDE_ASM("build/ee_asm/game/menu/to/to_210340", func_002126C0);

int func_00212880(void)
{
    return 0;
}

void func_00212888(int n)
{
    char buf[0x10];
    s32 max;

    func_002EF0D0(&D_006902A0, 0, 0x1C);
    max = MsGetGIL();
    D_006902A0.w8 = max;
    if (n < 0 || max < n) {
        D_006902A0.wC = max;
    } else {
        D_006902A0.wC = n;
    }
    D_006902A0.w14 = D_006902A0.w8;
    D_006902A0.w10 = 0;
    D_006902A0.h6 = 0;
    D_006902A0.h4 = 0;
    func_002F0008(buf, D_00570C90, D_006902A0.wC);
    D_006902A0.h2 = func_002F0840(buf) - 1;
    D_00325670 = 0;
}

/* DEBT(CAST): message strings are passed to int parameters (prototype not yet typed) */
int func_00212938(void)
{
    TOSeqStartScene(2, D_00570C38);
    TOSeqStartScene(2, D_00570C40);
    return 1;
}

INCLUDE_ASM("build/ee_asm/game/menu/to/to_210340", func_00212970);

int func_00212BD0(void)
{
    func_0020DBC8(2);
    return 1;
}

int func_00212BF0(void)
{
    return 0;
}

INCLUDE_ASM("build/ee_asm/game/menu/to/to_210340", func_00212BF8);
