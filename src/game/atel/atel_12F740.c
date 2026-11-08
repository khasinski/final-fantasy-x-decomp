/* tu_060 0x12f740-0x135510: low; unk_12F740 (config/tu_map.tsv) */
#define func_00133BB8 _hdr_func_00133BB8
#include "common.h"
#include "ffx/q0.h"
#include "ffx/r0.h"
#include "ffx/u0.h"
#include "ffx/v0.h"
#define func_00125268 q1_func_00125268 /* DEBT(TYPE): this header's guess conflicts with the TU */
#define TOSetAlbhedFlg q1_TOSetAlbhedFlg /* DEBT(TYPE): this header's guess conflicts with the TU */
#include "ffx/q1.h"
#undef func_00125268
#undef TOSetAlbhedFlg
#include "ffx/s0.h"
#undef func_00133BB8

int func_0012F740(Actor *a, void *op, ScriptCtx *ctx) {
    int on = AtelPopStackInteger(a, ctx) != 0;

    a->flags34.b.b31 = on;
    return on;
}

u8 *func_0012F788(Actor *a, void *op, ScriptCtx *ctx)
{
    int k = AtelPopStackInteger(a, ctx) * 2;
    int id = AtelPopStackInteger(a, ctx);
    u16 *t = (u16 *)func_00206EB0(id, func_00138240());

    if (((int (*)(void))func_0013A398)()) { /* DEBT(CAST): declared with an id the callee never reads */
        k++;
    }
    return (u8 *)t + t[k];
}

INCLUDE_ASM("build/ee_asm/game/atel/atel_12F740", func_0012F808);

int func_0012FA00(Actor *a, void *op, ScriptCtx *ctx)
{
    int n = AtelPopStackInteger(a, ctx);
    int mask = AtelPopStackInteger(a, ctx);
    int j = 0;
    int i;

    for (i = 0; i < 32; i++) {
        if ((mask >> i) & 1) {
            if (j == n) {
                return i;
            }
            j++;
        }
    }
    return 0;
}

s32 func_0012FA90(Actor *arg0, int unused1, ScriptCtx *arg2)
{
    float step;
    s32 duration;

    duration = AtelPopStackInteger(arg0, arg2);
    if (duration == 0)
    {
        step = -1.0f;
    }
    else
    {
        step = -1.0f / ((float) duration * 0.5f);
    }
    func_00136440(step);
    func_00139E98(duration, 0);
    return duration;
}

s32 func_0012FB10(Actor *arg0, int unused1, ScriptCtx *arg2)
{
    float step;
    s32 duration;

    duration = AtelPopStackInteger(arg0, arg2);
    if (duration == 0)
    {
        step = 1.0f;
    }
    else
    {
        step = 1.0f / ((float) duration * 0.5f);
    }
    func_00136440(step);
    func_00139E98(duration, 0x7F);
    return duration;
}

s32 func_0012FB90(Actor *a, void *op, ScriptCtx *ctx)
{
    s32 first = AtelPopStackInteger(a, ctx);

    func_0019CDD0(AtelPopStackInteger(a, ctx), first);
    return 1;
}

s32 func_0012FBF0(Actor *a, s32 unused, ScriptCtx *ctx)
{
    s32 v = AtelPopStackInteger(a, ctx);

    func_0019CDA0(v);
    return v;
}

u32 func_0012FC28(Actor *a, void *op, ScriptCtx *ctx)
{
    u32 v = AtelPopStackInteger(a, ctx);

    if (v != 0) {
        v |= 0x80000000;
    }
    ACTOR_W(a, 0xBC) = v;
    return v;
}

int func_0012FC70(Actor *a, void *op, ScriptCtx *ctx)
{
    int id = AtelPopStackInteger(a, ctx);
    int v = AtelPopStackInteger(a, ctx);
    Actor *o = AtelGetBasicWork(id);

    if (v) {
        v |= 0x80000000;
    }
    o->wBC = v;
    return v;
}

int func_0012FCE0(Actor *a, void *op, ScriptCtx *ctx) {
    int on = AtelPopStackInteger(a, ctx) != 0;
    u32 *w = (u32 *)AtelGetCurCtrlWork(); /* DEBT(CAST): flag word of the event state */

    *w = (*w & ~0x800000) | (on << 23);
    return on;
}

int func_0012FD30(Actor *a, void *op, ScriptCtx *ctx)
{
    int c = AtelPopStackInteger(a, ctx);
    int b = AtelPopStackInteger(a, ctx);
    int v = AtelPopStackInteger(a, ctx);

    AtelSetEncountBattleEndStatus(v, b, c);
    return v;
}

s32 func_0012FDB0(Actor *a, void *op, ScriptCtx *ctx)
{
    s32 v = AtelPopStackInteger(a, ctx) != 0;

    if (a->w40 != 0xFFFFFFFF) {
        func_002D6CC8(a->w40, v);
    }
    return v;
}

int func_0012FE08(Actor *a, void *op, ScriptCtx *ctx) {
    int n = AtelPopStackInteger(a, ctx);
    int m = AtelPopStackInteger(a, ctx);

    if (n) {
        n = 1;
    }
    func_002D6CC8(m, n);
    return n;
}

s32 func_0012FE70(void)
{
    return func_00138520();
}

INCLUDE_ASM("build/ee_asm/game/atel/atel_12F740", func_0012FE90);

int func_0012FF58(Actor *a, void *op, ScriptCtx *ctx)
{
    float c = AtelPopStackFloat(a, ctx);
    float b = AtelPopStackFloat(a, ctx);
    float t = AtelPopStackFloat(a, ctx);

    if (func_002D4690(func_002D4338(b - c), t) < t) {
        return 1;
    }
    return 0;
}

s32 func_0012FFF0(Actor *a, void *op, ScriptCtx *ctx)
{
    func_002D6CC8(a->w40, 1);
    return 1;
}

s32 func_00130018(Actor *a, s32 unused, ScriptCtx *ctx)
{
    func_002D6CC8(AtelPopStackInteger(a, ctx), 1);
    return 1;
}

s32 func_00130048(Actor *a, void *op, ScriptCtx *ctx)
{
    func_002D6CC8(a->w40, 0);
    return 0;
}

s32 func_00130070(Actor *a, s32 unused, ScriptCtx *ctx)
{
    func_002D6CC8(AtelPopStackInteger(a, ctx), 0);
    return 0;
}

s32 func_001300A0(Actor *a, void *op, ScriptCtx *ctx)
{
    if (a->w40 == 0xFFFFFFFF) {
        return 0;
    }
    func_002D6D00(a->w40, 1);
    return 1;
}

s32 func_001300D8(Actor *a, void *op, ScriptCtx *ctx)
{
    if (a->w40 == 0xFFFFFFFF) {
        return 0;
    }
    func_002D6D00(a->w40, 0);
    return 1;
}

s32 func_00130110(Actor *a, s32 unused, ScriptCtx *ctx)
{
    func_002D6D00(AtelPopStackInteger(a, ctx), 1);
    return 1;
}

s32 func_00130140(Actor *a, s32 unused, ScriptCtx *ctx)
{
    func_002D6D00(AtelPopStackInteger(a, ctx), 0);
    return 1;
}

s32 func_00130170(Actor *a, void *op, ScriptCtx *ctx)
{
    if (a->w40 == 0xFFFFFFFF) {
        return 0;
    }
    func_002D6D78(a->w40, 1);
    return 1;
}

s32 func_001301A8(Actor *a, void *op, ScriptCtx *ctx)
{
    if (a->w40 == 0xFFFFFFFF) {
        return 0;
    }
    func_002D6D78(a->w40, 0);
    return 1;
}

