/* tu_214 0x1e7af0-0x1ea000: low; ~Ms (config/tu_map.tsv) */
#include "common.h"
#include "ffx/g3.h"
#include "ffx/s3.h"
#include "ffx/q4.h"
#include "ffx/r3.h"
#include "ffx/u2.h"
#include "ffx/v3.h"

int func_001E7AF0(Actor *a) {
    int id = *func_00144158(a);
    BtlChr *c = MsGetChr(id);
    if (id != 0xFF) {
        MsDeathTerminate(id, c);
    }
    return 0;
}

int func_001E7B40(Actor *a) {
    u8 id = *func_00144158(a);
    if (id != 0xFF) {
        MsGetChr(id);
        if ((s8)D_003172F0.f213D > 0) { /* DEBT(TYPE): f213D is signed here, u8 elsewhere */
            D_003172F0.f213D--;
        }
    }
    return (s8)D_003172F0.f213D;
}

int func_001E7B98(Actor *a) {
    int id = *func_00144158(a);
    BtlChr *c = MsGetChr(id);
    if (id != 0xFF) {
        c->fF2 = 1;
    }
    return 0;
}

int ms_motion_trans(BtlChr *c, int v) {
    int r = v;
    int sel = c->fC8;
    int sel2 = c->fC9;

    switch (v) {
    case 1:
        r = c->fB1;
        break;
    case 2:
        switch (sel) {
        case 1:
            r = -1;
            break;
        case 2:
            r = 0xB0;
            break;
        case 3:
            r = 0xB8;
            break;
        case 4:
            r = 0xC0;
            break;
        case 5:
            r = 0xC8;
            break;
        default:
            r = 0x58;
            break;
        }
        break;
    case 3:
        switch (sel) {
        case 1:
            r = 0x5C;
            break;
        case 2:
            r = 0xB1;
            break;
        case 3:
            r = 0xB9;
            break;
        case 4:
            r = 0xC1;
            break;
        case 5:
            r = 0xC9;
            break;
        default:
            r = 0x59;
            break;
        }
        break;
    case 12:
        sel = sel2;
    case 4:
        switch (sel) {
        case 2:
            r = 0xB2;
            break;
        case 3:
            r = 0xBA;
            break;
        case 4:
            r = 0xC2;
            break;
        case 5:
            r = 0xCA;
            break;
        case 1:
        default:
            r = 0x5A;
            break;
        }
        break;
    case 13:
        sel = sel2;
    case 5:
        switch (sel) {
        case 2:
            r = 0xB3;
            break;
        case 3:
            r = 0xBB;
            break;
        case 4:
            r = 0xC3;
            break;
        case 5:
            r = 0xCB;
            break;
        case 1:
        default:
            r = 0x5B;
            break;
        }
        break;
    case 6:
        r = 0x5D;
        break;
    }
    return r;
}

int func_001E1C70(int id, BtlChr *c, int mot, int old_mot);
int Ch_MotionSetHokan(Chr *chr, int v);

int func_001E7D80(Actor *a, void *unused, ScriptCtx *ctx, int flag) {
    int r = 1;
    int mot = AtelPopStackInteger(a, ctx);
    u8 id = *func_00144158(a);

    if (id != 0xFF) {
        BtlChr *c = MsGetChr(id);
        Chr *w = c->chr;
        c->fF4 = 1;
        if (w != 0 && c->f38 != 0) {
            int hi = mot & 0x8000;
            mot = ms_motion_trans(c, mot & ~0x8000);
            if (c->fB3 == 0 && mot >= 0) {
                Ch_ResetMotion(w);
                Ch_SetSysMotion((int)w, c->f20, mot);
                if (hi != 0) {
                    Ch_MotionSetNextHokan(w, 0);
                    Ch_MotionSetHokan(w, 0);
                } else {
                    if ((c->flags & 0x80) == 0) {
                        Ch_MotionSetNextHokan(w, 0);
                    }
                    Ch_MotionSetHokan(w, func_001E1C70(id, c, mot, c->fB0));
                }
                if (c->fC5 != 0) {
                    c->fC5 = 0;
                    func_001D48D0(c);
                }
                c->fB0 = mot;
                c->fCA = flag;
                MsCalcMotionSpeed(c);
                r = Ch_GetSeqFrame(w);
                if (r > 0) {
                    int div;
                    if (c->fC4 == 1) {
                        div = (u16)c->fC2;
                    } else {
                        div = (c->fBC * c->padC6[0]) / 8;
                    }
                    if (div != 0) {
                        r = (r << 8) / div;
                    }
                    c->fF4 = 0;
                } else {
                    r = 1;
                }
            }
        }
    }
    return r;
}

