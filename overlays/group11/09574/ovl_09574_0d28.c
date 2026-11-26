#include "common.h"

typedef struct {
    u8 pad00[0x10];
    int *w10;
} TtCfg;

typedef struct {
    u8 pad00[0x40];
    float pos[4];
    int rot[4];
    float scale[4];
} TtPart;

extern void *D_006A3924;
extern float D_01B0079C;
extern void *D_01B007D4;
extern TtCfg *D_01B007D8;
extern u8 D_01B007E0[];
extern void *D_01B00920;
extern s32 D_01B00928;

extern void _pppStartPart(TtPart *, int, int, int);
extern void Ch_OptposGet(void *, int, float *);
extern void op_oef2_se_3d_on(void *, float *, int);

int func_01B00D28(TtPart *p)
{
    float s;
    s32 flag;
    {
        int *w10 = D_01B007D8->w10;
        register u8 *env __asm__("$3") = D_01B007E0;
        D_006A3924 = env;
        _pppStartPart(p, 0x1000, w10[0], 1);
    }
    Ch_OptposGet(D_01B00920, 0x10, p->pos);

    s = D_01B0079C;
    flag = D_01B00928;
    p->scale[0] = s;
    p->scale[1] = s;
    p->scale[2] = s;
    p->scale[3] = 1.0f;
    p->rot[0] = 0;
    p->rot[1] = 0;
    p->rot[2] = 0;
    p->rot[3] = 1;

    if (flag != 0) {
        op_oef2_se_3d_on(D_01B007D4, p->pos, 0x100);
    }
    return 1;
}
