#include "common.h"

extern u8 *D_01B0B398;

void func_01B02800(u8 *arg0) {
    u8 *p = D_01B0B398 + 0x5C30;

    if (*(s32 *)(p + 0x2908) == *(s32 *)(p + 0x290C)) {
        *(s32 *)(p + 0x2910) = 1;
        arg0[0x56] = 1;
    }
}
