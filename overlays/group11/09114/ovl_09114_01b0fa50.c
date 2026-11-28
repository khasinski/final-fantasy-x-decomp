#include "common.h"

struct CtxFA50;

typedef struct {
    u8 pad0[0x1C];
    void (*update)(struct CtxFA50 *);
} VtblFA50;

typedef struct NodeFA50 {
    VtblFA50 *vtbl;
    struct NodeFA50 *prev;
    struct NodeFA50 *next;
    struct NodeFA50 *tail;
    struct NodeFA50 *head;
    struct NodeFA50 *parent;
    u16 child_count;
    u8 flag_1a;
    u8 flag_1b;
    u16 cap;
    u16 stride;
    u8 *buf;
    u8 *seg0_ptr;
    u8 *seg1_ptr;
    u16 seg0_len;
    u16 seg1_len;
    u16 head_idx;
    u16 count;
    u16 tail_idx;
} NodeFA50;

typedef struct CtxFA50 {
    NodeFA50 *node;
    u8 dirty;
    u8 tick;
} CtxFA50;

typedef struct {
    NodeFA50 *obj;
    NodeFA50 *parent;
    u8 *buf;
    u16 cap;
    u16 stride;
} ArgFA50;

typedef struct {
    NodeFA50 *obj;
    u16 req;
    u16 len0;
    u16 len1;
    u16 pad0A;
    u8 *ptr0;
    u8 *ptr1;
} ArgFC10;

typedef struct {
    NodeFA50 *obj;
    u16 skip;
} ArgFD40;

extern VtblFA50 g_vtbl_fa50;

void ovl_09114_01b0fa50(CtxFA50 *a0) {
    NodeFA50 *s2 = a0->node;
    if (s2->flag_1a == a0->tick) {
        a0->dirty = 0;
    } else {
        NodeFA50 *s0 = s2->head;
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

void ovl_09114_01b0fae0(ArgFA50 *a0) {
    NodeFA50 *v0 = a0->obj;
    NodeFA50 *a1 = a0->parent;
    a1->prev = v0;
    v0->child_count++;
    a1->next = v0->head;
    v0->head->prev = a1;
    v0->head = a1;
    a1->parent = v0;
}

void ovl_09114_01b0fb18(ArgFA50 *a0) {
    NodeFA50 *n = a0->obj;
    NodeFA50 *p = n->parent;
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

void ovl_09114_01b0fb80(ArgFA50 *a0) {
    NodeFA50 *n = a0->obj;
    NodeFA50 *p = a0->parent;
    n->vtbl = &g_vtbl_fa50;
    n->flag_1a = 0xFF;
    n->head = n;
    n->tail = n;
    n->parent = p;
    n->flag_1b = 0;
    if (p != 0) {
        n->prev = p;
        n->next = p->head;
        if (p->head == p) {
            p->tail = n;
        } else {
            p->head->prev = n;
        }
        p->head = n;
        p->child_count++;
    }
    a0->obj->cap = a0->cap;
    a0->obj->buf = a0->buf;
    a0->obj->stride = a0->stride;
    a0->obj->tail_idx = 0;
    a0->obj->count = 0;
    a0->obj->head_idx = 0;
}
