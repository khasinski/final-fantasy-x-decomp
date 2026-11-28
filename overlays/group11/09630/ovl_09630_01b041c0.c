#include "common.h"

extern u8 *D_01B0C0B0;

void func_01B041C0(void)
{
    u8 *p = D_01B0C0B0;
    float f = *(float *)(p + 0x924) + 0.5f;
    *(float *)(p + 0x924) = f;
    *(float *)(p + 0x944) = f;
}
