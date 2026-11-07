/* tu_256 0x22fb30-0x2315e8: high; ~Tk (config/tu_map.tsv) */
#define func_002305B8 _hdr_func_002305B8
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
#undef func_002305B8
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

void _m2c_func_002305B8_func_00225908() __asm__("func_00225908");
void _m2c_func_002305B8_func_00225E88(s16, s16, s16, s16, s16, u16, s32) __asm__("func_00225E88");
void _m2c_func_002305B8_func_002274A0(s16, s32, s32, s16) __asm__("func_002274A0");
void _m2c_func_002305B8_func_00230480(void *, s32, s16, s32, s32) __asm__("func_00230480");
void _m2c_func_002305B8_func_00230560(void *, s32, s32) __asm__("func_00230560");
extern s16 _m2c_func_002305B8_D_00693C3A __asm__("D_00693C3A");
/* DEBT(CAST) */
void func_002305B8(void *arg0) {
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
