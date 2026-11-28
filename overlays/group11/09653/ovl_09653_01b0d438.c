#include "common.h"

struct CtxD438;

typedef struct {
    u8 pad0[0x1C];
    void (*update)(struct CtxD438 *);
} VtblD438;

typedef struct NodeD438 {
    VtblD438 *vtbl;
    struct NodeD438 *prev;
    struct NodeD438 *next;
    struct NodeD438 *tail;
    struct NodeD438 *head;
    struct NodeD438 *parent;
    u16 child_count;
    u8 flag_1a;
    u8 flag_1b;
    u32 pad1C;
    float f20[3];
    float f2C;
    struct NodeD438 *f30;
} NodeD438;

typedef struct CtxD438 {
    NodeD438 *node;
    u8 dirty;
    u8 tick;
} CtxD438;

typedef struct {
    NodeD438 *obj;
    NodeD438 *child;
} ArgD438;

extern u8 g_01b00a50[];
extern void fn_01b0d5d0(void *);

void ovl_09653_01b0d438(CtxD438 *a0) {
    CtxD438 sub;
    void *msg[3];
    NodeD438 *s2 = a0->node;

    if (s2->flag_1a == a0->tick) {
        a0->dirty = 0;
    } else {
        NodeD438 *s0 = s2->head;
        while (s0 != s2) {
            a0->node = s0;
            s0 = s0->next;
            a0->node->vtbl->update(a0);
        }
        a0->node = s2;
        s2->flag_1a = a0->tick;
        a0->dirty = 1;
    }

    if (a0->dirty & 1) {
        NodeD438 *s0 = a0->node;
        if (s0->f30 != 0) {
            sub.node = s0->f30;
            sub.tick = a0->tick;
            sub.node->vtbl->update(&sub);
            msg[0] = s0->f30;
            msg[1] = s0->f20;
            msg[2] = g_01b00a50;
            fn_01b0d5d0(msg);
            s0->f2C = 1.0f;
        }
    }
}

void ovl_09653_01b0d530(ArgD438 *a0) {
    NodeD438 *v0 = a0->obj;
    NodeD438 *a1 = a0->child;
    a1->prev = v0;
    v0->child_count++;
    a1->next = v0->head;
    v0->head->prev = a1;
    v0->head = a1;
    a1->parent = v0;
}

void ovl_09653_01b0d568(ArgD438 *a0) {
    NodeD438 *n = a0->obj;
    NodeD438 *p = n->parent;
    if (p != 0) {
        p->child_count--;
        if (n->prev == p) {
            p->head = n->next;
        } else {
            n->prev->next = n->next;
        }
        if (n->next == p) {
            n->next->tail = n->prev;
        } else {
            n->next->prev = n->prev;
        }
        n->next = n;
        n->prev = n;
        n->parent = 0;
    }
}
