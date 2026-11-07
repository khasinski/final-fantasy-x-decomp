/* tu_207 0x1df1c0-0x1dfc50: low; ~Ms (config/tu_map.tsv) */
#define MsSEPtransRegist _hdr_MsSEPtransRegist
#include "common.h"
#include "ffx/q4.h"
#include "ffx/r3.h"
#include "ffx/u2.h"
#include "ffx/v3.h"
#undef MsSEPtransRegist

void func_001DF1C0(void) {
    int i;
    D_00662EE0 = 0;
    D_00662EE4 = 0;
    D_00662EE8 = 0;
    for (i = 127; i >= 0; i--) {
        D_003172F0.w175C[i] = 0;
    }
    D_003172F0.f1759 = 0;
    D_003172F0.f175A = 0;
}

int MsSEPtransCheck(void) {
    return D_00662EE4 != 0 ? -1 : 0;
}

int MsSEPtransCheckWave(void) {
    int r = 0;
    if (D_00662EE4 > 0) {
        Q4Ent12 *e = &D_00662E20[D_00662EE0];
        r = 2;
        if (e->f8 == 0) {
            r = 1;
        }
    }
    return r;
}

/* DEBT(CAST) */
void MsSEPtransRegist(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    Q4Ent12 *temp_3_2;
    s32 temp_3;

    while (D_00662EE4 >= 0x10) {
        MsSEPtransProcess();
    }
    temp_3 = D_00662EE0 + D_00662EE4;
    D_00662EE4 += 1;
    temp_3_2 = &D_00662E20[temp_3 % 16];
    (*(s32 *)((u8 *)(temp_3_2) + (0))) = arg1;
    (*(s32 *)((u8 *)(temp_3_2) + (4))) = arg2;
    temp_3_2->pad9[0] = arg0;
    temp_3_2->f8 = arg3;
    temp_3_2->pad9[1] = 0;
}

INCLUDE_ASM("build/ee_asm/game/battle/ms_1DF1C0", MsSEPtransProcess);

INCLUDE_ASM("build/ee_asm/game/battle/ms_1DF1C0", MsRegistSEdata);

void MsSEPbattleClear(void)
{
    int i;

    for (i = 0; i < 128; i++) {
        if (D_003172F0.w175C[i] != 0) {
            SndSepClear(D_003172F0.w175C[i]);
            D_003172F0.w175C[i] = 0;
        }
    }
    D_003172F0.f1759 = 0;
}

void MsSEPchrClear(BtlChr *c, int clr) {
    int me;
    int i;
    int j;
    int k;
    s32 h;
    BtlChr *d;

    if (clr) {
        me = c->f0C;
        for (i = 0; i < 32; i++) {
            h = c->fB6C[i];
            if (h == 0) {
                continue;
            }
            for (j = 0; j < 31; j++) {
                if (j == me) {
                    continue;
                }
                d = MsGetChr(j);
                for (k = 0; k < 32; k++) {
                    if (h == d->fB6C[k]) {
                        goto found; /* DEBT(GOTO): leaves both search loops */
                    }
                }
            }
            continue;
        found:
            c->fB6C[i] = 0;
        }
    }
    for (i = 0; i < 32; i++) {
        h = c->fB6C[i];
        if (h != 0) {
            SndSepClear(h);
            c->fB6C[i] = 0;
        }
    }
    c->fBEC = 0;
}

void func_001DF8E0(void)
{
    int i;

    MsSEPbattleClear();
    for (i = 0; i < 31; i++) {
        MsSEPchrClear(MsGetChr(i), 0);
    }
}

void func_001DF928(void)
{
    int i;

    MsSEPbattleClear();
    for (i = 0; i < 18; i++) {
        MsSEPchrClear(MsGetChr(i), 0);
    }
}

int func_001DF970(int a, int b) {
    if (SndIsReadShoutVoiceStatus() != 0) return -1;
    if ((u32)a < 8 && (u32)b < 8) {
        u8 v = *(D_0031FF50[a] + b);
        if (v != 0xFF) {
            SndStartShoutStream(v, 0x3F, 0x7F);
            return 0;
        }
    } else {
        if (a >= 0) return -1;
        SndStartShoutStream(b, 0x3F, 0x7F);
    }
    return 0;
}

int MsSetVoice(int id, int a, int b, int c, int d) {
    int k2 = 0x4D;
    int r = 0;

    if (MsGetRamChrMonster(id)) {
        k2 = 0x4E;
    }
    MsGetChr(id);
    if (a >= 0) {
        MsAtelRequestInit();
        id += 0x4F;
        MsAtelRequestAdd(2, 1, id, a);
        MsAtelRequestAdd(2, 1, k2, a);
        MsAtelRequestAdd(2, 0, id, a);
        MsAtelRequestAdd(2, 0, k2, a);
        if (MsAtelRequestExe(2, 0, id, b, c, d) >= 0) {
            r = 1;
        }
    }
    return r;
}

int MsSetVoiceCheck(int id, int n, int a, int b, int c) {
    int r = 0;
    MsGetChr(id);
    if (n >= 0) {
        MsAtelRequestInit();
        id += 0x6D;
        MsAtelRequestAdd(2, 1, id, n);
        if (MsGetVoiceEventFlag() != 0) {
            MsAtelRequestAdd(2, 0, id, n);
        }
        if (MsAtelRequestExe(2, 0, id, a, b, c) >= 0) r = 1;
    }
    return r;
}

s32 MsSEPtransAmount(void) {
    return D_00662EE4;
}

void MsMusicReadStart(int a)
{
    int h;

    MsSEPbattleClear();
    MsEffectSepClearAll();
    h = SndGetNowPlayMusic();
    SndMusicStop(h);
    SndMusicClear(h);
    SndMusicRead(a);
}
