#include "p6_overlay.h"

extern P6NodeVt D_01B02E00;

typedef struct {
    P6Node node;        /* 0x00 */
    u16 h1C;            /* 0x1C */
    u16 h1E;            /* 0x1E */
    void *p20;          /* 0x20 */
    u8 pad24[0x0C];
    u16 h30;            /* 0x30 */
    u16 h32;            /* 0x32 */
    u16 h34;            /* 0x34 */
} Obj3D98;

typedef struct {
    Obj3D98 *obj;       /* 0x00 */
    P6Node *parent;     /* 0x04 */
    void *p08;          /* 0x08 */
    u16 h0C;            /* 0x0C */
    u16 h0E;            /* 0x0E */
} Arg3D98;

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

void func_01B03D98(Arg3D98 *a)
{
    attach_node(&a->obj->node, a->parent, &D_01B02E00);
    a->obj->h1C = a->h0C;
    a->obj->p20 = a->p08;
    a->obj->h1E = a->h0E;
    a->obj->h34 = 0;
    a->obj->h32 = 0;
    a->obj->h30 = 0;
}
