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

extern TtCfg *D_01B00474;
extern u8 D_01B00478;
extern PppObj D_01B005B0[];

extern void *D_006A3924;

extern void func_00267658(void *, int, int, int);

void func_01B00BF8(PppObj *p)
{
    D_006A3924 = &D_01B00478;
    func_00267658(p, 0x1000, D_01B00474->w10[3], 1);
    if (p - D_01B005B0 == 0) {
        p->pos[0] = 20.4126263f;
        p->pos[1] = -35.9432526f;
        p->pos[2] = -142.465393f;
        p->pos[3] = 1.0f;
        p->rot[0] = 0;
        p->rot[1] = -0x5600;
        p->rot[2] = 0;
        p->rot[3] = 1;
        p->scale[2] = p->scale[1] = p->scale[0] = 0.412496001f;
        p->scale[3] = 1.0f;
    } else {
        p->pos[0] = 27.7211189f;
        p->pos[1] = -26.273674f;
        p->pos[2] = -184.319473f;
        p->pos[3] = 1.0f;
        p->rot[0] = 0;
        p->rot[1] = 0;
        p->rot[2] = 0;
        p->rot[3] = 1;
        p->scale[2] = p->scale[1] = p->scale[0] = 0.723492026f;
        p->scale[3] = 1.0f;
    }
}
