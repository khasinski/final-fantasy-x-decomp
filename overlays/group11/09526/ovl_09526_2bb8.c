#include "common.h"

typedef struct {
    u8 pad00[0x1C];
    void (*fn1C)(void *);
} VTable;

typedef struct Node {
    VTable *vtable;
    u8 pad04[0x4];
    struct Node *next;
    u8 pad0C[0x4];
    struct Node *child;
    u8 pad14[0x6];
    u8 b1A;
    u8 pad1B[0x5];
    float v20[4];
    float v30[4];
    float v40[4];
    u8 pad50[0x50];
    float mA0[12];
    float vD0[4];
    u8 padE0[0x50];
    float v130[3];
    float f13C;
    struct Node *p140;
    struct Node *p144;
    u8 pad148[0x8];
    float f150;
    struct Node *p154;
} Node;

typedef struct {
    Node *node;
    u8 flag4;
    u8 b05;
} Ctx2BB8;

extern void func_002DD038(void *, void *, void *);
extern void func_002DCEC8(void *, void *);
extern void func_002DD068(void *, void *, float);
extern void func_002DCFF8(void *, void *, void *, float);
extern void func_002DCE80(void *, void *, void *);
extern void func_002DD0B0(void *, void *);
extern void func_002DD0C0(void *, void *);

static inline void call_dep(Ctx2BB8 *tmp, Node *dep, u8 b05)
{
    tmp->b05 = b05;
    tmp->node = dep;
    dep->vtable->fn1C(tmp);
}

void ovl_09526_2bb8(Ctx2BB8 *ctx)
{
    float v00[4];
    Node *n = ctx->node;

    if (n->b1A == ctx->b05) {
        ctx->flag4 = 0;
    } else {
        Node *c = n->child;
        while (c != n) {
            ctx->node = c;
            c = c->next;
            ctx->node->vtable->fn1C(ctx);
        }
        ctx->node = n;
        n->b1A = ctx->b05;
        ctx->flag4 = 1;
    }

    if (ctx->flag4 & 1) {
        Ctx2BB8 tmp;
        call_dep(&tmp, n->p140, ctx->b05);
        call_dep(&tmp, n->p154, ctx->b05);
        call_dep(&tmp, n->p144, ctx->b05);

        func_002DD038(v00, n->p154->v20, n->p140->v20);
        func_002DCEC8(v00, v00);
        func_002DD068(v00, v00, -1.0f);
        func_002DCFF8(v00, v00, n->v40, n->f150);
        func_002DCEC8(n->v40, v00);

        v00[0] = 0.0f;
        v00[1] = 1.0f;
        v00[2] = 0.0f;
        v00[3] = 1.0f;
        func_002DCE80(n->v20, v00, n->v40);
        func_002DCE80(n->v30, n->v40, n->v20);

        func_002DD0B0(n->v130, n->p144->v20);
        func_002DD068(v00, n->v130, n->f13C);
        func_002DD068(n->v20, n->v20, v00[0]);
        func_002DD068(n->v30, n->v30, v00[1]);
        func_002DD068(n->v40, n->v40, v00[2]);
        func_002DD0C0(n->mA0, n->v20);
        func_002DD0B0(n->vD0, n->p140->v20);
    }
}
