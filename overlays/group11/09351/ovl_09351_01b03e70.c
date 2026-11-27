#include "common.h"

void func_01B03E70(u8 *a0)
{
    float f;

    if (*(int *)(a0 + 0x118) > 0x50) {
        *(int *)(a0 + 0x104) = 0;
    }
    f = *(float *)(a0 + 0x60) + 0.00067500007f;
    *(float *)(a0 + 0x60) = f;
    *(float *)(a0 + 0x6C) = f;
    *(float *)(a0 + 0x68) = f;
    __asm__ volatile("");
    *(float *)(a0 + 0x64) = f;
}
