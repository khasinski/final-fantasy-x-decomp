#include "common.h"

typedef struct {
    u8 pad00[0xD8];
    float fD8;
    u8 padDC[0x0C];
    u32 flags;
} ObjB220;

typedef struct {
    ObjB220 *obj;
    u8 pad04[0x08];
    float f0C;
} ArgB220;

extern void func_01B0B1A0(ArgB220 *);

void func_01B0B220(ArgB220 *a)
{
    ObjB220 *o;
    func_01B0B1A0(a);
    o = a->obj;
    o->fD8 = a->f0C;
    o->flags |= 4;
}
