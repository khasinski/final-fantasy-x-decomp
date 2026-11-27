#include "common.h"

typedef unsigned long u_long64;

typedef struct F3aMat {
    float m[4][4];
} F3aMat;

typedef struct F3aWork {
    u8 pad00[0x10];
    u_long64 u10;
    u32 u18;
    u32 u1C;
    u8 pad20[0x0C];
    void *p2C;
    u8 pad30[0x1C];
    u8 b4C;
    s8 b4D;
} F3aWork;

typedef struct F3aSub {
    u8 pad00[0x18];
    u8 b18;
    u8 pad19[5];
    u8 b1E;
    u8 pad1F[0x11];
    u8 m30[0x60];
    u8 m90[0x18];
    u16 hA8;
    u16 hAA;
} F3aSub;

typedef struct F3aCtx {
    u8 pad00[0x80];
    F3aMat m80;
    F3aMat mC0;
    F3aWork work;
    u8 pad150[0xC2];
    s16 h212;
    u8 pad214[6];
    s16 h21A;
    u8 pad21C[2];
    s8 b21E;
    u8 pad21F;
    F3aSub *sub;
    u8 pad224[0x9C];
    F3aMat m2C0;
    u8 m300[0x60];
    void *ptrs[1];
} F3aCtx;

typedef struct F3aListEntry {
    void *p00;
    void *p04;
    u32 pad08;
    u32 pad0C;
} F3aListEntry;

typedef struct F3aList {
    u32 pad00;
    u16 count;
    u8 pad06[10];
    F3aListEntry ents[1];
} F3aList;

void *func_002960D0(void *a0, void *a1, s32 a2);
F3aList *func_002B09F8(void *a0, void *a1, void *a2, void *a3, s32 a4);
void func_002B0DC8(void *a0, void *a1, void *a2, void *a3, void *a4);
void *func_002A48D8(void *a0, void *a1);
void func_002B56D8(void *dst, void *a, void *b);
void func_002A6EB8(void *dst, u32 a1, float f0, void *a2, void *a3, s32 a4);
s32 func_01B05E50(void *a0, void *a1, void *a2, void *a3);
u8 *func_002A0820(void *a0, void *a1, void *a2, s32 a3);
F3aList *func_002B49A0(void *a0, s32 a1, s32 a2);
u8 *func_002A7318(void *a0, u32 a1);
void func_002B5880(void *dst, void *a, void *b);
void func_002B5978(void *dst, void *src, float f0);

u8 *func_01B05B40(F3aCtx *ctx, u8 *cmd)
{
    u8 pad[0x20];
    F3aMat m0;
    F3aMat m1;
    F3aMat m2;
    F3aSub *sub = ctx->sub;
    u8 *p300 = ctx->m300;
    void *p0 = ctx->ptrs[sub->b1E];
    u8 *obj;
    F3aList *list;
    F3aListEntry *ent;

    switch (ctx->h21A & 0xF000) {
    case 0x1000: {
        F3aWork *work = &ctx->work;
        F3aMat *pC0;
        F3aMat *p80;
        s32 i;
        u8 *sub90 = sub->m90;
        void *tmp;

        obj = (u8 *)func_002960D0(p300, sub, *(s16 *)(cmd + 2));
        list = func_002B09F8(work, ctx, p300, sub, *(s16 *)(cmd + 4));
        func_002B0DC8(work, ctx, p300, sub, cmd + 4);
        pC0 = &ctx->mC0;
        p80 = &ctx->m80;
        work->b4D = 0;
        *(volatile u8 *)&work->b4C = 0x80;
        *(volatile u_long64 *)&work->u10 = 0;
        work->u18 = *(volatile u32 *)(obj + 0xC8);
        *(volatile u32 *)&work->u1C = 0;
        *(volatile u16 *)&sub->hA8 = 0;
        *(volatile u16 *)&sub->hAA = 0;
        tmp = func_002A48D8(ctx, sub);
        func_002B56D8(&m1, &ctx->m2C0, tmp);
        func_002A6EB8(&m2, sub->b18, 256.0f, sub->m30, sub90, ctx->b21E);
        func_002A6EB8(p80, sub->b18, 256.0f, 0, sub90, ctx->b21E);
        work->p2C = &m0;
        ent = list->ents;
        for (i = 0; i < list->count; i++, ent++) {
            u16 ret;
            func_002B56D8(&m0, &m2, ent->p04);
            func_002B56D8(pC0, &m1, &m0);
            func_002B56D8(&m0, p80, ent->p04);
            ret = (u16)func_01B05E50(ent->p00, work, sub, obj);
            if (ret != 0) {
                sub->hA8 = ret;
                sub->hAA = i;
            }
        }
        cmd += 14;
        break;
    }
    case 0x2000:
        if (ctx->h212 != 0) {
            return cmd + 6;
        }
        if (sub->hA8 != 0) {
            obj = func_002A0820(p300, sub, cmd + *(s16 *)(cmd + 2), 1);
            if (obj != 0) {
                u32 idx;
                u8 *data;
                u8 *vert;

                list = func_002B49A0(p0, 4, *(s16 *)(cmd + 4));
                idx = sub->hAA;
                ent = list->ents;
                ent += idx;
                data = func_002A7318(list, idx);
                vert = data + *(u32 *)(data + 8) + (sub->hA8 << 4);

                func_002A6EB8(ctx, sub->b18, 256.0f, sub->m30, sub->m90, ctx->b21E);
                func_002B56D8(ctx, ctx, ent->p04);
                func_002B5880(obj + 0x90, ctx, vert);
                func_002B5978(obj + 0x40, obj + 0x90, 16.0f);
                *(u32 *)(obj + 0x4C) = 0;
            }
        }
        cmd += 6;
        break;
    }
    return cmd;
}
