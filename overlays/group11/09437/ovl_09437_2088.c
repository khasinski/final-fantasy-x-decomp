#include "common.h"

extern u8 D_01B0A508[];
extern u8 *D_01B0A5F0;

extern void func_01B04D38(s32, void *);
extern void func_01B052B8(s32, void *, void *);
extern s32 func_01B063E8(void *, void *, s32, s32, s32, s32, float);
extern void func_01B09C50(void *, s32, s32, float, float);

static inline void copy_vec(void *dst, void *src) {
    __asm__ volatile("lq $7, 0(%0)" : : "r"(src), "r"(dst) : "$7", "memory");
    __asm__ volatile("sq $7, 0(%0)" : : "r"(dst) : "memory");
}

void func_01B02088(void)
{
    u8 *s0 = D_01B0A5F0;
    u8 *s1 = s0 + 0xBE0;
    u8 *s2;
    u8 *s3;

    func_01B063E8(D_01B0A508, s1, 10, 0, 0, 0, 0.015f);
    s2 = s0 + 0x1C10;
    copy_vec(s0 + 0xCB0, s2);
    *(float *)(s1 + 0xC4) = *(float *)(s0 + 0x1F10);
    *(float *)(s1 + 0xD4) -= 0.5f;
    s3 = s0 + 0x1B50;
    *(float *)(s0 + 0x1B90) = 0.0f;
    *(float *)(s0 + 0x1B94) = *(float *)(s0 + 0x1F10);
    *(float *)(s0 + 0x1B98) = 0.0f;
    *(float *)(s0 + 0x1B9C) = 0.0f;
    func_01B052B8(-1, s3, s0 + 0x1B90);
    copy_vec(s0 + 0x1B80, s2);
    copy_vec(s0 + 0x1BA0, s2);
    func_01B04D38(-1, s3);
    func_01B09C50(s0 + 0x1DD0, 30, 0, 1.0f, 0.5f);
}
