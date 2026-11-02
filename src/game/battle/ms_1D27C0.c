/* tu_200 0x1d27c0-0x1d48d0: low; ~Ms (config/tu_map.tsv) */
#include "common.h"
#include "ffx/s3.h"
#include "ffx/q4.h"
#include "ffx/r3.h"
#include "ffx/u2.h"
#include "ffx/v3.h"
#include "ffx/s2.h"

int MsCheckStartEffect(int id, int mask) {
    int n = 0;
    int i;
    for (i = 0; i < 0x1F; i++) {
        if ((mask >> i) & 1) {
            BtlChr *c = MsGetChr(i);
            if ((id != i && c->f1C8 != 0) || c->fF6 != 0) {
                D_003172F0.f2138 = id;
                n++;
                D_003172F0.f2139 = 0xFF;
            }
        }
    }
    return n;
}

s32 func_001D2878(s32 arg0, s32 arg1, float *arg2, float *arg3, float *arg4)
{
    float value;
    BtlChr *chr;
    s32 result;
    s32 resource;

    chr = MsGetChr(arg0);
    resource = func_001CEB28(chr->fA80);
    result = msCheckSameTarget(arg0, chr, resource);
    MsGetChrInfo(arg1, resource, 0, arg2);
    MsGetChrInfo(4, resource, 0, &value);
    if (arg3 != 0)
    {
        *arg3 = value;
    }
    MsGetChrInfo(3, resource, 0, &value);
    if (arg4 != 0)
    {
        *arg4 = value;
    }
    return result;
}

INCLUDE_ASM("build/ee_asm/game/battle/ms_1D27C0", func_001D2958);

INCLUDE_ASM("build/ee_asm/game/battle/ms_1D27C0", MsGetDirMode);
INCLUDE_RODATA("build/ee_asm/game/battle/ms_1D27C0/rodata", jtbl_0056EAC0);

INCLUDE_ASM("build/ee_asm/game/battle/ms_1D27C0", func_001D3350);

void MsResetDirMove(BtlChr *c)
{
    c->fEE = 0;
    c->fEB = 0;
    c->fEC = 0;
}

void func_001D3480(u8 id)
{
    func_001D34A0(MsGetChr(id));
}

void func_001D34A0(BtlChr *c)
{
    c->fD5 = 0;
    c->fD7 = 0;
    c->fD8 = 0;
}

INCLUDE_ASM("build/ee_asm/game/battle/ms_1D27C0", func_001D34B0);

/* DEBT(CAST): signed/width views follow the existing shared interfaces. */
s32 MsSetMotion(s32 a, s32 b, s32 c, s32 d, s32 e, Actor *f, s32 *g)
{
    s32 result;
    s32 saved_state;
    BtlChr *chr;
    s32 event;
    s32 status;
    s8 saved_flag;

    chr = MsGetChr(a);
    result = 0;
    if (b >= 0)
    {
        saved_state = (s32) chr->f1CD;
        saved_flag = (s8) chr->f108;
        chr->fBB = chr->fBA;
        chr->f1CD = 0;
        chr->f108 = 0;
        chr->fE9 = 0;
        if (chr->fD4 != 0)
        {
            chr->f5C = -1;
        }
        if (c != 0)
        {
            chr->fAB2 = (u8) d;
            chr->fF2 = 1;
        }
        if (MsGetRamChrMonster(a) != 0)
        {
            MsAtelRequestInit();
            if ((s8) chr->f39 == 1)
            {
                MsAtelRequestAdd(3, a, 0x40, b);
                MsAtelRequestAdd(2, 1, 4, b);
                MsAtelRequestAdd(3, a, 4, b);
                MsAtelRequestAdd(2, 0, 4, b);
            }
            else
            {
                MsAtelRequestAdd(3, a, 0x40, b);
                MsAtelRequestAdd(2, 1, 3, b);
                MsAtelRequestAdd(3, a, 4, b);
                MsAtelRequestAdd(2, 0, 3, b);
            }
            status = MsAtelRequestExe(2, 0, a + 5, e, (s32) f, (s32) g);
        }
        else
        {
            event = a + 5;
            MsAtelRequestInit();
            MsAtelRequestAdd(2, 1, event, b);
            MsAtelRequestAdd(2, 1, 3, b);
            MsAtelRequestAdd(2, 0, event, b);
            MsAtelRequestAdd(2, 0, 3, b);
            status = MsAtelRequestExe(2, 0, event, e, (s32) f, (s32) g);
        }
        if (status < 0)
        {
            chr->f108 = (u8) saved_flag;
            chr->f1CD = (s8) saved_state;
            if (c != 0)
            {
                chr->fAB2 = 0;
                MsTerminateMotion(chr);
            }
        }
        else
        {
            result = 1;
            if (c == 0)
            {
                chr->fF2 = 0;
            }
        }
    }
    return result;
}

