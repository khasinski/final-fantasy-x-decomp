/* tu_021 0x113ff8-0x115e70: low; ~Ch (config/tu_map.tsv) */
#include "common.h"
#include "ffx/q0.h"
#include "ffx/r0.h"
#include "ffx/u0.h"
#include "ffx/v0.h"
#include "ffx/g0.h"

typedef struct G0Slot16 {
    s8 b0;
    s8 b1;
    s16 h2;
    s32 w4;
    void *p8;
    s32 wC;
} G0Slot16; /* DEBT(NAME) */

INCLUDE_ASM("build/ee_asm/game/chr/ch_113FF8", func_00113FF8);

INCLUDE_ASM("build/ee_asm/game/chr/ch_113FF8", func_00114120);

INCLUDE_ASM("build/ee_asm/game/chr/ch_113FF8", func_00114270);

INCLUDE_ASM("build/ee_asm/game/chr/ch_113FF8", func_00114398);

INCLUDE_ASM("build/ee_asm/game/chr/ch_113FF8", func_001144E8);

INCLUDE_ASM("build/ee_asm/game/chr/ch_113FF8", func_00114600);

INCLUDE_ASM("build/ee_asm/game/chr/ch_113FF8", Ch_ClothReset2);

s32 Ch_ClothReset(void *a) /* DEBT(TYPE): declared in funcs.h as returning s32, no value is produced */
{
    Ch_ReserveCalcNorm2(a);
    Ch_ClothReset2(a);
}

/* DEBT(TYPE): global type guessed from the access width only */
void func_001148E0(float v)
{
    D_0057F640 = v;
}

void func_001148F0(float x, float y, float z)
{
    D_0057F638 = y;
    D_0057F63C = z;
    D_0057F634 = x;
}

void func_00114910(float *x, float *y, float *z)
{
    if (y != 0) {
        *y = D_0057F638;
    }
    if (z != 0) {
        *z = D_0057F63C;
    }
    if (x != 0) {
        *x = D_0057F634;
    }
}

INCLUDE_ASM("build/ee_asm/game/chr/ch_113FF8", func_00114948);

void func_00114968(Chr *chr, s32 v)
{
    FLAGS_SET(chr, 33, v);
}

s32 func_00114998(Chr *chr)
{
    return (s32)((u64)chr->flags >> 33) & 1;
}

void func_001149A8(Chr *chr, float x, float y, float z)
{
    chr->f810 = y;
    chr->f814 = z;
    chr->f818 = x;
    func_00114968(chr, 1);
}

void func_001149C0(Chr *chr, float *x, float *y, float *z)
{
    if (y != 0) {
        *y = CHR_F32(chr, 0x810); /* DEBT(CAST) */
    }
    if (z != 0) {
        *z = CHR_F32(chr, 0x814);
    }
    if (x != 0) {
        *x = CHR_F32(chr, 0x818);
    }
}

INCLUDE_ASM("build/ee_asm/game/chr/ch_113FF8", func_001149F8);

INCLUDE_ASM("build/ee_asm/game/chr/ch_113FF8", func_00114A20);
INCLUDE_RODATA("build/ee_asm/game/chr/ch_113FF8/rodata", jtbl_005697E0);

INCLUDE_ASM("build/ee_asm/game/chr/ch_113FF8", Ch_ClothSetAtariJimenCheck);

void func_00114B30(s8 v)
{
    D_0057F644 = v;
}

s8 func_00114B40(void)
{
    return D_0057F644;
}

/* DEBT(TYPE): global type guessed from the access width only */
void func_00114B50(float v)
{
    D_0057F648 = v;
}

/* DEBT(TYPE): global type guessed from the access width only */
void func_00114B60(float v)
{
    D_0057F64C = v;
}

void Ch_ClothEnableGrav(Chr *chr, int v)
{
    u64 *w = (u64 *)&chr->f828; /* DEBT(CAST): 64-bit flag word at 0x828 overlaps f828/h82E */

    *w = (*w & ~(1L << 32)) | ((u64)(v & 1) << 32);
}

INCLUDE_ASM("build/ee_asm/game/chr/ch_113FF8", func_00114BA0);
INCLUDE_RODATA("build/ee_asm/game/chr/ch_113FF8/rodata", jtbl_005699D0);

INCLUDE_ASM("build/ee_asm/game/chr/ch_113FF8", func_00115DF0);

INCLUDE_ASM("build/ee_asm/game/chr/ch_113FF8", func_00115E08);

INCLUDE_ASM("build/ee_asm/game/chr/ch_113FF8", func_00115E20);

INCLUDE_ASM("build/ee_asm/game/chr/ch_113FF8", func_00115E48);

INCLUDE_ASM("build/ee_asm/game/chr/ch_113FF8", func_00115E60);
