/* tu_213 0x1e4cd0-0x1e7af0: low; ~Ms (config/tu_map.tsv) */
#include "common.h"
#include "ffx/g3.h"
#include "ffx/q4.h"
#include "ffx/r3.h"
#include "ffx/u2.h"
#include "ffx/v3.h"
#include "ffx/s3.h"

void MsEffectChrMotionOut(u8 id)
{
    BtlChr *c = MsGetChr(id);

    if (c->fABF == 0) {
        D_00319430 = 1;
        c->fABF = 1;
        c->fF6 = 0;
        c->f1BC.b += 3;
        c->f1C9.b = c->f1BC.b;
        MsSetMotion(id, 0x12, 1, 0, 1, 0, 0);
    }
}

INCLUDE_ASM("build/ee_asm/game/battle/ms_1E4CD0", MsEffectChrMotionIn);

int func_001E4E08(u8 id) {
    return MsGetChr(id)->fF2 != 0;
}

INCLUDE_ASM("build/ee_asm/game/battle/ms_1E4CD0", func_001E4E30);

int func_001E4F20(int *out)
{
    if (out != 0) {
        *out = D_003172F0.ent[0].w4;
    }
    return D_003172F0.ent[0].handle;
}

int func_001E4F40(void)
{
    return D_003188B0;
}

void func_001E4F50(void) {
}

INCLUDE_ASM("build/ee_asm/game/battle/ms_1E4CD0", MsGetBattleList);
INCLUDE_RODATA("build/ee_asm/game/battle/ms_1E4CD0/rodata", jtbl_0056F9B0);

INCLUDE_ASM("build/ee_asm/game/battle/ms_1E4CD0", MsGetTargetList);

INCLUDE_ASM("build/ee_asm/game/battle/ms_1E4CD0", func_001E5538);

INCLUDE_ASM("build/ee_asm/game/battle/ms_1E4CD0", MsGetTargetLinkList);

INCLUDE_ASM("build/ee_asm/game/battle/ms_1E4CD0", MsGetTargetRandomList);

u8 *func_001E58F8(u8 id, int *out)
{
    u8 *r = 0;

    if (MsBtlChrNumCheck(id)) {
        r = MsGetChr(id)->fA40;
    }
    if (out != 0) {
        *out = D_0031942E;
    }
    return r;
}

INCLUDE_ASM("build/ee_asm/game/battle/ms_1E4CD0", MsGetTargetSortList);

INCLUDE_ASM("build/ee_asm/game/battle/ms_1E4CD0", func_001E5B70);

int MsGetYoujinbouCom(void)
{
    return D_0031D274;
}

void MsAddYoujinbouCom(int delta)
{
    D_003194D0.f3DA4 = MsCheckRange(D_003194D0.f3DA4 + delta, 0, 0xFF);
}

int func_001E5CC0(void)
{
    return D_0031D278;
}

void func_001E5CD0(int v)
{
    D_0031D278 = v;
}

int MsGetSummonEnergy(int id) {
    return MsGetChr(id)->f3A1;
}

INCLUDE_ASM("build/ee_asm/game/battle/ms_1E4CD0", MsCheckSummon);
INCLUDE_RODATA("build/ee_asm/game/battle/ms_1E4CD0/rodata", jtbl_0056FA00);

int MsDeathYoujinbou(int a) {
    int r = -1;
    if (a == 0xE) {
        r = MsActionRequest(0xE, 0xFF, 0xB, 1, 2, 0);
    }
    return r;
}

void MsStoneInit(void)
{
    D_003172F0.f213A = 0;
    D_003172F0.f213B = 0;
    D_003172F0.f213C = 0;
    D_003172F0.f203C = 0;
    D_003172F0.f213D = 0;
}

int MsStoneRegist(int id) {
    int r = 1;
    int i;
    for (i = 0; i < D_003172F0.f213B; i++) {
        if (D_003172F0.f2080[i] == id) {
            r = 0;
            break;
        }
    }
    if ((D_003172F0.f203C >> id) & 1) {
        r = 0;
    }
    if (r != 0 && D_003172F0.f213B < 0x1F) {
        D_003172F0.f2080[D_003172F0.f213B] = id;
        D_003172F0.f213B++;
    }
    return r;
}

