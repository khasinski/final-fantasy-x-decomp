/* tu_256 0x22fb30-0x2315e8: high; ~Tk (config/tu_map.tsv) */
#include "common.h"
#include "ffx/r5.h"
#include "ffx/q5.h"
#include "ffx/w7.h"
#include "ffx/s5.h"
#include "ffx/u3.h"
#include "ffx/u4.h"
#include "ffx/v5.h"
#define func_001F8800 q6_func_001F8800 /* DEBT(TYPE): this header's guess conflicts with the TU */
#include "ffx/q6.h"
#undef func_001F8800

void func_0022FB30(void)
{
    func_00227460(D_00571CE0, D_00693C08);
    func_002273A0(D_00571CF0, D_00693C10);
    TkMn2GetCommonPlate(&D_00693C18, (int)D_00571D00, (int)D_00571D10, (int)D_00571D20, 0, 0); /* DEBT(CAST): names passed as int */
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

INCLUDE_ASM("build/ee_asm/game/menu/tk/tk_22FB30", func_0022FCE0);
INCLUDE_RODATA("build/ee_asm/game/menu/tk/tk_22FB30/rodata", jtbl_00571DC0);

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

INCLUDE_ASM("build/ee_asm/game/menu/tk/tk_22FB30", func_00230320);

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

INCLUDE_ASM("build/ee_asm/game/menu/tk/tk_22FB30", func_002305B8);

INCLUDE_ASM("build/ee_asm/game/menu/tk/tk_22FB30", func_00230700);

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

INCLUDE_ASM("build/ee_asm/game/menu/tk/tk_22FB30", func_002308B8);

INCLUDE_ASM("build/ee_asm/game/menu/tk/tk_22FB30", func_00230998);

INCLUDE_ASM("build/ee_asm/game/menu/tk/tk_22FB30", TkMenuCtrlLimit);
INCLUDE_RODATA("build/ee_asm/game/menu/tk/tk_22FB30/rodata", jtbl_00571E50);

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

INCLUDE_ASM("build/ee_asm/game/menu/tk/tk_22FB30", func_00231348);

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
