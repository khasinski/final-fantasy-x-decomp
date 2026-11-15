/* EE Battle-Effect Overlay: group 0x11, file 09660
 * Load base: 0x01B00000, .text: 0x01B00700..0x01B01364
 *
 * Particle scene shell ("tt_scene"): ppp part start/run/free, a small timed-callback ring
 * (24-byte entries, 8-byte slots) and debug-print stubs.
 */
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

extern int D_01B00508;
extern int D_01B0050C;
extern int D_01B00510;
extern u8 *D_01B00514;
extern u8 *D_01B00518;
extern int D_01B0051C;
extern int *D_01B00520;
extern TtCfg *D_01B00524;
extern TtHeap D_01B00528;
extern TtPart D_01B00560;
extern char D_01B01370[];
extern float D_01B013F0[4];
void func_002DD0B0(void *, void *);
void func_002DD128(void *);
void func_002DCEC8(void *, void *);
void func_002DCE80(void *, void *, void *);
void func_002DD038(void *, void *, void *);
int func_002EFD78(void);
extern void *D_01B005E0;
extern char D_01B013B0[];
void *func_0013B150(int);
extern int D_01B005E4;
extern TtRing D_01B005E8;
extern TtEnt D_01B004F0[];
extern u8 D_01B00040[];
extern u8 D_01B01430[];
extern u8 D_01B7D610[];
extern char D_01B01388[];
extern char D_01B013A0[];
extern char D_01B013B8[];
extern char D_01B013C8[];
extern char D_01B01400[];
extern char D_01B01410[];

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

int func_01B00FE8(char *fmt, ...);
void func_01B01018(char *fmt, ...);
int func_01B01040(char *fmt, ...);
void func_01B01080(int a, int b);
void func_01B01090(TtRing *r, TtEnt *tbl, int n);
int func_01B01140(TtRing *r);
int func_01B01298(TtRing *r);

int func_01B00700(TtPart *p)
{
    func_01B00FE8(D_01B01370, D_01B005E4);
    D_006A3924 = &D_01B00528;
    _pppStartPart(p, 0x1000, *D_01B00524->w10, 1);
    p->f40 = 0.0f;
    p->f44 = 9.999999974752427e-07f;
    p->f48 = 9.799854278564453f;
    p->f4C = 1.0f;
    p->w50 = 0;
    p->w54 = 0;
    p->w58 = 0;
    p->w5C = 1;
    p->f60 = 0.011300000362098217f;
    p->f64 = 0.011300000362098217f;
    p->f68 = 0.011300000362098217f;
    p->f6C = 1.0f;
}

int func_01B007C8(TtPart *p)
{
    pppSetMatrix(p);
    func_002DCE38(D_006A39B0, D_006A3970, D_006A3930);
    func_002DCE38(D_006A3AB0, D_006A3A70, D_006A39B0);
    D_006A3924 = &D_01B00528;
    return _pppRunPart(p, 0x30) == 0;
}

int func_01B00850(TtPart *p)
{
    func_01B00FE8(D_01B01388, D_01B005E4);
    D_006A3924 = &D_01B00528;
    _pppAllFreePObject(p);
    return 1;
}

int func_01B008A0(int a)
{
    u8 *base;
    TtCfg *c;

    func_01B00FE8(D_01B013A0);
    base = D_01B7D610;
    D_01B00514 = base;
    D_01B00518 = base + 0x80000;
    D_01B0051C = a;
    D_01B00520 = (int *)D_01B01430;
    op_oef2_set2(D_01B00520);
    func_002D02E8(D_01B00520, 0, 1000, 0x2000);
    D_01B00524 = (TtCfg *)op_oef2_a_get(D_01B00520, 8, 0);
    _pppInitData(D_01B00524, D_01B00040);
    pppInitEnv(&D_01B00528, D_01B00524, D_01B00514, 0x80000);
    c = D_01B00524;
    D_01B00528.w20 = c->w14;
    D_01B00528.w24 = c->w18;
    D_01B00528.w28 = c->w1c;
    func_01B01090(&D_01B005E8, D_01B004F0, 1);
    D_01B005E0 = func_0013B150(5);
    if (D_01B005E0 == 0) {
        func_01B01018(D_01B013B0);
    }
    return 1;
}

