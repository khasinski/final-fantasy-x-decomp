/* tu_058 0x12dd60-0x12f2f8: low; unk_12DD60 (config/tu_map.tsv) */
/* Field-script opcode handlers (module name unknown; no source-file string found). See ffx/w1.h. */
#include "common.h"
#include "ffx/q0.h"
#include "ffx/w1.h"
#include "ffx/r0.h"
#include "ffx/u0.h"
#include "ffx/v0.h"

void func_0012DD60(void) {
}

int func_0012DD68(void)
{
    int a = SndSyncMusicStandby(0);
    int r = a | func_002D6768();

    if (r != 0) {
        r = 0;
    } else {
        r = 5;
    }
    return r;
}

int func_0012DDA8(void)
{
    return SndSyncMusicStandby(0);
}

int func_0012DDC8(Actor *a, void *op, ScriptCtx *ctx)
{
    int o = AtelPopStackInteger(a, ctx);
    int v = AtelPopStackInteger(a, ctx);
    int k = AtelPopStackInteger(a, ctx);
    OpArgs *r;

    o = AtelGetRealVarAdrs(a, o);
    r = AtelGetSnd3dWork(k);
    r->v0 = v;
    r->v1 = o;
    return 1;
}

int func_0012DE58(Actor *a, void *op, ScriptCtx *ctx) {
    int n = AtelPopStackInteger(a, ctx);
    U0Q1F0 *e = AtelGetSnd3dWork(AtelPopStackInteger(a, ctx));

    if (e->p4) {
        *e->p4 |= 2;
        e->h8 = n;
    }
    return 1;
}

int func_0012DED0(Actor *a, void *op, ScriptCtx *ctx)
{
    float x, y, z;
    int k;
    V0Rec1364F0 *r;

    z = AtelPopStackFloat(a, ctx);
    y = AtelPopStackFloat(a, ctx);
    x = AtelPopStackFloat(a, ctx);
    k = AtelPopStackInteger(a, ctx);
    r = AtelGetSnd3dWork(AtelPopStackInteger(a, ctx));

    if (r->flags != 0) {
        *r->flags &= ~2;
        if (k) {
            r->v14[0] = x;
            r->v14[1] = y;
            r->v14[2] = z;
        } else {
            r->v8[0] = x;
            r->v8[1] = y;
            r->v8[2] = z;
        }
    }
    return 1;
}

int func_0012DFB0(Actor *a, void *op, ScriptCtx *ctx) {
    int n = AtelPopStackInteger(a, ctx);
    s32 *e = AtelGetSnd3dWork(n); /* DEBT(TYPE): Q1F0Ent, first member */

    if (e[0]) {
        SndSepStop(e[0]);
        func_00136520(n);
    }
    return 1;
}

s32 func_0012E000(Actor *a, void *op, ScriptCtx *ctx)
{
    s32 *p = AtelGetSnd3dWork(AtelPopStackInteger(a, ctx));

    if (*p != 0) {
        func_00136428(p, 1);
    }
    return 1;
}

s32 func_0012E040(Actor *a, void *op, ScriptCtx *ctx)
{
    u32 v = AtelPopStackInteger(a, ctx);

    if (v < 0xFF) {
        TkMsImportantSet(v + 0xA004);
        return 1;
    }
    return 0;
}

s32 func_0012E080(void)
{
    return func_002023C0();
}

int func_0012E0A0(Actor *a, void *op, ScriptCtx *ctx)
{
    int w = AtelPopStackInteger(a, ctx);
    int b23 = AtelPopStackInteger(a, ctx);
    int b22 = AtelPopStackInteger(a, ctx);
    int id = AtelPopStackInteger(a, ctx);
    V0EffectW *e = (V0EffectW *)AtelGetMesWinWork(id);

    e->b22 = b22;
    e->b23 = b23;
    e->w24 = w;
    return id;
}

s32 func_0012E140(Actor *a, s32 unused, ScriptCtx *ctx)
{
    return func_00207A80(AtelPopStackInteger(a, ctx));
}

s32 func_0012E168(void)
{
    return func_0014A190();
}

s32 func_0012E188(void)
{
    return AtelPopMember();
}

s32 func_0012E1A8(void)
{
    return func_0014A330();
}

