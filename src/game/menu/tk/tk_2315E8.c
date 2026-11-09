/* tu_257 0x2315e8-0x232c88: medium; ~Tk (config/tu_map.tsv) */
#define func_00232180 _hdr_func_00232180
#define D_00693D64 _hdr_D_00693D64
#include "common.h"
#include "ffx/r5.h"
#include "ffx/w7.h"
#include "ffx/q6.h"
#include "ffx/u4.h"
#include "ffx/v5.h"
#include "ffx/s5.h"
#undef func_00232180
#undef D_00693D64

extern int D_00693D64;

void func_002315E8(void)
{
    TkMn2GetCommonPlate(&D_00325AD0, D_00571E90, D_00571EA0, D_00571EB0, 0, 0);
    func_00227460(D_00571EC0, D_00693D68);
    func_002273A0(D_00571ED0, D_00693D70);
    func_002273A0(D_00571EE0, D_00693D78);
    func_00227460(D_00571EF0, D_00693D80);
    func_00227460(D_00571F00, &D_00693D88);
    func_002273A0(D_00571F10, D_00693D90);
    func_002273A0(D_00571F20, D_00325B00);
    func_00227460(D_00571F30, D_00325AC8);
    func_00227460(D_00571F40, D_00325AE8);
    func_002273A0(D_00571F50, D_00325AF0);
    func_00227460(D_00571F60, D_00325AF8);
    func_00227460(D_00571F70, D_00325B08);
    func_00227460(D_00571F80, D_00325B10);
    func_00227460(D_00571F90, D_00693D98);
}

void func_00231740(SlotRec *r, int id) {
    int i;

    for (i = 0; i < r->count; i++) {
        u16 v = r->slots[i];

        if (v == 0 || v == 0xFF) {
            r->slots[i] = id;
            break;
        }
    }
    TkMsSetSaveParamAll();
}

void func_00231780(int a0)
{
    s32 buf;

    func_002253F0(5, MsGetSaveWeapon(D_00693D60[a0], &buf));
}

int func_002317C0(int id, int b)
{
    s32 buf[4];
    Unk1BFED8 *p = MsGetSaveWeapon(id, buf);

    if (p->b2 == 0) {
        return 0;
    }
    if ((p->b3 >> 1) & 1) {
        return 0;
    }
    if (b != 0) {
        return 1;
    }
    if ((p->b3 >> 2) & 1) {
        return 0;
    }
    if ((p->b3 >> 3) & 1) {
        return 0;
    }
    return func_002249B8(p);
}

INCLUDE_ASM("build/ee_asm/game/menu/tk/tk_2315E8", func_00231840);
INCLUDE_RODATA("build/ee_asm/game/menu/tk/tk_2315E8/rodata", jtbl_00571FF0);
INCLUDE_RODATA("build/ee_asm/game/menu/tk/tk_2315E8/rodata", jtbl_00572030);

int func_00231DC8(Task *t)
{
    s32 buf;
    Unk1BFED8 *p = MsGetSaveWeapon(D_00693D60[t->x48], &buf);

    if (p->b2 == 0) {
        return -1;
    }
    return p->b4;
}

void func_00231E10(int level)
{
    int alpha = level >> 5;
    u32 c0;
    u32 c1;

    alpha <<= 24;
    if (alpha) {
        c0 = (D_0032587C & 0xFFFFFF) | alpha;
        c1 = (D_00325880 & 0xFFFFFF) | alpha;
        func_00225718(0, D_00693D6A, 0x200, 0x1A0 - D_00693D6A, c0, c1);
    }
}

INCLUDE_ASM("build/ee_asm/game/menu/tk/tk_2315E8", func_00231E68);

/* DEBT(FAKE) */
void func_00231F88(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    register s32 _cond __asm__("$3");
    s32 temp_19;
    s32 temp_7;
    s32 var_16;
    s32 var_17;
    s32 var_6;

    var_16 = -1;
    temp_19 = arg3 + D_00693D88.x;
    var_17 = arg4 + D_00693D88.y;
    var_6 = var_17;
    do {
        temp_7 = var_16 + arg2;
        func_00231E68(arg0, temp_19, var_6, temp_7, arg1);
        var_16 += 1;
        var_17 += 0x20;
        graphicUiRemapY2();
        var_6 = var_17;
    } while ((_cond = (var_16 < 0xA)) != 0);
}

INCLUDE_ASM("build/ee_asm/game/menu/tk/tk_2315E8", func_00232028);

void func_00232158(Task *o, int a1, int a2) { func_002270F8(a1, a2 + ((o->x48 - o->x32) << 5), 0); }

