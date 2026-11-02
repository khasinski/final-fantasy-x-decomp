/* tu_055 0x12c788-0x12ce80: low; unk_12C788 (config/tu_map.tsv) */
/* Field-script opcode handlers (module name unknown; no source-file string found). See ffx/w1.h. */
#include "common.h"
#include "ffx/q0.h"
#include "ffx/w1.h"
#include "ffx/r0.h"
#include "ffx/u0.h"
#include "ffx/v0.h"

int func_0012C788(Actor *a, void *op, ScriptCtx *ctx) {
    int v = AtelPopStackInteger(a, ctx);

    MsSetSavePlyJoin(v, 1);
    return v;
}

int func_0012C7C0(Actor *a, void *op, ScriptCtx *ctx) {
    int id = AtelPopStackInteger(a, ctx);
    int v[3];
    int i;

    MsSetSavePlyJoin(id, 0);
    MsGetSavePartyMember(&v[0], &v[1], &v[2]);
    for (i = 0; i < 3; i++) {
        if (v[i] == id && id != 0xFF) {
            v[i] = 0xFF;
        }
    }
    MsSetSavePartyMember(v[0], v[1], v[2]);
    return id;
}

int func_0012C848(Actor *a, void *op, ScriptCtx *ctx) {
    return MsGetSavePlyJoin(AtelPopStackInteger(a, ctx)) == 1;
}

int func_0012C878(Actor *a) {
    int v[3];
    int id = a->w40;
    int i;

    MsGetSavePartyMember(&v[0], &v[1], &v[2]);
    for (i = 0; i < 3; i++) {
        if (id == v[i] && id != 0xFF) {
            return 1;
        }
    }
    return 0;
}

int func_0012C8E0(Actor *a, void *op, ScriptCtx *ctx) {
    int v = AtelPopStackInteger(a, ctx);
    int w = AtelPopStackInteger(a, ctx);

    if (v == -1) {
        v = 0xFF;
    }
    MsExchangeSaveParty(v, w);
    return v;
}

int func_0012C948(Actor *a, void *op, ScriptCtx *ctx) {
    int id = AtelPopStackInteger(a, ctx);
    int v[3];
    int i;

    MsGetSavePartyMember(&v[0], &v[1], &v[2]);
    for (i = 0; i < 3; i++) {
        if (id == v[i] && id != 0xFF) {
            return 1;
        }
    }
    return 0;
}

void func_0012C9B8(Actor *a, void *op, ScriptCtx *ctx) {
    a->hB16 = AtelPopStackInteger(a, ctx);
}

void func_0012C9E8(Actor *a, void *op, ScriptCtx *ctx) {
    a->wAF0 = AtelPopStackInteger(a, ctx);
}

int func_0012CA18(Actor *a) {
    return a->wAF0;
}

int func_0012CA20(Actor *a, void *op, ScriptCtx *ctx) {
    AtelPushStackInteger(a, ctx, a->id);
    return func_00128A58(a, op, ctx);
}

int func_0012CA78(Actor *a, void *op, ScriptCtx *ctx) {
    AtelPushStackInteger(a, ctx, a->id);
    return func_00128AF0(a, op, ctx);
}

int func_0012CAD0(Actor *a, void *op, ScriptCtx *ctx) {
    AtelPushStackInteger(a, ctx, a->id);
    return func_00128AB8(a, op, ctx);
}

int func_0012CB28(Actor *a, void *op, ScriptCtx *ctx) {
    AtelPushStackInteger(a, ctx, a->id);
    return func_00128B50(a, op, ctx);
}

void func_0012CB80(Actor *a, OpArgs *op, ScriptCtx *ctx) {
    op->v0 = AtelPopStackInteger(a, ctx);
}

int func_0012CBB0(void) {
    int r = 0;

    if (GetCD()->f8(1) == 0 && TkSndReportStatus() == 0) {
        if (func_0015A550() == 0) {
            r = 5;
        }
    }
    if (func_00138638()) {
        r = 0;
    }
    return r;
}

s32 func_0012CC18(Actor *a, s32 *p, ScriptCtx *ctx)
{
    s32 v = *p;

    if (TkSndIsStandbyVoice() == 0) {
        SndStandbyStream(v);
    }
    return 0;
}

void func_0012CC50(Actor *a, void *op, ScriptCtx *ctx) {
    EvGameState *g = AtelGetCurCtrlWork();

    g->w214 = AtelPopStackInteger(a, ctx);
}

void func_0012CCA0(Actor *a, OpArgs *op)
{
    EvGameState *g = AtelGetCurCtrlWork();
    int v;

    op->v1 = 0;
    if (g->w214 < 0) {
        v = func_002D5BA0();
    } else if (func_002D9868()) {
        v = g->w214;
    } else {
        v = 0;
    }
    op->v0 = v;
    g->w214 = -1;
}

INCLUDE_ASM("build/ee_asm/game/atel/atel_12C788", func_0012CD10);

s32 func_0012CDD8(Actor *a, void *op, ScriptCtx *ctx)
{
    s32 v = func_0014D990();

    SndStartStream2(v, func_0014D980());
    return 0;
}

int func_0012CE18(void) {
    SndStopStream();
    return 0;
}

int func_0012CE38(void) {
    return SndGetStreamState() != 0;
}

int func_0012CE58(void)
{
    int r;

    r = SndGetStreamState();
    if (r == 0) {
        r = 1;
    } else {
        r = 0;
    }
    return r;
}
