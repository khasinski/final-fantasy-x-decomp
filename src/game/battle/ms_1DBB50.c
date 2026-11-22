/* tu_204 0x1dbb50-0x1dc7a0: low; ~Ms (config/tu_map.tsv) */
#include "common.h"
#include "ffx/s3.h"
#include "ffx/q4.h"
#include "ffx/r3.h"
#include "ffx/u2.h"
#include "ffx/v3.h"
#include "ffx/r5.h"

int func_001DBB50(BtlChr *c)
{
    return c->fF2 == 0;
}

void func_001DBB60(Q4Link *p) {
    u32 i = p->fC;
    if (i < 0x11) {
        D_00662D30[i].f0 = 0;
    }
}

void func_001DBB90(void) {
    int i;
    for (i = 0; i < 17; i++) {
        MsStructClear(&D_00662D30[i], 0xC);
    }
}

int func_001DBBE0(int i, int flag) {
    if ((u32)i < 0x11) {
        int arg[8];
        Q4Rec12 *r = &D_00662D30[i];
        arg[3] = i;
        r->f0 = 1;
        r->f4 = MsGetFileSize(0x27, flag ? 9 : 0x27, i);
        if (r->f8 == 0) {
            func_0011C348(0x40);
            r->f8 = (s32)user_malloc(r->f4, 5, D_0056F710, i); /* DEBT(TYPE): handle/pointer kept as int */
            MsMemCheckRegist((void *)r->f8, r->f4); /* DEBT(TYPE): handle/pointer kept as int */
        }
        GetCD()->f0(i, r->f8, func_001DBB60, arg);
        return 0;
    }
    return -1;
}

int func_001DBCB8(u32 i) {
    Q4Rec12 *r;
    if (i <= 16) {
        r = &D_00662D30[i];
        if (r->f8 != 0) {
            if (r->f0 != 0) {
                return -1;
            }
            func_0011D590(r->f8, 5);
            MsStructClear(&r, 0xC); /* clears the local pointer, not the record (as compiled) */
            return 0;
        }
    }
    return -1;
}

int func_001DBD20(u32 i) {
    if (i < 0x11) {
        Q4Rec12 *r = &D_00662D30[i];
        if (r->f8 != 0) {
            return r->f0;
        }
    }
    return 0;
}

INCLUDE_ASM("build/ee_asm/game/battle/ms_1DBB50", MsMenuGetText);
INCLUDE_RODATA("build/ee_asm/game/battle/ms_1DBB50/rodata", jtbl_0056F720);

INCLUDE_ASM("build/ee_asm/game/battle/ms_1DBB50", MsMenuGetHelp);
INCLUDE_RODATA("build/ee_asm/game/battle/ms_1DBB50/rodata", jtbl_0056F770);

int MsMenuGetBtlEndText(int a, int b)
{
    return MsMenuGetText(4, a, b);
}

int MsGetRomBtlText(int a, int b)
{
    return MsMenuGetText(0, a, b);
}

OfsTbl *MsMenuStatusNum(int a, s32 *b)
{
    return MsGetExcelData(a, D_00317378, b);
}

int func_001DC0D8(void)
{
    return MsGetExcelDataNum(D_00317378, 0);
}

int MsMenuCheckLook(void) {
    int i;
    if (D_00317335 != 0) {
        return -1;
    }
    for (i = 0; i < 18; i++) {
        BtlChr *c = MsGetChr(i);
        if ((c->f37C & 1) && c->fA8C == 0 && MsAutoCommandStatusCheck(c, 1, 1, 0) != 0) {
            return -1;
        }
    }
    return 0;
}

int MsMenuCheckChrLook(int id)
{
    BtlChr *c;

    if (D_00317335 == 0) {
        id &= 0xFF;
        c = MsGetChr(id);
        if (MsGetRamChrMonster(id) == 0 || ((c->flags278 >> 3) & 1)) {
            return 0;
        }
    }
    return 1;
}

int MsMenuCheckChrLive(u8 id)
{
    return MsGetChr(id)->f2D6 & 1;
}

u8 func_001DC220(u8 id)
{
    return MsGetChr(id)->f29A;
}

u8 func_001DC240(u8 id)
{
    return MsGetChr(id)->f29B;
}

u8 func_001DC260(u8 id)
{
    return MsGetChr(id)->f29C;
}

u8 func_001DC280(u8 id)
{
    return MsGetChr(id)->f29D;
}

u16 MsMenuBitStatus(u8 id)
{
    return MsGetChr(id)->f2C6;
}

u8 *MsMenuCountStatus(u8 id)
{
    return &MsGetChr(id)->f2C8;
}

u16 MsMenuBitStatus2(u8 id)
{
    return MsGetChr(id)->f2D6;
}

