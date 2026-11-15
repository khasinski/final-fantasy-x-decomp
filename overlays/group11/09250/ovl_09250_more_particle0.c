/* Overlay 9250: particle and scene helpers. */
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

extern int D_01B00480;
extern int D_01B00484;
extern int D_01B00488;
extern u8 *D_01B0048C;
extern u8 *D_01B00490;
extern int D_01B00494;
extern int *D_01B00498;
extern TtCfg *D_01B0049C;
extern TtHeap D_01B00560;
extern TtPart D_01B004D0;
extern TtPart D_01B00550;
extern void *D_01B005D0;
extern void *D_01B005D4;
extern char D_01B01158[];
extern char D_01B011A8[];
void func_001089A8(void *, void *);
extern char D_01B01198[];
void *func_0013B150(int);
extern int D_01B005D8;
extern TtRing D_01B005E0;
extern TtEnt D_01B00450[];
extern u8 D_01B00040[];
extern u8 D_01B01210[];
extern u8 D_01B3D390[];
extern char D_01B01170[];
extern char D_01B01188[];
extern char D_01B011B8[];
extern char D_01B011C0[];
extern char D_01B011E0[];
extern char D_01B011F0[];

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

int func_01B00DE8(char *fmt, ...);
void func_01B00E18(char *fmt, ...);
int func_01B00E40(char *fmt, ...);
void func_01B00E80(int a, int b);
void func_01B00E88(TtRing *r, TtEnt *tbl, int n);
int func_01B00F38(TtRing *r);
int func_01B01090(TtRing *r);


extern int D_01B00850;
extern char D_01B02AC0[],D_01B02AE8[],D_01B02B18[];
int func_01B01E48(char *,...);

int func_01B011C8(TtPart *p)
{
    pppSetMatrix(p);
    func_002DCE38(D_006A39B0, D_006A3970, D_006A3930);
    func_002DCE38(D_006A3AB0, D_006A3A70, D_006A39B0);
    D_006A3924 = &D_01B00560;
    return _pppRunPart(p, 0x30) == 0;
}

int func_01B01250(TtPart *p)
{
    func_01B01E48(D_01B02AC0, D_01B00850);
    D_006A3924 = &D_01B00560;
    _pppAllFreePObject(p);
    return 1;
}
