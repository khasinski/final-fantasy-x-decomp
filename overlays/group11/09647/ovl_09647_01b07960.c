#include "p6_overlay.h"

extern P6NodeVt g_vt_7960;

typedef struct {
    P6Node node;
    void *p1C;
    u16 h20;
    u16 h22;
    u16 h24;
    u16 h26;
    u16 h28;
} Obj7960;

typedef struct {
    Obj7960 *obj;
    P6Node *parent;
    void *p08;
    u16 h0C;
    u16 h0E;
} Arg7960;

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

void func_01B07960(Arg7960 *a)
{
    u16 h0E;
    attach_node(&a->obj->node, a->parent, &g_vt_7960);
    a->obj->h20 = a->h0C;
    a->obj->p1C = a->p08;
    h0E = a->h0E;
    __asm__("" : "+r"(h0E));
    a->obj->h24 = 0;
    __asm__("" : : "m"(a->obj->h24));
    a->obj->h22 = h0E;
    __asm__("" : : "m"(a->obj->h22));
    a->obj->h28 = 0;
    __asm__("" : : "m"(a->obj->h28));
    a->obj->h26 = 0;
}
