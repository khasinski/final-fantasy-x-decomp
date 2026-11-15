#include "p6_overlay.h"

/* F2 TU rank 180: destroy a P6PartObj. Compiled with -O0. */

typedef struct P6PartRef {
    P6PartObj *obj;
} P6PartRef;

void func_01B0AA50(P6PartRef *a);

void func_01B0B5E0(register P6PartObj *obj)
{
    P6PartRef ref;

    ref.obj = obj;
    func_01B0AA50(&ref);
}
