#include "common.h"

extern float D_01B00820[];

extern void func_01B03C48(void *);

void func_01B03CA0(void)
{
    float v[4];

    func_01B03C48(v);
    D_01B00820[0] = v[0];
    D_01B00820[2] = v[2];
}
