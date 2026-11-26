#include "common.h"

typedef struct {
    u8 pad00[0x104];
    u32 w104;
} Obj1940;

extern void func_1B021D8(s32, s32, s32, void *);
extern void func_1B03FE8(void *, s32, s32);

extern u8 D_01B0D3E0;

void ovl_09461_1928(u8 *a0)
{
    func_1B021D8(-1, 11, 0, a0 + 0xD0);
}

void ovl_09461_1940(Obj1940 *s0)
{
    func_1B03FE8(&D_01B0D3E0, 2, 0);
    s0->w104 = 0;
}
