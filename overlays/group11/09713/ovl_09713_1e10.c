#include "common.h"

typedef struct {
    u8 pad00[0x10];
    int *w10;
} TtCfg;

typedef struct {
    u8 pad00[0x40];
    float pos[4];
    s32 rot[4];
    float scale[4];
    u8 pad70[0x10];
} PppObj;

extern float D_01B00874;
extern TtCfg *D_01B008A0;
extern u8 D_01B008A8;
extern int D_01B00B20;
extern char D_01B04AA8[];

extern void *D_006A3924;
extern u8 D_006A3930[];
extern u8 D_006A3970[];
extern u8 D_006A39B0[];
extern u8 D_006A3A70[];
extern u8 D_006A3AB0[];

extern void func_01B027D8(char *, ...);
extern void func_002675B0(void *);
extern void func_00267658(void *, int, int, int);
extern int func_00267FA0(void *, int);
extern void func_002DCE38(void *, void *, void *);

int func_01B01E10(PppObj *p)
{
    func_01B027D8(D_01B04AA8, D_01B00B20);
    D_006A3924 = &D_01B008A8;
    func_00267658(p, 0x1000, D_01B008A0->w10[0], 1);
    p->pos[0] = -11.0f;
    p->pos[1] = -80.0f;
    p->pos[2] = -7.0f;
    p->pos[3] = 1.0f;
    p->rot[0] = 0;
    p->rot[1] = 0;
    p->rot[2] = 0;
    p->rot[3] = 1;
    p->scale[2] = p->scale[1] = p->scale[0] = 0.127597004f;
    p->scale[3] = 1.0f;
    return 1;
}

int func_01B01ED8(PppObj *p)
{
    p->scale[2] = p->scale[1] = p->scale[0] = D_01B00874;
    p->scale[3] = 1.0f;
    func_002675B0(p);
    func_002DCE38(D_006A39B0, D_006A3970, D_006A3930);
    func_002DCE38(D_006A3AB0, D_006A3A70, D_006A39B0);
    D_006A3924 = &D_01B008A8;
    return func_00267FA0(p, 0x30) == 0;
}
