#include "common.h"

typedef struct Node3580 {
    void *vt;
    struct Node3580 *prev;
    struct Node3580 *next;
    struct Node3580 *tail;
    struct Node3580 *head;
    struct Node3580 *parent;
    u16 count;
    u8 flag1A;
    u8 flag1B;
    u8 pad1C[4];
    int f20, f24, f28, f2C;
    int f30, f34, f38, f3C;
    int f40, f44;
} Node3580;

typedef struct Arg3580 {
    Node3580 *node;
    Node3580 *parent;
} Arg3580;

extern u8 D_01B02098[];

void func_01B03580(Arg3580 *a0)
{
    Node3580 *n = a0->node;
    Node3580 *p = a0->parent;

    n->flag1A = 0xFF;
    n->head = n;
    n->tail = n;
    n->parent = p;
    n->flag1B = 0;
    if (p != 0) {
        n->prev = p;
        n->next = p->head;
        if (p->head == p) {
            p->tail = n;
        } else {
            p->head->prev = n;
        }
        p->head = n;
        p->count += 1;
    }
    a0->node->vt = D_01B02098;
    n->f44 = 0;
    n->f40 = 0;
    n->f3C = 0;
    n->f38 = 0;
    n->f34 = 0;
    n->f30 = 0;
    n->f28 = 0;
    n->f24 = 0;
    n->f20 = 0;
}
