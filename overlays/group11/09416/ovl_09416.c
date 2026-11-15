/* EE Battle-Effect Overlay: group 0x11, file 09416
 * Load base: 0x01B00000, .text: 0x01B00700..0x01B0114C
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

extern int D_01B00480;
extern int D_01B00484;
extern int D_01B00488;
extern u8 *D_01B0048C;
extern u8 *D_01B00490;
extern int D_01B00494;
extern int *D_01B00498;
extern TtCfg *D_01B0049C;
extern TtHeap D_01B004A0;
extern TtPart D_01B004D0;
extern TtPart D_01B00550;
extern void *D_01B005D0;
extern void *D_01B005D4;
extern char D_01B01158[];
extern char D_01B011A8[];
void func_001089A8(void *, void *);
extern char D_01B01198[];
void *func_0013B150(int);
extern int D_01B005D8;
extern TtRing D_01B005E0;
extern TtEnt D_01B00450[];
extern u8 D_01B00040[];
extern u8 D_01B01210[];
extern u8 D_01B3D390[];
extern char D_01B01170[];
extern char D_01B01188[];
extern char D_01B011B8[];
extern char D_01B011C0[];
extern char D_01B011E0[];
extern char D_01B011F0[];

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

int func_01B00DE8(char *fmt, ...);
void func_01B00E18(char *fmt, ...);
int func_01B00E40(char *fmt, ...);
void func_01B00E80(int a, int b);
void func_01B00E88(TtRing *r, TtEnt *tbl, int n);
int func_01B00F38(TtRing *r);
int func_01B01090(TtRing *r);

int func_01B00700(TtPart *p)
{
    D_006A3924 = &D_01B004A0;
    _pppStartPart(p, 0x1000, D_01B0049C->w10[1], 1);
    func_001089A8(D_01B005D4, &p->f40);
    p->f44 -= 0.1f;
    p->w50 = 0;
    p->w54 = 0;
    p->w58 = 0;
    p->w5C = 1;
    p->f60 = 0.075f;
    p->f64 = 0.075f;
    p->f68 = 0.075f;
    p->f6C = 1.0f;
}

int func_01B007B0(TtPart *p)
{
    pppSetMatrix(p);
    func_002DCE38(D_006A39B0, D_006A3970, D_006A3930);
    func_002DCE38(D_006A3AB0, D_006A3A70, D_006A39B0);
    D_006A3924 = &D_01B004A0;
    return _pppRunPart(p, 0x30) == 0;
}

int func_01B00838(TtPart *p)
{
    func_01B00DE8(D_01B01158, D_01B005D8);
    D_006A3924 = &D_01B004A0;
    _pppAllFreePObject(p);
    return 1;
}

int func_01B00888(TtPart *p)
{
    D_006A3924 = &D_01B004A0;
    _pppStartPart(p, 0x1000, *D_01B0049C->w10, 1);
    p->f40 = -398.3934631347656f;
    p->f44 = 54.521873474121094f;
    p->f48 = -412.9638671875f;
    p->f4C = 1.0f;
    p->w50 = 0;
    p->w54 = 0;
    p->w58 = 0;
    p->w5C = 1;
    p->f60 = 0.075f;
    p->f64 = 0.075f;
    p->f68 = 0.075f;
    p->f6C = 1.0f;
}

int func_01B00940(TtPart *p)
{
    pppSetMatrix(p);
    func_002DCE38(D_006A39B0, D_006A3970, D_006A3930);
    func_002DCE38(D_006A3AB0, D_006A3A70, D_006A39B0);
    D_006A3924 = &D_01B004A0;
    return _pppRunPart(p, 0x30) == 0;
}

int func_01B009C8(TtPart *p)
{
    func_01B00DE8(D_01B01170, D_01B005D8);
    D_006A3924 = &D_01B004A0;
    _pppAllFreePObject(p);
    return 1;
}

int func_01B00A18(int a)
{
    u8 *base;
    TtCfg *c;

    func_01B00DE8(D_01B01188);
    base = D_01B3D390;
    D_01B0048C = base;
    D_01B00490 = base + 0x80000;
    D_01B00494 = a;
    D_01B00498 = (int *)D_01B01210;
    op_oef2_set2(D_01B00498);
    func_002D02E8(D_01B00498, 0, 1000, 0x2000);
    D_01B0049C = (TtCfg *)op_oef2_a_get(D_01B00498, 8, 0);
    _pppInitData(D_01B0049C, D_01B00040);
    pppInitEnv(&D_01B004A0, D_01B0049C, D_01B0048C, 0x80000);
    c = D_01B0049C;
    D_01B004A0.w20 = c->w14;
    D_01B004A0.w24 = c->w18;
    D_01B004A0.w28 = c->w1c;
    func_01B00E88(&D_01B005E0, D_01B00450, 2);
    D_01B005D0 = func_0013B150(4);
    if (D_01B005D0 == 0) {
        func_01B00E18(D_01B01198);
    }
    D_01B005D4 = func_0013B150(0);
    if (D_01B005D4 == 0) {
        func_01B00E18(D_01B011A8);
    }
    return 1;
}

int func_01B00B70(void)
{
    return 1;
}

int func_01B00B78(void)
{
    return 1;
}

int func_01B00B80(void)
{
    if (Sg_GetCurExecFrames() == 0) {
        return 0;
    }
    if (D_01B00480 == 0) {
        if (func_0029B830(0x2000) != 0) {
            return 1;
        }
        D_01B00480 = D_01B00480 + 1;
    }
    if (D_01B00484 == 0) {
        D_01B00484 = 1;
        MsEffectReady(D_01B00494, 0);
    }
    if (D_01B00488 == 0) {
        if (MsEffectMotionLevel(D_01B00494) > 0) {
            D_01B00488 = D_01B00488 + 1;
            return D_01B00488;
        }
        return 1;
    }
    return D_01B00488;
}

int func_01B00C38(void)
{
    if (D_01B00488 == 0) {
        return 0;
    }
    D_006A3924 = &D_01B004A0;
    func_001AACA0(D_006A3A70);
    func_001A9EE0(D_006A3970);
    D_006A3BCC = (int)D_01B00490;
    if (func_0014AA50(0) != 0) {
        func_01B00E80(0x20, 0x1A);
        func_01B00E40(D_01B011B8, D_01B005E0.frame);
        if (func_01B00F38(&D_01B005E0) == 0) {
            func_01B00DE8(D_01B011C0, D_01B005D8);
            MsEffectTerminate(D_01B00494);
            return 1;
        }
    }
    D_01B005D8 = D_01B005D8 + 1;
    return 1;
}

int func_01B00D18(void)
{
    return 1;
}

int func_01B00D20(void)
{
    return 1;
}

float func_01B00D28(float *v)
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

int func_01B00DE8(char *fmt, ...)
{
    return 0;
}

void func_01B00E18(char *fmt, ...)
{
}

int func_01B00E40(char *fmt, ...)
{
    return 0;
}

void func_01B00E70(void)
{
}

void func_01B00E78(void)
{
}

void func_01B00E80(int a, int b)
{
}

void func_01B00E88(TtRing *r, TtEnt *tbl, int n)
{
    int i;

    func_01B00DE8(D_01B011E0);
    if (n > 32) {
        func_01B00E18(D_01B011E0);
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

int func_01B00F38(TtRing *r)
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

int func_01B01090(TtRing *r)
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
        func_01B00E18(D_01B011F0);
    }
}
