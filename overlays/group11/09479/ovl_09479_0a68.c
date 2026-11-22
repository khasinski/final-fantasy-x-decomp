#include "common.h"
#include "vu0.h"

typedef struct {
    u8 pad00[0x04];
    s32 w04;
    u8 pad08[0x0C];
    u8 b14;
    u8 pad15[0xA7];
    s32 wBC;
} Obj670;

typedef struct {
    u8 pad00[0x2C];
    void *w2C;
} OvlMgr;

typedef struct {
    float x, y, z, w;
} Vec4;

typedef struct {
    u8 pad00[0xC4];
    float fC4;
    u8 padC8[0x08];
    Vec4 pos;
    u8 padE0[0x50];
} OvlCtx;

typedef struct {
    u8 pad00[0x10];
    s32 p10;
} TaskSub;

typedef struct {
    u8 pad00[0x08];
    TaskSub *p08;
    u8 pad0C[0x08];
    s32 w14;
    u8 b18;
} OvlTask;

extern u8 D_01B00040[];
extern Vec4 D_01B005E0[];
extern u8 D_01B00620[];
extern u8 D_01B00628[];
extern Obj670 D_01B00670;
extern u8 D_01B00A48[];
extern u8 D_01B04F88[];
extern u8 D_01B04FA8[];
extern Vec4 D_01B04FD0[];
extern float D_01B05010;
extern s32 D_01B05014;
extern s32 D_01B05018;
extern s32 D_01B0501C;
extern OvlMgr D_01B05020;
extern OvlCtx D_01B05060;
extern u8 *D_01B05190;
extern u8 *D_01B05194;
extern u8 D_01B0A560[];
extern u8 D_01B48380[];

extern void *func_002B49A0(void *, int, int);
extern void func_002DCE08(Vec4 *, float (*)[4], Vec4 *);
extern void func_002DD128(float (*)[4]);
extern void func_002DD318(float (*)[4], float (*)[4], float);

extern s32 func_01B01150(int, int);
extern float func_01B011A8(int);
extern void func_01B01260(int, float);
extern void func_01B012D0(int, Vec4 *, int);
extern void func_01B01400(int, float *);
extern void func_01B01F98(int, int);
extern void func_01B024B0(int, int, float);
extern void func_01B02CB8(int, void *, void *);
extern void func_01B02D28(int, void *, void *);
extern int func_01B02D70(void *);
extern void func_01B03010(void *, int);
extern void func_01B03298(void *, int, int, int);
extern OvlTask *func_01B03890(void *);
extern void func_01B03910(void *);
extern void func_01B03A58(void *);
extern void func_01B03B18(void *, void *, void *, int);
extern void func_01B03BF0(void *, void *, int, int, float, int, void *);
extern int func_01B03CD0(void *, void *);
extern float func_01B047D0(float, float *, int, int);
extern void func_01B04920(Vec4 *, Vec4 *, Vec4 *);
extern float func_01B04CF8(float, float *, int, int);

void ovl_09479_0be0(OvlTask *a0);
void ovl_09479_0cb8(void);
void ovl_09479_0e10(void *a0);

int ovl_09479_0a68(void)
{
    u8 *p = D_01B48380;
    Obj670 *obj = &D_01B00670;
    u8 *res;
    OvlMgr *mgr;
    OvlCtx *ctx;

    D_01B05194 = p + 0x40000;
    D_01B05190 = p;
    obj->wBC = func_01B01150(-1, 0);
    obj->b14 = 30;
    obj->w04 = 1;

    res = D_01B0A560;
    mgr = &D_01B05020;
    mgr->w2C = func_002B49A0(res, 8, 0);
    func_01B03B18(mgr, D_01B00040, D_01B05190, 0x40000);
    ctx = &D_01B05060;
    func_01B03BF0(mgr, ctx, 0, 10, 0.8f, 0, 0);
    func_01B012D0(-1, &ctx->pos, 0);
    ctx->pos.y -= 0.5f;
    ctx->fC4 = func_01B011A8(-1);
    ovl_09479_0cb8();
    D_01B05018 = 50;
    D_01B0501C = 0;
    func_01B03298(res, 0, 64, 256);
    func_01B02CB8(-1, D_01B04F88, D_01B00620);
    func_01B03A58(func_01B03890((void *)ovl_09479_0be0));
    return 0;
}

static inline void copy_vec(Vec4 *dst, Vec4 *src)
{
    MMI_COPY_LQ_A3(dst, src);
    MMI_COPY_SQ_A3(dst);
}

void ovl_09479_0be0(OvlTask *a0)
{
    if (D_01B05018 > 0) {
        if (--D_01B05018 <= 0) {
            func_01B01F98(-1, 0);
        }
    }
    func_01B02D70(D_01B04F88);
    func_01B02D70(D_01B04FA8);
    if (func_01B03CD0(&D_01B05020, D_01B05194) == 1 && D_01B0501C == 1) {
        func_01B03010(D_01B04F88, 2);
        func_01B03010(D_01B04FA8, 0);
        a0->w14 = 3;
        a0->p08->p10 = (s32)D_01B00A48;
    }
}

void ovl_09479_0cb8(void)
{
    float mat[4][4];
    Vec4 v40;
    Vec4 v50;
    Vec4 v60;
    Vec4 v70;
    Vec4 *dst;
    Vec4 *src;
    int i;
    OvlTask *t;

    func_01B012D0(0, &v40, 0);
    func_002DD128(mat);
    func_002DD318(mat, mat, func_01B011A8(0));
    copy_vec(&v50, &v40);
    dst = D_01B04FD0;
    copy_vec(dst, &v40);
    dst->w = func_01B011A8(0);

    src = D_01B005E0;
    for (i = 0; i < 3; i++) {
        func_002DCE08(&v70, mat, src);
        dst++;
        VU0_LQC2(1, 0, &v40);
        VU0_LQC2(2, 0, &v70);
        VU0_OP("vadd.xyz $vf1xyz, $vf1xyz, $vf2xyz");
        VU0_SQC2(1, 0, dst);
        func_01B04920(&v60, &v50, dst);
        dst->w = v60.y;
        copy_vec(&v50, dst);
        src++;
    }

    D_01B05014 = 40;
    *(s32 *)&D_01B05010 = 0;
    func_01B02D28(0, D_01B04FA8, D_01B00628);
    t = func_01B03890((void *)ovl_09479_0e10);
    t->b18 = 1;
    func_01B03A58(t);
}

void ovl_09479_0e10(void *a0)
{
    float pos[4];
    float t;

    if (--D_01B05014 == 0) {
        D_01B0501C = 1;
        func_01B03910(a0);
        return;
    }
    if (D_01B05014 == 10) {
        func_01B024B0(0, 10, 0.0f);
    }
    t = D_01B05010 + 0.1f;
    D_01B05010 = t;
    pos[0] = func_01B047D0(t, &D_01B04FD0[0].x, 4, 4);
    pos[1] = D_01B04FD0[0].y;
    pos[2] = func_01B047D0(t, &D_01B04FD0[0].z, 4, 4);
    pos[3] = 1.0f;
    func_01B01260(0, func_01B04CF8(t, &D_01B04FD0[0].w, 4, 4));
    func_01B01400(0, pos);
}
