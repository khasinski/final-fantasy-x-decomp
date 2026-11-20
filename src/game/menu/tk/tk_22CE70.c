/* tu_255 0x22ce70-0x22fb30: high; ~Tk (config/tu_map.tsv) */
#define func_0022F720 _hdr_func_0022F720
#include "common.h"
#include "ffx/r5.h"
#include "ffx/q5.h"
#include "ffx/w7.h"
#include "ffx/s5.h"
#include "ffx/u3.h"
#include "ffx/v5.h"
#undef func_0022F720

void func_0022CE70(void)
{
    TkMn2GetCommonPlate(&D_00693B90, D_005719D0, D_005719E0, D_005719F0, 0, 0);
    TkMn2GetCommonPlate(&D_00325A40, D_00571A00, D_00571A10, D_00571A20, 0, 0);
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
    D_00693BC4 = V5_TkMn2SeqGetNum_int(D_00571B08);
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

extern s16 D_00325878[2];
void func_00226D88(int x, int y, int k);

void func_0022D5E0(int a, int x, int y, int i, int b)
{
    Task *t = (Task *)a;

    if (b == 0) {
        y -= t->x46 / 128;
    }
    if (i >= 0 && i < (u16)t->x30) {
        SysEntry *e;

        func_00226D88(x, y, 0x10);
        ((int (*)(int, int, int))func_00226E10)(x + D_00325878[0] + 0x58, y + D_00325878[1], 0xD7);
        e = SYS_TBL;
        e += i;
        if (e->b2 != 0) {
            func_00226770(e->h0, x, y, e->b2 != 4);
        }
    }
}

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

typedef struct {
    s16 rect[4];
    s32 w8;
    s32 wC;
} Box16;

void func_00226FE0(DrawArgs *a);
void func_002277F8(int x, int y, int id, int a3, int a4);
void func_002274A0(int y, int h, int mode, int a3);
void func_00225E88(int a, int b, int c, int d, int e, int f, int g);

void func_0022D790(Task *t)
{
    FlagRec box;
    s32 chr;
    SysEntry *e;
    s32 item;
    u8 cnt;
    int x;
    s16 y;

    func_00225A38();
    chr = func_00242940();
    e = SYS_TBL;
    e += t->x48;
    if (e->b2 != 0) {
        u8 *g = (u8 *)TkMn2GetSummonGrow() + e->b3 * 8;
        item = *(u16 *)(g + 4);
        cnt = g[6];
    } else {
        item = -1;
        cnt = 0;
    }
    if (item >= 0) {
        func_002277F8(D_00325A40.rect[0], D_00325A40.rect[1], item, cnt, 0);
    }
    func_0022A768(0, 0, chr, 3, &D_003258C8, &D_003258CC, &D_003258D0, &D_003258D4, 0x1000);
    /* DEBT(CAST): header declares fewer args for func_0022A728 */
    ((int (*)(int, int, int, int, s32 *, s32 *, s32 *, s32 *))func_0022A728)(0, 0, chr, 3, &D_003258C8, &D_003258CC, &D_003258D0, &D_003258D4);
    func_00226210(D_00693BD8[0], D_00693BD8[1], 0xF);
    if (item >= 0) {
        func_00226210(D_00693BE0[0], D_00693BE0[1], 0x10);
    }
    y = D_00693BD0[1];
    if (t->x32 == t->x34) {
        func_002274A0(y, 0x120, 0, t->x46);
        func_0022D6C8((int)t, 0, t->x32, 0, -0x20);
    } else {
        func_002274A0(y, 0x120, 1, t->x46);
        func_0022D6C8((int)t, 1, t->x32, 0, -0x20);
        func_002274A0(y, 0x120, 2, t->x46);
        func_0022D6C8((int)t, 2, t->x34, 0, -(t->x46 * 0x120) / 0x1000 - 0x20);
    }
    func_00225908();
    func_0022D768(t, D_00693BD0[0] + 0xC, D_00693BD0[1] + 1);
    func_00225E88(D_00693BF8[0], D_00693BF8[1], D_00693BF8[2], D_00693BF8[3], t->x32, *(u16 *)((u8 *)t + 0x3A), (u16)t->x30);
    x = 0x1E0 - func_00226AD0((void *)TOMenuGetSummonMes(5));
    x -= D_003258A8[0];
    box.rect[1] = D_00325888.rect[1];
    box.rect[3] = D_00325888.rect[3];
    box.rect[2] = 0x200 - x;
    box.x08 = D_00325888.x08;
    box.x0C = D_00325888.x0C;
    box.rect[0] = x;
    func_00226FE0((DrawArgs *)&box);
    ((int (*)(int, int, int))func_00226E10)(box.rect[0] + D_003258A0[0], box.rect[1] + D_003258A0[1], 0xF3);
    func_00226350(box.rect[0] + D_003258A8[0], box.rect[1] + D_003258A8[1], TOMenuGetSummonMes(5), 0);
    func_002297A0(func_00228B80(), 1);
    func_00225B00();
}

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

void func_0022DEE8(void)
{
    Task *t = D_00693B80;

    if (t != 0) {
        t->b41 = 1;
        func_00227490(D_00571BB0);
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

void func_0022E2A0(int a0, int a1)
{
    PartySlot *chr = MsGetSavePlayerPtr(a1);
    u8 *p;
    R5Rec1C *d;
    int n;
    u32 val;

    if (a0 < 10) {
        p = (u8 *)func_0022E240(a0);
        d = &D_00325900[a0];
        n = func_0022E280((*(s32 (**)(s32, s32))((u8 *)d + 0x18))(a1, func_0022DF88((u8 *)chr, (FieldDesc *)d, 1)));
        MsSaveItemUse(*(u16 *)(p + 4), -n);
        val = func_0022DF88((u8 *)chr, (FieldDesc *)d, 0) + p[6];
        if (val > *(u32 *)((u8 *)d + 0x14)) {
            val = *(u32 *)((u8 *)d + 0x14);
        }
        func_0022E1F8((u8 *)chr, (FieldDesc *)d, 0, val);
    }
    TkMsSetSaveParam(a1);
}

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

void func_0022E468(int a0)
{
    extern s32 D_00693BF0, D_00693BF4;
    int sp0;
    int sp4;
    int i;
    int ok;

    D_00693BF0 = 0;
    D_00693BF4 = 0;
    for (i = 0; i < 10; i++) {
        ok = func_0022E380(i, a0, &sp0, &sp4);
        if (func_001BFE30(sp0) >= sp4) {
            D_00693BF4 |= 1 << i;
            if (ok != 0) {
                D_00693BF0 |= 1 << i;
            }
        }
    }
}

void func_0022E538(Task *t)
{
    FlagRec box; /* DEBT(PADDING): unused local matching original stack frame size */
    s32 item;
    s32 cnt;
    s32 chr;
    s16 y;

    func_00225A38();
    chr = func_00242940();
    func_0022E380(t->x48, chr, &item, &cnt);
    if (item >= 0) {
        func_002277F8(D_00325A40.rect[0], D_00325A40.rect[1], item, cnt, 0);
    }
    func_0022A768(0, 0, chr, 3, &D_003258C8, &D_003258CC, &D_003258D0, &D_003258D4, 0x1000);
    /* DEBT(CAST): header declares fewer args for func_0022A728 */
    ((int (*)(int, int, int, int, s32 *, s32 *, s32 *, s32 *))func_0022A728)(0, 0, chr, 3, &D_003258C8, &D_003258CC, &D_003258D0, &D_003258D4);
    func_00226210(D_00693BD8[0], D_00693BD8[1], 0x11);
    if (item >= 0) {
        func_00226210(D_00693BE0[0], D_00693BE0[1], 0x10);
    }
    y = D_00693BD0[1];
    if (t->x32 == t->x34) {
        func_002274A0(y, 0x120, 0, t->x46);
        func_0022E158((int)t, 0, t->x32, 0, -0x20);
    } else {
        func_002274A0(y, 0x120, 1, t->x46);
        func_0022E158((int)t, 1, t->x32, 0, -0x20);
        func_002274A0(y, 0x120, 2, t->x46);
        func_0022E158((int)t, 2, t->x34, 0, -(t->x46 * 0x120) / 0x1000 - 0x20);
    }
    func_00225908();
    func_0022D768(t, D_00693BD0[0] + 0xC, D_00693BD0[1] + 1);
    func_00225E88(D_00693BF8[0], D_00693BF8[1], D_00693BF8[2], D_00693BF8[3], t->x32, *(u16 *)((u8 *)t + 0x3A), (u16)t->x30);
    func_002297A0(func_00228B80(), 1);
    func_00225B00();
}

void func_0022E7A0(void) {
}

int func_0022E7A8(void) { return 1; }

int func_0022E7B0(void) { return 1; }

Task *func_0022E7B8(void)
{
    int two;
    int one;
    int k = func_00242940();
    Task *t = func_00243400();

    two = 2;
    t->x48 = 0;
    one = 1;
    t->x32 = 0;
    t->x34 = 0;
    t->cb = func_0022E7A0;
    t->x0C = (s32)func_0022DF10;
    t->x10 = (s32)func_0022E538;
    t->x14 = (s32)func_0022E7A8;
    t->b3E = two;
    t->x1C = (s32)func_0022E7B0;
    t->b42 = one;
    t->x30 = 10;
    t->b36 = 3;
    t->x3A = 9;
    t->b37 = 0;
    t->b45 = 0;
    t->x54 = 0xAA;
    TkMenuMainRegistWindow(t);
    D_00693B84 = t;
    TkMn2InitStatusBG();
    func_0022E468(k);
    func_00227490(D_00571B68);
    func_00227480(D_00571BB0);
    return t;
}

void func_0022E8A8(void)
{
    Task *t = D_00693B84;

    if (t != 0) {
        t->b41 = 1;
        D_00693B84 = 0;
        func_00227490(D_00571BB0);
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

void func_002375F8(int a, int *b, int *c, int d, int e);
void func_00237690(void);
void func_00237790(int a);

void func_0022F1F8(Task *t)
{
    int vals[4];
    int maxs[4];
    int n = 1;

    t->x1C = 0;
    vals[0] = func_00249520(0);
    maxs[0] = func_002497A8(0);
    D_00693B88[0] = 0;
    if (MsImportantGet(0xA01E) != 0 || MsImportantGet(0xA022) != 0) {
        vals[n] = func_00249520(1);
        maxs[n] = func_002497A8(1);
        D_00693B88[n] = 1;
        n++;
    }
    if (MsImportantGet(0xA01F) != 0) {
        vals[n] = func_00249520(2);
        maxs[n] = func_002497A8(2);
        D_00693B88[n] = 2;
        n++;
    }
    D_00693BEC = n;
    if (n >= 2) {
        func_002375F8((int)func_0022F1F0, vals, maxs, n, 1);
        func_00237690();
        func_00237790(0);
    }
    D_003258C8 = 0;
    D_003258CC = func_00242970();
    D_003258D0 = func_00242970();
    D_003258D4 = func_00242970();
}

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

void func_00226FE0(DrawArgs *a);
u8 func_00242798(int i);

void func_0022F5E8(int x, int y, int id)
{
    FlagRec box;
    PartySlot *p = MsGetSavePlayerPtr(id);
    int dx, dy;

    box = D_00693B90;
    box.rect[0] = D_00693BA8[0] + x;
    box.rect[1] = D_00693BA8[1] + y;
    func_00226FE0((DrawArgs *)&box);
    dx = D_00693BB0[0] + box.rect[0];
    dy = D_00693BB0[1] + box.rect[1];
    func_00226350(dx, dy, func_002494E8(0x18), 0x53);
    dx = D_00693BB8[0] + box.rect[0];
    dy = D_00693BB8[1] + box.rect[1];
    TkMn2SetMacroParam(4, 1, ((u8 *)p)[0x3D]);
    func_00226400(dx, dy, func_002494E8(0x19), 0);
}

void func_0022F720(int x, int y, int id)
{
    int hp = TkMenuGetHP(id);
    int st = func_00242C58(id);
    int flag = 0;

    if (D_00326030 != 0) {
        if (D_00693B88[D_00326030->x48] == 1 && id >= 14) {
            st = 1;
            flag = 1;
        }
    }
    if (hp > 0) {
        func_00226100(x, y, id, st);
    } else {
        func_00226188(x, y, id, flag ? st : 0x53);
        func_0022F5E8(x, y, id);
    }
}

void func_0022F810(int v, int a, int b)
{
    int i = 0;
    int max = TkMenuGetSummonListMax();
    int x = D_00693BC0[0] + v;
    int y = D_00693BC0[1];

    for (; i < max; i++) {
        func_0022F720(x, y, func_00242798(i));
        if (i == func_00242970()) {
            if (b >= 0) {
                func_002270F8(x + D_00693BC8[0], y + D_00693BC8[1], 0);
            } else if (b == -1) {
                func_002270F8(x + D_00693BC8[0], y + D_00693BC8[1], 1);
            }
        }
        y += D_00693BC4;
    }
}

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
