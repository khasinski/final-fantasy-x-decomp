/* tu_187 0x1b89d8-0x1ba7d0: low; ~Ms (config/tu_map.tsv) */
#define MsGetExcelData _hdr_MsGetExcelData
#include "common.h"
#include "ffx/r2.h"
#include "ffx/q4.h"
#include "ffx/s2.h"
#include "ffx/t2.h"
#include "ffx/u2.h"
#include "ffx/v2.h"
#include "ffx/g2.h"
#include "ffx/w4.h"
#undef MsGetExcelData

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

void *MsGetExcelData(int id, RangeTbl *tbl, void **strings_out) {
    RangeEnt *ent = tbl->ent;
    RangeEnt *e = ent;
    int i;

    for (i = 0; i < tbl->count; i++, e++) {
        if (id >= e->start && id <= e->end) {
            if (strings_out != 0) {
                *strings_out = (u8 *)tbl + e->off + e->extra;
            }
            return (u8 *)tbl + e->off + (id - e->start) * e->stride;
        }
    }
    if (strings_out != 0) {
        *strings_out = (u8 *)tbl + ent->off + ent->extra;
    }
    return (u8 *)tbl + ent->off;
}

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

int func_001BFE30(int);

int MsGetCommandUse(int id, int cmd)
{
    int i = cmd & 0xFFF;
    int r = 0;
    BtlChr *c;
    int w;
    int m;

    switch (cmd >> 12) {
    case 3:
        c = MsGetChr(id);
        w = i / 16;
        m = 1 << (cmd & 0xF);
        if (c->f350[w] & m) {
            r = 1;
        }
        if (cmd == 0x30FF) {
            for (i = 15; i < 18; i++) {
                if (func_001B9578(i) != 0) {
                    r = 1;
                    break;
                }
            }
        }
        break;
    case 0:
        if (func_001B9578(i) != 0) {
            r = 1;
        }
        break;
    case 2:
        if (cmd == *(u16 *)&D_00319368 && func_001BFE30(cmd) <= 0) {
            r = 1;
        }
        break;
    }
    return r;
}

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

typedef struct {
    u16 f00[0x14];
    u16 f28[0x8];
    u16 f38[0x8];
    u16 f48[0x18];
    u16 f78[0x18];
    u16 fA8[0x20];
    u16 fE8[0x20];
    u16 f128[0x18];
    u8 pad158[0x478 - 0x158];
} BtlPlyWin;

typedef struct {
    u8 pad0[0x3D6C];
    u16 f3D6C[16];
    u8 pad3D8C[0x3ECC - 0x3D8C];
    u16 f3ECC[0x70];
    u8 pad3FAC[0x40CC - 0x3FAC];
    u8 f40CC[0x70];
    u8 pad413C[0x449C - 0x413C];
    struct {
        u16 h0;
        u8 b2;
        u8 b3;
        u8 b4;
        u8 b5;
        u8 pad6[0x10];
    } f449C[200];
} SaveRamAbility;

typedef struct {
    u8 pad0[0x2C];
    u8 f2C;
    u8 pad2D[0x3E - 0x2D];
    u16 f3E[6];
    u8 pad4A[0x94 - 0x4A];
} PartySlotLocal;

void MsSortCommand(void *win);
u8 *MsGetBattleList(int mode, int *out);

