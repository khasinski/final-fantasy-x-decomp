#include "p9_overlay.h"

/* Angle wrap helpers and angle table sampling (family F8, TU rank 29). */

#define PI 3.1415927f
#define TWO_PI 6.2831855f

float func_01B05110(float a, float b)
{
    if (a < 0.0f) {
        if (0.0f < b) {
            if (b - a > PI) {
                b = -PI - (PI - b);
            }
        }
    } else if (b < 0.0f) {
        if (a - b > PI) {
            b = b + PI + PI;
        }
    }
    return b;
}

float func_01B05198(float a, float b)
{
    if (b < a) {
        a -= b;
        if (a > PI) {
            a = b + TWO_PI;
        } else {
            a = b;
        }
    } else {
        a = b - a;
        if (a > PI) {
            a = b - TWO_PI;
        } else {
            a = b;
        }
    }
    return a;
}

float func_01B05210(float *tbl, int n, int stride, float x)
{
    int i = x;
    float p0 = tbl[i * stride] + PI;
    float p1;
    int j;

    if (i == n - 1) {
        p1 = p0;
    } else {
        p1 = func_01B05198(p0, tbl[(i + 1) * stride] + PI);
    }
    x -= i;
    if (x < 0.5f) {
        if (i != 0) {
            j = i - 1;
            p0 += ((p1 + func_01B05198(p0, tbl[j * stride] + PI)) * 0.5f - p0) / (1.51f / (0.5f - x));
        }
    } else {
        j = i >= n - 2 ? n - 1 : i + 2;
        p1 += ((p0 + func_01B05198(p1, tbl[j * stride] + PI)) * 0.5f - p1) / (1.51f / (x - 0.499999f));
    }
    {
        float d;

        if (x != 0.0f) {
            d = (p1 - p0) / (1.0f / x);
        } else {
            d = 0.0f;
        }
        p0 += d;
    }
    j = p0 / TWO_PI;
    if (j > 0) {
        p0 -= j * TWO_PI;
    }
    if (p0 < 0.0f) {
        p0 += PI;
    } else {
        p0 -= PI;
    }
    return p0;
}
