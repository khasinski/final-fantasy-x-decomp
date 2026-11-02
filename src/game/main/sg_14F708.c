/* tu_087 0x14f708-0x150200: medium; ~Sg (config/tu_map.tsv) */
#include "common.h"
#include "ffx/q2.h"
#include "ffx/w2.h"
#include "ffx/r1.h"
#include "ffx/s1.h"
#include "ffx/u1.h"

int func_0014F708(Actor *a, void *op, ScriptCtx *ctx)
{
    func_0011A9E0(AtelPopStackInteger(a, ctx));
    return 0;
}

int func_0014F730(Actor *a, void *op, ScriptCtx *ctx)
{
    func_0011AA08(AtelPopStackInteger(a, ctx));
    return 0;
}

int func_0014F758(Actor *a, void *op, ScriptCtx *ctx)
{
    AtelPopStackFloat(a, ctx);
    AtelPopStackFloat(a, ctx);
    AtelPopStackInteger(a, ctx);
    return 0;
}

int func_0014F7A8(Actor *a, void *op, ScriptCtx *ctx)
{
    float r1;
    float r2;
    float r3;
    int r4;

    r1 = AtelPopStackFloat(a, ctx);
    r2 = AtelPopStackFloat(a, ctx);
    r3 = AtelPopStackFloat(a, ctx);
    r4 = AtelPopStackInteger(a, ctx);
    func_001067B0(r4, r3, r2, r1);
    return 0;
}

int func_0014F840(Actor *a, void *op, ScriptCtx *ctx)
{
    float r1;
    float r2;
    float r3;
    int r4;

    r1 = AtelPopStackFloat(a, ctx);
    r2 = AtelPopStackFloat(a, ctx);
    r3 = AtelPopStackFloat(a, ctx);
    r4 = AtelPopStackInteger(a, ctx);
    func_00106780(r4, r3, r2, r1);
    return 0;
}

int func_0014F8D8(Actor *a, void *op, ScriptCtx *ctx)
{
    int v1;
    int v2;
    int v3;
    int v4;
    int v5;

    v1 = AtelPopStackInteger(a, ctx);
    v2 = AtelPopStackInteger(a, ctx);
    v3 = AtelPopStackInteger(a, ctx);
    v4 = AtelPopStackInteger(a, ctx);
    v5 = AtelPopStackInteger(a, ctx);
    func_00106A08(AtelPopStackInteger(a, ctx), v5, v4, v3, v2, v1);
    return 0;
}

int func_0014F9A8(Actor *a, void *op, ScriptCtx *ctx)
{
    return Sg_EnFocus(AtelPopStackInteger(a, ctx));
}

int func_0014F9D0(Actor *a, void *op, ScriptCtx *ctx)
{
    int v1;

    v1 = AtelPopStackInteger(a, ctx);
    return Sg_SetFocus(AtelPopStackInteger(a, ctx), v1);
}

int func_0014FA28(Actor *a, void *op, ScriptCtx *ctx)
{
    float v1;

    v1 = AtelPopStackFloat(a, ctx);
    func_00116280(AtelPopStackInteger(a, ctx), v1);
    return 0;
}

int func_0014FA88(Actor *a, void *op, ScriptCtx *ctx)
{
    int v1;

    v1 = AtelPopStackInteger(a, ctx);
    func_00121B88(AtelPopStackInteger(a, ctx), v1);
    return 0;
}

int func_0014FAE8(Actor *a, void *op, ScriptCtx *ctx)
{
    return func_00121BA8(AtelPopStackInteger(a, ctx));
}

int func_0014FB10(Actor *a, void *op, ScriptCtx *ctx)
{
    func_00118A40(AtelPopStackInteger(a, ctx));
    return 0;
}

int func_0014FB38(Actor *a, void *op, ScriptCtx *ctx)
{
    int v1;

    v1 = AtelPopStackInteger(a, ctx);
    Sg_AccSetAlpha(AtelPopStackInteger(a, ctx), v1);
    return 0;
}

int func_0014FB98(Actor *a, void *op, ScriptCtx *ctx)
{
    func_00118A50(AtelPopStackInteger(a, ctx));
    return 0;
}

int func_0014FBC0(Actor *a, void *op, ScriptCtx *ctx)
{
    func_00118A60(AtelPopStackInteger(a, ctx));
    return 0;
}

int func_0014FBE8(Actor *a, void *op, ScriptCtx *ctx)
{
    SaveDataIsScreenClosed(AtelPopStackInteger(a, ctx));
    D_0058F9D0 = 1;
    return 1;
}

