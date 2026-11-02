/* tu_188 0x1ba7d0-0x1bb380: low; ~Ms (config/tu_map.tsv) */
#include "common.h"
#include "ffx/w4.h"
#include "ffx/v2.h"
#include "ffx/s3.h"
#include "ffx/q4.h"
#define MsSetChrTransparentVisible r3_MsSetChrTransparentVisible /* DEBT(TYPE): this header's guess conflicts with the TU */
#include "ffx/r3.h"
#undef MsSetChrTransparentVisible
#include "ffx/u2.h"
#include "ffx/v3.h"

INCLUDE_ASM("build/ee_asm/game/battle/ms_1BA7D0", MsSetRamChrParam);

void func_001BADA8(int a, int b, PairU16 *src) {
    D_003172F0.slot[a].id = b;
    D_003172F0.slot[a].val = src[b].v;
}

INCLUDE_ASM("build/ee_asm/game/battle/ms_1BA7D0", func_001BADD8);

INCLUDE_ASM("build/ee_asm/game/battle/ms_1BA7D0", MsGetCTBlist);

int func_001BB140(BtlChr *c) {
    if (FFXGetLang() == 0 && func_001BD360() == 0 && c->fA95 != 0) {
        return -1;
    }
    return 0;
}

void *func_001BB190(int id) {
    BtlChr *c = MsGetChr(id);
    if (func_001BB140(c) != 0) {
        func_0014D718(c->f200, c->f228);
        return c->f228;
    }
    return c->f200;
}

int func_001BB1E8(void) {
    return 0x28;
}

s32 MsGetRamChrHP(int id) {
    return MsGetChr(id)->f290;
}

s32 MsGetRamChrMP(int id) {
    return MsGetChr(id)->f294;
}

u8 MsGetRamChrStr(int id) {
    return MsGetChr(id)->f268;
}

u8 MsGetRamChrMag(int id) {
    return MsGetChr(id)->f26A;
}

s32 MsGetRamChrHPmax(int id) {
    return MsGetChr(id)->f254;
}

s32 MsGetRamChrMPmax(int id) {
    return MsGetChr(id)->f258;
}

u8 func_001BB2B0(int id) {
    return MsGetChr(id)->f31D;
}

int func_001BB2D0(int id) {
    return MsGetChr(id)->flags250 & 1;
}

int MsGetRamChrFemale(int id) {
    return (MsGetChr(id)->flags250 >> 1) & 1;
}

int MsGetRamChrSummon(int id) {
    return (MsGetChr(id)->flags250 >> 2) & 1;
}

int MsGetRamChrMegas(int id) {
    return (MsGetChr(id)->flags250 >> 3) & 1;
}

int MsGetRamChrMonster(int id) {
    return (u32)((u8)id - 0x14) < 8;
}