u8 *func_001DC300(u8 id)
{
    return &MsGetChr(id)->f301;
}

u8 *func_001DC320(u8 id)
{
    return &MsGetChr(id)->f30D;
}

u16 func_001DC340(u8 id)
{
    return MsGetChr(id)->f31A;
}

typedef struct {
    u8 pad0[0x26];
    u8 f26;
} ComData26;

typedef struct {
    u8 pad0[0x28];
    u16 cmd[8];
    u8 pad38[0x478 - 0x38];
} PlyWin478;

ComData26 *_CheckLeft_MsGetComData(int, int) __asm__("MsGetComData");

int MsCheckLeftWindow(int id)
{
    int ret = 0;
    BtlChr *c = MsGetChr(id);
    int i;

    for (i = 0; i < 8; i++) {
        u16 cmd = ((PlyWin478 *)btl_ply_win)[id].cmd[i];
        if (cmd != 0xFF) {
            ComData26 *com = _CheckLeft_MsGetComData(cmd, 0);
            if (MsGetCommandUse(id, cmd) == 0) {
                if (com->f26 != 0) {
                    if (c->f27C >= c->f27D || D_003172F0.f3C != 0) {
                        ret |= 2;
                    }
                } else {
                    ret |= 1;
                }
            }
        }
    }
    return ret;
}

typedef struct {
    u8 pad00[8];
    s32 ofs[2];
} MenuComInfo; /* DEBT(TYPE): offset table inside ComData */

MenuComInfo *_MenuInfo_MsGetComData(int, void *) __asm__("MsGetComData");

typedef struct {
    u8 pad00[0xC40];
    u8 *pC40[2];
} ChrMenuInfoPtr; /* DEBT(TYPE): array view of BtlChr::pC40 */

typedef struct {
    u32 pad0;
    struct { u16 x, y; } a[2];
    struct { u16 x, y; } b[2];
} MonInfoTbl; /* DEBT(TYPE): monster text offset table */

void *MsGetMenuChrInfo(int id, int kind)
{
    void *res = 0;
    int hira = MsGetSaveConfigHiragana();

    if ((id >> 12) != 0) {
        MenuComInfo *com = _MenuInfo_MsGetComData(id, &res);
        return res = (u8 *)res + com->ofs[hira];
    } else {
        BtlChr *chr = 0;
        if (MsGetChrTop() != 0) {
            u8 *tbl;
            int idx;

            chr = MsGetChr(id);
            tbl = D_003173D8;
            idx = 0xFF;
            switch (kind) {
            case 1:
                idx = chr->padC28[0xC];
                break;
            case 2:
                idx = chr->padC28[0xD];
                break;
            }
            if (idx != 0xFF && tbl != 0) {
                res = tbl + *(u16 *)(((idx * 2 + hira) << 2) + (u32)tbl);
            }
        }
        if (res != 0) {
            return res;
        }
        if (MsGetRamChrMonster(id) == 0) {
            u8 *base;
            OfsTbl *p = MsGetExcelData(id, D_00317358, (s32 *)&base);

            switch (kind) {
            case 0:
                return res = base + p->a[hira].x;
            case 1:
                return res = base + p->b[hira].x;
            case 2:
                return res = base + p->b[hira].x;
            }
        } else if (chr != 0) {
            u8 *tbl = ((ChrMenuInfoPtr *)chr)->pC40[func_001BD360()];

            switch (kind) {
            case 0:
                break;
            case 1:
                return res = tbl + (((MonInfoTbl *)tbl)->a[hira].x + 0x80);
            case 2:
                return res = tbl + (((MonInfoTbl *)tbl)->b[hira].x + 0x80);
            }
        }
    }
    return res;
}

int MsMenuGetChrSkipCommand(int id)
{
    int r = 0;

    if (D_003172F0.f52 != 0) {
        r = 0xFF;
    } else if (D_003172F0.f2130 != 0) {
        r = MsGetChr(id)->f388;
    }
    return r;
}

void MsMenuOpenTitleWindow(u16 a, int v)
{
    if (TOBtlOpenSignWindow(a)) {
        D_003172F0.f2101 = v;
        D_003172F0.f2102 = v;
    }
}

void MsMenuCloseTitleWindow(int keep) {
    if (keep != 0 && D_003172F0.f2101 > D_003172F0.f2102 - 45) {
        D_003172F0.f2101 = 45 - (D_003172F0.f2102 - D_003172F0.f2101);
        return;
    }
    D_003172F0.f2101 = 0;
    D_003172F0.f2102 = 0;
    TOBtlCloseSignWindow();
}

void func_001DC768(u8 v)
{
    D_00319417 = v;
}

int func_001DC778(int a, int b)
{
    return MsMenuGetText(1, a, b);
}
