#include "common.h"

extern u8 D_01B00A90[];
extern u8 D_01B0A508[];
extern u8 D_01B0A5B0[];
extern u8 *D_01B0A5F0;

extern void func_01B04D38(s32, void *);
extern void func_01B052B8(s32, void *, void *);
extern void func_01B054B0(s32, void *, void *);
extern s32 func_01B063E8(void *, void *, s32, s32, s32, s32, float);
extern void func_01B09C50(void *, s32, s32, float, float);

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

void func_01B03528(void)
{
    u8 *s0 = D_01B0A5F0;

    if (*(s32 *)(s0 + 0x1F2C) > 0) {
        float t;
        *(s32 *)(s0 + 0x1F2C) -= 1;
        t = (float)(*(s32 *)(s0 + 0x1F2C)) / 20.0f;
        lerp_vec(s0 + 0x1BA0, (float *)(s0 + 0x1C30), (float *)(s0 + 0x1C10), t);
        wrap_angle((float *)(s0 + 0x1B94), 0.31415927f);
        func_01B052B8(-1, s0 + 0x1B50, s0 + 0x1B90);

        if (*(s32 *)(s0 + 0x1F2C) == 0) {
            func_01B04D38(-1, 0);
            func_01B054B0(-1, D_01B0A5B0, D_01B00A90);
            func_01B063E8(D_01B0A508, s0, 0, 0, 0, 0, 0.02f);
            copy_vec(s0 + 0xD0, s0 + 0x1C10);
            *(float *)(s0 + 0xC4) = *(float *)(s0 + 0x1F10);
            *(float *)(s0 + 0xD4) -= 0.5f;
            func_01B09C50(s0 + 0x1E10, 30, 0, 0.5f, 1.0f);
        }
    }
}
