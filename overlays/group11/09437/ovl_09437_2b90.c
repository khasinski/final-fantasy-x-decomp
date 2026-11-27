#include "common.h"

extern u8 D_01B0A508[];
extern u8 *D_01B0A5F0;

extern void func_001072C0(s32, s32, s32);
extern void func_00110718(s32, s32);
extern void func_01B02A60(void);
extern s32 func_01B03910(s32);
extern s32 func_01B03948(s32, s32);
extern void func_01B063E8(void *, void *, s32, s32, s32, s32, float);

static inline void copy_vec(void *dst, void *src) {
    __asm__ volatile("lq $7, 0(%0)" : : "r"(src), "r"(dst) : "$7", "memory");
    __asm__ volatile("sq $7, 0(%0)" : : "r"(dst) : "memory");
}

void func_01B02B90(void)
{
    u8 *s0 = D_01B0A5F0;
    s32 s1;

    copy_vec(s0 + 0x1BA0, s0 + 0x1C10);
    *(float *)(s0 + 0x1BA4) -= 40.0f;
    s1 = func_01B03910(1);
    if (*(s32 *)(s0 + 0x1F1C) != -1) {
        func_001072C0(s1, 0, 0);
    }
    func_001072C0(s1, func_01B03910(-1), 18);
    s0 += 0x850;
    func_01B063E8(D_01B0A508, s0, 7, 0, 0, 0, 0.001f);
    *(void (**)(void))(s0 + 0x104) = func_01B02A60;
    s0[0x126] = 2;
    *(s32 *)(s0 + 0x120) = 6;
    func_00110718(func_01B03948(-1, 0), 1);
}
