/* tu_047 0x127970-0x128a58: low; unk_127970 (config/tu_map.tsv) */
/* Field-script opcode handlers (module name unknown; no source-file string found). See ffx/w1.h. */
#include "common.h"
#include "ffx/q0.h"
#include "ffx/w1.h"
#include "ffx/r0.h"
#include "ffx/u0.h"
#include "ffx/v0.h"

void func_00127970(Actor *a, void *op, ScriptCtx *ctx) {
    ActorSlot *s = &a->slot[a->slotIdx];
    float x = AtelPopStackFloat(a, ctx);
    float y = AtelPopStackFloat(a, ctx);

    s->f0C = x;
    s->f08 = y;
}

float func_001279E0(Actor *a, int unused, ScriptCtx *ctx)
{
    BindInfo *info = func_0013C9C8(a, a->slotIdx)->info;
    float scale = AtelPopStackFloat(a, ctx);
    float offset = AtelPopStackFloat(a, ctx);

    if (scale > 0.0f) {
        info->scale = scale;
    } else {
        info->scale = 1.0f;
    }
    info->offset = offset;
    return offset;
}

float func_00127A78(Actor *a, void *op, ScriptCtx *ctx) {
    AtelPopStackFloat(a, ctx);
    return AtelPopStackFloat(a, ctx);
}

int func_00127AB8(void) {
    return func_0013A1B8();
}

int func_00127AD8(void) {
    return func_0013A218();
}

int func_00127AF8(void) {
    return func_0013A238();
}

int func_00127B18(void) {
    return func_0013A258();
}

float func_00127B38(Actor *a, void *op, ScriptCtx *ctx) {
    ActorSlot *s = &a->slot[a->slotIdx];

    return s->f18 = AtelPopStackFloat(a, ctx);
}

INCLUDE_ASM("build/ee_asm/game/atel/atel_127970", func_00127B78);

INCLUDE_ASM("build/ee_asm/game/atel/atel_127970", func_00127D40);

int func_00127F08(Actor *a) {
    return (a->slot[a->slotIdx].flags & 0x7F) ? 0 : 5;
}

int func_00127F30(Actor *a) {
    return (func_0013C9C8(a, a->slotIdx)->info->flags & 0x1F) ? 0 : 5;
}

float func_00127F60(Actor *a, void *op, ScriptCtx *ctx) {
    float v = AtelPopStackFloat(a, ctx);

    func_0013B440(a, v);
    return v;
}

float func_00127FA8(Actor *a, void *op, ScriptCtx *ctx) {
    float v = AtelPopStackFloat(a, ctx);

    func_0013B4B8(a, v);
    return v;
}

float func_00127FF0(Actor *a, void *op, ScriptCtx *ctx) {
    float v = AtelPopStackFloat(a, ctx);

    func_0013B410(a, v);
    return v;
}

int func_00128038(Actor *a, void *op, ScriptCtx *ctx) {
    int x = AtelPopStackInteger(a, ctx);
    int y = AtelPopStackInteger(a, ctx);

    AtelSetEventJump2(y, x, 1);
    return 0;
}

int func_00128098(Actor *a, void *op, ScriptCtx *ctx) {
    int x = AtelPopStackInteger(a, ctx);
    int y = AtelPopStackInteger(a, ctx);

    AtelSetEventJump2(y, x, 1);
    return 0;
}

int func_001280F8(Actor *a, void *op, ScriptCtx *ctx) {
    int x = AtelPopStackInteger(a, ctx);
    int y = AtelPopStackInteger(a, ctx);

    AtelSetEventJump2(y, x, 0);
    return 0;
}

int func_00128158(Actor *a, void *op, ScriptCtx *ctx) {
    int x = AtelPopStackInteger(a, ctx);
    int y = AtelPopStackInteger(a, ctx);

    AtelSetEventJump2(y, x, 0);
    return 0;
}

float func_001281B8(Actor *a) {
    ActorState *st = AtelGetPosWorkAdrs(a);
    ActorSlot *s = &a->slot[a->slotIdx];

    return func_002D4520(st->x, st->z, s->f28, s->f30);
}

float func_00128208(Actor *a, void *op, ScriptCtx *ctx) {
    ActorState *st = AtelGetPosWorkAdrs(a);
    float x = AtelPopStackFloat(a, ctx);
    float z;

    AtelPopStackFloat(a, ctx); /* skipped operand */
    z = AtelPopStackFloat(a, ctx);
    return func_002D4520(st->x, st->z, z, x);
}

float func_00128288(Actor *a) {
    float outA, outB;
    ActorState *st = AtelGetPosWorkAdrs(a);
    ActorSlot *s = &a->slot[a->slotIdx];

    func_002D45C0(&outA, &outB, st->x, st->y, st->z, s->f28, s->f2C, s->f30);
    return outB;
}

float func_001282E8(Actor *a, void *op, ScriptCtx *ctx) {
    float outA, outB;
    ActorState *st = AtelGetPosWorkAdrs(a);
    float p = AtelPopStackFloat(a, ctx);
    float q = AtelPopStackFloat(a, ctx);
    float r = AtelPopStackFloat(a, ctx);

    func_002D45C0(&outA, &outB, st->x, st->y, st->z, r, q, p);
    return outB;
}

