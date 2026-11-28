#include "common.h"

extern int D_01B006A8;
extern void Sg_PLightAllocate(int);
extern void Sg_PLightDefine(int, float, float, float, int, int, int, int, float);
extern void func_0010DC38(int, int);
extern void Ch_SetCalcNorm(int, int);

int func_01B01DB8(void)
{
    Sg_PLightAllocate(4);
    Sg_PLightDefine(0, 0.0f, 0.0f, 0.0f, 0xFF, 0xFF, 0xFF, 0, 100.0f);
    Sg_PLightDefine(1, 0.0f, 0.0f, 0.0f, 1, 1, 1, 1, 100.0f);
    Sg_PLightDefine(2, 0.0f, 0.0f, 0.0f, 1, 1, 1, 2, 100.0f);
    Sg_PLightDefine(3, 0.0f, 0.0f, 0.0f, 1, 1, 1, 3, 100.0f);
    func_0010DC38(D_01B006A8, 0xF);
    Ch_SetCalcNorm(D_01B006A8, 1);
    return 1;
}
