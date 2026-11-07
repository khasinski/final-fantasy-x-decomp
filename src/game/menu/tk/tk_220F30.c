/* tu_248 0x220f30-0x224430: medium; ~Tk (config/tu_map.tsv) */
#define func_002238D8 _hdr_func_002238D8
#include "common.h"
#include "ffx/r5.h"
#include "ffx/q5.h"
#include "ffx/w6.h"
#include "ffx/u3.h"
#include "ffx/v4.h"
#include "ffx/s5.h"
#include "ffx/v5.h"
#include "ffx/w7.h"
#undef func_002238D8

int func_00220F30(void)
{
    s32 buf;
    int i;
    int text;
    int n = 0;
    Unk1BFED8 *e;

    for (i = 0; i < 8; i++) {
        e = MsGetSaveWeapon(btlgetdata.h[i], &buf);
        if (e->b2 != 0 && ((e->b3 >> 2) & 1 || e->b3 & 1 || (e->b3 >> 3) & 1)) {
            n++;
            text = func_001C0040(btlgetdata.h[i]);
        }
    }
    if (n == 1) {
        func_00206860(7, 0, 0);
        func_00206888(7, 0, text);
        func_002040F8(7);
        D_003257A8 = TkBtlEndGetText(0x401B);
    } else {
        D_003257A8 = TkBtlEndGetText(0x401C);
    }
    return n;
}

void func_00221040(int a, int b)
{
    if (a == 0) {
        D_003257B0 = D_003257AC;
    } else {
        D_003257B0 = a;
    }
    D_003257AC = b;
    if (D_003257B0 == b) {
        D_00693310 = 0x1000;
    } else {
        D_00693310 = 0;
    }
}

int TkBtlEndGetText(int a)
{
    return MsMenuGetBtlEndText(a, MsGetSaveConfigHiragana());
}

void func_002210B8(void)
{
    D_006932F8 = 1;
}

void func_002210C8(int a0, int a1)
{
    Rec0E *r;

    func_002210B8();
    r = D_006930B8 + a1;
    r->b0A = 0xF;
}

int func_00221108(int id)
{
    return func_001BE7B8(id);
}

s32 func_00221128(s32 i)
{
    return btlgetdata.next[i];
}

void func_00221140(s32 i, s32 v)
{
    btlgetdata.next[i] = v;
}

int func_00221158(void)
{
    return func_001BE690();
}

int func_00221178(int a)
{
    return MsGetNextAP(a);
}

s32 func_00221198(int id)
{
    return func_001BE5C0(id);
}

s32 func_002211B8(void)
{
    return MsGetGIL();
}

void func_002211D8(s32 cost)
{
    MsPayGIL(-cost);
}

u32 func_002211E0(int a)
{
    u32 r = (u32)func_00221178(a) / 0xBD | 1;

    if (r % 5 == 0) {
        r += 2;
    }
    return r;
}

s32 func_00221228(void)
{
    return D_0031FCBC;
}

INCLUDE_ASM("build/ee_asm/game/menu/tk/tk_220F30", func_00221238);

int func_002212E0(int id, int c)
{
    int r = 1;
    int n = func_002211E0(id);
    int left = func_00221128(id);

    if (func_00221108(id) >= 0x63) {
        func_00221140(id, 0);
        return 0;
    }
    if (n >= left) {
        n = left;
        r = 0;
    }
    left -= n;
    func_00221238(id, n, c);
    func_00221140(id, left);
    return r;
}

int func_00221398(void)
{
    int r = 0;
    int i;

    for (i = 0; i < D_006930B0; i++) {
        r |= func_002212E0(D_006930B8[i].h6, i);
    }
    return r;
}

int func_00221418(void)
{
    u32 a = D_006930A8;
    u32 b = D_006930AC;
    int r = 1;

    if (a >= b) {
        a = b;
        r = 0;
    }
    D_006930AC = b - a;
    func_002211D8(a);
    return r;
}

void func_00221468(int v)
{
    int i;
    Rec0E *e;

    for (i = 0; i < D_006930B0; i++) {
        e = &D_006930B8[i];
        e->h4 = v;
        if (v == 3) {
            e->h2 = (D_006930B0 - i - 1) * 2;
        }
    }
}

