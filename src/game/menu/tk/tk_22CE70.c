/* tu_255 0x22ce70-0x22fb30: high; ~Tk (config/tu_map.tsv) */
#include "common.h"
#include "ffx/r5.h"
#include "ffx/q5.h"
#include "ffx/w7.h"
#include "ffx/s5.h"
#include "ffx/u3.h"
#include "ffx/v5.h"

void func_0022CE70(void)
{
    TkMn2GetCommonPlate(&D_00693B90, (int)D_005719D0, (int)D_005719E0, (int)D_005719F0, 0, 0);
    TkMn2GetCommonPlate(&D_00325A40, (int)D_00571A00, (int)D_00571A10, (int)D_00571A20, 0, 0);
    func_00227460(D_00571A30, D_00325A58);
    func_00227460(D_00571A40, D_00325A60);
    func_00227460(D_00571A50, D_00325A68);
    func_00227460(D_00571A60, D_00325A70);
    func_002273A0(D_00571A70, D_00693BF8);
    func_002273A0(D_00571A80, D_00693BD8);
    func_002273A0(D_00571A90, D_00693BE0);
    func_00227460(D_00571AA0, D_00693BE8);
    func_00227460(D_00571AA8, D_00693BA8);
    func_00227460(D_00571AB8, D_00693BB0);
    func_00227460(D_00571AC8, D_00693BB8);
    func_00227460(D_00571AD8, D_00693BC0);
    func_00227460(D_00571AE8, D_00693BC8);
    func_00227460(D_00571AF8, D_00693BD0);
    D_00693BC4 = V5_TkMn2SeqGetNum_int((int)D_00571B08);
}

void func_0022D008(Task *o)
{
    s32 *state = &o->state;
    u16 a;
    u16 b;
    u16 c;
    int n;
    int se;

    a = func_00220318();
    b = TOMenuGetControlPadRep();
    c = TOMenuGetControlPadTrg();
    func_00225500(1, &D_003258C8, &D_003258CC, &D_003258D0, &D_003258D4);
    TkMn2CalcStatusBGRatio();
    n = func_00242940();
    switch (o->state) {
    case 0:
        *state = 1;
    case 1:
        *state = 2;
    case 2:
        *state = 4;
        break;
    case 3:
        SET_ANGLE_I(-0x155);
        func_00227490(D_00571B18);
        *state = 4;
        break;
    case 4:
        if (n < 0x12) {
            if (n >= 0xE) {
                goto skip7;
            }
        }
        if (c & 0x20) {
            PLAY_SE(0x80000001);
            *state = 7;
            break;
        }
    skip7:
        if (c & 0x40) {
            PLAY_SE(0x80000004);
            *state = 0xF;
        }
        if (TkMenuGetSummonListMax() >= 2) {
            if (func_002429D0() != 0) {
                if ((b & 4) && a == 4) {
                    PLAY_SE(0x80000004);
                    func_00242B18();
                    TkMenuFlushSummonCommand(func_00242940());
                    return;
                } else if ((b & 8) && a == 8) {
                    PLAY_SE(0x80000004);
                    func_00242AE0();
                    TkMenuFlushSummonCommand(func_00242940());
                    return;
                }
            }
        }
        break;
    case 5:
        *state = 6;
        break;
    case 7:
        SET_ANGLE_I(0x155);
        func_00227480(D_00571B18);
        TkMenuOpenStatusPageWindow(1, 1, 0x42, 0);
        *state = 8;
        break;
    case 8:
        if (c & 0x20) {
            PLAY_SE(0x80000001);
            TkMenuCloseStatusPageWindow(1);
            *state = 9;
        } else if (c & 0x40) {
            PLAY_SE(0x80000004);
            TkMenuCloseStatusPageWindow(1);
            *state = 3;
        }
        break;
    case 9:
        TkMenuOpenStatusPageWindow(1, 2, 0x43, 0);
        *state = 10;
        break;
    case 10:
        if (c & 0x20) {
            PLAY_SE(0x80000001);
            TkMenuCloseStatusPageWindow(2);
            *state = 11;
        } else if (c & 0x40) {
            PLAY_SE(0x80000004);
            TkMenuCloseStatusPageWindow(2);
            *state = 3;
        }
        break;
    case 11:
        TkMenuOpenStatusPageWindow(1, 3, 0x47, 0);
        *state = 12;
        break;
    case 12:
        if (c & 0x20) {
            PLAY_SE(0x80000001);
            TkMenuCloseStatusPageWindow(3);
            *state = 13;
        } else if (c & 0x40) {
            PLAY_SE(0x80000004);
            TkMenuCloseStatusPageWindow(3);
            *state = 3;
        }
        break;
    case 13:
        TkMenuOpenStatusPageWindow(1, 4, 0x46, 0);
        *state = 14;
        break;
    case 14:
        if (c & 0x20) {
            se = 0x80000001;
        } else if (c & 0x40) {
            se = 0x80000004;
        } else {
            break;
        }
        PLAY_SE(se);
        TkMenuCloseStatusPageWindow(4);
        *state = 3;
        break;
    case 15:
        o->b45 = -1;
        *state = 16;
        break;
    case 6:
    case 16:
        break;
    }
}

