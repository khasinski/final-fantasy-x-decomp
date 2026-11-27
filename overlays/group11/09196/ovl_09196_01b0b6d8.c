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
    void *p1C;
} Node;

typedef struct {
    Node *n;
    Node *p;
    void *p1C;
} ArgB6D8;

extern u8 D_01B05D90[];

void func_01B0B6D8(ArgB6D8 *a)
{
    Node *n = a->n;
    Node *p = a->p;
    n->vtbl = D_01B05D90;
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
    a->n->p1C = a->p1C;
}
