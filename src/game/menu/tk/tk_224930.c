/* tu_250 0x224930-0x226bf0: low; ~Tk (config/tu_map.tsv) */
#define func_00225E88 _hdr_func_00225E88
#define func_00225920 _hdr_func_00225920
#define func_002423F0 _hdr_func_002423F0
#include "common.h"
#include "ffx/r5.h"
#include "ffx/q5.h"
#include "ffx/w7.h"
#include "ffx/u3.h"
#include "ffx/v5.h"
#include "ffx/g3.h"
#include "ffx/u4.h"
#undef func_002423F0
#undef func_00225920
#undef func_00225E88

void func_002423F0(void);

s32 func_00224930(void)
{
    return D_00693848;
}

s32 func_00224940(void)
{
    return D_00693854;
}

int func_00224950(int a0, int a1) { return ((a0 << 1) * (a1 + 2)) / 4; }

int func_00224978(int a0, int a1) { return a0 + a0 * a1 / 32; }

s32 func_00224998(void)
{
    return D_00693858;
}

s32 func_002249A8(void)
{
    return D_0069385C;
}

int func_002249B8(R5ChoiceList *choices)
{
    u16 value = choices->entries[choices->selection - 1];
    int result = 0;

    /* DEBT(ORDER): accumulate the zero-entry flag before the 0xFF sentinel check. */
    if (value == 0) {
        result |= 1;
    }
    if (value == 0xFF) {
        result = 1;
    }
    return result;
}

typedef struct GrowEntry {
    u8 b0;
    u8 pad1;
    u16 h2;
    u16 h4;
    u8 b6;
    u8 pad7;
} GrowEntry;

typedef struct CmdPair {
    u16 h0;
    u16 h2;
} CmdPair;

extern u8 D_0036F1D8[];
u16 *MsGetSaveWeaponList(int a, int b, int c, s32 *count);
u16 *MsSaveItemTypeBuffer(s32 *count);
u8 *MsSaveItemNumBuffer(s32 *count);
int TkMenuSummonEnableMask(void);
int func_00242940(void);
int TkMenuGetCommandMax(void *tbl, int a, int b, int c);
int TkMenuGetCommandOffset(void *tbl, int a, int b, int c);
int MsGetSaveCommandMenuPanel(int id);
int MsImportantGet(int id);

