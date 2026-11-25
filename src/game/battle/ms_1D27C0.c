/* tu_200 0x1d27c0-0x1d48d0: low; ~Ms (config/tu_map.tsv) */
#define MsGetMoveTargetPos _hdr_MsGetMoveTargetPos
#define MsNearRag _hdr_MsNearRag
#define func_001AC310 _hdr_func_001AC310
#define MsMoveSplineRegist _hdr_MsMoveSplineRegist
#include "common.h"
#include "vu0.h"
#include "ffx/s3.h"
#include "ffx/q4.h"
#include "ffx/r3.h"
#include "ffx/u2.h"
#include "ffx/v3.h"
#include "ffx/s2.h"
#undef MsMoveSplineRegist
#undef MsGetMoveTargetPos
#undef MsNearRag
#undef func_001AC310
float MsNearRag(float, float);
float func_001AC310(float *);
void func_001AC258(float *dst, float *a, float *b, float t);
void func_001AC750(float *pos, int w, float x, float y, float z);
void func_001D48F8(int id, void *c, float *pos, float ang);

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

float func_001AC2D0(float *);
float func_001AC348(float *, float *);
float func_001AC388(float *, float *);
void func_001AC3D0(float *, float *, float *);
void MsSetBallSpline(int);
void MsSetMove(int, int, int, int, int, int, float, float, float, float, float);
float MsGetMoveTargetPos();
int func_001D34B0(void *, int, float *, float *, float);
float MsGetDirMode();
int MsCameraMoveCalc(int, float *, R2Fade *, float);

