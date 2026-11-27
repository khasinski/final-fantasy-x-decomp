#include "common.h"
#include "vu0.h"

#define MMI_COPY_LQ_A3_V0(src, dst) __asm__ volatile("lq $7, 0(%1)" : : "r"(dst), "r"(src) : "$7", "memory")
#define MMI_COPY_SQ_A3_V1(dst) __asm__ volatile("sq $7, 0(%0)" : "=r"(dst) : "0"(dst) : "memory")

extern u8 *D_01B0A1E0;
extern u8 D_01B0A0B8[];

void func_01B06268(void *a0, void *a1, int a2, int a3, int a4, void *a5, float f0);

void func_01B02810(void)
{
    u8 *s0 = D_01B0A1E0;
    u8 *s1 = s0 + 0x4C0;

    func_01B06268(D_01B0A0B8, s1, 4, 0, 0, 0, 0.8f);
    {
        register u8 *dst __asm__("$3") = s0 + 0x590;
        register u8 *src __asm__("$2") = s0 + 0xA60;
        MMI_COPY_LQ_A3_V0(src, dst);
        MMI_COPY_SQ_A3_V1(dst);
    }
    *(float *)(s1 + 0xC4) = *(float *)(s0 + 0x3148);
}