int func_002214D8(int idx)
{
    Rec0E *r = &D_006930B8[idx];
    int ret = 0;

    switch (r->h4) {
    case 0:
        r->h2 -= 1;
        if ((s16)r->h2 < 0) {
            r->h2 = 0;
            r->h4 = 1;
        }
        return 0;
    case 1:
        r->h2 += 0xE3;
        if ((s16)r->h2 >= 0x1000) {
            r->h2 = 0x1000;
            r->h4 = 2;
        }
        break;
    case 2:
        r->h2 = 0x1000;
        r->h4 = 2;
        ret = 1;
        break;
    case 3:
        r->h2 -= 1;
        if ((s16)r->h2 < 0) {
            r->h2 = 0;
            r->h4 = 4;
        }
        break;
    case 4:
        r->h2 += 0xE3;
        if ((s16)r->h2 >= 0x1000) {
            r->h2 = 0x1000;
            r->h4 = 5;
        }
        break;
    case 5:
        ret = 1;
        break;
    }
    if (func_00221108(r->h6) >= 0x63) {
        func_00221140(r->h6, 0);
    }
    return ret;
}

void func_00221620(void)
{
    func_001C03B0(D_003257B4[D_00693328 + D_00693338[0]], btlgetdata.h[D_00693338[1]]);
}

void func_00221668(void)
{
    s32 pos;
    int id = D_00693334;

    if (D_00693340 != 0) {
        id = !id;
    }
    if (id == 0) {
        id = D_003257B4[D_00693328 + D_00693338[0]];
    } else {
        id = btlgetdata.h[D_0069333C];
    }
    MsGetSaveWeapon(id, &pos);
}

void func_002216F0(void)
{
    int cur;

    if (func_00147DD0() == 0) {
        if (func_00147E00() != 0) {
            if (AtelGetMusicNumber() >= 0) {
                cur = AtelGetMusicNumber();
                if (cur != SndGetNowPlayMusic()) {
                    SndMusicCrossStart(AtelGetMusicNumber(), 0x78);
                }
            } else {
                SndMusicVolumeFadeOut(SndGetNowPlayMusic(), 0x78);
            }
        } else {
            AtelRegistMusicNumber(-1);
            SndMusicVolumeFadeOut(SndGetNowPlayMusic(), 0x78);
        }
    }
}

INCLUDE_ASM("build/ee_asm/game/menu/tk/tk_220F30", TkBtlEndCtrl);
INCLUDE_RODATA("build/ee_asm/game/menu/tk/tk_220F30/rodata", jtbl_005711D0);

void func_00222778(void)
{
    TkMenuDrawRect(0, 0, 0x200, 0x1A0, 0x80BA8C00, 0x80832400);
}

void func_002227A0(void)
{
    int i;

    for (i = 0; i < U3_BUF->bD0; i++) {
        MsSaveItemUse(U3_BUF->hD4[i], U3_BUF->bE4[i]);
    }
}

INCLUDE_ASM("build/ee_asm/game/menu/tk/tk_220F30", func_00222820);

void func_00222910(s16 *rec, int y)
{
    int py;
    int px;

    py = y + 0x1C6;
    px = rec[0] + 6;
    func_00246670(func_00221128(rec[3]), py, px, 0);
    py = y + 0x14A;
    px = rec[0] + 6;
    func_00246670(abs(MsGetNextAP(rec[3]) - func_001BE5C0(rec[3])), py, px, 0);
}

