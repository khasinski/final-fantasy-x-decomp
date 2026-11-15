#include "p9_overlay.h"

/* Linear angle-triple track step (family F9, TU rank 69 third function; its two neighbours use
 * VU0 / lq-a3 inline asm and stay out). */

float func_01B08A60(float x, float *tbl, int n, int stride);

void func_01B0A1D8(P9Track *t, float out[3])
{
    float *src = t->src;

    if (--t->total != 0) {
        t->pos += t->step;
        out[0] = func_01B08A60(t->pos, src, t->count, 3);
        out[1] = func_01B08A60(t->pos, src + 1, t->count, 3);
        out[2] = func_01B08A60(t->pos, src + 2, t->count, 3);
    } else {
        t->type = 0;
        src += t->count * 3 - 3;
        out[0] = src[0];
        out[1] = src[1];
        out[2] = src[2];
    }
}
