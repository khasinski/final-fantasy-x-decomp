#include "p6_overlay.h"

typedef struct {
    P6Node node;
    u8 pad1C[0xDC];
    int flags;
    int wFC;
} Obj4030;

typedef struct {
    Obj4030 *obj;
    int val;
} Arg4030;

void func_01B04030(Arg4030 *a)
{
    a->obj->wFC = a->val;
}

void func_01B04040(Arg4030 *a)
{
    Obj4030 *o = a->obj;
    if (a->val != 0) {
        o->flags &= 0xFFFFFFFD;
    } else {
        o->flags |= 2;
    }
}
