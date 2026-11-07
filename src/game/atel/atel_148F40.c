/* tu_080 0x148f40-0x14b260: low; ~Atel (config/tu_map.tsv) */
#define func_001496F0 _hdr_func_001496F0
#define func_0014ACC0 _hdr_func_0014ACC0
#define AtelGetHyoukaMenuEnable _hdr_AtelGetHyoukaMenuEnable
#include "common.h"
#include "ffx/q2.h"
#include "ffx/r1.h"
#include "ffx/s1.h"
#include "ffx/u0.h"
#include "ffx/actor_resources.h"
#undef AtelGetHyoukaMenuEnable
#undef func_001496F0
#undef func_0014ACC0

INCLUDE_ASM("build/ee_asm/game/atel/atel_148F40", func_00148F40);

INCLUDE_ASM("build/ee_asm/game/atel/atel_148F40", func_00149080);

int AtelSndTransSepSPKDataGroup(int a, int b, int c)
{
    int r = func_00149080(a, b, 1, c, 0);

    SndSyncTrans(1);
    return r;
}

void func_00149200(void)
{
    D_0030B8C4 = 0;
}

INCLUDE_ASM("build/ee_asm/game/atel/atel_148F40", func_00149210);

s32 _m2c_AtelGetHyoukaMenuEnable_AtelChangeCurrentCtrl(s32) __asm__("AtelChangeCurrentCtrl");
void _m2c_AtelGetHyoukaMenuEnable_AtelSetCurrentCtrl(s32) __asm__("AtelSetCurrentCtrl");
s32 _m2c_AtelGetHyoukaMenuEnable_MsBattleCheck() __asm__("MsBattleCheck");
s32 _m2c_AtelGetHyoukaMenuEnable_TkGetTGS() __asm__("TkGetTGS");
s32 _m2c_AtelGetHyoukaMenuEnable_func_0014AD18() __asm__("func_0014AD18");
s32 _m2c_AtelGetHyoukaMenuEnable_func_0015A550() __asm__("func_0015A550");
s32 _m2c_AtelGetHyoukaMenuEnable_func_002D6730() __asm__("func_002D6730");
extern u32 *_m2c_AtelGetHyoukaMenuEnable_D_0058E3D8 __asm__("D_0058E3D8");
/* DEBT(FAKE) */
s32 AtelGetHyoukaMenuEnable(void) {
    s32 temp_16;
    s32 temp_16_2;
    s32 temp_16_3;
    s32 temp_18;
    s32 var_16;
    register u32 *p __asm__("$3");
    register u32 v __asm__("$2");

    temp_18 = _m2c_AtelGetHyoukaMenuEnable_AtelChangeCurrentCtrl(0);
    p = _m2c_AtelGetHyoukaMenuEnable_D_0058E3D8;
    __asm__("" : "+r"(p));
    v = *p >> 0xC;
    __asm__("" : "+r"(v));
    temp_16_2 = v & 1;
    temp_16_3 = (_m2c_AtelGetHyoukaMenuEnable_TkGetTGS() != 0) ? 0 : temp_16_2;
    if (_m2c_AtelGetHyoukaMenuEnable_MsBattleCheck() != 0) {
        var_16 = 0;
    } else {
        var_16 = (((*_m2c_AtelGetHyoukaMenuEnable_D_0058E3D8 & 0x87200403) ^ 3) != 0) ? 0 : temp_16_3;
    }
    if ((_m2c_AtelGetHyoukaMenuEnable_func_002D6730() != 0) || (_m2c_AtelGetHyoukaMenuEnable_func_0015A550() != 0)) {
        var_16 = 0;
    }
    temp_16 = ((_m2c_AtelGetHyoukaMenuEnable_func_0014AD18() ^ 1) == 0) ? 0 : var_16;
    _m2c_AtelGetHyoukaMenuEnable_AtelSetCurrentCtrl(temp_18);
    return temp_16;
}

void func_001493C8(int v)
{
    int old;
    int on;

    if (ffx_debugmode) {
        old = AtelChangeCurrentCtrl(0);
        on = v != 0;
        S1SYS()->flags = (S1SYS()->flags & ~0x200000) | (on << 21);
        AtelSetCurrentCtrl(old);
    }
}

void AtelSetMoveHokanMode(Actor *a, s32 v)
{
    if (a->stateAA == 1 && a->ptr9C != 0) {
        Ch_EnRotHokan(a->ptr9C, v);
    }
}

