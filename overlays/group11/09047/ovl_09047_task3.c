#include "p6_overlay.h"

/* F2 TU rank 107: P6Task constructor. Compiled with -O0. */

extern P6NodeVt D_01B027D8;

void func_01B0BE28(P6Link *ring);

void func_01B0BBF8(P6TaskArg *a)
{
    P6Task *task;
    P6Task *self;

    a->task->vt = &D_01B027D8;
    task = a->task;
    self = a->task;
    func_01B0BE28(&self->ring);
    func_01B0BE28(&task->ring);
    task->flags = 1;
}
