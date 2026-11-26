#include "common.h"

typedef struct {
    void *p00;
    s32 w04;
} Call5C58;

typedef struct {
    u8 pad00[0x88];
    void *p88;
    u8 pad8C[0x28];
    u16 hB4;
} OvlObj;

typedef struct {
    OvlObj *obj;
} Arg4860;

extern void func_1B05C58(Call5C58 *);

void ovl_09470_4860(Arg4860 *a)
{
    OvlObj *s0 = a->obj;
    Call5C58 c;

    c.w04 = 1;
    c.p00 = s0->p88;
    func_1B05C58(&c);
    s0->hB4 |= 0x10;
}
