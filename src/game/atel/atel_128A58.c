/* tu_048 0x128a58-0x12a0b8: low; unk_128A58 (config/tu_map.tsv) */
/* Field-script opcode handlers (module name unknown; no source-file string found). See ffx/w1.h. */
#include "common.h"
#include "ffx/q0.h"
#include "ffx/w1.h"
#include "ffx/r0.h"
#include "ffx/u0.h"
#include "ffx/v0.h"

int func_00128A58(Actor *a, void *op, ScriptCtx *ctx) {
    Actor *t = AtelGetBasicWork(AtelPopStackInteger(a, ctx));
    int i;

    for (i = 0; i < 9; i++) {
        func_0013BD70(t, i);
    }
    return 0;
}

int func_00128AB8(Actor *a, void *op, ScriptCtx *ctx) {
    func_0013BD70(AtelGetBasicWork(AtelPopStackInteger(a, ctx)), -1);
    return 0;
}

int func_00128AF0(Actor *a, void *op, ScriptCtx *ctx) {
    Actor *t = AtelGetBasicWork(AtelPopStackInteger(a, ctx));
    int i;

    for (i = 0; i < 9; i++) {
        func_0013BE58(t, i);
    }
    return 0;
}

int func_00128B50(Actor *a, void *op, ScriptCtx *ctx) {
    func_0013BE58(AtelGetBasicWork(AtelPopStackInteger(a, ctx)), -1);
    return 0;
}

int func_00128B88(Actor *a, void *op, ScriptCtx *ctx) {
    int id = AtelPopStackInteger(a, ctx);
    Actor *t;

    if (id < 0) {
        t = a;
    } else {
        t = AtelGetBasicWork(id);
    }
    return t->id;
}

float func_00128BD0(Actor *a, void *op, ScriptCtx *ctx) {
    return AtelGetPosWorkAdrs(AtelGetBasicWork(AtelPopStackInteger(a, ctx)))->x;
}

float func_00128C00(Actor *a, void *op, ScriptCtx *ctx) {
    return AtelGetPosWorkAdrs(AtelGetBasicWork(AtelPopStackInteger(a, ctx)))->y;
}

float func_00128C30(Actor *a, void *op, ScriptCtx *ctx) {
    return AtelGetPosWorkAdrs(AtelGetBasicWork(AtelPopStackInteger(a, ctx)))->z;
}

int func_00128C60(Actor *a, void *op, ScriptCtx *ctx) {
    int n = AtelPopStackInteger(a, ctx);

    a->flagsAB |= 1 << n;
    return n;
}

int func_00128CA0(Actor *a, void *op, ScriptCtx *ctx) {
    a->flagsAB &= ~(1 << AtelPopStackInteger(a, ctx));
    return 0;
}

int func_00128CE8(Actor *a) {
    func_0013C1C0(a, 0xFF);
    return 0;
}

int func_00128D08(Actor *a, void *op, ScriptCtx *ctx) {
    func_0013C1C0(a, AtelPopStackInteger(a, ctx));
    return 0;
}

float func_00128D40(Actor *a) {
    return func_0013C9C8(a, a->slotIdx)->info->f38;
}

float func_00128D68(Actor *a) {
    return func_0013C9C8(a, a->slotIdx)->info->f3C;
}

float func_00128D90(Actor *a) {
    return func_0013C9C8(a, a->slotIdx)->info->f40;
}

int func_00128DB8(Actor *a) {
    int id = a->id;

    func_00144968(id);
    return id;
}

INCLUDE_ASM("build/ee_asm/game/atel/atel_128A58", func_00128DE8);

int func_00128EC8(Actor *a, void *op, ScriptCtx *ctx)
{
    int v = AtelPopStackInteger(a, ctx);

    if (AtelGetCurCtrlWork()->h1A == 0) {
        if (a->stateAA == 1 && a->ptr9C != 0) {
            ((void (*)(Chr *, int))Ch_SoundSetId)(a->ptr9C, v); /* DEBT(CAST): declared with an s8, the original passes the int */
        }
        a->bAF = v;
        SndEventSetPcToActorFoot(v, a->id);
    }
    return v;
}

int func_00128F48(Actor *a, void *op, ScriptCtx *ctx)
{
    EvGameState *g = AtelGetCurCtrlWork();
    int v = AtelPopStackInteger(a, ctx);
    Actor *o = AtelGetBasicWork(AtelPopStackInteger(a, ctx));

    if (g->h1A == 0) {
        if (o->stateAA == 1 && o->ptr9C != 0) {
            ((void (*)(Chr *, int))Ch_SoundSetId)(o->ptr9C, v); /* DEBT(CAST): declared with an s8, the original passes the int */
        }
        o->bAF = v;
        SndEventSetPcToActorFoot(v, o->id);
    }
    return v;
}

int func_00128FF8(void) {
    return func_002D26C8(0, 0, func_0013AAD8());
}

int func_00129028(void) {
    return func_002D26C8(0, 0, func_0013AAF8());
}

