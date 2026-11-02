/* tu_201 0x1d48d0-0x1d8078: low; ~Ms (config/tu_map.tsv) */
#include "common.h"
#include "ffx/q4.h"
#include "ffx/r3.h"
#include "ffx/v3.h"
#include "ffx/s3.h"

void func_001D48D0(BtlChr *c)
{
    c->fC4 = 1;
    c->fC2 = 0x100;
}

void func_001D48E8(BtlChr *c)
{
    c->fC4 = 0;
    c->fC2 = 0x100;
}

INCLUDE_ASM("build/ee_asm/game/battle/ms_1D48D0", func_001D48F8);

void MsActionInit(void) {
    ZanmatoSep = -1;
}

INCLUDE_ASM("build/ee_asm/game/battle/ms_1D48D0", MsActionRequest);

int MsActionTarget(int mask, int v, int unused2, int unused3, int w, int mode) {
    int n = 0;
    int i;
    for (i = 0; i < 0x1F; i++) {
        if ((mask >> i) & 1) {
            MsGetChr(i)->fAAD = v;
            if (mode != 1 || MsCheckCommandCue(i, 1) != 0) {
                if (MsActionRequest(i, v, w, 0, mode, 0) == 0) n++;
            }
        }
    }
    return n;
}

int func_001D4EC0(int a) {
    if (ZanmatoSep != -1) {
        MsStructClear(D_00662CC8, 0x48);
        D_00662CC8[0] = a;
        D_00662CC0 = 0;
        D_00662CBC = 0;
        return 0;
    }
    return -1;
}

INCLUDE_ASM("build/ee_asm/game/battle/ms_1D48D0", MsActCommandAdd);

INCLUDE_ASM("build/ee_asm/game/battle/ms_1D48D0", MsActReCommand);

int MsActChangeCommand(int id, int h, int targets) {
    if (ZanmatoSep != -1) {
        BtlChr *c = MsGetChr(MsGetChr(id)->fAAD);
        if (c->fAB0 != 3) {
            GsEnt48 *e = MsGetChrCommand2(c->f0C);
            if (e != 0) {
                e->f8[e->f2].h0 = h;
                e->f8[e->f2].h2 = 0xFF;
                e->f8[e->f2].targets = targets;
            }
        }
    }
    return 0;
}

INCLUDE_ASM("build/ee_asm/game/battle/ms_1D48D0", func_001D5260);

INCLUDE_ASM("build/ee_asm/game/battle/ms_1D48D0", func_001D53E0);

INCLUDE_ASM("build/ee_asm/game/battle/ms_1D48D0", MsActTargetSearch);

u32 func_001D5790(BtlChr *c)
{
    u32 flags = c->flags;

    if (c->fBB != 0) {
        flags |= 8;
    }
    return flags;
}

float func_001D57A8(BtlChr *c) {
    float f = c->f17C;
    if (c->fBB != 0) {
        f += f;
    }
    return f;
}

INCLUDE_ASM("build/ee_asm/game/battle/ms_1D48D0", MsGetChrStatInfo);
INCLUDE_RODATA("build/ee_asm/game/battle/ms_1D48D0/rodata", jtbl_0056EB70);

INCLUDE_ASM("build/ee_asm/game/battle/ms_1D48D0", MsSetChrStatInfo);
INCLUDE_RODATA("build/ee_asm/game/battle/ms_1D48D0/rodata", jtbl_0056F0E0);

float func_001D7E80(int id, int a) {
    int scaled = 0;
    float v = 0.0f;
    BtlChr *c = MsGetChr(id);

    switch (a) {
    case 0:
        v = c->f17C;
        scaled = 1;
        break;
    case 1:
        v = c->f180;
        scaled = 1;
        break;
    case 2:
        v = c->f188;
        break;
    case 3:
        v = c->f194;
        break;
    case 4:
        v = c->f198;
        break;
    case 5:
        v = c->f18C;
        break;
    case 6:
        v = c->f190;
        break;
    case 7:
        v = c->f19C;
        break;
    case 8:
        v = c->f184;
        break;
    case 9:
        v = c->f1A4;
        break;
    }
    if (scaled) {
        if (MsGetDamageResult(id, func_001B8198(id, -16, 0, 1), 0, 0, 0) == 1) {
            v += 10.0;
        }
    }
    return v;
}

void MsSetChrMotionInfo(int id, int a, float f) {
    BtlChr *c = MsGetChr(id);
    Chr *chr = c->chr;

    switch (a) {
    case 0:
        c->f17C = f;
        break;
    case 1:
        c->f180 = f;
        break;
    case 2:
        c->f188 = f;
        break;
    case 3:
        c->f194 = f;
        break;
    case 4:
        c->f198 = f;
        break;
    case 5:
        c->f18C = f;
        break;
    case 6:
        c->f190 = f;
        break;
    case 7:
        c->f19C = f;
        break;
    case 8:
        c->f184 = f;
        break;
    case 9:
        c->f1A4 = f;
        c->f10C = 1;
        if (chr != 0) {
            Ch_SetThickness(chr, f);
        }
        break;
    }
}
