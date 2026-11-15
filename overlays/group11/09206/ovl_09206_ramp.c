#include "p9_overlay.h"

/* Scalar ramp steps (family F9, TU rank 74, file09206). */

#define PI 3.1415927f
#define TWO_PI 6.2831855f

float func_01B08F88(float *tbl, int n, int stride, float x);

void func_01B0A670(P9Ramp *r, float *out)
{
    if (--r->left != 0) {
        float t = (float)r->left / (float)r->len;
        float v = r->a * (1.0f - t) + r->b * t;

        if (v > PI) {
            v -= TWO_PI;
        } else if (v < -PI) {
            v += TWO_PI;
        }
        *out = v;
    } else {
        *out = r->end;
        r->type = 0;
    }
}

void func_01B0A728(P9Ramp *r, float *out)
{
    float *tbl = r->table;

    if (--r->left != 0) {
        r->a += r->b;
        *out = func_01B08F88(tbl, r->len, 1, r->a);
    } else {
        r->type = 0;
        tbl += r->len - 1;
        *out = *tbl;
    }
}
