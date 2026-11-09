/* tu_016 0x110910-0x110cd8: low; ~Ch (config/tu_map.tsv) */
#define func_001109F0 _hdr_func_001109F0
#include "common.h"
#include "ffx/q0.h"
#include "ffx/r0.h"
#include "ffx/u0.h"
#include "ffx/v0.h"
#undef func_001109F0

float func_00110910(Chr *chr)
{
    return chr->param->f1C;
}

float Ch_SetThickness(Chr *chr, float v)
{
    float old = chr->f4F0;

    if (v <= 0.0f) {
        chr->f4F0 = chr->param->f1C;
    } else {
        chr->f4F0 = v;
    }
    return old;
}

float func_00110950(Chr *chr)
{
    return chr->f4F8;
}

void func_00110958(Chr *chr, float v)
{
    if (v < 0.0f) {
        chr->f4F8 = chr->param->f24;
    } else {
        chr->f4F8 = v;
    }
}

float func_00110980(Chr *chr)
{
    return chr->f500;
}

void func_00110988(Chr *chr, float v)
{
    if (v < 0.0f) {
        chr->f500 = chr->param->f2C;
    } else {
        chr->f500 = v;
    }
}

float Ch_GetFixHeight(Chr *chr)
{
    return chr->f4FC;
}

void func_001109B8(Chr *chr, float v)
{
    if (v < 0.0f) {
        chr->f4FC = chr->param->f28;
    } else {
        chr->f4FC = v;
    }
}

float func_001109E0(Chr *chr)
{
    return chr->param->f20;
}

s32 _m2c_func_001109F0_Ch_SetThickness(Chr *, float) __asm__("Ch_SetThickness");
/* DEBT(CAST) */
void func_001109F0(float fparg0) {
    Chr *var_16;

    var_16 = D_00300664;
    if (var_16 != &var_16[D_00300668]) {
        do {
            if (var_16->active != 0) {
                _m2c_func_001109F0_Ch_SetThickness(var_16, fparg0);
            }
            var_16 = (Chr *)((u8 *)var_16 + (0x840));
        } while (var_16 != &D_00300664[D_00300668]);
    }
}

void Ch_MotionSetHokan(Chr *chr, int v)
{
    chr->flags &= ~0x10000;
    chr->h746 = v;
    if (v == 0) {
        chr->u828.flags2 |= 1L << 34;
    }
}

void Ch_MotionSetNextHokan(Chr *chr, s32 v)
{
    if (v == -1) {
        chr->h748 = 0;
    } else if (v != 0) {
        chr->h748 = v;
    } else {
        chr->h748 = 1;
    }
}

float func_00110AF0(Chr *chr)
{
    return chr->param->f30;
}

void Ch_SetHideCalc(Chr *chr, s8 v)
{
    chr->b18D = v;
}

s32 func_00110B08(Chr *chr)
{
    s32 r = 0;

    if (chr->b18D != 0 || FLAGS_BIT(chr, 13) || chr->t34C.cur == 0.0f) {
        r = 1;
    }
    return r;
}

void Ch_SetBattleChrNum(Chr *chr, s32 v)
{
    chr->w198 = v;
}

s16 func_00110B58(Chr *chr)
{
    return chr->u828.s.h82E;
}

s32 Ch_EffectGetResidentPtr(Chr *chr)
{
    return chr->param->w124;
}

s32 func_00110B70(Chr *chr)
{
    return chr->w70C;
}

s32 func_00110B78(Chr *chr)
{
    return chr->w404;
}

void Ch_EffectSetEffectLevel(Chr *chr, s32 v)
{
    chr->w404 = v;
}

s32 func_00110B88(Chr *chr)
{
    return FLAGS_BIT(chr, 30);
}

void Ch_SetOverlapHit(Chr *chr, s32 v)
{
    FLAGS_SET(chr, 30, v);
}

s8 graphicCharacterInstanceSetMeshSegmentAlpha(Chr *chr, s32 i, s32 v)
{
    s8 old = chr->ents[i].b18;
    chr->ents[i].b18 = v & 1;
    return old;
}

s8 Ch_ModelGetHide(Chr *chr, s32 i)
{
    return chr->ents[i].b18;
}

s32 func_00110C00(Chr *chr, s32 i)
{
    return chr->ents[i].w04;
}

s32 func_00110C18(Chr *chr, s32 i)
{
    return chr->ents[i].w08;
}

void func_00110C30(Chr *chr, s32 i, float v)
{
    chr->ents[i].f14 = v;
}

void func_00110C48(Chr *chr, float v)
{
    chr->f528 = v;
}

void func_00110C50(Chr *chr, s32 v)
{
    FLAGS_SET(chr, 34, v);
}

void Ch_ClothSetEnable(Chr *chr, s32 v)
{
    FLAGS_SET(chr, 22, v);
}

void Ch_Vu1SetClipmode(Chr *chr, s32 v)
{
    FLAGS_SET(chr, 35, v);
}
