/* tu_187 0x1b89d8-0x1ba7d0: low; ~Ms (config/tu_map.tsv) */
#include "common.h"
#include "ffx/r2.h"
#include "ffx/q4.h"
#include "ffx/s2.h"
#include "ffx/t2.h"
#include "ffx/u2.h"
#include "ffx/v2.h"
#include "ffx/g2.h"
#include "ffx/w4.h"

float func_001B89D8(int a, int b) {
    float va[4];
    float vb[4];
    float ra, rb;

    func_001B6790(a, va);
    ra = MsGetChrWidth(a);
    func_001B6790(b, vb);
    rb = MsGetChrWidth(b);
    return func_001AC348(va, vb) - ra - rb;
}

INCLUDE_ASM("build/ee_asm/game/battle/ms_1B89D8", MsGetExcelData);

int MsGetExcelDataNum(RangeTbl *tbl, int i) {
    RangeEnt *e = tbl->ent;
    e += i;
    return e->end - e->start + 1;
}

void func_001B8B20(void) {
    D_006625E0 = 0;
    btl_ply_win = 0;
}

void MsBtlGetItemMem(void) {
    D_006625E0 = (s32)user_malloc(0x21E8, 5, D_0056E430, -1); /* DEBT(TYPE): D_006625E0 is declared s32 */
    if (D_006625E0) {
        MsStructClear((void *)D_006625E0, 0x21E8);
    }
    btl_ply_win = (s32)user_malloc(0x8A88, 5, D_0056E440, -1); /* DEBT(TYPE): btl_ply_win is declared s32 */
    if (btl_ply_win) {
        MsStructFill((u16 *)btl_ply_win, 0x8A88, 0xFF);
    }
}

void MsBtlFreeItemMem(void) {
    if (D_006625E0 != 0) {
        func_0011D590(D_006625E0, 5);
        D_006625E0 = 0;
    }
    if (btl_ply_win != 0) {
        func_0011D590(btl_ply_win, 5);
        btl_ply_win = 0;
    }
}

int MsGetChrID(V2CmdRef *o)
{
    int a = 0;
    int b = 0;
    int r = 0;
    int cmd = o->cmd;
    int i = cmd & 0xFFF;

    switch (cmd >> 12) {
    case 0:
        b = D_00319478[i];
        if (i == 6 && func_0014ABB0(6) != 0) {
            a = 0x29;
            o->b1D = 0;
        } else {
            a = b;
        }
        r = i;
        break;
    case 1:
        b = i + 0x1000;
        r = i;
        a = b;
        break;
    }
    o->w08 = b;
    o->w04 = a;
    return r;
}

/* clamp(val, lo, hi) */
int MsCheckRange(int val, int lo, int hi) {
    if (val < lo) {
        val = lo;
    }
    if (val > hi) {
        val = hi;
    }
    return val;
}

void MsCheckStatus(void) {
    int i;
    for (i = 0; i < 0x1F; i++) {
        BtlChr *c = MsGetChr(i);
        if (c->f10 != 0) {
            c->f290 = MsCheckRange(c->f290, 0, c->f254);
            c->f294 = MsCheckRange(c->f294, 0, c->f258);
        }
    }
}

INCLUDE_ASM("build/ee_asm/game/battle/ms_1B89D8", MsSetRamChrData);

void MsSetRamMonData(void) {
    int i;

    for (i = 0; i < 8; i++) {
        if (S2_MsGetMon(i)->f10 != 0) {
            MsSetRamChr(0, i + 0x14);
        }
    }
}

int func_001B93E8(int id, int n) {
    S2BitChr *c = (S2BitChr *)MsGetChr(id); /* DEBT(CAST): character record viewed through its bit sets */
    int r = 0;
    int i;
    int m;

    n &= 0xFFF;
    m = 1 << (n & 15);
    i = n / 16;
    if (c->a324[i] & m) {
        r = 1;
    }
    if (c->a350[i] & m) {
        r |= 2;
    }
    return r;
}

