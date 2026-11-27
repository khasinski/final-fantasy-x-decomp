#include "p6_overlay.h"

extern P6NodeVt D_01B05A40;

typedef struct {
    P6Node node;
    u8 pad1C[0x08];
    int w24;
} Obj9AC0;

typedef struct {
    Obj9AC0 *obj;
    P6Node *parent;
} Arg9AC0;

void func_01B09AC0(Arg9AC0 *a)
{
    P6Node *n = &a->obj->node;
    P6Node *p = a->parent;
    n->vt = &D_01B05A40;
    n->mark = 0xFF;
    n->last = n;
    n->first = n;
    n->parent = p;
    n->b1B = 0;
    if (p != 0) {
        n->next = p;
        n->prev = p->last;
        if (p->last == p) {
            p->first = n;
        } else {
            p->last->next = n;
        }
        p->last = n;
        p->count++;
    }
    a->obj->w24 = 0;
}
