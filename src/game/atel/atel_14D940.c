/* tu_085 0x14d940-0x14f3e0: low; ~Atel (config/tu_map.tsv) */
#include "common.h"
#include "ffx/q2.h"
#include "ffx/r1.h"
#include "ffx/s1.h"
#include "ffx/u1.h"

void AtelRegistMusicNumber(s32 v)
{
    D_0058F940 = v;
}

s32 AtelGetMusicNumber(void)
{
    return D_0058F940;
}

void func_0014D960(u8 v)
{
    D_0058F944 = v;
}

void func_0014D970(u8 v)
{
    D_0058F945 = v;
}

u8 func_0014D980(void)
{
    return D_0058F944;
}

u8 func_0014D990(void)
{
    return D_0058F945;
}

void func_0014D9A0(u8 v)
{
    D_0058F93C = v;
}

int func_0014D9B0(void)
{
    if (D_0058F93C == 0xFF) {
        return func_002D98A0();
    }
    return D_0058F93C;
}

void func_0014D9E8(void) {
}

void movie_stop_prog(void)
{
    yiReset();
}

void func_0014D9F8(int i)
{
    int *p = &D_0030BDD0[i];
    int h = *p;

    if (h != 0) {
        func_002F8660(0);
        TkFree(h);
        func_002F8660(0);
        *p = 0;
    }
}

int func_0014DA58(int i, int v)
{
    int h;

    func_0014D9F8(i);
    func_002F8660(0);
    h = TkMalloc(v);
    func_002F8660(0);
    D_0030BDD0[i] = h;
    return h;
}

void func_0014DAC0(int i)
{
    int *p = &D_0030BDD8[i];
    int h = *p;

    if (h != 0) {
        func_002F8660(0);
        TkFree(h);
        *p = 0;
        func_002F8660(0);
    }
}

void func_0014DB28(int i, int v)
{
    func_0014DAC0(i);
    D_0030BDD8[i] = v;
}

void func_0014DB70(s32 v)
{
    func_00124828()->xE0 = v;
}

void func_0014DB98(s32 v)
{
    func_00124828()->xD8 = v;
}

void func_0014DBC0(s32 v)
{
    func_00124828()->xDC = v;
}

s32 func_0014DBE8(void)
{
    return func_00124828()->xE0;
}

s32 func_0014DC08(void)
{
    return func_00124828()->xD8;
}

s32 func_0014DC28(void)
{
    return func_00124828()->xDC;
}

void func_0014DC48(void)
{
    Rec124828 *r = func_00124828();

    r->xE4 = 0;
    r->xE8 = 0;
}

void func_0014DC70(int v)
{
    func_00124828()->xE8 = v;
}

u16 func_0014DC98(void)
{
    return func_00124828()->xE8;
}

void func_0014DCB8(s32 v)
{
    func_00124828()->xE4 = v;
}

s32 func_0014DCE0(void)
{
    return func_00124828()->xE4;
}

void func_0014DD00(void)
{
    func_0014DB70(0);
    D_0058F924 = 0;
    D_0058F928 = 0;
    D_0058F92C = 0;
}

void func_0014DD38(int all)
{
    func_00158D60();
    if (all) {
        if (D_0058F92C) {
            TkFree(D_0058F92C);
            D_0058F92C = 0;
        }
        if (D_0058F928) {
            TkFree(D_0058F928);
            D_0058F928 = 0;
        }
        if (D_0058F924) {
            TkFree(D_0058F924);
            D_0058F924 = 0;
        }
    }
}

void func_0014DDB8(void)
{
    switch (func_0014DBE8()) {
    case 4:
        func_0014DD38(0);
        break;
    case 0:
    case 6:
    default:
        func_0014DD38(1);
        func_0014DB70(0);
        break;
    case 1:
    case 2:
    case 3:
    case 5:
        break;
    }
}

int func_0014DE28(void)
{
    int r = 0;

    switch (func_0014DBE8()) {
    case 2:
    case 3:
    case 4:
        r = 1;
        func_00159CE8(func_0014DC28(), D_0058F924, D_0058F920, D_0058F92C, D_0058F928);
        func_0014DB70(5);
        break;
    }
    return r;
}

