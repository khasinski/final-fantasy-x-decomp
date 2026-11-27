#include "common.h"
#include "vu0.h"

#define MMI_COPY_LQ_A3_V0(src, dst) __asm__ volatile("lq $7, 0(%1)" : : "r"(dst), "r"(src) : "$7", "memory")
#define MMI_COPY_SQ_A3_V1(dst) __asm__ volatile("sq $7, 0(%0)" : "=r"(dst) : "0"(dst) : "memory")

extern u8 D_01B0A2F8[];
extern u8 *D_01B0A480;

void func_01B060D0(void *a0, void *a1, int a2, int a3, int a4, void *a5, float f0);
void func_01B06F08(void *a0, void *a1, void *a2);
void func_01B022D8(void *a0);

void func_01B02708(void)
{
    float v0[4];
    float v1[4];
    u8 *s0 = D_01B0A480;
    u8 *s2 = s0 + 0x720;
    u8 *s1;

    func_01B060D0(D_01B0A2F8, s2, 6, 0, 0, 0, 0.0075f);
    s1 = s0 + 0x7F0;
    {
        register u8 *src __asm__("$3") = s0 + 0xCD0;
        MMI_COPY_LQ_A3_V0(src, s1);
        MMI_COPY_SQ_A3_V1(s1);
    }
    *(float *)(s2 + 0xC4) = *(float *)(s0 + 0xEC8);
    v0[0] = 0.0f;
    v0[1] = *(float *)(s0 + 0xEC8);
    v0[2] = 0.0f;
    v0[3] = 1.0f;
    v1[0] = -6.0f;
    v1[1] = -24.0f;
    v1[2] = 0.0f;
    v1[3] = 1.0f;
    func_01B06F08(v0, s1, v1);
    func_01B022D8(s1);
}
