#include "common.h"

#ifndef ARG_A2
#define ARG_A2 0
#endif

typedef struct {
    u8 pad00[0xD0];
    u8 vecD0[0x10];
} Obj130;

extern u8 D_01B07358[];
extern Obj130 D_01B06D20;
extern u8 D_01B04528[];

extern void func_01B03F88(void *, void *, s32, s32, s32, void *, float);
extern void func_002DD0B0(void *, void *);
extern void func_01B010B8(void *);

void ovl_09329_0f60(u8 *s1)
{
    Obj130 *s0 = &D_01B06D20;

    func_01B03F88(D_01B07358, s0, ARG_A2, 0, 0, D_01B04528, 0.1f);
    func_002DD0B0(s0->vecD0, s1 + 0x260);
    func_01B010B8(s1);
}
