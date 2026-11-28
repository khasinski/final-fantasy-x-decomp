#include "common.h"

typedef struct Ctx3088 Ctx3088;
typedef struct Node3088 Node3088;

typedef struct {
    u8 pad00[0x1C];
    void (*unk1C)(Ctx3088 *);
} Vtbl3088;

struct Node3088 {
    Vtbl3088 *vtable;
    Node3088 *prev;
    Node3088 *next;
    Node3088 *first;
    Node3088 *last;
    Node3088 *parent;
    u16 count;
    u8 unk1A;
    u8 unk1B;
    s32 pad1C;
    s32 unk20;
    s32 unk24;
    s32 unk28;
    s32 pad2C;
    s32 unk30;
    s32 unk34;
    s32 unk38;
    s32 unk3C;
    s32 unk40;
    s32 unk44;
    float unk48;
};

struct Ctx3088 {
    Node3088 *node;
    u8 unk04;
    u8 unk05;
};

void func_01B03088(Ctx3088 *ctx) {
    Node3088 *n = ctx->node;

    if (n->unk1A == ctx->unk05) {
        ctx->unk04 = 0;
    } else {
        Node3088 *cur = n->last;
        while (cur != n) {
            Node3088 *next;
            register Node3088 *p __asm__("$2");
            register void (*fn)(Ctx3088 *) __asm__("$5");
            ctx->node = cur;
            next = cur->next;
            p = *(Node3088 *volatile *)&ctx->node;
            fn = p->vtable->unk1C;
            fn(ctx);
            cur = next;
        }
        ctx->node = n;
        n->unk1A = ctx->unk05;
        ctx->unk04 = 1;
    }

    if (ctx->unk04 & 1) {
        Node3088 *v = ctx->node;
        s32 x = (s32)((float)v->unk3C * v->unk48);
        s32 y = (s32)((float)v->unk40 * v->unk48);
        s32 z = (s32)((float)v->unk44 * v->unk48);
        v->unk3C = x;
        v->unk40 = y;
        v->unk44 = z;
        v->unk20 = v->unk30 + x;
        v->unk24 = v->unk34 + y;
        v->unk28 = v->unk38 + z;
    }
}
