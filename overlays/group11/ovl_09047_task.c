#include "p6_overlay.h"

/* F2 TU rank 63: task object message handlers. Compiled with -O0. */

extern P6NodeVt D_01B027B8;

void func_01B0BBB0(struct P6TaskObj **ring);

void func_01B0B9C8(P6TaskMsg *a)
{
    P6TaskMsg call;
    u32 flags;
    P6TaskObj *self;

    flags = a->obj->flags;
    if (flags & 1) {
        self = a->obj;
        self->vt->fn[7](&self);
        a->res = 1;
    } else {
        a->res = 0;
        if (a->res & 1) {
            return;
        }
        call.obj = a->obj;
        call.res = a->obj->arg;
        a->obj->func(&call);
    }
}

void func_01B0BAB0(P6TaskMsg *a)
{
    P6TaskObj *obj;

    a->obj->vt = &D_01B027B8;
    obj = a->obj;
    func_01B0BBB0(&obj->next);
}
