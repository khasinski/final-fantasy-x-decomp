#include "p7_overlay.h"

/* F3 TU rank 61. */

void func_01B01C88(int idx, int a1, int a2, float *out)
{
    func_00107428(func_01B01630(idx), a1, a2, out);
    out[3] = 1.0f;
}

void func_01B01CE8(int idx, int a1, float *out)
{
    Ch_OptposGet(func_01B01630(idx), a1, out);
    out[3] = 1.0f;
}
