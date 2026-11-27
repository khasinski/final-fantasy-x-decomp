#include "common.h"

struct SNodeF810;
struct SNodeCtxF810;

typedef struct {
    u8 pad00[0x1C];
    void (*update)(struct SNodeCtxF810 *);
} SNodeVtF810;

typedef struct SNodeF810 {
    SNodeVtF810 *vtbl;
    struct SNodeF810 *prev;
    struct SNodeF810 *next;
    struct SNodeF810 *last;
    struct SNodeF810 *first;
    struct SNodeF810 *parent;
    u16 count;
    u8 b1A;
    u8 b1B;
    void *p1C;
} SNodeF810;

typedef struct {
    SNodeF810 *node;
    SNodeF810 *parent;
    void *p08;
} ArgF810;

typedef struct SNodeCtxF810 {
    SNodeF810 *node;
    u8 b04;
    u8 b05;
    u8 pad06[2];
} SNodeCtxF810;

extern SNodeVtF810 g_vt_f810;
extern int func_00103788(void *);

void func_01B0F810(ArgF810 *a)
{
    SNodeF810 *n = a->node;
    SNodeF810 *p = a->parent;

    n->vtbl = &g_vt_f810;
    n->b1A = 0xFF;
    n->first = n;
    n->last = n;
    n->parent = p;
    n->b1B = 0;
    if (p != 0) {
        n->prev = p;
        n->next = p->first;
        if (p->first == p) {
            p->last = n;
        } else {
            p->first->prev = n;
        }
        p->first = n;
        p->count++;
    }
    n->p1C = a->p08;
}

void func_01B0F878(void)
{
}

void func_01B0F880(SNodeCtxF810 *ctx)
{
    SNodeF810 *self = ctx->node;
    if (self->b1A == ctx->b05) {
        ctx->b04 = 0;
    } else {
        SNodeF810 *it = self->first;
        while (it != self) {
            register SNodeCtxF810 *arg __asm__("$4");
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

    if (ctx->b04 & 1) {
        int r = func_00103788(ctx->node->p1C);
        __asm__("" : : "r"(r));
    }
}
