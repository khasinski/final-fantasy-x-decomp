/* Battle-effect overlay 09584: 0x01B01630..0x01B01850 */
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
extern PppObj D_01B00A60[];
extern int D_01B00D60;
extern char D_01B02810[];

int func_01B023F0(char *, ...);
void func_00267658(PppObj *, int, int, int);

int func_01B01630(PppObj *p)
{
    int idx;

    func_01B023F0(D_01B02810, D_01B00D60);
    idx = p - D_01B00A60;
    if (idx != 3) {
        D_006A3924 = D_01B00928;
        func_00267658(p, 0x1000, D_01B00920->w10[0], 1);
    } else {
        D_006A3924 = D_01B00928;
        func_00267658(p, 0x1000, D_01B00920->w10[1], 1);
    }
    switch (idx) {
    case 0:
        p->pos[0] = -12.4999285f;
        p->pos[1] = -10.3998365f;
        p->pos[2] = 156.296341f;
        p->pos[3] = 1.0f;
        p->rot[0] = 0;
        p->rot[1] = 0;
        p->rot[2] = 0;
        p->rot[3] = 1;
        p->scale[2] = p->scale[1] = p->scale[0] = 0.075000003f;
        p->scale[3] = 1.0f;
        break;
    case 1:
        p->pos[0] = -8.49997425f;
        p->pos[1] = -8.79989529f;
        p->pos[2] = 142.999985f;
        p->pos[3] = 1.0f;
        p->rot[0] = 0;
        p->rot[1] = 0;
        p->rot[2] = 0;
        p->rot[3] = 1;
        p->scale[2] = p->scale[1] = p->scale[0] = 0.0689989999f;
        p->scale[3] = 1.0f;
        break;
    case 2:
        p->pos[0] = 5.099998f;
        p->pos[1] = -11.0999784f;
        p->pos[2] = 155.699844f;
        p->pos[3] = 1.0f;
        p->rot[0] = 0;
        p->rot[1] = 0;
        p->rot[2] = 0;
        p->rot[3] = 1;
        p->scale[2] = p->scale[1] = p->scale[0] = 0.0869999975f;
        p->scale[3] = 1.0f;
        break;
    case 3:
        p->pos[0] = -13.6999884f;
        p->pos[1] = 1.30000198f;
        p->pos[2] = 132.498993f;
        p->pos[3] = 1.0f;
        p->rot[0] = 0;
        p->rot[1] = 0;
        p->rot[2] = 0;
        p->rot[3] = 1;
        p->scale[2] = p->scale[1] = p->scale[0] = 0.0915959999f;
        p->scale[3] = 1.0f;
        break;
    }
    return 1;
}
