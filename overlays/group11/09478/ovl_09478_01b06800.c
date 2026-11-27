#include "common.h"

extern u8 *D_01B102F0;
extern u8 D_01B00EE8[];

extern int func_01B0A378(int);
extern void func_00110648(int, int);
extern void func_01B09FE0(int, void *);
extern void func_01B0A560(int, void *);
extern void func_01B060C8(void);
extern void func_01B09AA8(int, int);

void func_01B06800(void)
{
    register u8 *s0 __asm__("$16") = D_01B102F0;
    register u8 *s1 __asm__("$17") = D_01B00EE8;
    u8 *s2 = s0 + 0xC20;
    int r;

    r = func_01B0A378(0x3018);
    s1[0x14] = 0x20;
    *(int *)(s1 + 0xC4) = r;
    func_00110648(r, 0);
    func_01B09FE0(0, s2);
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
        register u_long128 *src __asm__("$3") = (u_long128 *)(s0 + 0xC70);
        register u_long128 *dst __asm__("$16") = (u_long128 *)(s0 + 0xC90);
        register u_long128 q __asm__("$7");
        __asm__("" : "+r"(src), "+r"(dst));
        q = *src;
        *dst = q;
    }
    __asm__ volatile("");
    func_01B0A560(0, s2);
    func_01B060C8();
    func_01B09AA8(0, 1);
}
