/* tu_011 0x10d6d0-0x10de98: medium; ~Sg (config/tu_map.tsv) */
#define Sg_PLightGetColor _hdr_Sg_PLightGetColor
#include "common.h"
#include "ffx/q0.h"
#include "ffx/r0.h"
#include "ffx/s0.h"
#include "ffx/u0.h"
#undef Sg_PLightGetColor

void func_0010D6D0(void)
{
    D_0057EAFC = 0;
    D_0057EB00 = 0;
}

s32 func_0010D6E8(void)
{
    func_0011D590((s32)D_0057EAFC, 6); /* DEBT(TYPE): handle passed as int */
    D_0057EAFC = 0;
    D_0057EB00 = 0;
    func_001031F8();
}

void func_0010D720(void)
{
    func_0010D6E8();
}

extern char D_00569620[];

typedef struct PLightEntry {
    float x, y, z, f0C;
    float color[3], f1C;
    float f20, f24;
    s8 flag, flag2;
    u8 pad2A[6];
} PLightEntry;

void Sg_PLightAllocate(s32 n)
{
    s32 i;

    func_0010D720();
    D_0057EAFC = user_malloc(n * sizeof(PLightEntry), 6, D_00569620, 0x56F);
    D_0057EB00 = n;
    for (i = 0; i < n; i++) {
        ((PLightEntry *)&D_0057EAFC[i])->flag = 0;
        ((PLightEntry *)&D_0057EAFC[i])->f0C = 1.0f;
        ((PLightEntry *)&D_0057EAFC[i])->f1C = 1.0f;
    }
}

void func_0010D7C8(s32 idx, s32 mask, float x, float y, float z)
{
    TblEntry30 *e = &D_0057EAFC[idx];

    if (D_0057EB00 >= idx) {
        if (mask & 1) {
            e->x = x;
        }
        if (mask & 2) {
            e->y = y;
        }
        if (mask & 4) {
            e->z = z;
        }
    }
}

void func_0010D818(s32 arg0, s32 arg1, s32 arg2, s32 arg3)
{
    TblEntry30 *entry;
    s32 outside;

    /* DEBT(ORDER): resolve entry before reading the independent limit. */
    entry = &D_0057EAFC[arg0];
    outside = D_0057EB00 < arg0;
    if (outside == 0)
    {
        entry->color[0] = (float) ((float) arg1 / 255.0f);
        entry->color[1] = (float) ((float) arg2 / 255.0f);
        entry->color[2] = (float) ((float) arg3 / 255.0f);
    }
    return;
}

void Sg_PLightGetPos(s32 idx, float *x, float *y, float *z)
{
    TblEntry30 *e = &D_0057EAFC[idx];

    if (D_0057EB00 >= idx) {
        if (x) {
            *x = e->x;
        }
        if (y) {
            *y = e->y;
        }
        if (z) {
            *z = e->z;
        }
    }
}

void Sg_PLightGetColor(s32 arg0, s32 *arg1, s32 *arg2, s32 *arg3) {
    TblEntry30 *temp_10;

    temp_10 = &D_0057EAFC[arg0];
    if (D_0057EB00 >= arg0) {
        if (arg1 != 0) {
            *arg1 = (s32) (temp_10->color[0] * 255.0f);
        }
        if (arg2 != 0) {
            *arg2 = (s32) (temp_10->color[1] * 255.0f);
        }
        if (arg3 != 0) {
            *arg3 = (s32) (temp_10->color[2] * 255.0f);
        }
    }
}

void Sg_PLightSetEnable(s32 idx, s32 flag) {
    if (D_0057EB00 >= idx) {
        D_0057EAFC[idx].flag = flag;
    }
}

s32 func_0010D9C0(s32 idx)
{
    if (D_0057EB00 < idx) {
        return 0;
    }
    return D_0057EAFC[idx].flag;
}

void func_0010D9F8(s32 idx, float v)
{
    if (D_0057EB00 >= idx) {
        D_0057EAFC[idx].f20 = v;
    }
}

float Sg_PLightGetRadius(s32 idx)
{
    if (D_0057EB00 < idx) {
        return 0.0f;
    }
    return D_0057EAFC[idx].f20;
}

void Sg_PLightSetAttenuation(s32 idx, float v)
{
    if (D_0057EB00 >= idx) {
        D_0057EAFC[idx].f24 = v;
    }
}

float Sg_PLightGetAttenuation(s32 idx)
{
    if (D_0057EB00 < idx) {
        return 0.0f;
    }
    return D_0057EAFC[idx].f24;
}

void func_0010DAE8(s32 idx, s32 v)
{
    if (D_0057EB00 >= idx) {
        D_0057EAFC[idx].flag2 = v;
    }
}

s32 Sg_PLightGetLight(s32 idx)
{
    if (D_0057EB00 < idx) {
        return 0;
    }
    return D_0057EAFC[idx].flag2;
}

void Sg_PLightDefine(float x, float y, float z, float w, s32 idx, s32 a, s32 b, s32 c, s32 d)
{
    if (D_0057EB00 >= idx)
    {
        func_0010D7C8(idx, 7, x, y, z);
        func_0010D818(idx, a, b, c);
        func_0010D9F8(idx, w);
        func_0010DAE8(idx, d);
        Sg_PLightSetAttenuation(idx, 2.0f);
        Sg_PLightSetEnable(idx, 1);
    }
}

void func_0010DC38(Chr *chr, s8 v)
{
    chr->b194 = v;
}

s8 func_0010DC40(Chr *chr)
{
    return chr->b194;
}

void func_0010DC48(Chr *chr, s32 val, s32 mask)
{
    chr->b194 = ((u8)chr->b194 & ~mask) | val;
}

INCLUDE_ASM("build/ee_asm/game/main/sg_10D6D0", func_0010DC60);
