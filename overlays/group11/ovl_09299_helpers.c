/* Overlay 09299: matrix/vector helpers and timed callback queue. */
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

extern float D_01B01B40[4];
void func_002DD0B0(void *, void *);
void func_002DD128(void *);
void func_002DCEC8(void *, void *);
void func_002DCE80(void *, void *, void *);
void func_002DD038(void *, void *, void *);
int func_002EFD78(void);
extern char D_01B014E0[];
extern char D_01B014E0[];
extern char D_01B01B50[];
extern char D_01B01B60[];

int Sg_GetCurExecFrames(void);
void *func_002EF0D0(void *p, int v, int n);
double func_002ED038(float f);
double func_002E9290(double d);
float func_002EC440(double d);

int func_01B016D8(char *fmt, ...);
void func_01B01708(char *fmt, ...);
int func_01B01730(char *fmt, ...);
void func_01B01770(int a, int b);
void func_01B01790(TtRing *r, TtEnt *tbl, int n);
int func_01B01840(TtRing *r);
int func_01B01998(TtRing *r);

typedef union TtVec { float v[4]; double d[2]; } TtVec;
extern float D_01B01B40[4];
void func_002DD128(void *);
void func_002DD0B0(void *, void *);
void func_002DD038(void *, void *, void *);
void func_002DCEC8(void *, void *);
void func_002DCE80(void *, void *, void *);
int func_002EFD78(void);
double func_002ED038(float);
double func_002E9290(double);
float func_002EC440(double);

void func_01B01230(float *m)
{
    func_002DCEC8(m, m);
    func_002DCEC8(m + 4, m + 4);
    func_002DCEC8(m + 8, m + 8);
}

void func_001072F8(void *, int, void *);
void func_01B01270(void *chr, int bone, float *m)
{
    func_001072F8(chr, bone, m);
    func_01B01230(m);
}
void func_01B01298(float *dst, float *src)
{
    func_002DD0B0(dst, src + 8);
}

void func_01B012A0(float *v)
{
    float divisor = 32767.0f;
    float half = 0.5f;

    v[0] = ((float)(func_002EFD78() & 0x7FFF) / divisor - half) * 2.0f;
    v[1] = ((float)(func_002EFD78() & 0x7FFF) / divisor - half) * 2.0f;
    v[2] = ((float)(func_002EFD78() & 0x7FFF) / divisor - half) * 2.0f;
    v[3] = 1.0f;
    func_002DCEC8(v, v);
}

void func_01B01370(float *m, float scale)
{
    func_002DD128(m);
    m[10] = scale;
    m[5] = scale;
    m[0] = scale;
}

void func_01B013B0(float *a, float *b)
{
    float tmp[4];

    func_002DD0B0(tmp, a);
    func_002DD0B0(a, b);
    func_002DD0B0(b, tmp);
}

void func_01B01400(float *m, float *dir)
{
    float x[4];
    float y[4];
    float z[4];
    TtVec up = *(const TtVec *)D_01B01B40;

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

void func_01B014F8(float *m, float *from, float *to)
{
    float delta[4];
    float x[4];
    float y[4];
    float z[4];
    TtVec up = *(const TtVec *)D_01B01B40;

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

float func_01B01618(float *v)
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

int func_01B016D8(char *fmt, ...)
{
    return 0;
}

void func_01B01708(char *fmt, ...)
{
}

int func_01B01730(char *fmt, ...)
{
    return 0;
}

void func_01B01760(void)
{
}

void func_01B01768(void)
{
}

void func_01B01770(int a, int b)
{
}

void func_01B01778(void)
{
}

void func_01B01780(void) {}
void func_01B01788(void) {}

void func_01B01790(TtRing *r, TtEnt *tbl, int n)
{
    int i;

    func_01B016D8(D_01B01B50);
    if (n > 32) {
        func_01B01708(D_01B01B50);
    }
    func_002EF0D0(r, 0, 0x110);
    r->tbl = tbl;
    r->n = n;
    r->active = n;
    for (i = 0; i < n; i++) {
        r->slot[i].on = 1;
    }
}

#define TT_RING_END(r, e, sl)         \
    if ((e)->on_end != 0) {           \
        (e)->on_end((e)->arg);        \
    }                                 \
    *(sl) = 0;                        \
    (r)->active = (r)->active - 1;    \
    if ((r)->active == 0) {           \
        return 0;                     \
    }

int func_01B01840(TtRing *r)
{
    int i;
    int res;
    TtEnt *e;
    int *sl;

    if (r->active == 0) {
        return 0;
    }
    sl = &r->slot[0].on;
    e = r->tbl;
    for (i = 0; i < r->n; i++, sl += 2, e++) {
        res = 777;
        if (*sl != 0) {
            if (r->frame < e->start) {
                continue;
            }
            if (r->frame == e->start) {
                if (e->on_start != 0) {
                    e->on_start(e->arg);
                }
            }
            if (e->on_run != 0) {
                res = e->on_run(e->arg);
            }
            if (e->len != -1) {
                if (r->frame == e->start + e->len - 1) {
                    TT_RING_END(r, e, sl)
                }
            } else if (res == 0) {
                TT_RING_END(r, e, sl)
            }
        }
    }
    if (Sg_GetCurExecFrames() == 0) {
        return 1;
    }
    r->frame = r->frame + 1;
    return 1;
}

int func_01B01998(TtRing *r)
{
    int i;
    TtEnt *e;
    int *sl;

    func_01B016D8(D_01B01B60);

    if (r->active == 0) {
        return 0;
    }
    sl = &r->slot[0].on;
    e = r->tbl;
    for (i = 0; i < r->n; i++, sl += 2, e++) {
        if (*sl != 0) {
            if (e->on_end != 0) {
                e->on_end(e->arg);
            }
            *sl = 0;
            r->active = r->active - 1;
        }
    }
    if (r->active != 0) {
        func_01B01708(D_01B01B60);
    }
}
