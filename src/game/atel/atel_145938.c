/* tu_078 0x145938-0x148660: low; ~Atel (config/tu_map.tsv) */
#define func_001478B8 _hdr_func_001478B8
#define func_00146B40 _hdr_func_00146B40
#define func_00147A28 _hdr_func_00147A28
#include "common.h"
#include "ffx/q1.h"
#include "ffx/r1.h"
#include "ffx/u0.h"
#include "ffx/q2.h"
#include "ffx/s1.h"
#include "ffx/g0.h"
#undef func_001478B8
#undef func_00146B40
#undef func_00147A28

void func_00145938(void) {
    D_0058E3F8 = 0x10001;
}

INCLUDE_ASM("build/ee_asm/game/atel/atel_145938", func_00145950);

void func_00145C10(void)
{
    Rec124828 *r = func_00124828();
    u8 *p = &r->buf1EC[0xFFF];
    int i;

    for (i = 0xFFF; i >= 0; i--) {
        *p-- = 0;
    }
    func_00149200();
    func_00138C08();
    func_00265F18();
}

int AtelGetElemId(int a, int b)
{
    int r;

    switch (b) {
    case 1:
        r = MsGetSaveChrArmorModel(a);
        break;
    case 0:
    default:
        r = MsGetSaveChrWeaponModel(a);
        break;
    }
    return r;
}

void func_00145CA0(Actor *a)
{
    int i;
    int v;

    for (i = 0; i < 4; i++) {
        v = AR(a)->ent[i].h0 & ~0x8000;
        if (v) {
            func_00269DA8(v);
        }
    }
}

void AtelRecoverFPFromBattle(Actor *a)
{
    int i;
    int v;
    float vec[4];

    for (i = 0; i < 4; i++) {
        v = AR(a)->ent[i].h0 & ~0x8000;
        if (v) {
            switch (AR(a)->stateAA) {
            case 1:
                if (AR(a)->ptr9C) {
                    pppFpSetStickChr(v, AR(a)->ptr9C, AR(a)->ent[i].h2);
                }
                break;
            case 5:
                func_00269D60(v, AR(a)->ent[i].h2);
                break;
            case 4:
                pppFpSetStickMap(v, AR(a)->ent[i].h2);
                break;
            default:
                return;
            }
            if (AR(a)->ent[i].h0 & 0x8000) {
                vec[0] = AR(a)->ent[i].f4;
                vec[1] = AR(a)->ent[i].f8;
                vec[2] = AR(a)->ent[i].fC;
                vec[3] = 1.0f;
                pppFpSetStickPos(v, vec);
            }
        }
    }
}

void func_00145E58(Actor *a)
{
    if (AR(a)->w34.b.f29 & 2) {
        ChN_ReadSystemMGRP(AR(a)->hA8, 2);
    }
    if (AR(a)->w34.b.f29 & 1) {
        ChN_ReadSystemMGRP(AR(a)->hA8, 0);
    }
}

void func_00145EC0(Actor *a, int v)
{
    int i;

    for (i = 0; i < 2; i++) {
        if ((AR(a)->hB14 >> i) & 1) {
            if (AR(a)->hB04[i] != 0xFF) {
                if (AR(a)->arrAF4[i]) {
                    graphicLevelGetNameHash(AR(a)->arrAF4[i], v);
                    func_001108B8(AR(a)->arrAF4[i], 0);
                }
            }
        }
    }
}

