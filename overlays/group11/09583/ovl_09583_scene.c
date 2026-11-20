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

extern int D_01B00BA0;
extern int D_01B00BA4;
extern int D_01B00BA8;
extern u8 *D_01B00BAC;
extern u8 *D_01B00BB0;
extern int D_01B00BB4;
extern int *D_01B00BB8;
extern TtCfg *D_01B00BBC;
extern TtHeap D_01B00BC8;
extern TtPart D_01B00470;
extern int D_01B004F4;
extern TtRing D_01B00D88;
extern TtEnt D_01B00B58[];
extern u8 D_01B00040[];
extern u8 D_01B01BF0[];
extern u8 D_01BAC320[];
extern char D_01B00EC0[];
extern char D_01B01B88[];
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

int func_01B017B8(char *fmt, ...);
void func_01B00B80(char *fmt, ...);
int func_01B00BA8(char *fmt, ...);
void func_01B00BE8(int a, int b);
void func_01B01858(TtRing *r, TtEnt *tbl, int n);
int func_01B00CA0(TtRing *r);
int func_01B00DF8(TtRing *r);

extern TtRing D_01B00E98;
extern TtEnt D_01B00B88[];

int func_01B013B0(int a)
{
    u8 *base;
    TtCfg *c;

    func_01B017B8(D_01B01B88);
    base = D_01BAC320;
    D_01B00BAC = base;
    D_01B00BB0 = base + 0x80000;
    D_01B00BB4 = a;
    D_01B00BB8 = (int *)D_01B01BF0;
    op_oef2_set2(D_01B00BB8);
    func_002D02E8(D_01B00BB8, 0, 1000, 0x2000);
    D_01B00BBC = (TtCfg *)op_oef2_a_get(D_01B00BB8, 8, 0);
    _pppInitData(D_01B00BBC, D_01B00040);
    pppInitEnv(&D_01B00BC8, D_01B00BBC, D_01B00BAC, 0x80000);
    c = D_01B00BBC;
    D_01B00BC8.w20 = c->w14;
    D_01B00BC8.w24 = c->w18;
    D_01B00BC8.w28 = c->w1c;
    func_01B01858(&D_01B00D88, D_01B00B58, 2);
    func_01B01858(&D_01B00E98, D_01B00B88, 1);
    return 1;
}

int func_01B014E0(void)
{
    return 1;
}

int func_01B014E8(void)
{
    return 1;
}

int func_01B014F0(void)
{
    if (Sg_GetCurExecFrames() == 0) {
        return 0;
    }
    if (D_01B00BA0 == 0) {
        if (func_0029B830(0x2000) != 0) {
            return 1;
        }
        D_01B00BA0 = D_01B00BA0 + 1;
    }
    if (D_01B00BA4 == 0) {
        D_01B00BA4 = 1;
        MsEffectReady(D_01B00BB4, 0);
    }
    if (D_01B00BA8 == 0) {
        if (MsEffectMotionLevel(D_01B00BB4) > 0) {
            D_01B00BA8 = D_01B00BA8 + 1;
            return D_01B00BA8;
        }
        return 1;
    }
    return D_01B00BA8;
}

extern int D_01B00D84;
extern char D_01B01B98[];
extern char D_01B01BA0[];
int func_01B01810(char *fmt, ...);
void func_01B01850(int, int);
int func_01B01908(TtRing *r);
int func_01B01A60(TtRing *r);

int func_01B015A8(void)
{
    if (D_01B00BA8 == 0) {
        return 0;
    }
    D_006A3924 = &D_01B00BC8;
    func_001AACA0(D_006A3A70);
    func_001A9EE0(D_006A3970);
    D_006A3BCC = (int)D_01B00BB0;
    if (func_0014AA50(0) != 0) {
        func_01B01850(0x20, 0x1A);
        func_01B01850(0x20, 0);
        func_01B01810(D_01B01B98, D_01B00D88.frame);
        func_01B01908(&D_01B00D88);
    }
    if (func_0014AA50(1) != 0) {
        func_01B01850(0x20, 1);
        func_01B01810(D_01B01B98, D_01B00E98.frame);
        func_01B01908(&D_01B00E98);
    }
    if (func_0014AA50(2) != 0) {
        func_01B01A60(&D_01B00D88);
        func_01B01A60(&D_01B00E98);
        func_01B017B8(D_01B01BA0, D_01B00D84);
        MsEffectTerminate(D_01B00BB4);
        return 1;
    }
    D_01B00D84++;
    return 1;
}
