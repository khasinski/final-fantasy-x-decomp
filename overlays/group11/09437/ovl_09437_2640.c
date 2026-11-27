#include "common.h"

extern u8 *D_01B0A5F0;

extern void func_01B04D38(s32, void *);
extern void func_01B052B8(s32, void *, void *);
extern void func_01B07220(void *, void *, void *);

static inline void copy_vec(void *dst, void *src) {
    __asm__ volatile("lq $7, 0(%0)" : : "r"(src), "r"(dst) : "$7", "memory");
    __asm__ volatile("sq $7, 0(%0)" : : "r"(dst) : "memory");
}

static inline void copy_vec_m(void *dst, void *src) {
    __asm__ volatile("lq $7, 0(%0)" : : "r"(src) : "$7", "memory");
    __asm__ volatile("sq $7, %0" : "=m"(*(u_long128 *)dst) : : "memory");
}

void func_01B02640(void)
{
    float v0[4];
    float v1[4];
    float v2[4];
    u8 *s2 = D_01B0A5F0;
    u8 *s3 = s2 + 0x1C10;
    float a;
    u8 *s0;

    copy_vec_m(v0, s3);
    v1[0] = 0.0f;
    a = *(float *)(s2 + 0x1F10) + 2.3561945f;
    if (a > 3.1415927f) {
        a -= 6.2831855f;
    } else if (a < -3.1415927f) {
        a += 6.2831855f;
    }
    v1[1] = a;
    v1[2] = 0.0f;
    v1[3] = 0.0f;
    v2[0] = 0.0f;
    v2[1] = -17.0f;
    v2[2] = 100.0f;
    v2[3] = 1.0f;
    func_01B07220(v1, v0, v2);
    copy_vec(s2 + 0x1C30, v0);
    copy_vec(s2 + 0x1C40, s3);
    v2[0] = 0.0f;
    v2[1] = -40.0f;
    v2[2] = -10.0f;
    v2[3] = 1.0f;
    func_01B07220(v1, s2 + 0x1C40, v2);
    s0 = s2 + 0x1BB0;
    *(s32 *)(s2 + 0x1F24) = 45;
    *(float *)(s2 + 0x1BF0) = 0.0f;
    *(float *)(s2 + 0x1BF4) = v1[1];
    *(float *)(s2 + 0x1BF8) = 0.0f;
    *(float *)(s2 + 0x1BFC) = 0.0f;
    func_01B052B8(1, s0, s2 + 0x1BF0);
    copy_vec(s2 + 0x1BE0, v0);
    copy_vec(s2 + 0x1C00, v0);
    func_01B04D38(1, s0);
}
