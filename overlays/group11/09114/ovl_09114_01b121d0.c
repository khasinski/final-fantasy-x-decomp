#include "common.h"

typedef struct Node21D0 Node21D0;
struct Node21D0 {
    void *vtbl;
    Node21D0 *prev;
    Node21D0 *next;
    Node21D0 *tail;
    Node21D0 *head;
    Node21D0 *parent;
    u16 count;
    u8 b1A;
    u8 b1B;
    u8 pad1C[0x50];
    u32 w6C;
    void *p70;
    void *p74;
    u8 b78;
};

typedef struct {
    Node21D0 *node;
    Node21D0 *parent;
    void *p08;
    void *p0C;
} Arg21D0;

extern u8 g_vtable_21d0[];

void func_01B121D0(Arg21D0 *a)
{
    register Arg21D0 *ap __asm__("$7") = a;
    Node21D0 *n = ap->node;
    Node21D0 *p = ap->parent;

    n->vtbl = g_vtable_21d0;
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
        register Node21D0 *n2 __asm__("$2") = ap->node;
        __asm__("" : "+r"(n2));
        {
            register int two __asm__("$6") = 2;
            register void *p0C __asm__("$4") = ap->p0C;
            register void *p08 __asm__("$5") = ap->p08;
            __asm__("" : "+r"(two), "+r"(p0C), "+r"(p08));
            n2->b78 = 0;
            __asm__("" : : "m"(n2->b78));
            n2->p74 = p0C;
            __asm__("" : : "m"(n2->p74));
            n2->p70 = p08;
            ap->node->w6C = two;
        }
    }
}