int func_001E5FF8(void) {
    GameState *g;
    int r = 0;
    int i;
    int k;

    if (D_003172F0.f213B > 0 && D_003172F0.f213A != 0) {
        r = 1;
        while (D_003172F0.f213C < 3) {
            i = D_003172F0.f2080[0];
            D_003172F0.f203C |= 1 << i;
            D_003172F0.f213B--;
            g = &D_003172F0; /* DEBT(FAKE): alias only steers the base register of the loop tests */
            for (k = 0; k < D_003172F0.f213B; k++) {
                D_003172F0.f2080[k] = D_003172F0.f2080[k + 1];
            }
            if (MsDeathEffectStart(i, 7)) {
                D_003172F0.f213C++;
            }
            if (g->f213B <= 0) {
                break;
            }
        }
    }
    return r;
}

int MsStoneEffectCheck(void)
{
    return D_003172F0.f213B + D_003172F0.f213C;
}

void MsStoneMove(int a)
{
    D_003172F0.f213D++;
    MsSetMotion(a, 0x4F, 1, 0, 1, 0, 0);
}

int func_001E6148(int *p)
{
    if (*p != 0) {
        return 1;
    }
    return 5;
}

void func_001E6160(Actor *a, void *u, ScriptCtx *ctx) {
    int x = AtelPopStackInteger(a, ctx);
    int y = AtelPopStackInteger(a, ctx);
    func_002EF240(D_0056FA20, y, x);
    MsBattleLabelExe(y, 1, x);
}

int func_001E61D0(void) {
    return 1;
}

int func_001E61D8(Actor *ctx, void *unused, ScriptCtx *arg)
{
    func_001AEA68(AtelPopStackInteger(ctx, arg));
    return 0;
}

int func_001E6200(Actor *ctx, void *unused, ScriptCtx *arg)
{
    return func_001AEAB0(AtelPopStackInteger(ctx, arg));
}

int func_001E6228(Actor *ctx, void *unused, ScriptCtx *arg)
{
    int a = AtelPopStackInteger(ctx, arg);
    int b = AtelPopStackInteger(ctx, arg);

    return func_001AEAE8(b, a);
}

int func_001E6280(Actor *ctx, void *unused, ScriptCtx *arg)
{
    int v = AtelPopStackInteger(ctx, arg);

    D_0031880D = v & 1;
    return 0;
}

int func_001E62B0(Actor *a, void *u, ScriptCtx *c) {
    D_00318804 = AtelPopStackFloat(a, c);
    return 0;
}

int func_001E62D8(Actor *ctx, void *unused, ScriptCtx *arg)
{
    int flag = AtelPopStackInteger(ctx, arg) & 1;
    u8 id = *func_00144158(ctx);

    if (id != 0xFF) {
        MsGetChr(id);
        if (flag) {
            MsSetChrGravity(id, 0);
        } else {
            MsSetChrGravity(id, 1);
        }
    }
    return 0;
}

int func_001E6350(Actor *ctx, void *unused, ScriptCtx *arg)
{
    int flag = AtelPopStackInteger(ctx, arg) & 1;
    u8 id = *func_00144158(ctx);

    if (id != 0xFF) {
        MsGetChr(id)->f32 = flag;
    }
    return 0;
}

int func_001E63B0(Actor *ctx, void *unused, ScriptCtx *arg)
{
    int flag = AtelPopStackInteger(ctx, arg) & 1;
    u8 id = *func_00144158(ctx);

    if (id != 0xFF) {
        msSetChrBodyHit(MsGetChr(id), 0, flag);
    }
    return 0;
}

int func_001E6418(Actor *ctx, void *unused, ScriptCtx *arg)
{
    int flag = AtelPopStackInteger(ctx, arg) & 1;
    u8 id = *func_00144158(ctx);

    if (id != 0xFF) {
        MsGetChr(id)->f1C5 = flag;
    }
    return 0;
}

int func_001E6478(Actor *a, int unused, ScriptCtx *ctx) {
    float f = AtelPopStackFloat(a, ctx);
    int v = AtelPopStackInteger(a, ctx);
    int id = *func_00144158(a);
    if (id != 0xFF) {
        BtlChr *c = MsGetChr(id);
        c->f1CC = v;
        c->f1F8 = f;
        MsSetChrHeight(id);
    }
    return 0;
}

int func_001E6500(Actor *ctx, void *unused, ScriptCtx *arg)
{
    int v = AtelPopStackInteger(ctx, arg);

    D_0031731C = v & 1;
    return 0;
}

int func_001E6530(Actor *ctx, void *unused, ScriptCtx *arg)
{
    int v = AtelPopStackInteger(ctx, arg);

    D_003193FE = v & 1;
    return 0;
}