s32 func_001301E0(Actor *a, s32 unused, ScriptCtx *ctx)
{
    func_002D6D78(AtelPopStackInteger(a, ctx), 1);
    return 1;
}

s32 func_00130210(Actor *a, s32 unused, ScriptCtx *ctx)
{
    func_002D6D78(AtelPopStackInteger(a, ctx), 0);
    return 1;
}

s32 func_00130240(Actor *a, void *op, ScriptCtx *ctx)
{
    func_001300A0(a, op, ctx);
    func_00130170(a, op, ctx);
    return 1;
}

int func_00130290(Actor *a, void *op, ScriptCtx *ctx)
{
    int v = AtelPopStackInteger(a, ctx);

    AtelPushStackInteger(a, ctx, v);
    func_00130110(a, (s32)op, ctx); /* DEBT(CAST): declared with an unused s32 */
    AtelPushStackInteger(a, ctx, v);
    func_001301E0(a, (s32)op, ctx);
    return 1;
}

s32 func_00130320(Actor *a, void *op, ScriptCtx *ctx)
{
    func_001300D8(a, op, ctx);
    func_001301A8(a, op, ctx);
    return 1;
}

int func_00130370(Actor *a, void *op, ScriptCtx *ctx)
{
    int v = AtelPopStackInteger(a, ctx);

    AtelPushStackInteger(a, ctx, v);
    func_00130140(a, (s32)op, ctx); /* DEBT(CAST): declared with an unused s32 */
    AtelPushStackInteger(a, ctx, v);
    func_00130210(a, (s32)op, ctx);
    return 1;
}

INCLUDE_ASM("build/ee_asm/game/atel/atel_12F740", func_00130400);

INCLUDE_ASM("build/ee_asm/game/atel/atel_12F740", func_00130768);

int func_00130810(void)
{
    EvGameState *ev = AtelGetCurCtrlWork();

    *(u32 *)ev &= ~0x4000000; /* DEBT(CAST): GameFlags has no member for bit 26 */
    func_00145400();
    return 1;
}

int func_00130848(Actor *a, void *op, ScriptCtx *ctx)
{
    int v = AtelPopStackInteger(a, ctx) != 0;

    func_002D6808(v);
    return v;
}

s32 func_00130880(Actor *a, s32 unused, ScriptCtx *ctx)
{
    s32 v = AtelPopStackInteger(a, ctx);

    TkMsImportantSet(v);
    return v;
}

s32 func_001308B8(Actor *a, s32 unused, ScriptCtx *ctx)
{
    s32 v = AtelPopStackInteger(a, ctx);

    func_00124528(v);
    return v;
}

int func_001308F0(Actor *a, s32 unused, ScriptCtx *ctx)
{
    return MsImportantGet(AtelPopStackInteger(a, ctx));
}

s32 func_00130918(Actor *a, s32 unused, ScriptCtx *ctx)
{
    s32 v = AtelPopStackInteger(a, ctx);

    func_002D85E0(v);
    return v;
}

s32 func_00130950(Actor *a, void *op, ScriptCtx *ctx)
{
    s32 first = AtelPopStackInteger(a, ctx);

    func_002D85E8(AtelPopStackInteger(a, ctx), first);
    return 1;
}

s32 func_001309B0(Actor *a, void *op, ScriptCtx *ctx)
{
    s32 first = AtelPopStackInteger(a, ctx);

    func_002D8618(AtelPopStackInteger(a, ctx), first);
    return first;
}

int func_00130A10(Actor *a, void *op, ScriptCtx *ctx) {
    int v = AtelPopStackInteger(a, ctx);
    int r = AtelGetMusicNumber();

    if (r >= 0) {
        func_002D8618(r, v);
    }
    return r;
}

int func_00130A60(Actor *a, void *op, ScriptCtx *ctx) {
    int x = AtelPopStackInteger(a, ctx);
    int y = AtelPopStackInteger(a, ctx);

    func_002D85F0(AtelPopStackInteger(a, ctx), y, x);
    return x;
}

int func_00130AD8(Actor *a, void *op, ScriptCtx *ctx) {
    int x = AtelPopStackInteger(a, ctx);
    int y = AtelPopStackInteger(a, ctx);
    int id = AtelGetMusicNumber();

    if (id >= 0) {
        func_002D85F0(id, y, x);
    }
    return id;
}

int func_00130B48(Actor *a, void *op, ScriptCtx *ctx) {
    Rec124828H *r = REC124828H();
    int x = AtelPopStackInteger(a, ctx);
    int y = AtelPopStackInteger(a, ctx);

    r->hB4 = y;
    r->hB6 = x;
    return 1;
}

int func_00130BB8(Actor *a, void *op, ScriptCtx *ctx) {
    Rec124828H *r = REC124828H();
    int v = AtelPopStackInteger(a, ctx);

    r->hB8 = v;
    r->hBA = func_0013A238();
    func_00124550((Rec124828 *)r);
    return v;
}

int func_00130C20(Actor *a, void *op, ScriptCtx *ctx) {
    Rec124828H *r = REC124828H();
    int x = AtelPopStackInteger(a, ctx);
    int y = AtelPopStackInteger(a, ctx);

    r->hB8 = x;
    r->hBA = y;
    func_00124550((Rec124828 *)r);
    return x;
}

int func_00130C98(Actor *a, void *op, ScriptCtx *ctx) {
    PartySlot *p = MsGetSavePlayerPtr(AtelPopStackInteger(a, ctx));

    p->b3D = 0;
    if ((u32)p->v1C > (u32)p->v24) {
        return p->v1C;
    }
    p->v1C = p->v24;
    return p->v24;
}

int func_00130CE8(Actor *a, void *op, ScriptCtx *ctx) {
    PartySlot *p = MsGetSavePlayerPtr(AtelPopStackInteger(a, ctx));

    if ((u32)p->v20 > (u32)p->v28) {
        return p->v20;
    }
    p->v20 = p->v28;
    return p->v1C;
}

int func_00130D30(Actor *a, void *op, ScriptCtx *ctx) {
    ActorFlagsQ *f = (ActorFlagsQ *)&a->flags34; /* DEBT(CAST): see ActorFlagsQ */
    int on = AtelPopStackInteger(a, ctx) != 0;

    f->b22 = on;
    if (on) {
        f->b31 = 1;
    }
    return on;
}

int func_00130D90(Actor *a, void *op, ScriptCtx *ctx) {
    return func_0014AA50(AtelPopStackInteger(a, ctx));
}

void func_00130DB8(Actor *a, OpArgs *op, ScriptCtx *ctx) {
    op->v0 = AtelPopStackInteger(a, ctx);
}

int func_00130DE8(Actor *a, OpArgs *op) {
    return func_0014AA50(op->v0) ? 5 : 0;
}

int func_00130E18(Actor *a, void *op, ScriptCtx *ctx) {
    int v = AtelPopStackInteger(a, ctx);

    AtelSetEffectFlag(v);
    return v;
}

int func_00130E50(Actor *a, void *op, ScriptCtx *ctx) {
    int v = AtelPopStackInteger(a, ctx);

    func_0014AA30(v);
    return v;
}

int func_00130E88(Actor *a, void *op, ScriptCtx *ctx) {
    int v = AtelPopStackInteger(a, ctx);

    SndMusicReplayPointClear(v);
    func_002D82E0(v);
    AtelRegistMusicNumber(v);
    return 1;
}

int func_00130ED0(Actor *a, void *op, ScriptCtx *ctx) {
    int v = AtelPopStackInteger(a, ctx);

    func_002D82E0(v);
    AtelRegistMusicNumber(v);
    return 1;
}

