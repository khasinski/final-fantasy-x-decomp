#include "common.h"

typedef struct {
    u8 pad00[0x10];
    int *w10;
    float *w14;
    s16 *w18;
    char *w1c;
} TtCfg;

typedef struct {
    u8 pad00[0x20];
    float *w20;
    s16 *w24;
    char *w28;
} TtHeap;

typedef struct {
    u8 pad00[0x40];
    float pos[4];
    s32 rot[4];
    float scale[4];
    u8 pad70[0x10];
} PppObj;

typedef struct {
    u8 pad00[0x10];
    float pos[4];
    u8 pad20[0x10];
    int max_life;
    int life;
    int flags;
    u8 pad3c[0x34];
    float scale;
    float rot;
} PartItem;

extern TtCfg *D_01B004BC;
extern TtHeap D_01B004C0;
extern PppObj D_01B004F0;
extern int D_01B051A4;
extern float D_01B053D0[4];
extern char D_01B07008[];

extern void *D_006A3924;
extern u8 D_006A3930;
extern u8 D_006A3970;
extern u8 D_006A39B0;
extern u8 D_006A3A70;
extern u8 D_006A3AB0;

extern int func_01B063F0(char *, ...);
extern PartItem *func_01B06B48(void *, void *);
extern void func_001A9EE0(void *);
extern void func_001AACA0(void *);
extern void func_002675B0(void *);
extern void func_00267658(void *, int, int, int);
extern int func_00267FA0(void *, int);
extern float func_002D56C0(float);
extern void func_002DCE38(void *, void *, void *);
extern int func_002EFD78(void);

int func_01B053F8(void)
{
    return 1;
}

void func_01B05400(void *a0, void *a1, float *a2)
{
    PartItem *p;

    p = func_01B06B48(a0, a1);
    if (p == 0) {
        return;
    }
    p->life = 0x14;
    p->max_life = 0x14;
    p->flags = 2;
    p->pos[0] = a2[0] + (((float)(func_002EFD78() & 0x7FFF) / 32767.0f) - 0.5f) * 2.0f * 1.70000005f;
    p->pos[1] = a2[1] + (((float)(func_002EFD78() & 0x7FFF) / 32767.0f) - 0.5f) * 2.0f * 1.70000005f;
    p->pos[2] = a2[2] + (((float)(func_002EFD78() & 0x7FFF) / 32767.0f) - 0.5f) * 2.0f * 1.70000005f;
    p->rot = func_002D56C0(((float)(func_002EFD78() & 0x7FFF) / 32767.0f) * 360.0f);
    p->scale = ((float)(func_002EFD78() & 0x7FFF) / 32767.0f) * 0.0625f * 0.100000001f;
}

void func_01B05588(void)
{
    func_01B063F0(D_01B07008, D_01B051A4);
    D_006A3924 = &D_01B004C0;
    func_00267658(&D_01B004F0, 0x1000, D_01B004BC->w10[0], 1);
    D_01B004F0.pos[0] = 0.0f;
    D_01B004F0.pos[1] = 0.0f;
    D_01B004F0.pos[2] = 0.0f;
    D_01B004F0.pos[3] = 1.0f;
    D_01B004F0.rot[0] = 0;
    D_01B004F0.rot[1] = 0;
    D_01B004F0.rot[2] = 0;
    D_01B004F0.rot[3] = 1;
    D_01B004F0.scale[0] = 0.0187500007f;
    D_01B004F0.scale[1] = 0.0187500007f;
    D_01B004F0.scale[2] = 0.0187500007f;
    D_01B004F0.scale[3] = 1.0f;
    D_01B053D0[0] = 0.0f;
    D_01B053D0[1] = -503.5f;
    D_01B053D0[2] = 0.0f;
    D_01B053D0[3] = 1.0f;
}

int func_01B05660(void)
{
    D_006A3924 = &D_01B004C0;
    D_01B004C0.w20 = D_01B004BC->w14;
    D_01B004C0.w24 = D_01B004BC->w18;
    D_01B004C0.w28 = D_01B004BC->w1c;
    func_001AACA0(&D_006A3A70);
    func_001A9EE0(&D_006A3970);
    D_01B004F0.pos[0] = D_01B053D0[0];
    D_01B004F0.pos[1] = D_01B053D0[1];
    D_01B004F0.pos[2] = D_01B053D0[2];
    func_002675B0(&D_01B004F0);
    func_002DCE38(&D_006A39B0, &D_006A3970, &D_006A3930);
    func_002DCE38(&D_006A3AB0, &D_006A3A70, &D_006A39B0);
    D_006A3924 = &D_01B004C0;
    func_00267FA0(&D_01B004F0, 0x30);
    return 1;
}
