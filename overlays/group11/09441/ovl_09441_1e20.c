#include "common.h"

extern u8 *D_01B093A8;

extern float func_01B067C0(float, float, float, float, float, float);

void func_01B01E20(void) {
    float tmp[4];
    u8 *s = D_01B093A8;
    s32 rem;
    float t;
    float *p0;
    float *p1;
    float *dst;
    s32 i;

    rem = *(s32 *)(s + 0x2490);
    if (rem > 0) {
        rem--;
        *(s32 *)(s + 0x2490) = rem;
    }

    t = (float)rem / 120.0f;
    dst = tmp;
    p1 = (float *)(s + 0x1900);
    p0 = (float *)(s + 0x1910);
    for (i = 0; i < 3; i++) {
        float diff = p1[i] - p0[i];
        dst[i] = p0[i] + func_01B067C0(diff, diff * 0.99f, diff * 0.9f, diff * 0.5f, 0.0f, t);
    }

    *(float *)(s + 0xD0) = tmp[0];
    *(float *)(s + 0xD8) = tmp[2];
}