int func_00130F10(Actor *a, void *op, ScriptCtx *ctx) {
    int x = AtelPopStackInteger(a, ctx);
    int y = AtelPopStackInteger(a, ctx);

    if (SndGetNowPlayMusic() >= 0) {
        SndMusicCrossStart(y, x);
    } else {
        SndMusicReplayPointClear(y);
        SndMusicStart(y);
    }
    AtelRegistMusicNumber(y);
    return 1;
}

int func_00130F98(Actor *a, void *op, ScriptCtx *ctx) {
    int v = AtelPopStackInteger(a, ctx);
    int n;

    if (v >= -0x80) {
        if (v > 0x7F) {
            n = 0x7F;
        } else {
            n = v;
        }
    } else {
        n = -0x80;
    }
    func_002D8478(n);
    return 1;
}

int func_00130FE0(Actor *a, void *op, ScriptCtx *ctx) {
    int v = AtelPopStackInteger(a, ctx);
    int id = AtelPopStackInteger(a, ctx);
    int n;

    if (v >= -0x80) {
        if (v > 0x7F) {
            n = 0x7F;
        } else {
            n = v;
        }
    } else {
        n = -0x80;
    }
    func_002D8480(id, n);
    return 1;
}

int func_00131058(Actor *a, void *op, ScriptCtx *ctx)
{
    int x = AtelPopStackInteger(a, ctx);
    int y = AtelPopStackInteger(a, ctx);

    if (x < 0) {
        x = 0;
    }
    if (y < -0x80) {
        y = -0x80;
    }
    if (x > 0xFF) {
        x = 0xFF;
    }
    if (y > 0x7F) {
        y = 0x7F;
    }
    func_002D8488(y, x);
    return 1;
}

int func_001310E0(Actor *a, void *op, ScriptCtx *ctx)
{
    int x = AtelPopStackInteger(a, ctx);
    int y = AtelPopStackInteger(a, ctx);
    int v = AtelPopStackInteger(a, ctx);

    if (x < 0) {
        x = 0;
    }
    if (y < -0x80) {
        y = -0x80;
    }
    if (x > 0xFF) {
        x = 0xFF;
    }
    if (y > 0x7F) {
        y = 0x7F;
    }
    func_002D8490(v, y, x);
    return v;
}

int func_00131188(Actor *a, void *op, ScriptCtx *ctx) {
    int v = AtelPopStackInteger(a, ctx);
    int id;

    if (v <= 0) {
        id = AtelGetMusicNumber();
        SndMusicStop(id);
        SndMusicClear(id);
        AtelRegistMusicNumber(-1);
    } else if (AtelGetMusicNumber() >= 0) {
        SndMusicVolumeFadeOut(AtelGetMusicNumber(), v);
        AtelRegistMusicNumber(-1);
    }
    return v;
}

int func_00131220(Actor *a, void *op, ScriptCtx *ctx) {
    int x = AtelPopStackInteger(a, ctx);
    int y = AtelPopStackInteger(a, ctx);
    int id;

    if (x <= 0) {
        id = AtelGetMusicNumber();
        SndMusicStop(id);
        SndMusicClear(id);
    } else if (y >= 0) {
        SndMusicVolumeFadeOut(y, x);
    }
    return x;
}

void func_001312B0(Actor *a, void *op, ScriptCtx *ctx) {
    func_0014D890(AtelPopStackInteger(a, ctx));
}

int func_001312D0(void) {
    return 1;
}

int func_001312D8(Actor *a, void *op, ScriptCtx *ctx) {
    int v = AtelPopStackInteger(a, ctx);

    func_00138A58(v);
    return v;
}

int func_00131310(Actor *a, void *op, ScriptCtx *ctx) {
    int v = AtelPopStackInteger(a, ctx);

    func_00138A78(v);
    return v;
}

int func_00131348(Actor *a, void *op, ScriptCtx *ctx) {
    int x = AtelPopStackInteger(a, ctx);
    int y = AtelPopStackInteger(a, ctx);
    int z = AtelPopStackInteger(a, ctx);

    CALL_func_002D8698(z, y, x);
    return 1;
}

int func_001313C0(Actor *a, void *op, ScriptCtx *ctx) {
    int x = AtelPopStackInteger(a, ctx);
    int y = AtelPopStackInteger(a, ctx);
    int z = AtelPopStackInteger(a, ctx);
    int w = AtelPopStackInteger(a, ctx);

    CALL_func_002D8700(w, z, y, x);
    return 1;
}

int func_00131458(Actor *a, void *op, ScriptCtx *ctx) {
    int v = AtelPopStackInteger(a, ctx);

    func_0014D960(v);
    SndVagStreamVolumeDirect(v);
    return 0;
}

int func_00131498(Actor *a, void *op, ScriptCtx *ctx) {
    int x = AtelPopStackInteger(a, ctx);
    int y = AtelPopStackInteger(a, ctx);

    func_0014D960(x);
    func_002D84C8(y, x);
    return 0;
}

int func_00131500(Actor *a, void *op, ScriptCtx *ctx) {
    int v = AtelPopStackInteger(a, ctx);

    func_0014D970(v);
    func_002D8508(v);
    return 0;
}

int func_00131540(Actor *a, void *op, ScriptCtx *ctx) {
    int x = AtelPopStackInteger(a, ctx);
    int y = AtelPopStackInteger(a, ctx);

    func_0014D970(x);
    func_002D8510(y, x);
    return 0;
}

void func_001315A8(Actor *a, void *op, ScriptCtx *ctx) {
    EvGameStateF *g = (EvGameStateF *)AtelGetCurCtrlWork(); /* DEBT(CAST): see EvGameStateF */

    g->f1F0 = AtelPopStackFloat(a, ctx);
}

int func_001315F8(Actor *a, void *op, ScriptCtx *ctx) {
    int v = AtelPopStackInteger(a, ctx);

    func_0014ABD0(v);
    return v;
}

int func_00131630(void) {
    return func_00138BE8() ? 0 : 5;
}

int func_00131658(Actor *a, void *op, ScriptCtx *ctx)
{
    int v = AtelPopStackInteger(a, ctx);

    switch (a->stateAA) {
    case 4:
    case 5:
        AtelBindFp(a, v, a->hA8);
    }
    return 1;
}

int func_001316B0(Actor *a, void *op, ScriptCtx *ctx) {
    int x = AtelPopStackInteger(a, ctx);
    int y = AtelPopStackInteger(a, ctx);
    int z = AtelPopStackInteger(a, ctx);

    if (a->stateAA != 5) {
        return 0;
    }
    func_001746E8(z, y, x);
    return 1;
}

int func_00131738(Actor *a, void *op, ScriptCtx *ctx) {
    int x = AtelPopStackInteger(a, ctx);
    int y = AtelPopStackInteger(a, ctx);

    if (a->stateAA == 5) {
        AtelPushStackInteger(a, ctx, ACTOR_HA8(a));
        AtelPushStackInteger(a, ctx, y);
        AtelPushStackInteger(a, ctx, x);
        return func_001316B0(a, op, ctx);
    }
    return 0;
}

int func_001317F8(Actor *a, void *op, ScriptCtx *ctx) {
    int x = AtelPopStackInteger(a, ctx);
    int y = AtelPopStackInteger(a, ctx);

    yiDisposeAnimDObj(y, x);
    return 1;
}

int func_00131858(Actor *a, void *op, ScriptCtx *ctx) {
    int v = AtelPopStackInteger(a, ctx);

    if (a->stateAA == 5) {
        AtelPushStackInteger(a, ctx, ACTOR_HA8(a));
        AtelPushStackInteger(a, ctx, v);
        return func_001317F8(a, op, ctx);
    }
    return 0;
}

