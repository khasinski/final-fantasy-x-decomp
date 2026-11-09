/* tu_189 0x1bb380-0x1bc440: low; ~Ms (config/tu_map.tsv) */
#include "common.h"
#include "ffx/s3.h"
#include "ffx/q4.h"
#define MsGetDamageInfo _hdr_MsGetDamageInfo
#include "ffx/r3.h"
#undef MsGetDamageInfo
#include "ffx/u2.h"
#include "ffx/v3.h"

int MsGetDamageInfo(int a, int b, int *outA, int *outB, int *outC);

int func_001BB380(int a, int b) {
    int v[3];
    int m;
    MsGetDamageInfo(a, b, &v[0], &v[1], &v[2]);
    m = v[0];
    if (ABS(v[0]) < ABS(v[1])) {
        m = v[1];
    }
    if (ABS(m) < ABS(v[2])) {
        m = v[2];
    }
    return m;
}

int MsGetDamageInfo(int a, int b, int *outA, int *outB, int *outC) {
    u8 id = a;
    int n = 0;
    int z = 0;
    int y = 0;
    int x = 0;

    if (MsBtlChrNumCheck(id)) {
        int sub = MsGetChrCommand(id)->f2;
        Obj436 *o = (Obj436 *)MsGetChr(b);
        int i;
        for (i = 0; i < 2; i++) {
            struct Obj436Slot *s = &o->slot[i];
            int k;
            if (s->v != id || s->sub != sub) {
                continue;
            }
            n += s->count - s->first;
            for (k = s->first; k < s->count; k++) {
                x += s->ent[k].w20;
                y += s->ent[k].w24;
                z += s->ent[k].w28;
            }
        }
    }
    if (outA) {
        *outA = x;
    }
    if (outB) {
        *outB = y;
    }
    if (outC) {
        *outC = z;
    }
    return n;
}

int MsMergeDamage(int a, int b) {
    u8 id = a;
    int n = 0;
    int sub;
    Obj436 *o;
    struct Obj436Slot *s;
    Obj436Ent acc;
    Obj436Ent *e;
    int i;
    int k;
    int f;

    if (MsBtlChrNumCheck(id)) {
        sub = MsGetChrCommand(id)->f2;
        o = (Obj436 *)MsGetChr(b); /* DEBT(CAST): the slot area of the BtlChr record */
        for (i = 0; i < 2; i++) {
            s = &o->slot[i];
            if (s->v != id || s->sub != sub) {
                continue;
            }
            acc = s->ent[s->count - 1];
            acc.b2 = 0;
            acc.b4 = 0;
            acc.h18 = 0;
            acc.h1A = 0;
            acc.w1C = 0;
            acc.w20 = 0;
            acc.w24 = 0;
            acc.w28 = 0;
            f = 1;
            for (k = s->first; k < s->count; k++) {
                e = &s->ent[k];
                acc.b2 |= e->b2;
                acc.b4 |= e->b4;
                acc.w1C += e->w1C;
                acc.h18 |= e->h18;
                acc.w20 += e->w20;
                acc.h1A |= e->h1A;
                acc.w24 += e->w24;
                acc.w28 += e->w28;
                n++;
                if (e->b1 == 0 && f == 1) {
                    f = 0;
                }
                if (e->b1 == 2) {
                    f = 2;
                }
            }
            acc.b1 = f;
            s->ent[s->first] = acc;
            s->count = s->first + 1;
        }
    }
    return n;
}

int func_001BB7F8(int a, int b, int *outA, int *outB, int *outC) {
    u8 id = a;
    int n = 0;
    int z = 0;
    int y = 0;
    int x = 0;

    if (MsBtlChrNumCheck(id)) {
        int sub = MsGetChrCommand(id)->f2;
        Obj436 *o = (Obj436 *)MsGetChr(b);
        int i;
        for (i = 0; i < 2; i++) {
            struct Obj436Slot *s = &o->slot[i];
            int k;
            if (s->v != id || s->sub != sub) {
                continue;
            }
            k = s->first;
            n += s->count - k;
            x += s->ent[k].w20;
            y += s->ent[k].w24;
            z += s->ent[k].w28;
        }
    }
    if (outA) {
        *outA = x;
    }
    if (outB) {
        *outB = y;
    }
    if (outC) {
        *outC = z;
    }
    return n;
}

INCLUDE_ASM("build/ee_asm/game/battle/ms_1BB380", func_001BB930);

