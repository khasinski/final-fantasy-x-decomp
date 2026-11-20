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
    int flags;
    u8 pad3c[0x34];
    float scale;
    float rot;
    int rgb[3];
} PartItem;

typedef struct {
    u16 h00;
    u16 h02;
    u32 w04;
    u8 pad08[0x28];
} SprParam;

extern float D_01B00518;
extern float D_01B0051C;
extern float D_01B00520;
extern float D_01B00524;
extern float D_01B00528;
extern float D_01B0052C;
extern float D_01B00530;
extern void *D_01B00548;
extern void *D_01B0054C;
extern void *D_01B00558;
extern TtCfg *D_01B0055C;
extern u8 D_01B00560;
extern void *D_01B00790;
extern void *D_01B00794;
extern SprParam D_01B007A0;
extern void *D_01B007D0;
extern u8 D_01B007E0;
extern int D_01B00850;
extern int D_01B00854;
extern int D_01B00870;
extern int D_01B00878;
extern char D_01B02A50[];
extern char D_01B02A60[];
extern char D_01B02A78[];
extern char D_01B02A98[];
extern char D_01B02AB0[];

extern void *D_006A3924;

extern int func_01B01E48(char *, ...);
extern void func_01B01E78(char *, ...);
extern void func_01B023E0(void *, void *, int);
extern void func_01B02458(void *);
extern PartItem *func_01B02590(void *, void *);
extern void *func_01B025F0(void *, void *, void *, float);
extern void func_01B026C8(void *, int, float, float);
extern int func_01B02730(void *);
extern void func_00107428(int, int, int, void *);
extern void func_00267658(void *, int, int, int);
extern float func_002B3DF8(float);
extern void *func_002B49A0(void *, int, int);
extern float func_002D56C0(float);
extern void func_002DA610(int, int);
extern void *func_002EF0D0(void *, int, int);
extern int func_002EFD78(void);

void func_01B00990(void *a0, void *a1, float *a2)
{
    PartItem *p;

    p = func_01B02590(a0, a1);
    if (p == 0) {
        func_01B01E48(D_01B02A50);
        return;
    }
    p->flags = 2;
    p->max_life = p->life = (int)D_01B00524;
    p->pos[0] = a2[0] + D_01B00518 * ((((float)(func_002EFD78() & 0x7FFF) / 32767.0f) - 0.5f) * 2.0f);
    p->pos[1] = a2[1] + D_01B00518 * ((((float)(func_002EFD78() & 0x7FFF) / 32767.0f) - 0.5f) * 2.0f);
    p->pos[2] = a2[2] + D_01B00518 * ((((float)(func_002EFD78() & 0x7FFF) / 32767.0f) - 0.5f) * 2.0f);
    p->vel[0] = D_01B0052C * ((((float)(func_002EFD78() & 0x7FFF) / 32767.0f) - 0.5f) * 2.0f);
    p->vel[1] = D_01B0052C * ((((float)(func_002EFD78() & 0x7FFF) / 32767.0f) - 0.5f) * 2.0f);
    p->vel[2] = D_01B0052C * ((((float)(func_002EFD78() & 0x7FFF) / 32767.0f) - 0.5f) * 2.0f);
    p->rot = func_002D56C0(((float)(func_002EFD78() & 0x7FFF) / 32767.0f) * 360.0f);
    p->scale = D_01B0051C * 0.899999976f + (D_01B0051C * 0.100000001f) * ((float)(func_002EFD78() & 0x7FFF) / 32767.0f);
    func_002EFD78();
    p->rgb[0] = 0x4B;
    p->rgb[1] = 0x81;
    p->rgb[2] = 0xCF;
}