void func_001D2958(int arg0)
{
    float pos[4];
    float target_pos[4];
    float vel[4];
    R2Fade fade;
    float ang;
    float pitch;
    s32 out_ok;
    s32 out_ang_flag;
    BtlChr *chr = MsGetChr(arg0);
    void *obj = *(void **)chr;

    if (obj == 0) {
        return;
    }
    switch (((u8 *)chr)[0xD5] & 0x7F) {
    case 0:
        break;
    case 7: {
        BtlCommandWork *sp;
        u16 cnt = ++*(u16 *)((u8 *)chr + 0x112);

        if (cnt >= *(u16 *)((u8 *)chr + 0x11A)) {
            ((u8 *)chr)[0xD5] = 0;
            ((u8 *)chr)[0xD8] = 0;
        }
        if (*(u16 *)((u8 *)chr + 0x114) == 2) {
            MsSetBallSpline(arg0);
        }
        sp = &D_00662670[*(u16 *)((u8 *)chr + 0x114)];
        TkMtCalcSpline((s32)pos, (u8 *)sp + 0x10, sp->count, (float)*(u16 *)((u8 *)chr + 0x112) / (float)*(u16 *)((u8 *)chr + 0x11A));
        MsSetChrPos(arg0, pos);
        {
            register int a __asm__("$3") = *(u16 *)((u8 *)chr + 0x112);
            func_002D5188((s32)pos, (u8 *)sp + 0x10, sp->count, (float)a / (float)*(u16 *)((u8 *)chr + 0x11A));
        }
        if ((double)*(float *)((u8 *)chr + 0x12C) != 0.0) {
            if ((double)func_001AC2D0(pos) != 0.0) {
                float d;
                s8 flg;

                MsVectorRect2Polar(pos, 0, &ang, 0, 0);
                ang = MsNearRag(*(float *)((u8 *)chr + 0x150), ang);
                d = ang - *(float *)((u8 *)chr + 0x150);
                flg = ((s8 *)chr)[0xEA];
                if (flg < 0 && d > 1.5707964f) {
                    d = -d;
                } else if (flg > 0 && d < -1.5707964f) {
                    d = -d;
                }
                *(float *)((u8 *)chr + 0x150) = *(float *)((u8 *)chr + 0x150) + d * *(float *)((u8 *)chr + 0x12C);
                Ch_SetDirF(*(void **)chr, *(float *)((u8 *)chr + 0x150));
            }
        }
        break;
    }
    case 0x10: {
        u16 cnt;

        func_001B6790(arg0, pos);
        func_001AC750(vel, 0, *(float *)((u8 *)chr + 0x130), *(float *)((u8 *)chr + 0x13C), *(float *)((u8 *)chr + 0x120));
        func_001AC3D0(pos, pos, vel);
        MsSetChrPos(arg0, pos);
        cnt = ++*(u16 *)((u8 *)chr + 0x112);
        if (cnt >= *(u16 *)((u8 *)chr + 0x11A)) {
            ((u8 *)chr)[0xD5] = 0;
            ((u8 *)chr)[0xD8] = 0;
        }
        break;
    }
    default: {
        float *tp = target_pos;
        float ret = MsGetMoveTargetPos(arg0, chr, ((u8 *)chr)[0xD5], tp, 0);

        if (arg0 == 0) {
            MMI_COPY_LQ_T0(D_00662CA0, tp);
            MMI_COPY_SQ_T0(D_00662CA0);
        }
        if (((u8 *)chr)[0xD5] & 0x80) {
            register float d __asm__("$f1");

            func_001B6790(arg0, pos);
            MsVectorRect2Polar(tp, pos, &ang, &pitch, 0);
            *(float *)((u8 *)chr + 0x120) += *(float *)((u8 *)chr + 0x128);
            if (*(float *)((u8 *)chr + 0x120) > *(float *)((u8 *)chr + 0x124)) {
                *(float *)((u8 *)chr + 0x120) = *(float *)((u8 *)chr + 0x124);
            }
            *(float *)((u8 *)chr + 0x134) += *(float *)((u8 *)chr + 0x138);
            ang = MsNearRag(*(float *)((u8 *)chr + 0x130), ang);
            d = ang - *(float *)((u8 *)chr + 0x130);
            if (d > *(float *)((u8 *)chr + 0x134)) {
                d = *(float *)((u8 *)chr + 0x134);
            }
            if (d < -*(float *)((u8 *)chr + 0x134)) {
                d = -*(float *)((u8 *)chr + 0x134);
            }
            {
                register float cur __asm__("$f3") = *(float *)((u8 *)chr + 0x130) + d;
                register float d2 __asm__("$f1");
                register float a0 __asm__("$f0");
                *(float *)((u8 *)chr + 0x130) = cur;
                a0 = ang;
                d2 = a0 - cur;
                if (*(u16 *)((u8 *)chr + 0x112) > *(u16 *)((u8 *)chr + 0x11A)) {
                    int dt = *(u16 *)((u8 *)chr + 0x112) - *(u16 *)((u8 *)chr + 0x11A);

                    a0 = d2 * dt;
                    d2 = a0 / (*(u16 *)((u8 *)chr + 0x11A) * 4 + 1);
                    d2 = cur + d2;
                    *(float *)((u8 *)chr + 0x130) = d2;
                }
            }
            if (((s8 *)chr)[0x34] == 0) {
                register float res __asm__("$f0");

                *(float *)((u8 *)chr + 0x140) += *(float *)((u8 *)chr + 0x144);
                pitch = MsNearRag(*(float *)((u8 *)chr + 0x13C), pitch);
                d = pitch - *(float *)((u8 *)chr + 0x13C);
                if (d > *(float *)((u8 *)chr + 0x140)) {
                    d = *(float *)((u8 *)chr + 0x140);
                }
                if (d < -*(float *)((u8 *)chr + 0x140)) {
                    d = -*(float *)((u8 *)chr + 0x140);
                }
                res = *(float *)((u8 *)chr + 0x13C) + d;
                *(float *)((u8 *)chr + 0x13C) = res;
            }
            func_001AC750(vel, 0, *(float *)((u8 *)chr + 0x130), *(float *)((u8 *)chr + 0x13C), *(float *)((u8 *)chr + 0x120));
            func_001AC3D0(pos, pos, vel);
            if ((double)*(float *)((u8 *)chr + 0x12C) != 0.0) {
                register float res __asm__("$f0");

                ang = MsNearRag(*(float *)((u8 *)chr + 0x150), *(float *)((u8 *)chr + 0x130));
                d = ang - *(float *)((u8 *)chr + 0x150);
                if (d > *(float *)((u8 *)chr + 0x12C)) {
                    d = *(float *)((u8 *)chr + 0x12C);
                }
                if (d < -*(float *)((u8 *)chr + 0x12C)) {
                    d = -*(float *)((u8 *)chr + 0x12C);
                }
                res = *(float *)((u8 *)chr + 0x150) + d;
                *(float *)((u8 *)chr + 0x150) = res;
                Ch_SetDirF(*(void **)chr, res);
            }
            *(u16 *)((u8 *)chr + 0x112) += 1;
            MsSetChrPos(arg0, pos);
            {
                register int lim __asm__("$3") = *(u16 *)((u8 *)chr + 0x11A);
                if (*(u16 *)((u8 *)chr + 0x112) > lim * 2) {
                    float dist = (((s8 *)chr)[0x34] != 0) ? func_001AC348(pos, tp) : func_001AC388(pos, tp);
                    register int f0 __asm__("$2") = (int)(dist / *(float *)((u8 *)chr + 0x124));
                    int frames = f0 | 1;

                    MsSetChrDirTarget(arg0, 8, 0, 0, frames / 4, 1);
                    MsSetMove(arg0, ((u8 *)chr)[0xD5] & 0x7F, ((u8 *)chr)[0xD6], frames, 0, 0x20, *(float *)((u8 *)chr + 0x120), *(float *)((u8 *)chr + 0x148), *(float *)((u8 *)chr + 0x14C), *(float *)((u8 *)chr + 0x158), *(float *)((u8 *)chr + 0x168));
                }
            }
        } else {
            int cnt;
            register float r __asm__("$f12") = ret;

            *(u16 *)((u8 *)chr + 0x112) += 1;
            cnt = *(u16 *)((u8 *)chr + 0x112);
            if (func_001D34B0(chr, cnt, tp, pos, r) != 0) {
                MsSetChrPos(arg0, pos);
            }
            if (cnt >= *(u16 *)((u8 *)chr + 0x11A)) {
                ((u8 *)chr)[0xD5] = 0;
                ((u8 *)chr)[0xD8] = 0;
            }
        }
        if (((s8 *)chr)[0xD9] != 0) {
            int t_int = *(u16 *)((u8 *)chr + 0x11A);
            float t_total = t_int;
            float v0 = ((target_pos[1] - *(float *)((u8 *)chr + 0x54)) - *(float *)((u8 *)chr + 0x168) * t_total * t_total * 0.5f) / t_total;
            float t;

            t_int = *(u16 *)((u8 *)chr + 0x112);
            func_001B6790(arg0, pos);
            t = t_int;
            pos[1] = *(float *)((u8 *)chr + 0x54) + v0 * t + *(float *)((u8 *)chr + 0x168) * t * t * 0.5f;
            MsSetChrPos(arg0, pos);
        }
        break;
    }
    }
    if (((u8 *)chr)[0xEE] != 0) {
        fade.h4 = 0;
        fade.mode = 2;
        fade.t0 = ((u8 *)chr)[0xEF];
        fade.t1 = ((u8 *)chr)[0xF0];
        fade.t2 = ((u8 *)chr)[0xEF];
        fade.total = ((u8 *)chr)[0xEF] + (((u8 *)chr)[0xEF] + ((u8 *)chr)[0xF0]);
        fade.time = fade.total - ((u8 *)chr)[0xEE];
        ((u8 *)chr)[0xEE] -= 1;
        ang = MsGetDirMode(arg0, chr, target_pos, 1, &out_ok, &out_ang_flag);
        *(float *)((u8 *)chr + 0x1B4) = ang;
        if (out_ok != 0) {
            MsCameraMoveCalc(out_ang_flag, &ang, &fade, *(float *)((u8 *)chr + 0x150));
            Ch_SetDirF(obj, ang);
        }
    }
}

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

