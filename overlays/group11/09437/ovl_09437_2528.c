#include "common.h"

extern u8 D_01B0A508[];
extern u8 *D_01B0A5F0;

extern void func_01B024F0(void);
extern void func_01B063E8(void *, void *, s32, s32, s32, s32, float);

static inline void copy_vec(void *dst, void *src) {
    __asm__ volatile("lq $7, 0(%0)" : : "r"(src), "r"(dst) : "$7", "memory");
    __asm__ volatile("sq $7, 0(%0)" : : "r"(dst) : "memory");
}

void func_01B02528(void)
{
    u8 *s1 = D_01B0A5F0;
    u8 *s2 = s1 + 0xAB0;

    func_01B063E8(D_01B0A508, s2, 9, 0, 0, 0, 0.01f);
    copy_vec(s1 + 0xB80, s1 + 0x1C20);
    *(float *)(s2 + 0xC4) = *(float *)(s1 + 0x1F10);
    *(float *)(s2 + 0xE8) = -23.0f;
    s2 = s1 + 0x980;
    func_01B063E8(D_01B0A508, s2, 8, 0x22, 0, 0, 0.01f);
    *(float *)(s2 + 0xC4) = *(float *)(s1 + 0x1F10);
    *(void (**)(void))(s2 + 0x104) = func_01B024F0;
}
