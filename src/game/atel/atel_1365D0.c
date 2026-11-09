/* tu_064 0x1365d0-0x137250: low; ~Sqs (config/tu_map.tsv) */
#include "common.h"
#include "ffx/q1.h"
#include "ffx/r0.h"
#include "ffx/u0.h"

char *func_001365D0(void) {
    return D_0056A520;
}

int func_001365E0(Actor *a, void *op, ScriptCtx *ctx) {
    AtelGetRealVarAdrs(a, AtelPopStackInteger(a, ctx));
    return 1;
}

int func_00136618(void) {
    if (TkIsDebug()) {
        void *rec = func_00124828();
        int h = func_2058538(D_0030B2C0);

        if (h >= 0) {
            func_20585F0(h, rec, 0x21EC);
            func_2058698(h);
            return 1;
        }
    }
    return 0;
}

int func_00136690(void) {
    if (TkIsDebug()) {
        void *rec = func_00124828();
        int h = func_2058460(D_0030B2C0);

        if (h >= 0) {
            func_20585B8(h, rec, 0x21EC);
            func_2058698(h);
            return 1;
        }
    }
    return 0;
}

int func_00136708(Actor *a, void *op, ScriptCtx *ctx) {
    func_001BD2B0(AtelPopStackInteger(a, ctx) != 0);
    return 0;
}

int func_00136730(Actor *a, void *op, ScriptCtx *ctx) {
    func_00139748(AtelPopStackInteger(a, ctx));
    return 0;
}

int func_00136758(Actor *a, void *op, ScriptCtx *ctx) {
    AtelMapLoadBtl(AtelPopStackInteger(a, ctx));
    return 0;
}

int func_00136780(Actor *a, void *op, ScriptCtx *ctx) {
    AtelMapLoadNoCache(AtelPopStackInteger(a, ctx));
    return 0;
}

int func_001367A8(Actor *a, void *op, ScriptCtx *ctx) {
    int x = AtelPopStackInteger(a, ctx);
    int y = AtelPopStackInteger(a, ctx);

    if (TkIsDebug()) {
        func_0011F990(y, x);
    }
    return 1;
}

int func_00136810(Actor *a, void *op, ScriptCtx *ctx) {
    int v = AtelPopStackInteger(a, ctx);

    if (TkIsDebug()) {
        func_0011FA30(v);
    }
    return 1;
}

int func_00136850(void) {
    if (TkIsDebug()) {
        func_0011FAA8();
    }
    return 1;
}

int func_00136880(Actor *a, void *op, ScriptCtx *ctx) {
    int x = AtelPopStackInteger(a, ctx);
    int y = AtelPopStackInteger(a, ctx);

    func_00124858(y, x);
    return y;
}

int func_001368E0(Actor *a, void *op, ScriptCtx *ctx) {
    int v = AtelPopStackInteger(a, ctx);

    func_0014D9A0(v);
    return v;
}

int func_00136918(Actor *a, void *op, ScriptCtx *ctx) {
    int v = AtelPopStackInteger(a, ctx);

    if (TkIsDebug() != 0) {
        func_002EF240(D_0056A538);
        return yiLoadFieldParticleNo(v);
    }
    return 1;
}

int func_00136968(Actor *a, void *op, ScriptCtx *ctx) {
    int v = AtelPopStackInteger(a, ctx);

    if (TkIsDebug() != 0) {
        func_002EF240(D_0056A588);
        return yiLoadBattleFieldParticleNo(v);
    }
    return 1;
}

int func_001369B8(Actor *a, void *op, ScriptCtx *ctx) {
    int on = AtelPopStackInteger(a, ctx) != 0;

    func_001BD488(on);
    return on;
}

int func_001369F0(Actor *a, void *op, ScriptCtx *ctx) {
    int p = AtelPopStackInteger(a, ctx);
    int q = AtelPopStackInteger(a, ctx);
    int r = AtelPopStackInteger(a, ctx);
    int s = AtelPopStackInteger(a, ctx);

    func_00252888(s, r, q, p);
    return s;
}

int func_00136A88(Actor *a, void *op, ScriptCtx *ctx) {
    int v = AtelPopStackInteger(a, ctx);

    AtelGetRealVarAdrs(a, v);
    return 0;
}

int func_00136AC0(Actor *a, void *op, ScriptCtx *ctx) {
    SndStandbyStream(AtelPopStackInteger(a, ctx));
    return 1;
}

int func_00136AE8(void) {
    SndStartStream();
    return 1;
}

int func_00136B08(void) {
    return SndGetStreamState() != 0;
}

int func_00136B28(void) {
    int v = MsGetSaveConfigHiragana();

    if (v != 1) {
        v = 0;
    }
    return v;
}

int func_00136B50(void) {
    return MsGetSaveConfigCreditName() != 0;
}

/* DEBT(CAST): existing handle-based prototypes require pointer conversions. */
s32 func_00136B70(Actor *arg0, int unused1, ScriptCtx *arg2)
{
    s32 value0;
    s32 value1;
    s32 value2;
    s32 value3;
    void *value4;

    value0 = AtelGetRealVarAdrs(arg0, AtelPopStackInteger(arg0, arg2));
    if (TkIsDebug() != 0)
    {
        value1 = func_2058460((s8 *) value0);
        if (value1 >= 0)
        {
            value2 = func_2058630(value1);
            value3 = TkMalloc(value2 + 0x40);
            value4 = func_00124DE0(value3, 0x40);
            func_20585B8(value1, value4, value2);
            func_2058698(value1);
            func_002D7D08((s32) value4, value2);
            TkFree(value3);
        }
    }
    return 1;
}

