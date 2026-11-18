/* tu_031 0x11d598-0x11d750: medium; mem2 (config/tu_map.tsv) */
#include "common.h"
#include "ffx/q0.h"
#include "ffx/r0.h"
#include "ffx/s0.h"
#include "ffx/u0.h"
#include "ffx/w6.h"
#include "ffx/v0.h"

void *func_0011D598(s32 a)
{
    return user_malloc(a, 6, D_00569D40, 0x6D);
}

char *func_0011D5C0(s32 size)
{
    return func_0011D420(size, 6, D_00569D40, 0x71);
}

void func_0011D5E8(s32 h)
{
    func_0011D590(h, 6);
}

s32 func_0011D5F0(s32 a, s32 b)
{
    return func_0011C6E0(1, 6, a, b);
}

s32 SgRealloc(s32 a, s32 b)
{
    return func_0011C6E0(0, 6, a, b);
}

char *func_0011D640(const char *s)
{
    return func_002F072C(func_0011D5C0(func_002F0840(s) + 1), s);
}

INCLUDE_ASM("build/ee_asm/game/main/mem2", func_0011D678);

void func_0011D6C8(s32 a)
{
    func_0011CA28(a, 0xE);
}

char *func_0011D6D0(const char *s)
{
    return func_002F072C(user_malloc(func_002F0840(s) + 1, 0xD, D_00569D40, 0x99), s);
}

s32 func_0011D718(s32 a, s32 b)
{
    return func_0011C6E0(0, 0xD, a, b);
}

Cmd16 *func_0011D740(void)
{
    return D_00580928;
}
