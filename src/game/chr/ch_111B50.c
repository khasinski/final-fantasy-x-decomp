/* tu_018 0x111b50-0x1132b8: medium; ~Ch (config/tu_map.tsv) */
#include "common.h"
#include "ffx/q0.h"
#include "ffx/r0.h"
#include "ffx/s0.h"
#include "ffx/v0.h"
#include "ffx/u0.h"

s32 func_00111B50(Chr *chr)
{
    return chr->w74C;
}

INCLUDE_ASM("build/ee_asm/game/chr/ch_111B50", func_00111B58);
INCLUDE_RODATA("build/ee_asm/game/chr/ch_111B50/rodata", jtbl_00569720);

INCLUDE_ASM("build/ee_asm/game/chr/ch_111B50", func_00112100);

void func_001121C8(Chr *chr)
{
    ChrUpdateLink *link;

    /* DEBT(CAST): relocated integer offset is a list pointer at this point. */
    link = (ChrUpdateLink *)chr->w758;
    if (link != 0)
    {
        do
        {
            link->saved1A = (u16) link->flags16;
            link->previous0C = (s32) link->value08;
            link->h06 = 0;
            link->flags16 = 0U;
            link->h14 = 0;
            link = link->next;
        } while (link != 0);
    }
    func_00112100(chr, 1);
    link = (ChrUpdateLink *)chr->w758;
    if (link != 0)
    {
        do
        {
            link->previous18 = (u16) link->saved1A;
            link = link->next;
        } while (link != 0);
    }
    chr->w7E8 = 1;
}

void Ch_MotionRemappingFcurve(Chr *chr, int d)
{
    int i;
    s32 *p;

    if (chr->w758 != 0) {
        chr->w758 += d;
        p = chr->p754;
        for (i = 0; i < chr->hdr->h0A * 9; i++, p += 10) {
            if (*p != 0) {
                *p += d;
            }
        }
    }
}

INCLUDE_ASM("build/ee_asm/game/chr/ch_111B50", Ch_MotionSetupFcurve);

INCLUDE_ASM("build/ee_asm/game/chr/ch_111B50", Ch_MotionCalcHokan);

void func_001127E0(Chr *chr, s16 v)
{
    chr->h732 = v;
}

s16 func_001127E8(Chr *chr)
{
    return chr->h730;
}

s8 Ch_GetWaitMotion(Chr *chr)
{
    return chr->b742;
}

INCLUDE_ASM("build/ee_asm/game/chr/ch_111B50", Ch_IncrementFrame);

INCLUDE_ASM("build/ee_asm/game/chr/ch_111B50", Ch_MotionApply);

INCLUDE_ASM("build/ee_asm/game/chr/ch_111B50", func_00112A70);

INCLUDE_ASM("build/ee_asm/game/chr/ch_111B50", Ch_AnimCopy2);

s8 func_00112EE8(void)
{
    return Sg_GetKeepFps();
}

void func_00112F08(int a)
{
    Sg_SetKeepFps(a);
}

s32 func_00112F10(Chr *chr, s32 v)
{
    s32 old = FLAGS_BIT(chr, 20);

    FLAGS_SET(chr, 20, v);
    return old;
}

s32 func_00112F40(Chr *chr)
{
    return FLAGS_BIT(chr, 20);
}

void func_00112F58(s32 v)
{
    D_003038B8 = v;
}

s32 func_00112F68(void)
{
    return D_003038B8;
}

INCLUDE_ASM("build/ee_asm/game/chr/ch_111B50", func_00112F78);
