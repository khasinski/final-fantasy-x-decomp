#include "p6_overlay.h"

extern P6NodeVt D_01B05D30;

typedef struct {
    P6Node node;
    u16 h1C;
    u16 h1E;
    void *p20;
} ObjADC0;

typedef struct {
    ObjADC0 *obj;
    P6Node *parent;
    void *p08;
    u16 h0C;
    u16 h0E;
} ArgADC0;

static inline void attach_node(P6Node *n, P6Node *p, P6NodeVt *vt)
{
    n->vt = vt;
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
}

void func_01B0ADC0(ArgADC0 *a)
{
    attach_node(&a->obj->node, a->parent, &D_01B05D30);
    a->obj->h1C = a->h0C;
    a->obj->p20 = a->p08;
    a->obj->h1E = a->h0E;
}