u8 MsGetMotionNum(u8 id)
{
    return MsGetChr(id)->fB0;
}

void MsSetMotionReturn(int id) {
    MsGetChr(id)->fABB = 7;
}

void MsSetMotionAttackWait(int id) {
    MsGetChr(id)->fABB = 0xF;
}

void MsTerminateMotion(BtlChr *c)
{
    c->fF2 = 0;
    c->fF3 = 0;
    c->fFE = 0;
    c->fC4 = 0;
    c->fC5 = 0;
    if (c->fABB == 2) {
        c->fABB = 3;
    }
}

float func_001D3B10(int id, int v)
{
    float position[4];
    float target[4];
    float radius;
    float distance;
    float result;
    MsGetChr(id);
    result = 0.0f;
    func_001B6790(id, position);
    if (func_001D2878(id, v, target, &radius, 0)) {
        func_001AC3E8(position, position, target);
        distance = func_001AC2D0(position);
        result = distance - (radius + MsGetChrWidth(id));
    }
    return result;
}

INCLUDE_ASM("build/ee_asm/game/battle/ms_1D27C0", MsGetMoveTargetPos);
INCLUDE_RODATA("build/ee_asm/game/battle/ms_1D27C0/rodata", jtbl_0056EB20);

INCLUDE_ASM("build/ee_asm/game/battle/ms_1D27C0", MsGetMoveTargetDist);

INCLUDE_ASM("build/ee_asm/game/battle/ms_1D27C0", MsGetEscapeDir);

INCLUDE_ASM("build/ee_asm/game/battle/ms_1D27C0", MsGetSummonDir);

INCLUDE_ASM("build/ee_asm/game/battle/ms_1D27C0", MsSetMove);

void MsMoveSplineSet(u32 i) {
    if (i < 3) {
        D_00662660[i] = 0;
    }
}

INCLUDE_ASM("build/ee_asm/game/battle/ms_1D27C0", MsMoveSplineRegist);

/* DEBT(CAST): signed/width views follow the existing shared interfaces. */
void MsMoveSpline(s32 a, s32 b, s32 c, float f, s32 d)
{
    BtlChr *chr;
    float value;
    s32 count;

    value = f;
    if ((u32) a < 3U)
    {
        count = D_00662660[a];
        if (count > 0)
        {
            D_00662670[a].count = count;
            chr = MsGetChr(b);
            chr->fD5 = 7;
            chr->f11A = (u16) c;
            chr->f114 = (s16) a;
            chr->fD7 = 0;
            chr->f112 = 0;
            if (chr->fDB != 0)
            {
                value = 0.0f;
            }
            chr->f12C = value;
            chr->fEA = (u8) d;
            func_001B6E48(b, chr->f150);
        }
    }
}

int func_001D4578(int id) {
    return MsGetChr(id)->fD5 != 0;
}

void MsSetChrHeight(int id) {
    BtlChr *c = MsGetChr(id);
    switch (c->f1CC) {
    case 0:
        c->f1F4 = D_00318808 - MsGetChrHeight(id) * 0.5f + c->f1F8;
        break;
    case 1:
        c->f1F4 = 0;
        break;
    }
}

INCLUDE_ASM("build/ee_asm/game/battle/ms_1D27C0", MsGetChrPredictPos);

int MsGetChrMoveFrameRest(int id) {
    BtlChr *c = MsGetChr(id);
    float pos[3];
    float tmp[3];
    int r;
    int k;
    func_001B6790(id, pos);
    k = c->fD5 & 0x7F;
    r = 0;
    if (k != 7) {
        if (k != 0) {
            MsGetMoveTargetPos(id, c, c->fD5, tmp, 0);
            if (c->fD5 & 0x80) {
                r = (int)(func_001AC388(pos, tmp) / c->f124);
            } else {
                r = c->f11A - c->f112;
            }
        }
    } else {
        r = c->f11A - c->f112;
    }
    return r;
}

u8 *func_001D48C0(void) {
    return D_00662CA0;
}
