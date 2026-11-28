#include "common.h"

struct CtxF880;

typedef struct {
    u8 pad0[0x1C];
    void (*update)(struct CtxF880 *);
} VtblF880;

typedef struct NodeF880 {
    VtblF880 *vtbl;
    struct NodeF880 *prev;
    struct NodeF880 *next;
    struct NodeF880 *tail;
    struct NodeF880 *head;
    struct NodeF880 *parent;
    u16 child_count;
    u8 flag_1a;
    u8 flag_1b;
    u16 f1C;
    u16 f1E;
    void *f20;
} NodeF880;

typedef struct CtxF880 {
    NodeF880 *node;
    u8 dirty;
    u8 tick;
} CtxF880;

typedef struct {
    NodeF880 *obj;
    NodeF880 *parent;
    void *f08;
    u16 f0C;
    u16 f0E;
} ArgF880;

extern VtblF880 g_vtbl_f880;
extern void fn_00103788(u32);

void ovl_09114_01b0f880(CtxF880 *a0) {
    NodeF880 *s2 = a0->node;
    if (s2->flag_1a == a0->tick) {
        a0->dirty = 0;
    } else {
        NodeF880 *s0 = s2->head;
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
        fn_00103788(*(u32 *)&a0->node->f1C);
        __asm__("");
    }
}

void ovl_09114_01b0f928(ArgF880 *a0) {
    NodeF880 *v0 = a0->obj;
    NodeF880 *a1 = a0->parent;
    a1->prev = v0;
    v0->child_count++;
    a1->next = v0->head;
    v0->head->prev = a1;
    v0->head = a1;
    a1->parent = v0;
}

void ovl_09114_01b0f960(ArgF880 *a0) {
    NodeF880 *n = a0->obj;
    NodeF880 *p = n->parent;
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

void ovl_09114_01b0f9c8(ArgF880 *a0) {
    NodeF880 *n = a0->obj;
    NodeF880 *p = a0->parent;
    n->vtbl = &g_vtbl_f880;
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
    a0->obj->f1C = a0->f0C;
    a0->obj->f20 = a0->f08;
    a0->obj->f1E = a0->f0E;
}

void ovl_09114_01b0fa48(void) {
}
