#include "p9_overlay.h"
#include "vu0.h"

struct Ovl09086Cam;
struct Ovl09086Ctx;

typedef struct Ovl09086Vtbl {
    u8 pad0[0x1C];
    void (*update)(struct Ovl09086Ctx *);
} Ovl09086Vtbl;

typedef struct Ovl09086VecNode {
    Ovl09086Vtbl *vtbl;
    u8 pad4[0x1C];
    union {
        float f[4];
        int i[4];
        u_long128 q;
    } vec20;
} Ovl09086VecNode;

typedef struct Ovl09086MtxNode {
    Ovl09086Vtbl *vtbl;
    u8 pad4[0x9C];
    float mtxA0[4][4];
} Ovl09086MtxNode;

typedef struct Ovl09086Cam {
    Ovl09086Vtbl *vtbl;         /* 0x00 */
    u8 pad4[4];
    struct Ovl09086Cam *next;   /* 0x08 */
    u8 padC[4];
    struct Ovl09086Cam *child;  /* 0x10 */
    u8 pad14[6];
    u8 tick;                    /* 0x1A */
    u8 pad1B[5];
    float mtx20[4][4];          /* 0x20 */
    float mtx60[4][4];          /* 0x60 */
    float mtxA0[4][4];          /* 0xA0 */
    float mtxE0[4][4];          /* 0xE0 */
    int unk120[3];              /* 0x120 */
    struct Ovl09086Cam *parent; /* 0x12C */
    float unk130[4];            /* 0x130 */
    Ovl09086VecNode *unk140;    /* 0x140 */
    Ovl09086VecNode *unk144;    /* 0x144 */
    Ovl09086VecNode *unk148;    /* 0x148 */
    u8 unk14C;                  /* 0x14C */
    u8 pad14D[3];
    float unk150[4];            /* 0x150 */
    Ovl09086MtxNode *unk160;    /* 0x160 */
    Ovl09086MtxNode *unk164;    /* 0x164 */
    Ovl09086VecNode *unk168;    /* 0x168 */
    Ovl09086VecNode *unk16C;    /* 0x16C */
    float unk170;               /* 0x170 */
    void *unk174;               /* 0x174 */
    float unk178;               /* 0x178 */
    u8 unk17C;                  /* 0x17C */
} Ovl09086Cam;

typedef struct Ovl09086Ctx {
    void *node;
    u8 dirty;
    u8 tick;
    u8 pad[10];
} Ovl09086Ctx;

extern void (*D_01B059B0[])(float (*)[4], float *);

void func_002DD038(float dst[4], float a[4], float b[4]);
void func_002DD050(float dst[4], float a[4], float b[4]);
void func_002DD068(float dst[4], float src[4], float s);
void func_002DD0B0(float dst[4], float src[4]);
void func_002DD0C0(float dst[4][4], float src[4][4]);
void func_001A7840(void *cam, int idx, float v[4]);

static inline void call_update(Ovl09086Ctx *sub, void *node, u8 tick)
{
    sub->tick = tick;
    sub->node = node;
    ((Ovl09086Cam *)node)->vtbl->update(sub);
}

static inline void update_base(Ovl09086Ctx *ctx)
{
    Ovl09086Cam *node = (Ovl09086Cam *)ctx->node;
    Ovl09086Cam *parent = node->parent;

    if (node->tick == ctx->tick) {
        ctx->dirty = 0;
    } else {
        Ovl09086Cam *child = node->child;
        while (child != node) {
            ctx->node = child;
            child = child->next;
            ((Ovl09086Cam *)ctx->node)->vtbl->update(ctx);
        }
        ctx->node = node;
        node->tick = ctx->tick;
        ctx->dirty = 1;
    }

    if (ctx->dirty & 1) {
        float tmp20[4];
        Ovl09086Ctx sub30;
        Ovl09086Ctx sub40;
        Ovl09086Ctx sub50;
        Ovl09086Ctx sub60;

        call_update(&sub30, node->unk140, ctx->tick);
        call_update(&sub40, node->unk148, ctx->tick);
        call_update(&sub50, node->unk144, ctx->tick);
        if (node->parent != 0) {
            call_update(&sub60, node->parent, ctx->tick);
        }

        D_01B059B0[node->unk14C](node->mtx60, node->unk148->vec20.f);
        func_002DD068(tmp20, node->unk144->vec20.f, node->unk144->vec20.f[3]);
        func_002DD068(node->mtx20[0], node->mtx60[0], tmp20[0]);
        func_002DD068(node->mtx20[1], node->mtx60[1], tmp20[1]);
        func_002DD068(node->mtx20[2], node->mtx60[2], tmp20[2]);
        func_002DD0B0(node->mtx20[3], node->unk140->vec20.f);

        if (parent == 0) {
            *(u_long128 *)node->unk120 = node->unk148->vec20.q;
            func_002DD0B0(node->unk130, node->unk144->vec20.f);
            func_002DD0C0(node->mtxE0, node->mtx60);
            func_002DD0C0(node->mtxA0, node->mtx20);
        } else {
            node->unk120[0] = parent->unk120[0] + node->unk148->vec20.i[0];
            node->unk120[1] = parent->unk120[1] + node->unk148->vec20.i[1];
            node->unk120[2] = parent->unk120[2] + node->unk148->vec20.i[2];
            func_002DD050(node->unk130, parent->unk130, node->unk144->vec20.f);
            func_002DCE38(node->mtxE0, parent->mtxE0, node->mtx60);
            func_002DCE38(node->mtxA0, parent->mtxA0, node->mtx20);
            func_002DCE08(node->mtxA0[3], parent->mtxE0, node->mtx20[3]);
            VU0_LQC2_INPUTS(1, node->mtxA0[3], parent->mtxA0[3], node->mtxA0[3]);
            VU0_LQC2(2, 0, parent->mtxA0[3]);
            VU0_LQC2(3, 0, node->mtxA0[3]);
            VU0_OP("vadd.xyz $vf3, $vf1, $vf2");
            VU0_SQC2(3, 0, node->mtxA0[3]);
        }
    }
}

void func_01B0A330(Ovl09086Ctx *ctx)
{
    float v0[4];
    float v10[4];

    update_base(ctx);

    if (ctx->dirty & 1) {
        Ovl09086Ctx sub20;
        Ovl09086Ctx sub30;
        Ovl09086Cam *n = (Ovl09086Cam *)ctx->node;

        sub20.tick = ctx->tick;
        sub20.node = n->unk168;
        n->unk168->vtbl->update(&sub20);
        sub20.node = n->unk16C;
        n->unk16C->vtbl->update(&sub20);

        sub30.tick = ctx->tick;
        sub30.node = n->unk160;
        n->unk160->vtbl->update(&sub30);
        sub30.node = n->unk164;
        n->unk164->vtbl->update(&sub30);

        func_002DCE08(v10, n->unk164->mtxA0, n->unk16C->vec20.f);
        func_001A7840(n->unk174, 1, v10);

        if (n->unk17C & 1) {
            v0[0] = 0.0f;
            v0[1] = 0.0f;
            v0[2] = n->unk178;
            v0[3] = 1.0f;
            func_002DCE08(v0, n->mtxA0, v0);
            func_002DD020(v0, v10, v0);
        } else {
            func_002DCE08(v0, n->unk160->mtxA0, n->unk168->vec20.f);
        }
        func_002DD038(v0, v0, n->unk150);
        func_002DD068(v0, v0, n->unk170);
        func_002DD020(n->unk150, n->unk150, v0);
        func_001A7840(n->unk174, 0, n->unk150);
    }
}
