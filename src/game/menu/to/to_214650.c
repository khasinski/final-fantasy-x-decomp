/* tu_240 0x214650-0x216fa0: low; ~TOBtlInit (config/tu_map.tsv) */
#define _TOBtlGetStdPad _hdr_TOBtlGetStdPad
#define _TOGetPadStatusPrepare _hdr_TOGetPadStatusPrepare
#include "common.h"
#include "ffx/q5.h"
#include "ffx/w6.h"
#include "ffx/r4.h"
#include "ffx/s4.h"
#include "ffx/u3.h"
#include "ffx/t4.h"
#include "ffx/v4.h"
#undef _TOBtlGetStdPad
#undef _TOGetPadStatusPrepare

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
int TOBtlSetNextAction(int, int);

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

typedef struct {
    u8 b0;
    s8 state;
    s8 b2;
    u8 pad3[5];
    s16 h8;
    s8 bA;
    s8 bB;
    u16 hC;
    u16 hE[4];
    u16 h16[4];
    u16 h1E;
    s16 *list;
    u8 pad24[0x14];
    s16 h38;
    s16 h3A;
    u8 pad3C[4];
    s16 h40;
    s16 h42;
    s16 h44;
    u8 pad46[0x32];
    void (*f78)(void);
    u8 pad7C[0x18];
    s16 h94;
    s16 h96;
    u8 pad98[0x34];
} R4RecFull;

extern u16 D_00692046;
void func_002159A8(int idx, int a1, int cmd);
void TOBtlSetTarget(int i, int a, int b);
void TOBtlSetDefaultCursorPos(void);
void TOBtlFinishCommand(void);
int TOCheckBtlCommandUse(int owner, int item);
extern void _int_func_001BFEA8(int) __asm__("func_001BFEA8");

extern R4RecFull _r4_D_003249C0[] __asm__("D_003249C0");
#define R4REC(i) (_r4_D_003249C0[i])