int func_01B009D8(void)
{
    return 1;
}

int func_01B009E0(void)
{
    return 1;
}

int func_01B009E8(void)
{
    if (Sg_GetCurExecFrames() == 0) {
        return 0;
    }
    if (D_01B00508 == 0) {
        if (func_0029B830(0x2000) != 0) {
            return 1;
        }
        D_01B00508 = D_01B00508 + 1;
    }
    if (D_01B0050C == 0) {
        D_01B0050C = 1;
        MsEffectReady(D_01B0051C, 0);
    }
    if (D_01B00510 == 0) {
        if (MsEffectMotionLevel(D_01B0051C) > 0) {
            D_01B00510 = D_01B00510 + 1;
            return D_01B00510;
        }
        return 1;
    }
    return D_01B00510;
}

int func_01B00AA0(void)
{
    int running = 1;

    if (D_01B00510 == 0) {
        return 0;
    }
    D_006A3924 = &D_01B00528;
    func_001AACA0(D_006A3A70);
    func_001A9EE0(D_006A3970);
    D_006A3BCC = (int)D_01B00518;
    if (func_0014AA50(1) != 0) {
        func_01B01080(0x20, 0x1A);
        func_01B01040(D_01B013B8, D_01B005E8.frame);
        running = func_01B01140(&D_01B005E8);
    }
    if (running == 0) {
        func_01B01298(&D_01B005E8);
        func_01B00FE8(D_01B013C8, D_01B005E4);
        MsEffectTerminate(D_01B0051C);
        return 1;
    }
    D_01B005E4 = D_01B005E4 + 1;
    return 1;
}

int func_01B00B98(void)
{
    return 1;
}

int func_01B00BA0(void)
{
    return 1;
}

typedef union TtVec { float v[4]; double d[2]; } TtVec;

void func_01B00BA8(float *dst, float *src)
{
    func_002DD0B0(dst, src + 8);
}

void func_01B00BB0(float *v)
{
    float divisor = 32767.0f;
    float half = 0.5f;

    v[0] = ((float)(func_002EFD78() & 0x7FFF) / divisor - half) * 2.0f;
    v[1] = ((float)(func_002EFD78() & 0x7FFF) / divisor - half) * 2.0f;
    v[2] = ((float)(func_002EFD78() & 0x7FFF) / divisor - half) * 2.0f;
    v[3] = 1.0f;
    func_002DCEC8(v, v);
}

void func_01B00C80(float *m, float scale)
{
    func_002DD128(m);
    m[10] = scale;
    m[5] = scale;
    m[0] = scale;
}

void func_01B00CC0(float *a, float *b)
{
    float tmp[4];

    func_002DD0B0(tmp, a);
    func_002DD0B0(a, b);
    func_002DD0B0(b, tmp);
}

void func_01B00D10(float *m, float *dir)
{
    float x[4];
    float y[4];
    float z[4];
    TtVec up = *(const TtVec *)D_01B013F0;

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

void func_01B00E08(float *m, float *from, float *to)
{
    float delta[4];
    float x[4];
    float y[4];
    float z[4];
    TtVec up = *(const TtVec *)D_01B013F0;

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

float func_01B00F28(float *v)
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

int func_01B00FE8(char *fmt, ...)
{
    return 0;
}

void func_01B01018(char *fmt, ...)
{
}

int func_01B01040(char *fmt, ...)
{
    return 0;
}

void func_01B01070(void)
{
}

void func_01B01078(void)
{
}

void func_01B01080(int a, int b)
{
}

void func_01B01088(void)
{
}

void func_01B01090(TtRing *r, TtEnt *tbl, int n)
{
    int i;

    func_01B00FE8(D_01B01400);
    if (n > 32) {
        func_01B01018(D_01B01400);
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

int func_01B01140(TtRing *r)
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

int func_01B01298(TtRing *r)
{
    int i;
    TtEnt *e;
    int *sl;

    func_01B00FE8(D_01B01410);

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
        func_01B01018(D_01B01410);
    }
}
