#include "common.h"

extern s32 D_01B00748[];
extern s32 D_01B0A5C4;
extern s32 D_01B0A5E4;
extern u8 *D_01B0A5F0;
extern u8 D_01B12470[];

extern s32 func_001B4E18(s32);
extern s32 func_001E4E30(void);
extern void func_01B00FD0(void);
extern float func_01B039A0(s32);
extern void func_01B03AC8(s32, void *, s32);
extern void func_01B05A18(void *, s32, s32);

void func_01B01D98(void)
{
    u8 *s1 = D_01B0A5F0;
    s32 s0;

    func_01B03AC8(-1, s1 + 0x1C10, 0);
    *(float *)(s1 + 0x1F10) = func_01B039A0(-1);
    s0 = func_001E4E30();
    if (s0 >= 0) {
        s32 v;
        *(s32 *)(s1 + 0x1F18) = s0;
        *(s32 *)(s1 + 0x1F1C) = func_001B4E18(s0);
        v = D_01B00748[s0];
        *(s32 *)(s1 + 0x1F20) = v;
        func_01B05A18(D_01B12470, v, 0);
    } else {
        *(s32 *)(s1 + 0x1F1C) = -1;
    }
    *(s32 *)(s1 + 0x1F30) = 0;
    *(s32 *)(s1 + 0x1F14) = -1;
    D_01B0A5C4 = 1;
    D_01B0A5E4 = 1;
    func_01B00FD0();
}
