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

extern TtCfg *D_01B0055C;
extern u8 D_01B00560;
extern int D_01B00850;
extern char D_01B02B00[];

extern void *D_006A3924;

extern int func_01B01E48(char *, ...);
extern void func_00267658(void *, int, int, int);

int func_01B01508(PppObj *p)
{
    func_01B01E48(D_01B02B00, D_01B00850);
    D_006A3924 = &D_01B00560;
    func_00267658(p, 0x1000, D_01B0055C->w10[1], 1);
    p->pos[0] = -33.0f;
    p->pos[1] = -18.0f;
    p->pos[2] = 21.0f;
    p->pos[3] = 1.0f;
    p->rot[0] = 0;
    p->rot[1] = 0;
    p->rot[2] = 0;
    p->rot[3] = 1;
    p->scale[2] = p->scale[1] = p->scale[0] = 0.155596003f;
    p->scale[3] = 1.0f;
    return 1;
}