int func_00129058(void) {
    return func_002D26C8(0, 0, func_0013AB08());
}

int func_00129088(void) {
    return func_002D26C8(0, 0, func_0013AB18());
}

int func_001290B8(void) {
    return func_002D26C8(0, 0, func_0013AB28());
}

int func_001290E8(void)
{
    return func_0013AAD8();
}

int func_00129108(void)
{
    return func_0013AAF8();
}

int func_00129128(void)
{
    return func_0013AB08();
}

int func_00129148(void)
{
    return func_0013AB18();
}

int func_00129168(void)
{
    return func_0013AB28();
}

s32 func_00129188(Actor *a, void *op, ScriptCtx *ctx)
{
    s32 bit = AtelPopStackInteger(a, ctx);

    return (func_002D26C8(0, 0, func_0013AAD8()) >> bit) & 1;
}

s32 func_001291D0(Actor *a, void *op, ScriptCtx *ctx)
{
    s32 bit = AtelPopStackInteger(a, ctx);

    return (func_002D26C8(0, 0, func_0013AAF8()) >> bit) & 1;
}

s32 func_00129218(Actor *a, void *op, ScriptCtx *ctx)
{
    s32 bit = AtelPopStackInteger(a, ctx);

    return (func_002D26C8(0, 0, func_0013AB08()) >> bit) & 1;
}

s32 func_00129260(Actor *a, void *op, ScriptCtx *ctx)
{
    s32 bit = AtelPopStackInteger(a, ctx);

    return (func_002D26C8(0, 0, func_0013AB18()) >> bit) & 1;
}

s32 func_001292A8(Actor *a, void *op, ScriptCtx *ctx)
{
    s32 bit = AtelPopStackInteger(a, ctx);

    return (func_002D26C8(0, 0, func_0013AB28()) >> bit) & 1;
}

s32 func_001292F0(Actor *a, void *op, ScriptCtx *ctx)
{
    s32 bit = AtelPopStackInteger(a, ctx);

    return (func_0013AAD8() >> bit) & 1;
}

s32 func_00129328(Actor *a, void *op, ScriptCtx *ctx)
{
    s32 bit = AtelPopStackInteger(a, ctx);

    return (func_0013AAF8() >> bit) & 1;
}

s32 func_00129360(Actor *a, void *op, ScriptCtx *ctx)
{
    s32 bit = AtelPopStackInteger(a, ctx);

    return (func_0013AB08() >> bit) & 1;
}

s32 func_00129398(Actor *a, void *op, ScriptCtx *ctx)
{
    s32 bit = AtelPopStackInteger(a, ctx);

    return (func_0013AB18() >> bit) & 1;
}

s32 func_001293D0(Actor *a, void *op, ScriptCtx *ctx)
{
    s32 bit = AtelPopStackInteger(a, ctx);

    return (func_0013AB28() >> bit) & 1;
}

INCLUDE_ASM("build/ee_asm/game/atel/atel_128A58", func_00129408);

INCLUDE_ASM("build/ee_asm/game/atel/atel_128A58", func_00129528);

int func_00129628(Actor *a, void *op, ScriptCtx *ctx)
{
    ActorState *st = AtelGetPosWorkAdrs(a);
    float f = AtelPopStackFloat(a, ctx);
    u8 t = a->hdr->type;

    if (t == 2 || t == 5 || t == 3 || t == 6) {
        st->f1C = f;
        a->flags34.b.b16 = 1;
        return 1;
    }
    return 0;
}

int func_001296B8(Actor *a, void *op, ScriptCtx *ctx)
{
    int v = AtelPopStackInteger(a, ctx) != 0;
    u8 t = a->hdr->type;

    if (t == 2 || t == 3 || t == 5 || t == 6) {
        a->flags34.w = (a->flags34.w & ~0x80) | (v << 7) | 0x10000;
        return 1;
    }
    return 0;
}

int func_00129738(Actor *a, void *op, ScriptCtx *ctx)
{
    int v = AtelPopStackInteger(a, ctx);
    Actor *o = AtelGetBasicWork(AtelPopStackInteger(a, ctx));
    u8 t;

    if (v) {
        v = 1;
    }
    t = o->hdr->type;
    if (t == 2 || t == 3 || t == 5 || t == 6) {
        o->flags34.w = (o->flags34.w & ~0x80) | ((v & 1) << 7) | 0x10000;
        return 1;
    }
    return 0;
}

s32 func_001297F0(Actor *a, void *op, ScriptCtx *ctx)
{
    return func_001296B8(a, op, ctx);
}

s32 func_00129810(Actor *a, void *op, ScriptCtx *ctx)
{
    return func_00129738(a, op, ctx);
}

INCLUDE_ASM("build/ee_asm/game/atel/atel_128A58", func_00129830);

INCLUDE_ASM("build/ee_asm/game/atel/atel_128A58", func_001298E8);

int func_001299A0(Actor *a, void *op, ScriptCtx *ctx) {
    func_0013CE10(a, ctx, -1.0f);
    return func_001298E8(a, op, ctx);
}