int func_0014FC18(void)
{
    return --D_0058F9D0 == -1;
}

int func_0014FC38(void) {
    return Sg_MenuGetResult();
}

int func_0014FC58(Actor *a, void *op, ScriptCtx *ctx)
{
    return Sg_Test(AtelPopStackInteger(a, ctx));
}

int func_0014FC80(void) {
    func_00111AC0();
    return 0;
}

int func_0014FCA0(void) {
    func_00111AC8();
    return 0;
}

int func_0014FCC0(Actor *a, void *op, ScriptCtx *ctx)
{
    return Sg_CacheDisposeChr(AtelPopStackInteger(a, ctx));
}

int func_0014FCE8(Actor *a, void *op, ScriptCtx *ctx)
{
    return Sg_SetKeepFps(AtelPopStackInteger(a, ctx));
}

int func_0014FD10(Actor *a, void *op, ScriptCtx *ctx)
{
    Sg_PLightAllocate(AtelPopStackInteger(a, ctx));
    return 0;
}

int func_0014FD38(void) {
    func_0010D720();
    return 0;
}

int func_0014FD58(Actor *a, void *op, ScriptCtx *ctx)
{
    int v1;
    int v2;
    int v3;
    int v4;
    float f1;
    float f2;
    float f3;
    float f4;

    v1 = AtelPopStackInteger(a, ctx);
    v2 = AtelPopStackInteger(a, ctx);
    v3 = AtelPopStackInteger(a, ctx);
    v4 = AtelPopStackInteger(a, ctx);
    f1 = AtelPopStackFloat(a, ctx);
    f2 = AtelPopStackFloat(a, ctx);
    f3 = AtelPopStackFloat(a, ctx);
    f4 = AtelPopStackFloat(a, ctx);
    Sg_PLightDefine(f4, f3, f2, f1, AtelPopStackInteger(a, ctx), v4, v3, v2, v1);
    return 0;
}

int func_0014FE78(Actor *a, void *op, ScriptCtx *ctx)
{
    float r1;
    float r2;
    float r3;
    int r4;
    int r5;

    r1 = AtelPopStackFloat(a, ctx);
    r2 = AtelPopStackFloat(a, ctx);
    r3 = AtelPopStackFloat(a, ctx);
    r4 = AtelPopStackInteger(a, ctx);
    r5 = AtelPopStackInteger(a, ctx);
    func_0010D7C8(r5, r4, r3, r2, r1);
    return 0;
}

int func_0014FF28(Actor *a, void *op, ScriptCtx *ctx)
{
    int v1;
    int v2;
    int v3;

    v1 = AtelPopStackInteger(a, ctx);
    v2 = AtelPopStackInteger(a, ctx);
    v3 = AtelPopStackInteger(a, ctx);
    Sg_PLightGetPos(AtelPopStackInteger(a, ctx), v3, v2, v1);
    return 0;
}

int func_0014FFC0(Actor *a, void *op, ScriptCtx *ctx)
{
    int v1;
    int v2;
    int v3;

    v1 = AtelPopStackInteger(a, ctx);
    v2 = AtelPopStackInteger(a, ctx);
    v3 = AtelPopStackInteger(a, ctx);
    func_0010D818(AtelPopStackInteger(a, ctx), v3, v2, v1);
    return 0;
}

int func_00150058(Actor *a, void *op, ScriptCtx *ctx)
{
    int v1;
    int v2;
    int v3;

    v1 = AtelPopStackInteger(a, ctx);
    v2 = AtelPopStackInteger(a, ctx);
    v3 = AtelPopStackInteger(a, ctx);
    Sg_PLightGetColor(AtelPopStackInteger(a, ctx), v3, v2, v1);
    return 0;
}

int func_001500F0(Actor *a, void *op, ScriptCtx *ctx)
{
    int v1;

    v1 = AtelPopStackInteger(a, ctx);
    Sg_PLightSetEnable(AtelPopStackInteger(a, ctx), v1);
    return 0;
}

int func_00150150(Actor *a, void *op, ScriptCtx *ctx)
{
    return func_0010D9C0(AtelPopStackInteger(a, ctx));
}

int func_00150178(Actor *a, void *op, ScriptCtx *ctx)
{
    float r1;
    int r2;

    r1 = AtelPopStackFloat(a, ctx);
    r2 = AtelPopStackInteger(a, ctx);
    func_0010D9F8(r2, r1);
    return 0;
}

float func_001501D8(Actor *a, void *op, ScriptCtx *ctx)
{
    return Sg_PLightGetRadius(AtelPopStackInteger(a, ctx));
}
