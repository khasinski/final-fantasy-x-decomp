/* tu_078 0x145938-0x148660: low; ~Atel (config/tu_map.tsv) */
#define func_001478B8 _hdr_func_001478B8
#define func_00146B40 _hdr_func_00146B40
#define func_00147A28 _hdr_func_00147A28
#define func_00146180 _hdr_func_00146180
#define Ch_SoundSetId _hdr_Ch_SoundSetId
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
#undef func_00146180
#undef Ch_SoundSetId
void Ch_SoundSetId(Chr *, int);

void func_00145938(void) {
    D_0058E3F8 = 0x10001;
}

typedef struct Str5 {
    char b[5];
} Str5;
extern s8 D_00576479;
extern Str5 D_0056AD38;
extern Str5 D_0056AD40;
extern char D_0056AD48[];
extern s32 D_0058E994;
extern void func_00138260(void);
extern void func_00138AA8(void);
extern u8 D_003089C8[];
extern u8 D_00308BC0[];
extern u8 D_0030B2D8[];
extern u8 D_0030CB48[];
extern u8 D_00321318[];
extern u8 D_0030C258[];
extern u8 D_0030BDE8[];
extern u8 D_0030D4B8[];
extern u8 D_003200A8[];
extern u8 D_00312F00[];
extern u8 D_00327058[];

void func_00145950(void)
{
    u8 buf[0x400];
    int i;

    func_00138260();
    if (D_00576479 != 0) {
        Str5 s1 = D_0056AD38;
        Str5 s2 = D_0056AD40;
        func_0014D718(s1.b, buf);
        func_0014D610((int)s2.b, buf);
    }
    func_002413A8();
    AtelSetShopRatio(100);
    func_0014B150(-1, -1, -1, -1);
    AtelClearPauseFlag();
    func_0014D9A0(0xFF);
    func_00138C78(0);
    func_00135BD0();
    ((void (*)(void))func_0013AC00)(); /* DEBT(TYPE): header prototype has extra arg */
    func_0014CB88();
    func_0014D8A8();
    AtelClearMenuOtakaraFlag();
    AtelRegistAlbhedDic(0, 0);
    func_0014AF68(-1);
    func_00138700();
    func_001387F0();
    func_0014D7F0(179.0f);
    func_0014CF38();
    func_0014D7D0(0);
    AtelRegistMusicNumber(-1);
    func_0014DD00();
    func_00245450();
    func_0014AD08(0);
    D_0058E994 = 0;
    D_0058E93C = 0;
    func_002D1F48(2, func_00138AA8);
    {
        register u32 v __asm__("$3") = 0x10001; /* DEBT(FAKE): match v0/v1 allocation */
        D_0058E3F8 = v;
    }
    func_00138BF8(0);
    func_00138B40(0, 0);
    for (i = 0; i < 16; i++) {
        func_0014B8E8(i, 0);
    }
    func_0014B8E8(1, D_003089C8);
    func_0014B8E8(0, D_00308BC0);
    func_0014B8E8(12, D_0030B2D8);
    func_0014B8E8(6, D_0030CB48);
    func_0014B8E8(9, D_00321318);
    func_0014B8E8(5, D_0030C258);
    func_0014B8E8(4, D_0030BDE8);
    func_0014B8E8(11, D_0030D4B8);
    func_0014B8E8(7, D_003200A8);
    func_0014B8E8(8, D_00312F00);
    func_0014B8E8(13, D_00327058);
    for (i = 0; i < 7; i++) {
        ((void (*)(int))func_00144938)(i); /* DEBT(TYPE): header prototype omits arg */
        AtelChangeCurrentCtrl(i);
    }
    AtelChangeCurrentCtrl(0);
    func_0013D858(1.0f);
    func_0014F0D0();
    AtelInitCalcSound();
    func_0014CD50(D_0056AD48);
}

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

