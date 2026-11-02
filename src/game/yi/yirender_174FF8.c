/* tu_124 0x174ff8-0x178648: low; ~yiRender (config/tu_map.tsv) */
#include "common.h"
#include "ffx/q3.h"
#include "ffx/w2.h"
#include "ffx/r1.h"
#include "ffx/v1.h"
#define MsSetCameraMatrix v2_MsSetCameraMatrix /* DEBT(TYPE): this header's guess conflicts with the TU */
#include "ffx/v2.h"
#undef MsSetCameraMatrix
#include "ffx/r2.h"
#include "ffx/s2.h"

int func_00174FF8(float *out, int i)
{
    int k;

    if (i < D_00597F00.w68260) {
        for (k = 0; k < 4; k++) {
            out[k] = D_00597F00.v68270[i][k];
        }
        return 1;
    }
    return 0;
}

void func_00175060(int a, int b, int c, int d)
{
    D_00597F00.fBCB4C = a;
    D_00597F00.fBCB50 = b;
    D_00597F00.fBCB54 = c;
    D_00597F00.fBCB58 = d;
}

void func_001750A8(int v)
{
    yiRenderEnable(0x100);
    D_00597F00.w67F44 = v;
}

void func_001750E8(float a, float b, float c, float d) {
    D_00597F00.fBCB4C = a;
    D_00597F00.fBCB50 = b;
    D_00597F00.fBCB54 = c;
    D_00597F00.fBCB58 = d;
}

void func_00175110(float a, float b, float c, float d, float e, float f) {
    D_00597F00.fBCB5C = a;
    D_00597F00.fBCB60 = b;
    D_00597F00.fBCB64 = c;
    D_00597F00.fBCB68 = d;
    D_00597F00.fBCB6C = e;
    D_00597F00.fBCB70 = f;
}

void func_00175140(void) {
    yiRenderDisable(256);
}

void func_00175148(int a, int b) {
    func_0018B7A0(&D_00597F00, a, b);
}

int func_00175160(u32 i, int *a, int *b)
{
    if (i >= D_00597F00.w687B8) {
        return -1;
    }
    D_00597F00.ent[i].rgbaA0[0] = a[0];
    D_00597F00.ent[i].rgbaA0[1] = a[1];
    D_00597F00.ent[i].rgbaA0[2] = a[2];
    D_00597F00.ent[i].rgbaA0[3] = a[3];
    D_00597F00.ent[i].rgbaA4[0] = b[0];
    D_00597F00.ent[i].rgbaA4[1] = b[1];
    D_00597F00.ent[i].rgbaA4[2] = b[2];
    D_00597F00.ent[i].rgbaA4[3] = b[3];
    return 0;
}

int func_001751E8(u32 i, int *a, int *b)
{
    if (i >= D_00597F00.w687B8) {
        return -1;
    }
    a[0] = D_00597F00.ent[i].rgbaA0[0];
    a[1] = D_00597F00.ent[i].rgbaA0[1];
    a[2] = D_00597F00.ent[i].rgbaA0[2];
    a[3] = D_00597F00.ent[i].rgbaA0[3];
    b[0] = D_00597F00.ent[i].rgbaA4[0];
    b[1] = D_00597F00.ent[i].rgbaA4[1];
    b[2] = D_00597F00.ent[i].rgbaA4[2];
    b[3] = D_00597F00.ent[i].rgbaA4[3];
    return 0;
}

INCLUDE_ASM("build/ee_asm/game/yi/yirender_174FF8", func_00175270);

int yiGetVCount(void) {
    return D_00307F30;
}

int yiGetFCount(void) {
    return D_00307F2C << 1;
}

