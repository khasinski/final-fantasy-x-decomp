#include "common.h"

typedef struct {
    u8 pad00[0x2C];
    void *w2C;
} OvlMgr;

typedef struct {
    u8 pad00[0xC4];
    float fC4;
    u8 padC8[0x8];
    float fD0[4];
    float fE0[4];
    u8 padF0[0x20];
    void *f110;
    u8 pad114[0x1C];
} Ovl9233Obj;

typedef struct {
    u8 pad00[0x4];
    int count;
} Ovl9233Info;

extern u8 D_01B88280[];
extern u8 D_01B0AF10[];
extern u8 D_01B00040[];
extern u8 D_01B00400[];
extern u8 D_01B00428[];
extern u8 D_01B00AB8[];
extern u8 D_01B03DB8[];
extern u8 D_01B04BB8[];
extern Ovl9233Info D_01B00480;
extern Ovl9233Obj D_01B04BE0[];
extern OvlMgr D_01B05560;
extern Ovl9233Obj D_01B055A0[];
extern void *D_01B05800;
extern void *D_01B05804;

extern void *func_002B49A0(void *, int, int);
extern void func_01B03740(void *, void *, void *, int);
extern void func_01B03818(void *, void *, int, int, float, int, void *);
extern void func_01B00EF8(int, void *, int);
extern float func_01B00DD0(int);
extern void func_01B02FA0(void *, void *, void *);
extern void func_01B04548(void *, void *, void *);
extern void func_01B028E0(int, void *, void *);
extern void *func_01B034B8(void *);
extern void func_01B03680(void *);

int func_01B00888(void)
{
    float v0[4];
    float v1[4];
    u8 *p = D_01B88280;
    u8 *res = D_01B0AF10;
    OvlMgr *mgr;
    Ovl9233Obj *ctx;
    u8 *q;
    int i;

    D_01B05800 = p;
    D_01B05804 = p + 0x40000;
    mgr = &D_01B05560;
    mgr->w2C = func_002B49A0(res, 8, 0);
    func_01B03740(mgr, D_01B00040, D_01B05800, 0x40000);
    ctx = D_01B055A0;
    func_01B03818(mgr, ctx, 0, 4, 2.0f, 0, 0);
    func_01B00EF8(-1, ctx->fD0, 1);
    ctx->fC4 = func_01B00DD0(-1);
    ctx->fD0[1] -= 3.0f;
    ctx->fE0[2] -= 5.0f;
    q = p + 0x140000;
    func_01B02FA0(q, res, D_01B00400);
    ctx->f110 = q;
    func_01B00EF8(-1, v1, 1);

    ctx = D_01B04BE0;
    for (i = 0; i < D_01B00480.count; i++, ctx++) {
        func_01B03818(mgr, ctx, 1, 0x13, 1.5f, 0, D_01B03DB8);
        func_01B00EF8(i, ctx->fD0, 1);
        func_01B04548(v0, ctx->fD0, v1);
        ctx->fC4 = v0[1];
    }

    func_01B028E0(-1, D_01B04BB8, D_01B00428);
    func_01B03680(func_01B034B8(D_01B00AB8));
    return 0;
}
