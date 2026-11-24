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

extern float D_01B007D4;
extern TtCfg *D_01B00800;
extern u8 D_01B00808;
extern int D_01B012C0;
extern int D_01B012C8;
extern char D_01B04D90[];

extern void *D_006A3924;
extern u8 D_006A3930;
extern u8 D_006A3970;
extern u8 D_006A39B0;
extern u8 D_006A3A70;
extern u8 D_006A3AB0;

extern void func_01B03508(int, int, void *);
extern void func_01B03608(void *, float);
extern void func_01B03698(void *, void *);
extern int func_01B03970(char *, ...);
extern void func_01B04860(void *, float);
extern void func_00267658(void *, int, int, int);
extern int func_00267FA0(void *, int);
extern void func_002DCE38(void *, void *, void *);
extern void func_002DD0B0(void *, void *);
extern void func_002DD0C0(void *, void *);
extern void func_002DD998(void *, void *, float);

int func_01B02F00(PppObj *p)
{
    func_01B03970(D_01B04D90, D_01B012C0);
    D_006A3924 = &D_01B00808;
    func_00267658(p, 0x1000, D_01B00800->w10[4], 1);
    p->pos[0] = 0.0f;
    p->pos[1] = 0.0f;
    p->pos[2] = 0.0f;
    p->pos[3] = 1.0f;
    p->rot[0] = 0;
    p->rot[1] = 0;
    p->rot[2] = 0;
    p->rot[3] = 1;
    p->scale[2] = p->scale[1] = p->scale[0] = 0.1059499979f;
    p->scale[3] = 1.0f;
    return 1;
}

int func_01B02FB0(PppObj *p)
{
    float m0[4][4];
    float m1[4][4];
    float m2[4][4];
    float v0[4];

    func_01B03508(D_01B012C8, 6, m1);
    func_002DD0B0(v0, m1[1]);
    v0[1] = 0.0f;
    func_002DD998(v0, v0, 1.0f);
    func_01B03698(m0, v0);
    func_002DD0B0(m0[3], m1[3]);
    m0[3][1] = D_01B007D4;
    func_01B04860(m0, 20.0f);
    func_01B03608(m2, p->scale[0]);
    func_002DCE38(m0, m0, m2);
    func_002DD0C0(&D_006A3930, m0);
    func_002DCE38(&D_006A39B0, &D_006A3970, &D_006A3930);
    func_002DCE38(&D_006A3AB0, &D_006A3A70, &D_006A39B0);
    D_006A3924 = &D_01B00808;
    return func_00267FA0(p, 0x30) == 0;
}
