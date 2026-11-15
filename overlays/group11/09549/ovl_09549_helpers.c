/* Overlay 09549: vector, matrix, and timed callback helpers. */
#include "common.h"

typedef struct TtEnt {
    int start;
    int len;
    void (*on_start)(int);
    int (*on_run)(int);
    void (*on_end)(int);
    int arg;
} TtEnt;

typedef struct TtRing {
    int frame;
    int n;
    int active;
    struct {
        int on;
        int pad;
    } slot[32];
    TtEnt *tbl;
} TtRing;

extern float D_01B070D0[4];
void func_002DD0B0(void *, void *);
void func_002DD128(void *);
void func_002DCEC8(void *, void *);
void func_002DCE80(void *, void *, void *);
void func_002DD038(void *, void *, void *);
int func_002EFD78(void);
extern char D_01B014E0[];
extern char D_01B014E0[];
extern char D_01B070E0[];
extern char D_01B070F0[];

int Sg_GetCurExecFrames(void);
void *func_002EF0D0(void *p, int v, int n);
double func_002ED038(float f);
double func_002E9290(double d);
float func_002EC440(double d);

int func_01B063F0(char *fmt, ...);
void func_01B06420(char *fmt, ...);
int func_01B06448(char *fmt, ...);
void func_01B06488(int a, int b);
void func_01B06D28(TtRing *r, TtEnt *tbl, int n);
int func_01B06DD8(TtRing *r);
int func_01B06F30(TtRing *r);

typedef union TtVec { float v[4]; double d[2]; } TtVec;
extern float D_01B070D0[4];
void func_002DD128(void *);
void func_002DD0B0(void *, void *);
void func_002DD038(void *, void *, void *);
void func_002DCEC8(void *, void *);
void func_002DCE80(void *, void *, void *);
int func_002EFD78(void);
double func_002ED038(float);
double func_002E9290(double);
float func_002EC440(double);

void func_01B05F48(float *m)
{
    func_002DCEC8(m, m);
    func_002DCEC8(m + 4, m + 4);
    func_002DCEC8(m + 8, m + 8);
}

void func_001072F8(void *, int, void *);
void func_01B05F88(void *chr, int bone, float *m)
{
    func_001072F8(chr, bone, m);
    func_01B05F48(m);
}
void func_01B05FB0(float *dst, float *src)
{
    func_002DD0B0(dst, src + 8);
}

void func_01B05FB8(float *v)
{
    float divisor = 32767.0f;
    float half = 0.5f;

    v[0] = ((float)(func_002EFD78() & 0x7FFF) / divisor - half) * 2.0f;
    v[1] = ((float)(func_002EFD78() & 0x7FFF) / divisor - half) * 2.0f;
    v[2] = ((float)(func_002EFD78() & 0x7FFF) / divisor - half) * 2.0f;
    v[3] = 1.0f;
    func_002DCEC8(v, v);
}

void func_01B06088(float *m, float scale)
{
    func_002DD128(m);
    m[10] = scale;
    m[5] = scale;
    m[0] = scale;
}

void func_01B060C8(float *a, float *b)
{
    float tmp[4];

    func_002DD0B0(tmp, a);
    func_002DD0B0(a, b);
    func_002DD0B0(b, tmp);
}

void func_01B06118(float *m, float *dir)
{
    float x[4];
    float y[4];
    float z[4];
    TtVec up = *(const TtVec *)D_01B070D0;

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

void func_01B06210(float *m, float *from, float *to)
{
    float delta[4];
    float x[4];
    float y[4];
    float z[4];
    TtVec up = *(const TtVec *)D_01B070D0;

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

float func_01B06330(float *v)
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

int func_01B063F0(char *fmt, ...)
{
    return 0;
}

void func_01B06420(char *fmt, ...)
{
}

int func_01B06448(char *fmt, ...)
{
    return 0;
}

void func_01B06478(void)
{
}

void func_01B06480(void)
{
}

void func_01B06488(int a, int b)
{
}

void func_01B06490(void)
{
}

void func_01B06498(void) {}
void func_01B064A0(void) {}