void func_0014DEA0(void)
{
    int a;
    int b;

    switch (func_0014DBE8()) {
    case 3:
        AtelPs2DebugString(D_0056B0D0);
        func_0014DD38(0);
        break;
    case 1: {
        s32 *p0 = &D_0058F920;
        s32 *p1 = &D_0058F924;
        AtelPs2DebugString(D_0056B0E8);
        func_0014DD38(1);
        func_00159E80(func_0014DC08(), &a, &b);
        *p0 = TkCdSize(a, b);
        *p1 = func_001250E8(a, b);
        AtelPs2DebugString(D_0056B100);
        {
            int t = sa_task_buff_size_get(1);
            AtelPs2DebugString(D_0056B118);
            D_0058F928 = TkMalloc(t);
        }
        AtelPs2DebugString(D_0056B138);
        {
            int t = func_00159CD8(*p1);
            AtelPs2DebugString(D_0056B158);
            D_0058F92C = TkMalloc(t);
        }
        AtelPs2DebugString(D_0056B178);
        AtelPs2DebugString(D_0056B198);
        func_0014DB70(2);
        break;
    }
    case 0: case 2: case 4: case 5: case 6:
    default:
        break;
    }
}

void func_0014DFE8(int a, int b)
{
    func_0014DB70(1);
    func_0014DB98(a);
    func_0014DBC0(b);
}

void func_0014E028(void)
{
    switch (func_0014DBE8()) {
    case 2:
    case 3:
    case 4:
    case 5:
        func_0014DB70(1);
        break;
    }
}

void func_0014E068(void)
{
    switch (func_0014DBE8()) {
    case 2:
    case 3:
    case 4:
    case 5:
        func_0014DB70(4);
        break;
    }
}

void func_0014E0A8(int a, int b)
{
    switch (func_0014DBE8()) {
    case 2:
    case 3:
    case 4:
    case 5:
        if (a == func_0014DC08()) {
            if (b != func_0014DC28()) {
                func_0014DB70(3);
                func_0014DBC0(b);
            }
        } else {
            func_0014DFE8(a, b);
        }
        break;
    default:
        func_0014DFE8(a, b);
        break;
    }
}

void func_0014E160(void)
{
    func_0014DB70(6);
    func_0014DB98(-1);
}

void func_0014E180(void) {
}

void func_0014E188(void) {
}

void func_0014E190(void) {
}

void func_0014E198(void) {
}

void func_0014E1A0(void) {
}

void func_0014E1A8(void) {
}

void AtelClearPauseFlag(void)
{
    D_0058F948 = 0;
    D_0058F94C = 0;
}

void func_0014E1C8(void)
{
    D_0058F948 = 1;
}

INCLUDE_ASM("build/ee_asm/game/atel/atel_14D940", func_0014E1D8);

void AtelExecSoftWareReset(void)
{
    int save;
    EvGameState *gs;
    int ok;

    save = AtelChangeCurrentCtrl(0);
    gs = AtelGetCurCtrlWork();
    ok = *(u32 *)&gs->flags & 1; /* DEBT(CAST): GameFlags does not name these bits */
    if (MsBattleCheck() || (*(u32 *)&gs->flags & 0x3000000)) {
        ok = 0;
    }
    if (((int (*)(int))func_0014A500)(0) == 0) { /* DEBT(CAST): s1.h declares no parameter, the caller passes 0 */
        ok = 0;
    }
    if (*(u32 *)&gs->flags & 0x80000000) {
        ok = 0;
    }
    if ((gs->w210 >> 1) & 1) {
        ok = 0;
    }
    if (func_0015A550()) {
        ok = 0;
    }
    switch (func_0014AD18()) {
    case 1:
    case 2:
    case 3:
        ok = 0;
        break;
    }
    if (((gs->w210 >> 4) & 1) == 0) {
        ok = 0;
    }
    if (func_0013A238() == 0x15C) {
        ok = 0;
    }
    if (func_0013A238() == 0x15D) {
        ok = 0;
    }
    if (func_0013A238() == 0x17) {
        ok = 0;
    }
    if (((gs->w210 >> 6) & 1) == 0) {
        ok = 0;
    }
    if (TkSndIsStandbyVoice()) {
        ok = 0;
    }
    if (TkSndIsReadVoice()) {
        ok = 0;
    }
    AtelSetCurrentCtrl(save);
    if (ok && TkCheckSoftWareReset()) {
        func_00147FA8();
    }
}

