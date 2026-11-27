#include "common.h"

extern u8 *D_01B0A5F0;

extern void func_01B052B8(s32, void *, void *);

static inline void copy_vec(void *dst, void *src) {
    __asm__ volatile("lq $7, 0(%0)" : : "r"(src), "r"(dst) : "$7", "memory");
    __asm__ volatile("sq $7, 0(%0)" : : "r"(dst) : "memory");
}

static inline void wrap_angle(float *p, float d) {
    float a = *p + d;
    if (a > 3.1415927f) {
        a -= 6.2831855f;
    } else if (a < -3.1415927f) {
        a += 6.2831855f;
    }
    *p = a;
}

static inline void lerp_vec(void *dst, float *a, float *b, float t) {
    float v[4];
    float u = 1.0f - t;
    s32 i;
    for (i = 0; i < 3; i++) {
        v[i] = b[i] * u + a[i] * t;
    }
    v[3] = 1.0f;
    copy_vec(dst, v);
}

void func_01B027E0(void)
{
    u8 *t0 = D_01B0A5F0;
    float t;

    if (*(s32 *)(t0 + 0x1F24) > 0) {
        *(s32 *)(t0 + 0x1F24) -= 1;
        t = (float)(*(s32 *)(t0 + 0x1F24)) / 45.0f;
    } else {
        t = 1.0f;
    }
    lerp_vec(t0 + 0x1C00, (float *)(t0 + 0x1C30), (float *)(t0 + 0x1C40), t);
    wrap_angle((float *)(t0 + 0x1BF0), 0.9424779f);
    func_01B052B8(1, t0 + 0x1BB0, t0 + 0x1BF0);
}
