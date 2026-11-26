#include "common.h"

extern void func_0026BE48(float *, s32);
extern void func_002DCE08(float *, float *, float *);

void ovl_09229_0d28(float *out, s32 angle)
{
    float mat[16];

    func_0026BE48(mat, -angle);
    out[0] = 1.0f;
    out[3] = 1.0f;
    out[1] = out[2] = 0.0f;
    func_002DCE08(out, mat, out);
}
