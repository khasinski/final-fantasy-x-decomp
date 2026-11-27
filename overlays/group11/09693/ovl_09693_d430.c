#include "common.h"

typedef struct Node1CE0 Node1CE0;
struct Node1CE0 {
    void *vtbl;
    Node1CE0 *prev;
    Node1CE0 *next;
    Node1CE0 *tail;
    Node1CE0 *head;
    Node1CE0 *parent;
    u16 count;
    u8 b1A;
    u8 b1B;
    u8 pad1C[0x24];
    void *p40;
    void *p44;
};

typedef struct {
    Node1CE0 *node;
    Node1CE0 *parent;
    void *p08;
    void *p0C;
} Arg1CE0;

extern u8 g_vtable_1ce0[];

void func_01B11CE0(Arg1CE0 *a)
{
    Node1CE0 *n = a->node;
    Node1CE0 *p = a->parent;

    n->vtbl = g_vtable_1ce0;
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
    {
        void *p0C = a->p0C;
        void *p08 = a->p08;
        __asm__("" : "+r"(p0C));
        n->p44 = p0C;
        __asm__("" : : "m"(n->p44));
        n->p40 = p08;
    }
}
