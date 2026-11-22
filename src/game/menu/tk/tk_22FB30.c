/* tu_256 0x22fb30-0x2315e8: high; ~Tk (config/tu_map.tsv) */
#define func_002305B8 _hdr_func_002305B8
#define func_00226AD0 _hdr_func_00226AD0
#define func_00226FC0 _hdr_func_00226FC0
#define func_0022FCE0 _hdr_func_0022FCE0
#include "common.h"
#include "ffx/r5.h"
#include "ffx/q5.h"
#include "ffx/w7.h"
#include "ffx/s5.h"
#include "ffx/u3.h"
#include "ffx/u4.h"
#include "ffx/v5.h"
#include "ffx/q6.h"
#undef func_0022FCE0
#undef func_00226FC0
#undef func_00226AD0
#undef func_002305B8

void func_00226770(int id, int x, int y, int f);
int TkMenuGetCommandOffset(void *p, int flag, int a2, int a3);
int func_00226AD0(int text);
void func_00226FC0(FlagRec *r);
void func_00230700(Task *t);
int func_00230820(void);
void func_00230830(Task *o);
extern u16 D_00693CD8[32];
extern u16 D_00693D18[32];

void func_0022FB30(void)
{
    func_00227460(D_00571CE0, D_00693C08);
    func_002273A0(D_00571CF0, D_00693C10);
    TkMn2GetCommonPlate(&D_00693C18, D_00571D00, D_00571D10, D_00571D20, 0, 0);
    func_00227460(D_00571D30, D_00693C30);
    func_00227460(D_00571D40, D_00693C38);
    func_002273A0(D_00571D50, D_00693C40);
    func_002273A0(D_00571D60, D_00693C48);
}

void TkMn2DrawSelItemsHelp(Task *t)
{
    SysEntry *e;
    int r = 0;

    if (t->x48 < (u16)t->x30) {
        e = SYS_TBL;
        e += t->x48;
        switch (e->b2) {
        case 18:
            if (e->h0 != 0) {
                r = TkMn2GetItemHelp(e->h0);
            }
            break;
        case 11:
        case 12:
        case 13:
        case 14:
        case 15:
        case 16:
            if (e->h0 != 0) {
                r = TkMn2GetAbilityHelp(e->h0);
            }
            break;
        case 1:
        case 4:
        case 5:
        case 6:
        case 7:
            if (e->h0 != 0) {
                r = TkMn2GetCommandHelp(e->h0);
            }
            break;
        case 2:
            if (e->h0 != 0xF) {
                r = MsGetMenuChrInfo(e->h0, 0);
            } else {
                r = TkMn2GetCommandHelp(0x30FF);
            }
            break;
        case 3:
            r = TkMenuMenu1Help(e->h0 + 0x1033);
            break;
        }
    }
    TkMenuSetHelpMessage(r);
}

typedef struct {
    u8 pad00[0x1C];
    int (*f1C)(void *, int, int);
    u8 pad20[0x08];
    s32 state;
    s16 h2C[2];
    u16 h30;
    s16 h32;
    s16 h34;
    u8 b36;
    u8 b37;
    u8 pad38[0x02];
    u16 h3A;
    u8 pad3C[0x09];
    s8 b45;
    s16 h46;
    s16 h48;
} SelWin;

int func_002429E0(int);

