/* tu_240 0x214650-0x216fa0: low; ~TOBtlInit (config/tu_map.tsv) */
#include "common.h"
#include "ffx/q5.h"
#include "ffx/w6.h"
#include "ffx/r4.h"
#include "ffx/s4.h"
#include "ffx/u3.h"
#include "ffx/t4.h"
#include "ffx/v4.h"

INCLUDE_ASM("build/ee_asm/game/menu/to/to_214650", func_00214650);

INCLUDE_ASM("build/ee_asm/game/menu/to/to_214650", func_00214790);

void TOControlBtlWindow(void)
{
    int i;
    R4Rec *r;

    TOSeqCtrl(2);
    func_0021D6C8();
    func_00216FD8(0);
    func_00216FD8(1);
    TOBtlCtrlStatusWin();
    TOBtlCtrlEnemyLimit();
    func_0021A128();
    TOBtlCtrlLimitTimer();
    TOBtlCtrlAuronLimitWindow();
    TOBtlCtrlTidusLimitWindow();
    TOBtlCtrlLuluLimitWindow();
    if (MsBattleGetStatus() == 1 && D_00692038 != 0) {
        func_0021FB00();
        graphicGetTime();
        for (i = 0; i < 8; i++) {
            switch (D_003249C0[i].state) {
            case 0:
                break;
            case 2:
                r = &D_003249C0[i];
                if (r->f84 != 0) {
                    r->f84(r);
                }
                r->state++;
                break;
            case 3:
                r = &D_003249C0[i];
                if (r->f88(r) == 1) {
                    r->state++;
                }
                break;
            case 4: {
                R4Rec *q = &D_003249C0[i];

                q->f8C(q);
                break;
            }
            case 1:
            case 5:
                D_003249C0[i].state++;
                break;
            case 6:
                r = &D_003249C0[i];
                if (r->f90(r) == 1) {
                    r->state = 0;
                }
                break;
            }
        }
        TOBtlCtrlHelpWin();
        TOBtlCtrlInfoWin();
        TOBtlCtrlInfoWinMes();
        TOControlMsSetMenuCommand();
    }
}

INCLUDE_ASM("build/ee_asm/game/menu/to/to_214650", TODrawBtlWindow);

void TOClearBtlWindow(void)
{
    TOBtlStopLimitTimer();
    TOInitPadData();
    TOSetExeMessageWindowArea(0);
    D_003249A0 = 0;
}

INCLUDE_ASM("build/ee_asm/game/menu/to/to_214650", TOSetBtlActiveChr);

INCLUDE_ASM("build/ee_asm/game/menu/to/to_214650", TOBtlSetNextAction);

INCLUDE_ASM("build/ee_asm/game/menu/to/to_214650", TOBtlSetPrevAction);

void func_00215360() /* DEBT(TYPE): old-style definition; TOBtlFinishCommand passes an argument */
{
    D_00692038 = 0;
    func_002EF0D0(D_00690678, 0, 0x20);
    D_00690698 = 0;
}

INCLUDE_ASM("build/ee_asm/game/menu/to/to_214650", TOControlMsSetMenuCommand);

void TOBtlFinishCommand(void)
{
    TOControlMsSetMenuCommand();
    MsSetBtlCommand(D_003252A8, D_00325670, 0);
    if (MsGetSaveConfigCursorSave() == 1 && D_003252A8[0] < 0x12) {
        func_0021ECC0();
    }
    func_002184B8();
    func_00215360(D_003252A4);
    func_0020DC78(2);
    D_003252A4 = 0xFF;
}

void func_002155F0(U3Rect *r, int x, int y, int w, int h)
{
    r->x1 = x + w;
    r->x0 = x;
    r->y0 = y;
    r->y1 = y + h;
    r->x0 = (r->x0 > 0x1FF) ? 0x1FF : (r->x0 >= 0) ? r->x0 : 0;
    r->y0 = (r->y0 > 0x19F) ? 0x19F : (r->y0 >= 0) ? r->y0 : 0;
    r->x1 = (r->x1 > 0x1FF) ? 0x1FF : (r->x1 >= 0) ? r->x1 : 0;
    r->y1 = (r->y1 > 0x19F) ? 0x19F : (r->y1 >= 0) ? r->y1 : 0;
}

