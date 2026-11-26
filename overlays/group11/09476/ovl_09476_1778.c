#include "common.h"

typedef struct {
    u8 pad00[0x104];
    void *fn104;
} OvlObj;

extern u8 D_01B0EB10[];

extern void func_01B04120(void *, int, int);

void ovl_09476_1778(OvlObj *obj)
{
    func_01B04120(D_01B0EB10, 2, 1);
    obj->fn104 = 0;
}
