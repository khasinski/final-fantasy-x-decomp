#include "common.h"
#include "vu0.h"

#define MMI_COPY_LQ_A3_V0(src, dst) __asm__ volatile("lq $7, 0(%1)" : : "r"(dst), "r"(src) : "$7", "memory")
#define MMI_COPY_SQ_A3_V1(dst) __asm__ volatile("sq $7, 0(%0)" : "=r"(dst) : "0"(dst) : "memory")

extern u8 D_01B0A860[];
extern u8 *D_01B0A988;

void func_01B05E08(void *a0);
void func_01B06558(void *a0, void *a1);
void func_01B060E8(void *a0, void *a1, int a2, int a3, int a4, void *a5, float f0);

void func_01B02E48(void)
{
    u8 *s1 = D_01B0A988;

    if (*(void **)(s1 + 0x3BF0) != 0) {
        func_01B05E08(*(void **)(s1 + 0x3BF0));
        *(void **)(s1 + 0x3BF0) = 0;
    }
    func_01B06558(D_01B0A860, s1 + 0x5F0);
    func_01B06558(D_01B0A860, s1 + 0x980);
}

void func_01B02EA8(void)
{
    u8 *s0 = D_01B0A988;
    u8 *s1 = s0 + 0x5F0;

    func_01B060E8(D_01B0A860, s1, 5, 0, 0, 0, 0.15f);
    {
        register u8 *dst __asm__("$3") = s0 + 0x6C0;
        register u8 *src __asm__("$2") = s0 + 0x2B30;
        MMI_COPY_LQ_A3_V0(src, dst);
        MMI_COPY_SQ_A3_V1(dst);
        *(float *)(s1 + 0xC4) = *(float *)(s0 + 0x3BF4);
        *(float *)(s1 + 0xD4) -= 60.0f;
        {
            register u8 *dst2 __asm__("$2") = s0 + 0x2B40;
            MMI_COPY_LQ_A3_V0(dst, dst2);
            MMI_COPY_SQ_A3_V1(dst2);
        }
    }
}
