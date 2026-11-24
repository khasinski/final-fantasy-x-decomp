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

extern TtCfg *D_01B006C8;
extern u8 D_01B006D0;
extern PppObj D_01B00980[];
extern int D_01B00DA8;
extern int D_01B00DAC;
extern int D_01B00E60;
extern char D_01B03838[];

extern void *D_006A3924;

extern int func_01B02BC0(char *, ...);
extern void func_00107428(int, int, int, float *);
extern void func_00267658(void *, int, int, int);

int func_01B02080(PppObj *p)
{
    func_01B02BC0(D_01B03838, D_01B00E60);
    D_006A3924 = &D_01B006D0;
    func_00267658(p, 0x1000, D_01B006C8->w10[2], 1);
    p->pos[0] = 0.0f;
    p->pos[1] = 0.0f;
    p->pos[2] = 0.0f;
    p->pos[3] = 1.0f;
    p->rot[0] = 0;
    p->rot[1] = 0;
    p->rot[2] = 0;
    p->rot[3] = 1;
    p->scale[2] = p->scale[1] = p->scale[0] = 0.0625f;
    p->scale[3] = 1.0f;
    if (p - D_01B00980 == 0) {
        func_00107428(D_01B00DA8, 5, 0, p->pos);
    } else {
        func_00107428(D_01B00DAC, 5, 0, p->pos);
    }
    return 1;
}