typedef struct {
    u8 pad00[0x14];
    u8 f14;
    u8 pad15[0x3B];
    float f50[4];
    u8 pad60[0x30];
    float f90[4];
    u8 padA0[0x2C];
    u8 fCC;
    u8 padCD[4];
    u8 fD1;
    u8 padD2[3];
    u8 fD5;
    u8 fD6;
    u8 fD7;
    s8 fD8;
    u8 padD9[0x39];
    u16 f112;
    u8 pad114[0x34];
    float f148;
    u8 pad14C[0xC];
    float f158;
    u8 pad15C[0x60];
    s8 f1BC[3];
    u8 pad1BF[0x8C1];
    s32 fA80;
    u8 padA84[0x29];
    s8 fAAD;
} TargetChr;

float MsGetMoveTargetPos(int arg_id, TargetChr *c, int mode, float *arg_pos, int *out_flag)
{
    register int id __asm__("$17") = arg_id;
    register float *pos __asm__("$18") = arg_pos;
    float tmp[4];
    float w;
    float h;
    float ret = 0.0f;
    int flag = 0;

    switch (mode & 0x7F) {
    case 3:
        MsGetChrEscapePos(id, (int)pos);
        break;
    case 4:
        c = (TargetChr *)MsGetChr(D_00319408);
        MsBtlGetPos(0, (BtlChr *)c, c->f1BC[0], c->f1BC[1], c->f1BC[2], (int)pos);
        break;
    case 18:
        MsGetSummonerPos(MsGetChr(D_003172F0.f2118), D_003172F0.f2118, 3, pos);
        break;
    case 5:
        c = (TargetChr *)MsGetChr(D_00319408);
        MsBtlGetPos(0, (BtlChr *)c, c->f1BC[0], c->f1BC[1] + 3, c->f1BC[2], (int)pos);
        break;
    case 1:
        MsGetChrBtlPos(id, pos);
        break;
    case 6:
        func_001B6790(id, pos);
        break;
    case 15:
        Ch_OptposGet(MsGetChrHandle(c->f14), 0xE, (int)pos);
        break;
    case 8:
        func_001B6790(c->fAAD, pos);
        break;
    case 9:
        if (c->fD7 == 0) {
            c->fD7 = 1;
            func_001B6790(c->fAAD, c->f90);
        }
        if (c->fD5 == 0) {
            func_001B6790(id, tmp);
            func_001AC258(pos, tmp, c->f90, 10.0f);
            if (c->fD1 != 0) {
                func_001D48F8(id, c, pos, 0.7853981852531433f);
            }
            func_001AC3D0(pos, tmp, pos);
        } else {
            func_001AC258(pos, c->f50, c->f90, 10.0f);
            if (c->fD1 != 0) {
                func_001D48F8(id, c, pos, 0.7853981852531433f);
            }
            func_001AC3D0(pos, c->f50, pos);
        }
        break;
    case 2:
        func_001D2878(id, 1, pos, &w, &h);
        if ((1 << id) != c->fA80) {
            float cw = MsGetChrWidth(id);
            float py = pos[1] - h * c->f158;
            ret = w + cw + c->f148;
            pos[1] = py;
        } else {
            ret = 0.0f;
        }
        break;
    case 11:
        func_001D2878(id, 1, pos, &w, &h);
        if ((1 << id) != c->fA80) {
            ret = c->f148;
            pos[1] -= h * c->f158;
        } else {
            ret = 0.0f;
        }
        break;
    case 10:
        func_001B6790(c->fD6, pos);
        ret = MsGetChrWidth(c->fD6) + MsGetChrWidth(id) + c->f148;
        break;
    case 12:
        if ((1 << id) != c->fA80) {
            D_00662CB0 = c->fCC + 1;
            if (c->fD8 != 0) {
                D_00662CB0 -= c->f112;
            }
            func_001D2878(id, 12, pos, &w, &h);
            {
                float cw = MsGetChrWidth(id);
                float py = pos[1] - h * c->f158;
                ret = w + cw + c->f148;
                pos[1] = py;
            }
        } else {
            ret = 0.0f;
            func_001D2878(id, 1, pos, &w, &h);
            flag = -1;
        }
        break;
    case 13:
        MsGetChrBtlPos(id, pos);
        pos[1] = MsGetChrGround(id) - MsGetChrHeight(id) * 0.25f;
        break;
    case 14:
        func_001B6790(id, pos);
        pos[1] = MsGetChrGround(id);
        break;
    case 17: {
        register int tid __asm__("$17") = c->f14;
        func_001B6790(tid, tmp);
        func_001B6E48(tid, &w);
        func_001AC750(pos, 0, w, 0.0f, 10.0f);
        func_001AC3D0(pos, tmp, pos);
        break;
    }
    case 7:
    case 16:
        break;
    }
    if (out_flag != 0) {
        *out_flag = flag;
    }
    return ret;
}

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

