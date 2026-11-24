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

extern TtCfg *D_01B00800;
extern u8 D_01B00808;
extern PppObj D_01B00FC0[];
extern int D_01B012C0;
extern u8 D_01B04D30[];

extern void *D_006A3924;

extern void func_01B03970(void *, int);
extern void func_00267658(void *, int, int, int);

int func_01B02A98(PppObj *p)
{
    func_01B03970(D_01B04D30, D_01B012C0);
    D_006A3924 = &D_01B00808;
    func_00267658(p, 0x1000, D_01B00800->w10[11], 1);

    if (p - D_01B00FC0 == 0) {
        p->pos[0] = -17.399959564208984f;
        p->pos[1] = -0.01f;
        p->pos[2] = -21.139982223510742f;
        p->pos[3] = 1.0f;
        p->scale[2] = p->scale[1] = p->scale[0] = 0.007922999560832977f;
        p->scale[3] = 1.0f;
        p->rot[0] = 0;
        p->rot[1] = 0x7054;
        p->rot[2] = 0;
        p->rot[3] = 1;
    } else {
        p->pos[0] = -12.399955749511719f;
        p->pos[1] = -0.01f;
        p->pos[2] = -28.039926528930664f;
        p->pos[3] = 1.0f;
        p->scale[2] = p->scale[1] = p->scale[0] = 0.007922999560832977f;
        p->scale[3] = 1.0f;
        p->rot[0] = -0x38E;
        p->rot[1] = -0x2AA8;
        p->rot[2] = 0;
        p->rot[3] = 1;
    }
    return 1;
}
