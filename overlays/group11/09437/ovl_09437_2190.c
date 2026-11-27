#include "common.h"

extern u8 D_01B0A508[];
extern u8 *D_01B0A5F0;

extern float func_002B3DB0(float);
extern void func_01B03AC8(s32, void *, s32);
extern float func_01B03E38(s32);
extern s32 func_01B063E8(void *, void *, s32, s32, s32, s32, float);
extern void func_01B07220(void *, void *, void *);

static inline void copy_vec(void *dst, void *src) {
    __asm__ volatile("lq $7, 0(%0)" : : "r"(src), "r"(dst) : "$7", "memory");
    __asm__ volatile("sq $7, 0(%0)" : : "r"(dst) : "memory");
}

void func_01B02190(void)
{
    u8 *s0 = D_01B0A5F0;
    float v0[4];
    float v1[4];
    u8 *s2 = s0 + 0x1C20;
    u8 *s3;
    float r;

    v0[0] = 0.0f;
    v0[1] = *(float *)(s0 + 0x1F10);
    v0[2] = 0.0f;
    v1[0] = 0.0f;
    v1[1] = 0.0f;
    v1[2] = func_01B03E38(0) + 35.0f;
    func_01B03AC8(0, s2, 3);
    *(float *)(s0 + 0x1C24) = *(float *)(s0 + 0x1C14);
    func_01B07220(v0, s2, v1);
    copy_vec(s0 + 0x1BA0, s2);

    s3 = s0 + 0xE40;
    r = (func_002B3DB0(0.2f) + 1.0f) * 0.0125f;
    func_01B063E8(D_01B0A508, s3, 9, 0, 0, 0, r);
    copy_vec(s0 + 0xF10, s2);
    *(float *)(s3 + 0xC4) = *(float *)(s0 + 0x1F10);
    *(float *)(s3 + 0xE8) = -5.0f;

    s3 = s0 + 0xF70;
    r = (func_002B3DB0(0.2f) + 1.0f) * 0.0125f;
    func_01B063E8(D_01B0A508, s3, 9, 5, 0, 0, r);
    copy_vec(s0 + 0x1040, s2);
    *(float *)(s3 + 0xC4) = *(float *)(s0 + 0x1F10);
    *(float *)(s3 + 0xE8) = -13.0f;
    *(float *)(s3 + 0xE0) = 5.0f;

    s3 = s0 + 0x10A0;
    r = (func_002B3DB0(0.2f) + 1.0f) * 0.0125f;
    func_01B063E8(D_01B0A508, s3, 9, 8, 0, 0, r);
    copy_vec(s0 + 0x1170, s2);
    *(float *)(s3 + 0xC4) = *(float *)(s0 + 0x1F10);
    *(float *)(s3 + 0xE8) = -17.0f;
    *(float *)(s3 + 0xE0) = -3.0f;
}
