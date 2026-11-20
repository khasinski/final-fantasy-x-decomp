/* Battle-effect overlay 09584: 0x01B01928..0x01B019FC */
#include "common.h"

typedef struct PppObj {
    u8 pad00[0x40];
    float pos[4];
    s32 rot[4];
    float scale[4];
    u8 pad70[0x10];
} PppObj;

typedef struct TtCfg {
    u8 pad00[0x10];
    int *w10;
} TtCfg;

extern void *D_006A3924;
extern TtCfg *D_01B00920;
extern u8 D_01B00928[];
extern int D_01B00D60;
extern char D_01B02840[];

int func_01B023F0(char *, ...);
void func_00267658(PppObj *, int, int, int);

int func_01B01928(PppObj *p)
{
    func_01B023F0(D_01B02840, D_01B00D60);
    D_006A3924 = D_01B00928;
    func_00267658(p, 0x1000, D_01B00920->w10[5], 1);
    p->pos[0] = 0.300002009f;
    p->pos[1] = -29.4997654f;
    p->pos[2] = 138.99852f;
    p->pos[3] = 1.0f;
    p->rot[0] = 0;
    p->rot[1] = 0;
    p->rot[2] = 0;
    p->rot[3] = 1;
    p->scale[2] = p->scale[1] = p->scale[0] = 0.070596002f;
    p->scale[3] = 1.0f;
    return 1;
}
