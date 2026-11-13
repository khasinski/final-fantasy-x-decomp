/* tu_258 0x232c88-0x234910: low; ~Tk (config/tu_map.tsv) */
#define func_00225E70 _hdr_func_00225E70
#include "common.h"
#include "ffx/r5.h"
#include "ffx/w7.h"
#include "ffx/q6.h"
#include "ffx/s5.h"
#include "ffx/u4.h"
#include "ffx/v5.h"
#undef func_00225E70

extern U4Id4 D_00325BA8;
extern U4Id4 D_00325BB0;

U4Id4 *func_00232C88(void)
{
    if (D_00693E20 < 0) {
        if (func_0020B850() == 0) {
            if (func_001BD360() == 0) {
                return &D_00325BA8;
            }
            return &D_00325BB0;
        }
        return &D_00325BB0;
    }
    if (func_0020B850() == 0) {
        if (func_001BD360() == 0) {
            return &D_00325B18[D_00693E20];
        }
        return &D_00325B18[D_00693E20];
    }
    return &D_00325B60[D_00693E20];
}

Pt16 *func_00232D30(void)
{
    if (func_0020B850() == 0) {
        if (func_001BD360() == 0) {
            if (D_00693E20 < 0) {
                return D_00325C20;
            }
            return D_00325BF0;
        }
        if (D_00693E20 < 0) {
            return D_00325C38;
        }
        return D_00325BD8;
    }
    if (D_00693E20 < 0) {
        return D_00325C38;
    }
    return D_00325BD8;
}

void func_00232DB8(void)
{
    TkMn2GetCommonPlate(&D_00693F18, D_00572080, D_00572090, D_00572090, 0xDA, 0xDB);
    TkMn2GetCommonPlate(&D_00693F30, D_005720A0, D_005720B0, D_005720C0, 0, 0);
    TkMn2GetCommonPlate(&D_00693F48, D_005720D0, D_005720E0, D_005720E0, 0, 0);
    D_00693ED4 = V5_TkMn2SeqGetNum_int(D_005720F0);
    D_00693EEC = V5_TkMn2SeqGetNum_int(D_00572100);
    D_00693EF0 = V5_TkMn2SeqGetNum_int(D_00572110);
    D_00693EE4 = TkMn2SeqGetColor(D_00572120);
    func_00227460(D_00572130, D_00693EC8);
    func_00227460(D_00572140, &D_00693ED0);
    func_00227460(D_00572150, D_00693EE0);
    func_00227460(D_00572160, D_00693EE8);
    func_00227460(D_00572170, D_00693EF8);
    func_00227460(D_00572180, D_00693F00);
    func_00227460(D_00572190, D_00693F08);
    func_00227460(D_005721A0, D_00693F10);
    func_002273A0(D_005721A8, D_00693ED8);
}

void func_00232F48(void)
{
    u8 buf[4];
    u8 *p;
    u8 c;
    int i;

    if (D_00693E20 >= 0) {
        p = (u8 *)MsGetSaveChrName(D_00693E20);
    } else {
        p = (u8 *)func_00124828() + 0xEC;
    }
    i = 0;
    for (c = D_00693E48[0].on; c != 0; c = D_00693E48[i].on) {
        if (D_00693E20 >= 0 && func_0020B850() == 0 && func_001BD360() == 0) {
            *(s32 *)buf = 0;
            func_0014D610((int)&D_00693E48[i], buf);
            i++;
            *p++ = buf[0];
        } else {
            *p++ = c;
            if (c >= 6 && c <= 47) {
                *p++ = D_00693E48[i].b1;
            }
            i++;
        }
    }
    *p = 0;
}

void func_00233060(int a)
{
    u8 *s = (u8 *)a; /* DEBT(TYPE): string address passed as int */
    int i = 0;
    int c;

    for (c = *s++; c != 0; c = *s++, i++) {
        if (c >= 6 && c <= 46) {
            D_00693E48[i].on = c;
            D_00693E48[i].b1 = *s++;
            D_00693E48[i].b2 = 0;
        } else {
            D_00693E48[i].on = c;
            D_00693E48[i].b1 = 0;
        }
    }
    for (; i < 32; i++) {
        D_00693E48[i].on = 0;
    }
}

void func_00233110(int i)
{
    if (i >= 0) {
        if (func_0020B850() == 0) {
            func_00233060(TOMenuGetNameMes(D_00325B18[i].id));
        } else {
            func_00233060(TOMenuGetNameMes(D_00325B60[i].id));
        }
    }
}

void func_00233198(void) {
}

void func_002331A0(void) {
}

void func_002331A8(void)
{
    func_002492F0();
    func_002492F0();
    func_00225A38();
    ((void (*)(void))func_00225920)();
    func_002297A0(func_00228B80(), 4);
    if (D_00693E20 >= 0) {
        if (D_00693E20 < 8) {
            func_00225E70(0);
            func_002299A8(D_00693EC8[0], D_00693EC8[1], D_003258C8, D_003258CC, D_003258D0);
        } else {
            func_00225E70(1);
            func_00229BE8(D_00693EC8[0], D_00693EC8[1], D_003258C8, D_003258CC, D_003258D0);
        }
    }
    func_00225B00();
}

