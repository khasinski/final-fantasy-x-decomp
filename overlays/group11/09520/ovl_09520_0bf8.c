#include "common.h"
#include "vu0.h"

typedef struct {
    u8 pad00[0x2C];
    void *w2C;
} OvlMgr;

typedef struct {
    u8 pad00[0x40];
} OvlFade;

typedef struct {
    float x, y, z, w;
} Vec4;

typedef struct {
    u8 pad00[0xC4];
    float fC4;
    u8 padC8[0x08];
    Vec4 pos;
    float fE0;
    float fE4;
    float fE8;
    u8 padEC[0x44];
} OvlCtx;

typedef struct {
    s32 w00;
    s32 w04;
} Cfg808;

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
extern u8 D_01B007C0[];
extern Cfg808 D_01B00808;
extern u8 D_01B00BD8[];
extern s32 D_01B04AA0;
extern u8 D_01B04AA8[];
extern OvlFade D_01B04AD0[];
extern u8 *D_01B04B50;
extern s32 D_01B04B54;
extern OvlMgr D_01B04B58;
extern OvlCtx D_01B04BA0[];
extern u8 *D_01B05060;
extern u8 *D_01B05064;
extern u8 D_01B0A2D0[];
extern u8 D_01B8F400[];

extern void *func_002B49A0(void *, int, int);
extern void func_00117A68(void *);
extern void func_001178E0(void *);
extern void func_002A3BD8(void *, void *);
extern void func_002A3CA0(void *, void *, int, int, int, int);

extern void func_01B010C0(int);
extern void *func_01B01258(int);
extern float func_01B012E8(int);
extern void func_01B01410(int, Vec4 *, int);
extern void func_01B01F88(int);
extern void func_01B02DF8(int, void *, void *);
extern int func_01B02EB0(void *);
extern void func_01B03240(int);
extern void func_01B033D8(void *, int, int, int);
extern void *func_01B039D0(void *);
extern void func_01B03A50(void *);
extern void func_01B03B98(void *);
extern void func_01B03C58(void *, void *, void *, int);
extern int func_01B03D30(void *, void *, float, int, int, int, void *);
extern int func_01B03E10(void *, void *);
extern void func_01B04860(void *, float, float, int, int);

extern void func_01B00F68(void *);
void ovl_09520_0ed8(OvlTask *a0);

int ovl_09520_0bf8(void)
{
    u8 *p = D_01B8F400;
    u8 *res;
    OvlMgr *mgr;
    OvlCtx *ctx;
    Vec4 pos;
    float f20;
    void *chr;

    D_01B05060 = p;
    D_01B05064 = p + 0x40000;
    D_01B04B50 = p + 0x140000;
    D_01B00808.w00 = 20;
    D_01B00808.w04 = 0;
    func_01B010C0(D_01B04AA0);

    res = D_01B0A2D0;
    mgr = &D_01B04B58;
    mgr->w2C = func_002B49A0(res, 8, 0);
    func_01B03C58(mgr, D_01B00040, D_01B05060, 0x40000);
    func_01B01410(-1, &pos, 0);
    f20 = func_01B012E8(-1);

    ctx = &D_01B04BA0[2];
    func_01B03D30(mgr, ctx, 0.4f, 2, 0, 0, 0);
    MMI_COPY_LQ_A3(&ctx->pos, &pos);
    MMI_COPY_SQ_A3(&ctx->pos);
    ctx->fC4 = f20;
    ctx->fE8 = -14.0f;

    ctx = &D_01B04BA0[0];
    func_01B03D30(mgr, ctx, 0.4f, 0, 30, 0, 0);
    MMI_COPY_LQ_A3(&ctx->pos, &pos);
    MMI_COPY_SQ_A3(&ctx->pos);
    ctx->fC4 = f20;

    ctx = &D_01B04BA0[3];
    func_01B03D30(mgr, ctx, 1.5f, 3, 150, 0, 0);
    MMI_COPY_LQ_A3(&ctx->pos, &pos);
    MMI_COPY_SQ_A3(&ctx->pos);
    ctx->fC4 = f20;
    ctx->pos.y += 40.0f;

    ctx = &D_01B04BA0[1];
    func_01B03D30(mgr, ctx, 0.6f, 1, 300, 0, 0);
    MMI_COPY_LQ_A3(&ctx->pos, &pos);
    MMI_COPY_SQ_A3(&ctx->pos);
    ctx->fC4 = f20;

    chr = func_01B01258(-1);
    func_00117A68(chr);
    func_002A3BD8(chr, D_01B04B50);

    D_01B04B54 = 120;
    func_01B04860(&D_01B04AD0[0], 1.0f, 0.5f, 60, 0);
    func_01B04860(&D_01B04AD0[1], 0.5f, 1.0f, 30, 450);
    func_01B03240(1);
    func_01B01F88(-1);
    func_01B033D8(res, 0, 64, 256);
    func_01B02DF8(-1, D_01B04AA8, D_01B007C0);
    func_01B03B98(func_01B039D0((void *)func_01B00F68));
    func_01B03B98(func_01B039D0((void *)ovl_09520_0ed8));
    return 0;
}

void ovl_09520_0ed8(OvlTask *a0)
{
    int r = func_01B02EB0(D_01B04AA8);
    if (func_01B03E10(&D_01B04B58, D_01B05064) == 1 && r == 1) {
        func_001178E0(func_01B01258(-1));
        a0->w14 = 3;
        a0->p08->p10 = (s32)D_01B00BD8;
    }
}
