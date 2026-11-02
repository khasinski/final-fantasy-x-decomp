/* tu_261 0x235c38-0x2362b8: low; unk_235C38 (config/tu_map.tsv) */
#include "common.h"
#include "ffx/r5.h"
#include "ffx/w7.h"
#include "ffx/q6.h"
#include "ffx/s5.h"
#include "ffx/u4.h"
#include "ffx/v5.h"

void func_00235C38(Task *o)
{
    s32 *state = &o->state;
    u16 trig;
    u16 held;
    int st;

    func_00220318();
    held = TOMenuGetControlPadRep();
    trig = TOMenuGetControlPadTrg();
    st = o->state;
    /* DEBT(GOTO): state machine re-dispatches with goto (no loop alignment in the original) */
again:
    {
        switch (st) {
        case 0:
            o->x48 = 1;
            o->b45 = 0;
            if (o->ext[0] != 0) {
                *state = 1;
            } else if (o->ext[14] == 1) {
                *state = 2;
            } else {
                *state = 3;
            }
            return;
        case 1:
            if (trig & 0x20) {
                PLAY_SE(0x80000001);
                st = 4;
                goto again;
            }
            if (trig & 0x40) {
                PLAY_SE(0x80000004);
                st = 6;
                goto again;
            }
            if (held & 0x5000) {
                PLAY_SE(0x80000001);
                o->x48 = o->x48 == 0;
            }
            return;
        case 2:
            if (trig == 0) {
                return;
            }
            if (o->b37 != 0) {
                PLAY_SE(0x80000001);
            }
        case 3:
            *state = 4;
            return;
        case 4:
            o->b45 = 1;
            o->x2C = o->x48;
            *state = 5;
            st = 5;
            goto again;
        case 6:
            o->x2C = (o->b45 = 1);
            o->x48 = 1;
            *state = 7;
            st = 7;
            goto again;
        case 5:
        case 7:
        default:
            return;
        }
    }
}

INCLUDE_ASM("build/ee_asm/game/menu/menu_235C38", func_00235DC8);

int func_00235F48(void) { return 1; }

INCLUDE_ASM("build/ee_asm/game/menu/menu_235C38", func_00235F50);

void func_00236020(void)
{
    if (D_0032602C) {
        D_0032602C->b41 = 1;
        D_0032602C = 0;
    }
}

int func_00236040(int a0, int a1, int a2) { return func_00235F50(a0, a1, a2, 0); }

int func_00236060(void) { return func_00235F50(); }

Task *func_00236080(void) {
    return D_0032602C;
}

void func_00236090(Task *o)
{
    s32 *state = &o->state;
    u16 trig;
    u16 held;
    int st;

    func_00220318();
    held = TOMenuGetControlPadRep();
    trig = TOMenuGetControlPadTrg();
    st = o->state;
    /* DEBT(GOTO): state machine re-dispatches with goto (no loop alignment in the original) */
again:
    {
        switch (st) {
        case 0:
            o->x48 = 1;
            o->b45 = 0;
            if (o->ext[0] != 0) {
                *state = 1;
            } else if (o->ext[14] == 1) {
                *state = 2;
            } else {
                *state = 3;
            }
            return;
        case 1:
            if (trig & 0x20) {
                if (o->b37 != 0) {
                    PLAY_SE(0x80000001);
                }
                st = 4;
                goto again;
            }
            if (trig & 0x40) {
                PLAY_SE(0x80000004);
                st = 6;
                goto again;
            }
            if (held & 0x5000) {
                PLAY_SE(0x80000001);
                o->x48 = o->x48 == 0;
            }
            return;
        case 2:
            if (trig == 0) {
                return;
            }
            PLAY_SE(0x80000001);
            st = 4;
            *state = st;
            return;
        case 3:
            *state = 4;
            return;
        case 4:
            o->b45 = 1;
            o->x2C = o->x48;
            *state = 5;
            st = 5;
            goto again;
        case 6:
            o->x2C = 1;
            o->b45 = -1;
            *state = 7;
            st = 7;
            goto again;
        case 5:
        case 7:
        default:
            return;
        }
    }
}

int func_00236228(Task *t)
{
    int w;
    int h;

    _TOGetMessageWH(0, (u8 *)t->x24, (s16 *)&w, (s16 *)&h, 0, 0); /* DEBT(CAST): text pointer in x24, sizes filled as words here */
    if (t->ext[0] != 0) {
        h += 0x30;
    }
    h += 0x10;
    if (t->ext[15] != 0) {
        h += 0xA;
        if (h < 30) {
            h = 30;
        }
    }
    return h;
}
