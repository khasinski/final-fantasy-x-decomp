#include "common.h"

extern u8 *D_01B0A1E0;

void func_01B02A20(void)
{
    u8 *v1 = D_01B0A1E0;
    *(float *)(v1 + 0xA54) -= 15.0f;
}

void func_01B02A40(void)
{
    u8 *v1 = D_01B0A1E0;
    float f = *(float *)(v1 + 0xA84) - *(float *)(v1 + 0xA94);

    *(float *)(v1 + 0xA84) = f;
    *(float *)(v1 + 0xA54) -= f;
}

void func_01B02A68(void)
{
    *(int *)(D_01B0A1E0 + 0x3154) = 0;
}
