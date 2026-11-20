/* Shared ee-gcc2.96 helper (TU rank 432, 10 containers): normalize 3D vector and return length. */
#include "common.h"

extern double sqrt(double);

float func_01B01208(float *v)
{
    double d = sqrt((double)(v[0] * v[0] + v[1] * v[1] + v[2] * v[2]));
    float len = (float)d;
    if (len != 0.0f) {
        float inv = 1.0f / len;
        v[0] *= inv;
        v[1] *= inv;
        v[2] *= inv;
    }
    return len;
}
