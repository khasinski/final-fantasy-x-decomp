#include "common.h"

typedef struct Ent10 {
    void *p00;
    void *p04;
    u8 pad08[0x8];
} Ent10; /* size 0x10 */

typedef struct ResObj {
    u8 pad00[0x4];
    u16 h04;
    u8 pad06[0xA];
    Ent10 ents[1];
} ResObj;

typedef struct Sub100 {
    u8 pad00[0x10];
    s32 w10;
    s32 w14;
    u32 w18;
    u32 w1C;
    u8 pad20[0xC];
    void *p2C;
} Sub100;

typedef struct NodeObj {
    u8 pad00[0x18];
    u8 b18;
    u8 pad19[0x5];
    u8 b1E;
    u8 pad1F[0x11];
    float f30[3];       /* 0x30 */
    float f3C;          /* 0x3C */
    u8 pad40[0xC];
    float f4C;          /* 0x4C */
    u8 pad50[0x40];
    float f90;          /* 0x90 */
    float f94;          /* 0x94 */
    u8 pad98[0x30];
    u32 wC8;            /* 0xC8 */
} NodeObj;

typedef struct CtxObj {
    u8 pad00[0x80];
    float mtx80[4][4];  /* 0x80 */
    float mtxC0[4][4];  /* 0xC0 */
    Sub100 sub100;      /* 0x100 */
    u8 pad130[0xEA];
    u16 h21A;           /* 0x21A */
    u8 pad21C[0x2];
    s8 b21E;            /* 0x21E */
    u8 pad21F[0x1];
    NodeObj *p220;      /* 0x220 */
    u8 pad224[0x9C];
    float mtx2C0[4][4]; /* 0x2C0 */
    u8 sub300[0x60];    /* 0x300 */
    void *arr360[1];    /* 0x360 */
} CtxObj;

typedef struct CmdObj {
    u8 pad00[0x2];
    s16 h02;
    s16 h04;
    s16 h06;
} CmdObj;

NodeObj *func_002960D0(void *a0, NodeObj *a1, s32 a2);
ResObj *func_002B09F8(Sub100 *a0, CtxObj *a1, void *a2, NodeObj *a3, s32 a4);
void func_002B0DC8(Sub100 *a0, CtxObj *a1, void *a2, NodeObj *a3, s16 *a4);
void *func_002A48D8(CtxObj *a0, NodeObj *a1);
void func_002B56D8(void *dst, void *a1, void *a2);
void func_002A6EB8(void *dst, u32 a1, float f0, float *a2, float *a3, s32 t0);
void func_002A4318(void *a0, s32 a1, void *a2);
void func_01B04818(void *a0, Sub100 *a1, NodeObj *a2, NodeObj *a3, void *t0);
void func_002B7CE8(ResObj *a0, Sub100 *a1, void *a2, s32 a3, s32 t0, void *t1, void *t2, float f0);

void *func_01B04478(CtxObj *ctx, CmdObj *cmd)
{
    u8 sp00[0x20];
    float mtx20[4][4];
    float mtx60[4][4];
    float mtxA0[4][4];
    void *s1 = ctx->sub300;
    NodeObj *s5 = ctx->p220;
    float f20 = 256.0f;
    void *mtxC0;
    void *mtx80;
    ResObj *res;
    void *p236;
    NodeObj *s6;
    u16 flags;
    Sub100 *s4;
    s32 alpha;

    p236 = ctx->arr360[s5->b1E];
    s6 = func_002960D0(s1, s5, cmd->h02);
    flags = ctx->h21A;
    if (flags & 0x800) {
        f20 = s6->f3C;
    }

    switch (flags & 0xF000) {
    case 0x1000: {
        float *s0 = &s5->f90;
        Ent10 *ent;

        s4 = &ctx->sub100;
        res = func_002B09F8(s4, ctx, s1, s5, cmd->h06);
        func_002B0DC8(s4, ctx, s1, s5, &cmd->h06);
        mtx80 = ctx->mtx80;
        {
            void *tmp = func_002A48D8(ctx, s5);
            ent = res->ents;
            func_002B56D8(mtx60, ctx->mtx2C0, tmp);
        }
        mtxC0 = ctx->mtxC0;
        s4->w10 = (s32)s6->f90 << 16;
        s4->w14 = (s32)s6->f94 << 16;
        alpha = (s32)s6->f4C;
        if (alpha >= 255) {
            alpha = 255;
        }
        if (alpha < 0) {
            alpha = 0;
        }
        s4->w18 = s6->wC8;
        ((u8 *)&s4->w18)[3] = alpha;
        func_002A6EB8(mtxA0, s5->b18, f20, s5->f30, s0, ctx->b21E);
        func_002A6EB8(mtx80, s5->b18, f20, s6->f30, s0, ctx->b21E);
        func_002A4318(p236, cmd->h04, sp00);
        s4->p2C = mtx20;
        alpha = res->h04;
        while (alpha > 0) {
            alpha--;
            func_002B56D8(mtx20, mtxA0, ent->p04);
            func_002B56D8(mtxC0, mtx60, mtx20);
            func_002B56D8(mtx20, mtx80, ent->p04);
            func_01B04818(ent->p00, s4, s5, s6, sp00);
            ent++;
        }
        cmd = (CmdObj *)((u8 *)cmd + 0x10);
        break;
    }
    case 0x2000: {
        float *s1p = &s5->f90;

        s4 = &ctx->sub100;
        res = func_002B09F8(s4, ctx, s1, s5, cmd->h06);
        mtx80 = ctx->mtx80;
        {
            void *tmp = func_002A48D8(ctx, s5);
            func_002B56D8(mtx60, ctx->mtx2C0, tmp);
        }
        s4->w10 = (s32)s6->f90 << 16;
        s4->w14 = (s32)s6->f94 << 16;
        s4->w18 = s6->wC8;
        s4->w1C = s5->wC8;
        alpha = (s32)s6->f4C;
        if (alpha >= 255) {
            alpha = 255;
        }
        if (alpha < 0) {
            alpha = 0;
        }
        ((u8 *)&s4->w18)[3] = alpha;
        func_002A6EB8(mtxA0, s5->b18, f20, s5->f30, s1p, ctx->b21E);
        func_002A6EB8(mtx80, s5->b18, f20, s6->f30, s1p, ctx->b21E);
        func_002A4318(p236, cmd->h04, sp00);
        cmd = (CmdObj *)((u8 *)cmd + 0x08);
        func_002B7CE8(res, s4, mtxA0, 0, 0, sp00, mtx80, s5->f3C * 16.0f);
        break;
    }
    }
    return cmd;
}
