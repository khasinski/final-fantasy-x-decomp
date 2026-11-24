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
extern int D_01B01058;
extern char D_01B03FF8[];

extern void *D_006A3924;
extern u8 D_006A3930;
extern u8 D_006A3970;
extern u8 D_006A39B0;
extern u8 D_006A3A70;
extern u8 D_006A3AB0;

extern int func_01B03408(char *, ...);
extern int func_0014AA50(int);
extern void func_002675B0(void *);
extern void func_00267658(void *, int, int, int);
extern int func_00267FA0(void *, int);
extern void func_002DCE38(void *, void *, void *);

void func_01B014B0(PppObj *p)
{
    func_01B03408(D_01B03FF8, D_01B01058);
    D_006A3924 = &D_01B007E8;
    func_00267658(p, 0x1000, D_01B007E0->w10[9], 1);
    p->pos[0] = 11.0f;
    p->pos[1] = -15.5f;
    p->pos[2] = 1.0f;
    p->pos[3] = 1.0f;
    p->rot[0] = 0;
    p->rot[1] = 0x7C00;
    p->rot[2] = 0;
    p->rot[3] = 1;
    p->scale[2] = p->scale[1] = p->scale[0] = 0.08449500054f;
    p->scale[3] = 1.0f;
}

int func_01B01570(PppObj *p)
{
    func_002675B0(p);
    func_002DCE38(&D_006A39B0, &D_006A3970, &D_006A3930);
    func_002DCE38(&D_006A3AB0, &D_006A3A70, &D_006A39B0);
    D_006A3924 = &D_01B007E8;
    if (func_00267FA0(p, 0x30) != 0) {
        return 0;
    }
    return func_0014AA50(1) == 0;
}