int func_001318F0(Actor *a, void *op, ScriptCtx *ctx) {
    int x = AtelPopStackInteger(a, ctx);
    int y = AtelPopStackInteger(a, ctx);
    int z = AtelPopStackInteger(a, ctx);

    if (a->ptr9C != 0) {
        func_001747B0(z, a->ptr9C, x);
    }
    return 1;
}

int func_00131960(Actor *a, void *op, ScriptCtx *ctx) {
    int x = AtelPopStackInteger(a, ctx);
    int y = AtelPopStackInteger(a, ctx);

    AtelPushStackInteger(a, ctx, ACTOR_HA8(a));
    AtelPushStackInteger(a, ctx, y);
    AtelPushStackInteger(a, ctx, x);
    return func_001318F0(a, op, ctx);
}

int func_00131A08(void) {
    s32 *flags = MsGetSaveMenu();
    int r = 0;

    if ((*flags >> 8) & 1) {
        r = (*flags >> 9) & 1;
    }
    return r;
}

int func_00131A48(Actor *a, void *op, ScriptCtx *ctx) {
    return func_0014ACC0(AtelPopStackInteger(a, ctx));
}

int func_00131A70(Actor *a, void *op, ScriptCtx *ctx) {
    AtelPushStackInteger(a, ctx, 0);
    return func_00131A48(a, op, ctx);
}

int func_00131AC8(Actor *a, void *op, ScriptCtx *ctx) {
    Vec4 v;
    float f0 = AtelPopStackFloat(a, ctx);
    float f1 = AtelPopStackFloat(a, ctx);
    float f2 = AtelPopStackFloat(a, ctx);
    float f3 = AtelPopStackFloat(a, ctx);
    int id = AtelPopStackInteger(a, ctx);

    v.x = f3;
    v.y = f2;
    v.z = f1;
    v.w = f0;
    func_001747D0(id, &v);
    return 1;
}

int func_00131B80(Actor *a, void *op, ScriptCtx *ctx) {
    AtelPushStackInteger(a, ctx, 0);
    return func_00131AC8(a, op, ctx);
}

int func_00131BD8(Actor *a, void *op, ScriptCtx *ctx) {
    AtelPushStackInteger(a, ctx, 0);
    AtelPushStackInteger(a, ctx, 0);
    return func_00131AC8(a, op, ctx);
}

int func_00131C40(Actor *a, void *op, ScriptCtx *ctx) {
    AtelPushStackInteger(a, ctx, 0);
    AtelPushStackInteger(a, ctx, 0);
    AtelPushStackInteger(a, ctx, 0);
    return func_00131AC8(a, op, ctx);
}

int func_00131CB8(Actor *a, void *op, ScriptCtx *ctx) {
    int x = AtelPopStackInteger(a, ctx);
    int y = AtelPopStackInteger(a, ctx);

    func_00174810(y, x);
    return 1;
}

INCLUDE_ASM("build/ee_asm/game/atel/atel_12F740", func_00131D18);

INCLUDE_ASM("build/ee_asm/game/atel/atel_12F740", func_00131E60);

int func_00131F48(Actor *a, OpBlkH *op) {
    int r = 0;
    u16 st = op->hA;

    if (op->h8 == 0) {
        r = 5;
    } else {
        switch (st) {
        case 0:
            SaveDataIsScreenClosed(0x10001);
            st = 1;
            break;
        case 1:
            r = 1;
            break;
        }
    }
    op->hA = st;
    return r;
}

int func_00131FB8(Actor *a, OpBlk *op) {
    if (op->h8 != 0) {
        MsBtlGetInit();
    }
    return 1;
}

int func_00131FE8(Actor *a, void *op, ScriptCtx *ctx) {
    return ((PartySlotV *)MsGetSavePlayerPtr(AtelPopStackInteger(a, ctx)))->v54; /* DEBT(CAST): see PartySlotV */
}

int func_00132010(Actor *a, void *op, ScriptCtx *ctx) {
    return ((PartySlotV *)MsGetSavePlayerPtr(AtelPopStackInteger(a, ctx)))->v50; /* DEBT(CAST): see PartySlotV */
}

int func_00132038(Actor *a, void *op, ScriptCtx *ctx) {
    return ((PartySlotV *)MsGetSavePlayerPtr(AtelPopStackInteger(a, ctx)))->v58; /* DEBT(CAST): see PartySlotV */
}

int func_00132060(void) {
    return MsGetSaveBattleCount();
}

int func_00132080(Actor *a, void *op, ScriptCtx *ctx) {
    return MsGetMonsterCapture(AtelPopStackInteger(a, ctx));
}

int func_001320A8(Actor *a, void *op, ScriptCtx *ctx) {
    return func_001E19A8(AtelPopStackInteger(a, ctx), 1);
}

int func_001320D0(Actor *a, void *op, ScriptCtx *ctx) {
    return func_001E19A8(AtelPopStackInteger(a, ctx), -1);
}

int func_001320F8(Actor *a, void *op, ScriptCtx *ctx) {
    int x = AtelPopStackInteger(a, ctx);
    int y = AtelPopStackInteger(a, ctx);

    return func_001E19A8(y, x);
}

int func_00132150(Actor *a, void *op, ScriptCtx *ctx) {
    int x = AtelPopStackInteger(a, ctx);
    int y = AtelPopStackInteger(a, ctx);

    func_0014E0A8(y, x);
    return y;
}

int func_001321B0(void) {
    func_0014E160();
    return 1;
}

int func_001321D0(Actor *a, void *op, ScriptCtx *ctx) {
    return func_001BFE30(AtelPopStackInteger(a, ctx));
}

int func_001321F8(void) {
    return func_002D67D8() != 0;
}

int func_00132218(void) {
    return func_0014DE28();
}

int func_00132238(void) {
    return func_001E0C98() != 0;
}

int func_00132258(Actor *a, void *op, ScriptCtx *ctx) {
    int r = 0;
    int v = AtelPopStackInteger(a, ctx);

    if (func_001E0C98()) {
        func_001E0DE8(v);
        r = 1;
    }
    return r;
}

int func_001322A8(void) {
    return func_001E0CF0(1);
}

int func_001322C8(void) {
    return func_001E0CF0(0);
}

int func_001322E8(void) {
    return CALL_func_002D5E48(0); /* DEBT(CAST): funcs.h declares (void) */
}

int func_00132308(Actor *a, void *op, ScriptCtx *ctx) {
    func_00148780(AtelPopStackInteger(a, ctx));
    return 1;
}

int func_00132330(Actor *a, void *op, ScriptCtx *ctx) {
    func_0014AD58(AtelPopStackInteger(a, ctx));
    return 1;
}

int func_00132358(void) {
    return func_0014AD88();
}

int func_00132378(void) {
    func_0014ADB8();
    return 1;
}

int func_00132398(Actor *a, void *op, ScriptCtx *ctx) {
    int v = AtelPopStackInteger(a, ctx);
    int i = AtelPopStackInteger(a, ctx);
    int n;

    if (i >= 0) {
        if (i > 3) {
            n = 3;
        } else {
            n = i;
        }
    } else {
        n = 0;
    }
    func_0014AE00(n, v);
    return v;
}

int func_00132410(void) {
    func_0014E068();
    return 1;
}

int func_00132430(void) {
    func_0014E028();
    return 1;
}

int func_00132450(Actor *a, void *op, ScriptCtx *ctx) {
    int v = AtelPopStackInteger(a, ctx);

    func_0014DCB8(v);
    return v;
}

int func_00132488(Actor *a, void *op, ScriptCtx *ctx) {
    int v = AtelPopStackInteger(a, ctx) != 0;

    func_0014DC70(v);
    return v;
}