INCLUDE_ASM("build/ee_asm/game/atel/atel_148F40", AtelGetActorStartPos);

INCLUDE_ASM("build/ee_asm/game/atel/atel_148F40", AtelGetActorEndPos);

INCLUDE_ASM("build/ee_asm/game/atel/atel_148F40", func_001495A8);

float _m2c_func_00149678_func_00138FC8(char *p) __asm__("func_00138FC8");
float func_00149678(void) {
    float var_f20;
    s32 temp_16;
    s8 *temp_4;

    temp_16 = AtelChangeCurrentCtrl(0);
    if ((D_0058E3D8->flags & 1) && (temp_4 = D_0058E3D8->p48, (temp_4 != 0))) {
        var_f20 = _m2c_func_00149678_func_00138FC8(temp_4);
    } else {
        var_f20 = 0.0f;
    }
    AtelSetCurrentCtrl(temp_16);
    return var_f20;
}

s32 _m2c_func_001496F0_AtelChangeCurrentCtrl(s32) __asm__("AtelChangeCurrentCtrl");
s32 _m2c_func_001496F0_AtelSetCurrentCtrl(s32) __asm__("AtelSetCurrentCtrl");
float _m2c_func_001496F0_func_00138FF0(s8 *, s32) __asm__("func_00138FF0");
float func_001496F0(s32 arg0) {
    float var_f20;
    s32 temp_17;
    s8 *temp_4;

    temp_17 = _m2c_func_001496F0_AtelChangeCurrentCtrl(0);
    if ((D_0058E3D8->flags & 1) && (temp_4 = D_0058E3D8->p48, (temp_4 != 0))) {
        var_f20 = _m2c_func_001496F0_func_00138FF0(temp_4, arg0);
    } else {
        var_f20 = 0.0f;
    }
    _m2c_func_001496F0_AtelSetCurrentCtrl(temp_17);
    return var_f20;
}

/* DEBT(FAKE) */
s32 func_00149770(void) {
    register s32 temp_17 __asm__("$17");
    register s32 var_16 __asm__("$16");
    s8 *temp_4;

    temp_17 = AtelChangeCurrentCtrl(0);
    if (D_0058E3D8->flags & 1) {
        var_16 = 0;
        temp_4 = D_0058E3D8->p48;
        if (temp_4 != 0) {
            var_16 = func_00139080(temp_4);
        }
    } else {
        var_16 = 0;
    }
    AtelSetCurrentCtrl(temp_17);
    return var_16;
}

int func_001497E0(void)
{
    return func_00149770();
}

INCLUDE_ASM("build/ee_asm/game/atel/atel_148F40", AtelGetGuideMapActorInfo);

int func_001499A8(void)
{
    return AtelGetGuideMapActorInfo();
}

int func_001499C8(int v)
{
    int on = v != 0;
    int old = AtelChangeCurrentCtrl(0);
    S1Sys *s = S1SYS();
    u32 w = s->flags;
    int prev;

    s->flags = (w & ~0x20000000) | (on << 29);
    prev = (w >> 29) & 1;
    AtelSetCurrentCtrl(old);
    return prev;
}

int func_00149A30(int v)
{
    int on = v != 0;
    int old = AtelChangeCurrentCtrl(0);
    S1Sys *s = S1SYS();
    u32 w = s->flags;
    int prev;

    s->flags = (w & ~0x40000000) | (on << 30);
    prev = (w >> 30) & 1;
    AtelSetCurrentCtrl(old);
    return prev;
}

int func_00149A98(int v)
{
    int on = v != 0;
    int old = AtelChangeCurrentCtrl(0);
    S1Sys *s = S1SYS();
    u32 w = s->flags;
    int prev;

    s->flags = (w & ~0x8000000) | (on << 27);
    prev = (w >> 27) & 1;
    AtelSetCurrentCtrl(old);
    return prev;
}

INCLUDE_ASM("build/ee_asm/game/atel/atel_148F40", AtelEventRegistFootInfo);

INCLUDE_ASM("build/ee_asm/game/atel/atel_148F40", func_00149E00);

INCLUDE_ASM("build/ee_asm/game/atel/atel_148F40", func_00149E88);

void func_0014A000(int v)
{
    Rec124828 *r = func_00124828();

    if (v != r->x28) {
        r->x28 = v;
        if (S1SYS()->p48) {
            func_00149E88(S1SYS()->p48, v);
        }
        func_00149E00(v);
    }
}

