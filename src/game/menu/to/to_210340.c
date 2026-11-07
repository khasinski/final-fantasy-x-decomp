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

void _m2c_func_002123B8_func_00211E80() __asm__("func_00211E80");
void _m2c_func_002123B8_func_00212288(s16, s16, s32) __asm__("func_00212288");
extern s16 _m2c_func_002123B8_D_00324358 __asm__("D_00324358");
extern s16 _m2c_func_002123B8_D_00324360 __asm__("D_00324360");
/* DEBT(CAST) */ /* DEBT(FAKE) */
s32 func_002123B8(void *arg0) {
    s16 temp_2;
    s16 temp_5;
    register s32 temp_7 __asm__("$7");
    register s32 rem __asm__("$8");
    register s32 h40 __asm__("$6");
    s32 h70;
    s32 h72;
    _m2c_func_002123B8_func_00211E80();
    TODrawScissorXYWH(0, 0, 0x1FF, 0x19F);
    temp_5 = *(s32 *)(((*(s16 *)((u8 *)(arg0) + (0x42))) * 2) + (*(s32 *)((u8 *)(arg0) + (0x20))));
    if (temp_5 == 0x30FF) {
        _m2c_func_002123B8_func_00212288(0xF, _m2c_func_002123B8_D_00324358, 0xB4);
        _m2c_func_002123B8_func_00212288(0x10, _m2c_func_002123B8_D_00324358, _m2c_func_002123B8_D_00324360 + 0xB4);
        _m2c_func_002123B8_func_00212288(0x11, _m2c_func_002123B8_D_00324358, (_m2c_func_002123B8_D_00324360 * 2) + 0xB4);
    } else {
        _m2c_func_002123B8_func_00212288(temp_5, _m2c_func_002123B8_D_00324358, (_m2c_func_002123B8_D_00324360 * 2) + 0xB4);
    }
    temp_7 = (s16) ((*(s16 *)((u8 *)(arg0) + (0x38))));
    temp_2 = (*(s16 *)((u8 *)(arg0) + (0x42)));
    rem = temp_2 % temp_7;
    h40 = (*(s16 *)((u8 *)(arg0) + (0x40)));
    h70 = (*(s16 *)((u8 *)(arg0) + (0x70)));
    h72 = (*(s16 *)((u8 *)(arg0) + (0x72)));
    func_0021F448(0, (s16) (h70 + (rem * ((*(s16 *)((u8 *)(arg0) + (0x62))) + 0x10))), (s16) (h72 + (((temp_2 - h40) / temp_7) * 0x14)));
    return 0;
}

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

void _m2c_func_00212578_TOBtlDrawWeaponAbilityWindow(s16, s32, s32) __asm__("TOBtlDrawWeaponAbilityWindow");
void _m2c_func_00212578_func_00211E80() __asm__("func_00211E80");
/* DEBT(CAST) */ /* DEBT(FAKE) */
s32 func_00212578(void *arg0) {
    s16 temp_2;
    s16 temp_2_2;
    register s32 temp_7 __asm__("$7");
    register s32 rem __asm__("$8");
    register s32 h40 __asm__("$6");
    s32 h70;
    s32 h72;
    _m2c_func_00212578_func_00211E80();
    temp_7 = (s16) ((*(s16 *)((u8 *)(arg0) + (0x38))));
    temp_2 = (*(s16 *)((u8 *)(arg0) + (0x42)));
    rem = temp_2 % temp_7;
    h40 = (*(s16 *)((u8 *)(arg0) + (0x40)));
    h70 = (*(s16 *)((u8 *)(arg0) + (0x70)));
    h72 = (*(s16 *)((u8 *)(arg0) + (0x72)));
    func_0021F448(0, (s16) (h70 + (rem * ((*(s16 *)((u8 *)(arg0) + (0x62))) + 0x10))), (s16) (h72 + (((temp_2 - h40) / temp_7) * 0x14)));
    temp_2_2 = *(s32 *)(((*(s16 *)((u8 *)(arg0) + (0x42))) * 2) + (*(s32 *)((u8 *)(arg0) + (0x20))));
    if (temp_2_2 != 0xFF) {
        _m2c_func_00212578_TOBtlDrawWeaponAbilityWindow(temp_2_2, (*(s16 *)((u8 *)(arg0) + (0x6C))) + 0x14, 0x16D);
    }
    return 0;
}

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
