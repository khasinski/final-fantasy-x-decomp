#include "common.h"

struct CtxD238;

typedef struct {
    u8 pad0[0x1C];
    void (*update)(struct CtxD238 *);
} VtblD238;

typedef struct NodeD238 {
    VtblD238 *vtbl;
    struct NodeD238 *prev;
    struct NodeD238 *next;
    struct NodeD238 *tail;
    struct NodeD238 *head;
    struct NodeD238 *parent;
    u16 child_count;
    u8 flag_1a;
    u8 flag_1b;
    u32 pad1C;
    u8 f20[0x10];
    void *f30;
    float f34;
    s32 f38;
} NodeD238;

typedef struct CtxD238 {
    NodeD238 *node;
    u8 dirty;
    u8 tick;
} CtxD238;

typedef struct {
    NodeD238 *obj;
    NodeD238 *parent;
    void *f08;
} ArgD238;

typedef struct {
    void *f00;
    void *f04;
    float f08;
    s32 f0C;
} MsgD238;

extern VtblD238 g_vtbl_d238;
extern void fn_01b0ed30(MsgD238 *);

void ovl_09653_01b0d238(CtxD238 *a0) {
    MsgD238 msg;
    NodeD238 *s2 = a0->node;

    if (s2->flag_1a == a0->tick) {
        a0->dirty = 0;
    } else {
        NodeD238 *s0 = s2->head;
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
        NodeD238 *s0 = a0->node;
        if (s0->f30 != 0) {
            msg.f00 = s0->f30;
            msg.f04 = s0->f20;
            msg.f08 = s0->f34;
            fn_01b0ed30(&msg);
            if (msg.f0C != 0) {
                s0->f38 |= 1;
            } else {
                s0->f38 &= -2;
            }
        }
    }
}

void ovl_09653_01b0d320(ArgD238 *a0) {
    NodeD238 *v0 = a0->obj;
    NodeD238 *a1 = a0->parent;
    a1->prev = v0;
    v0->child_count++;
    a1->next = v0->head;
    v0->head->prev = a1;
    v0->head = a1;
    a1->parent = v0;
}

void ovl_09653_01b0d358(ArgD238 *a0) {
    NodeD238 *n = a0->obj;
    NodeD238 *p = n->parent;
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

void ovl_09653_01b0d3c0(ArgD238 *a0) {
    NodeD238 *n = a0->obj;
    NodeD238 *p = a0->parent;
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
    a0->obj->f30 = a0->f08;
    a0->obj->vtbl = &g_vtbl_d238;
}

void ovl_09653_01b0d430(void) {
}