int func_001E6560(void)
{
    return D_003192F8;
}

s8 func_001E6570(void)
{
    return D_003193EE;
}

int func_001E6580(Actor *a, void *u, ScriptCtx *ctx) {
    u8 id = *func_00144158(a);
    int v = AtelPopStackInteger(a, ctx);
    func_002EF240(D_0056FA38, v, v, id);
    return 0;
}

int func_001E65E8(Actor *a, void *u, ScriptCtx *ctx) {
    u8 id = *func_00144158(a);
    int v = AtelPopStackInteger(a, ctx);
    func_002EF240(D_0056FA58, v, v, id);
    return 0;
}

int func_001E6650(Actor *a, void *u, ScriptCtx *ctx) {
    u8 id = *func_00144158(a);
    float f = AtelPopStackFloat(a, ctx);
    func_002EF240(D_0056FA78, f, id);
    return 0;
}

int func_001E66C0(Actor *ctx, void *unused, ScriptCtx *arg)
{
    D_003193FC = AtelPopStackInteger(ctx, arg);
    return 0;
}

s8 func_001E66E8(void)
{
    return D_003193FC;
}

int func_001E66F8(void)
{
    return func_001AF358();
}

int func_001E6718(Actor *ctx, void *unused, ScriptCtx *arg)
{
    int r = 0;
    int v = AtelPopStackInteger(ctx, arg);

    if (D_003172F0.f10 != 0) {
        if (D_003172F0.p120 != 0) {
            if (*D_003172F0.p120 == v >> 16) {
                r = 1;
            }
        }
    }
    return r;
}

int func_001E6778(Actor *a, void *unused, ScriptCtx *ctx) {
    int v = AtelPopStackInteger(a, ctx);
    u8 id = *func_00144158(a);
    if (id != 0xFF) {
        BtlChr *c = MsGetChr(id);
        Chr *chr;
        c->f1C8 = 0;
        MsStatusEffectClear(id);
        func_001CFDB0(id, c);
        chr = c->chr;
        if (chr != 0 && c->fA8E == 0) {
            s8 s;
            Ch_ResetMotion(chr);
            s = c->f20;
            Ch_SetSysMotion((int)chr, s, ms_motion_trans(c, 1)); /* DEBT(TYPE): funcs.h declares the model as int */
        }
        func_001B57F0(id, 0);
        if (v != 0) {
            c->fA88 = 0;
        }
    }
    return 0;
}

int func_001E6858(Actor *a, void *u, ScriptCtx *c) {
    int v = AtelPopStackInteger(a, c);
    D_003172F0.f2121 = v;
    if (D_003172F0.f10 == 1) {
        D_003172F0.f10 = 2;
    }
    return v;
}

u8 func_001E68A0(void)
{
    return D_00319411;
}

int func_001E68B0(Actor *a, int *out, ScriptCtx *ctx) {
    int v = 0;
    int x = AtelPopStackInteger(a, ctx);
    if (D_003172F0.f14 == 0) {
        D_003172F0.f14 = 2;
        if (func_001B2DF0(x, 2, a, &v) < 0) {
            D_003172F0.f14 = 0;
        }
    }
    *out = v;
    return func_002EF240(D_0056FA90, v, D_003172F0.f14);
}

int func_001E6950(int a, int *b) {
    return func_001E6148(b);
}

int func_001E6970(Actor *a, int *out, ScriptCtx *ctx) {
    int v = 0;
    int x = AtelPopStackInteger(a, ctx);
    if (D_003172F0.f14 == 0) {
        D_003172F0.f14 = 1;
        if (func_001B2DF0(x, 2, a, &v) < 0) {
            D_003172F0.f14 = 0;
        }
    }
    *out = v;
    return func_002EF240(D_0056FAB0, v, D_003172F0.f14);
}

int func_001E6A10(int a, int *b) {
    return func_001E6148(b);
}

int func_001E6A30(void)
{
    D_00317304 = 0;
    return 0;
}

INCLUDE_ASM("build/ee_asm/game/battle/ms_1E4CD0", func_001E6A40);

int func_001E6C08(void)
{
    if (D_00318A42 == 1) {
        return 5;
    }
    return 0;
}

int func_001E6C20(Actor *a, int *out, ScriptCtx *ctx) {
    int r;
    int v = 0;
    int x = AtelPopStackInteger(a, ctx);
    int y = AtelPopStackInteger(a, ctx) - 1;
    if (y < 0) {
        y = 0;
    }
    if (D_0031732B != 0) {
        func_002EF240(D_0056FB38, x);
    }
    r = MsAtelRequestCamera(y, 0xFF, x, 0xFFFF, 1, 2, a, &v);
    *out = v;
    return r;
}

