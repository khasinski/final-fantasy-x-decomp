#include "common.h"

extern float D_01B009F4[];
extern void func_01B044F8(float *);

void func_01B04550(void)
{
    float v[4];

    func_01B044F8(v);
    D_01B009F4[0] = v[0];
    D_01B009F4[1] = -28.0f;
    D_01B009F4[2] = v[2];
}
