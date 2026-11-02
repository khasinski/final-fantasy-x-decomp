/* tu_081 0x14b260-0x14c3a8: low; ~Atel (config/tu_map.tsv) */
#include "common.h"
#include "ffx/q2.h"
#include "ffx/r1.h"
#include "ffx/u0.h"
#include "ffx/g0.h"
#include "ffx/s1.h"

INCLUDE_ASM("build/ee_asm/game/atel/atel_14B260", TkRefreshHDD);

void AtelSetDolby(int v)
{
    u32 *p = MsGetSaveMenu();

    if (v) {
        *p |= 0x80;
    } else {
        *p &= ~0x80;
    }
    TkRefreshSoundMode();
}

INCLUDE_ASM("build/ee_asm/game/atel/atel_14B260", AtelStopSoundAll);

s32 func_0014B428(Tbl *t, int i)
{
    return ((s32 *)(t->base + t->hdr->intOff))[i];
}

float func_0014B448(Tbl *t, int i)
{
    return ((float *)(t->base + t->hdr->floatOff))[i];
}

int func_0014B468(u8 a)
{
    if (func_0013CCA0(a)) {
        return 3;
    }
    return 1;
}

u8 func_0014B498(int type, int i)
{
    u8 r = 0xFF;

    switch (type) {
    case 1:
        r = D_0030B968[i];
        break;
    case 2:
    case 3:
        r = D_0030B970[i];
        break;
    case 5:
    case 6:
        r = D_0030B978[i];
        break;
    case 4:
    default:
        break;
    }
    return r;
}

u16 *func_0014B4F8(int type)
{
    switch (type) {
    case 2:
    case 3:
        return D_0030B990;
    case 5:
        return D_0030B9A0;
    case 6:
        return D_0030B9B0;
    case 1:
    case 4:
    default:
        return D_0030B980;
    }
}

u16 func_0014B550(int type, int i, u16 *p)
{
    u16 r = 0xFFFF;

    if (p == 0) {
        p = func_0014B4F8(type);
    }
    if (p) {
        r = p[i];
    }
    return r;
}

/* DEBT(CAST): existing handle-based prototypes require pointer conversions. */
/* DEBT(GOTO): shared switch-result block retained pending structured matching. */
s32 AtelEventSystemRequestDirectMain(s32 a, s32 b, s32 c, s32 d, s32 e)
{
    s32 saved0;
    Actor *value0;
    s32 value1;
    s32 value2;
    s32 state0;
    s32 state1;
    s32 state2;

    state0 = e;
    state2 = 0;
    saved0 = AtelChangeCurrentCtrl(0);
    value0 = AtelGetBasicWork(b);
    value2 = AtelGetActorType(b);
    value1 = func_0014B498(value2, c);
    if (state0 < 0)
    {
        state0 = func_0014B550(value2, c, value0->w44);
    }
    if ((value1 != 0xFF) && (state0 != 0xFFFF) && (((s32) value0->flagsAB >> c) & 1))
    {
        switch (d)                                  /* irregular */
        {
        case 0:
            state1 = func_001425E0(a, b, 0, value1, state0);
block_14:
            state2 = state1;
            break;
        case 1:
            state1 = func_00142688(a, b, 0, value1, state0);
            goto block_14;
        case 2:
            state1 = func_00142530(a, b, 0, value1, state0);
            goto block_14;
        }
    }
    AtelSetCurrentCtrl(saved0);
    return state2;
}

int func_0014B720(int a, int b, int c)
{
    return AtelEventSystemRequestDirectMain(a, b, c, 0, -1);
}

int func_0014B740(int a, int b, int c)
{
    return AtelEventSystemRequestDirectMain(a, b, c, 1, -1);
}

int func_0014B760(int a, int b, int c)
{
    return AtelEventSystemRequestDirectMain(a, b, c, 2, -1);
}

int func_0014B780(int a, int b, int c, int d)
{
    return AtelEventSystemRequestDirectMain(a, b, c, 2, d);
}

