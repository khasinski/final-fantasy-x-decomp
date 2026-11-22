#include "common.h"

typedef struct PppSys {
    u8 pad00[0x2C];
    void *p2C;
} PppSys;

typedef struct PppObj {
    u8 pad00[0xC4];
    float fC4;
    u8 padC8[0x8];
    float pos[4];
} PppObj;

typedef struct Cfg3C0 {
    s32 w00;
    s32 w04;
} Cfg3C0;

extern u8 D_01B00040[];
extern Cfg3C0 D_01B003C0;
extern u8 D_01B007B0[];
extern u8 D_01B00930[];
extern s32 D_01B04110;
extern PppSys D_01B04118;
extern PppObj D_01B04160;
extern u8 *D_01B04290;
extern u8 *D_01B04294;
extern u8 D_01B09510[];
extern u8 D_01B81A40[];

void func_01B009B0(s32 a0);
void *func_002B49A0(void *a0, s32 a1, s32 a2);
void func_01B03548(PppSys *sys, void *a1, void *a2, u32 a3);
void func_01B03620(PppSys *sys, PppObj *obj, s32 a2, s32 a3, float f0, s32 t0, void *t1);
void func_01B00D00(s32 a0, float *pos, s32 a2);
float func_01B00BD8(s32 a0);
void func_01B019C8(s32 a0, s32 a1);
void *func_01B032C0(void *fn);
void func_01B03488(void *task);

s32 func_01B00808(void)
{
    u8 *p = D_01B81A40;
    PppSys *mgr;
    PppObj *ctx;

    D_01B04290 = p;
    D_01B04294 = p + 0x40000;
    D_01B003C0.w00 = 0x14;
    D_01B003C0.w04 = 0;
    func_01B009B0(D_01B04110);

    mgr = &D_01B04118;
    mgr->p2C = func_002B49A0(D_01B09510, 8, 0);
    func_01B03548(mgr, D_01B00040, D_01B04290, 0x40000);
    ctx = &D_01B04160;
    func_01B03620(mgr, ctx, 0, 0, 0.04f, 0x96, D_01B00930);
    func_01B00D00(-1, ctx->pos, 0);
    ctx->fC4 = func_01B00BD8(-1);
    ctx->pos[1] -= 0.5f;
    func_01B019C8(-1, 0);

    func_01B03488(func_01B032C0(D_01B007B0));
    return 0;
}
