#include "common.h"

struct Ctx8540;

typedef struct {
    u8 pad0[0x1C];
    void (*update)(struct Ctx8540 *);
} Vtbl8540;

typedef struct Node8540 {
    Vtbl8540 *vtbl;
    struct Node8540 *prev;
    struct Node8540 *next;
    struct Node8540 *tail;
    struct Node8540 *head;
    struct Node8540 *parent;
    u16 child_count;
    u8 flag_1a;
    u8 flag_1b;
    u32 pad1C;
    u8 f20[0x10];
    void *f30;
    void *f34;
    s32 f38;
    s32 f3C;
    s32 f40;
    u8 pad44[0xC];
    u8 f50;
    u8 f51;
    u8 f52;
    u8 pad53[0x7D];
    u8 fD0[0x30];
    u8 f100[0x130];
    u8 f230[0x10];
    struct Node8540 *f240;
    u8 pad244[0xC];
    u8 f250[0x10];
    void *f260;
    u8 f264;
} Node8540;

typedef struct Ctx8540 {
    Node8540 *node;
    u8 dirty;
    u8 tick;
} Ctx8540;

typedef struct {
    Node8540 *obj;
    Node8540 *parent;
    void *f08;
    void *f0C;
} Arg8540;

extern Vtbl8540 g_vtbl_8540;
extern void fn_001a7840(void *, s32, void *);
extern void fn_002dce08(void *, void *, void *);

void ovl_09194_01b08540(Ctx8540 *a0) {
    Ctx8540 sub;
    Node8540 *s2 = a0->node;

    if (s2->flag_1a == a0->tick) {
        a0->dirty = 0;
    } else {
        Node8540 *s0 = s2->head;
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
        Node8540 *s0 = a0->node;
        if (s0->f264 & 1) {
            if (s0->f264 & 2) {
                fn_001a7840(s0->f260, 0, s0->f250);
            } else if (s0->f240 != 0) {
                sub.node = s0->f240;
                sub.tick = a0->tick;
                sub.node->vtbl->update(&sub);
                fn_001a7840(s0->f260, 0, s0->f240->f20);
            }
        } else {
            fn_002dce08(s0->f20, s0->fD0, s0->f230);
            fn_001a7840(s0->f260, 0, s0->f100);
        }
        fn_001a7840(s0->f260, 1, s0->f20);
    }
}

void ovl_09194_01b08698(Arg8540 *a0) {
    Node8540 *v0 = a0->obj;
    Node8540 *a1 = a0->parent;
    a1->prev = v0;
    v0->child_count++;
    a1->next = v0->head;
    v0->head->prev = a1;
    v0->head = a1;
    a1->parent = v0;
}

void ovl_09194_01b086d0(Arg8540 *a0) {
    Node8540 *n = a0->obj;
    Node8540 *p = n->parent;
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

void ovl_09194_01b08738(Arg8540 *a0) {
    Node8540 *n = a0->obj;
    Node8540 *p = a0->parent;
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
    {
        void *f08 = a0->f08;
        void *f0C;
        n->f30 = f08;
        n->f3C = 0;
        n->f40 = 0;
        f0C = a0->f0C;
        n->f52 = 0;
        n->f50 = 0;
        n->f51 = 0;
        n->f34 = f0C;
        n->f38 = 0;
        a0->obj->vtbl = &g_vtbl_8540;
    }
}

void ovl_09194_01b087c8(void) {
}
