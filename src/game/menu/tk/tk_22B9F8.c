/* tu_254 0x22b9f8-0x22ce70: high; ~Tk (config/tu_map.tsv) */
#include "common.h"
#include "ffx/r5.h"
#include "ffx/q5.h"
#include "ffx/w7.h"
#include "ffx/s5.h"
#include "ffx/u3.h"
#include "ffx/v5.h"

void func_0022B9F8(void)
{
    func_002273A0(D_00571860, D_00693AC8);
    func_00227460(D_00571870, D_00693AD0);
    func_002273A0(D_00571880, D_00693AD8);
    func_00227460(D_00571890, D_00693AE0);
    func_002273A0(D_005718A0, D_00693AE8);
}

void func_0022BA70(void)
{
    func_002253F0(0x14);
    D_00693AB0 = func_00224998();
}

INCLUDE_ASM("build/ee_asm/game/menu/tk/tk_22B9F8", func_0022BAA0);

void func_0022BBC8(void)
{
    s16 v[2];

    if (D_00693AA0 >= 0x1000) {
        func_00228B90(v, D_00693AB4);
        func_002270F8(v[0], v[1], D_00693ABC);
    }
}

INCLUDE_ASM("build/ee_asm/game/menu/tk/tk_22B9F8", func_0022BC18);

void func_0022BCF0(Task *o, int a1, int a2) { func_002270F8(a1, a2 + ((o->x48 - o->x32) << 5), 0); }

void func_0022BD18(int a, int b, int c, int x, int y)
{
    int i;

    x += D_00693AD0[0];
    y += D_00693AD0[1];
    for (i = -1; i < 6; i++) {
        func_0022BC18(a, x, y, i + c, b);
        graphicUiRemapY2_int();
        y += 0x20;
    }
}

INCLUDE_ASM("build/ee_asm/game/menu/tk/tk_22B9F8", func_0022BDB8);

int func_0022BF08(void) { return 1; }

void func_0022BF10(Task *o) { o->state = 0; }

int func_0022BF18(void) { return 1; }

INCLUDE_ASM("build/ee_asm/game/menu/tk/tk_22B9F8", func_0022BF20);

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

INCLUDE_ASM("build/ee_asm/game/menu/tk/tk_22B9F8", func_0022CCE8);

/* DEBT(CAST): message strings are passed to int parameters (prototype not yet typed) */
void func_0022CE30(void)
{
    func_00227490((int)D_005719B0);
    func_00227490((int)D_005719B8);
    func_00227490((int)D_005719C0);
}

void func_0022CE68(void) {
}
