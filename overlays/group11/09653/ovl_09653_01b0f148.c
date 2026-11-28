#include "common.h"

struct CtxF148;

typedef struct {
    u8 pad0[0x1C];
    void (*update)(struct CtxF148 *);
} VtblF148;

typedef struct NodeF148 {
    VtblF148 *vtbl;
    struct NodeF148 *prev;
    struct NodeF148 *next;
    struct NodeF148 *tail;
    struct NodeF148 *head;
    struct NodeF148 *parent;
    u16 child_count;
    u8 flag_1a;
    u8 flag_1b;
    u32 pad1C;
    float f20;
    float f24;
    float f28;
    u8 pad2C[0x10];
    void *f3C;
    struct NodeF148 *f40;
    struct NodeF148 *f44;
    u8 pad48[0x24];
    u32 f6C;
    void *f70;
    void *f74;
    u8 f78;
} NodeF148;

typedef struct CtxF148 {
    NodeF148 *node;
    u8 dirty;
    u8 tick;
} CtxF148;

typedef struct {
    NodeF148 *obj;
    NodeF148 *parent;
    void *f08;
    void *f0C;
} ArgF148;

extern VtblF148 g_vtbl_f148;

void ovl_09653_01b0f148(CtxF148 *a0) {
    CtxF148 sub1;
    CtxF148 sub2;
    NodeF148 *s2 = a0->node;

    if (s2->flag_1a == a0->tick) {
        a0->dirty = 0;
    } else {
        NodeF148 *s0 = s2->head;
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
        NodeF148 *s0 = a0->node;
        NodeF148 *n1 = s0->f40;
        sub1.tick = a0->tick;
        sub1.node = n1;
        n1->vtbl->update(&sub1);
        if (s0->f44 != 0) {
            NodeF148 *n2 = s0->f44;
            sub2.node = n2;
            sub2.tick = a0->tick;
            n2->vtbl->update(&sub2);
            s0->f3C = &s0->f44->f20;
        } else {
            s0->f3C = 0;
        }
        s0->f20 = s0->f40->f20;
        s0->f24 = s0->f40->f24;
        s0->f28 = s0->f40->f28;
    }
}

void ovl_09653_01b0f258(ArgF148 *a0) {
    NodeF148 *v0 = a0->obj;
    NodeF148 *a1 = a0->parent;
    a1->prev = v0;
    v0->child_count++;
    a1->next = v0->head;
    v0->head->prev = a1;
    v0->head = a1;
    a1->parent = v0;
}

void ovl_09653_01b0f290(ArgF148 *a0) {
    NodeF148 *n = a0->obj;
    NodeF148 *p = n->parent;
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

void ovl_09653_01b0f2f8(ArgF148 *a0) {
    a0->obj->f6C &= ~1;
}
