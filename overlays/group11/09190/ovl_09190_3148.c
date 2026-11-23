#include "common.h"

typedef struct {
    u8 pad00[0x3E];
    u16 flags;
} Sub3148;

typedef struct {
    u8 pad00[0x30];
    Sub3148 *sub;
} Obj3148;

typedef struct {
    Obj3148 *obj;
    int res;
} Arg3148;

void func_01B03148(Arg3148 *a)
{
    a->res = a->obj->sub->flags & 0x2000;
}
