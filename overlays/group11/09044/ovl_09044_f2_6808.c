#include "common.h"
#include "vu0.h"

typedef struct F2Work5 {
    u8 pad00[0x14];
    float f14;          /* 0x14 */
    u8 pad18[0xC];
    float f24;          /* 0x24 */
} F2Work5;

typedef struct F2Sub {
    u8 pad00[0x18];
    u8 chr;             /* 0x18 */
    u8 pad19[5];
    u8 b1E;             /* 0x1E */
    u8 pad1F[0x11];
    float pos[3];       /* 0x30 */
    float f3C;          /* 0x3C */
    float f40;          /* 0x40 */
    float f44;          /* 0x44 */
    u8 pad48[0x48];
    float rot[4];       /* 0x90 */
    u8 padA0[0x1C];
    void *work;         /* 0xBC */
} F2Sub;

typedef struct F2DrawCtx {
    u8 pad00[0x24];
    void *p24;          /* 0x24 */
    void *p28;          /* 0x28 */
    void *p2C;          /* 0x2C */
} F2DrawCtx;

typedef struct F2Th {
    float m00[4][4];    /* 0x000 */
    float m40[4][4];    /* 0x040 */
    float m80[4][4];    /* 0x080 */
    float mC0[4][4];    /* 0x0C0 */
    F2DrawCtx ctx;      /* 0x100 */
    u8 pad130[0xEA];
    s16 op;             /* 0x21A */
    u8 pad21C[2];
    s8 b21E;            /* 0x21E */
    u8 pad21F[1];
    F2Sub *sub;         /* 0x220 */
    u8 pad224[0x9C];
    float m2C0[4][4];   /* 0x2C0 */
    u8 obj300[0x60];    /* 0x300 */
    void *res360[18];   /* 0x360 */
    void *heap;         /* 0x3A8 */
} F2Th;

typedef struct F2Part {
    void *p00;
    void *m04;
    u32 u08;
    u32 u0C;
} F2Part;

typedef struct F2Model {
    u32 u00;
    u16 count;          /* 0x04 */
    u16 u06;
    u32 u08;
    u32 u0C;
    F2Part parts[1];    /* 0x10 */
} F2Model;

void *op_malloc(void *heap, int size);
F2Sub *opus_no_get(void *obj300, F2Sub *sub, int id);
void *opus_local_get(F2Th *th, F2Sub *sub);
void opus_rt_m_chara(void *dst, int chr, void *pos, float *rot, float scale, int flag);
F2Model *rcefChrDraw(F2DrawCtx *ctx, F2Th *th, void *obj300, F2Sub *sub, int id);
void func_002B0DC8(F2DrawCtx *ctx, F2Th *th, void *obj300, F2Sub *sub, s16 *pc);
void *op_oef2_a_get(void *res, int type, int id);
void func_002B56D8(void *dst, void *a, void *b);
void func_002B5978(void *dst, void *src, float scale);

void func_01B06C10(void *work, int n);
void func_01B06CA8(void *work, float *rot, F2Th *th);
void func_01B06D28(void *work, F2Th *th);
int func_01B06FD0(void *a, int n);
void func_01B07018(void *work, void *a, void *m80, int n);
void func_01B07110(void *a, F2Work5 *work, void *other_work, void *m80, void *ptr, float f);
void func_01B07490(F2Work5 *work);
int func_01B07518(void *p00, F2DrawCtx *ctx, F2Sub *sub, F2Sub *other, void *work, int flag);

s16 *func_01B06808(F2Th *th, s16 *pc)
{
    float m00[4][4];
    float m40[4][4];
    float m80[4][4];
    int flag;
    void *obj;
    F2Sub *sub;
    void *res;
    int n;
    void *a;
    F2Work5 *work;
    void *other_work;
    F2Sub *other;
    F2DrawCtx *ctx;
    F2Part *part;
    void *m80_p;
    void *mC0_p;
    void *m40_p;
    int i;
    float f;

    sub = th->sub;
    obj = th->obj300;
    res = th->res360[sub->b1E];

    switch (th->op & 0xF000) {
    case 0x0000:
        n = pc[1];
        pc += 2;
        func_01B06C10(sub->work = op_malloc(th->heap, n * 32 + 16), n);
        break;
    case 0x1000:
        func_002B5978(th, sub->pos, 1.0f / 256);
        pc += 1;
        func_01B06CA8(sub->work, sub->rot, th);
        break;
    case 0x2000:
        a = opus_local_get(th, sub);
        pc += 1;
        func_002B56D8(th, th->m2C0, a);
        func_01B06D28(sub->work, th);
        break;
    case 0x4000:
        m80_p = th->m80;
        a = op_oef2_a_get(res, 4, pc[1]);
        n = pc[2];
        work = sub->work = op_malloc(th->heap, func_01B06FD0(a, n));
        MMI_SQ_ZERO(0, th);
        pc += 3;
        opus_rt_m_chara(m80_p, sub->chr, th, sub->rot, 256.0f, th->b21E);
        func_01B07018(work, a, m80_p, n);
        break;
    case 0x5000:
        work = sub->work;
        other_work = opus_no_get(obj, sub, pc[3])->work;
        m80_p = th->m80;
        other = opus_no_get(obj, sub, pc[1]);
        MMI_SQ_ZERO(0, th);
        th->m00[0][1] = sub->pos[1];
        opus_rt_m_chara(m80_p, sub->chr, th, sub->rot, 256.0f, th->b21E);
        f = work->f24 - (work->f24 - work->f14) * other->f44 * (1.0f / 256);
        a = op_oef2_a_get(res, 4, pc[2]);
        pc += 4;
        func_01B07110(a, work, other_work, m80_p, (void *)0x01F80000, f);
        func_01B07490(work);
        break;
    case 0x6000:
        m80_p = th->m80;
        m40_p = th->m40;
        mC0_p = th->mC0;
        MMI_SQ_ZERO(0, th);
        th->m00[0][1] = sub->pos[1];
        flag = 0;
        ctx = &th->ctx;
        opus_rt_m_chara(m80_p, sub->chr, th, sub->rot, 256.0f, th->b21E);
        a = rcefChrDraw(ctx, th, obj, sub, pc[2]);
        ctx->p2C = m80;
        ctx->p24 = m40;
        ctx->p28 = m00;
        func_002B0DC8(ctx, th, obj, sub, pc + 2);
        part = ((F2Model *)a)->parts;
        {
            void *local = opus_local_get(th, sub);
            func_002B56D8(m40_p, th->m2C0, local);
        }
        other = opus_no_get(obj, sub, pc[1]);
        work = sub->work;
        for (i = ((F2Model *)a)->count; i > 0; i--, part++) {
            func_002B56D8(m80, m80_p, part->m04);
            func_002B56D8(mC0_p, m40_p, m80);
            flag = func_01B07518(part->p00, ctx, sub, other, work, flag);
        }
        pc += 7;
        break;
    }
    return pc;
}
