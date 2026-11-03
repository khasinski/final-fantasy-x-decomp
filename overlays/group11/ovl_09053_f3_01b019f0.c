#include "p7_overlay.h"

/* F3 TU rank 41: target scale. */

void func_01B019F0(int idx, float *out)
{
    void *h = func_01B01630(idx);
    float s = func_00110AF0(h) * 0.001f;

    out[0] = Ch_GetScaleX(h) * s;
    out[1] = Ch_GetScaleY(h) * s;
    out[2] = Ch_GetScaleZ(h) * s;
}

void func_01B01A70(int idx, float *v)
{
    Ch_SetScale(func_01B01630(idx), 7, v[0], v[1], v[2]);
}

void func_01B01AA8(float f)
{
    float v[3];
    int i;

    v[2] = f;
    v[1] = f;
    v[0] = f;
    for (i = 0; i < D_01B005A0.count; i++) {
        func_01B01A70(i, v);
    }
}

float func_01B01B10(int idx)
{
    void *h = func_01B01630(idx);

    return Ch_GetFixHeight(h) * Ch_GetScaleY(h);
}
