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

typedef struct {
    int active;
    u8 pad04[0xC];
    float pos[4];
    float vel[4];
    u8 pad30[4];
    int life;
    u8 pad38[0x38];
    float scale;
    float rot;
    u8 pad78[0xC];
    float alpha;
    u8 pad88[0x38];
} PartItem;

typedef struct {
    int count;
    PartItem *items;
} PartPool;

extern float D_01B004F0[];
extern int D_01B00588[];
extern int D_01B00594;
extern void *D_01B00598;
extern void *D_01B005A8;
extern TtCfg *D_01B005B0;
extern u8 D_01B005B8;
extern PppObj D_01B00770[];
extern void *D_01B00C00;
extern u8 D_01B00C10;
extern void *D_01B00C40;
extern PartPool D_01B00C50;
extern char D_01B028C8[];
extern double D_01B028D8;
extern char D_01B028E0[];
extern char D_01B028F8[];

extern void *D_006A3924;

extern int func_01B01CA8(char *, ...);
extern void func_01B02238(void *, void *, int);
extern void func_01B022B0(void *);
extern PartItem *func_01B023E8(void *, void *);
extern void *func_01B02448(void *, void *, void *, float);
extern void func_01B02520(void *, int, float, float);
extern void func_00107428(int, int, int, void *);
extern void func_00267658(void *, int, int, int);
extern void *func_002B49A0(void *, int, int);
extern float func_002D56C0(float);
extern int func_002EFD78(void);

void func_01B00E68(void *a0, void *a1, float *a2)
{
    PartItem *p;

    p = func_01B023E8(a0, a1);
    if (p == 0) {
        func_01B01CA8(D_01B028C8);
        return;
    }
    p->life = 0x20;
    p->pos[0] = a2[0] + (((float)(func_002EFD78() & 0x7FFF) / 32767.0f) - 0.5f) * 2.0f * 7.0f;
    p->pos[1] = a2[1] + (((float)(func_002EFD78() & 0x7FFF) / 32767.0f) - 0.5f) * 2.0f * 7.0f;
    p->pos[2] = a2[2] + (((float)(func_002EFD78() & 0x7FFF) / 32767.0f) - 0.5f) * 2.0f * 7.0f;
    p->vel[0] = (((float)(func_002EFD78() & 0x7FFF) / 32767.0f) - 0.5f) * 2.0f * 0.5f;
    p->vel[1] = (((float)(func_002EFD78() & 0x7FFF) / 32767.0f) - 0.5f) * 2.0f * 0.5f;
    p->vel[2] = (((float)(func_002EFD78() & 0x7FFF) / 32767.0f) - 0.5f) * 2.0f * 0.5f;
    p->rot = func_002D56C0(((float)(func_002EFD78() & 0x7FFF) / 32767.0f) * 360.0f);
    p->scale = ((float)(func_002EFD78() & 0x7FFF) / 32767.0f) * 0.015;
}

int func_01B01090(int idx)
{
    float pos[4];
    int i;

    func_00107428(D_01B00588[idx], 0x39, 0, pos);
    for (i = 0; i < 5; i++) {
        func_01B00E68(&D_01B00C50, D_01B00C00, pos);
    }
    return 1;
}

int func_01B01110(void)
{
    func_01B01CA8(D_01B028E0, D_01B00594);
    D_01B00C00 = func_002B49A0(D_01B00598, 4, 0);
    func_01B02238(&D_01B00C50, D_01B00C40, 1000);
    func_01B02520(&D_01B00C50, 0, 0.0250000004f, 0.0f);
    return 1;
}

int func_01B01198(void)
{
    int i;
    PartItem *item = D_01B00C50.items;
    void *tmp;

    for (i = 0; i < D_01B00C50.count; i++, item++) {
        if (item->active != 0) {
            item->alpha = D_01B004F0[0x20 - item->life] * 0.5f;
        }
    }
    func_01B022B0(&D_01B00C50);
    tmp = D_01B005A8;
    D_01B005A8 = func_01B02448(&D_01B00C50, &D_01B00C10, tmp, 0.0f);
    return 1;
}

int func_01B01270(PppObj *p)
{
    int idx = p - D_01B00770;

    func_01B01CA8(D_01B028F8, D_01B00594);
    D_006A3924 = &D_01B005B8;
    func_00267658(p, 0x1000, D_01B005B0->w10[0], 1);
    if (idx == 0) {
        p->pos[0] = -3.63757491f;
        p->pos[1] = -120.724068f;
        p->pos[2] = -26.2202148f;
        p->pos[3] = 1.0f;
        p->scale[2] = p->scale[1] = p->scale[0] = 0.075000003f;
        p->scale[3] = 1.0f;
    } else if (idx == 1) {
        p->pos[0] = -59.2131729f;
        p->pos[1] = -120.624008f;
        p->pos[2] = -33.7565346f;
        p->pos[3] = 1.0f;
        p->scale[2] = p->scale[1] = p->scale[0] = 0.075000003f;
        p->scale[3] = 1.0f;
    } else if (idx == 2) {
        p->pos[0] = -34.6952019f;
        p->pos[1] = -121.432281f;
        p->pos[2] = -33.9010849f;
        p->pos[3] = 1.0f;
        p->scale[2] = p->scale[1] = p->scale[0] = 0.0489999987f;
        p->scale[3] = 1.0f;
    }
    p->rot[0] = 0;
    p->rot[1] = 0;
    p->rot[2] = 0;
    p->rot[3] = 1;
    return 1;
}
