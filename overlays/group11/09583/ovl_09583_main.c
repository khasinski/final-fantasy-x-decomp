/* EE Battle-Effect Overlay: group 0x11, file 09583
 * .text: 0x01B00FB8..0x01B013B0 (6 functions: two ppp part init/run/free triples).
 */
#include "common.h"

typedef struct TtCfg {
    u8 pad00[0x10];
    int *w10;
    float *w14;
    s16 *w18;
    char *w1c;
} TtCfg;

typedef struct TtHeap {
    u8 pad00[0x20];
    float *w20;
    s16 *w24;
    char *w28;
} TtHeap;

typedef struct TtPObj {
    u8 pad00[0x40];
    float x, y, z, w;
    int rx, ry, rz, rw;
    float sx, sy, sz, sw;
} TtPObj;

extern void *D_006A3924;
extern u8 D_006A3930[];
extern u8 D_006A3970[];
extern u8 D_006A39B0[];
extern u8 D_006A3A70[];
extern u8 D_006A3AB0[];

extern u8 D_01B004A0[];
extern void *D_01B00BAC;
extern void *D_01B00BB8;
extern TtCfg *D_01B00BBC;
extern TtCfg *D_01B00BC0;
extern TtHeap D_01B00BC8;
extern TtPObj D_01B00D00;
extern int D_01B00D84;
extern int D_01B00E98;
extern char D_01B01B28[];
extern char D_01B01B40[];
extern char D_01B01B58[];
extern char D_01B01B70[];
extern u8 D_01B30E00[];

extern int func_01B017B8(char *, ...);
extern void func_00267530(void *);
extern void func_002675B0(void *);
extern void func_00267658(void *, int, int, int);
extern void func_002678E0(void *, void *);
extern void func_00267A68(void *, void *, void *, int);
extern int func_00267FA0(void *, int);
extern void func_002B4980(void *);
extern TtCfg *func_002B49A0(void *, int, int);
extern void func_002D02E8(void *, int, int, int);
extern void func_002D05F0(int);
extern void func_002DCE38(void *, void *, void *);

int func_01B00FB0(void)
{
    return 1;
}

void func_01B00FB8(TtPObj *o)
{
    func_01B017B8(D_01B01B28, D_01B00D84);
    D_006A3924 = &D_01B00BC8;
    func_00267658(o, 0x1000, D_01B00BBC->w10[0], 1);
    o->x = 977.0f;
    o->y = -31.0f;
    o->z = -1463.5f;
    o->w = 1.0f;
    o->rx = 0;
    o->ry = 0x8400;
    o->rz = 0;
    o->rw = 1;
    o->sx = 0.0625f;
    o->sy = 0.0625f;
    o->sz = 0.0625f;
    o->sw = 1.0f;
}

int func_01B01088(TtPObj *o)
{
    func_002675B0(o);
    func_002DCE38(D_006A39B0, D_006A3970, D_006A3930);
    func_002DCE38(D_006A3AB0, D_006A3A70, D_006A39B0);
    D_006A3924 = &D_01B00BC8;
    if (func_00267FA0(o, 0x30) != 0) {
        return 0;
    }
    return D_01B00E98 != 0x1F;
}

int func_01B01120(TtPObj *o)
{
    func_01B017B8(D_01B01B40, D_01B00D84);
    D_006A3924 = &D_01B00BC8;
    func_00267530(o);
    return 1;
}

void func_01B01170(void)
{
    TtCfg *c;

    func_01B017B8(D_01B01B58, D_01B00D84);
    D_01B00BB8 = D_01B30E00;
    func_002B4980(D_01B30E00);
    func_002D02E8(D_01B00BB8, 0, 0x3E8, 0x2000);
    func_002D05F0(0x2000);
    D_01B00BC0 = func_002B49A0(D_01B00BB8, 8, 0);
    func_002678E0(D_01B00BC0, D_01B004A0);
    func_00267A68(&D_01B00BC8, D_01B00BC0, D_01B00BAC, 0x80000);
    c = D_01B00BC0;
    D_01B00BC8.w20 = c->w14;
    D_01B00BC8.w24 = c->w18;
    D_01B00BC8.w28 = c->w1c;
    D_006A3924 = &D_01B00BC8;
    func_00267658(&D_01B00D00, 0x1000, c->w10[0], 1);
    D_01B00D00.x = 1153.0f;
    D_01B00D00.y = -30.0f;
    D_01B00D00.z = -1444.0f;
    D_01B00D00.w = 1.0f;
    D_01B00D00.rx = 0;
    D_01B00D00.ry = 0;
    D_01B00D00.rz = 0;
    D_01B00D00.rw = 1;
    D_01B00D00.sx = 0.1f;
    D_01B00D00.sy = 0.1f;
    D_01B00D00.sz = 0.1f;
    D_01B00D00.sw = 1.0f;
}

int func_01B012D8(void)
{
    func_002675B0(&D_01B00D00);
    func_002DCE38(D_006A39B0, D_006A3970, D_006A3930);
    func_002DCE38(D_006A3AB0, D_006A3A70, D_006A39B0);
    D_006A3924 = &D_01B00BC8;
    return func_00267FA0(&D_01B00D00, 0x30) == 0;
}

int func_01B01368(void)
{
    func_01B017B8(D_01B01B70, D_01B00D84);
    D_006A3924 = &D_01B00BC8;
    func_00267530(&D_01B00D00);
    return 1;
}
