/* tu_181 0x1b15c8-0x1b3388: medium; ~Ms (config/tu_map.tsv) */
#include "common.h"
#include "ffx/r2.h"
#include "ffx/q4.h"
#include "ffx/s2.h"
#include "ffx/t2.h"
#include "ffx/u2.h"
#include "ffx/v2.h"

void MsAtelRegistInit(void) {
    int i;

    for (i = 0; i < 2; i++) {
        D_0065FF88[i].count = 0;
        D_0065FF88[i].w4 = 0;
        D_0065FF88[i].w8 = 0;
        D_0065FF88[i].wC = 0;
        D_0065FF88[i].w10 = 0;
    }
    MsStructClear(D_00660088, 0x1000);
    MsStructClear(D_00661088, 0x800);
    MsAtelRequestInit();
}

void MsAtelRegistFree(void) {
    int i;

    for (i = 0; i < 2; i++) {
        if (D_0065FF88[i].w4) {
            func_0011D590((s32)D_0065FF88[i].w4, 5); /* DEBT(TYPE): funcs.h takes the handle as s32 */
        }
        if (D_0065FF88[i].wC) {
            func_0011D590((s32)D_0065FF88[i].wC, 5); /* DEBT(TYPE) */
        }
    }
    MsAtelCamFree();
    AtelCtrlRemove(2);
    AtelCtrlRemove(3);
    MsAtelRegistInit();
}

int MsAtelRegist(int a, int b, int c) {
    int n = D_0065FF88[a].count;

    if (n < 8) {
        D_0065FF88[a].count = n + 1;
        D_0065FF88[a].a34[n] = 0;
        D_0065FF88[a].a14[n] = (void *)c; /* DEBT(TYPE): s2.h passes it as int */
        return 0;
    }
    return -1;
}

void func_001B1700(int n) {
    int i;
    int kind;
    void (*cb)(void);
    int work;
    int local;

    for (i = 0; i < D_0065FF88[n].count; i++) {
        D_0065FF88[n].w8 += AtelGetActorBufferSize(D_0065FF88[n].a14[i]);
        D_0065FF88[n].w10 += func_00144810(D_0065FF88[n].a14[i]);
    }
    if (n != 2) {
        D_0065FF88[n].w4 = user_malloc(D_0065FF88[n].w8, 5, D_0056E2A0, -1);
        D_0065FF88[n].wC = user_malloc(D_0065FF88[n].w10, 5, D_0056E2B0, -1);
    } else {
        D_0065FF88[2].w4 = D_00661088;
        work = (D_0065FF88[2].w8 + 15) / 16 * 16;
        D_0065FF88[2].wC = D_00661088 + work;
        local = (D_0065FF88[2].w10 + 15) / 16 * 16;
        if (work + local > 0x800) {
            MsBattleError(D_0056E2C0);
        }
    }
    kind = 0;
    cb = 0;
    switch (n) {
    case 0:
        kind = 2;
        cb = func_001B1960;
        break;
    case 1:
        kind = 3;
        cb = func_001B1A18;
        break;
    case 2:
        kind = 4;
        cb = func_001B1AC0;
        break;
    }
    if (cb) {
        AtelBattleSetUp(D_0065FF88[n].a14, D_0065FF88[n].a34, D_0065FF88[n].count, D_00660088, D_0065FF88[n].wC, D_0065FF88[n].w4, kind, cb);
    }
}

void func_001B1960(void) {
    int i;
    int n = R2_CALL0(AtelGetCtrlworkActorTotal);
    for (i = 0; i < n; i++) {
        AtelDecodeSignal(i, -1);
    }
    for (i = 0; i < n; i++) {
        AtelDecodeCommand(i, 0);
    }
    MsMotionProcess();
    MsBattleSpecial();
    for (i = 0; i < n; i++) {
        AtelDecodeSignal(i, -1);
    }
}

void func_001B1A18(void) {
    int i;
    int n = R2_CALL0(AtelGetCtrlworkActorTotal);
    for (i = 0; i < n; i++) {
        AtelDecodeSignal(i, -1);
    }
    for (i = 0; i < n; i++) {
        AtelDecodeCommand(i, 0);
    }
    for (i = 0; i < n; i++) {
        AtelDecodeSignal(i, -1);
    }
}