int func_001324C0(Actor *a, void *op, ScriptCtx *ctx) {
    return func_00132488(a, op, ctx);
}

void func_001324E0(Actor *a, OpBlk *op, ScriptCtx *ctx) {
    EvGameStateG *g = (EvGameStateG *)AtelGetCurCtrlWork(); /* DEBT(CAST): see EvGameStateG */
    int x;
    int y;

    g->w210 &= ~0x10;
    x = AtelPopStackInteger(a, ctx);
    y = AtelPopStackInteger(a, ctx);
    op->bA = y;
    op->bB = x;
    op->w0 = 0;
    op->w4 = 0;
    op->h8 = 0;
    op->bF = 0;
    op->bC = 2;
    op->bD = 1;
    op->bE = 4;
    func_002D9030(y);
}

INCLUDE_ASM("build/ee_asm/game/atel/atel_12F740", func_00132588);
INCLUDE_RODATA("build/ee_asm/game/atel/atel_12F740/rodata", jtbl_0056A4A0);

int func_00132CB8(Actor *a, OpMove *op)
{
    EvGameStateG *g = (EvGameStateG *)AtelGetCurCtrlWork(); /* DEBT(CAST): see EvGameStateG */
    int r = op->mode;

    if (op->kind == 1) {
        switch (r) {
        case 6:
            r = 3;
            break;
        case 4:
            r = 4;
            break;
        case 0:
        case 2:
        case 5:
            r = 0;
            break;
        }
    } else if (r == 6) {
        AtelRegistAlbhedDic(op->b0F, op->w4);
        if (op->b0F == 0) {
            r = 2;
        }
    }
    g->w210 |= 0x10;
    return r;
}

int func_00132D70(void) {
    return func_00124530();
}

int func_00132D90(void) {
    return func_0014F168();
}

int func_00132DB0(Actor *a, void *op, ScriptCtx *ctx) {
    Actor *t = AtelGetBasicWork(AtelPopStackInteger(a, ctx));

    AQ(t)->w38 |= 4;
    return 1;
}

int func_00132DE8(Actor *a, void *op, ScriptCtx *ctx) {
    AtelPushStackInteger(a, ctx, AQ(a)->id);
    return func_00132DB0(a, op, ctx);
}

int func_00132E40(void) {
    return SndGetNowPlayMusic();
}

int func_00132E60(void) {
    return AtelGetMusicNumber();
}

int func_00132E80(Actor *a) {
    if (AQ(a)->stateAA == 1) {
        if (AQ(a)->ptr9C != 0) {
            op_et_bindeff(AQ(a)->ptr9C);
            func_002994B8(AQ(a)->ptr9C);
            AQ(a)->w38 |= 0x10;
        }
    }
    return 1;
}

int func_00132EE0(Actor *a) {
    if (AQ(a)->stateAA == 1) {
        if (AQ(a)->ptr9C != 0) {
            func_002994D8(AQ(a)->ptr9C);
            AQ(a)->w38 &= ~0x10;
        }
    }
    return 1;
}

int func_00132F38(Actor *a) {
    if (AQ(a)->stateAA == 1) {
        if (AQ(a)->ptr9C != 0) {
            AtelBindEff2On(a, 0);
        }
    }
    return 1;
}

int func_00132F78(Actor *a) {
    if (AQ(a)->stateAA == 1) {
        if (AQ(a)->ptr9C != 0) {
            func_00138970(a, 0);
        }
    }
    return 1;
}

int func_00132FB8(Actor *a) {
    if (AQ(a)->stateAA == 1) {
        if (AQ(a)->ptr9C != 0) {
            AtelBindEff2On(a, 1);
        }
    }
    return 1;
}

int func_00132FF8(Actor *a) {
    if (AQ(a)->stateAA == 1) {
        if (AQ(a)->ptr9C != 0) {
            func_00138970(a, 1);
        }
    }
    return 1;
}

int func_00133038(Actor *a) {
    if (AQ(a)->stateAA == 1) {
        if (AQ(a)->ptr9C != 0) {
            AtelBindEff2On(a, 2);
        }
    }
    return 1;
}

int func_00133078(Actor *a) {
    if (AQ(a)->stateAA == 1) {
        if (AQ(a)->ptr9C != 0) {
            func_00138970(a, 2);
        }
    }
    return 1;
}

int func_001330B8(Actor *a, void *op, ScriptCtx *ctx) {
    Actor *t = AtelGetBasicWork(AtelPopStackInteger(a, ctx));

    if (AQ(t)->stateAA == 1) {
        AQ(t)->w38 |= 8;
    }
    return 1;
}

int func_00133100(Actor *a, void *op, ScriptCtx *ctx) {
    AtelPushStackInteger(a, ctx, AQ(a)->id);
    return func_001330B8(a, op, ctx);
}

void func_00133158(Actor *a, OpArgs *op, ScriptCtx *ctx) {
    op->v0 = AtelPopStackInteger(a, ctx);
}

int func_00133188(Actor *a, OpArgs *op) {
    if (D_00576479 == 0) {
        return 5;
    }
    if (D_005661F4 != 0) {
        return 5;
    }
    op->v0 -= 1;
    return op->v0 < 1;
}

int func_001331C0(Actor *a, void *op, ScriptCtx *ctx)
{
    Rec124828 *p = func_00124828();
    int v = AtelPopStackInteger(a, ctx);
    int s;
    int r;

    if (func_00138240()) {
        s = func_0013A8E0(v);
    } else {
        s = func_0013A8C0(v);
    }
    r = func_002F05E8(s, p->padEC);
    if (r != 0) {
        r = 0;
    } else {
        r = 1;
    }
    return r;
}

int func_00133248(Actor *a, void *op, ScriptCtx *ctx) {
    int v = AtelPopStackInteger(a, ctx) != 0;

    func_002D8778(v);
    return v;
}

int func_00133280(Actor *a, void *op, ScriptCtx *ctx) {
    int x = AtelPopStackInteger(a, ctx);
    int i = AtelPopStackInteger(a, ctx);

    if (x != 0) {
        x = 1;
    }
    if (AQ(a)->arrAF4[i] != 0) {
        if ((AQ(a)->hB14 >> i) & 1) {
            Ch_EnClip(AQ(a)->arrAF4[i], x);
        }
    }
    AQ(a)->arrB08[i].b0 = x;
    return x;
}

int func_00133328(Actor *a, void *op, ScriptCtx *ctx) {
    int x = AtelPopStackInteger(a, ctx);
    int i = AtelPopStackInteger(a, ctx);

    if (x != 0) {
        x = 1;
    }
    if (AQ(a)->arrAF4[i] != 0) {
        if ((AQ(a)->hB14 >> i) & 1) {
            Ch_Vu1SetClipmode(AQ(a)->arrAF4[i], x);
        }
    }
    AQ(a)->arrB08[i].b1 = x;
    return x;
}

int func_001333D0(Actor *a, void *op, ScriptCtx *ctx) {
    SysVtQ *vt = (SysVtQ *)GetCD(); /* DEBT(CAST): see SysVtQ */
    int x = AtelPopStackInteger(a, ctx);
    int y = AtelPopStackInteger(a, ctx);

    vt->f88(y, x);
    return 1;
}

int func_00133448(Actor *a, void *op, ScriptCtx *ctx) {
    SysVtQ *vt = (SysVtQ *)GetCD(); /* DEBT(CAST): see SysVtQ */
    int v = AtelPopStackInteger(a, ctx);
    s32 buf[2];
    u32 t;

    func_002D7430(v, &buf[0], &buf[1]);
    t = func_002D71C0(v);
    if (t == 0xFFFFFFFF) {
        v = 0;
    } else {
        v = func_002D72F8(0, &buf[1], &buf[0], v, t);
        vt->f8C(v);
    }
    return v;
}

