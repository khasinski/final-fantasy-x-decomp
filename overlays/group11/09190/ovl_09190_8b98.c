#include "common.h"

typedef struct Ctx8B Ctx8B;

typedef struct {
    void *pad[7];
    void (*fn1C)(Ctx8B *);
} Vtbl8B;

typedef struct Node8B {
    Vtbl8B *vtbl;
    u8 pad04[0x1C];
    float v20[3];
    u8 pad2C[0x04];
    float v30[3];
    struct Node8B *child;
} Node8B;

struct Ctx8B {
    Node8B *node;
    u8 flag04;
    u8 flag05;
    u8 pad06[0x0A];
};

extern void func_01B08E98(Ctx8B *);

void func_01B08B98(register Ctx8B *ctx)
{
    Node8B *n;
    Node8B *c;
    Ctx8B sub;

    func_01B08E98(ctx);
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