s32 _m2c_func_00232180_TkMenuGetCurrentPlayer() __asm__("TkMenuGetCurrentPlayer");
void _m2c_func_00232180_func_00225908() __asm__("func_00225908");
void _m2c_func_00232180_func_00225920() __asm__("func_00225920");
void _m2c_func_00232180_func_00225A38() __asm__("func_00225A38");
void _m2c_func_00232180_func_00225B00() __asm__("func_00225B00");
void _m2c_func_00232180_func_00225E88(s16, s16, s16, s16, s16, u16, u16) __asm__("func_00225E88");
void _m2c_func_00232180_func_00225F30(s16, s16, s32) __asm__("func_00225F30");
void _m2c_func_00232180_func_00226210(s16, s16, s32) __asm__("func_00226210");
void _m2c_func_00232180_func_002274A0(s16, s32, s32, s16) __asm__("func_002274A0");
s32 _m2c_func_00232180_func_00228B80() __asm__("func_00228B80");
s32 _m2c_func_00232180_func_00231DC8(void *) __asm__("func_00231DC8");
void _m2c_func_00232180_func_00231E10(s32) __asm__("func_00231E10");
void _m2c_func_00232180_func_00231F88(void *, s32, s16, s32, s32) __asm__("func_00231F88");
void _m2c_func_00232180_func_00232028(s16) __asm__("func_00232028");
void _m2c_func_00232180_func_00232158(void *, s32, s32) __asm__("func_00232158");
/* DEBT(CAST) */
void func_00232180(void *arg0) {
    s16 temp_16;
    s16 temp_17;
    s16 temp_17_2;
    s32 temp_2;

    _m2c_func_00232180_func_00225A38();
    _m2c_func_00232180_func_00225920();
    _m2c_func_00232180_TkMenuGetCurrentPlayer();
    temp_17 = D_00693D88.y;
    if ((*(s16 *)((u8 *)(arg0) + (0x32))) == (*(s16 *)((u8 *)(arg0) + (0x34)))) {
        _m2c_func_00232180_func_002274A0(temp_17, 0x120, 0, (*(s16 *)((u8 *)(arg0) + (0x46))));
        _m2c_func_00232180_func_00231F88(arg0, 0, (*(s16 *)((u8 *)(arg0) + (0x32))), 0, -0x20);
    } else {
        _m2c_func_00232180_func_002274A0(temp_17, 0x120, 1, (*(s16 *)((u8 *)(arg0) + (0x46))));
        _m2c_func_00232180_func_00231F88(arg0, 1, (*(s16 *)((u8 *)(arg0) + (0x32))), 0, -0x20);
        _m2c_func_00232180_func_002274A0(temp_17, 0x120, 2, (*(s16 *)((u8 *)(arg0) + (0x46))));
        temp_2 = -((*(s16 *)((u8 *)(arg0) + (0x46))) * 0x120);
        _m2c_func_00232180_func_00231F88(arg0, 2, (*(s16 *)((u8 *)(arg0) + (0x34))), 0, (((s32)temp_2 / 4096)) - 0x20);
    }
    _m2c_func_00232180_func_00225908();
    _m2c_func_00232180_func_00232158(arg0, D_00693D88.x + 0xC, (temp_17 = D_00693D88.y) + 1);
    _m2c_func_00232180_func_00225E88((*(s16 *)((u8 *)(D_00693D90) + (0))), D_00693D90[1], D_00693D90[2], D_00693D90[3], (*(s16 *)((u8 *)(arg0) + (0x32))), (*(u16 *)((u8 *)(arg0) + (0x3A))), (*(u16 *)((u8 *)(arg0) + (0x30))));
    _m2c_func_00232180_func_00226210((*(s16 *)((u8 *)(D_00693D78) + (0))), D_00693D78[1], 7);
    _m2c_func_00232180_func_00226210((*(s16 *)((u8 *)(D_00693D70) + (0))), D_00693D70[1], 6);
    _m2c_func_00232180_func_00231E10(_m2c_func_00232180_func_00228B80());
    _m2c_func_00232180_func_00232028((*(s16 *)((u8 *)(arg0) + (0x48))));
    temp_16 = (*(s16 *)((u8 *)(D_00693D68) + (0)));
    temp_17_2 = D_00693D68[1];
    _m2c_func_00232180_func_00225F30(temp_16, temp_17_2, _m2c_func_00232180_func_00231DC8(arg0));
    _m2c_func_00232180_func_00225B00();
}

int func_00232348(void) { return 1; }

void func_00232350(void) {
    D_00693D9C = 0;
}

int func_00232360(int a, int i) {
    return func_002317C0(D_00693D60[i], 1) != 0;
}

void func_00232398(void)
{
    Task *t = func_00243400();

    t->b3E = 1;
    t->x48 = 0;
    t->x32 = 0;
    t->x34 = 0;
    t->cb = func_00232350;
    t->x0C = (s32)func_00231840;
    t->x10 = (s32)func_00232180;
    t->x14 = (s32)func_00232348;
    t->x1C = (s32)func_00232360;
    t->b3F = 1;
    t->b42 = 1;
    t->x30 = D_00693D64;
    t->b36 = 3;
    t->b37 = 0;
    t->x3A = 9;
    TkMenuMainRegistWindow(t);
    D_00693D58 = t;
}

