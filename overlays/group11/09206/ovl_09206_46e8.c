#include "common.h"

extern u8 D_01B0C700[];
extern u8 *D_01B0C888;

extern void func_00118098(s32, s32);
extern s32 func_001ACEA0(void);
extern void func_01B04568(void);
extern void func_01B06D50(s32, void *, void *);
extern void *func_01B07B20(void (*)(void));
extern void func_01B07CE8(void *);
extern void func_01B082F0(void *, void *);
extern void func_01B08CB8(void *, void *, void *);

static inline void copy_vec(void *dst, void *src) {
    __asm__ volatile("lq $7, 0(%0)" : : "r"(src), "r"(dst) : "$7", "memory");
    __asm__ volatile("sq $7, 0(%0)" : : "r"(dst) : "memory");
}

static inline float wrap_val(float a) {
    if (a > 3.1415927f) {
        a -= 6.2831855f;
    } else if (a < -3.1415927f) {
        a += 6.2831855f;
    }
    return a;
}

void func_01B046E8(void)
{
    float v0[4];
    float v1[4];
    u8 *s1 = D_01B0C888;
    u8 *s3;
    u8 *s2;
    void *t;

    func_01B082F0(D_01B0C700, s1 + 0x390);
    s3 = s1 + 0x970;
    copy_vec(s1 + 0x8230, s3);
    s2 = s1 + 0x980;
    copy_vec(s1 + 0x8240, s2);
    v0[0] = 0.0f;
    v0[1] = -16.0f;
    v0[2] = -2.0f;
    func_01B08CB8(s1 + 0x8230, s1 + 0x8240, v0);
    *(float *)(s1 + 0xA20) = 0.0f;
    *(float *)(s1 + 0xA28) = 0.0f;
    *(float *)(s1 + 0xA10) = -0.75f;
    *(float *)(s1 + 0xA14) = 1.0f;
    *(float *)(s1 + 0xA24) = 0.62831855f;
    func_00118098(0, 0x50000);
    func_00118098(1, 0x50000);
    if (func_001ACEA0() & 1) {
        copy_vec(v1, s3);
        v1[1] = wrap_val(v1[1] - 1.0995574f);
        func_01B06D50(-1, s1 + 0x890, v1);
        func_01B06D50(1, s1 + 0x8D0, v1);
        v1[1] = wrap_val(*(float *)(s1 + 0x974) - 1.5707964f);
        v0[0] = 0.0f;
        v0[1] = 0.6f;
        v0[2] = 1.5f;
        func_01B08CB8(v1, s2, v0);
        copy_vec(s1 + 0x9A0, s2);
        *(s32 *)(s1 + 0x8628) = 1;
    } else {
        *(s32 *)(s1 + 0x8628) = 0;
    }
    t = func_01B07B20(func_01B04568);
    func_01B07CE8(t);
    *(void **)(s1 + 0x8600) = t;
}
