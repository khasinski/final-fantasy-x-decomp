/* Battle-effect overlay 09734: byte-exact C helpers and callbacks. */
#include "common.h"

void func_002DD0B0(void *, void *);
void func_002DD128(void *);
void func_002DCEC8(void *, void *);
void func_002DCE80(void *, void *, void *);
void func_002DD038(void *, void *, void *);
int func_002EFD78(void);
double func_002ED038(float);
double func_002E9290(double);
float func_002EC440(double);
extern float D_01B039E0[4];
typedef union TtVec
{
    float v[4];
    double d[2];
}
TtVec;

void func_001072F8(void *, int, float *);
void func_01B023D8(float *m)
{
    func_002DCEC8(m, m);
    func_002DCEC8(m + 4, m + 4);
    func_002DCEC8(m + 8, m + 8);
}
void func_01B02418(void *a, int b, float *m)
{
    func_001072F8(a, b, m);
    func_01B023D8(m);
}
void func_01B02440(float *dst, float *src)
{
    func_002DD0B0(dst, src + 8);
}

void func_01B02448(float *v)
{
    float divisor = 32767.0f;
    float half = 0.5f;

    v[0] = ((float)(func_002EFD78() & 0x7FFF) / divisor - half) * 2.0f;
    v[1] = ((float)(func_002EFD78() & 0x7FFF) / divisor - half) * 2.0f;
    v[2] = ((float)(func_002EFD78() & 0x7FFF) / divisor - half) * 2.0f;
    v[3] = 1.0f;
    func_002DCEC8(v, v);
}

void func_01B02518(float *m, float scale)
{
    func_002DD128(m);
    m[10] = scale;
    m[5] = scale;
    m[0] = scale;
}

void func_01B02558(float *a, float *b)
{
    float tmp[4];

    func_002DD0B0(tmp, a);
    func_002DD0B0(a, b);
    func_002DD0B0(b, tmp);
}

void func_01B025A8(float *m, float *dir)
{
    float x[4];
    float y[4];
    float z[4];
    TtVec up = *(const TtVec *)D_01B039E0;

    func_002DCEC8(z, dir);
    func_002DCE80(x, &up, z);
    func_002DCE80(y, z, x);
    func_002DCEC8(x, x);
    func_002DCEC8(y, y);
    ((u_long128 *)m)[3] = 0;
    m[0] = x[0]; m[1] = x[1]; m[2] = x[2]; m[3] = 0;
    m[4] = y[0]; m[5] = y[1]; m[6] = y[2]; m[7] = 0;
    m[8] = z[0]; m[9] = z[1]; m[10] = z[2]; m[11] = 0;
    m[15] = 1.0f;
}

void func_01B026A0(float *m, float *from, float *to)
{
    float delta[4];
    float x[4];
    float y[4];
    float z[4];
    TtVec up = *(const TtVec *)D_01B039E0;

    func_002DD038(delta, to, from);
    func_002DCEC8(z, delta);
    func_002DCE80(x, &up, z);
    func_002DCE80(y, z, x);
    func_002DCEC8(x, x);
    func_002DCEC8(y, y);
    ((u_long128 *)m)[3] = 0;
    m[0] = x[0]; m[1] = x[1]; m[2] = x[2]; m[3] = 0;
    m[4] = y[0]; m[5] = y[1]; m[6] = y[2]; m[7] = 0;
    m[8] = z[0]; m[9] = z[1]; m[10] = z[2]; m[11] = 0;
    m[15] = 1.0f;
}

float func_01B027C0(float *v)
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

int func_01B02880(char *fmt, ...)
{
    return 0;
}

void func_01B028B0(char *fmt, ...)
{
}

int func_01B028D8(char *fmt, ...)
{
    return 0;
}

void func_01B02908(void)
{
}

void func_01B02910(void)
{
}

void func_01B02918(int a, int b)
{
}

void func_01B02920(void)
{
}

void func_01B02928(void)
{
}
void func_01B02930(void)
{
}
