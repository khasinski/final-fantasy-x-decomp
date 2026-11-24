/* tu_254 0x22b9f8-0x22ce70: high; ~Tk (config/tu_map.tsv) */
#define MsGetSaveWeapon _hdr_MsGetSaveWeapon
#define func_0022BA70 _hdr_func_0022BA70
#define func_0022BC18 _hdr_func_0022BC18
#define TkMenuGetArmor _hdr_TkMenuGetArmor
#define TkMenuGetWeapon _hdr_TkMenuGetWeapon
#define TkMenuMainActiveMenu _hdr_TkMenuMainActiveMenu
#include "common.h"
#include "ffx/r5.h"
#include "ffx/q5.h"
#include "ffx/w7.h"
#include "ffx/s5.h"
#include "ffx/u3.h"
#include "ffx/u4.h"
#include "ffx/v5.h"
#undef MsGetSaveWeapon
#undef func_0022BA70
#undef func_0022BC18
#undef TkMenuGetArmor
#undef TkMenuGetWeapon
#undef TkMenuMainActiveMenu

typedef struct {
    u16 h0;
    u8 b2;
    u8 b3;
    u8 b4;
    u8 b5;
    u8 b6;
    u8 pad7[4];
    u8 bB;
    u16 fC;
    u16 fE[4];
} WeaponRec;

WeaponRec *MsGetSaveWeapon(int a0, s32 *buf);
void func_00226800(int id, int x, int y, int a);
void func_002269B0(int id, int x, int y, int a);
void func_002274A0(int a, int b, int c, int d);
void func_0022BC18(Task *t, int x, int y, int i, int b);
int TkMenuGetArmor(int idx);
int TkMenuGetWeapon(int idx);
extern s32 D_00693B30[];
extern s32 D_00693B50[];
extern s32 D_00693AA4;

void func_0022B9F8(void)
{
    func_002273A0(D_00571860, D_00693AC8);
    func_00227460(D_00571870, D_00693AD0);
    func_002273A0(D_00571880, D_00693AD8);
    func_00227460(D_00571890, D_00693AE0);
    func_002273A0(D_005718A0, D_00693AE8);
}

void func_0022BA70(int a, int b)
{
    func_002253F0(0x14);
    D_00693AB0 = func_00224998();
}

void func_0022BAA0(void)
{
    s32 buf;
    int i;
    WeaponRec *w;
    int x;
    int y;

    if (D_00693AC0 != 0xFF) {
        i = 0;
        w = MsGetSaveWeapon(D_00693AC0, &buf);
        x = D_00693AE0[0];
        y = D_00693AE0[1];
        for (; i < w->bB; i++, y += 0x20) {
            func_00226D88(x, y, 0x10);
            func_00226E10(x + D_00325878[0] + 0x58, y + D_00325878[1], 0xD7);
        }
        x = D_00693AE0[0];
        y = D_00693AE0[1];
        for (i = 0; i < 4; i++, y += 0x20) {
            int id = w->fE[i];

            if (id != 0 && id != 0xFF) {
                func_00226800(id, x, y, 0);
            }
        }
    }
}

void func_0022BBC8(void)
{
    s16 v[2];

    if (D_00693AA0 >= 0x1000) {
        func_00228B90(v, D_00693AB4);
        func_002270F8(v[0], v[1], D_00693ABC);
    }
}

void func_0022BC18(Task *t, int x, int y, int i, int b)
{
    s32 buf;

    if (b == 0) {
        y -= t->x46 / 128;
    }
    if (i >= 0 && i < (u16)t->x30) {
        SysEntry *e = SYS_TBL;

        e += i;
        func_00226D88(x, y, 0);
        func_00226E10(x + D_00325878[0] + 0x58, y + D_00325878[1], 0xD7);
        if (e->h0 != 0) {
            MsGetSaveWeapon(e->h0, &buf);
            func_002269B0(e->h0, x, y, 0);
        }
    }
}

void func_0022BCF0(Task *o, int a1, int a2) { func_002270F8(a1, a2 + ((o->x48 - o->x32) << 5), 0); }

void func_0022BD18(int a, int b, int c, int x, int y)
{
    int i;

    x += D_00693AD0[0];
    y += D_00693AD0[1];
    for (i = -1; i < 6; i++) {
        func_0022BC18((Task *)a, x, y, i + c, b);
        graphicUiRemapY2_int();
        y += 0x20;
    }
}

