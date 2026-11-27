#include "common.h"

extern u8 *D_01B0C888;

extern void func_01B06D50(s32, void *, void *);
extern void func_01B08CB8(void *, void *, void *);
extern void func_01B0BA88(void *, s32, s32, float, float);

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

void func_01B05008(void)
{
    float v0[4];
    float v1[4];
    u8 *s2 = D_01B0C888;
    u8 *s1;
    u8 *s0;

    wrap_angle((float *)(s2 + 0x954), 0.7853982f);
    s1 = s2 + 0x960;
    v0[0] = 0.0f;
    v0[1] = *(float *)(s2 + 0x8608);
    v0[2] = 0.0f;
    v0[3] = 0.0f;
    s0 = s2 + 0x950;
    v1[0] = 25.0f;
    v1[1] = 0.0f;
    v1[2] = 15.0f;
    v1[3] = 1.0f;
    func_01B08CB8(v0, s1, v1);
    func_01B06D50(0, s2 + 0x850, s0);
    copy_vec(s2 + 0x9B0, s0);
    copy_vec(s2 + 0x9C0, s1);
    func_01B06D50(2, s2 + 0x910, s2 + 0x9B0);
    func_01B0BA88(s2 + 0x8470, 30, 0x55, 0.5f, 1.0f);
}