int func_001E7F58(Actor *a, void *u, ScriptCtx *c) {
    return func_001E7D80(a, u, c, 0);
}

int func_001E7F78(Actor *a, void *u, ScriptCtx *c) {
    return func_001E7D80(a, u, c, 1);
}

int func_001E7F98(Actor *a, void *unused, ScriptCtx *ctx) {
    BtlChr *c = MsGetChr(*func_00144158(a));
    s8 old = c->f38;
    c->f38 = 1;
    func_001E7D80(a, unused, ctx, 0);
    c->f38 = old;
    if (c->fF4 != 0) {
        c->fB3 = 1;
    }
    return old;
}

int func_001E8028(Chr *w, BtlChr *c, int r) {
    if (Ch_GetWaitMotion(w) != 0) {
        if (c->fF4 == 0) {
            r = 0;
        }
    }
    return r;
}

int func_001E8070(Actor *ctx)
{
    int r = 5;
    u8 id = *func_00144158(ctx);
    BtlChr *c;
    Chr *w;

    if (id != 0xFF) {
        c = MsGetChr(id);
        w = c->chr;
        if (c->fB3 != 0) {
            r = 0;
        } else if (w != 0) {
            r = func_001E8028(w, c, 5);
        }
    }
    return r;
}

int func_001E80E0(Actor *a) {
    int r = 5;
    int id = *func_00144158(a);
    if (id != 0xFF) {
        if (MsGetChr(id)->fE5 != 0) {
            r = 0;
        }
    }
    return r;
}

int func_001E8128(Actor *ctx)
{
    u8 id = *func_00144158(ctx);
    Chr *w;

    if (id != 0xFF) {
        w = MsGetChr(id)->chr;
        if (w != 0) {
            if (Ch_GetWaitMotion(w) != 0) {
                return -1;
            }
        }
    }
    return 0;
}

int func_001E8180(Actor *ctx, void *unused, ScriptCtx *arg)
{
    int a = AtelPopStackInteger(ctx, arg);
    int b = AtelPopStackInteger(ctx, arg);
    u8 id = *func_00144158(ctx);

    MsSetChrDirTarget(id, 2, 0, -1, b, a);
    return 0;
}

int func_001E81F8(Actor *a, void *unused, ScriptCtx *ctx) {
    int x = AtelPopStackInteger(a, ctx);
    int y = AtelPopStackInteger(a, ctx);
    int id = *func_00144158(a);
    if (MsGetChr(id)->fDD != 0) {
        MsSetChrDirTarget(id, 1, 0, -1, y, x);
    }
    return 0;
}

int func_001E8288(Actor *a, void *unused, ScriptCtx *ctx) {
    int x = AtelPopStackInteger(a, ctx);
    int y = AtelPopStackInteger(a, ctx);
    int id = *func_00144158(a);
    if (MsGetChr(id)->fDD != 0) {
        MsSetChrDirTarget(id, 1, 1, -1, y, x);
    }
    return 0;
}

int func_001E8318(Actor *a, void *unused, ScriptCtx *ctx) {
    int x = AtelPopStackInteger(a, ctx);
    int y = AtelPopStackInteger(a, ctx);
    int z;
    AtelPopStackFloat(a, ctx);
    z = AtelPopStackInteger(a, ctx);
    MsSetChrDirTarget(*func_00144158(a), z, 0, -1, y, x);
    return 0;
}

int func_001E83B8(Actor *a, void *unused, ScriptCtx *ctx) {
    int x = AtelPopStackInteger(a, ctx);
    int y = AtelPopStackInteger(a, ctx);
    int z;
    AtelPopStackFloat(a, ctx);
    z = AtelPopStackInteger(a, ctx);
    MsSetChrDirTarget(*func_00144158(a), z, 1, -1, y, x);
    return 0;
}

int func_001E8458(Actor *a) {
    func_001B72A0(*func_00144158(a));
    return 0;
}

