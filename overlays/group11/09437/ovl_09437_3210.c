#include "common.h"

extern u8 D_01B06988[];
extern u8 D_01B0A508[];
extern u8 *D_01B0A5F0;

extern void func_01B02F78(void);
extern s32 func_01B04408(s32);
extern void func_01B04790(s32, s32);
extern s32 func_01B063E8(void *, void *, s32, s32, s32, void *, float);
extern void func_01B06858(void *, void *);
extern void func_01B09A98(void *, s32);

static inline void copy_vec(void *dst, void *src) {
    __asm__ volatile("lq $7, 0(%0)" : : "r"(src), "r"(dst) : "$7", "memory");
    __asm__ volatile("sq $7, 0(%0)" : : "r"(dst) : "memory");
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

void func_01B03210(void)
{
    u8 *s2 = D_01B0A5F0;
    float t;

    if (*(s32 *)(s2 + 0x1F24) > 0) {
        func_01B02F78();
        *(s32 *)(s2 + 0x1F24) -= 1;
        t = (float)(*(s32 *)(s2 + 0x1F24)) / 12.0f;
    } else {
        t = 1.0f;
    }
    lerp_vec(s2 + 0x1C00, (float *)(s2 + 0x1C30), (float *)(s2 + 0x1C40), t);

    if (*(s32 *)(s2 + 0x1F24) == 0) {
        s32 idx;
        u8 *s0;
        u8 *f;

        func_01B06858(D_01B0A508, s2 + 0x130);
        idx = func_01B04408(0) == 0 ? 4 : 3;
        s0 = s2 + idx * 0x130;
        func_01B063E8(D_01B0A508, s0, idx, 0, 0, D_01B06988, 0.02f);
        copy_vec(s0 + 0xD0, s2 + 0x1C40);
        *(float *)(s0 + 0xC4) = *(float *)(s2 + 0x1F10);

        f = s2 + 0x1C60;
        f[0x82] = 0xFF;
        f[0x81] = 0xFF;
        f[0x80] = 0xFF;
        f[0x83] = 0x80;
        f[0x84] = 0xFF;
        f[0x85] = 0xFF;
        f[0x86] = 0xFF;
        f[0x87] = 0;
        *(s32 *)(f + 0x88) = 0;
        f[0x98] = 0x48;
        f[0x99] = 0;
        func_01B09A98(f, 0x14);
        func_01B04790(1, 0);
        *(s32 *)(s2 + 0x1F24) -= 1;
    }
}