int func_001E6CD8(int a, int *b) {
    return func_001E6148(b);
}

int func_001E6CF8(int v) {
    if (v < 0) {
        v = 0;
    }
    if (v >= 7) {
        v = 6;
    }
    return v;
}

s32 func_001E6D18(Actor *arg0, s32 arg1, ScriptCtx *arg2) {
    s32 temp_16;
    s32 temp_17;
    s32 temp_18;
    s32 temp_19;
    s32 temp_20;
    s32 temp_21;

    temp_21 = AtelPopStackInteger(arg0, arg2);
    temp_20 = AtelPopStackInteger(arg0, arg2);
    temp_19 = AtelPopStackInteger(arg0, arg2);
    temp_18 = AtelPopStackInteger(arg0, arg2);
    temp_17 = func_001E6CF8(AtelPopStackInteger(arg0, arg2));
    temp_16 = D_003172F0.h32[1].w14;
    D_003172F0.f1980 = temp_18;
    if (temp_16 != 0) {
        func_00217610(temp_17, temp_16 + *(u16 *)((((temp_18 * 2) + MsGetSaveConfigHiragana()) * 4) + temp_16), temp_19, temp_20, temp_21);
    }
    return 0;
}

s32 func_001E6E08(Actor *arg0, s32 arg1, ScriptCtx *arg2) {
    s32 temp_16;
    s32 temp_17;
    s32 temp_18;
    s32 temp_19;
    s32 temp_20;
    s32 temp_21;

    temp_21 = AtelPopStackInteger(arg0, arg2);
    temp_20 = AtelPopStackInteger(arg0, arg2);
    temp_19 = AtelPopStackInteger(arg0, arg2);
    temp_18 = AtelPopStackInteger(arg0, arg2);
    temp_17 = func_001E6CF8(AtelPopStackInteger(arg0, arg2));
    temp_16 = D_003172F0.h32[0].w14;
    D_003172F0.f1980 = temp_18;
    if (temp_16 != 0) {
        if (func_001BD320() != 0) {
            func_00217610(temp_17, temp_16 + *(u16 *)((((temp_18 * 2) + MsGetSaveConfigHiragana()) * 4) + temp_16), temp_19, temp_20, temp_21);
        }
    }
    return 0;
}

int func_001E6F08(Actor *a, void *unused, ScriptCtx *ctx)
{
    int x = AtelPopStackInteger(a, ctx);
    int y = func_001E6CF8(AtelPopStackInteger(a, ctx));
    GameState *g = &D_003172F0;
    u8 *p;

    g->f1980 = x;
    p = (u8 *)g->h32[1].w14; /* DEBT(TYPE): text table pointer kept as int */
    if (p != 0) {
        func_002176B0(y, (int)(p + ((V3TxtOfs *)p)[x * 2 + MsGetSaveConfigHiragana()].ofs)); /* DEBT(TYPE): handle/pointer kept as int */
    }
    return 0;
}

int func_001E6FA0(Actor *ctx, void *unused, ScriptCtx *arg)
{
    int a = AtelPopStackInteger(ctx, arg);
    int b = AtelPopStackInteger(ctx, arg);

    func_001E6CF8(b);
    MsSystemMessageOpen(a);
    return 0;
}

int func_001E7000(Actor *a, void *unused, ScriptCtx *ctx)
{
    int x = AtelPopStackInteger(a, ctx);
    int y = func_001E6CF8(AtelPopStackInteger(a, ctx));
    GameState *g = &D_003172F0;
    u8 *p;

    g->f1980 = x;
    p = (u8 *)g->h32[1].w14; /* DEBT(TYPE): text table pointer kept as int */
    if (p != 0) {
        func_002177B0(y, (int)(p + ((V3TxtOfs *)p)[x * 2 + MsGetSaveConfigHiragana()].ofs)); /* DEBT(TYPE): handle/pointer kept as int */
    }
    return 0;
}

