/* EE battle-effect overlay 09661: byte-exact C.
 * .text 0x01B008A0..0x01B00BB4.
 * Shared vector/matrix, particle scene, and timed callback helpers.
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

extern u8 *D_01B005BC;
extern u8 *D_01B005C0;
extern int D_01B005C4;
extern int *D_01B005C8;
extern TtCfg *D_01B005CC;
extern TtHeap D_01B005D0;
extern char D_01B01548[];
extern void *D_01B00780;
extern char D_01B01580[];
void *func_0013B150(int);
extern int D_01B00784;
extern TtRing D_01B00788;
extern TtEnt D_01B00568[];
extern u8 D_01B00040[];
extern u8 D_01B01600[];
extern u8 D_01B30F20[];
extern char D_01B01558[];
extern char D_01B01570[];

extern void *D_006A3924;
extern u8 D_006A3930[];
extern u8 D_006A3970[];
extern u8 D_006A39B0[];
extern u8 D_006A3A70[];
extern u8 D_006A3AB0[];

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
int MsEffectReady(int id, int flag);
int MsEffectMotionLevel(int id);
void MsEffectTerminate(int id);

int func_01B011C0(char *fmt, ...);
void func_01B011F0(char *fmt, ...);
void func_01B01268(TtRing *r, TtEnt *tbl, int n);

int func_01B008A0(TtPart *p)
{
    func_01B011C0(D_01B01548, D_01B00784);
    D_006A3924 = &D_01B005D0;
    _pppStartPart(p, 0x1000, *D_01B005CC->w10, 1);
    p->f40 = 0.0f;
    p->f44 = 9.999999974752427e-07f;
    p->f48 = 9.799854278564453f;
    p->f4C = 1.0f;
    p->w50 = 0;
    p->w54 = 0;
    p->w58 = 0;
    p->w5C = 1;
    p->f60 = 0.09459800273180008f;
    p->f64 = 0.09459800273180008f;
    p->f68 = 0.09459800273180008f;
    p->f6C = 1.0f;
}

int func_01B00968(TtPart *p)
{
    pppSetMatrix(p);
    func_002DCE38(D_006A39B0, D_006A3970, D_006A3930);
    func_002DCE38(D_006A3AB0, D_006A3A70, D_006A39B0);
    D_006A3924 = &D_01B005D0;
    if (_pppRunPart(p, 0x30) != 0) {
        D_006A3924 = &D_01B005D0;
        _pppAllFreePObject(p);
        D_006A3924 = &D_01B005D0;
        _pppStartPart(p, 0x1000, *D_01B005CC->w10, 1);
    }
    return 1;
}

int func_01B00A30(TtPart *p)
{
    func_01B011C0(D_01B01558, D_01B00784);
    D_006A3924 = &D_01B005D0;
    _pppAllFreePObject(p);
    return 1;
}

int func_01B00A80(int a)
{
    u8 *base;
    TtCfg *c;

    func_01B011C0(D_01B01570);
    base = D_01B30F20;
    D_01B005BC = base;
    D_01B005C0 = base + 0x80000;
    D_01B005C4 = a;
    D_01B005C8 = (int *)D_01B01600;
    op_oef2_set2(D_01B005C8);
    func_002D02E8(D_01B005C8, 0, 1000, 0x2000);
    D_01B005CC = (TtCfg *)op_oef2_a_get(D_01B005C8, 8, 0);
    _pppInitData(D_01B005CC, D_01B00040);
    pppInitEnv(&D_01B005D0, D_01B005CC, D_01B005BC, 0x80000);
    c = D_01B005CC;
    D_01B005D0.w20 = c->w14;
    D_01B005D0.w24 = c->w18;
    D_01B005D0.w28 = c->w1c;
    func_01B01268(&D_01B00788, D_01B00568, 3);
    D_01B00780 = func_0013B150(5);
    if (D_01B00780 == 0) {
        func_01B011F0(D_01B01580);
    }
    return 1;
}
