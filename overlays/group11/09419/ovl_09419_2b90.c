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

extern TtCfg *D_01B007E0;
extern u8 D_01B007E8;
extern int D_01B01058;
extern char D_01B041C8[];

extern void *D_006A3924;

extern int func_01B03408(char *, ...);
extern void func_00267658(void *, int, int, int);

void func_01B02B90(PppObj *p)
{
    func_01B03408(D_01B041C8, D_01B01058);
    D_006A3924 = &D_01B007E8;
    func_00267658(p, 0x1000, D_01B007E0->w10[5], 1);
    p->pos[0] = 14.0f;
    p->pos[1] = -16.5f;
    p->pos[2] = 71.0f;
    p->pos[3] = 1.0f;
    p->rot[0] = 0;
    p->rot[1] = 0;
    p->rot[2] = 0;
    p->rot[3] = 1;
    p->scale[2] = p->scale[1] = p->scale[0] = 0.04913748056f;
    p->scale[3] = 1.0f;
}
