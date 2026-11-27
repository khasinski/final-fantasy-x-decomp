#include "common.h"

typedef struct {
    u8 pad00[0x2C];
    void *w2C;
} OvlMgr;

typedef struct {
    u8 pad00[0xC4];
    float fC4;
    u8 padC8[0x08];
    float fD0[4];
    u8 padE0[0x24];
    void *w104;
    u8 pad108[0x08];
    void *w110;
    u8 pad114[0x1C];
} OvlCtx;

typedef struct {
    int w00;
    int cnt;
} OvlTbl538;

typedef struct {
    int w00;
    int w04;
    int w08;
} OvlWork6060;

extern u8 D_01B2C580[];
extern u8 D_01B0B8C0[];
extern u8 D_01B00040[];
extern u8 D_01B004C8[];
extern u8 D_01B004E0[];
extern OvlTbl538 D_01B00538;
extern u8 D_01B048C0[];
extern u8 D_01B056B8[];
extern OvlCtx D_01B056E0[];
extern OvlWork6060 D_01B06060;
extern int D_01B0606C;
extern OvlMgr D_01B06070;
extern OvlCtx D_01B061E0;
extern void *D_01B06310;
extern void *D_01B06314;

extern void *func_002B49A0(void *, int, int);
extern void func_01B04248(void *, void *, void *, int);
extern void func_01B04320(void *, void *, int, int, int, void *, float);
extern void func_01B01A00(int, void *, int);
extern float func_01B018D8(int);
extern void func_01B03AA8(void *, void *, void *);
extern void func_01B05050(float *, float *, float *);
extern void func_01B033E8(int, void *, void *);
extern void *func_01B03FC0(void *);
extern void func_01B04188(void *);
extern void func_01B00B70(void);
extern void func_01B00C00(void);
extern void func_01B00C18(void);

int func_01B00930(void)
{
    float vec[4];
    u8 *p = D_01B2C580;
    u8 *res = D_01B0B8C0;
    OvlMgr *mgr;
    OvlCtx *ctx;
    int i;

    D_01B06310 = p;
    D_01B06314 = p + 0x40000;
    mgr = &D_01B06070;
    mgr->w2C = func_002B49A0(res, 8, 0);
    func_01B04248(mgr, D_01B00040, D_01B06310, 0x40000);
    ctx = &D_01B061E0;
    func_01B04320(mgr, ctx, 1, 0x16, 0, 0, 0.15f);
    func_01B01A00(-1, ctx->fD0, 0);
    ctx->fC4 = func_01B018D8(-1);
    ctx->w104 = (void *)func_01B00C00;
    p += 0x140000;
    func_01B03AA8(p, res, D_01B004C8);
    ctx->w110 = p;

    ctx = D_01B056E0;
    for (i = 0; i < D_01B00538.cnt; i++, ctx++) {
        func_01B04320(mgr, ctx, 0, 0x2E, 0, D_01B048C0, 0.1f);
        func_01B01A00(i, ctx->fD0, 1);
        func_01B05050(vec, ctx->fD0, D_01B061E0.fD0);
        ctx->fC4 = vec[1];
    }

    D_01B06060.w00 = 0x16;
    D_01B06060.w04 = 0x18;
    D_01B06060.w08 = 0;
    D_01B0606C = 0;
    func_01B033E8(-1, D_01B056B8, D_01B004E0);
    func_01B04188(func_01B03FC0((void *)func_01B00C18));
    func_01B04188(func_01B03FC0((void *)func_01B00B70));
    return 0;
}
