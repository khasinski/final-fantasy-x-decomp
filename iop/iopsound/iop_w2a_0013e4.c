#include "iopsound.h"

extern u32 D_018790[];
extern u32 D_0187C0[];

s32 func_0013E4(s32 a0, s32 a1, s32 a2, s32 a3) {
    s32 semi;
    s32 pitch;

    a1 = (a0 >> 12) + a1 + (a2 >> 16);
    a2 = 0;
    while (a1 < 0) {
        a1 += 3072;
        a2--;
    }
    semi = (a1 >> 8) & 0x7f;
    a1 &= 0xff;
    a2 += semi / 12;
    semi %= 12;
    pitch = ((D_018790[semi] >> (10 - a2)) * D_0187C0[a1]) >> 16;
    if (a3 != 0) {
        if (a3 > 0) {
            a1 = (pitch * (a3 + 1)) >> 7;
            pitch += a1;
        } else {
            pitch *= (a3 & 0xff);
            pitch >>= 8;
        }
    }
    return pitch;
}
