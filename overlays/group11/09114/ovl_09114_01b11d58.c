#include "common.h"

struct SNode;
struct SNodeCtx;

typedef struct SNodeVtbl {
    u8 pad00[0x1C];
    void (*update)(struct SNodeCtx *);
} SNodeVtbl;

typedef struct SNode {
    SNodeVtbl *vtbl;
    struct SNode *prev;
    struct SNode *next;
    struct SNode *last;
    struct SNode *first;
    struct SNode *parent;
    u16 child_cnt;
    u8 b1A;
    u8 b1B;
    u8 pad1C[4];
    float v20[4];
    u8 pad30[0xC];
    void *p3C;
    struct SNode *p40;
    struct SNode *p44;
} SNode;

typedef struct SNodeCtx {
    SNode *node;
    u8 b04;
    u8 b05;
    u8 pad06[10];
} SNodeCtx; /* size 0x10 */

static inline void update_children(SNodeCtx *ctx)
{
    SNode *self = ctx->node;
    if (self->b1A == ctx->b05) {
        ctx->b04 = 0;
    } else {
        SNode *it = self->first;
        while (it != self) {
            register SNodeCtx *arg __asm__("$4");
            ctx->node = it;
            arg = ctx;
            __asm__ volatile("" : "+r"(arg) : : "memory");
            it = it->next;
            ctx->node->vtbl->update(arg);
        }
        ctx->node = self;
        self->b1A = ctx->b05;
        ctx->b04 = 1;
    }
}

void func_01B11D58(SNodeCtx *a0)
{
    SNodeCtx c0;
    SNodeCtx c1;
    SNode *obj;

    update_children(a0);
    if (!(a0->b04 & 1)) {
        return;
    }

    obj = a0->node;
    c0.node = obj->p40;
    c0.b05 = a0->b05;
    c0.node->vtbl->update(&c0);

    if (obj->p44 != 0) {
        c1.node = obj->p44;
        c1.b05 = a0->b05;
        c1.node->vtbl->update(&c1);
        obj->p3C = obj->p44->v20;
    } else {
        obj->p3C = 0;
    }

    obj->v20[0] = obj->p40->v20[0];
    obj->v20[1] = obj->p40->v20[1];
    obj->v20[2] = obj->p40->v20[2];
}
