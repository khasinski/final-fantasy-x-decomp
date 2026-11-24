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

extern u8 D_00662580[];
void MsSetRamChrParam(int id);
void MsSetChrImageDamageAttack(void *c);
void MsSetRamChrAbility(int id, BtlChr *chr);
void func_001BA720(int id);

typedef struct {
    u8 name[0x28];
    u8 pad28[0x50 - 0x28];
    u8 b50;
    u8 b51;
    u8 b52[2];
    s32 w54;
    s32 w58;
    s32 w5C;
    s32 w60;
    s32 w64;
    u8 b68;
    u8 b69;
    u8 b6A;
    u8 b6B;
    u8 b6C;
    u8 b6D;
    u8 b6E;
    u8 b6F;
    u8 pad70[8];
    u16 h78;
    u8 b7A;
    u8 b7B;
    u8 b7C;
    u8 b7D;
    u8 pad7E[3];
    u8 b81;
    u8 b82;
    u8 b83;
    u8 pad84;
    u8 b85;
    u8 b86;
    u8 b87;
    u8 b88;
    u8 b89;
    u8 pad8A[2];
    s32 w8C;
    s32 w90;
    s32 w94;
    u8 pad98;
    u8 b99;
    u8 b9A;
    u8 b9B;
    u8 b9C;
    u8 b9D;
    u8 pad9E[0xC6 - 0x9E];
    u16 hC6;
    u8 padC8[0xD6 - 0xC8];
    u16 hD6;
    u8 padD8[0xEA - 0xD8];
    u16 hEA;
    u8 padEC[2];
    u16 hEE;
    u16 hF0;
    u16 hF2;
    u16 hF4;
    u16 hF6;
    u16 hF8;
    u16 hFA;
    u8 bFC;
    u8 padFD[4];
    u8 b101[0x19];
    u16 h11A;
    u8 pad11C[0x150 - 0x11C];
    u16 h150[0x16];
    u8 pad17C[0x186 - 0x17C];
    u16 h186;
    u16 h188;
    u8 pad18A[7];
    u8 b191;
    u8 pad192;
    u8 b193;
    u8 b194;
    u8 pad195;
    u16 h196;
    u8 b198;
    u8 b199;
    u8 pad19A[7];
    u8 b1A1;
    u8 pad1A2[2];
    s32 w1A4;
    s32 w1A8;
    u8 pad1AC[0x1BC - 0x1AC];
    s32 w1BC;
    u8 pad1C0[0x1CC - 0x1C0];
    float f1CC;
    u8 pad1D0[2];
    u16 h1D2;
    u8 pad1D4[5];
    u8 b1D9;
    u8 pad1DA[0x1EC - 0x1DA];
} BtlChrSub200;

