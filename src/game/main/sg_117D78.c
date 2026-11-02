/* tu_025 0x117d78-0x1194e0: low; ~Sg (config/tu_map.tsv) */
#include "common.h"
#include "ffx/q0.h"
#include "ffx/r0.h"
#include "ffx/u0.h"
#include "ffx/s0.h"
#include "ffx/v0.h"

void Sg_Flash(int a, int b, int c, int d)
{
    D_005803F8.b0 = 6;
    D_00580428 |= 4;
    D_005803F8.h4 = a;
    D_005803F8.h6 = a;
    D_005803F8.b1 = b;
    D_005803F8.b2 = c;
    D_005803F8.b3 = d;
}

void func_00117DB0(int a, int b, int c)
{
    FxSlot *s = &((FxSlot *)D_005803D8)[4]; /* DEBT(CAST): D_005803D8 is declared as bytes */

    D_00580428 |= 0x10;
    if (b) {
        s->kind = c ? 4 : 2;
    } else {
        s->kind = c ? 5 : 3;
    }
    s->h4 = a;
    s->h6 = a;
    s->b3 = 0xFF;
    s->b2 = 0xFF;
    s->b1 = 0xFF;
}

void func_00117E08(int v)
{
    func_00117DB0(v, 0, 1);
}

void func_00117E18(int v)
{
    func_00117DB0(v, 0, 0);
}

void func_00117E28(int v)
{
    func_00117DB0(v, 1, 1);
}

void func_00117E38(int v)
{
    func_00117DB0(v, 1, 0);
}

s16 func_00117E48(void)
{
    return D_005803EE;
}

void Sg_Blur(int a)
{
    D_005803E8.b0 = 1;
    D_00580428 |= 2;
    if (a) {
        D_005803E8.h6 = a;
        D_005803E8.h4 = 1;
    } else {
        D_005803E8.h4 = 0;
        D_005803E8.h6 = 0;
    }
}

s16 func_00117E98(void)
{
    return D_005803DE;
}

INCLUDE_ASM("build/ee_asm/game/main/sg_117D78", Sg_AccSetAlpha);

INCLUDE_ASM("build/ee_asm/game/main/sg_117D78", Sg_FilterAdd);

void Sg_FilterSub(int a, int b, int c, int d)
{
    Sg_FilterAdd(a, b, c, d);
    D_00580408 = 8;
}

/* DEBT(TYPE): global type guessed from the access width only */
void func_00117FC8(void)
{
    D_005803FC = 0;
}

/* DEBT(TYPE): global type guessed from the access width only */
void Sg_FilterReset(void)
{
    D_0058040C = 0;
}

void Sg_FadeReset(void)
{
    D_0058041C = 0;
}

s16 func_00117FF8(void)
{
    return D_0058041C;
}

void graphicAddScreenFadeTask(FxSlot *s, int v)
{
    func_0011D998(s->b1, s->b2, s->b3, v);
    Sg_GsPRIM(0x46);
    Sg_GsXYZF2(0, 0);
    Sg_GsXYZF2(D_00307F40, D_00307F44);
}

s32 Sg_EnFocus(s32 v)
{
    s32 old = D_00580444;

    D_00580444 = v & 1;
    return old;
}

s32 func_00118070(void)
{
    return D_00580444 & 0x1;
}

s32 Sg_GetFocus(s32 i)
{
    return D_00580430[i];
}

void Sg_SetFocus(s32 i, s32 v)
{
    D_00580430[i] = v;
    if (v != 0) {
        D_00580440 |= 1 << v;
        Sg_EnFocus(1);
    } else {
        D_00580440 &= ~1;
    }
}

void func_001180F0(void)
{
    D_00580444 = (D_00580444 + 1) & 1;
    if (D_00580444) {
        Sg_SetFocus(0, Sg_GetFocus(0));
        Sg_SetFocus(1, Sg_GetFocus(1));
    }
}

void func_00118150(void)
{
    Sg_SetFocus(0, 0x10000);
    Sg_SetFocus(1, 0x20000);
    Sg_EnFocus(0);
}

void Sg_InitFilter(void)
{
    CALL_func_002ED0E0_INT(D_005803D8, 0x50U);
    D_00580428 = 0;
    D_00580440 = 0;
    func_00118150();
}