void func_0014E5E0(int a)
{
    int w[2];

    if (a & 1) {
        func_0014D4F8();
    }
    func_0014D5D8(&w[0], &w[1]);
    func_002D2830(0, 0, w[0] * 2);
    func_002D2808(0, 0, w[1] * 2);
}

void func_0014E638(void)
{
    func_0014D8C8();
    func_00145858();
    AtelUpdateBattleStatus();
    func_0014C3A8();
    func_0014C3A8();
    func_0014E1A8();
    func_0014E5E0(1);
    func_0014E1D8();
    AtelExecSoftWareReset();
    if (func_002D3DF8()) {
        func_00136450();
        AtelExecEventSound();
        func_002D3DD8();
    }
}

void AtelExecMenuCtrl(void)
{
    func_00145868();
    if (AtelCheckCallbackQue(0)) {
        AtelExecCallbackQue(0);
    }
}

void func_0014E6F8(void) {
}

void AtelDrawNoTrans(void)
{
    AtelUpdateWaterStatus();
    AtelExecDrawShape();
}

void AtelDrawSemiTrans(void)
{
    EvGameState *gs = AtelGetCtrlWork(0);
    u32 flags;
    int on;

    if (!(*(u32 *)&gs->flags & 1)) { /* DEBT(CAST): GameFlags does not name these bits */
        return;
    }
    if (MsBattleCheck()) {
        return;
    }
    flags = *(u32 *)&gs->flags; /* DEBT(CAST) */
    on = 0;
    if (flags & 0x20000000) {
        on = 1;
    }
    if (flags & 0x10000000) {
        on = 0;
    }
    if (flags & 0x40000000) {
        on = 1;
    }
    if (!((((PadState *)MsGetSaveMenu())->flags >> 6) & 1)) {
        on = 0;
    }
    if (*(u32 *)&gs->flags & 0x8000000) { /* DEBT(CAST) */
        on = 1;
    }
    if ((u32)gs->w1F4 < 3) { /* DEBT(TYPE): w1F4 is compared unsigned */
        on = 0;
    }
    func_0019CD38(on);
}

void func_0014E7F8(void)
{
    func_2063E68();
}

void func_0014E800(void)
{
    int i;

    if (TkIsDebug()) {
        func_20591E8();
    }
    for (i = 0; i < 2; i++) {
        func_0014D9F8(i);
    }
}

INCLUDE_ASM("build/ee_asm/game/atel/atel_14D940", AtelEventSetUp);