int func_001299F8(Actor *a, void *op, ScriptCtx *ctx) {
    ActorState *st = AtelGetPosWorkAdrs(a);
    float v = AtelPopStackFloat(a, ctx);

    if (a->hdr->type == 3 || a->hdr->type == 6) {
        st->f34 = v;
        a->flags34.b.b16 = 1;
        return 0;
    }
    return 0;
}

int func_00129A78(Actor *a, void *op, ScriptCtx *ctx) {
    ActorState *st = AtelGetPosWorkAdrs(a);

    st->f48 = AtelPopStackFloat(a, ctx);
    a->flags34.b.b16 = 1;
    return 1;
}

int func_00129AD8(Actor *a, void *op, ScriptCtx *ctx) {
    return func_00129A78(a, op, ctx);
}

int func_00129AF8(void) {
    AtelUcOn();
    return 1;
}

int func_00129B18(void) {
    AtelUcOff();
    return 0;
}

int func_00129B38(Actor *a, void *op, ScriptCtx *ctx) {
    int r = func_001454C8(a, AtelPopStackInteger(a, ctx));

    func_00145470();
    return r;
}

int func_00129B78(Actor *a) {
    func_001454C8(a, 1);
    func_00145470();
    return 1;
}

int func_00129BA0(Actor *a) {
    func_001454C8(a, 0);
    func_00145470();
    return 0;
}

void func_00129BC8(Actor *a, void *op, ScriptCtx *ctx) {
    ActorState *st = AtelGetPosWorkAdrs(a);

    st->f40 = (int)AtelPopStackFloat(a, ctx);
    a->flags34.b.b16 = 1;
}

void func_00129C38(Actor *a, void *op, ScriptCtx *ctx) {
    ActorState *st = AtelGetPosWorkAdrs(a);

    st->f44 = (int)AtelPopStackFloat(a, ctx);
    a->flags34.b.b16 = 1;
}

void func_00129CA8(Actor *a, void *op, ScriptCtx *ctx) {
    ActorState *st = AtelGetPosWorkAdrs(a);

    st->f3C = AtelPopStackFloat(a, ctx);
    a->flags34.b.b16 = 1;
}

void func_00129D08(Actor *a, void *op, ScriptCtx *ctx) {
    ActorState *st = AtelGetPosWorkAdrs(a);

    st->f4C = AtelPopStackFloat(a, ctx);
    a->flags34.b.b16 = 1;
}

int func_00129D68(Actor *a, void *op, ScriptCtx *ctx) {
    int src = AtelPopStackInteger(a, ctx);
    Effect *e = AtelGetMesWinWork(AtelPopStackInteger(a, ctx));

    e->w08 = func_0013A8A0(src);
    e->w0C = func_0013A8E0(src);
    e->h16 = func_0013A900(src, func_00138240());
    return 0;
}

int func_00129DF0(Actor *a, void *op, ScriptCtx *ctx) {
    int p = AtelPopStackInteger(a, ctx);
    int q = AtelPopStackInteger(a, ctx);
    int r = AtelPopStackInteger(a, ctx);
    Effect *e;

    p = AtelGetRealVarAdrs(a, p);
    e = AtelGetMesWinWork(r);
    e->w0C = e->w08 = p;
    e->h16 = q;
    return 0;
}

int func_00129E88(Actor *a, void *op, ScriptCtx *ctx) {
    int p = AtelPopStackInteger(a, ctx);
    int q = AtelPopStackInteger(a, ctx);
    Effect *e = AtelGetMesWinWork(AtelPopStackInteger(a, ctx));

    e->w0C = e->w08 = p;
    e->h16 = q;
    return 0;
}

int func_00129F08(Actor *a, void *op, ScriptCtx *ctx) {
    int id = AtelPopStackInteger(a, ctx);
    int v;

    if (func_00138240()) {
        v = func_0013A8E0(id);
    } else {
        v = func_0013A8A0(id);
    }
    return func_00205DE0(v);
}

int func_00129F60(Actor *a, void *op, ScriptCtx *ctx) {
    int p = AtelPopStackInteger(a, ctx);
    int q = AtelPopStackInteger(a, ctx);
    int r = AtelPopStackInteger(a, ctx);
    Effect *e = AtelGetMesWinWork(AtelPopStackInteger(a, ctx));

    e->b1C = p;
    e->h00 = r;
    e->h02 = q;
    return 0;
}

int func_00129FF8(Actor *a, void *op, ScriptCtx *ctx) {
    int v = AtelPopStackInteger(a, ctx);
    int id = AtelPopStackInteger(a, ctx);

    AtelGetMesWinWork(id)->b20 = v;
    return id;
}

int func_0012A058(Actor *a, void *op, ScriptCtx *ctx) {
    int v = AtelPopStackInteger(a, ctx);
    int id = AtelPopStackInteger(a, ctx);

    AtelGetMesWinWork(id)->w18 = v;
    return id;
}