s32 func_001E8480(Actor *arg0, s32 arg1, ScriptCtx *arg2) {
    float var_f20;
    s32 temp_2;
    s32 var_16;
    s32 var_19;
    s32 var_2;
    u8 temp_17;

    var_19 = 0;
    var_f20 = 0.0f;
    temp_17 = *func_00144158(arg0);
    var_16 = 0;
    temp_2 = MsGetChrBit((s32) temp_17, AtelPopStackInteger(arg0, arg2), 0, 1);
    do {
        if ((temp_2 >> var_16) & 1) {
            var_19 += 1;
            var_f20 += func_001D3B10(var_16, 1);
        }
        var_16 += 1;
    } while (var_16 < 0x1F);
    if (var_19 > 0) {
        var_f20 /= (float) var_19;
    }
    return (s32) var_f20;
}

s32 func_001E8550(Actor *arg0, s32 arg1, ScriptCtx *arg2) {
    u8 sp[0x10];
    float sp10;
    s32 temp_17_2;
    s32 temp_19;
    u8 temp_17;

    temp_17 = *func_00144158(arg0);
    temp_19 = MsGetChrBit((s32) temp_17, AtelPopStackInteger(arg0, arg2), 0, 1);
    temp_17_2 = MsGetChrBit((s32) temp_17, AtelPopStackInteger(arg0, arg2), 0, 1);
    MsGetChrInfo(1, temp_19, -1, sp);
    MsGetChrInfo(1, temp_17_2, -1, &sp10);
    return (s32) func_001AC348(sp, &sp10);
}

int func_001E8620(Actor *a, void *b, ScriptCtx *c) {
    u8 id = *func_00144158(a);
    int v;
    float f;
    MsGetChr(id);
    v = func_001B8198(id, AtelPopStackInteger(a, c), 0, 1);
    f = func_002EC440(func_002EBF18(func_002ED038(func_001D3B10(v, 12)), 2.5));
    return f;
}

float func_001E86B8(BtlChr *c) {
    float f = c->f194;
    if (c->f0C == 0x1D) {
        if (MsGetChr(c->f14)->fBB != 0) {
            f += f;
        }
    }
    return f;
}

int func_001E8700(Actor *a, void *b, ScriptCtx *ctx) {
    u8 id = *func_00144158(a);
    int v = func_001B8198(id, AtelPopStackInteger(a, ctx), 0, 1);
    float dist = func_001D3B10(v, 12);
    BtlChr *c = MsGetChr(v);
    int r = func_001D5790(c);
    int count = c->padCC[2];

    if (c->fBC < c->fC0) {
        count = (count * c->fBC) / c->fC0;
    }
    if (r & 3) {
        float step;
        float max_step;
        float accel;
        dist -= c->f17C;
        step = c->f18C;
        max_step = func_001E86B8(c);
        accel = c->f190;
        while ((double)dist > 0.0) {
            step += accel;
            if (max_step < step) {
                step = max_step;
            }
            dist -= step;
            count++;
        }
    }
    return count;
}

int func_001E8838(Actor *a, void *unused, ScriptCtx *ctx) {
    int id = *func_00144158(a);
    BtlChr *c = MsGetChr(id);
    int h = func_001B8198(id, AtelPopStackInteger(a, ctx), 0, 1);
    float d = func_001E86B8(c);
    return (int)(func_001D3B10(h, 12) / d);
}

int func_001E88E0(Actor *a, void *b, ScriptCtx *ctx) {
    int y = AtelPopStackInteger(a, ctx);
    float f = 0.0f;
    int x = AtelPopStackInteger(a, ctx);
    int id = func_001B8198(*func_00144158(a), x, 0, 1);

    if (id != 0xFF) {
        f = MsGetMoveTargetDist(id, y, 0);
    }
    f = func_002EC440(func_002EBBB0(func_002EBF18(func_002ED038(f), 20.0), 4.0));
    if (f > 20.0f) {
        f = 20.0f;
    }
    return f;
}

int func_001E89C8(Actor *ctx, void *unused, ScriptCtx *arg)
{
    int v = AtelPopStackInteger(ctx, arg);
    u8 id = *func_00144158(ctx);

    if (id != 0xFF) {
        func_001C5E90(id, v, 0);
    }
    return 0;
}