void func_0022FCE0(Task *o)
{
    SelWin *t = (SelWin *)o;
    s32 *statep = &t->state;
    u16 s5 = func_00220318();
    u16 s4 = TOMenuGetControlPadRep();
    u16 s2 = TOMenuGetControlPadTrg();
    int state = t->state;

loop:
    switch (state) {
    case 0:
    case 1:
        TkMn2DrawSelItemsHelp(o);
        *statep = 2;
        break;
    case 2:
        func_002429E0(1);
        if (((s2 & s4) & 0xFFFF) == 0) {
            break;
        }
        *statep = 3;
    case 3: {
        int row = t->h48 >> 1;
        int maxrow = (t->h30 + 1) >> 1;

        if (s2 & 0x20) {
            if (t->f1C != 0) {
                int r = t->f1C(t, t->h48, t->b45);
                if (r < 0) {
                    break;
                }
                if (r == 0) {
                    SndSepPlaySimple(0x80000003);
                    break;
                }
            }
            if (t->b37 != 0) {
                ((int (*)(int))SndSepPlaySimple)(0x80000001);
            }
            *statep = 12;
            break;
        }
        if (s2 & 0x40) {
            ((int (*)(int))SndSepPlaySimple)(0x80000004);
            *statep = 14;
            break;
        }
        if (s2 & 0x8000) {
            if (!(t->h48 & 1)) {
                break;
            }
            ((int (*)(int))SndSepPlaySimple)(0x80000001);
            t->h48 &= ~1;
            TkMn2DrawSelItemsHelp(o);
            break;
        }
        if (s2 & 0x2000) {
            if (t->h48 & 1) {
                break;
            }
            if (t->h48 < t->h30 - 1) {
                t->h48 |= 1;
            } else {
                if (row == 0) {
                    break;
                }
                t->h48 -= 1;
            }
            ((int (*)(int))SndSepPlaySimple)(0x80000001);
            TkMn2DrawSelItemsHelp(o);
            break;
        }
        if ((s4 & 1) && s5 == 1 && row > 0) {
            int dst = t->h32 - t->h3A;
            if (dst < 0) {
                dst = 0;
            }
            if (dst == t->h32) {
                break;
            }
            t->h34 = dst;
            ((int (*)(int))SndSepPlaySimple)(0x80000001);
            func_002429E0(0);
            state = 6;
            goto loop;
        }
        if ((s4 & 2) && s5 == 2 && row < maxrow - 1) {
            int lim = maxrow - t->h3A;
            int dst = t->h32 + t->h3A;
            if (dst >= lim) {
                dst = lim;
                if (dst < 0) {
                    dst = 0;
                }
            }
            if (dst == t->h32) {
                break;
            }
            t->h34 = dst;
            ((int (*)(int))SndSepPlaySimple)(0x80000001);
            func_002429E0(0);
            state = 10;
            goto loop;
        }
        if ((s4 & 0x1000) && row > 0) {
            row--;
            ((int (*)(int))SndSepPlaySimple)(0x80000001);
            t->h48 -= 2;
            TkMn2DrawSelItemsHelp(o);
            if (row >= t->h32) {
                break;
            }
            func_002429E0(0);
            state = 4;
            goto loop;
        }
        if ((s4 & 0x4000) && row < maxrow - 1) {
            ((int (*)(int))SndSepPlaySimple)(0x80000001);
            if (t->h48 < t->h30 - 2) {
                t->h48 += 2;
                row++;
            } else {
                t->h48 += 1;
                row++;
            }
            TkMn2DrawSelItemsHelp(o);
            if (row < t->h32 + t->h3A) {
                break;
            }
            func_002429E0(0);
            state = 8;
            goto loop;
        }
        break;
    }
    case 4:
        t->h46 = 0x1000;
        *statep = 5;
        t->h34 = t->h32 = t->h32 - 1;
        s2 = 0;
    case 5:
        t->h46 -= 0x333;
        if (t->h46 <= 0 || (s2 & 0x1000)) {
            s2 = 0;
            t->h46 = 0;
            t->h48 -= (t->h32 - t->h34) * 2;
            t->h32 = t->h34;
            TkMn2DrawSelItemsHelp(o);
            func_002429E0(1);
            *statep = 3;
            state = 3;
            goto loop;
        }
        break;
    case 6:
        t->h46 = 0x1000;
        *statep = 7;
    case 7:
        t->h46 -= 0x111;
        if (t->h46 <= 0) {
            s2 = 0;
            t->h46 = 0;
            t->h48 -= (t->h32 - t->h34) * 2;
            t->h32 = t->h34;
            TkMn2DrawSelItemsHelp(o);
            func_002429E0(1);
            *statep = 3;
            state = 3;
            goto loop;
        }
        break;
    case 8:
        t->h46 = -0x1000;
        *statep = 9;
        t->h34 = t->h32 = t->h32 + 1;
        s2 = 0;
    case 9:
        t->h46 += 0x333;
        if (t->h46 >= 0 || (s2 & 0x4000)) {
            t->h46 = 0;
            t->h48 += (t->h34 - t->h32) * 2;
            t->h32 = t->h34;
            TkMn2DrawSelItemsHelp(o);
            if (t->h48 >= t->h30) {
                t->h48 = t->h30 - 1;
            }
            s2 = 0;
            func_002429E0(1);
            *statep = 3;
            state = 3;
            goto loop;
        }
        break;
    case 10:
        t->h46 = -0x1000;
        *statep = 11;
    case 11:
        t->h46 += 0x111;
        if (t->h46 >= 0) {
            t->h46 = 0;
            t->h48 += (t->h34 - t->h32) * 2;
            t->h32 = t->h34;
            if (t->h48 >= t->h30) {
                t->h48 = t->h30 - 1;
            }
            s2 = 0;
            TkMn2DrawSelItemsHelp(o);
            func_002429E0(1);
            *statep = 3;
            state = 3;
            goto loop;
        }
        break;
    case 12:
        t->h2C[t->b45] = t->h48;
        t->b45++;
        *statep = 13;
        break;
    case 14:
        t->b45--;
        *statep = 15;
        break;
    case 13:
    case 15:
    default:
        break;
    }
}