void func_002249E8(int mode, int arg1)
{
    int arr0[4];
    u32 arr1[4];
    int arr2[4];
    s32 buf30;
    s32 n34;
    s32 buf38;
    s32 n3C;
    s32 buf40;
    s32 n44;
    s32 buf48;
    s32 n4C;
    s32 buf50;
    s32 buf54;
    s32 buf58;
    int i;
    SysEntry *p;
    SysEntry *end;
    u16 *p2;
    CmdPair *statusTbl;
    int chr;
    int flag;

    p = SYS_TBL;
    p2 = (u16 *)0x1D56F00;
    statusTbl = (CmdPair *)MsMenuStatusNum(0, &buf30);
    chr = TkMenuGetCurrentPlayer();
    for (i = 0; i < 512; i++, p++, p2++) {
        p->h0 = 0;
        p->b2 = 0;
        p->b3 = 0;
        *p2 = 0;
    }
    p = SYS_TBL;
    D_00693858 = 0;
    flag = 0;
    end = SYS_TBL;

    switch (mode) {
    case 21: {
        u16 *list = MsGetSaveWeaponList(-1, -1, 0, &n34);

        for (i = 0; i < n34; i++, p++) {
            u16 id = list[i];
            Unk1BFED8 *w = MsGetSaveWeapon(id, &buf38);

            if (id != 0) {
                if (w->b2 == 0 || ((w->b3 >> 1) & 1)) {
                    p->h0 = id;
                    p->b3 = 0;
                    p->b2 = 0;
                } else {
                    p->h0 = id;
                    if (((w->b3 >> 2) & 1) || ((w->b3 >> 3) & 1) || (w->b3 & 1)) {
                        p->b3 = 0;
                    } else if (((u8 *)w)[6] != 0xFF) {
                        p->b3 = 0;
                    } else {
                        p->b3 = 1;
                    }
                    p->b2 = 1;
                }
            }
        }
        for (i = n34 - 1; i >= 0; i--) {
            if (MsGetSaveWeapon(list[i], &buf38)->b2 != 0) {
                i++;
                break;
            }
        }
        if (i <= 0) {
            i = 1;
            SYS_TBL[0].h0 = 0;
            SYS_TBL[0].b3 = 0;
            SYS_TBL[0].b2 = 0;
        }
        end = &SYS_TBL[i];
        break;
    }
    case 19: {
        u16 *list = MsGetSaveWeaponList(-1, -1, 0, &n3C);

        for (i = 0; i < n3C; i++, p++) {
            u16 id = list[i];
            Unk1BFED8 *w = MsGetSaveWeapon(id, &buf40);

            if (id != 0) {
                if (w->b2 == 0 || ((w->b3 >> 1) & 1)) {
                    p->h0 = 0;
                    p->b3 = 0;
                    p->b2 = 0;
                } else {
                    p->h0 = id;
                    if (((w->b3 >> 2) & 1) || ((w->b3 >> 3) & 1) || (w->b3 & 1)) {
                        p->b3 = 0;
                    } else if (((u8 *)w)[6] != 0xFF) {
                        p->b3 = 0;
                    } else {
                        p->b3 = 1;
                    }
                    p->b2 = 1;
                }
            }
        }
        for (i = n3C - 1; i >= 0; i--) {
            if (MsGetSaveWeapon(list[i], &buf40)->b2 != 0) {
                i++;
                break;
            }
        }
        if (i <= 0) {
            i = 1;
            SYS_TBL[0].h0 = 0;
            SYS_TBL[0].b3 = 0;
            SYS_TBL[0].b2 = 0;
        }
        end = &SYS_TBL[i];
        break;
    }
    case 6:
    case 7: {
        u16 *types = MsSaveItemTypeBuffer(&n44);
        u8 *nums = MsSaveItemNumBuffer(&n44);

        for (i = 0; i < n44; i++, p++) {
            u16 id = *types++;
            u8 num = *nums++;
            u8 *item = (u8 *)TkMsGetRomItem(id, &buf48);

            if (num != 0) {
                int ok;

                if (*(u32 *)(item + 0x1C) & 1) {
                    if ((item[0x22] >> 7) == 0 || ((item[0x22] >> 6) & 1) || TkMenuSummonEnableMask() != 0) {
                        ok = 1;
                    } else {
                        ok = 0;
                    }
                } else {
                    ok = 0;
                }
                if (mode == 7) {
                    ok = 1;
                }
                if (num == 0) {
                    ok = 0;
                }
                p->h0 = id;
                p->b2 = 0x12;
                p->b3 = ok;
            }
        }
        end = p;
        break;
    }
    case 2:
        flag = 1;
        chr = func_00242940();
    case 0: {
        int max;
        int ofs;

        switch (chr) {
        case 0:
            flag = 1;
            break;
        case 1: {
            int mask = TkMenuSummonEnableMask();

            for (i = 8; i < 16; i++) {
                if ((mask >> i) & 1) {
                    p->h0 = i;
                    p->b2 = 2;
                    p->b3 = 1;
                    p++;
                }
            }
            goto done_p;
        }
        case 2:
            flag = 1;
            break;
        case 4:
            flag = 1;
            break;
        }
        func_002423F0();
        max = TkMenuGetCommandMax(statusTbl, 5, chr, 0);
        ofs = TkMenuGetCommandOffset(statusTbl, 5, chr, 0);
        for (i = 0; i < max; i++, p++) {
            u16 cmd = ((CmdPair *)((u8 *)statusTbl + ofs * 4))[i].h2;

            if (MsGetSaveCommand(chr, cmd) != 0) {
                p->h0 = cmd;
                p->b2 = 1;
                p->b3 = 1;
            } else if (flag != 0) {
                p--;
            } else if (MsGetSaveCommandMenuPanel(cmd) == 0) {
                p--;
            }
        }
    done_p:
        end = p;
        break;
    }
    case 3: {
        int imp = MsImportantGet(0xA022);
        int max;
        GrowEntry *g;

        chr = func_00242940();
        max = func_00227EA8();
        g = (GrowEntry *)TkMn2GetSummonGrow();
        for (i = 0; i < max; i++, p++, g++) {
            u16 cmd = g->h2;

            p->b3 = 0xFF;
            if (MsGetSaveCommand(chr, cmd) != 0) {
                p->h0 = cmd;
                p->b2 = 5;
                p->b3 = i;
            } else {
                int have = func_001BFE30(g->h4);

                if (have != 0) {
                    p->h0 = cmd;
                    if (have >= g->b6) {
                        if ((((g->b0 >> (chr - 8)) & 1) == 0) && imp == 0) {
                            p->b3 = i;
                            p->b2 = 6;
                        } else {
                            p->b3 = i;
                            p->b2 = 4;
                        }
                    } else {
                        p->b2 = 7;
                        p->b3 = i;
                    }
                } else {
                    p--;
                }
            }
        }
        end = p;
        break;
    }
    case 1: {
        int mask = func_00225648(chr);

        for (i = 0; i < 20; i++) {
            chr = D_0036F1D8[i];

            if ((mask >> chr) & 1) {
                p->h0 = chr;
                p->b2 = 3;
                p->b3 = 1;
                p++;
            }
        }
        end = p;
        break;
    }
    case 20: {
        int k;
        u16 *list = MsGetSaveWeaponList(TkMenuGetCurrentPlayer(), arg1, 0, &n4C);

        for (k = 0; k < n4C; k++) {
            u16 id = list[k];

            if (MsGetSaveWeapon(id, &buf50)->b2 != 0) {
                p->h0 = id;
                p->b3 = 1;
                p->b2 = 1;
                p++;
            }
        }
        if (arg1 == 1) {
            p->b3 = 1;
            p->h0 = 0;
            p->b2 = 0;
            p++;
        }
        end = p;
        break;
    }
    case 5: {
        GrowEntry *g = (GrowEntry *)func_00227ED0();
        int max = func_00227EF0();
        int nslot;
        int mask = 1;
        int hasFF = 0;
        int hidden;
        u16 *slots = ((R5ChoiceList *)arg1)->entries;
        int j;

        if (((u8 *)arg1)[5] != 0) {
            mask = 2;
        }
        for (i = 0; i < 4; i++) {
            arr0[i] = 0;
            arr1[i] = 0xFFFFFFFFU;
        }
        nslot = 0;
        for (i = 0; i < 4; i++) {
            u16 ab = slots[i];

            if (ab != 0 && ab != 0xFF) {
                u8 *rom = (u8 *)MsGetRomAbility(ab, &buf54);

                arr0[nslot] = rom[0x69];
                arr1[nslot] = rom[0x6A];
                arr2[nslot] = rom[0x6B];
                nslot++;
                if (rom[0x6B] == 0xFF) {
                    hasFF = 1;
                }
            }
        }
        hidden = 0;
        for (i = 0; i < max; i++, g++) {
            if (g->b0 & mask) {
                u16 ab = g->h2;
                u8 *rom = (u8 *)MsGetRomAbility(ab, &buf58);
                int have = func_001BFE30(g->h4);

                if (have != 0) {
                    int st = 0xB;

                    for (j = 0; j < nslot; j++) {
                        if (arr0[j] == rom[0x69]) {
                            if ((u32)rom[0x6A] < (u32)arr1[j]) {
                                st = 0xF;
                            }
                            if (arr1[j] == rom[0x6A]) {
                                st = (arr2[j] == rom[0x6B]) ? 0xC : 0xF;
                            }
                        }
                        if (hasFF != 0 && rom[0x6B] == 0xFE) {
                            st = 0xF;
                        }
                    }
                    if (st == 0xB && have < g->b6) {
                        st = 0xE;
                    }
                    if (func_002249B8((R5ChoiceList *)arg1) == 0) {
                        st = 0x10;
                    }
                    p->h0 = ab;
                    p->b3 = i;
                    p->b2 = st;
                    p++;
                } else {
                    hidden++;
                }
            }
        }
        end = p;
        while (hidden > 0) {
            p->h0 = 0;
            p->b3 = 0xFF;
            p->b2 = 0x11;
            p++;
            hidden--;
        }
        break;
    }
    }
    D_00693858 = ((u32)p - (u32)SYS_TBL) >> 2;
    D_0069385C = ((u32)end - (u32)SYS_TBL) >> 2;
    if (D_0069385C == 0) {
        D_0069385C = 1;
    }
}