int TOBtlSetNextAction(int id, int cmd_arg)
{
    int i;
    register int cmd __asm__("$18") = cmd_arg;

    if (R4REC(D_00325020).b2 == 1) {
        if (R4REC(D_00325020).h96 >= R4REC(D_00325020).h94) {
            TOBtlFinishCommand();
            return 1;
        }
        {
            extern u64 _a_toTarget[] __asm__("toTarget");
            extern u64 _a_D_00325170[] __asm__("D_00325170");
            cmd = 0x3115;
            __builtin_memcpy(_a_D_00325170, _a_toTarget, 0x134);
        }
        if (D_003249A4 == 0x10000) {
            int buf;
            OfsTbl *com = MsGetComData(R4REC(D_00325020).hC, &buf);
            D_00692040[3] = MsGetCommandMP(R4REC(D_00325020).h8, com);
        }
    }

    {
        register int res __asm__("$19");
        switch (cmd) {
        case 0xFFFE:
            res = 0xD;
            break;
        case 0xFFFF:
            res = 0xC;
            break;
        default:
            res = TOCheckBtlCommandUse(id, cmd);
            if (res < 0) {
                return 0;
            }
            break;
        }

        if (res == 0xFF) {
            TOBtlFinishCommand();
            return 1;
        }

        if (D_00325020 >= 0) {
            R4REC(D_00325020).state = 6;
            R4REC(D_00325020).h16[R4REC(D_00325020).bB] = cmd;
        }
        D_00325020++;
        func_002EF0D0(&R4REC(D_00325020), 0, sizeof(R4RecFull));
        R4REC(D_00325020).h16[0] = 0xFF;
        R4REC(D_00325020).h8 = id;
        R4REC(D_00325020).hC = cmd;
        if (D_00325020 == 0) {
            R4REC(D_00325020).h96 = 0;
            R4REC(D_00325020).h94 = 1;
        } else {
            int prev = D_00325020 - 1;
            __asm__ volatile("" : "+r"(prev));
            R4REC(D_00325020).h94 = R4REC(prev).h94;
            R4REC(D_00325020).h96 = R4REC(prev).h96;
        }
        R4REC(D_00325020).state = 1;
        if (res < 0x81) {
            func_002159A8(D_00325020, id, cmd);
        }
        if (res == 0xFE) {
            TOBtlSetTarget(D_00325020, id, cmd);
        }
    }
    if (MsGetSaveConfigCursorSave() == 1
        && ((s8 *)D_006906A0)[D_003252A4] == 1
        && (u16)(R4REC(1).hC + 2) >= 2) {
        register int idx __asm__("$3") = D_00325020;
        __asm__ volatile("" : "+r"(idx));
        {
            register R4RecFull *r __asm__("$4") = &R4REC(idx);
            __asm__ volatile("" : "+r"(r));
            if (r->h8 < 0x12) {
                TOBtlSetDefaultCursorPos();
            }
        }
    }
    if (R4REC(D_00325020).b2 == 1) {
        typedef struct {
            u8 pad00[0x10];
            s32 w10;
            u8 pad14[0x84];
            u32 w98;
            u8 pad9C[0xC];
            s32 wA8;
            s16 hAC;
            u8 padAE[2];
            s32 wB0[1];
        } ToTarget98;
        ToTarget98 *tt = (ToTarget98 *)&toTarget;
        if (tt->w98 == 0xFFFFFFFFU && tt->w10 == 0) {
            for (i = 0; i < D_00692008; i++) {
                if (MsGetChrStatDeath(D_00692010[i]) == 1) {
                    toTarget.h126 = toTarget.hAC;
                    toTarget.wA8 = (&toTarget.wB0)[i];
                    toTarget.h124 = D_00692010[i];
                    toTarget.p128 = &toTarget.wB0;
                    toTarget.h130 = 0;
                    __asm__ volatile("" : "+r"(i) : : "memory");
                    toTarget.h12C = i;
                    break;
                }
            }
        }
    }
    return 1;
}

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

typedef struct {
    u8 b0;
    u8 pad1[2];
    u8 b3;
    u8 pad4[4];
    struct {
        u16 h0[2];
        u16 pad4[2];
        u32 w8;
        u32 padC;
    } item[3];
} ToBtlCmdBuf;

typedef struct {
    u8 pad0[2];
    s8 b2;
    u8 pad3[5];
    s16 h8;
    u8 padA[0xC];
    u16 h16;
    u16 h18;
    u8 pad1A[0xAE];
    u32 wC8;
} R4RecCmd;

extern u32 D_003250D8;

