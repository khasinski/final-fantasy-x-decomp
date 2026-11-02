/* tu_050 0x12af80-0x12b4f0: low; unk_12AF80 (config/tu_map.tsv) */
/* Field-script opcode handlers (module name unknown; no source-file string found). See ffx/w1.h. */
#include "common.h"
#include "ffx/q0.h"
#include "ffx/w1.h"
#include "ffx/r0.h"
#include "ffx/u0.h"
#include "ffx/v0.h"

float func_0012AF80(Actor *a, void *op, ScriptCtx *ctx) {
    ActorState *st = AtelGetPosWorkAdrs(a);

    return st->f2C = AtelPopStackFloat(a, ctx);
}

int func_0012AFD0(Actor *a, void *op, ScriptCtx *ctx)
{
    int id = AtelPopStackInteger(a, ctx);
    int r;

    switch (AtelGetMesWinWork(id)->kind) {
    case 0:
    case 3:
    case 4:
        return 1;
    case 2:
        r = TOGetMessageStatus(id);
        if (r == 3) {
            return 1;
        }
    }
    return 0;
}

float func_0012B058(Actor *a, void *op, ScriptCtx *ctx) {
    return AtelGetPosWorkAdrs(a)->f34;
}

float func_0012B078(Actor *a, void *op, ScriptCtx *ctx) {
    return AtelGetPosWorkAdrs(a)->f20;
}

float func_0012B098(Actor *a, void *op, ScriptCtx *ctx) {
    return AtelGetPosWorkAdrs(a)->f30;
}

float func_0012B0B8(Actor *a, void *op, ScriptCtx *ctx) {
    return AtelGetPosWorkAdrs(a)->f38;
}

float func_0012B0D8(Actor *a, void *op, ScriptCtx *ctx) {
    return AtelGetPosWorkAdrs(a)->f24;
}

float func_0012B0F8(Actor *a, void *op, ScriptCtx *ctx) {
    return func_0012B058(AtelGetBasicWork(AtelPopStackInteger(a, ctx)), op, ctx);
}

float func_0012B148(Actor *a, void *op, ScriptCtx *ctx) {
    return func_0012B078(AtelGetBasicWork(AtelPopStackInteger(a, ctx)), op, ctx);
}

float func_0012B198(Actor *a, void *op, ScriptCtx *ctx) {
    return func_0012B098(AtelGetBasicWork(AtelPopStackInteger(a, ctx)), op, ctx);
}

float func_0012B1E8(Actor *a, void *op, ScriptCtx *ctx) {
    return func_0012B0B8(AtelGetBasicWork(AtelPopStackInteger(a, ctx)), op, ctx);
}

float func_0012B238(Actor *a, void *op, ScriptCtx *ctx) {
    return func_0012B0D8(AtelGetBasicWork(AtelPopStackInteger(a, ctx)), op, ctx);
}

float func_0012B288(Actor *a, void *op, ScriptCtx *ctx) {
    float v = AtelPopStackFloat(a, ctx);

    func_0013B4A0(a, v);
    return v;
}

float func_0012B2D0(Actor *a, void *op, ScriptCtx *ctx) {
    ActorState *st = AtelGetPosWorkAdrs(a);
    float v;

    func_0013BE58(a, -1);
    v = func_002D4338(AtelPopStackFloat(a, ctx));
    st->f20 = v;
    st->f34 = v;
    AtelSetMoveHokanMode(a, 0);
    switch (a->stateAA) {
    case 1:
        if (a->ptr9C != 0) {
            Ch_SetDirF(a->ptr9C, st->f20);
            func_00110300(a->ptr9C, st->f20);
        }
        break;
    case 4:
    case 5:
        AtelSetBindObject(a);
        break;
    }
    return v;
}

float func_0012B3A8(Actor *a, void *op, ScriptCtx *ctx) {
    ActorState *st = AtelGetPosWorkAdrs(a);
    float v;

    func_0013BE58(a, -1);
    v = func_002D4338(AtelPopStackFloat(a, ctx));
    st->f24 = v;
    st->f30 = v;
    switch (a->stateAA) {
    case 4:
    case 5:
        AtelSetBindObject(a);
        break;
    }
    return v;
}

float func_0012B440(Actor *a, void *op, ScriptCtx *ctx) {
    ActorState *st = AtelGetPosWorkAdrs(a);
    float v;

    func_0013BE58(a, -1);
    v = func_002D4338(AtelPopStackFloat(a, ctx));
    st->f38 = v;
    AtelSetMoveHokanMode(a, 0);
    switch (a->stateAA) {
    case 1:
        break;
    case 4:
    case 5:
        AtelSetBindObject(a);
        break;
    }
    return v;
}
