/* Overlay 09528: particle scene and timed callback helpers. */

#include "common.h"
#define TT_RING_END(r, e, sl)         \
    if ((e)->on_end != 0) {           \
        (e)->on_end((e)->arg);        \
    }                                 \
    *(sl) = 0;                        \
    (r)->active = (r)->active - 1;    \
    if ((r)->active == 0) {           \
        return 0;                     \
    }



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

extern int D_01B00418;
extern int D_01B0041C;
extern int D_01B00420;
extern u8 *D_01B00424;
extern u8 *D_01B00428;
extern int D_01B0042C;
extern int *D_01B00430;
extern TtCfg *D_01B00434;
extern TtHeap D_01B00438;
extern TtPart D_01B00470;
extern int D_01B004F4;
extern TtRing D_01B004F8;
extern TtEnt D_01B00400[];
extern u8 D_01B00040[];
extern u8 D_01B00F40[];
extern u8 D_01B3A2F0[];
extern char D_01B00EC0[];
extern char D_01B00ED8[];
extern char D_01B00EE8[];
extern char D_01B00EF0[];
extern char D_01B02C20[];
extern char D_01B02C30[];

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

int func_01B01EB0(char *fmt, ...);
void func_01B01EE0(char *fmt, ...);
int func_01B01F08(char *fmt, ...);
void func_01B01F48(int a, int b);
void func_01B027D0(TtRing *r, TtEnt *tbl, int n);
int func_01B02880(TtRing *r);
int func_01B029D8(TtRing *r);


float func_01B01DF0(float *v)
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

int func_01B01EB0(char *fmt, ...)
{
    return 0;
}

void func_01B01EE0(char *fmt, ...)
{
}

int func_01B01F08(char *fmt, ...)
{
    return 0;
}

void func_01B01F38(void)
{
}

void func_01B01F40(void)
{
}

void func_01B01F48(int a, int b)
{
}
