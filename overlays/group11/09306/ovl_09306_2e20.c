#include "common.h"
#include "vu0.h"

extern void func_002DD038(float *, float *, float *);
extern void func_002DD068(float *, float *, float);

typedef struct Ctx2E20 Ctx2E20;
typedef struct Node2E20 Node2E20;

typedef struct {
    u8 pad00[0x1C];
    void (*unk1C)(Ctx2E20 *);
} Vtbl2E20;

struct Node2E20 {
    Vtbl2E20 *vtable;
    Node2E20 *prev;
    Node2E20 *next;
    Node2E20 *first;
    Node2E20 *last;
    Node2E20 *parent;
    u16 count;
    u8 unk1A;
    u8 unk1B;
    s32 pad1C;
    float unk20[4];
    float unk30[4];
    Node2E20 *unk40;
    float unk44;
    float unk48;
    float unk4C;
    float unk50;
    float unk54;
};

struct Ctx2E20 {
    Node2E20 *node;
    u8 unk04;
    u8 unk05;
};

void func_01B02E20(Ctx2E20 *ctx) {
    float tmp[4];
    Ctx2E20 sub;
    Node2E20 *n = ctx->node;

    if (n->unk1A == ctx->unk05) {
        ctx->unk04 = 0;
    } else {
        Node2E20 *cur = n->last;
        while (cur != n) {
            Node2E20 *next;
            register Node2E20 *p __asm__("$2");
            register void (*fn)(Ctx2E20 *) __asm__("$5");
            ctx->node = cur;
            next = cur->next;
            p = *(Node2E20 *volatile *)&ctx->node;
            fn = p->vtable->unk1C;
            fn(ctx);
            cur = next;
        }
        ctx->node = n;
        n->unk1A = ctx->unk05;
        ctx->unk04 = 1;
    }

    if (ctx->unk04 & 1) {
        Node2E20 *child;
        float t;
        n = ctx->node;
        child = n->unk40;
        sub.unk05 = ctx->unk05;
        sub.node = child;
        child->vtable->unk1C(&sub);

        n->unk4C += n->unk50;
        n->unk48 += n->unk4C;
        n->unk54 += 1.0f;
        t = n->unk48 * n->unk48 * n->unk54;
        n->unk44 = t;
        if (t >= 1.0f) {
            n->unk44 = 1.0f;
        }
        func_002DD038(tmp, n->unk40->unk20, n->unk30);
        func_002DD068(tmp, tmp, n->unk44);
        {
            float *dst = n->unk20;
            VU0_LQC2(1, 0, n->unk30);
            VU0_LQC2(2, 0, tmp);
            VU0_LQC2(3, 0, dst);
            VU0_OP("vadd.xyz $vf3, $vf1, $vf2");
            VU0_SQC2(3, 0, dst);
        }
    }
}
