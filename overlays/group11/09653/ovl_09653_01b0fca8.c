#include "common.h"

typedef struct NodeFCA8 {
    void *vtbl;
    struct NodeFCA8 *prev;
    struct NodeFCA8 *next;
    struct NodeFCA8 *tail;
    struct NodeFCA8 *head;
    struct NodeFCA8 *parent;
    u16 child_count;
    u8 flag_1a;
    u8 flag_1b;
    u8 pad1C[0x40];
    u16 f5C;
} NodeFCA8;

typedef struct {
    NodeFCA8 *obj;
    NodeFCA8 *child;
} ArgFCA8;

extern void fn_01b0fc58(ArgFCA8 *);

void ovl_09653_01b0fca8(ArgFCA8 *a0) {
    fn_01b0fc58(a0);
    a0->obj->f5C |= 1;
}

void ovl_09653_01b0fce0(ArgFCA8 *a0) {
    NodeFCA8 *v0 = a0->obj;
    NodeFCA8 *a1 = a0->child;
    a1->prev = v0;
    v0->child_count++;
    a1->next = v0->head;
    v0->head->prev = a1;
    v0->head = a1;
    a1->parent = v0;
}

void ovl_09653_01b0fd18(ArgFCA8 *a0) {
    NodeFCA8 *n = a0->obj;
    NodeFCA8 *p = n->parent;
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