void func_00232448(void) {
    if (D_00693D58) {
        TkMenuRestartSelFileWindow(D_00693D58);
    }
}

void func_00232468(void) {
    if (D_00693D58) {
        D_00693D58->b41 = 1;
        D_00693D58 = 0;
    }
}

void func_00232488(Task *o) {
    TkMenuCtrlSelFileWindow(o);
    TkMn2DrawSelItemsHelp(o);
}

int func_002324B0(int a, int idx)
{
    SysEntry *e = SYS_TBL;

    e += idx;
    return e->b3 != 0xFF;
}
void func_002324D0(int x, int y, int i)
{
    s32 buf[4];

    MsGetSaveWeapon(D_00693D60[i], buf);
    func_00226D88(x, y, 0);
    func_00226E10(x + D_00325878[0] + 0x58, y + D_00325878[1], 0xD7);
    func_00226350(x + 0x1D, y + 1, buf[0], 0);
}

INCLUDE_ASM("build/ee_asm/game/menu/tk/tk_2315E8", func_00232560);

void func_00232660(Task *o, int a1, int a2) { func_002270F8(a1, a2 + ((o->x48 - o->x32) << 5), 0); }

/* DEBT(FAKE) */
void func_00232688(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    register s32 _cond __asm__("$3");
    s32 temp_19;
    s32 temp_7;
    s32 var_16;
    s32 var_17;
    s32 var_6;

    var_16 = -1;
    temp_19 = arg3 + D_00693D88.x;
    var_17 = arg4 + D_00693D88.y;
    var_6 = var_17;
    do {
        temp_7 = var_16 + arg2;
        func_00232560(arg0, temp_19, var_6, temp_7, arg1);
        var_16 += 1;
        var_17 += 0x20;
        graphicUiRemapY2();
        var_6 = var_17;
    } while ((_cond = (var_16 < 0xA)) != 0);
}

INCLUDE_ASM("build/ee_asm/game/menu/tk/tk_2315E8", func_00232728);

int func_00232930(void) { return 1; }

void func_00232938(Task *o) { o->state = 0; }

void func_00232940(int a)
{
    Task *t = func_00243400();

    func_00231780(a);
    t->ext[0] = a;
    t->b3E = 3;
    t->x48 = 0;
    t->x32 = 0;
    t->x34 = 0;
    t->cb = func_00232938;
    t->x0C = (s32)func_00232488; /* DEBT(CAST): Task callbacks are typed s32 */
    t->x10 = (s32)func_00232728;
    t->x14 = (s32)func_00232930;
    t->x1C = (s32)func_002324B0;
    t->b3F = 2;
    t->b42 = 1;
    t->x30 = func_002249A8();
    t->b36 = 3;
    t->b37 = 0;
    t->x3A = 9;
    TkMenuMainRegistWindow(t);
    func_00227480(D_00571FA0);
    D_00693D5C = t;
}

void func_00232A18(void) {
    if (D_00693D5C) {
        TkMenuRestartSelFileWindow(D_00693D5C);
    }
}

void func_00232A38(void) {
    if (D_00693D5C) {
        D_00693D5C->b41 = 1;
        D_00693D5C = 0;
    }
}

void TkMenuCtrlKaizou(Task *o)
{
    s32 *state = &o->x1C;

    func_00220318();
    TOMenuGetControlPadRep();
    TOMenuGetControlPadTrg();
    switch (*state) {
    case 0:
        func_00232398();
        *state = 1;
    case 1:
        if (D_00693D58->b45 < 0) {
            *state = 2;
        }
        break;
    case 2:
        *state = 3;
    case 3:
        *state = 4;
    case 4:
        TkMenuMainSleepMenu(9);
        TkMenuMainActiveMenu(1, 0);
        break;
    }
}

void func_00232B28(void) { func_00225A38(); func_00225920(); func_00225B00(); }

void func_00232B50(void) { func_002315E8(); }

u16 *_m2c_MsGetSaveWeaponList(int, int, int, s32 *) __asm__("MsGetSaveWeaponList");

void func_00232B58(Task *o)
{
    s32 count;
    s32 idx;
    int i;

    o->x1C = 0;
    D_00693D60 = _m2c_MsGetSaveWeaponList(-1, -1, 0, &count);
    for (i = count - 1; i > 0; i--) {
        if (MsGetSaveWeapon(D_00693D60[i], &idx)->b2 != 0) {
            i++;
            break;
        }
    }
    D_00693D64 = i;
    TkMn2InitStatusBG();
    func_00227480(D_00572068);
    func_00227480(D_00572070);
}

void func_00232C10(void) {
    TkMsSetSaveParamAll();
    func_00232468();
    AtelRegistCallbackQue2(0, TkMn2ArmsRefreshArms, D_00572078);
    TkMn2InitStatusBG();
    func_00227490(D_00572068);
    func_00227490(D_00572070);
    func_00227490(D_00571FA0);
}

void func_00232C78(void) {
}

int func_00232C80(void) { return 1; }