int func_001E8A20(Actor *a, int unused, ScriptCtx *ctx) {
    float f = AtelPopStackFloat(a, ctx);
    int id = *func_00144158(a);
    if (id != 0xFF) {
        BtlChr *c = MsGetChr(id);
        if (c->chr != 0) {
            Ch_SetSp(c->chr, f);
        }
    }
    return 0;
}

int func_001E8A90(Actor *ctx, void *unused, ScriptCtx *arg)
{
    int v = AtelPopStackInteger(ctx, arg);
    u8 id = *func_00144158(ctx);

    if (id != 0xFF) {
        MsGetChr(id)->fE0 = v;
    }
    return 0;
}

int func_001E8AF0(Actor *a) {
    int r = 0;
    int id = *func_00144158(a);
    if (id != 0xFF) {
        r = MsGetChr(id)->fE0;
    }
    return r;
}

int func_001E8B38(Actor *ctx, void *unused, ScriptCtx *arg)
{
    int v = AtelPopStackInteger(ctx, arg);
    u8 id = *func_00144158(ctx);

    if (id != 0xFF) {
        MsGetChr(id)->f10F = v;
    }
    return 0;
}

int func_001E8B98(Actor *a) {
    int r = 0;
    int id = *func_00144158(a);
    if (id != 0xFF) {
        r = MsGetChr(id)->f10F;
    }
    return r;
}

int func_001E8BE0(Actor *ctx, void *unused, ScriptCtx *arg)
{
    int v = AtelPopStackInteger(ctx, arg);
    u8 id = *func_00144158(ctx);

    if (id != 0xFF) {
        MsGetChr(id)->fB1 = v;
    }
    return 0;
}

float _m2c_MsGetDirDivide_MsNearRag(float, float) __asm__("MsNearRag");
void _m2c_MsGetDirDivide_MsVectorRect2Polar(s32, s32, float *, s32, s32) __asm__("MsVectorRect2Polar");
float _m2c_MsGetDirDivide_func_001AC388(s32, s32) __asm__("func_001AC388");
void _m2c_MsGetDirDivide_func_001B6E48(s32, void *) __asm__("func_001B6E48");
s32 _m2c_MsGetDirDivide_func_002EC198(s32, s32) __asm__("func_002EC198");
s32 _m2c_MsGetDirDivide_func_002ED038(float) __asm__("func_002ED038");
/* DEBT(FAKE) */
s32 MsGetDirDivide(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    float sp0;
    float sp4;
    register s32 temp_hi __asm__("$4");
    register s32 cvt __asm__("$2");
    register s32 cvt1 __asm__("$3");
    register s32 a3_2 __asm__("$5");

    _m2c_MsGetDirDivide_func_001B6E48(arg2, (&sp0));
    sp0 = _m2c_MsGetDirDivide_MsNearRag(0.0f, sp0);
    if (_m2c_MsGetDirDivide_func_002EC198(_m2c_MsGetDirDivide_func_002ED038(_m2c_MsGetDirDivide_func_001AC388(arg0, arg1)), 0) == 0) {
        sp4 = 0.0f;
    } else {
        _m2c_MsGetDirDivide_MsVectorRect2Polar(arg0, arg1, &sp4, 0, 0);
        sp4 = _m2c_MsGetDirDivide_MsNearRag(sp0, sp4) - sp0;
    }
    if (arg4 != 0) {
        cvt = (s32) (((((sp4 * 180.0f) / 3.1415927f) + 360.0f) * (float) arg3) / 360.0f);
        return cvt % arg3;
    }
    cvt = (s32) (((((sp4 * 180.0f) / 3.1415927f) + 360.0f) * (float) arg3) / 180.0f);
    cvt1 = cvt + 1;
    a3_2 = arg3 * 2;
    temp_hi = cvt1 % a3_2;
    return (s32) (((u32) temp_hi >> 0x1F) + temp_hi) >> 1;
}

INCLUDE_ASM("build/ee_asm/game/battle/ms_1E7AF0", func_001E8DF0);

int func_001E8F58(Actor *a, void *unused, ScriptCtx *ctx) {
    float p1[4];
    float p2[4];
    int r = 0;
    int x = AtelPopStackInteger(a, ctx);
    int y = AtelPopStackInteger(a, ctx);
    u8 id = *func_00144158(a);
    BtlChr *c;

    if (id != 0xFF) {
        c = MsGetChr(id);
        if (c->f10E != 0 && x < 0) {
            if (c->f10E < 0) {
                r = 1;
            } else {
                r = 0;
            }
        } else {
            if (x < 0) {
                x = -x;
            }
            func_001B6790(id, p1);
            MsGetMoveTargetPos(id, c, y, p2, 0);
            r = MsGetDirDivide((s32)p2, (s32)p1, id, x, 0);
        }
    }
    return r;
}