void _m2c_AtelEventRemove_MsBattleExeClear(void) __asm__("MsBattleExeClear");
void _m2c_AtelEventRemove_func_00136430(float v) __asm__("func_00136430");
void _m2c_AtelEventRemove_func_00144D48(int v) __asm__("func_00144D48");
s32 _m2c_AtelEventRemove_AtelActorRemove() __asm__("AtelActorRemove");
s32 _m2c_AtelEventRemove_AtelClearSnd3dWorkAll() __asm__("AtelClearSnd3dWorkAll");
s32 _m2c_AtelEventRemove_AtelEventRemoveSep(s32) __asm__("AtelEventRemoveSep");
s32 _m2c_AtelEventRemove_func_00138700() __asm__("func_00138700");
s32 _m2c_AtelEventRemove_func_001394E0() __asm__("func_001394E0");
s32 _m2c_AtelEventRemove_func_00139EA0(s32) __asm__("func_00139EA0");
s32 _m2c_AtelEventRemove_func_00145188(s32) __asm__("func_00145188");
s32 _m2c_AtelEventRemove_func_00145938() __asm__("func_00145938");
s32 _m2c_AtelEventRemove_func_0014D4B0() __asm__("func_0014D4B0");
s32 _m2c_AtelEventRemove_func_0014DAC0(s32) __asm__("func_0014DAC0");
s32 _m2c_AtelEventRemove_func_0014DDB8() __asm__("func_0014DDB8");
s32 _m2c_AtelEventRemove_op_event_effect_free() __asm__("op_event_effect_free");
void AtelEventRemove(void) {
    if (_m2c_AtelEventRemove_func_00145188(0) != 0) {
        func_0014CB20();
        AtelClearPauseFlag();
        _m2c_AtelEventRemove_op_event_effect_free();
        SndSepLock(1);
        SndStopStream();
        func_002D3FF0(0);
        func_002D6630();
        func_002D3FF0(0);
        func_002D6630();
        _m2c_AtelEventRemove_MsBattleExeClear();
        _m2c_AtelEventRemove_func_00138700();
        func_0014AF68(-1);
        AtelRegistAlbhedDic(0, 0);
        AtelSetEncountBattleEndStatus(0, 0, 0);
        _m2c_AtelEventRemove_func_00145938();
        func_0014B150(-1, -1, -1, -1);
        func_0019CE30(0);
        _m2c_AtelEventRemove_func_0014D4B0();
        _m2c_AtelEventRemove_func_00144D48(0);
        func_00138C78(0);
        SndMusicStop(0x8AU);
        SndMusicClear(0x8AU);
        func_0014D7D0(0);
        func_001487B0();
        func_0014DC48();
        MsEventEffectFree();
        func_0014AEA0();
        SndEventClearPcToActorFoot();
        _m2c_AtelEventRemove_AtelActorRemove();
        MsBattleDisposeAtEvent();
        _m2c_AtelEventRemove_AtelClearSnd3dWorkAll();
        _m2c_AtelEventRemove_func_00136430(0.0f);
        func_00136440(0.0f);
        SndRemoveFootSepWork();
        SndClearFootStatus();
        _m2c_AtelEventRemove_AtelEventRemoveSep(1);
        _m2c_AtelEventRemove_func_00139EA0(0);
        func_002D7C28(-2);
        func_00145148(0);
    }
    _m2c_AtelEventRemove_func_001394E0();
    func_0014D9F8(0);
    _m2c_AtelEventRemove_func_0014DAC0(0);
    func_002D67F8(0);
    _m2c_AtelEventRemove_func_0014DDB8();
    movie_stop_prog();
    func_0014BF60();
}

void func_0014F0D0(void)
{
    int i;

    for (i = 0; i < 2; i++) {
        D_0030BDD0[i] = 0;
        D_0030BDD8[i] = 0;
        D_0030BDE0[i] = 0;
    }
    if (TkIsDebug()) {
        func_20592B0();
    }
}

void AtelClearMenuOtakaraFlag(void)
{
    D_0058F933 = 0;
}

void func_0014F148(void)
{
    D_0058F933 = 1;
}

s8 func_0014F158(void)
{
    return D_0058F933;
}

void func_0014F168(void)
{
    if (D_0030BDCC < 0) {
        D_0030BDCC = (TkCdSize(0x2A, 0) + 0x3FF) / 1024 + 0x1F;
    }
}

char *func_0014F1C0(int id)
{
    char *s;

    if (id >= 15) {
        s = (char *)TkMn2GetCommandName(0x30FF); /* DEBT(CAST): funcs.h declares an int result */
    } else {
        s = (char *)MsGetSaveChrName(id); /* DEBT(CAST): funcs.h declares a Rec14 result */
        if (func_00138240() == 0) {
            func_0014D718((u8 *)s, (u8 *)D_0058F950);
            s = D_0058F950;
        }
    }
    return s;
}

INCLUDE_ASM("build/ee_asm/game/atel/atel_14D940", func_0014F228);

int func_0014F380(int a, int b)
{
    return MsSetSaveCommand(a, (b & 0xFFF) | 0x3000);
}

u16 AtelGetItemMapX(void)
{
    return func_00124828()->xB4;
}

u16 AtelGetItemMapY(void)
{
    return func_00124828()->xB6;
}
