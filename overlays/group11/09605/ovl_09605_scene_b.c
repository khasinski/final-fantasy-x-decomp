/* EE battle-effect overlay 09605: byte-exact C.
 * .text 0x01B00A78..0x01B00C38.
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

extern int D_01B00478;
extern int D_01B0047C;
extern int D_01B00480;
extern u8 *D_01B00488;
extern int D_01B0048C;
extern TtHeap D_01B00498;
extern int D_01B005D4;
extern TtRing D_01B005D8;
extern char D_01B01448[];
extern char D_01B01458[];

extern void *D_006A3924;
extern u8 D_006A3970[];
extern u8 D_006A3A70[];
extern int D_006A3BCC;

void _pppStartPart(void *part, int a, int b, int c);
void pppSetMatrix(void *part);
int _pppRunPart(void *part, int n);
void _pppAllFreePObject(void *part);
void _pppInitData(void *a, void *b);
void pppInitEnv(void *heap, void *cfg, void *base, int size);
void op_oef2_set2(void *tbl);
int *op_oef2_a_get(void *tbl, int a, int b);
int Sg_GetCurExecFrames(void);
int func_0029B830(int a);
int MsEffectReady(int id, int flag);
int MsEffectMotionLevel(int id);
void MsEffectTerminate(int id);
void func_001AACA0(void *m);
void func_001A9EE0(void *m);
int func_0014AA50(int a);

int func_01B01078(char *fmt, ...);
int func_01B010D0(char *fmt, ...);
void func_01B01110(int a, int b);
int func_01B011D0(TtRing *r);
int func_01B01328(TtRing *r);

int func_01B00A78(void)
{
    return 1;
}

int func_01B00A80(void)
{
    if (Sg_GetCurExecFrames() == 0) {
        return 0;
    }
    if (D_01B00478 == 0) {
        if (func_0029B830(0x2000) != 0) {
            return 1;
        }
        D_01B00478 = D_01B00478 + 1;
    }
    if (D_01B0047C == 0) {
        D_01B0047C = 1;
        MsEffectReady(D_01B0048C, 0);
    }
    if (D_01B00480 == 0) {
        if (MsEffectMotionLevel(D_01B0048C) > 0) {
            D_01B00480 = D_01B00480 + 1;
            return D_01B00480;
        }
        return 1;
    }
    return D_01B00480;
}

int func_01B00B38(void)
{
    if (D_01B00480 == 0) {
        return 0;
    }
    D_006A3924 = &D_01B00498;
    func_001AACA0(D_006A3A70);
    func_001A9EE0(D_006A3970);
    D_006A3BCC = (int)D_01B00488;
    if (func_0014AA50(0) != 0) {
        func_01B01110(0x20, 0x1A);
        func_01B010D0(D_01B01448, D_01B005D8.frame);
        func_01B011D0(&D_01B005D8);
    }
    if (func_0014AA50(1) != 0) {
        func_01B01328(&D_01B005D8);
        func_01B01078(D_01B01458, D_01B005D4);
        MsEffectTerminate(D_01B0048C);
        return 1;
    }
    D_01B005D4 = D_01B005D4 + 1;
    return 1;
}

int func_01B00C28(void)
{
    return 1;
}

int func_01B00C30(void)
{
    return 1;
}
