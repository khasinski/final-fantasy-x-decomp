#include "common.h"

typedef struct {
    u16 h00;
    s16 h02;
} Cmd4;

typedef struct {
    Cmd4 *p00;
    s32 w04;
    s32 idx08;
    s32 state0C;
    s16 h10;
    u16 h12;
} Obj18A8;

extern s32 func_001CE1A8(s32);
extern void func_01B01A08(void *, s32);
extern void func_001CE050(s32, u32);
extern void func_01B01A38(void *, s32);

s32 ovl_09088_18a8(Obj18A8 *s1)
{
    s32 ready;

    if (s1->state0C == 1) {
        return 1;
    }

    if ((s16)s1->h10 == 0) {
        s1->h12++;
        ready = func_001CE1A8(s1->w04);
    } else {
        s1->h10--;
        ready = (s1->h10 == 0);
    }

    if (ready != 0) {
        Cmd4 *s0;
        s1->idx08++;
        s0 = &s1->p00[s1->idx08];
        if (s0->h00 == 0xFFFE) {
            func_01B01A08(s1, s0->h02);
            s1->idx08++;
            s0 = &s1->p00[s1->idx08];
        }
        if (s0->h00 != 0xFFFF) {
            func_001CE050(s1->w04, s0->h00);
        }
        switch (s0->h02) {
        case -1:
            func_01B01A38(s1, 0);
            break;
        case -2:
            s1->h10 = 0;
            s1->h12 = 0;
            break;
        case -3:
            func_01B01A38(s1, 1);
            break;
        case -4:
            s1->state0C = 1;
            break;
        default:
            s1->h10 = s0->h02;
            break;
        }
    }

    return s1->state0C;
}
