/* tu_046 0x126d68-0x127970: low; ~Atel (config/tu_map.tsv) */
#include "common.h"
#include "ffx/q0.h"
#include "ffx/r0.h"
#include "ffx/s0.h"
#include "ffx/u0.h"
#include "ffx/v0.h"
#include "ffx/w1.h"

s32 func_00126D68(Actor *a, void *op, ScriptCtx *ctx)
{
    s32 v = AtelPopStackInteger(a, ctx);

    func_0014B0B0(a, v);
    return 1;
}

void _m2c_func_00126DA0_TkCh_Dispose(int v) __asm__("TkCh_Dispose");
/* DEBT(FAKE) */
s32 func_00126DA0(Actor *a, void *op, ScriptCtx *ctx) {
    register s32 _cond __asm__("$3");
    s32 temp_20;
    s32 var_17;
    s32 var_6;
    u16 temp_5;
    register u8 temp_3 __asm__("$3");

    temp_20 = AtelPopStackInteger(a, ctx);
    temp_3 = a->stateAA;
    switch (temp_3) {
    case 0:
    case 3:
        break;
    case 4:
    case 5:
        AtelSetBindObject(a);
        break;
    case 1:
        var_17 = 0;
        if (a->ptr9C != 0) {
            __asm__ volatile("" : "+r"(var_17));
            var_6 = var_17;
            do {
                AtelPushStackInteger(a, ctx, var_6);
                var_17 += 1;
                func_00126D68(a, op, ctx);
                var_6 = var_17;
            } while ((_cond = (var_17 < 2)) != 0);
            _m2c_func_00126DA0_TkCh_Dispose((s32) a->ptr9C);
            a->w38 &= ~0x10;
            if (temp_20 != 0) {
                ChN_DataDispose((s32) a->hA8, 0);
                temp_5 = a->hA8;
                func_002EF240(D_0056A420, temp_5, temp_5);
            }
            a->ptr9C = 0;
        }
        break;
    case 2:
        MsBindOffCamera(a);
        break;
    }
    a->stateAA = 0;
    a->hA8 = 0;
    return 0;
}

int func_00126EC8(Actor *a, void *op, ScriptCtx *ctx) {
    AtelPushStackInteger(a, ctx, 0);
    return func_00126DA0(a, op, ctx);
}

/* DEBT(TYPE): this caller passes the full unsigned byte to the legacy signed-byte interface. */
s32 func_00126F20(Actor *actor, s32 kind, ScriptCtx *script)
{
    ActorState *state;
    Chr *chr;
    EvGameState *game;
    s32 resource;

    game = AtelGetCurCtrlWork();
    state = AtelGetPosWorkAdrs(actor);
    func_00126EC8(actor, kind, script);
    resource = AtelPopStackInteger(actor, script);
    actor->ptr9C = TkCh_Allocate2(resource, actor->id);
    TkChSetBattleChrNum(actor);
    CALL_Ch_SoundSetId_U8(actor->ptr9C, actor->bAF);
    Ch_SetDirF(actor->ptr9C, state->f20);
    func_00110300(actor->ptr9C, state->f20);
    actor->hA8 = (u16) resource;
    actor->stateAA = 1;
    AtelSetPos3d(actor, 0, state->x, state->y, state->z);
    if (game->h1A == 0)
    {
        if (actor->stateAA == 1)
        {
            chr = actor->ptr9C;
            if (chr != 0)
            {
                CALL_Ch_SoundSetId_U8(chr, actor->bAF);
            }
        }
        SndEventSetPcToActorFoot((s32) actor->bAF, (s32) actor->id);
    }
    if (actor->w38 & 0x20)
    {
        AtelBindEff2On(actor, 0);
    }
    if (actor->w38 & 0x40)
    {
        AtelBindEff2On(actor, 1);
    }
    if (actor->w38 & 0x80)
    {
        AtelBindEff2On(actor, 2);
    }
    return 0;
}

s32 func_00127088(void)
{
    return CALL0_func_00126F20();
}

void func_001270A8(Actor *a, Pair32 *out, ScriptCtx *ctx)
{
    out->w0 = AtelPopStackInteger(a, ctx);
    out->w4 = 0;
}

s32 MsVoiceStanby(Actor *a, Pair32 *st)
{
    s32 r = 0;
    SysVt *vt = GetCD();
    s32 chr = st->w0;
    s32 state = st->w4;

    switch (state) {
    case 0:
        if (func_00138638() != 0) {
            break;
        }
        state = 1;
    case 1:
        if (vt->f8(1) != 0) {
            break;
        }
        if (TkSndReportStatus() != 0) {
            break;
        }
        if (func_0015A550() != 0) {
            break;
        }
        func_00138648(a->id);
    case 2:
        ChN_ReadSystemMGRPstart(chr, 0);
        state = 3;
    case 3:
        if (ChN_ReadSystemMGRPsync(chr, 0) == 1) {
            break;
        }
        Ch_DataRead(chr);
        state = 4;
    case 4:
        r = 5;
        if (Ch_DataReadSync(chr) == 1) {
            r = 0;
        }
        break;
    }
    st->w4 = state;
    return r;
}