int func_001334F0(Actor *a, void *op, ScriptCtx *ctx) {
    SysVtQ *vt = (SysVtQ *)GetCD(); /* DEBT(CAST): see SysVtQ */
    int v = AtelPopStackInteger(a, ctx);

    vt->f8C(v);
    return v;
}

/* DEBT(FAKE) */
s32 func_00133550(Actor *arg0, void *arg1, ScriptCtx *arg2) {
    s32 temp_18;
    s32 temp_19;
    s32 temp_20;
    register s32 temp_21 __asm__("$19");
    s32 temp_2;
    s32 var_4;
    s32 var_5;
    s32 var_6;
    s32 var_7;

    temp_19 = AtelPopStackInteger(arg0, arg2);
    temp_21 = AtelPopStackInteger(arg0, arg2);
    temp_20 = AtelPopStackInteger(arg0, arg2);
    temp_18 = AtelPopStackInteger(arg0, arg2);
    temp_2 = AtelPopStackInteger(arg0, arg2);
    if (temp_2 >= 0) {
        var_4 = (temp_2 >= 8) ? 7 : temp_2;
    } else {
        var_4 = 0;
    }
    if (temp_18 >= 0) {
        var_5 = (temp_18 >= 2) ? 1 : temp_18;
    } else {
        var_5 = 0;
    }
    if (temp_20 >= 0) {
        var_6 = (temp_20 >= 0x80) ? 0x7F : temp_20;
    } else {
        var_6 = 0;
    }
    if (temp_21 >= 0) {
        var_7 = (temp_21 >= 0x80) ? 0x7F : temp_21;
    } else {
        var_7 = 0;
    }
    func_0014D2F8(var_4, var_5, var_6, var_7, temp_19);
    return 1;
}

int func_00133660(Actor *a, void *op, ScriptCtx *ctx) {
    int e = AtelPopStackInteger(a, ctx);
    int d = AtelPopStackInteger(a, ctx);
    int c = AtelPopStackInteger(a, ctx);
    int b = AtelPopStackInteger(a, ctx);

    func_0014D2F8(3, b, c, d, e);
    return 1;
}

int func_001336F8(Actor *a, void *op, ScriptCtx *ctx) {
    int v = AtelPopStackInteger(a, ctx);

    func_0014D468(v);
    return v;
}

int func_00133730(Actor *a, void *op, ScriptCtx *ctx) {
    AtelPushStackInteger(a, ctx, 3);
    return func_001336F8(a, op, ctx);
}

int func_00133788(Actor *a, void *op, ScriptCtx *ctx) {
    AtelPushStackInteger(a, ctx, 2);
    return func_001336F8(a, op, ctx);
}

int func_001337E0(Actor *a, void *op, ScriptCtx *ctx) {
    AtelPushStackInteger(a, ctx, 1);
    return func_001336F8(a, op, ctx);
}

void func_00133838(Actor *a, OpArgs *op, ScriptCtx *ctx) {
    op->v0 = AtelPopStackInteger(a, ctx);
}

int func_00133868(Actor *a, OpArgs *op) {
    return func_0014CEB0(op->v0) ? 0 : 5;
}

void func_00133898(Actor *a, OpArgs *op, ScriptCtx *ctx) {
    AtelPushStackInteger(a, ctx, 3);
    func_00133838(a, op, ctx);
}

int func_001338E8(Actor *a, OpArgs *op) {
    return func_00133868(a, op);
}

int func_00133908(Actor *a, void *op, ScriptCtx *ctx) {
    func_00144D48(AtelGetRealVarAdrs(a, AtelPopStackInteger(a, ctx)));
    return 1;
}

int func_00133948(Actor *a, void *op, ScriptCtx *ctx) {
    int x = AtelPopStackInteger(a, ctx);
    int y = AtelPopStackInteger(a, ctx);
    int w = ((EvGameStateK *)AtelGetCurCtrlWork())->w44; /* DEBT(CAST): see EvGameStateK */

    if (w != 0) {
        func_0014D3F0(y, x, w);
    }
    return 1;
}

INCLUDE_ASM("build/ee_asm/game/atel/atel_12F740", func_001339B8);

int func_00133A50(int x) {
    return MsMenuGetText(3, x, MsGetSaveConfigHiragana());
}

int func_00133A88(void) {
    char buf[256];
    char *s = (char *)func_00133A50(0x202C); /* DEBT(TYPE): returns a string pointer, int in funcs.h */

    if (func_00138240() == 0) {
        func_0014D610((int)s, buf);
        s = buf;
    }
    func_002F072C((char *)MsGetSaveChrName(6), s); /* DEBT(CAST): Rec14 as char destination */
    return 1;
}

int func_00133AE0(Actor *a, void *op, ScriptCtx *ctx) {
    int v = AtelPopStackInteger(a, ctx);

    if (AQ(a)->stateAA == 1) {
        if (AQ(a)->ptr9C != 0) {
            Ch_EffectSetEffectLevel(AQ(a)->ptr9C, v);
            return 1;
        }
    }
    return 0;
}

int func_00133B38(Actor *a) {
    if (AQ(a)->stateAA == 1) {
        if (AQ(a)->ptr9C != 0) {
            return func_00110B78(AQ(a)->ptr9C);
        }
    }
    return 0;
}

int func_00133B78(void) {
    return func_00173150();
}

int func_00133B98(void) {
    return func_00173190();
}

float _m2c_func_00133BB8_AtelPopStackFloat(s32, s32) __asm__("AtelPopStackFloat");
s32 _m2c_func_00133BB8_AtelPopStackInteger() __asm__("AtelPopStackInteger");
s32 _m2c_func_00133BB8_func_001731C0(s32, float, float, float) __asm__("func_001731C0");
/* DEBT(FAKE) */
s32 func_00133BB8(s32 arg0, s32 arg1, s32 arg2) {
    float temp_f20;
    float temp_f21;
    float temp_f0;
    register float f13 __asm__("$f13");
    register float f14 __asm__("$f14");
    s32 temp_18;

    temp_18 = _m2c_func_00133BB8_AtelPopStackInteger(arg0, arg2);
    temp_f21 = _m2c_func_00133BB8_AtelPopStackFloat(arg0, arg2);
    temp_f20 = _m2c_func_00133BB8_AtelPopStackFloat(arg0, arg2);
    temp_f0 = _m2c_func_00133BB8_AtelPopStackFloat(arg0, arg2);
    f13 = temp_f20;
    f14 = temp_f21;
    __asm__ volatile("" : "+f"(f13), "+f"(f14));
    return _m2c_func_00133BB8_func_001731C0(temp_18, temp_f0, f13, f14);
}

int func_00133C48(void) {
    func_00173240();
    return 1;
}

int func_00133C68(Actor *a, void *op, ScriptCtx *ctx) {
    int x = AtelPopStackInteger(a, ctx);
    int y = AtelPopStackInteger(a, ctx);
    int z = AtelPopStackInteger(a, ctx);

    return func_001731E8(z, y, x);
}

int func_00133CE0(Actor *a, void *op, ScriptCtx *ctx) {
    float f0 = AtelPopStackFloat(a, ctx);
    float f1 = AtelPopStackFloat(a, ctx);
    int id = AtelPopStackInteger(a, ctx);

    func_00173208(id, f1, f0);
    return id;
}

int func_00133D60(Actor *a, void *op, ScriptCtx *ctx) {
    int x = AtelPopStackInteger(a, ctx);
    int y = AtelPopStackInteger(a, ctx);

    SndMusicReplayPointClear(y);
    func_002D8268(y, x);
    AtelRegistMusicNumber(y);
    return 1;
}

