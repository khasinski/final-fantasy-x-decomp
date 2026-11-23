#include "common.h"

typedef struct {
    u8 pad00[0x2C];
    float f2C;
    u8 pad30[0xC];
    void *p3C;
} Obj8B10;

typedef struct {
    Obj8B10 *obj;
    void *p4;
    void *p8;
} Arg8B10;

extern void func_01B08D60(Arg8B10 *);

void func_01B08B10(register Arg8B10 *a)
{
    func_01B08D60(a);
    a->obj->p3C = a->p8;
    a->obj->f2C = 1.0f;
}
