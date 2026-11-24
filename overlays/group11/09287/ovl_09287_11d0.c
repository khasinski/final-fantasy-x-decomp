#include "common.h"

typedef struct {
    s32 w00;
    s32 count;
} Hdr618;

typedef struct {
    u8 pad00[0xC4];
    float fC4;
    u8 padC8[0x8];
    float vecD0[4];
    u8 padE0[0x8];
    float fE8;
    u8 padEC[0x2C];
    s32 w118;
    u8 pad11C[0x14];
} Obj130;

extern Hdr618 D_01B00618;
extern Obj130 D_01B06010[];

extern float func_01B01598(s32);
extern void func_01B01B60(s32, s32, s32, void *);

void ovl_09287_11d0(void)
{
    s32 i;
    Obj130 *s1 = D_01B06010;

    for (i = 0; i < D_01B00618.count; i++, s1++) {
        float ang = func_01B01598(-1) + 3.1415927f;
        if (ang > 3.1415927f) {
            ang -= 6.2831855f;
        } else if (ang < -3.1415927f) {
            ang += 6.2831855f;
        }
        s1->fC4 = ang;
    }
}

void ovl_09287_12a8(Obj130 *s0)
{
    if (s0->w118 == 0) {
        func_01B01B60(-1, 6, 0, s0->vecD0);
        s0->fC4 = func_01B01598(-1);
        s0->fE8 = -30.0f;
    }
}
