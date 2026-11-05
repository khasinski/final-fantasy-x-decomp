/* EE Battle-Effect Overlay: group 0x11, file 09412
 * Load base: 0x01B00000, .text: 0x01B005C0..0x01B00E5C
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

extern int D_01B003C8;
extern int D_01B003CC;
extern int D_01B003D0;
extern u8 *D_01B003D4;
extern u8 *D_01B003D8;
extern int D_01B003DC;
extern int *D_01B003E0;
extern TtCfg *D_01B003E4;
extern TtHeap D_01B003E8;
extern TtPart D_01B00420;
extern int D_01B004A4;
extern TtRing D_01B004A8;
extern TtEnt D_01B003B0[];
extern u8 D_01B00040[];
extern u8 D_01B00EF0[];
extern u8 D_01B2B0B0[];
extern char D_01B00E68[];
extern char D_01B00E80[];
extern char D_01B00E90[];
extern char D_01B00E98[];
extern char D_01B00EB8[];
extern char D_01B00EC8[];

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

int func_01B00AF8(char *fmt, ...);
void func_01B00B28(char *fmt, ...);
int func_01B00B50(char *fmt, ...);
void func_01B00B90(int a, int b);
void func_01B00B98(TtRing *r, TtEnt *tbl, int n);
int func_01B00C48(TtRing *r);
int func_01B00DA0(TtRing *r);

int func_01B005C0(void)
{
    return 1;
}

int func_01B005C8(void)
{
    TtPart *p = &D_01B00420;

    D_006A3924 = &D_01B003E8;
    _pppStartPart(p, 0x1000, *D_01B003E4->w10, 1);
    p->f40 = 13.0f;
    p->f44 = 70.0f;
    p->f48 = -57.0f;
    p->f4C = 1.0f;
    p->w50 = -0x1600;
    p->w54 = 0;
    p->w58 = 0;
    p->w5C = 1;
    p->f60 = 0.2804970145f;
    p->f64 = 0.2804970145f;
    p->f68 = 0.2804970145f;
    p->f6C = 1.0f;
}

int func_01B00680(void)
{
    pppSetMatrix(&D_01B00420);
    func_002DCE38(D_006A39B0, D_006A3970, D_006A3930);
    func_002DCE38(D_006A3AB0, D_006A3A70, D_006A39B0);
    D_006A3924 = &D_01B003E8;
    return _pppRunPart(&D_01B00420, 0x30) == 0;
}

int func_01B00710(void)
{
    func_01B00AF8(D_01B00E68, D_01B004A4);
    D_006A3924 = &D_01B003E8;
    _pppAllFreePObject(&D_01B00420);
    return 1;
}

int func_01B00758(int a)
{
    u8 *base;
    TtCfg *c;

    func_01B00AF8(D_01B00E80);
    base = D_01B2B0B0;
    D_01B003D4 = base;
    D_01B003D8 = base + 0x80000;
    D_01B003DC = a;
    D_01B003E0 = (int *)D_01B00EF0;
    op_oef2_set2(D_01B003E0);
    func_002D02E8(D_01B003E0, 0, 1000, 0x2000);
    D_01B003E4 = (TtCfg *)op_oef2_a_get(D_01B003E0, 8, 0);
    _pppInitData(D_01B003E4, D_01B00040);
    pppInitEnv(&D_01B003E8, D_01B003E4, D_01B003D4, 0x80000);
    c = D_01B003E4;
    D_01B003E8.w20 = c->w14;
    D_01B003E8.w24 = c->w18;
    D_01B003E8.w28 = c->w1c;
    func_01B00B98(&D_01B004A8, D_01B003B0, 1);
    return 1;
}

int func_01B00870(void)
{
    return 1;
}

int func_01B00878(void)
{
    return 1;
}

int func_01B00880(void)
{
    if (Sg_GetCurExecFrames() == 0) {
        return 0;
    }
    if (D_01B003C8 == 0) {
        if (func_0029B830(0x2000) != 0) {
            return 1;
        }
        D_01B003C8 = D_01B003C8 + 1;
    }
    if (D_01B003CC == 0) {
        D_01B003CC = 1;
        MsEffectReady(D_01B003DC, 0);
    }
    if (D_01B003D0 == 0) {
        if (MsEffectMotionLevel(D_01B003DC) > 0) {
            D_01B003D0 = D_01B003D0 + 1;
            return D_01B003D0;
        }
        return 1;
    }
    return D_01B003D0;
}

int func_01B00938(void)
{
    if (D_01B003D0 == 0) {
        return 0;
    }
    D_006A3924 = &D_01B003E8;
    func_001AACA0(D_006A3A70);
    func_001A9EE0(D_006A3970);
    D_006A3BCC = (int)D_01B003D8;
    if (func_0014AA50(0) != 0) {
        func_01B00B90(0x20, 0x1A);
        func_01B00B50(D_01B00E90, D_01B004A8.frame);
        func_01B00C48(&D_01B004A8);
    }
    if (func_0014AA50(1) != 0) {
        func_01B00DA0(&D_01B004A8);
        func_01B00AF8(D_01B00E98, D_01B004A4);
        MsEffectTerminate(D_01B003DC);
        return 1;
    }
    D_01B004A4 = D_01B004A4 + 1;
    return 1;
}

int func_01B00A28(void)
{
    return 1;
}

int func_01B00A30(void)
{
    return 1;
}

float func_01B00A38(float *v)
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

int func_01B00AF8(char *fmt, ...)
{
    return 0;
}

void func_01B00B28(char *fmt, ...)
{
}

int func_01B00B50(char *fmt, ...)
{
    return 0;
}

void func_01B00B80(void)
{
}

void func_01B00B88(void)
{
}

void func_01B00B90(int a, int b)
{
}

void func_01B00B98(TtRing *r, TtEnt *tbl, int n)
{
    int i;

    func_01B00AF8(D_01B00EB8);
    if (n > 32) {
        func_01B00B28(D_01B00EB8);
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

int func_01B00C48(TtRing *r)
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

int func_01B00DA0(TtRing *r)
{
    int i;
    TtEnt *e;
    int *sl;

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
        func_01B00B28(D_01B00EC8);
    }
}
