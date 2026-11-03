#include "p9_overlay.h"

/* Bernstein-style curve blends (family F8, TU rank 14 part 1, position independent). */

float func_01B04BF0(float a, float b, float c, float t)
{
    float u = 1.0f - t;

    return a * (u * u) + b * (u * t * 2.0f) + c * (t * t);
}

float func_01B04C28(float a, float b, float c, float d, float t)
{
    float u = 1.0f - t;

    return a * (u * u * u) + b * (u * t * u * 3.0f) + c * (t * t * u * 3.0f) + d * (t * t * t);
}

float func_01B04C80(float a, float b, float c, float d, float e, float t)
{
    float u = 1.0f - t;
    float k0 = u * u * (u * u);
    float k1 = u * u * (u * t) * 4.0f;
    float k2 = u * u * (t * t) * 4.0f;
    float k3 = u * t * (t * t) * 4.0f;
    float k4 = t * t * (t * t);

    return a * k0 + b * k1 + c * k2 + d * k3 + e * k4;
}
