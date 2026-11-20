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

extern int D_01B00C30;
extern int D_01B00C34;
extern float D_01B00634;
extern TtCfg *D_01B00670;
extern u8 D_01B00678;
extern PppObj D_01B00830[];
extern char D_01B02850[];

extern void *D_006A3924;
extern u8 D_006A3930;
extern u8 D_006A3970;
extern u8 D_006A39B0;
extern u8 D_006A3A70;
extern u8 D_006A3AB0;

extern void func_01B01FC8(int, int, void *);
extern void func_01B020C8(void *, float);
extern void func_01B02158(void *, void *);
extern int func_01B02430(char *, ...);
extern void func_00267658(void *, int, int, int);
extern int func_00267FA0(void *, int);
extern void func_002DCE38(void *, void *, void *);
extern void func_002DD0B0(void *, void *);
extern void func_002DD0C0(void *, void *);

int func_01B015A8(PppObj *p)
{
    int idx;

    func_01B02430(D_01B02850, D_01B00C30);
    idx = p - D_01B00830;
    D_006A3924 = &D_01B00678;
    func_00267658(p, 0x1000, D_01B00670->w10[4], 1);
    if (idx == 0) {
        p->pos[0] = 78.0f;
        p->pos[1] = 0.0f;
        p->pos[2] = 7.0f;
        p->pos[3] = 0.0f;
    } else {
        p->pos[0] = 85.0f;
        p->pos[1] = 0.0f;
        p->pos[2] = 8.0f;
        p->pos[3] = 1.0f;
    }
    p->rot[0] = 0;
    p->rot[1] = 0;
    p->rot[2] = 0;
    p->rot[3] = 1;
    p->scale[2] = p->scale[1] = p->scale[0] = 0.157597005f;
    p->scale[3] = 1.0f;
    return 1;
}

int func_01B016B8(PppObj *p)
{
    float m0[4][4];
    float m1[4][4];
    float m2[4][4];
    float v0[4];

    if (p - D_01B00830 == 0) {
        func_01B01FC8(D_01B00C34, 0xBA, m1);
    } else {
        func_01B01FC8(D_01B00C34, 0xBE, m1);
    }
    func_002DD0B0(v0, m1[0]);
    v0[1] = 0.0f;
    func_01B02158(m0, v0);
    func_002DD0B0(m0[3], m1[3]);
    m0[3][1] = D_01B00634;
    func_01B020C8(m2, p->scale[0]);
    func_002DCE38(m0, m0, m2);
    func_002DD0C0(&D_006A3930, m0);
    func_002DCE38(&D_006A39B0, &D_006A3970, &D_006A3930);
    func_002DCE38(&D_006A3AB0, &D_006A3A70, &D_006A39B0);
    D_006A3924 = &D_01B00678;
    return func_00267FA0(p, 0x30) == 0;
}
