/* tu_065 0x137250-0x137a00: low; unk_137250 (config/tu_map.tsv) */
#include "common.h"
#include "ffx/q1.h"
#include "ffx/r0.h"

int func_00137250(Actor *a, void *op, ScriptCtx *ctx) {
    int ok = 0;
    const char *s = (const char *)func_0013A8A0(AtelPopStackInteger(a, ctx)); /* DEBT(CAST): int returned, used as a string */
    int room = func_001BDDC8(0);

    if ((u32)func_002F0840(s) < (u32)room) {
        Rec14 *r = MsGetSaveChrName(0);

        if (r != 0) {
            func_002F072C((char *)r, s); /* DEBT(CAST): record used as a string buffer */
            ok = 1;
        }
    }
    return ok;
}

int func_001372D8(Actor *a, void *op, ScriptCtx *ctx) {
    int x = AtelPopStackInteger(a, ctx);
    int y = AtelPopStackInteger(a, ctx);

    SndMusicStandby(AtelGetRealVarAdrs(a, y), x);
    return 1;
}

int func_00137340(void) {
    int i;

    if (TkIsDebug() != 0) {
        TOSetAlbhedFlg(-1);
        for (i = 0; i < 0x1A; i++) {
            func_00124528(i + 0xA004);
        }
    }
    return 0;
}

int func_001373A0(void) {
    int i;

    if (TkIsDebug() != 0) {
        for (i = 0; i < 0x1A; i++) {
            TkMsImportantSet(i + 0xA004);
        }
    }
    return 1;
}

int func_001373F0(Actor *a, void *op, ScriptCtx *ctx) {
    ActorState *st = AtelGetPosWorkAdrs(a);
    ActorSlotB *s = &a->slotB[a->slotIdx];
    int x = AtelPopStackInteger(a, ctx);
    int y = AtelPopStackInteger(a, ctx);
    int flags = AtelPopStackInteger(a, ctx);

    func_002D4338(s->f20 - st->f34);
    if (flags & 2) {
        return x;
    }
    return y;
}

int func_001374A8(Actor *a, void *op, ScriptCtx *ctx) {
    int v = AtelPopStackInteger(a, ctx);

    if (TkIsDebug() != 0) {
        CALL_func_00124618(v);
        if (TkIsDebug() != 0) {
            if (v != 0) {
                func_2059B48();
            }
        }
    }
    return v;
}

int func_00137508(void) {
    return 0;
}

int func_00137510(Actor *a, void *op, ScriptCtx *ctx) {
    return AtelPopStackInteger(a, ctx);
}

int func_00137530(Actor *a, void *op, ScriptCtx *ctx)
{
    EvGameState *g = AtelGetCurCtrlWork();
    float f = AtelPopStackFloat(a, ctx);
    int on = AtelPopStackInteger(a, ctx) != 0;

    g->f208 = f;
    g->flags.b.b16 = on;
    return on;
}

int func_001375B8(void) {
    EvGameState *g = AtelGetCurCtrlWork();

    TkIsDebug();
    return g->w1F4;
}

int func_001375E8(Actor *a, void *op, ScriptCtx *ctx) {
    func_0013C9C8(a, a->slotIdx);
    return 1;
}

int func_00137608(void) {
    return func_0010AEA0();
}

int func_00137628(Actor *a, void *op, ScriptCtx *ctx) {
    AtelPopStackInteger(a, ctx);
    if (TkIsDebug() != 0) {
        func_0010AE50(1);
    }
    return 1;
}

int func_00137660(Actor *a, void *op, ScriptCtx *ctx) {
    return (int)func_0013B0F8(AtelPopStackInteger(a, ctx)); /* DEBT(CAST): returns Chr * as the opcode result */
}

int func_00137688(Actor *a, void *op, ScriptCtx *ctx) {
    int on = AtelPopStackInteger(a, ctx) != 0;

    func_00269B68(on);
    return on;
}

int func_001376C0(Actor *a, void *op, ScriptCtx *ctx) {
    int v = AtelPopStackInteger(a, ctx);
    u16 *t = func_00208448();
    int i = v * 2;

    if (CALL0_func_0013A398() != 0) {
        i++;
    }
    return (int)t + t[i];
}

int func_00137718(Actor *a, void *op, ScriptCtx *ctx) {
    int x = AtelPopStackInteger(a, ctx);
    int y = AtelPopStackInteger(a, ctx);
    int z = AtelPopStackInteger(a, ctx);
    SysVt *vt;

    x = AtelGetRealVarAdrs(a, x);
    vt = GetCD();
    vt->f10(z);
    vt->f0(y, x, 0, 0);
    return 1;
}

int func_001377C8(Actor *a, void *op, ScriptCtx *ctx) {
    SysVt *vt = GetCD();

    return vt->f8(AtelPopStackInteger(a, ctx));
}

int func_00137820(Actor *a, void *op, ScriptCtx *ctx) {
    int x = AtelPopStackInteger(a, ctx);
    int y = AtelPopStackInteger(a, ctx);
    int z = AtelPopStackInteger(a, ctx);

    SndStartShoutStream(z, y, x);
    return 1;
}

int func_00137898(void) {
    func_001BCE30();
    return 1;
}

int func_001378B8(void) {
    MsDebugFullCommand();
    return 1;
}

int func_001378D8(Actor *a, void *op, ScriptCtx *ctx) {
    int flag = AtelPopStackInteger(a, ctx);
    int v = AtelPopStackInteger(a, ctx);

    if (flag != 0) {
        AtelSetEffectFlag(v);
    } else {
        func_0014AA30(v);
    }
    return flag;
}

int func_00137948(Actor *a, void *op, ScriptCtx *ctx) {
    return SndIsSepPlay(AtelPopStackInteger(a, ctx));
}

int func_00137970(Actor *a, void *op, ScriptCtx *ctx) {
    int m = AtelPopStackInteger(a, ctx);

    SndSetSoundMode(m);
    return m;
}

int func_001379A8(void) {
    return func_002D5FE8();
}

int func_001379C8(Actor *a, void *op, ScriptCtx *ctx) {
    int m = AtelPopStackInteger(a, ctx);

    func_002D5FF8(m);
    return m;
}
