#include "p6_overlay.h"

extern P6NodeVt D_01B02E20;

typedef struct {
    P6Node node;        /* 0x00 */
    u16 h1C;            /* 0x1C */
    u16 h1E;            /* 0x1E */
    u8 *p20;            /* 0x20 */
    u8 pad24[0x0C];
    u16 h30;            /* 0x30 */
    u16 h32;            /* 0x32 */
    u16 h34;            /* 0x34 */
    u8 pad36[0x1A];
    P6Node *p50;        /* 0x50 */
    u8 pad54[0x0C];
    u32 w60;            /* 0x60 */
    u32 w64;            /* 0x64 */
    u8 pad68[0x08];
    u8 buf70[1];        /* 0x70 */
} Obj4110;

typedef struct {
    Obj4110 *obj;       /* 0x00 */
    P6Node *parent;     /* 0x04 */
    u8 *p08;            /* 0x08 */
    u16 h0C;            /* 0x0C */
    u16 h0E;            /* 0x0E */
    P6Node *p10;        /* 0x10 */
} Arg4110;

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

void func_01B04110(Arg4110 *a)
{
    Obj4110 *o = a->obj;
    P6Node *p = a->parent;

    o->node.vt = &D_01B02E20;
    a->h0C = 0x80;
    a->p08 = o->buf70;
    a->h0E = 0x40;

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
    a->obj->h1C = a->h0C;
    a->obj->p20 = a->p08;
    a->obj->h1E = a->h0E;
    a->obj->h34 = 0;
    a->obj->h32 = 0;
    a->obj->h30 = 0;

    o->p50 = a->p10;
    o->w60 = 0;
    o->w64 = 0;
}