int func_00146180(s32 *st)
{
    int ret = 0;
    int s = *st;

again:
    switch (s) {
    case 0:
        *st = 1;
        break;
    case 1:
        {
            int (**cd)(int) = (int (**)(int))GetCD();
            if (func_002D6768() != 0) {
                break;
            }
            if (cd[2](1) != 0) {
                break;
            }
            *st = 2;
        }
        break;
    case 2:
        func_00139A00(*(s32 *)((u8 *)D_0058E3D8 + 0x48), 0);
        *st = 3;
        break;
    case 3:
        func_00139D48(0xF, 0x3F, 1);
        if (D_0058E9A0 == 0) {
            ret = 1;
        } else {
            *st = 4;
        }
        break;
    case 4:
        if (SndGetNowPlayMusic() != 0x8A) {
            SndMusicStop(0x8A);
            SndMusicClear(0x8A);
        }
        if (AtelGetMusicNumber() >= 0 && !(D_0058E3F8 & 0x400) && AtelGetMusicNumber() != 0x10) {
            func_002D85D0();
            SndMusicStop(AtelGetMusicNumber());
            SndMusicClear(AtelGetMusicNumber());
        }
        *st = 5;
        break;
    case 5:
        {
            int (**cd)(int) = (int (**)(int))GetCD();
            if (func_002D6768() != 0) {
                break;
            }
            if (cd[2](1) != 0) {
                break;
            }
            s = 6;
            goto again; /* DEBT(GOTO): re-enter switch on state 5 -> 6 */
        }
        break;
    case 6:
        {
            int a = func_001245D8();
            int b = func_001245E8();
            SndMusicStandby(a, b);
            *st = 7;
        }
        break;
    case 7:
        if (SndSyncMusicStandby(0) == 0) {
            *st = 8;
        }
        break;
    case 8:
        if (SndGetNowPlayMusic() == 0x10) {
            SndMusicStop(0x10);
            SndMusicReplayPointClear(0x10);
        }
        SndMusicStart(0x10);
        *st = 9;
        break;
    case 9:
        ret = 1;
        break;
    }
    return ret;
}

void func_001463B0(void)
{
    if (!(D_0058E3F8 & 0x400)) {
        D_0058E9A0 = 1;
    } else {
        D_0058E9A0 = 0;
    }
    AtelRegistCallbackQue2(0, func_00146180, D_0056ADD8);
}

void func_001463F0(int unused)
{
    int saved;
    int n;
    int i;

    func_002D67F8(0);
    if (func_001AF348() == 0) {
        u32 *p = (u32 *)func_00124828();
        D_0058E3F8 &= ~0x10000;
        D_0058E3F8 |= p[0xE4 / 4];
    }
    func_001463B0();
    func_0014CED0(1, 0);
    func_0014CED0(2, 0);
    func_0014CED0(3, 0);
    func_002D6C38();
    SndClearFootStatus();
    func_0014AD08(0);
    func_00174C58();
    saved = AtelChangeCurrentCtrl(0);
    n = AtelGetCtrlworkActorTotal((char *)AtelGetCurCtrlWork());
    for (i = 0; i < n; i++) {
        Actor *a = AtelGetBasicWork(i);
        *(s32 *)&AR(a)->w34.w &= -5; /* DEBT(CAST): signed -5 mask emits li -5 */
        if (a->ptr9C != 0) {
            ((s8 *)a)[0xAC] = func_00110560(a->ptr9C);
            ((s8 *)a)[0xB0] = func_00110818(a->ptr9C);
            a->wA4 = func_00102220(a->ptr9C);
            if (a->w38 & 8) {
                a->b33 |= 0x80;
            }
        }
    }
    for (i = 0; i < n; i++) {
        Actor *a = AtelGetBasicWork(i);
        if (a->ptr9C != 0 && a->hA8 == 0x5001) {
            int j;
            u8 *ep = (u8 *)a + 0xB18; /* DEBT(CAST): Actor effect table at +0xB18 */
            for (j = 0; j < 4; j++, ep += 0x10) {
                u32 id = *(u16 *)ep & 0xFFFF7FFF;
                if (id != 0) {
                    pppFpIDdispOff(id);
                }
            }
        }
    }
    *(u32 *)D_0058E3D8 |= 0x80000000; /* DEBT(CAST): D_0058E3D8 flag word */
    AtelSetCurrentCtrl(saved);
    func_00145470();
    func_001394E0();
}

typedef struct {
    u8 pad00[0x33];
    u8 b33;
    union {
        s32 u;
        struct {
            u32 lo : 29;
            u32 mgrp : 2;
            u32 hi : 1;
        } bf;
    } f34;
    s32 f38;
    u8 pad3C[0x60];
    void *chr;
    s32 fA0;
    u8 padA4[4];
    u16 hA8;
    u8 bAA;
    u8 padAB[0xA49];
    void *elem[2];
    u8 padAFC[8];
    u16 elem_id[2];
    u8 padB08[8];
    s32 fB10;
} AtelRemoveWork; /* DEBT(NAME): AtelBasicWork offset view for AtelEventRemoveForBattle */