void func_0022BDB8(Task *t)
{
    func_00225A38();
    func_00225920();
    if (t->x32 == t->x34) {
        func_002274A0(D_00693AD0[1], 0xA0, 0, t->x46);
        func_0022BD18((int)t, 0, t->x32, 0, -0x20);
    } else {
        func_002274A0(D_00693AD0[1], 0xA0, 1, t->x46);
        func_0022BD18((int)t, 1, t->x32, 0, -0x20);
        func_002274A0(D_00693AD0[1], 0xA0, 2, t->x46);
        func_0022BD18((int)t, 2, t->x34, 0, (-(t->x46 * 0xA0)) / 4096 - 0x20);
    }
    func_00225908();
    func_0022BCF0(t, D_00693AD0[0] + 0xC, D_00693AD0[1] + 1);
    func_00225E88(D_00693AE8[0], D_00693AE8[1], D_00693AE8[2], D_00693AE8[3], t->x32, (u16)t->x3A, (u16)t->x30);
    func_00225B00();
}

int func_0022BF08(void) { return 1; }

void func_0022BF10(Task *o) { o->state = 0; }

int func_0022BF18(void) { return 1; }

void func_0022BF20(int a, int b)
{
    Task *t = func_00243400();

    func_0022BA70(a, b);
    t->b3F = 2;
    t->b3E = 1;
    t->b42 = 1;
    t->x0C = (s32)TkMenuCtrlSelFileWindow;
    t->x10 = (s32)func_0022BDB8;
    t->x14 = (s32)func_0022BF08;
    t->x1C = (s32)func_0022BF18;
    t->cb = func_0022BF10;
    t->x30 = D_00693AB0;
    t->x48 = 0;
    t->x32 = 0;
    t->x34 = 0;
    t->b36 = 3;
    t->x3A = 5;
    t->x4A = 0x1D;
    t->x4C = 0x32;
    t->b37 = 0;
    TkMenuMainRegistWindow(t);
    D_00693AA8 = t;
}

void func_0022C008(void)
{
    if (D_00693AA8 != 0) {
        D_00693AA8->b45 = 0;
        D_00693AA8->state = 0;
    }
}

void func_0022C030(void)
{
    if (D_00693AA8 != 0) {
        D_00693AA8->b41 = 1;
        D_00693AA8 = 0;
    }
}

s32 func_0022C050(void)
{
    return D_00693AB4 != 0;
}

void func_0022C060(void)
{
    SysEntry *e = SYS_TBL;

    e += D_00693AA8->x48;
    if (e->h0 != 0) {
        D_00693AC0 = e->h0;
    } else {
        D_00693AC0 = 0xFF;
    }
}

int AtelGetTotalActorNumber2(void);
int MsGetSaveChrWeaponModel(int);
int MsGetSaveChrArmorModel(int);

