/* Battle-effect overlay 09540: 0x01B027B8..0x01B0289C */
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
    void **w10;
} TtCfg;

extern void *D_006A3924;
extern TtCfg *D_01B00AF4;
extern u8 D_01B00AF8[];
extern PppObj D_01B016B0[];
extern float D_01B00640[][4];
extern int D_01B01EB4;
extern char D_01B033E0[];

int func_01B02FE0(char *, ...);
void func_00267658(PppObj *, int, void *, int);

int func_01B027B8(PppObj *p)
{
    int idx;

    func_01B02FE0(D_01B033E0, D_01B01EB4);
    D_006A3924 = D_01B00AF8;
    func_00267658(p, 0x1000, D_01B00AF4->w10[3], 1);
    idx = p - D_01B016B0;
    p->pos[0] = D_01B00640[idx][0];
    p->pos[1] = D_01B00640[idx][1];
    p->pos[2] = D_01B00640[idx][2];
    p->pos[3] = 1.0f;
    p->rot[0] = 0;
    p->rot[1] = 0;
    p->rot[2] = 0;
    p->rot[3] = 1;
    p->scale[2] = p->scale[1] = p->scale[0] = 0.151501f;
    p->scale[3] = 1.0f;
    return 1;
}