int func_0012E1C8(Actor *a, void *op, ScriptCtx *ctx)
{
    V0GameFlags *g = (V0GameFlags *)AtelGetCurCtrlWork();
    int x = AtelPopStackInteger(a, ctx);
    int y = AtelPopStackInteger(a, ctx);
    int t = 0;
    int r = 1;

    if (x) {
        t = 1;
    }
    g->b17 = t;
    if (!y) {
        r = 0;
    }
    g->b18 = r;
    return r;
}

int func_0012E270(Actor *a, void *op, ScriptCtx *ctx) {
    s32 *w = (s32 *)AtelGetCurCtrlWork(); /* DEBT(CAST): flag word of the event state */
    int on = AtelPopStackInteger(a, ctx) != 0;

    *w = (*w & ~0x80000) | (on << 19);
    return on;
}

s32 func_0012E2D8(Actor *a, void *op, ScriptCtx *ctx)
{
    s32 v = AtelPopStackInteger(a, ctx);
    Actor *e = AtelGetBasicWork(v);

    OFF_W(e, 0x34) = (OFF_W(e, 0x34) & 0xF9FFFFFF) | 0x02000000;
    return v;
}

s32 func_0012E330(Actor *a, void *op, ScriptCtx *ctx)
{
    s32 v = AtelPopStackInteger(a, ctx);
    Actor *e = AtelGetBasicWork(v);

    OFF_W(e, 0x34) = (OFF_W(e, 0x34) & 0xF9FFFFFF) | 0x04000000;
    return v;
}

s32 func_0012E388(Actor *a, void *op, ScriptCtx *ctx)
{
    s32 v = AtelPopStackInteger(a, ctx);
    Actor *e = AtelGetBasicWork(v);

    OFF_W(e, 0x34) = ((OFF_W(e, 0x34) | 0x10000000) & 0xF9FFFFFF) | 0x02000000;
    return v;
}

s32 func_0012E3E8(Actor *a, void *op, ScriptCtx *ctx) {
    int n = AtelPopStackInteger(a, ctx);
    int k;

    if (n >= 0) {
        if (n > 1) {
            k = 1;
        } else {
            k = n;
        }
    } else {
        k = 0;
    }
    return AtelGetElemId(a->w40, k);
}

int func_0012E438(Actor *a, void *op, ScriptCtx *ctx)
{
    int k = AtelPopStackInteger(a, ctx);
    Actor *o = AtelGetBasicWork(AtelPopStackInteger(a, ctx));
    int n;

    if (k >= 0) {
        n = k;
        if (n > 1) {
            n = 1;
        }
    } else {
        n = 0;
    }
    if ((u32)o->w40 < 8) {
        return AtelGetElemId(o->w40, n);
    }
    return 0;
}

int func_0012E4D0(Actor *a, void *op, ScriptCtx *ctx)
{
    int x = AtelPopStackInteger(a, ctx);
    int y = AtelPopStackInteger(a, ctx);
    int z = AtelPopStackInteger(a, ctx);

    x = AtelGetRealVarAdrs(a, x);
    func_0014C7F8(AtelGetRealVarAdrs(a, z), y, x);
    return 1;
}

int func_0012E568(Actor *a, void *op, ScriptCtx *ctx) {
    int n = AtelPopStackInteger(a, ctx);
    int m = AtelPopStackInteger(a, ctx);

    AtelRegistShape(m, AtelGetRealVarAdrs(a, n));
    return m;
}

s32 func_0012E5D8(Actor *a, s32 unused, ScriptCtx *ctx)
{
    s32 v = AtelPopStackInteger(a, ctx);

    func_0014CAB8(v);
    return v;
}

s32 func_0012E610(Actor *a, void *op, ScriptCtx *ctx)
{
    s32 first = AtelPopStackInteger(a, ctx);
    s32 second = AtelPopStackInteger(a, ctx);

    func_0014C9B0(second, first);
    return second;
}

int func_0012E670(Actor *a, void *op, ScriptCtx *ctx)
{
    int d = AtelPopStackInteger(a, ctx);
    int c = AtelPopStackInteger(a, ctx);
    int b = AtelPopStackInteger(a, ctx);
    int v = AtelPopStackInteger(a, ctx);

    func_0014C928(v, b, d, c);
    return v;
}

s32 func_0012E708(Actor *a, void *op, ScriptCtx *ctx)
{
    s32 first = AtelPopStackInteger(a, ctx);
    s32 second = AtelPopStackInteger(a, ctx);

    func_0014CA78(second, first);
    return second;
}

s32 func_0012E768(Actor *a, void *op, ScriptCtx *ctx)
{
    s32 first = AtelPopStackInteger(a, ctx);
    s32 second = AtelPopStackInteger(a, ctx);

    func_0014C8D8(second, first);
    return second;
}

