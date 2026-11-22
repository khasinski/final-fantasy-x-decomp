#include "common.h"

void func_01B06BD8(u32 a, u32 b, u32 c);
void func_01B06BE8(void);
void func_01B082F0(u32 a, u32 b);
void func_01B06228(s32 a, u32 b);

u8 *func_01B0AB70(void *vm, u8 *pc)
{
    func_01B06BD8(*(u32 *)(pc + 4), *(u16 *)(pc + 8), *(u16 *)(pc + 10));
    return pc + 12;
}

u8 *func_01B0ABA8(void *vm, u8 *pc)
{
    func_01B06BE8();
    return pc + 4;
}

u8 *func_01B0ABD0(void *vm, u8 *pc)
{
    func_01B082F0(*(u32 *)(pc + 4), *(u32 *)(pc + 8));
    return pc + 12;
}

u8 *func_01B0AC00(void *vm, u8 *pc)
{
    if (*(u16 *)(pc + 2) == 1) {
        *(u16 *)(*(u8 **)(pc + 4) + 0x124) |= 1;
    } else {
        *(u16 *)(*(u8 **)(pc + 4) + 0x124) &= ~1;
    }
    return pc + 8;
}

u8 *func_01B0AC30(void *vm, u8 *pc)
{
    func_01B06228(*(s16 *)(pc + 2), *(u32 *)(pc + 4));
    return pc + 8;
}
