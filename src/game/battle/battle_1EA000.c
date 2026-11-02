/* tu_215 0x1ea000-0x1ef4e8: low; unk_1EA000 (config/tu_map.tsv) */
#include "common.h"
#include "ffx/q4.h"
#include "ffx/r3.h"
#define func_001B81E8 u2_func_001B81E8 /* DEBT(TYPE): this header's guess conflicts with the TU */
#define MsGetCommand u2_MsGetCommand /* DEBT(TYPE): this header's guess conflicts with the TU */
#include "ffx/u2.h"
#undef func_001B81E8
#undef MsGetCommand
#include "ffx/v3.h"
#include "ffx/u3.h"
#include "ffx/v4.h"
#define func_001E4A30 q5_func_001E4A30 /* DEBT(TYPE): this header's guess conflicts with the TU */
#include "ffx/q5.h"
#undef func_001E4A30
#include "ffx/w5.h"
#define MsGetChrInfo r4_MsGetChrInfo /* DEBT(TYPE): this header's guess conflicts with the TU */
#include "ffx/r4.h"
#undef MsGetChrInfo
#include "ffx/s4.h"

int func_001EA000(Actor *a, int unused, ScriptCtx *ctx) {
    int v = AtelPopStackInteger(a, ctx);
    Chr *c = MsGetChrHandle(2);
    if (c != 0) {
        TkChPatchM160(c, v);
    }
    return 0;
}

int func_001EA048(Actor *a) {
    MsUseChrMpLimit(*func_00144158(a));
    return 0;
}

int func_001EA070(Actor *a) {
    int id = *func_00144158(a);
    if (id != 0xFF) {
        return func_001DBAF0(MsGetChr(id));
    }
    return 0;
}

int func_001EA0B8(Actor *a) {
    u8 id = *func_00144158(a);
    if (id != 0xFF && D_00319404 == id) {
        return 0;
    }
    return 1;
}

int func_001EA0F8(Actor *ctx)
{
    u8 id = *func_00144158(ctx);

    if (id != 0xFF) {
        MsGetChr(id)->fC0 = 0xFFFF;
    }
    return 0;
}

int func_001EA138(Actor *a, void *unused, ScriptCtx *ctx) {
    int id = *func_00144158(a);
    int x = AtelPopStackInteger(a, ctx);
    int y = AtelPopStackInteger(a, ctx);
    int z = AtelPopStackInteger(a, ctx);
    return func_001E1020(func_001B8198(id, z, 0, 1), y, x);
}

int func_001EA1D8(Actor *a, void *unused, ScriptCtx *ctx) {
    u8 id = *func_00144158(a);
    int x = AtelPopStackInteger(a, ctx);
    int h = func_001B8198(id, AtelPopStackInteger(a, ctx), 0, 1);
    int other = id != h;
    if (MsGetChr(MsGetChr(h)->fE2)->fA8C == 0) {
        MsDamageSetMotion(h, x, other);
    }
    return 0;
}

int func_001EA288(Actor *a, void *unused, ScriptCtx *ctx) {
    int x = AtelPopStackInteger(a, ctx);
    int y = AtelPopStackInteger(a, ctx);
    BtlChr *c = MsGetChr(func_001B8198(*func_00144158(a), y, 0, 1));
    if (c->chr != 0) {
        func_00117D38(c->chr, 4, x);
    }
    return 0;
}

int func_001EA318(Actor *a, void *u, ScriptCtx *c) {
    int v = AtelPopStackInteger(a, c);
    D_00319426 = v & 1;
    return v;
}

s8 func_001EA340(void) {
    return D_00319426;
}

int func_001EA350(void) {
    BtlChr *c = MsGetChr(0xD);
    if (c->chr != 0) {
        graphicCharacterInstanceSetMeshSegmentAlpha(c->chr, 1, D_003172F0.f2136);
    }
    return D_003172F0.f2136;
}

int func_001EA3A0(Actor *a, void *unused, ScriptCtx *ctx) {
    int id = *func_00144158(a);
    int x = AtelPopStackInteger(a, ctx);
    int h = func_001B8198(id, AtelPopStackInteger(a, ctx), 0, 1);
    BtlChr *c;
    x = func_001B8198(id, x, 0, 1);
    c = MsGetChr(h);
    if (x < 0) {
        x = 0xFF;
    }
    c->fF9 = 1;
    c->fF8 = x;
    return x;
}

int func_001EA460(Actor *a, void *unused, ScriptCtx *ctx) {
    float v[3];
    int id = *func_00144158(a);
    Chr *o;
    v[2] = AtelPopStackFloat(a, ctx);
    v[1] = AtelPopStackFloat(a, ctx);
    v[0] = AtelPopStackFloat(a, ctx);
    o = MsGetChrHandle(func_001B8198(id, AtelPopStackInteger(a, ctx), 0, 1));
    if (o != 0) {
        func_0010A1F8(o, v);
    }
    return 0;
}

s8 func_001EA508(void) {
    s8 r = D_003172F0.f2140;
    D_003172F0.f2140 = 1;
    return r;
}

int func_001EA520(Actor *a) {
    int r = 5;
    func_00144158(a);
    if (D_00319430 == 0) {
        r = 0;
    }
    return r;
}

int func_001EA558(Actor *ctx)
{
    u8 id = *func_00144158(ctx);

    if (id != 0xFF) {
        MsGetChr(id)->fD1 = 0;
    }
    return 0;
}

int func_001EA598(Actor *ctx, void *unused, ScriptCtx *arg)
{
    u8 id = *func_00144158(ctx);
    int v = AtelPopStackInteger(ctx, arg);
    int r = func_001B8198(id, v, 0, 1);
    void *p = MsGetChrHandle(r);

    if (p != 0) {
        func_00109B88(p, 1);
    }
    return r;
}

int func_001EA618(Actor *ctx, void *unused, ScriptCtx *arg)
{
    u8 id = *func_00144158(ctx);
    int v = AtelPopStackInteger(ctx, arg);
    int r = func_001B8198(id, v, 0, 1);
    void *p = MsGetChrHandle(r);

    if (p != 0) {
        func_00109B88(p, 1);
    }
    return r;
}

int func_001EA698(Actor *ctx, void *unused, ScriptCtx *arg)
{
    u8 id = *func_00144158(ctx);
    int v = AtelPopStackInteger(ctx, arg);
    int r = func_001B8198(id, v, 0, 1);
    void *p = MsGetChrHandle(r);

    if (p != 0) {
        func_00109B88(p, 0);
    }
    return r;
}

INCLUDE_ASM("build/ee_asm/game/battle/battle_1EA000", func_001EA718);

int func_001EA7E0(Actor *a, void *unused, ScriptCtx *ctx) {
    int id = *func_00144158(a);
    float v = AtelPopStackFloat(a, ctx);
    if (id != 0xFF) {
        Chr *c = MsGetChrHandle(id);
        if (c != 0) {
            func_0010AF88(c, v);
        }
    }
    return 0;
}