int func_00133DD0(Actor *a, void *op, ScriptCtx *ctx) {
    SndSepClear(AtelPopStackInteger(a, ctx));
    return 1;
}

float func_00133DF8(Actor *a, void *op, ScriptCtx *ctx) {
    float f = AtelPopStackFloat(a, ctx);

    func_0014D7F0(f);
    return f;
}

int func_00133E30(void) {
    return func_0014D7E0();
}

int func_00133E50(void) {
    int mask = 0;
    int i;

    for (i = 8; i < 16; i++) {
        if (MsGetSavePlyJoin(i)) {
            mask |= 1 << i;
        }
    }
    return mask;
}

INCLUDE_ASM("build/ee_asm/game/atel/atel_12F740", func_00133EB0);

int func_00134040(Actor *a, void *op, ScriptCtx *ctx) {
    int mask = AtelPopStackInteger(a, ctx);
    int want = AtelPopStackInteger(a, ctx);
    int n = 0;
    int i;

    for (i = 8; i < 16; i++) {
        if ((mask >> i) & 1) {
            if (want == n) {
                return i;
            }
            n++;
        }
    }
    return -1;
}

int func_001340D0(Actor *a, void *op, ScriptCtx *ctx) {
    int v = AtelPopStackInteger(a, ctx) != 0;

    TkMenuSetDummyControlerFlag(v);
    return v;
}

int func_00134108(Actor *a, void *op, ScriptCtx *ctx) {
    int v = AtelPopStackInteger(a, ctx);

    func_002415B8(1 << v);
    return v;
}

void func_00134140(Actor *a, OpArgs *op, ScriptCtx *ctx) {
    int v = AtelPopStackInteger(a, ctx);
    int m = 1 << v;

    op->v1 = func_00265EE0();
    op->v0 = m;
}

int func_00134188(Actor *a, OpArgs *op) {
    int h = op->v0;
    int r;

    op->v1 -= 1;
    r = op->v1 > 0 ? 0 : 5;
    func_002415B8(h);
    return r;
}

int func_001341C8(Actor *a, void *op, ScriptCtx *ctx) {
    int x = AtelPopStackInteger(a, ctx);
    int y = AtelPopStackInteger(a, ctx);
    int z = AtelPopStackInteger(a, ctx);

    func_001387D0(z, y, x);
    return 0;
}

int func_00134240(Actor *a, void *op, ScriptCtx *ctx) {
    int v = AtelPopStackInteger(a, ctx);

    AtelPushStackInteger(a, ctx, v);
    func_0012C7C0(a, op, ctx);
    CALL_func_001BDE20(v, 0);
    return 1;
}

int func_001342C0(void) {
    return func_00220F10();
}

int func_001342E0(void) {
    return func_00220F20();
}

int func_00134300(Actor *a, void *op, ScriptCtx *ctx) {
    int x = AtelPopStackInteger(a, ctx);
    int y = AtelPopStackInteger(a, ctx);

    return func_0014F380(y, x, 1);
}

INCLUDE_ASM("build/ee_asm/game/atel/atel_12F740", func_00134360);

int func_001345D0(Actor *a, OpBlkR *op) {
    int bits = CALL_func_0012A7E0();
    int r = 0;

    switch (op->hE) {
    case 0:
        if (bits & 1) {
            op->hE = 1;
        }
        break;
    case 1:
        op->hE = 2;
        break;
    case 2:
        r = 5;
        break;
    }
    return r;
}

int func_00134660(Actor *a, OpBlkR *op) {
    int h = op->w8;
    int k = op->hC;
    GameFlagsQ *f = (GameFlagsQ *)&((EvGameState *)AtelGetCurCtrlWork())->flags; /* DEBT(CAST): see GameFlagsQ */

    f->b26 = 0;
    func_00145400();
    return func_0014F380(h, k, 1);
}

int func_001346B8(Actor *a, void *op, ScriptCtx *ctx) {
    int x = AtelPopStackInteger(a, ctx);
    int y = AtelPopStackInteger(a, ctx);

    return func_0014F380(y, x, 0);
}

int func_00134718(Actor *a, void *op, ScriptCtx *ctx) {
    int x = AtelPopStackInteger(a, ctx);
    int y = AtelPopStackInteger(a, ctx);

    return MsGetSaveCommand(y, x);
}

int func_00134770(Actor *a, void *op, ScriptCtx *ctx) {
    int id = AtelPopStackInteger(a, ctx);

    AQ(AtelGetBasicWork(id))->w38 |= 0x100;
    AtelPushStackInteger(a, ctx, id);
    return func_00132DB0(a, op, ctx);
}

int func_001347F0(Actor *a, void *op, ScriptCtx *ctx) {
    AQ(a)->w38 |= 0x100;
    return func_00132DE8(a, op, ctx);
}

int func_00134818(Actor *a, void *op, ScriptCtx *ctx) {
    int v = AtelPopStackInteger(a, ctx);

    func_0014AEF8(v);
    return v;
}

int func_00134850(void) {
    return func_0014AF20();
}

int func_00134870(Actor *a, void *op, ScriptCtx *ctx) {
    int v;

    func_0014AF68(AtelPopStackInteger(a, ctx));
    v = func_0014AF40(func_0013A278());
    func_001ADC50(v);
    return v;
}

int func_001348C0(Actor *a, void *op, ScriptCtx *ctx) {
    int v = AtelPopStackInteger(a, ctx);

    AtelSetHelpEventFlag(v, 1);
    return v;
}

int func_001348F8(Actor *a, void *op, ScriptCtx *ctx) {
    return AtelGetHelpEventFlag(AtelPopStackInteger(a, ctx));
}

int func_00134920(Actor *a, void *op, ScriptCtx *ctx) {
    int n = AtelPopStackInteger(a, ctx);
    int base = AtelPopStackInteger(a, ctx);
    int i;

    for (i = 0; i < n; i++) {
        if (!AtelGetHelpEventFlag(base + i)) {
            break;
        }
    }
    return i == n;
}

int func_001349A0(Actor *a, void *op, ScriptCtx *ctx) {
    int v = AtelPopStackInteger(a, ctx);

    AtelSetHelpEventFlag(v, 0);
    return v;
}

INCLUDE_ASM("build/ee_asm/game/atel/atel_12F740", func_001349D8);

int func_00134A60(Actor *a, void *op, ScriptCtx *ctx) {
    int x = AtelPopStackInteger(a, ctx);
    Actor *t = AtelGetBasicWork(AtelPopStackInteger(a, ctx));

    if (AQ(t)->stateAA == 1) {
        if (AQ(t)->ptr9C != 0) {
            return Ch_OptposGetElement(AQ(t)->ptr9C, x, 0);
        }
    }
    return 0;
}

int func_00134AE8(Actor *a, void *op, ScriptCtx *ctx) {
    int v = AtelPopStackInteger(a, ctx);

    AtelPushStackInteger(a, ctx, AQ(a)->id);
    AtelPushStackInteger(a, ctx, v);
    return func_00134A60(a, op, ctx);
}

int func_00134B68(Actor *a, void *op, ScriptCtx *ctx)
{
    int x = AtelPopStackInteger(a, ctx);
    int n = AtelPopStackInteger(a, ctx);

    if (n >= 18) {
        return 0;
    }
    if (n < 0) {
        return 0;
    }
    if (x >= 3) {
        x = 2;
    }
    return func_00227FD8(n, x > 0 ? x : 1);
}

int func_00134BF0(void) {
    MsBtlGetInit();
    return 1;
}

int func_00134C10(Actor *a, void *op, ScriptCtx *ctx) {
    return MsGetMonsterCapture(AtelPopStackInteger(a, ctx));
}

