#include "common.h"

extern u8 D_01B020B8[];
extern void func_002DD0C0(void *, void *);
extern void func_002DD0B0(void *, void *);

void func_01B03BA8(u8 **s1)
{
    u8 *s0 = s1[0];

    *(void **)s0 = D_01B020B8;
    func_002DD0C0(s0 + 0x60, s1[1] + 0x60);
    func_002DD0C0(s0 + 0xA0, s1[1] + 0xA0);
    func_002DD0C0(s0 + 0xE0, s1[1] + 0xE0);
    func_002DD0B0(s0 + 0x130, s1[1] + 0x130);
    __asm__ volatile("");
}