void func_002229B0(int i)
{
    Rec0E *r;
    int s0;
    int s2;
    int s3;
    int n;
    int a;

    r = &D_006930B8[i];
    s3 = 0;
    s2 = 0;
    switch (r->h4) {
    case 0:
    case 5:
        return;
    case 1:
        s0 = -(func_00125D90((s16)r->h2) << 9) / 4096;
        s3 = s0 * 2 / 3;
        s2 = s0;
        break;
    case 2:
    case 3:
        s3 = 0;
        s2 = 0;
        break;
    case 4:
        s0 = 0x1000 - func_00125D60(0x1000 - (s16)r->h2);
        s0 = -(s0 << 9) / 4096;
        s3 = s0 * 2 / 3;
        s2 = s0;
        break;
    }
    TOMenuOpenPktBuffTmp();
    TODrawMenuPlateXYWC2_Rfix(0xCC, 0xCD, s3, r->h0, D_00324208, D_0032420C, D_00324210);
    func_001F37C8(TOGetSaveChrName(r->h6), s3 + D_00324214, r->h0 + D_00324216);
    TOMkpShapeXY(0xEB, s3 + 0x111, r->h0 + 0xB);
    func_001F63B8(func_00221128(r->h6), s3 + 0x10C, r->h0 + 0xC, 0x25);
    func_001FE298(0xE7, 0, r->h0, 0x200, 0, 0x80808080, 0x80808080);
    TOMkpShapeXY(0x107, s2 + D_00324228 + 0x68, r->h0 + D_0032422A);
    func_001F5E80(func_00242468(r->h6), s2 + D_00324228 + D_0032422C, r->h0 + D_0032422A + D_0032422E, 0);
    if (func_00221108(r->h6) >= 99) {
        func_001F64F8(D_00571280, s2 + D_00324228 + 0x59, r->h0 + D_0032422A - 13, 0x25);
    } else {
        s0 = MsGetNextAP(r->h6);
        func_001F63B8(s0 - func_001BE5C0(r->h6), s2 + D_00324228 + 0x8B, r->h0 + D_0032422A - 13, 0x25);
    }
    if (r->b0A > 0) {
        a = 15 - r->b0A;
        if (a >= 3) {
            a = 2;
        }
        if (a < 0) {
            a = 0;
        }
        TOMkpShapeXY(0xFA + a, s3 + (D_0032422C + D_00324228) + 3, r->h0 + D_0032422A + D_0032422E - 2);
        r->b0A--;
    }
    TOMenuDrawKickTmp();
}

void func_00222D20(int a)
{
    func_00246CB8(0x10, a, 0x1E0);
}

void func_00222D30(void)
{
    Rec0E *r;

    r = D_006930B8;
    switch (r->h4) {
    case 0:
    case 5:
        return;
    case 1:
        func_00125D90((s16)r->h2);
        break;
    case 2:
    case 3:
        break;
    case 4:
        func_00125D60(0x1000 - (s16)r->h2);
        break;
    }
    func_002243C0(10, 0x94, 0x2D);
}

INCLUDE_ASM("build/ee_asm/game/menu/tk/tk_220F30", func_00222DB0);

INCLUDE_ASM("build/ee_asm/game/menu/tk/tk_220F30", func_00222EB0);

void func_00222F90(int y)
{
    s32 w[2];

    func_002243C0(12, y + 0x1C, 0x14A);
    TOMenuOpenPktBuffTmp();
    TOSeqGetPoint(1, D_005712C8, (s16 *)&w[0], (s16 *)&w[1]); /* DEBT(CAST): filled as words here */
    TOMkpShapeXY(0xD5, y + 0xB8, 0x163);
    TOMkpShapeXY(0xD6, y + w[0] + 0xB8, 0x163);
    func_001F63B8(D_006930AC, y + 0xB8, 0x167, 0x25);
    TOMkpShapeXY(0xD5, y + 0xB8, 0x175);
    TOMkpShapeXY(0xD6, y + w[0] + 0xB8, 0x175);
    func_001F63B8(func_002211B8(), y + 0xB8, 0x179, 0x25);
    TOMenuDrawKickTmp();
}

INCLUDE_ASM("build/ee_asm/game/menu/tk/tk_220F30", func_00223078);

INCLUDE_ASM("build/ee_asm/game/menu/tk/tk_220F30", func_00223140);

INCLUDE_ASM("build/ee_asm/game/menu/tk/tk_220F30", func_00223228);

INCLUDE_ASM("build/ee_asm/game/menu/tk/tk_220F30", func_00223468);

INCLUDE_ASM("build/ee_asm/game/menu/tk/tk_220F30", func_00223620);

INCLUDE_ASM("build/ee_asm/game/menu/tk/tk_220F30", func_002237B0);

void func_00223878(void)
{
    TOMenuOpenPktBuffTmp();
    func_001FA548(0x10B, 0xC4, 0xE8, 0x16);
    if (D_003257A4 != 0) {
        func_001F37C8(D_003257A4, 0x11F, 0xC8);
    }
    TOMakePktScissor(0, 0, 0x1FF, 0x19F);
    TOMenuDrawKickTmp();
}