int TkMn2ArmsRefreshArms(int *stp)
{
    int ret = 0;
    int prevCtrl = AtelChangeCurrentCtrl(0);
    int total = AtelGetTotalActorNumber2();
    int st = *stp;

again:
    switch (st) {
    case 0:
        D_00693B70 = -1;
        /* fallthrough */
    case 1:
        *stp = 9;
        /* fallthrough */
    case 9:
        D_00693B70++;
        if (D_00693B70 < total) {
            u8 *w = AtelGetBasicWork(D_00693B70);
            register int id __asm__("$4") = func_0013B068(w);
            register int ok __asm__("$5") = 0;
            if (w[0xAA] == 1 && *(void **)(w + 0x9C) != 0) {
                ok = (u32)id < 7;
            }
            if (ok) {
                *stp = 2;
                st = 2;
                goto again;
            } else {
                st = 9;
                goto again;
            }
        } else {
            st = 10;
            goto again;
        }
        break;
    case 2:
        st = 3;
        goto again;
    case 3: {
        u8 *w = AtelGetBasicWork(D_00693B70);
        int id = func_0013B068(w);
        if (*(u16 *)(w + 0xB14) & 1) {
            if (D_00693AF0[id] != TkMenuGetWeapon(id)) {
                if (*(void **)(w + 0xAF4) != 0) {
                    TkCh_Dispose(*(void **)(w + 0xAF4));
                }
                ChN_DataDispose(*(u16 *)(w + 0xB04), 0);
                *(void **)(w + 0xAF4) = 0;
                *(u16 *)(w + 0xB04) = MsGetSaveChrWeaponModel(id);
                Ch_DataRead(*(u16 *)(w + 0xB04));
                *stp = 4;
                goto case_4;
            }
            st = 6;
            goto again;
        }
        st = 6;
        goto again;
    }
    case 4:
    case_4: {
        u8 *w = AtelGetBasicWork(D_00693B70);
        if (Ch_DataReadSync(*(u16 *)(w + 0xB04)) == 1) {
            break;
        }
        st = 5;
        goto again;
    }
    case 5: {
        u8 *w = AtelGetBasicWork(D_00693B70);
        void *ch = TkCh_Allocate(*(u16 *)(w + 0xB04));
        *(void **)(w + 0xAF4) = ch;
        Ch_SoundSetId(ch, 0xF);
        TkCh_BindToElem(*(u16 *)(w + 0xA8), *(void **)(w + 0xAF4), *(void **)(w + 0x9C), *(int *)(w + 0xAFC), 0);
        Ch_EnClip(*(void **)(w + 0xAF4), *(u32 *)(w + 0xB08) & 1);
        Ch_Vu1SetClipmode(*(void **)(w + 0xAF4), (*(u32 *)(w + 0xB08) >> 1) & 1);
        st = 6;
        goto again;
    }
    case 6: {
        u8 *w = AtelGetBasicWork(D_00693B70);
        int id = func_0013B068(w);
        if (*(u16 *)(w + 0xB14) & 2) {
            if (D_00693B10[id] != TkMenuGetArmor(id)) {
                if (*(void **)(w + 0xAF8) != 0) {
                    TkCh_Dispose(*(void **)(w + 0xAF8));
                }
                if (*(u16 *)(w + 0xB06) != 0) {
                    ChN_DataDispose(*(u16 *)(w + 0xB06), 0);
                }
                *(void **)(w + 0xAF8) = 0;
                *(u16 *)(w + 0xB06) = MsGetSaveChrArmorModel(id);
                if (*(u16 *)(w + 0xB06) != 0) {
                    Ch_DataRead(*(u16 *)(w + 0xB06));
                    *stp = 7;
                    break;
                }
                st = 9;
                goto again;
            }
            st = 9;
            goto again;
        }
        st = 9;
        goto again;
    }
    case 7: {
        u8 *w = AtelGetBasicWork(D_00693B70);
        if (Ch_DataReadSync(*(u16 *)(w + 0xB06)) == 1) {
            break;
        }
        st = 8;
        goto again;
    }
    case 8: {
        u8 *w = AtelGetBasicWork(D_00693B70);
        void *ch = TkCh_Allocate(*(u16 *)(w + 0xB06));
        *(void **)(w + 0xAF8) = ch;
        Ch_SoundSetId(ch, 0xF);
        TkCh_BindToElem(*(u16 *)(w + 0xA8), *(void **)(w + 0xAF8), *(void **)(w + 0x9C), *(int *)(w + 0xB00), 1);
        Ch_EnClip(*(void **)(w + 0xAF8), *(u32 *)(w + 0xB0C) & 1);
        Ch_Vu1SetClipmode(*(void **)(w + 0xAF8), (*(u32 *)(w + 0xB0C) >> 1) & 1);
        st = 9;
        goto again;
    }
    case 10:
        ret = 1;
        break;
    }
    AtelSetCurrentCtrl(prevCtrl);
    return ret;
}

extern int D_00693AB8;
extern char D_005718E0[];
extern char D_005718F0[];
extern char D_00571900[];
extern char D_00571910[];
extern char D_00571920[];
int AtelCheckCallbackQue(int);
void func_002377C8(void);
int TkMenuMainHelp(int);
void TkMenuSetHelpMessage(int);
int func_00242818(void);
int func_002429D0(void);
void func_002429F0(void);
void func_00242980(void);
int func_002277C0(int);
void TkMenuSetHP(int, int);
void TkMenuSetMP(int, int);
Task *TOMenuGetYesNoWindow(void);
void TOMenuCloseYesNoWindow(void);
void TkMsSetSaveParamAll(void);
void AtelRegistCallbackQue2(int, int (*)(int *), void *);
void TkMenuMainSleepMenu(int);
void TkMenuMainActiveMenu(int, int);

