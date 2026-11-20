/* Overlay 09528: particle scene and timed callback helpers. */
#include "common.h"
extern char D_01B016F0[];
extern char D_01B01708[];

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

extern int D_01B0048C;
extern int D_01B00490;
extern int D_01B00494;
extern u8 *D_01B00498;
extern u8 *D_01B0049C;
extern int D_01B004A0;
extern int *D_01B004A4;
extern TtCfg *D_01B004A8;
extern TtHeap D_01B004B0;
extern TtPart D_01B006C0;
extern char D_01B016C0[];
extern float D_01B01760[4];
void func_002DD0B0(void *, void *);
void func_002DD128(void *);
void func_002DCEC8(void *, void *);
void func_002DCE80(void *, void *, void *);
void func_002DD038(void *, void *, void *);
int func_002EFD78(void);
extern void *D_01B005E0;
extern char D_01B01410[];
void *func_0013B150(int);
extern int D_01B005E4;
extern TtRing D_01B005E8;
extern TtEnt D_01B00450[];
extern u8 D_01B00040[];
extern u8 D_01B01490[];
extern u8 D_01B11610[];
extern char D_01B016D8[];
extern char D_01B01400[];
extern char D_01B01730[];
extern char D_01B01740[];
extern char D_01B01770[];
extern char D_01B01780[];

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

int func_01B01020(char *fmt, ...);
void func_01B01050(char *fmt, ...);
int func_01B01078(char *fmt, ...);
void func_01B010B8(int a, int b);
void func_01B010C0(TtRing *r, TtEnt *tbl, int n);
int func_01B01170(TtRing *r);
int func_01B012C8(TtRing *r);


extern int D_01B00488;
extern float D_01B00480;
extern float D_01B00484;
extern float D_01B00700[4];
extern char D_01B01390[], D_01B013A8[], D_01B013B8[], D_01B013D0[], D_01B013E8[], D_01B01418[], D_01B01428[], D_01B01438[];
void func_0010D720(void);
void Sg_PLightAllocate(int);
void Sg_PLightDefine(int, int, int, int, int, float, float, float, float);
void func_0010DC38(void *, int);
void func_00107428(void *, int, void *, void *);
void func_002DD0B0(void *, void *);
int func_00117F58(int,int,int,int);

int func_01B00718(void)
{
    return 1;
}

void func_01B00720(TtPart *p)
{
    func_01B01020(D_01B01390, D_01B005E4);
    D_006A3924 = &D_01B004B0;
    _pppStartPart(p, 0x1000, D_01B004A8->w10[0], 1);
    p->f40 = 0.0f;
    p->f44 = 0.0f;
    p->f48 = 0.0f;
    p->f4C = 1.0f;
    p->w50 = 0;
    p->w54 = 0;
    p->w58 = 0;
    p->w5C = 1;
    p->f60 = 0.237697f;
    p->f64 = 0.237697f;
    p->f68 = 0.237697f;
    p->f6C = 1.0f;
    Sg_PLightAllocate(1);
    Sg_PLightDefine(0, 0xFF, 0, 0, 0, 0.0f, 0.0f, 0.0f, 1000.0f);
    func_0010DC38(D_01B005E0, 4);
}

int func_01B00810(TtPart *p)
{
    if (D_01B005E8.frame < 0x9C) {
        float pos[4];
        pos[0] = 0.0f;
        pos[1] = 0.0f;
        pos[2] = 1500.0f;
        pos[3] = 1.0f;
        func_00107428(D_01B005E0, 0x5D, pos, &p->f40);
        Sg_PLightDefine(0, 0xDC, 0xC8, 0xA0, 2, p->f40, p->f44, p->f48, D_01B00484);
        D_01B00484 += 2.0f / 7.0f;
        if (D_01B00484 > 10.0f) {
            D_01B00484 = 10.0f;
        }
        func_01B01020(D_01B013A8, (double)D_01B00484);
    } else {
        p->f44 -= D_01B00480;
        D_01B00480 -= 0.3f;
        func_002DD0B0(D_01B00700, &p->f40);
    }
    pppSetMatrix(p);
    func_002DCE38(D_006A39B0, D_006A3970, D_006A3930);
    func_002DCE38(D_006A3AB0, D_006A3A70, D_006A39B0);
    D_006A3924 = &D_01B004B0;
    if (_pppRunPart(p, 0x30) != 0) {
        D_006A3924 = &D_01B004B0;
        _pppAllFreePObject(p);
        D_006A3924 = &D_01B004B0;
        _pppStartPart(p, 0x1000, D_01B004A8->w10[0], 1);
    }
    return 1;
}

