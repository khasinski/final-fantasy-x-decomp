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
extern PppObj D_01B00CC0[];
extern int D_01B012C0;
extern int D_01B013E0;
extern u8 D_01B04CA0[];

extern void *D_006A3924;

extern void func_01B03970(void *, int);
extern void func_00267658(void *, int, int, int);

int func_01B02420(PppObj *p)
{
    int idx = p - D_01B00CC0;

    func_01B03970(D_01B04CA0, D_01B012C0);
    D_006A3924 = &D_01B00808;
    func_00267658(p, 0x1000, D_01B00800->w10[13], 1);

    p->pos[0] = 0.0f;
    p->pos[1] = 0.0f;
    p->pos[2] = 0.0f;
    p->pos[3] = 1.0f;
    p->rot[0] = 0;
    p->rot[1] = 0;
    p->rot[2] = 0;
    p->rot[3] = 1;
    p->scale[2] = p->scale[1] = p->scale[0] = 0.07624399662017822f;
    __asm__("" : "+r"(p));
    p->scale[3] = 1.0f;

    if (idx == 0 && D_01B013E0 >= 0x3B1) {
        p->scale[2] = p->scale[1] = p->scale[0] = 0.0609951987862587f;
    }
    return 1;
}
