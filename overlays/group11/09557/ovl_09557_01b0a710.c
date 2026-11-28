#include "common.h"

typedef struct ObjA710 {
    u8 pad00[0x38];
    int f38;
} ObjA710;

typedef struct ArgA710 {
    ObjA710 *obj;
} ArgA710;

extern void func_01B0AA40(ArgA710 *);

void func_01B0A710(register ArgA710 *s0)
{
    func_01B0AA40(s0);
    s0->obj->f38 = 0;
}
