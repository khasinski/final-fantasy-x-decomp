/* Shared 09427-cluster float track step (124 B, 1 func). */

#include "common.h"

typedef struct {
    float *keys;
    float t;
    float dt;
    int pad0C;
    int remain;
    int count;
    int active;
} FloatTrack;

extern float fn_eval_curve(float *keys, int count, int stride, float t);

void ovl_09427_5af0(FloatTrack *tr, float *out)
{
    float *keys = tr->keys;
    if (--tr->remain != 0) {
        tr->t += tr->dt;
        *out = fn_eval_curve(keys, tr->count, 1, tr->t);
    } else {
        tr->active = 0;
        keys += tr->count - 1;
        *out = *keys;
    }
}
