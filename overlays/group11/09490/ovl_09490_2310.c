#include "common.h"

extern u8 *D_01B0B398;

void func_01B02310(u8 *arg0) {
    u8 *p = D_01B0B398 + 0x30B0;

    if (*(s32 *)(p + 0x2B6C) == *(s32 *)(p + 0x2B70)) {
        *(s32 *)(p + 0x2B74) = 1;
        arg0[0x56] = 1;
    }
}
