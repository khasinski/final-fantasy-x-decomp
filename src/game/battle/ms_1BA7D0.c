/* tu_188 0x1ba7d0-0x1bb380: low; ~Ms (config/tu_map.tsv) */
#include "common.h"
#include "ffx/w4.h"
#include "ffx/v2.h"
#include "ffx/s3.h"
#include "ffx/q4.h"
#include "ffx/r3.h"
#include "ffx/u2.h"
#include "ffx/v3.h"

typedef struct {
    u8 pad00[0x52];
    u8 f52;
    u8 f53;
    s32 f54;
    s32 f58;
    s32 f5C;
    s32 f60;
    u8 pad64[0x4];
    u8 f68;
    u8 f69;
    u8 f6A;
    u8 f6B;
    u8 f6C;
    u8 f6D;
    u8 f6E;
    u8 f6F;
    u8 f70;
    u8 f71;
    u8 f72;
    u8 f73;
    u8 f74;
    u8 f75;
    u8 f76;
    u8 f77;
    u8 pad78[0x9];
    u8 f81;
    u8 pad82[0x5];
    u8 f87;
    u8 pad88[0x8];
    s32 f90;
    s32 f94;
    u8 f98;
    u8 f99;
    u8 f9A;
    u8 f9B;
    u8 f9C;
    u8 f9D;
    u8 f9E[0x19];
    u8 fB7[0xD];
    u16 fC4;
    u8 padC6[0x24];
    u16 fEA;
    u16 fEC;
    u16 fEE;
    u16 fF0;
    u16 fF2;
    u16 fF4;
    u16 fF6;
    u16 fF8;
    u16 fFA;
    u8 fFC;
    u8 padFD[0x4];
    u8 f101[0x19];
    u16 f11A;
    u8 pad11C[0x60];
    u16 f17C[3];
} RamChrSub;

typedef struct {
    u8 pad00[0x24];
    s32 f24;
    s32 f28;
    u8 pad2C;
    u8 f2D;
    u8 f2E;
    u8 f2F;
    u8 f30;
    u8 f31;
    u8 f32;
    u8 f33;
    u8 f34;
    u8 f35;
    u8 f36;
    u8 pad37[0x94 - 0x37];
} RamPartyView;

typedef struct {
    u8 pad00[0x8];
    u8 f08;
    u8 f09;
    u8 f0A;
    u8 pad0B[0x3];
    u16 f0E[4];
} RamWeaponView;

typedef struct {
    u8 pad00[0x10];
    u8 f10;
    u8 f11;
    u8 f12;
    u8 f13;
    u8 f14;
    u8 f15;
    u8 f16[0x19];
    u8 f2F[0xD];
    u8 f3C[0x19];
    u8 pad55[0x3];
    u16 f58;
    u16 f5A;
    u16 f5C;
    u16 f5E;
    u16 f60;
    u16 f62[3];
} RamAutoAbView;

void MsSetRamChrParam(int chr_id)
{
    RamWeaponView *wpn[2];
    BtlChr *chr = MsGetChr(chr_id);
    RamChrSub *sub = (RamChrSub *)((u8 *)chr + 0x200);
    RamPartyView *p = &((RamPartyView *)D_0031EA9C)[chr_id];
    int i, j, k;

    sub->f54 = p->f24;
    sub->f58 = p->f28;
    sub->f5C = p->f24;
    sub->f60 = p->f28;
    sub->f68 = MsCheckRange(p->f2F + sub->f70, 1, 0xFF);
    sub->f69 = MsCheckRange(p->f30 + sub->f71, 1, 0xFF);
    sub->f6A = MsCheckRange(p->f31 + sub->f72, 1, 0xFF);
    sub->f6B = MsCheckRange(p->f32 + sub->f73, 1, 0xFF);
    sub->f6C = MsCheckRange(p->f33 + sub->f74, 1, 0xFF);
    sub->f6D = MsCheckRange(p->f34 + sub->f75, 1, 0xFF);
    sub->f6E = MsCheckRange(p->f35 + sub->f76, 0, 0xFF);
    sub->f6F = MsCheckRange(p->f36 + sub->f77, 1, 0xFF);
    sub->f52 = p->f2D;
    sub->f53 = p->f2E;

    for (i = 0; i < 2; i++) {
        wpn[i] = (RamWeaponView *)MsGetSaveWeapon(chr->item252[i], 0);
    }

    sub->f81 = 1;
    sub->f87 = 0x10;
    sub->f98 = 0;
    sub->f99 = 0;
    sub->f9A = 0;
    sub->f9B = 0;
    sub->f9C = 0;
    sub->f9D = 0;
    for (i = 0; i < 0x19; i++) {
        sub->f9E[i] = 0;
    }
    for (i = 0; i < 0xD; i++) {
        sub->fB7[i] = 0;
    }
    sub->fC4 = 0;
    sub->fFC = 0;
    sub->fEA = 0;
    sub->fEC = 0;
    sub->fEE = 0;
    sub->fF0 = 0;
    sub->fF2 = 0;
    sub->fF4 = 0;
    sub->fF6 = 0;
    sub->fF8 = 0;
    sub->fFA = 0;
    for (i = 0; i < 0x19; i++) {
        sub->f101[i] = 0;
    }
    sub->f11A = 0;
    for (i = 0; i < 3; i++) {
        sub->f17C[i] = 0;
    }

    for (i = 0; i < 2; i++) {
        if (wpn[i] != 0) {
            if (i == 0) {
                sub->f81 = wpn[0]->f08;
                sub->f87 = wpn[0]->f09;
            }
            sub->f98 += wpn[i]->f0A;
            for (j = 0; j < 4; j++) {
                u16 ab = wpn[i]->f0E[j];
                if (ab != 0 && ab != 0xFF) {
                    RamAutoAbView *a = (RamAutoAbView *)MsGetExcelData(ab & 0xFFF, D_003172F0.p74, 0);
                    sub->f99 |= a->f11;
                    sub->f9A |= a->f12;
                    sub->f9B |= a->f13;
                    sub->f9C |= a->f14;
                    sub->f9D |= a->f15;
                    for (k = 0; k < 0x19; k++) {
                        sub->f9E[k] = MsCheckRange(sub->f9E[k] + a->f16[k], 0, 0xFE);
                    }
                    for (k = 0; k < 0xD; k++) {
                        sub->fB7[k] = MsCheckRange(sub->fB7[k] + a->f2F[k], 0, 0xFE);
                    }
                    sub->fC4 |= a->f5E;
                    if (a->f10 & 1) {
                        sub->fFC = 1;
                        sub->fF6 |= a->f58;
                        sub->fF8 |= a->f5A;
                        sub->fFA |= a->f5C;
                    } else {
                        sub->fF0 |= a->f58;
                        sub->fF2 |= a->f5A;
                        sub->fF4 |= a->f5C;
                    }
                    for (k = 0; k < 0x19; k++) {
                        sub->f101[k] = MsCheckRange(sub->f101[k] + a->f3C[k], 0, 0xFF);
                    }
                    sub->f11A |= a->f60;
                    for (k = 0; k < 3; k++) {
                        sub->f17C[k] |= a->f62[k];
                    }
                }
            }
        }
    }

    MsLimitStatusProcess(chr_id, chr, -1);
    sub->f90 = MsCheckRange(sub->f90, 0, sub->f54);
    sub->f94 = MsCheckRange(sub->f94, 0, sub->f58);
}

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
