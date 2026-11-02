/* tu_093 0x152420-0x1530d8: low; ~Ch (config/tu_map.tsv) */
#include "common.h"
#include "ffx/q2.h"
#include "ffx/w2.h"
#include "ffx/r1.h"
#include "ffx/s1.h"
#include "ffx/u1.h"

int func_00152420(Actor *a, void *op, ScriptCtx *ctx)
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
    func_00105750_I(r4, r1);
    return 0;
}

int func_00152490(Actor *a, void *op, ScriptCtx *ctx)
{
    Chr *chr;

    chr = AtelGetCharHandle(a);
    if (chr == 0) {
        return 0;
    }
    return func_00111B50(chr);
}

int func_001524C8(Actor *a, void *op, ScriptCtx *ctx)
{
    Chr *c = AtelGetCharHandle(a);
    float z = AtelPopStackFloat(a, ctx);
    float y = AtelPopStackFloat(a, ctx);
    float x = AtelPopStackFloat(a, ctx);
    int v = AtelPopStackInteger(a, ctx);
    int id = AtelPopStackInteger(a, ctx);

    if (c == 0) {
        return 0;
    }
    if (id != -1) {
        func_00107250(c, AtelGetCharHandle(AtelGetBasicWork(id)), v, x, y, z);
    } else {
        func_00107250(c, 0, 0, x, y, z);
    }
    return 0;
}

int func_001525D8(Actor *a, void *op, ScriptCtx *ctx)
{
    int v1;
    Chr *chr;

    v1 = AtelPopStackInteger(a, ctx);
    chr = AtelGetCharHandle(AtelGetBasicWork(AtelPopStackInteger(a, ctx)));
    if (chr == 0) {
        return 0;
    }
    return func_00108750(chr, v1);
}

int func_00152650(Actor *a, void *op, ScriptCtx *ctx)
{
    int v1;
    int v2;
    Chr *chr;

    v1 = AtelPopStackInteger(a, ctx);
    v2 = AtelPopStackInteger(a, ctx);
    chr = AtelGetCharHandle(a);
    if (chr == 0) {
        return 0;
    }
    return graphicCharacterInstanceSetMeshSegmentAlpha(chr, v2, v1);
}

int func_001526C8(Actor *a, void *op, ScriptCtx *ctx)
{
    int v1;
    Chr *chr;

    v1 = AtelPopStackInteger(a, ctx);
    chr = AtelGetCharHandle(a);
    if (chr == 0) {
        return 0;
    }
    return Ch_ModelGetHide(chr, v1);
}

int func_00152720(Actor *a, void *op, ScriptCtx *ctx)
{
    Chr *chr;
    int v1;

    chr = AtelGetCharHandle(a);
    v1 = AtelPopStackInteger(a, ctx);
    if (chr == 0) {
        return 0;
    }
    return Ch_SetCalcNorm(chr, v1);
}

int func_00152780(Actor *a, void *op, ScriptCtx *ctx)
{
    int v1;
    Chr *chr;

    v1 = AtelPopStackInteger(a, ctx);
    chr = AtelGetCharHandle(AtelGetBasicWork(AtelPopStackInteger(a, ctx)));
    if (chr == 0) {
        return 0;
    }
    return Ch_SetCalcNorm(chr, v1);
}

int func_001527F8(Actor *a, void *op, ScriptCtx *ctx)
{
    func_00107C40(AtelPopStackInteger(a, ctx));
    return 0;
}

int func_00152820(Actor *a, void *op, ScriptCtx *ctx)
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
    Ch_SetSysMotion(chr, v2, v1);
    return 0;
}

int func_00152898(Actor *a, void *op, ScriptCtx *ctx)
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
    return Ch_TextureSetImageBase(chr, v2, v1);
}

int func_00152918(Actor *a, void *op, ScriptCtx *ctx)
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
    return Ch_TextureSetClutBase(chr, v2, v1);
}

int func_00152998(Actor *a, void *op, ScriptCtx *ctx)
{
    Chr *chr;
    int v1;

    chr = AtelGetCharHandle(a);
    v1 = AtelPopStackInteger(a, ctx);
    if (chr == 0) {
        return 0;
    }
    Ch_MotionSetNextHokan(chr, v1);
    return 0;
}

int func_001529F8(Actor *a, void *op, ScriptCtx *ctx)
{
    Chr *chr;

    chr = AtelGetCharHandle(a);
    if (chr == 0) {
        return 0;
    }
    return func_00105E48(chr);
}

float func_00152A30(Actor *a, void *op, ScriptCtx *ctx)
{
    Chr *chr;

    chr = AtelGetCharHandle(a);
    if (chr == 0) {
        return 0.0f;
    }
    return func_00110280(chr);
}

int func_00152A68(Actor *a, void *op, ScriptCtx *ctx)
{
    Chr *r1;
    int r2;

    r1 = AtelGetCharHandle(a);
    r2 = AtelPopStackInteger(a, ctx);
    if (r1 == 0) {
        return 0;
    }
    func_001127E0_I(r1, r2);
    return 0;
}