void func_002253E8(int a0) { func_002249E8(a0, 0); }

void func_002253F0(int a0, int a1) { func_002249E8(a0, a1); }

void func_002253F8(s32 a, s32 b, s32 c, s32 d)
{
    D_003257E8[0] = a;
    D_003257F0[0] = b;
    D_003257F8[0] = c;
    D_00325800[0] = d;
}

void func_00225420(void)
{
    int i;

    for (i = 1; i > 0; i--) {
        D_003257E8[i] = D_003257E8[i - 1];
        D_003257F0[i] = D_003257F0[i - 1];
        D_003257F8[i] = D_003257F8[i - 1];
        D_00325800[i] = D_00325800[i - 1];
    }
}

void func_00225498(void)
{
    int i;

    for (i = 0; i < 1; i++) {
        D_003257E8[i] = D_003257E8[i + 1];
        D_003257F0[i] = D_003257F0[i + 1];
        D_003257F8[i] = D_003257F8[i + 1];
        D_00325800[i] = D_00325800[i + 1];
    }
}

void func_00225500(int a, s32 *b, s32 *c, s32 *d, s32 *e)
{
    int pos;
    int old;

    if (a == 1) {
        pos = func_00242970();
    } else {
        pos = TkMenuGetCurrentPlayerPos();
    }
    old = *e;
    if (*b > 0) {
        *b -= 0x199;
        if (*b <= 0) {
            *b = 0;
            *c = pos;
            *d = pos;
        }
    } else if (*b != 0) {
        *b += 0x199;
        if (*b >= 0) {
            *b = 0;
            *c = pos;
            *d = pos;
        }
    }
    if (old != pos) {
        int v;

        if (a == 1) {
            v = func_00242B60() << 12;
        } else {
            v = func_00242B50() << 12;
        }
        *b = v;
        *c = old;
        *d = pos;
        *e = pos;
    }
}

