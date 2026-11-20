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
    u8 pad00[0x10];
    float pos[4];
    float vel[4];
    int max_life;
    int life;
    u8 pad38[0x38];
    float scale;
    float rot;
    int rgb[3];
    float alpha;
} PartItem;

typedef struct {
    u16 h00;
    u16 h02;
    u8 pad04[0x2C];
} SprParam;

typedef struct {
    u8 pad00[0x70];
} PartPool70;

extern int D_01B00454;
extern int D_01B00458;
extern void *D_01B0045C;
extern void *D_01B0046C;
extern TtCfg *D_01B00474;
extern u8 D_01B00478;
extern PppObj D_01B004B0;
extern void *D_01B00A60[2];
extern SprParam D_01B00A70[2];
extern void *D_01B00AD0[2];
extern PartPool70 D_01B00AE0[2];
extern char D_01B02AC8[];
extern char D_01B02AD8[];
extern char D_01B02AF0[];
extern char D_01B02B08[];

extern void *D_006A3924;
extern u8 D_006A3930;
extern u8 D_006A3970;
extern u8 D_006A39B0;
extern u8 D_006A3A70;
extern u8 D_006A3AB0;

extern int func_01B01EB0(char *, ...);
extern void func_01B02440(void *, void *, int);
extern void func_01B024B8(void *);
extern PartItem *func_01B025F0(void *, void *);
extern void *func_01B02650(void *, void *, void *, float);
extern void func_01B02728(void *, float, float, int);
extern void func_00107428(int, int, int, void *);
extern int func_0014AA50(int);
extern void func_001A9EE0(void *);
extern void func_001AACA0(void *);
extern void func_00267530(void *);
extern void func_002675B0(void *);
extern void func_00267658(void *, int, int, int);
extern int func_00267FA0(void *, int);
extern void *func_002B49A0(void *, int, int);
extern float func_002D56C0(float);
extern void func_002DCE38(void *, void *, void *);
extern void *func_002EF0D0(void *, int, int);
extern int func_002EFD78(void);

void func_01B00E00(void *a0, void *a1, float *a2, int a3)
{
    PartItem *p;

    p = func_01B025F0(a0, a1);
    if (p == 0) {
        func_01B01EB0(D_01B02AC8);
        return;
    }
    p->life = 0x10;
    p->max_life = 0x10;
    p->pos[0] = a2[0];
    p->pos[1] = a2[1];
    p->pos[2] = a2[2];
    p->vel[0] = (((float)(func_002EFD78() & 0x7FFF) / 32767.0f) - 0.5f) * 2.0f * 0.75f;
    p->vel[1] = (((float)(func_002EFD78() & 0x7FFF) / 32767.0f) - 0.5f) * 2.0f * 0.75f;
    p->vel[2] = (((float)(func_002EFD78() & 0x7FFF) / 32767.0f) - 0.5f) * 2.0f * 0.75f;
    p->rot = func_002D56C0(((float)(func_002EFD78() & 0x7FFF) / 32767.0f) * 360.0f);
    p->scale = 0.1875f;
    if (a3 == 0) {
        p->rgb[0] = 0x18;
        p->rgb[1] = 0x7;
        p->rgb[2] = 0x6;
        p->alpha = 1.0f;
    } else {
        p->rgb[0] = 0x3C;
        p->rgb[1] = 0x6E;
        p->rgb[2] = 0x5A;
        p->alpha = 1.0f;
    }
}

void func_01B00FC8(void)
{
    int i;
    void *tex = 0;

    func_01B01EB0(D_01B02AD8, D_01B00458);
    for (i = 0; i < 2; i++) {
        SprParam *sp;
        if (i == 0) {
            tex = func_002B49A0(D_01B0045C, 4, 0);
        } else if (i == 1) {
            tex = func_002B49A0(D_01B0045C, 4, 1);
        }
        D_01B00A60[i] = tex;
        sp = &D_01B00A70[i];
        func_002EF0D0(sp, 0, 0x30);
        sp->h02 = 0x80;
    }
    for (i = 0; i < 2; i++) {
        func_01B02440(&D_01B00AE0[i], D_01B00AD0[i], 500);
        func_01B02728(&D_01B00AE0[i], 0.0f, 0.0f, 0);
    }
}

int func_01B01100(void)
{
    float pos[4];
    int i;

    func_00107428(D_01B00454, 0x3C, 0, pos);
    if ((((float)(func_002EFD78() & 0x7FFF) / 32767.0f) - 0.5f) * 2.0f > 0.0f) {
        for (i = 0; i < 1; i++) {
            func_01B00E00(&D_01B00AE0[0], D_01B00A60[0], pos, 0);
        }
    }
    if (((float)(func_002EFD78() & 0x7FFF) / 32767.0f) < 0.25f) {
        for (i = 0; i < 1; i++) {
            func_01B00E00(&D_01B00AE0[1], D_01B00A60[1], pos, 1);
        }
    }
    for (i = 0; i < 2; i++) {
        func_01B024B8(&D_01B00AE0[i]);
        D_01B0046C = func_01B02650(&D_01B00AE0[i], &D_01B00A70[i], D_01B0046C, 0.0f);
    }
    return 1;
}

int func_01B01288(void)
{
    func_01B01EB0(D_01B02AF0, D_01B00458);
    return 1;
}

int func_01B012B8(void)
{
    func_01B01EB0(D_01B02B08, D_01B00458);
    D_006A3924 = &D_01B00478;
    func_00267658(&D_01B004B0, 0x1000, D_01B00474->w10[2], 1);
    D_01B004B0.pos[0] = 68.4491501f;
    D_01B004B0.pos[1] = -29.7276402f;
    D_01B004B0.pos[2] = -169.938049f;
    D_01B004B0.pos[3] = 0.0f;
    D_01B004B0.rot[0] = 0;
    D_01B004B0.rot[1] = 0x8000;
    D_01B004B0.rot[2] = 0;
    D_01B004B0.rot[3] = 0;
    D_01B004B0.scale[2] = D_01B004B0.scale[1] = D_01B004B0.scale[0] = 0.3125f;
    D_01B004B0.scale[3] = 1.0f;
    return 1;
}

int func_01B01390(void)
{
    D_006A3924 = &D_01B00478;
    func_001AACA0(&D_006A3A70);
    func_001A9EE0(&D_006A3970);
    func_002675B0(&D_01B004B0);
    func_002DCE38(&D_006A39B0, &D_006A3970, &D_006A3930);
    func_002DCE38(&D_006A3AB0, &D_006A3A70, &D_006A39B0);
    D_006A3924 = &D_01B00478;
    if (func_00267FA0(&D_01B004B0, 0x30) != 0) {
        if (func_0014AA50(1) != 0) {
            return 0;
        }
        D_006A3924 = &D_01B00478;
        func_00267530(&D_01B004B0);
        D_006A3924 = &D_01B00478;
        func_00267658(&D_01B004B0, 0x1000, D_01B00474->w10[2], 1);
    }
    return 1;
}