int MsGetDamageResult(int a, int b, int *outA, int *outB, int *outC) {
    u8 id = a;
    int x = 0;
    int y = 0;
    int n = 0;
    int r = 0;
    int sub;
    int i;
    int k;
    struct Obj436Slot *s;
    Obj436Ent *e;

    if (MsBtlChrNumCheck(id)) {
        sub = MsGetChrCommand(id)->f2;
        s = ((Obj436 *)MsGetChr(b))->slot; /* DEBT(CAST): the slot area of the BtlChr record */
        for (i = 0; i < 2; i++, s++) {
            if (s->v != id || s->sub != sub) {
                continue;
            }
            k = s->first;
            if (k >= s->count) {
                k = s->count - 1;
            } else {
                n++;
            }
            y = s->ent[k].h1A;
            r = s->ent[k].b0;
            x = s->ent[k].b2;
        }
    }
    if (outA) {
        *outA = y;
    }
    if (outC) {
        *outC = n;
    }
    if (outB) {
        *outB = x;
    }
    return r;
}

int MsGetDamageLimit(int arg, int other) {
    u8 id = arg;
    int r = 0;
    if (MsBtlChrNumCheck(id) != 0) {
        u8 k = MsGetChrCommand(id)->f2;
        BtlChrRecs *c = (BtlChrRecs *)MsGetChr(other); /* DEBT(CAST): see BtlChrRecs */
        int i;
        for (i = 0; i < 2; i++) {
            BtlRec434 *e = &c->rec[i];
            if (e->b2 == id && e->b3 == k) {
                r = e->b15;
                break;
            }
        }
    }
    return r;
}

void func_001BBDC0(int *a, int *b, int *c) {
    if (a != 0) {
        *a = D_003192B5[0];
    }
    if (b != 0) {
        *b = D_003192B5[1];
    }
    if (c != 0) {
        *c = D_003192B5[2];
    }
}

OfsTbl *MsGetComData(int id, int *base) {
    OfsTbl *r = &D_00662580;
    int type = id >> 12;
    int full = id;

    id &= 0xFFF;
    switch (type) {
    case 0:
        if (base != 0) {
            *base = (int)func_001BB190(id);
        }
        break;
    case 2:
        r = MsGetRomItem(id, base);
        break;
    case 3:
        r = MsGetRomPlyCommand(id, base);
        break;
    case 4:
        r = MsGetRomMonCommand1(id, base);
        break;
    case 6:
        r = MsGetRomMonCommand2(id, base);
        break;
    case 5:
    case 7:
    case 11:
        if (base != 0) {
            *base = func_001C0040(full);
        }
        break;
    case 8:
        r = MsGetRomAbility(id, base);
        break;
    case 10:
        if (base != 0) {
            *base = MsImportantName(id);
        }
        break;
    }
    return r;
}

typedef struct {
    u8 pad0[0x2C6];
    u16 f2C6;
    u8 f2C8[10];
    u8 f2D2;
    u8 f2D3;
    u8 f2D4;
    u8 pad2D5;
    u16 f2D6;
    u16 f2D8;
    u8 f2DA[13];
    u8 pad2E7;
    u16 f2E8;
    u16 f2EA;
    u16 f2EC;
    u16 f2EE;
    u16 f2F0;
    u16 f2F2;
    u16 f2F4;
    u16 f2F6;
    u16 f2F8;
    u16 f2FA;
    u16 f2FC;
    u8 f2FE;
    u8 f2FF;
    u8 pad300[0x392 - 0x300];
    u8 f392;
} BtlChrAuto;

