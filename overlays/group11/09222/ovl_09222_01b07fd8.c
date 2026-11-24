#include "common.h"

extern float func_01B08410(float);

int func_01B07FD8(int mode, float y, float g, float vy, float *out)
{
    float tmp;
    float d;
    float a;
    float b;
    float c;
    float b2;
    float ac4;
    float r1;
    float r2;

    a = g * 0.5f;
    b = vy;
    c = -y;
    b2 = b * b;
    ac4 = a * 4.0f * c;
    d = b2 - ac4;
    if (d < 0.0f) {
        return 0;
    }

    tmp = func_01B08410(d);
    r1 = -b + tmp;
    r2 = -b - tmp;
    tmp = 1.0f / (2.0f * a);
    r1 = r1 * tmp;
    r2 = r2 * tmp;

    if (mode != 0) {
        if (r1 > r2) {
            if (r1 > 0.0f) {
                *out = r1;
            } else if (r2 > 0.0f) {
                *out = r2;
            } else {
                return 0;
            }
        } else {
            if (r2 > 0.0f) {
                *out = r2;
            } else if (r1 > 0.0f) {
                *out = r1;
            } else {
                return 0;
            }
        }
    } else {
        if (r1 < r2) {
            if (r1 > 0.0f) {
                *out = r1;
            } else if (r2 > 0.0f) {
                *out = r2;
            } else {
                return 0;
            }
        } else {
            if (r2 > 0.0f) {
                *out = r2;
            } else if (r1 > 0.0f) {
                *out = r1;
            } else {
                return 0;
            }
        }
    }

    return 1;
}
