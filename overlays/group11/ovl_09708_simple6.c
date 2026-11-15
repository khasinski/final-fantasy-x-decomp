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

extern TtHeap D_01B00678;
extern char D_01B027D8[];
void func_001089A8(void *, void *);
void *func_0013B150(int);
extern int D_01B00C30;
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
int func_01B02430(char *fmt, ...);
extern char D_01B02808[];
extern char D_01B02838[];
extern char D_01B02868[];
extern char D_01B02890[];
extern char D_01B028B8[];
extern int D_01B00654;
extern int D_01B00658;
extern int D_01B0065C;
extern int D_01B00668;
void func_002DD0B0(void *, void *);
void func_002DD128(void *);
void func_002DCEC8(void *, void *);
void func_002DCE80(void *, void *, void *);
void func_002DD038(void *, void *, void *);
int func_002EFD78(void);
void func_0010D720(void);
int func_00117F58(int,int,int,int);

int func_01B01DC8(void)
{
    return 1;
}

int func_01B01DD0(void)
{
    if (Sg_GetCurExecFrames() == 0) {
        return 0;
    }
    if (D_01B00654 == 0) {
        if (func_0029B830(0x2000) != 0) {
            return 1;
        }
        D_01B00654 = D_01B00654 + 1;
    }
    if (D_01B00658 == 0) {
        D_01B00658 = 1;
        MsEffectReady(D_01B00668, 0);
    }
    if (D_01B0065C == 0) {
        if (MsEffectMotionLevel(D_01B00668) > 0) {
            D_01B0065C = D_01B0065C + 1;
            return D_01B0065C;
        }
        return 1;
    }
    return D_01B0065C;
}