void TOControlMsSetMenuCommand(void)
{
    int i;
    int cnt;
    int sub;
    u32 mask;

    for (i = 0; i < 3; i++) {
        ((ToBtlCmdBuf *)D_003252A8)->item[i].h0[0] = 0xFF;
        ((ToBtlCmdBuf *)D_003252A8)->item[i].h0[1] = 0xFF;
        ((ToBtlCmdBuf *)D_003252A8)->item[i].w8 = 0;
    }
    cnt = 0;
    sub = 0;
    for (i = 0; i <= D_00325020; i++) {
        int h = ((R4RecCmd *)D_003249C0)[i].h16;
        if ((u16)h == 0xFFFF) {
            continue;
        }
        if ((u16)h == 0xFFFE) {
            continue;
        }
        if (((R4RecCmd *)D_003249C0)[i].b2 == 0) {
            if (sub >= 2) {
                ((ToBtlCmdBuf *)D_003252A8)->item[cnt].h0[0] = ((ToBtlCmdBuf *)D_003252A8)->item[cnt].h0[1];
                sub--;
            }
            ((ToBtlCmdBuf *)D_003252A8)->item[cnt].h0[sub] = h;
            sub++;
        } else {
            ((ToBtlCmdBuf *)D_003252A8)->item[cnt].w8 = ((R4RecCmd *)D_003249C0)[i].wC8;
            cnt++;
            sub = 0;
        }
    }
    if (D_003249A4 == 0x100) {
        R4RecCmd *rec = (R4RecCmd *)D_003249C0;
        ((ToBtlCmdBuf *)D_003252A8)->item[0].h0[0] = 0x311E;
        ((ToBtlCmdBuf *)D_003252A8)->item[0].h0[1] = rec[2].h16;
        ((ToBtlCmdBuf *)D_003252A8)->item[1].h0[0] = rec[2].h18;
        cnt = 2;
    }
    if (cnt == 0) {
        cnt = 1;
    }
    ((ToBtlCmdBuf *)D_003252A8)->b0 = (u8)((R4RecCmd *)D_003249C0)[0].h8;
    ((ToBtlCmdBuf *)D_003252A8)->b3 = (u8)cnt;
    func_001C94C0(D_003252A8);
    if (((R4RecCmd *)D_003249C0)[D_00325020].b2 == 0) {
        mask = 1 << ((R4RecCmd *)D_003249C0)[D_00325020].h8;
    } else {
        mask = D_003250D8;
    }
    if (((ToBtlCmdBuf *)D_003252A8)->item[0].h0[1] == 0xFF) {
        TOBtlCtrlCtbWindow((s16)((ToBtlCmdBuf *)D_003252A8)->item[0].h0[0], mask);
    } else {
        TOBtlCtrlCtbWindow((s16)((ToBtlCmdBuf *)D_003252A8)->item[0].h0[1], mask);
    }
}

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

typedef struct {
    u8 pad00[0x8];
    s16 h8;
    u8 pad0A[0x16];
    s16 *list;
    s32 w24;
    s16 h28;
    u8 pad2A[2];
    u16 h2C[0x1B];
    s16 h62;
    s16 h64;
    s16 h66;
    u8 pad68[0x38];
    s32 wA0;
    u8 *pA4[1];
} ScanCmdWk;

void TOBtlScanCommandWH(MenuList *arg)
{
    ScanCmdWk *o = (ScanCmdWk *)arg;
    s16 w0;
    s16 h0;
    s16 w1;
    s16 h1;
    u8 *strBase;
    s32 cnt;
    register int maxW __asm__("$21") = 0;
    register int i __asm__("$20");

    for (i = 0; i < o->w24; i++) {
        s16 cmd = o->list[i];
        OfsTbl *com;

        if (cmd == 0xFF) {
            continue;
        }
        com = MsGetComData(cmd, (int *)&strBase);
        if ((com->b16 & 0xF8) == 8) {
            TOGetSaveWindow(o->h8, com->b17, &cnt);
            if (cnt == 0) {
                continue;
            }
        }
        _TOGetMessageWH(-1, strBase + *(u16 *)com, &w0, &h0, 0, 0);
        if (maxW < w0) {
            maxW = w0;
        }
    }
    w0 = maxW;
    i = 0;
    if (o->h28 > 0) {
        register int cond __asm__("$2");
        do {
            u16 entry = o->h2C[i];
            int param = entry & 0xFF;

            switch (entry >> 8) {
            case 3:
                w0 += 12;
                break;
            case 2:
            case 4: {
                int t = (u16)w0 + param * 12;
                __asm__("" : "+r"(t));
                w0 = t + 5;
                break;
            }
            case 1:
            case 7:
                w0 += 20;
                break;
            case 17: {
                u16 x;
                u16 t;
                register int lim __asm__("$2");
                i = 0;
                if (o->wA0 > 0) {
                    do {
                        _TOGetMessageWH(-1, o->pA4[i], &w1, &h1, 0, 0);
                        t = w1;
                    } while (++i < (lim = o->wA0));
                } else {
                    t = w1;
                }
                x = w0;
                w0 = x + t;
                break;
            }
            case 5:
            case 6:
            case 18:
                w0 += param * 12;
                break;
            }
            i++;
            cond = i < o->h28;
        } while (cond);
    }
    {
        register int finalW __asm__("$3") = w0;
        register int h64v __asm__("$2");
        __asm__ volatile("" : "+r"(finalW));
        h64v = 18;
        o->h66 = maxW;
        o->h64 = h64v;
        __asm__ volatile("" : "+r"(finalW) : "r"(h64v));
        o->h62 = finalW;
    }
}

