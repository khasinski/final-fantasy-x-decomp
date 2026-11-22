/* tu_240 0x214650-0x216fa0: low; ~TOBtlInit (config/tu_map.tsv) */
#include "common.h"
#include "ffx/q5.h"
#include "ffx/w6.h"
#include "ffx/r4.h"
#include "ffx/s4.h"
#include "ffx/u3.h"
#include "ffx/t4.h"
#include "ffx/v4.h"

typedef struct {
    u8 pad00[0xC];
    s16 hC[4];
    s16 h14;
    u8 pad16[6];
    s32 w1C;
    u8 pad20[4];
} BtlHistEnt;

extern u8 D_006906A0[18];
extern BtlHistEnt D_006906B8[18][10];
extern char D_00570D20[];
extern R4Init D_00325170;

void TOBtlInitChrNum(void);
void TOBtlInitStatusWin(void);
void TOBtlInitEnemyLimit(void);
void func_00218928(void);
void TOBtlInitInfoWinMes(void);
void func_002180A0(void);
void func_00216FA0(int a);
void TOBtlInitLimitTimer(void);

void func_00214650(void)
{
    int i;
    int j;
    int k;

    for (i = 0; i < 18; i++) {
        D_006906A0[i] = 0;
    }
    for (i = 0; i < 18; i++) {
        for (j = 0; j < 10; j++) {
            /* DEBT(CAST): explicit offset order matches (j*0x24 + i*0x168) + base */
            func_002EF0D0((u8 *)D_006906B8 + (j * sizeof(BtlHistEnt) + i * sizeof(BtlHistEnt) * 10), 0, sizeof(BtlHistEnt));
            for (k = 0; k < 4; k++) {
                D_006906B8[i][j].hC[k] = 0xFF;
            }
            D_006906B8[i][j].h14 = 0xFF;
        }
    }
}

void func_00214790(void)
{
    int i;
    int j;

    TOInitPadData();
    D_003249A0 = 1;
    D_003249A4 = 0;
    TOBtlInitActiveChrCursor();
    TOSeqGetNum(2, D_00570D20, &D_00325022);
    TOSetExeMessageWindowArea(1);
    func_002EF0D0(D_003249C0, 0, 0x660);
    func_002EF0D0(&toTarget, 0, sizeof(R4Init));
    for (i = 0; i < 18; i++) {
        for (j = 0; j < 10; j++) {
            D_006906B8[i][j].w1C = 0;
        }
    }
    D_003252A4 = 0xFF;
    D_003249AA = 1;
    D_00692038 = 0;
    D_00692450 = 0;
    TOBtlInitChrNum();
    TOBtlInitStatusWin();
    TOBtlInitEnemyLimit();
    func_00218928();
    TOBtlInitInfoWinMes();
    func_002180A0();
    func_00216FA0(0);
    func_00216FA0(1);
    TOBtlInitLimitTimer();
    graphicGetTime();
    func_0020DC78(2);
}

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

extern s8 D_003249AA;
extern s16 D_003252A4;
extern s16 D_0032436E;
extern s16 D_00324370;

extern void _void_func_0021A8F0(void) __asm__("func_0021A8F0"); /* DEBT(TYPE): funcs.h declares as int */
extern void _void_TOBtlDrawActiveChrCursor(int) __asm__("TOBtlDrawActiveChrCursor"); /* DEBT(TYPE): funcs.h declares as int */
extern void _void_TOBtlDrawCtbWindow(int, int) __asm__("TOBtlDrawCtbWindow"); /* DEBT(TYPE): funcs.h declares as int */
extern void _void_QuickConfigMenuDraw(void) __asm__("QuickConfigMenuDraw"); /* DEBT(TYPE): funcs.h declares as int */

