/* PARKED (p9): func_01B04CE8, TU rank 14 (F8), file09053 0x01B04CE8..0x01B04E38, 159 containers.
 * Table sample with 1.51-tension neighbour easing (float twin of the matched func_01B05210 in
 * ovl_09053_angspline.c). Everything matches except 15 words of FP register choice:
 *   target: w (0.5) = $f1, k (1.51/..) = $f2;  this: w = $f2, k = $f1
 * (local-alloc places the block-local 1.51 quotient before the global 0.5 pseudo). Integer regs
 * were fixed by the shared index `j` plus `i >= n - 2 ? n - 1 : i + 2`; the tail by an if/else `d`.
 * Tried for the FP part: 0.5f literal vs variable, k at function scope, declaration orders, inline
 * helper, separate delta variable. Neighbours func_01B04FE0 / func_01B05020 are VU0 inline asm
 * (handwritten class) and are not attempted. */
#include "p9_overlay.h"
float func_01B04CE8(float *tbl, int n, int stride, float x)
{
    int i = x;
    float p0 = tbl[i * stride];
    float p1;
    int j;
    float w;

    if (i == n - 1) {
        p1 = p0;
    } else {
        p1 = tbl[(i + 1) * stride];
    }
    x -= i;
    w = 0.5f;
    if (x < w) {
        if (i != 0) {
            j = i - 1;
            {
                float k = 1.51f / (w - x);

                w = (p1 + tbl[j * stride]) * w - p0;
                w /= k;
                p0 += w;
            }
        }
    } else {
        j = i >= n - 2 ? n - 1 : i + 2;
        {
            float k = 1.51f / (x - 0.499999f);

            w = (p0 + tbl[j * stride]) * w - p1;
            w /= k;
            p1 += w;
        }
    }
    {
        float d;

        if (x != 0.0f) {
            d = (p1 - p0) / (1.0f / x);
        } else {
            d = 0.0f;
        }
        return p0 + d;
    }
}
