/* tu_022 0x115e70-0x116cb8: low; ~Sg (config/tu_map.tsv) */
#include "common.h"
#include "ffx/q0.h"
#include "ffx/r0.h"
#include "ffx/u0.h"

void Sg_SetPlayer(s32 v)
{
    D_0057F650 = v;
    D_0057F654 = 0;
    D_0057F658 = 0;
    D_0057F65C = 0;
    D_0057F660 = 0;
}

s32 Sg_GetPlayer(void)
{
    return D_0057F650;
}

int Sg_GetPlayerPos(float *out)
{
    float x, y, z;

    if (D_0057F650 == 0) {
        return 1;
    }
    Ch_GetPos((Chr *)D_0057F650, &x, &y, &z); /* DEBT(TYPE): D_0057F650 is declared s32 but holds a Chr pointer */
    out[0] = x;
    out[1] = y;
    out[2] = z;
    return 0;
}

void func_00115F10(void)
{
    D_003038E0 = (D_003038E0 + 1) & 1;
}

s32 func_00115F28(void)
{
    return D_003038E0;
}

void func_00115F38(int v)
{
    D_003038E4 = (D_003038E4 & ~1) | (v != 0);
}

s32 func_00115F60(void)
{
    return D_003038E4 & 0x1;
}

void func_00115F70(int v)
{
    D_003038E4 = (D_003038E4 & ~2) | (v ? 2 : 0);
}

s32 func_00115F98(void)
{
    return ((u8)D_003038E4 >> 1) & 1;
}

void func_00115FB0(void)
{
    D_003038E8 = (D_003038E8 + 1) & 1;
    if (ffx_debugmode) {
        if (D_003038E8) {
            func_2031678(0);
        } else {
            func_2031678(1);
        }
    }
}

s8 Sg_GetLRButtonMode(void)
{
    return D_0057F680;
}

void func_00116000(s32 v)
{
    D_0057F680 = v & 0x1;
}

void func_00116010(s8 v)
{
    D_0057F682 = v;
}

s8 func_00116020(void)
{
    return D_003038EC;
}

void func_00116030(s32 v)
{
    if (v >= 100) {
        v = 99;
    }
    if (v < 0) {
        v = 0;
    }
    D_003038EC = v;
}

s8 func_00116058(void)
{
    return D_0057F683;
}

s32 Sg_GetCurExecFrames(void)
{
    int a = func_00116058();

    return (D_0057F681 ? D_0057F682 : D_003038EC) | a;
}

s32 func_001160B0(void)
{
    return D_00303904;
}

INCLUDE_ASM("build/ee_asm/game/main/sg_115E70", Sg_ControlMain);

void func_00116280(s32 a, float v)
{
    switch (a) {
    case 1:
        D_0057F688 = v;
        break;
    case 2:
        D_0057F68C = v;
        break;
    case 0x12:
        D_0057F690 = v;
        break;
    case 0x13:
        D_0057F694 = v;
        break;
    }
}

INCLUDE_ASM("build/ee_asm/game/main/sg_115E70", Sg_PlayerSetDirFix);

void func_00116388(void)
{
    D_0057F664 = func_00119810();
    D_003038F0 = 0;
}

void func_001163B8(s8 v)
{
    D_0057F6A0 = v;
}

INCLUDE_ASM("build/ee_asm/game/main/sg_115E70", func_001163C8);

void Sg_PlayerInitAll(void)
{
    Sg_SetPlayer(0);
    func_001163B8(1);
}

void func_001164B0(void)
{
    Sg_PlayerInitAll();
    func_00116280(1, 16.0f);
    func_00116280(2, 34.0f);
    func_00116280(0x12, 20.0f);
}

INCLUDE_ASM("build/ee_asm/game/main/sg_115E70", Sg_ControlPlayer);
