#include "common.h"

extern u8 *D_01B0BD58;
extern void *D_01B0BD60;
extern void *D_01B01054;
extern u8 D_01B0BC78[];
extern u8 D_01B0BCD8[];
extern u8 D_01B0BD38[];

extern void func_01B089D0(void);
extern int func_01B0ABF8(void *);
extern void func_01B067C8(void *);
extern void func_01B091F8(void);
extern void func_01B02428(void);
extern void func_01B07368(void *);

void func_01B02090(void *a0)
{
    u8 *s1 = D_01B0BD58;
    int r;

    func_01B089D0();
    D_01B01054 = D_01B0BD60;
    r = func_01B0ABF8(D_01B0BC78);
    func_01B0ABF8(D_01B0BCD8);
    if (r == 0) {
        {
            register u_long128 *src __asm__("$2") = (u_long128 *)(s1 + 0x9D0);
            register u_long128 *dst __asm__("$3") = (u_long128 *)(s1 + 0x9B0);
            register u_long128 q __asm__("$7");
            __asm__("" : "+r"(src));
            __asm__("" : "+r"(dst));
            q = *src;
            *dst = q;
        }
        __asm__ volatile("");
        func_01B067C8(D_01B0BD38);
        func_01B091F8();
    } else {
        *(int *)(s1 + 0x62B0) = 1;
        func_01B02428();
        func_01B07368(a0);
    }
}