void func_002156B0(s16 v)
{
    D_003249A8 = v;
}

void func_002156C0(s8 v)
{
    D_003249AA = v;
}

INCLUDE_ASM("build/ee_asm/game/menu/to/to_214650", TOCheckBtlCommandUse);

s32 TOCheckBtlCommandTarget(s32 a, s32 b) {
    s32 temp_3;

    __asm__ volatile("" : : : "memory");
    func_0021D7A0(a, b);
    func_0021D820();
    TOBtlMakeTargetGroupBit();
    TOBtlMakeTargetChrStatusBit();
    func_0021DBF0();
    TOBtlMakeTargetTargetBit();
    if (D_003249A4 == 0x100) {
        toTarget.h12E = 0;
        toTarget.h130 = 0;
        toTarget.h126 = 1;
        toTarget.w10 = 2;
        toTarget.p128 = &toTarget.wB0;
        temp_3 = toTarget.wC & toTarget.w84 & toTarget.w8C;
        toTarget.hAC = 1;
        toTarget.h12C = 0;
        toTarget.wB0 = temp_3;
        toTarget.wA8 = temp_3;
        toTarget.h124 = 0xFF;
    }
    return 1;
}

u16 *TOGetSaveWindow(int id, int mode, s32 *out)
{
    s32 n = 0;
    u16 *buf = MsGetSaveWindow(id, mode, &n);

    switch (mode) {
    case 6:
    case 17:
    case 20:
        *out = n;
        break;
    case 7:
    case 15:
        for (; n > 0 && buf[n - 1] == 0xFF; n--) {
        }
        *out = n;
        if (*out <= 0) {
            *out = 1;
        }
        break;
    default:
        for (; n > 0 && buf[n - 1] == 0xFF; n--) {
        }
        *out = n;
        break;
    }
    return buf;
}

INCLUDE_ASM("build/ee_asm/game/menu/to/to_214650", func_002159A8);

void TOBtlSetTarget(int i, int a, int b)
{
    R4Rec *r = &D_003249C0[i];

    r->b2 = 1;
    TOCheckBtlCommandTarget(a, b);
    r->h42 = toTarget.h12C;
    r->wC8 = toTarget.wA8;
    r->h96++;
    func_00210358((R4Task *)r); /* DEBT(CAST): R4Rec and R4Task are views of one record */
}

void func_00215B78(R4Wk *o, int b)
{
    o->list = TOGetSaveWindow(o->h8, b, &o->w24);
    o->f78 = func_0021BDC0;
}

INCLUDE_ASM("build/ee_asm/game/menu/to/to_214650", TOBtlScanCommandWH);
INCLUDE_RODATA("build/ee_asm/game/menu/to/to_214650/rodata", jtbl_00570D90);

INCLUDE_ASM("build/ee_asm/game/menu/to/to_214650", _TOBtlGetMainPad);

INCLUDE_ASM("build/ee_asm/game/menu/to/to_214650", _TOBtlGetStdPad);

INCLUDE_ASM("build/ee_asm/game/menu/to/to_214650", _TOGetPadStatusPrepare);

void func_00216EE8(void) {
}

void func_00216EF0(void) {
}

void _TOBtlDrawTargetCursor(void)
{
    s32 x;
    s32 y;
    int i;

    for (i = 0; i < 28; i++) {
        if ((toTarget.wA8 >> i) & 1) {
            MsGetChrTargetPos(i, &x, &y);
            func_001F23E8();
            if (i < 20) {
                func_001FE7F8(4, x, y);
            } else {
                func_001FE7F8(5, x, y);
            }
        }
    }
}