INCLUDE_ASM("build/ee_asm/game/main/sg_117D78", func_001181B8);

INCLUDE_ASM("build/ee_asm/game/main/sg_117D78", func_00118308);

INCLUDE_ASM("build/ee_asm/game/main/sg_117D78", func_00118470);
INCLUDE_RODATA("build/ee_asm/game/main/sg_117D78/rodata", jtbl_00569A00);

INCLUDE_ASM("build/ee_asm/game/main/sg_117D78", Sg_DebugFill);

/* old-style definition: callers in this file pass other argument counts (DEBT(TYPE)) */
void func_00118A40()
{
    D_00307EAC = 0x1;
}

void func_00118A50(s8 v)
{
    D_0058044E = v;
}

void func_00118A60(s8 v)
{
    D_0058044F = v;
}

void func_00118A70(s8 v)
{
    D_00580450 = v;
}

INCLUDE_ASM("build/ee_asm/game/main/sg_117D78", func_00118A80);

INCLUDE_ASM("build/ee_asm/game/main/sg_117D78", sg_AccSetCurrent);

INCLUDE_ASM("build/ee_asm/game/main/sg_117D78", func_00118CD8);

/* DEBT(CAST): shared declarations retain untyped handles or buffers at these calls. */
void func_00118DE0(void)
{
    s32 buffer;

    buffer = Sg_GetSpadPtr();
    if (D_0058044F != 0)
    {
        Sg_GsSetPacket((Cmd16 *) buffer);
        func_0011D800();
        if (D_0058044F != 0)
        {
            Sg_GsFRAME_16(0xD0, 0);
            Sg_GsFRAME2_16(0xD0, 0);
        }
        else
        {
            func_00118CD8();
        }
        func_0010E028(Sg_GsEnd2());
    }
}

void func_00118E70(void)
{
    Sg_GsSetPacket((Cmd16 *)Sg_GetSpadPtr()); /* DEBT(CAST): getter returns s32 */
    func_0011D800();
    if (D_00580450) {
        Sg_GsFRAME_16(0xD0, 0);
        Sg_GsFRAME2_16(0xD0, 0);
    } else {
        func_00118CD8();
    }
    func_0010E028((int)Sg_GsEnd2()); /* DEBT(CAST) */
}

/* DEBT(CAST): shared declarations retain untyped handles or buffers at these calls. */
void func_00118EE0(void)
{
    s32 buffer;

    buffer = Sg_GetSpadPtr();
    if (D_0058044E != 0)
    {
        Sg_GsSetPacket((Cmd16 *) buffer);
        func_0011D800();
        func_0011DF70(0, 0, 0, 0, 0, 0, 1, 1);
        Sg_GsZBUF(1);
        func_00118A80(0x80);
        Sg_GsZBUF(0);
        func_0010E028(Sg_GsEnd2());
    }
}

void Sg_AccSetClear(u8 a, u8 b, u8 c, u8 d)
{
    D_00580449 = a;
    D_0058044A = b;
    D_0058044B = c;
    D_0058044C = d;
}

void func_00118F98(void)
{
    Sg_AccSetAlpha(0, 0);
    func_00118A50(0);
    func_00118A40(0);
    func_00118A60(0);
    func_00118A70(0);
    Sg_AccSetClear(0, 0, 0, 0);
}

s32 func_00118FE8(void)
{
    return D_005803D0;
}

s32 Sg_VramGetAddrZ(void)
{
    return 0x84000;
}

s32 func_00119008(void)
{
    return D_005803D4;
}

s32 func_00119018(void)
{
    return D_005803D0;
}

void func_00119028(s8 v)
{
    D_00307EB4 = v;
}

void func_00119038(s8 v)
{
    D_00307EB5 = v;
}

INCLUDE_ASM("build/ee_asm/game/main/sg_117D78", Sg_DrawSetEnvironmentInit);

INCLUDE_ASM("build/ee_asm/game/main/sg_117D78", Sg_DrawSetEnvironmentInitMovie);

INCLUDE_ASM("build/ee_asm/game/main/sg_117D78", Sg_DrawSetEnvironment);