int func_001E9050(Actor *a, int unused, ScriptCtx *ctx) {
    int v = AtelPopStackInteger(a, ctx);
    return func_001E8DF0(*func_00144158(a), v, 1);
}

float _m2c_func_001E90A0_func_001D3350(BtlChr *, float) __asm__("func_001D3350");
s32 func_001E90A0(Actor *arg0, s32 arg1, ScriptCtx *arg2) {
    BtlChr *temp_2;
    s32 temp_17;

    temp_17 = AtelPopStackInteger(arg0, arg2);
    temp_2 = MsGetChr((s32) *func_00144158(arg0));
    return (s32) (((_m2c_func_001E90A0_func_001D3350(temp_2, (((struct { u8 _pad[0x1D4]; float a[1]; } *)(temp_2))->a[temp_2->f1D1])) - temp_2->f150[0]) / 3.1415927f) * (float) temp_17);
}

int func_001E9138(Actor *a, void *unused, ScriptCtx *ctx) {
    float x = AtelPopStackFloat(a, ctx);
    float y = AtelPopStackFloat(a, ctx);
    float z = AtelPopStackFloat(a, ctx);
    int id = *func_00144158(a);
    if (id != 0xFF) {
        BtlChr *c = MsGetChr(id);
        c->f60 = z;
        c->f64 = y;
        c->f68 = x;
        if (c->chr != 0) {
            Ch_SetScale(c->chr, 7, z, y, x);
        }
    }
    return 0;
}

int func_001E91F8(Actor *a, int unused, ScriptCtx *ctx) {
    float f = AtelPopStackFloat(a, ctx);
    int id = *func_00144158(a);
    if (id != 0xFF) {
        BtlChr *c = MsGetChr(id);
        c->f6C = f;
        if (c->chr != 0) {
            Ch_BindSetScale(c->chr, f);
        }
    }
    return 0;
}

int func_001E9268(Actor *ctx, void *unused, ScriptCtx *arg)
{
    int v = AtelPopStackInteger(ctx, arg);
    u8 id = *func_00144158(ctx);

    return MsGetChrBtlPosHeight(func_001B8198(id, v, 0, 1));
}

float func_001E92C0(Actor *a, void *u, ScriptCtx *c) {
    int v = AtelPopStackInteger(a, c);
    u8 id = *func_00144158(a);
    if (id != 0xFF) {
        return MsGetMoveTargetDist(id, v, 0);
    }
    return 0.0f;
}

float func_001E9320(Actor *a, void *u, ScriptCtx *c) {
    int v = AtelPopStackInteger(a, c);
    u8 id = *func_00144158(a);
    if (id != 0xFF) {
        return MsGetMoveTargetDist(id, v, 1);
    }
    return 0.0f;
}

/* DEBT(FAKE) */
s32 func_001E9380(Actor *arg0, s32 arg1, ScriptCtx *arg2) {
    BtlChr *temp_2_2;
    float temp_f20;
    register s32 temp_17 __asm__("$17");
    register s32 temp_2 __asm__("$17");
    register s32 var_18 __asm__("$18");
    s32 var_2;

    var_18 = 0;
    temp_f20 = MsNearRag(0.0f, (AtelPopStackFloat(arg0, arg2) * 3.1415927f) / 180.0f);
    temp_17 = AtelPopStackInteger(arg0, arg2);
    temp_2 = MsGetChrBit((s32) *func_00144158(arg0), temp_17, 0, 1);
    do {
        if ((temp_2 >> var_18) & 1) {
            temp_2_2 = MsGetChr(var_18);
            temp_2_2->f1D2 = 1;
            temp_2_2->f1D4[0] = temp_f20;
            temp_2_2->f1D4[1] = temp_f20;
        }
        var_18 += 1;
    } while (var_18 < 0x1F);
    return 0;
}

