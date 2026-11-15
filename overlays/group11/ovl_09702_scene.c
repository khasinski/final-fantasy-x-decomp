/* Overlay 09702: scene; byte-exact C. */
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

extern int D_01B00620;
extern int D_01B00624;
extern int D_01B00628;
extern u8 *D_01B0062C;
extern u8 *D_01B00630;
extern int D_01B00634;
extern int *D_01B00638;
extern TtCfg *D_01B0063C;
extern TtHeap D_01B00640;
extern TtPart D_01B00670;
extern char D_01B014A8[];
extern float D_01B01510[4];
void func_002DD0B0(void *, void *);
void func_002DD128(void *);
void func_002DCEC8(void *, void *);
void func_002DCE80(void *, void *, void *);
void func_002DD038(void *, void *, void *);
int func_002EFD78(void);
extern void *D_01B006EC;
extern char D_01B014E0[];
void *func_0013B150(int);
extern int D_01B006F0;
extern TtRing D_01B006F8;
extern TtEnt D_01B00608[];
extern u8 D_01B00040[];
extern u8 D_01B01550[];
extern u8 D_01B38840[];
extern char D_01B014C0[];
extern char D_01B014D8[];
extern char D_01B014E0[];
extern char D_01B014E8[];
extern char D_01B01520[];
extern char D_01B01530[];

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

int func_01B01110(char *fmt, ...);
void func_01B01140(char *fmt, ...);
int func_01B01168(char *fmt, ...);
void func_01B011A8(int a, int b);
void func_01B011C8(TtRing *r, TtEnt *tbl, int n);
int func_01B01278(TtRing *r);
int func_01B013D0(TtRing *r);

int func_01B00810(TtPart *p)
{
    func_01B01110(D_01B014A8, D_01B006F0);
    D_006A3924 = &D_01B00640;
    _pppStartPart(p, 0x1000, *D_01B0063C->w10, 1);
    p->f40 = 0.0f;
    p->f44 = -2.0f;
    p->f48 = -30.59998893737793f;
    p->f4C = 1.0f;
    p->w50 = 0;
    p->w54 = 0;
    p->w58 = 0;
    p->w5C = 1;
    p->f60 = 0.208064004778862f;
    p->f64 = 0.208064004778862f;
    p->f68 = 0.208064004778862f;
    p->f6C = 1.0f;
    return 1;
}

int func_01B008D8(TtPart *p)
{
    pppSetMatrix(p);
    func_002DCE38(D_006A39B0, D_006A3970, D_006A3930);
    func_002DCE38(D_006A3AB0, D_006A3A70, D_006A39B0);
    D_006A3924 = &D_01B00640;
    return _pppRunPart(p, 0x30) == 0;
}

int func_01B00960(TtPart *p)
{
    func_01B01110(D_01B014C0, D_01B006F0);
    D_006A3924 = &D_01B00640;
    _pppAllFreePObject(p);
    return 1;
}

int func_01B009B0(int a)
{
    u8 *base;
    TtCfg *c;

    func_01B01110(D_01B014D8);
    base = D_01B38840;
    D_01B0062C = base;
    D_01B00630 = base + 0x80000;
    D_01B00634 = a;
    D_01B00638 = (int *)D_01B01550;
    op_oef2_set2(D_01B00638);
    func_002D02E8(D_01B00638, 0, 1000, 0x2000);
    D_01B0063C = (TtCfg *)op_oef2_a_get(D_01B00638, 8, 0);
    _pppInitData(D_01B0063C, D_01B00040);
    pppInitEnv(&D_01B00640, D_01B0063C, D_01B0062C, 0x80000);
    c = D_01B0063C;
    D_01B00640.w20 = c->w14;
    D_01B00640.w24 = c->w18;
    D_01B00640.w28 = c->w1c;
    func_01B011C8(&D_01B006F8, D_01B00608, 1);
    return 1;
}

int func_01B00AC8(void)
{
    return 1;
}

int func_01B00AD0(void)
{
    return 1;
}

int func_01B00AD8(void)
{
    if (Sg_GetCurExecFrames() == 0) {
        return 0;
    }
    if (D_01B00620 == 0) {
        if (func_0029B830(0x2000) != 0) {
            return 1;
        }
        D_01B00620 = D_01B00620 + 1;
    }
    if (D_01B00624 == 0) {
        D_01B00624 = 1;
        MsEffectReady(D_01B00634, 0);
    }
    if (D_01B00628 == 0) {
        if (MsEffectMotionLevel(D_01B00634) > 0) {
            D_01B00628 = D_01B00628 + 1;
            return D_01B00628;
        }
        return 1;
    }
    return D_01B00628;
}

int func_01B00B90(void)
{
    if (D_01B00628 == 0) return 0;
    D_006A3924 = &D_01B00640;
    func_001AACA0(D_006A3A70);
    func_001A9EE0(D_006A3970);
    D_006A3BCC = (int)D_01B00630;
    if (func_0014AA50(0) != 0) {
        func_01B01278(&D_01B006F8);
    }
    if (func_0014AA50(1) != 0) {
        func_01B013D0(&D_01B006F8);
        func_01B01110(D_01B014E8, D_01B006F0);
        MsEffectTerminate(D_01B00634);
        return 1;
    }
    D_01B006F0 = D_01B006F0 + 1;
    return 1;
}

int func_01B00C58(void)
{
    return 1;
}

int func_01B00C60(void)
{
    return 1;
}

void func_01B00C68(float *m)
{
    func_002DCEC8(m, m);
    func_002DCEC8(m + 4, m + 4);
    func_002DCEC8(m + 8, m + 8);
}

void func_001072F8(void *, int, void *);
void func_01B00CA8(void *chr, int bone, float *m)
{
    func_001072F8(chr, bone, m);
    func_01B00C68(m);
}
