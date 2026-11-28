#include "common.h"

extern float D_01B008C8[3];
extern void func_01B04610(float *);

void func_01B04668(void)
{
    float v[4];

    func_01B04610(v);
    D_01B008C8[0] = v[0];
    D_01B008C8[1] = -4.0f;
    D_01B008C8[2] = v[2];
}