int func_001E7098(Actor *a, void *unused, ScriptCtx *ctx) {
    int x = AtelPopStackInteger(a, ctx);
    int y = func_001E6CF8(AtelPopStackInteger(a, ctx));
    GameState *g = &D_003172F0;
    u8 *p;
    g->f1980 = x;
    p = (u8 *)g->h32[0].w14; /* DEBT(TYPE): text table pointer kept as int */
    if (p != 0 && func_001BD320() != 0) {
        func_002177B0(y, (int)(p + ((V3TxtOfs *)p)[x * 2 + MsGetSaveConfigHiragana()].ofs)); /* DEBT(TYPE): handle/pointer kept as int */
    }
    return 0;
}

int func_001E7140(Actor *ctx, int *out, ScriptCtx *arg)
{
    return *out = func_001E6CF8(AtelPopStackInteger(ctx, arg));
}

int func_001E7178(Actor *ctx, int *p)
{
    int id = *p;
    int r = 5;

    if (TOGetMessageStatus(id) != 0) {
        if (func_00207EE0(id) == 0) {
            r = 0;
        } else {
            TOCloseMessageWindow(id);
        }
    }
    return r;
}

int func_001E71D8(Actor *ctx, int *out, ScriptCtx *arg)
{
    return *out = func_001E6CF8(AtelPopStackInteger(ctx, arg));
}

int func_001E7210(int unused, int *p) {
    int h = *p;
    int r = 5;
    int v = TOGetMessageStatus(h);
    if (v != 0) {
        if (func_00207EE0(h) == 1 || (SndGetStreamState() == 0 && v == 3)) {
            TOCloseMessageWindow(h);
        } else {
            r = 0;
        }
    }
    return r;
}

int func_001E72A0(Actor *ctx, void *unused, ScriptCtx *arg)
{
    TOCloseMessageWindow(func_001E6CF8(AtelPopStackInteger(ctx, arg)));
    return 0;
}

int func_001E72D0(Actor *ctx, void *unused, ScriptCtx *arg)
{
    func_001D9F58(AtelPopStackInteger(ctx, arg));
    return 0;
}

int func_001E72F8(void) {
    func_002156C0(1);
    return 0;
}

int func_001E7318(void) {
    func_002156C0(0);
    return 0;
}

int func_001E7338(Actor *ctx)
{
    u8 id = *func_00144158(ctx);
    BtlChr *c;

    if (id != 0xFF) {
        c = MsGetChr(id);
        c->fC25 = 8;
        func_001CFDB0(id, c);
        func_001E0BF0(id, c->fC24, c->fC25);
    }
    return 0;
}

int func_001E73A8(Actor *a) {
    u8 id = *func_00144158(a);
    if (id != 0xFF) {
        BtlChr *c;
        func_002EF240(D_0056FB50, id);
        c = MsGetChr(id);
        MsResetAutoStatus(c);
        MsSetRamChrParam(id);
        MsSetChrWeak(id, -1);
        MsSetAutoStatus(c);
        MsStatusEffectCheck(id);
        MsSetWeaponEffectAttribute(id, c);
    }
    return 0;
}

void func_001E7438(Actor *ctx, void *unused, ScriptCtx *arg)
{
    int v = AtelPopStackInteger(ctx, arg);

    D_003193ED = v & 3;
}

int func_001E7460(Actor *a, void *u, ScriptCtx *c) {
    s8 old = D_003172F0.f212C;
    D_003172F0.f212C = AtelPopStackInteger(a, c) & 1;
    return old;
}

void func_001E74A8(Actor *ctx, int *out, ScriptCtx *arg)
{
    int v = AtelPopStackInteger(ctx, arg);

    *out = v;
    MsRegMotionRead(v);
}

int func_001E74D8(void) {
    return D_003193EF != 0 ? 5 : 0;
}

int func_001E74F0(void) {
    MsRegMotionDispose();
    return 0;
}

INCLUDE_ASM("build/ee_asm/game/battle/ms_1E4CD0", func_001E7510);

void func_001E75D8(Actor *ctx, void *unused, ScriptCtx *arg)
{
    D_0031941F = AtelPopStackInteger(ctx, arg);
}

void func_001E7600(Actor *ctx, void *unused, ScriptCtx *arg)
{
    D_00319420 = AtelPopStackInteger(ctx, arg);
}

int func_001E7628(void) {
    return MsGetVoiceEventFlag();
}

int func_001E7648(void) {
    return func_001BD4B0();
}

int func_001E7668(void) {
    return MsGetGIL();
}

int func_001E7688(void) {
    return func_001E5CC0();
}

int func_001E76A8(Actor *ctx, void *unused, ScriptCtx *arg)
{
    int v = AtelPopStackInteger(ctx, arg);

    func_001E5CD0(v);
    return v;
}

