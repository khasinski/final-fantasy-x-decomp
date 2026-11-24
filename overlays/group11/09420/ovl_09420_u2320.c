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
extern char D_01B04550[];

int func_01B03858(char *, ...);
void func_00267658(void *, int, int, int);

int func_01B02320(TtPart *p)
{
    func_01B03858(D_01B04550, D_01B01258);
    D_006A3924 = D_01B00880;
    func_00267658(p, 0x1000, D_01B00878->w10[11], 1);
    p->pos[0] = -31.72026062f;
    p->pos[1] = -69.0f;
    p->pos[2] = -57.80844879f;
    p->pos[3] = 1.0f;
    p->rot[0] = 0;
    p->rot[1] = -0x3400;
    p->rot[2] = 0;
    p->rot[3] = 1;
    p->scale[2] = p->scale[1] = p->scale[0] = 0.06949499995f;
    p->scale[3] = 1.0f;
    return 1;
}