void AtelExecEventSound(void)
{
    ActorInitTable *table;
    ActorInitRecord *record;
    s32 context;
    s32 table1;
    s32 i;
    s32 mode;
    u32 flagsAfter;
    u32 flags;

    table1 = AtelChangeCurrentCtrl(0);
    func_00135F50();
    flags = D_0058E3D8->flags;
    if ((flags & 1) && (D_0058E3D8->p48 != 0))
    {
        if (((flags & 0x03000008) == 8) && (MsBattleCheck() == 0))
        {
            /* DEBT(CAST): resource bytes contain a count and typed trailing records. */
            table = (ActorInitTable *)func_00139228(D_0058E3D8->p48);
            context = SYS()->w1F4;
            if (table != 0)
            {
                for (i = 0; i < table->count; i++)
                {
                    record = &table->records[i];
                    record->payload.self = record;
                    /* DEBT(CAST): initializer API takes an integer payload address. */
                    func_00135F60((s32)&record->payload, 0, context);
                }
            }
            flagsAfter = D_0058E3D8->flags;
            if (flagsAfter & 0x40000)
            {
                mode = (flagsAfter >> 0x11) & 1;
            }
            else
            {
                mode = func_00138BC8();
            }
            func_0014A000(mode);
        }
    }
    AtelSetCurrentCtrl(table1);
}

INCLUDE_ASM("build/ee_asm/game/atel/atel_148F40", func_0014A190);

INCLUDE_ASM("build/ee_asm/game/atel/atel_148F40", AtelPopMember);

u8 func_0014A330(void)
{
    return func_00124828()->x20;
}

s32 func_0014A350(s32 a, s32 b)
{
    return a * 18 + b + 3;
}

void AtelSetBindObject(Actor *a)
{
    Vec4 output;
    Vec4 input;
    ActorState *state;
    u8 mode;
    state = AtelGetPosWorkAdrs(a);
    mode = a->stateAA;
    input.x = state->f30;
    input.y = state->f34;
    input.z = state->f38;
    input.w = 0;
    output.x = state->x;
    output.y = state->y;
    output.z = state->z;
    output.w = 1.0f;
    if (mode == 4) yiSetRotTransGroup(a->hA8, &input, &output);
    else if (mode == 5) yiSetRotTransDObj(a->hA8, &input, &output);
}

s32 AtelCheckEventEffectStart(s32 id)
{
    s32 r = 0;

    switch (MsEventEffectGetStat()) {
    case 0:
    case 1:
    case 6:
        r = 0;
        break;
    case 3:
        MsEventEffectStart(id);
        r = 0;
        break;
    case 5:
        func_00138BF8(0);
        r = 5;
        break;
    }
    return r;
}

int func_0014A498(int id)
{
    int r = 0;

    switch (MsEventEffectGetStat()) {
    case 0:
    case 6:
        r = 5;
        func_0014AD08(4);
        break;
    case 1:
    case 3:
    case 5:
        r = 0;
        break;
    }
    return r;
}

int func_0014A500(void)
{
    int r = 0;

    switch (MsEventEffectGetStat()) {
    case 0:
        r = 5;
        break;
    case 1:
    case 3:
    case 5:
    case 6:
        r = 0;
        break;
    }
    return r;
}

INCLUDE_ASM("build/ee_asm/game/atel/atel_148F40", AtelBindFp);

INCLUDE_ASM("build/ee_asm/game/atel/atel_148F40", func_0014A650);

/* DEBT(CAST) */ /* DEBT(FAKE) */
void func_0014A730(Actor *a, s32 v) {
    Actor *var_16;
    register s32 var_17 __asm__("$17");
    register s32 mask __asm__("$18");

    if (a->hdr->type == 1) {
        var_16 = a;
        if (v == 0) {
            mask = 0xFFFF7FFF;
            __asm__ volatile("" : "+r"(mask));
            var_17 = 3;
            do {
                if ((*(u16 *)((u8 *)(var_16) + (0xB18))) & mask) {
                    (*(u16 *)((u8 *)(var_16) + (0xB18))) = 0U;
                    func_00269DA8(v);
                }
                var_17 -= 1;
                var_16 = (Actor *)((u8 *)var_16 + (0x10));
            } while (var_17 >= 0);
            return;
        }
        mask = 0xFFFF7FFF;
        __asm__ volatile("" : "+r"(mask));
        var_17 = 3;
        do {
            if (((*(u16 *)((u8 *)(var_16) + (0xB18))) & mask) == v) {
                (*(u16 *)((u8 *)(var_16) + (0xB18))) = 0U;
                func_00269DA8(v);
            }
            var_17 -= 1;
            var_16 = (Actor *)((u8 *)var_16 + (0x10));
        } while (var_17 >= 0);
    }
}

