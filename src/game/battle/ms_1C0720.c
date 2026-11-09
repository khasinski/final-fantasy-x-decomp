/* tu_192 0x1c0720-0x1c0c98: low; ~Ms (config/tu_map.tsv) */
#include "common.h"
#include "ffx/q4.h"
#include "ffx/r3.h"
#include "ffx/u2.h"
#include "ffx/v3.h"

int MsGetFirstAttack(int rate) {
    int r = 2;
    int rnd = (u8)brnd(1);
    int i;

    for (i = 0; i < 0x12; i++) {
        if (MsGetChr(i)->fA88 != 0 && ((MsGetSavePlayerPtr(i)->h4A >> 2) & 1)) {
            int t = rnd - 1;
            rnd = t - rate;
            break;
        }
    }
    if (rnd < 0xFF - rate) {
        r = rnd < rate;
    }
    return r;
}

INCLUDE_ASM("build/ee_asm/game/battle/ms_1C0720", MsSetFirstCTB);

int MsGetNextCTB(BtlChr *c, int a, int b, int d) {
    int m = a > 0 ? a : 1;
    return func_001C0AB0((int)c, MsGetRomCTBcount(c->f26C) * m, b, d);
}

int func_001C0AB0(int a, int b, int half, int dbl) {
    int v = b;
    if (half != 0) {
        v = b / 2;
    }
    return MsCheckRange(dbl ? v * 2 : v, 0, 255);
}

int MsCalcWeakLevel(int a, int b) {
    int q = 0;
    if (b != 0) {
        q = a * 4 / b;
    }
    if (a <= 0) {
        return 3;
    }
    if (q <= 0) {
        return 2;
    }
    return q < 2;
}

int MsSetChrWeak(int id, int mode) {
    BtlChr *c = MsGetChr(id);
    int s = MsCalcWeakLevel(c->f290, c->f254);
    int t;

    if (c->f110 != 0) {
        mode = 0;
    } else if (mode == -1) {
        mode = s;
        t = 0;
        if (mode == 0) {
            if (c->f2C8 != 0 || c->f2C9 != 0 || c->f2CA != 0) {
                mode = 1;
            }
        }
        if (mode == 3) {
            if (MsCheckInputCueExe(id, c) == 0) {
                t = 1;
                mode = 2;
            }
            if (c->fA8C == 0) {
                mode = 2;
            }
        }
        if (mode == 2) {
            if (D_003193EE != 0) {
                mode = 1;
            }
            if (MsGetRamChrSummon(id) != 0) {
                t ^= 1;
                mode = t;
            }
        }
    }
    c->f2FE = s;
    c->f2FD = mode;
    return mode;
}

int MsGetChrVigor(int id) {
    BtlChr *c = MsGetChr(id);
    if (MsCalcWeakLevel(c->f290, c->f254) == 0 && MsGetChrStatDeath(id) == 0) {
        if (MsGetChrStatStone(id) == 0) {
            return 1;
        }
    }
    return 0;
}