float func_00128388(Actor *a, void *op, ScriptCtx *ctx) {
    ActorState *st = AtelGetPosWorkAdrs(a);

    return st->f20 = AtelPopStackFloat(a, ctx);
}

float func_001283D8(Actor *a, void *op, ScriptCtx *ctx) {
    ActorState *st = AtelGetPosWorkAdrs(a);

    return st->f24 = AtelPopStackFloat(a, ctx);
}

void func_00128428(Actor *a, void *op, ScriptCtx *ctx) {
    ActorSlot *s = &a->slot[a->slotIdx];

    s->f44 = func_002D4338(AtelPopStackFloat(a, ctx));
}

void func_00128470(Actor *a, void *op, ScriptCtx *ctx) {
    ActorSlot *s = &a->slot[a->slotIdx];

    s->f48 = func_002D4338(AtelPopStackFloat(a, ctx));
}

float func_001284B8(Actor *a, void *op, ScriptCtx *ctx) {
    ActorState *st = AtelGetPosWorkAdrs(a);
    float v = func_002D4338(AtelPopStackFloat(a, ctx));
    ActorSlotB *s = &a->slotB[a->slotIdx];

    s->f20 = v;
    s->f2C = func_002D4338(st->f34 - v);
    return v;
}

float func_00128540(Actor *a, void *op, ScriptCtx *ctx) {
    ActorState *st = AtelGetPosWorkAdrs(a);
    float v = func_002D4338(AtelPopStackFloat(a, ctx));
    ActorSlotB *s = &a->slotB[a->slotIdx];

    s->f24 = v;
    s->f30 = func_002D4338(st->f30 - v);
    return v;
}

float func_001285C8(Actor *a, void *op, ScriptCtx *ctx) {
    ActorState *st = AtelGetPosWorkAdrs(a);
    float v = func_002D4338(AtelPopStackFloat(a, ctx));
    ActorSlotB *s = &a->slotB[a->slotIdx];

    s->f28 = v;
    s->f34 = func_002D4338(st->f38 - v);
    return v;
}

float func_00128650(Actor *a, void *op, ScriptCtx *ctx) {
    ActorState *st = AtelGetPosWorkAdrs(a);

    return st->f34 = func_002D4338(AtelPopStackFloat(a, ctx));
}

float func_001286A8(Actor *a, void *op, ScriptCtx *ctx) {
    ActorState *st = AtelGetPosWorkAdrs(a);

    return st->f30 = func_002D4338(AtelPopStackFloat(a, ctx));
}

float func_00128700(Actor *a, void *op, ScriptCtx *ctx) {
    ActorState *st = AtelGetPosWorkAdrs(a);

    return st->f38 = func_002D4338(AtelPopStackFloat(a, ctx));
}

float func_00128758(Actor *a, void *op, ScriptCtx *ctx) {
    float v = AtelPopStackFloat(a, ctx);

    return func_0013B4E8(a, a->slotIdx, v);
}

float func_00128790(Actor *a, void *op, ScriptCtx *ctx) {
    float v = AtelPopStackFloat(a, ctx);

    return func_0013B500(a, a->slotIdx, v);
}

float func_001287C8(Actor *a, void *op, ScriptCtx *ctx) {
    float v = AtelPopStackFloat(a, ctx);

    return func_0013B518(a, a->slotIdx, v);
}

float func_00128800(Actor *a, void *op, ScriptCtx *ctx) {
    float v = AtelPopStackFloat(a, ctx);

    return func_0013B530(a, a->slotIdx, v);
}

float func_00128838(Actor *a, void *op, ScriptCtx *ctx) {
    float v = AtelPopStackFloat(a, ctx);

    return func_0013B548(a, a->slotIdx, v);
}

float func_00128870(Actor *a, void *op, ScriptCtx *ctx) {
    float v = AtelPopStackFloat(a, ctx);

    return func_0013B560(a, a->slotIdx, v);
}

float func_001288A8(Actor *a, void *op, ScriptCtx *ctx) {
    float v = AtelPopStackFloat(a, ctx);

    func_0013B578(a, v);
    return v;
}

float func_001288F0(Actor *a, void *op, ScriptCtx *ctx) {
    float v = AtelPopStackFloat(a, ctx);

    func_0013B638(a, v);
    return v;
}

float func_00128938(Actor *a, void *op, ScriptCtx *ctx) {
    float v = AtelPopStackFloat(a, ctx);

    func_0013B698(a, v);
    return v;
}

float func_00128980(Actor *a, void *op, ScriptCtx *ctx) {
    float v = AtelPopStackFloat(a, ctx);

    func_0013B5D8(a, v);
    return v;
}

float func_001289C8(Actor *a, void *op, ScriptCtx *ctx) {
    float v = AtelPopStackFloat(a, ctx);

    func_0013B6F8(a, v);
    return v;
}

float func_00128A10(Actor *a, void *op, ScriptCtx *ctx) {
    float v = AtelPopStackFloat(a, ctx);

    func_0013B758(a, v);
    return v;
}
