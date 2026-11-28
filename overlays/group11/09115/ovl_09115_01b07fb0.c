#include "common.h"

typedef struct Node7FB0 {
    void *vt;
    struct Node7FB0 *prev;
    struct Node7FB0 *next;
    struct Node7FB0 *tail;
    struct Node7FB0 *head;
    struct Node7FB0 *parent;
    u16 count;
    u8 flag1A;
    u8 flag1B;
    u8 pad1C[0x14];
    void *f30;
    int f34;
    int f38;
    int f3C;
} Node7FB0;

typedef struct Arg7FB0 {
    Node7FB0 *node;
    Node7FB0 *parent;
    void *f8;
} Arg7FB0;

extern u8 D_01B05008[];

void func_01B07FB0(Arg7FB0 *a0)
{
    Node7FB0 *n = a0->node;
    Node7FB0 *p = a0->parent;

    n->vt = D_01B05008;
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
    n->f30 = a0->f8;
    n->f34 = 0;
    n->f38 = 0;
    n->f3C = 0;
}
