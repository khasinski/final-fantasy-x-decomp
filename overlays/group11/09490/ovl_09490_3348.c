#include "common.h"

extern u8 *D_01B0B398;

void func_01B03348(u8 *arg0) {
    u8 *p = D_01B0B398 + 0x8550;

    if (*(s32 *)(p + 0x520C) == *(s32 *)(p + 0x5210)) {
        *(s32 *)(p + 0x5214) = 1;
        arg0[0x56] = 1;
    }
}
