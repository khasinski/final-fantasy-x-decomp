/* tu_254 0x22b9f8-0x22ce70: high; ~Tk (config/tu_map.tsv) */
#define MsGetSaveWeapon _hdr_MsGetSaveWeapon
#define func_0022BA70 _hdr_func_0022BA70
#define func_0022BC18 _hdr_func_0022BC18
#define TkMenuGetArmor _hdr_TkMenuGetArmor
#define TkMenuGetWeapon _hdr_TkMenuGetWeapon
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

INCLUDE_ASM("build/ee_asm/game/menu/tk/tk_22B9F8", TkMn2ArmsRefreshArms);
INCLUDE_RODATA("build/ee_asm/game/menu/tk/tk_22B9F8/rodata", jtbl_005718B0);

INCLUDE_ASM("build/ee_asm/game/menu/tk/tk_22B9F8", TkMenuCtrlEquip);
INCLUDE_RODATA("build/ee_asm/game/menu/tk/tk_22B9F8/rodata", jtbl_00571930);

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