void func_00145F78(Actor *actor, s32 arg1, s32 arg2)
{
    Chr *chr;
    Chr *chrForMask;
    s32 slot;
    u8 flags;

    if (actor->ptr9C != 0)
    {
        func_00145E58(actor);
        func_00102288(actor->ptr9C, actor->wA4);
        chr = actor->ptr9C;
        flags = actor->b33;
        if (chr != 0 && (flags & 0x40))
        {
            graphicLevelGetNameHash(chr, 1);
            func_00145EC0(actor, 1);
            func_001108B8(actor->ptr9C, 0);
            chr = actor->ptr9C;
            flags = actor->b33;
        }
        actor->b33 = flags & 0xBF;
        if (actor->ptr9C != 0)
        {
            if (actor->w38 & 0x1000)
            {
                func_002EF240(D_0056AD50, actor->id);
                graphicLevelGetNameHash(actor->ptr9C, 0);
                func_00145EC0(actor, 0);
            }
        }
        actor->w38 &= ~0x1000;
        if (arg2 != 0)
        {
            chrForMask = actor->ptr9C;
            slot = actor->w40;
            if ((chrForMask != 0) && (slot < 8))
            {
                if (((s32) D_0058E42C >> slot) & 1)
                {
                    graphicLevelGetNameHash(chrForMask, 0);
                    func_00145EC0(actor, 0);
                }
                else
                {
                    graphicLevelGetNameHash(chrForMask, 1);
                    func_00145EC0(actor, 1);
                }
            }
        }
        if (arg1 == 0)
        {
            Ch_ResetMotion(actor->ptr9C);
        }
    }
}

void func_001460E0(void)
{
    int i;
    int n;
    int saved;

    if (func_00145188(0)) {
        i = 0;
        saved = AtelChangeCurrentCtrl(0);
        n = AtelGetCtrlworkActorTotal((char *)AtelGetCurCtrlWork());
        for (; i < n; i++) {
            AR(AtelGetBasicWork(i))->w34.w |= 4;
        }
        AtelSetCurrentCtrl(saved);
    }
}

INCLUDE_ASM("build/ee_asm/game/atel/atel_145938", func_00146180);
INCLUDE_RODATA("build/ee_asm/game/atel/atel_145938/rodata", jtbl_0056ADB0);

void func_001463B0(void)
{
    if (!(D_0058E3F8 & 0x400)) {
        D_0058E9A0 = 1;
    } else {
        D_0058E9A0 = 0;
    }
    AtelRegistCallbackQue2(0, func_00146180, D_0056ADD8);
}

INCLUDE_ASM("build/ee_asm/game/atel/atel_145938", func_001463F0);

INCLUDE_ASM("build/ee_asm/game/atel/atel_145938", AtelEventRemoveForBattle);

typedef struct Tbl146A68Ent {
    int w0;
    u16 h4;
    u16 h6;
    int w8;
    int wC;
} Tbl146A68Ent;

typedef struct Tbl146A68 {
    u32 count;
    Tbl146A68Ent ent[1];
} Tbl146A68;

void func_00146A68(int a)
{
    char *p = D_0058E3D8->p48;
    int off;

    if (p != 0 && (off = *(int *)(p + 0x24)) != 0) {
        Tbl146A68 *t = (Tbl146A68 *)(p + off);
        u32 i;

        for (i = 0; i < t->count; i++) {
            if (t->ent[i].w0 == a || func_0014DC98() != 0) {
                u16 id = t->ent[i].h4;

                func_00142530(0xFFFF, id, 0, 8, t->ent[i].h6);
                AtelDecodeSignal(id, -1);
            }
        }
    }
}

void func_00146B38(void) {
}

extern u8 D_0058D430;

int func_00146B40(s32 *state)
{
    int ret = 0;

    switch (*state) {
    case 0:
        *state = 1;
        break;
    case 1:
        if (func_002D6768() == 0) {
            if (func_00147E00() != 0) {
                *state = 2;
            } else if (SndGetNowPlayMusic() >= 0) {
                ret = 1;
                if (func_00147E18() != 0) {
                    break;
                }
                goto fade;
            } else {
                ret = 1;
            }
        } else {
            D_0058D430++;
        }
        break;
    case 2:
        if (AtelGetMusicNumber() >= 0) {
            SndMusicRead(AtelGetMusicNumber());
        }
        *state = 3;
        break;
    case 3:
        if (SndSyncMusicStandby(0) == 0) {
            if (func_00147DD0() != 0) {
                ret = 1;
            } else if (func_00147E18() != 0) {
                ret = 1;
            } else if (AtelGetMusicNumber() >= 0) {
                SndMusicCrossStart(AtelGetMusicNumber(), 0x78);
                ret = 1;
            } else {
            fade:
                SndMusicVolumeFadeOut(SndGetNowPlayMusic(), 0x78);
                ret = 1;
            }
        }
        break;
    }
    return ret;
}