int func_0012E7C8(Actor *a, void *op, ScriptCtx *ctx)
{
    int c = AtelPopStackInteger(a, ctx);
    int b = AtelPopStackInteger(a, ctx);
    int v = AtelPopStackInteger(a, ctx);

    func_0014C9E8(v, b, c);
    return v;
}

int func_0012E848(Actor *a, void *op, ScriptCtx *ctx)
{
    float y = AtelPopStackFloat(a, ctx);
    float x = AtelPopStackFloat(a, ctx);
    int v = AtelPopStackInteger(a, ctx);

    func_0014CA20(v, x, y);
    return v;
}

int func_0012E8C8(Actor *a, void *op, ScriptCtx *ctx) {
    int n = AtelPopStackInteger(a, ctx);

    if (n < 0) {
        n = 0;
    }
    if (n > 13) {
        n = 13;
    }
    return TkGetControlerAnalog(0, 0, TkGetControlerBindAnalogIndex(0, 0, n));
}

int func_0012E918(Actor *a, void *op, ScriptCtx *ctx)
{
    int v = AtelPopStackInteger(a, ctx);

    if (v < 0) {
        v = 0;
    }
    return TkGetControlerAnalog(0, 0, v < 14 ? v : 13);
}

s32 func_0012E958(Actor *a, s32 unused, ScriptCtx *ctx)
{
    return AtelPopStackInteger(a, ctx);
}

s32 func_0012E978(Actor *a, s32 unused, ScriptCtx *ctx)
{
    return AtelPopStackInteger(a, ctx);
}

int func_0012E998(Actor *a, void *op, ScriptCtx *ctx)
{
    float f = AtelPopStackFloat(a, ctx);
    Actor *o = AtelGetBasicWork(AtelPopStackInteger(a, ctx));
    ActorState *s = AtelGetPosWorkAdrs(a);
    ActorState *t = AtelGetPosWorkAdrs(o);

    return func_002D4850(f, s->x - t->x, s->y - t->y, s->z - t->z);
}

int func_0012EA30(Actor *a, void *op, ScriptCtx *ctx) {
    func_0013CE10(a, ctx, AtelGetPosWorkAdrs(a)->f48);
    return func_0012E998(a, op, ctx);
}

int func_0012EA90(Actor *a, void *op, ScriptCtx *ctx) {
    s32 *w = (s32 *)AtelGetCurCtrlWork(); /* DEBT(CAST): flag word of the event state */
    int on = AtelPopStackInteger(a, ctx) != 0;

    *w = (*w & ~0x400000) | (on << 22);
    return on;
}

int func_0012EAF8(Actor *a, void *op, ScriptCtx *ctx) {
    EvGameState *ev = AtelGetCurCtrlWork();
    int x = AtelPopStackInteger(a, ctx);

    ev->h6 = AtelPopStackInteger(a, ctx);
    ev->h4 = x;
    return 1;
}

int func_0012EB68(Actor *a, void *op, ScriptCtx *ctx) {
    int n = AtelPopStackInteger(a, ctx);
    Rec124828 *r = func_00124828();
    int k;

    if (n >= 0) {
        if (n > 7) {
            k = 7;
        } else {
            k = n;
        }
    } else {
        k = 0;
    }
    return r->w2C[k];
}

int func_0012EBC0(Actor *a, void *op, ScriptCtx *ctx)
{
    int n = AtelPopStackInteger(a, ctx);
    int i = AtelPopStackInteger(a, ctx);
    Rec124828 *p = func_00124828();
    int k;

    if (i >= 0) {
        if (i > 7) {
            k = 7;
        } else {
            k = i;
        }
    } else {
        k = 0;
    }
    n += p->w2C[k];
    p->w2C[k] = n;
    return n;
}

int func_0012EC50(Actor *a, void *op, ScriptCtx *ctx)
{
    int n = AtelPopStackInteger(a, ctx);
    int i = AtelPopStackInteger(a, ctx);
    Rec124828 *p = func_00124828();
    int k;

    if (i >= 0) {
        if (i > 7) {
            k = 7;
        } else {
            k = i;
        }
    } else {
        k = 0;
    }
    n = p->w2C[k] - n;
    if (n < 0) {
        n = 0;
    }
    p->w2C[k] = n;
    return n;
}