void func_002302E8(Task *o) {
    if (o != 0) {
        o->b45 = 0;
        o->state = 1;
    }
}

void func_00230300(Task *o) {
    if (o->b45 == 0) {
        func_0022FCE0(o);
    }
}

extern s16 D_00325878[2];

typedef struct LearnEntry {
    u16 id;
    u8 kind;
    u8 active;
} LearnEntry;

void func_00230320(int t_, int x, int y, int idx, int mode)
{
    Task *t = (Task *)t_; /* DEBT(CAST): v5.h declares int */
    LearnEntry *table = (LearnEntry *)0x1D57300;
    LearnEntry *e;

    if (mode == 0) {
        y -= t->x46 / 128;
    }
    if (idx < 0 || idx >= (u16)t->x30) {
        return;
    }
    func_00226D88(x, y, 0x10);
    func_00226E10(x + D_00325878[0] + 0x58, y + D_00325878[1], 0xD7);
    e = &table[idx];
    if (e->active != 0) {
        int mes;
        switch (e->kind) {
        case 1:
            func_00226770(e->id, x, y, 0);
            break;
        case 2:
            mes = func_0014F1C0(e->id);
            func_00226350(x + 0xC, y + 1, mes, 0);
            break;
        case 3:
            mes = TkMenuMenu1Mes(e->id + 0x1033);
            func_00226350(x + 0x1D, y + 1, mes, 0);
            break;
        }
    }
}

void func_00230480(int a, int b, int page, int x, int y)
{
    int i;
    int r = page * 2 - 1;
    int l = page * 2 - 2;

    y += D_00693C30[1];
    for (i = 0; i < 9; i++) {
        func_00230320(a, x + D_00693C30[0], y, l, b);
        l += 2;
        func_00230320(a, x + D_00693C38[0], y, r, b);
        graphicUiRemapY2();
        y += 0x20;
        r += 2;
    }
}

void func_00230560(Task *t, int a1, int a2)
{
    int x;
    int y = D_00693C38[1] + a2 + (((t->x48 >> 1) - t->x32) << 5);

    if (t->x48 & 1) {
        x = a1 + D_00693C38[0];
    } else {
        x = a1 + D_00693C30[0];
    }
    func_002270F8(x, y, 0);
}

