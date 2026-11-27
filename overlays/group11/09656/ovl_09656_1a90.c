#include "common.h"
#include "vu0.h"

#define MMI_COPY_LQ_A3_V0(src, dst) __asm__ volatile("lq $7, 0(%1)" : : "r"(dst), "r"(src) : "$7", "memory")
#define MMI_COPY_SQ_A3_V1(dst) __asm__ volatile("sq $7, 0(%0)" : "=r"(dst) : "0"(dst) : "memory")

extern u8 *D_01B0A988;

void func_01B07B20(int a0);
u8 *func_01B07E50(int a0);
void func_002DD128(void *a0);
void func_002DD318(void *a0, void *a1, float a2);

void func_01B01A90(void)
{
    u8 *s1 = D_01B0A988;
    u8 *s0;

    func_01B07B20(0);
    s0 = func_01B07E50(0);
    s0[0x146] = 1;
    func_002DD128(s0);
    func_002DD318(s0, s0, *(float *)(s1 + 0x3BF4));
    {
        u8 *dst = s0 + 0x30;
        u8 *src = s1 + 0x2B20;
        MMI_COPY_LQ_A3_V0(src, dst);
        MMI_COPY_SQ_A3_V1(dst);
    }
}