int func_00146CB8(s32 *state)
{
    int ret = 0;
    int h = AtelChangeCurrentCtrl(0);

    switch (*state) {
    case 0:
        D_0058E3E4 = 0;
        *state = 1;
    case 1:
        if (((int (*)(u32))op_oef2_sound_cue_check)(0xFFFFFFFF) == 0) {
            *state = 4;
        }
        break;
    case 2:
        if (func_002D6768() == 0) {
            *state = 3;
        }
        break;
    case 3:
        if (func_002D6768() == 0) {
            *state = 4;
        }
        break;
    case 4:
        while (D_0058E3E4 < 7) {
            int i;
            int m = func_00138C58();
            i = D_0058E3E4;
            D_0058E3E4 = i + 1;
            if ((m >> i) & 1) {
                func_00149080((int)S1SYS()->p48, S1SYS()->w204, 0, i, 1);
                *state = 2;
                goto done;
            }
        }
        *state = 5;
        break;
    case 5:
        if (func_002D6730() == 0) {
            *state = 6;
        }
        break;
    case 6:
        {
            AtelEventKickBGSep((int)S1SYS()->p48, 0);
            ret = 1;
        }
        break;
    default:
        break;
    }
done:
    AtelSetCurrentCtrl(h);
    return ret;
}

void func_00146E30(void)
{
    AtelRegistCallbackQue2(0, func_00146B40, D_0056AE00);
}

void func_00146E48(void)
{
    AtelRegistCallbackQue2(0, func_00146CB8, D_0056AE08);
}

int func_00146E60(s32 *state)
{
    int busy = 0;
    int h = AtelChangeCurrentCtrl(0);

    switch (*state) {
    case 0:
        TkGetNowEventJumpMapIdNo(TkGetNowEventJumpMapNo());
        *state = 1;
        break;
    case 1:
        if (yiGetRenderStatus() & 0x40) {
            break;
        }
        func_002F8660(0);
        *state = 2;
        break;
    case 2: {
        int v = TkGetNowEventJumpMapNo();
        yiFieldObjReadNB(v, func_00124C88());
        *state = 3;
        break;
    }
    case 3:
        if (yiGetRenderStatus() & 0x20) {
            break;
        }
        *state = 4;
        break;
    case 4:
        func_00174E28();
        func_002F8660(0);
        Yn_GuideMapSetMapNo(D_0058E418);
        pppFpLoadStat(D_0058E490);
        *state = 5;
    case 5:
        busy = 1;
        AtelRecoverPreBgPage();
        yiSetDrawMask(D_0058E428);
        func_00139538();
        Yn_Dummy();
        break;
    default:
        break;
    }
    AtelSetCurrentCtrl(h);
    return busy;
}

void func_00146FB8(int a)
{
    if (a != TkGetNowEventJumpMapNo()) {
        AtelRegistCallbackQue2(0, func_00146E60, D_0056AE28);
    } else {
        func_00174E28();
        func_0014D890(func_00124C88());
        Yn_GuideMapSetMapNo(D_0058E418);
        pppFpLoadStat(D_0058E490);
        yiSetDrawMask(D_0058E428);
        func_00139538();
        Yn_Dummy();
    }
}

INCLUDE_ASM("build/ee_asm/game/atel/atel_145938", func_00147048);

