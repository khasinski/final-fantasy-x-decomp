#include "common.h"

extern void func_01B03508(void *, int, void *);
extern void func_01B03608(void *, float);
extern void func_01B03698(void *, void *);
extern void func_002DCE38(void *, void *, void *);
extern void func_002DD0B0(void *, void *);

void func_01B01628(void *out, void *a1, float f0, float f1)
{
    float m0[4][4];
    float m1[4][4];
    float m2[4][4];
    float v0[4];

    func_01B03508(a1, 3, m1);
    func_002DD0B0(v0, m1[1]);
    v0[1] = 0.0f;
    func_01B03698(m0, v0);
    func_002DD0B0(m0[3], m1[3]);
    m0[3][1] = f0;
    func_01B03608(m2, f1);
    func_002DCE38(out, m0, m2);
}
