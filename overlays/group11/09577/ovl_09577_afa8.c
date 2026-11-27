#include "p6_overlay.h"

extern P6NodeVt D_01B05AE0;

typedef struct {
    P6Node node;
    void *p1C;
} ObjAFA8;

typedef struct {
    ObjAFA8 *obj;
    P6Node *parent;
    void *p08;
} ArgAFA8;

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

void func_01B0AFA8(ArgAFA8 *a)
{
    attach_node(&a->obj->node, a->parent, &D_01B05AE0);
    a->obj->p1C = a->p08;
}