int func_001E9470(Actor *a, void *unused, ScriptCtx *ctx) {
    int id = *func_00144158(a);
    int x = AtelPopStackInteger(a, ctx);
    float f1 = AtelPopStackFloat(a, ctx);
    float f2 = AtelPopStackFloat(a, ctx);
    if (id != 0xFF) {
        MsSetChrTransparentVisible(id, f2, f1, x, 1);
    }
    return 0;
}

s32 func_001E9510(Actor *arg0, int unused1, ScriptCtx *arg2)
{
    float value;
    float other;
    s32 mode;
    u8 id;

    id = *func_00144158(arg0);
    mode = AtelPopStackInteger(arg0, arg2);
    other = AtelPopStackFloat(arg0, arg2);
    value = AtelPopStackFloat(arg0, arg2);
    if (id != 0xFF)
    {
        MsSetChrTransparentVisible((s32) id, value, other, mode, (s32) MsGetChr((s32) id)->fE3);
    }
    return 0;
}

int func_001E95C0(Actor *a, void *u, ScriptCtx *ctx) {
    float v = AtelPopStackInteger(a, ctx);
    u8 id = *func_00144158(a);
    if (id != 0xFF) {
        MsGetChr(id)->fBC = v;
    }
    return 0;
}

int func_001E9628(void) {
    return 0;
}

int func_001E9630(Actor *ctx, void *unused, ScriptCtx *arg)
{
    u8 id = *func_00144158(ctx);
    int v = AtelPopStackInteger(ctx, arg);
    BtlChr *c;

    if (id != 0xFF) {
        c = MsGetChr(id);
        c->fB5 = v;
        c->fB6 = v;
    }
    return 0;
}

void func_001E96A0(Actor *a, int *out, ScriptCtx *ctx) {
    u8 id = *func_00144158(a);
    int x = AtelPopStackInteger(a, ctx);
    int y = AtelPopStackInteger(a, ctx);
    int mask = MsGetChrBit(id, AtelPopStackInteger(a, ctx), 0, 1);
    int r = 0;
    int i;
    int res;

    for (i = 0; i < 31; i++) {
        if ((mask >> i) & 1) {
            MsSetMotion(i, y, x, 0, 1, a, &res);
            if (res) {
                r = 1;
            }
        }
    }
    *out = r;
}

int func_001E97B0(int a, int *b) {
    return func_001E6148(b);
}

void func_001E97D0(Actor *a, int *out, ScriptCtx *ctx) {
    u8 id = *func_00144158(a);
    int x;
    int y;
    int mask;
    int r = 0;
    int i;
    int res;
    BtlChr *o;

    MsGetChr(id);
    x = AtelPopStackInteger(a, ctx);
    y = AtelPopStackInteger(a, ctx);
    mask = MsGetChrBit(id, AtelPopStackInteger(a, ctx), 0, 1);
    for (i = 0; i < 31; i++) {
        if ((mask >> i) & 1) {
            o = MsGetWeaponSpecial(i, 0);
            if (o != 0) {
                MsSetMotion(o->f0C, y, x, 0, 1, a, &res);
                if (res) {
                    r = 1;
                }
            }
        }
    }
    *out = r;
}

int func_001E98F8(int a, int *b) {
    return func_001E6148(b);
}

int func_001E9918(int mask)
{
    int r = 0;
    int i;

    for (i = 0; i < 31; i++) {
        if ((mask >> i) & 1) {
            if (MsGetChr(i)->fF2 != 0) {
                r = 1;
            }
        }
    }
    return r;
}

void func_001E9998(Actor *ctx, int *out, ScriptCtx *arg)
{
    u8 id = *func_00144158(ctx);

    *out = MsGetChrBit(id, AtelPopStackInteger(ctx, arg), 0, 1);
}

int func_001E9A08(Actor *ctx, int *p)
{
    int r = 5;

    if (func_001E9918(*p)) {
        r = 0;
    }
    return r;
}

int func_001E9A38(Actor *ctx, void *unused, ScriptCtx *arg)
{
    u8 id = *func_00144158(ctx);

    return func_001E9918(MsGetChrBit(id, AtelPopStackInteger(ctx, arg), 0, 1));
}