void func_00175358(V1Record1753 *record)
{
    s32 remaining;
    s16 *value;

    record->w00 = 0;
    remaining = 3;
    record->w2C = 0;
    value = &record->values[3];
    record->w34 = 0;
    record->w24 = 0;
    record->w04 = 0;
    record->h1C = 0;
    record->w3C = 0;
    record->w40 = 0;
    record->w08 = 0;
    do
    {
        *value = 0;
        remaining -= 1;
        value -= 1;
    } while (remaining >= 0);
    record->scale = 1.0f;
    /* DEBT(ORDER): chained color writes preserve original store scheduling. */
    record->color[4] = record->color[5] = record->color[6] = record->color[7] =
        record->color[0] = record->color[1] = record->color[2] = record->color[3] = 0x80;
}

INCLUDE_ASM("build/ee_asm/game/yi/yirender_174FF8", yiRender_setfogparam);

INCLUDE_ASM("build/ee_asm/game/yi/yirender_174FF8", func_00175468);

INCLUDE_ASM("build/ee_asm/game/yi/yirender_174FF8", func_00175C08);

void func_00175D50(Sys597F00 *s) {
    func_0017DC70(s->wBCB10);
    func_0017DC70(s->wBCB20);
}

void func_00175D88(Sys597F00 *s) {
    s->w9E7D8 = 0;
    s->wC0E14 = 0;
    s->wC0E18 = 0;
    s->w67F4C = -1;
}

INCLUDE_ASM("build/ee_asm/game/yi/yirender_174FF8", yiRender_resetobj);

void yiRender_reset(Sys597F00 *p) {
    yiRender_resetobj(p);
    func_00175D88(p);
}

void func_00175F58(void *p)
{
    Sys597F00 *s = p;

    yiRender_reset(s);
    func_0017DC70((struct Q3Ent *)s->wBCB10); /* DEBT(CAST): wBCB10 holds a buffer */
    func_0017DC70((struct Q3Ent *)s->wBCB20); /* DEBT(CAST) */
    s->wBCB10 = 0;
    s->wBCB14 = 0;
    s->wBCB20 = 0;
    s->wBCB24 = 0;
}

INCLUDE_ASM("build/ee_asm/game/yi/yirender_174FF8", func_00175FA8);

INCLUDE_ASM("build/ee_asm/game/yi/yirender_174FF8", func_00176138);

void func_00176360(void) {
}

INCLUDE_ASM("build/ee_asm/game/yi/yirender_174FF8", func_00176368);

INCLUDE_ASM("build/ee_asm/game/yi/yirender_174FF8", func_001764A0);

INCLUDE_ASM("build/ee_asm/game/yi/yirender_174FF8", func_001765D0);

INCLUDE_ASM("build/ee_asm/game/yi/yirender_174FF8", func_001766D0);

INCLUDE_ASM("build/ee_asm/game/yi/yirender_174FF8", func_00176778);

INCLUDE_ASM("build/ee_asm/game/yi/yirender_174FF8", yiRender_setupparamVU1);

INCLUDE_ASM("build/ee_asm/game/yi/yirender_174FF8", yiRender_setupparamGS);

void func_00178520(V2Blk40 *src, R2Qw *p, int addr) {
    p->w[1] = 0;
    p->w[2] = 0;
    p->w[0] = 0x20000005;
    p->w[3] = 0;
    p++;
    p->w[0] = 0x11000000;
    p->w[2] = 0x1000101;
    p->w[3] = addr | 0x6C040000;
    p->w[1] = 0;
    p++;
    *(V2Blk40 *)p = *src; /* DEBT(CAST) */
}

void func_001785A8(V2Blk40 *src, R2Qw *p, int addr) {
    p->w[0] = 0;
    p->w[1] = 0;
    p->w[3] = addr | 0x6C040000;
    p->w[2] = 0;
    p++;
    *(V2Blk40 *)p = *src; /* DEBT(CAST) */
}

void func_00178608(S2Ctx *ctx, V2Cmd *c) {
    switch (c->kind) {
    case 0x10:
        func_0018B5A8(ctx, c->addr, c->h1A, c->h16);
        break;
    case 0x100:
        func_0018B558(ctx, c->addr, c->h1A);
        break;
    }
}