INCLUDE_ASM("build/ee_asm/game/atel/atel_145938", func_00147290);
INCLUDE_RODATA("build/ee_asm/game/atel/atel_145938/rodata", jtbl_0056AE30);

void func_00147890(void)
{
    AtelRegistCallbackQue2(0, func_00147290, D_0056AE70);
}

void func_001478A8(void)
{
    func_00139D48(0x78, 0x7F, 1);
}

int func_001478B8(void)
{
    int saved = AtelChangeCurrentCtrl(0);

    D_0058E3D8->flags &= ~0x03000000;
    func_001478A8();
    D_0058E3D8->prev[0] = D_0058E3D8->cur[0];
    D_0058E3D8->prev[1] = D_0058E3D8->cur[1];
    D_0058E3D8->prev[2] = D_0058E3D8->cur[2];
    D_0058E3D8->prev[3] = D_0058E3D8->cur[3];
    AtelClearMenuOtakaraFlag();
    AtelSetCurrentCtrl(saved);
    func_001387D0(-1, 0, 0);
    return 1;
}

int func_00147950(void)
{
    func_0019CE30(1);
    func_001478A8();
    func_001387D0(-1, 0, 0);
    return 1;
}

void func_00147988(int a)
{
    AtelRegistCallbackQue2(0, func_001478B8, D_0056AE78);
    if (a == 0) {
        AtelRegistCallbackQue2(0, func_00147950, D_0056AE80);
    }
}

void func_001479E8(int a, int b)
{
    int v1;

    v1 = AtelChangeCurrentCtrl(0);
    func_00146A68(b);
    AtelSetCurrentCtrl(v1);
}

int func_00147A28(s32 *state)
{
    int ret = 0;
    int s = *state;

loop:
    switch (s) {
    case 0:
        *state = 1;
    case 1:
        if (((int (**)(int))GetCD())[2](1) == 0 && func_002D6730() == 0) {
            *state = 2;
            s = 2;
            goto loop;
        }
        break;
    case 2:
        func_001596C8(D_0058E3E8, D_0058E3EC);
        func_00159C88();
        *state = 3;
        break;
    case 3:
        {
            int v = func_0015A120();
            int t = func_00158958();
            if (D_0058E434 > 0 && t >= D_0058E434) {
                if (D_0058E43C != 0) {
                    func_00117E08(D_0058E438);
                } else {
                    func_00117E18(D_0058E438);
                }
                D_0058E434 = -1;
            }
            if (v & 1) {
                func_00158D60();
                ret = 1;
            }
        }
        break;
    default:
        break;
    }
    return ret;
}

void func_00147B78(s32 a, s32 b)
{
    D_0058E3E8 = a;
    D_0058E3EC = b;
    AtelRegistCallbackQue2(0, func_00147A28, D_0056AE88);
}

int func_00147BA0(int *state)
{
    int r = 0;

    switch (*state) {
    case 0:
        func_0014AD28(D_0058E3F0);
        if (MsEventEffectGetStat() != 1) {
            *state = 0;
        } else {
            *state = 1;
        }
        break;
    case 1:
        if (AtelCheckEventEffectStart(D_0058E3F4) & 1) {
            r = 1;
        }
        break;
    }
    return r;
}

void func_00147C38(s32 a, s32 b)
{
    D_0058E3F0 = a;
    D_0058E3F4 = b;
    AtelRegistCallbackQue2(0, func_00147BA0, D_0056AE90);
    func_00138BF8(1);
}

int func_00147C78(int *st)
{
    int r = func_0014A498(D_0058E3F4);

    if (*st == 0) {
        *st = 1;
    }
    return r & 1;
}

void func_00147CC0(void)
{
    AtelRegistCallbackQue2(0, func_00147C78, D_0056AE98);
}

s32 func_00147CD8(s32 *st)
{
    s32 result;

    result = 0;
    if (*st != 0)
    {
        func_00154390();
        result = 1;
    }
    *st += 1;
    return result;
}

