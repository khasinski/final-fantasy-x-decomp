/* tu_138 0x18d0f8-0x18d7f8: medium; unk_18D0F8 (config/tu_map.tsv) */
#include "common.h"
#include "ffx/r2.h"
#include "ffx/s2.h"
#include "ffx/v2.h"
#include "ffx/t2.h"

INCLUDE_ASM("build/ee_asm/game/yi/yi_18D0F8", func_0018D0F8);

INCLUDE_ASM("build/ee_asm/game/yi/yi_18D0F8", func_0018D158);

INCLUDE_ASM("build/ee_asm/game/yi/yi_18D0F8", func_0018D1A8);

INCLUDE_ASM("build/ee_asm/game/yi/yi_18D0F8", func_0018D218);

INCLUDE_ASM("build/ee_asm/game/yi/yi_18D0F8", func_0018D288);

INCLUDE_ASM("build/ee_asm/game/yi/yi_18D0F8", func_0018D2B0);

int func_0018D310(Actor *a, ScrOpId *op, ScriptCtx *ctx) {
    int ret = 5;

    switch (func_00269BA8(op->id)) {
    case 0:
        break;
    case 1:
        ret = 0;
        break;
    case 2:
        if (op->w4 != 0) {
            ret = 0;
        }
        break;
    }
    return ret;
}

void func_0018D388(Actor *a, void *op, ScriptCtx *ctx) {
    AtelPushStackInteger(a, ctx, 1);
    func_0018D2B0(a, op, ctx);
}

int func_0018D3D8(Actor *a, void *op, ScriptCtx *ctx) {
    return func_0018D310(a, op, ctx);
}

void func_0018D3F8(Actor *a, void *op, ScriptCtx *ctx) {
    func_0014D800(AtelPopStackInteger(a, ctx));
}

int func_0018D418(Actor *a, void *op, ScriptCtx *ctx) {
    return 1;
}

int func_0018D420(Actor *a, void *op, ScriptCtx *ctx) {
    func_00269E50();
    return 1;
}

int func_0018D440(Actor *a, void *op, ScriptCtx *ctx) {
    func_00269EC0();
    return 1;
}

int func_0018D460(Actor *a, void *op, ScriptCtx *ctx) {
    int n0, n1;

    n1 = AtelPopStackInteger(a, ctx);
    n0 = AtelPopStackInteger(a, ctx);
    AtelBindFp(a, n0, n1);
    return 1;
}

int func_0018D4C0(Actor *a, void *op, ScriptCtx *ctx) {
    float z = AtelPopStackFloat(a, ctx);
    float y = AtelPopStackFloat(a, ctx);
    float x = AtelPopStackFloat(a, ctx);
    int id = AtelPopStackFloat(a, ctx);

    func_002EF240(D_0056D378, id, x, y, z);
    func_0014A650(a, id, x, y, z);
    return 1;
}

int func_0018D5B8(Actor *a, void *op, ScriptCtx *ctx) {
    int v = AtelPopStackInteger(a, ctx);

    func_0014A730(a, v >= 0 ? v : 0);
    return 1;
}

int func_0018D600(Actor *a, void *op, ScriptCtx *ctx) {
    int on = AtelPopStackInteger(a, ctx) != 0;

    func_00269B68(on);
    return on;
}

int func_0018D638(Actor *a, void *op, ScriptCtx *ctx) {
    return func_0019BC08();
}

int func_0018D658(Actor *a, void *op, ScriptCtx *ctx) {
    func_0019BC38(AtelPopStackInteger(a, ctx));
    return 1;
}

int func_0018D680(Actor *a, void *op, ScriptCtx *ctx) {
    func_0019BCA8(AtelPopStackInteger(a, ctx));
    return 1;
}

int func_0018D6A8(Actor *a, void *op, ScriptCtx *ctx) {
    int n0, n1, n2;

    n2 = AtelPopStackInteger(a, ctx);
    n1 = AtelPopStackInteger(a, ctx);
    n0 = AtelPopStackInteger(a, ctx);
    func_0019BD10(n0, n1, n2);
    return 1;
}

int func_0018D720(Actor *a, void *op, ScriptCtx *ctx) {
    return func_0019BD88(AtelPopStackInteger(a, ctx));
}

int func_0018D748(Actor *a, void *op, ScriptCtx *ctx) {
    return func_0019BDF0(AtelPopStackInteger(a, ctx));
}

int func_0018D770(Actor *a, void *op, ScriptCtx *ctx) {
    int n0;
    float f0;

    f0 = AtelPopStackFloat(a, ctx);
    n0 = AtelPopStackInteger(a, ctx);
    func_0019BE58(n0, f0);
    return 1;
}

float func_0018D7D0(Actor *a, void *op, ScriptCtx *ctx) {
    return func_0019BEC0(AtelPopStackInteger(a, ctx));
}