typedef struct {
    u8 pad00[0x04];
    s32 w04;
    s32 w08;
    u8 b0C;
    u8 b0D;
    u16 h0E;
    s8 b10;
    s8 b11;
    u8 pad12;
    u8 b13;
    u8 b14;
    s8 b15;
    s8 b16[4];
    u8 pad1A;
    s8 b1B;
    s8 b1C;
    s8 b1D;
    s8 b1E;
    u8 pad1F;
    s8 b20;
    s8 b21;
    s8 b22;
    s8 b23;
    s8 b24;
    s8 b25;
    s8 b26;
    s8 b27;
    s8 b28;
    u8 pad29;
    s8 b2A;
    s8 b2B;
    s8 b2C;
    s8 b2D;
    s8 b2E[4];
    s8 b32;
    u8 pad33;
    s8 b34;
    u8 pad35[2];
    s8 b37;
    u8 pad38;
    s8 b39;
    u8 pad3A[6];
    float f40;
    float f44;
    void *p48;
    u8 pad4C[0x60 - 0x4C];
    float f60;
    float f64;
    float f68;
    float f6C;
    u8 pad70[0xB0 - 0x70];
    u8 bB0;
    u8 bB1;
    u8 bB2;
    u8 padB3[2];
    s8 bB5;
    s8 bB6;
    u8 padB7;
    s8 bB8;
    s8 bB9;
    u8 padBA[2];
    s16 hBC;
    u8 padBE[2];
    s16 hC0;
    u8 padC2[4];
    s8 bC6;
    u8 padC7;
    s8 bC8;
    s8 bC9;
    u8 padCA[5];
    s8 bCF;
    u8 padD0[0xDD - 0xD0];
    s8 bDD;
    u8 padDE[4];
    s8 bE2;
    u8 padE3[0xF7 - 0xE3];
    s8 bF7;
    u8 bF8;
    u8 padF9[2];
    s8 bFB;
    u8 padFC;
    s8 bFD;
    u8 padFE;
    u8 bFF;
    u8 pad100[2];
    u8 b102;
    u8 pad103[4];
    s8 b107;
    u8 pad108[7];
    s8 b10F;
    u8 pad110[0x170 - 0x110];
    s16 h170;
    s16 h172;
    u8 pad174[4];
    s8 b178;
    s8 b179;
    s8 b17A;
    u8 pad17B;
    float f17C;
    s32 w180;
    s32 w184;
    u8 pad188[8];
    float f190;
    float f194;
    float f198;
    float f19C;
    u8 pad1A0[0x1B0 - 0x1A0];
    float f1B0;
    u8 pad1B4[9];
    s8 b1BD;
    s8 b1BE;
    u8 pad1BF[0x1CC - 0x1BF];
    s8 b1CC;
    u8 pad1CD[0x1F4 - 0x1CD];
    s32 w1F4;
    u8 pad1F8[8];
    BtlChrSub200 s200;
    u8 pad3EC[0xA88 - 0x3EC];
    s8 bA88;
    u8 padA89[3];
    s8 bA8C;
    u8 padA8D[5];
    s8 bA92;
    s8 bA93;
    s8 bA94;
    s8 bA95;
    s8 bA96;
    s8 bA97;
    s8 bA98;
    s8 bA99;
    s8 bA9A;
    u8 padA9B[3];
    u16 hA9E;
    u8 padAA0[4];
    u8 bAA4;
    u8 bAA5;
    u8 padAA6[0xAB3 - 0xAA6];
    s8 bAB3;
    u8 padAB4[5];
    s8 bAB9;
    u8 padABA[0xACE - 0xABA];
    s8 bACE;
    s8 bACF;
    u8 padAD0[5];
    s8 bAD5;
    u8 padAD6[0xAEC - 0xAD6];
    s32 wAEC;
    u8 padAF0[0xC20 - 0xAF0];
    s32 wC20;
    u8 padC24[0xC34 - 0xC24];
    u8 bC34;
    u8 bC35;
    u8 padC36[0xC40 - 0xC36];
    void *pC40[2];
    void *pC48;
} BtlChrEx;

typedef struct {
    u8 pad00[0x4D];
    s8 b4D;
    s8 b4E;
    u8 pad4F[0x68 - 0x4F];
    RangeTbl *p68;
    u8 pad6C[0xF0 - 0x6C];
    u16 *pF0;
    u8 padF4[0x20FE - 0xF4];
    s8 b20FE;
    u8 pad20FF[0x2115 - 0x20FF];
    u8 b2115;
} GameStateEx;

#define GS_EX ((GameStateEx *)&D_003172F0)

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

typedef struct {
    u8 raw[0x118];
} BtlItemSlot;

typedef struct {
    u8 pad00[0x14];
    s32 w14;
    u8 pad18[4];
    s32 w1C;
    s32 w20;
    s32 w24;
    u8 pad28[4];
    u8 b2C;
    u8 pad2D[0x37 - 0x2D];
    u8 b37;
    u8 b38;
    u8 b39;
    u8 b3A;
    u8 pad3B[2];
    u8 b3D;
    u8 pad3E[0x94 - 0x3E];
} PartySlotEx;

typedef struct {
    u8 pad00[0x10];
    u8 b10;
    u8 pad11[0x2A - 0x11];
    u8 b2A;
    u8 b2B;
} PlyExcelEx;

typedef struct {
    u8 pad00[0x14];
    s32 w14;
    s32 w18;
    s32 w1C;
    u8 b20;
    u8 b21;
    u8 b22;
    u8 b23;
    u8 b24;
    u8 b25;
    u8 b26;
    u8 b27;
    u16 h28;
    u8 b2A;
    u8 b2B;
    u8 b2C;
    u8 b2D;
    u8 b2E;
    u8 b2F[0x19];
    u16 h48;
    u16 h4A;
    u16 h4C;
    u16 h4E;
    u16 h50[16];
    u16 h70;
    u8 pad72[2];
    u16 h74;
    u8 b76;
    u8 b77;
    u16 h78;
} MonDataEx;

