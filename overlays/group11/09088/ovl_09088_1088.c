#include "common.h"

extern void func_002DD998(float (*dst)[4], float (*src)[4], float s);

void func_01B01088(float (*dst)[4], float (*src)[4])
{
    func_002DD998(dst, src, 100.0f);
    func_002DD998(dst + 1, src + 1, 100.0f);
    func_002DD998(dst + 2, src + 2, 100.0f);
}