int func_00136C38(Actor *a, void *op, ScriptCtx *ctx) {
    SndSepPlaySimple(AtelPopStackInteger(a, ctx));
    return 1;
}

int func_00136C60(Actor *a, void *op, ScriptCtx *ctx) {
    SndSepStop(AtelPopStackInteger(a, ctx));
    return 1;
}

int func_00136C88(Actor *a, void *op, ScriptCtx *ctx) {
    int v = AtelPopStackInteger(a, ctx);
    int r = AtelGetRealVarAdrs(a, v);

    if (TkIsDebug() != 0) {
        return SqsSetProjectBase((const char *)r); /* DEBT(CAST): value passed as pointer */
    }
    return 1;
}

int func_00136CE0(Actor *a, void *op, ScriptCtx *ctx) {
    int x = AtelPopStackInteger(a, ctx);
    int y = AtelPopStackInteger(a, ctx);
    int z = AtelPopStackInteger(a, ctx);

    func_002D6E48(1, z, y, x);
    return 1;
}

int func_00136D60(Actor *a, void *op, ScriptCtx *ctx) {
    int x = AtelPopStackInteger(a, ctx);
    int y = AtelPopStackInteger(a, ctx);
    int z = AtelPopStackInteger(a, ctx);

    func_002D6E48(0, z, y, x);
    return 1;
}

int func_00136DE0(Actor *a, void *op, ScriptCtx *ctx) {
    int x = AtelPopStackInteger(a, ctx);
    int y = AtelPopStackInteger(a, ctx);

    func_002D6E48(5, y, x, 0);
    return 1;
}

int func_00136E48(Actor *a, void *op, ScriptCtx *ctx) {
    int x = AtelPopStackInteger(a, ctx);
    int y = AtelPopStackInteger(a, ctx);
    int z = AtelPopStackInteger(a, ctx);

    func_002D6E48(2, z, y, x);
    return 1;
}

int func_00136EC8(Actor *a, void *op, ScriptCtx *ctx) {
    int x = AtelPopStackInteger(a, ctx);
    int y = AtelPopStackInteger(a, ctx);
    int z = AtelPopStackInteger(a, ctx);

    func_002D6E48(3, z, y, x);
    return 1;
}

int func_00136F48(Actor *a, void *op, ScriptCtx *ctx) {
    int x = AtelPopStackInteger(a, ctx);
    int y = AtelPopStackInteger(a, ctx);
    int z = AtelPopStackInteger(a, ctx);

    func_002D6E48(4, z, y, x);
    return 1;
}

int func_00136FC8(Actor *a, void *op, ScriptCtx *ctx) {
    func_002D6E48(6, AtelPopStackInteger(a, ctx), 0, 0);
    return 1;
}

int func_00137000(Actor *a, void *op, ScriptCtx *ctx) {
    func_002D6E48(7, AtelPopStackInteger(a, ctx), 0, 0);
    return 1;
}

int func_00137038(Actor *a, void *op, ScriptCtx *ctx) {
    return AtelPopStackInteger(a, ctx);
}

int func_00137058(Actor *a, void *op, ScriptCtx *ctx) {
    return AtelPopStackInteger(a, ctx);
}

int func_00137078(Actor *a, void *op, ScriptCtx *ctx) {
    int v = AtelPopStackInteger(a, ctx);

    if (TkIsDebug() != 0) {
        return Sg_EnableDrawGui(v);
    }
    return 1;
}

int func_001370C0(Actor *a, void *op, ScriptCtx *ctx) {
    int vx = AtelPopStackInteger(a, ctx);
    int vy = AtelPopStackInteger(a, ctx);
    int vz = AtelPopStackInteger(a, ctx);
    int joint = AtelPopStackInteger(a, ctx);
    int id = AtelPopStackInteger(a, ctx);
    Chr *chr;
    float m[16]; /* 4x4 matrix, translation at [12..14] */

    vz = AtelGetRealVarAdrs(a, vz);
    vy = AtelGetRealVarAdrs(a, vy);
    vx = AtelGetRealVarAdrs(a, vx);
    chr = AtelGetBasicWork(id)->ptr9C;
    if (chr == 0) {
        *(float *)vz = 0; /* DEBT(CAST): script slot address used as float pointer */
        *(float *)vy = 0;
        *(float *)vx = 0;
    } else {
        func_001072F8(chr, joint, m);
        *(float *)vz = m[12];
        *(float *)vy = m[13];
        *(float *)vx = m[14];
    }
    return 1;
}

void func_001371D0(Actor *a, void *op, ScriptCtx *ctx) {
    int v;

    AtelPopStackInteger(a, ctx);
    v = AtelPopStackInteger(a, ctx);
    func_001463F0(func_0013A278());
    AtelEventRemoveForBattle(func_0013A278());
    func_00148390(1, v, func_0013A278(), 0);
}

int func_00137248(void) {
    return 1;
}
