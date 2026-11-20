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

extern int D_01B00594;
extern TtCfg *D_01B005B0;
extern u8 D_01B005B8;
extern PppObj D_01B008F0[];
extern char D_01B02928[];

extern void *D_006A3924;

extern int func_01B01CA8(char *, ...);
extern void func_00267658(void *, int, int, int);

int func_01B014B8(PppObj *p)
{
    int idx = p - D_01B008F0;

    func_01B01CA8(D_01B02928, D_01B00594);
    D_006A3924 = &D_01B005B8;
    func_00267658(p, 0x1000, D_01B005B0->w10[0], 1);
    if (idx == 0) {
        p->pos[0] = -102.213264f;
        p->pos[1] = -120.44088f;
        p->pos[2] = -0.441482991f;
        p->pos[3] = 1.0f;
        p->scale[2] = p->scale[1] = p->scale[0] = 0.075000003f;
        p->scale[3] = 1.0f;
    } else if (idx == 1) {
        p->pos[0] = 27.7867432f;
        p->pos[1] = -120.440872f;
        p->pos[2] = -128.441483f;
        p->pos[3] = 1.0f;
        p->scale[2] = p->scale[1] = p->scale[0] = 0.075000003f;
        p->scale[3] = 1.0f;
    } else if (idx == 2) {
        p->pos[0] = -30.3216324f;
        p->pos[1] = -120.844788f;
        p->pos[2] = 61.5400848f;
        p->pos[3] = 1.0f;
        p->scale[2] = p->scale[1] = p->scale[0] = 0.0979989991f;
        p->scale[3] = 1.0f;
    }
    p->rot[0] = 0;
    p->rot[1] = 0;
    p->rot[2] = 0;
    p->rot[3] = 1;
    return 1;
}
