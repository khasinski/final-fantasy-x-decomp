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

extern TtCfg *D_01B006C8;
extern u8 D_01B006D0;
extern PppObj D_01B00700[];
extern int D_01B00DA0;
extern int D_01B00E60;
extern char D_01B03858[];

extern void *D_006A3924;

extern int func_01B02BC0(char *, ...);
extern void func_00107428(int, int, int, float *);
extern void func_00267658(void *, int, int, int);

int func_01B02250(PppObj *p)
{
    func_01B02BC0(D_01B03858, D_01B00E60);
    D_006A3924 = &D_01B006D0;
    func_00267658(p, 0x1000, D_01B006C8->w10[4], 1);
    p->pos[0] = 0.0f;
    p->pos[1] = 0.0f;
    p->pos[2] = 0.0f;
    p->pos[3] = 1.0f;
    p->rot[0] = 0;
    p->rot[1] = 0;
    p->rot[2] = 0;
    p->rot[3] = 1;
    p->scale[2] = p->scale[1] = p->scale[0] = 0.1724999994f;
    p->scale[3] = 1.0f;
    func_00107428(D_01B00DA0, 0x25, 0, p->pos);
    switch (p - D_01B00700) {
    case 0:
        break;
    case 1:
        p->pos[0] = -19.43784142f;
        p->pos[1] = -106.4545898f;
        p->pos[2] = -119.1160812f;
        p->pos[3] = 1.0f;
        break;
    case 2:
        p->pos[0] = -19.43784142f;
        p->pos[1] = -106.4545898f;
        p->pos[2] = -126.1160736f;
        p->pos[3] = 1.0f;
        break;
    case 3:
        p->pos[0] = -18.74062538f;
        p->pos[1] = -107.749321f;
        p->pos[2] = -121.3746033f;
        p->pos[3] = 1.0f;
        break;
    }
    return 1;
}
