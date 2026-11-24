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
} TtPart;

extern void *D_006A3924;
extern TtCfg *D_01B00878;
extern u8 D_01B00880[];
extern int D_01B01258;
extern char D_01B04648[];

int func_01B03858(char *, ...);
void func_00267658(void *, int, int, int);

int func_01B03168(TtPart *p)
{
    func_01B03858(D_01B04648, D_01B01258);
    D_006A3924 = D_01B00880;
    func_00267658(p, 0x1000, D_01B00878->w10[0], 1);
    p->scale[2] = p->scale[1] = p->scale[0] = 0.295498997f;
    p->scale[3] = 1.0f;
    p->pos[0] = -163.7202606f;
    p->pos[1] = -66.0f;
    p->pos[2] = -47.80844879f;
    p->pos[3] = 1.0f;
    p->rot[0] = 0;
    p->rot[1] = 0;
    p->rot[2] = 0;
    p->rot[3] = 1;
    return 1;
}
