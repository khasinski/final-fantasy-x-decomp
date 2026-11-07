/* tu_208 0x1dfc50-0x1e08f0: low; ~Ms (config/tu_map.tsv) */
#define func_001E0410 _hdr_func_001E0410
#include "common.h"
#include "ffx/q4.h"
#include "ffx/r3.h"
#include "ffx/u2.h"
#include "ffx/v3.h"
#undef func_001E0410

int MsMusicSync(int a)
{
    int h;
    int r;

    if (SndSyncMusicStandby(0) == 0) {
        h = SndGetNowPlayMusic();
        SndMusicStop(h);
        SndMusicClear(h);
        SndMusicReplayPointClear(a);
        SndMusicStart(a);
        r = -1;
    } else {
        r = 0;
    }
    return r;
}

int func_001DFCB8(int a)
{
    SndMusicStop(a);
    SndMusicClear(a);
    return 0;
}

void MsNowMusicStop(void)
{
    int h = SndGetNowPlayMusic();

    SndMusicStop(h);
    SndMusicClear(h);
}

void MsMusicVolume(int a, int b)
{
    func_002D85F0(SndGetNowPlayMusic(), b, a);
}

INCLUDE_ASM("build/ee_asm/game/battle/ms_1DFC50", func_001DFD60);

void MsChrSEfoot(u8 id, int v)
{
    MsGetChr(id)->fCF = v;
}

int func_001DFFA0(int id, int b) {
    u32 r;
    if (MsGetChrTop() != 0) {
        id &= 0xFF;
        r = func_001DFD60(id, b);
        if (r != 0 && D_003172F0.f2010 != r) {
            MsSEP3Dregist(3, id, r, 0, 0);
            D_003172F0.f2010 = r;
            return r;
        }
    }
    return 0;
}

u32 func_001E0030(int id, int b) {
    u32 r;
    if (MsGetChrTop() != 0) {
        id &= 0xFF;
        r = func_001DFD60(id, b);
        if (r != 0) {
            MsSEP3Dregist(3, id, r, 1, 0);
            return r;
        }
    }
    return 0;
}

int func_001E00A0(u8 id, int b)
{
    int r = 0;

    if (MsGetChr(id)->f2D3 == 0) {
        r = func_001DFFA0(id, b);
    }
    return r;
}

INCLUDE_ASM("build/ee_asm/game/battle/ms_1DFC50", MsChrSEplayMotion);

int func_001E0188(u8 id, int unused, int v) {
    u32 h = func_001DFD60(id, unused);
    if (h != 0) {
        MsSEP3DfadeOut(h, v);
        return -1;
    }
    return 0;
}

int MsRegSEplay(int id, u32 key) {
    if (key != 0) {
        key |= 0x80000000;
        id = (u8)id;
        if (D_003172F0.w2014 != key) {
            MsSEP3Dregist(3, id, key, 0, 0);
            D_003172F0.w2014 = key;
            return key;
        }
    }
    return 0;
}

u32 MsRegSEplay2(int id, u32 v) {
    if (v != 0) {
        v |= 0x80000000;
        MsSEP3Dregist(3, id & 0xFF, v, 1, 0);
        return v;
    }
    return 0;
}

int func_001E0290(u8 id, int key)
{
    int r = 0;

    if (MsGetChr(id)->f2D3 == 0) {
        r = MsRegSEplay(id, key);
    }
    return r;
}

int MsRegSEfade(int a, u32 key, int c)
{
    if (key != 0) {
        MsSEP3DfadeOut(key | 0x80000000, c);
        return -1;
    }
    return 0;
}

void func_001E0328(void) {
    int i;
    for (i = 0; i < 8; i++) {
        MsStructClear(&D_00662EF0[i], 0x1C);
    }
}

W5Bits *func_001E0378(int i) {
    if ((u32)i >= 8) {
        return 0;
    }
    return (W5Bits *)&D_00662EF0[i]; /* DEBT(CAST): D_00662EF0 records are W5Bits */
}

void func_001E03A0(int a, int v)
{
    W5Bits *b;

    if ((v >> 12) == 3) {
        v &= 0xFFF;
        b = func_001E0378(a);
        b->bits[v / 16] |= 1 << (v & 0xF);
    }
}

void *_m2c_func_001E0410_MsGetChr() __asm__("MsGetChr");
s32 _m2c_func_001E0410_MsGetChrInfo(s32, s32, s32, s32 *) __asm__("MsGetChrInfo");
s32 _m2c_func_001E0410_func_001B6790(s32, float *) __asm__("func_001B6790");
extern s32 _m2c_func_001E0410_D_00662FD0 __asm__("D_00662FD0");
/* DEBT(CAST) */
void func_001E0410(s32 arg0) {
    u8 sp[0x10];
    float *var_2;
    float *var_3;
    float temp_f0;
    s32 var_4;
    void *temp_17;

    temp_17 = _m2c_func_001E0410_MsGetChr();
    _m2c_func_001E0410_func_001B6790(arg0, sp);
    var_3 = temp_17 + 0x50;
    var_2 = sp;
    var_4 = 2;
    do {
        temp_f0 = *var_2;
        var_4 -= 1;
        var_2 = (float *)((u8 *)var_2 + (4));
        *var_3 = temp_f0;
        var_3 = (float *)((u8 *)var_3 + (4));
    } while (var_4 >= 0);
    _m2c_func_001E0410_MsGetChrInfo(0xD, (*(s32 *)((u8 *)(temp_17) + (0xA80))), 0x10, &_m2c_func_001E0410_D_00662FD0);
}

INCLUDE_ASM("build/ee_asm/game/battle/ms_1DFC50", MsSetBallSpline);
