#include "p9_overlay.h"

/* Eased angle-triple track step (family F9, TU rank 89, file09206). */

float func_01B089F8(float a, float b, float c, float d, float e, float t);
float func_01B08A60(float x, float *tbl, int n, int stride);

void func_01B0A2B0(P9Track *t, float out[3])
{
    float *src = t->src;

    if (--t->total != 0) {
        float *w;
        float x;

        t->pos += t->step;
        w = t->arg;
        x = func_01B089F8(w[0], w[1], w[2], w[3], w[4], t->pos);
        out[0] = func_01B08A60(x, src, t->count, 3);
        out[1] = func_01B08A60(x, src + 1, t->count, 3);
        out[2] = func_01B08A60(x, src + 2, t->count, 3);
    } else {
        t->type = 0;
        src += t->count * 3 - 3;
        out[0] = src[0];
        out[1] = src[1];
        out[2] = src[2];
    }
}
