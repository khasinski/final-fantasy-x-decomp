#include "p6_overlay.h"

extern P6NodeVt g_vt_8028;

typedef struct {
    P6Node node;
    u8 pad1C[0x14];
    void *p30;
    void *p34;
    int w38;
    int w3C;
    int w40;
    u8 pad44[0x0C];
    u8 b50;
    u8 b51;
    u8 b52;
} Obj8028;

typedef struct {
    Obj8028 *obj;
    P6Node *parent;
    void *p08;
    void *p0C;
} Arg8028;

void func_01B08028(Arg8028 *a)
{
    Obj8028 *o = a->obj;
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
    o->p30 = a->p08;
    o->w3C = 0;
    o->w40 = 0;
    o->p34 = a->p0C;
    o->b52 = 0;
    o->b50 = 0;
    o->b51 = 0;
    o->w38 = 0;
    a->obj->node.vt = &g_vt_8028;
}
