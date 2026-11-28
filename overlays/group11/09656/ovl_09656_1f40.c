#include "common.h"

extern u8 *D_01B0A988;
extern u8 D_01B0A860[];

extern void **func_01B06678(void *, s32);
extern float func_01B03C18(s32);
extern void func_002DD0C0(void *, void *);
extern void func_01B07098(void *, float);
extern u8 *func_01B09EB8(void);
extern void func_01B074B0(void *, void *);
extern void func_002DCE08(void *, void *, void *);
extern float func_002B3DB0(float);
extern float func_002B3DF8(float);
extern void func_01B05E08(void *);

static inline void copy_vec(void *dst, void *src) {
    __asm__ volatile("lq $7, 0(%0)" : : "r"(src), "r"(dst) : "$7", "memory");
    __asm__ volatile("sq $7, 0(%0)" : : "r"(dst) : "memory");
}

void func_01B01F40(u8 *s3) {
    float sp0[12];
    float sp30[4];
    s32 mask = *(s16 *)(s3 + 0x16) <= 0x59 ? 0xF : 1;
    s32 c = *(u16 *)(s3 + 0x14) + 1;

    *(u16 *)(s3 + 0x14) = c;
    if ((mask & c) == 0) {
        u8 *base = D_01B0A988;
        void *s6 = *func_01B06678(D_01B0A860, 9);
        u8 *s1 = base + 0x2EC0;
        float fs0f = func_01B03C18(-1) - 1.0f;
        s32 i, j;

        func_002DD0C0(sp0, base + 0x35A0);
        copy_vec(sp30, base + 0x3620);
        func_01B07098(sp0, 0.045f);

        for (i = 0; i < 18; s1 += 0x60, i++) {
            for (j = 0; j < 1; j++) {
                u8 *p = func_01B09EB8();
                if (p == 0) {
                    break;
                }
                func_01B074B0(p + 0x30, s6);
                func_002DCE08(p, sp0, s1);
                *(float *)(p + 0x0) += func_002B3DB0(10.0f);
                *(float *)(p + 0x4) += func_002B3DB0(4.0f) - 5.0f;
                *(float *)(p + 0x8) += func_002B3DB0(10.0f);
                *(float *)(p + 0x10) = func_002B3DB0(0.2f);
                *(float *)(p + 0x14) = func_002B3DB0(0.1f) + -0.3f;
                *(float *)(p + 0x18) = func_002B3DB0(0.2f);
                *(float *)(p + 0x1C) = func_002B3DB0(3.1415927f);
                *(u32 *)(p + 0x20) = 0;
                *(u32 *)(p + 0x28) = 0;
                *(float *)(p + 0x2C) = 1.0f;
                *(float *)(p + 0x24) = 0.0001f;
                *(float *)(p + 0x3C) = (func_002B3DF8(0.5f) + 1.0f) * 0.35f;
                *(s32 *)(p + 0x4C) = 0x20;
                *(s32 *)(p + 0x50) = 0x10;
                *(s32 *)(p + 0x54) = -0x10;
                p[0x67] = 0x40;
                p[0x6B] = 0;
                *(u32 *)(p + 0x60) = 0;
                if (fs0f < *(float *)(p + 0x4)) {
                    *(float *)(p + 0x4) = fs0f - 1.0f;
                }
            }
        }
    }

    *(s16 *)(s3 + 0x16) += 1;
    if (*(s16 *)(s3 + 0x16) >= 0x60) {
        func_01B05E08(s3);
    }
}
