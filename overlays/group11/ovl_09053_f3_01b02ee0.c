#include "p7_overlay.h"

/* F3 TU rank 56. */

float func_01B02EE0(int idx)
{
    return func_00110AF0(func_01B01630(idx));
}

void func_01B02F08(int idx, float *m)
{
    float s;
    void *h;

    func_002DD128(m);
    s = func_01B02EE0(idx) * 0.001f;
    m[10] = s;
    m[5] = s;
    m[0] = s;
    h = func_01B01630(idx);
    m[0] *= Ch_GetScaleX(h);
    m[5] *= Ch_GetScaleY(h);
    m[10] *= Ch_GetScaleZ(h);
}