int func_001EA858(Actor *a, void *unused, ScriptCtx *ctx) {
    int x = AtelPopStackInteger(a, ctx);
    int y = AtelPopStackInteger(a, ctx);
    u8 id = *func_00144158(a);
    int r = 0;
    int v;
    BtlChr *c;

    if (id != 0xFF) {
        c = MsGetChr(id);
        v = MsAutoCommandStatusCheck(c, 0, c->f28B == 0, 1);
        func_002EF240(D_0056FC98, id, x, MsGetChrBit(id, y, 0, 1), v);
        if (v != 0 && D_0031731A == 0) {
            MsActCommandAdd(id, x, MsGetChrBit(id, y, 0, 1), 0, -1);
            r = 1;
        }
    }
    return r;
}

int func_001EA980(Actor *a, void *unused, ScriptCtx *ctx) {
    int r = 0;
    int x = AtelPopStackInteger(a, ctx);
    int y = AtelPopStackInteger(a, ctx);
    int id = *func_00144158(a);
    if (id != 0xFF) {
        r = 1;
        MsActCommandAdd(id, x, MsGetChrBit(id, y, 0, 1), 1, -1);
    }
    return r;
}

/* DEBT(CAST): existing handle-based prototypes require pointer conversions. */
s32 func_001EAA28(Actor *arg0, int unused1, ScriptCtx *arg2)
{
    BtlChr *value0;
    s32 value1;
    s32 value2;
    s32 state0;
    u8 value3;

    state0 = 0;
    value2 = AtelPopStackInteger(arg0, arg2);
    value1 = AtelPopStackInteger(arg0, arg2);
    value3 = *func_00144158(arg0);
    if (value3 != 0xFF)
    {
        state0 = 1;
        value0 = MsGetChr((s32) value3);
        if (value0->fB9 != 0)
        {
            func_001D2298((s32) value3, value0);
        }
        MsActCommandAdd((s32) value3, value2, MsGetChrBit((s32) value3, value1, 0, 1), 1, 0x40);
    }
    return state0;
}

int func_001EAAF0(Actor *ctx, void *unused, ScriptCtx *arg)
{
    int a = AtelPopStackInteger(ctx, arg);
    int b = AtelPopStackInteger(ctx, arg);
    u8 id = *func_00144158(ctx);
    int out;

    MsGetChrStatInfo(id, a, b, &out);
    return out;
}

int func_001EAB60(Actor *ctx, void *unused, ScriptCtx *arg)
{
    int v = AtelPopStackInteger(ctx, arg);
    u8 id = *func_00144158(ctx);
    int out;

    MsGetChrStatInfo(id, v, -0xD, &out);
    return out;
}

int func_001EABB8(Actor *a, void *unused, ScriptCtx *ctx) {
    int x = AtelPopStackInteger(a, ctx);
    int y = AtelPopStackInteger(a, ctx);
    int z = AtelPopStackInteger(a, ctx);
    return MsSetChrStatInfo(*func_00144158(a), y, z, x);
}

int func_001EAC40(Actor *ctx, void *unused, ScriptCtx *arg)
{
    int a = AtelPopStackInteger(ctx, arg);
    int b = AtelPopStackInteger(ctx, arg);
    u8 id = *func_00144158(ctx);

    return MsSetChrStatInfo(id, b, -0xD, a);
}

int func_001EACB0(Actor *ctx, void *unused, ScriptCtx *arg)
{
    int a = AtelPopStackInteger(ctx, arg);
    int b = AtelPopStackInteger(ctx, arg);
    u8 id = *func_00144158(ctx);

    /* DEBT(FAKE): see func_001EAD28 */
    if (func_001D7E80(func_001B8198(id, b, 0, 1), a) != 0.0f) {
    }
}

int func_001EAD28(Actor *a, int unused, ScriptCtx *ctx) {
    int v = AtelPopStackInteger(a, ctx);
    /* DEBT(FAKE): empty test keeps the call from becoming a tail call; result (float in $f0) is unused */
    if (func_001D7E80(*func_00144158(a), v) != 0.0f) {
    }
}

s32 func_001EAD70(Actor *arg0, int unused1, ScriptCtx *arg2)
{
    float value;
    s32 index;
    s32 mode;

    value = AtelPopStackFloat(arg0, arg2);
    mode = AtelPopStackInteger(arg0, arg2);
    index = AtelPopStackInteger(arg0, arg2);
    MsSetChrMotionInfo(func_001B8198((s32) *func_00144158(arg0), index, 0, 1), mode, value);
    return 0;
}

int func_001EAE08(Actor *a, void *u, ScriptCtx *ctx) {
    float f = AtelPopStackFloat(a, ctx);
    int i = AtelPopStackInteger(a, ctx);
    MsSetChrMotionInfo(*func_00144158(a), i, f);
    return 0;
}

int func_001EAE78(Actor *a, void *unused, ScriptCtx *ctx) {
    int d = AtelPopStackInteger(a, ctx);
    int c = AtelPopStackInteger(a, ctx);
    int b = AtelPopStackInteger(a, ctx);
    int m = AtelPopStackInteger(a, ctx);
    u8 id = *func_00144158(a);
    int out;

    m = MsActTargetSearch(id, m, 4, 0, 5, 0, 0, 0);
    m = MsActTargetSearch(id, m, 0x52, 0, 5, 0, 1, 0);
    m = MsActTargetSearch(id, m, b, c, 4, d, 1, &out);
    func_001B81E8(id, m);
    return out;
}

int func_001EAF80(Actor *a, void *unused, ScriptCtx *ctx) {
    int w = AtelPopStackInteger(a, ctx);
    int x = AtelPopStackInteger(a, ctx);
    int y = AtelPopStackInteger(a, ctx);
    int z = AtelPopStackInteger(a, ctx);
    u8 id = *func_00144158(a);
    int out;
    func_001B81E8(id, MsActTargetSearch(id, z, y, x, 4, w, 0, &out));
    return out;
}

int func_001EB048(int id, int a, int b, int c, int d, int e)
{
    int out;
    int m = MsGetChrBit(id, b, 0, 1);
    int r = MsActTargetSearch_int(id, b, c, d, 4, e, 0, &out);

    func_001B81E8(id, func_001CCA60(id, m, r, a));
    return out;
}

int func_001EB100(Actor *a, void *unused, ScriptCtx *ctx) {
    int p = AtelPopStackInteger(a, ctx);
    int q = AtelPopStackInteger(a, ctx);
    int r = AtelPopStackInteger(a, ctx);
    int s = AtelPopStackInteger(a, ctx);
    int t = AtelPopStackInteger(a, ctx);
    return func_001EB048(*func_00144158(a), t, s, r, q, p);
}

int func_001EB1C0(Actor *a, void *unused, ScriptCtx *ctx) {
    int out;
    int p = AtelPopStackInteger(a, ctx);
    int q = AtelPopStackInteger(a, ctx);
    int r = AtelPopStackInteger(a, ctx);
    int s = AtelPopStackInteger(a, ctx);
    MsActTargetSearch(0, s, r, q, 7, p, 0, &out);
    return out;
}

int func_001EB268(Actor *ctx)
{
    u8 id = *func_00144158(ctx);

    if (id != 0xFF) {
        return MsActReCommand(id);
    }
    return 0;
}