int func_00152AC8(Actor *a, void *op, ScriptCtx *ctx)
{
    Chr *chr;
    int v1;

    chr = AtelGetCharHandle(a);
    v1 = AtelPopStackInteger(a, ctx);
    if (chr == 0) {
        return 0;
    }
    Ch_IdEnableShade(chr, v1);
    return 0;
}

int func_00152B28(Actor *a, void *op, ScriptCtx *ctx)
{
    int v1;

    v1 = AtelPopStackInteger(a, ctx);
    ChN_ReadSystemMGRPstart(AtelPopStackInteger(a, ctx), v1);
    return 0;
}

void func_00152B88(Actor *a, int *p, ScriptCtx *ctx)
{
    p[3] = 0;
    p[2] = AtelPopStackInteger(a, ctx);
    p[1] = AtelPopStackInteger(a, ctx);
    p[0] = AtelPopStackInteger(a, ctx);
}

int func_00152BF0(int a, int *p)
{
    if (p[2]) {
        p[3] = ChN_ReadSystemMGRPsync(p[0], p[1]);
    } else if (ChN_ReadSystemMGRPsync(p[0], p[1]) != 0) {
        return 0;
    }
    return 5;
}

s32 func_00152C48(int a, s32 *b)
{
    return b[3];
}

int func_00152C50(Actor *a, int *p, ScriptCtx *ctx)
{
    p[3] = 0;
    p[2] = 0;
    p[1] = AtelPopStackInteger(a, ctx);
    return p[0] = AtelPopStackInteger(a, ctx);
}

int func_00152CB0(int a, int *p)
{
    if (p[2]) {
        p[3] = ChN_ReadSystemMGRPsync(p[0], p[1]);
        return 5;
    }
    return ChN_ReadSystemMGRPsync(p[0], p[1]) == 0;
}

s32 func_00152D00(int a, s32 *b)
{
    return b[3];
}

int func_00152D08(int *p)
{
    if (p[2]) {
        p[3] = Ch_DataReadSync(p[0]);
        return 5;
    }
    return Ch_DataReadSync(p[0]) == 0;
}

int func_00152D58(Actor *a, int *p, ScriptCtx *ctx)
{
    p[3] = 0;
    p[2] = AtelPopStackInteger(a, ctx);
    return p[0] = AtelPopStackInteger(a, ctx);
}

int func_00152DB0(int a, int *p)
{
    return func_00152D08(p);
}

s32 func_00152DD0(int a, s32 *b)
{
    return b[3];
}

int func_00152DD8(Actor *a, int *p, ScriptCtx *ctx)
{
    p[3] = 0;
    p[2] = 0;
    return p[0] = AtelPopStackInteger(a, ctx);
}

int func_00152E10(int a, int *p)
{
    return func_00152D08(p);
}

s32 func_00152E30(int a, s32 *b)
{
    return b[3];
}

int func_00152E38(Actor *a, void *op, ScriptCtx *ctx)
{
    func_00104F50(AtelPopStackInteger(a, ctx));
    return 0;
}

int func_00152E60(Actor *a, int *p, ScriptCtx *ctx)
{
    p[3] = 0;
    return p[0] = AtelPopStackInteger(a, ctx);
}

int func_00152E90(Actor *a, int *p, ScriptCtx *ctx)
{
    return func_00104F88(p[0]) == 0;
}

s32 func_00152EB8(int a, s32 *b)
{
    return b[3];
}

int func_00152EC0(Actor *a, void *op, ScriptCtx *ctx)
{
    Chr *chr;
    int v1;

    chr = AtelGetCharHandle(a);
    v1 = AtelPopStackInteger(a, ctx);
    if (chr == 0) {
        return 0;
    }
    Ch_DrawSetCull(chr, v1);
    return 0;
}

int func_00152F20(void)
{
    return func_00113480(1) == 0;
}

int func_00152F40(Actor *a, void *op, ScriptCtx *ctx)
{
    Chr *chr;
    int v1;

    chr = AtelGetCharHandle(a);
    v1 = AtelPopStackInteger(a, ctx);
    if (chr == 0) {
        return 0;
    }
    return func_00112F10(chr, v1);
}

int func_00152FA0(Actor *a, void *op, ScriptCtx *ctx)
{
    Chr *r1;
    int r2;

    r1 = AtelGetCharHandle(a);
    r2 = AtelPopStackInteger(a, ctx);
    if (r1 == 0) {
        return 0;
    }
    func_0010DC38_I(r1, r2);
    return 0;
}

int func_00153000(Actor *a, void *op, ScriptCtx *ctx)
{
    Chr *chr;

    chr = AtelGetCharHandle(a);
    if (chr == 0) {
        return 0;
    }
    return func_0010DC40(chr);
}

int func_00153038(Actor *a, void *op, ScriptCtx *ctx)
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
    func_0010DC48(chr, v2, v1);
    return 0;
}

int func_001530B0(Actor *a, void *op, ScriptCtx *ctx)
{
    return Ch_DataRead(AtelPopStackInteger(a, ctx));
}