int func_00134C38(Actor *a, void *op, ScriptCtx *ctx) {
    int x = AtelPopStackInteger(a, ctx);
    int y = AtelPopStackInteger(a, ctx);

    return func_001E19A8(y, x);
}

int func_00134C90(Actor *a, void *op, ScriptCtx *ctx) {
    int x = AtelPopStackInteger(a, ctx);
    int y = AtelPopStackInteger(a, ctx);

    return func_0014F228(0, y, x, 0);
}

int func_00134CF0(Actor *a, void *op, ScriptCtx *ctx) {
    int x = AtelPopStackInteger(a, ctx);
    int y = AtelPopStackInteger(a, ctx);

    return func_0014F228(1, y, x, 0);
}

int func_00134D50(Actor *a, void *op, ScriptCtx *ctx) {
    return func_0014F228(2, 0, AtelPopStackInteger(a, ctx), 0);
}

int func_00134D80(void) {
    s32 buf[2];
    u16 *p;
    int i;
    int r = 0;

    p = MsGetSaveWeaponList(0, 0, 0, &buf[0]);
    for (i = 0; i < buf[0]; i++, p++) {
        int id = *p;

        if ((((Unk1BFED8Q *)MsGetSaveWeapon(id, &buf[1]))->b3 >> 3) & 1) { /* DEBT(CAST): see Unk1BFED8Q */
            MsEquipSaveWeapon(0, 0, id);
            r = 1;
            TkMsSetSaveParamAll();
        }
    }
    return r;
}

int func_00134E40(Actor *a, void *op, ScriptCtx *ctx) {
    int v = AtelPopStackInteger(a, ctx);

    func_001385A8(v, 0);
    return v;
}

int func_00134E78(Actor *a, void *op, ScriptCtx *ctx) {
    int v = AtelPopStackInteger(a, ctx);

    func_001385A8(v, 1);
    return v;
}

int func_00134EB0(Actor *a, void *op, ScriptCtx *ctx) {
    int i = AtelPopStackInteger(a, ctx);

    return D_0036E998[i];
}

int func_00134EE0(Actor *a, void *op, ScriptCtx *ctx) {
    int i = AtelPopStackInteger(a, ctx);

    return D_0036F0E0[i];
}

int func_00134F10(Actor *a, void *op, ScriptCtx *ctx) {
    u32 *flags = MsGetSaveMenu();
    int on = AtelPopStackInteger(a, ctx) != 0;

    *flags = (*flags & ~0x10) | (on << 4);
    TkSetControlerActuatorMode();
    return on;
}

int func_00134F80(void) {
    s32 *flags = MsGetSaveMenu();

    return (*flags >> 4) & 1;
}

int func_00134FA8(Actor *a, void *op, ScriptCtx *ctx) {
    int v = AtelPopStackInteger(a, ctx);

    AtelSetShopRatio(v);
    return v;
}

int func_00134FE0(Actor *a, void *op, ScriptCtx *ctx) {
    int v = AtelPopStackInteger(a, ctx) != 0;

    func_00269B68(v);
    return v;
}

int func_00135018(Actor *a) {
    AQ(a)->w38 |= 0x200;
    return 1;
}

int func_00135030(Actor *a) {
    AQ(a)->w38 |= 0x400;
    return 1;
}

void func_00135048(Actor *a, OpArgs *op) {
    op->v0 = 0;
    op->v1 = 10;
}

/* DEBT(CAST) */ /* DEBT(FAKE) */
s32 func_00135058(s32 arg0, void *arg1) {
    register s32 var_16 __asm__("$16");
    register s32 var_17 __asm__("$17");
    s32 var_3;

    var_3 = 0;
    var_17 = (*(s32 *)((u8 *)(arg1) + (0)));
    var_16 = (*(s32 *)((u8 *)(arg1) + (4)));
    switch (var_17) {                               /* irregular */
    case 0:
        if (var_16 != 0) {
            var_16 -= 1;
        } else {
            var_17 = 1;
        }
        break;
    case 1:
        var_3 = (func_00265ED0() == 0) ? 0 : 5;
        break;
    }
    (*(s32 *)((u8 *)(arg1) + (0))) = var_17;
    (*(s32 *)((u8 *)(arg1) + (4))) = var_16;
    return var_3;
}
int func_001350D8(Actor *a, void *op, ScriptCtx *ctx) {
    int x = AtelPopStackInteger(a, ctx);
    int y = AtelPopStackInteger(a, ctx);

    func_002415C8(y, x);
    return 1;
}

void func_00135138(Actor *a, OpArgs *op, ScriptCtx *ctx) {
    op->v0 = AtelPopStackInteger(a, ctx);
}

int func_00135168(Actor *a, OpArgs *op) {
    int mask = op->v0;

    return (func_002D26C8(0, 0, func_0013AB18()) & mask) ? 5 : 0;
}

int func_001351A8(Actor *a, void *op, ScriptCtx *ctx) {
    int x = AtelPopStackInteger(a, ctx);
    int y = AtelPopStackInteger(a, ctx);
    int z = AtelPopStackInteger(a, ctx);
    int w = AtelPopStackInteger(a, ctx);

    func_0014B150(w, z, y, x);
    return 1;
}

int func_00135240(Actor *a) {
    AQ(a)->w38 |= 0x800;
    return 1;
}

int func_00135258(Actor *a, void *op, ScriptCtx *ctx) {
    AQ(AtelGetBasicWork(AtelPopStackInteger(a, ctx)))->w38 |= 0x800;
    return 1;
}

int func_00135290(Actor *a, void *op, ScriptCtx *ctx) {
    int v = AtelPopStackInteger(a, ctx);

    TkMn2SetMainFrameRatioDiff(v);
    return v;
}

int func_001352C8(void) {
    func_0014B188();
    return 1;
}

int func_001352E8(void) {
    return func_0014B240();
}

int func_00135308(Actor *a, void *op, ScriptCtx *ctx) {
    int v = AtelPopStackInteger(a, ctx);

    if (func_00138240()) {
        return func_0013A8E0(v);
    }
    return func_0013A8A0(v);
}

int func_00135358(Actor *a, void *op, ScriptCtx *ctx) {
    char tmp[4];
    int cur = -1;
    int n = 0;
    int i;
    int dst = AtelPopStackInteger(a, ctx);
    int src = AtelPopStackInteger(a, ctx);
    int mask = AtelPopStackInteger(a, ctx);
    int cnt = AtelPopStackInteger(a, ctx);

    dst = AtelGetRealVarAdrs(a, dst); /* DEBT(TYPE): returns a text buffer / string table address, int in funcs.h */
    src = AtelGetRealVarAdrs(a, src);
    *(char *)dst = 0;
    func_002F032C((char *)dst, D_0056A400);
    for (i = 0; i < cnt; i++) {
        char *s = *(char **)src;
        int on = (mask >> i) & 1;

        src += 4;
        if (on != cur) {
            if (on) {
                func_002F032C((char *)dst, D_0056A3E0);
            } else {
                func_002F032C((char *)dst, D_0056A3E8);
            }
        }
        cur = on;
        if (on) {
            tmp[0] = 0x10;
            tmp[1] = n + '0';
            tmp[2] = 0;
            func_002F032C((char *)dst, tmp);
            n++;
        }
        func_002F032C((char *)dst, s);
        if (i < cnt - 1) {
            func_002F032C((char *)dst, D_0056A3F0);
        }
    }
    func_002F032C((char *)dst, D_0056A3F8);
    func_002F072C((char *)dst + func_002F0840((char *)dst) + 1, (char *)dst);
    return n << 8;
}