void func_0021BE28(void);
void func_0021BDC8(void);

void _TOBtlGetMainPad(void *o)
{
    R4RecFull *wk = (R4RecFull *)o;
    s32 winCnt;
    s16 oldCur;

    if (D_00692038 == 0) {
        return;
    }
    if (wk->f78 != func_0021BDC0) {
        return;
    }

    if (D_003238D0.h14 & 0x10) {
        int skip = MsMenuGetChrSkipCommand(wk->h8);
        if (skip != 0) {
            ((ToBtlCmdBuf *)D_003252A8)->b0 = wk->h8;
            ((ToBtlCmdBuf *)D_003252A8)->b3 = 1;
            ((ToBtlCmdBuf *)D_003252A8)->item[0].h0[0] = skip;
            ((ToBtlCmdBuf *)D_003252A8)->item[0].h0[1] = 0xFF;
            D_003250D8 = 1 << wk->h8;
            ((ToBtlCmdBuf *)D_003252A8)->item[0].w8 = 1 << wk->h8;
            MsSetBtlCommand(D_003252A8, 0, 0);
            func_00215360(D_003252A4);
            func_002184B8();
            func_0020DC78(2);
            D_003252A4 = 0xFF;
            func_002D70D8(1);
            return;
        }
        func_002D70D8(3);
    }

    if (D_003238D0.h14 & 4) {
        if (MsGetSaveChrSummon(wk->h8) != 0) {
            func_002D70D8(3);
            return;
        }
        if (TOBtlSetNextAction(wk->h8, 0x3002) == 1) {
            func_002D70D8(1);
            return;
        }
        func_002D70D8(3);
        return;
    }

    if (D_003238D0.h14 & 0x8000) {
        if (MsCheckLeftWindow(wk->h8) > 0) {
            TOBtlSetNextAction(wk->h8, 0xFFFF);
            func_002D70D8(1);
            return;
        }
    }

    if (D_003238D0.h14 & 0x2000) {
        TOGetSaveWindow(wk->h8, 0xD, &winCnt);
        if (winCnt == 0) {
            func_002D70D8(3);
            return;
        }
        TOBtlSetNextAction(wk->h8, 0xFFFE);
        func_002D70D8(1);
        return;
    }

    oldCur = wk->h42;
    if (D_003238D0.h16 & 0x1000) {
        wk->h42 -= wk->h38;
    }
    if (D_003238D0.h16 & 0x4000) {
        wk->h42 += wk->h38;
    }
    if (wk->h42 < 0) {
        wk->h42 += wk->h38;
    }
    if (wk->h42 >= wk->h44) {
        if (wk->h42 / wk->h38 > (wk->h44 - 1) / wk->h38) {
            wk->h42 -= wk->h38;
        } else {
            wk->h42 = wk->h44 - 1;
        }
    }

    wk->h16[wk->bB] = wk->list[wk->h42];
    wk->hE[wk->bB] = wk->h42;

    if (D_003238D0.h14 & 0x40) {
        if (wk->bB > 0) {
            wk->h16[wk->bB] = 0xFF;
            wk->hE[wk->bB] = 0xFF;
            wk->bB--;
            wk->h42 = wk->hE[wk->bB];
            wk->h1E = wk->h16[wk->bB];
            func_001BFEA8(0);
            func_002D70D8(4);
            return;
        }
        if (D_00325020 > 0) {
            TOBtlSetPrevAction();
            wk->state++;
            func_002D70D8(4);
            return;
        }
        return;
    }

    if (D_003238D0.h14 & 0x20) {
        if (TOCheckBtlCommandUse(wk->h8, wk->h16[wk->bB]) < 0) {
            func_002D70D8(3);
            return;
        }
        wk->h16[wk->bB] = wk->list[wk->h42];
        wk->hE[wk->bB] = wk->h42;
        wk->bB++;
        if (wk->bB < wk->bA) {
            _int_func_001BFEA8(wk->h16[0]);
            func_002D70D8(1);
            return;
        }
        if (TOBtlSetNextAction(wk->h8, wk->list[wk->h42]) == 1) {
            func_002D70D8(1);
            return;
        }
        func_002D70D8(3);
        return;
    }

    if (wk->h42 < wk->h40) {
        wk->h40 -= wk->h38;
        wk->f78 = func_0021BE28;
    }
    if (wk->h42 >= wk->h40 + wk->h3A * wk->h38) {
        wk->h40 += wk->h38;
        wk->f78 = func_0021BDC8;
    }
    if (wk->h3A * wk->h38 < wk->h44) {
        winCnt = ((wk->h44 + wk->h38 - 1) / wk->h38 - wk->h3A) * wk->h38;
        wk->h40 = (wk->h40 > winCnt) ? winCnt : (wk->h40 < 0 ? 0 : wk->h40);
    } else {
        wk->h40 = 0;
    }

    if (wk->h42 != oldCur) {
        wk->h1E = wk->list[wk->h42];
        wk->hE[wk->bB] = wk->h42;
        wk->h16[wk->bB] = wk->list[wk->h42];
        func_002D70D8(1);
    }
}

