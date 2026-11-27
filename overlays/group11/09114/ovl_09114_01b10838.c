#include "common.h"

typedef struct Node0838 {
    void *vtbl;
    struct Node0838 *prev;
    struct Node0838 *next;
    struct Node0838 *head;
    struct Node0838 *tail;
    struct Node0838 *parent;
    u16 count;
    u8 b1A;
    u8 b1B;
    u8 pad1C[0x08];
    int w24;
} Node0838;

typedef struct {
    Node0838 *n;
    Node0838 *p;
} Arg0838;

extern u8 g_vt_0838[];

void func_01B10838(Arg0838 *a)
{
    Node0838 *n = a->n;
    Node0838 *p = a->p;
    n->vtbl = g_vt_0838;
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
