#include "common.h"

extern u16 D_01B12E90[];
extern u16 D_01B12E98[];
extern u16 D_01B12EA0[];

extern u16 func_002D28E8(s32, s32, s32);
extern u16 func_002D2938(s32, s32, s32);
extern u16 func_002D2978(s32, s32, s32);
extern s32 func_002D4128(void);

void func_01B0AA00(void) {
    s32 i;
    s32 j;
    s32 n;

    n = func_002D4128();
    for (i = 0; i < 2; i++) {
        u16 a = 0;
        u16 b = 0;
        u16 c = 0;

        for (j = 1 - n; j <= 0; j++) {
            a |= func_002D28E8(i, 0, j);
            b |= func_002D2938(i, 0, j);
            c |= func_002D2978(i, 0, j);
        }
        D_01B12E90[i] = a;
        D_01B12E98[i] = b;
        D_01B12EA0[i] = c;
    }
}
