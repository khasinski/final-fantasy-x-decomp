/* EE Battle-Effect Overlay: group 0x11, file 09393 (0x01B01140..0x01B012D4)
 * Load base: 0x01B00000, .text: 0x01B01140..0x01B012D4 (1 function)
 */
#include "common.h"
#include "vu0.h"

typedef struct Vec4 {
    float x, y, z, w;
} Vec4;

typedef struct OvlCtx {
    u8 pad00[0xC4];
    float fC4;
    u8 padC8[0x08];
    Vec4 pos;
    Vec4 vecE0;
    u8 padF0[0x40];
} OvlCtx;

typedef struct Sub30 {
    u8 pad00[0x04];
    int w04;
    float f08;
    int w0C;
    float f10;
    float f14;
    int w18;
    u8 pad1C[0x08];
    int w24;
    u8 pad28[0x04];
    u16 h2C;
    u8 pad2E[0x02];
} Sub30;

typedef struct Sub1A60 {
    u8 pad00[0x14];
    float f14;
} Sub1A60;

typedef struct Work09393 {
    u8 pad0000[0x4C0];
    OvlCtx ctx[5];       /* 0x4C0 */
    u8 pad0AB0[0xF64];
    float unk1A14;       /* 0x1A14 */
    u8 pad1A18[0x08];
    Vec4 unk1A20;        /* 0x1A20 */
    Sub30 unk1A30;       /* 0x1A30 */
    Sub1A60 unk1A60;     /* 0x1A60 */
} Work09393;

extern Vec4 D_01B00590[5];
extern int D_01B005E0[5];
extern u8 D_01B07AE8[];
extern Work09393 *D_01B07C10;

float func_002B3DF8(float);
void func_01B045C0(void *, void *, int, int, float, int, void *);
void func_01B075C0(void *, int);
void func_01B078A0(void *, int, int, float, float);

void func_01B01140(void)
{
    Work09393 *w = D_01B07C10;
    OvlCtx *ctx = w->ctx;
    Vec4 *vpos = &w->unk1A20;
    Sub30 *sub = &w->unk1A30;
    Sub1A60 *sub2 = &w->unk1A60;
    int i;

    for (i = 0; i < 5; i++) {
        func_01B045C0(D_01B07AE8, ctx, 2, D_01B005E0[i],
                      (func_002B3DF8(0.5f) + 1.0f) * 0.15f, 0, 0);
        ctx->fC4 = w->unk1A14;
        {
            Vec4 *vp = &ctx->pos;
            MMI_COPY_LQ_A3(vp, vpos);
            MMI_COPY_SQ_A3(vp);
        }
        {
            Vec4 *ve = &ctx->vecE0;
            Vec4 *vs = &D_01B00590[i];
            MMI_COPY_LQ_A3(ve, vs);
            MMI_COPY_SQ_A3(ve);
        }
        ctx++;
    }

    func_01B075C0(sub, 0x19);
    sub->w04 = 0;
    sub->w0C = 0;
    sub->w18 = 0;
    sub->f08 = 0.2f;
    sub->f10 = 5.0f;
    sub->f14 = 5.0f;
    sub->h2C |= 3;
    sub->w24 = 0xC;
    func_01B078A0(sub2, 0x1E, 0, 1.0f, 0.5f);
    sub2->f14 = 0.65f;
}
