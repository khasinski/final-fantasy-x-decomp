#include "p6_overlay.h"

extern P6NodeVt D_01B199C0;

typedef struct {
    P6Node node;   /* 0x00 */
    u8 pad1C[0x14];
    int w30;       /* 0x30 */
    int w34;       /* 0x34 */
} ObjEF88;

typedef struct {
    ObjEF88 *obj;
    P6Node *parent;
    int w08;
} ArgEF88;

void func_01B1EF88(ArgEF88 *a0)
{
    ObjEF88 *o = a0->obj;
    P6Node *p = a0->parent;

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
    a0->obj->node.vt = &D_01B199C0;
    a0->obj->w30 = a0->w08;
    a0->obj->w34 = 0;
}