void _m2c_func_002305B8_func_00225908() __asm__("func_00225908");
void _m2c_func_002305B8_func_00225E88(s16, s16, s16, s16, s16, u16, s32) __asm__("func_00225E88");
void _m2c_func_002305B8_func_002274A0(s16, s32, s32, s16) __asm__("func_002274A0");
void _m2c_func_002305B8_func_00230480(void *, s32, s16, s32, s32) __asm__("func_00230480");
void _m2c_func_002305B8_func_00230560(void *, s32, s32) __asm__("func_00230560");
extern s16 _m2c_func_002305B8_D_00693C3A __asm__("D_00693C3A");
/* DEBT(CAST) */
void func_002305B8(void *arg0, s32 arg1) {
    s16 temp_17;
    s16 temp_7;
    s32 temp_2;

    temp_17 = _m2c_func_002305B8_D_00693C3A;
    temp_7 = (*(s16 *)((u8 *)(arg0) + (0x46)));
    if ((*(s16 *)((u8 *)(arg0) + (0x32))) == (*(s16 *)((u8 *)(arg0) + (0x34)))) {
        _m2c_func_002305B8_func_002274A0(temp_17, 0xE0, 0, temp_7);
        _m2c_func_002305B8_func_00230480(arg0, 0, (*(s16 *)((u8 *)(arg0) + (0x32))), 0, -0x20);
    } else {
        _m2c_func_002305B8_func_002274A0(temp_17, 0xE0, 1, temp_7);
        _m2c_func_002305B8_func_00230480(arg0, 1, (*(s16 *)((u8 *)(arg0) + (0x32))), 0, -0x20);
        _m2c_func_002305B8_func_002274A0(temp_17, 0xE0, 2, (*(s16 *)((u8 *)(arg0) + (0x46))));
        temp_2 = -((*(s16 *)((u8 *)(arg0) + (0x46))) * 0xE0);
        _m2c_func_002305B8_func_00230480(arg0, 2, (*(s16 *)((u8 *)(arg0) + (0x34))), 0, (((s32)temp_2 / 4096)) - 0x20);
    }
    _m2c_func_002305B8_func_00225908();
    _m2c_func_002305B8_func_00225E88((*(s16 *)((u8 *)(D_00693C40) + (0))), (*(s16 *)((u8 *)(D_00693C40) + (2))), (*(s16 *)((u8 *)(D_00693C40) + (4))), (*(s16 *)((u8 *)(D_00693C40) + (6))), (*(s16 *)((u8 *)(arg0) + (0x32))), (*(u16 *)((u8 *)(arg0) + (0x3A))), (s32) ((*(u16 *)((u8 *)(arg0) + (0x30))) + 1) >> 1);
    if ((*(s8 *)((u8 *)(arg0) + (0x45))) >= 0) {
        _m2c_func_002305B8_func_00230560(arg0, 0xC, 1);
    }
}

void func_00230700(Task *t)
{
    int text;
    int w;
    u8 k = TkMenuGetCurrentPlayer();
    u16 *e = (u16 *)MsMenuStatusNum(0, &text);

    e += TkMenuGetCommandOffset(e, 5, k, 0x48) * 2;
    func_002492F0();
    func_002492F0();
    func_00225A38();
    V5_func_00225920_void();
    if (t->ext[1] != 0) {
        func_00226FC0(&D_00693C18);
        text = TkMn2GetCommandName(e[1]);
        w = func_00226AD0(text);
        func_00226350(D_00693C18.rect[0] + (D_00693C18.rect[2] - w) / 2, D_00693C18.rect[1] + 4, text, 0);
    } else {
        func_00226210(D_00693C48[0], D_00693C48[1], 0);
    }
    func_002305B8(t, k);
    func_00225B00();
}

int func_00230820(void) { return 1; }

int func_00230828(void) { return -1; }

void func_00230830(Task *o) { o->state = 0; }

void func_00230838(void)
{
    Task *t = D_00693C50;

    if (t != 0) {
        t->state = 0;
        t->b45 = 0;
    }
}

void func_00230858(void)
{
    Task *t = D_00693C54;

    if (t != 0) {
        t->state = 0;
        t->b45 = 0;
    }
}

