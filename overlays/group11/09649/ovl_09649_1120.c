#include "common.h"

extern s32 D_01B0B1EC;
extern u8 *D_01B0B1F8;

extern void func_01B01318(void);
extern void func_01B01568(void);
extern void func_01B04098(s32, void *, s32);
extern float func_01B044E8(s32);
extern void func_01B05308(s32, void *);
extern void func_01B05458(void *);
extern void func_01B05888(s32, void *, void *);
extern void func_01B076E8(void *, void *, void *);
extern void func_01B077F0(void *, void *, void *);

static inline void copy_vec(void *dst, void *src) {
    __asm__ volatile("lq $7, 0(%0)" : : "r"(src), "r"(dst) : "$7", "memory");
    __asm__ volatile("sq $7, 0(%0)" : : "r"(dst) : "memory");
}

void func_01B01120(void)
{
    float v0[4];
    float v1[4];
    float v2[4];
    float v3[4];
    u8 *s0 = D_01B0B1F8;

    func_01B04098(-1, v0, 0);
    func_01B05458(v1);
    func_01B076E8(v3, v0, v1);
    v3[0] = 0.0f;
    func_01B05308(-1, s0 + 0x1430);
    copy_vec(s0 + 0x1470, v3);
    func_01B05888(-1, s0 + 0x1430, v3);

    v2[0] = 0.0f;
    v2[1] = 0.0f;
    v2[2] = 47.64586f;
    v2[3] = 1.0f;
    copy_vec(s0 + 0x1480, v1);
    func_01B077F0(v3, s0 + 0x1480, v2);
    copy_vec(s0 + 0x1460, s0 + 0x1480);
    *(float *)(s0 + 0x3178) = v3[1];

    v2[0] = 0.0f;
    v2[1] = 0.0f;
    v2[2] = -30.0f;
    v2[3] = 1.0f;
    copy_vec(s0 + 0x14A0, v1);
    func_01B077F0(v3, s0 + 0x14A0, v2);
    *(float *)(s0 + 0x14A4) = func_01B044E8(-1);
    copy_vec(s0 + 0x1490, s0 + 0x14A0);
    copy_vec(s0 + 0x14B0, s0 + 0x14A0);
    *(float *)(s0 + 0x14B4) -= 130.0f;

    copy_vec(s0 + 0x14C0, v1);
    v2[2] = 10.0f;
    func_01B077F0(v3, s0 + 0x14C0, v2);
    *(float *)(s0 + 0x14C4) -= 50.0f;

    copy_vec(s0 + 0x14E0, v1);
    v2[2] = -20.0f;
    func_01B077F0(v3, s0 + 0x14E0, v2);

    *(s32 *)(s0 + 0x317C) = 0;
    *(s32 *)(s0 + 0x3170) = 0;
    *(s32 *)(s0 + 0x3174) = 0;
    *(s32 *)(s0 + 0x3180) = 0;
    D_01B0B1EC = 1;
    func_01B01318();
    func_01B01568();
}
