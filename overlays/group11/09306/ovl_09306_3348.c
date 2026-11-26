#include "common.h"

typedef struct {
    u8 pad00[0x20];
    u8 items[8][0xA0];
    int count;
} Obj3348;

typedef struct {
    Obj3348 *obj;
} Arg3348;

extern void func_01B04948(void **);

void func_01B03348(Arg3348 *a)
{
    Obj3348 *o = a->obj;
    int i;
    void *ptr;

    for (i = 0; i < o->count; i++) {
        ptr = o->items[i];
        func_01B04948(&ptr);
    }
}
