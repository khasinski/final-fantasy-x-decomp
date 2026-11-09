/* tu_262 0x2362b8-0x237888: low; ~TOMenuDrawYesNoWindow (config/tu_map.tsv) */
#include "common.h"
#include "ffx/r5.h"
#include "ffx/w7.h"
#include "ffx/q6.h"
#include "ffx/s5.h"
#include "ffx/u4.h"
#include "ffx/v5.h"

INCLUDE_ASM("build/ee_asm/game/menu/to/to_2362B8", func_002362B8);

int func_00236558(void) { return 1; }

/* old-style definition: callers in this file pass other argument counts (DEBT(TYPE)) */
int func_00236560(text, a, b, c)
    int text, a, b, c;
{
    Task *t = func_00243400();

    D_00326038 = t;
    t->cb = 0;
    t->x1C = 0;
    t->x0C = (s32)func_00236090; /* DEBT(CAST): Task callbacks are typed s32 */
    t->x10 = (s32)func_002362B8;
    t->x14 = (s32)func_00236558;
    t->x30 = 2;
    t->x48 = 1;
    t->b42 = 1;
    t->x3A = 2;
    t->b37 = 1;
    if (a != 0) {
        t->b3E = 2;
    } else {
        t->b3E = 3;
    }
    t->x24 = text;
    t->ext[0] = a;
    t->ext[1] = b;
    t->ext[2] = c;
    t->ext[14] = 1;
    t->ext[15] = 1;
    TkMenuMainRegistWindow(t);
    return (int)t; /* DEBT(TYPE): declared int in funcs.h */
}

int func_00236640(int text, int a, int b, int c)
{
    Task *t = func_00243400();

    D_00326038 = t;
    t->cb = 0;
    t->x1C = 0;
    t->x0C = (s32)func_00236090; /* DEBT(CAST): Task callbacks are typed s32 */
    t->x10 = (s32)func_002362B8;
    t->x14 = (s32)func_00236558;
    t->x30 = 2;
    t->x48 = 1;
    t->x3A = 2;
    t->b42 = 1;
    if (a != 0) {
        t->b3E = 2;
    } else {
        t->b3E = 3;
    }
    t->x24 = text;
    t->ext[0] = a;
    t->ext[1] = b;
    t->ext[2] = c;
    t->ext[14] = 0;
    t->ext[15] = 1;
    TkMenuMainRegistWindow(t);
    return (int)t; /* DEBT(TYPE): declared int in funcs.h */
}

INCLUDE_ASM("build/ee_asm/game/menu/to/to_2362B8", func_00236720);

int func_00236808(int text, int a, int b, int c)
{
    Task *t = func_00243400();

    D_00326038 = t;
    t->cb = 0;
    t->x1C = 0;
    t->x0C = (s32)func_00236090; /* DEBT(CAST): Task callbacks are typed s32 */
    t->x10 = (s32)func_002362B8;
    t->x14 = (s32)func_00236558;
    t->x30 = 2;
    t->x48 = 1;
    t->b42 = 1;
    t->x3A = 2;
    t->b37 = 1;
    if (a != 0) {
        t->b3E = 2;
    } else {
        t->b3E = 3;
    }
    t->x24 = text;
    t->ext[0] = a;
    t->ext[1] = b;
    t->ext[2] = c;
    t->ext[14] = 0;
    t->ext[15] = 2;
    TkMenuMainRegistWindow(t);
    return (int)t; /* DEBT(TYPE): declared int in funcs.h */
}

void TOMenuCloseYesNoWindow(void)
{
    if (D_00326038 != 0) {
        if (D_00326038->ext[15] == 2) {
            TOSeqStopScene(1, D_005723C0);
        }
        D_00326038->b41 = 1;
        D_00326038 = 0;
    }
}

int func_00236940(int a0, int a1, int a2) { return func_00236560(a0, a1, a2, 0); }

int func_00236960(int a0, int a1, int a2) { return func_00236640(a0, a1, a2, 0); }

int func_00236980(int a0, int a1, int a2) { return func_00236720(a0, a1, a2, 0); }

int func_002369A0(int a0, int a1, int a2) { return func_00236808(a0, a1, a2, 0); }

int func_002369C0(void) { return func_00236560(); }

Task *TOMenuGetYesNoWindow(void) {
    return D_00326038;
}

void func_002369F0(void)
{
    Task *t = D_00326030;

    if (t != 0) {
        TkMenuSetHelpMessage(t->ext[t->x48 * 3 + 1]);
    }
}