u8 TkMn2GetOverDriveId(int idx) { return MsGetSavePlayerPtr(idx)->b38; }

void func_00225620(int idx, int v) { MsGetSavePlayerPtr(idx)->b38 = v; }

s32 func_00225648(int idx) { return MsGetSavePlayerPtr(idx)->v88; }

void func_00225668(int x, int y, int w, u32 c0, u32 c1)
{
    u8 *p = (u8 *)D_0069384C;
    CmdRec *tag = (CmdRec *)p;
    GsAdPacket *q = (GsAdPacket *)(p + 0x10);
    int x0 = (x << 4) + 0x7000;
    int y0 = (y << 4) + 0x7300;
    int x1 = x0 + (w << 4);
    int n;

    q[0].data = 0x6400000000008001UL;
    q[0].reg = 0xF51510UL;
    q[1].data = 0x1C9;
    q[1].reg = c0;
    q[2].data = x0 | ((u64)y0 << 16);
    q[2].reg = c1;
    q[3].data = x1 | ((u64)y0 << 16);
    q[3].reg = 0;
    q += 4;
    n = (u32)((u8 *)q - p + 15) / 16 - 1;
    {
        u32 wC = 0x50000000;
        tag->b3 = 0x10;
        tag->b2 = 0;
        tag->w0 = n;
        tag->w4 = 0;
        tag->w8 = 0;
        tag->wC = n | wC;
        D_0069384C = (CmdRec *)q;
    }
}

int func_00225718(int x, int y, int w, int h, int c0, int c1) /* DEBT(TYPE): declared int in funcs.h, no value returned */
{
    u8 *p = (u8 *)D_0069384C;
    CmdRec *tag = (CmdRec *)p;
    GsAdPacket *q = (GsAdPacket *)(p + 0x10);
    int x0 = (x + 0x700) << 4;
    int y0 = (y + 0x730) << 4;
    int x1 = (x + w + 0x700) << 4;
    int y1 = (y + h + 0x730) << 4;
    int n;

    q[0].data = 0xA400000000008001UL;
    q[0].reg = 0xF515151510UL;
    q[1].data = 0x14C;
    q[1].reg = (u32)c0;
    q[2].data = x0 | ((u64)y0 << 16);
    q[2].reg = (u32)c1;
    q[3].data = x1 | ((u64)y0 << 16);
    q[3].reg = (u32)c0;
    q[4].data = x0 | ((u64)y1 << 16);
    q[4].reg = (u32)c1;
    q[5].data = x1 | ((u64)y1 << 16);
    q[5].reg = 0;
    q += 6;
    n = (u32)((u8 *)q - p + 15) / 16 - 1;
    {
        u32 wC = 0x50000000;
        tag->b3 = 0x10;
        tag->b2 = 0;
        tag->w0 = n;
        tag->w4 = 0;
        tag->w8 = 0;
        tag->wC = n | wC;
        D_0069384C = (CmdRec *)q;
    }
}

int func_00225800(int x, int y, int w, int h) /* DEBT(TYPE): declared int in funcs.h, no value returned */
{
    u8 *p;
    CmdRec *tag;
    GsAdPacket *q;
    int dx, dy;
    int x0, x1, y0, y1;
    int n;

    dx = w + x;
    dy = h + y;
    if (x >= 0) {
        x0 = x < 0x200 ? x : 0x1FF;
    } else {
        x0 = 0;
    }
    if (dx >= 0) {
        x1 = dx < 0x200 ? dx : 0x1FF;
    } else {
        x1 = 0;
    }
    if (y >= 0) {
        y0 = y < 0x1A0 ? y : 0x19F;
    } else {
        y0 = 0;
    }
    if (dy >= 0) {
        if (dy >= 0x1A0) {
            y1 = 0x19F;
        } else {
            y1 = dy;
        }
    } else {
        y1 = 0;
    }
    p = (u8 *)D_0069384C;
    tag = (CmdRec *)p;
    q = (GsAdPacket *)(p + 0x10);
    q[0].data = 0x2000000000008001UL;
    q[0].reg = 0xEE;
    q[1].data = ((u64)x0) | ((u64)x1 << 16) | ((u64)y0 << 32) | ((u64)y1 << 48);
    q[1].reg = 0x40;
    q[2].data = 0x3000C;
    q[2].reg = 0x47;
    q += 3;
    n = (u32)((u8 *)q - p + 15) / 16 - 1;
    {
        u32 wC = 0x50000000;
        tag->b3 = 0x10;
        tag->b2 = 0;
        tag->w0 = n;
        tag->w4 = 0;
        tag->w8 = 0;
        tag->wC = n | wC;
        D_0069384C = (CmdRec *)q;
    }
}

