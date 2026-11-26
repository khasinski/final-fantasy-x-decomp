#include "common.h"

typedef struct {
    u8 pad00[0x2C];
    float f2C;
    u8 pad30[0xC];
    void *p3C;
} Obj8478;

typedef struct {
    Obj8478 *obj;
    void *p4;
    void *p8;
} Arg8478;

extern void func_01B086C8(Arg8478 *);

void func_01B08478(register Arg8478 *a)
{
    func_01B086C8(a);
    a->obj->p3C = a->p8;
    a->obj->f2C = 1.0f;
}
