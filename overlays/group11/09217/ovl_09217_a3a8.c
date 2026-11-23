/* Shared 09217/09190 scene node update A (264 B; 09217 @ 0x01B0A3A8). */

#include "common.h"

typedef struct OvlNodeA OvlNodeA;

typedef struct {
    u8 pad00[0x1C];
    void (*update)(void *);
} OvlVtable;

struct OvlNodeA {
    OvlVtable *vtable;
    OvlNodeA *prev;
    OvlNodeA *next;
    OvlNodeA *tail;
    OvlNodeA *head;
    OvlNodeA *parent;
    u16 child_count;
    u8 flag1A;
    u8 flag1B;
    u32 pad1C;
    float f20;
    float f24;
    float f28;
    float f2C;
    u8 pad30[0x0C];
    void *p3C;
    OvlNodeA *p40;
    OvlNodeA *p44;
};

typedef struct {
    OvlNodeA *node;
    u8 dirty;
    u8 seq;
    u16 pad06;
    u8 pad08[0x08];
} UpdateCtx;

void ovl_09217_a3a8(UpdateCtx *ctx)
{
    OvlNodeA *self = ctx->node;

    if (self->flag1A == ctx->seq) {
        ctx->dirty = 0;
    } else {
        OvlNodeA *child = self->head;
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
        OvlNodeA *n = ctx->node;
        UpdateCtx sub0;
        UpdateCtx sub1;

        sub0.node = n->p40;
        sub0.seq = ctx->seq;
        sub0.node->vtable->update(&sub0);

        if (n->p3C != 0) {
            sub1.node = n->p44;
            sub1.seq = ctx->seq;
            sub1.node->vtable->update(&sub1);
        }

        n->f20 = n->p40->f20;
        n->f24 = n->p40->f24;
        n->f28 = n->p40->f28;
    }
}