void func_00225908(void) { func_00225800(0, 0, 0x1FF, 0x19F); }

CmdRec *_m2c_func_00225920_func_00220830() __asm__("func_00220830");
s32 _m2c_func_00225920_func_00220838() __asm__("func_00220838");
/* DEBT(CAST) */
void func_00225920(void) {
    CmdRec *temp_16;
    s32 temp_2;
    s32 temp_2_2;

    temp_16 = _m2c_func_00225920_func_00220830();
    temp_2 = _m2c_func_00225920_func_00220838();
    temp_2_2 = ((s32)temp_2 / 128) << 6;
    if (D_00693850 == temp_16) {
        D_0069384C = (CmdRec *)((u8 *)temp_16 + temp_2_2);
    } else {
        D_0069384C = temp_16;
    }
    D_003257E8[0] = 0x80;
    D_003257F0[0] = 0x80;
    D_003257F8[0] = 0x80;
    D_00325800[0] = 0x80;
    D_00693850 = D_0069384C;
}

void func_002259B8(void)
{
    CmdRec *p = D_0069384C;

    p->b3 = 0x70;
    D_0069384C = p + 1;
    p->w4 = 0;
    p->w8 = 0;
    p->wC = 0;
    p->w0 = 0;
}

void func_002259E8(int a0) {
    u32 *p = func_002DB6D8(1);

    *p |= 0x40;
    func_002F8660(0);
    func_002DBA28(p, a0);
}

void func_00225A38(void) { func_00124F08(); }

void func_00225A40(int a)
{
    u32 used = (u32)D_0069384C - (u32)D_00693850; /* DEBT(TYPE): high-water marks kept as addresses */
    u32 cur;

    if ((u32)D_00693854 < used) {
        D_00693854 = used;
    }
    cur = (u32)D_0069384C;
    if ((u32)D_00693848 < cur) {
        D_00693848 = cur;
    }
    if (a != 0) {
        func_00225908();
    }
    func_002259B8();
    func_00225A38();
    if ((u32)D_0069384C < 0x2000000) {
        func_002259E8((int)D_00693850);
    } else {
        func_002EF240(D_00571378);
    }
    func_00225920();
}

void func_00225AF8(void) { func_00225A40(1); }

void func_00225B00(void) {
    func_00225A40(1);
    func_00225A38();
}

void graphicUiRemapY2(void) {
    func_00225A40(0);
    func_00225A38();
}

void func_00225B40(int a, int b, int c)
{
    CmdRec *p = D_0069384C;
    u32 n;

    D_0069384C = p + 1;
    D_0069384C = (CmdRec *)func_00200040(p + 1, c, a, b, D_003257E8[0], D_003257F0[0], D_003257F8[0], D_00325800[0]);
    n = ((u32)((u8 *)D_0069384C - (u8 *)p) + 15) >> 4;
    p->b3 = 0x10;
    p->b2 = 0;
    p->w0 = n - 1;
    p->w4 = 0;
    p->w8 = 0;
    p->wC = 0x50000000 | (n - 1);
}

void func_00225BE8(int a, int x, int y, int v)
{
    CmdRec *p = D_0069384C;
    u32 n;

    func_00201D48(a, x, y, v);
    D_0069384C = p + 1;
    D_0069384C = func_00201F50(a, p + 1);
    n = ((u32)((u8 *)D_0069384C - (u8 *)p) + 15) >> 4;
    p->b3 = 0x10;
    p->b2 = 0;
    p->w0 = n - 1;
    p->w4 = 0;
    p->w8 = 0;
    p->wC = 0x50000000 | (n - 1);
}

void func_00225C70(int a, int x, int y, int v)
{
    CmdRec *p = D_0069384C;
    u32 n;

    func_00201DE8(a, x, y, v);
    D_0069384C = p + 1;
    D_0069384C = func_00201F50(a, p + 1);
    n = ((u32)((u8 *)D_0069384C - (u8 *)p) + 15) >> 4;
    p->b3 = 0x10;
    p->b2 = 0;
    p->w0 = n - 1;
    p->w4 = 0;
    p->w8 = 0;
    p->wC = 0x50000000 | (n - 1);
}

