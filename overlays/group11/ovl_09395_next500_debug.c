/* Overlay 09395: ring helpers; ee-gcc 2.96 with period assembler. */
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

void func_002DD0B0(void *, void *);
void func_002DD128(void *);
void func_002DCEC8(void *, void *);
void func_002DCE80(void *, void *, void *);
void func_002DD038(void *, void *, void *);
int func_002EFD78(void);
int Sg_GetCurExecFrames(void);
void *func_002EF0D0(void *, int, int);
double func_002ED038(float);
double func_002E9290(double);
float func_002EC440(double);
extern float D_01B059A0[4];
extern float D_01B059B0[4];
typedef union TtVec { float v[4]; double d[2]; } TtVec;

void func_001072F8(void *, int, float *);
int func_01B03C10(char *fmt, ...)
{
    return 0;
}

void func_01B03C60(char *fmt, ...)
{
}

int func_01B03CA8(char *fmt, ...)
{
    return 0;
}

void func_01B03CF8(void)
{
}

void func_01B03D00(void)
{
}

void func_01B03D08(int a, int b)
{
}

void func_01B03D10(void)
{
}

void func_01B03D18(void) {}
void func_01B03D20(void) {}
