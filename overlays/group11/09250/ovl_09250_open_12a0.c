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
extern PppObj D_01B00610[];
extern int D_01B00850;
extern char D_01B02AD0[];

extern void *D_006A3924;

extern int func_01B01E48(char *, ...);
extern void func_00267658(void *, int, int, int);

int func_01B012A0(PppObj *p)
{
    func_01B01E48(D_01B02AD0, D_01B00850);
    if (p - D_01B00610 == 0) {
        D_006A3924 = &D_01B00560;
        func_00267658(p, 0x1000, D_01B0055C->w10[2], 1);
        p->pos[0] = -13.4999933f;
        p->pos[1] = -0.400000006f;
        p->pos[2] = -54.2999954f;
        p->pos[3] = 1.0f;
        p->rot[0] = 0;
        p->rot[1] = 0;
        p->rot[2] = 0;
        p->rot[3] = 1;
        p->scale[2] = p->scale[1] = p->scale[0] = 0.110596001f;
        p->scale[3] = 1.0f;
    } else {
        D_006A3924 = &D_01B00560;
        func_00267658(p, 0x1000, D_01B0055C->w10[3], 1);
        p->pos[0] = -8.69998646f;
        p->pos[1] = -0.600000024f;
        p->pos[2] = -74.0999374f;
        p->pos[3] = 1.0f;
        p->rot[0] = 0;
        p->rot[1] = -0x9600;
        p->rot[2] = 0;
        p->rot[3] = 1;
        p->scale[2] = p->scale[1] = p->scale[0] = 0.177596003f;
        p->scale[3] = 1.0f;
    }
    return 1;
}