int func_01B009E0(TtPart *p)
{
    func_01B01020(D_01B013B8, D_01B005E4);
    func_0010D720();
    D_006A3924 = &D_01B004B0;
    _pppAllFreePObject(p);
    return 1;
}

int func_01B00A38(TtPart *p)
{
    func_01B01020(D_01B013D0, D_01B005E4);
    D_006A3924 = &D_01B004B0;
    _pppStartPart(p, 0x1000, D_01B004A8->w10[1], 1);
    func_002DD0B0(&p->f40, D_01B00700);
    p->w50 = 0;
    p->w54 = 0;
    p->w58 = 0;
    p->w5C = 1;
    p->f60 = 1.3193949460983276f;
    p->f64 = 1.3193949460983276f;
    p->f68 = 1.3193949460983276f;
    p->f6C = 1.0f;
}

int func_01B00AE8(TtPart *p)
{
    pppSetMatrix(p);
    func_002DCE38(D_006A39B0, D_006A3970, D_006A3930);
    func_002DCE38(D_006A3AB0, D_006A3A70, D_006A39B0);
    D_006A3924 = &D_01B004B0;
    if (_pppRunPart(p, 0x30) != 0) {
        D_006A3924 = &D_01B004B0;
        _pppAllFreePObject(p);
        D_006A3924 = &D_01B004B0;
        _pppStartPart(p, 0x1000, D_01B004A8->w10[1], 1);
    }
    func_00117F58(160, 150, 139, D_01B00488);
    D_01B00488 -= 6;
    if (D_01B00488 < 0) { D_01B00488 = 0; }
    return 1;
}

int func_01B00BD8(TtPart *p)
{
    func_01B01020(D_01B013E8, D_01B005E4);
    func_0010D720();
    D_006A3924 = &D_01B004B0;
    _pppAllFreePObject(p);
    return 1;
}

int func_01B00C30(int a)
{
    u8 *base;
    TtCfg *c;

    func_01B01020(D_01B01400);
    base = D_01B11610;
    D_01B00498 = base;
    D_01B0049C = base + 0x80000;
    D_01B004A0 = a;
    D_01B004A4 = (int *)D_01B01490;
    op_oef2_set2(D_01B004A4);
    func_002D02E8(D_01B004A4, 0, 1000, 0x2000);
    D_01B004A8 = (TtCfg *)op_oef2_a_get(D_01B004A4, 8, 0);
    _pppInitData(D_01B004A8, D_01B00040);
    pppInitEnv(&D_01B004B0, D_01B004A8, D_01B00498, 0x80000);
    c = D_01B004A8;
    D_01B004B0.w20 = c->w14;
    D_01B004B0.w24 = c->w18;
    D_01B004B0.w28 = c->w1c;
    func_01B010C0(&D_01B005E8, D_01B00450, 2);
    D_01B005E0 = func_0013B150(5);
    if (D_01B005E0 == 0) {
        func_01B01050(D_01B01410);
    }
    return 1;
}

int func_01B00D68(void)
{
    return 1;
}

int func_01B00D70(void)
{
    return 1;
}

int func_01B00D78(void)
{
    if (Sg_GetCurExecFrames() == 0) {
        return 0;
    }
    if (D_01B0048C == 0) {
        if (func_0029B830(0x2000) != 0) {
            return 1;
        }
        D_01B0048C = D_01B0048C + 1;
    }
    if (D_01B00490 == 0) {
        D_01B00490 = 1;
        MsEffectReady(D_01B004A0, 0);
    }
    if (D_01B00494 == 0) {
        if (MsEffectMotionLevel(D_01B004A0) > 0) {
            D_01B00494 = D_01B00494 + 1;
            return D_01B00494;
        }
        return 1;
    }
    return D_01B00494;
}

int func_01B00E30(void)
{
    if (D_01B00494 == 0) { return 0; }
    D_006A3924 = &D_01B004B0;
    func_001AACA0(D_006A3A70);
    func_001A9EE0(D_006A3970);
    D_006A3BCC = (int)D_01B0049C;
    if (func_0014AA50(0) != 0) {
        func_01B010B8(0x20, 0x1A);
        func_01B01078(D_01B01418, D_01B005E8.frame);
        func_01B01170(&D_01B005E8);
    }
    if (func_0014AA50(1) != 0) {
        func_01B010B8(0x20, 0x1A);
        func_01B01078(D_01B01428, D_01B005E8.frame + 1);
    }
    if (func_0014AA50(2) != 0) {
        func_01B012C8(&D_01B005E8);
        func_01B01020(D_01B01438, D_01B005E4);
        MsEffectTerminate(D_01B004A0);
        return 1;
    }
    D_01B005E4++;
    return 1;
}