void MsSetAutoStatus(BtlChr *chr) {
    BtlChrAuto *c = (BtlChrAuto *)chr;
    u8 f2FE = c->f2FE;
    u8 f2D2 = c->f2D2;
    u8 f2D3 = c->f2D3;
    u16 m, m1, v, dst;
    int i;

    c->f2EA = c->f2F0;
    c->f2EC = c->f2F2;
    c->f2EE = c->f2F4;
    if ((u32)(f2FE - 1) < 2) {
        c->f2EA |= c->f2F6;
        c->f2EC |= c->f2F8;
        c->f2EE |= c->f2FA;
    }
    c->f2FF = f2FE;
    m = c->f2EA;
    v = c->f2C6;
    dst = c->f2D8;
    m1 = c->f2EC;
    for (i = 0; i < 12; i++) {
        if ((m >> i) & 1) {
            dst = (dst & ~(1 << i)) | (v & (1 << i));
            v |= 1 << i;
        }
    }
    c->f2C6 = v;
    c->f2D8 = dst;
    for (i = 0; i < 13; i++) {
        if ((m1 >> i) & 1) {
            c->f2DA[i] = c->f2C8[i];
            c->f2C8[i] = 0xFF;
        }
    }
    if (f2D3 == 0 && c->f2D3 != 0 && c->f2D4 < 0xFF) {
        c->f2D4 = 0;
    }
    m = c->f2EE;
    v = c->f2D6;
    dst = c->f2E8;
    for (i = 0; i < 16; i++) {
        if ((m >> i) & 1) {
            dst = (dst & ~(1 << i)) | (v & (1 << i));
            v |= 1 << i;
        }
    }
    c->f2D6 = v;
    c->f2E8 = dst;
    if (c->f2D2 != 0 && f2D2 == 0) {
        c->f392 = 0;
    }
}

void MsResetAutoStatus(BtlChr *c) {
    u16 m1 = c->f2EC;
    u16 m = c->f2EA;
    u16 v = c->f2C6;
    u16 src = c->f2D8;
    int i;
    for (i = 0; i < 12; i++) {
        if ((m >> i) & 1) {
            v = (v & ~(1 << i)) | (src & (1 << i));
        }
    }
    c->f2C6 = v;
    for (i = 0; i < 13; i++) {
        if ((m1 >> i) & 1) {
            (&c->f2C8)[i] = c->f2DA[i]; /* DEBT(TYPE): f2C8..f2D4 are one 13-byte array */
        }
    }
    m = c->f2EE;
    v = c->f2D6;
    src = c->f2E8;
    for (i = 0; i < 16; i++) {
        if ((m >> i) & 1) {
            v = (v & ~(1 << i)) | (src & (1 << i));
        }
    }
    c->f2D6 = v;
}

void func_001BC158(Rec2D8 *p) {
    int i;
    p->f2D8 = 0;
    for (i = 0; i < 13; i++) {
        p->f2DA[i] = 0;
    }
    p->f2E8 = 0;
}

u8 func_001BC190(int id) {
    return MsGetChr(id)->f282;
}

u8 func_001BC1B0(int id) {
    return MsGetChr(id)->f283;
}

int func_001BC1D0(u8 id) {
    return (MsGetChr(id)->flags278 >> 9) & 1;
}

int MsGetStatusThreat(int id) {
    int r = 0;
    BtlChr *c = MsGetChr(id);
    if ((c->f2C6 >> 11) & 1) {
        r = c->f286 == 0xFF;
    }
    return r;
}

OfsTbl *MsGetRomPlyCommand(int a, s32 *pos) {
    return MsGetExcelData(a & 0xFFF, D_0031734C, pos);
}

OfsTbl *MsGetRomMonCommand1(int a, s32 *pos) {
    return MsGetExcelData(a & 0xFFF, D_00317350, pos);
}

OfsTbl *MsGetRomMonCommand2(int a, s32 *pos) {
    return MsGetExcelData(a & 0xFFF, D_00317354, pos);
}

OfsTbl *MsGetRomItem(int a, s32 *pos) {
    return MsGetExcelData(a & 0xFFF, D_00317360, pos);
}

OfsTbl *MsGetRomAbility(int a, s32 *pos) {
    return MsGetExcelData(a & 0xFFF, D_00317364, pos);
}

u8 MsGetRomCTBcount(int a) {
    TblEnt *e = MsGetExcelData(MsCheckRange(a, 1, 255) - 1, D_0031736C, 0);

    return e->f0;
}

TblEnt *MsGetRomCTBbase(int a) {
    return MsGetExcelData(MsCheckRange(a, 1, 255) - 1, D_0031736C, 0);
}

int MsGetRomSummonGrow(s32 *out) {
    int v = MsGetExcelDataNum(D_003172F0.p90, 0);
    void *r = MsGetExcelData(0, D_003172F0.p90, 0);
    if (out != 0) {
        *out = v;
    }
    return (int)r; /* DEBT(TYPE): callers use the table entry pointer as int */
}

int MsGetRomKaizou(s32 *out) {
    int v = MsGetExcelDataNum(D_003172F0.p94, 0);
    void *r = MsGetExcelData(0, D_003172F0.p94, 0);
    if (out != 0) {
        *out = v;
    }
    return (int)r; /* DEBT(TYPE): callers use the table entry pointer as int */
}
