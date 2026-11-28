#include "common.h"

extern float func_002E89C0(float);

static inline float lerp(float a, float b, float t)
{
    return (1.0f - t) * a + t * b;
}

void func_01B013D0(float *out, float arg)
{
    float y = 0.0f;
    float s_arg = func_002E89C0(arg);
    int i;

    for (i = 0; i < 33; i++) {
        float sy = func_002E89C0((float)i * 0.03125f * 3.1415927410125732f);
        float x = 0.0f;
        float b = lerp(0.0f, 25.132741928100586f, sy);
        float a = lerp(1.5707963705062866f, 0.7853981852531433f, sy);
        int j;

        for (j = 0; j < 33; j++) {
            register float sx __asm__("$f21") = func_002E89C0(x * 3.1415927410125732f);
            float t1 = lerp(0.0f, 0.7853981852531433f, sx);
            float w;

            t1 = t1 * func_002E89C0(t1) * s_arg;
            w = b * func_002E89C0(t1) * s_arg;
            t1 = func_002E89C0(t1);
            t1 = func_002E89C0(t1 * func_002E89C0(w)) * 0.4000000059604645f * sx + x;
            if (t1 < 0.0f) {
                t1 = 0.0f;
            } else if (t1 > 1.0f) {
                t1 = 1.0f;
            }
            out[0] = t1;

            w = lerp(-12.566370964050293f, 12.566370964050293f, func_002E89C0(x));
            t1 = a * func_002E89C0(a) * s_arg;
            w = w * func_002E89C0(t1) * s_arg;
            t1 = func_002E89C0(t1);
            w = func_002E89C0(t1 * func_002E89C0(w)) * 0.30000001192092896f * sy + y;
            if (w < 0.01f) {
                w = 0.01f;
            }
            if (w < 0.0f) {
                w = 0.0f;
            } else if (w > 0.8125f) {
                w = 0.8125f;
            }
            out[1] = w;

            x += 0.03125f;
            out += 2;
        }
        y += 0.025390625f;
    }
}
