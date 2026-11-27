#include "common.h"

typedef struct {
    u8 pad00[0x90];
    u8 b90[0x40];
    s32 wD0;
    u8 padD4[0x0C];
} ElemE0; /* size 0xE0 */

typedef struct {
    u8 pad00[0x1850];
    ElemE0 elem[16];
} Work9649;

extern u8 D_01B88370[];
extern Work9649 *D_01B0B1F8;

extern s32 func_01B03E48(s32);
extern void func_01B051B8(s32, s32);
extern void func_01B05308(s32, s32);
extern void func_01B053F8(s32, s32);
extern void func_01B05428(s32, s32);
extern void func_01B060A8(void *, s32, void *, s32);

void func_01B034F0(u8 *a0)
{
    s32 s0 = *(s32 *)(a0 + 0x120);
    ElemE0 *s1 = &D_01B0B1F8->elem[s0];

    func_01B053F8(func_01B03E48(s0), 2);
    func_01B05308(s0, 0);
    func_01B05428(s0, 6);
    func_01B051B8(s0, 1);
    func_01B060A8(D_01B88370, 3, s1->b90, 0x100);
    s1->wD0 = 1;
}
