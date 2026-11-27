#include "common.h"

extern u8 *D_01B102F0;

extern void func_01B0A560(int, void *);
extern void func_01B0B3B0(void *);

void func_01B07348(void)
{
    u8 *s0 = D_01B102F0;
    void *p;

    {
        register u_long128 *dst __asm__("$6") = (u_long128 *)(s0 + 0xC80);
        register u_long128 *src __asm__("$2") = (u_long128 *)(s0 + 0xC60);
        register u_long128 q __asm__("$7");
        __asm__("" : "+r"(dst), "+r"(src));
        q = *src;
        *dst = q;
    }
    __asm__ volatile("");
    {
        register u_long128 *dst __asm__("$3") = (u_long128 *)(s0 + 0xC90);
        register u_long128 *src __asm__("$2") = (u_long128 *)(s0 + 0xC70);
        register u_long128 q __asm__("$7");
        __asm__("" : "+r"(dst), "+r"(src));
        q = *src;
        *dst = q;
    }
    __asm__ volatile("");
    func_01B0A560(0, s0 + 0xC20);
    p = *(void **)(s0 + 0x1B00);
    if (p != 0) {
        func_01B0B3B0(p);
        *(void **)(s0 + 0x1B00) = 0;
    }
}
