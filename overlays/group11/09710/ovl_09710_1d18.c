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

extern float D_01B007CC;
extern TtCfg *D_01B00800;
extern u8 D_01B00808;
extern int D_01B012C0;
extern int D_01B012C4;
extern char D_01B04C10[];

extern void *D_006A3924;

extern int func_01B03970(char *, ...);
extern void func_00107428(int, int, int, float *);
extern void func_00267658(void *, int, int, int);

int func_01B01D18(PppObj *p)
{
    func_01B03970(D_01B04C10, D_01B012C0);
    D_006A3924 = &D_01B00808;
    func_00267658(p, 0x1000, D_01B00800->w10[7], 1);
    p->pos[0] = 0.0f;
    p->pos[1] = 0.0f;
    p->pos[2] = 0.0f;
    p->pos[3] = 1.0f;
    p->rot[0] = 0;
    p->rot[1] = 0;
    p->rot[2] = 0;
    p->rot[3] = 1;
    p->scale[2] = p->scale[1] = p->scale[0] = 0.01647759974f;
    p->scale[3] = 1.0f;
    func_00107428(D_01B012C4, 3, 0, p->pos);
    p->pos[1] = D_01B007CC;
    return 1;
}
