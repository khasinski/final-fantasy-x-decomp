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
extern char D_01B02898[];

extern void *D_006A3924;

extern int func_01B01CA8(char *, ...);
extern void func_00267658(void *, int, int, int);

int func_01B00CC8(PppObj *p)
{
    func_01B01CA8(D_01B02898, D_01B00594);
    D_006A3924 = &D_01B005B8;
    func_00267658(p, 0x1000, D_01B005B0->w10[2], 1);
    p->pos[0] = -25.6375732f;
    p->pos[1] = -121.324089f;
    p->pos[2] = -29.2202148f;
    p->pos[3] = 1.0f;
    p->scale[2] = p->scale[1] = p->scale[0] = 0.0430000015f;
    p->scale[3] = 1.0f;
    p->rot[0] = 0;
    p->rot[1] = 0;
    p->rot[2] = 0;
    p->rot[3] = 1;
    return 1;
}
