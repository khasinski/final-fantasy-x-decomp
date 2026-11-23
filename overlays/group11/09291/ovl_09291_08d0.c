#include "common.h"

typedef struct {
    u8 pad00[0x2C];
    void *w2C;
} OvlMgr;

typedef struct {
    u8 pad00[0x04];
    s32 w04;
} Cfg4D8;

typedef struct {
    u8 pad00[0x54];
    s32 w54;
} Obj63F0;

typedef struct {
    u8 pad00[0xC0];
    float fC0;
    u8 padC4[0x0C];
    float pos[4];
    u8 padE0[0x30];
    void *p110;
    u8 pad114[0x0C];
    s32 w120;
    u8 pad124[0x0C];
} OvlCtx;

typedef struct {
    u8 pad00[0x40];
} Sub40;

extern u8 D_01B6B180[];
extern void *D_01B06918;
extern void *D_01B0691C;
extern u8 D_01B0BEC0[];
extern OvlMgr D_01B068D8;
extern u8 D_01B00040[];
extern Cfg4D8 D_01B004D8;
extern OvlCtx D_01B04E90[][6];
extern u8 D_01B03F40[];
extern Sub40 D_01B06450[][6];
extern u8 D_01B00468[];
extern s32 D_01B068D0;
extern Obj63F0 D_01B063F0;
extern u8 D_01B00450[];
extern u8 D_01B04E68[];
extern u8 D_01B00480[];
extern u8 D_01B00BE0[];

extern void *func_002B49A0(void *, s32, s32);
extern float func_002B3DB0(float);
extern double sqrt(double);
extern s32 func_002EFD78(void);
extern void func_01B03898(void *, void *, void *, s32);
extern void func_01B01050(s32, void *, s32);
extern void func_01B03970(void *, void *, s32, s32, float, s32, void *);
extern s32 func_01B00E00(s32);
extern void func_01B030F8(void *, void *, void *);
extern void func_01B04CF8(void *, void *, void *, s32);
extern void func_01B02A38(s32, void *, void *);
extern void *func_01B03610(void *);
extern void func_01B037D8(void *);

s32 ovl_09291_08d0(void)
{
    float v0[4];
    float v1[4];
    register u8 *p __asm__("$2") = D_01B6B180;
    OvlMgr *mgr = &D_01B068D8;
    s32 i, j;

    D_01B06918 = p;
    {
        register u8 *end __asm__("$3") = p + 0x40000;
        D_01B0691C = end;
    }
    mgr->w2C = func_002B49A0(D_01B0BEC0, 8, 0);
    func_01B03898(mgr, D_01B00040, D_01B06918, 0x40000);

    func_01B01050(-1, v0, 0);
    for (i = 0; i < D_01B004D8.w04; i++) {
        s32 delay = 92;

        func_01B01050(i, v1, 0);
        v1[0] -= v0[0];
        v1[2] -= v0[2];
        if ((float)sqrt((double)(v1[0] * v1[0] + v1[2] * v1[2])) > 100.0f) {
            delay = 84;
        }
        for (j = 0; j < 6; j++) {
            OvlCtx *ctx = &D_01B04E90[i][j];
            Sub40 *sub;

            func_01B03970(mgr, ctx, 0, delay, 0.3f, 0, D_01B03F40);
            func_01B01050(i, ctx->pos, 1);
            ctx->fC0 += 0.34906587f;
            ctx->pos[0] += func_002B3DB0(5.0f);
            ctx->pos[1] += func_002B3DB0(5.0f);
            ctx->pos[2] += func_002B3DB0(5.0f);
            ctx->w120 = func_01B00E00(i);
            sub = &D_01B06450[i][j];
            func_01B030F8(sub, D_01B0BEC0, D_01B00468);
            ctx->p110 = sub;
            delay += 8 + (func_002EFD78() % 4);
        }
    }

    D_01B068D0 = 0;
    func_01B04CF8(&D_01B063F0, D_01B0BEC0, D_01B00450, 1);
    D_01B063F0.w54 = -1;
    func_01B02A38(-1, D_01B04E68, D_01B00480);
    func_01B037D8(func_01B03610(D_01B00BE0));
    return 0;
}
