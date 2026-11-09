/* tu_061 0x135510-0x135b90: low; unk_135510 (config/tu_map.tsv) */
#include "common.h"
#include "ffx/q1.h"
#include "ffx/r0.h"

int func_00135510(Actor *a, void *op, ScriptCtx *ctx) {
    AtelSetDolby(AtelPopStackInteger(a, ctx));
    return 1;
}

int func_00135538(void) {
    MsSetSaveStartGame();
    MsBattleReadData();
    TkCdReadSync(0);
    return 1;
}

int func_00135568(Actor *a, void *op, ScriptCtx *ctx) {
    int v = AtelPopStackInteger(a, ctx);

    SndSepLock(v);
    return v;
}

int func_001355A0(Actor *a, void *op, ScriptCtx *ctx) {
    int v = AtelPopStackInteger(a, ctx);

    func_0014C828(v);
    return v;
}

int func_001355D8(Actor *a, void *op, ScriptCtx *ctx) {
    int x = AtelPopStackInteger(a, ctx);
    int y = AtelPopStackInteger(a, ctx);

    if (x != 0) {
        x = 1;
    }
    MsChangeWeaponInvisible(y, x);
    return x;
}

int func_00135640(Actor *a, void *op, ScriptCtx *ctx) {
    int on = AtelPopStackInteger(a, ctx) != 0;
    EvGameState *g = AtelGetCurCtrlWork();

    g->w210 = (g->w210 & ~8) | (on << 3);
    return on;
}

int func_00135690(Actor *a, void *op, ScriptCtx *ctx) {
    int on = AtelPopStackInteger(a, ctx) != 0;
    EvGameState *g = AtelGetCurCtrlWork();

    g->w210 = (g->w210 & ~0x40) | (on << 6);
    return on;
}

int func_001356E0(void) {
    return get_hdd_inst_info();
}

int func_00135700(void) {
    return func_00167D50();
}

int func_00135720(void) {
    func_00299B30();
    return 1;
}

int func_00135740(void) {
    func_00299B48();
    return 1;
}

int func_00135760(void) {
    func_00299B90();
    return 1;
}

int func_00135780(void) {
    func_00299BA8();
    return 1;
}

int func_001357A0(void) {
    func_00299B60();
    return 1;
}

int func_001357C0(void) {
    func_00299B78();
    return 1;
}

int func_001357E0(Actor *a, void *op, ScriptCtx *ctx) {
    u32 *flags = MsGetSaveMenu();
    int on = AtelPopStackInteger(a, ctx) != 0;

    *flags = (*flags & ~0x2000) | (on << 13);
    TkRefreshHDD();
    return on;
}

int func_00135850(Actor *a, void *op, ScriptCtx *ctx) {
    int x = AtelPopStackInteger(a, ctx);
    int i = AtelPopStackInteger(a, ctx);

    if (x != 0) {
        x = 1;
    }
    if ((AQ(a)->hB14 >> i) & 1) {
        if (AQ(a)->hB04[i] != 0xFF) {
            if (AQ(a)->arrAF4[i] != 0) {
                graphicLevelGetNameHash(AQ(a)->arrAF4[i], x);
            }
        }
    }
    return x;
}

int func_001358F0(Actor *a) {
    AQ(a)->w38 |= 0x1000;
    return 1;
}

int func_00135908(void) {
    return FFXGetLang();
}

int func_00135928(void) {
    s32 *flags = MsGetSaveMenu();

    return (*flags >> 14) & 3;
}

int func_00135950(Actor *a, void *op, ScriptCtx *ctx) {
    u32 *flags = MsGetSaveMenu();
    int v = AtelPopStackInteger(a, ctx);

    *flags = (*flags & ~0xC000) | ((v & 3) << 14);
    func_00265B58(D_0031B6BC);
    return v;
}

int func_001359D0(Actor *a, void *op, ScriptCtx *ctx) {
    int v = AtelPopStackInteger(a, ctx);

    AtelGetMesWinWork(v)->w28 = 0x8000;
    return v;
}

int func_00135A10(Actor *a, void *op, ScriptCtx *ctx) {
    int v = AtelPopStackInteger(a, ctx);

    AtelGetMesWinWork(v)->w28 = 0;
    return v;
}

void func_00135A48(Actor *a, OpArgs *op, ScriptCtx *ctx) {
    int on = AtelPopStackInteger(a, ctx) != 0;

    if (on != func_00138240()) {
        op->v0 = 0;
        MsSetSaveConfigEnglish(on);
        TOSwapInternationalEnvInit(func_00138240());
    } else {
        op->v0 = -1;
    }
}

int func_00135AB8(Actor *a, OpArgs *op) {
    int r = 0;

    if (op->v0 == 0) {
        if (TOSwapInternationalEnvExec()) {
            r = 5;
            op->v0 = -1;
        }
    } else {
        r = 5;
    }
    return r;
}

float func_00135B10(Actor *a, void *op, ScriptCtx *ctx) {
    float f = AtelPopStackFloat(a, ctx);

    func_001382C0(AtelPopStackInteger(a, ctx), f);
    return f;
}

int func_00135B70(void) {
    return func_00138220();
}
