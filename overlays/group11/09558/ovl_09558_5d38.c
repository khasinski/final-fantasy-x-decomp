#include "common.h"

typedef struct {
    u8 pad00[0x60];
    int f60;
    int f64;
    u8 pad68[0x3C];
    u16 fA4;
    u16 fA6;
} Obj5D38;

typedef struct {
    Obj5D38 *obj;
    int mode;
    int *pair;
} Arg5D38;

void func_01B05D38(Arg5D38 *a0)
{
    Obj5D38 *o = a0->obj;
    int mode = a0->mode;

    o->fA4 &= ~2;
    switch (mode) {
    case 0:
        o->fA4 |= 2;
        break;
    case 2:
        o->fA4 |= 2;
    case 1:
        o->f60 = a0->pair[0];
        o->f64 = a0->pair[1];
        break;
    }
    o->fA6 = a0->mode;
}
