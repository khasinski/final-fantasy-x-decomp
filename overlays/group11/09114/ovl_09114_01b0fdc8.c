#include "common.h"

struct CtxFDC8;

typedef struct {
    u8 pad0[0x1C];
    void (*update)(struct CtxFDC8 *);
} VtblFDC8;

typedef struct NodeFDC8 {
    VtblFDC8 *vtbl;
    struct NodeFDC8 *prev;
    struct NodeFDC8 *next;
    struct NodeFDC8 *tail;
    struct NodeFDC8 *head;
    struct NodeFDC8 *parent;
    u16 child_count;
    u8 flag_1a;
    u8 flag_1b;
} NodeFDC8;

typedef struct CtxFDC8 {
    NodeFDC8 *node;
    u8 dirty;
    u8 tick;
} CtxFDC8;

typedef struct {
    NodeFDC8 *obj;
    NodeFDC8 *child;
} ArgFDC8;

void ovl_09114_01b0fdc8(CtxFDC8 *a0) {
    NodeFDC8 *s2 = a0->node;
    if (s2->flag_1a == a0->tick) {
        a0->dirty = 0;
    } else {
        NodeFDC8 *s0 = s2->head;
        while (s0 != s2) {
            a0->node = s0;
            s0 = s0->next;
            a0->node->vtbl->update(a0);
        }
        a0->node = s2;
        s2->flag_1a = a0->tick;
        a0->dirty = 1;
    }
}

void ovl_09114_01b0fe58(ArgFDC8 *a0) {
    NodeFDC8 *v0 = a0->obj;
    NodeFDC8 *a1 = a0->child;
    a1->prev = v0;
    v0->child_count++;
    a1->next = v0->head;
    v0->head->prev = a1;
    v0->head = a1;
    a1->parent = v0;
}

void ovl_09114_01b0fe90(ArgFDC8 *a0) {
    NodeFDC8 *n = a0->obj;
    NodeFDC8 *p = n->parent;
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