int func_001EB2A8(Actor *a, void *u, ScriptCtx *ctx) {
    u8 id = *func_00144158(a);
    int x = AtelPopStackInteger(a, ctx);
    int y = AtelPopStackInteger(a, ctx);
    return func_001C2C98(id, y, x);
}

int func_001EB318(Actor *a, void *unused, ScriptCtx *ctx) {
    int id = *func_00144158(a);
    int x = AtelPopStackInteger(a, ctx);
    int y = AtelPopStackInteger(a, ctx);
    int z = AtelPopStackInteger(a, ctx);
    return func_001C2C98(func_001B8198(id, z, 0, 1), y, x);
}

int func_001EB3B8(Actor *a, void *unused, ScriptCtx *ctx) {
    int x = AtelPopStackInteger(a, ctx);
    int y = AtelPopStackInteger(a, ctx);
    int id = *func_00144158(a);
    if (id != 0xFF) {
        MsActChangeCommand(id, x, MsGetChrBit(id, y, 0, 1));
    }
    return 0;
}

int func_001EB448(Actor *a, void *unused, ScriptCtx *ctx) {
    int x = AtelPopStackInteger(a, ctx);
    int n = 0;
    int y = AtelPopStackInteger(a, ctx);
    u8 id = *func_00144158(a);
    int i;
    y = MsGetChrBit(id, y, 0, 1);
    x = MsGetChrBit(id, x, 0, 1);
    for (i = 0; i < 0x1F; i++) {
        if ((y >> i) & 1) {
            n += (x >> i) & 1;
        }
    }
    return n;
}

int func_001EB518(Actor *a, void *unused, ScriptCtx *ctx)
{
    int i = AtelPopStackInteger(a, ctx);

    i = func_001B8198(*func_00144158(a), i, 0, 1);
    if (i >= 0) {
        return MsGetChr(i)->fE;
    }
    return -1;
}

int func_001EB580(Actor *a, void *unused, ScriptCtx *ctx) {
    int i;
    int h = AtelPopStackInteger(a, ctx);
    h = func_001B8198(*func_00144158(a), h, 0, 1);
    if (h < 0) {
        return 0xFF;
    }
    if (MsGetRamChrMonster(h) != 0) {
        return MsGetChr(h)->f0C;
    }
    for (i = 0; i < 18; i++) {
        if (D_003192B5[i] == h) {
            return -6 - i;
        }
    }
    return 0xFF;
}

int func_001EB638(Actor *a, void *u, ScriptCtx *ctx) {
    int x = AtelPopStackInteger(a, ctx);
    int y = AtelPopStackInteger(a, ctx);
    return func_001D5260(*func_00144158(a), x, y, 1);
}

int func_001EB6A8(Actor *a, void *u, ScriptCtx *ctx) {
    int x = AtelPopStackInteger(a, ctx);
    int y = AtelPopStackInteger(a, ctx);
    return func_001D53E0(*func_00144158(a), x, y);
}

int func_001EB710(Actor *a, void *unused, ScriptCtx *ctx) {
    int n = 0;
    int i = 0;
    int x = AtelPopStackInteger(a, ctx);
    int y = AtelPopStackInteger(a, ctx);
    int z = AtelPopStackInteger(a, ctx);
    z = MsGetChrBit(*func_00144158(a), z, 0, 1);
    for (; i < 0x1F; i++) {
        if ((z >> i) & 1) {
            func_001B96E8(i, y, x);
            n++;
        }
    }
    return n;
}

int func_001EB7E8(Actor *a, void *unused, ScriptCtx *ctx)
{
    int v = AtelPopStackInteger(a, ctx);
    int mask = AtelPopStackInteger(a, ctx);
    int i;

    mask = MsGetChrBit(*func_00144158(a), mask, 0, 1);
    for (i = 0; i < 31; i++) {
        if ((mask >> i) & 1) {
            MsGetChr(i)->fA9D = v;
        }
    }
    return 0;
}

INCLUDE_ASM("build/ee_asm/game/battle/battle_1EA000", func_001EB898);

int func_001EBA30(Actor *a, int *out, ScriptCtx *ctx) {
    int v = AtelPopStackInteger(a, ctx);
    int r = func_001EB898(a, MsGetChrBit(*func_00144158(a), v, 0, 1), -1);
    *out = r;
    return r;
}

int func_001EBAA0(int a, int *b) {
    return func_001E6148(b);
}

int func_001EBAC0(Actor *a, void *unused, ScriptCtx *ctx) {
    int v = AtelPopStackInteger(a, ctx);
    BtlChr *c;
    v = func_001B8198(*func_00144158(a), v, 0, 1);
    if (v >= 0) {
        c = MsGetChr(v);
        v = 1 << v;
        if (v == c->fA80) return 0;
    }
    return -1;
}

s8 func_001EBB40(void) {
    return D_00319402;
}

s8 func_001EBB50(void) {
    return D_00319403;
}

int func_001EBB60(Actor *a, void *unused, ScriptCtx *ctx) {
    int x = AtelPopStackInteger(a, ctx);
    int y = AtelPopStackInteger(a, ctx);
    u8 id = *func_00144158(a);
    BtlChr *dst, *src;
    int i;
    y = func_001B8198(id, y, 0, 1);
    x = func_001B8198(id, x, 0, 1);
    dst = MsGetChr(y);
    src = MsGetChr(x);
    for (i = 0; i < 0x28; i++) {
        dst->f200[i] = src->f200[i];
    }
    dst->fA95 = src->fA95;
    return 0;
}

int func_001EBC40(Actor *a, void *unused, ScriptCtx *ctx) {
    int x = AtelPopStackInteger(a, ctx);
    int y = AtelPopStackInteger(a, ctx);
    BtlChr *c = MsGetChr(func_001B8198(*func_00144158(a), y, 0, 1));
    u8 *t = D_003173D8;
    u8 *src = 0;
    int i;
    if (t != 0) {
        src = t + ((V3TxtOfs *)t)[x * 2 + MsGetSaveConfigHiragana()].ofs;
    }
    if (src != 0) {
        for (i = 0; i < 0x28; i++) {
            c->f200[i] = src[i];
        }
    }
    return 0;
}

s8 func_001EBD20(void) {
    return D_0031941A;
}

int func_001EBD30(void) {
    return D_00319415 != 0;
}

int func_001EBD40(Actor *a, int unused, ScriptCtx *ctx) {
    int id = *func_00144158(a);
    int v = MsGetChrBit(id, AtelPopStackInteger(a, ctx), 0, 1);
    MsGetChr(id)->fA80 = v;
    return v;
}

int func_001EBDB0(Actor *a, int unused, ScriptCtx *ctx) {
    int id = *func_00144158(a);
    int v = AtelPopStackInteger(a, ctx);
    int r = MsGetChrBit(id, v, 0, 1);
    MsGetChr(id)->fA80 |= r;
    return r;
}

int func_001EBE30(Actor *a, int unused, ScriptCtx *ctx) {
    int id = *func_00144158(a);
    int v = AtelPopStackInteger(a, ctx);
    int r = MsGetChrBit(id, v, 0, 1);
    MsGetChr(id)->fA80 &= ~r;
    return r;
}