void _TOBtlGetStdPad(R4RecFull *wk)
{
    s32 winCnt;
    s16 oldCur;

    if (D_00692038 == 0) {
        return;
    }
    if (wk->f78 != func_0021BDC0) {
        return;
    }

    if (D_00325020 == 0 && (D_003238D0.h14 & 0x10)) {
        int skip = MsMenuGetChrSkipCommand(wk->h8);
        if (skip != 0) {
            func_002D70D8(1);
            ((ToBtlCmdBuf *)D_003252A8)->b0 = wk->h8;
            ((ToBtlCmdBuf *)D_003252A8)->b3 = 1;
            ((ToBtlCmdBuf *)D_003252A8)->item[0].h0[0] = skip;
            ((ToBtlCmdBuf *)D_003252A8)->item[0].h0[1] = 0xFF;
            D_003250D8 = 1 << wk->h8;
            ((ToBtlCmdBuf *)D_003252A8)->item[0].w8 = 1 << wk->h8;
            MsSetBtlCommand(D_003252A8, 0, 0);
            func_00215360(D_003252A4);
            func_002184B8();
            func_0020DC78(2);
            D_003252A4 = 0xFF;
            return;
        }
        func_002D70D8(3);
    }

    if (D_003238D0.h14 & 4) {
        if (D_00325020 != 0) {
            func_002D70D8(3);
            return;
        }
        if (MsGetSaveChrSummon(wk->h8) != 0) {
            func_002D70D8(3);
            return;
        }
        if (TOBtlSetNextAction(wk->h8, 0x3002) == 1) {
            func_002D70D8(1);
            return;
        }
        func_002D70D8(3);
        return;
    }

    if (D_00325020 == 0) {
        if (D_003238D0.h14 & 0x8000) {
            if (MsCheckLeftWindow(wk->h8) > 0) {
                TOBtlSetNextAction(wk->h8, 0xFFFF);
                func_002D70D8(1);
                return;
            }
        }
        if (D_003238D0.h14 & 0x2000) {
            TOGetSaveWindow(wk->h8, 0xD, &winCnt);
            if (winCnt == 0) {
                func_002D70D8(3);
                return;
            }
            TOBtlSetNextAction(wk->h8, 0xFFFE);
            func_002D70D8(1);
            return;
        }
    }

    oldCur = wk->h42;
    if ((D_003238D0.h12 & 0x9000) != 0x9000
        && (D_003238D0.h12 & 0x3000) != 0x3000
        && (D_003238D0.h12 & 0xC000) != 0xC000
        && (D_003238D0.h12 & 0x6000) != 0x6000) {
        if (D_003238D0.h16 == 0x1000) {
            wk->h42 -= wk->h38;
        }
        if (D_003238D0.h16 == 0x4000) {
            wk->h42 += wk->h38;
        }
        if (D_003238D0.h16 == 0x8000) {
            wk->h42--;
        }
        if (D_003238D0.h16 == 0x2000) {
            wk->h42++;
        }
        if (D_003238D0.h16 == 0x1000 || D_003238D0.h16 == 0x4000) {
            if (wk->h42 < 0) {
                wk->h42 += wk->h38;
            }
            if (wk->h42 >= wk->h44) {
                if (wk->h42 / wk->h38 > (wk->h44 - 1) / wk->h38) {
                    wk->h42 -= wk->h38;
                } else {
                    wk->h42 = wk->h44 - 1;
                }
            }
        }
        if (D_003238D0.h16 == 0x8000 || D_003238D0.h16 == 0x2000) {
            if (wk->h42 < 0) {
                wk->h42 = 0;
            }
            if (wk->h42 >= wk->h44) {
                wk->h42 = wk->h44 - 1;
            }
        }
    }

    wk->h16[wk->bB] = wk->list[wk->h42];
    wk->hE[wk->bB] = wk->h42;

    if (D_003238D0.h14 & 0x40) {
        if (wk->bB > 0) {
            wk->h16[wk->bB] = 0xFF;
            wk->hE[wk->bB] = 0xFF;
            wk->bB--;
            wk->h42 = wk->hE[wk->bB];
            wk->h1E = wk->h16[wk->bB];
            func_001BFEA8(0);
            func_002D70D8(4);
            return;
        }
        if (D_00325020 > 0) {
            TOBtlSetPrevAction();
            wk->state++;
            func_002D70D8(4);
            return;
        }
        return;
    }

    if (D_003238D0.h14 & 0x20) {
        if (TOCheckBtlCommandUse(wk->h8, wk->h16[wk->bB]) < 0) {
            func_002D70D8(3);
            return;
        }
        wk->h16[wk->bB] = wk->list[wk->h42];
        wk->hE[wk->bB] = wk->h42;
        wk->bB++;
        if (wk->bB < wk->bA) {
            _int_func_001BFEA8(wk->h16[0]);
            func_002D70D8(1);
            return;
        }
        if (TOBtlSetNextAction(wk->h8, wk->list[wk->h42]) == 1) {
            func_002D70D8(1);
            return;
        }
        func_002D70D8(3);
        return;
    }

    if (wk->h42 < wk->h40) {
        wk->h40 -= wk->h38;
        wk->f78 = func_0021BE28;
    }
    if (wk->h42 >= wk->h40 + wk->h3A * wk->h38) {
        wk->h40 += wk->h38;
        wk->f78 = func_0021BDC8;
    }
    if (wk->h3A * wk->h38 < wk->h44) {
        winCnt = ((wk->h44 + wk->h38 - 1) / wk->h38 - wk->h3A) * wk->h38;
        wk->h40 = (wk->h40 > winCnt) ? winCnt : (wk->h40 < 0 ? 0 : wk->h40);
    } else {
        wk->h40 = 0;
    }

    if (wk->h42 != oldCur) {
        wk->h1E = wk->list[wk->h42];
        wk->hE[wk->bB] = wk->h42;
        wk->h16[wk->bB] = wk->list[wk->h42];
        func_002D70D8(1);
    }
}