INCLUDE_ASM("build/ee_asm/game/menu/tk/tk_224930", func_00225CF8);

void func_00225DE0(int a, int b, int c, int d)
{
    CmdRec *p = D_0069384C;
    u32 n;

    D_0069384C = p + 1;
    D_0069384C = (CmdRec *)func_00225CF8(p + 1, a, b, c, d);
    n = ((u32)((u8 *)D_0069384C - (u8 *)p) + 15) >> 4;
    p->b3 = 0x10;
    p->b2 = 0;
    p->w0 = n - 1;
    p->w4 = 0;
    p->w8 = 0;
    p->wC = 0x50000000 | (n - 1);
}

void func_00225E70(int a0) {
    if (a0 != 0) {
        func_001FFDE0();
    } else {
        func_001FFDC0();
    }
}

CmdRec *_m2c_func_00225E88_func_00200870(CmdRec *, s32, s32, s32, s32, s32, s32, s32) __asm__("func_00200870");
/* DEBT(CAST) */
void func_00225E88(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6) {
    CmdRec *temp_16;
    CmdRec *temp_2;
    CmdRec *temp_2_2;
    s32 temp_3;

    if (arg5 < arg6) {
        temp_16 = D_0069384C;
        temp_2 = ((CmdRec *)((u8 *)temp_16 + (0x10)));
        D_0069384C = temp_2;
        temp_2_2 = _m2c_func_00225E88_func_00200870(temp_2, arg0, arg1, arg2, arg3, arg4, arg5, arg6);
        D_0069384C = temp_2_2;
        temp_3 = ((u32) ((((s32)((u8 *)temp_2_2 - (u8 *)temp_16))) + 0xF) >> 4) - 1;
        temp_16->b2 = 0;
        temp_16->w0 = temp_3;
        temp_16->wC = temp_3 | 0x50000000;
        temp_16->w4 = 0;
        temp_16->w8 = 0;
        temp_16->b3 = 0x10;
    }
}

void func_00225F30(int x, int y, int k)
{
    CmdRec *p;
    u32 n;

    if ((func_00242900() >> k) & 1) {
        func_00225718(x + ((s16 *)&D_00326DA0)[0], y + ((s16 *)&D_00326DA0)[1], /* DEBT(CAST): S6Pt is not visible here */
                      0x200, D_00326DAE, D_00326D98, D_00326DA4);
    }
    p = D_0069384C;
    D_0069384C = p + 1;
    D_0069384C = (CmdRec *)func_00200C58(p + 1, k, x, y);
    n = ((u32)((u8 *)D_0069384C - (u8 *)p) + 15) >> 4;
    p->b3 = 0x10;
    p->b2 = 0;
    p->w0 = n - 1;
    p->w4 = 0;
    p->w8 = 0;
    p->wC = 0x50000000 | (n - 1);
}

int func_00226018(int x, int y, int k) /* DEBT(TYPE): declared int in u4.h, no value returned */
{
    CmdRec *p;
    u32 n;

    if ((func_00242900() >> k) & 1) {
        func_00225718(x + ((s16 *)&D_00326DA0)[0], y + ((s16 *)&D_00326DA0)[1], /* DEBT(CAST): S6Pt is not visible here */
                      0x200, D_00326DAE, D_00326D98, D_00326DA4);
    }
    p = D_0069384C;
    D_0069384C = p + 1;
    D_0069384C = (CmdRec *)func_00200F98(p + 1, k, x, y);
    n = ((u32)((u8 *)D_0069384C - (u8 *)p) + 15) >> 4;
    p->b3 = 0x10;
    p->b2 = 0;
    p->w0 = n - 1;
    p->w4 = 0;
    p->w8 = 0;
    p->wC = 0x50000000 | (n - 1);
}

void func_00226100(int a, int b, int c, int d)
{
    CmdRec *p = D_0069384C;
    u32 n;

    D_0069384C = p + 1;
    D_0069384C = (CmdRec *)func_00201250(p + 1, c, a, b, d);
    n = ((u32)((u8 *)D_0069384C - (u8 *)p) + 15) >> 4;
    p->b3 = 0x10;
    p->b2 = 0;
    p->w0 = n - 1;
    p->w4 = 0;
    p->w8 = 0;
    p->wC = 0x50000000 | (n - 1);
}