void MsSetMove(int id, int mode, int a2, int frames, int d0, int d1,
               float f12, float f13, float f14, float f15, float f16)
{
    float pos[4];
    float target[4];
    BtlChr *chr = MsGetChr(id);
    int v0 = (frames * d0) / 128;
    int v1 = (frames * d1) / 128;

    ((u8 *)chr)[0xD5] = mode & 0x3F;
    ((u8 *)chr)[0xD7] = 0;
    *(u16 *)((u8 *)chr + 0x112) = 0;
    *(u16 *)((u8 *)chr + 0x114) = v0;
    *(u16 *)((u8 *)chr + 0x118) = v1;
    *(u16 *)((u8 *)chr + 0x116) = frames - v0 - v1;
    if (mode & 0x40) {
        *(float *)((u8 *)chr + 0x11C) = *(float *)((u8 *)chr + 0x120);
    } else {
        *(float *)((u8 *)chr + 0x11C) = f12;
    }
    ((u8 *)chr)[0xD6] = a2;
    *(u16 *)((u8 *)chr + 0x11A) = frames;
    *(float *)((u8 *)chr + 0x148) = f13;
    *(float *)((u8 *)chr + 0x14C) = f14;
    *(float *)((u8 *)chr + 0x158) = f15;
    func_001B6790(id, pos);
    *(float *)((u8 *)chr + 0x50) = pos[0];
    *(float *)((u8 *)chr + 0x54) = pos[1];
    *(float *)((u8 *)chr + 0x58) = pos[2];
    if ((double)f16 != 0.0) {
        *(float *)((u8 *)chr + 0x168) = f16;
        ((s8 *)chr)[0xD9] = -1;
    } else {
        ((s8 *)chr)[0xD9] = 0;
        *(float *)((u8 *)chr + 0x168) = 0.0f;
    }
    MsGetMoveTargetPos(id, (TargetChr *)chr, ((u8 *)chr)[0xD5], target, 0);
    func_001AC3E8(pos, target, pos);
    if (((s8 *)chr)[0x34] == 0) {
        *(float *)((u8 *)chr + 0x164) = func_001AC2D0(pos);
    } else {
        *(float *)((u8 *)chr + 0x164) = func_001AC310(pos);
    }
    *(float *)((u8 *)chr + 0x160) = 0.0f;
}

