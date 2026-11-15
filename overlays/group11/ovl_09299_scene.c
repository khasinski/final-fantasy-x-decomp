/* Overlay 09299: scene lifecycle. */
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

extern int D_01B00728;
extern int D_01B0072C;
extern int D_01B00730;
extern u8 *D_01B00734;
extern u8 *D_01B00738;
extern int D_01B0073C;
extern int *D_01B00740;
extern TtCfg *D_01B00744;
extern TtHeap D_01B00748;
extern void *D_01B00904;
extern char D_01B01B08[];
extern char D_01B014E0[];
void *func_0013B150(int);
extern int D_01B00900;
extern TtRing D_01B00908;
extern TtEnt D_01B006F8[];
extern u8 D_01B00040[];
extern u8 D_01B01B80[];
extern u8 D_01B5D360[];
extern char D_01B01AF8[];
extern char D_01B014E0[];
extern char D_01B01B18[];

extern void *D_006A3924;
extern u8 D_006A3970[];
extern u8 D_006A3A70[];
extern int D_006A3BCC;

void _pppInitData(void *a, void *b);
void pppInitEnv(void *heap, void *cfg, void *base, int size);
void op_oef2_set2(void *tbl);
void func_002D02E8(void *a, int b, int c, int d);
int *op_oef2_a_get(void *tbl, int a, int b);
int Sg_GetCurExecFrames(void);
int func_0029B830(int a);
int MsEffectReady(int id, int flag);
int MsEffectMotionLevel(int id);
void MsEffectTerminate(int id);
void func_001AACA0(void *m);
void func_001A9EE0(void *m);
int func_0014AA50(int a);

int func_01B016D8(char *fmt, ...);
void func_01B01708(char *fmt, ...);
void func_01B01790(TtRing *r, TtEnt *tbl, int n);
int func_01B01840(TtRing *r);
int func_01B01998(TtRing *r);

int func_01B00F58(int a)
{
    u8 *base;
    TtCfg *c;

    func_01B016D8(D_01B01AF8);
    base = D_01B5D360;
    D_01B00734 = base;
    D_01B00738 = base + 0x80000;
    D_01B0073C = a;
    D_01B00740 = (int *)D_01B01B80;
    op_oef2_set2(D_01B00740);
    func_002D02E8(D_01B00740, 0, 1000, 0x2000);
    D_01B00744 = (TtCfg *)op_oef2_a_get(D_01B00740, 8, 0);
    _pppInitData(D_01B00744, D_01B00040);
    pppInitEnv(&D_01B00748, D_01B00744, D_01B00734, 0x80000);
    c = D_01B00744;
    D_01B00748.w20 = c->w14;
    D_01B00748.w24 = c->w18;
    D_01B00748.w28 = c->w1c;
    func_01B01790(&D_01B00908, D_01B006F8, 2);
    D_01B00904 = func_0013B150(23);
    if (D_01B00904 == 0) {
        func_01B01708(D_01B01B08);
    }
    return 1;
}

int func_01B01090(void)
{
    return 1;
}

int func_01B01098(void)
{
    return 1;
}

int func_01B010A0(void)
{
    if (Sg_GetCurExecFrames() == 0) {
        return 0;
    }
    if (D_01B00728 == 0) {
        if (func_0029B830(0x2000) != 0) {
            return 1;
        }
        D_01B00728 = D_01B00728 + 1;
    }
    if (D_01B0072C == 0) {
        D_01B0072C = 1;
        MsEffectReady(D_01B0073C, 0);
    }
    if (D_01B00730 == 0) {
        if (MsEffectMotionLevel(D_01B0073C) > 0) {
            D_01B00730 = D_01B00730 + 1;
            return D_01B00730;
        }
        return 1;
    }
    return D_01B00730;
}

int func_01B01158(void)
{
    if (D_01B00730 == 0) return 0;
    D_006A3924 = &D_01B00748;
    func_001AACA0(D_006A3A70);
    func_001A9EE0(D_006A3970);
    D_006A3BCC = (int)D_01B00738;
    if (func_0014AA50(0) != 0) {
        func_01B01840(&D_01B00908);
    }
    if (func_0014AA50(1) != 0) {
        func_01B01998(&D_01B00908);
        func_01B016D8(D_01B01B18, D_01B00900);
        MsEffectTerminate(D_01B0073C);
        return 1;
    }
    D_01B00900 = D_01B00900 + 1;
    return 1;
}

int func_01B01220(void)
{
    return 1;
}

int func_01B01228(void)
{
    return 1;
}
