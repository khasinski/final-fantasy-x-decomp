#include "vu0.h"

typedef struct Ovl09606PppMgr {
    u8 pad00[0x2C];
    void *p2C;
} Ovl09606PppMgr;

typedef struct Ovl09606PppObj {
    u8 pad00[0xC4];
    float fC4;
    u8 padC8[0x08];
    float pos[4];
    float fE0;
    float fE4;
    float fE8;
    u8 padEC[0x44];
} Ovl09606PppObj;

typedef struct Ovl09606Fog {
    u8 pad00[0x80];
    u8 b80;
    u8 b81;
    u8 b82;
    u8 b83;
    u8 b84;
    u8 b85;
    u8 b86;
    u8 b87;
    int w88;
    u8 pad8C[0x0C];
    u8 b98;
    u8 b99;
} Ovl09606Fog;

typedef struct Ovl09606Fade {
    u8 pad00[0x04];
    float f04;
    u8 pad08[0x0C];
    float f14;
    u8 pad18[0x28];
} Ovl09606Fade;

typedef struct Ovl09606Snd {
    u8 pad00[0x54];
    int w54;
} Ovl09606Snd;

typedef struct Ovl09606TaskObj {
    u8 pad00[0x14];
    s16 h14;
    s16 h16;
    u8 b18;
} Ovl09606TaskObj;

typedef union Ovl09606Vec {
    float f[4];
    u_long128 q;
} Ovl09606Vec;

extern u8 D_01B00040[];
extern u8 D_01B00658[];
extern u8 D_01B006F0[];
extern u8 D_01B01D98[];
extern u8 D_01B01DC8[];
extern u8 D_01B01E88[];
extern u8 D_01B020B8[];
extern u8 D_01B02128[];
extern u8 D_01B074B8[];
extern Ovl09606PppObj D_01B07740[];
extern Ovl09606Fog D_01B07FE0;
extern Ovl09606Fade D_01B08080[];
extern Ovl09606Snd D_01B08100;
extern u8 *D_01B08160;
extern u8 *D_01B08164;
extern int D_01B08168;
extern int D_01B0816C;
extern Ovl09606PppMgr D_01B08170;
extern u8 *D_01B081B0;
extern u8 *D_01B081B4;
extern u8 D_01B0D450[];
extern u8 D_01BB6500[];

void *func_002B49A0(void *a0, int a1, int a2);
void func_01B02160(void);
void func_01B021A8(void);
float func_01B02680(int a0);
void func_01B027A8(int a0, float *a1, int a2);
void func_01B03840(int a0, int a1);
void func_01B04190(int a0, void *a1, void *a2);
void func_01B045D8(int a0);
Ovl09606TaskObj *func_01B04D68(void *a0);
void func_01B04F30(Ovl09606TaskObj *a0);
void func_01B04FF0(void *a0, void *a1, void *a2, int a3);
void *func_01B050C8(void *a0, void *a1, int a2, int a3, int a4, void *a5, float a6);
void func_01B06B00(void *a0, int a1);
void func_01B06F58(void *a0, int a1);
void func_01B07110(void *a0, int a1, int a2, float a3, float a4);
void func_01B07348(void *a0, void *a1, void *a2, int a3);

