/* tu_339 0x2d5b90-0x2d6808: low; ~Snd (config/tu_map.tsv) */
/* DEBT(NAME): module and names guessed: event flag pairs (cur,pend) (see w10.h). */
#define SndSeqIopCommandSendMain _hdr_SndSeqIopCommandSendMain
#define func_002D6030 _hdr_func_002D6030
#include "common.h"
#include "ffx/r7.h"
#include "ffx/q7.h"
#include "ffx/w10.h"
#undef func_002D6030
#undef SndSeqIopCommandSendMain

s32 func_002D5B90(void) {
    return D_0078BA20;
}

s32 func_002D5BA0(void)
{
    float v = (float)D_0078BA20;

    if (func_002D9868() == 0) {
        return 0;
    }
    if (v < 0.0f) {
        return 0;
    }
    v = v * 2048.0f;
    v = v - 32.0f;
    v = v / 48000.0f;
    v = v * 16.0f / 28.0f;
    v = v * 2016.0f / 2048.0f;
    v = v * 4.9699993f;
    return (s32)v;
}

char *func_002D5C70(void) {
    if (D_0078BBA4 > 0) {
        D_0078BBA4--;
    } else {
        D_0078BBA4 = 0;
        D_0078BBB0[0] = 0;
    }
    return D_0078BBB0;
}

char *func_002D5CA0(void) {
    return D_0078BBD0;
}

void func_002D5CB0(char *s) {
    s32 c;

    for (; (c = *s) != 0; s++) {
        if (c >= 'a' && c <= 'z') {
            c &= 0xDF;
            *s = c;
        }
    }
}

void func_002D5CE8(void) {
    D_0078BBA0 = 0;
}

u8 func_002D5CF8(void) {
    return D_0078BBA0;
}

u8 func_002D5D08(void) {
    return D_0078BBA1;
}

void SndSepLock(s32 on) {
    D_0078BB9D = on != 0;
}

extern s8 _m2c_SndSeqIopCommandSendMain_D_005661F4 __asm__("D_005661F4");
s32 _m2c_SndSeqIopCommandSendMain_SqsIopCommandSend() __asm__("SqsIopCommandSend");
s32 _m2c_SndSeqIopCommandSendMain_TkCdReadSync(s32) __asm__("TkCdReadSync");
s32 _m2c_SndSeqIopCommandSendMain_TkRefreshHDDMode() __asm__("TkRefreshHDDMode");
s32 _m2c_SndSeqIopCommandSendMain_func_00165EE8(s32) __asm__("func_00165EE8");
s32 _m2c_SndSeqIopCommandSendMain_func_002D88B8() __asm__("func_002D88B8");
extern u8 _m2c_SndSeqIopCommandSendMain_D_0078BBA3 __asm__("D_0078BBA3");
void SndSeqIopCommandSendMain(void) {
    _m2c_SndSeqIopCommandSendMain_SqsIopCommandSend();
    if ((_m2c_SndSeqIopCommandSendMain_D_0078BBA3 == 0) && (_m2c_SndSeqIopCommandSendMain_D_005661F4 != 0) && (_m2c_SndSeqIopCommandSendMain_func_002D88B8() != 0) && (_m2c_SndSeqIopCommandSendMain_TkCdReadSync(1) == 0)) {
        _m2c_SndSeqIopCommandSendMain_D_005661F4 = 0;
        _m2c_SndSeqIopCommandSendMain_D_0078BBA3 = 1;
        _m2c_SndSeqIopCommandSendMain_TkRefreshHDDMode();
        _m2c_SndSeqIopCommandSendMain_func_00165EE8(1);
    }
}

void func_002D5DB8(void) {
    SndSeqIopCommandSendMain();
    D_0078BB90.cur = D_0078BB90.pend;
    D_0078BB80.cur = D_0078BB80.pend;
    D_0078BB70.cur = D_0078BB70.pend;
    D_0078BB90.pend = 0;
    D_0078BB80.pend = 0;
    D_0078BB70.pend = 0;
}

