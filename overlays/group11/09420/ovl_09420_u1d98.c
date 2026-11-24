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
extern TtPart D_01B00AB0[];
extern int D_01B01258;
extern char D_01B044F8[];

int func_01B03858(char *, ...);
void func_00267658(void *, int, int, int);
int func_002EFD78(void);

void func_01B01D98(TtPart *p)
{
    int idx = p - D_01B00AB0;

    func_01B03858(D_01B044F8, D_01B01258);
    if (idx == 0) {
        D_006A3924 = D_01B00880;
        func_00267658(p, 0x1000, D_01B00878->w10[7], 1);
        p->pos[0] = -37.05632782f;
        p->pos[1] = -122.0f;
        p->pos[2] = 55.41827393f;
        p->pos[3] = 1.0f;
    } else if (idx == 1) {
        D_006A3924 = D_01B00880;
        func_00267658(p, 0x1000, D_01B00878->w10[8], 1);
        p->pos[0] = 52.94366837f;
        p->pos[1] = -122.0f;
        p->pos[2] = 108.4182739f;
        p->pos[3] = 1.0f;
    } else if (idx == 2) {
        D_006A3924 = D_01B00880;
        func_00267658(p, 0x1000, D_01B00878->w10[9], 1);
        p->pos[0] = 44.94366837f;
        p->pos[1] = -122.0f;
        p->pos[2] = 53.41827393f;
        p->pos[3] = 1.0f;
    } else if (idx == 3) {
        D_006A3924 = D_01B00880;
        func_00267658(p, 0x1000, D_01B00878->w10[7], 1);
        p->pos[0] = 39.94366837f;
        p->pos[1] = -122.0f;
        p->pos[2] = 125.4182739f;
        p->pos[3] = 1.0f;
    }
    p->rot[0] = 0;
    p->rot[1] = 0;
    p->rot[2] = 0;
    p->rot[3] = 1;
    p->scale[2] = p->scale[1] = p->scale[0] = ((float)(func_002EFD78() & 0x7FFF) / 32767.0f) * 0.03f + 0.07f;
    p->scale[3] = 1.0f;
}
