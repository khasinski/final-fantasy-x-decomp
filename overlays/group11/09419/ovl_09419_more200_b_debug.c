/* Battle-effect overlay 09419: byte-exact C helpers and callbacks. */
#include "common.h"

double func_002ED038(float);
double func_002E9290(double);
float func_002EC440(double);
float func_01B03348(float *v)
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

int func_01B03408(char *fmt, ...)
{
    return 0;
}

void func_01B03438(char *fmt, ...)
{
}

int func_01B03460(char *fmt, ...)
{
    return 0;
}

void func_01B03490(void)
{
}

void func_01B03498(void)
{
}

void func_01B034A0(int a, int b)
{
}