void func_001B9458(int id, int n, int on) {
    S2BitChr *c = (S2BitChr *)MsGetChr(id); /* DEBT(CAST): character record viewed through its bit sets */
    int i;
    int m;

    n &= 0xFFF;
    i = n / 16;
    m = 1 << (n & 15);
    if (on) {
        c->a324[i] |= m;
    } else {
        c->a324[i] &= ~m;
    }
}

void func_001B94E8(int id, int n, int on) {
    S2BitChr *c = (S2BitChr *)MsGetChr(id); /* DEBT(CAST): character record viewed through its bit sets */
    int i;
    int m;

    n &= 0xFFF;
    i = n / 16;
    m = 1 << (n & 15);
    if (on) {
        c->a350[i] |= m;
    } else {
        c->a350[i] &= ~m;
    }
}

int func_001B9578(int id) {
    int r = 0;
    BtlChr *c = MsGetChr(id);

    if (c->f290 <= 0 || c->fA94 == 0 || c->fA8D != 0 || c->f398 != 0) {
        r = 1;
    }
    return r;
}

INCLUDE_ASM("build/ee_asm/game/battle/ms_1B89D8", MsGetCommandUse);

void func_001B96E8(int id, int cmd, int on)
{
    BtlChr *c;
    int i = cmd & 0xFFF;
    int w;
    int m;

    switch (cmd >> 12) {
    case 0:
        MsGetChr(i)->fA94 = on;
        break;
    case 3:
        c = MsGetChr(id);
        w = i / 16;
        m = 1 << (cmd & 0xF);
        if (on != 0) {
            c->f350[w] |= m;
        } else {
            c->f350[w] &= ~m;
        }
        break;
    }
}

int func_001B97B0(s16 *bits, int n) {
    int mask;
    n &= 0xFFF;
    mask = 1 << (n & 15);
    if (bits[n / 16] & mask) {
        return -1;
    }
    return 0;
}

s32 _m2c_MsClearStatus_MsLimitStatusProcess() __asm__("MsLimitStatusProcess");
/* DEBT(CAST) */ /* DEBT(FAKE) */
void MsClearStatus(s32 arg0, s32 arg1) {
    BtlChr *temp_2;
    s32 var_3;
    register s32 var_3_2 __asm__("$3");
    register s8 *var_2_2 __asm__("$2");
    register s8 *p31E __asm__("$5");
    u8 *var_2;
    void *temp_4;

    temp_2 = MsGetChr(arg0);
    var_3 = 0xC;
    temp_4 = ((BtlChr *)((u8 *)temp_2 + (0x200)));
    p31E = (s8 *)temp_2 + 0x31E;
    (*(s16 *)((u8 *)(temp_4) + (0xC6))) = 0;
    var_2 = &temp_2->f2D4;
    do {
        *var_2 = 0;
        var_3 -= 1;
        var_2 -= 1;
    } while (var_3 >= 0);
    (*(s16 *)((u8 *)(temp_4) + (0xD6))) = 0;
    __asm__ volatile("" : "+r"(p31E));
    var_2_2 = p31E + 5;
    var_3_2 = 5;
    do {
        *var_2_2 = 0;
        var_3_2 -= 1;
        var_2_2 -= 1;
    } while (var_3_2 >= 0);
    _m2c_MsClearStatus_MsLimitStatusProcess(arg0, temp_2, 0);
    temp_2->f2C6 = (temp_2->f2C6 & 0xFFFE) | (arg1 & 1);
}

void func_001B98A8(Obj436 *p) {
    int i;
    for (i = 0; i < 2; i++) {
        p->slot[i].v = 0xFF;
    }
}

INCLUDE_ASM("build/ee_asm/game/battle/ms_1B89D8", MsSetRamChr);

INCLUDE_ASM("build/ee_asm/game/battle/ms_1B89D8", MsSetRamChrAbility);
INCLUDE_RODATA("build/ee_asm/game/battle/ms_1B89D8/rodata", jtbl_0056E450);
INCLUDE_RODATA("build/ee_asm/game/battle/ms_1B89D8/rodata", jtbl_0056E490);

INCLUDE_ASM("build/ee_asm/game/battle/ms_1B89D8", func_001BA720);
