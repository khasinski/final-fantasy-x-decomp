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

extern TtCfg *D_01B007E0;
extern u8 D_01B007E8;
extern PppObj D_01B00AA0[];
extern int D_01B01058;
extern char D_01B04168[];

extern void *D_006A3924;

extern int func_01B03408(char *, ...);
extern void func_00267658(void *, int, int, int);

void func_01B02708(PppObj *p)
{
    func_01B03408(D_01B04168, D_01B01058);
    D_006A3924 = &D_01B007E8;
    func_00267658(p, 0x1000, D_01B007E0->w10[1], 1);
    if (p - D_01B00AA0 == 0) {
        p->pos[0] = 10.0f;
        p->pos[1] = -14.99999142f;
        p->pos[2] = 73.0f;
        p->pos[3] = 1.0f;
        p->rot[0] = 0;
        p->rot[1] = 0;
        p->rot[2] = 0;
        p->rot[3] = 1;
        p->scale[2] = p->scale[1] = p->scale[0] = 0.01549699996f;
        p->scale[3] = 1.0f;
    } else if (p - D_01B00AA0 == 1) {
        p->pos[0] = 4.0f;
        p->pos[1] = -14.99999142f;
        p->pos[2] = 54.0f;
        p->pos[3] = 1.0f;
        p->rot[0] = 0;
        p->rot[1] = 0;
        p->rot[2] = 0;
        p->rot[3] = 1;
        p->scale[2] = p->scale[1] = p->scale[0] = 0.02749699913f;
        p->scale[3] = 1.0f;
    } else if (p - D_01B00AA0 == 2) {
        p->pos[0] = -3.900002003f;
        p->pos[1] = -15.09998035f;
        p->pos[2] = 9.599928856f;
        p->pos[3] = 1.0f;
        p->rot[0] = 0;
        p->rot[1] = -0x5000;
        p->rot[2] = 0;
        p->rot[3] = 1;
        p->scale[2] = p->scale[1] = p->scale[0] = 0.03449700028f;
        p->scale[3] = 1.0f;
    } else if (p - D_01B00AA0 == 3) {
        goto case34;
    } else if (p - D_01B00AA0 == 4) {
    case34:
        p->pos[0] = 11.09999466f;
        p->pos[1] = -15.09998035f;
        p->pos[2] = 20.29986572f;
        p->pos[3] = 1.0f;
        p->rot[0] = 0;
        p->rot[1] = 0;
        p->rot[2] = 0;
        p->rot[3] = 1;
        p->scale[2] = p->scale[1] = p->scale[0] = 0.03749699891f;
        p->scale[3] = 1.0f;
    }
}
