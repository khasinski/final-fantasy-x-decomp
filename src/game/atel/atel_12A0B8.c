/* tu_049 0x12a0b8-0x12af80: low; unk_12A0B8 (config/tu_map.tsv) */
/* Field-script opcode handlers (module name unknown; no source-file string found). See ffx/w1.h. */
#define func_0012A5D8 _hdr_func_0012A5D8
#include "common.h"
#include "ffx/q0.h"
#include "ffx/w1.h"
#include "ffx/r0.h"
#include "ffx/u0.h"
#include "ffx/v0.h"
#undef func_0012A5D8

int func_0012A0B8(Actor *a, void *op, ScriptCtx *ctx) {
    int p = AtelPopStackInteger(a, ctx);
    int q = AtelPopStackInteger(a, ctx);
    Effect *e = AtelGetMesWinWork(AtelPopStackInteger(a, ctx));

    e->h04 = q;
    e->h06 = p;
    return 0;
}

int func_0012A138(Actor *a, void *op, ScriptCtx *ctx) {
    int v = AtelPopStackInteger(a, ctx);

    AtelPushStackInteger(a, ctx, v & 0xFFFF);
    AtelPushStackInteger(a, ctx, (u32)v >> 16);
    return func_0012A0B8(a, op, ctx);
}

int func_0012A1B8(Actor *a, void *op, ScriptCtx *ctx) {
    int p = AtelPopStackInteger(a, ctx);
    int q = AtelPopStackInteger(a, ctx);
    int id = AtelPopStackInteger(a, ctx);
    Effect *e = AtelGetMesWinWork(id);

    e->b1E = q;
    e->b1F = p;
    return id;
}

INCLUDE_ASM("build/ee_asm/game/atel/atel_12A0B8", func_0012A238);

int func_0012A3D0(Actor *a, void *op, ScriptCtx *ctx) {
    int id = AtelPopStackInteger(a, ctx);

    func_0013A6D8(id);
    return id;
}

void func_0012A408(Actor *a, OpArgs *op, ScriptCtx *ctx)
{
    int v1 = AtelPopStackInteger(a, ctx);

    op->v0 = AtelPopStackInteger(a, ctx);
    op->v1 = v1;
    func_0013A6D8(op->v0);
}

int func_0012A470(Actor *a, OpArgs *op) {
    int kind = AtelGetMesWinWork(op->v0)->kind;
    int ret = 0;

    if (op->v1 == 0) {
        ret = 5;
    } else {
        switch (kind) {
        case 0:
        case 4:
            ret = 5;
            break;
        case 3:
            ret = 0;
            break;
        }
    }
    return ret;
}

int func_0012A4E0(Actor *a, OpArgs *op) {
    return op->v0;
}

void func_0012A4E8(Actor *a, OpList *op, ScriptCtx *ctx) {
    int n = AtelPopStackInteger(a, ctx);
    int cnt;
    int i;

    n = (n < 0) ? 0 : (n >= 8) ? 7 : n;
    op->v0 = n;
    op->count = 0;
    cnt = ctx->argc;
    if (cnt != 0) {
        if (cnt >= 3) {
            cnt = 2;
        }
        for (i = 0; i < cnt; i++) {
            op->arg[i] = AtelPopStackInteger(a, ctx);
            op->count++;
        }
    }
    AtelGetMesWinWork(n)->b1D |= 0x20;
}

int func_0012A5D8(Actor *a, OpList *op)
{
    int h = -1;
    int r = 0;
    int id = op->v0;
    int kind = AtelGetMesWinWork(id)->kind;

    switch (kind) {
    case 2:
        if (TOGetMessageStatus(id) == 3 && func_00205DB8(id) == kind) {
            u8 *p = (u8 *)func_00205AA0(id);

            if (func_00205A68(id) > 0) {
                h = *p;
            }
            op->h4 = h;
            r = 1;
        }
        break;
    case 0:
    case 3:
    case 4:
        op->h4 = h;
        r = 1;
        break;
    }
    return r;
}

s32 func_0012A6B0(Actor *a, OpList *op, ScriptCtx *ctx)
{
    int i;
    int r;

    AtelPushStackInteger(a, ctx, op->v0);
    func_0012A3D0(a, op, ctx);
    i = op->count;
    r = op->h4;
    while (i > 0) {
        i--;
        AtelPushStackInteger(a, ctx, op->arg[i]);
    }
    return r;
}

void func_0012A750(Actor *a, OpArgs *op, ScriptCtx *ctx) {
    int x = AtelPopStackInteger(a, ctx);
    int n = AtelPopStackInteger(a, ctx);

    n = (n < 0) ? 0 : (n < 8) ? n : 7;
    op->v0 = n;
    op->v1 = x;
    AtelGetMesWinWork(n)->b1D |= 0x10;
}

