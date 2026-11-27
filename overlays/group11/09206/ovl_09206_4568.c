#include "common.h"

extern u8 *D_01B0C888;
extern u8 D_01B11E30[];

extern void *func_002B49A0(void *, s32, s32);
extern void func_002DCE38(void *, void *, void *);
extern void func_002DD128(void *);
extern void func_002DD3C0(void *, void *, void *);
extern void func_01B01A90(void *, void *, void *, s32, s32, s32);
extern void func_01B02788(void);
extern void func_01B06C30(void *, void *);

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

void func_01B04568(void)
{
    float m0[4][4];
    float m1[4][4];
    float m2[4][4];
    u8 *s2 = D_01B0C888;
    s32 i;

    wrap_angle((float *)(s2 + 0xA14), 0.015707964f);
    func_01B02788();
    func_01B06C30(m1, m2);
    func_002DD128(m0);
    m0[2][2] = 0.002f;
    m0[1][1] = 0.002f;
    m0[0][0] = 0.002f;
    func_002DD3C0(m0, m0, s2 + 0x8230);
    copy_vec(m0[3], s2 + 0x8240);
    func_002DCE38(m0, m2, m0);
    func_002DCE38(m0, m1, m0);
    for (i = 0; i < 20; i++) {
        func_01B01A90(func_002B49A0(D_01B11E30, 4, i), m0, D_01B0C888 + 0xA30 + i * 0x600, 0x50, 0x80, 0x20);
    }
}
