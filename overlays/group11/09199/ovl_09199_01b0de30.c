#include "p6_overlay.h"

extern P6NodeVt g_vt_de30;

typedef struct {
    P6Node node;
    u8 pad1C[0x14];
    void *p30;
} ObjDE30;

typedef struct {
    ObjDE30 *obj;
    P6Node *parent;
    void *p08;
} ArgDE30;

void func_01B0DE30(ArgDE30 *a)
{
    ObjDE30 *o = a->obj;
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
    {
        register void *p08 __asm__("$2") = a->p08;
        a = (ArgDE30 *)a->obj;
        ((ObjDE30 *)a)->node.vt = &g_vt_de30;
        __asm__("" : : "m"(((ObjDE30 *)a)->node.vt));
        ((ObjDE30 *)a)->p30 = p08;
    }
}