INCLUDE_ASM("build/ee_asm/game/atel/atel_14B260", func_0014B7A0);

s32 func_0014B838(s32 arg0, s32 arg1)
{
    s32 saved;
    s32 value;
    s32 result;

    result = 0;
    saved = AtelChangeCurrentCtrl(0);
    value = func_0014B7A0(arg0);
    if (value >= 0)
    {
        result = func_0014B720(0xFFFF, value, arg1);
    }
    AtelSetCurrentCtrl(saved);
    return result;
}

void func_0014B8B0(void) {
}

int func_0014B8B8(void)
{
    return 0;
}

u8 *func_0014B8C0(u32 v)
{
    return D_0058E9A8[v >> 12] + (v & 0xFFF) * 16;
}

void func_0014B8E8(int i, u8 *p)
{
    if (p) {
        D_0058E9A8[i] = p;
    } else {
        D_0058E9A8[i] = D_0030B9C0;
    }
}

/* DEBT(CAST): func_0014B8C0 exposes the operation descriptor as a byte pointer. */
void func_0014B920(u32 opcode, Actor *a, int operand, ScriptCtx *ctx)
{
    float (*floatResult)(Actor *, int, ScriptCtx *);
    int (*intResult)(Actor *, int, ScriptCtx *);
    int result;

    floatResult = ((U0Ops *)func_0014B8C0(opcode))->floatResult;
    if (floatResult != 0) {
        func_0013CE10(a, ctx, floatResult(a, operand, ctx));
        return;
    }
    intResult = ((U0Ops *)func_0014B8C0(opcode))->intResult;
    if (intResult != 0) {
        result = intResult(a, operand, ctx);
    } else {
        result = 0;
    }
    AtelPushStackInteger(a, ctx, result);
}

int func_0014B9E0(u32 id, int a, int b)
{
    U0Ops *o = (U0Ops *)func_0014B8C0(id); /* DEBT(CAST) */

    if (o->fn4) {
        return o->fn4(a, b);
    }
    return 5;
}

/* DEBT(CAST): operation descriptors and Actor share the existing untyped dispatch interface. */
void func_0014BA30(u32 opcode, void *arg, int b, int c)
{
    int (*invoke)(void *, int, int);
    Actor *actor = arg;
    int flags;

    if ((opcode >> 12) == 6) {
        flags = actor->flags34.w;
        if (!(flags & 0x100000)) {
            actor->flags34.w = flags | 0x200000;
        }
    }
    invoke = ((U0Ops *)func_0014B8C0(opcode))->invoke;
    if (invoke != 0) {
        invoke(arg, b, c);
    }
}

INCLUDE_ASM("build/ee_asm/game/atel/atel_14B260", AtelCommonSetUp);

void AtelCharSetUp(char *p)
{
    G0Res588 *res = (G0Res588 *)AtelGetCtrlWork(0); /* DEBT(CAST) */
    int n = res->hC;

    n -= res->h14 + res->h18 + res->h16;
    n += AtelGetBinHdrExpandAddChr(p);
    n += 8;
    if (n < 0x24) {
        n = 0x24;
    }
    AtelPs2DebugString(D_0056AF98);
    func_00103AA8(n);
}

INCLUDE_ASM("build/ee_asm/game/atel/atel_14B260", AtelActorSetUp2);

void AtelActorSetUp(int a, int b, int c, int d, int e, int f)
{
    AtelActorSetUp2(a, b, c, c, d, e, f);
}

void func_0014BF60(void)
{
    Sg_EventjumpDispose();
}

void AtelCtrlRemove(int a)
{
    func_00145148(a);
}

u8 *func_0014BF70(U0Args *p, int off)
{
    return (u8 *)p->wB8 + off; /* DEBT(CAST) */
}

INCLUDE_ASM("build/ee_asm/game/atel/atel_14B260", AtelBattleSetUp);

INCLUDE_ASM("build/ee_asm/game/atel/atel_14B260", AtelActorRemove);
