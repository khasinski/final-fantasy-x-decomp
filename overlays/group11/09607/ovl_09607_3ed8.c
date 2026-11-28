#include "common.h"

extern u8 *D_01B0BC98;
extern void *D_01B0BC9C;

extern void func_00173CD8(void *, void *, void *, s32, unsigned long, unsigned long, float);
extern u8 *func_01B06F90(void *);
extern void func_01B07158(void *);
extern void func_01B03E58(void);
extern void func_01B03168(void);

typedef struct {
    u8 pad00[0x10];
    s32 w[20];
} Item3ED8;

void func_01B03ED8(void) {
    u8 *s = D_01B0BC98;
    u8 *v1;
    Item3ED8 *it;
    float ang;
    s32 i;
    u8 *t;

    func_00173CD8(D_01B0BC9C, s + 0x2B80, s + 0x2B90, 0x80, 0x201D0UL, 0x007F0000007F0000UL, 1.0f);

    v1 = s + 0x2EC0;
    *(float *)(v1 + 0x770) = 0.0f;
    ang = *(float *)(s + 0x2B04) - 1.2217306f;
    if (ang > 3.1415927f) {
        ang -= 6.2831855f;
    } else if (ang < -3.1415927f) {
        ang += 6.2831855f;
    }
    *(float *)(v1 + 0x774) = ang;
    *(s32 *)(v1 + 0x7A0) = 0x5B;
    *(s32 *)(v1 + 0x778) = 0;
    *(s32 *)(v1 + 0x77C) = 0;
    *(s32 *)(v1 + 0x780) = 0;
    *(s32 *)(v1 + 0x784) = 0;
    *(s32 *)(v1 + 0x788) = 0;
    *(s32 *)(v1 + 0x78C) = 0;

    it = (Item3ED8 *)v1;
    for (i = 0x11; i >= 0; i--, it++) {
        it->w[0] = 0;
        it->w[1] = 0;
        it->w[2] = 0;
        it->w[3] = 0;
        it->w[4] = 0;
        it->w[5] = 0;
        it->w[6] = 0;
        it->w[7] = 0;
        it->w[8] = 0;
        it->w[9] = 0;
        it->w[10] = 0;
        it->w[11] = 0;
        it->w[12] = 0;
        it->w[13] = 0;
        it->w[14] = 0;
        it->w[15] = 0;
        it->w[16] = 0;
        it->w[17] = 0;
        it->w[18] = 0;
        it->w[19] = 0;
    }

    *(s32 *)(v1 + 0x7A4) = 0;
    t = func_01B06F90((void *)func_01B03E58);
    func_01B07158(t);
    *(u8 **)(s + 0x3BF0) = t;

    t = func_01B06F90((void *)func_01B03168);
    *(u16 *)(t + 0x14) = 0;
    *(u16 *)(t + 0x16) = 0;
    func_01B07158(t);
}
