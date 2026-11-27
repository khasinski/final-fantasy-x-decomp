#include "common.h"

extern void func_00108910(s32, s32, float *);
extern s32 func_01B03630(s32, s32);

void func_01B022D8(float *a0)
{
    func_00108910(func_01B03630(0, 0), 0xE, a0);
}
