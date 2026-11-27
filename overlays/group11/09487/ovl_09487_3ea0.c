#include "common.h"

typedef struct {
    u8 pad00[0x10];
    int *w10;
} TtCfg;

typedef struct {
    u8 pad00[0x2C];
} PppEnv;

typedef struct {
    u8 pad00[0x40];
    float pos[4];
    s32 rot[4];
    float scale[4];
    u8 pad70[0x10];
} PppObj;

extern float D_01B00748;
extern float D_01B00760;
extern TtCfg *D_01B007B0;
extern PppEnv D_01B007B8;
extern float D_01B00A00[4];
extern float D_01B00AB0[4];

extern PppEnv *D_006A3924;

extern void func_00267658(void *, int, int, int);
extern void func_002DD0B0(void *, void *);

int func_01B03DB8(PppObj *p)
{
    int *arr = D_01B007B0->w10;
    register void *h __asm__("$3") = &D_01B007B8;
    float s;

    D_006A3924 = h;
    func_00267658(p, 0x1000, arr[3], 1);
    D_01B00AB0[0] = 0.0f;
    D_01B00AB0[1] = 4.999995231628418f;
    D_01B00AB0[2] = -8.5999275f;
    D_01B00AB0[3] = 1.0f;
    func_002DD0B0(p->pos, D_01B00A00);
    s = D_01B00748 * D_01B00760;
    p->scale[3] = 1.0f;
    p->rot[3] = 1;
    p->rot[0] = 0;
    p->rot[1] = 0;
    p->rot[2] = 0;
    p->scale[0] = s;
    p->scale[1] = s;
    p->scale[2] = s;
    return 1;
}
