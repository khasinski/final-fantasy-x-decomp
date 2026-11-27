#include "common.h"

extern float D_01B010E8[];
extern void func_01B05DA8(void *);

void func_01B05E00(void)
{
    float v[4];

    func_01B05DA8(v);
    D_01B010E8[0] = v[0];
    D_01B010E8[2] = v[2];
}
