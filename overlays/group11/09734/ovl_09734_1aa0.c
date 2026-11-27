#include "common.h"

typedef struct {
    u8 pad00[0x10];
    int *w10;
} TtCfg;

extern void *D_006A3924;
extern float D_01B00798;
extern TtCfg *D_01B007FC;
extern u8 D_01B00800[];
extern u8 D_01B009C0[];

extern void func_00267658(void *, int, int, int);
extern void func_002DD0B0(void *, void *);

int func_01B01AA0(u8 *a0)
{
    TtCfg *cfg = D_01B007FC;
    int *w10;
    float s;

    *(volatile void **)&D_006A3924 = D_01B00800;
    w10 = cfg->w10;
    func_00267658(a0, 0x1000, w10[2], 1);
    func_002DD0B0(a0 + 0x40, D_01B009C0);
    {
        float y = *(float *)(a0 + 0x44) + 1.0f;
        float f = D_01B00798;
        *(int *)(a0 + 0x50) = 0;
        *(int *)(a0 + 0x54) = 0;
        *(int *)(a0 + 0x58) = 0;
        *(float *)(a0 + 0x44) = y;
        *(int *)(a0 + 0x5C) = 1;
        s = (float)((double)f * 0.057);
    }
    *(float *)(a0 + 0x6C) = 1.0f;
    *(float *)(a0 + 0x68) = *(float *)(a0 + 0x64) = *(float *)(a0 + 0x60) = s;
    return 1;
}
