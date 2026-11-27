#include "common.h"

extern void func_002B5C18(void *, void *, int);

void func_01B03608(void *a0, float (*pts)[4], int n,
                   float x0, float y0, float z0,
                   float x1, float y1, float z1)
{
    int i;
    float (*p)[4] = pts;

    for (i = 0; i < n; i++, p++) {
        float t = (float)i / (float)(n - 1);
        (*p)[0] = x0 + (x1 - x0) * t;
        (*p)[1] = y0 + (y1 - y0) * t;
        (*p)[2] = z0 + (z1 - z0) * t;
        (*p)[3] = 1.0f;
    }
    func_002B5C18(a0, pts, n);
}
