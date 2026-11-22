#include "common.h"

void func_01B066E0(s32 a, float x, float y, float z, u32 b);
void func_01B06740(s32 a, float x, u32 b);

u8 *func_01B0AF40(void *vm, u8 *pc)
{
    func_01B066E0(
        *(s16 *)(pc + 2),
        (float)(*(s32 *)(pc + 4)) * (1.0f / 4096.0f),
        (float)(*(s32 *)(pc + 8)) * (1.0f / 4096.0f),
        (float)(*(s32 *)(pc + 12)) * (1.0f / 4096.0f),
        *(u32 *)(pc + 16));
    return pc + 20;
}

u8 *func_01B0AFA0(void *vm, u8 *pc)
{
    func_01B06740(
        *(s16 *)(pc + 2),
        (float)(*(s32 *)(pc + 4)) * (1.0f / 4096.0f),
        *(u32 *)(pc + 8));
    return pc + 12;
}