void func_0022D3D8(void)
{
    int k = func_00242940();

    func_002492F0();
    func_002492F0();
    func_00225920();
    func_0022A768(0, 0, k, 1, &D_003258C8, &D_003258CC, &D_003258D0, &D_003258D4, 0x1000);
    func_0022A9A0(0, 0, k, 0x1000);
    ((void (*)(int, int, int, int, s32 *, s32 *, s32 *, s32 *))func_0022A728)(0, 0, k, 1, &D_003258C8, &D_003258CC, &D_003258D0, &D_003258D4); /* DEBT(TYPE): callee reads only the first four arguments */
    func_002297A0(func_00228B80(), 1);
    func_00225B00();
}

int func_0022D4C0(void) { return 1; }

INCLUDE_ASM("build/ee_asm/game/menu/tk/tk_22CE70", func_0022D4C8);

void func_0022D588(void)
{
    if (D_00693B7C) {
        TkMn2InitStatusBG();
        D_00693B7C->b41 = 1;
        D_00693B7C = 0;
        func_00227490(D_00571B70);
    }
}

INCLUDE_ASM("build/ee_asm/game/menu/tk/tk_22CE70", func_0022D5E0);

void func_0022D6C8(int a, int b, int c, int x, int y)
{
    int i;

    x += D_00693BD0[0];
    y += D_00693BD0[1];
    for (i = -1; i < 10; i++) {
        func_0022D5E0(a, x, y, i + c, b);
        graphicUiRemapY2_int();
        y += 0x20;
    }
}

void func_0022D768(Task *o, int a1, int a2) { func_002270F8(a1, a2 + ((o->x48 - o->x32) << 5), 0); }

INCLUDE_ASM("build/ee_asm/game/menu/tk/tk_22CE70", func_0022D790);

int func_0022DAE8(Task *t)
{
    SysEntry *e = SYS_TBL;

    e += t->x48;
    return e->b2 != 0;
}
int func_0022DB08(void) { return 1; }

INCLUDE_ASM("build/ee_asm/game/menu/tk/tk_22CE70", func_0022DB10);
INCLUDE_RODATA("build/ee_asm/game/menu/tk/tk_22CE70/rodata", jtbl_00571B80);

void func_0022DDC8(Task *t)
{
    func_002253E8(3);
    D_00693C00 = 0;
    t->x30 = func_002249A8();
}

Task *TkMn2OpenSummonGrowWindow(void)
{
    int two;
    int one;
    int three;
    int nine;
    Task *t = func_00243400();

    two = 2; /* DEBT(FAKE): early constant loads */
    t->x48 = 0;
    one = 1;
    t->x32 = 0;
    t->x34 = 0;
    t->cb = func_0022DDC8;
    t->x0C = (s32)func_0022DB10; /* DEBT(CAST): Task callbacks are typed s32 */
    t->x10 = (s32)func_0022D790;
    t->x14 = (s32)func_0022DB08;
    t->b3E = two;
    t->b42 = one;
    t->x30 = func_00227EA8();
    three = 3;
    nine = 9;
    t->b37 = 0;
    t->b36 = three;
    t->x3A = nine;
    t->x54 = 0xAA;
    TkMenuMainRegistWindow(t);
    D_00693B80 = t;
    TkMn2InitStatusBG();
    func_00227490(D_00571B68);
    func_00227480(D_00571BB0);
    return t;
}

void func_0022DEC8(void)
{
    if (D_00693B80 != 0) {
        TkMenuRestartSelFileWindow(D_00693B80);
    }
}

/* DEBT(CAST): string address passed to an int parameter */
void func_0022DEE8(void)
{
    Task *t = D_00693B80;

    if (t != 0) {
        t->b41 = 1;
        func_00227490((int)D_00571BB0);
    }
}

