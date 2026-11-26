#include "common.h"

typedef struct Ctx85 Ctx85;

typedef struct {
    void *pad[7];
    void (*fn1C)(Ctx85 *);
} Vtbl85;

typedef struct Node85 {
    Vtbl85 *vtbl;
    u8 pad04[0x1C];
    float v20[3];
    u8 pad2C[0x04];
    float v30[3];
    struct Node85 *child;
} Node85;

struct Ctx85 {
    Node85 *node;
    u8 flag04;
    u8 flag05;
    u8 pad06[0x0A];
};

extern void func_01B08800(Ctx85 *);

void func_01B08500(register Ctx85 *ctx)
{
    Node85 *n;
    Node85 *c;
    Ctx85 sub;

    func_01B08800(ctx);
    if (!(ctx->flag04 & 1)) {
        return;
    }
    n = ctx->node;
    c = n->child;
    sub.flag05 = ctx->flag05;
    sub.node = n->child;
    sub.node->vtbl->fn1C(&sub);
    n->v20[0] = c->v20[0] + n->v30[0];
    n->v20[1] = c->v20[1] + n->v30[1];
    n->v20[2] = c->v20[2] + n->v30[2];
}