int func_00233278(void) { return 1; }

Task *func_00233280(int a)
{
    Task *t = func_00243400();

    t->cb = func_00233198;
    t->x0C = (s32)func_002331A0; /* DEBT(TYPE): Task callback slots are typed s32 */
    t->x10 = (s32)func_002331A8;
    t->x14 = (s32)func_00233278;
    t->b3E = 3;
    t->ext[0] = a;
    TkMenuMainRegistWindow(t);
    D_003258CC = a;
    D_003258D0 = a;
    D_003258D4 = a;
    D_003258C8 = 0;
    return t;
}

void func_00233318(void) {
}

void func_00233320(void) {
}

void func_00233328(int a, int x, int y) {
    if (D_00693E38 == 1) {
        x += D_00693F18.x;
        y += D_00693F18.y;
        func_002270F8(x + D_00693ED0.x, y + D_00693ED0.y + D_00693E34 * D_00693ED4, 0);
    }
}

INCLUDE_ASM("build/ee_asm/game/menu/tk/tk_232C88", func_00233398);

int func_00233518(void) { return 1; }

int func_00233520(int a0, int a1)
{
    if (a1 == 4) {
        return D_00693E48[0].on != 0;
    } else if (a1 == 3) {
        if (D_00693E20 < 0) {
            return 1;
        }
        return D_00693E48[0].on != 0;
    }
    return 1;
}

Task *func_00233560(void) {
    Task *t = func_00243400();

    t->cb = func_00233318;
    t->x0C = (s32)func_00233320; /* DEBT(CAST): Task callbacks are typed s32 */
    t->x10 = (s32)func_00233398;
    t->x14 = (s32)func_00233518;
    t->x1C = (s32)func_00233520;
    t->b3E = 3;
    TkMenuMainRegistWindow(t);
    return t;
}

void func_002335D8(void) {
}

extern u16 _m2c_func_002335E0_D_00325C98 __asm__("D_00325C98");
extern u16 _m2c_func_002335E0_D_00325CC0 __asm__("D_00325CC0");
extern u16 _m2c_func_002335E0_D_00325D00 __asm__("D_00325D00");
extern s32 _m2c_func_002335E0_D_00325D28 __asm__("D_00325D28");
extern s32 _m2c_func_002335E0_D_00693E24 __asm__("D_00693E24");
/* DEBT(CAST) */
s32 func_002335E0(void) {
    s32 var_4;
    u16 *var_3;

    if (func_0020B850() == 0) {
        if (func_001BD360() == 0) {
            if (D_00693E20 < 0) {
                var_3 = *(s32 *)((_m2c_func_002335E0_D_00693E24 * 4) + ((void *)&_m2c_func_002335E0_D_00325D28));
            } else {
                var_3 = &_m2c_func_002335E0_D_00325C98;
            }
        } else {
            var_3 = &_m2c_func_002335E0_D_00325D00;
        }
    } else {
        var_3 = &_m2c_func_002335E0_D_00325CC0;
    }
    var_4 = 0;
    if (*var_3 != 0) {
        do {
            var_3 = (u16 *)((u8 *)var_3 + (2));
            var_4 += 1;
        } while (*var_3 != 0);
    }
    return var_4 / 3;
}

int func_00233698(void) {
    Pt16 *p = func_00232D30();
    int n;

    for (n = 0; p->x != 0; p++) {
        n++;
    }
    return n;
}

void func_002336E8(int a, int b) {
    D_00693E30 = a + b * 15;
}

INCLUDE_ASM("build/ee_asm/game/menu/tk/tk_232C88", func_00233700);

void func_00233890(void)
{
    int i = 0;

    do {
        if (D_00693E48[i].on == 0) {
            break;
        }
        i++;
    } while (1);
    if (i != 0) {
        i--;
        D_00693E48[i].on = 0;
    }
}

INCLUDE_ASM("build/ee_asm/game/menu/tk/tk_232C88", func_002338D0);
INCLUDE_RODATA("build/ee_asm/game/menu/tk/tk_232C88/rodata", jtbl_005721C0);
INCLUDE_RODATA("build/ee_asm/game/menu/tk/tk_232C88/rodata", jtbl_005721F0);

INCLUDE_ASM("build/ee_asm/game/menu/tk/tk_232C88", func_00234100);

INCLUDE_ASM("build/ee_asm/game/menu/tk/tk_232C88", func_002341E8);

INCLUDE_ASM("build/ee_asm/game/menu/tk/tk_232C88", func_00234428);

void func_00234628(int a)
{
    DrawArgs box;

    func_002492F0();
    func_002492F0();
    func_00225A38();
    ((void (*)(void))func_00225920)(); /* DEBT(CAST): the original call site sees a void declaration */
    box = D_00693F30;
    func_00226FE0(&box);
    func_002341E8(a);
    func_00234428(a);
    func_00234100(a, 0, 0);
    func_00225B00();
}

int func_002346D0(void) { return 1; }

INCLUDE_ASM("build/ee_asm/game/menu/tk/tk_232C88", func_002346D8);

void func_002348D8(void)
{
    if (D_00693E40->h30 != 0) {
        TkMenuMainSleepMenu(0xE);
        func_00201CD0();
    }
}
