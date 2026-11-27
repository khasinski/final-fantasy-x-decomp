#include "common.h"

void func_0026BE48(void *mtx, int angle);
void func_002DCE08(void *out, void *m, void *in);

void func_01B04858(float *out, float len, int angle)
{
    float m[16];
    float z;
    float one;

    func_0026BE48(m, -angle);
    one = 1.0f;
    z = 0.0f;
    out[0] = len;
    out[2] = z;
    out[1] = z;
    out[3] = one;
    func_002DCE08(out, m, out);
}
