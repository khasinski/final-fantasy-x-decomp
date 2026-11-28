#include "common.h"

struct Ctx7F40;

typedef struct {
    u8 pad0[0x1C];
    void (*update)(struct Ctx7F40 *);
} Vtbl7F40;

typedef struct Node7F40 {
    Vtbl7F40 *vtbl;
    struct Node7F40 *prev;
    struct Node7F40 *next;
    struct Node7F40 *tail;
    struct Node7F40 *head;
    struct Node7F40 *parent;
    u16 child_count;
    u8 flag_1a;
    u8 flag_1b;
    void *f1C;
    u16 f20;
    u16 f22;
    u16 f24;
    u16 f26;
    u16 f28;
} Node7F40;

typedef struct Ctx7F40 {
    Node7F40 *node;
    u8 dirty;
    u8 tick;
} Ctx7F40;

typedef struct {
    Node7F40 *obj;
    Node7F40 *parent;
    void *f08;
    u16 f0C;
    u16 f0E;
} Arg7F40;

extern Vtbl7F40 g_vtbl_7f40;

void ovl_09194_01b07f40(Ctx7F40 *a0) {
    Node7F40 *s2 = a0->node;
    if (s2->flag_1a == a0->tick) {
        a0->dirty = 0;
    } else {
        Node7F40 *s0 = s2->head;
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

void ovl_09194_01b07fd0(Arg7F40 *a0) {
    Node7F40 *v0 = a0->obj;
    Node7F40 *a1 = a0->parent;
    a1->prev = v0;
    v0->child_count++;
    a1->next = v0->head;
    v0->head->prev = a1;
    v0->head = a1;
    a1->parent = v0;
}

void ovl_09194_01b08008(Arg7F40 *a0) {
    Node7F40 *n = a0->obj;
    Node7F40 *p = n->parent;
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

void ovl_09194_01b08070(Arg7F40 *a0) {
    Node7F40 *n = a0->obj;
    Node7F40 *p = a0->parent;
    n->vtbl = &g_vtbl_7f40;
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
    a0->obj->f20 = a0->f0C;
    a0->obj->f1C = a0->f08;
    a0->obj->f22 = a0->f0E;
    a0->obj->f28 = 0;
    a0->obj->f26 = 0;
    a0->obj->f24 = 0;
}

void ovl_09194_01b08100(void) {
}