void func_00230878(void)
{
    if (D_00693C50 != 0) {
        D_00693C50->b41 = 1;
        D_00693C50 = 0;
    }
}

void func_00230898(void)
{
    if (D_00693C54 != 0) {
        D_00693C54->b41 = 1;
        D_00693C54 = 0;
    }
}

typedef struct {
    u8 pad00[0x08];
    void *f08;
    void *f0C;
    void *f10;
    void *f14;
    u8 pad18[0x04];
    s32 w1C;
    u8 pad20[0x10];
    s16 h30;
    s16 h32;
    s16 h34;
    s8 b36;
    s8 b37;
    u8 pad38[0x02];
    s16 h3A;
    u8 pad3C[0x02];
    s8 b3E;
    s8 b3F;
    u8 pad40[0x02];
    s8 b42;
    u8 pad43[0x02];
    s8 b45;
    u8 pad46[0x02];
    s16 h48;
    u8 pad4A[0x0E];
    s32 w58;
    s32 w5C;
} LimitWin;

int func_00224998(void);
void func_002253E8(int);
void func_002308B8(int);
void func_00230998(int);

INCLUDE_ASM("build/ee_asm/game/menu/tk/tk_22FB30", func_002308B8);

INCLUDE_ASM("build/ee_asm/game/menu/tk/tk_22FB30", func_00230998);

extern Task *D_00326030;
extern s32 D_00693C58[16];
extern s32 D_00693C98[16];
extern char D_00571E10[];
extern char D_00571E28[];
int func_002377C8(void);
void func_002EF240(const char *, ...);
int func_00225648(int);
void func_00225620(int, int);
int func_00242818(void);
int func_002429D0(void);
void func_002429F0(void);
void func_00242980(void);
void TkMenuMainSleepMenu(int);

