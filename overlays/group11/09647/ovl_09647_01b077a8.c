#include "p6_overlay.h"

extern P6NodeVt g_vt_77a8;

typedef struct {
    P6Node node;
    void *p1C;
    u16 h20;
    u16 h22;
} Obj77A8;

typedef struct {
    Obj77A8 *obj;
    P6Node *parent;
    void *p08;
    u16 h0C;
    u16 h0E;
} Arg77A8;

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

void func_01B077A8(Arg77A8 *a)
{
    attach_node(&a->obj->node, a->parent, &g_vt_77a8);
    a->obj->h20 = a->h0C;
    a->obj->p1C = a->p08;
    a->obj->h22 = a->h0E;
}
