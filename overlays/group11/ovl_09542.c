/* EE Battle-Effect Overlay: group 0x11, file 09542
 * Load base: 0x01B00000, .text: 0x01B008D0..0x01B016B4
 *
 * Particle scene shell ("tt_scene"): ppp part start/run/free, a small timed-callback ring
 * (24-byte entries, 8-byte slots) and debug-print stubs.
 */
#include "common.h"
extern char D_01B016F0[];
extern char D_01B01708[];

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

typedef struct TtCfg {
    u8 pad00[0x10];
    int *w10;
    int w14;
    void **w18;
    char *w1c;
} TtCfg;

typedef struct TtHeap {
    u8 pad00[0x20];
    int w20;
    void **w24;
    char *w28;
} TtHeap;

typedef struct TtPart {
    u8 pad00[0x40];
    float f40;
    float f44;
    float f48;
    float f4C;
    int w50;
    int w54;
    int w58;
    int w5C;
    float f60;
    float f64;
    float f68;
    float f6C;
} TtPart;

extern int D_01B00660;
extern int D_01B00664;
extern int D_01B00668;
extern u8 *D_01B0066C;
extern u8 *D_01B00670;
extern int D_01B00674;
extern int *D_01B00678;
extern TtCfg *D_01B0067C;
extern TtHeap D_01B00680;
extern TtPart D_01B006C0;
extern char D_01B016C0[];
extern float D_01B01760[4];
void func_002DD0B0(void *, void *);
void func_002DD128(void *);
void func_002DCEC8(void *, void *);
void func_002DCE80(void *, void *, void *);
void func_002DD038(void *, void *, void *);
int func_002EFD78(void);
extern void *D_01B007AC;
extern char D_01B01728[];
void *func_0013B150(int);
extern int D_01B007B0;
extern TtRing D_01B007B8;
extern TtEnt D_01B00630[];
extern u8 D_01B00040[];
extern u8 D_01B017A0[];
extern u8 D_01B2EB90[];
extern char D_01B016D8[];
extern char D_01B01720[];
extern char D_01B01730[];
extern char D_01B01740[];
extern char D_01B01770[];
extern char D_01B01780[];

extern void *D_006A3924;
extern u8 D_006A3930[];
extern u8 D_006A3970[];
extern u8 D_006A39B0[];
extern u8 D_006A3A70[];
extern u8 D_006A3AB0[];
extern int D_006A3BCC;

void _pppStartPart(void *part, int a, int b, int c);
void pppSetMatrix(void *part);
int _pppRunPart(void *part, int n);
void _pppAllFreePObject(void *part);
void _pppInitData(void *a, void *b);
void pppInitEnv(void *heap, void *cfg, void *base, int size);
void op_oef2_set2(void *tbl);
void func_002D02E8(void *a, int b, int c, int d);
int *op_oef2_a_get(void *tbl, int a, int b);
void func_002DCE38(void *a, void *b, void *c);
int Sg_GetCurExecFrames(void);
int func_0029B830(int a);
int MsEffectReady(int id, int flag);
int MsEffectMotionLevel(int id);
void MsEffectTerminate(int id);
void func_001AACA0(void *m);
void func_001A9EE0(void *m);
int func_0014AA50(int a);
void *func_002EF0D0(void *p, int v, int n);
double func_002ED038(float f);
double func_002E9290(double d);
float func_002EC440(double d);

int func_01B01338(char *fmt, ...);
void func_01B01368(char *fmt, ...);
int func_01B01390(char *fmt, ...);
void func_01B013D0(int a, int b);
void func_01B013E0(TtRing *r, TtEnt *tbl, int n);
int func_01B01490(TtRing *r);
int func_01B015E8(TtRing *r);

int func_01B008D0(TtPart *p)
{
    func_01B01338(D_01B016C0, D_01B007B0);
    D_006A3924 = &D_01B00680;
    _pppStartPart(p, 0x1000, D_01B0067C->w10[1], 1);
    p->f40 = 0.0f;
    p->f44 = -7.999999046325684f;
    p->f48 = -26.20008087158203f;
    p->f4C = 1.0f;
    p->w50 = 0;
    p->w54 = 0;
    p->w58 = 0;
    p->w5C = 1;
    p->f60 = 0.011297999881207943f;
    p->f64 = 0.011297999881207943f;
    p->f68 = 0.011297999881207943f;
    p->f6C = 1.0f;
}

int func_01B00998(TtPart *p)
{
    pppSetMatrix(p);
    func_002DCE38(D_006A39B0, D_006A3970, D_006A3930);
    func_002DCE38(D_006A3AB0, D_006A3A70, D_006A39B0);
    D_006A3924 = &D_01B00680;
    return _pppRunPart(p, 0x30) == 0;
}

int func_01B00A20(TtPart *p)
{
    func_01B01338(D_01B016D8, D_01B007B0);
    D_006A3924 = &D_01B00680;
    _pppAllFreePObject(p);
    return 1;
}

int func_01B00A70(TtPart *p)
{
    func_01B01338(D_01B016F0, D_01B007B0);
    D_006A3924 = &D_01B00680;
    _pppStartPart(p, 0x1000, D_01B0067C->w10[0], 1);
    p->f40 = 1.7999980449676514f;
    p->f44 = -7.799980163574219f;
    p->f48 = -24.099462509155273f;
    p->f4C = 1.0f;
    p->w50 = 0;
    p->w54 = 0;
    p->w58 = 0;
    p->w5C = 1;
    p->f60 = 0.091498002409935f;
    p->f64 = 0.091498002409935f;
    p->f68 = 0.091498002409935f;
    p->f6C = 1.0f;
}