extern s32 D_0058E418;
extern s32 D_0058E428;
extern void SndSepLock(int);
extern int MsBattleGetChrDisposeFlag(void);
extern void Yn_BattleBegin(void);
extern void func_0019CE30(int);
extern int yiGetDrawMask(void);
extern void pppFpSaveStat(void *);
extern void func_001382F0(void);
extern int Yn_GuideMapGetMapNo(void);
extern int func_00145188(int);
extern int AtelChangeCurrentCtrl(int);
extern void SndStopStream(void);
extern int ChN_ExistSystemMGRP(int, int);
extern void ChN_DisposeSystemMGRP(int, int);
extern void TkCh_Dispose(void *);

void AtelEventRemoveForBattle(int v)
{
    int dispose;
    int save;
    int total;
    int i;

    SndSepLock(0);
    dispose = MsBattleGetChrDisposeFlag();
    Yn_BattleBegin();
    func_0019CE30(0);
    D_0058E428 = yiGetDrawMask();
    func_002EF0D0(D_0058E490, 0, 0x100);
    pppFpSaveStat(D_0058E490);
    func_001382F0();
    D_0058E418 = Yn_GuideMapGetMapNo();
    if (func_00145188(0) == 0) {
        return;
    }
    save = AtelChangeCurrentCtrl(0);
    total = AtelGetCtrlworkActorTotal(AtelGetCurCtrlWork());
    SndStopStream();
    for (i = 0; i < total; i++) {
        AtelRemoveWork *w = (AtelRemoveWork *)AtelGetBasicWork(i); /* DEBT(CAST): AtelBasicWork offset view */
        w->f34.u &= ~4;
        if (w->bAA != 1) {
            continue;
        }
        if (w->chr != 0 && !(w->f34.u & 0x400000)) {
            Ch_SetSp(w->chr, 0.0f);
        }
        w->b33 &= ~4;
        w->f34.bf.mgrp = 0;
        w->fB10 &= ~1;
        w->fA0 = 0;
        if (w->chr == 0) {
            continue;
        }
        if (ChN_ExistSystemMGRP(w->hA8, 0) != 0) {
            w->f34.bf.mgrp |= 1;
        }
        if (ChN_ExistSystemMGRP(w->hA8, 2) != 0) {
            w->f34.bf.mgrp |= 2;
        }
        w->fA0 = Ch_GetHideEvent(w->chr);
        if (w->f38 & 0x1000) {
            w->fA0 = 0;
        }
        if (!(w->f38 & 0x800)) {
            func_00110908(w->chr, 0);
        }
        w->f38 &= ~0x800;
        func_00145CA0(w);
        if (w->chr == 0) {
            continue;
        }
        if (w->b33 & 2) {
            if (!(w->f34.u & 0x400000)) {
                if (ChN_ExistSystemMGRP(w->hA8, 0) != 0) {
                    ChN_DisposeSystemMGRP(w->hA8, 0);
                }
                if (ChN_ExistSystemMGRP(w->hA8, 2) != 0) {
                    ChN_DisposeSystemMGRP(w->hA8, 2);
                }
            }
            w->b33 &= ~2;
        }
        if (w->chr == 0) {
            continue;
        }
        if (w->b33 & 0x10) {
            if (!(w->f34.u & 0x400000)) {
                if (w->elem[0] != 0) {
                    TkCh_Dispose(w->elem[0]);
                    if (dispose != 0) {
                        ChN_DataDispose(w->elem_id[0], 0);
                    }
                    w->elem[0] = 0;
                }
            }
            w->b33 &= ~0x10;
        }
        if (w->chr == 0) {
            continue;
        }
        if (w->b33 & 0x20) {
            if (!(w->f34.u & 0x400000)) {
                if (w->elem[1] != 0) {
                    TkCh_Dispose(w->elem[1]);
                    if (dispose != 0) {
                        ChN_DataDispose(w->elem_id[1], 0);
                    }
                    w->elem[1] = 0;
                }
            }
            w->b33 &= ~0x20;
        }
        if (w->chr == 0) {
            continue;
        }
        if ((w->b33 & 1) && !(w->f34.u & 0x400000)) {
            int j;
            w->b33 &= ~1;
            for (j = 0; j < 2; j++) {
                if (w->elem[j] != 0) {
                    TkCh_Dispose(w->elem[j]);
                    if (dispose != 0) {
                        ChN_DataDispose(w->elem_id[j], 0);
                    }
                    w->elem[j] = 0;
                }
            }
            TkCh_Dispose(w->chr);
            if (dispose != 0) {
                ChN_DataDispose(w->hA8, 0);
            }
            w->chr = 0;
        }
    }
    AtelSetCurrentCtrl(save);
}

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