int func_001EBEB0(Actor *a, int unused, ScriptCtx *ctx) {
    int v = AtelPopStackInteger(a, ctx);
    int id = *func_00144158(a);
    v = func_001B8198(id, v, 0, 1);
    MsGetChr(id)->f391 = v;
    return v;
}

INCLUDE_ASM("build/ee_asm/game/battle/battle_1EA000", func_001EBF18);

int func_001EC020(Actor *a)
{
    int r = 0;
    int none = 0xFF; /* DEBT(FAKE): the compares against 0xFF go through one register */
    u8 id = *func_00144158(a);
    BtlChr *c;
    BtlChr *t;

    if (id != none) {
        c = MsGetChr(id);
        if (c->fAAD != none) {
            t = MsGetChr(c->fAAD);
            if (MsAutoCommandStatusCheck(c, 0, 0, 1) != 0) {
                r = t->fAB1 == 0;
            }
        }
    }
    return r;
}

int func_001EC0B0(Actor *a)
{
    int r = 0;
    int none = 0xFF; /* DEBT(FAKE): the compares against 0xFF go through one register */
    u8 id = *func_00144158(a);
    BtlChr *c;

    if (id != none) {
        c = MsGetChr(id);
        if (c->fAAD != none) {
            r = MsGetChr(c->fAAD)->fAB1 == 0;
        }
    }
    return r;
}

int func_001EC118(Actor *a, void *unused, ScriptCtx *ctx) /* DEBT(TYPE): no return value in the asm */
{
    u8 id = *func_00144158(a);
    BtlChr *c = MsGetChr(id);
    s32 v = AtelPopStackInteger(a, ctx);
    u8 *r = MsGetCommand(id, 0, -1, 0, &v);

    c->fA80 = MsGetCommandTarget(id, v, ((*(u16 *)(r + 0x1A) >> 1) & 1) ^ 1, 1); /* DEBT(CAST): record type unknown */
}

int func_001EC1B8(int id, int a, int b)
{
    int i;
    BtlChr *c = MsGetChr(id);
    int mask = MsGetCommandTarget2(id, a, b, 1);
    int v;

    c->fA80 = mask;
    v = MsCheckUseCommand(id, MsGetComData(a, 0), 0);
    if (v < 0) {
        mask = 0;
    }
    func_002EF240(D_0056FCE0, id, a, v, c->fA80, mask);
    for (i = 0; i < 0x1F; i++) {
        if ((mask >> i) & 1) {
            func_002EF240(D_0056FD08, i);
        }
    }
    func_002EF240(D_0056FD10);
    return mask;
}

int func_001EC2B8(Actor *a, void *u, ScriptCtx *ctx) {
    u8 id = *func_00144158(a);
    int x = AtelPopStackInteger(a, ctx);
    int y = AtelPopStackInteger(a, ctx);
    return func_001EC1B8(id, y, x);
}

int func_001EC328(Actor *ctx, void *unused, ScriptCtx *arg)
{
    return func_001BFE30(AtelPopStackInteger(ctx, arg));
}

int func_001EC350(Actor *a, int unused, ScriptCtx *ctx) {
    int x = AtelPopStackInteger(a, ctx);
    int y = AtelPopStackInteger(a, ctx);
    return MsSaveItemUse(y, x);
}

int func_001EC3A8(Actor *a) {
    u8 id = *func_00144158(a);
    u16 *p = (u16 *)((u8 *)btl_ply_win + id * 0x478); /* DEBT(TYPE): btl_ply_win is a pointer to 0x478-byte records */
    int i;
    for (i = 0; i < 20; i++) {
        p[i] = 0xFF;
    }
    return 0;
}

int func_001EC410(Actor *a, void *unused, ScriptCtx *ctx)
{
    int v = AtelPopStackInteger(a, ctx);
    u16 *list = (u16 *)(btl_ply_win + *func_00144158(a) * 0x478); /* DEBT(CAST): btl_ply_win holds the table address */
    int i;

    for (i = 0; i < 20; i++) {
        if (list[i] == 0xFF) {
            list[i] = v;
            break;
        }
    }
    return 0;
}

int func_001EC4A8(Actor *a, void *unused, ScriptCtx *ctx) {
    int x = AtelPopStackInteger(a, ctx);
    int y = AtelPopStackInteger(a, ctx);
    int h = func_001B8198(*func_00144158(a), y, 0, 1);
    int v = MsCheckUseCommand(h, MsGetComData(x, 0), 0);
    func_002EF240(D_0056FD18, h, x, v);
    return v;
}

int func_001EC558(Actor *a, void *unused, ScriptCtx *ctx) {
    int x = AtelPopStackInteger(a, ctx);
    int y = AtelPopStackInteger(a, ctx);
    return MsGetSaveCommand(func_001B8198(*func_00144158(a), y, 0, 1), x);
}

int func_001EC5D0(int a, int b)
{
    int n;

    if (b < 0) {
        return 1;
    }
    if (a == 0 || D_006632A8 == 0) {
        n = (u8)brnd(0x12);
        func_002EF240(D_0056FD30, a, n, b);
        return n < b;
    }
    return a == D_006632A8;
}

int func_001EC658(Actor *a, int unused, ScriptCtx *ctx) {
    int x = AtelPopStackInteger(a, ctx);
    int y = AtelPopStackInteger(a, ctx);
    return func_001EC5D0(y, x);
}

int func_001EC6B0(Actor *a, void *u, ScriptCtx *c) {
    D_006632A8 = AtelPopStackInteger(a, c);
    return 0;
}

u16 func_001EC6D8(void) {
    return D_006632A8;
}

int func_001EC6E8(void) {
    D_00663280 = 0;
    D_00663281 = 0;
    return 0;
}

int func_001EC700(Actor *a, void *u, ScriptCtx *c) {
    int v = AtelPopStackInteger(a, c);
    if (D_00663280 < 16) {
        D_00663288[D_00663280] = v;
        D_00663280++;
    }
    return v;
}

int func_001EC758(void) {
    int r = 0;
    if (D_00663281 < D_00663280) {
        int i = D_00663281;
        D_00663281++;
        r = D_00663288[i];
    }
    return r;
}

int func_001EC7A0(Actor *a, void *op, ScriptCtx *ctx)
{
    int r = 0xFF;
    u8 id = *func_00144158(a);
    int t = AtelPopStackInteger(a, ctx);
    int s = AtelPopStackInteger(a, ctx);
    int q = AtelPopStackInteger(a, ctx);
    int p = AtelPopStackInteger(a, ctx);
    int x = AtelPopStackInteger(a, ctx);

    if (func_001EC1B8(id, x, p) != 0 && func_001EC5D0(x, t) != 0) {
        int v = func_001EB048(id, x, -0x10, q, 0, s);

        if (v != 0xFF) {
            r = v;
        }
    }
    return r;
}