void func_00147D20(void)
{
    AtelRegistCallbackQue2(0, func_00147CD8, D_0056AEA0);
}

void AtelSetEncountBattleEndStatus(s32 a, s32 b, s32 c)
{
    D_0058E3F8 = a;
    D_0058E400 = b;
    D_0058E404 = c;
}

int func_00147D58(void)
{
    if (D_0058E3F8 & 0x8000) {
        return 0;
    }
    return 1;
}

int AtelGetStatusWinFadeOut(void)
{
    if (D_0058E3F8 & 0x10000) {
        return 0;
    }
    return 1;
}

int AtelGetPlayStatusFanfare(void)
{
    if (D_0058E3F8 & 0x100) {
        return 0;
    }
    return 1;
}

int AtelGetPlayStatusGameOver(void)
{
    if (D_0058E3F8 & 0x200) {
        return 0;
    }
    return 1;
}

int func_00147DB8(void)
{
    if (D_0058E3FC & 0x100) {
        return 0;
    }
    return 1;
}

int func_00147DD0(void)
{
    if (D_0058E3FC & 0x20000) {
        return 1;
    }
    return 0;
}

void AtelSetBattleEndKeepRecoverType(s32 v)
{
    D_0058E3FC = v & ~0xFF;
}

int func_00147E00(void)
{
    if (D_0058E3FC & 0x800) {
        return 0;
    }
    return 1;
}

int func_00147E18(void) {
    return *(u8 *)&D_0058E3FC == 0; /* DEBT(CAST): only the low byte is tested */
}

int func_00147E28(void) {
    return *(u8 *)&D_0058E3F8 == 0; /* DEBT(CAST): only the low byte is tested */
}

int func_00147E38(void)
{
    if (D_0058E3FC & 0x1000) {
        return 0;
    }
    return 1;
}

int func_00147E50(void)
{
    if (D_0058E3FC & 0x2000) {
        return 1;
    }
    return 0;
}

int TkCheckSoftWareReset(void)
{
    int ret = 1;
    int i;

    if (TkGetTGS() != 0) {
        return 0;
    }
    for (i = 0; i < 6; i++) {
        if (TkGetControlerHist(0, 0, -(i + 1)) != 0x90F) {
            ret = 0;
        }
    }
    return ret;
}

void func_00147EE0(void)
{
    Sg_EnFocus(0);
    Sg_Blur(0);
    Sg_FilterReset();
    func_00173190();
}

void func_00147F10(void)
{
    int old = func_00138240();

    if (func_00138220() != 0) {
        MsSetSaveConfigEnglish(1);
    } else {
        MsSetSaveConfigEnglish(0);
    }
    if (old != func_00138240()) {
        TOSwapInternationalEnvInit(func_00138240());
        while (TOSwapInternationalEnvExec() == 0) {
            func_002D3FF0(0);
            func_001656D8();
        }
    }
}

INCLUDE_ASM("build/ee_asm/game/atel/atel_145938", func_00147FA8);

s32 _m2c_func_001481F0_AtelStopSoundAll() __asm__("AtelStopSoundAll");
s32 _m2c_func_001481F0_TOReset1() __asm__("TOReset1");
s32 _m2c_func_001481F0_func_00138260() __asm__("func_00138260");
s32 _m2c_func_001481F0_func_0013A1B0(s32, s32) __asm__("func_0013A1B0");
s32 _m2c_func_001481F0_func_00147F10() __asm__("func_00147F10");
s32 _m2c_func_001481F0_func_0014D4B0() __asm__("func_0014D4B0");
s32 _m2c_func_001481F0_func_00209B68() __asm__("func_00209B68");

