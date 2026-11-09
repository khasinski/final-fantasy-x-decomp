/* tu_350 0x2dc580-0x2dce38: medium; ~FFXVu0ApplyMatrix (config/tu_map.tsv) */
#include "common.h"
#include "vu0.h"
#include "ffx/r7.h"
#include "ffx/q7.h"
#include "ffx/w11.h"
#include "ffx/v7.h"

INCLUDE_ASM("build/ee_asm/game/platform/ffx_2DC580", func_002DC580);

void func_002DC5B0(u16 addr, V7VuQword *p)
{
    V7VuQword val;
    register int vi1 __asm__("$6");
    register u_long128 vf1 __asm__("$5");
    u64 hi = p->d[1];
    u64 lo = p->d[0];
    val.d[1] = hi;
    VU0_CFC2_NI(vi1, 1);
    val.d[0] = lo;
    VU0_QMFC2_NI(vf1, 1);
    VU0_QMTC2_NI(1, *(u_long128 *)&val);
    VU0_CTC2_NI(1, addr);
    VU0_OP("vsqi.xyzw $vf1, ($vi1++)");
    VU0_CTC2_NI(1, vi1);
    VU0_QMTC2_NI(1, vf1);
}

INCLUDE_ASM("build/ee_asm/game/platform/ffx_2DC580", func_002DC5F0);

INCLUDE_ASM("build/ee_asm/game/platform/ffx_2DC580", func_002DC638);

INCLUDE_ASM("build/ee_asm/game/platform/ffx_2DC580", func_002DC650);
INCLUDE_RODATA("build/ee_asm/game/platform/ffx_2DC580/rodata", jtbl_005769F0);

int func_002DC6B0(void)
{
    int r = 0;
    int n = func_002DC780();

    if (n < 4) {
        if (n > 0) {
            r = 1;
            func_002DC7C8(func_002DC7D8());
        }
    }
    return r;
}

INCLUDE_ASM("build/ee_asm/game/platform/ffx_2DC580", func_002DC700);

INCLUDE_ASM("build/ee_asm/game/platform/ffx_2DC580", func_002DC730);

INCLUDE_ASM("build/ee_asm/game/platform/ffx_2DC580", func_002DC760);

INCLUDE_ASM("build/ee_asm/game/platform/ffx_2DC580", func_002DC770);

INCLUDE_ASM("build/ee_asm/game/platform/ffx_2DC580", func_002DC780);

INCLUDE_ASM("build/ee_asm/game/platform/ffx_2DC580", func_002DC7C8);

int func_002DC7D8(void)
{
    return func_002DC5F0(0x43A).h[0];
}

INCLUDE_ASM("build/ee_asm/game/platform/ffx_2DC580", func_002DC800);

INCLUDE_ASM("build/ee_asm/game/platform/ffx_2DC580", func_002DC990);

void func_002DCAD8(void)
{
    /* VIF1 FBRST and ERR hardware registers. */
    *(volatile u32 *)0x10003810 = 1;
    *(volatile u32 *)0x10003820 = 6;
}

int func_002DCB00(int a)
{
    int s = func_002DCBD8();

    if (s == 0) {
        return 0;
    }
    if (s == 1) {
        return 0;
    }
    if (a == 0) {
        *(volatile u32 *)0x10003810 = 2;
    } else if (a == 1) {
        *(volatile u32 *)0x10003810 = 4;
    }
    return 1;
}

int func_002DCB68(void)
{
    if (func_002DCBD8() != 1) {
        return 0;
    }
    *(volatile u32 *)0x10003810 = 8;
    return 1;
}

u32 func_002DCBA8(u32 a, u32 b, u32 c)
{
    /* VIF1 ERR mask: MII, ME0 and ME1. */
    u32 value = a | (b << 1) | (c << 2);

    *(volatile u32 *)0x10003820 = value;
    return value;
}

u32 func_002DCBC8(void)
{
    return *(volatile u32 *)0x10003820;
}

int func_002DCBD8(void)
{
    u32 s = *(volatile u32 *)0x10003800;

    if ((s & 3) == 0) {
        return 0;
    }
    if (s & 0x700) {
        return 1;
    }
    if (s & 0xC) {
        return 2;
    }
    return (s & 0x3000) ? 3 : 4;
}

INCLUDE_ASM("build/ee_asm/game/platform/ffx_2DC580", func_002DCC28);

int func_002DCDA8(u_long128 *src, int n)
{
    int i = 0;

    while (n-- != 0) {
        if (*(volatile u32 *)0x10003800 & 0x10000000) {
            return i;
        }
        *(volatile u_long128 *)0x10004000 = *src++;
        i++;
    }
    return i;
}void func_002DCE08(u32 a0, u32 a1, u32 a2)
{
    __asm__ volatile(
        "lqc2       $vf4, 0x0($5)\n"
        "lqc2       $vf5, 0x10($5)\n"
        "lqc2       $vf6, 0x20($5)\n"
        "lqc2       $vf7, 0x30($5)\n"
        "lqc2       $vf8, 0x0($6)\n"
        "vmulax.xyzw ACC, $vf4, $vf8x\n"
        "vmadday.xyzw ACC, $vf5, $vf8y\n"
        "vmaddaz.xyzw ACC, $vf6, $vf8z\n"
        "vmaddw.xyzw $vf9, $vf7, $vf8w\n"
        "sqc2      $vf9, 0x0($4)\n"
        :  : "r"(a0), "r"(a1), "r"(a2));
}