void MsSetRamChrAbility(int id, BtlChr *chr) {
    u16 *dst = chr->f324;
    PartySlotLocal *ps = &((PartySlotLocal *)D_0031EA9C)[id];
    SaveRamAbility *ram;
    OfsTbl *cmd;
    int is_yojimbo;
    int is_magus;
    int cmd_id;
    int i;
    int j;

    for (i = 0; i < 6; i++) {
        dst[i] = ps->f3E[i];
    }
    ram = (SaveRamAbility *)&D_003194D0;
    for (i = 0; i < 16; i++) {
        dst[6 + i] = ram->f3D6C[i];
    }
    is_yojimbo = 0;
    is_magus = 0;
    if (id == 0xE) {
        is_yojimbo = 1;
    }
    if (id >= 0xF && id <= 0x11) {
        is_magus = 1;
    }
    for (i = 0; i < 0x140; i++) {
        int kind;
        cmd = MsGetRomPlyCommand(i, 0);
        kind = cmd->b16 & 0xF8;
        if (kind == 8) {
            int has = 0;
            int sub = cmd->b17;
            for (j = 0; j < 0x140; j++) {
                OfsTbl *c2 = MsGetRomPlyCommand(j, 0);
                if ((c2->b16 & 7) == 0 && ((u8 *)c2)[0x18] == sub) {
                    if (func_001B93E8(id, j) & 1) {
                        has = 1;
                        break;
                    }
                }
            }
            switch (sub) {
            case 6:
            case 17:
                for (j = 0; j < 0x70; j++) {
                    if (((SaveRamAbility *)&D_003194D0)->f3ECC[j] != 0 && ((SaveRamAbility *)&D_003194D0)->f40CC[j] != 0) {
                        has = 1;
                    }
                }
                break;
            case 5:
                for (j = 8; j < 0x12; j++) {
                    if (((PartySlotLocal *)D_0031EA9C)[j].f2C & 1) {
                        has = 1;
                        break;
                    }
                }
                break;
            case 7:
                for (j = 0; j < 200; j++) {
                    if (((SaveRamAbility *)&D_003194D0)->f449C[j].b2 != 0 &&
                        ((SaveRamAbility *)&D_003194D0)->f449C[j].b5 == 0 &&
                        ((SaveRamAbility *)&D_003194D0)->f449C[j].b4 == id &&
                        !((((SaveRamAbility *)&D_003194D0)->f449C[j].b3 >> 1) & 1)) {
                        has = 1;
                        break;
                    }
                }
                break;
            case 15:
                for (j = 0; j < 200; j++) {
                    if (((SaveRamAbility *)&D_003194D0)->f449C[j].b2 != 0 &&
                        ((SaveRamAbility *)&D_003194D0)->f449C[j].b5 == 1 &&
                        ((SaveRamAbility *)&D_003194D0)->f449C[j].b4 == id &&
                        !((((SaveRamAbility *)&D_003194D0)->f449C[j].b3 >> 1) & 1)) {
                        has = 1;
                        break;
                    }
                }
                break;
            case 10:
                MsGetBattleList(sub, &has);
                if (has != 0) {
                    has = 1;
                }
                break;
            }
            if (kind == 8) {
                func_001B9458(id, i, has);
            } else if (has == 0) {
                func_001B94E8(id, i, 1);
            }
        }
        {
            u8 owner = ((u8 *)cmd)[0x19];
            if (owner == 0xFF) {
                if (is_yojimbo != 0 || is_magus != 0) {
                    func_001B9458(id, i, 0);
                }
            } else if (owner != id) {
                func_001B9458(id, i, 0);
            }
        }
    }
    for (i = 0; i < 0x140; i++) {
        u16 *list;
        int max;
        int on;
        int empty;

        cmd = MsGetRomPlyCommand(i, 0);
        cmd_id = i + 0x3000;
        list = 0;
        max = 0;
        if ((cmd->b16 & 7) == 0) {
            switch (((u8 *)cmd)[0x18]) {
            case 1:
                list = ((BtlPlyWin *)btl_ply_win)[id].f78;
                max = 0x18;
                break;
            case 2:
                list = ((BtlPlyWin *)btl_ply_win)[id].f48;
                max = 0x18;
                break;
            case 3:
                list = ((BtlPlyWin *)btl_ply_win)[id].fA8;
                max = 0x20;
                break;
            case 14:
                list = ((BtlPlyWin *)btl_ply_win)[id].fE8;
                max = 0x20;
                break;
            case 4:
                list = ((BtlPlyWin *)btl_ply_win)[id].f128;
                max = 0x18;
                break;
            }
        } else {
            if ((cmd->flags >> 12) & 1) {
                list = ((BtlPlyWin *)btl_ply_win)[id].f28;
                max = 8;
            } else if ((cmd->flags >> 11) & 1) {
                list = ((BtlPlyWin *)btl_ply_win)[id].f38;
                max = 8;
            } else {
                list = ((BtlPlyWin *)btl_ply_win)[id].f00;
                max = 0x14;
            }
        }
        on = func_001B93E8(id, i) & 1;
        empty = -1;
        if (list != 0) {
            for (j = 0; j < max; j++) {
                if (list[j] == 0xFF && empty < 0) {
                    empty = j;
                }
                if (list[j] == cmd_id) {
                    if (on == 0) {
                        list[j] = 0xFF;
                    } else {
                        on = -1;
                    }
                }
            }
            if (on > 0 && empty >= 0) {
                list[empty] = cmd_id;
            }
        }
    }
    MsSortCommand(&((BtlPlyWin *)btl_ply_win)[id]);
    for (i = 0; i < ((u8 *)chr)[0x38B]; i++) {
        int pos;
        cmd_id = ((struct { u8 pad[0x3DA]; u16 f3DA[4]; u8 f3E2[4]; } *)chr)->f3DA[i];
        pos = ((struct { u8 pad[0x3DA]; u16 f3DA[4]; u8 f3E2[4]; } *)chr)->f3E2[i];
        for (j = 7; j > pos; j--) {
            ((BtlPlyWin *)btl_ply_win)[id].f28[j] = ((BtlPlyWin *)btl_ply_win)[id].f28[j - 1];
        }
        ((BtlPlyWin *)btl_ply_win)[id].f28[pos] = cmd_id;
    }
}

INCLUDE_ASM("build/ee_asm/game/battle/ms_1B89D8", func_001BA720);
