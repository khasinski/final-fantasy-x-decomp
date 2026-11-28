#include "common.h"

extern u8 *func_01B04400(void *, void *);
extern int func_002EFD78(void);
extern float func_002D56C0(float);

void func_01B017C8(void *a0, void *a1, float *s1)
{
    u8 *s0 = func_01B04400(a0, a1);
    float f;

    if (s0 == 0) {
        return;
    }
    *(int *)(s0 + 0x34) = 0x10;
    *(float *)(s0 + 0x10) = s1[0];
    *(float *)(s0 + 0x14) = s1[1];
    *(float *)(s0 + 0x18) = s1[2];

    *(float *)(s0 + 0x20) = ((float)(func_002EFD78() & 0x7FFF) / 32767.0f - 0.5f) * 2.0f * 0.75f;
    *(float *)(s0 + 0x24) = ((float)(func_002EFD78() & 0x7FFF) / 32767.0f - 0.5f) * 2.0f * 0.75f;
    *(float *)(s0 + 0x28) = ((float)(func_002EFD78() & 0x7FFF) / 32767.0f - 0.5f) * 2.0f * 0.75f;

    f = func_002D56C0(((float)(func_002EFD78() & 0x7FFF) / 32767.0f) * 360.0f);
    *(float *)(s0 + 0x74) = f;
    *(float *)(s0 + 0x70) = 0.1875f;
    *(int *)(s0 + 0x78) = 24;
    *(int *)(s0 + 0x7C) = 7;
    *(int *)(s0 + 0x80) = 6;
    *(float *)(s0 + 0x84) = 1.0f;
}