INCLUDE_ASM("build/ee_asm/game/atel/atel_148F40", TkChPatchM160);

void TkChSetBattleChrNum(Actor *a)
{
    s32 v;

    if (a->ptr9C != 0) {
        v = a->w40;
        if (v == -1) {
            v = 0xFF;
        }
        Ch_SetBattleChrNum(a->ptr9C, v);
    }
}

Chr *TkCh_Allocate(int id)
{
    Chr *c = func_00102B98(id);

    ChN_ReadSystemMGRP(id, 0);
    if (c && id == 3) {
        TkChPatchM160(c, 1);
    }
    return c;
}

void _m2c_TkCh_Allocate2_TkChPatchM160(Chr *chr, int v) __asm__("TkChPatchM160");
/* DEBT(FAKE) */
Chr *TkCh_Allocate2(s32 arg0) {
    register Chr *temp_17 __asm__("$17");

    temp_17 = Ch_Allocate2();
    ChN_ReadSystemMGRP(arg0, 0);
    if (temp_17 != 0) {
        if (arg0 == 3) {
            _m2c_TkCh_Allocate2_TkChPatchM160(temp_17, 1);
        }
    }
    return temp_17;
}

/* DEBT(CAST): shared declarations retain untyped handles or buffers at these calls. */
void TkCh_BindToElem(s32 a, Chr *b, Chr *c, s32 d, s32 e)
{
    if (a == 7)
    {
        if (c != 0)
        {
            if (e == 0)
            {
                graphicCharacterInstanceSetMeshSegmentAlpha((s32) c, 1, 1);
            }
        }
    }
    Ch_BindToElem(b, c, d);
}

void func_0014A9D8(int id)
{
    Actor *a = AtelGetBasicWork(id);

    func_0013C9C8(a, a->slotIdx);
}

void func_0014AA00(void)
{
    D_0058E420 = 0;
}

void AtelSetEffectFlag(int bit)
{
    D_0058E420 |= 1 << bit;
}

void func_0014AA30(int bit)
{
    D_0058E420 &= ~(1 << bit);
}

int func_0014AA50(int bit)
{
    return (D_0058E420 >> bit) & 1;
}

void AtelEventLoadMusic(void)
{
    int n = func_00138DF0();

    if (n < 0) {
        n &= 0xFFFF;
        AtelPs2DebugString(D_0056AF30);
        SndMusicRead(n);
        AtelPs2DebugString(D_0056AF48);
        SndSyncMusicStandby(1);
    }
}

INCLUDE_ASM("build/ee_asm/game/atel/atel_148F40", AtelEventPlayMusic);

u8 func_0014ABB0(void)
{
    return func_00124828()->xD1;
}

void func_0014ABD0(int v)
{
    Rec124828 *r;

    r = func_00124828();
    if (v != 0) {
        v = 1;
    }
    r->xD1 = v;
}

u16 func_0014AC00(void)
{
    return func_00124828()->xBEC;
}

int func_0014AC20(void)
{
    PadState *p = MsGetSaveMenu();

    return (p->flags >> 8) & 1;
}

void TkSetControlerActuatorMode(void)
{
    PadState *p = MsGetSaveMenu();

    func_002D2768(0, 0, (p->flags >> 4) & 1);
}

/* DEBT(TYPE): declared with a return type (shared header) but no value is returned; callers ignore it */
int TkRefreshSoundMode(void)
{
    s32 w = *(s32 *)MsGetSaveMenu();
    int k;

    if ((w >> 7) & 1) {
        k = 0;
    } else {
        k = (w & 1) ? 1 : 2;
    }
    SndSetSoundMode(k);
    TkSetControlerActuatorMode();
}

s32 *_m2c_func_0014ACC0_AtelGetCurCtrlWork() __asm__("AtelGetCurCtrlWork");
s32 func_0014ACC0(s32 arg0) {
    s32 temp_4;
    s32 var_3;

    temp_4 = *_m2c_func_0014ACC0_AtelGetCurCtrlWork();
    var_3 = (temp_4 & 0x22) != 0;
    if (arg0 != 0) {
        var_3 = (temp_4 & 0x84000400) ? 0 : var_3;
    }
    return var_3 != 0;
}

