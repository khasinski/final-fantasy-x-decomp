/* tu_081 0x14b260-0x14c3a8: low; ~Atel (config/tu_map.tsv) */
#define TkRefreshHDD _hdr_TkRefreshHDD
#define SndMusicStop _hdr_SndMusicStop
#define SndMusicClear _hdr_SndMusicClear
#include "common.h"
#include "ffx/q2.h"
#include "ffx/r1.h"
#include "ffx/u0.h"
#include "ffx/g0.h"
#include "ffx/s1.h"
#undef TkRefreshHDD
#undef SndMusicStop
#undef SndMusicClear

int get_hdd_inst_info(void);
void TkRefreshHDDMode(void);
void SndMusicStop(int id);
void SndMusicClear(int id);
extern s8 D_005661F4;

void TkRefreshHDD(void)
{
    int one = 1;
    s32 *save = MsGetSaveMenu();
    u8 *cfg = (u8 *)TkGetFFXCofingAdrs();
    s32 flag = (*save >> 13) & 1;

    if (func_00167D50() == 3 || get_hdd_inst_info() != one) {
        flag = 0;
    }
    cfg[0xE] = flag;
    D_005661F4 = flag;
    TkRefreshHDDMode();
}

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

void func_002D3FF0(int);
void func_002D6630(void);
void func_002D88D8(void);

void AtelStopSoundAll(void)
{
    int i;

    for (i = 1; i < 0x78; i++) {
        SndSepStop(i | 0x80000000);
        if ((i & 0xF) == 0) {
            func_002D3FF0(0);
            func_002D6630();
        }
    }
    SndMusicStop(-1);
    SndMusicClear(-1);
    func_002D3FF0(0);
    func_002D6630();
    for (i = 0; i < 0x100; i++) {
        SndMusicStop(i);
        SndMusicClear(i);
        if ((i & 7) == 0) {
            func_002D3FF0(0);
            func_002D6630();
        }
    }
    func_002D3FF0(0);
    func_002D6630();
    SndMusicStop(-1);
    SndMusicClear(-1);
    func_002D3FF0(0);
    func_002D6630();
    func_002D88D8();
    func_002D3FF0(0);
    func_002D6630();
}

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

s32 func_0014B7A0(s32 ptr)
{
    s32 i = 0;
    EvGameState *ctrl = AtelGetCurCtrlWork();

    for (; i < ctrl->hC; i++) {
        Actor *a = AtelGetBasicWork(i);

        if (a->stateAA == 1 && a->ptr9C == (Chr *)ptr) {
            return a->id;
        }
    }
    return -1;
}

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

typedef struct {
    int count;
    struct {
        int x0;
        int x4;
        int x8;
    } entries[1];
} AtelDbgWork;

typedef struct {
    u8 pad0[0x34];
    int x34;
    int x38;
    u8 pad3C[0x4C - 0x3C];
    void *x4C;
    int x50;
} AtelCtrlWorkLocal;

typedef struct {
    int x0;
    int x4;
    int x8;
    int xC;
    int x10;
    void *x14;
    void *x18;
    int x1C;
} AtelBasicInitInfo;

int AtelGetActorNumber(void *bin);
int AtelGetNamespaceNumber(void *bin);
void func_20594F8(int a, int b, int c, int d, int e);
AtelCtrlWorkLocal *AtelRequireCtrlWork(int id, void *bin, int a, int b);
void AtelSetUpCtrlWork(int id);
void *AtelGetIndexWork(void *bin, int i);
void AtelInitBasicWork(AtelBasicInitInfo *info, int a);
void AtelInitSourceCodeDebugWork(int i, AtelDbgWork *dbg);
void AtelInitActor(void);
void AtelExecCtrlEvent(int *w);
void func_00143DB8(void *bin);
void AtelSetBattleSceneGroup(int i);
extern char D_0056AFA8[];
extern char D_0056AFB8[];

