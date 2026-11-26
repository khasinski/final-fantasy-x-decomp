#include "common.h"

typedef struct {
    u8 pad00[0x10];
    int *w10;
} TtCfg;

extern void *D_006A3924;
extern float D_01B00748;
extern TtCfg *D_01B007B0;
extern u8 D_01B007B8[];
extern u8 D_01B00A00[];

extern void func_00267658(void *, int, int, int);
extern void func_002DD0B0(void *, void *);

int func_01B042D0(u8 *a0)
{
    register TtCfg *cfg __asm__("$6") = D_01B007B0;
    int *w10 = cfg->w10;
    float s;

    *(volatile void **)&D_006A3924 = D_01B007B8;
    func_00267658(a0, 0x1000, w10[0], 1);
    func_002DD0B0(a0 + 0x40, D_01B00A00);
    {
        float y = *(float *)(a0 + 0x44) + 1.0f;
        float f = D_01B00748;
        register int one __asm__("$2") = 1;
        *(int *)(a0 + 0x5C) = one;
        *(int *)(a0 + 0x50) = 0;
        *(int *)(a0 + 0x54) = 0;
        *(float *)(a0 + 0x44) = y;
        *(int *)(a0 + 0x58) = 0;
        s = (float)((double)f * 0.057000000000000005);
    }
    *(float *)(a0 + 0x68) = *(float *)(a0 + 0x64) = *(float *)(a0 + 0x60) = s;
    *(float *)(a0 + 0x6C) = 1.0f;
    return 1;
}
