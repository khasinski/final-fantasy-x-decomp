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

extern TtCfg *D_01B006C8;
extern u8 D_01B006D0;
extern PppObj D_01B00B80[];
extern void *D_01B00DB8;
extern s32 D_01B00E60;
extern u8 D_01B03818[];

extern void *D_006A3924;

extern int func_01B02BC0(void *, ...);
extern void func_00107428(void *, s32, s32, float *);
extern void func_00267658(void *, s32, s32, s32);

int func_01B01E58(PppObj *p)
{
    float s;

    func_01B02BC0(D_01B03818, D_01B00E60);
    func_00107428(D_01B00DB8, 0x6E, 0, p->pos);
    p->pos[0] = 0.917477011680603f;
    p->pos[2] = -28.732973098754883f;
    if (p - D_01B00B80 == 0) {
        D_006A3924 = &D_01B006D0;
        func_00267658(p, 0x1000, D_01B006C8->w10[0], 1);
        s = 0.1875f;
        p->scale[2] = p->scale[1] = p->scale[0] = s;
        p->scale[3] = 1.0f;
    } else {
        D_006A3924 = &D_01B006D0;
        func_00267658(p, 0x1000, D_01B006C8->w10[1], 1);
        p->pos[1] += -10.0f;
        p->pos[1] += -10.0f;
        s = 0.625f;
        p->scale[2] = p->scale[1] = p->scale[0] = s;
        p->scale[3] = 1.0f;
    }
    p->rot[0] = 0;
    p->rot[1] = 0;
    p->rot[2] = 0;
    p->rot[3] = 1;
    return 1;
}
