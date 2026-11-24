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
extern TtPart D_01B009B0[];
extern int D_01B01258;
extern char D_01B04528[];

int func_01B03858(char *, ...);
void func_00267658(void *, int, int, int);

int func_01B020C0(TtPart *p)
{
    int idx = p - D_01B009B0;

    func_01B03858(D_01B04528, D_01B01258);
    if (idx == 0) {
        D_006A3924 = D_01B00880;
        func_00267658(p, 0x1000, D_01B00878->w10[6], 1);
        p->pos[0] = -29.72026062f;
        p->pos[1] = -164.0f;
        p->pos[2] = 20.19155121f;
        p->pos[3] = 1.0f;
        p->rot[0] = 0;
        p->rot[1] = 0;
        p->rot[2] = 0;
        p->rot[3] = 1;
        p->scale[2] = p->scale[1] = p->scale[0] = 0.1564950049f;
        p->scale[3] = 1.0f;
    } else if (idx == 1) {
        D_006A3924 = D_01B00880;
        func_00267658(p, 0x1000, D_01B00878->w10[10], 1);
        p->pos[0] = -1.720260978f;
        p->pos[1] = -122.0f;
        p->pos[2] = 44.19155121f;
        p->pos[3] = 1.0f;
        p->rot[0] = 0;
        p->rot[1] = 0x5000;
        p->rot[2] = 0;
        p->rot[3] = 1;
        p->scale[2] = p->scale[1] = p->scale[0] = 0.1014939994f;
        p->scale[3] = 1.0f;
    }
    return 1;
}
