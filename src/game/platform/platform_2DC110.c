/* tu_349 0x2dc110-0x2dc580: medium; unk_2DC110 (config/tu_map.tsv) */
#include "common.h"
#include "vu0.h"
#include "ffx/r7.h"
#include "ffx/q7.h"
#include "ffx/w11.h"
#include "ffx/v7.h"

typedef struct Vu0RegisterState {
    u_long128 vf[32];
    u32 status;
    u32 mac;
    u32 clip;
    u32 r;
    u32 i;
    u32 q;
    u16 vi[16];
} Vu0RegisterState;

INCLUDE_ASM("build/ee_asm/game/platform/platform_2DC110", func_002DC110);

u32 func_002DC158(u32 *p, u32 v)
{
    u32 old = *p;

    *p = v;
    return (old >> 8) & 1;
}

int func_002DC170(void)
{
    u32 v;

    VU0_CFC2_NI(v, 29);
    return (v & 0xF) == 1;
}

INCLUDE_ASM("build/ee_asm/game/platform/platform_2DC110", func_002DC188);

int func_002DC1A0(void)
{
    int r = 0;

    switch (func_002DC2D0()) {
    case 4: {
        u32 v;

        VU0_CFC2_NI(v, 28);
        VU0_CTC2_NI(28, v | 1);
    }
    /* fallthrough */
    case 0:
    case 3:
        r = 1;
        break;
    case 1:
    case 2:
        break;
    }
    return r;
}

int func_002DC200(void)
{
    int r = 0;
    int n = func_002DC2D0();

    if (n < 4) {
        if (n > 0) {
            r = 1;
            func_002DC310(func_002DC320());
        }
    }
    return r;
}

INCLUDE_ASM("build/ee_asm/game/platform/platform_2DC110", func_002DC250);

INCLUDE_ASM("build/ee_asm/game/platform/platform_2DC110", func_002DC280);

u32 func_002DC2B0(void)
{
    u32 v;

    VU0_CFC2_NI(v, 28);
    return (v >> 2) & 1;
}

u32 func_002DC2C0(void)
{
    u32 v;

    VU0_CFC2_NI(v, 28);
    return (v >> 3) & 1;
}

int func_002DC2D0(void)
{
    u32 v;

    VU0_CFC2_NI(v, 29);
    if (v & 2) {
        return 1;
    }
    if (v & 4) {
        return 2;
    }
    if (v & 8) {
        return 3;
    }
    return (v & 1) ? 4 : 0;
}

void func_002DC310(int addr)
{
    VU0_CTC2_NI(27, addr & 0xFFFF);
    VU0_OP("vcallmsr $vi27");
}

int func_002DC320(void)
{
    int v;

    VU0_CFC2_NI(v, 26);
    return v & 0xFFFF;
}

INCLUDE_ASM("build/ee_asm/game/platform/platform_2DC110", func_002DC330);

INCLUDE_ASM("build/ee_asm/game/platform/platform_2DC110", func_002DC410);
