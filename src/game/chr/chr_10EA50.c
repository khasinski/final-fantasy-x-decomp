/* tu_013 0x10ea50-0x110158: low; ~Sg (config/tu_map.tsv) */
#define func_0010F060 _hdr_func_0010F060
#include "common.h"
#include "ffx/q0.h"
#include "ffx/r0.h"
#include "ffx/u0.h"
#include "ffx/v0.h"
#undef func_0010F060

/* DEBT(TYPE): global type guessed from the access width only */
void func_0010EA50(s32 v)
{
    D_0057EB58 = v;
}

void func_0010EA60(s8 v)
{
    D_0057EB40 = v;
}

void func_0010EA70(s8 v)
{
    D_0057EB44 = v;
}

void func_0010EA80(s8 v)
{
    D_0057EB41 = v;
}

void func_0010EA90(u8 v)
{
    D_0057EB49 = v;
}

void func_0010EAA0(s8 a, s8 b, s8 c)
{
    D_0057EB46 = a;
    D_0057EB47 = b;
    D_0057EB48 = c;
}

void func_0010EAC0(s8 v)
{
    D_0057EB43 = v;
}

void func_0010EAD0(s8 v)
{
    D_0057EB45 = v;
}

void func_0010EAE0(s8 v)
{
    D_0057EB42 = v;
}

void func_0010EAF0(float v)
{
    D_0057EB4C = v;
}

void func_0010EB00(float v)
{
    D_0057EB50 = v;
}

void func_0010EB10(s8 a, s8 b, s8 c, s8 d)
{
    D_0057EB54 = a;
    D_0057EB55 = b;
    D_0057EB56 = c;
    D_0057EB57 = d;
}

s32 func_0010EB38(void)
{
    return (yiGetRenderStatus() >> 14) & 1;
}

void func_0010EB60(s32 v)
{
    D_0057EB7C = v;
}

INCLUDE_ASM("build/ee_asm/game/chr/chr_10EA50", func_0010EB70);

void func_0010EB90(float a, float b, float c)
{
    D_0057EB80 = a;
    D_0057EB84 = b;
    D_0057EB88 = c;
}

s32 *func_0010EBB0(void)
{
    return &D_0057EBA0;
}

void func_0010EBC0(void)
{
    D_00303714 = (D_00303714 + 1) & 1;
}

INCLUDE_ASM("build/ee_asm/game/chr/chr_10EA50", func_0010EBD8);

INCLUDE_ASM("build/ee_asm/game/chr/chr_10EA50", func_0010EF98);

s32 _m2c_func_0010F060_func_0010EBD8(s32) __asm__("func_0010EBD8");
void _m2c_func_0010F060_func_0010EF98(s32 *) __asm__("func_0010EF98");
extern u_long128 _m2c_func_0010F060_D_00578E00 __asm__("D_00578E00");
/* DEBT(CAST) */
s32 func_0010F060(u_long128 *arg0) {
    _m2c_func_0010F060_func_0010EF98(&D_0057EBA0);
    *arg0 = _m2c_func_0010F060_D_00578E00;
    return _m2c_func_0010F060_func_0010EBD8(((u_long128 *)((u8 *)arg0 + (0x10))));
}

INCLUDE_ASM("build/ee_asm/game/chr/chr_10EA50", func_0010F0A8);

INCLUDE_ASM("build/ee_asm/game/chr/chr_10EA50", func_0010F0D8);

INCLUDE_ASM("build/ee_asm/game/chr/chr_10EA50", func_0010F1A0);

INCLUDE_ASM("build/ee_asm/game/chr/chr_10EA50", func_0010F308);

INCLUDE_ASM("build/ee_asm/game/chr/chr_10EA50", func_0010F468);

INCLUDE_ASM("build/ee_asm/game/chr/chr_10EA50", Sg_VectorToMatrix);

INCLUDE_ASM("build/ee_asm/game/chr/chr_10EA50", func_0010F818);

/* DEBT(TYPE): global type guessed from the access width only */
void func_0010F9E0(u8 v)
{
    D_0057EB74 = v;
}

INCLUDE_ASM("build/ee_asm/game/chr/chr_10EA50", Ch_CreateVu1Packet);