int func_001EC8A8(Actor *a, void *unused, ScriptCtx *ctx)
{
    u8 id = *func_00144158(a);
    BtlChr *c = MsGetChr(id);
    int x = AtelPopStackInteger(a, ctx);
    int y = AtelPopStackInteger(a, ctx);

    if (D_006632A8 == 0) {
        c->f3D4 = 1;
        c->f3D5 = 0;
        c->f3E6[0] = x;
        c->f3E6[1] = x;
        c->f3E8[0] = y;
        c->f3E8[1] = y;
    }
    return id;
}

int func_001EC950(Actor *a, void *unused, ScriptCtx *ctx) {
    BtlChr *c = MsGetChr(*func_00144158(a));
    int p = AtelPopStackInteger(a, ctx);
    int q = AtelPopStackInteger(a, ctx);
    int r = AtelPopStackInteger(a, ctx);
    int s = AtelPopStackInteger(a, ctx);
    c->f3E8[1] = s;
    c->f3D4 = 1;
    c->f3E6[0] = p;
    c->f3E8[0] = q;
    c->f3E6[1] = r;
    c->f3D5 = 0;
    return 0;
}

int func_001ECA08(Actor *a) {
    int v = MsGetChr(*func_00144158(a))->fA80;
    D_003192F0 = v;
    return v;
}

/* DEBT(CAST): explicit width views follow the existing shared interfaces. */
/* DEBT(ORDER): store the scalar before clearing the flag to retain the original schedule. */
s32 func_001ECA38(Actor *actor, int unused, ScriptCtx *script)
{
    BtlChr *chr;
    float value;
    s32 kind;
    s32 mask;
    s32 id;
    s32 count;
    u8 actor_id;

    count = 0;
    id = 0;
    actor_id = *func_00144158(actor);
    MsGetChr((s32) actor_id);
    value = AtelPopStackFloat(actor, script);
    kind = AtelPopStackInteger(actor, script);
    mask = MsGetChrBit((s32) actor_id, AtelPopStackInteger(actor, script), 0, 1);
    do
    {
        if ((mask >> id) & 1)
        {
            count += 1;
            chr = MsGetChr(id);
            if (chr->chr != 0)
            {
                chr->fC7 = 1;
                if (kind != 0)
                {
                    MsSetChrGravity(id, 0);
                    chr->f1C5 = 1;
                    chr->f1CC = 0;
                }
                chr->f1F8 = value;
                chr->fFD = 0;
            }
        }
        id += 1;
    } while (id < 0x1F);
    return count;
}

INCLUDE_ASM("build/ee_asm/game/battle/battle_1EA000", func_001ECB50);

int func_001ECCB0(Actor *a, void *b, ScriptCtx *c) {
    func_001ECB50(a, b, c, 0.0f);
    return 0;
}

int func_001ECCD8(Actor *a, void *b, ScriptCtx *ctx) {
    BtlChr *c = func_001ECB50(a, b, ctx, 0.0f);
    if (c != 0) {
        c->fD8 = 1;
    }
    return 0;
}

int func_001ECD10(Actor *a, void *b, ScriptCtx *c) {
    func_001ECB50(a, b, c, AtelPopStackFloat(a, c));
    return 0;
}

INCLUDE_ASM("build/ee_asm/game/battle/battle_1EA000", func_001ECD68);

int func_001ED130(Actor *a, void *u, ScriptCtx *ctx) {
    int v = AtelPopStackInteger(a, ctx);
    u8 id = *func_00144158(a);
    BtlChr *c;
    if (id != 0xFF) {
        c = MsGetChr(id);
        c->f11A = v;
        c->fD5 = 0x10;
        c->f112 = 0;
        c->fD7 = 0;
    }
    return 0;
}

int func_001ED1A0(Actor *ctx)
{
    u8 id = *func_00144158(ctx);

    if (id != 0xFF) {
        func_001D34A0(MsGetChr(id));
    }
    return 0;
}

int func_001ED1E0(Actor *ctx)
{
    u8 id = *func_00144158(ctx);

    if (id != 0xFF) {
        return MsGetChr(id)->fD2;
    }
    return 0;
}

int func_001ED218(Actor *a, void *op, ScriptCtx *ctx)
{
    MsMoveSplineSet(AtelPopStackInteger(a, ctx));
    return 0;
}

int func_001ED240(Actor *a, void *unused, ScriptCtx *ctx) {
    int id = *func_00144158(a);
    int x = AtelPopStackInteger(a, ctx);
    MsMoveSplineRegist(AtelPopStackInteger(a, ctx), id, x, 0);
    return 0;
}

int func_001ED2B8(Actor *a, void *unused, ScriptCtx *ctx) {
    float v[3];
    v[2] = AtelPopStackFloat(a, ctx);
    v[1] = AtelPopStackFloat(a, ctx);
    v[0] = AtelPopStackFloat(a, ctx);
    MsMoveSplineRegist(AtelPopStackInteger(a, ctx), 0, 0, v);
    return 0;
}

int func_001ED338(Actor *a, void *unused, ScriptCtx *ctx) {
    int id = *func_00144158(a);
    int x = AtelPopStackInteger(a, ctx);
    float f = AtelPopStackFloat(a, ctx);
    int y = AtelPopStackInteger(a, ctx);
    MsMoveSpline(AtelPopStackInteger(a, ctx), id, y, f, x);
    return 0;
}

/* DEBT(CAST): existing handle-based prototypes require pointer conversions. */
s32 func_001ED3E8(Actor *arg0, int unused1, ScriptCtx *arg2)
{
    BtlChr *value0;
    float float_value0;
    s32 value1;
    s32 value2;
    u8 value3;

    value3 = *func_00144158(arg0);
    value2 = AtelPopStackInteger(arg0, arg2);
    float_value0 = AtelPopStackFloat(arg0, arg2);
    value1 = AtelPopStackInteger(arg0, arg2);
    func_001E0410((s32) value3);
    value0 = MsGetChr((s32) value3);
    value0->f11A = (u16) value1;
    value0->f112 = 0;
    MsSetBallSpline(value3);
    MsMoveSpline(2, (s32) value3, value1, float_value0, value2);
    value0->f112 = 1;
    return 0;
}

int func_001ED4B0(Actor *a, void *unused, ScriptCtx *ctx) {
    int n = 0;
    int i;
    int id = *func_00144158(a);
    int bits = MsGetChrBit(id, AtelPopStackInteger(a, ctx), 0, 1);
    for (i = 0; i < 31; i++) {
        if ((bits >> i) & 1) {
            if (MsGetChr(i)->fD5 != 0) {
                n++;
            }
        }
    }
    return n;
}

int func_001ED568(Actor *a)
{
    u8 id = *func_00144158(a);
    BtlChr *c = MsGetChr(id);

    if (id != 0xFF) {
        return c->f1C8;
    }
    return 0;
}

s8 func_001ED5B0(Actor *arg0)
{
    BtlChr *chr;
    float saved_value;
    s8 saved_flag;
    u8 id;

    id = *func_00144158(arg0);
    chr = MsGetChr((s32) id);
    if ((chr->f2C8 != 0) && (chr->f1C5 != 0))
    {
        saved_flag = chr->f34;
        saved_value = chr->f1B0;
        chr->f34 = 1;
        chr->f1B0 = 10.0f;
        func_001D2298((s32) id, chr);
        chr->f34 = saved_flag;
        chr->f1B0 = saved_value;
    }
    else
    {
        func_001D2298((s32) id, chr);
    }
    return chr->f1C8;
}

