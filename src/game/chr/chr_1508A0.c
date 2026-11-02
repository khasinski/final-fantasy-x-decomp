/* tu_090 0x1508a0-0x150d70: low; unk_1508A0 (config/tu_map.tsv) */
#include "common.h"
#include "ffx/q2.h"
#include "ffx/w2.h"
#include "ffx/r1.h"
#include "ffx/s1.h"
#include "ffx/u1.h"

int func_001508A0(void)
{
    Chr *c = AtelGetCharHandle();

    if (c == 0) {
        return 0;
    }
    return c->b742 != 0;
}

int func_001508D0(void)
{
    Chr *c = AtelGetCharHandle();

    if (!c) {
        return 0;
    }
    Ch_ResetMotion(c);
    return 0;
}

int func_00150900(Actor *a, void *op, ScriptCtx *ctx)
{
    Chr *r1;
    float r2;
    float r3;
    float r4;
    int r5;

    r1 = AtelGetCharHandle(a);
    r2 = AtelPopStackFloat(a, ctx);
    r3 = AtelPopStackFloat(a, ctx);
    r4 = AtelPopStackFloat(a, ctx);
    r5 = AtelPopStackInteger(a, ctx);
    if (r1 == 0) {
        return 0;
    }
    Ch_SetScale(r1, r5, r4, r3, r2);
    return 0;
}

int func_001509B0(Actor *a, void *op, ScriptCtx *ctx)
{
    Chr *r1;
    float r2;

    r1 = AtelGetCharHandle(a);
    r2 = AtelPopStackFloat(a, ctx);
    if (r1 == 0) {
        return 0;
    }
    func_00110770(r1, r2);
    return 0;
}

int func_00150A10(Actor *a, void *op, ScriptCtx *ctx)
{
    Chr *chr;
    int v1;

    chr = AtelGetCharHandle(a);
    v1 = AtelPopStackInteger(a, ctx);
    if (chr == 0) {
        return 0;
    }
    graphicLevelGetNameHash(chr, v1);
    return 0;
}

float func_00150A70(Actor *a, void *op, ScriptCtx *ctx)
{
    Chr *c = AtelGetCharHandle(a);
    float v = AtelPopStackFloat(a, ctx);

    if (c == 0) {
        return 0.0f;
    }
    return Ch_SetWeight(c, v);
}

int func_00150AD8(Actor *a, void *op, ScriptCtx *ctx)
{
    Chr *r1;
    float r2;

    r1 = AtelGetCharHandle(a);
    r2 = AtelPopStackFloat(a, ctx);
    if (r1 == 0) {
        return 0;
    }
    func_00110568(r1, r2);
    return 0;
}

int func_00150B38(Actor *a, void *op, ScriptCtx *ctx)
{
    Chr *c = AtelGetCharHandle(a);
    float v = AtelPopStackFloat(a, ctx);

    if (c == 0) {
        return 0;
    }
    ((void (*)(Chr *, double))func_00110848)(c, func_002ED038(v)); /* DEBT(CAST): called unprototyped in the original (float promoted to double) */
    return 0;
}

int func_00150BA0(Actor *a, void *op, ScriptCtx *ctx)
{
    Chr *chr;
    int v1;

    chr = AtelGetCharHandle(a);
    v1 = AtelPopStackInteger(a, ctx);
    if (chr == 0) {
        return 0;
    }
    func_00110678(chr, v1);
    return 0;
}

int func_00150C00(Actor *a, void *op, ScriptCtx *ctx)
{
    Chr *c = AtelGetCharHandle(a);

    AtelPopStackInteger(a, ctx);
    if (c == 0) {
        return 0;
    }
    return 0;
}

int func_00150C50(Actor *a, void *op, ScriptCtx *ctx)
{
    Chr *chr;
    int v1;

    chr = AtelGetCharHandle(a);
    v1 = AtelPopStackInteger(a, ctx);
    if (chr == 0) {
        return 0;
    }
    func_00110698(chr, v1);
    return 0;
}

int func_00150CB0(Actor *a, void *op, ScriptCtx *ctx)
{
    Chr *chr;
    int v1;

    chr = AtelGetCharHandle(a);
    v1 = AtelPopStackInteger(a, ctx);
    if (chr == 0) {
        return 0;
    }
    graphicLevelGetNameHash(chr, v1);
    return 0;
}

int func_00150D10(Actor *a, void *op, ScriptCtx *ctx)
{
    Chr *c = AtelGetCharHandle(a);
    int v = AtelPopStackInteger(a, ctx);

    if (c == 0) {
        return 0;
    }
    ChN_DisposeSystemMGRP(*(u16 *)c, v); /* DEBT(CAST): first member of Chr read as u16 */
    return 0;
}