int func_001E76E0(Actor *a, void *unused, ScriptCtx *ctx) {
    int msg = 0x30E2;
    int x = AtelPopStackInteger(a, ctx);
    int y = AtelPopStackInteger(a, ctx);
    int sum = y + x;
    if (sum < 0x20) {
        msg = 0x30DE;
    } else if (sum < 0x30) {
        msg = 0x30DF;
    } else if (sum < 0x3F) {
        msg = 0x30E0;
    } else if (sum <= 0x4F) {
        msg = 0x30E1;
    }
    func_002EF240(D_0056FB88, msg, y, x);
    return msg;
}

int func_001E7798(void) {
    return brnd(0x11);
}

int func_001E77B8(Actor *a, void *unused, ScriptCtx *ctx) {
    int size = AtelPopStackInteger(a, ctx);
    GameState *g = &D_003172F0;
    if (g->ent[0].handle == 0) {
        g->ent[0].w4 = size;
        func_0011C348(0x40);
        g->ent[0].handle = (s32)user_malloc(size, 5, D_0056FBA8, -1); /* DEBT(TYPE): handle/pointer kept as int */
        MsMemCheckRegist((void *)g->ent[0].handle, size); /* DEBT(TYPE): handle/pointer kept as int */
    }
    return 0;
}

s8 func_001E7838(void) {
    return D_00317325;
}

void func_001E7848(Actor *ctx, void *unused, ScriptCtx *arg)
{
    D_0031931C = AtelPopStackInteger(ctx, arg);
}

int func_001E7870(void) {
    D_00319405 = 1;
    return 0;
}

int func_001E7888(void) {
    D_00319405 = 2;
    return 0;
}

void func_001E78A0(Actor *ctx, void *unused, ScriptCtx *arg)
{
    D_00319431 = AtelPopStackInteger(ctx, arg);
}

void func_001E78C8(Actor *ctx, void *unused, ScriptCtx *arg)
{
    D_00319432 = AtelPopStackInteger(ctx, arg);
}

void func_001E78F0(Actor *ctx, void *unused, ScriptCtx *arg)
{
    D_0031936E = AtelPopStackInteger(ctx, arg);
}

int func_001E7918(Actor *ctx, void *unused, ScriptCtx *arg)
{
    int id = AtelPopStackInteger(ctx, arg);
    int i;

    if (id < 0) {
        id = 0xFF;
    } else {
        MsGetChr(id)->f3E = 1;
        for (i = 0; i < 2; i++) {
            MsGetWeapon(id, i)->f3E = 1;
        }
    }
    return id;
}

int func_001E7998(Actor *ctx)
{
    u8 id = *func_00144158(ctx);

    if (id != 0xFF) {
        MsGetChr(id)->fAB2 = 0;
    }
    return 0;
}

int func_001E79D8(Actor *ctx)
{
    u8 id = *func_00144158(ctx);
    BtlChr *c;

    if (id != 0xFF) {
        c = MsGetChr(id);
        c->fF5 = 0;
        switch (c->fABB) {
        case 2:
            c->fABB = 3;
            break;
        case 9:
            c->fF2 = 0;
            break;
        default:
            c->fF2 = 0;
            break;
        }
    }
    return 0;
}

s32 _m2c_MsEffectMagicMotion_func_00144158() __asm__("func_00144158");
/* DEBT(CAST) */ /* DEBT(FAKE) */
s32 MsEffectMagicMotion(s32 arg0, s32 arg1, s32 arg2) {
    s32 temp_18;
    register u32 temp_17 __asm__("$17");
    void *temp_16;

    temp_17 = _m2c_MsEffectMagicMotion_func_00144158(arg0);
    __asm__ volatile("" : "+r"(temp_17), "+r"(arg0));
    temp_18 = AtelPopStackInteger(arg0, arg2);
    temp_17 = *(u8 *)temp_17;
    temp_16 = MsGetChr(temp_17);
    if (temp_17 != 0xFF) {
        if ((*(s8 *)((u8 *)(temp_16) + (0xB3))) == 0) {
            MsTerminateMotion(temp_16);
            (*(s8 *)((u8 *)(temp_16) + (0xB2))) = temp_18;
            if (D_0031732B != 0) {
                func_002EF240(D_0056FBB0, temp_17, temp_18, (*(s8 *)((u8 *)(temp_16) + (0xF2))), (*(s8 *)((u8 *)(temp_16) + (0xF3))));
            }
        }
    }
    return 0;
}
