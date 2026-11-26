#include "p6_overlay.h"

typedef struct {
    P6Node node;
    u8 pad1C[4];
    u8 items[8][0xA0];
    int count;
} Obj3470;

typedef struct {
    Obj3470 *obj;
} Arg3470;

extern void func_01B04A50(void **);

void func_01B03470(Arg3470 *a)
{
    Obj3470 *o = a->obj;
    int i;
    void *ptr;
    P6Node *n;
    P6Node *p;

    for (i = 0; i < o->count; i++) {
        ptr = o->items[i];
        func_01B04A50(&ptr);
    }
    n = &a->obj->node;
    p = n->parent;
    if (p != 0) {
        p->count--;
        if (n->next == p) {
            p->last = n->prev;
        } else {
            n->next->prev = n->prev;
        }
        if (n->prev == p) {
            p->first = n->next;
        } else {
            n->prev->next = n->next;
        }
        n->parent = 0;
        n->prev = n;
        __asm__ volatile("" ::: "memory");
        n->next = n;
    }
}
