/* EE battle-effect overlay 09605: byte-exact C.
 * .text 0x01B006F0..0x01B00A70.
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
    u16 h70;
    u16 h72;
    u16 h74;
    u16 h76;
} TtPart;

extern u8 D_01B00040[];
extern TtEnt D_01B00450[];
extern float D_01B00468[4];
extern u8 *D_01B00484;
extern u8 *D_01B00488;
extern int D_01B0048C;
extern void *D_01B00490;
extern TtCfg *D_01B00494;
extern TtHeap D_01B00498;
extern int D_01B005D4;
extern TtRing D_01B005D8;
extern char D_01B01400[];
extern char D_01B01418[];
extern char D_01B01420[];
extern char D_01B01438[];
extern u8 D_01B014C0[];
extern u8 D_01B0E610[];

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

int func_01B01078(char *fmt, ...);
void func_01B01120(TtRing *r, TtEnt *tbl, int n);

void func_01B006F0(TtPart *p)
{
    func_01B01078(D_01B01400, D_01B005D4);
    D_006A3924 = &D_01B00498;
    _pppStartPart(p, 0x1000, D_01B00494->w10[0], 1);
    p->f40 = -1561.0f;
    p->f44 = -4210.1997f;
    p->f48 = -171.0f;
    p->f4C = 1.0f;
    p->w50 = 0;
    p->w54 = 0;
    p->w58 = 0;
    p->w5C = 1;
    p->f60 = 4.949391f;
    p->f64 = 4.949391f;
    p->f68 = 4.949391f;
    p->f6C = 1.0f;
    func_01B01078(D_01B01418, p->h70);
    func_01B01078(D_01B01418, p->h72);
    func_01B01078(D_01B01418, p->h74);
    func_01B01078(D_01B01418, p->h76);
}

int func_01B007F8(TtPart *p)
{
    p->h70 = (int)D_01B00468[0];
    p->h72 = (int)D_01B00468[1];
    p->h74 = (int)D_01B00468[2];
    p->h76 = (int)D_01B00468[3];
    pppSetMatrix(p);
    func_002DCE38(D_006A39B0, D_006A3970, D_006A3930);
    func_002DCE38(D_006A3AB0, D_006A3A70, D_006A39B0);
    D_006A3924 = &D_01B00498;
    if (_pppRunPart(p, 0x30) != 0) {
        D_006A3924 = &D_01B00498;
        _pppAllFreePObject(p);
        D_006A3924 = &D_01B00498;
        _pppStartPart(p, 0x1000, D_01B00494->w10[0], 1);
    }
    return 1;
}

int func_01B00908(TtPart *p)
{
    func_01B01078(D_01B01420, D_01B005D4);
    D_006A3924 = &D_01B00498;
    _pppAllFreePObject(p);
    return 1;
}

int func_01B00958(int a0)
{
    func_01B01078(D_01B01438);
    D_01B00484 = D_01B0E610;
    D_01B00488 = D_01B00484 + 0x80000;
    D_01B0048C = a0;
    D_01B00490 = D_01B014C0;
    op_oef2_set2(D_01B014C0);
    func_002D02E8(D_01B00490, 0, 0x3E8, 0x2000);
    D_01B00494 = (TtCfg *)op_oef2_a_get(D_01B00490, 8, 0);
    _pppInitData(D_01B00494, D_01B00040);
    pppInitEnv(&D_01B00498, D_01B00494, D_01B00484, 0x80000);
    D_01B00498.w20 = D_01B00494->w14;
    D_01B00498.w24 = D_01B00494->w18;
    D_01B00498.w28 = D_01B00494->w1c;
    func_01B01120(&D_01B005D8, D_01B00450, 1);
    return 1;
}
