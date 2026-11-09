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

typedef struct {
    int x0;
    int x4;
    int (*fn8)(int);
} CdObj12F608;

typedef struct {
    u8 pad0[0x48];
    int x48;
    u8 pad4C[0x204 - 0x4C];
    int x204;
} CtrlWork12F608;

int func_002D6768(void);
void AtelSndTransSepSPKDataGroup(int a, int b, int c);
void SndStandbySepWave(void);

int func_0012F608(Actor *a, Triple *op)
{
    int ret = 0;
    CtrlWork12F608 *ctrl = (CtrlWork12F608 *)AtelGetCurCtrlWork();
    int state = op->w0;
    int val = op->w4;

    switch (state) {
    case 0:
        {
            CdObj12F608 *cd = (CdObj12F608 *)GetCD();

            if (func_002D6768() == 0 && cd->fn8(1) == 0) {
                AtelSndTransSepSPKDataGroup(ctrl->x48, ctrl->x204, val);
                state = 1;
            }
        }
        break;
    case 1:
        if (func_002D6768() == 0) {
            SndStandbySepWave();
            state = 2;
        }
        break;
    case 2:
        if (func_002D6768() == 0) {
            state = 3;
        }
        break;
    case 3:
        if (--op->w8 <= -1) {
            ret = 1;
        }
        break;
    }
    op->w0 = state;
    return ret;
}
