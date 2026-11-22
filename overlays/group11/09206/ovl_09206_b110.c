#include "common.h"

void *func_01B09BE8(u32 id);
void func_01B0A070(void *slot, float a, float b, u32 c, u32 d);
void func_01B0A090(void *slot);
void func_00118098(u32 a, u32 b);
void func_01B060B8(s32 a);

u8 *func_01B0B110(void *vm, u8 *pc)
{
    float a = (float)(*(s32 *)(pc + 4)) * (1.0f / 4096.0f);
    float b = (float)(*(s32 *)(pc + 8)) * (1.0f / 4096.0f);
    void *s = func_01B09BE8(*(u16 *)(pc + 2));
    func_01B0A070(s, a, b, *(u16 *)(pc + 12), *(u16 *)(pc + 14));
    return pc + 16;
}

u8 *func_01B0B188(void *vm, u8 *pc)
{
    func_01B0A090(func_01B09BE8(*(u16 *)(pc + 2)));
    return pc + 4;
}

u8 *func_01B0B1C0(void *vm, u8 *pc)
{
    func_00118098(*(u16 *)(pc + 2), *(u32 *)(pc + 4));
    return pc + 8;
}

u8 *func_01B0B1F0(void *vm, u8 *pc)
{
    func_01B060B8(*(s16 *)(pc + 2));
    return pc + 4;
}