void func_0014AD08(u8 v)
{
    D_0058E430 = v;
}

u8 func_0014AD18(void)
{
    return D_0058E430;
}

int func_0014AD28(int a)
{
    func_0014AD08(1);
    return MsEventEffectRead(a);
}

void func_0014AD58(int v)
{
    Rec124828 *r;

    r = func_00124828();
    if (v != 0) {
        v = 1;
    }
    r->xD7 = v;
}

u8 func_0014AD88(void)
{
    return func_00124828()->xD7;
}

void func_0014ADA8(void)
{
    D_0058E431 = 0;
}

void func_0014ADB8(void)
{
    D_0058E431 = 1;
}

void func_0014ADC8(void)
{
    int i;

    for (i = 3; i >= 0; i--) {
        D_0058E598[i] = 0;
    }
}

void func_0014AE00(int idx, s32 v)
{
    D_0058E598[idx] = v;
}

s32 func_0014AE18(int idx)
{
    return D_0058E598[idx];
}

void func_0014AE30(void)
{
    int v1;
    s32 v2;

    v1 = AtelGetMusicNumber();
    v2 = SndGetNowPlayMusic();
    SndMusicStop(v1);
    SndMusicClear(v1);
    SndMusicStop(v2);
    SndMusicClear(v2);
    SndSepClearAll();
    func_002D7C28(-1);
}

void func_0014AE98(void)
{
    opd_exit_from_ovl();
}

void func_0014AEA0(void)
{
    D_0058E414 = 0;
    D_0058E40C = -1;
    D_0058E410 = -1;
}

void TkCh_Dispose(int v)
{
    if (!Ch_CheckHandle(v)) {
        Ch_Dispose(v);
    }
}

void func_0014AEF8(u16 v)
{
    func_00124828()->xEA = v;
}

u16 func_0014AF20(void)
{
    return func_00124828()->xEA;
}

s32 func_0014AF40(s32 def)
{
    if (D_0030B8B8 >= 1) {
        def = D_0030B8B8;
    }
    return def;
}

s32 func_0014AF58(void)
{
    return D_0030B8B8;
}

void func_0014AF68(s32 v)
{
    D_0030B8B8 = v;
}

INCLUDE_ASM("build/ee_asm/game/atel/atel_148F40", AtelGetHelpEventFlag);

INCLUDE_ASM("build/ee_asm/game/atel/atel_148F40", AtelSetHelpEventFlag);

void AtelSetShopRatio(s32 v)
{
    D_0058E41C = v;
}

s32 func_0014B0A0(void)
{
    return D_0058E41C;
}

void func_0014B0B0(Actor *actor, s32 index)
{
    int offset;
    Chr **base;
    Chr **entry;
    Chr *chr;
    Chr *attached;

    /* DEBT(ORDER): calculate the slot displacement before resolving its base. */
    offset = index * sizeof(Chr *);
    base = &actor->chrAF4;
    /* DEBT(CAST): the indexed slots still have separate fields in Actor. */
    entry = (Chr **)((u8 *)base + offset);
    chr = *entry;
    if (chr != 0) {
        TkCh_Dispose((s32)chr); /* DEBT(CAST): legacy integer character handle. */
        *entry = 0;
    }
    if ((index == 0) && (actor->hA8 == 7)) {
        attached = actor->ptr9C;
        if (attached != 0) {
            graphicCharacterInstanceSetMeshSegmentAlpha((s32)attached, 1, 0); /* DEBT(CAST): legacy integer character handle. */
        }
    }
    actor->hB14 &= ~(1 << index);
}

void func_0014B150(s32 a, s32 b, s32 c, s32 d)
{
    D_0058E5A8[0] = a;
    D_0058E5A8[1] = b;
    D_0058E5A8[2] = c;
    D_0058E5A8[3] = d;
}

void AtelRegistAlbhedDic(s32 a, s32 b)
{
    D_0058D43C = a;
    D_0058D440 = b;
}

void func_0014B188(void)
{
    int mask, pending, i;

    if (D_0058D43C != 0)
    {
        mask = D_0031D1E0;
        pending = D_0058D440;
        for (i = 0; i < 26; i++)
        {
            if (!((mask >> i) & 1) && ((pending >> i) & 1))
                TkMsImportantSet(i + 0xA004);
        }
    }
    D_0058D43C = 0;
    D_0058D440 = 0;
}

s32 func_0014B240(void)
{
    if (D_0058D43C == 0) {
        return 0;
    }
    return D_0058D440;
}