s32 func_002D5E10(void) {
    D_0078BB80.pend |= func_002538B0(0);
    return D_0078BB80.cur | D_0078BB80.pend;
}

s32 func_002D5E48(int v) {
    return func_002524B8();
}

s32 func_002D5E68(void) {
    return func_00252AE8();
}

s32 func_002D5E88(void) {
    return D_0078BA18;
}

s32 func_002D5E98(void) {
    return D_0078BA1C;
}

s32 func_002D5EA8(s32 wait) {
    s32 v;

    for (;;) {
        D_0078BB70.pend |= func_002518C8(0);
        v = D_0078BB70.cur | D_0078BB70.pend;
        if (!(wait && v)) {
            break;
        }
        func_002D3FF0(0);
        func_002D5DB8();
    }
    return v;
}

void func_002D5F18(void) {
}

s32 func_002D5F20(void) {
    D_0078BB90.pend |= iVoicePlayStatus(0);
    return D_0078BB90.cur | D_0078BB90.pend;
}

void func_002D5F58(int a) {
    func_00253050(a);
    D_0078BB70.pend |= 1;
    D_0078BA1C |= D_0078BB70.pend;
}

void SndSetSoundMode(s32 mode) {
    mode = (mode < 0) ? 0 : (mode < 3 ? mode : 2);
    func_00251AD0(mode);
    D_0078BB9E = mode;
}

u8 func_002D5FE8(void) {
    return D_0078BB9E;
}

void func_002D5FF8(s32 mode) {
    mode = (mode < 0) ? 0 : (mode < 2 ? mode : 1);
    D_0078BB9F = mode;
}

u8 func_002D6020(void) {
    return D_0078BB9F;
}

void func_002D6030() {
    D_0078BB9C = 0;
}

void func_002D6040(void) {
    s32 i;

    D_0078BB68 = 0;
    for (i = 0; i < 17; i++) {
        D_0078BAE0[i].val = 0;
        D_0078BAE0[i].id = 0;
    }
}

void func_002D6080(s32 id, s32 val) {
    W10Cmd *e = &D_0078BAE0[D_0078BB68];

    D_0078BB68++;
    e->id = id;
    e->val = val + 2;
}

void func_002D60B0(int arg, int value)
{
    int index = D_0078BB68;
    W10Cmd *entry = &D_0078BAE0[index];

    value += 2;
    /* DEBT(ORDER): independent command writes retain original scheduling. */
    D_0078BAE0[index].arg = arg;
    entry->id = -1;
    entry->val = value;
    D_0078BB68 = index + 1;
}

INCLUDE_ASM("build/ee_asm/game/snd/snd_2D5B90", func_002D60F0);

void func_002D6260(s32 a) {
    func_002D60F0(0, a);
}

void func_002D6270(s32 a) {
    func_002D60F0(-1, a);
}

void func_002D6280(void) {
    s32 i;

    for (i = 0; i < 1; i++) {
        D_0078BAD8[i] = -1;
    }
}

void func_002D62B8(s32 a) {
    s32 i;

    for (i = 0; i < 1; i++) {
        if (D_0078BAD8[i] == a) {
            D_0078BAD8[i] = -1;
        }
    }
}

s32 SndGetNowPlayMusic(void) {
    return D_0078BAD8[0];
}

void func_002D62F8(s32 a) {
    s32 slot = -1;
    s32 i;

    for (i = 0; i < 1; i++) {
        if (D_0078BAD8[i] < 0) {
            slot = i;
        }
        if (a == D_0078BAD8[i]) {
            return;
        }
    }
    if (slot < 0) {
        slot = 0;
    }
    D_0078BAD8[slot] = a;
}

void SndEventClearPcToActorFoot(void) {
    s32 i;

    for (i = 0; i < 16; i++) {
        D_0078BA98[i] = -1;
    }
}