int func_001ED650(Actor *a, void *u, ScriptCtx *ctx) {
    u8 id = *func_00144158(a);
    int v = AtelPopStackInteger(a, ctx);
    MsSetBtlPosReset(func_001B8198(id, v, 0, 1));
    return 0;
}

int func_001ED6B8(Actor *a, void *unused, ScriptCtx *ctx) {
    int id = *func_00144158(a);
    int h = func_001B8198(id, AtelPopStackInteger(a, ctx), 0, 1);
    float pos[3];
    func_001B6790(h, pos);
    return (int)((MsGetChrGround(h) - pos[1]) * 100.0f);
}

int func_001ED748(Actor *a)
{
    u8 id = *func_00144158(a);

    if (id != 0xFF) {
        return func_001CA948(id, MsGetChr(id));
    }
    return 0;
}

int func_001ED798(Actor *ctx)
{
    u8 id = *func_00144158(ctx);

    if (id != 0xFF) {
        return MsGetChrMoveFrameRest(id);
    }
    return 0;
}

int func_001ED7D8(void)
{
    s8 s = D_00317300;

    if (s == 1 || s == 2 || s == 0x18 || s == 0x1B || s == 0x1E) {
        return 1;
    }
    return 0;
}

void func_001ED818(Actor *ctx, int *out, ScriptCtx *arg)
{
    int v = AtelPopStackInteger(ctx, arg);

    *out = v;
    D_00318C6C = v;
}

int func_001ED850(void) {
    int r = 5;
    GetCD();
    if (func_001ED7D8() != 0) {
        if (msVoiceCheckStanby(1) != 0) {
            r = 0;
        }
    } else {
        r = 0;
    }
    return r;
}

int func_001ED898(Actor *a, int *p) {
    if (*p >= 0) {
        SndStandbyStream(*p);
    }
    return 0;
}

int func_001ED8C0(void) {
    int r = 5;
    GetCD();
    if (func_001ED7D8() != 0) {
        if (msVoiceCheckStanby(0) != 0) {
            r = 0;
        }
    } else {
        r = 0;
    }
    return r;
}

int func_001ED908(void)
{
    SndStartStream();
    return 0;
}

int func_001ED928(void)
{
    return func_001E1ED0();
}

int func_001ED948(void)
{
    return MsVoiceStatus() != 0;
}

INCLUDE_ASM("build/ee_asm/game/battle/battle_1EA000", func_001ED968);

int func_001ED990(Actor *a, void *op, ScriptCtx *ctx)
{
    int slot = AtelPopStackInteger(a, ctx);
    int sel = AtelPopStackInteger(a, ctx);
    int target = func_001B8198(*func_00144158(a), sel, 0, 1);
    int owner;
    BtlChr *c;
    int h;

    if (target >= 0) {
        owner = MsGetChr(target)->f14;
        c = MsGetChr(owner);
        if (c->fBEC != 0 && slot >= 0 && slot < 0x20) {
            h = c->fB6C[slot];
            if (D_003172F0.f3B != 0) {
                func_002EF240(D_0056FD48, h, target, owner);
            }
            if (h != 0 && D_003172F0.f2010 != h) {
                MsSEP3Dregist(3, target, h, 0, 0);
                D_003172F0.f2010 = h;
            }
        }
    }
    return 0;
}

int func_001EDAA8(Actor *a, int *out, ScriptCtx *c) {
    int x = AtelPopStackInteger(a, c);
    int y = AtelPopStackInteger(a, c);
    out[0] = x;
    out[1] = y;
    return y;
}

int func_001EDB08(void) {
    int r = 0;
    if (SndSyncMusicStandby(0) == 0 || D_003193EE != 0) {
        r = 5;
    }
    return r;
}

int func_001EDB50(Actor *a, int *args) {
    if (D_003193EE == 0) {
        if (func_001ED7D8() != 0) {
            func_001DF970(func_001B8198(*func_00144158(a), args[1], 0, 1), args[0]);
            return 0;
        }
    }
    return 1;
}

void func_001EDBD0(Actor *a, int *out, ScriptCtx *ctx)
{
    int res;
    int found = 0;
    int i;
    u8 id = *func_00144158(a);
    int v = AtelPopStackInteger(a, ctx);
    int mask = MsGetChrBit(id, AtelPopStackInteger(a, ctx), 0, 1);

    for (i = 0; i < 0x1F; i++) {
        if ((mask >> i) & 1) {
            MsSetVoice(i, v, 1, (int)a, (int)&res); /* DEBT(CAST): callee takes untyped words */
            if (res != 0) {
                found = 1;
            }
        }
    }
    *out = found;
}

int func_001EDCB8(int unused, int *p) {
    return func_001E6148(p);
}

int func_001EDCD8(Actor *a) {
    int r = 5;
    u8 id = *func_00144158(a);
    BtlChr *c;
    if (id != 0xFF) {
        c = MsGetChr(id);
        if (c->f11 == 0) {
            c = MsGetChr(c->f14);
        }
        if (c->fBEC == 0) {
            if (c->fBEE != 0) {
                r = 0;
            }
        }
    }
    return r;
}

int func_001EDD48(Actor *a, void *unused, ScriptCtx *ctx) {
    int x = AtelPopStackInteger(a, ctx);
    int y = AtelPopStackInteger(a, ctx);
    int h = func_001B8198(*func_00144158(a), y, 0, 1);
    int r = 0;
    if (h >= 0) {
        r = func_001DFFA0(h, x);
    }
    return r;
}

int func_001EDDD0(Actor *a, void *unused, ScriptCtx *ctx) {
    int x = AtelPopStackInteger(a, ctx);
    int y = AtelPopStackInteger(a, ctx);
    int h = func_001B8198(*func_00144158(a), y, 0, 1);
    int r = 0;
    if (h >= 0) {
        r = func_001E0030(h, x);
    }
    return r;
}

int func_001EDE58(Actor *a, void *unused, ScriptCtx *ctx)
{
    int key = AtelPopStackInteger(a, ctx);
    int v = AtelPopStackInteger(a, ctx);
    int i = func_001B8198(*func_00144158(a), v, 0, 1);
    int r = 0;

    if (i >= 0) {
        r = func_001E00A0_i(i, key);
    }
    return r;
}

int func_001EDEE0(Actor *a, void *unused, ScriptCtx *ctx) {
    int x = AtelPopStackInteger(a, ctx);
    int y = AtelPopStackInteger(a, ctx);
    int z = AtelPopStackInteger(a, ctx);
    int h = func_001B8198(*func_00144158(a), z, 0, 1);
    int r = 0;
    if (h >= 0) {
        r = func_001E0188(h, y, x);
    }
    return r;
}

int func_001EDF88(Actor *a, void *unused, ScriptCtx *ctx) {
    int x = AtelPopStackInteger(a, ctx);
    int y = AtelPopStackInteger(a, ctx);
    int h = func_001B8198(*func_00144158(a), y, 0, 1);
    int r = 0;
    if (h >= 0) {
        r = MsRegSEplay(h, x);
    }
    return r;
}

