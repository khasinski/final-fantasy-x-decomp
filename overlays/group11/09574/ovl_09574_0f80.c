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
extern float D_01B00798;
extern void *D_01B007D0;
extern TtCfg *D_01B007D8;
extern u8 D_01B007E0[];
extern void *D_01B00918;

extern void Ch_GetRootGlobalMatrix(void *, float *);
extern void _pppStartPart(TtPart *, int, int, int);
extern void op_oef2_se_3d_on(void *, float *, int);

int func_01B00F80(TtPart *p)
{
    float mtx[16];

    Ch_GetRootGlobalMatrix(D_01B00918, mtx);
    {
        register void **p3924 __asm__("$8") = &D_006A3924;
        int *w10 = D_01B007D8->w10;
        register u8 *env __asm__("$2") = D_01B007E0;
        *p3924 = env;
        _pppStartPart(p, 0x1000, w10[1], 1);
    }

    p->pos[0] = 0.0f;
    {
        register float s __asm__("$f1") = D_01B00798;
        register float one __asm__("$f0") = 1.0f;
        register int one_i __asm__("$3") = 1;
        p->pos[3] = one;
        p->scale[3] = one;
        p->scale[0] = s;
        p->scale[1] = s;
        p->scale[2] = s;
        p->pos[1] = 0.0f;
        p->pos[2] = 0.0f;
        p->rot[0] = 0;
        p->rot[1] = 0;
        p->rot[2] = 0;
        p->rot[3] = one_i;
    }

    op_oef2_se_3d_on(D_01B007D0, &mtx[12], 0x100);
    return 1;
}
