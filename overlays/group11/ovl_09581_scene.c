/* EE Battle-Effect Overlay: group 0x11, file 09337
 * Load base: 0x01B00000, .text: 0x01B00618..0x01B00EB4
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

extern int D_01B00520;
extern int D_01B00524;
extern int D_01B00528;
extern u8 *D_01B0052C;
extern u8 *D_01B00530;
extern int D_01B00534;
extern int *D_01B00538;
extern TtCfg *D_01B0053C;
extern TtHeap D_01B00540;
extern TtPart D_01B00470;
extern int D_01B004F4;
extern TtRing D_01B00698;
extern TtEnt D_01B004D0[];
extern u8 D_01B00040[];
extern u8 D_01B01390[];
extern u8 D_01B2D720[];
extern char D_01B00EC0[];
extern char D_01B01328[];
extern char D_01B00EE8[];
extern char D_01B00EF0[];
extern char D_01B00F10[];
extern char D_01B00F20[];

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

int func_01B00F88(char *fmt, ...);
void func_01B00B80(char *fmt, ...);
int func_01B00BA8(char *fmt, ...);
void func_01B00BE8(int a, int b);
void func_01B01028(TtRing *r, TtEnt *tbl, int n);
int func_01B00CA0(TtRing *r);
int func_01B00DF8(TtRing *r);

void func_01B007B8(void);

int func_01B00BD8(int a)
{
    u8 *base;
    TtCfg *c;

    func_01B007B8();
    func_01B00F88(D_01B01328);
    base = D_01B2D720;
    D_01B0052C = base;
    D_01B00530 = base + 0x80000;
    D_01B00534 = a;
    D_01B00538 = (int *)D_01B01390;
    op_oef2_set2(D_01B00538);
    func_002D02E8(D_01B00538, 0, 1000, 0x2000);
    D_01B0053C = (TtCfg *)op_oef2_a_get(D_01B00538, 8, 0);
    _pppInitData(D_01B0053C, D_01B00040);
    pppInitEnv(&D_01B00540, D_01B0053C, D_01B0052C, 0x80000);
    c = D_01B0053C;
    D_01B00540.w20 = c->w14;
    D_01B00540.w24 = c->w18;
    D_01B00540.w28 = c->w1c;
    func_01B01028(&D_01B00698, D_01B004D0, 2);
    return 1;
}

int func_01B00CF0(void)
{
    return 1;
}

int func_01B00CF8(void)
{
    return 1;
}

int func_01B00D00(void)
{
    if (Sg_GetCurExecFrames() == 0) {
        return 0;
    }
    if (D_01B00520 == 0) {
        if (func_0029B830(0x2000) != 0) {
            return 1;
        }
        D_01B00520 = D_01B00520 + 1;
    }
    if (D_01B00524 == 0) {
        D_01B00524 = 1;
        MsEffectReady(D_01B00534, 0);
    }
    if (D_01B00528 == 0) {
        if (MsEffectMotionLevel(D_01B00534) > 0) {
            D_01B00528 = D_01B00528 + 1;
            return D_01B00528;
        }
        return 1;
    }
    return D_01B00528;
}