void func_01B00C20(void *a0, void *a1, float *a2)
{
    PartItem *p;

    p = func_01B02590(a0, a1);
    if (p == 0) {
        func_01B01E48(D_01B02A50);
        return;
    }
    p->flags = 2;
    p->max_life = p->life = (int)D_01B00528;
    p->pos[0] = a2[0] + D_01B00518 * ((((float)(func_002EFD78() & 0x7FFF) / 32767.0f) - 0.5f) * 2.0f);
    p->pos[1] = a2[1] + D_01B00518 * ((((float)(func_002EFD78() & 0x7FFF) / 32767.0f) - 0.5f) * 2.0f);
    p->pos[2] = a2[2] + D_01B00518 * ((((float)(func_002EFD78() & 0x7FFF) / 32767.0f) - 0.5f) * 2.0f);
    p->vel[0] = D_01B00530 * ((((float)(func_002EFD78() & 0x7FFF) / 32767.0f) - 0.5f) * 2.0f);
    p->vel[1] = D_01B00530 * ((((float)(func_002EFD78() & 0x7FFF) / 32767.0f) - 0.5f) * 2.0f);
    p->vel[2] = D_01B00530 * ((((float)(func_002EFD78() & 0x7FFF) / 32767.0f) - 0.5f) * 2.0f);
    p->rot = func_002D56C0(((float)(func_002EFD78() & 0x7FFF) / 32767.0f) * 360.0f);
    p->scale = D_01B00520 * 0.899999976f + (D_01B00520 * 0.100000001f) * ((float)(func_002EFD78() & 0x7FFF) / 32767.0f);
}

int func_01B00E98(void)
{
    func_01B01E48(D_01B02A60);
    D_01B00794 = func_002B49A0(D_01B00558, 4, 1);
    D_01B00790 = func_002B49A0(D_01B00558, 4, 0);
    func_002EF0D0(&D_01B007A0, 0, 0x30);
    D_01B007A0.w04 = 0x80808080;
    D_01B007A0.h02 = 0x80;
    func_01B023E0(&D_01B007E0, D_01B007D0, 500);
    func_01B026C8(&D_01B007E0, 0, 0.0f, 0.0f);
    return 1;
}

int func_01B00F60(void)
{
    float pos[4];
    int bone;

    bone = (int)func_002B3DF8(152.0f);
    if (bone == 0) {
        bone = 1;
    }
    if (bone == 0x98) {
        bone = 0x97;
    }
    func_00107428(D_01B00854, bone, 0, pos);
    if (D_01B00878 < 0x168) {
        func_01B00C20(&D_01B007E0, D_01B00794, pos);
        func_01B00C20(&D_01B007E0, D_01B00794, pos);
        if (D_01B00878 % 5 == 0) {
            func_01B00990(&D_01B007E0, D_01B00790, pos);
        }
    }
    func_01B02458(&D_01B007E0);
    D_01B00870 = func_01B02730(&D_01B007E0);
    D_01B0054C = func_01B025F0(&D_01B007E0, &D_01B007A0, D_01B0054C, 0.0f);
    if ((u32)D_01B0054C >= (u32)D_01B00548 + 0x80000) {
        func_01B01E78(D_01B02A78);
    }
    func_002DA610(0, 0);
    return func_01B02730(&D_01B007E0) != 0;
}

int func_01B010C8(void)
{
    func_01B01E48(D_01B02A98, D_01B00850);
    return 1;
}

int func_01B010F8(PppObj *p)
{
    func_01B01E48(D_01B02AB0, D_01B00850);
    D_006A3924 = &D_01B00560;
    func_00267658(p, 0x1000, D_01B0055C->w10[0], 1);
    p->pos[0] = -32.0f;
    p->pos[1] = -22.0f;
    p->pos[2] = 23.0f;
    p->pos[3] = 1.0f;
    p->rot[0] = -0x1600;
    p->rot[1] = 0;
    p->rot[2] = 0;
    p->rot[3] = 1;
    p->scale[2] = p->scale[1] = p->scale[0] = 0.329593986f;
    p->scale[3] = 1.0f;
    return 1;
}
