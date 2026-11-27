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
    u8 padE0[0x08];
    float fE8;
    u8 padEC[0x18];
    void *w104;
    u8 pad108[0x08];
    void *w110;
    u8 pad114[0x0C];
    int w120;
    u8 pad124[0x0C];
} OvlCtx;

typedef struct {
    u8 pad00[0x40];
} OvlFade6CD0;

typedef struct {
    u8 pad00[0x18];
    u8 b18;
} OvlTask;

extern u8 D_01B7EE80[];
extern u8 D_01B0D3E0[];
extern u8 D_01B00040[];
extern u8 D_01B004A0[];
extern u8 D_01B004B8[];
extern u8 D_01B004D0[];
extern int D_01B0052C;
extern u8 D_01B01940[];
extern u8 D_01B04C18[];
extern u8 D_01B06328[];
extern OvlCtx D_01B06350[];
extern OvlFade6CD0 D_01B06CD0[];
extern void *D_01B06D50;
extern int D_01B06D54;
extern int D_01B06D58;
extern int D_01B06D5C;
extern int D_01B06D60;
extern float D_01B06D64;
extern OvlMgr D_01B06D78;
extern OvlCtx D_01B06DC0;
extern void *D_01B07020;
extern void *D_01B07024;

extern void *func_002B49A0(void *, int, int);
extern int func_002EFD78(void);
extern void func_01B04580(void *, void *, void *, int);
extern void func_01B04658(void *, void *, int, float, int, int, void *);
extern void func_01B01D38(int, void *, int);
extern float func_01B01C10(int);
extern int func_01B01AE8(int);
extern void func_01B03DE0(void *, void *, void *);
extern float func_01B05530(float *, float *);
extern void func_01B05388(float *, float *, float *);
extern void func_01B060D8(void *, float, float, int, int);
extern void func_01B03B68(int);
extern void func_01B03720(int, void *, void *);
extern OvlTask *func_01B042F8(void *);
extern void func_01B044C0(OvlTask *);
extern void func_01B013A8(void *, int);
extern void func_01B01928(void);
extern void func_01B00D48(void);
extern void func_01B00D78(void);

int func_01B00950(void)
{
    float v0[4];
    float v1[4];
    float v2[4];
    u8 *heap = D_01B7EE80;
    OvlMgr *mgr;
    OvlCtx *ctx;
    float maxDist;
    int i;
    int n;
    int t;
    OvlTask *task;

    D_01B07024 = heap + 0x80000;
    D_01B06D50 = heap + 0x1A0000;
    D_01B07020 = D_01B7EE80;
    mgr = &D_01B06D78;
    mgr->w2C = func_002B49A0(D_01B0D3E0, 8, 0);
    func_01B04580(mgr, D_01B00040, D_01B07020, 0x80000);

    ctx = &D_01B06DC0;
    func_01B04658(mgr, ctx, 0, 0.03f, 0x1D, 0, D_01B01940);
    func_01B01D38(-1, ctx->fD0, 1);
    ctx->fC4 = func_01B01C10(-1);
    ctx->fE8 = -0.5f;
    ctx->w104 = (void *)func_01B01928;
    func_01B03DE0(heap + 0x1F0000, D_01B0D3E0, D_01B004A0);
    ctx->w110 = heap + 0x1F0000;

    func_01B01D38(-1, v0, 0);
    maxDist = 0.0f;
    n = D_01B0052C;
    for (i = 0; i < n; i++) {
        float d;
        func_01B01D38(i, v1, 0);
        d = func_01B05530(v0, v1);
        if (maxDist < d) {
            maxDist = d;
        }
    }

    D_01B06D60 = 0x3C;
    D_01B06D64 = maxDist;
    t = (int)(maxDist / 6.0f);
    D_01B06D54 = t;

    ctx = D_01B06350;
    {
        int t49 = t + 0x49;
        for (i = 0; i < n; i++, ctx++) {
            int r = func_002EFD78() % 10;
            func_01B04658(mgr, ctx, 1, 0.2f, t49 + r, 0, D_01B04C18);
            func_01B01D38(i, ctx->fD0, 1);
            ctx->w120 = func_01B01AE8(i);
            func_01B05388(v2, ctx->fD0, v0);
            ctx->fC4 = v2[1];
            func_01B03DE0(heap + 0x1F0040 + (i << 6), D_01B0D3E0, D_01B004B8);
            ctx->w110 = heap + 0x1F0040 + (i << 6);
        }
    }

    func_01B060D8(&D_01B06CD0[0], 1.0f, 0.5f, 0x20, 0);
    func_01B060D8(&D_01B06CD0[1], 0.5f, 1.0f, 0x20, t + 0x75);
    func_01B03B68(1);
    D_01B06D58 = 0x1D;
    D_01B06D5C = 0x59;
    func_01B03720(-1, D_01B06328, D_01B004D0);

    task = func_01B042F8((void *)func_01B00D48);
    task->b18 = 1;
    func_01B044C0(task);

    func_01B013A8(heap + 0x1E0000, 0x200);

    task = func_01B042F8((void *)func_01B00D78);
    task->b18 = 2;
    func_01B044C0(task);

    return 0;
}