int func_001EE010(Actor *a, void *unused, ScriptCtx *ctx) {
    int x = AtelPopStackInteger(a, ctx);
    int y = AtelPopStackInteger(a, ctx);
    int h = func_001B8198(*func_00144158(a), y, 0, 1);
    int r = 0;
    if (h >= 0) {
        r = MsRegSEplay2(h, x);
    }
    return r;
}

int func_001EE098(Actor *a, void *unused, ScriptCtx *ctx)
{
    int key = AtelPopStackInteger(a, ctx);
    int v = AtelPopStackInteger(a, ctx);
    int i = func_001B8198(*func_00144158(a), v, 0, 1);
    int r = 0;

    if (i >= 0) {
        r = func_001E0290_i(i, key);
    }
    return r;
}

int func_001EE120(Actor *a, void *unused, ScriptCtx *ctx) {
    int x = AtelPopStackInteger(a, ctx);
    int y = AtelPopStackInteger(a, ctx);
    int z = AtelPopStackInteger(a, ctx);
    int h = func_001B8198(*func_00144158(a), z, 0, 1);
    int r = 0;
    if (h >= 0) {
        r = MsRegSEfade(h, y, x);
    }
    return r;
}

int func_001EE1C8(Actor *a, void *op, ScriptCtx *ctx)
{
    return func_001E1F20(AtelPopStackInteger(a, ctx));
}

int func_001EE1F0(Actor *a, void *op, ScriptCtx *ctx)
{
    int v = AtelPopStackInteger(a, ctx);

    D_00318C70 = v;
    if (func_001BD320() != 0) {
        func_001E1F30(v);
    }
    return v;
}

s8 func_001EE238(void)
{
    return D_003173E0[1];
}

int func_001EE248(Actor *a, void *op, ScriptCtx *ctx)
{
    int v = AtelPopStackInteger(a, ctx);
    int sel = AtelPopStackInteger(a, ctx);
    s8 f = v & 1;

    switch (sel) {
    case 0:
        func_001BCE30();
        return v;
    case 1:
        D_00317319 = f;
        break;
    case 2:
        D_003172F0.f29 = f;
        D_003172F0.f28 = f;
        break;
    case 3:
        D_0031731A = f;
        break;
    case 4:
        D_00317321 = f;
        break;
    case 5:
        D_0031732C = f;
        break;
    case 6:
        D_00317328 = f;
        break;
    case 7:
        D_00317329 = f;
        break;
    case 8:
        D_0031732A = f;
        break;
    case 9:
        D_0031732B = f;
        break;
    case 10:
        func_001BCFD0();
        MsDebugFullGill();
        return v;
    case 11: {
        Unk1BFED8 *p = MsGetSaveWeapon(D_0031EAC9, 0);

        while (func_001C0598(p) != 0) {
        }
        return v;
    }
    case 12:
        D_00317318 = f;
        break;
    case 13:
        D_0031732D = f;
        break;
    case 14:
        D_0031732E = f;
        break;
    case 15:
        D_0031732F = f;
        break;
    case 16:
        D_00317330 = f;
        break;
    case 17:
        D_00317331 = f;
        break;
    case 18:
        D_00317332 = f;
        break;
    case 19:
        D_00317333 = f;
        break;
    case 20:
        D_00317334 = f;
        break;
    case 21:
        MsDebugFullCommand();
        return v;
    case 22:
        func_001BCC50();
        return v;
    case 23:
        D_00317342 = f;
        break;
    case 24:
        D_00317335 = f;
        break;
    case 25:
        D_00317343 = v;
        break;
    }
    return v;
}

int func_001EE438(Actor *a, void *op, ScriptCtx *ctx)
{
    int r;
    int v = AtelPopStackInteger(a, ctx);

    r = 0;
    switch (v) {
    case 0:
        break;
    case 1:
        r = D_00317319;
        break;
    case 2:
        if (D_003172F0.f29 != 0) {
            r = D_003172F0.f28 != 0;
        }
        break;
    case 3:
        r = D_0031731A;
        break;
    case 4:
        r = D_00317321;
        break;
    case 5:
        r = D_0031732C;
        break;
    case 6:
        r = D_00317328;
        break;
    case 7:
        r = D_00317329;
        break;
    case 8:
        r = D_0031732A;
        break;
    case 9:
        r = D_0031732B;
        break;
    case 12:
        r = D_00317318;
        break;
    case 13:
        r = D_0031732D;
        break;
    case 14:
        r = D_0031732E;
        break;
    case 15:
        r = D_0031732F;
        break;
    case 16:
        r = D_00317330;
        break;
    case 17:
        r = D_00317331;
        break;
    case 18:
        r = D_00317332;
        break;
    case 19:
        r = D_00317333;
        break;
    case 20:
        r = D_00317334;
        break;
    case 23:
        r = D_00317342;
        break;
    case 24:
        r = D_00317335;
        break;
    case 25:
        r = D_00317343;
        break;
    }
    return r;
}

int func_001EE590(Actor *a, void *op, ScriptCtx *ctx)
{
    int found = 0;
    int i;
    int id = *func_00144158(a);
    BtlChr *c = MsGetChr(func_001B8198(id, AtelPopStackInteger(a, ctx), 0, 1));
    Unk1BFED8 *q;

    for (i = 0; i < 2; i++) {
        q = MsGetSaveWeapon(c->item252[i], 0);
        if (q != 0 && (q->b3 >> 3 & 1)) {
            found = 1;
        }
    }
    return found;
}

int func_001EE650(void)
{
    return func_001E0C98();
}

float func_001EE670(Actor *a, void *op, ScriptCtx *ctx)
{
    int id = *func_00144158(a);
    int r = func_001B8198(id, AtelPopStackInteger(a, ctx), 0, 1);

    return r >= 0 ? MsGetChrCamWidth(r) : 0.0f;
}

float func_001EE6E8(Actor *a, void *op, ScriptCtx *ctx)
{
    int id = *func_00144158(a);
    int r = func_001B8198(id, AtelPopStackInteger(a, ctx), 0, 1);
    BtlChr *c;

    if (r >= 0) {
        c = MsGetChr(r);
        if (c->chr != 0) {
            return func_00110980(c->chr) * c->f64;
        }
    }
    return 0;
}

float func_001EE780(Actor *a, void *op, ScriptCtx *ctx)
{
    float v[4];
    int id = *func_00144158(a);

    MsGetChrInfo(11, MsGetChrBit(id, AtelPopStackInteger(a, ctx), 0, 1), 0, v);
    return v[0];
}

float func_001EE7F8(Actor *a, void *op, ScriptCtx *ctx)
{
    float v[4];
    int id = *func_00144158(a);

    MsGetChrInfo(10, MsGetChrBit(id, AtelPopStackInteger(a, ctx), 0, 1), 0, v);
    return v[0];
}

