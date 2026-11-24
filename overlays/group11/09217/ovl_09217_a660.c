#include "common.h"

typedef struct OvlNodeB OvlNodeB;

typedef struct {
    u8 pad00[0x1C];
    void (*update)(void *);
} OvlVtable;

struct OvlNodeB {
    OvlVtable *vtable;
    OvlNodeB *prev;
    OvlNodeB *next;
    OvlNodeB *tail;
    OvlNodeB *head;
    OvlNodeB *parent;
    u16 child_count;
    u8 flag1A;
    u8 flag1B;
    u32 pad1C;
    float f20[4];
    u8 data30[0x10];
    void *p40;
    OvlNodeB *p44;
    OvlNodeB *p48;
    OvlNodeB *p4C;
    void *p50;
    u8 flag54;
};

typedef struct {
    OvlNodeB *node;
    u8 dirty;
    u8 seq;
    u16 pad06;
    u8 pad08[0x08];
} UpdateCtx;

typedef struct {
    void *a0;
    void *a1;
    void *a2;
    void *a3;
    void *a4;
    void *a5;
    void *a6;
    void *a7;
} DrawParams;

typedef struct {
    OvlNodeB *node;
    float *pos;
    float *dir;
    u32 pad0C;
} HelperArg;

extern void (*g_fn_a660)(void *, void *);
extern u8 g_data_a80[];
extern u8 g_data_48[];
extern void func_ovl_a568(HelperArg *);
extern void func_002DCE08(void *, void *, void *);
extern void func_00282218(DrawParams *);
extern void func_00282358(void *, void *, void *, void *, void *, int, unsigned long, void *);

typedef struct {
    float v[4];
} __attribute__((aligned(16))) Vec4A16;

void ovl_09217_a660(UpdateCtx *ctx)
{
    float mat[4][4];
    Vec4A16 dir = { { 0.0f, 0.0f, -1.0f, 1.0f } };
    DrawParams dp;
    float pair[2] = { 1.0f, 1.0833333730697632f };
    OvlNodeB *self = ctx->node;

    if (self->flag1A == ctx->seq) {
        ctx->dirty = 0;
    } else {
        OvlNodeB *child = self->head;
        while (child != self) {
            ctx->node = child;
            child = child->next;
            ctx->node->vtable->update(ctx);
        }
        ctx->node = self;
        self->flag1A = ctx->seq;
        ctx->dirty = 1;
    }

    if (ctx->dirty & 1) {
        OvlNodeB *n = ctx->node;
        UpdateCtx sub0;
        UpdateCtx sub1;
        UpdateCtx sub2;
        HelperArg h;

        sub0.node = n->p44;
        sub0.seq = ctx->seq;
        sub0.node->vtable->update(&sub0);

        sub1.node = n->p48;
        sub1.seq = ctx->seq;
        sub1.node->vtable->update(&sub1);

        sub2.node = n->p4C;
        sub2.seq = ctx->seq;
        sub2.node->vtable->update(&sub2);

        if (n->flag54 & 1) {
            register HelperArg *hp __asm__("$3") = &h;
            register OvlNodeB *p44 __asm__("$2");
            float *pos;
            __asm__("" : "+r"(hp));
            p44 = n->p44;
            __asm__("" : : "r"(dir.v));
            h.node = n;
            __asm__("" : "+r"(p44) : "m"(h.node));
            pos = p44->f20;
            __asm__("" : "+r"(hp) : "r"(pos));
            {
                register HelperArg *a0 __asm__("$4") = hp;
                __asm__("" : "+r"(pos), "+r"(hp) : "r"(a0));
                h.pos = pos;
                hp->dir = dir.v;
                func_ovl_a568(a0);
            }
            n->flag54 &= ~1;
        }

        g_fn_a660(mat, n->p48->f20);
        {
            register u8 *mptr __asm__("$29") = (u8 *)mat;
            __asm__("" : "+r"(mptr));
            func_002DCE08(mptr + 0x40, mptr, mptr + 0x40);
        }

        {
            void *a1 = n->p4C->f20;
            void *a4 = n->p44->f20;
            void *a3 = n->p50;
            void *a2 = n->p40;
            dp.a1 = a1;
            dp.a3 = a3;
            dp.a2 = a2;
            dp.a4 = a4;
            dp.a5 = dir.v;
            dp.a0 = n->data30;
        }
        func_00282218(&dp);

        func_00282358(n->data30, g_data_a80, pair, n->p40, g_data_48, 0x48, 0x51801UL, n->f20);
    }
}