int func_0012A7E0(Actor *a, void *op_, ScriptCtx *ctx)
{
    OpArgs *op = op_;
    int r = 0;
    int id = op->v0;

    switch (AtelGetMesWinWork(id)->kind) {
    case 2:
        if (TOGetMessageStatus(id) == 3) {
            EvGameState *g = AtelGetCurCtrlWork();

            if (g->flags.w & 4) {
                func_0013A6D8(id);
                g->flags.w &= ~4;
            }
        }
        break;
    case 3:
        r = op->v1 == 0;
        break;
    case 0:
    case 4:
        r = 1;
        break;
    }
    return r;
}

int func_0012A8C0(Actor *a, void *op, ScriptCtx *ctx)
{
    AtelPushStackInteger(a, ctx, *(s32 *)op); /* DEBT(TYPE): op layout unknown */
    func_0012A3D0(a, op, ctx);
    return 0;
}

void func_0012A918(Actor *a, void *op, ScriptCtx *ctx) {
    AtelPushStackInteger(a, ctx, 0);
    func_0012A750(a, op, ctx);
}

int func_0012A968(Actor *a, void *op, ScriptCtx *ctx) {
    return func_0012A7E0(a, op, ctx);
}

int func_0012A988(Actor *a, void *op, ScriptCtx *ctx) {
    return func_0012A8C0(a, op, ctx);
}

int func_0012A9A8(Actor *a, void *op, ScriptCtx *ctx) {
    int v = AtelPopStackInteger(a, ctx);

    func_0013B2E0(a, a->slotIdx, v);
    return v;
}

int func_0012A9F0(Actor *a, void *op, ScriptCtx *ctx) {
    int v = AtelPopStackInteger(a, ctx);

    func_0013B2F8(a, a->slotIdx, v);
    return v;
}

int func_0012AA38(Actor *a, void *op, ScriptCtx *ctx) {
    int v = AtelPopStackInteger(a, ctx);

    func_0013B338(a, v);
    return v;
}

int func_0012AA80(Actor *a, void *op, ScriptCtx *ctx) {
    int v = AtelPopStackInteger(a, ctx);

    func_0013B398(a, v);
    return v;
}

int func_0012AAC8(Actor *a, void *op, ScriptCtx *ctx) {
    return AtelPopStackInteger(a, ctx);
}

INCLUDE_ASM("build/ee_asm/game/atel/atel_12A0B8", func_0012AAE8);

int func_0012AC80(void) {
    return AtelGetNowCtrlTopId();
}

int func_0012ACA0(Actor *a, void *op, ScriptCtx *ctx) {
    int v = AtelPopStackInteger(a, ctx);
    int type = a->hdr->type;

    if (type == 2 || type == 3 || type == 5 || type == 6) {
        a->flags34.b.f13 = v;
        return 1;
    }
    return 0;
}

float func_0012AD18(void) {
    return func_0013A358()->f0C;
}

float func_0012AD38(void) {
    return func_0013A358()->f10;
}

float func_0012AD58(void) {
    return func_0013A358()->f14;
}

float func_0012AD78(void) {
    return func_0013A358()->f08;
}

int func_0012AD98(void) {
    return func_0013A278();
}

int func_0012ADB8(void) {
    return func_0013A238();
}

int func_0012ADD8(void) {
    return func_0013A1D8();
}

int func_0012ADF8(void) {
    return func_0013A1B8();
}

int func_0012AE18(void) {
    return func_00143D78();
}

int func_0012AE38(Actor *a)
{
    int v = func_00143ED8(a, -1);
    int r;

    if (v >= 0) {
        return v;
    }
    r = a->flags34.b.f17;
    return r != 3 ? r : -1;
}

int func_0012AE80(Actor *a, void *op, ScriptCtx *ctx)
{
    int id = AtelPopStackInteger(a, ctx);
    int r = func_00143ED8(a, id);

    if (r < 0) {
        ActorState *st = AtelGetPosWorkAdrs(a);

        if (id == st->h28 || st->h28 == 0xFFFF) {
            int f = a->flags34.b.f17;

            r = f;
            if (f == 3) {
                r = -1;
            }
        }
    }
    return r;
}

int func_0012AF10(void) {
    return AtelGetCurCtrlWork()->w1F4;
}

float func_0012AF30(Actor *a, void *op, ScriptCtx *ctx) {
    ActorState *st = AtelGetPosWorkAdrs(a);

    return st->f1C = AtelPopStackFloat(a, ctx);
}
