#include "common.h"

extern u8 *D_01B0BD58;
extern u8 D_01B0BC30[];
extern void func_01B07AB8(void *, void *);
extern void func_01B0B788(void *, int);

void func_01B03A38(void)
{
    u8 *s0 = D_01B0BD58;
    u8 *p;

    func_01B07AB8(D_01B0BC30, s0 + *(int *)(s0 + 0x62AC) * 0x130);
    func_01B07AB8(D_01B0BC30, s0 + 0x390);
    func_01B07AB8(D_01B0BC30, s0 + 0x4C0);
    p = s0 + 0x5DC0;
    *(u8 *)(p + 0xF0) = 0x80;
    *(u8 *)(p + 0xF1) = 0x80;
    *(u8 *)(p + 0xF2) = 0x80;
    *(u8 *)(p + 0xF3) = 0x30;
    *(u16 *)(p + 0x124) = 4;
    *(float *)(p + 0xF8) = 0.04f;
    *(float *)(p + 0xFC) = 0.02f;
    *(int *)(p + 0x120) = 0;
    *(int *)(p + 0x110) = 0;
    *(int *)(p + 0x100) = 0;
    func_01B0B788(p, 0x14);
}
