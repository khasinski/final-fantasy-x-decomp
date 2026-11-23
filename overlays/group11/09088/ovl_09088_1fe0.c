#include "common.h"

typedef struct {
    u8 pad00[0x1C];
    void *p1C;
    u8 sub20[4];
} Obj1FE0;

extern void func_002678E0(void *, void *);
extern void func_00267A68(void *, void *, void *, int);
extern void func_01B02628(void *);

void func_01B01FE0(Obj1FE0 *o, void *a1, void *a2, int a3)
{
    func_002678E0(o->p1C, a1);
    func_00267A68(o, o->p1C, a2, a3);
    func_01B02628(o->sub20);
}
