/* Battle-effect overlay 09705: 0x01B02C58..0x01B02D3C */
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
extern float D_01B007D0[][4];
extern TtCfg *D_01B01064;
extern u8 D_01B01068[];
extern int D_01B012A0;
extern char D_01B03B28[];
extern char D_01B03BE0[];

void func_00267658(PppObj *, int, int, int);
void func_002DD0B0(float *, float *);
int func_01B02240(void);
int func_01B03748(char *, ...);
void func_01B03778(char *);

int func_01B02C58(PppObj *p)
{
    int slot;

    func_01B03748(D_01B03BE0, D_01B012A0);
    D_006A3924 = D_01B01068;
    func_00267658(p, 0x1000, D_01B01064->w10[1], 1);
    slot = func_01B02240();
    if (slot == -1) {
        func_01B03778(D_01B03B28);
    }
    func_002DD0B0(p->pos, D_01B007D0[slot]);
    p->rot[0] = 0;
    p->rot[1] = 0;
    p->rot[2] = 0;
    p->rot[3] = 1;
    p->scale[2] = p->scale[1] = p->scale[0] = 0.127597004f;
    p->scale[3] = 1.0f;
    return 1;
}
