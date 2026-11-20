/* Battle-effect overlay 09705: 0x01B02A10..0x01B02B7C */
#include "common.h"

typedef struct PppObj {
    u8 pad00[0x40];
    float pos[4];
    s32 rot[4];
    float scale[4];
    u8 pad70[0x10];
} PppObj;

typedef struct TtCfg {
    u8 pad00[0x10];
    int *w10;
} TtCfg;

extern void *D_006A3924;
extern float D_01B008B0[][4];
extern float D_01B00990[][4];
extern TtCfg *D_01B01064;
extern u8 D_01B01068[];
extern PppObj D_01B011A0[];
extern int D_01B012A0;
extern char D_01B03B28[];
extern char D_01B03BB0[];

void func_00267658(PppObj *, int, int, int);
void func_002DD0B0(float *, float *);
int func_01B02240(void);
int func_01B03748(char *, ...);
void func_01B03778(char *);

int func_01B02A10(PppObj *p)
{
    int idx;
    int slot;

    func_01B03748(D_01B03BB0, D_01B012A0);
    idx = p - D_01B011A0;
    D_006A3924 = D_01B01068;
    func_00267658(p, 0x1000, D_01B01064->w10[2], 1);
    slot = func_01B02240();
    if (slot == -1) {
        func_01B03778(D_01B03B28);
    }
    if (idx == 0) {
        func_002DD0B0(p->pos, D_01B008B0[slot]);
    } else {
        func_002DD0B0(p->pos, D_01B00990[slot]);
    }
    if ((u32)(slot - 2) < 4) {
        p->rot[0] = 0;
        p->rot[1] = 0;
        p->rot[2] = -0x4000;
        p->rot[3] = 1;
    } else if ((u32)(slot - 12) < 2) {
        p->rot[0] = 0;
        p->rot[1] = 0x4718;
        p->rot[2] = 0x4718;
        p->rot[3] = 1;
    } else {
        p->rot[0] = 0;
        p->rot[1] = 0;
        p->rot[2] = 0;
        p->rot[3] = 1;
    }
    p->scale[2] = p->scale[1] = p->scale[0] = 0.127597004f;
    p->scale[3] = 1.0f;
    return 1;
}