int func_01B00B40(TtPart *p)
{
    pppSetMatrix(p);
    func_002DCE38(D_006A39B0, D_006A3970, D_006A3930);
    func_002DCE38(D_006A3AB0, D_006A3A70, D_006A39B0);
    D_006A3924 = &D_01B00680;
    return _pppRunPart(p, 0x30) == 0;
}

int func_01B00BC8(TtPart *p)
{
    func_01B01338(D_01B01708, D_01B007B0);
    D_006A3924 = &D_01B00680;
    _pppAllFreePObject(p);
    return 1;
}

int func_01B00C18(int a)
{
    u8 *base;
    TtCfg *c;

    func_01B01338(D_01B01720);
    base = D_01B2EB90;
    D_01B0066C = base;
    D_01B00670 = base + 0x80000;
    D_01B00674 = a;
    D_01B00678 = (int *)D_01B017A0;
    op_oef2_set2(D_01B00678);
    func_002D02E8(D_01B00678, 0, 1000, 0x2000);
    D_01B0067C = (TtCfg *)op_oef2_a_get(D_01B00678, 8, 0);
    _pppInitData(D_01B0067C, D_01B00040);
    pppInitEnv(&D_01B00680, D_01B0067C, D_01B0066C, 0x80000);
    c = D_01B0067C;
    D_01B00680.w20 = c->w14;
    D_01B00680.w24 = c->w18;
    D_01B00680.w28 = c->w1c;
    func_01B013E0(&D_01B007B8, D_01B00630, 2);
    return 1;
}

int func_01B00D30(void)
{
    return 1;
}

int func_01B00D38(void)
{
    return 1;
}

int func_01B00D40(void)
{
    if (Sg_GetCurExecFrames() == 0) {
        return 0;
    }
    if (D_01B00660 == 0) {
        if (func_0029B830(0x2000) != 0) {
            return 1;
        }
        D_01B00660 = D_01B00660 + 1;
    }
    if (D_01B00664 == 0) {
        D_01B00664 = 1;
        MsEffectReady(D_01B00674, 0);
    }
    if (D_01B00668 == 0) {
        if (MsEffectMotionLevel(D_01B00674) > 0) {
            D_01B00668 = D_01B00668 + 1;
            return D_01B00668;
        }
        return 1;
    }
    return D_01B00668;
}

int func_01B00DF8(void)
{
    if (D_01B00668 == 0) {
        return 0;
    }
    D_006A3924 = &D_01B00680;
    func_001AACA0(D_006A3A70);
    func_001A9EE0(D_006A3970);
    D_006A3BCC = (int)D_01B00670;
    if (func_0014AA50(0) != 0) {
        func_01B013D0(0x20, 0x1A);
        func_01B01390(D_01B01730, D_01B007B8.frame);
        func_01B01490(&D_01B007B8);
    }
    if (func_0014AA50(1) != 0) {
        func_01B015E8(&D_01B007B8);
        func_01B01338(D_01B01740, D_01B007B0);
        MsEffectTerminate(D_01B00674);
        return 1;
    }
    D_01B007B0 = D_01B007B0 + 1;
    return 1;
}

int func_01B00EE8(void)
{
    return 1;
}

int func_01B00EF0(void)
{
    return 1;
}

typedef union TtVec { float v[4]; double d[2]; } TtVec;

void func_01B00EF8(float *dst, float *src)
{
    func_002DD0B0(dst, src + 8);
}

void func_01B00F00(float *v)
{
    float divisor = 32767.0f;
    float half = 0.5f;

    v[0] = ((float)(func_002EFD78() & 0x7FFF) / divisor - half) * 2.0f;
    v[1] = ((float)(func_002EFD78() & 0x7FFF) / divisor - half) * 2.0f;
    v[2] = ((float)(func_002EFD78() & 0x7FFF) / divisor - half) * 2.0f;
    v[3] = 1.0f;
    func_002DCEC8(v, v);
}

void func_01B00FD0(float *m, float scale)
{
    func_002DD128(m);
    m[10] = scale;
    m[5] = scale;
    m[0] = scale;
}

void func_01B01010(float *a, float *b)
{
    float tmp[4];

    func_002DD0B0(tmp, a);
    func_002DD0B0(a, b);
    func_002DD0B0(b, tmp);
}

void func_01B01060(float *m, float *dir)
{
    float x[4];
    float y[4];
    float z[4];
    TtVec up = *(const TtVec *)D_01B01760;

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

void func_01B01158(float *m, float *from, float *to)
{
    float delta[4];
    float x[4];
    float y[4];
    float z[4];
    TtVec up = *(const TtVec *)D_01B01760;

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

float func_01B01278(float *v)
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

int func_01B01338(char *fmt, ...)
{
    return 0;
}

void func_01B01368(char *fmt, ...)
{
}

int func_01B01390(char *fmt, ...)
{
    return 0;
}

void func_01B013C0(void)
{
}

void func_01B013C8(void)
{
}

void func_01B013D0(int a, int b)
{
}

void func_01B013D8(void)
{
}

void func_01B013E0(TtRing *r, TtEnt *tbl, int n)
{
    int i;

    func_01B01338(D_01B01770);
    if (n > 32) {
        func_01B01368(D_01B01770);
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

int func_01B01490(TtRing *r)
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

int func_01B015E8(TtRing *r)
{
    int i;
    TtEnt *e;
    int *sl;

    func_01B01338(D_01B01780);

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
        func_01B01368(D_01B01780);
    }
}
