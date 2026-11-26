#include "p6_overlay.h"

typedef struct {
    P6Node node;
    void *p1C;
    void *p20;
    void *p24;
    int flags;
} Obj4DB0;

typedef struct {
    Obj4DB0 *obj;
} Arg4DB0;

void func_01B04DB0(Arg4DB0 *a)
{
    a->obj->flags |= 1;
}
