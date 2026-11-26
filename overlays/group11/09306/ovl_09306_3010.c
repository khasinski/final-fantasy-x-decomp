#include "p6_overlay.h"

extern P6NodeVt D_01B01830;

typedef struct {
    P6Node node;
    u8 pad1C[0x2C];
    float f48;
} Obj3010;

typedef struct {
    Obj3010 *obj;
    P6Node *parent;
    float f08;
} Arg3010;

void func_01B03010(Arg3010 *a)
{
    Obj3010 *o = a->obj;
    P6Node *p = a->parent;

    o->node.mark = 0xFF;
    o->node.last = &o->node;
    o->node.first = &o->node;
    o->node.parent = p;
    o->node.b1B = 0;
    if (p != 0) {
        o->node.next = p;
        o->node.prev = p->last;
        if (p->last == p) {
            p->first = &o->node;
        } else {
            p->last->next = &o->node;
        }
        p->last = &o->node;
        p->count++;
    }
    o->f48 = a->f08;
    a->obj->node.vt = &D_01B01830;
}
