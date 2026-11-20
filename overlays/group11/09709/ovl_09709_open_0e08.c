/* Battle-effect overlay 09709: 0x01B00E08..0x01B00EDC */
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
extern TtCfg *D_01B00654;
extern u8 D_01B00658[];
extern int D_01B00A90;
extern char D_01B02538[];

int func_01B02170(char *, ...);
void func_00267658(PppObj *, int, int, int);

int func_01B00E08(PppObj *p)
{
    func_01B02170(D_01B02538, D_01B00A90);
    D_006A3924 = D_01B00658;
    func_00267658(p, 0x1000, D_01B00654->w10[7], 1);
    p->pos[0] = -44.5499763f;
    p->pos[1] = -0.00999999978f;
    p->pos[2] = -0.529996991f;
    p->pos[3] = 1.0f;
    p->rot[0] = 0;
    p->rot[1] = 0;
    p->rot[2] = 0;
    p->rot[3] = 1;
    p->scale[2] = p->scale[1] = p->scale[0] = 0.0155570004f;
    p->scale[3] = 1.0f;
    return 1;
}