int func_0012ECE8(Actor *a, void *op, ScriptCtx *ctx)
{
    int v = AtelPopStackInteger(a, ctx);
    int i = AtelPopStackInteger(a, ctx);
    Rec124828 *p;
    int k;

    if (i >= 0) {
        if (i > 7) {
            k = 7;
        } else {
            k = i;
        }
    } else {
        k = 0;
    }
    i = k; /* DEBT(FAKE): clamping through k steers register allocation */
    p = func_00124828();
    if (v < 0) {
        v = 0;
    }
    p->w2C[i] = v;
    return i;
}

int func_0012ED78(Actor *a, void *op, ScriptCtx *ctx)
{
    Rec124828 *p = func_00124828();
    u32 v = AtelPopStackInteger(a, ctx);
    int bit = v & 0x1F;
    u32 i = v >> 5;

    if (i < 20) {
        p->w4C[i] &= ~(1 << bit);
    }
    return 1;
}

int func_0012EDF8(Actor *a, void *op, ScriptCtx *ctx)
{
    Rec124828 *p = func_00124828();
    u32 v = AtelPopStackInteger(a, ctx);
    int bit = v & 0x1F;
    u32 i = v >> 5;

    if (i < 20) {
        p->w4C[i] |= 1 << bit;
    }
    return 1;
}

int func_0012EE78(Actor *a, void *op, ScriptCtx *ctx)
{
    Rec124828 *p = func_00124828();
    u32 v = AtelPopStackInteger(a, ctx);
    int bit = v & 0x1F;
    u32 i = v >> 5;
    u32 r = 0;

    if (i < 20) {
        r = p->w4C[i] & (1 << bit);
    }
    return r != 0;
}

s32 func_0012EEF0(void)
{
    return MsGetGIL();
}

s32 func_0012EF10(Actor *arg0, s32 arg1, ScriptCtx *arg2) {
    s32 _r;
    s32 _m1;
    _r = MsPayGIL(-AtelPopStackInteger(arg0, arg2));
    _m1 = -1;
    __asm__("" : "+r"(_m1));
    return _m1 < _r;
}

s32 func_0012EF40(Actor *arg0, s32 arg1, ScriptCtx *arg2) {
    s32 _r;
    s32 _m1;
    _r = MsPayGIL(AtelPopStackInteger(arg0, arg2));
    _m1 = -1;
    __asm__("" : "+r"(_m1));
    return _m1 < _r;
}

s32 func_0012EF70(Actor *a, s32 unused, ScriptCtx *ctx)
{
    MsSetGIL(AtelPopStackInteger(a, ctx));
    return MsGetGIL();
}

/* DEBT(CAST): existing handle-based prototypes require pointer conversions. */
void func_0012EFA0(s32 a, s32 b, s32 c, s32 d)
{
    s32 saved0;
    s32 saved1;
    s32 saved2;
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
    saved2 = AtelPopStackInteger((Actor *) a, (ScriptCtx *) c);
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
    AtelPushStackInteger((Actor *) a, (ScriptCtx *) c, saved2);
    func_0012E0A0(a, b, c);
    AtelPushStackInteger((Actor *) a, (ScriptCtx *) c, value4);
    AtelPushStackInteger((Actor *) a, (ScriptCtx *) c, saved0 | 0x42);
    func_0012A238((Actor *) a, (ScriptCtx *) b, c);
    AtelPushStackInteger((Actor *) a, (ScriptCtx *) c, value4);
    func_0012A4E8((Actor *) a, (OpList *) b, (ScriptCtx *) c);
}

s32 func_0012F208(Actor *a, OpArgs *op, ScriptCtx *ctx)
{
    func_0012A6B0(a, op, ctx);
    AtelPushStackInteger(a, ctx, op->v0);
    return func_0012E140(a, (s32)op, ctx); /* DEBT(CAST): func_0012E140 ignores its second argument */
}

void func_0012F268(s32 a, s32 b, s32 c)
{
    func_0012EFA0(a, b, c, 0);
}

s32 func_0012F270(void)
{
    return func_0012A5D8();
}

s32 func_0012F290(Actor *a, OpArgs *op, ScriptCtx *ctx)
{
    return func_0012F208(a, op, ctx);
}

void func_0012F2B0(s32 a, s32 b, s32 c)
{
    func_0012EFA0(a, b, c, 8);
}

s32 func_0012F2B8(void)
{
    return func_0012A5D8();
}

s32 func_0012F2D8(Actor *a, OpArgs *op, ScriptCtx *ctx)
{
    return func_0012F208(a, op, ctx);
}
