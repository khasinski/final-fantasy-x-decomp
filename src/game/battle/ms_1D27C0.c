/* tu_200 0x1d27c0-0x1d48d0: low; ~Ms (config/tu_map.tsv) */
#define MsGetMoveTargetPos _hdr_MsGetMoveTargetPos
#define MsNearRag _hdr_MsNearRag
#include "common.h"
#include "ffx/s3.h"
#include "ffx/q4.h"
#include "ffx/r3.h"
#include "ffx/u2.h"
#include "ffx/v3.h"
#include "ffx/s2.h"
#undef MsGetMoveTargetPos
#undef MsNearRag
float MsGetMoveTargetPos(int, BtlChr *, int, float *, int);
float MsNearRag(float, float);

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

typedef struct {
    u8 pad00[0xA0];
    s32 fA0[4];
    u8 padB0[0x26];
    u8 fD6;
    u8 padD7[0x14];
    u8 fEB;
    u8 fEC;
    u8 fED;
    u8 padEE[3];
    u8 fF1;
    u8 padF2[0xC2];
    float f1B4;
    u8 pad1B8[0x19];
    s8 f1D1;
    u8 pad1D2[2];
    float f1D4[2];
    u8 pad1DC[0x8D1];
    s8 fAAD;
} DirChr; /* DEBT(NAME): BtlChr offset view for MsGetDirMode */

extern s8 D_00319408;
extern u8 D_00319400;
extern s32 D_00662CB0;
float func_001D3350(BtlChr *c, float ang);

float MsGetDirMode(int id, DirChr *c, void *pos, int flag, s32 *out_s3, s32 *out_s7)
{
    s32 self_pos[4];
    float ang = 0.0f;
    float add_ang = 0.0f;
    int r;
    int s7;

    r = 0;
    func_001B6790(id, self_pos);
    s7 = 1;
    switch (c->fEB) {
    case 1:
        r = -1;
        ang = c->f1D4[c->f1D1];
        break;
    case 6: {
        DirChr *p = (DirChr *)MsGetChr(D_00319408); /* DEBT(CAST): offset view */
        r = -1;
        ang = p->f1D4[p->f1D1];
        break;
    }
    case 3:
        MsGetChrBtlPos(id, pos);
        r = -1;
        MsVectorRect2Polar(pos, self_pos, &ang, 0, 0);
        break;
    case 9:
        add_ang = 3.1415927f;
        /* fallthrough */
    case 2:
        if (c->fF1 == 0xFF) {
            D_00662CB0 = 4;
            r = func_001D2878(id, 12, pos, 0, 0);
        } else if (id != c->fF1) {
            func_001B6790(c->fF1, pos);
            r = -1;
        }
        if (r == 0) {
            r = -1;
            ang = c->f1D4[c->f1D1];
        } else {
            MsVectorRect2Polar(pos, self_pos, &ang, 0, 0);
        }
        break;
    case 7:
        D_00662CB0 = 4;
        r = func_001D2878(D_00319400, 12, pos, 0, 0);
        MsVectorRect2Polar(pos, self_pos, &ang, 0, 0);
        break;
    case 4:
        func_001B6790(c->fD6, pos);
        r = -1;
        MsVectorRect2Polar(pos, self_pos, &ang, 0, 0);
        break;
    case 10:
        add_ang = 3.1415927f;
        /* fallthrough */
    case 5:
        func_001B6790(c->fAAD, pos);
        r = -1;
        MsVectorRect2Polar(pos, self_pos, &ang, 0, 0);
        break;
    case 13:
        MsGetChrEscapePos(id, pos);
        add_ang = 3.1415927f;
        r = -1;
        MsVectorRect2Polar(pos, self_pos, &ang, 0, 0);
        break;
    case 8:
        r = -1;
        MsVectorRect2Polar(pos, self_pos, &ang, 0, 0);
        break;
    case 11:
        r = -1;
        if (c->fED == 0 && flag != 0) {
            c->fED = 1;
            pos = c->fA0;
            func_001B6790(c->fAAD, pos);
        } else {
            pos = c->fA0;
        }
        MsVectorRect2Polar(pos, self_pos, &ang, 0, 0);
        break;
    case 12:
        ang = c->f1B4;
        r = -1;
        break;
    }

    if (c->fEC != 0) {
        s7 = 0;
        ang = func_001D3350(c, ang);
    }
    ang += add_ang;
    if (out_s3 != 0) {
        *out_s3 = r;
    }
    if (out_s7 != 0) {
        *out_s7 = s7;
    }
    return ang;
}

float func_001D3350(BtlChr *chr, float angle)
{
    float current, delta;
    angle = MsNearRag(chr->f150[0], angle);
    current = chr->f150[0];
    delta = angle - current;
    if (delta >= 0.0) {
        if (chr->f150[1] < -2.094395160675049 && delta > 2.094395160675049) {
            angle = current + delta - 6.2831854820251465f;
        }
    } else {
        if (chr->f150[1] > 2.094395160675049 && delta < -2.094395160675049) {
            angle = current + delta + 6.2831854820251465f;
        }
    }
    return angle;
}

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

float MsGetMoveTargetDist(int id, int v, int flag) {
    float pos1[4];
    float pos2[4];
    BtlChr *c = MsGetChr(id);
    float d = MsGetMoveTargetPos(id, c, v, pos2, 0);

    func_001B6790(id, pos1);
    func_001AC3E8(pos1, pos1, pos2);
    if (flag != 0) {
        pos1[1] = 0.0f;
    }
    return func_001AC2D0(pos1) - d;
}

float MsGetEscapeDir(int id) {
    float pos1[4];
    float pos2[4];
    float dir;

    MsGetChrEscapePos(id, (int)pos2);
    func_001B6790(id, pos1);
    MsVectorRect2Polar(pos2, pos1, (int)&dir, 0, 0);
    dir = MsNearRag(0.0f, dir);
    return dir;
}

extern s8 D_00319408;

float MsGetSummonDir(int id) {
    float pos1[4];
    float pos2[4];
    float dir;
    BtlChr *c = MsGetChr(D_00319408);

    MsBtlGetPos(0, c, (s8)c->f1BC.a, (s8)c->f1BC.b, (s8)c->f1BC.c, (int)pos2);
    func_001B6790(id, pos1);
    MsVectorRect2Polar(pos2, pos1, (int)&dir, 0, 0);
    dir = MsNearRag(0.0f, dir);
    return dir;
}

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
