/* EE battle-effect overlay 09531: byte-exact C.
 * .text 0x01B00A40..0x01B00E74 (4 functions).
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

extern u8 D_01B00040[];
extern TtEnt D_01B00400[];
extern TtEnt D_01B00418[];
extern float D_01B00430[4];
extern int D_01B0044C;
extern void *D_01B00450;
extern void *D_01B00454;
extern int D_01B00458;
extern void *D_01B0045C;
extern u8 *D_01B00460;
extern u8 *D_01B00464;
extern TtCfg *D_01B00468;
extern TtHeap D_01B00470;
extern TtPart D_01B00520;
extern TtRing D_01B00640;
extern TtRing D_01B00750;
extern float D_01B00860;
extern float D_01B00870[4];
extern float D_01B00880;
extern char D_01B01530[];
extern char D_01B01548[];
extern char D_01B01560[];
extern char D_01B01570[];
extern char D_01B01580[];
extern u8 D_01B015F0[];
extern u8 D_01B39EE0[];

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
void *func_0013B150(int a);

float func_01B010D0(float *v);
int func_01B01190(char *fmt, ...);
void func_01B011C0(char *fmt, ...);
void func_01B01230(TtRing *r, TtEnt *tbl, int n);

int func_01B00A40(void)
{
    func_01B01190(D_01B01530, D_01B00458);
    D_006A3924 = &D_01B00470;
    _pppStartPart(&D_01B00520, 0x1000, D_01B00468->w10[0], 1);
    D_01B00520.f40 = 0.0f;
    D_01B00520.f44 = 0.0f;
    D_01B00520.f48 = 0.0f;
    D_01B00520.f4C = 1.0f;
    D_01B00520.w50 = 0;
    D_01B00520.w54 = 0x8000;
    D_01B00520.w58 = 0;
    D_01B00520.w5C = 1;
    D_01B00860 = 0.7f;
    D_01B00870[0] = -206.43983f;
    D_01B00870[1] = -6.149711f;
    D_01B00870[2] = -87.749146f;
    D_01B00870[3] = 0.0f;
    func_01B010D0(D_01B00430);
    D_01B00880 = 5.0f;
    return 1;
}

int func_01B00B48(void)
{
    float s;
    D_01B00870[0] += D_01B00430[0] * D_01B00880;
    D_01B00870[2] += D_01B00430[2] * D_01B00880;
    D_01B00880 += 0.4f;
    D_01B00520.f40 = D_01B00870[0];
    D_01B00520.f48 = D_01B00870[2];
    D_01B00520.f44 = -3.0f;
    D_01B00860 += 0.051999997f;
    s = D_01B00860 * 0.03125f;
    D_01B00520.f60 = s;
    D_01B00520.f64 = s;
    D_01B00520.f68 = s;
    D_01B00520.f6C = 1.0f;
    pppSetMatrix(&D_01B00520);
    func_002DCE38(D_006A39B0, D_006A3970, D_006A3930);
    func_002DCE38(D_006A3AB0, D_006A3A70, D_006A39B0);
    D_006A3924 = &D_01B00470;
    if (_pppRunPart(&D_01B00520, 0x30) != 0) {
        D_006A3924 = &D_01B00470;
        _pppAllFreePObject(&D_01B00520);
        D_006A3924 = &D_01B00470;
        _pppStartPart(&D_01B00520, 0x1000, D_01B00468->w10[0], 1);
    }
    return 1;
}

int func_01B00CC0(void)
{
    D_006A3924 = &D_01B00470;
    _pppAllFreePObject(&D_01B00520);
    func_01B01190(D_01B01548, D_01B00458);
    return 1;
}

int func_01B00D08(void)
{
    return 1;
}

int func_01B00D10(int a0)
{
    func_01B01190(D_01B01560);
    D_01B0044C = a0;
    D_01B00460 = D_01B39EE0;
    D_01B00464 = D_01B00460 + 0x80000;
    D_01B0045C = D_01B015F0;
    op_oef2_set2(D_01B015F0);
    func_002D02E8(D_01B0045C, 0, 0x3E8, 0x2000);
    D_01B00468 = (TtCfg *)op_oef2_a_get(D_01B0045C, 8, 0);
    _pppInitData(D_01B00468, D_01B00040);
    pppInitEnv(&D_01B00470, D_01B00468, D_01B00460, 0x80000);
    D_01B00470.w20 = D_01B00468->w14;
    D_01B00470.w24 = D_01B00468->w18;
    D_01B00470.w28 = D_01B00468->w1c;
    func_01B01230(&D_01B00640, D_01B00418, 1);
    func_01B01230(&D_01B00750, D_01B00400, 1);
    D_01B00454 = func_0013B150(0);
    if (D_01B00454 == 0) {
        func_01B011C0(D_01B01570);
    }
    D_01B00450 = func_0013B150(0x15);
    if (D_01B00450 == 0) {
        func_01B011C0(D_01B01580);
    }
    return 1;
}
