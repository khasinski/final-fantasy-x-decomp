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

extern TtHeap D_01B003E0;
void func_001089A8(void *, void *);
void *func_0013B150(int);
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
extern char D_01B02300[];
extern int D_01B00490;
int func_01B010B8(char *fmt, ...);
extern int D_01B003BC;
extern int D_01B003C0;
extern int D_01B003C4;
extern int D_01B003D0;
void func_002DD0B0(void *, void *);
void func_002DD128(void *);
void func_002DCEC8(void *, void *);
void func_002DCE80(void *, void *, void *);
void func_002DD038(void *, void *, void *);
int func_002EFD78(void);
void func_0010D720(void);
int func_00117F58(int,int,int,int);

int func_01B00AE0(void)
{
    return 1;
}

int func_01B00AE8(void)
{
    if (Sg_GetCurExecFrames() == 0) {
        return 0;
    }
    if (D_01B003BC == 0) {
        if (func_0029B830(0x2000) != 0) {
            return 1;
        }
        D_01B003BC = D_01B003BC + 1;
    }
    if (D_01B003C0 == 0) {
        D_01B003C0 = 1;
        MsEffectReady(D_01B003D0, 0);
    }
    if (D_01B003C4 == 0) {
        if (MsEffectMotionLevel(D_01B003D0) > 0) {
            D_01B003C4 = D_01B003C4 + 1;
            return D_01B003C4;
        }
        return 1;
    }
    return D_01B003C4;
}
