#include "common.h"

typedef struct NodeB390 {
    void *vtbl;
    struct NodeB390 *prev;
    struct NodeB390 *next;
    struct NodeB390 *tail;
    struct NodeB390 *head;
    struct NodeB390 *parent;
    u16 child_count;
} NodeB390;

typedef struct {
    NodeB390 *obj;
    NodeB390 *parent;
} ArgB390;

void ovl_09194_01b0b390(ArgB390 *a0) {
    NodeB390 *v0 = a0->obj;
    NodeB390 *a1 = a0->parent;
    a1->prev = v0;
    v0->child_count++;
    a1->next = v0->head;
    v0->head->prev = a1;
    v0->head = a1;
    a1->parent = v0;
}

void ovl_09194_01b0b3c8(ArgB390 *a0) {
    NodeB390 *n = a0->obj;
    NodeB390 *p = n->parent;
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
