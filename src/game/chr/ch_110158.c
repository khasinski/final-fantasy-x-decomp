/* tu_014 0x110158-0x1106a8: medium; ~Ch (config/tu_map.tsv) */
#include "common.h"
#include "ffx/q0.h"
#include "ffx/r0.h"
#include "ffx/u0.h"
#include "ffx/v0.h"

float func_00110158(Chr *chr)
{
    return chr->f510;
}

void func_00110160(Chr *chr, float v)
{
    chr->f510 += v;
}

void func_00110170(Chr *chr)
{
    chr->h82E = -1;
}

float Ch_GetJimen(Chr *chr)
{
    return chr->f178;
}

void Ch_SetPos(Chr *chr, float x, float z)
{
    chr->f10 = x;
    chr->f18 = z;
    *(V128 *)&chr->f20 = *(V128 *)&chr->f10; /* DEBT(CAST): position vector copied as one quad */
    chr->h82E = -1;
    chr->flags |= 0x2000000;
}

void func_001101C0(void)
{
    D_00303860 = 0x1;
}

void Ch_SetPos3(Chr *chr, float x, float y, float z)
{
    if (D_00303860 != 0) {
        D_00303860 = 0;
        return;
    }
    chr->f10 = x;
    chr->f14 = y;
    chr->f18 = z;
    *(V128 *)&chr->f20 = *(V128 *)&chr->f10; /* DEBT(CAST): position vector copied as one quad */
    chr->h82E = -1;
    chr->flags |= 0x2000000;
}

void Ch_GetPos(Chr *chr, float *x, float *y, float *z)
{
    if (x) {
        *x = chr->f10;
    }
    if (y) {
        *y = chr->f14;
    }
    if (z) {
        *z = chr->f18;
    }
}

void Ch_SetSp(Chr *chr, float v)
{
    chr->f160 = v;
}

void func_00110260(Chr *chr, float v)
{
    chr->f14 += v;
}

INCLUDE_ASM("build/ee_asm/game/chr/ch_110158", func_00110270);

float func_00110280(Chr *chr)
{
    return chr->f160;
}

INCLUDE_ASM("build/ee_asm/game/chr/ch_110158", func_00110288);

float func_001102F8(Chr *chr)
{
    return chr->f174;
}

void func_00110300(Chr *chr, float v)
{
    chr->f164 = v;
}

void func_00110308(Chr *chr, float v)
{
    chr->f174 = v;
}

void Ch_SetDirF(void *chr, float v)
{
    func_00110300(chr, v);
    func_00110308(chr, v);
}

s32 Ch_EnRotHokan(Chr *chr, s32 v)
{
    s32 old = FLAGS_BIT(chr, 10);

    FLAGS_SET(chr, 10, v);
    return old;
}

void Ch_ResetMotion(Chr *chr)
{
    chr->h734 = 0;
    chr->b742 = 0; /* DEBT(ORDER): scheduler needs this order to emit the original sequence */
    chr->w73C = 1;
}

void func_00110390(FloatTween *t, float v, s32 frames)
{
    t->dst = v;
    t->frames = frames;
    if (frames == 0) {
        t->cur = v;
    }
}

void func_001103A8(Chr *chr, float v, s32 frames)
{
    func_00110390((FloatTween *)&chr->f358, v, frames); /* DEBT(CAST): tween record inside the pad */
}

INCLUDE_ASM("build/ee_asm/game/chr/ch_110158", func_001103B0);

void func_00110478(Chr *chr, float v, s32 frames)
{
    func_00110390((FloatTween *)&chr->f364, v, frames); /* DEBT(CAST) */
    func_001103B0(chr, v, frames);
}

void Ch_SetShadeCol(Chr *chr, s32 frames, float x, float y, float z)
{
    func_00110390((FloatTween *)&chr->f328, x, frames); /* DEBT(CAST): tweens at 0x328/0x334/0x340 */
    func_00110390((FloatTween *)&chr->f334, y, frames);
    func_00110390((FloatTween *)&chr->f340, z, frames);
}

void func_00110530(Chr *chr, float x, float y, float z)
{
    chr->fC0 = x;
    chr->fC4 = y;
    chr->fC8 = z;
}

void func_00110540(Chr *chr, float v, s32 frames)
{
    func_00110390((FloatTween *)&chr->f34C, v, frames); /* DEBT(CAST): tween record inside the pad */
}

void func_00110548(Chr *chr, float v, s32 frames)
{
    func_00110390((FloatTween *)((u8 *)chr + 0x370), v, frames); /* DEBT(CAST): tween record inside the pad */
}

void Ch_SetMotionType(Chr *chr, s8 v)
{
    chr->b192 = v;
}

void Ch_SetFieldMode(Chr *chr, s8 v)
{
    chr->b191 = v;
}

s8 func_00110560(Chr *chr)
{
    return chr->b191;
}

void func_00110568(Chr *chr, float v)
{
    chr->f178 = v;
}

/* DEBT(TYPE): declared with a return type (shared header) but no value is returned; callers ignore it */
s32 Ch_EnMapID(Chr *chr, int v)
{
    FLAGS_SET(chr, 7, 1 - v);
    if (FLAGS_BIT(chr, 7)) {
        chr->w80 = 0;
        chr->f84 = -1.0f;
        chr->w88 = 0;
        Ch_IdEnableShade(chr, 0);
    } else {
        Ch_IdEnableShade(chr, 1);
    }
}

void func_001105D8(Chr *chr, s32 v)
{
}

s32 Ch_EnBodyHit(Chr *chr, int b)
{
    s64 old = chr->flags;

    chr->flags = (old & ~0x100) | (((1 - b) & 1) << 8);
    return (s32)(old >> 8) & 1;
}

s32 func_00110618(Chr *chr)
{
    return ~(s32)(chr->flags >> 8) & 1;
}

s32 func_00110630(Chr *chr)
{
    return FLAGS_BIT(chr, 11);
}

s32 Ch_EnClip(Chr *chr, s32 v)
{
    s32 old = FLAGS_BIT(chr, 11);

    FLAGS_SET(chr, 11, v);
    return old;
}

void func_00110678(Chr *chr, s32 v)
{
    Ch_EnMapID(chr, ~v & 1);
}

void func_00110688(Chr *chr, s32 v)
{
    func_001105D8(chr, ~v & 1);
}

void func_00110698(Chr *chr, s32 v)
{
    Ch_EnBodyHit(chr, ~v & 1);
}
