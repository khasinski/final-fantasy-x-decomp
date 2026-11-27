#include "common.h"

typedef struct Node {
    void *vtbl;
    struct Node *prev;
    struct Node *next;
    struct Node *head;
    struct Node *tail;
    struct Node *parent;
    u16 count;
    u8 b1A;
    u8 b1B;
    u8 pad1C[0x08];
    int w24;
} Node;

typedef struct {
    Node *n;
    Node *p;
} Arg81A0;

extern u8 D_01B05CB0[];

void func_01B081A0(Arg81A0 *a)
{
    Node *n = a->n;
    Node *p = a->p;
    n->vtbl = D_01B05CB0;
    n->b1A = 0xFF;
    n->tail = n;
    n->head = n;
    n->parent = p;
    n->b1B = 0;
    if (p != 0) {
        n->prev = p;
        n->next = p->tail;
        if (p->tail == p) {
            p->head = n;
        } else {
            p->tail->prev = n;
        }
        p->tail = n;
        p->count++;
    }
    a->n->w24 = 0;
}