void func_001B1AC0(void) {
    int i;
    int n = R2_CALL0(AtelGetCtrlworkActorTotal);
    for (i = 0; i < n; i++) {
        AtelDecodeSignal(i, -1);
    }
    for (i = 0; i < n; i++) {
        AtelDecodeCommand(i, 0);
    }
    for (i = 0; i < n; i++) {
        AtelDecodeSignal(i, -1);
    }
}

void MsAtelRequestInit(void) {
    D_00661888 = 0;
}

void MsAtelRequestAdd(int a, int b, int c, int d) {
    int n = D_00661888;
    if (n < 16) {
        D_00661890[n].h0 = a;
        D_00661890[n].h2 = b;
        D_00661890[n].h4 = c;
        D_00661890[n].h6 = d;
        D_00661888 = n + 1;
    }
}

INCLUDE_ASM("build/ee_asm/game/battle/ms_1B15C8", func_001B1BD8);

INCLUDE_ASM("build/ee_asm/game/battle/ms_1B15C8", func_001B1C70);

INCLUDE_ASM("build/ee_asm/game/battle/ms_1B15C8", MsAtelRequestExe);

INCLUDE_ASM("build/ee_asm/game/battle/ms_1B15C8", MsAtelParseSysTag);

int MsAtelGetSysReq(int a, int b, int c) {
    int r = -1;
    int save = AtelChangeCurrentCtrl(a);
    int off;
    u8 *p = func_001B1C70(a, b, c, &off);

    if (p) {
        if (AtelGetRequestLevel(*p + off) == 7) {
            r = 0;
        }
    }
    AtelSetCurrentCtrl(save);
    return r;
}

u8 *MsAtelGetID(int a, int b, int c) {
    u8 *r = 0;
    int save = AtelChangeCurrentCtrl(a);
    int off;
    u8 *p = func_001B1C70(a, b, c, &off);

    if (p) {
        r = AtelGetBattleIdAdrs(*p + off);
    }
    AtelSetCurrentCtrl(save);
    return r;
}

int func_001B2330(int a, int b, int c, int v) {
    int off;
    u8 *p = func_001B1C70(a, b, c, &off);

    if (p) {
        *AtelGetBattleIdAdrs(*p + off) = v;
        return 1;
    }
    return 0;
}

INCLUDE_ASM("build/ee_asm/game/battle/ms_1B15C8", MsAtelChrInit);

void AtelGetEventActorPos(u8 id, int kind, float *out) {
    float v[3];

    switch (kind) {
    case 1:
    case 8:
    case 9:
        func_00142FF0(id, &v[0], &v[1], &v[2]);
        break;
    case 2:
        v[0] = S2_func_0013B7B8(id);
        break;
    case 7:
        v[0] = S2_func_0013B7B8(id) + 3.14159274f;
        break;
    case 3:
    case 10:
        v[0] = 18.0f;
        break;
    case 4:
    case 11:
        v[0] = 10.0f;
        break;
    }
    if (out) {
        out[0] += v[0];
        out[1] += v[1];
        out[2] += v[2];
    }
}

INCLUDE_ASM("build/ee_asm/game/battle/ms_1B15C8", MsAtelChrInfo);

void func_001B2940(void) {
    int h;

    Sg_Blur(0);
    h = AtelChangeCurrentCtrl(2);
    func_001B3160(2, 1, 0x3E, 0);
    func_001B3160(2, 0, 0, 0);
    func_001B3160(2, 0, 1, 0);
    func_001B3160(2, 0, 2, 0);
    AtelSetCurrentCtrl(h);
}

INCLUDE_ASM("build/ee_asm/game/battle/ms_1B15C8", MsAtelRequestCamera);

INCLUDE_ASM("build/ee_asm/game/battle/ms_1B15C8", MsAtelRequestMagicCamera);

