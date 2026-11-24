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

extern TtCfg *D_01B00800;
extern u8 D_01B00808;
extern PppObj D_01B00EC0[];
extern int D_01B012C0;
extern char D_01B04D00[];

extern void *D_006A3924;

extern int func_01B03970(char *, ...);
extern void func_00267658(void *, int, int, int);

int func_01B028A0(PppObj *p)
{
    func_01B03970(D_01B04D00, D_01B012C0);
    D_006A3924 = &D_01B00808;
    func_00267658(p, 0x1000, D_01B00800->w10[3], 1);
    if (p - D_01B00EC0 == 0) {
        p->pos[0] = 2.829998016f;
        p->pos[1] = -0.009999999776f;
        p->pos[2] = -3.529999018f;
        p->pos[3] = 1.0f;
    } else {
        p->pos[0] = -4.269999027f;
        p->pos[1] = -0.009999999776f;
        p->pos[2] = 1.669999003f;
        p->pos[3] = 1.0f;
    }
    p->rot[0] = 0;
    p->rot[1] = 0;
    p->rot[2] = 0;
    p->rot[3] = 1;
    p->scale[2] = p->scale[1] = p->scale[0] = 0.1265130043f;
    p->scale[3] = 1.0f;
    return 1;
}
