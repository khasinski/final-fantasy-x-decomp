/* Battle-effect overlay 09532: byte-exact C helpers and callbacks. */
#include "common.h"

double func_002ED038(float);
double func_002E9290(double);
float func_002EC440(double);
float func_01B012C0(float *v)
{
    float len;
    float inv;

    len = v[0] * v[0] + v[1] * v[1] + v[2] * v[2];
    func_002ED038(len);
    len = func_002EC440(func_002E9290(func_002ED038(len)));
    if (len != 0.0f) {
        inv = 1.0f / len;
        v[0] = v[0] * inv;
        v[1] = v[1] * inv;
        v[2] = v[2] * inv;
    }
    return len;
}

int func_01B01380(char *fmt, ...)
{
    return 0;
}

void func_01B013B0(char *fmt, ...)
{
}

int func_01B013D8(char *fmt, ...)
{
    return 0;
}

void func_01B01408(void)
{
}

void func_01B01410(void)
{
}

void func_01B01418(int a, int b)
{
}
