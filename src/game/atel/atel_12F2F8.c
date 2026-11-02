/* tu_059 0x12f2f8-0x12f740: low; unk_12F2F8 (config/tu_map.tsv) */
#include "common.h"
#include "ffx/q0.h"
#include "ffx/r0.h"
#include "ffx/u0.h"
#include "ffx/v0.h"

/* DEBT(CAST): existing handle-based prototypes require pointer conversions. */
void func_0012F2F8(s32 a, s32 b, s32 c, s32 d)
{
    s32 saved0;
    s32 saved1;
    s32 value0;
    s32 value1;
    s32 value2;
    s32 value3;
    s32 value4;
    s32 value5;

    saved0 = d;
    value2 = AtelPopStackInteger((Actor *) a, (ScriptCtx *) c);
    value1 = AtelPopStackInteger((Actor *) a, (ScriptCtx *) c);
    value0 = AtelPopStackInteger((Actor *) a, (ScriptCtx *) c);
    saved1 = AtelPopStackInteger((Actor *) a, (ScriptCtx *) c);
    value5 = AtelPopStackInteger((Actor *) a, (ScriptCtx *) c);
    value3 = AtelPopStackInteger((Actor *) a, (ScriptCtx *) c);
    value4 = AtelPopStackInteger((Actor *) a, (ScriptCtx *) c);
    AtelPushStackInteger((Actor *) a, (ScriptCtx *) c, value4);
    AtelPushStackInteger((Actor *) a, (ScriptCtx *) c, value0);
    AtelPushStackInteger((Actor *) a, (ScriptCtx *) c, value1);
    AtelPushStackInteger((Actor *) a, (ScriptCtx *) c, value2);
    func_00129F60((Actor *) a, (void *) b, (ScriptCtx *) c);
    AtelPushStackInteger((Actor *) a, (ScriptCtx *) c, value4);
    AtelPushStackInteger((Actor *) a, (ScriptCtx *) c, 0);
    func_00129FF8((Actor *) a, (void *) b, (ScriptCtx *) c);
    AtelPushStackInteger((Actor *) a, (ScriptCtx *) c, value4);
    AtelPushStackInteger((Actor *) a, (ScriptCtx *) c, value3);
    func_00129D68((Actor *) a, (void *) b, (ScriptCtx *) c);
    AtelPushStackInteger((Actor *) a, (ScriptCtx *) c, value4);
    AtelPushStackInteger((Actor *) a, (ScriptCtx *) c, 0);
    func_0012A058((Actor *) a, (void *) b, (ScriptCtx *) c);
    AtelPushStackInteger((Actor *) a, (ScriptCtx *) c, value4);
    AtelPushStackInteger((Actor *) a, (ScriptCtx *) c, value5);
    AtelPushStackInteger((Actor *) a, (ScriptCtx *) c, saved1);
    func_0012A1B8((Actor *) a, (void *) b, (ScriptCtx *) c);
    AtelPushStackInteger((Actor *) a, (ScriptCtx *) c, value4);
    AtelPushStackInteger((Actor *) a, (ScriptCtx *) c, saved0 | 2);
    func_0012A238((Actor *) a, (ScriptCtx *) b, c);
    AtelPushStackInteger((Actor *) a, (ScriptCtx *) c, value4);
    func_0012A4E8((Actor *) a, (OpList *) b, (ScriptCtx *) c);
}

void func_0012F540(s32 a, s32 b, s32 c)
{
    func_0012F2F8(a, b, c, 0);
}

s32 func_0012F548(void)
{
    return func_0012A5D8();
}

s32 func_0012F568(void)
{
    return func_0012A6B0();
}

void func_0012F588(s32 a, s32 b, s32 c)
{
    func_0012F2F8(a, b, c, 8);
}

s32 func_0012F590(void)
{
    return func_0012A5D8();
}

s32 func_0012F5B0(void)
{
    return func_0012A6B0();
}

s32 func_0012F5D0(Actor *a, Triple *op, ScriptCtx *ctx)
{
    op->w4 = AtelPopStackInteger(a, ctx);
    op->w8 = 2;
    op->w0 = 0;
}

INCLUDE_ASM("build/ee_asm/game/atel/atel_12F2F8", func_0012F608);