void TODrawBtlWindow(void)
{
    int i;

    if (D_003249A0 == 0) {
        return;
    }
    MsBattleCursorCalc();
    func_001FAB08();
    TOMakePktScissor(0, 0, 0x1FF, 0x19F);
    TOSeqDraw(2, 0);
    TOBtlDrawDamageValue2();
    func_00216FE0(0);
    func_00216FE0(1);
    if (MsBattleGetStatus() != 2 && MsBattleGetStatus() != 1) {
        return;
    }
    if (D_003249AA == 1) {
        TOBtlDrawStatusWin();
    }
    TOBtlDrawEnemyLimit();
    func_0021A200();
    func_0021AD80();
    func_0021B358();
    func_0021B9C8();
    _void_func_0021A8F0();
    if (D_00692038 != 0) {
        _void_TOBtlDrawActiveChrCursor(D_003252A4);
        _void_TOBtlDrawCtbWindow(D_0032436E, D_00324370);
        for (i = 0; i < 8; i++) {
            if (D_003249C0[i].state >= 3) {
                void (*fn)(R4Rec *) = *(void (**)(R4Rec *))((u8 *)&D_003249C0[i] + 0x80); /* DEBT(CAST): draw cb at R4Rec+0x80 */
                if (fn != 0) {
                    fn(&D_003249C0[i]);
                }
            }
        }
        func_00218330();
        {
            u8 *t = (u8 *)&toTarget; /* DEBT(CAST): toTarget+0x124 */
            func_00218A78(*(u16 *)(t + 0x124), 0x14, 0x46);
            TOBtlDrawInfoWinMes(*(u16 *)(t + 0x124));
        }
    }
    TODrawScissorXYWH(0, 0, 0x1FF, 0x19F);
    TOSeqDraw(2, 1);
    _void_QuickConfigMenuDraw();
}

void TOClearBtlWindow(void)
{
    TOBtlStopLimitTimer();
    TOInitPadData();
    TOSetExeMessageWindowArea(0);
    D_003249A0 = 0;
}

extern s16 D_00692040[];
void TOBtlInitAnm(void);
void TOBtlInitCtbWindow(void);
void TOBtlInitChrNum(void);
void TOBtlInitStatusWin(void);
void func_002180A0(void);
void func_00218928(void);
void TOBtlInitLimitTimer(void);
void TOBtlSetNextAction(int,int);

void TOSetBtlActiveChr(int id)
{
    if (MsBattleGetStatus() == 1 && D_00692038 == 0) {
        func_002EF0D0(D_00690678,0,0x20);
        D_00690698=0;
        D_003249A4=0;
        D_00325670=0;
        func_002EF0D0(D_003249C0,0,0x660);
        D_00325020=-1;
        func_002EF0D0(D_00692040,0,8);
        func_002EF0D0(D_003252A8,0,0x48);
        TOBtlInitAnm();
        TOBtlInitCtbWindow();
        TOBtlInitChrNum();
        TOBtlInitStatusWin();
        func_002180A0();
        func_00216FA0(0);
        func_00216FA0(1);
        func_00218928();
        TOBtlInitInfoWinMes();
        TOBtlInitLimitTimer();
        D_00692038 |= 1 << id;
        D_003252A4 = id;
        TOBtlSetNextAction(id,0xFE);
    }
}

INCLUDE_ASM("build/ee_asm/game/menu/to/to_214650", TOBtlSetNextAction);

extern R4Init D_00325170;
extern s16 D_00692040[];

typedef struct {
    u8 b0;
    s8 state;
    s8 b2;
    u8 pad3[5];
    u16 h8;
    s8 bA;
    s8 bB;
    u16 hC;
    u8 padE[8];
    u16 h16;
    u8 pad18[0x96 - 0x18];
    u16 h96;
    u8 pad98[0xCC - 0x98];
} R4RecPrev;