void _m2c_func_002238D8_TOMakePktScissor(s32, s32, s32, s32) __asm__("TOMakePktScissor");
void _m2c_func_002238D8_TOMenuDrawKickTmp() __asm__("TOMenuDrawKickTmp");
void _m2c_func_002238D8_TOMenuOpenPktBuffTmp() __asm__("TOMenuOpenPktBuffTmp");
void _m2c_func_002238D8__TOGetMessageWH(s32, s32, void *, u16 *, s32, s32) __asm__("_TOGetMessageWH");
void _m2c_func_002238D8_func_001F37C8(s32, s32, s32) __asm__("func_001F37C8");
void _m2c_func_002238D8_func_001FA548(s32, s32, s16, s16) __asm__("func_001FA548");
void func_002238D8(void) {
    s16 sp0;
    u16 sp2;
    s32 temp_17;
    s32 temp_3;

    _m2c_func_002238D8_TOMenuOpenPktBuffTmp();
    _m2c_func_002238D8__TOGetMessageWH(7, D_003257A4, (&sp0), &sp2, 0, 0);
    sp0 = 0xE8;
    temp_3 = sp2 + 0x10;
    sp2 = temp_3;
    temp_17 = 0x198 - (s16) temp_3;
    _m2c_func_002238D8_TOMakePktScissor(0, 0, 0x1FF, 0x19F);
    _m2c_func_002238D8_func_001FA548(0x118, temp_17, sp0, (s16) sp2);
    if (D_003257A4 != 0) {
        _m2c_func_002238D8_func_001F37C8(D_003257A4, 0x128, temp_17 + 8);
    }
    _m2c_func_002238D8_TOMakePktScissor(0, 0, 0x1FF, 0x19F);
    _m2c_func_002238D8_TOMenuDrawKickTmp();
}

INCLUDE_ASM("build/ee_asm/game/menu/tk/tk_220F30", func_002239A8);

void func_00223B00(void)
{
    TOMenuOpenPktBuffTmp();
    ((int (*)())TODrawMenuPlateXYWC2_Rfix)(0x45, 0x46, D_00324248, D_0032424A, D_0032424C, D_00324250, D_00324254); /* DEBT(TYPE): called as returning int */
    TODrawMenuPlateXYWC2_Rfix(6, 7, D_0032425C, D_0032425E, D_00324260, D_00324264, D_00324268);
    TOMkpShapeXY(0x3E, D_00324248 + 0x50, D_0032424A);
    if (D_003257AC != 0) {
        func_001F37C8(D_003257AC, D_0032425C + D_0032426C, D_0032425E + D_0032426E);
    }
    TOMenuDrawKickTmp();
}

INCLUDE_ASM("build/ee_asm/game/menu/tk/tk_220F30", TkBtlEndDraw);

int func_00223DC0(int v) {
    int a[3];
    int i;

    MsGetSavePartyMember(&a[0], &a[1], &a[2]);
    for (i = 0; i < 3; i++) {
        if (v == a[i] && v != 0xFF) {
            return 1;
        }
    }
    return 0;
}

int func_00223E28(void) { return func_00242C58(); }

int func_00223E48(int a0, int a1) {
    return ((140 - a1 * 20) >> 1) + (a0 * 20 + 46);
}

int func_00223E70(int a0, int a1) {
    return ((308 - a1 * 44) >> 1) + (a0 * 44 + 76);
}

INCLUDE_ASM("build/ee_asm/game/menu/tk/tk_220F30", func_00223E98);

void func_00223FB8(int a)
{
    switch ((u8)a) {
    default:
        AtelSetBattleEndKeepRecoverType(a);
        D_006930A0 = 1;
        break;
    case 1:
        D_006930A0 = 0x1D;
        break;
    case 2:
        D_006930A0 = 0;
        break;
    }
    D_006930A4 = 0;
    D_006932F8 = 0;
    D_006930B2 = 0;
    func_00223E98();
}

void func_00224030(void)
{
    D_006930AC = func_00221228();
    D_006930A8 = (D_006930AC / 189) | 1;
    if (D_006930A8 % 5 == 0) {
        D_006930A8 += 2;
    }
}

INCLUDE_ASM("build/ee_asm/game/menu/tk/tk_220F30", TkBtlEndInit);

void func_002243C0(int a0, int a1, int a2) {
    TOMenuOpenPktBuffTmp();
    func_001FF1D8(0xDA, 0xDB, a1, a2, 0xD5, 0x80000000, 0x80000000);
    func_002018D8(a0, a1 + 0x15, a2 + 5);
    TOMenuDrawKickTmp();
}