void MsSetRamChr(int unused, int id)
{
    BtlChrEx *c = (BtlChrEx *)MsGetChr(id);
    BtlChrSub200 *s = &c->s200;

    MsStructClear(s, 0x1EC);
    if (MsGetRamChrMonster(id) == 0) {
        PlyExcelEx *ex = (PlyExcelEx *)MsGetExcelData(id, GS_EX->p68, 0);
        PartySlotEx *ps = &((PartySlotEx *)D_0031EA9C)[id];
        u8 *name = ((u8 *)D_0031EA9C) + 0xD80 + id * 0x14;
        int j;

        for (j = 0; j < 0x14; j++) {
            s->name[j] = *name++;
        }
        s->b50 = ex->b10;
        s->b51 = ps->b2C;
        s->b7A = MsCheckRange(ps->b37, 0, 0xFF);
        s->b85 = 0xFF;
        s->b86 = 0xFF;
        s->h78 = 0;
        s->b7B = ps->b38;
        s->b7C = ps->b39;
        s->b7D = ps->b3A;
        s->b88 = 0;
        s->b89 = ex->b2A;
        s->h196 = 0;
        s->b198 = ps->b3D;
        s->b199 = ex->b2B;
        s->w8C = ps->w14;
        s->w90 = ps->w1C;
        s->w94 = ps->w20;
        s->w64 = ps->w24;
        s->w1A4 = s->w90;
        s->w1A8 = s->w94;
        s->w1BC = -1;
        s->b191 = 0xFF;
        s->b1A1 = 0x32;
        s->b1D9 = 0;
        c->wC20 = s->w64;
        s->b82 = id;
        s->b83 = 0;
        s->f1CC = 1.0f;
        s->h1D2 = 0xFF;
        MsSetRamChrParam(id);
        {
            register s32 off __asm__("$2") = id * 0x118; /* DEBT(REG) */
            register s32 base __asm__("$5") = D_006625E0; /* DEBT(REG) */
            register u16 c3000 __asm__("$3") = 0x3000; /* DEBT(REG) */
            register void *p __asm__("$7"); /* DEBT(REG) */
            s->hC6 = 0;
            s->hD6 = 0;
            s->h186 = c3000;
            p = (void *)(base + off);
            c->pC48 = p;
        }
        if (MsGetRamChrSummon(id) != 0) {
            s->h188 = 0;
        } else {
            s->h188 = 0x3021;
        }
        s->h78 |= 0x200;
        s->b193 = 0xFF;
        s->b194 = 0xFF;
        for (j = 0; j < 0x16; j++) {
            s->h150[j] = 0;
        }
        MsSetChrImageDamageAttack(c);
        MsSetRamChrAbility(id, (BtlChr *)c);
        func_001BA720(id);
        if (GS_EX->b20FE != 0 || GS_EX->b2115 == 2) {
            func_001B96E8(id, 0x3002, 1);
        }
        if (GS_EX->b4D != 0) {
            s->w90 = 1;
        }
    } else {
        MonDataEx *m = (MonDataEx *)c->pC40[0];
        register u8 *lang __asm__("$3") = (u8 *)c->pC40[func_001BD360()]; /* DEBT(REG) */
        u8 *m48 = (u8 *)c->p48;
        int cnt;
        int i;

        if (m48 != 0) {
            register u8 *mname __asm__("$5"); /* DEBT(REG) */
            BtlItemSlot *dst;
            u8 *m2F;

            {
                register u16 w08 __asm__("$2") = m->h74; /* DEBT(REG) */
                c->w08 = w08;
                __asm__("" : "+m"(c->w08), "+r"(m)); /* DEBT(ORDER) */
            }
            m2F = m->b2F;
            __asm__("" : "+r"(m2F), "+r"(lang)); /* DEBT(ORDER) */
            {
                register int loff __asm__("$2") = *(u16 *)lang; /* DEBT(REG) */
                __asm__("" : "+r"(loff)); /* DEBT(ORDER) */
                mname = lang + (loff + 0x80);
            }
            {
                register int j __asm__("$6"); /* DEBT(REG) */
                for (j = 0; j < 0x28; j++) {
                    s->name[j] = mname[j];
                }
            }
            {
                register u8 *p52_base __asm__("$7") = s->b52; /* DEBT(REG) */
                register u8 *p52 __asm__("$2"); /* DEBT(REG) */
                register u8 ff __asm__("$3"); /* DEBT(REG) */
                register int k __asm__("$6"); /* DEBT(REG) */
                __asm__("" : "+r"(p52_base)); /* DEBT(ORDER) */
                p52 = p52_base + 1;
                __asm__ volatile("" : "+r"(p52)); /* DEBT(ORDER) */
                ff = 0xFF;
                for (k = 1; k >= 0; k--) {
                    *p52-- = ff;
                }
            }
            s->w54 = m->w14;
            s->w58 = m->w18;
            s->w5C = m->w14;
            s->w60 = m->w18;
            s->b68 = MsCheckRange(m->b20, 1, 0xFF);
            s->b69 = MsCheckRange(m->b21, 1, 0xFF);
            s->b6A = MsCheckRange(m->b22, 1, 0xFF);
            s->b6B = MsCheckRange(m->b23, 1, 0xFF);
            s->b6C = MsCheckRange(m->b24, 1, 0xFF);
            s->b6D = MsCheckRange(m->b25, 1, 0xFF);
            s->b6E = MsCheckRange(m->b26, 0, 0xFF);
            s->b6F = MsCheckRange(m->b27, 1, 0xFF);
            s->b7A = MsCheckRange(m->b2A, 0, 0xFF);
            s->h78 = m->h28;
            s->b81 = 1;
            s->b85 = 0xFF;
            s->b86 = 0xFF;
            s->b87 = 0x10;
            s->b7D = 0x64;
            s->b7B = 0;
            s->b7C = 0;
            s->b88 = 0;
            s->b89 = m->b77;
            s->h196 = m->h78;
            s->b198 = 0;
            s->b199 = 0;
            s->w90 = m->w14;
            s->w94 = m->w18;
            s->w64 = m->w1C;
            c->wC20 = s->w64;
            s->b191 = 0xFF;
            {
                register s32 hp __asm__("$2") = s->w90; /* DEBT(REG) */
                register s32 mp __asm__("$3") = s->w94; /* DEBT(REG) */
                s->b1D9 = 1;
                s->w1A8 = mp;
                s->w1BC = -1;
                s->w1A4 = hp;
            }
            s->b1A1 = 0;
            s->b99 = 0;
            s->b9A = m->b2B;
            s->b9B = m->b2C;
            s->b9C = m->b2D;
            s->b9D = m->b2E;
            s->bFC = 0;
            s->hEA = 0;
            s->hEE = 0;
            s->hF0 = m->h48;
            {
                register u16 h4A __asm__("$4") = m->h4A; /* DEBT(REG) */
                s->hF2 = h4A;
            }
            s->hF4 = m->h4C;
            s->hF6 = 0;
            s->hF8 = 0;
            s->hFA = 0;
            {
                register s32 soff __asm__("$5") = *(s32 *)(m48 + 0x14); /* DEBT(REG) */
                BtlItemSlot *src = (BtlItemSlot *)(m48 + soff);
                dst = &((BtlItemSlot *)D_006625E0)[id];
                *dst = *src;
                c->pC48 = dst;
            }
            for (i = 0; i < 0x19; i++) {
                s->b101[i] = MsCheckRange(s->b101[i] + m2F[i], 0, 0xFF);
            }
            s->h11A = m->h4E;
            s->h186 = m->h70;
            s->b194 = s->b193 = s->h188 = 0xFF;
            s->b82 = m->b76;
            s->b83 = 0;
        }
        s->h1D2 = 0xFF;
        s->f1CC = 1.0f;
        MsSetChrImageDamageAttack(c);
        cnt = 0;
        {
            register u16 cmd0 __asm__("$2") = 0x3001; /* DEBT(REG) */
            ((u16 *)((u8 *)btl_ply_win + id * 0x478))[cnt++] = cmd0;
        }
        {
            int j;
            for (j = 0; j < 16; j++) {
                if (cnt < 0x14 && m->h50[j] != 0) {
                    ((u16 *)((u8 *)btl_ply_win + id * 0x478))[cnt++] = m->h50[j];
                }
            }
        }
        for (; cnt < 0x14; cnt++) {
            ((u16 *)((u8 *)btl_ply_win + id * 0x478))[cnt] = 0xFF;
        }
        if (GS_EX->b4E != 0) {
            s->w90 = 1;
        }
    }
    MsSetEternalRelife((BtlChr *)c);
    MsSetChrWeak(id, -1);
    MsSetAutoStatus((BtlChr *)c);
    if (s->w90 <= 0 || (((BtlChr *)c)->f2C6 & 1)) {
        register u16 f __asm__("$2") = ((BtlChr *)c)->f2C6 | 1; /* DEBT(REG) */
        register s8 v2 __asm__("$3") = 2; /* DEBT(REG) */
        ((BtlChr *)c)->f2C6 = f;
        c->bA8C = v2;
    }
}

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