int func_001E9AA0(Actor *a, void *unused, ScriptCtx *ctx) {
    u8 id = *func_00144158(a);
    int v = AtelPopStackInteger(a, ctx);
    int y = AtelPopStackInteger(a, ctx);
    int x = AtelPopStackInteger(a, ctx);
    BtlChr *c;
    float pos[4];

    x = func_001B8198(id, x, 0, 1);
    y = func_001B8198(id, y, 0, 1);
    if (x >= 0 && y >= 0) {
        c = MsGetChr(x);
        c->f101 = v;
        c->fFF = y;
        msSetChrBodyHit(c, 0, 0);
        func_001B66E0(c, pos);
        MsSetChrPos(x, pos);
        MsGetChr(y)->f100++;
    }
    return 0;
}

int _m2c_func_001E9BA8_Ch_OptposGet(int a, int b, int c) __asm__("Ch_OptposGet");
/* DEBT(FAKE) */
s32 func_001E9BA8(Actor *arg0, s32 arg1, ScriptCtx *arg2) {
    u8 sp[0x10];
    Chr *temp_4;
    s32 temp_16;
    register s32 temp_19 __asm__("$19");
    register s32 temp_19_2 __asm__("$19");
    s32 temp_20;
    u8 temp_18;

    temp_18 = *func_00144158(arg0);
    temp_20 = AtelPopStackInteger(arg0, arg2);
    temp_19 = AtelPopStackInteger(arg0, arg2);
    temp_16 = func_001B8198((s32) temp_18, AtelPopStackInteger(arg0, arg2), 0, 1);
    temp_19_2 = func_001B8198((s32) temp_18, temp_19, 0, 1);
    if (temp_16 >= 0) {
        if (temp_19_2 >= 0) {
            temp_4 = MsGetChr(temp_19_2)->chr;
            if (temp_4 != 0) {
                _m2c_func_001E9BA8_Ch_OptposGet(temp_4, temp_20, sp);
            }
            MsTransSpPos(0, (s32) sp);
            MsSetChrPosReset(temp_16, sp);
        }
    }
    return 0;
}

int func_001E9C98(Actor *a, void *unused, ScriptCtx *ctx) {
    int x = AtelPopStackInteger(a, ctx);
    int h = AtelPopStackInteger(a, ctx);
    BtlChr *c;
    h = func_001B8198(*func_00144158(a), h, 0, 1);
    if (h >= 0) {
        c = MsGetChr(h);
        x = ms_motion_trans(c, x);
        if (c->fB0 == x) return 0;
    }
    return -1;
}

int func_001E9D40(Actor *a, void *unused, ScriptCtx *ctx) {
    int x = AtelPopStackInteger(a, ctx);
    int y = AtelPopStackInteger(a, ctx);
    int z = AtelPopStackInteger(a, ctx);
    int h = func_001B8198(*func_00144158(a), z, 0, 1);
    if (h >= 0) {
        BtlChr *c = MsGetChr(h);
        if (c->chr != 0) {
            graphicCharacterInstanceSetMeshSegmentAlpha(c->chr, y, x & 1);
        }
    }
    return 0;
}

int func_001E9DF0(Actor *a, int unused, ScriptCtx *ctx) {
    int v = AtelPopStackInteger(a, ctx);
    return MsAttachWeapon(*func_00144158(a), v);
}

int func_001E9E38(Actor *ctx)
{
    if (*func_00144158(ctx) == 4) {
        MsAttachWeapon(4, 0);
    }
    return 0;
}

int func_001E9E78(Actor *ctx, void *unused, ScriptCtx *arg)
{
    return MsAttachWeapon(5, AtelPopStackInteger(ctx, arg));
}

int func_001E9EA0(Actor *a, int unused, ScriptCtx *ctx) {
    int v = AtelPopStackInteger(a, ctx);
    return MsDetachWeapon(*func_00144158(a), v);
}

int func_001E9EE8(Actor *ctx, void *unused, ScriptCtx *arg)
{
    int v = AtelPopStackInteger(ctx, arg);
    u8 id = *func_00144158(ctx);
    int a = func_001B8198(id, v, 0, 1);
    int b = func_001B8198(a, -0x10, 0, 1);

    return MsGetDamageResult(a, b, 0, 0, 0);
}

int func_001E9F68(Actor *a, void *unused, ScriptCtx *ctx) {
    int x = AtelPopStackInteger(a, ctx);
    int y = AtelPopStackInteger(a, ctx);
    int id = *func_00144158(a);
    int h = func_001B8198(id, y, 0, 1);
    return MsGetDamageLimit(h, func_001B8198(id, x, 0, 1));
}