extern u8 D_0058E431;

void func_00147048(Actor *a, s32 arg1) {
    u32 w38 = a->w38;
    int b2 = (w38 >> 2) & 1;
    int b8 = (w38 >> 8) & 1;
    int b3 = (w38 >> 3) & 1;
    float *pos;
    int i;

    a->w38 &= ~4;
    a->w38 &= ~8;
    a->w38 &= ~0x100;
    pos = (float *)AtelGetPosWorkAdrs(a);
    if (arg1 == 0 || (u32)(*(u8 *)&D_0058E3FC - 3) >= 2 || a->w40 != D_0058E404) {
        if (b2 && AR(a)->stateAA == 1 && a->ptr9C != 0) {
            Ch_GetPos(a->ptr9C, &pos[0], &pos[1], &pos[2]);
            func_0013E850(a);
            pos[13] = pos[8];
        }
        func_00145F78(a, b3, b8);
        a->b33 &= 0x7F;
        graphicPreviousLevelGetNameHash(a->ptr9C, pos[0], pos[1] - 0.1f, pos[2]);
        Ch_ClothReset(a->ptr9C);
        Ch_SetDirF(a->ptr9C, pos[8]);
        func_00110300(a->ptr9C, pos[13]);
        Ch_SoundSetId(a->ptr9C, *((u8 *)a + 0xAF));
        SndEventSetPcToActorFoot(*((u8 *)a + 0xAF), a->id);
        AtelRecoverFPFromBattle(a);
        if (AR(a)->hA8 == 3 && D_0058E431 == 0) {
            TkChPatchM160(a->ptr9C, 1);
        }
        if (AR(a)->hA8 == 7 && a->ptr9C != 0) {
            if (AR(a)->hB14 & 1) {
                graphicCharacterInstanceSetMeshSegmentAlpha((s32)a->ptr9C, 1, 1);
            } else {
                graphicCharacterInstanceSetMeshSegmentAlpha((s32)a->ptr9C, 1, 0);
            }
        }
        if (AR(a)->hA8 == 0x5001) {
            for (i = 0; i < 4; i++) {
                int v = AR(a)->ent[i].h0 & ~0x8000;
                if (v) {
                    pppFpIDdispOn(v);
                }
            }
        }
        *(s32 *)((u8 *)a + 0xB10) |= 1;
        a->w38 |= 1;
    }
}

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

void func_00147FA8(void)
{
    int (**cd)(int);
    s32 prev;

    cd = (int (**)(int))GetCD();
    MsBtlGetInit();
    func_0014D4B0();
    func_0014CED0(-1, 1);
    TOReset1();
    while (TkSndIsReadVoice() != 0) {
        SndSeqIopCommandSendMain();
        func_002D3FF0(0);
        func_002D6630();
    }
    if (func_002D6768() != 0 || cd[2](1) != 0) {
        func_002D3FF0(0);
        func_002D6630();
    }
    if (AtelGetMusicNumber() >= 0) {
        SndMusicReplayPointClear(AtelGetMusicNumber());
    }
    if (SndGetNowPlayMusic() >= 0) {
        SndMusicReplayPointClear(SndGetNowPlayMusic());
        SndMusicVolumeFadeOut(SndGetNowPlayMusic(), 0x78);
    }
    SndMusicStop(0x8A);
    SndMusicClear(0x8A);
    AtelRegistMusicNumber(-1);
    func_0014AE30();
    func_0014DD38(1);
    if (func_0015A550() != 0) {
        func_00158D60();
    }
    SndSepClearAll();
    AtelStopSoundAll();
    func_002D7C28(-2);
    func_00149200();
    func_00138C08();
    SndStopStream();
    SndSeqIopCommandSendMain();
    func_002D3FF0(0);
    func_002D6630();
    func_002D3FF0(0);
    func_002D6630();
    func_002D3FF0(0);
    func_002D6630();
    while (func_002D6768() != 0) {
        func_002D3FF0(2);
        func_002D6630();
    }
    TkCdReadSync(0);
    func_002D3FF0(0);
    func_00111AC0();
    prev = AtelChangeCurrentCtrl(0);
    D_0058E3D8->flags |= 0x80;
    D_0058E3D8->f210.w |= 2;
    func_00147EE0();
    func_00147F10();
    func_00209B68();
    func_00138260();
    func_0013A1B0(0x17, 0);
    AtelSetCurrentCtrl(prev);
}

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
