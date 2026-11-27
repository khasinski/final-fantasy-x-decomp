#include "p6_overlay.h"

extern P6NodeVt D_01B05AC0;

typedef struct {
    P6Node node;        /* 0x00 */
    u16 cap;            /* 0x1C */
    u16 stride;         /* 0x1E */
    u8 *buf;            /* 0x20 */
    u8 pad24[0x0C];
    u16 wr_pos;         /* 0x30 */
    u16 count;          /* 0x32 */
    u16 rd_pos;         /* 0x34 */
    u16 pad36;
    P6Node *src;        /* 0x38 */
} RingObj2;

typedef struct {
    RingObj2 *obj;      /* 0x00 */
    P6Node *parent;     /* 0x04 */
    u8 *buf;            /* 0x08 */
    u16 cap;            /* 0x0C */
    u16 stride;         /* 0x0E */
    P6Node *src;        /* 0x10 */
} ArgABC8;

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

void func_01B0ABC8(ArgABC8 *a)
{
    attach_node(&a->obj->node, a->parent, &D_01B05AC0);
    a->obj->cap = a->cap;
    a->obj->src = a->src;
    a->obj->buf = a->buf;
    a->obj->stride = a->stride;
    a->obj->rd_pos = 0;
    a->obj->count = 0;
    __asm__ volatile("");
    a->obj->wr_pos = 0;
}
