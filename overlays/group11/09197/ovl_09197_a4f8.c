#include "p6_overlay.h"

extern P6NodeVt D_01B08C10;

typedef struct {
    P6Node node;
    u16 cap;
    u16 stride;
    u32 base;
    u32 p24;
    u32 p28;
    u16 h2C;
    u16 h2E;
    u16 widx;
    u16 used;
    u16 ridx;
} ObjA4F8;

typedef struct {
    ObjA4F8 *obj;
    P6Node *parent;
    u32 base;
    u16 cap;
    u16 stride;
} ArgA4F8;

typedef struct {
    ObjA4F8 *obj;
    u16 n;
    u16 out_n1;
    u16 out_n2;
    u16 pad0A;
    u32 out_p1;
    u32 out_p2;
} ArgA588;

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

void func_01B0A4F8(ArgA4F8 *a)
{
    attach_node(&a->obj->node, a->parent, &D_01B08C10);
    a->obj->cap = a->cap;
    a->obj->base = a->base;
    a->obj->stride = a->stride;
    a->obj->ridx = 0;
    a->obj->used = 0;
    a->obj->widx = 0;
}

void func_01B0A588(ArgA588 *a)
{
    ObjA4F8 *o = a->obj;
    u16 n = a->n;
    u16 widx;
    u16 end;

    __asm__("" : "+r"(n));
    if (n > o->cap) {
        a->out_n1 = 0;
        return;
    }

    widx = o->widx;
    __asm__("" : "+r"(widx));
    {
        register u32 st __asm__("$2") = o->stride;
        register u32 bs __asm__("$3") = o->base;
        a->out_p1 = bs + widx * st;
    }
    end = widx + n;

    if (end <= o->cap) {
        a->out_n1 = n;
        a->out_n2 = 0;
        if (end == o->cap) {
            o->widx = 0;
        } else {
            o->widx = end;
        }
    } else {
        u16 tmp1 = o->cap - widx;
        u16 tmp2 = n - (o->cap - widx);
        a->out_n1 = tmp1;
        a->out_n2 = tmp2;
        a->out_p2 = o->base;
        o->widx = end - o->cap;
    }

    if (o->used < o->cap) {
        o->used += a->n;
        if (o->used > o->cap) {
            o->used = o->cap;
        }
    } else {
        o->ridx = o->widx;
    }

    {
        register u32 r0 __asm__("$3") = o->ridx;
        register u32 stride2 __asm__("$11") = o->stride;
        register u32 base2 __asm__("$8") = o->base;
        register u32 sum16 __asm__("$7");
        register int cmp __asm__("$4");
        register u16 tmp __asm__("$2");
        r0 = base2 + r0 * stride2;
        o->p24 = r0;
        tmp = o->ridx + o->used;
        sum16 = tmp;
        cmp = ((u16)sum16 > o->cap);
        if (cmp) {
            o->h2C = o->cap - o->ridx;
            o->h2E = o->used - (o->cap - o->ridx);
            o->p28 = base2;
        } else {
            o->h2C = o->used;
            o->h2E = 0;
            o->p28 = o->used * stride2 + base2;
        }
    }
}