void func_00226188(int a, int b, int c, int d)
{
    CmdRec *p = D_0069384C;
    u32 n;

    D_0069384C = p + 1;
    D_0069384C = (CmdRec *)func_00201410(p + 1, c, a, b, d);
    n = ((u32)((u8 *)D_0069384C - (u8 *)p) + 15) >> 4;
    p->b3 = 0x10;
    p->b2 = 0;
    p->w0 = n - 1;
    p->w4 = 0;
    p->w8 = 0;
    p->wC = 0x50000000 | (n - 1);
}

void func_00226210(int a, int b, int c)
{
    CmdRec *p = D_0069384C;
    u32 n;

    D_0069384C = p + 1;
    D_0069384C = (CmdRec *)func_00201A68(p + 1, c, a, b);
    n = ((u32)((u8 *)D_0069384C - (u8 *)p) + 15) >> 4;
    p->b3 = 0x10;
    p->b2 = 0;
    p->w0 = n - 1;
    p->w4 = 0;
    p->w8 = 0;
    p->wC = 0x50000000 | (n - 1);
}

void func_00226290(int a, int b, int c)
{
    CmdRec *p;
    u32 col = D_003257E8[0] | (D_003257F0[0] << 8) | (D_003257F8[0] << 16) | (D_00325800[0] << 24);
    u32 n;

    p = D_0069384C;
    D_0069384C = p + 1;
    D_0069384C = (CmdRec *)func_00201AE0(p + 1, c, a, b, col, col);
    n = ((u32)((u8 *)D_0069384C - (u8 *)p) + 15) >> 4;
    p->b3 = 0x10;
    p->b2 = 0;
    p->w0 = n - 1;
    p->w4 = 0;
    p->w8 = 0;
    p->wC = 0x50000000 | (n - 1);
}

void func_00226350(int a, int b, int c, int d)
{
    CmdRec *p = D_0069384C;
    u32 n;

    D_0069384C = p + 1;
    D_0069384C = (CmdRec *)func_001F4260(p + 1, c, a, b, d, D_003257E8[0], D_003257F0[0], D_003257F8[0], D_00325800[0]);
    n = ((u32)((u8 *)D_0069384C - (u8 *)p) + 15) >> 4;
    p->b3 = 0x10;
    p->b2 = 0;
    p->w0 = n - 1;
    p->w4 = 0;
    p->w8 = 0;
    p->wC = 0x50000000 | (n - 1);
}

void func_00226400(int a, int b, int c, int d)
{
    CmdRec *p = D_0069384C;
    u32 n;

    D_0069384C = p + 1;
    D_0069384C = (CmdRec *)func_001F4350(p + 1, 0, c, a, b, d, D_003257E8[0], D_003257F0[0], D_003257F8[0], D_00325800[0]);
    n = ((u32)((u8 *)D_0069384C - (u8 *)p) + 15) >> 4;
    p->b3 = 0x10;
    p->b2 = 0;
    p->w0 = n - 1;
    p->w4 = 0;
    p->w8 = 0;
    p->wC = 0x50000000 | (n - 1);
}

void TkMn2SetMacroParam(int a0, int a1, int a2) {
    TOMenuSetMacroCommandType(0, a0, a1);
    TOMenuSetMacroCommandValue(0, a0, a2);
}

void func_002264F8(int a, int b, int c, int d)
{
    CmdRec *p = D_0069384C;
    u32 n;

    D_0069384C = p + 1;
    D_0069384C = (CmdRec *)func_001F5918(p + 1, c, a, b, d, D_003257E8[0], D_003257F0[0], D_003257F8[0], D_00325800[0]);
    n = ((u32)((u8 *)D_0069384C - (u8 *)p) + 15) >> 4;
    p->b3 = 0x10;
    p->b2 = 0;
    p->w0 = n - 1;
    p->w4 = 0;
    p->w8 = 0;
    p->wC = 0x50000000 | (n - 1);
}

void func_002265A8(int x, int y, u8 *text, int d)
{
    int w = func_0020E7E0(text);
    CmdRec *p = D_0069384C;
    u32 n;

    D_0069384C = p + 1;
    D_0069384C = (CmdRec *)func_001F5918(p + 1, (int)text, x - w, y, d, D_003257E8[0], D_003257F0[0], D_003257F8[0], D_00325800[0]);
    n = ((u32)((u8 *)D_0069384C - (u8 *)p) + 15) >> 4;
    p->b3 = 0x10;
    p->b2 = 0;
    p->w0 = n - 1;
    p->w4 = 0;
    p->w8 = 0;
    p->wC = 0x50000000 | (n - 1);
}