void MsMoveSplineSet(u32 i) {
    if (i < 3) {
        D_00662660[i] = 0;
    }
}

void MsMoveSplineRegist(u32 idx, int chr_id, int mode, u_long128 *pos)
{
    if (idx < 3) {
        int cnt = D_00662660[idx];
        if (cnt < 0x20) {
            u_long128 *dst;
            D_00662660[idx] = cnt + 1;
            dst = (u_long128 *)((u8 *)&D_00662670[idx] + (cnt + 1) * 0x10);
            if (pos != 0) {
                MMI_COPY_LQ_T0(dst, pos);
                MMI_COPY_SQ_T0(dst);
            }
            MsGetMoveTargetPos(chr_id, (TargetChr *)MsGetChr(chr_id), mode, (float *)dst, 0);
        }
    }
}

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

void MsGetChrPredictPos(int id, float *out)
{
    float tmp[4];
    int flag;
    BtlChr *chr = MsGetChr(id);
    int mode;
    int cnt;

    if (((u8 *)chr)[0xE5] != 0) {
        MMI_COPY_LQ_T0(out, (u8 *)chr + 0x80);
        MMI_COPY_SQ_T0(out);
        return;
    }
    func_001B6790(id, out);
    mode = ((u8 *)chr)[0xD5] & 0x7F;
    cnt = *(u16 *)((u8 *)chr + 0x112);
    if (mode == 7) {
        BtlCommandWork *sp;
        cnt += D_00662CB0;
        if (cnt > *(u16 *)((u8 *)chr + 0x11A)) {
            cnt = *(u16 *)((u8 *)chr + 0x11A);
        }
        sp = &D_00662670[*(u16 *)((u8 *)chr + 0x114)];
        TkMtCalcSpline((s32)tmp, (u8 *)sp + 0x10, sp->count, (float)cnt / (float)*(u16 *)((u8 *)chr + 0x11A));
        func_001AC3D0(out, out, tmp);
    } else if (mode != 0) {
        float ret = MsGetMoveTargetPos(id, (TargetChr *)chr, ((u8 *)chr)[0xD5], tmp, &flag);
        if (flag == 0) {
            if (((u8 *)chr)[0xD5] & 0x80) {
                register float max_spd __asm__("$f1") = *(float *)((u8 *)chr + 0x124);
                int n = D_00662CB0;
                register float dist __asm__("$f21") = 0.0f;
                register float spd __asm__("$f0") = *(float *)((u8 *)chr + 0x120);
                register float accel __asm__("$f2");
                __asm__ volatile("" : "+f"(spd), "+f"(max_spd), "+f"(dist));
                accel = *(float *)((u8 *)chr + 0x128);
                if (n > 0) {
                    do {
                        spd += accel;
                        if (spd > max_spd) {
                            spd = max_spd;
                        }
                        dist += spd;
                    } while (--n != 0);
                }
                {
                    register float d __asm__("$f20") = func_001AC388(out, tmp);
                    if (dist > d) {
                        dist = d;
                    }
                }
                func_001AC258(tmp, tmp, out, dist);
                func_001AC3D0(out, out, tmp);
            } else {
                float s164 = *(float *)((u8 *)chr + 0x164);
                register float r __asm__("$f12") = ret;
                float s160 = *(float *)((u8 *)chr + 0x160);
                func_001D34B0(chr, cnt + D_00662CB0, tmp, out, r);
                *(float *)((u8 *)chr + 0x164) = s164;
                *(float *)((u8 *)chr + 0x160) = s160;
            }
        }
    }
}

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
