/* tu_242 0x2180a0-0x218a78: low; ~TOBtlCtrlHelpWin (config/tu_map.tsv) */
#define func_00218330 _hdr_func_00218330
#define MsMenuCheckChrLive _hdr_MsMenuCheckChrLive
#include "common.h"
#include "ffx/q5.h"
#include "ffx/w6.h"
#include "ffx/r4.h"
#include "ffx/u3.h"
#include "ffx/g3.h"
#include "ffx/v4.h"
#undef func_00218330
#undef MsMenuCheckChrLive

int MsMenuCheckLook(void);
int MsMenuCheckChrLive(int id);
void TOBtlSetInfoWinParam(u16 id);

void func_002180A0(void)
{
    D_003249AB = 0;
    func_002EF0D0(D_00692480, 0, 0x80);
}

INCLUDE_ASM("build/ee_asm/game/menu/to/to_2180A0", TOBtlCtrlHelpWin);

s32 *_m2c_func_00218330_MsGetSaveMenu() __asm__("MsGetSaveMenu");
s32 _m2c_func_00218330_TODrawMenuPlateXYWC2_Rfix(s32, s32, s16, s16, s16, s32, s32) __asm__("TODrawMenuPlateXYWC2_Rfix");
s32 _m2c_func_00218330_TODrawScissorXYWH(s32, s32, s32, s32) __asm__("TODrawScissorXYWH");
s32 _m2c_func_00218330_TOMkpShapeXY(s32, s32, s16) __asm__("TOMkpShapeXY");
s32 _m2c_func_00218330_TOSeqStartSceneNoErase(s32, s8 *) __asm__("TOSeqStartSceneNoErase");
s32 _m2c_func_00218330_TOSeqStopScene(s32, s8 *) __asm__("TOSeqStopScene");
s32 _m2c_func_00218330_func_001F3958(s32, u8 *, s32, s32, s32) __asm__("func_001F3958");
void func_00218330(void) {
    if (((s32) *_m2c_func_00218330_MsGetSaveMenu() >> 0xA) & 1) {
        _m2c_func_00218330_TOSeqStartSceneNoErase(2, D_00570E28);
    } else {
        _m2c_func_00218330_TOSeqStopScene(2, D_00570E28);
    }
    if (((s32) *_m2c_func_00218330_MsGetSaveMenu() >> 0xA) & 1) {
        if (D_003249AB == 1) {
            _m2c_func_00218330_TODrawScissorXYWH(0, 0, 0x1FF, 0x19F);
            _m2c_func_00218330_TODrawMenuPlateXYWC2_Rfix(0x45, 0x46, D_00324248, D_0032424A, D_0032424C, D_00324250, D_00324254);
            _m2c_func_00218330_TODrawMenuPlateXYWC2_Rfix(6, 7, D_0032425C, D_0032425E, D_00324260, 0x40000000, 0x40000000);
            _m2c_func_00218330_TOMkpShapeXY(0x3E, D_00324248 + 0x50, D_0032424A);
            _m2c_func_00218330_func_001F3958(0, D_00692480, 0x28, 0xC, 0);
        }
    }
}

/* DEBT(CAST): the flag word behind MsGetSaveMenu() is untyped */
void func_00218470(void)
{
    D_003249AB = 1;
    if ((*(s32 *)MsGetSaveMenu() >> 10) & 1) {
        TOSeqStartSceneNoErase(2, D_00570E28);
    }
}

/* DEBT(CAST): the flag word behind MsGetSaveMenu() is untyped */
void func_002184B8(void)
{
    D_003249AB = 0;
    if ((*(s32 *)MsGetSaveMenu() >> 10) & 1) {
        TOSeqStopScene(2, D_00570E28);
    }
}

void func_00218500(u16 id)
{
    int base;
    char *s;

    s = (char *)(base + MsGetComData(id, &base)->a[2].x);
    _TOGetMessageWH(0, (u8 *)s, D_00692478, &D_0069247A, 0, 0);
    func_002EF0D0(D_00692480, 0, 0x80);
    func_002F072C(D_00692480, s);
    _TOGetMessageWH(0, (u8 *)D_00692480, D_00692478, &D_0069247A, 0, 0);
}

INCLUDE_ASM("build/ee_asm/game/menu/to/to_2180A0", TOBtlSetTargetHelpMes);

void TOBtlSetChangeHelpMes(unsigned int id)
{
    int base;
    char *text;

    if (id < 18 || id == 0x30FF) {
        func_002EF0D0(D_00692480, 0, 0x80);
        if (id < 8) {
            text = (char *)MsGetMenuChrInfo(id, 0);
        }
        if (id - 8 < 10) {
            text = (char *)MsGetMenuChrInfo(id, 0);
        }
        if (id == 0x30FF) {
            OfsTbl *command = MsGetComData(0x30FF, &base);

            text = (char *)base + command->b[0].x;
        }
        func_002F072C((char *)D_00692480, text);
        _TOGetMessageWH(0, D_00692480, &D_00692478[0], &D_0069247A, 0, 0);
    }
}

void func_002188A0(char *s)
{
    if (s != 0) {
        func_002EF0D0(D_00692480, 0, 0x80);
        func_002F072C(D_00692480, s);
        _TOGetMessageWH(0, (u8 *)D_00692480, D_00692478, &D_0069247A, 0, 0);
    }
}

void func_00218928(void)
{
    D_003249AC = 0;
    D_00692500 = 0xFF;
}

void TOBtlCtrlInfoWin(void)
{
    if (D_003249C0[D_00325020].b2 != 1) {
        D_003249AC = 0;
        return;
    }
    if (MsMenuCheckLook() == -1) {
        if ((u16)toTarget.h124 >= 0x14 && (u16)toTarget.h124 < 0x1C && MsMenuCheckChrLook((u16)toTarget.h124) == 1) {
            if ((u16)D_00692500 != (u16)toTarget.h124) {
                TOBtlSetInfoWinParam((u16)toTarget.h124);
                D_00692500 = toTarget.h124;
            }
            D_003249AC = 1;
            goto check_live; /* DEBT(GOTO): matches single D_003249AC = 0 fallthrough */
        }
    }
    D_003249AC = 0;
check_live:
    if (MsMenuCheckChrLive((u16)toTarget.h124) == 1) {
        if ((u16)toTarget.h124 >= 0x14 && (u16)toTarget.h124 < 0x1C) {
            if ((u16)D_00692500 != (u16)toTarget.h124) {
                TOBtlSetInfoWinParam((u16)toTarget.h124);
                D_00692500 = toTarget.h124;
            }
            D_003249AC = 1;
        }
    }
}
