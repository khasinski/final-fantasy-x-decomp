/* tu_057 0x12d498-0x12dd60: low; unk_12D498 (config/tu_map.tsv) */
/* Field-script opcode handlers (module name unknown; no source-file string found). See ffx/w1.h. */
#include "common.h"
#include "ffx/q0.h"
#include "ffx/w1.h"
#include "ffx/r0.h"
#include "ffx/u0.h"
#include "ffx/v0.h"

int func_0012D498(Actor *a, void *op, ScriptCtx *ctx) {
    s32 *w = (s32 *)AtelGetCurCtrlWork(); /* DEBT(CAST): flag word of the event state */
    int on = AtelPopStackInteger(a, ctx) != 0;

    *w = (*w & ~0x800) | (on << 11);
    return on;
}

INCLUDE_ASM("build/ee_asm/game/atel/atel_12D498", func_0012D500);

int func_0012D5F8(Actor *a, void *op, ScriptCtx *ctx) {
    s32 *w = (s32 *)AtelGetCurCtrlWork(); /* DEBT(CAST): flag word of the event state */
    int on = AtelPopStackInteger(a, ctx) != 0;

    *w = (*w & ~0x1000) | (on << 12);
    return on;
}

int func_0012D660(void) {
    return AtelGetCurCtrlWork()->flags.b12;
}

int func_0012D688(Actor *a) {
    return a->slotIdx;
}

int func_0012D690(Actor *a, void *op, ScriptCtx *ctx) {
    int id = AtelPopStackInteger(a, ctx);
    int v[3];
    int i;

    if (id == 0xFFFFFFFF) {
        return -1;
    }
    MsGetSavePartyMember(&v[0], &v[1], &v[2]);
    for (i = 0; i < 3; i++) {
        if (id == v[i] && id != 0xFF) {
            return i;
        }
    }
    return -1;
}

int func_0012D710(Actor *a) {
    return a->w40;
}

int func_0012D718(Actor *a, void *op, ScriptCtx *ctx) {
    return AtelGetBasicWork(AtelPopStackInteger(a, ctx))->flags34.b.b5;
}

int func_0012D748(Actor *a, void *op, ScriptCtx *ctx) {
    int on = AtelPopStackInteger(a, ctx) != 0;

    a->flags34.b.b27 = on;
    return on;
}

int func_0012D790(Actor *a, void *op, ScriptCtx *ctx) {
    int v = AtelGetRealVarAdrs(a, AtelPopStackInteger(a, ctx));

    func_00144080(a, v);
    return 1;
}

int func_0012D7D8(Actor *a, void *op, ScriptCtx *ctx) {
    return func_001499C8(AtelPopStackInteger(a, ctx));
}

int func_0012D800(Actor *a, void *op, ScriptCtx *ctx) {
    return func_00149A30(AtelPopStackInteger(a, ctx));
}

int func_0012D828(Actor *a, void *op, ScriptCtx *ctx) {
    return func_00149A98(AtelPopStackInteger(a, ctx));
}

int func_0012D850(Actor *a, void *op, ScriptCtx *ctx) {
    int v = AtelPopStackInteger(a, ctx);

    func_0019CD70(v);
    return v;
}

void func_0012D888(Actor *a, OpArgs *op, ScriptCtx *ctx) {
    int x = AtelPopStackInteger(a, ctx);
    int y = AtelPopStackInteger(a, ctx);

    op->v0 = x;
    op->v1 = (y > 0) ? y : 1;
}

int func_0012D8F8(Actor *a, OpArgs *op)
{
    int x = op->v0;
    int y = op->v1;
    int r;

    if (x < 0) {
        r = 5;
    } else if (func_001427A8(x, y) != 0) {
        r = 0;
    } else {
        r = 5;
    }
    return r;
}

void func_0012D938(Actor *a, OpArgs *op, ScriptCtx *ctx) {
    int x = AtelPopStackInteger(a, ctx);
    int y = AtelPopStackInteger(a, ctx);

    op->v0 = func_0013B008(x);
    if (y <= 0) {
        y = 1;
    }
    op->v1 = y;
}

int func_0012D9B0(Actor *a, OpArgs *op) {
    return func_0012D8F8(a, op);
}

int func_0012D9D0(Actor *a, void *op, ScriptCtx *ctx)
{
    int n = AtelPopStackInteger(a, ctx);
    int c = AtelPopStackInteger(a, ctx);
    int o = AtelGetRealVarAdrs(a, AtelPopStackInteger(a, ctx));

    if (TkIsDebug()) {
        func_002EF0D0((void *)o, c, n); /* DEBT(CAST): AtelGetRealVarAdrs returns the object address as int */
    }
    return n;
}

int func_0012DA60(void) {
    if (TkIsDebug()) {
        return func_00124648();
    }
    return 1;
}

int func_0012DA98(Actor *a, void *op, ScriptCtx *ctx) {
    int v = AtelPopStackInteger(a, ctx);

    func_00124668(v);
    return v;
}

int func_0012DAD0(Actor *a, void *op, ScriptCtx *ctx) {
    int v = AtelPopStackInteger(a, ctx);

    AtelGetMesWinWork(v);
    return func_002075F8(v);
}

int func_0012DB08(Actor *a, void *op, ScriptCtx *ctx) {
    return func_00138C98(AtelPopStackInteger(a, ctx));
}

void func_0012DB30(Actor *a, OpArgs *op, ScriptCtx *ctx) {
    op->v0 = AtelPopStackInteger(a, ctx);
}

int func_0012DB60(void) {
    SysVt *vt = GetCD();
    int r = 0;

    if (TkSndReportStatus() == 0) {
        if (vt->f8(1) == 0) {
            r = 5;
        }
    }
    return r;
}

int func_0012DBB8(Actor *a, OpArgs *op) {
    int v = op->v0;

    SndMusicRead(v);
    return v;
}

int func_0012DBE8(Actor *a, void *op, ScriptCtx *ctx) {
    int v = AtelPopStackInteger(a, ctx);

    if (AtelGetMusicNumber() == v) {
        AtelRegistMusicNumber(-1);
    }
    SndMusicClear(v);
    SndMusicClear(0x8A);
    return 1;
}

int func_0012DC38(void) {
    int v = AtelGetMusicNumber();

    if (v >= 0) {
        SndMusicStop(v);
    }
    AtelRegistMusicNumber(-1);
    return 1;
}

int func_0012DC70(Actor *a, void *op, ScriptCtx *ctx) {
    int v = AtelPopStackInteger(a, ctx);

    if (AtelGetMusicNumber() == v) {
        AtelRegistMusicNumber(-1);
    }
    SndMusicStop(v);
    return 1;
}

int func_0012DCB8(Actor *a, void *op, ScriptCtx *ctx) {
    int v = AtelPopStackInteger(a, ctx);

    SndMusicReplayPointClear(v);
    SndMusicStart(v);
    AtelRegistMusicNumber(v);
    return 1;
}

int func_0012DD00(Actor *a, void *op, ScriptCtx *ctx) {
    int v = AtelPopStackInteger(a, ctx);

    SndMusicStart(v);
    AtelRegistMusicNumber(v);
    return 1;
}

int func_0012DD40(void) {
    func_002D85D0();
    return 1;
}