float func_001EE870(Actor *a, void *op, ScriptCtx *ctx)
{
    float pos[4];
    int id = *func_00144158(a);

    func_001B6790(func_001B8198(id, AtelPopStackInteger(a, ctx), 0, 1), pos);
    return pos[1];
}

INCLUDE_ASM("build/ee_asm/game/battle/battle_1EA000", func_001EE8E0);

INCLUDE_ASM("build/ee_asm/game/battle/battle_1EA000", func_001EE9E8);

float func_001EEAF0(Actor *a, void *op, ScriptCtx *ctx)
{
    float zero = 0;
    float v;
    float f;
    int id = *func_00144158(a);
    int r = func_001B8198(id, AtelPopStackInteger(a, ctx), 0, 1);

    f = func_001B6AD0(r, zero);
    func_001B6E48(r, &v);
    return MsNearRag(zero, f - v) * 180.0f / 3.14159274f;
}

float func_001EEBB8(Actor *a, void *op, ScriptCtx *ctx)
{
    float zero = 0;
    int id = *func_00144158(a);
    int r = func_001B8198(id, AtelPopStackInteger(a, ctx), 0, 1);

    return MsNearRag(zero, func_001B6AD0(r, zero)) * 180.0f / 3.14159274f;
}

float func_001EEC60(Actor *a, void *op, ScriptCtx *ctx)
{
    float v;
    int id = *func_00144158(a);
    int r = func_001B8198(id, AtelPopStackInteger(a, ctx), 0, 1);

    func_001B6E48(r, &v);
    v = MsNearRag(0, v) * 180.0f / 3.14159274f;
    return v;
}

int func_001EED00(Actor *a, void *op, ScriptCtx *ctx)
{
    return func_001E4CA8(AtelPopStackInteger(a, ctx));
}

int func_001EED28(Actor *a, void *op, ScriptCtx *ctx)
{
    return func_001E4C58(AtelPopStackInteger(a, ctx));
}

INCLUDE_ASM("build/ee_asm/game/battle/battle_1EA000", func_001EED50);

int func_001EED60(void)
{
    int i;
    u8 *p;

    for (i = 0; i < 4; i++) {
        p = func_001E4A30(i);
        if (*p) {
            return *p;
        }
    }
    return 0;
}

int func_001EEDA8(void)
{
    int i;
    u8 *p;

    for (i = 0; i < 4; i++) {
        p = func_001E4A30(i);
        if (p[0] != 0) {
            return p[1];
        }
    }
    return 0;
}

int func_001EEDF8(Actor *a, void *op, ScriptCtx *ctx)
{
    int v = AtelPopStackInteger(a, ctx);

    D_00319433 = v & 1;
}

s8 func_001EEE20(void)
{
    return D_00319435;
}

int func_001EEE30(Actor *a, void *op, ScriptCtx *ctx)
{
    int x = AtelPopStackInteger(a, ctx);
    int y = AtelPopStackInteger(a, ctx);
    int id = *func_00144158(a);

    if (func_001CF6F8(id, y, 7, x, 1) != 0) {
        MsGetChr(id)->fAD2++;
    }
    return 0;
}

int func_001EEEC8(Actor *a, void *op, ScriptCtx *ctx)
{
    int x = AtelPopStackInteger(a, ctx);
    int y = AtelPopStackInteger(a, ctx);

    return func_001CF6F8(*func_00144158(a), y, 1, x, 1);
}

int func_001EEF38(Actor *a, void *op, ScriptCtx *ctx)
{
    int n = AtelPopStackInteger(a, ctx);
    BtlChr *c;
    int v;

    AtelPopStackInteger(a, ctx);
    c = MsGetChr(*func_00144158(a));
    if (n > 0 && c->fAD5 != 0 && c->fB68 == 0) {
        v = op_et_weapon_afterimage(c->chr, 0, 0, 0, 0, 0, 0);
        if (v != 0) {
            c->fB68 = v;
        }
    }
    return 0;
}

int func_001EEFE0(Actor *ctx)
{
    MsResetAfterImage(MsGetChr(*func_00144158(ctx)));
    return 0;
}

int func_001EF010(Actor *a, void *op, ScriptCtx *ctx)
{
    int x = AtelPopStackInteger(a, ctx);
    int y = AtelPopStackInteger(a, ctx);

    return func_001CF458(*func_00144158(a), y, x, 1);
}

int func_001EF080(Actor *a, void *op, ScriptCtx *ctx)
{
    int v = AtelPopStackInteger(a, ctx);

    func_001CF0C0(*func_00144158(a), v);
    return 0;
}

int func_001EF0D0(Actor *a, void *unused, ScriptCtx *ctx)
{
    int x = AtelPopStackInteger(a, ctx);
    int y = AtelPopStackInteger(a, ctx);
    int i = AtelPopStackInteger(a, ctx);

    i = func_001B8198(*func_00144158(a), i, 0, 1);
    if (func_001CF6F8(i, y, 7, x, 1) != 0) {
        MsGetChr(i)->fAD2++;
    }
    return 0;
}

int func_001EF190(Actor *a, void *op, ScriptCtx *ctx)
{
    int x = AtelPopStackInteger(a, ctx);
    int y = AtelPopStackInteger(a, ctx);
    int z = AtelPopStackInteger(a, ctx);

    func_001CF4B0(func_001B8198(*func_00144158(a), z, 0, 1), y, x);
    return 0;
}

int func_001EF228(Actor *a, void *op, ScriptCtx *ctx)
{
    int x = AtelPopStackInteger(a, ctx);
    int y = AtelPopStackInteger(a, ctx);
    int z = AtelPopStackInteger(a, ctx);

    func_001CF558(func_001B8198(*func_00144158(a), z, 0, 1), y, x);
    return 0;
}

int func_001EF2C0(Actor *a, void *op, ScriptCtx *ctx)
{
    int x = AtelPopStackInteger(a, ctx);
    int y = AtelPopStackInteger(a, ctx);
    int z = AtelPopStackInteger(a, ctx);

    return func_001CF458(func_001B8198(*func_00144158(a), z, 0, 1), y, x, 1);
}

int func_001EF358(Actor *a, void *op, ScriptCtx *ctx)
{
    int id;

    AtelPopStackInteger(a, ctx);
    AtelPopStackInteger(a, ctx);
    id = *func_00144158(a);
    MsGetChr(id)->f36 = 1;
    return id;
}

int func_001EF3B8(Actor *a)
{
    MsResetBindEffect(*func_00144158(a));
    return 0;
}

int func_001EF3E0(Actor *a)
{
    int id = *func_00144158(a);

    return id == 255 ? 0 : MsCheckStartEffect(id, MsGetChr(id)->fA80);
}

int func_001EF430(Actor *a, void *op, ScriptCtx *ctx)
{
    int v = AtelPopStackInteger(a, ctx);
    int id = *func_00144158(a);

    return id == 255 ? 0 : func_001CFA38(id, v);
}

int func_001EF490(Actor *a)
{
    func_00144158(a);
    return 0;
}

int func_001EF4B0(Actor *ctx)
{
    int r = 5;

    if (MsGetChr(*func_00144158(ctx))->fAD2 != 0) {
        r = 0;
    }
    return r;
}
