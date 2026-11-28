#include "common.h"

typedef struct {
    u8 pad00[0x10];
    int *w10;
} TtCfg;

extern void *D_006A3924;
extern TtCfg *D_01B00874;
extern u8 D_01B00878[];
extern u8 D_01B00AC0[];

extern void func_00267658(void *, int, int, int);
extern void func_002DD0B0(void *, void *);

int func_01B023B0(u8 *s0)
{
    register TtCfg *cfg __asm__("$6") = D_01B00874;
    int *w10 = cfg->w10;
    float y;

    *(volatile void **)&D_006A3924 = D_01B00878;
    func_00267658(s0, 0x1000, w10[0], 1);
    func_002DD0B0(s0 + 0x40, D_01B00AC0);
    y = *(float *)(s0 + 0x44) + 1.0f;
    *(int *)(s0 + 0x5C) = 1;
    *(int *)(s0 + 0x50) = 0;
    *(int *)(s0 + 0x54) = 0;
    *(float *)(s0 + 0x44) = y;
    *(int *)(s0 + 0x58) = 0;
    *(float *)(s0 + 0x60) = 0.057000001f;
    *(float *)(s0 + 0x64) = 0.057000001f;
    *(float *)(s0 + 0x68) = 0.057000001f;
    *(float *)(s0 + 0x6C) = 1.0f;
    return 1;
}
