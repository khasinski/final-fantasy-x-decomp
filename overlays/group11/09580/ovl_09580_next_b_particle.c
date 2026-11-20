/* Battle-effect overlay 09580: byte-exact C helpers and callbacks. */
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

extern u8 D_01B00040[];
extern TtEnt D_01B004F0[];
extern u8 *D_01B005A4;
extern u8 *D_01B005A8;
extern int D_01B005AC;
extern void *D_01B005B0;
extern TtHeap D_01B005B8;
extern TtCfg *D_01B005E4;
extern void *D_01B008F0;
extern int D_01B008F4;
extern TtRing D_01B008F8;
extern float D_01B00A08;
extern char D_01B018F8[];
extern char D_01B01910[];
extern char D_01B01928[];
extern char D_01B01940[];
extern char D_01B01958[];
extern char D_01B01968[];
extern u8 D_01B019E0[];
extern u8 D_01B2EF90[];

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
int func_002EFD78(void);
void func_00107428(void *, int, int, void *);
void func_00110540(void *, int, float);
void func_0010C790(void *, int);
void func_00103788(int);
void func_002B2730(int);
void *func_0013B150(int);

int func_01B01570(char *fmt, ...);
void func_01B015A0(char *fmt, ...);
void func_01B01618(TtRing *r, TtEnt *tbl, int n);

int func_01B00A18(void)
{
    return 1;
}

void func_01B00A20(TtPart *p)
{
    int r;
    float s;
    func_01B01570(D_01B018F8, D_01B008F4);
    D_006A3924 = &D_01B005B8;
    _pppStartPart(p, 0x1000, D_01B005E4->w10[1], 1);
    r = func_002EFD78() % 0xB8;
    func_00107428(D_01B008F0, r, 0, &p->f40);
    p->w50 = 0;
    p->w54 = 0;
    p->w58 = 0;
    p->w5C = 1;
    s = ((float)(func_002EFD78() & 0x7FFF) / 32767.0f) * 0.039f + 0.091f;
    p->f60 = s;
    p->f64 = s;
    p->f68 = s;
    p->f6C = 1.0f;
}

int func_01B00B28(TtPart *p)
{
    pppSetMatrix(p);
    func_002DCE38(D_006A39B0, D_006A3970, D_006A3930);
    func_002DCE38(D_006A3AB0, D_006A3A70, D_006A39B0);
    D_006A3924 = &D_01B005B8;
    return _pppRunPart(p, 0x30) == 0;
}

int func_01B00BB0(TtPart *p)
{
    func_01B01570(D_01B01910, D_01B008F4);
    D_006A3924 = &D_01B005B8;
    _pppAllFreePObject(p);
    return 1;
}

int func_01B00C00(void)
{
    D_01B00A08 = 0.0f;
    return 1;
}

int func_01B00C10(void)
{
    D_01B00A08 += 1.0f / 120.0f;
    if (D_01B00A08 >= 1.0f) {
        D_01B00A08 = 1.0f;
    }
    func_00110540(D_01B008F0, 0, D_01B00A08);
    return 1;
}

void func_01B00C70(TtPart *p)
{
    func_01B01570(D_01B01928, D_01B008F4);
    D_006A3924 = &D_01B005B8;
    _pppStartPart(p, 0x1000, D_01B005E4->w10[0], 1);
    p->f40 = -105.355476f;
    p->f44 = -24.529911f;
    p->f48 = 90.249176f;
    p->f4C = 1.0f;
    p->w50 = 0;
    p->w54 = 0;
    p->w58 = 0;
    p->w5C = 1;
    p->f60 = 0.15f;
    p->f64 = 0.15f;
    p->f68 = 0.15f;
    p->f6C = 1.0f;
    func_0010C790(D_01B008F0, 1);
}

int func_01B00D50(TtPart *p)
{
    func_00103788(1);
    func_002B2730(0);
    pppSetMatrix(p);
    func_002DCE38(D_006A39B0, D_006A3970, D_006A3930);
    func_002DCE38(D_006A3AB0, D_006A3A70, D_006A39B0);
    D_006A3924 = &D_01B005B8;
    return _pppRunPart(p, 0x30) == 0;
}

int func_01B00DE8(TtPart *p)
{
    func_01B01570(D_01B01940, D_01B008F4);
    func_0010C790(D_01B008F0, 0);
    D_006A3924 = &D_01B005B8;
    _pppAllFreePObject(p);
    return 1;
}

int func_01B00E48(int a0)
{
    func_01B01570(D_01B01958);
    D_01B005A4 = D_01B2EF90;
    D_01B005A8 = D_01B005A4 + 0x100000;
    D_01B005AC = a0;
    D_01B005B0 = D_01B019E0;
    op_oef2_set2(D_01B019E0);
    func_002D02E8(D_01B005B0, 0, 0x3E8, 0x2000);
    D_01B005E4 = (TtCfg *)op_oef2_a_get(D_01B005B0, 8, 0);
    _pppInitData(D_01B005E4, D_01B00040);
    pppInitEnv(&D_01B005B8, D_01B005E4, D_01B005A4, 0x100000);
    D_01B005B8.w20 = D_01B005E4->w14;
    D_01B005B8.w24 = D_01B005E4->w18;
    D_01B005B8.w28 = D_01B005E4->w1c;
    func_01B01618(&D_01B008F8, D_01B004F0, 7);
    D_01B008F0 = func_0013B150(0x14);
    if (D_01B008F0 == 0) {
        func_01B015A0(D_01B01968);
    }
    func_00110540(D_01B008F0, 0, 0.0f);
    return 1;
}