void SndEventSetPcToActorFoot(s32 i, s32 v) {
    if (i < 16) {
        D_0078BA98[i] = v;
    }
}

s32 SsSetProjectBase(const char *a) {
    return SqsSetProjectBase(a);
}

void func_002D63D8(int a) {
    func_00253E40(a);
}

extern char D_00576050[];
extern int D_0078BA54;

s32 func_002D63E0(void)
{
    s32 r = func_00253E98(D_00576479);
    s32 i;

    func_002D6030(0);
    SndSetSoundMode(0);
    func_002D5FF8(1);
    D_0078BA20 = 0;
    SsSetProjectBase(D_00576050);
    func_00253E40(0);
    _m2c_SndSeqIopCommandSendMain_D_0078BBA3 = 0;
    D_0078BBB0[0] = 0;
    D_0078BBD0[0] = 0;
    D_0078BA54 = 0;
    for (i = 15; i >= 0; i--) {
        D_0078BA58[i] = 0;
    }
    SndSepLock(0);
    return r;
}

void func_002D64A0(s32 v) {
    D_0078BA4C = v;
}

void SndEventSetSoundEvent(u32 *v) {
    D_0078BA50 = v;
}

s32 func_002D64C0(void) {
    return D_0078BA10;
}

s32 SndIsReadShoutVoiceStatus(void) {
    return D_0078BA0C;
}

s32 _m2c_func_002D64E0_func_002518C8() __asm__("func_002518C8");
s32 func_002D64E0(void) {
    s32 v = _m2c_func_002D64E0_func_002518C8();

    D_0078BA1C |= v;
    D_0078BB70.pend |= v;
    return v;
}

void func_002D6528(void)
{
    s32 s2 = func_002D5F20();
    s32 s0 = func_002D5E10();

    D_0078BA1C |= func_002D5EA8(0);
    D_0078BA0C |= s0;
    D_0078BA10 |= s2;
    D_0078BA08 |= D_0078BA10 | D_0078BA0C;
    D_0078BA18 |= SqsDataSendingCompleted(0);
}

void TkSndUpdateMain(void) {
    if (TkGetSoundSyncVFlag()) {
        func_002D5DB8();
        D_0078BA1C = 0;
        D_0078BA0C = 0;
        D_0078BA10 = 0;
        D_0078BA08 = 0;
        D_0078BA18 = 0;
        func_002D6528();
        TkClearSoundSyncVFlag();
    }
}

void func_002D6630(void) {
    func_002D60F0(1, 0);
    TkSndUpdateMain();
}

void TkSndUpdate2(void) {
    if (TkGetSoundSyncVFlag()) {
        func_002D60F0(1, 0);
        func_002D6630();
    }
}

s32 func_002D6688(s32 a) {
    s32 cur = func_002D3E30();

    if (a == 0) {
        return cur;
    }
    if (a == cur) {
        return cur;
    }
    func_002D3D88();
    TkSndUpdateMain();
    return cur;
}

s32 func_002D66D8(void) {
    s32 x = D_0078BA1C | D_0078BA18;
    s32 y = D_0078BA14 | D_0078BA08;
    s32 r = (x | y) != 0;

    TkSndUpdateMain();
    return r;
}

int func_002D6730(void)
{
    return ((D_0078BA1C | D_0078BA18) | (D_0078BA14 | D_0078BA08)) != 0;
}

s32 func_002D6768(void) {
    return func_002D6730();
}

s32 func_002D6788(void) {
    return func_002D66D8();
}

s32 TkSndReportStatus(void) {
    return D_0078BA1C != 0;
}

s32 TkSndIsReadVoice(void) {
    return D_0078BA08 != 0;
}

s32 func_002D67C8(void) {
    return D_0078BA0C != 0;
}

s32 func_002D67D8(void) {
    return D_0078BA10 != 0;
}

s32 TkSndIsStandbyVoice(void) {
    return D_0078BA14 != 0;
}

void func_002D67F8(s32 v) {
    D_0078BA14 = v;
}
