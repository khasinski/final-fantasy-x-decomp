/* tu_318 0x2a0618-0x2a0820: low; ~opu; split at 0x2a0618: flag split: 0x2A0618-0x2A0718 needs -Btools/cc/ee-as-delay/ -Wa,-mips4 (config/cflags.txt), func_0029FD20 does not (config/tu_map.tsv) */
/* Angle conversion and adjacent event-script helpers. */
#include "common.h"
#include "ffx/q7.h"
#include "ffx/t6.h"
#include "ffx/w9.h"
#include "ffx/v6.h"

float func_002A0618(float angle)
{
    int value;

    angle *= 2048.0f;
    angle /= 3.141592f;
    value = (int)angle;
    value &= 0xFFF;
    value = -value;
    value += 1024;
    value &= 0xFFF;
    return (float)value;
}

float func_002A0660(float x)
{
    int i = (int)x;

    return (float)((-(i & 0xFFF) + 0x400) & 0xFFF) * 3.141592f * 0.00048828125f;
}

INCLUDE_ASM("build/ee_asm/game/op/opu/opu_29DC40_2A0618", func_002A06A0);

void func_002A06D0(int id, float *out)
{
    Chr *chr = owu_chr_hd[id];

    if (chr != 0) {
        *out = func_00110288(chr);
    }
}

void opus_set_chr_pos(int id, float *pos)
{
    Chr *chr;

    if (MsBattleChrStart() != 0) {
        MsSetChrPos(id, pos);
    } else {
        chr = owu_chr_hd[id];
        if (chr != 0) {
            Ch_SetPos3(chr, pos[0], pos[1], pos[2]);
        }
    }
}

void opus_set_chr_dirf(int id, float v)
{
    Chr *chr;

    if (MsBattleChrStart() != 0) {
        MsSetChrDirF(id, v);
    } else {
        chr = owu_chr_hd[id];
        if (chr != 0) {
            Ch_SetDirF(chr, v);
        }
    }
}
