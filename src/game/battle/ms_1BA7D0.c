/* tu_188 0x1ba7d0-0x1bb380: low; ~Ms (config/tu_map.tsv) */
#include "common.h"
#include "ffx/w4.h"
#include "ffx/v2.h"
#include "ffx/s3.h"
#include "ffx/q4.h"
#include "ffx/r3.h"
#include "ffx/u2.h"
#include "ffx/v3.h"

INCLUDE_ASM("build/ee_asm/game/battle/ms_1BA7D0", MsSetRamChrParam);

void func_001BADA8(int a, int b, PairU16 *src) {
    D_003172F0.slot[a].id = b;
    D_003172F0.slot[a].val = src[b].v;
}

void func_001BADD8(int id, int a1, s32 *a2, u8 *a3, u8 *a4) {
    BtlChr *c = MsGetChr(id);
    a2[id] += MsGetNextCTB(c, a1, a3[id], a4[id]);
    if ((u8)(a3[id] - 1) < 0xFD) {
        a3[id]--;
    }
    if ((u8)(a4[id] - 1) < 0xFD) {
        a4[id]--;
    }
}

extern int MsCalcCostCTB(void *);
extern void MsCalcDamageCTB(void *, s32 *, int, u8 *, u8 *);
extern void MsOrderInit(void);
extern void MsOrderRegist(int);
extern u8 *MsOrderCalc(s32 *);
extern u8 D_00318810[];
extern u8 D_00317420[];

typedef struct {
    u8 pad00[0x130];
    struct { s8 id; u8 pad1; s16 val; } slot[32];
    u8 pad1B0[0x1520 - 0x1B0];
    u8 f1520[0x2116 - 0x1520];
    s8 f2116;
} CtbGsView; /* DEBT(NAME): GameState offset view for MsGetCTBlist */

void *MsGetCTBlist(s32 *out_cnt)
{
    s32 ctb[0x20];
    u8 spd[0x20];
    u8 slw[0x20];
    s32 order_cnt;
    int cost = 3;
    register int act_id __asm__("$20") = -1; /* DEBT(REG): pin act_id to $s4 */
    int i, slot;
    register int ord_idx __asm__("$17"); /* DEBT(REG): pin ord_idx to $s1 */
    register u8 *ord_list __asm__("$18"); /* DEBT(REG): pin ord_list to $s2 */
    CtbGsView *gs = (CtbGsView *)&D_003172F0; /* DEBT(CAST): GameState view */

    if (gs->f2116 != 0) {
        act_id = gs->f1520[0];
        cost = MsCalcCostCTB(gs->f1520);
    }

    for (slot = 0; slot < 0x1F; slot++) {
        BtlChr *c = MsGetChr(slot);
        spd[slot] = c->f2D3;
        slw[slot] = c->f2D4;
        if (c->fA88 != 0 && *((s8 *)c + 0xA97) != 0 && c->fA8C == 0 && !((c->f2C6 >> 2) & 1)) { /* DEBT(CAST): BtlChr +0xA97 */
            ctb[slot] = c->f31C;
        } else {
            ctb[slot] = -1;
        }
    }

    order_cnt = 0;
    ord_list = 0;
    ord_idx = 0;
    slot = 0;
    if (act_id >= 0 && ctb[act_id] >= 0) {
        func_001BADA8(0, act_id, (void *)ctb);
        slot = 1;
        MsCalcDamageCTB(D_00318810, ctb, cost, spd, slw);
        func_001BADD8(act_id, cost, ctb, spd, slw);
    }

    while (slot < 0x20) {
        if (order_cnt <= 0) {
            register int min_val __asm__("$18") = -2; /* DEBT(REG): pin min_val to $s2 */
            MsOrderInit();
            for (i = 0; i < 0x1F; i++) {
                if (ctb[i] >= 0) {
                    if (ctb[i] < min_val || min_val < 0) {
                        min_val = ctb[i];
                    }
                }
            }
            for (i = 0; i < 0x1F; i++) {
                if (ctb[i] == min_val) {
                    MsOrderRegist(i);
                }
            }
            ord_list = MsOrderCalc(&order_cnt);
            if (order_cnt <= 0) {
                break;
            }
            ord_idx = 0;
        }
        func_001BADA8(slot, ord_list[ord_idx], (void *)ctb);
        slot++;
        func_001BADD8(ord_list[ord_idx], 3, ctb, spd, slw);
        ord_idx++;
        order_cnt--;
    }

    for (; slot < 0x20; slot++) {
        ((CtbGsView *)&D_003172F0)->slot[slot].id = -1; /* DEBT(CAST): GameState slot view */
        ((CtbGsView *)&D_003172F0)->slot[slot].val = 0;
    }
    if (out_cnt != 0) {
        *out_cnt = 0x20;
    }
    return D_00317420;
}

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
