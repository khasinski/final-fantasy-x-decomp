/* tu_015 0x1106a8-0x110910: low; ~Ch (config/tu_map.tsv) */
#include "common.h"
#include "ffx/q0.h"
#include "ffx/r0.h"
#include "ffx/u0.h"
#include "ffx/v0.h"

s32 func_001106A8(Chr *chr, int on, int mask)
{
    s32 old = (chr->b18C & mask) != 0;

    if (on) {
        chr->b18C |= mask;
    } else {
        chr->b18C &= ~mask;
        *(u64 *)&chr->f828 |= 1L << 34; /* DEBT(CAST): 64-bit flag word at 0x828 overlaps f828/h82E */
    }
    return old;
}

s32 graphicLevelGetNameHash(s32 a, s32 b)
{
    return func_001106A8(a, b, 1);
}

s32 func_00110718(s32 a, s32 b)
{
    return func_001106A8(a, b, 2);
}

s32 func_00110738(s32 a, s32 b)
{
    return func_001106A8(a, b, 0x10);
}

s8 func_00110758(Chr *chr)
{
    return chr->b18C;
}

s32 Ch_GetHideEvent(Chr *chr)
{
    return (u8)chr->b18C & 1;
}

void func_00110770(Chr *chr, float v)
{
    /* DEBT(ORDER): descending order reproduces the original store sequence */
    chr->f68 = v;
    chr->f64 = v;
    chr->f60 = v;
}

void Ch_SetScale(Chr *chr, s32 mask, float x, float y, float z)
{
    if (mask & 1) {
        chr->f60 = x;
    }
    if (mask & 2) {
        chr->f64 = y;
    }
    if (mask & 4) {
        chr->f68 = z;
    }
}

void Ch_SetOffset(Chr *chr, float x, float y, float z)
{
    chr->f70 = x;
    chr->f74 = y;
    chr->f78 = z;
}

float Ch_GetScaleX(Chr *chr)
{
    return chr->f60;
}

float Ch_GetScaleY(Chr *chr)
{
    return chr->f64;
}

float Ch_GetScaleZ(Chr *chr)
{
    return chr->f68;
}

void func_001107D8(Chr *chr, float *x, float *y, float *z)
{
    if (x) {
        *x = chr->f60;
    }
    if (y) {
        *y = chr->f64;
    }
    if (z) {
        *z = chr->f68;
    }
}

void Ch_SetGravMode(Chr *chr, s8 v)
{
    chr->b18E = v;
}

s8 func_00110818(Chr *chr)
{
    return chr->b18E;
}

void Ch_SetMotionSpeed(Chr *chr, s16 v)
{
    chr->h75C = v;
}

s16 Ch_GetMotionSpeed(Chr *chr)
{
    return chr->h75C;
}

void Ch_SetOrgMatrix(Chr *chr, s32 v)
{
    chr->w110 = v;
}

void func_00110838(Chr *chr, float v)
{
    chr->f114 = v;
}

s32 func_00110840(Chr *chr)
{
    return chr->w110;
}

void func_00110848(Chr *chr, float v)
{
    chr->f504 = v;
}

void func_00110850(Chr *chr, s32 i, s32 v)
{
    if (v == -1) {
        chr->w768[i] = D_00303868[i];
    } else {
        chr->w768[i] = v;
    }
}

float func_00110888(Chr *chr, float v)
{
    float old = chr->f17C;

    if (0.0f < v) {
        chr->f17C = v;
    } else {
        chr->f17C = 18.0f;
    }
    return old;
}

s8 func_001108B8(Chr *chr, s8 v)
{
    s8 old = chr->b18F;

    chr->b18F = v;
    return old;
}

float Ch_SetWeight(Chr *chr, float v)
{
    float old = chr->f50C;

    chr->f50C = v;
    return old;
}

float Ch_SetClipZ(Chr *chr, float v)
{
    float old = CHR_F32(chr, 0x180) / 10.0f; /* DEBT(CAST) */

    CHR_F32(chr, 0x180) = v * 10.0f;
    return old;
}

s8 func_00110900(Chr *chr)
{
    return chr->b18C;
}

void func_00110908(Chr *chr, s8 v)
{
    chr->b18C = v;
}