void TkMenuCtrlEquip(Task *t)
{
    int pad0;
    int padTrg;
    int padRep;
    int *stp;
    int st;

    pad0 = func_00220318();
    padRep = TOMenuGetControlPadRep();
    padTrg = TOMenuGetControlPadTrg();
    func_00225500(0, &D_003258C8, &D_003258CC, &D_003258D0, &D_003258D4);
    D_00693AA0 += D_00693AA4;
    if (D_00693AA0 > 0x1000) {
        D_00693AA0 = 0x1000;
    }
    if (D_00693AA0 < 0) {
        D_00693AA0 = 0;
    }
    st = t->x1C;
    stp = &t->x1C;
again:
    switch (st) {
    case 0:
        if (D_00693AB4 != 0) {
            D_00693AC0 = TkMenuGetArmor(TkMenuGetCurrentPlayer());
        } else {
            D_00693AC0 = TkMenuGetWeapon(TkMenuGetCurrentPlayer());
        }
        st = 1;
        goto again;
    case 1:
        if (D_00693AA0 < 0x1000) {
            break;
        }
        *stp = 2;
        break;
    case 2:
        if (AtelCheckCallbackQue(0) != 0) {
            break;
        }
        *stp = 3;
        st = 3;
        goto again;
    case 4:
        func_002377C8();
        /* fallthrough */
    case 3:
        *stp = 5;
        break;
    case 5:
        *stp = 6;
        break;
    case 7:
        TkMenuSetHelpMessage(TkMenuMainHelp(2));
        /* fallthrough */
    case 6:
        *stp = 8;
        break;
    case 8:
        *stp = 9;
        break;
    case 9:
        *stp = 10;
        break;
    case 10:
        if (D_00693AB4 != 0) {
            D_00693AC0 = TkMenuGetArmor(TkMenuGetCurrentPlayer());
        } else {
            D_00693AC0 = TkMenuGetWeapon(TkMenuGetCurrentPlayer());
        }
        if (padTrg & 0x40) {
            PLAY_SE(0x80000004);
            *stp = 13;
            break;
        }
        if (padTrg & 0x20) {
            PLAY_SE(0x80000001);
            *stp = 11;
            break;
        }
        if (padRep & 0x5000) {
            PLAY_SE(0x80000001);
            D_00693AB4 = (D_00693AB4 == 0);
            break;
        }
        if (func_00242818() < 2) {
            break;
        }
        if (func_002429D0() == 0) {
            break;
        }
        if ((padRep & 4) && pad0 == 4) {
            SndSepPlaySimple(0x80000004);
            func_002429F0();
            break;
        }
        if ((padRep & 8) && pad0 == 8) {
            SndSepPlaySimple(0x80000004);
            func_00242980();
            break;
        }
        break;
    case 11:
        *stp = 12;
        /* fallthrough */
    case 12:
        *stp = 15;
        break;
    case 13:
        *stp = 14;
        break;
    case 14:
        *stp = 28;
        break;
    case 15: {
        int type = func_0022C050();
        func_0022BF20(TkMenuGetCurrentPlayer(), type);
        D_00693ABC = 1;
        *stp = 17;
        break;
    }
    case 16:
        func_0022C008();
        *stp = 17;
        break;
    case 17:
        *stp = 18;
        break;
    case 18:
        *stp = 19;
        break;
    case 19:
        func_0022C060();
        if (D_00693AA8->b45 > 0) {
            *stp = 20;
            break;
        }
        if (D_00693AA8->b45 < 0) {
            *stp = 26;
        }
        break;
    case 20: {
        register int chr __asm__("$19") = TkMenuGetCurrentPlayer();
        int type;
        int item;
        int flag;
        int s_yes;
        int s_no;
        int s_msg;
        SysEntry *e;

        switch (D_00693AB4) {
        case 0:
            D_00693AB8 = TkMenuGetWeapon(chr);
            break;
        case 1:
            D_00693AB8 = TkMenuGetArmor(chr);
            break;
        }
        type = func_0022C050();
        e = SYS_TBL;
        e += D_00693AA8->x2C;
        item = (e->h0 != 0) ? e->h0 : 0xFF;
        MsEquipSaveWeapon(chr, type, item);
        TkMsSetSaveParam(chr);
        func_002EF240(D_005718E0, D_00693B30[chr]);
        func_002EF240(D_005718F0, TkMenuGetHP(chr));
        flag = 0;
        if (D_00693B30[chr] > TkMenuGetHP(chr)) {
            flag |= 1;
        }
        if (D_00693B50[chr] > TkMenuGetMP(chr)) {
            flag |= 2;
        }
        func_002EF240(D_00571900, flag);
        s_yes = func_002277C0(0x11);
        s_no = func_002277C0(0x12);
        switch (flag) {
        case 1:
            s_msg = func_002277C0(0xE);
            break;
        case 2:
            s_msg = func_002277C0(0xF);
            break;
        case 3:
            s_msg = func_002277C0(0x10);
            break;
        default:
            st = 23;
            goto again;
        }
        MsEquipSaveWeapon(chr, type, D_00693AB8);
        TkMsSetSaveParam(chr);
        TkMenuSetHP(chr, D_00693B30[chr]);
        TkMenuSetMP(chr, D_00693B50[chr]);
        func_00236940(s_msg, s_yes, s_no);
        st = 21;
        goto again;
    }
    case 21:
        *stp = 22;
        /* fallthrough */
    case 22: {
        Task *w = TOMenuGetYesNoWindow();
        if (w != 0) {
            if (w->b45 < 0) {
                TOMenuCloseYesNoWindow();
                st = 16;
                goto again;
            }
            if (w->b45 != 0) {
                int sel = w->x2C;
                TOMenuCloseYesNoWindow();
                switch (sel) {
                case 0:
                    st = 23;
                    goto again;
                case 1:
                    st = 16;
                    goto again;
                }
            }
            break;
        }
        func_002EF240(D_00571910);
        break;
    }
    case 23: {
        int chr = TkMenuGetCurrentPlayer();
        int type = func_0022C050();
        SysEntry *e = SYS_TBL;
        int item;
        e += D_00693AA8->x2C;
        item = (e->h0 != 0) ? e->h0 : 0xFF;
        MsEquipSaveWeapon(chr, type, item);
        TkMsSetSaveParam(chr);
        D_00693B30[chr] = TkMenuGetHP(chr);
        D_00693B50[chr] = TkMenuGetMP(chr);
        st = 24;
        goto again;
    }
    case 24:
        SndSepPlaySimple(0x80000038);
        func_0022C030();
        *stp = 25;
        break;
    case 26:
        func_0022C030();
        *stp = 27;
        break;
    case 25:
    case 27:
        D_00693ABC = 0;
        *stp = 7;
        break;
    case 28:
        *stp = 29;
        break;
    case 29:
        *stp = 30;
        break;
    case 30:
        TkMsSetSaveParamAll();
        AtelRegistCallbackQue2(0, TkMn2ArmsRefreshArms, D_00571920);
        TkMenuMainSleepMenu(4);
        TkMenuMainActiveMenu(1, 0);
        break;
    }
}

