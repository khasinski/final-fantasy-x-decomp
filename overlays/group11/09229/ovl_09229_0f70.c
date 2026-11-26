#include "common.h"

extern s32 D_01B00450;
extern s32 D_01B00454;
extern s32 D_01B00458;
extern s32 D_01B01A30;
extern s32 D_01D01C00;
extern s32 D_01D01C04;
extern void *D_01D01C08;

extern void func_00107428(void *, s32, s32, float *);
extern s32 func_001CDAF8(s32);
extern void func_001CDC58(s32, s32);
extern void func_001CE050(s32, s32);
extern s32 func_0029B830(s32);
extern void func_01B00D80(float *);

s32 ovl_09229_0f70(void)
{
    float mat[16];
    float v0[4];
    float pos[4];

    if (D_01B00450 == 0) {
        if (func_0029B830(D_01B01A30) != 0) {
            return 0;
        }
        D_01B00450++;
    }
    if (D_01B00454 == 0) {
        D_01B00454 = 1;
        func_001CDC58(D_01B01A30, 0);
    }
    if (D_01B00458 == 0) {
        if (func_001CDAF8(D_01B01A30) <= 0) {
            return 0;
        }
        D_01B00458++;
    }
    if (D_01D01C00 == 0x24) {
        func_001CE050(D_01D01C04, 0xC9);
    } else if (D_01D01C00 == 0x8F) {
        func_001CE050(D_01D01C04, 0xCA);
    } else if (D_01D01C00 == 0xA1) {
        func_001CE050(D_01D01C04, 0xCB);
    }
    if ((u32)(D_01D01C00 - 0x28) < 0x23) {
        func_00107428(D_01D01C08, 0x11, 0, pos);
        func_01B00D80(pos);
    }
    (void)mat;
    (void)v0;
    return 0;
}
