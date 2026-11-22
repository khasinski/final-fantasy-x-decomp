#include "common.h"

typedef struct {
    float x, y, z, w;
} Vec4 __attribute__((aligned(16)));

typedef struct {
    u8 pad00[0x2C];
    void *w2C;
} OvlMgr;

typedef struct {
    u8 pad00[0xC4];
    float fC4;
    u8 padC8[0x08];
    Vec4 pos;
    u8 padE0[0x34];
    s32 w114;
    u8 pad118[0x18];
} OvlCtx;

typedef struct {
    u8 pad00[0x14];
    s32 w14;
    u8 pad18[0x98];
    u16 hB0;
} Obj5520;

typedef struct {
    u8 pad00[0x54];
    s32 w54;
} Obj56A0;

typedef struct {
    u8 pad00[0x10];
    s32 p10;
} TaskSub;

typedef struct {
    u8 pad00[0x08];
    TaskSub *p08;
    u8 pad0C[0x08];
    s32 w14;
} OvlTask;

extern u8 D_01B00040[];
extern u8 D_01B004A0[];
extern u8 D_01B004B8[];
extern u8 D_01B008E0[];
extern u8 D_01B03EE0[];
extern u8 D_01B05168[];
extern OvlCtx D_01B05190[];
extern Obj5520 D_01B05520;
extern Obj56A0 D_01B056A0;
extern OvlMgr D_01B05700;
extern u8 *D_01B05740;
extern u8 *D_01B05744;
extern u8 D_01B0AAA0[];
extern u8 D_01B9B5C0[];

extern float func_002B3DB0(float);
extern void *func_002B49A0(void *, int, int);
extern int func_002EFD78(void);

extern float func_01B00EF8(int);
extern void func_01B01020(int, Vec4 *, int);
extern void func_01B02A08(int, void *, void *);
extern int func_01B02AC0(void *);
extern void *func_01B035E0(void *);
extern void func_01B037A8(void *);
extern void func_01B03868(void *, void *, void *, int);
extern void func_01B03940(void *, void *, float, int, int, int, void *);
extern int func_01B03A20(void *, void *);
extern void func_01B04670(Vec4 *, Vec4 *, Vec4 *);
extern void func_01B04778(Vec4 *, Vec4 *, Vec4 *);
extern void func_01B04CC8(void *, int, Vec4 *, int, float, float, float);
extern void func_01B04FF0(void *, void *, void *, int);

void ovl_09243_0bd0(OvlTask *a0);

int ovl_09243_0900(void)
{
    u8 *p = D_01B9B5C0;
    OvlMgr *mgr;
    OvlCtx *ctx;
    Vec4 v00;
    Vec4 v10;
    Vec4 v20;
    Vec4 v30;
    float rot;
    int i;

    D_01B05744 = p + 0x40000;
    D_01B05740 = p;
    mgr = &D_01B05700;
    mgr->w2C = func_002B49A0(D_01B0AAA0, 8, 0);
    func_01B03868(mgr, D_01B00040, D_01B05740, 0x40000);

    ctx = D_01B05190;
    rot = func_01B00EF8(0);
    for (i = 0; i < 2; i++, ctx++) {
        func_01B03940(mgr, ctx, 0.35f, 0, 28, 0, 0);
        func_01B01020(0, &ctx->pos, 1);
        ctx->pos.x += func_002B3DB0(2.0f);
        ctx->pos.y += func_002B3DB0(4.0f);
        ctx->pos.z += func_002B3DB0(2.0f);
        ctx->fC4 = rot;
        ctx->w114 += func_002EFD78() % 8;
    }

    func_01B03940(mgr, ctx, 0.35f, 0, 28, 0, D_01B03EE0);
    func_01B01020(0, &ctx->pos, 1);
    ctx->fC4 = rot;

    func_01B01020(-1, &v00, 0);
    func_01B01020(0, &v10, 0);
    func_01B04670(&v20, &v00, &v10);
    v30.x = 0.0f;
    v30.y = 0.0f;
    v30.z = 4.0f;
    func_01B04778(&v20, &v10, &v30);

    func_01B04CC8(&D_01B05520, -1, &v10, 28, 0.5f, 1.2f, 0.99f);
    D_01B05520.w14 = 1;
    func_01B04FF0(&D_01B056A0, D_01B0AAA0, D_01B004A0, 1);
    D_01B056A0.w54 = -1;
    func_01B02A08(-1, D_01B05168, D_01B004B8);
    func_01B037A8(func_01B035E0((void *)ovl_09243_0bd0));
    return 0;
}

void ovl_09243_0bd0(OvlTask *a0)
{
    int r = func_01B02AC0(D_01B05168);
    if (func_01B03A20(&D_01B05700, D_01B05744) == 1 && r == 1 && (D_01B05520.hB0 & 0x8000)) {
        a0->w14 = 3;
        a0->p08->p10 = (s32)D_01B008E0;
    }
}
