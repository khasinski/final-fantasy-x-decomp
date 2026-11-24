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
extern PppObj D_01B00DA0[];
extern int D_01B01058;
extern char D_01B04138[];

extern void *D_006A3924;

extern int func_01B03408(char *, ...);
extern void func_00267658(void *, int, int, int);

void func_01B024F0(PppObj *p)
{
    int idx;

    func_01B03408(D_01B04138, D_01B01058);
    D_006A3924 = &D_01B007E8;
    func_00267658(p, 0x1000, D_01B007E0->w10[0], 1);
    idx = p - D_01B00DA0;
    if (idx == 0) {
        p->pos[0] = 12.0f;
        p->pos[1] = -11.5f;
        p->pos[2] = 34.0f;
        p->pos[3] = 1.0f;
        p->rot[0] = 0;
        p->rot[1] = 0;
        p->rot[2] = 0;
        p->rot[3] = 1;
        p->scale[2] = p->scale[1] = p->scale[0] = 0.06849700212f;
        p->scale[3] = 1.0f;
    } else if (idx == 1) {
        p->pos[0] = -9.0f;
        p->pos[1] = -12.5f;
        p->pos[2] = -26.0f;
        p->pos[3] = 1.0f;
        p->rot[0] = 0;
        p->rot[1] = 0;
        p->rot[2] = 0;
        p->rot[3] = 1;
        p->scale[2] = p->scale[1] = p->scale[0] = 0.06849700212f;
        p->scale[3] = 1.0f;
    }
}