int func_001271F8(Actor *a, void *op, ScriptCtx *ctx) {
    int r;

    AtelPushStackInteger(a, ctx, *(int *)op); /* DEBT(TYPE): op layout unknown */
    r = func_00126F20(a, op, ctx);
    func_001386A0(a->id);
    return r;
}

INCLUDE_ASM("build/ee_asm/game/atel/atel_126D68", func_00127260);

int func_001273D8(Actor *a, void *op, ScriptCtx *ctx)
{
    int n;
    int m;

    AtelPopStackInteger(a, ctx);
    n = AtelPopStackInteger(a, ctx);
    m = AtelPopStackInteger(a, ctx);
    func_00126EC8(a, op, ctx);
    a->stateAA = 2;
    a->hA8 = m;
    MsBindCamera((int)a, m, n); /* DEBT(CAST): declared (int, int, int) */
    if (m == 1) {
        a->flags34.w |= 0x100000;
    } else {
        a->flags34.w &= ~0x100000;
    }
    AtelPushStackInteger(a, ctx, 2);
    func_0012ACA0(a, op, ctx);
    return 0;
}

s32 func_001274C8(Actor *a, void *op, ScriptCtx *ctx)
{
    a->hA8 = AtelPopStackInteger(a, ctx);
    a->stateAA = 3;
    return 0;
}

s32 func_00127500(Actor *a, void *op, ScriptCtx *ctx)
{
    a->hA8 = AtelPopStackInteger(a, ctx);
    a->stateAA = 4;
    return 0;
}

s32 func_00127538(Actor *a, void *op, ScriptCtx *ctx)
{
    a->hA8 = AtelPopStackInteger(a, ctx);
    a->stateAA = 5;
    return 0;
}

s32 func_00127570(void)
{
    return 0;
}

float func_00127578(Actor *a, void *op, ScriptCtx *ctx)
{
    float v = AtelPopStackFloat(a, ctx);

    func_0013B3F8(a, a->slotIdx, v);
    return v;
}

int func_001275C0(void)
{
    return AtelGetCharHandle();
}

u8 func_001275E0(Chr *chr)
{
    return chr->bAA;
}

u16 func_001275E8(Chr *chr)
{
    return chr->hA8;
}

int func_001275F0(Actor *a)
{
    return AtelGetActorType(a->id);
}

s32 func_00127610(Actor *a, s32 unused, ScriptCtx *ctx)
{
    s32 v = AtelPopStackInteger(a, ctx);

    Sg_SetPlayer(v);
    return v;
}

int func_00127648(Actor *a, void *op, ScriptCtx *ctx) {
    float x = AtelPopStackFloat(a, ctx);

    AtelSetPos(a, 0, AtelPopStackFloat(a, ctx), x);
    return 0;
}

int func_001276B0(Actor *a, void *op, ScriptCtx *ctx)
{
    float z, y, x;

    AtelGetCurCtrlWork();
    z = AtelPopStackFloat(a, ctx);
    y = AtelPopStackFloat(a, ctx);
    x = AtelPopStackFloat(a, ctx);
    AtelSetPos3d(a, 0, x, y, z);
    return 0;
}

int func_00127738(Actor *a, void *op, ScriptCtx *ctx) {
    float x = AtelPopStackFloat(a, ctx);

    AtelSetPos(a, 1, AtelPopStackFloat(a, ctx), x);
    return 0;
}

int func_001277A0(Actor *a, void *op, ScriptCtx *ctx)
{
    float z = AtelPopStackFloat(a, ctx);
    float y = AtelPopStackFloat(a, ctx);
    float x = AtelPopStackFloat(a, ctx);

    AtelSetPos3d(a, 1, x, y, z);
    return 0;
}

int func_00127820(Actor *a, void *op, ScriptCtx *ctx) {
    float x = AtelPopStackFloat(a, ctx);

    func_0013BD60(a, AtelPopStackFloat(a, ctx), x);
    return 0;
}

int func_00127880(Actor *a, void *op, ScriptCtx *ctx)
{
    float z = AtelPopStackFloat(a, ctx);
    float y = AtelPopStackFloat(a, ctx);
    float x = AtelPopStackFloat(a, ctx);

    func_0013BCE0(a, x, y, z);
    return 0;
}

int func_00127900(Actor *a, void *op, ScriptCtx *ctx) {
    func_0013EB20(a, AtelPopStackInteger(a, ctx));
    return 0;
}

int func_00127938(Actor *a, void *op, ScriptCtx *ctx) {
    func_0013EC20(a, AtelPopStackInteger(a, ctx));
    return 0;
}