void func_00226688(int id, int x, int y, int z)
{
    CmdRec *p;
    u32 n;

    if (id == 100) {
        func_00226350(x, y, TkMn2GetCommandName(0x30FF), z);
        return;
    }
    p = D_0069384C;
    D_0069384C = p + 1;
    D_0069384C = (CmdRec *)func_001F9138(p + 1, id, x, y, z);
    n = ((u32)((u8 *)D_0069384C - (u8 *)p) + 15) >> 4;
    p->b3 = 0x10;
    p->b2 = 0;
    p->w0 = n - 1;
    p->w4 = 0;
    p->w8 = 0;
    p->wC = 0x50000000 | (n - 1);
}

void func_00226770(int a, int b, int c, int d)
{
    CmdRec *p = D_0069384C;
    u32 n;

    D_0069384C = p + 1;
    D_0069384C = (CmdRec *)func_001F5060(p + 1, a, b, c, d);
    n = ((u32)((u8 *)D_0069384C - (u8 *)p) + 15) >> 4;
    p->b3 = 0x10;
    p->b2 = 0;
    p->w0 = n - 1;
    p->w4 = 0;
    p->w8 = 0;
    p->wC = 0x50000000 | (n - 1);
}

void func_00226800(int a, int b, int c, int d)
{
    CmdRec *p = D_0069384C;
    u32 n;

    D_0069384C = p + 1;
    D_0069384C = (CmdRec *)func_001F5380(p + 1, a, b, c, d);
    n = ((u32)((u8 *)D_0069384C - (u8 *)p) + 15) >> 4;
    p->b3 = 0x10;
    p->b2 = 0;
    p->w0 = n - 1;
    p->w4 = 0;
    p->w8 = 0;
    p->wC = 0x50000000 | (n - 1);
}

void func_00226890(int a, int b, int c, int d)
{
    CmdRec *p = D_0069384C;
    u32 n;

    D_0069384C = p + 1;
    D_0069384C = (CmdRec *)func_001F50F8(p + 1, a, b, c, d);
    n = ((u32)((u8 *)D_0069384C - (u8 *)p) + 15) >> 4;
    p->b3 = 0x10;
    p->b2 = 0;
    p->w0 = n - 1;
    p->w4 = 0;
    p->w8 = 0;
    p->wC = 0x50000000 | (n - 1);
}

void func_00226920(int a, int b, int c, int d)
{
    CmdRec *p = D_0069384C;
    u32 n;

    D_0069384C = p + 1;
    D_0069384C = (CmdRec *)func_001F5418(p + 1, a, b, c, d);
    n = ((u32)((u8 *)D_0069384C - (u8 *)p) + 15) >> 4;
    p->b3 = 0x10;
    p->b2 = 0;
    p->w0 = n - 1;
    p->w4 = 0;
    p->w8 = 0;
    p->wC = 0x50000000 | (n - 1);
}

void func_002269B0(int a, int b, int c, int d)
{
    CmdRec *p = D_0069384C;
    u32 n;

    D_0069384C = p + 1;
    D_0069384C = (CmdRec *)func_001F5290(p + 1, a, b, c, d);
    n = ((u32)((u8 *)D_0069384C - (u8 *)p) + 15) >> 4;
    p->b3 = 0x10;
    p->b2 = 0;
    p->w0 = n - 1;
    p->w4 = 0;
    p->w8 = 0;
    p->wC = 0x50000000 | (n - 1);
}

void func_00226A40(int a, int b, int c, int d)
{
    CmdRec *p = D_0069384C;
    u32 n;

    D_0069384C = p + 1;
    D_0069384C = (CmdRec *)TOAdpMenuIconWeaponName2(p + 1, a, b, c, d);
    n = ((u32)((u8 *)D_0069384C - (u8 *)p) + 15) >> 4;
    p->b3 = 0x10;
    p->b2 = 0;
    p->w0 = n - 1;
    p->w4 = 0;
    p->w8 = 0;
    p->wC = 0x50000000 | (n - 1);
}

u16 func_00226AD0(u8 *text) { return func_00205ED8(text); }

int func_00226AF0(u8 *text) { return func_00205ED8(text); }

void func_00226B10(int x, int y, u8 *text, int d)
{
    int w = func_00226AD0(text);
    CmdRec *p = D_0069384C;
    u32 n;

    D_0069384C = p + 1;
    D_0069384C = (CmdRec *)func_001F4260(p + 1, (int)text, x - w, y, d, D_003257E8[0], D_003257F0[0], D_003257F8[0], D_00325800[0]);
    n = ((u32)((u8 *)D_0069384C - (u8 *)p) + 15) >> 4;
    p->b3 = 0x10;
    p->b2 = 0;
    p->w0 = n - 1;
    p->w4 = 0;
    p->w8 = 0;
    p->wC = 0x50000000 | (n - 1);
}
