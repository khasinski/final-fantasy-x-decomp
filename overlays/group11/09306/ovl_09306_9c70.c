#include "common.h"

typedef struct {
    u8 pad00[0x3C];
    void *p3C;
} Obj9C70;

typedef struct {
    Obj9C70 *obj;
    void *p04;
    void *p08;
} Arg9C70;

extern void func_01B09EF0(Arg9C70 *);
extern void func_01B09E68(void *);

void func_01B09C70(register Arg9C70 *a)
{
    func_01B09EF0(a);
    func_01B09E68(a->p08);
    a->obj->p3C = a->p08;
}
