#include "iopsound.h"

extern volatile u32 D_018708;

s32 func_0108F0(s32 *arg) {
    if (*arg != 0) {
        D_018708 |= 1;
    } else {
        D_018708 &= ~1;
    }
    return *arg;
}

s32 func_010934(s32 *arg) {
    if (*arg != 0) {
        D_018708 |= 0x10000;
    } else {
        D_018708 &= ~0x10000;
    }
    return *arg;
}
