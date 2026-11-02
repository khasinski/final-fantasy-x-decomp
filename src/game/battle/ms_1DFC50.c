/* tu_208 0x1dfc50-0x1e08f0: low; ~Ms (config/tu_map.tsv) */
#include "common.h"
#include "ffx/q4.h"
#include "ffx/r3.h"
#include "ffx/u2.h"
#include "ffx/v3.h"

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

INCLUDE_ASM("build/ee_asm/game/battle/ms_1DFC50", func_001E0410);

INCLUDE_ASM("build/ee_asm/game/battle/ms_1DFC50", MsSetBallSpline);
