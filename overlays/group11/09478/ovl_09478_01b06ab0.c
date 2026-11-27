#include "common.h"

extern u8 *D_01B102F0;
extern u8 D_01B101A8[];

extern void func_01B0BB00(void *, void *);
extern void func_01B0B690(void *, void *, int, int, int, int, float);

void func_01B06AB0(void)
{
    u8 *s1 = D_01B102F0;

    func_01B0BB00(D_01B101A8, s1 + 0x980);
    func_01B0B690(D_01B101A8, s1, 0, 0, 0, 0, 0.009f);
    {
        register float f __asm__("$f0") = *(float *)(s1 + 0x1B08);
        register u_long128 *dst __asm__("$3") = (u_long128 *)(s1 + 0xD0);
        register u_long128 *src __asm__("$2") = (u_long128 *)(s1 + 0xCA0);
        register u_long128 q __asm__("$7");
        __asm__("" : "+f"(f), "+r"(dst), "+r"(src));
        *(float *)(s1 + 0xC4) = f;
        __asm__ volatile("");
        q = *src;
        *dst = q;
    }
    __asm__ volatile("");
    *(float *)(s1 + 0xE0) = 2.0f;
    *(float *)(s1 + 0xE8) = -11.5f;
    *(float *)(s1 + 0xD4) -= 0.5f;
}
