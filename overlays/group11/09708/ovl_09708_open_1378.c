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
extern int D_01B00C38;
extern float D_01B0063C;
extern float D_01B00640;
extern TtCfg *D_01B00670;
extern u8 D_01B00678;
extern PppObj D_01B00930[];
extern char D_01B02820[];

extern void *D_006A3924;
extern u8 D_006A3930;
extern u8 D_006A3970;
extern u8 D_006A39B0;
extern u8 D_006A3A70;
extern u8 D_006A3AB0;

extern void func_01B00E68(void *, int, float, float);
extern int func_01B02430(char *, ...);
extern void func_00267530(void *);
extern void func_00267658(void *, int, int, int);
extern int func_00267FA0(void *, int);
extern void func_002DCE38(void *, void *, void *);
extern void func_002DD0C0(void *, void *);

int func_01B01378(PppObj *p)
{
    func_01B02430(D_01B02820, D_01B00C30);
    D_006A3924 = &D_01B00678;
    func_00267658(p, 0x1000, D_01B00670->w10[5], 1);
    p->pos[0] = 0.0f;
    p->pos[1] = 0.0f;
    p->pos[2] = 0.0f;
    p->pos[3] = 1.0f;
    p->rot[0] = 0;
    p->rot[1] = 0;
    p->rot[2] = 0;
    p->rot[3] = 1;
    p->scale[2] = p->scale[1] = p->scale[0] = 0.0599999987f;
    p->scale[3] = 1.0f;
    return 1;
}

int func_01B01428(PppObj *p)
{
    float m[4][4];

    if (p - D_01B00930 == 0) {
        func_01B00E68(m, D_01B00C34, D_01B0063C, p->scale[0]);
    } else {
        func_01B00E68(m, D_01B00C38, D_01B00640, p->scale[0]);
    }
    func_002DD0C0(&D_006A3930, m);
    func_002DCE38(&D_006A39B0, &D_006A3970, &D_006A3930);
    func_002DCE38(&D_006A3AB0, &D_006A3A70, &D_006A39B0);
    D_006A3924 = &D_01B00678;
    if (func_00267FA0(p, 0x30) != 0) {
        D_006A3924 = &D_01B00678;
        func_00267530(p);
        D_006A3924 = &D_01B00678;
        func_00267658(p, 0x1000, D_01B00670->w10[5], 1);
    }
    return 1;
}
