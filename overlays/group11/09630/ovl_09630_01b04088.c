#include "common.h"

extern u8 *D_01B0C0B0;
extern void func_01B05E98(int, int);
extern void *func_01B07368(void *);
extern void func_01B07530(void *);
extern void func_01B03D10(void);

void func_01B04088(void)
{
    u8 *s0 = D_01B0C0B0;
    u8 *s1 = s0 + 0x8000;
    void *h;

    *(int *)(s1 + 0x5D4) = 0;
    *(int *)(s1 + 0x5D8) = 0;
    *(int *)(s1 + 0x5DC) = 0;
    *(int *)(s1 + 0x5E0) = 0xA0;
    func_01B05E98(-1, 1);
    func_01B05E98(1, 1);
    *(int *)(s0 + 0x9C4) = 0;
    *(float *)(s0 + 0x9C0) = -0.9424779f;
    *(float *)(s0 + 0x9C8) = 1.5707964f;
    h = func_01B07368((void *)func_01B03D10);
    func_01B07530(h);
    *(void **)(s1 + 0x5C4) = h;
}
