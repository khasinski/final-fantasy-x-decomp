#include "common.h"

extern void fn_002dd998(void *, void *, float);

void ovl_09478_01b0c640(u8 *a0, float f12) {
    fn_002dd998(a0, a0, f12);
    fn_002dd998(a0 + 16, a0 + 16, f12);
    fn_002dd998(a0 + 32, a0 + 32, f12);
}

float ovl_09478_01b0c698(float a, float b) {
    if (a < 0.0f) {
        if (b > 0.0f && b - a > 3.1415927410125732f) {
            b = -3.1415927410125732f - (3.1415927410125732f - b);
        }
    } else if (b < 0.0f) {
        if (a - b > 3.1415927410125732f) {
            b = (b + 3.1415927410125732f) + 3.1415927410125732f;
        }
    }
    return b;
}

float ovl_09478_01b0c720(float a, float b) {
    if (b < a) {
        a -= b;
        if (a > 3.1415927410125732f) {
            a = b + 6.2831854820251465f;
        } else {
            a = b;
        }
    } else {
        a = b - a;
        if (a > 3.1415927410125732f) {
            a = b - 6.2831854820251465f;
        } else {
            a = b;
        }
    }
    return a;
}