/* DEBT(CAST): integer-width views follow the existing shared interfaces. */
void func_0022CC20(void)
{
    func_002492F0();
    func_002492F0();
    func_00225A38();
    func_00225920();
    CALL_func_0022A768_INT(0, 0, TkMenuGetCurrentPlayer(), 0, &D_003258C8, &D_003258CC, &D_003258D0, &D_003258D4, D_00693AA0);
    func_00226210((s32) D_00693AC8[0], (s32) D_00693AC8[1], 6);
    func_00226210((s32) D_00693AD8[0], (s32) D_00693AD8[1], 7);
    CALL_func_0022BBC8_INT();
    func_0022BAA0();
    func_00225B00();
}

void func_0022CCE0(void) { func_0022B9F8(); }

void func_0022CCE8(Task *t)
{
    int i;
    int p;

    t->x1C = 0;
    D_00693ABC = 0;
    D_00693AC0 = 0xFF;
    D_003258C8 = 0;
    D_003258CC = TkMenuGetCurrentPlayerPos();
    D_003258D0 = TkMenuGetCurrentPlayerPos();
    D_003258D4 = TkMenuGetCurrentPlayerPos();
    for (i = 0; i < 7; i++) {
        D_00693B10[i] = TkMenuGetArmor(i);
        D_00693AF0[i] = TkMenuGetWeapon(i);
        D_00693B30[i] = TkMenuGetHP(i);
        D_00693B50[i] = TkMenuGetMP(i);
    }
    D_00693AB4 = 0;
    p = TkMenuGetCurrentPlayer();
    func_0022BA70(p, func_0022C050());
    D_00693AA4 = 0x155;
    D_00693AA0 = 0;
    func_00227480(D_005719B0);
    func_00227480(D_005719B8);
    func_00227480(D_005719C0);
}

void func_0022CE30(void)
{
    func_00227490(D_005719B0);
    func_00227490(D_005719B8);
    func_00227490(D_005719C0);
}

void func_0022CE68(void) {
}
