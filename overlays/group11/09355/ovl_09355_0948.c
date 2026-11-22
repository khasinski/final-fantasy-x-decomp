#include "common.h"

typedef struct {
    float x, y, z, w;
} Vec4;

typedef struct {
    u8 pad00[0x2C];
    void *w2C;
} OvlMgr;

typedef struct {
    u8 pad00[0xC4];
    float fC4;
    u8 padC8[0x08];
    Vec4 pos;
    u8 padE0[0x30];
    void *p110;
} OvlCtx;

typedef struct {
    u8 pad00[0x80];
    u8 b80;
    u8 b81;
    u8 b82;
    u8 b83;
    u8 b84;
    u8 b85;
    u8 b86;
    u8 b87;
    s32 w88;
    u8 pad8C[0x0C];
    u8 b98;
    u8 b99;
} Obj54E0;

typedef struct {
    u8 pad00[0x40];
} OvlFade;

typedef struct {
    u8 pad00[0xB0];
    u16 hB0;
} Obj5420;

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
extern u8 D_01B004F0[];
extern u8 D_01B00508[];
extern u8 D_01B00928[];
extern u8 D_01B03F08[];
extern Obj5420 D_01B05420;
extern Obj54E0 D_01B054E0;
extern OvlFade D_01B05580[];
extern s32 D_01B05600;
extern OvlMgr D_01B05608;
extern OvlCtx D_01B05650;
extern u8 *D_01B05780;
extern u8 *D_01B05784;
extern u8 D_01B0ACA0[];
extern u8 D_01B67E00[];

extern void *func_002B49A0(void *, int, int);

extern float func_01B00F20(int);
extern void func_01B01048(int, Vec4 *, int);
extern void func_01B01D10(int, int);
extern void func_01B02A30(int, void *, void *);
extern void func_01B02E78(int);
extern void func_01B030F0(void *, void *, void *);
extern void *func_01B03608(void *);
extern void func_01B037D0(void *);
extern void func_01B03890(void *, void *, void *, int);
extern void func_01B03968(void *, void *, float, int, int, int, void *);
extern int func_01B03A48(void *, void *);
extern void func_01B04698(Vec4 *, Vec4 *, Vec4 *);
extern void func_01B047A0(Vec4 *, Vec4 *, Vec4 *);
extern void func_01B04CF0(void *, int, Vec4 *, int, float, float, float);
extern void func_01B05018(void *, int);
extern void func_01B051D0(void *, float, float, int, int);

void ovl_09355_0bf8(OvlTask *a0);

int ovl_09355_0948(void)
{
    u8 *p = D_01B67E00;
    u8 *res = D_01B0ACA0;
    OvlMgr *mgr;
    OvlCtx *ctx;
    Vec4 v00;
    Vec4 v10;
    Vec4 v20;
    Vec4 v30;

    D_01B05780 = p;
    D_01B05784 = p + 0x40000;
    mgr = &D_01B05608;
    mgr->w2C = func_002B49A0(res, 8, 0);
    func_01B03890(mgr, D_01B00040, D_01B05780, 0x40000);

    ctx = &D_01B05650;
    func_01B03968(mgr, ctx, 0.07f, 0, 30, 2, D_01B03F08);
    func_01B01048(-1, &ctx->pos, 3);
    ctx->fC4 = func_01B00F20(-1);
    ctx->pos.y -= 20.0f;

    p += 0x140000;
    func_01B030F0(p, res, D_01B004F0);
    ctx->p110 = p;

    func_01B01048(-1, &v00, 0);
    func_01B01048(0, &v10, 0);
    v10.y = v00.y;
    func_01B04698(&v20, &v00, &v10);
    v20.x = 0.0f;
    v30.x = 0.0f;
    v30.y = 0.0f;
    v30.z = 10.0f;
    func_01B047A0(&v20, &v10, &v30);

    ctx->pos.x = v10.x;
    ctx->pos.z = v10.z;

    func_01B04CF0(&D_01B05420, -1, &v10, 30, 0.5f, 1.2f, 0.99f);
    func_01B02A30(-1, &D_01B05420, D_01B00508);

    D_01B054E0.b82 = 255;
    D_01B054E0.b81 = 255;
    D_01B054E0.b80 = 255;
    D_01B054E0.b83 = 128;
    D_01B054E0.b87 = 0;
    D_01B054E0.b86 = 0;
    D_01B054E0.b85 = 0;
    D_01B054E0.b84 = 0;
    D_01B054E0.w88 = 32;
    D_01B054E0.b98 = 72;
    D_01B054E0.b99 = 0;
    func_01B05018(&D_01B054E0, 10);

    D_01B05600 = D_01B054E0.w88;
    func_01B051D0(&D_01B05580[0], 1.0f, 0.5f, 30, 0);
    func_01B051D0(&D_01B05580[1], 0.5f, 1.0f, 16, 54);
    func_01B02E78(1);
    func_01B037D0(func_01B03608((void *)ovl_09355_0bf8));
    return 0;
}

void ovl_09355_0bf8(OvlTask *a0)
{
    if (D_01B05600 > 0) {
        if (--D_01B05600 == 0) {
            func_01B01D10(-1, 0);
        }
    }
    if (func_01B03A48(&D_01B05608, D_01B05784) == 1 && (D_01B05420.hB0 & 0x8000)) {
        a0->w14 = 3;
        a0->p08->p10 = (s32)D_01B00928;
    }
}
