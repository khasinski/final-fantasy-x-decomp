#include "common.h"

extern u8 *D_01B0AB88;

extern void func_01B03DE0(s32);

void func_01B022B8(u8 *a0) {
    if (*(s32 *)(a0 + 0x118) >= 84) {
        u8 *s = D_01B0AB88;
        func_01B03DE0(0);
        *(float *)(s + 0x1844) += 0.038f;
        *(float *)(a0 + 0xD4) += *(float *)(s + 0x1844);
    }
}
