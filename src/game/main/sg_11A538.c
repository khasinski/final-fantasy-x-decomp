/* tu_029 0x11a538-0x11ba20: low; ~Sg (config/tu_map.tsv) */
#define func_0011B9D8 _hdr_func_0011B9D8
#define Sg_MainInit _hdr_Sg_MainInit
#include "common.h"
#include "ffx/q0.h"
#include "ffx/r0.h"
#include "ffx/u0.h"
#include "ffx/v0.h"
#include "ffx/g0.h"
#undef Sg_MainInit
#undef func_0011B9D8

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

void _m2c_Sg_MainInit_Ch_ChrMemHeapSet() __asm__("Ch_ChrMemHeapSet");
void _m2c_Sg_MainInit_Ch_InitAll() __asm__("Ch_InitAll");
void _m2c_Sg_MainInit_MsBattleInit() __asm__("MsBattleInit");
void _m2c_Sg_MainInit_MsBattleMemInit() __asm__("MsBattleMemInit");
void _m2c_Sg_MainInit_MsCameraInit() __asm__("MsCameraInit");
void _m2c_Sg_MainInit_MsDebugInfoRead() __asm__("MsDebugInfoRead");
void _m2c_Sg_MainInit_SaveDataIsScreenClosed(s32) __asm__("SaveDataIsScreenClosed");
s32 _m2c_Sg_MainInit_Sg_CalcScreenMatrix() __asm__("Sg_CalcScreenMatrix");
void _m2c_Sg_MainInit_Sg_DebugFill(s32) __asm__("Sg_DebugFill");
void _m2c_Sg_MainInit_Sg_EnableDrawGui(s32) __asm__("Sg_EnableDrawGui");
void _m2c_Sg_MainInit_Sg_EnableDrawMenu(s32) __asm__("Sg_EnableDrawMenu");
void _m2c_Sg_MainInit_Sg_InitAll() __asm__("Sg_InitAll");
void _m2c_Sg_MainInit_Sg_PlayerInitAll() __asm__("Sg_PlayerInitAll");
void _m2c_Sg_MainInit_Sg_SetDBuffDc(s32) __asm__("Sg_SetDBuffDc");
void _m2c_Sg_MainInit_Sg_SetMovieGomiAvoid(s32) __asm__("Sg_SetMovieGomiAvoid");
void _m2c_Sg_MainInit_TkSg_IOPInit() __asm__("TkSg_IOPInit");
void _m2c_Sg_MainInit_func_0010B9E8(s32) __asm__("func_0010B9E8");
void _m2c_Sg_MainInit_func_00111758() __asm__("func_00111758");
void _m2c_Sg_MainInit_func_00116010(s32) __asm__("func_00116010");
void _m2c_Sg_MainInit_func_001195E8(s32, s32) __asm__("func_001195E8");
void _m2c_Sg_MainInit_func_00119830(s32) __asm__("func_00119830");
void _m2c_Sg_MainInit_func_0011A5A0(s32) __asm__("func_0011A5A0");
void _m2c_Sg_MainInit_func_0011A968(s32) __asm__("func_0011A968");
void _m2c_Sg_MainInit_func_0011A990(s32) __asm__("func_0011A990");
void _m2c_Sg_MainInit_func_0011A9B8(s32) __asm__("func_0011A9B8");
void _m2c_Sg_MainInit_func_0011A9E0(s32) __asm__("func_0011A9E0");
void _m2c_Sg_MainInit_func_0011AA08(s32) __asm__("func_0011AA08");
void _m2c_Sg_MainInit_func_0011AA80(s32) __asm__("func_0011AA80");
void _m2c_Sg_MainInit_func_0011AAB8(s32) __asm__("func_0011AAB8");
void _m2c_Sg_MainInit_func_0011AAD8(s32) __asm__("func_0011AAD8");
void _m2c_Sg_MainInit_func_0011AB68(s32) __asm__("func_0011AB68");
void _m2c_Sg_MainInit_func_0011AB80(s32) __asm__("func_0011AB80");
void _m2c_Sg_MainInit_func_0011ABA8(s32) __asm__("func_0011ABA8");
void _m2c_Sg_MainInit_func_0011FD00(s32) __asm__("func_0011FD00");
void _m2c_Sg_MainInit_func_00122B00() __asm__("func_00122B00");
void _m2c_Sg_MainInit_func_00122B08() __asm__("func_00122B08");
void _m2c_Sg_MainInit_func_00124E00(s32, s32, s8) __asm__("func_00124E00");
void _m2c_Sg_MainInit_func_00125E40() __asm__("func_00125E40");
void _m2c_Sg_MainInit_func_001578B8() __asm__("func_001578B8");
void _m2c_Sg_MainInit_func_001A56F8(s32, s32) __asm__("func_001A56F8");
void _m2c_Sg_MainInit_func_001AD9C0() __asm__("func_001AD9C0");
void _m2c_Sg_MainInit_func_00293148() __asm__("func_00293148");
void _m2c_Sg_MainInit_func_00293570() __asm__("func_00293570");
void _m2c_Sg_MainInit_func_002D3F30(s32, s32 *) __asm__("func_002D3F30");
void _m2c_Sg_MainInit_func_002D63E0(s32) __asm__("func_002D63E0");
s32 _m2c_Sg_MainInit_func_002D9868() __asm__("func_002D9868");
void _m2c_Sg_MainInit_func_002D98A8(s32, s32, s32, s32) __asm__("func_002D98A8");
void _m2c_Sg_MainInit_func_002D9A48() __asm__("func_002D9A48");
void _m2c_Sg_MainInit_func_002DA610(s32, s32) __asm__("func_002DA610");
void _m2c_Sg_MainInit_func_002DB640(s32 *, s32) __asm__("func_002DB640");
s32 _m2c_Sg_MainInit_func_002DB6D8(s32) __asm__("func_002DB6D8");
void _m2c_Sg_MainInit_func_002DB700(s32) __asm__("func_002DB700");
void _m2c_Sg_MainInit_func_002DC188() __asm__("func_002DC188");
void _m2c_Sg_MainInit_func_002DC638() __asm__("func_002DC638");
void _m2c_Sg_MainInit_func_002DCAD8() __asm__("func_002DCAD8");
void _m2c_Sg_MainInit_func_002DDAE8() __asm__("func_002DDAE8");
void _m2c_Sg_MainInit_func_002DDC78(s32) __asm__("func_002DDC78");
void _m2c_Sg_MainInit_func_002F8660(s32) __asm__("func_002F8660");
void _m2c_Sg_MainInit_func_202C7C8() __asm__("func_202C7C8");
void _m2c_Sg_MainInit_func_2031620() __asm__("func_2031620");
void _m2c_Sg_MainInit_op_init_ffx() __asm__("op_init_ffx");
void _m2c_Sg_MainInit_op_loop_ffx_after() __asm__("op_loop_ffx_after");
void _m2c_Sg_MainInit_yiInit() __asm__("yiInit");
extern s32 _m2c_Sg_MainInit_D_00307F48 __asm__("D_00307F48");
extern s32 _m2c_Sg_MainInit_D_00307F4C __asm__("D_00307F4C");
extern s32 _m2c_Sg_MainInit_func_0011AD90 __asm__("func_0011AD90");
s32 Sg_MainInit(void) {
    s32 temp_16;

    _m2c_Sg_MainInit_func_002DCAD8();
    _m2c_Sg_MainInit_func_002DC188();
    _m2c_Sg_MainInit_func_002DC638();
    _m2c_Sg_MainInit_func_002DDAE8();
    _m2c_Sg_MainInit_func_002DB700(1);
    _m2c_Sg_MainInit_MsBattleMemInit();
    _m2c_Sg_MainInit_MsDebugInfoRead();
    temp_16 = ((_m2c_Sg_MainInit_func_002D9868() ^ 1) != 0) ? 2 : 3;
    _m2c_Sg_MainInit_func_002D98A8(0, 1, temp_16, 0);
    _m2c_Sg_MainInit_func_002D9A48();
    dmaGif = _m2c_Sg_MainInit_func_002DB6D8(2);
    _m2c_Sg_MainInit_D_00307F48 = _m2c_Sg_MainInit_func_002DB6D8(0);
    _m2c_Sg_MainInit_D_00307F4C = _m2c_Sg_MainInit_func_002DB6D8(1);
    _m2c_Sg_MainInit_func_002DA610(0, 0);
    _m2c_Sg_MainInit_func_0011A5A0(0);
    _m2c_Sg_MainInit_func_002D98A8(0, 1, temp_16, 0);
    _m2c_Sg_MainInit_Sg_SetDBuffDc(1);
    _m2c_Sg_MainInit_Sg_SetDBuffDc(0);
    _m2c_Sg_MainInit_func_002F8660(0);
    _m2c_Sg_MainInit_func_002DB640(&D_005804F0, 0);
    _m2c_Sg_MainInit_Sg_DebugFill(-1);
    _m2c_Sg_MainInit_TkSg_IOPInit();
    _m2c_Sg_MainInit_func_002D63E0(0);
    _m2c_Sg_MainInit_func_00111758();
    _m2c_Sg_MainInit_func_002DDC78(0);
    _m2c_Sg_MainInit_func_001578B8();
    _m2c_Sg_MainInit_func_00125E40();
    _m2c_Sg_MainInit_Sg_InitAll();
    _m2c_Sg_MainInit_Ch_InitAll();
    _m2c_Sg_MainInit_func_00122B08();
    _m2c_Sg_MainInit_yiInit();
    _m2c_Sg_MainInit_func_001A56F8(0x200, 0x1A0);
    _m2c_Sg_MainInit_MsCameraInit();
    if (ffx_debugmode != 0) {
        _m2c_Sg_MainInit_func_2031620();
        _m2c_Sg_MainInit_func_202C7C8();
    }
    _m2c_Sg_MainInit_func_00122B00();
    _m2c_Sg_MainInit_Sg_PlayerInitAll();
    _m2c_Sg_MainInit_MsBattleInit();
    _m2c_Sg_MainInit_func_00293148();
    _m2c_Sg_MainInit_op_init_ffx();
    _m2c_Sg_MainInit_func_00293570();
    _m2c_Sg_MainInit_op_loop_ffx_after();
    _m2c_Sg_MainInit_func_001AD9C0();
    _m2c_Sg_MainInit_Ch_ChrMemHeapSet();
    _m2c_Sg_MainInit_func_00116010(6);
    _m2c_Sg_MainInit_func_0011FD00(1);
    _m2c_Sg_MainInit_func_0011A9E0(1);
    _m2c_Sg_MainInit_func_0011AA08(1);
    _m2c_Sg_MainInit_func_0011A968(1);
    _m2c_Sg_MainInit_func_0011A990(1);
    _m2c_Sg_MainInit_func_0011A9B8(1);
    _m2c_Sg_MainInit_Sg_EnableDrawGui(1);
    _m2c_Sg_MainInit_Sg_EnableDrawMenu(1);
    _m2c_Sg_MainInit_func_00119830(1);
    _m2c_Sg_MainInit_func_0011AB80(1);
    _m2c_Sg_MainInit_func_0011AB68(1);
    _m2c_Sg_MainInit_func_0011AA80(0);
    _m2c_Sg_MainInit_func_0011AAB8(1);
    _m2c_Sg_MainInit_func_0011AAD8(1);
    _m2c_Sg_MainInit_func_0010B9E8(1);
    _m2c_Sg_MainInit_func_0011ABA8(0);
    _m2c_Sg_MainInit_SaveDataIsScreenClosed(-1);
    _m2c_Sg_MainInit_func_002D3F30(1, &_m2c_Sg_MainInit_func_0011AD90);
    _m2c_Sg_MainInit_Sg_SetMovieGomiAvoid(0);
    D_005808B0 = D_00307F30;
    D_00307F2C = 0;
    _m2c_Sg_MainInit_func_00124E00((ffx_debugmode != 0) ? 0 : 0x17, D_00307F30, ffx_debugmode);
    _m2c_Sg_MainInit_func_001195E8(0x100, 0xD0);
    return _m2c_Sg_MainInit_Sg_CalcScreenMatrix();
}

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

s32 _m2c_func_0011B9D8_SgStrdupD(s32, s32) __asm__("SgStrdupD");
s32 _m2c_func_0011B9D8_Sg_MainInit() __asm__("Sg_MainInit");
s32 _m2c_func_0011B9D8_Sg_MainLoop() __asm__("Sg_MainLoop");
s32 _m2c_func_0011B9D8_func_0011BE48() __asm__("func_0011BE48");
s32 _m2c_func_0011B9D8_func_002E9C18() __asm__("func_002E9C18");
/* DEBT(GOTO) */
void func_0011B9D8(s32 arg0, s32 arg1) {
    _m2c_func_0011B9D8_func_002E9C18();
    _m2c_func_0011B9D8_func_0011BE48();
    _m2c_func_0011B9D8_SgStrdupD(arg0, arg1);
    _m2c_func_0011B9D8_Sg_MainInit();
loop_1:
    _m2c_func_0011B9D8_Sg_MainLoop();
    goto loop_1;
}