void TkMenuCtrlLimit(s32 *a0)
{
    s32 *statep = &a0[7];
    u16 s6 = func_00220318();
    u16 s5 = TOMenuGetControlPadRep();
    int state;
    int p;

    TOMenuGetControlPadTrg();
    state = *statep;
loop:
    switch (state) {
    case 0:
        *statep = 7;
    case 1:
        *statep = 3;
        state = 3;
        goto loop;
    case 2:
        func_002377C8();
        *statep = 3;
        state = 3;
        goto loop;
    case 3: {
        LimitWin *m = (LimitWin *)D_00326030;
        s16 s2 = m->h48;
        s8 s7 = m->b45;

        switch (s2) {
        case 0: {
            int p = TkMenuGetCurrentPlayer();
            if (D_00693C50 == 0) {
                func_002308B8(p);
                D_00693C50->b45 = -1;
            } else {
                func_002253E8(0);
            }
            D_00693C50->x30 = func_00224998();
            D_00693C50->x32 = D_00693C58[p];
            D_00693C50->x34 = D_00693C58[p];
            D_00693C50->x48 = D_00693C98[p];
            func_00230898();
            break;
        }
        case 1: {
            int p = TkMenuGetCurrentPlayer();
            if (D_00693C54 == 0) {
                func_00230998(p);
                D_00693C54->b45 = -1;
            } else {
                func_002253E8(1);
            }
            D_00693C54->x30 = func_00224998();
            D_00693C54->x32 = ((u32 *)D_00693CD8)[p];
            D_00693C54->x34 = ((u32 *)D_00693CD8)[p];
            D_00693C54->x48 = ((u32 *)D_00693D18)[p];
            func_00230878();
            break;
        }
        }
        if (s7 > 0) {
            switch (s2) {
            case 0:
                state = 8;
                goto loop;
            case 1:
                state = 4;
                goto loop;
            }
        }
        if (s7 < 0) {
            state = 10;
            goto loop;
        }
        break;
    }
    case 4:
        func_00230858();
        *statep = 6;
    case 5:
        func_00230858();
        *statep = 6;
    case 6:
        if (D_00693C54 != 0) {
            int p2 = TkMenuGetCurrentPlayer();
            if (D_00693C54->b45 > 0) {
                LearnEntry *table = (LearnEntry *)0x1D57300;
                func_002EF240(D_00571E10);
                if (func_00225648(p2) != table[D_00693C54->x48].id) {
                    func_002EF240(D_00571E28, func_00225648(p2), table[D_00693C54->x48].id);
                    SndSepPlaySimple(0x80000064);
                } else {
                    SndSepPlaySimple(0x80000003);
                }
                func_002253E8(1);
                func_00225620(p2, table[D_00693C54->x48].id);
                func_00230858();
                break;
            }
            if (D_00693C54->b45 < 0) {
                ((s32 *)D_00693CD8)[p2] = D_00693C54->x32;
                ((s32 *)D_00693D18)[p2] = D_00693C54->x48;
                *statep = 2;
                break;
            }
        }
        if (func_00242818() < 2) {
            break;
        }
        if (func_002429D0() == 0) {
            break;
        }
        if ((s5 & 4) && s6 == 4) {
            p = TkMenuGetCurrentPlayer();
            SndSepPlaySimple(0x80000004);
            ((s32 *)D_00693CD8)[p] = D_00693C54->x32;
            ((s32 *)D_00693D18)[p] = D_00693C54->x48;
            func_002429F0();
            p = TkMenuGetCurrentPlayer();
            func_002253E8(1);
            if (D_00693C54 != 0) {
                D_00693C54->x30 = func_00224998();
                D_00693C54->x32 = ((u32 *)D_00693CD8)[p];
                D_00693C54->x34 = ((u32 *)D_00693CD8)[p];
                D_00693C54->x48 = ((u32 *)D_00693D18)[p];
                TkMn2DrawSelItemsHelp(D_00693C54);
            }
            break;
        }
        if ((s5 & 8) && s6 == 8) {
            p = TkMenuGetCurrentPlayer();
            SndSepPlaySimple(0x80000004);
            ((s32 *)D_00693CD8)[p] = D_00693C54->x32;
            ((s32 *)D_00693D18)[p] = D_00693C54->x48;
            func_00242980();
            p = TkMenuGetCurrentPlayer();
            func_002253E8(1);
            if (D_00693C54 != 0) {
                D_00693C54->x30 = func_00224998();
                D_00693C54->x32 = ((u32 *)D_00693CD8)[p];
                D_00693C54->x34 = ((u32 *)D_00693CD8)[p];
                D_00693C54->x48 = ((u32 *)D_00693D18)[p];
                TkMn2DrawSelItemsHelp(D_00693C54);
            }
            break;
        }
        break;
    case 7:
        func_00230838();
        *statep = 9;
    case 8:
        func_00230838();
        *statep = 9;
    case 9:
        if (D_00693C50 != 0 && D_00693C50->b45 != 0) {
            int p2 = TkMenuGetCurrentPlayer();
            D_00693C58[p2] = D_00693C50->x32;
            D_00693C98[p2] = D_00693C50->x48;
            D_00693C50->b45 = -1;
            *statep = 2;
            break;
        }
        if (func_00242818() < 2) {
            break;
        }
        if (func_002429D0() == 0) {
            break;
        }
        if ((s5 & 4) && s6 == 4) {
            p = TkMenuGetCurrentPlayer();
            SndSepPlaySimple(0x80000004);
            D_00693C58[p] = D_00693C50->x32;
            D_00693C98[p] = D_00693C50->x48;
            func_002429F0();
            p = TkMenuGetCurrentPlayer();
            func_002253E8(0);
            if (D_00693C50 != 0) {
                D_00693C50->x30 = func_00224998();
                D_00693C50->x32 = D_00693C58[p];
                D_00693C50->x34 = D_00693C58[p];
                D_00693C50->x48 = D_00693C98[p];
                TkMn2DrawSelItemsHelp(D_00693C50);
            }
            break;
        }
        if ((s5 & 8) && s6 == 8) {
            p = TkMenuGetCurrentPlayer();
            SndSepPlaySimple(0x80000004);
            D_00693C58[p] = D_00693C50->x32;
            D_00693C98[p] = D_00693C50->x48;
            func_00242980();
            p = TkMenuGetCurrentPlayer();
            func_002253E8(0);
            if (D_00693C50 != 0) {
                D_00693C50->x30 = func_00224998();
                D_00693C50->x32 = D_00693C58[p];
                D_00693C50->x34 = D_00693C58[p];
                D_00693C50->x48 = D_00693C98[p];
                TkMn2DrawSelItemsHelp(D_00693C50);
            }
            break;
        }
        break;
    case 10:
        *statep = 11;
    case 11:
        *statep = 12;
    case 12:
        TkMenuMainSleepMenu(0x15);
        TkMenuMainActiveMenu(1, 0);
        break;
    default:
        break;
    }
}