void AtelCommonSetUp(int ctrl_id, int arg1, void *bin, int arg3, int arg4, AtelDbgWork *dbg)
{
    int actor_num = AtelGetActorNumber(bin);
    int ns_num = AtelGetNamespaceNumber(bin);
    int i;
    AtelCtrlWorkLocal *ctrl;
    AtelBasicInitInfo info;

    if (dbg != 0) {
        for (i = 0; i < dbg->count; i++) {
            int x4 = dbg->entries[i].x4;
            int x0 = dbg->entries[i].x0;
            int x8 = dbg->entries[i].x8;

            if (ctrl_id == 0) {
                func_20594F8(x4, x8, arg4, x0, 0x100000);
            } else {
                func_20594F8(x4, x8, arg4, x0, 0x20000);
            }
        }
    }
    ctrl = AtelRequireCtrlWork(ctrl_id, bin, arg1, -1);
    ctrl->x34 = arg3;
    AtelSetUpCtrlWork(ctrl_id);
    AtelChangeCurrentCtrl(ctrl_id);
    info.x0 = 1;
    info.x8 = ctrl_id;
    info.xC = 0;
    info.x18 = bin;
    info.x1C = arg4;
    for (i = 0; i < actor_num; i++) {
        void *idx_work = AtelGetIndexWork(bin, i);

        info.x4 = i;
        info.x10 = i;
        info.x14 = idx_work;
        AtelInitBasicWork(&info, 1);
        AtelInitSourceCodeDebugWork(i, dbg);
    }
    info.x0 = 0;
    for (; i < ns_num; i++) {
        void *idx_work = AtelGetIndexWork(bin, i);

        info.x4 = i;
        info.x10 = i;
        info.x14 = idx_work;
        AtelInitBasicWork(&info, 1);
        AtelInitSourceCodeDebugWork(i, dbg);
    }
    AtelInitActor();
}

void AtelCharSetUp(char *p)
{
    EvGameState *res = AtelGetCtrlWork(0);
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

void AtelActorSetUp2(int a, int b, int c, int d, int e, int f, int g)
{
    void *bin = (void *)b;
    AtelDbgWork *dbg = (AtelDbgWork *)f;
    int x = d ? d : c;
    int actor_num = AtelGetActorNumber(bin);
    int ns_num = AtelGetNamespaceNumber(bin);
    int i;
    AtelCtrlWorkLocal *ctrl;
    AtelBasicInitInfo info;

    if (dbg != 0) {
        for (i = 0; i < dbg->count; i++) {
            int x4 = dbg->entries[i].x4;
            int x0 = dbg->entries[i].x0;
            int x8 = dbg->entries[i].x8;

            func_20594F8(x4, x8, e, x0, 0x100000);
        }
    }
    ctrl = AtelRequireCtrlWork(0, bin, a, g);
    ctrl->x4C = AtelExecCtrlEvent;
    ctrl->x34 = c;
    ctrl->x38 = x;
    ctrl->x50 = 0;
    AtelSetUpCtrlWork(0);
    AtelChangeCurrentCtrl(0);
    info.x0 = 1;
    info.x8 = 0;
    info.xC = 0;
    info.x18 = bin;
    info.x1C = e;
    for (i = 0; i < actor_num; i++) {
        void *idx_work = AtelGetIndexWork(bin, i);

        info.x4 = i;
        info.x10 = i;
        info.x14 = idx_work;
        AtelInitBasicWork(&info, 1);
        AtelInitSourceCodeDebugWork(i, dbg);
    }
    info.x0 = 0;
    for (; i < ns_num; i++) {
        void *idx_work = AtelGetIndexWork(bin, i);

        info.x4 = i;
        info.x10 = i;
        info.x14 = idx_work;
        AtelInitBasicWork(&info, 1);
        AtelInitSourceCodeDebugWork(i, dbg);
    }
    AtelPs2DebugString(D_0056AFA8);
    AtelCharSetUp(bin);
    AtelPs2DebugString(D_0056AFB8);
    func_00143DB8(bin);
    AtelSetSaveDicIndex(0);
    AtelSetBattleSceneGroup(0);
    AtelInitActor();
}

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

void AtelSetUpCtrlWork(int a);
void TkCh_Dispose(int v);

void AtelActorRemove(void)
{
    int i = 0;
    int old = AtelChangeCurrentCtrl(0);
    EvGameState *ctrl;
    int n;

    AtelSetUpCtrlWork(0);
    ctrl = AtelGetCurCtrlWork();
    n = ctrl->hC;
    for (; i < n; i++) {
        Actor *a = AtelGetBasicWork(i);

        if (a->stateAA == 1) {
            int j;
            Chr **p = &AR(a)->arrAF4[0];

            for (j = 1; j >= 0; j--, p++) {
                if (*p != 0) {
                    TkCh_Dispose((int)*p);
                    *p = 0;
                }
            }
            if (a->ptr9C != 0) {
                TkCh_Dispose((int)a->ptr9C);
                a->ptr9C = 0;
                a->w38 &= ~0x10;
            }
        }
    }
    AtelSetCurrentCtrl(old);
}