void _TOGetPadStatusPrepare(R4RecFull *wk)
{
    s16 oldCur;

    if (D_00692038 == 0) {
        return;
    }
    if (wk->f78 != func_0021BDC0) {
        return;
    }

    if (D_003238D0.h14 & 0x40) {
        if (wk->bB > 0) {
            wk->h16[wk->bB] = 0xFF;
            wk->hE[wk->bB] = 0xFF;
            wk->bB--;
            wk->h42 = wk->hE[wk->bB];
            wk->h1E = wk->h16[wk->bB];
            func_001BFEA8(0);
            func_002D70D8(4);
            return;
        }
        if (D_00325020 > 0) {
            TOBtlSetPrevAction();
            wk->state++;
            func_002D70D8(4);
            return;
        }
        return;
    }

    if (D_003238D0.h14 & 0x20) {
        if (TOCheckBtlCommandUse(wk->h8, wk->list[wk->h42]) < 0) {
            func_002D70D8(3);
            return;
        }
        wk->h16[wk->bB] = wk->list[wk->h42];
        wk->hE[wk->bB] = wk->h42;
        wk->bB++;
        if (wk->bB < wk->bA) {
            _int_func_001BFEA8(wk->h16[0]);
            func_002D70D8(1);
            return;
        }
        if (TOBtlSetNextAction(wk->h8, wk->list[wk->h42]) == 1) {
            func_002D70D8(1);
            return;
        }
        func_002D70D8(3);
        return;
    }

    if (D_003238D0.h14 & 4) {
        func_002D70D8(3);
        return;
    }

    oldCur = wk->h42;
    if ((D_003238D0.h12 & 0x9000) != 0x9000
        && (D_003238D0.h12 & 0x3000) != 0x3000
        && (D_003238D0.h12 & 0xC000) != 0xC000
        && (D_003238D0.h12 & 0x6000) != 0x6000) {
        if (D_003238D0.h16 == 0x1000) {
            wk->h42 -= wk->h38;
        }
        if (D_003238D0.h16 == 0x4000) {
            wk->h42 += wk->h38;
        }
        if (D_003238D0.h16 == 0x8000) {
            wk->h42--;
        }
        if (D_003238D0.h16 == 0x2000) {
            wk->h42++;
        }
        if (D_003238D0.h16 == 0x1000 || D_003238D0.h16 == 0x4000) {
            if (wk->h42 < 0) {
                wk->h42 += wk->h38;
            }
            if (wk->h42 >= wk->h44) {
                if (wk->h42 / wk->h38 > (wk->h44 - 1) / wk->h38) {
                    wk->h42 -= wk->h38;
                } else {
                    wk->h42 = wk->h44 - 1;
                }
            }
        }
        if (D_003238D0.h16 == 0x8000 || D_003238D0.h16 == 0x2000) {
            if (wk->h42 < 0) {
                wk->h42 = 0;
            }
            if (wk->h42 >= wk->h44) {
                wk->h42 = wk->h44 - 1;
            }
        }
    }

    wk->h16[wk->bB] = wk->list[wk->h42];
    wk->hE[wk->bB] = wk->h42;

    if (wk->h42 < wk->h40) {
        wk->h40 -= wk->h38;
        wk->f78 = func_0021BE28;
    }
    if (wk->h42 >= wk->h40 + wk->h3A * wk->h38) {
        wk->h40 += wk->h38;
        wk->f78 = func_0021BDC8;
    }
    if (wk->h3A * wk->h38 < wk->h44) {
        int maxTop = ((wk->h44 + wk->h38 - 1) / wk->h38 - wk->h3A) * wk->h38;
        wk->h40 = (wk->h40 > maxTop) ? maxTop : (wk->h40 < 0 ? 0 : wk->h40);
    } else {
        wk->h40 = 0;
    }

    if (wk->h42 != oldCur) {
        wk->h1E = wk->list[wk->h42];
        func_002D70D8(1);
    }
}

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