int TOBtlSetPrevAction(void)
{
    R4RecPrev *rec;
    R4RecPrev *prev;

    if (D_00325020 <= 0) {
        return 0;
    }
    rec = (R4RecPrev *)&D_003249C0[D_00325020];
    rec->state = 5;
    rec->h8 = D_003252A4;
    rec->h16 = 0xFF;
    if (rec->hC == 0x311E) {
        D_003249A4 = 0;
    }
    if (rec->hC == 0x3029) {
        D_003249A4 = 0;
    }
    if (rec->b2 == 1) {
        int idx = D_00325020 - 1;
        __asm__ volatile("" : "+r"(idx)); /* DEBT(ORDER): prevent GCC from folding (D_00325020 - 1) * 0xCC into rec - 0xCC */
        rec->h96 = D_003249C0[idx].h96;
    }
    D_00325020--;
    prev = (R4RecPrev *)&D_003249C0[D_00325020];
    prev->state = 2;
    if (prev->bB >= prev->bA && prev->bB > 0) {
        prev->bB--;
    }
    if (D_003249C0[D_00325020].b2 == 1) {
        extern u64 _a_toTarget[] __asm__("toTarget"); /* DEBT(CAST): 8-byte aligned view for __builtin_memcpy 0x134 bytes */
        extern u64 _a_D_00325170[] __asm__("D_00325170");
        __builtin_memcpy(_a_toTarget, _a_D_00325170, 0x134);
        D_00692040[3] = 0;
    }
    return 1;
}

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

extern u16 D_00692046;
int MsGetCommandUse(int, int);
int MsCheckUseCommand(int, OfsTbl *, int);
int TOCheckBtlCommandUse(int owner, int item)
{
    int output[2];
    OfsTbl *cmd;
    int kind;
    if (item == 0xFE) {
        return 0;
    }
    if (item == 0xFF) {
        return -2;
    }
    cmd = MsGetComData(item, &output[0]);
    if (MsGetCommandUse(owner, item) == 1) {
        return -1;
    }
    if (MsCheckUseCommand(owner, cmd, D_00692046) == -1) {
        return -2;
    }
    kind = cmd->b16 & 0xF8;
    if (kind == 8 || kind == 16) {
        TOGetSaveWindow(owner, cmd->b17, &output[1]);
        if (output[1] == 0) {
            return kind != 8 ? -3 : -4;
        }
        return cmd->b17;
    }
    if (cmd->h1A & 1) {
        return 0xFE;
    }
    return D_003249A4 == 0x100 ? 0xFE : 0xFF;
}

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

extern s8 D_00325020;
extern s32 D_003249A4;

void func_002159A8(int idx, int a1, int cmd)
{
    R4Rec *r = &D_003249C0[idx];

    r->b2 = 0;
    switch (cmd) {
    case 0xFE:
        ((u8 *)r)[0xB] = 0; /* DEBT(CAST): R4Rec fields at +6, +A, +B, +C, +94 */
        ((u8 *)r)[0xA] = 1;
        __asm__ volatile("" ::: "memory"); /* DEBT(ORDER): keep sb +0xB before sh +0x6 */
        *(s16 *)((u8 *)r + 6) = 0;
        break;
    case 0xFFFE:
        *(s16 *)((u8 *)r + 6) = 0xD;
        ((u8 *)r)[0xA] = 1;
        ((u8 *)r)[0xB] = 0;
        break;
    case 0xFFFF:
        *(s16 *)((u8 *)r + 6) = 0xC;
        ((u8 *)r)[0xA] = 1;
        ((u8 *)r)[0xB] = 0;
        break;
    default:
        {
            int buf;
            u8 *com = (u8 *)MsGetComData(cmd, &buf);
            R4Rec *r2 = &D_003249C0[idx];
            R4Rec *cur = &D_003249C0[D_00325020];

            *(s16 *)((u8 *)r2 + 6) = com[0x17];
            ((u8 *)r2)[0xB] = 0;
            ((u8 *)r2)[0xA] = 1;
            if (*(volatile u16 *)((u8 *)cur + 0xC) == 0x311E) { /* DEBT(ORDER): reload +0xC after +0xA store */
                D_003249A4 = 0x100;
                ((u8 *)cur)[0xA] = 2;
            }
            if (*(u16 *)((u8 *)cur + 0xC) == 0x3029) {
                D_003249A4 = 0x10000;
                *(s16 *)((u8 *)cur + 0x94) = 2;
            }
        }
        break;
    }
    {
        R4Rec *r3 = &D_003249C0[idx];
        func_00215B78((R4Wk *)r3, *(s16 *)((u8 *)r3 + 6));
        func_002105D0((R4Task *)r3);
        TOBtlSetCallback((R4Task *)r3);
    }
}

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
