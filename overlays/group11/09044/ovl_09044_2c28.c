#include "common.h"
#include "vu0.h"

void *op_oef2_a_get(void *res, int type, int id);
void opus_rt_m_chara(void *dst, int chr, void *pos, float *rot, float scale, int flag);
void *rcefChrDraw(void *ctx, void *th, void *obj300, void *sub, int id);
void func_002B0DC8(void *ctx, void *th, void *obj300, void *sub, s16 *pc);
void *opus_local_get(void *th, void *sub);
void func_002B56D8(void *dst, void *a, void *b);
void *opus_no_get(void *obj300, void *sub, int id);
void func_01B02F68(void *a0, void *a1, void *a2, void *a3);
void func_01B03078(void *p00, void *ctx, void *sub, void *other, void *pD0);

typedef struct F2bSub {
    u8 pad00[0x18];
    u8 chr;             /* 0x18 */
    u8 pad19[5];
    u8 b1E;             /* 0x1E */
    u8 pad1F[0x11];
    float pos[3];       /* 0x30 */
    u8 pad3C[0x54];
    float rot[4];       /* 0x90 */
    u8 padA0[0x30];
    float vD0[4];       /* 0xD0 */
    float vE0[4];       /* 0xE0 */
} F2bSub;

typedef struct F2bDrawCtx {
    u8 pad00[0x24];
    void *p24;
    void *p28;
    void *p2C;
} F2bDrawCtx;

typedef struct F2bTh {
    float m00[4][4];    /* 0x000 */
    float m40[4][4];    /* 0x040 */
    float m80[4][4];    /* 0x080 */
    float mC0[4][4];    /* 0x0C0 */
    F2bDrawCtx ctx;     /* 0x100 */
    u8 pad130[0xEA];
    s16 op;             /* 0x21A */
    u8 pad21C[0x2];
    s8 b21E;            /* 0x21E */
    u8 pad21F[0x1];
    F2bSub *sub;        /* 0x220 */
    u8 pad224[0x9C];
    float m2C0[4][4];   /* 0x2C0 */
    u8 obj300[0x60];    /* 0x300 */
    void *res360[18];   /* 0x360 */
} F2bTh;

typedef struct F2bPart {
    void *p00;
    void *m04;
    u32 u08;
    u32 u0C;
} F2bPart;

typedef struct F2bModel {
    u32 u00;
    u16 count;
    u16 u06;
    u32 u08;
    u32 u0C;
    F2bPart parts[1];
} F2bModel;

s16 *func_01B02C28(F2bTh *th, s16 *pc)
{
    float m00[4][4];
    float m40[4][4];
    float m80[4][4];
    void *obj;
    F2bSub *sub;
    void *res;
    void *a;
    F2bSub *other;
    F2bDrawCtx *ctx;
    F2bPart *part;
    void *m80_p;
    void *m40_p;
    void *mC0_p;
    void *vD0;
    int i;

    sub = th->sub;
    obj = th->obj300;
    res = th->res360[sub->b1E];

    switch (th->op & 0xF000) {
    case 0x0000:
        m80_p = th->m80;
        a = op_oef2_a_get(res, 4, pc[1]);
        vD0 = sub->vD0;
        pc += 2;
        opus_rt_m_chara(m80_p, sub->chr, th, sub->rot, 256.0f, th->b21E);
        func_01B02F68(a, m80_p, vD0, sub->vE0);
        break;
    case 0x1000:
        m80_p = th->m80;
        m40_p = th->m40;
        mC0_p = th->mC0;
        MMI_SQ_ZERO(0, th);
        th->m00[0][1] = sub->pos[1];
        ctx = &th->ctx;
        opus_rt_m_chara(m80_p, sub->chr, th, sub->rot, 256.0f, th->b21E);
        vD0 = sub->vD0;
        a = rcefChrDraw(ctx, th, obj, sub, pc[2]);
        ctx->p2C = m00;
        ctx->p28 = m40;
        ctx->p24 = m80;
        func_002B0DC8(ctx, th, obj, sub, pc + 2);
        part = ((F2bModel *)a)->parts;
        {
            void *local = opus_local_get(th, sub);
            func_002B56D8(m40_p, th->m2C0, local);
        }
        other = opus_no_get(obj, sub, pc[1]);
        for (i = ((F2bModel *)a)->count; i > 0; i--, part++) {
            func_002B56D8(m00, m80_p, part->m04);
            func_002B56D8(mC0_p, m40_p, m00);
            func_01B03078(part->p00, ctx, sub, other, vD0);
        }
        pc += 7;
        break;
    }
    return pc;
}
