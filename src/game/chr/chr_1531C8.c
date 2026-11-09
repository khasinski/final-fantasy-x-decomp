/* tu_095 0x1531c8-0x153ea0: low; unk_1531C8 (config/tu_map.tsv) */
#include "common.h"
#include "ffx/q2.h"
#include "ffx/w2.h"
#include "ffx/r1.h"
#include "ffx/s1.h"
#include "ffx/u1.h"

int func_001531C8(Actor *a, void *op, ScriptCtx *ctx)
{
    Chr *c = AtelGetCharHandle(a);
    float v = AtelPopStackFloat(a, ctx);
    float deg = AtelPopStackFloat(a, ctx);
    float rad;

    if (c == 0) {
        return 0;
    }
    rad = deg * 3.141592f / 180.0f;
    while (rad > 3.141592f) {
        rad -= 6.283184f;
    }
    while (rad < -3.141592f) {
        rad += 6.283184f;
    }
    func_00108178(c, rad, v);
    return 0;
}

int func_001532E0(Actor *a, void *op, ScriptCtx *ctx)
{
    Chr *r1;
    float r2;

    r1 = AtelGetCharHandle(a);
    r2 = AtelPopStackFloat(a, ctx);
    if (r1 == 0) {
        return 0;
    }
    Ch_BindSetScale(r1, r2);
    return 0;
}

int func_00153340(Actor *a, void *op, ScriptCtx *ctx)
{
    Chr *r1;
    int r2;

    r1 = AtelGetCharHandle(a);
    if (r1 == 0) {
        return 0;
    }
    r2 = AtelPopStackInteger(a, ctx);
    Ch_SetHideCalc_I(r1, r2);
    return 0;
}

int func_001533A0(Actor *a, void *op, ScriptCtx *ctx)
{
    Chr *chr;

    chr = AtelGetCharHandle(a);
    if (chr == 0) {
        return 0;
    }
    return func_00110B08(chr);
}

int func_001533D8(Actor *a, void *op, ScriptCtx *ctx)
{
    Chr *chr;
    int v1;

    chr = AtelGetCharHandle(a);
    v1 = AtelPopStackInteger(a, ctx);
    if (chr == 0) {
        return 0;
    }
    Ch_TextureLoadImage(chr, v1);
    return 0;
}

int func_00153438(Actor *a, void *op, ScriptCtx *ctx)
{
    Chr *chr;

    chr = AtelGetCharHandle(a);
    if (chr == 0) {
        return 0;
    }
    return func_00110B58(chr);
}

int func_00153470(Actor *a, void *op, ScriptCtx *ctx)
{
    Chr *chr;

    chr = AtelGetCharHandle(a);
    if (chr == 0) {
        return 0;
    }
    Ch_SetOverlapHit(chr, AtelPopStackInteger(a, ctx));
    return 0;
}

int func_001534D0(Actor *a, void *op, ScriptCtx *ctx)
{
    Chr *chr;

    chr = AtelGetCharHandle(a);
    if (chr == 0) {
        return 0;
    }
    return func_00110B88(chr);
}

int func_00153508(Actor *a, void *op, ScriptCtx *ctx)
{
    Chr *chr;

    chr = AtelGetCharHandle(AtelGetBasicWork(AtelPopStackInteger(a, ctx)));
    if (chr == 0) {
        return 0;
    }
    return func_00111B50(chr);
}

int func_00153550(Actor *a, void *op, ScriptCtx *ctx)
{
    Chr *r1;
    int r2;

    r1 = AtelGetCharHandle(a);
    if (r1 == 0) {
        return 0;
    }
    r2 = AtelPopStackInteger(a, ctx);
    func_00109B88_I(r1, r2);
    return 0;
}

int func_001535B0(Actor *a, void *op, ScriptCtx *ctx)
{
    Chr *chr;

    chr = AtelGetCharHandle(a);
    if (chr == 0) {
        return 0;
    }
    return func_00109B90(chr);
}

int func_001535E8(Actor *a, void *op, ScriptCtx *ctx)
{
    Chr *chr;
    int v1;
    int v2;

    chr = AtelGetCharHandle(a);
    v1 = AtelPopStackInteger(a, ctx);
    v2 = AtelPopStackInteger(a, ctx);
    if (chr == 0) {
        return 0;
    }
    func_00117D38(chr, v2, v1);
    return 0;
}

int func_00153660(Actor *a, void *op, ScriptCtx *ctx)
{
    Chr *chr;
    int v1;

    chr = AtelGetCharHandle(a);
    v1 = AtelPopStackInteger(a, ctx);
    if (chr == 0) {
        return 0;
    }
    Ch_NeckSetEnable(chr, v1);
    return 0;
}

int func_001536C0(Actor *a, void *op, ScriptCtx *ctx)
{
    Chr *chr;
    Chr *chr2;

    chr = AtelGetCharHandle(a);
    chr2 = AtelGetCharHandle(AtelGetBasicWork(AtelPopStackInteger(a, ctx)));
    if (chr == 0) {
        return 0;
    }
    Ch_NeckSetTarget(chr, chr2);
    return 0;
}

int func_00153730(Actor *a, void *op, ScriptCtx *ctx)
{
    Chr *c = AtelGetCharHandle(a);
    float v[3];

    v[2] = AtelPopStackFloat(a, ctx);
    v[1] = AtelPopStackFloat(a, ctx);
    v[0] = AtelPopStackFloat(a, ctx);
    if (c == 0) {
        return 0;
    }
    func_0010A1F8(c, v);
    return 0;
}

int func_001537B0(void)
{
    Chr *c = AtelGetCharHandle();

    if (!c) {
        return 0;
    }
    func_0010A220(c);
    return 0;
}