void func_002312C8(void)
{
    u8 k = TkMenuGetCurrentPlayer();

    func_002492F0();
    func_002492F0();
    func_00225A38();
    V5_func_00225920_void();
    func_00225F30(D_00693C08[0], D_00693C08[1], k);
    func_00229D58(D_00693C10[0], D_00693C10[1], k);
    func_00225B00();
}

void func_00231340(void) { func_0022FB30(); }

extern s32 D_00693C58[16];
extern s32 D_00693C98[16];
int TkMenuGetCurrentPlayerPos(void);
int TkMenuGetPlayerListMax2(void);
void func_00242930(int);
int TkMenuGetPlayerFromIndex2(int);
int func_00220A78(int);
int func_00220CE0(int);
void func_002375F8(int, int *, int *, int, int);
void func_00237690(void);
void func_00237790(int);

void func_00231348(s32 *a0, s32 a1)
{
    int arr0[2];
    int arr1[2];
    int i;
    int cur;
    int max;

    a0[8] = a1;
    a0[7] = 0;
    for (i = 0; i < 16; i++) {
        D_00693C58[i] = 0;
        D_00693C98[i] = 0;
    }
    cur = TkMenuGetCurrentPlayerPos();
    max = TkMenuGetPlayerListMax2();
    for (i = 0; i < max; i++) {
        int p;
        int od;
        int cnt;
        int j;
        LearnEntry *table = (LearnEntry *)0x1D57300;

        func_00242930(i);
        p = TkMenuGetPlayerFromIndex2(i);
        od = TkMn2GetOverDriveId(p);
        func_002253E8(1);
        cnt = func_00224998();
        ((s32 *)D_00693D18)[p] = 0;
        for (j = 0; j < cnt; j++, table++) {
            if (od == table->id) {
                ((s32 *)D_00693D18)[p] = j;
                break;
            }
        }
        ((s32 *)D_00693CD8)[p] = 0;
        if (((s32 *)D_00693D18)[p] >= 7) {
            int row = ((s32 *)D_00693D18)[p] / 2;
            int maxrow = (cnt + 1) / 2;

            ((s32 *)D_00693CD8)[p] = row - 3;
            if (row + 4 >= maxrow) {
                ((s32 *)D_00693CD8)[p] = maxrow - 7;
                if (((s32 *)D_00693CD8)[p] < 0) {
                    ((s32 *)D_00693CD8)[p] = 0;
                }
            }
        } else {
            ((s32 *)D_00693CD8)[p] = 0;
        }
    }
    func_00242930(cur);
    func_002253E8(0);
    arr0[0] = func_00220A78(2);
    arr0[1] = func_00220A78(3);
    arr1[0] = func_00220CE0(2);
    arr1[1] = func_00220CE0(3);
    func_002375F8(0, arr0, arr1, 2, 0);
    func_00237690();
    func_002308B8(TkMenuGetCurrentPlayer());
    func_00237790(0);
    func_00227480(D_00571E00);
    func_00227480(D_00571E08);
}

void func_002315A0(void)
{
    func_00237818();
    func_00230878();
    func_00230898();
    func_00227480(D_00571E00);
    func_00227480(D_00571E08);
}

void func_002315E0(void) {
}
