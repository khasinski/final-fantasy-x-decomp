#include "p6_overlay.h"

/* F2 TU rank 67: P6TaskObj check / constructor. Compiled with -O0. */

typedef struct P6TaskInit {
    P6TaskObj *obj;
    void (*func)();
    int arg;
} P6TaskInit;

extern P6NodeVt D_01B02790;

void func_01B0B818(P6TaskMsg *a)
{
    u32 flags;
    P6TaskObj *self;

    flags = a->obj->flags;
    if (flags & 1) {
        self = a->obj;
        self->vt->fn[7](&self);
        a->res = 1;
    } else {
        a->res = 0;
    }
}

void func_01B0B8A8(P6TaskInit *a)
{
    P6TaskObj *t;

    a->obj->vt = &D_01B02790;
    t = a->obj;
    t->next = t->prev = t;
    a->obj->func = a->func;
    a->obj->arg = a->arg;
}
