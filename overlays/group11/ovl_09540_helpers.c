/* Overlay 09540: vector normalization and timed callback queue. */
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
extern char D_01B034B0[];
extern char D_01B034C0[];

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

int func_01B02FE0(char *fmt, ...);
void func_01B03010(char *fmt, ...);
int func_01B03038(char *fmt, ...);
void func_01B03078(int a, int b);
void func_01B03080(TtRing *r, TtEnt *tbl, int n);
int func_01B03130(TtRing *r);
int func_01B03288(TtRing *r);

float func_01B02F20(float *v)
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

int func_01B02FE0(char *fmt, ...)
{
    return 0;
}

void func_01B03010(char *fmt, ...)
{
}

int func_01B03038(char *fmt, ...)
{
    return 0;
}

void func_01B03068(void)
{
}

void func_01B03070(void)
{
}

void func_01B03078(int a, int b)
{
}

void func_01B03080(TtRing *r, TtEnt *tbl, int n)
{
    int i;

    func_01B02FE0(D_01B034B0);
    if (n > 32) {
        func_01B03010(D_01B034B0);
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

int func_01B03130(TtRing *r)
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

int func_01B03288(TtRing *r)
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
        func_01B03010(D_01B034C0);
    }
}