void func_0022DF10(Task *t)
{
    TkMn2CalcStatusBGRatio();
    TkMenuCtrlSelFileWindow(t);
    if (t->x48 < (u16)t->x30) {
        if (t->b45 == 0) {
            TkMenuSetHelpMessage(func_00220D18(D_00325900[t->x48].w4));
        }
    }
}

int func_0022DF88(u8 *base, FieldDesc *d, int sel)
{
    switch (d->kind) {
    case 4:
        return *(s32 *)(base + (sel ? d->h0C : d->h0E));
    case 1:
    default:
        return base[sel ? d->h0C : d->h0E];
    }
}

INCLUDE_ASM("build/ee_asm/game/menu/tk/tk_22CE70", func_0022DFD0);

void func_0022E158(int a, int b, int c, int x, int y)
{
    int i;

    x += D_00693BD0[0];
    y += D_00693BD0[1];
    for (i = -1; i < 10; i++) {
        func_0022DFD0(a, x, y, i + c, b);
        graphicUiRemapY2_int();
        y += 0x20;
    }
}

void func_0022E1F8(u8 *base, FieldDesc *d, int sel, int v)
{
    switch (d->kind) {
    case 4:
        *(s32 *)(base + (sel ? d->h0C : d->h0E)) = v;
        break;
    case 1:
    default:
        base[sel ? d->h0C : d->h0E] = v;
        break;
    }
}

int func_0022E240(int a0) {
    int base = TkMn2GetSummonGrow() + a0 * 8; /* DEBT(ORDER): temp fixes evaluation order */

    return base + func_00227EA8() * 8;
}

int func_0022E280(int x) {
    if (x < 1) {
        x = 1;
    }
    if (x > 99) {
        x = 99;
    }
    return x;
}

INCLUDE_ASM("build/ee_asm/game/menu/tk/tk_22CE70", func_0022E2A0);

s32 _m2c_func_0022E380_func_0022DF88(PartySlot *, R5Rec1C *, s32, s32) __asm__("func_0022DF88");
/* DEBT(CAST) */ /* DEBT(FAKE) */
s32 func_0022E380(s32 arg0, s32 arg1, s32 *arg2, s32 *arg3) {
    PartySlot *temp_18;
    R5Rec1C *temp_16;
    s32 temp_2;
    s32 var_21;
    void *p;
    register s32 temp_7 __asm__("$7");

    var_21 = 0;
    *arg2 = -1;
    *arg3 = 0;
    temp_18 = MsGetSavePlayerPtr(arg1);
    if (arg0 < 0xA) {
        p = (void *)func_0022E240(arg0);
        temp_16 = &D_00325900[arg0];
        temp_7 = (*(u16 *)((u8 *)(p) + (4)));
        __asm__("" : "+r"(temp_7));
        *arg2 = temp_7;
        temp_2 = _m2c_func_0022E380_func_0022DF88(temp_18, temp_16, 1, temp_7);
        if (temp_2 < (*(s32 *)((u8 *)(temp_16) + (0x14)))) {
            var_21 = 1;
            *arg3 = func_0022E280((*(s32 (**)(s32, s32))((u8 *)(temp_16) + (0x18)))(arg1, temp_2));
        } else {
            *arg3 = 0;
        }
    }
    return var_21;
}

INCLUDE_ASM("build/ee_asm/game/menu/tk/tk_22CE70", func_0022E468);

INCLUDE_ASM("build/ee_asm/game/menu/tk/tk_22CE70", func_0022E538);

void func_0022E7A0(void) {
}

int func_0022E7A8(void) { return 1; }

int func_0022E7B0(void) { return 1; }

INCLUDE_ASM("build/ee_asm/game/menu/tk/tk_22CE70", func_0022E7B8);

/* DEBT(CAST): string address passed to an int parameter */
void func_0022E8A8(void)
{
    Task *t = D_00693B84;

    if (t != 0) {
        t->b41 = 1;
        D_00693B84 = 0;
        func_00227490((int)D_00571BB0);
    }
}

void func_0022E8D8(void)
{
    if (D_00693B84 != 0) {
        TkMenuRestartSelFileWindow(D_00693B84);
    }
}

INCLUDE_ASM("build/ee_asm/game/menu/tk/tk_22CE70", TkMenuCtrlSummon);
INCLUDE_RODATA("build/ee_asm/game/menu/tk/tk_22CE70/rodata", jtbl_00571C20);

void func_0022F1E0(void) {
}

void func_0022F1E8(void) { func_0022CE70(); }

int func_0022F1F0(void) { return 1; }

