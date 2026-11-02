/* tu_180 0x1af9e8-0x1b15c8: low; ~Ms (config/tu_map.tsv) */
#include "common.h"
#include "ffx/r2.h"
#include "ffx/q4.h"
#include "ffx/s2.h"
#include "ffx/u2.h"
#include "ffx/v2.h"
#include "ffx/t2.h"

s8 func_001AF9E8(int flag) {
    s8 old = D_003172F0.f30;
    D_003172F0.f30 = flag & 1;
    return old;
}

int func_001AFA00(void) {
    return func_002D9880();
}

void func_001AFA20(int n) {
    if (func_0020D540()) {
        if (n < 0) {
            D_00319464 = (D_00319464 + 1) & 7;
            n = D_00319464;
        }
        func_0011BFD0();
        Sg_DebugFill(n);
    }
}

void func_001AFA80(void) {
    D_0065FF70 = 0;
    D_003172F0.f59 = D_003172F0.f5A = 0;
    D_0065FF74 = 0;
}

INCLUDE_ASM("build/ee_asm/game/battle/ms_1AF9E8", MsBtlReadManage);
INCLUDE_RODATA("build/ee_asm/game/battle/ms_1AF9E8/rodata", jtbl_0056E1E0);

void func_001B0100(void) {
    D_00317300 = 7;
}

INCLUDE_ASM("build/ee_asm/game/battle/ms_1AF9E8", MsBtlReadSetScene);

INCLUDE_ASM("build/ee_asm/game/battle/ms_1AF9E8", func_001B0290);

void func_001B0460(Q4Link *p) {
    func_001B0480(p->fC);
    func_001B0290();
}

INCLUDE_ASM("build/ee_asm/game/battle/ms_1AF9E8", func_001B0480);

INCLUDE_ASM("build/ee_asm/game/battle/ms_1AF9E8", func_001B0528);

INCLUDE_ASM("build/ee_asm/game/battle/ms_1AF9E8", func_001B05F8);

void func_001B07A8(Q4Link2 *p) {
    int m = p->f10;
    func_001B09F0(p->fC);
    switch (m) {
    case 0:
        func_001B0940();
        break;
    case 2:
        func_001B1598();
        break;
    }
}

INCLUDE_ASM("build/ee_asm/game/battle/ms_1AF9E8", MsCDreadWeapon);

INCLUDE_ASM("build/ee_asm/game/battle/ms_1AF9E8", func_001B0940);

INCLUDE_ASM("build/ee_asm/game/battle/ms_1AF9E8", func_001B09F0);

void func_001B0B50(void);

void func_001B0AB0(int arg) {
    int sz;

    GetCD()->f10(0x29);
    sz = GetCD()->f14(arg);
    func_0011C348(0x40);
    D_0065FF74 = user_malloc(sz, 5, D_0056E258, -1);
    GetCD()->f0(arg, D_0065FF74, func_001B0B50, 0);
}

void func_001B0B50(void) {
    R2Hdr0 *p = D_0065FF74;
    int off = p->w4;

    if (p->w0 >= 2 && off != 0) {
        MsRegistSEdata(0, (u8 *)p + off);
    } else {
        MsBtlReadSceneFree();
    }
    func_001B0940();
}

void MsBtlReadSceneFree(void) {
    if (D_0065FF74 != 0) {
        func_0011D590(D_0065FF74, 5);
        D_0065FF74 = 0;
    }
}

void MsBtlReadPlayerModelProcess(int id) {
    MsBtlChrRegist(id, MsGetChr(id)->f04);
    MsStatusEffectCheck(id);
}

INCLUDE_ASM("build/ee_asm/game/battle/ms_1AF9E8", MsBtlReadPlayerProcess);

INCLUDE_ASM("build/ee_asm/game/battle/ms_1AF9E8", MsBtlReadMonsterProcess);

int func_001B0FE8(void) {
    GameState *g = &D_003172F0;
    int i;

    for (i = 0; i < 31; i++) {
        if (MsGetChr(i)->fF3 != 0) {
            g->f2138 = i;
            g->f2139 = 0xD0;
            return -1;
        }
    }
    return 0;
}

int func_001B1058(void) {
    int n = 0;
    int i;
    BtlChr *c;
    Chr *chr;
    float v[3];
    for (i = 20; i < 28; i++) {
        c = MsGetChr(i);
        chr = c->chr;
        if (chr != 0) {
            MsGetChrBtlPos(i, v);
            n++;
            graphicLevelGetNameHash((s32)chr, 0); /* DEBT(CAST): funcs.h takes s32 */
            Ch_SetPos3(chr, v[0], v[1], v[2]);
            if (c->fC7 == 0) {
                func_001B57F0(i, 0);
            }
        }
    }
    return n;
}

u8 MsBtlReadCueLevel(void) {
    return D_00318A41;
}

INCLUDE_ASM("build/ee_asm/game/battle/ms_1AF9E8", MsBtlReadCueManage);
INCLUDE_RODATA("build/ee_asm/game/battle/ms_1AF9E8/rodata", jtbl_0056E270);

void MsBtlReadCueRegist(int a, int b, int c, int d, int e) {
    if (D_003172F0.f1751 < 0x20) {
        S2Cmd *q = &S2_CMDQ[(D_003172F0.f1750 + D_003172F0.f1751) % 32];

        q->b0 = a;
        q->b1 = b;
        q->b4 = c;
        q->h6 = d;
        q->b3 = e;
        q->b2 = 0;
        q->w8 = 0;
        D_003172F0.f1751++;
        MsBtlReadCueManage();
    }
}

int MsBtlReadCueRegistWeapon(int id) {
    u16 *p;
    u16 v;
    int r = 0;
    for (p = D_00319468; (v = *p) != 0; p++) {
        if (id == v) {
            r = 1;
            break;
        }
    }
    return r;
}

INCLUDE_ASM("build/ee_asm/game/battle/ms_1AF9E8", func_001B1490);

void func_001B1598(void) {
    if (D_003172F0.f1751 != 0) {
        D_003172F0.ent[D_003172F0.f1750].fA = 2;
    }
}
