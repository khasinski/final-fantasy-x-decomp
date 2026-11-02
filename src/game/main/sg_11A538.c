/* tu_029 0x11a538-0x11ba20: low; ~Sg (config/tu_map.tsv) */
#include "common.h"
#include "ffx/q0.h"
#include "ffx/r0.h"
#include "ffx/u0.h"
#include "ffx/v0.h"
#include "ffx/g0.h"

s32 *Sg_GetDBuffDC(s32 *p)
{
    if (p != 0) {
        *p = D_00307F2C;
    }
    return &D_005804F0;
}

s32 func_0011A558(void)
{
    return D_00307F40;
}

s32 func_0011A568(void)
{
    return D_00307F44;
}

s8 Sg_GetDispMode(void)
{
    return D_00580823;
}

void func_0011A588(s32 a, s32 b)
{
    D_00307F40 = a;
    D_00307F44 = b;
}

void func_0011A5A0(s8 v)
{
    D_00580823 = v;
}

void func_0011A5B0(s8 v)
{
    D_00580824 = v;
}

void Sg_SetMovieGomiAvoid(s8 v)
{
    D_00580825 = v;
}

INCLUDE_ASM("build/ee_asm/game/main/sg_11A538", Sg_SetDBuffDc);

s8 func_0011A968(s32 v)
{
    s8 old = D_00580826;

    D_00580826 = v & 1;
    return old;
}

s8 func_0011A980(void)
{
    return D_00580826;
}

s8 func_0011A990(s32 v)
{
    s8 old = D_00580827;

    D_00580827 = v & 1;
    return old;
}

s8 func_0011A9A8(void)
{
    return D_00580827;
}

s8 func_0011A9B8(s32 v)
{
    s8 old = D_00580828;

    D_00580828 = v & 1;
    return old;
}

s8 func_0011A9D0(void)
{
    return D_00580828;
}

s8 func_0011A9E0(s32 v)
{
    s8 old = D_00580829;

    D_00580829 = v & 1;
    return old;
}

s8 func_0011A9F8(void)
{
    return D_00580829;
}

s8 func_0011AA08(s32 v)
{
    s8 old = D_0058082A;

    D_0058082A = v & 1;
    return old;
}

s8 func_0011AA20(void)
{
    return D_0058082A;
}

s8 Sg_EnableDrawGui(s32 v)
{
    s8 old = D_0058082B;

    D_0058082B = v & 1;
    return old;
}

s8 func_0011AA48(void)
{
    return D_0058082B;
}

s8 Sg_EnableDrawMenu(s32 v)
{
    s8 old = D_0058082C;

    D_0058082C = v & 1;
    return old;
}

s8 func_0011AA70(void)
{
    return D_0058082C;
}

void func_0011AA80(void) {
}

s8 func_0011AA88(void)
{
    return D_0058082D;
}

void Sg_SetMapAlphaFast(s8 v)
{
    D_0058082E = v;
}

s8 func_0011AAA8(void)
{
    return D_0058082E;
}

void func_0011AAB8(s32 v)
{
    D_00580831 = v & 0x1;
}

s8 func_0011AAC8(void)
{
    return D_00580831;
}

void func_0011AAD8(s8 v)
{
    D_00580832 = v;
}

s8 func_0011AAE8(void)
{
    return D_00580832;
}

s32 func_0011AAF8(void)
{
    D_00580831 = ((u8)D_00580831 + 1) & 1; /* DEBT(TYPE): read unsigned here, signed below */
    func_00104518(D_00580831);
    return 1 - D_00580831;
}

void func_0011AB40(void)
{
    D_0058082F = ((u8)D_0058082F + 1) & 1;
}

s8 func_0011AB58(void)
{
    return D_0058082F;
}

s8 func_0011AB68(s32 v)
{
    s8 old = D_0058082F;

    D_0058082F = v & 1;
    return old;
}

void func_0011AB80(s8 v)
{
    D_00580830 = v;
}

void func_0011AB90(void)
{
    D_00580821 = (D_00580821 + 1) & 1;
}

void func_0011ABA8(s8 v)
{
    D_00580833 = v;
}

s8 Sg_GetPause(void)
{
    return D_00580833;
}

INCLUDE_ASM("build/ee_asm/game/main/sg_11A538", func_0011ABC8);

s32 func_0011AC68(void)
{
    return D_00580870;
}

void func_0011AC78(void)
{
    func_002EF0D0(&D_00580838, 0, 0x38);
    *(volatile s32 *)0x10000800 = 0; /* EE timer 1 counter */
}

s32 func_0011ACB0(void)
{
    return D_005808AC;
}

s32 Sg_GetFuka(int i)
{
    return (&D_00580870)[i]; /* DEBT(TYPE): globals.h declares a single s32 */
}

void func_0011ACD8(void)
{
    D_005808AC = D_00580838 + *(volatile s32 *)0x10000800; /* EE timer 2 counter */
}

s32 func_0011AD00(int i)
{
    u32 t = T0_COUNT;

    D_00580838 += t;
    if (i != -1) {
        (&D_00580838)[i] += t; /* DEBT(TYPE): D_00580838 is the first of an array of counters */
    }
    T0_COUNT = 0;
    return 0;
}

s32 Sg_SetKeepFps(int v)
{
    s8 old = D_005808B4;
    D_005808B4 = v;
    return old;
}

s8 Sg_GetKeepFps(void)
{
    return D_005808B4;
}

float func_0011AD70(void)
{
    return D_00307F3C;
}

s32 func_0011AD80(void)
{
    return D_00307F38;
}

void func_0011AD90(void)
{
    D_00307F30++;
    D_00307F34++;
    func_002D3920();
    if (ffx_debugmode) {
        func_20318A8();
    }
}

INCLUDE_ASM("build/ee_asm/game/main/sg_11A538", Sg_MainInit);

void SaveDataIsScreenClosed(s32 a)
{
    D_005808B8 = a;
    D_005808BC = -1;
}

s32 Sg_MenuGetResult(void)
{
    return D_005808BC;
}

/* DEBT(ORDER): independent counter/result updates retain the original schedule. */
s32 Sg_MainCheckMenu(void)
{
    s32 saved_count;
    s32 status;
    s32 next_count;
    s32 result;

    result = 0;
    if (D_005808B8 != -1)
    {
        saved_count = D_00307F30;
        status = TOMenuOpen(D_005808B8);
        D_005808BC = status;
        if (status == 0)
        {
            next_count = saved_count + 1;
            result = 1;
            D_00307F30 = next_count;
            D_005808B0 = next_count;
        }
        D_005808B8 = -1;
    }
    if (D_003038F8 & 0x10)
    {
        SaveDataIsScreenClosed(0U);
    }
    return result;
}

INCLUDE_ASM("build/ee_asm/game/main/sg_11A538", Sg_MainCalcRate);

INCLUDE_ASM("build/ee_asm/game/main/sg_11A538", func_0011B218);

INCLUDE_ASM("build/ee_asm/game/main/sg_11A538", Sg_MainLoop);

INCLUDE_ASM("build/ee_asm/game/main/sg_11A538", func_0011B9D8);
