#include "vu0.h"

typedef struct Ovl09293PppMgr {
    u8 pad00[0x2C];
    void *p2C;
} Ovl09293PppMgr;

typedef struct Ovl09293PppObj {
    u8 pad00[0xC4];
    float fC4;
    u8 padC8[0x08];
    float pos[4];
    float fE0;
    float fE4;
    float fE8;
    u8 padEC[0x44];
} Ovl09293PppObj;

typedef struct Ovl09293Fog {
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
} Ovl09293Fog;

typedef struct Ovl09293Fade {
    u8 pad00[0x04];
    float f04;
    u8 pad08[0x0C];
    float f14;
    u8 pad18[0x28];
} Ovl09293Fade;

typedef struct Ovl09293Snd {
    u8 pad00[0x54];
    int w54;
} Ovl09293Snd;

typedef struct Ovl09293TaskObj {
    u8 pad00[0x14];
    s16 h14;
    s16 h16;
    u8 b18;
} Ovl09293TaskObj;

typedef union Ovl09293Vec {
    float f[4];
    u_long128 q;
} Ovl09293Vec;

extern u8 D_01B00040[];
extern u8 D_01B00658[];
extern u8 D_01B006F0[];
extern int D_01B00738[];
extern u8 D_01B01DB0[];
extern u8 D_01B01DE0[];
extern u8 D_01B01EA0[];
extern u8 D_01B020D0[];
extern u8 D_01B02140[];
extern int D_01B074D0;
extern u8 D_01B074D8[];
extern Ovl09293PppObj D_01B07760[];
extern Ovl09293Fog D_01B08000;
extern Ovl09293Fade D_01B080A0[];
extern Ovl09293Snd D_01B08120;
extern u8 *D_01B08180;
extern u8 *D_01B08184;
extern int D_01B08188;
extern int D_01B0818C;
extern Ovl09293PppMgr D_01B08190;
extern u8 *D_01B081D0;
extern u8 *D_01B081D4;
extern u8 D_01B0D520[];
extern u8 D_01BB65C0[];

void *func_002B49A0(void *a0, int a1, int a2);
void func_01B02178(void);
void func_01B021C0(void);
void func_01B02470(int a0);
float func_01B02698(int a0);
void func_01B027C0(int a0, float *a1, int a2);
void func_01B03858(int a0, int a1);
void func_01B041A8(int a0, void *a1, void *a2);
void func_01B045F0(int a0);
Ovl09293TaskObj *func_01B04D80(void *a0);
void func_01B04F48(Ovl09293TaskObj *a0);
void func_01B05008(void *a0, void *a1, void *a2, int a3);
void *func_01B050E0(void *a0, void *a1, int a2, int a3, int a4, void *a5, float a6);
void func_01B06B18(void *a0, int a1);
void func_01B06F70(void *a0, int a1);
void func_01B07128(void *a0, int a1, int a2, float a3, float a4);
void func_01B07360(void *a0, void *a1, void *a2, int a3);

int func_01B01898(void)
{
    u8 *base = D_01BB65C0;
    float v00[4];
    float dir;
    Ovl09293PppMgr *mgr;
    Ovl09293PppObj *p;
    Ovl09293TaskObj *t;

    D_01B081D0 = base;
    D_01B081D4 = base + 0x40000;
    D_01B08184 = base + 0x140000;
    D_01B08180 = base + 0x150000;

    D_01B00738[0] = 0x14;
    D_01B00738[1] = 0;
    func_01B02470(D_01B074D0);

    mgr = &D_01B08190;
    mgr->p2C = func_002B49A0(D_01B0D520, 8, 0);
    func_01B05008(mgr, D_01B00040, D_01B081D0, 0x40000);

    func_01B027C0(-1, v00, 0);
    dir = func_01B02698(-1);

    p = &D_01B07760[0];
    func_01B050E0(&D_01B08190, p, 3, 10, -1, 0, 0.06f);
    MMI_COPY_LQ_A3(p->pos, v00);
    MMI_COPY_SQ_A3(p->pos);
    p->fC4 = dir;
    p->pos[1] -= 30.0;

    p = &D_01B07760[1];
    func_01B050E0(&D_01B08190, p, 3, 35, -1, 0, 0.06f);
    MMI_COPY_LQ_A3(p->pos, v00);
    MMI_COPY_SQ_A3(p->pos);
    p->fC4 = dir;
    p->pos[1] -= 30.0;

    p = &D_01B07760[2];
    func_01B050E0(&D_01B08190, p, 1, 98, 0, D_01B020D0, 0.6f);
    p->fE0 += 500.0f;

    p = &D_01B07760[3];
    func_01B050E0(&D_01B08190, p, 4, 118, -1, 0, 0.03f);
    MMI_COPY_LQ_A3(p->pos, v00);
    MMI_COPY_SQ_A3(p->pos);
    p->fC4 = dir;
    p->pos[1] -= 10.0f;
    p->fE8 -= 20.0f;

    p = &D_01B07760[4];
    func_01B050E0(&D_01B08190, p, 5, 168, -1, 0, 0.52f);
    MMI_COPY_LQ_A3(p->pos, v00);
    MMI_COPY_SQ_A3(p->pos);
    p->fC4 = dir;
    p->pos[1] -= 20.0f;
    p->fE8 -= 5.0f;

    p = &D_01B07760[5];
    func_01B050E0(&D_01B08190, p, 2, 208, 0, D_01B02140, 0.32f);
    MMI_COPY_LQ_A3(p->pos, v00);
    MMI_COPY_SQ_A3(p->pos);
    p->fC4 = dir;
    p->pos[1] -= 12.0f;
    p->fE8 -= 7.0f;

    func_01B021C0();
    func_01B03858(-1, 1);
    func_01B02178();

    D_01B08188 = 0;
    D_01B0818C = 0;

    func_01B07360(&D_01B08120, D_01B0D520, D_01B00658, 1);
    D_01B08120.w54 = -1;

    D_01B08000.b82 = 0x40;
    D_01B08000.b81 = 0x40;
    D_01B08000.b80 = 0x40;
    D_01B08000.b83 = 0x80;
    D_01B08000.b84 = 0x40;
    D_01B08000.b85 = 0x40;
    D_01B08000.b86 = 0x40;
    D_01B08000.b87 = 0;
    D_01B08000.w88 = 0;
    D_01B08000.b98 = 0x48;
    D_01B08000.b99 = 0;
    func_01B06F70(&D_01B08000, 0x18);

    func_01B07128(&D_01B080A0[0], 0x5A, 0, 1.0f, 0.45f);
    D_01B080A0[0].f14 = 0.5f;
    func_01B07128(&D_01B080A0[1], 0x5A, 0x15E, 0.45f, 1.0f);
    D_01B080A0[1].f04 = 0.5f;

    func_01B045F0(1);
    func_01B041A8(-1, D_01B074D8, D_01B006F0);

    t = func_01B04D80(D_01B01DB0);
    t->b18 = 1;
    func_01B04F48(t);

    t = func_01B04D80(D_01B01EA0);
    t->h14 = 0;
    t->h16 = 0x19;
    func_01B04F48(t);

    t = func_01B04D80(D_01B01EA0);
    t->h14 = 0x3C;
    t->h16 = 0x1A;
    func_01B04F48(t);

    t = func_01B04D80(D_01B01EA0);
    t->h14 = 0x69;
    t->h16 = 0x0C;
    func_01B04F48(t);

    func_01B06B18(base + 0x190000, 0x100);

    t = func_01B04D80(D_01B01DE0);
    t->b18 = 2;
    func_01B04F48(t);

    return 0;
}
