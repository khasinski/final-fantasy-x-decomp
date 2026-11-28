#include "common.h"

extern float D_01B00B3C[3];
extern float D_01B00B58[3];

void func_01B044F8(void *a0);

void func_01B04590(void)
{
    float v[4];

    func_01B044F8(v);
    D_01B00B3C[0] = v[0];
    D_01B00B3C[1] = -50.0f;
    D_01B00B3C[2] = v[2];
}

void func_01B045D0(void)
{
    float v[4];

    func_01B044F8(v);
    D_01B00B58[0] = v[0];
    D_01B00B58[1] = -10.0f;
    D_01B00B58[2] = v[2];
}
