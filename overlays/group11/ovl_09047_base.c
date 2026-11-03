#include "p6_overlay.h"

/* F2 TU rank 64: base node class methods. Compiled with -O0. */

typedef struct P6Counter {
    P6NodeVt *vt;           /* 0x00 */
    u16 count;              /* 0x04 */
} P6Counter;

typedef struct P6CounterArg {
    P6Counter *obj;
} P6CounterArg;

extern P6NodeVt D_01B025F0;
extern P6NodeVt D_01B02610;

void func_01B035C8(P6CounterArg *a);
void func_01B03778(P6AttachArg *arg);

void func_01B03508(P6CounterArg *a)
{
    func_01B035C8(a);
    return;
}

void func_01B03548(P6AttachArg *a)
{
    a->node->vt = &D_01B025F0;
}

void func_01B03580(void *a)
{
}

void func_01B035A8(void)
{
}

void func_01B035C8(register P6CounterArg *a)
{
    a->obj->count = 0;
}

void func_01B035F8(P6AttachArg *a)
{
    a->node->vt = &D_01B02610;
    func_01B03778(a);
}