/* DEBT(FAKE) */
s32 MsGetVoiceEventFlag(void) {
    register s32 var_2 __asm__("$2");

    var_2 = 0;
    if (*D_003172F0.h32[1].p1C != 0) {
        var_2 = D_003172F0.f20FE == 0;
    }
    return var_2;
}

INCLUDE_ASM("build/ee_asm/game/battle/ms_1B15C8", func_001B2DF0);

s32 MsAtelRequestSystemCheckExe(s32 arg0, s32 arg1, s32 arg2, s32 arg3)
{
    s32 state0;

    MsAtelRequestInit();
    MsAtelRequestAdd(2, 1, 0x6C, arg0);
    if (MsAtelRequestExe(2, 1, 0x6C, arg1, arg2, arg3) >= 0)
    {
        MsAtelParseSysTag(2, 1, 0x6C);
    }
    if (MsGetVoiceEventFlag() != 0)
    {
        MsAtelRequestInit();
        MsAtelRequestAdd(2, 1, 0x89, arg0);
        MsAtelRequestAdd(2, 0, 0x89, arg0);
        state0 = MsAtelRequestExe(2, 0, 0x89, arg1, arg2, arg3);
        if (state0 >= 0)
        {
            MsAtelParseSysTag(2, 0, 0x89);
        }
    }
    else
    {
        MsAtelRequestInit();
        MsAtelRequestAdd(2, 1, 0x89, arg0);
        state0 = MsAtelRequestExe(2, 1, 0x89, arg1, arg2, arg3);
        if (state0 >= 0)
        {
            MsAtelParseSysTag(2, 1, 0x89);
        }
    }
    return state0;
}

void MsAtelActorWorkInit(int a, int b, int c) {
    int off;
    int save = AtelChangeCurrentCtrl(a);
    u8 *p = func_001B1C70(a, b, c, &off);

    if (p) {
        AtelInitInternalActorWork(*p + off);
    }
    AtelSetCurrentCtrl(save);
}

void func_001B3110(int unused, int a, int b, int c) {
    int off;
    u8 *p = func_001B1C70(a, b, c, &off);

    if (p) {
        MsBindCamera((int)AtelGetBasicWork(*p + off), 2, 0); /* DEBT(CAST): Actor pointer passed as int */
    }
}

void func_001B3160(int a, int b, int c, int v) {
    int off;
    u8 *p = func_001B1C70(a, b, c, &off);
    int *q;

    if (p) {
        q = (int *)func_0013A468((char *)AtelGetBasicWork(*p + off)); /* DEBT(CAST): Actor pointer handed on as the string argument */
        if (*q) {
            MsCameraPriority(*q, v);
        }
    }
}

/* DEBT(TYPE): this caller uses the no-result view of the legacy helper. */
int MsAtelRequestCancel(s32 a, s32 b, s32 c)
{
    int base;
    int result;
    s32 saved;
    u8 *entry;

    result = -1;
    saved = AtelChangeCurrentCtrl(a);
    entry = func_001B1C70(a, b, c, &base);
    if (entry != 0)
    {
        result = 0;
        CALL_AtelSkipReqLevel2_VOID(*entry + base, 0);
        AtelExecReturn2(*entry + base, 0, 0);
        AtelDecodeSignal(*entry + base, -1);
    }
    AtelSetCurrentCtrl(saved);
    return result;
}

int func_001B3278(s32 arg) {
    S2Hdr *o = (S2Hdr *)arg; /* DEBT(CAST): header address passed as s32 */

    if (o != 0) {
        MsAtelActorWorkInit(2, 0, 0);
        MsAtelActorWorkInit(2, 0, 1);
        MsAtelActorWorkInit(2, 0, 2);
        D_00661914 = (s32)o + o->off4;
        D_00661918 = (s32)o + o->off8;
        MsAtelRegist(2, 0, D_00661914);
        func_001B1700(2);
        D_00661910 = -1;
        return -1;
    }
    return 0;
}

INCLUDE_ASM("build/ee_asm/game/battle/ms_1B15C8", MsAtelCamInit);

void MsAtelCamFree(void) {
    if (D_00661910 != 0) {
        MsAtelCamInit();
        AtelCtrlRemove(4);
    }
}
