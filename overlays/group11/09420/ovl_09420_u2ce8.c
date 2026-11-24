#include "common.h"

typedef struct TtCfg {
    u8 pad00[0x10];
    int *w10;
} TtCfg;

typedef struct TtPart {
    u8 pad00[0x40];
    float pos[4];
    int rot[4];
    float scale[4];
    u8 pad70[0x10];
} TtPart;

extern void *D_006A3924;
extern TtCfg *D_01B00878;
extern u8 D_01B00880[];
extern TtPart D_01B00DB0[];
extern int D_01B01258;
extern char D_01B045F8[];

int func_01B03858(char *, ...);
void func_00267658(void *, int, int, int);

void func_01B02CE8(TtPart *p)
{
    int idx;

    func_01B03858(D_01B045F8, D_01B01258);
    idx = p - D_01B00DB0;
    if (idx == 0) {
        D_006A3924 = D_01B00880;
        func_00267658(p, 0x1000, D_01B00878->w10[2], 1);
        p->pos[0] = -189.7202606f;
        p->pos[1] = -66.0f;
        p->pos[2] = -22.80844879f;
        p->pos[3] = 1.0f;
        p->rot[0] = 0;
        p->rot[1] = 0;
        p->rot[2] = 0;
        p->rot[3] = 1;
        p->scale[2] = p->scale[1] = p->scale[0] = 0.295498997f;
        p->scale[3] = 1.0f;
    } else if (idx == 1) {
        D_006A3924 = D_01B00880;
        func_00267658(p, 0x1000, D_01B00878->w10[3], 1);
        p->pos[0] = -119.7202606f;
        p->pos[1] = -42.0f;
        p->pos[2] = 26.19155121f;
        p->pos[3] = 1.0f;
        p->rot[0] = 0;
        p->rot[1] = 0;
        p->rot[2] = 0;
        p->rot[3] = 1;
        p->scale[2] = p->scale[1] = p->scale[0] = 0.5804989934f;
        p->scale[3] = 1.0f;
    } else if (idx == 2) {
        D_006A3924 = D_01B00880;
        func_00267658(p, 0x1000, D_01B00878->w10[4], 1);
        p->pos[0] = -175.7202606f;
        p->pos[1] = -67.0f;
        p->pos[2] = 48.19155121f;
        p->pos[3] = 1.0f;
        p->rot[0] = 0;
        p->rot[1] = 0;
        p->rot[2] = 0;
        p->rot[3] = 1;
        p->scale[2] = p->scale[1] = p->scale[0] = 0.5804989934f;
        p->scale[3] = 1.0f;
    }
}
