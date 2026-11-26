#include "common.h"

typedef struct {
    u8 pad00[0x04];
    int w04;
    u8 pad08[0x0D];
    u8 b15;
    u8 pad16[0xAE];
    void *pC4;
} ObjB60;

extern ObjB60 D_01B00B60;

extern void func_00110648(void *, int);
extern void func_01B03748(int, int);
extern void *func_01B04018(int);

void func_01B01D68(void)
{
    ObjB60 *o = &D_01B00B60;
    void *p = func_01B04018(0x3016);

    o->pC4 = p;
    o->b15 = 0x20;
    func_00110648(p, 0);
    {
        register int v __asm__("$3") = 2;
        o->w04 = v;
    }
    func_01B03748(1, 1);
}
