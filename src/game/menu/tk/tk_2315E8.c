/* tu_257 0x2315e8-0x232c88: medium; ~Tk (config/tu_map.tsv) */
#include "common.h"
#include "ffx/r5.h"
#include "ffx/w7.h"
#include "ffx/q6.h"
#include "ffx/u4.h"
#include "ffx/v5.h"
#include "ffx/s5.h"

void func_002315E8(void)
{
    TkMn2GetCommonPlate(&D_00325AD0, (int)D_00571E90, (int)D_00571EA0, (int)D_00571EB0, 0, 0); /* DEBT(CAST): names passed as int */
    func_00227460(D_00571EC0, D_00693D68);
    func_002273A0(D_00571ED0, D_00693D70);
    func_002273A0(D_00571EE0, D_00693D78);
    func_00227460(D_00571EF0, D_00693D80);
    func_00227460(D_00571F00, (s16 *)&D_00693D88); /* DEBT(CAST): Pt16s is an s16 pair */
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

INCLUDE_ASM("build/ee_asm/game/menu/tk/tk_2315E8", func_00231F88);

INCLUDE_ASM("build/ee_asm/game/menu/tk/tk_2315E8", func_00232028);

void func_00232158(Task *o, int a1, int a2) { func_002270F8(a1, a2 + ((o->x48 - o->x32) << 5), 0); }

INCLUDE_ASM("build/ee_asm/game/menu/tk/tk_2315E8", func_00232180);

int func_00232348(void) { return 1; }

void func_00232350(void) {
    D_00693D9C = 0;
}

int func_00232360(int a, int i) {
    return func_002317C0(D_00693D60[i], 1) != 0;
}

INCLUDE_ASM("build/ee_asm/game/menu/tk/tk_2315E8", func_00232398);

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

INCLUDE_ASM("build/ee_asm/game/menu/tk/tk_2315E8", func_00232688);

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

INCLUDE_ASM("build/ee_asm/game/menu/tk/tk_2315E8", func_00232B58);

void func_00232C10(void) {
    TkMsSetSaveParamAll();
    func_00232468();
    AtelRegistCallbackQue2(0, TkMn2ArmsRefreshArms, D_00572078);
    TkMn2InitStatusBG();
    func_00227490((int)D_00572068); /* DEBT(CAST): address passed as int */
    func_00227490((int)D_00572070);
    func_00227490((int)D_00571FA0);
}

void func_00232C78(void) {
}

int func_00232C80(void) { return 1; }
