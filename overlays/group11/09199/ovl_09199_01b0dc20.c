#include "p6_overlay.h"

extern P6NodeVt g_vt_dc20;

typedef struct {
    P6Node node;
    u8 pad1C[0x10];
    float f2C;
    void *p30;
    u32 w34;
    u32 w38;
} ObjDC20;

typedef struct {
    ObjDC20 *obj;
    P6Node *parent;
    void *p08;
} ArgDC20;

static inline void attach_node(P6Node *n, P6Node *p)
{
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

void func_01B0DC20(ArgDC20 *a)
{
    attach_node(&a->obj->node, a->parent);
    a->obj->node.vt = &g_vt_dc20;
    a->obj->p30 = a->p08;
    a->obj->f2C = 1.0f;
    a->obj->w38 = 0;
}
