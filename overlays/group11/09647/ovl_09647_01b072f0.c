#include "common.h"

typedef struct Node72F0 {
    void *vtbl;
    struct Node72F0 *prev;
    struct Node72F0 *next;
    struct Node72F0 *tail;
    struct Node72F0 *head;
    struct Node72F0 *parent;
    u16 count;
    u8 b1A;
    u8 b1B;
} Node72F0;

typedef struct {
    Node72F0 *node;
    Node72F0 *parent;
} Arg72F0;

extern u8 g_vt_72f0[];

void func_01B072F0(Arg72F0 *a0)
{
    Node72F0 *n = a0->node;
    Node72F0 *p = a0->parent;

    n->vtbl = g_vt_72f0;
    n->b1A = 0xFF;
    n->head = n;
    n->tail = n;
    n->parent = p;
    n->b1B = 0;
    if (p != 0) {
        n->prev = p;
        n->next = p->head;
        if (p->head == p) {
            p->tail = n;
        } else {
            p->head->prev = n;
        }
        p->head = n;
        p->count++;
    }
}
