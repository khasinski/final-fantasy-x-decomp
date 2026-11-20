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
    u8 pad20[0x14];
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

typedef struct {
    u16 h00;
    u16 h02;
    u32 w04;
    u8 pad08[0x28];
} SprParam;

extern float D_01B004A0[];
extern int D_01B004F0[];
extern int D_01B00504;
extern void *D_01B00508;
extern void *D_01B00518;
extern TtCfg *D_01B00520;
extern u8 D_01B00528;
extern PppObj D_01B00560[];
extern void *D_01B008F0;
extern SprParam D_01B00900;
extern void *D_01B00930;
extern PartPool D_01B00940;
extern char D_01B01F70[];
extern char D_01B01F80[];
extern char D_01B01F98[];
extern char D_01B01FB0[];

extern void *D_006A3924;
extern u8 D_006A3930;
extern u8 D_006A3970;
extern u8 D_006A39B0;
extern u8 D_006A3A70;
extern u8 D_006A3AB0;

extern int func_01B01380(char *, ...);
extern void func_01B01910(void *, void *, int);
extern void func_01B01988(void *);
extern PartItem *func_01B01AC0(void *, void *);
extern void *func_01B01B20(void *, void *, void *, float);
extern void func_01B01BF8(void *, int, float, float);
extern void func_00107378(int, void *);
extern void func_00267530(void *);
extern void func_002675B0(void *);
extern void func_00267658(void *, int, int, int);
extern int func_00267FA0(void *, int);
extern void *func_002B49A0(void *, int, int);
extern float func_002D56C0(float);
extern void func_002DCE38(void *, void *, void *);
extern void func_002DD128(void *);
extern void *func_002EF0D0(void *, int, int);
extern int func_002EFD78(void);

void func_01B009B8(void *a0, void *a1, float *a2)
{
    PartItem *p;

    p = func_01B01AC0(a0, a1);
    if (p == 0) {
        func_01B01380(D_01B01F70);
        return;
    }
    p->life = 0x10;
    p->pos[0] = a2[0] + (((float)(func_002EFD78() & 0x7FFF) / 32767.0f) - 0.5f) * 2.0f * 7.0f;
    p->pos[1] = a2[1] + (((float)(func_002EFD78() & 0x7FFF) / 32767.0f) - 0.5f) * 2.0f * 7.0f;
    p->pos[2] = a2[2] + (((float)(func_002EFD78() & 0x7FFF) / 32767.0f) - 0.5f) * 2.0f * 7.0f;
    p->rot = func_002D56C0(((float)(func_002EFD78() & 0x7FFF) / 32767.0f) * 360.0f);
    p->scale = ((float)(func_002EFD78() & 0x7FFF) / 32767.0f) * 0.0625f;
}

int func_01B00B48(void)
{
    func_01B01380(D_01B01F80);
    D_01B008F0 = func_002B49A0(D_01B00508, 4, 0);
    func_002EF0D0(&D_01B00900, 0, 0x30);
    D_01B00900.w04 = 0x80808080;
    D_01B00900.h02 = 0x80;
    func_01B01910(&D_01B00940, D_01B00930, 1000);
    func_01B01BF8(&D_01B00940, 0, 0.0f, 0.0f);
    return 1;
}

int func_01B00BF8(void)
{
    float m[4][4];
    int i;
    int j;
    PartItem *item;

    for (i = 0; i < 5; i++) {
        func_00107378(D_01B004F0[i], m);
        for (j = 0; j < 10; j++) {
            func_01B009B8(&D_01B00940, D_01B008F0, m[3]);
        }
    }
    item = D_01B00940.items;
    for (i = 0; i < D_01B00940.count; i++, item++) {
        if (item->active != 0) {
            item->alpha = D_01B004A0[0x10 - item->life];
        }
    }
    func_01B01988(&D_01B00940);
    D_01B00518 = func_01B01B20(&D_01B00940, &D_01B00900, D_01B00518, 0.0f);
    return 1;
}

int func_01B00D28(void)
{
    func_01B01380(D_01B01F98);
    return 1;
}

int func_01B00D50(PppObj *p)
{
    D_006A3924 = &D_01B00528;
    func_00267658(p, 0x1000, D_01B00520->w10[1], 1);
    p->pos[0] = 0.0f;
    p->pos[1] = 0.0f;
    p->pos[2] = 0.0f;
    p->pos[3] = 1.0f;
    p->rot[0] = 0;
    p->rot[1] = 0;
    p->rot[2] = 0;
    p->rot[3] = 1;
    p->scale[2] = p->scale[1] = p->scale[0] = 0.0625f;
    p->scale[3] = 1.0f;
    return 1;
}

int func_01B00DE8(PppObj *p, void *m)
{
    func_002675B0(p);
    func_002DCE38(&D_006A3930, m, &D_006A3930);
    func_002DCE38(&D_006A39B0, &D_006A3970, &D_006A3930);
    func_002DCE38(&D_006A3AB0, &D_006A3A70, &D_006A39B0);
    D_006A3924 = &D_01B00528;
    return func_00267FA0(p, 0x30) == 0;
}

int func_01B00E90(PppObj *p)
{
    float m0[4][4];
    float m1[4][4];

    func_00107378(D_01B004F0[p - D_01B00560], m0);
    func_002DD128(m1);
    m1[0][0] = m1[1][1] = m1[2][2] = 100.0f;
    func_002DCE38(m0, m0, m1);
    return func_01B00DE8(p, m0);
}

int func_01B00F20(PppObj *p)
{
    func_01B01380(D_01B01FB0, D_01B00504);
    D_006A3924 = &D_01B00528;
    func_00267530(p);
    return 1;
}