void func_001481F0(void) {
    s32 temp_16;

    _m2c_func_001481F0_TOReset1();
    MsBtlGetInit();
    _m2c_func_001481F0_func_0014D4B0();
    func_0014CED0(-1, 1);
    if (AtelGetMusicNumber() >= 0) {
        SndMusicReplayPointClear(AtelGetMusicNumber());
    }
    if (SndGetNowPlayMusic() >= 0) {
        SndMusicReplayPointClear(SndGetNowPlayMusic());
        SndMusicVolumeFadeOut(SndGetNowPlayMusic(), 0x78);
    }
    SndMusicStop(0x8AU);
    SndMusicClear(0x8AU);
    AtelRegistMusicNumber(-1);
    SndSepClearAll();
    _m2c_func_001481F0_AtelStopSoundAll();
    func_002D7C28(-2);
    func_00149200();
    func_00138C08();
    func_0014DB70(6);
    temp_16 = AtelChangeCurrentCtrl(0);
    D_0058E3D8->flags |= 0x80;
    D_0058E3D8->f210.w |= 2;
    func_00147EE0();
    _m2c_func_001481F0_func_00147F10();
    _m2c_func_001481F0_func_00209B68();
    _m2c_func_001481F0_func_00138260();
    _m2c_func_001481F0_func_0013A1B0(0x17, 0);
    AtelSetCurrentCtrl(temp_16);
}

void func_00148320(void)
{
    int ids[3];
    int i;

    D_0058E42C = 0;
    MsGetSavePartyMember(&ids[0], &ids[1], &ids[2]);
    for (i = 0; i < 3; i++) {
        if (ids[i] != 0xFF) {
            D_0058E42C |= 1 << ids[i];
        }
    }
}

int func_00148390(int a, int b, int c, int d)
{
    Rec124828 *r;
    int saved;
    int ok;

    func_00148320();
    r = func_00124828();
    func_00138BF8(0);
    func_00138408();
    SndSepLock(0);
    SndStopStream();
    func_002D67F8(0);
    func_0014CED0(1, 1);
    func_0014CED0(2, 1);
    func_0014CED0(3, 1);
    r->xD0 = d;
    if (d == 6) {
        func_00147FA8();
    } else {
        saved = AtelChangeCurrentCtrl(0);
        D_0058E3FC = D_0058E3F8;
        if (d == 1 && AtelGetPlayStatusGameOver()) {
            func_001481F0();
        } else {
            func_0014F148();
            func_001479E8(a, b);
            func_001460E0();
            ok = 0;
            if (S1SYS()->p48 != 0) {
                AtelEventRegistFootInfo(S1SYS()->p48);
                func_002D6C80();
            }
            if (a == 1) {
                S1SYS()->flags = (S1SYS()->flags & 0xFCFFFFFF) | 0x2000000;
                if (!(D_0058E3F8 & 0x4000)) {
                    func_00147D20();
                }
                switch (D_0058E3F8 & 0xFF) {
                case 2:
                    AtelRegistMusicNumber(-1);
                    func_00147B78(D_0058E400, D_0058E404);
                    break;
                case 3:
                case 4:
                    func_00147C38(D_0058E400, D_0058E404);
                    break;
                case 1:
                    break;
                case 0:
                default:
                    ok = 1;
                    break;
                }
            } else {
                S1SYS()->flags = (S1SYS()->flags & 0xFCFFFFFF) | 0x1000000;
                ok = 1;
                D_0058E3FC = 0;
                func_00147D20();
            }
            func_00146E30();
            func_00146E48();
            func_00146FB8(c);
            func_00147890();
            if (a == 1 && (u8)D_0058E3F8 == 3) {
                func_00147CC0();
            }
            func_00147988(ok);
            if (ok) {
                SaveDataIsScreenClosed(0x40010002);
                D_0058E3FC &= -0x100;
            }
        }
        D_0058E3F8 = 0x10001;
        func_00135E28(0);
        AtelSetCurrentCtrl(saved);
    }
    return 1;
}
