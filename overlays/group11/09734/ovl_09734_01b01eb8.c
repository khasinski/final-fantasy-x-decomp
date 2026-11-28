#include "common.h"

extern float D_01B00A90[4];
extern float D_01B009C0[4];
extern float D_01B007C0[4];
extern int D_01B007D0;
extern int D_01B00AA4;

extern void func_002DD020(void *, void *, void *);
extern void Sg_PLightDefine(int, float, float, float, int, int, int, int, float);

int func_01B01EB8(void)
{
    func_002DD020(D_01B00A90, D_01B009C0, D_01B007C0);
    Sg_PLightDefine(0, D_01B00A90[0], D_01B00A90[1], D_01B00A90[2], 0xFF, 0xFF, 0xFF, 0, 1000.0f);
    Sg_PLightDefine(3, D_01B00A90[0], D_01B00A90[1], D_01B00A90[2], D_01B007D0, D_01B007D0, D_01B007D0, 3, 100.0f);
    return D_01B00AA4 != 1;
}
