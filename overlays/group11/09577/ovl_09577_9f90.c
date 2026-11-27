#include "p6_overlay.h"

extern P6NodeVt D_01B05A60;

typedef struct {
    P6Node node;
    u8 pad1C[0x50];
    int w6C;
    void *p70;
    void *p74;
    u8 b78;
} Obj9F90;

typedef struct {
    Obj9F90 *obj;
    P6Node *parent;
    void *p08;
    void *p0C;
} Arg9F90;

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

void func_01B09F90(Arg9F90 *a)
{
    register Arg9F90 *ap __asm__("$7") = a;
    register Obj9F90 *o __asm__("$2");
    register int two __asm__("$6");
    register void *p0c __asm__("$4");
    register void *p08 __asm__("$5");

    attach_node(&ap->obj->node, ap->parent, &D_01B05A60);
    o = ap->obj;
    two = 2;
    p0c = ap->p0C;
    p08 = ap->p08;
    o->b78 = 0;
    __asm__ volatile("");
    o->p74 = p0c;
    __asm__ volatile("");
    {
        register Obj9F90 *o2 __asm__("$3") = ap->obj;
        __asm__ volatile("" : "+r"(o2));
        o->p70 = p08;
        o2->w6C = two;
    }
}
