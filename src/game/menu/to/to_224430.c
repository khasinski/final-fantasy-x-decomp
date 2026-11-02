/* tu_249 0x224430-0x224930: medium; ~TkMenuCtrlWorldMap (config/tu_map.tsv) */
#include "common.h"
#include "ffx/r5.h"
#include "ffx/q5.h"
#include "ffx/w7.h"
#include "ffx/s5.h"
#include "ffx/u3.h"
#include "ffx/v5.h"

void TkMenuCtrlWorldMap(Task *o)
{
    s32 *state = &o->x1C;
    u16 trig;

    func_00220318();
    TOMenuGetControlPadRep();
    trig = TOMenuGetControlPadTrg();
    switch (o->x1C) {
    case 0:
        *state = 1;
        break;
    case 1:
        if (func_0020CDB8() == 0) {
            *state = 2;
        }
        break;
    case 2:
        func_0020CD30(0x12, 0x17, 0x800000);
        *state = 3;
        break;
    case 3:
        if (func_0020CDB8() == 0) {
            TOTransImageHL(0x800000, 0x3800, 0x13, 0, 0, 0x200, 0x1A0);
            *state = 4;
        }
        break;
    case 4:
        func_00224608();
        *state = 5;
        break;
    case 5:
        if (func_00224910() == 0x80) {
            *state = 6;
        }
        break;
    case 6:
        *state = 7;
        break;
    case 7:
        if (trig & 0x40) {
            PLAY_SE(0x80000004);
            *state = 8;
        }
        break;
    case 8:
        TOSeqStopScene(1, D_005712E0);
        func_00224920(-6);
        *state = 9;
        break;
    case 9:
        if (func_00224910() == 0) {
            *state = 10;
        }
        break;
    case 10:
        func_00224698();
        TkMenuMainSleepMenu(0x17);
        break;
    }
}

void func_002245E0(void) {
}

void func_002245E8(void) {
}

void func_002245F0(Task *o) { o->x1C = 0; }

void func_002245F8(void) {
}

void func_00224600(void) {
}

Task * func_00224608(void)
{
    Task *t = func_00243400();

    D_00693360 = t;
    t->x14 = 0;
    t->x1C = 0;
    t->ext[3] = 0;
    t->cb = func_002246B8;
    t->x0C = (s32)func_002246C0;
    t->x10 = (s32)TOMenuDrawWorldMapWindow;
    t->b3E = 0x7;
    t->ext[0] = 0x80;
    t->ext[1] = 0x80;
    t->ext[2] = 0x80;
    t->ext[4] = 0x6;
    TkMenuMainRegistWindow(t);
    return t;
}

void func_00224698(void)
{
    if (D_00693360 != 0) {
        D_00693360->b41 = 1;
        D_00693360 = 0;
    }
}

void func_002246B8(void) {
}

void func_002246C0(Task *o) {
    o->ext[3] += o->ext[4];
    if (o->ext[3] < 0) {
        o->ext[3] = 0;
    }
    if (o->ext[3] > 0x80) {
        o->ext[3] = 0x80;
    }
}

INCLUDE_ASM("build/ee_asm/game/menu/to/to_224430", TOMenuDrawWorldMapWindow);

s32 func_00224910(void)
{
    return D_00693360->ext[3];
}

void func_00224920(s32 v)
{
    D_00693360->ext[4] = v;
}
