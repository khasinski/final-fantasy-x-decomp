#include "common.h"

extern float D_01B009F0[];
extern void func_01B04610(void *);

void func_01B04730(void)
{
    float v[4];

    func_01B04610(v);
    D_01B009F0[0] = v[0] + 0.6442f;
    D_01B009F0[1] = v[1] - 20.0f;
    D_01B009F0[2] = v[2] + 9.7999f;
}
