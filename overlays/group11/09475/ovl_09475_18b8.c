#include "common.h"

extern void *D_01B0A070;

extern void func_0010D380(void *, int, int);
extern void func_0010D3A8(void *, int, int);
extern void func_002A7308(void *, void *, int, int);
extern void func_002DCEC8(float *, float *);
extern void *func_01B037F0(int);

void func_01B018B8(void)
{
    void *p = func_01B037F0(0);

    func_0010D380(p, -1, 0x3C00);
    func_0010D3A8(p, -1, 0x2EE0);
    func_002A7308(D_01B0A070, p, 1, 0);
    func_0010D380(p, -1, -1);
    func_0010D3A8(p, -1, -1);
}

void func_01B01938(float *out, float *p0, float *p1, float *p2)
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
