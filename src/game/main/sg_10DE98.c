/* tu_012 0x10de98-0x10ea50: low; ~Sg (config/tu_map.tsv) */
#include "common.h"
#include "ffx/q0.h"
#include "ffx/r0.h"
#include "ffx/s0.h"
#include "ffx/u0.h"

/* DEBT(FAKE) */
s32 func_0010DE98(s32 a) {
    register s32 hi2 __asm__("$6") = 0x580000;
    register s32 hi5 __asm__("$5");
    D_0057EB38 = 0;
    __asm__ volatile("" : "+r"(hi2) : : "$2", "memory");
    D_0057EB34 = a;
    hi5 = 0x580000;
    __asm__("" : "+r"(hi5));
    *(s32 *)(hi2 - 0x14d0) = 0;
    __asm__("" : "+r"(hi5) : "m"(*(s32 *)(hi2 - 0x14d0)));
    *(s32 *)(hi5 - 0x14c4) = 0;
    return 0x70000000;
}

s32 Sg_GetSpadPtr(void)
{
    return D_0057EB30 ? 0x70002000 : 0x70000000;
}

s32 func_0010DEE0(void)
{
    return D_0057EB30 ? 0x70000000 : 0x70002000;
}

s32 func_0010DF00(void)
{
    return Sg_GetSpadPtr();
}

void func_0010DF20(void)
{
    while (*(volatile u32 *)0x10009000 & 0x100) {
    }
    while (*(volatile u32 *)0x1000D000 & 0x100) {
    }
    *(volatile s32 *)0x1000E000 = (*(volatile s32 *)0x1000E000 & ~0xC) | 0x8;
    *(volatile u32 *)0x1000E050 = 0x800000;
    *(volatile u32 *)0x1000E040 = 0x1FFFF0;
    *(volatile u32 *)0x1000D010 = 0x800000;
    *(volatile u32 *)0x10009030 = 0x800000;
    *(volatile u32 *)0x10009010 = 0;
    *(volatile u32 *)0x10009020 = 0;
    *(volatile u32 *)0x10009000 = 0x1C5;
    func_0010DE98(0x800000);
}

s32 func_0010DFF8(s32 a)
{
    return (a - (D_0057EB30 ? 0x70002000 : 0x70000000)) >> 4;
}

INCLUDE_ASM("build/ee_asm/game/main/sg_10DE98", func_0010E028);

s32 func_0010E260(void)
{
    return Sg_GetSpadPtr();
}

s32 func_0010E280(s32 a)
{
    if (a) {
        return func_0010E028(a);
    }
    return Sg_GetSpadPtr();
}

INCLUDE_ASM("build/ee_asm/game/main/sg_10DE98", func_0010E2B0);

void func_0010E2D0(void)
{
    u64 *p = (u64 *)Sg_GetSpadPtr(); /* DEBT(TYPE): getter returns s32 */

    p[0] = 0xF0000000;
    p[1] = 0;
    func_0010E028((int)(p + 2)); /* DEBT(TYPE) */
    func_0010E2B0();
}

/* Wait until the DMA channel has cleared its transfer-in-progress bit. */
void func_0010E308(void)
{
    do { } while (DMA_FROM_SPR_CHCR & 0x100);
}

INCLUDE_ASM("build/ee_asm/game/main/sg_10DE98", Sg_MFIFOSync);

INCLUDE_ASM("build/ee_asm/game/main/sg_10DE98", func_0010E430);

INCLUDE_ASM("build/ee_asm/game/main/sg_10DE98", Ch_EffectPacketCreateMain);