INCLUDE_ASM("build/ee_asm/game/menu/tk/tk_22CE70", func_0022F1F8);

void func_0022F340(void)
{
    if (D_00693BEC >= 2) {
        func_00237818();
    }
    func_0022FB10();
    func_00227490(D_00571CB8);
    func_00227490(D_00571B70);
    func_00227490(D_00571B68);
    func_00227490(D_00571BB0);
}

void func_0022F3A0(void) {
}

void func_0022F3A8(Task *o)
{
    s32 *state = &o->state;
    u16 a;
    u16 b;
    u16 c;

    a = func_00220318();
    b = TOMenuGetControlPadRep();
    c = TOMenuGetControlPadTrg();
    func_00243508(o);
    func_00225500(1, &D_003258C8, &D_003258CC, &D_003258D0, &D_003258D4);
    switch (o->state) {
    case 0:
        ((int (*)(void))func_002369F0)(); /* DEBT(TYPE): int view of a void function */
        o->x54 = 0x155;
        *state = 1;
    case 1:
        if (o->x52 >= 0x1000) {
            if (TOMenuGetFirstReadEndFlag() != 0) {
                *state = 2;
            }
        }
    case 2:
        *state = 3;
        break;
    case 3:
        if (c & 0x20) {
            if (o->x1C != 0) {
                /* DEBT(CAST): x1C holds a callback typed s32 */
                if (((int (*)(Task *, int, int))o->x1C)(o, o->x48, o->b45) == 0) {
                    SndSepPlaySimple(0x80000003);
                    return;
                }
            }
            *state = 4;
        } else if (c & 0x40) {
            *state = 6;
        } else if (TkMenuGetSummonListMax() >= 2) {
            if ((b & 0x1000) || ((b & 4) && a == 4)) {
                PLAY_SE(0x80000001);
                func_00242B18();
                return;
            } else if ((b & 0x4000) || ((b & 8) && a == 8)) {
                PLAY_SE(0x80000001);
                func_00242AE0();
                return;
            }
        }
        break;
    case 4:
        o->b45 = 1;
        o->x54 = -0x155;
        *state = 5;
        break;
    case 6:
        o->b45 = -2;
        o->x54 = -0x155;
        *state = 7;
        break;
    case 5:
    case 7:
        break;
    }
}

INCLUDE_ASM("build/ee_asm/game/menu/tk/tk_22CE70", func_0022F5E8);

INCLUDE_ASM("build/ee_asm/game/menu/tk/tk_22CE70", func_0022F720);

INCLUDE_ASM("build/ee_asm/game/menu/tk/tk_22CE70", func_0022F810);

void func_0022F918(Task *t)
{
    int v;

    func_00242940();
    v = func_002292B8(t->x52, t->x54) * 0x180 / 4096;
    if (t->x54 < 0) {
        v = 0;
    }
    func_002492F0();
    func_002492F0();
    func_00225A38();
    func_00225920();
    func_00225E70(1);
    func_00229AC8(D_003258B0[0], D_003258B0[1], D_003258C8, D_003258CC, D_003258D0);
    func_0022F810(v, 0, t->b45);
    func_00225B00();
}

void func_0022F9D8(void) {
}

int func_0022F9E0(void) { return 1; }

int func_0022F9E8(void)
{
    u8 k = 0;
    int r;
    int ret;

    if (D_00326030 != 0) {
        k = D_00693B88[D_00326030->x48];
    }
    r = func_00242940();
    ret = 1;
    if (k == 1) {
        if (r >= 14) {
            ret = 0;
        }
    }
    return ret;
}

void func_0022FA48(void)
{
    Task *t = func_00243400();

    t->cb = func_0022F9D8;
    D_00693B78 = t;
    t->x0C = (s32)func_0022F3A8; /* DEBT(CAST): Task callbacks are typed s32 */
    t->x10 = (s32)func_0022F918;
    t->x14 = (s32)func_0022F9E0;
    t->x1C = (s32)func_0022F9E8;
    t->x54 = 0x155;
    TkMenuMainRegistWindow(t);
    func_00227480(D_00571CB8);
    func_00227480(D_00571B68);
}

void func_0022FAD0(void)
{
    if (D_00693B78) {
        if (D_00693BEC >= 2) {
            D_00693B78->state = 2;
        } else {
            D_00693B78->state = 0;
        }
        D_00693B78->b45 = 0;
        TkMn2InitStatusBG();
    }
}

void func_0022FB10(void)
{
    if (D_00693B78 != 0) {
        D_00693B78->b41 = 1;
        D_00693B78 = 0;
    }
}