void func_00236A28(Task *o)
{
    s32 *state;
    u16 a;
    u16 b;
    u16 c;
    int st;
    int r;

    a = func_00220318();
    b = TOMenuGetControlPadRep();
    c = TOMenuGetControlPadTrg();
    o->x46 += o->x38;
    if (o->x46 > 0x1000) {
        o->x46 = 0x1000;
    }
    if (o->x46 < 0) {
        o->x46 = 0;
    }
    st = o->state;
    state = &o->state;
    /* DEBT(GOTO): state machine re-dispatches with goto (no loop alignment in the original) */
again:
    {
        switch (st) {
        case 0:
            TkMenuSetHelpMessage(o->ext[o->x48 * 3 + 1]);
            *state = 2;
            break;
        case 1:
            TkMenuSetHelpMessage(o->ext[o->x48 * 3 + 1]);
            *state = 2;
            break;
        case 2:
            *state = 3;
            break;
        case 3:
            *state = 5;
            break;
        case 4:
            *state = 5;
            break;
        case 5:
            if (o->x46 != 0x1000) {
                return;
            }
            if (c & 0x20) {
                if (o->x1C != 0) {
                    /* DEBT(CAST): x1C holds a callback typed s32 */
                    r = ((int (*)(Task *, int, int))o->x1C)(o, o->x48, o->b45);
                } else {
                    r = 1;
                }
                if (r != 0) {
                    PLAY_SE(0x80000001);
                    *state = 6;
                    break;
                }
                SndSepPlaySimple(0x80000003);
                return;
            } else if (c & 0x40) {
                PLAY_SE(0x80000004);
                *state = 8;
                break;
            } else if ((u16)o->x30 >= 2) {
                if (b & 0x8000) {
                    PLAY_SE(0x80000001);
                    o->x48 -= 1;
                    if (o->x48 < 0) {
                        o->x48 = (u16)o->x30 - 1;
                    }
                    TkMenuSetHelpMessage(o->ext[o->x48 * 3 + 1]);
                    return;
                } else if (b & 0x2000) {
                    PLAY_SE(0x80000001);
                    o->x48 += 1;
                    if (o->x48 >= (u16)o->x30) {
                        o->x48 = 0;
                    }
                    TkMenuSetHelpMessage(o->ext[o->x48 * 3 + 1]);
                    return;
                }
            }
            if (o->b44 == 0) {
                if (func_00242818() < 2) {
                    return;
                }
                if (func_002429D0() == 0) {
                    break;
                }
                if ((b & 4) && a == 4) {
                    PLAY_SE(0x80000004);
                    func_002429F0();
                    return;
                } else if ((b & 8) && a == 8) {
                    PLAY_SE(0x80000004);
                    func_00242980();
                    return;
                }
            } else if (o->b44 == 1) {
                if (TkMenuGetSummonListMax() < 2) {
                    return;
                }
                if (func_002429D0() == 0) {
                    break;
                }
                if ((b & 4) && a == 4) {
                    PLAY_SE(0x80000004);
                    func_00242B18();
                    return;
                } else if ((b & 8) && a == 8) {
                    PLAY_SE(0x80000004);
                    func_00242AE0();
                    return;
                }
            }
            break;
        case 6:
            o->b45 = 1;
            o->x2C = o->x48;
            *state = 7;
            break;
        case 8:
            o->b45 = -1;
            *state = 9;
        case 9:
            st = 10;
            goto again;
        case 10:
            *state = 11;
            break;
        case 14:
            *state = 15;
            break;
        case 15:
            *state = 16;
            break;
        case 16:
            *state = 4;
            break;
        case 7:
        case 11:
        case 12:
        case 13:
        default:
            break;
        }
    }
}

INCLUDE_ASM("build/ee_asm/game/menu/to/to_2362B8", func_00236E60);

INCLUDE_ASM("build/ee_asm/game/menu/to/to_2362B8", func_00237180);

void func_00237398(void) {
}

int func_002373A0(Task *o) {
    func_00201D20(o->ext[14] + 0xF, 0);
    return 1;
}

int func_002373C8(Task *o) { return o->x46 < 1; }

INCLUDE_ASM("build/ee_asm/game/menu/to/to_2362B8", func_002373D8);

void func_002375F8(int a, int b, int c, int d, int e)
{
    D_00326030 = func_002373D8(a, b, c, d, 0x17D, e);
    D_00326030->x4A = 0x11;
    D_00326030->x4C = 0x25;
}

void func_00237630(int a, int b, int c, int d, int e, int f)
{
    D_00326030 = func_002373D8(a, b, c, d, f, e);
    D_00326030->x4A = 0x11;
    D_00326030->x4C = 0x25;
}

void func_00237670(Task *o) { o->x4A = (0x200 - o->x4E) / 2; }

void func_00237690(void) {
    if (D_00326030) {
        func_00237670(D_00326030);
    }
}

Task *func_002376B0(int a, int b, int c, int d, int e)
{
    int y = 0x165;
    int x;

    if (D_00326030 != 0) {
        y = D_00326030->x4E;
        y = y - 0x18; /* DEBT(ORDER): split found by the permuter */
        y -= D_00326030->ext[D_00326030->x48 * 3 + 2];
    }
    D_00326034 = func_002373D8(a, b, c, d, y, e);
    D_00326034->x46 = 0;
    D_00326034->b3E = 3;
    D_00326034->b3F = 0;
    D_00326034->x14 = (s32)func_002373C8; /* DEBT(CAST): Task callbacks are typed s32 */
    D_00326034->x10 = (s32)func_00237180;
    if (D_00326030 != 0) {
        x = D_00326030->x4A + D_00326030->x4E - D_00326034->x4E;
    } else {
        x = 0x30;
    }
    D_00326034->ext[15] = 1;
    D_00326034->x4A = x;
    D_00326034->x4C = 0x25;
    D_00326034->ext[14] = -1;
    return D_00326034;
}

void func_00237790(int v) {
    if (D_00326030) {
        D_00326030->b45 = 1;
        D_00326030->x2C = v;
        D_00326030->x48 = v;
        D_00326030->state = 6;
    }
}

void func_002377C8(void) {
    if (D_00326030) {
        D_00326030->b45 = 0;
        D_00326030->state = 1;
    }
}

void func_002377F0(void) {
    if (D_00326034) {
        D_00326034->b45 = 0;
        D_00326034->state = 1;
    }
}

void func_00237818(void) {
    if (D_00326030) {
        D_00326030->b41 = 1;
        D_00326030 = 0;
    }
}

void func_00237838(void) {
    if (D_00326034) {
        D_00326034->b41 = 1;
        D_00326034 = 0;
    }
}

void func_00237858(int v) {
    if (D_00326030) {
        D_00326030->x38 = v;
    }
}

void func_00237870(int v) {
    if (D_00326034) {
        D_00326034->x38 = v;
    }
}