int func_001537E0(Actor *a, void *op, ScriptCtx *ctx)
{
    Chr *c = AtelGetCharHandle(a);
    float deg2 = AtelPopStackFloat(a, ctx);
    float deg1 = AtelPopStackFloat(a, ctx);
    float r1;
    float r2;

    if (c == 0) {
        return 0;
    }
    r1 = deg1 * 3.141592f / 180.0f;
    while (r1 > 3.141592f) {
        r1 -= 6.283184f;
    }
    while (r1 < -3.141592f) {
        r1 += 6.283184f;
    }
    r2 = deg2 * 3.141592f / 180.0f;
    while (r2 > 3.141592f) {
        r2 -= 6.283184f;
    }
    while (r2 < -3.141592f) {
        r2 += 6.283184f;
    }
    func_0010A230(c, r1, r2);
    return 0;
}

int func_00153988(Actor *a, void *op, ScriptCtx *ctx)
{
    int r1;
    int r2;
    Actor *r3;
    Chr *r4;

    r1 = AtelPopStackInteger(a, ctx);
    r2 = AtelPopStackInteger(a, ctx);
    r3 = AtelGetBasicWork(r2);
    r4 = AtelGetCharHandle(r3);
    if (r4 == 0) {
        return 0;
    }
    func_00109B88_I(r4, r1);
    return 0;
}

int func_001539F8(Actor *a, void *op, ScriptCtx *ctx)
{
    float r1;
    int r2;
    Chr *r3;

    r1 = AtelPopStackFloat(a, ctx);
    r2 = AtelPopStackInteger(a, ctx);
    r3 = AtelGetCharHandle(a);
    if (r3 == 0) {
        return 0;
    }
    func_00110C30(r3, r2, r1);
    return 0;
}

int func_00153A68(Actor *a, void *op, ScriptCtx *ctx)
{
    float r1;
    Chr *r2;

    r1 = AtelPopStackFloat(a, ctx);
    r2 = AtelGetCharHandle(a);
    if (r2 == 0) {
        return 0;
    }
    func_00110C48(r2, r1);
    return 0;
}

int func_00153AB8(Actor *a, void *op, ScriptCtx *ctx)
{
    Chr *chr;

    chr = AtelGetCharHandle(a);
    if (chr == 0) {
        return 0;
    }
    func_00110C50(chr, AtelPopStackInteger(a, ctx));
    return 0;
}

int func_00153B18(Actor *a, void *op, ScriptCtx *ctx)
{
    Chr *chr;

    chr = AtelGetCharHandle(a);
    if (chr == 0) {
        return 0;
    }
    Ch_ClothSetEnable(chr, AtelPopStackInteger(a, ctx));
    return 0;
}

int func_00153B78(Actor *a, void *op, ScriptCtx *ctx)
{
    Chr *chr;

    chr = AtelGetCharHandle(a);
    if (chr == 0) {
        return 0;
    }
    Ch_Vu1SetClipmode(chr, AtelPopStackInteger(a, ctx));
    return 0;
}

int func_00153BD8(Actor *a, void *op, ScriptCtx *ctx)
{
    float r1;
    Chr *r2;

    r1 = AtelPopStackFloat(a, ctx);
    r2 = AtelGetCharHandle(a);
    if (r2 == 0) {
        return 0;
    }
    func_0010A250(r2, r1);
    return 0;
}

int func_00153C28(Actor *a, void *op, ScriptCtx *ctx)
{
    float r1;
    Chr *r2;

    r1 = AtelPopStackFloat(a, ctx);
    r2 = AtelGetCharHandle(a);
    if (r2 == 0) {
        return 0;
    }
    func_0010AF88(r2, r1);
    return 0;
}

int func_00153C78(void)
{
    Chr *c = AtelGetCharHandle();

    if (!c) {
        return 0;
    }
    func_00107B98(c);
    return 0;
}

int func_00153CA8(void) {
    Ch_AllReserveCalcNorm();
    return 0;
}

int func_00153CC8(Actor *a, void *op, ScriptCtx *ctx)
{
    Chr *c = AtelGetCharHandle(a);
    int n = AtelPopStackInteger(a, ctx);
    float v = AtelPopStackFloat(a, ctx);

    if (c == 0) {
        return 0;
    }
    func_00110478(c, v, n);
    return 0;
}

int func_00153D40(Actor *a, void *b, ScriptCtx *c)
{
    func_00151F68(a, c, 2, 0);
    return 0;
}

int func_00153D68(Actor *a, void *b, ScriptCtx *c)
{
    func_00151F68(a, c, 2, 1);
    return 0;
}

int func_00153D90(Actor *a, void *b, ScriptCtx *c)
{
    func_00151F68(a, c, 2, 0);
    return 0;
}

int func_00153DB8(Actor *a, void *b, ScriptCtx *c)
{
    func_00151F68(a, c, 2, 1);
    return 0;
}

int func_00153DE0(Actor *a, void *op, ScriptCtx *ctx)
{
    Chr *chr;
    int v1;

    chr = AtelGetCharHandle(a);
    v1 = AtelPopStackInteger(a, ctx);
    if (chr == 0) {
        return 0;
    }
    func_00117D58(chr, v1);
    return 0;
}

int func_00153E40(Actor *a, void *op, ScriptCtx *ctx)
{
    Chr *chr;
    int v1;

    chr = AtelGetCharHandle(a);
    v1 = AtelPopStackInteger(a, ctx);
    if (chr == 0) {
        return 0;
    }
    Ch_ClothEnableGrav(chr, v1);
    return 0;
}
