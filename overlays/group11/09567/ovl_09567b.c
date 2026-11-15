/* EE Battle-Effect Overlay: group 0x11, file 09567
 * Load base: 0x01B00000, .text: 0x01B01148..0x01B01D04
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
    u8 pad70[16];
} TtPart;

extern int D_01B0078C;
extern int D_01B00790;
extern int D_01B00794;
extern u8 *D_01B00798;
extern u8 *D_01B0079C;
extern int D_01B007A0;
extern int *D_01B007A4;
extern TtCfg *D_01B007A8;
extern TtHeap D_01B007B0;
extern TtPart D_01B00860[];
extern TtPart D_01B00860[];
extern void *D_01B00DE4;
extern void *D_01B00DE0;
extern char D_01B01D10[];
extern char D_01B01D68[];
void func_00107428(void *, int, int, void *);
extern int D_01B00760[];
extern float D_01B00478[];
extern double D_01B01D20;
extern char D_01B01D28[];
int func_002EFD78(void);
double func_002EBC70(double,double);
double func_002EBBB0(double,double);
void Sg_PLightAllocate(int);
void Sg_PLightDefine(int,int,int,int,int,float,float,float,float);
void func_0010DC38(void *, int);
void func_0010D720(void);
extern char D_01B01D58[];
void *func_0013B150(int);
extern int D_01B00DE8;
extern TtRing D_01B00DF0;
extern TtEnt D_01B00610[];
extern u8 D_01B00040[];
extern u8 D_01B01DD0[];
extern u8 D_01B240D0[];
extern char D_01B01D30[];
extern char D_01B01D48[];
extern char D_01B01D78[];
extern char D_01B01D80[];
extern char D_01B01DA0[];
extern char D_01B01DB0[];

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

int func_01B019A0(char *fmt, ...);
void func_01B019D0(char *fmt, ...);
int func_01B019F8(char *fmt, ...);
void func_01B01A38(int a, int b);
void func_01B01A40(TtRing *r, TtEnt *tbl, int n);
int func_01B01AF0(TtRing *r);
int func_01B01C48(TtRing *r);

int func_01B013D0(TtPart *p)
{
    float k = 0.1f;
    Sg_PLightDefine(0, 200, 128, 128, 0, 19.899818420410156f, -12.199919700622559f, 49.399810791015625f, (float)(int)(D_01B00478[D_01B00DF0.frame] * k));
    func_0010DC38(D_01B00DE0, 1);
    func_01B01A38(32, 27);
    func_01B019F8(D_01B01D28, (int)(D_01B00478[D_01B00DF0.frame] * k));
    pppSetMatrix(p);
    func_002DCE38(D_006A39B0, D_006A3970, D_006A3930);
    func_002DCE38(D_006A3AB0, D_006A3A70, D_006A39B0);
    D_006A3924 = &D_01B007B0;
    if (_pppRunPart(p, 0x30) != 0) {
        D_006A3924 = &D_01B007B0;
        _pppAllFreePObject(p);
        D_006A3924 = &D_01B007B0;
        _pppStartPart(p, 0x1000, D_01B007A8->w10[1], 1);
    }
    return 1;
}
int func_01B01568(TtPart *p)
{
    func_01B019A0(D_01B01D30, D_01B00DE8);
    func_0010D720();
    D_006A3924 = &D_01B007B0;
    _pppAllFreePObject(p);
    return 1;
}

int func_01B015C0(int a)
{
    u8 *base;
    TtCfg *c;

    func_01B019A0(D_01B01D48);
    base = D_01B240D0;
    D_01B00798 = base;
    D_01B0079C = base + 0x80000;
    D_01B007A0 = a;
    D_01B007A4 = (int *)D_01B01DD0;
    op_oef2_set2(D_01B007A4);
    func_002D02E8(D_01B007A4, 0, 1000, 0x2000);
    D_01B007A8 = (TtCfg *)op_oef2_a_get(D_01B007A4, 8, 0);
    _pppInitData(D_01B007A8, D_01B00040);
    pppInitEnv(&D_01B007B0, D_01B007A8, D_01B00798, 0x80000);
    c = D_01B007A8;
    D_01B007B0.w20 = c->w14;
    D_01B007B0.w24 = c->w18;
    D_01B007B0.w28 = c->w1c;
    func_01B01A40(&D_01B00DF0, D_01B00610, 12);
    D_01B00DE4 = func_0013B150(20);
    if (D_01B00DE4 == 0) {
        func_01B019D0(D_01B01D58);
    }
    D_01B00DE0 = func_0013B150(21);
    if (D_01B00DE0 == 0) {
        func_01B019D0(D_01B01D68);
    }
    return 1;
}

int func_01B01718(void)
{
    return 1;
}

int func_01B01720(void)
{
    return 1;
}

int func_01B01728(void)
{
    if (Sg_GetCurExecFrames() == 0) {
        return 0;
    }
    if (D_01B0078C == 0) {
        if (func_0029B830(0x2000) != 0) {
            return 1;
        }
        D_01B0078C = D_01B0078C + 1;
    }
    if (D_01B00790 == 0) {
        D_01B00790 = 1;
        MsEffectReady(D_01B007A0, 0);
    }
    if (D_01B00794 == 0) {
        if (MsEffectMotionLevel(D_01B007A0) > 0) {
            D_01B00794 = D_01B00794 + 1;
            return D_01B00794;
        }
        return 1;
    }
    return D_01B00794;
}

int func_01B017E0(void)
{
    if (D_01B00794 == 0) {
        return 0;
    }
    D_006A3924 = &D_01B007B0;
    func_001AACA0(D_006A3A70);
    func_001A9EE0(D_006A3970);
    D_006A3BCC = (int)D_01B0079C;
    if (func_0014AA50(0) != 0) {
        func_01B01A38(0x20, 0x1A);
        func_01B019F8(D_01B01D78, D_01B00DF0.frame);
        func_01B01AF0(&D_01B00DF0);
    }
    if (func_0014AA50(1) != 0) {
        func_01B01C48(&D_01B00DF0);
        func_01B019A0(D_01B01D80, D_01B00DE8);
        MsEffectTerminate(D_01B007A0);
        return 1;
    }
    D_01B00DE8 = D_01B00DE8 + 1;
    return 1;
}

int func_01B018D0(void)
{
    return 1;
}

int func_01B018D8(void)
{
    return 1;
}

float func_01B018E0(float *v)
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

int func_01B019A0(char *fmt, ...)
{
    return 0;
}

void func_01B019D0(char *fmt, ...)
{
}

int func_01B019F8(char *fmt, ...)
{
    return 0;
}

void func_01B01A28(void)
{
}

void func_01B01A30(void)
{
}

void func_01B01A38(int a, int b)
{
}

void func_01B01A40(TtRing *r, TtEnt *tbl, int n)
{
    int i;

    func_01B019A0(D_01B01DA0);
    if (n > 32) {
        func_01B019D0(D_01B01DA0);
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

int func_01B01AF0(TtRing *r)
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

int func_01B01C48(TtRing *r)
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
        func_01B019D0(D_01B01DB0);
    }
}
