#include "common.h"

extern void func_002DCEC8(float *, float *);

void func_01B017B8(float *out, float *p0, float *p1, float *p2)
{
    float ax = p1[0] - p0[0];
    float ay = p1[1] - p0[1];
    float az = p1[2] - p0[2];
    float bx = p2[0] - p0[0];
    float by = p2[1] - p0[1];
    float bz = p2[2] - p0[2];

    out[3] = 1.0f;
    out[0] = ay * bz - az * by;
    out[1] = az * bx - ax * bz;
    out[2] = ax * by - ay * bx;
    func_002DCEC8(out, out);
}