int func_01B018A0(void)
{
    u8 *base = D_01BB6500;
    float v00[4];
    float dir;
    Ovl09606PppMgr *mgr;
    Ovl09606PppObj *p;
    Ovl09606TaskObj *t;

    D_01B081B0 = base;
    D_01B081B4 = base + 0x40000;
    D_01B08164 = base + 0x140000;
    D_01B08160 = base + 0x150000;

    mgr = &D_01B08170;
    mgr->p2C = func_002B49A0(D_01B0D450, 8, 0);
    func_01B04FF0(mgr, D_01B00040, D_01B081B0, 0x40000);

    func_01B027A8(-1, v00, 0);
    dir = func_01B02680(-1);

    p = &D_01B07740[0];
    func_01B050C8(&D_01B08170, p, 3, 10, -1, 0, 0.06f);
    MMI_COPY_LQ_A3(p->pos, v00);
    MMI_COPY_SQ_A3(p->pos);
    p->fC4 = dir;
    p->pos[1] -= 30.0;

    p = &D_01B07740[1];
    func_01B050C8(&D_01B08170, p, 3, 35, -1, 0, 0.06f);
    MMI_COPY_LQ_A3(p->pos, v00);
    MMI_COPY_SQ_A3(p->pos);
    p->fC4 = dir;
    p->pos[1] -= 30.0;

    p = &D_01B07740[2];
    func_01B050C8(&D_01B08170, p, 1, 98, 0, D_01B020B8, 0.6f);
    p->fE0 += 500.0f;

    p = &D_01B07740[3];
    func_01B050C8(&D_01B08170, p, 4, 118, -1, 0, 0.03f);
    MMI_COPY_LQ_A3(p->pos, v00);
    MMI_COPY_SQ_A3(p->pos);
    p->fC4 = dir;
    p->pos[1] -= 10.0f;
    p->fE8 -= 20.0f;

    p = &D_01B07740[4];
    func_01B050C8(&D_01B08170, p, 5, 168, -1, 0, 0.52f);
    MMI_COPY_LQ_A3(p->pos, v00);
    MMI_COPY_SQ_A3(p->pos);
    p->fC4 = dir;
    p->pos[1] -= 20.0f;
    p->fE8 -= 5.0f;

    p = &D_01B07740[5];
    func_01B050C8(&D_01B08170, p, 2, 208, 0, D_01B02128, 0.32f);
    MMI_COPY_LQ_A3(p->pos, v00);
    MMI_COPY_SQ_A3(p->pos);
    p->fC4 = dir;
    p->pos[1] -= 12.0f;
    p->fE8 -= 7.0f;

    func_01B021A8();
    func_01B03840(-1, 1);
    func_01B02160();

    D_01B08168 = 0;
    D_01B0816C = 0;

    func_01B07348(&D_01B08100, D_01B0D450, D_01B00658, 1);
    D_01B08100.w54 = -1;

    D_01B07FE0.b82 = 0x40;
    D_01B07FE0.b81 = 0x40;
    D_01B07FE0.b80 = 0x40;
    D_01B07FE0.b83 = 0x80;
    D_01B07FE0.b84 = 0x40;
    D_01B07FE0.b85 = 0x40;
    D_01B07FE0.b86 = 0x40;
    D_01B07FE0.b87 = 0;
    D_01B07FE0.w88 = 0;
    D_01B07FE0.b98 = 0x48;
    D_01B07FE0.b99 = 0;
    func_01B06F58(&D_01B07FE0, 0x18);

    func_01B07110(&D_01B08080[0], 0x5A, 0, 1.0f, 0.45f);
    D_01B08080[0].f14 = 0.5f;
    func_01B07110(&D_01B08080[1], 0x5A, 0x15E, 0.45f, 1.0f);
    D_01B08080[1].f04 = 0.5f;

    func_01B045D8(1);
    func_01B04190(-1, D_01B074B8, D_01B006F0);

    t = func_01B04D68(D_01B01D98);
    t->b18 = 1;
    func_01B04F30(t);

    t = func_01B04D68(D_01B01E88);
    t->h14 = 0;
    t->h16 = 0x19;
    func_01B04F30(t);

    t = func_01B04D68(D_01B01E88);
    t->h14 = 0x3C;
    t->h16 = 0x1A;
    func_01B04F30(t);

    t = func_01B04D68(D_01B01E88);
    t->h14 = 0x69;
    t->h16 = 0x0C;
    func_01B04F30(t);

    func_01B06B00(base + 0x190000, 0x100);

    t = func_01B04D68(D_01B01DC8);
    t->b18 = 2;
    func_01B04F30(t);

    return 0;
}
