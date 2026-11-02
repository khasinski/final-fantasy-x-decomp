/* tu_069 0x138588-0x13a5d8: low; ~Atel (config/tu_map.tsv) */
#include "common.h"
#include "ffx/q1.h"
#include "ffx/r0.h"
#include "ffx/u0.h"
#include "ffx/v0.h"

void func_00138588(void) {
    D_0058E440 = 0;
}

u32 func_00138598(void) {
    return D_0058E440;
}

void func_001385A8(int bit, int on) {
    if (bit < 8) {
        if (on) {
            D_0058E440 |= 1 << bit;
        } else {
            D_0058E440 &= ~(1 << bit);
        }
    }
}

void func_001385F8(void) {
    int i;

    D_0058E488 = 0;
    for (i = 0; i < 16; i++) {
        D_0058E488 |= D_0058E448[i];
    }
}

u32 func_00138638(void) {
    return D_0058E488;
}

void func_00138648(int id)
{
    if (id < 0x200) {
        D_0058E448[id / 32] |= 1 << (id % 32);
        func_001385F8();
    }
}

void func_001386A0(int id)
{
    if (id < 0x200) {
        D_0058E448[id / 32] &= ~(1 << (id % 32));
        func_001385F8();
    }
}

void func_00138700(void) {
    int i;

    for (i = 15; i >= 0; i--) {
        D_0058E448[i] = 0;
    }
    func_001385F8();
}

int func_00138738(void) {
    int n = D_00325A34;

    n += D_003258F4;
    n += D_00326404;
    n += D_00325A94;
    n += D_0032586C;
    n += D_00325ABC;
    n += D_00325D54;
    n += D_00326024;
    n += D_0032605C;
    n += D_00326164;
    n += D_0032631C;
    return n;
}

char *func_001387C0(void) {
    return D_0056A688;
}

void func_001387D0(int a, int b, int c) {
    D_0058E434 = a;
    D_0058E438 = b;
    D_0058E43C = c;
}

void func_001387F0(void) {
    D_0058E940 = 0;
}

void func_00138800(int a, int b) {
    int i = D_0058E940;

    D_0058E948[i] = a;
    D_0058E968[i] = b;
    D_0058E940 = i + 1;
}

void func_00138838(void) {
    int i;

    for (i = 0; i < D_0058E940; i++) {
        SndSepVolumeFadeOut(D_0058E948[i], D_0058E968[i]);
    }
    func_001387F0();
}

void AtelBindEff2On(Actor *a, int mode) {
    CALL_op_et_bindeff2(AQ(a)->ptr9C);
    func_00299820(AQ(a)->ptr9C);
    switch (mode) {
    case 0:
        op_et_bindeff2_walk_on(AQ(a)->ptr9C);
        AQ(a)->w38 |= 0x20;
        break;
    case 1:
        func_00299A00(AQ(a)->ptr9C);
        AQ(a)->w38 |= 0x40;
        break;
    case 2:
        func_00299A90(AQ(a)->ptr9C);
        AQ(a)->w38 |= 0x80;
        break;
    }
}

void func_00138970(Actor *a, int mode) {
    switch (mode) {
    case 0:
        func_00299928(AQ(a)->ptr9C);
        AQ(a)->w38 &= ~0x20;
        break;
    case 1:
        func_002999B8(AQ(a)->ptr9C);
        AQ(a)->w38 &= ~0x40;
        break;
    case 2:
        func_00299A48(AQ(a)->ptr9C);
        AQ(a)->w38 &= ~0x80;
        break;
    }
    if ((ACTOR_BITS38(a)->b5 | ACTOR_BITS38(a)->b6 | ACTOR_BITS38(a)->b7) == 0) {
        func_00299840(AQ(a)->ptr9C);
        func_002996E0(AQ(a)->ptr9C);
    }
}

void func_00138A48(void) {
    D_0058E424 = 0;
}

void func_00138A58(int bit) {
    D_0058E424 |= 1 << bit;
}

void func_00138A78(int bit) {
    D_0058E424 &= ~(1 << bit);
}

u32 func_00138A98(void) {
    return D_0058E424;
}

void func_00138AA8(void)
{
    Rec124828 *r = CALL0_func_00124828();
    u32 limit;
    int v;

    D_0058E93C++;
    limit = func_002D9868() ? 50 : 60;
    if (D_0058E93C >= limit) {
        v = r->vBC;
        if (v < 0) {
            r->vBC = 0;
        } else if (v < 0x36EE7F) {
            v++;
            r->vBC = v;
        } else {
            r->vBC = 0x36EE7F;
        }
        D_0058E93C = 0;
    }
}

void func_00138B40(void (*a)(void), void (*b)(void)) {
    D_0058E934 = a;
    D_0058E938 = b;
}

void func_00138B58(void) {
    if (D_0058E934 != 0) {
        D_0058E934();
    }
}

void func_00138B80(void) {
    if (D_0058E938 != 0) {
        D_0058E938();
    }
}

int MsBattleCheck(void) {
    return func_001AEB80();
}

int func_00138BC8(void) {
    return D_0058E931;
}

void func_00138BD8(int v) {
    D_0058E931 = v;
}

int func_00138BE8(void) {
    return D_0058E408;
}

void func_00138BF8(int v) {
    D_0058E408 = v;
}

void func_00138C08(void) {
    D_0058E932 = 0;
}

void func_00138C18(int bit) {
    D_0058E932 &= ~(1 << bit);
}

void func_00138C38(int bit) {
    D_0058E932 |= 1 << bit;
}

int func_00138C58(void) {
    return D_0058E932 | 1;
}

int func_00138C68(void) {
    return D_0058E930;
}

void func_00138C78(int v) {
    D_0058E930 = v;
}

float func_00138C88(void) {
    return 1.0f;
}

int func_00138C98(int bit) {
    Rec124828 *r = func_00124828();
    int i = bit / 32;

    bit -= i * 32;
    if (i >= 2) {
        return 0;
    }
    r->w18[i] |= 1 << bit;
    return 1;
}

int func_00138D10(int n) {
    int *w = (int *)(REC124828_BASE() + 0x18);

    return (w[n / 32] >> n) & 1;
}

Fmt138 *func_00138D60(char *p) {
    int off = *(int *)(p + 0x2C);

    return off ? (Fmt138 *)(p + off) : 0;
}

Sub138 *func_00138D78(char *p) {
    Sub138 *r = 0;
    Fmt138 *q = func_00138D60(p);

    if (q != 0) {
        if (q->w3C != 0) {
            r = (Sub138 *)(p + q->w3C);
        }
    }
    return r;
}

int AtelGetBinHdrExpandAddChr(char *p) {
    Fmt138 *q = func_00138D60(p);
    int v = 0;

    if (q != 0) {
        v = q->w4;
    }
    return v;
}

int func_00138DF0(char *p) {
    Fmt138 *q = func_00138D60(p);
    int v = 0;

    if (q != 0) {
        v = q->w38;
    }
    return v;
}

char *func_00138E20(char *p) {
    Fmt138 *q = func_00138D60(p);

    if (q == 0) {
        return 0;
    }
    return q->w2C ? p + q->w2C : 0;
}

int func_00138E60(char *p) {
    Fmt138 *q = func_00138D60(p);
    int v = 0;

    if (q != 0) {
        v = q->w8;
    }
    return v;
}

int func_00138E90(char *p) {
    Fmt138 *f = func_00138D60(p);

    return f ? (f->wC ? *(int *)(p + f->wC) : 0) : 0;
}

int func_00138ED8(char *p, int i) {
    Fmt138 *f = func_00138D60(p);

    return f ? (f->wC ? ((U0Tbl *)(p + f->wC))->e[i].a : 0) : 0;
}

int func_00138F30(char *p, int i) {
    Fmt138 *f = func_00138D60(p);

    return f ? (f->wC ? ((U0Tbl *)(p + f->wC))->e[i].b : 0) : 0;
}

char *func_00138F88(char *p) {
    Fmt138 *q = func_00138D60(p);

    if (q != 0) {
        if (q->w10 != 0) {
            return p + q->w10;
        }
    }
    return D_0056A6A0;
}

float func_00138FC8(char *p) {
    Fmt138 *q = func_00138D60(p);

    if (q != 0) {
        return q->f14;
    }
    return 0.0f;
}

float func_00138FF0(char *p, int i) {
    Sub138 *r = func_00138D78(p);

    if (r == 0) {
        return func_00138FC8(p);
    }
    return r->f44[i];
}

char *func_00139048(char *p) {
    Sub138 *r = func_00138D78(p);
    char *v = 0;

    if (r != 0) {
        v = p + r->w8;
    }
    return v;
}

int func_00139080(char *p) {
    Fmt138 *f = func_00138D60(p);

    return f ? (f->w18 ? *(int *)(p + f->w18) : 0) : 0;
}

int func_001390C8(char *p, int i) {
    Fmt138 *f = func_00138D60(p);

    return f ? (f->w18 ? ((U0TblH *)(p + f->w18))->e[i].h : 0) : 0;
}

int func_00139120(char *p, int i) {
    Fmt138 *f = func_00138D60(p);

    return f ? (f->w18 ? ((U0TblH *)(p + f->w18))->e[i].a : 0) : 0;
}

char *func_00139178(char *p, int kind, int i) {
    Fmt138 *q = func_00138D60(p);
    char *r = 0;

    if (q != 0) {
        switch (kind) {
        case 0:
            kind = q->w1C;
            break;
        case 1:
            kind = q->w20;
            break;
        case 2:
            kind = q->w30;
            break;
        case 3:
            kind = q->w34;
            break;
        }
        if (kind != 0) {
            u16 *t = (u16 *)(p + kind);
            u16 *e = t + i;
            int h = *e;

            r = (char *)t + h;
            if (h == 0) {
                r = 0;
            }
        }
    }
    return r;
}

char *func_00139228(char *p) {
    Fmt138 *q = func_00138D60(p);
    char *r = 0;

    if (q != 0) {
        if (q->w24 != 0) {
            r = p + q->w24;
        }
    }
    return r;
}

int func_00139268(char *p) {
    int *x = (int *)func_00139228(p);
    int v = 0;

    if (x != 0) {
        v = *x;
    }
    return v;
}

int func_00139298(char *t, int key, int key2) {
    if (key == D_0058E40C && key == D_0058E410) {
        return D_0058E414;
    }
    return -1;
}

char *func_001392C8(char *p) {
    Sub138 *s = func_00138D78(p);
    char *r = 0;

    if (s != 0) {
        if (s->w4 != 0) {
            r = p + s->w4;
        }
    }
    return r;
}

INCLUDE_ASM("build/ee_asm/game/atel/atel_138588", func_00139308);

char *func_00139400(char *p) {
    Fmt138 *q = func_00138D60(p);

    if (q != 0) {
        if (q->w28 != 0) {
            return p + q->w28;
        }
    }
    return D_0030B900;
}

INCLUDE_ASM("build/ee_asm/game/atel/atel_138588", func_00139440);

void func_001394E0(void) {
    int v = AtelChangeCurrentCtrl(0);

    if (D_0058E3D8->flags & 0x8000) {
        D_0058E3D8->flags &= ~0x8000;
        func_0019CD00();
    }
    AtelSetCurrentCtrl(v);
}

void func_00139538(void) {
    int v = AtelChangeCurrentCtrl(0);

    if ((D_0058E3D8->flags & 0x8000) == 0) {
        D_0058E3D8->flags |= 0x8000;
        func_0019CCF8();
    }
    AtelSetCurrentCtrl(v);
}

void func_00139588(void) {
    func_00139538();
    func_0019CD70(0);
}

INCLUDE_ASM("build/ee_asm/game/atel/atel_138588", func_001395A8);

void func_00139700(int a, int b, int c) {
    if (a > 0) {
        if (c != 0) {
            if (b != 0) {
                func_00172FC8(a, 0);
            } else {
                func_00172FC8(a, 0);
            }
        } else {
            if (b != 0) {
                func_00172F80(a, 0);
            } else {
                func_00172F80(a, 0);
            }
        }
    }
}

void func_00139748(int a) {
    TkSetEventJumpMapNo(a, 0);
    func_00139700(a, 0, 0);
}

void AtelMapLoadBtl(int a) {
    TkSetEventJumpMapNo(a, 0);
    func_00139700(a, 0, 1);
}

void AtelMapLoadNoCache(int a) {
    TkSetEventJumpMapNo(a, 0);
    func_00139700(a, 1, 0);
}

INCLUDE_ASM("build/ee_asm/game/atel/atel_138588", func_001397F0);

void func_00139A00(char *p, int b) {
    func_001397F0(p, b, -1);
}

void func_00139A08(char *p) {
    func_002D64A0((int)func_00138E20(p)); /* DEBT(CAST): pointer passed as handle */
}

void AtelEventSetUpSep(int a, int b, int c) {
    int v = AtelChangeCurrentCtrl(0);

    if (c == 1) {
        D_0058E3D8->w204 = b;
    }
    func_00149080(a, b, c, -1, 0);
    SndSyncTrans(1);
    AtelSetCurrentCtrl(v);
    func_00136430(0.0f);
    func_00136440(0.016666668f);
}

void AtelEventRemoveSep(int a) {
    int v;

    SndStopStream();
    v = AtelChangeCurrentCtrl(0);
    if (D_0058E3D8->p48 != 0) {
        func_00139A00(D_0058E3D8->p48, a);
        AtelSetCurrentCtrl(v);
    }
}

int func_00139B30(int n) {
    if (*(u8 *)(REC124828_BASE() + 0x28) != 0) {
        n = n / 2;
    }
    return n;
}

INCLUDE_ASM("build/ee_asm/game/atel/atel_138588", AtelEventKickBGSep);

INCLUDE_ASM("build/ee_asm/game/atel/atel_138588", func_00139D48);

void func_00139E98(int a, int b) {
    func_00139D48(a, b, 0);
}

void func_00139EA0(void) {
    int v = CALL0_AtelChangeCurrentCtrl();

    D_0058E3D8->w204 = 0;
    AtelSetCurrentCtrl(v);
}

INCLUDE_ASM("build/ee_asm/game/atel/atel_138588", AtelGetMapIndex);

int func_00139FC8(int n) {
    return (n << 1) | 1;
}

int func_00139FD8(int n) {
    return n << 1;
}

int func_00139FE0(int v) { /* DEBT(TYPE): funcs.h declares int, but no value is returned */
    *(u8 *)(REC124828_BASE() + 0x12) = v;
}

int func_0013A008(int v) { /* DEBT(TYPE): funcs.h declares int, but no value is returned */
    *(u8 *)(REC124828_BASE() + 0x11) = v;
}

int func_0013A030(void) {
    return *(u8 *)(REC124828_BASE() + 0x12);
}

int func_0013A050(void) {
    return *(u8 *)(REC124828_BASE() + 0x11);
}

void AtelSetEventJump2(int a, int b, int c) {
    int s;

    if (EVW()->flags & 0x80) {
        AtelUcOff();
        func_00124CC8(a, b);
        func_00138B58();
        MsBattleExeClear();
        EVW()->flags &= ~0x80;
        EVW()->w210 |= 2;
        func_00136440(-0.06666667f);
        if (c != 0) {
            s = func_0013A030();
            func_00124848(s);
            switch (func_0013A050()) {
            case 0:
                func_00117E18(s);
                break;
            case 1:
                func_00117E08(s);
                break;
            }
        } else {
            func_00124848(0);
        }
    }
}

void func_0013A1B0(int a, int b) {
    AtelSetEventJump2(a, b, 0);
}

int func_0013A1B8(void) {
    return func_00124BC8();
}

int func_0013A1D8(void) {
    return func_00124BE8();
}

int func_0013A1F8(void) {
    return func_00124C08();
}

int func_0013A218(void) {
    return func_00124C28();
}

int func_0013A238(void) {
    return func_00124C48();
}

int func_0013A258(void) {
    return func_00124CA8();
}

int func_0013A278(void) {
    return TkGetNowEventJumpMapNo();
}

int func_0013A298(void) {
    return func_00124C88();
}

void func_0013A2B8(int a) {
    TkSetEventJumpMapNo(a, func_00124C88());
}

char *func_0013A2E8(char *p, int k) {
    int base = *(int *)(p + 4);
    int end = *(int *)(p + 8);
    char *r;

    if (k < 0) {
        k = func_0013A258();
    }
    k = k * 32;
    if (base != 0) {
        k += base;
        if (!(k < end)) {
            k = base;
        }
        r = p + k;
    } else {
        r = D_0030B908;
    }
    return r;
}

INCLUDE_ASM("build/ee_asm/game/atel/atel_138588", func_0013A358);

CamInfo *func_0013A378(Actor *a, int id) {
    return (CamInfo *)func_0013A2E8(*(char **)((char *)a + 4), id); /* DEBT(CAST): word at Actor+4 is the blob pointer */
}

int func_0013A398(int id) { /* DEBT(TYPE): id is unused by the original too */
    return MsGetSaveConfigHiragana();
}

INCLUDE_ASM("build/ee_asm/game/atel/atel_138588", func_0013A3B8);

char *func_0013A468(char *p) {
    return p + 0x3C;
}

char *func_0013A470(void) {
    return (char *)CALL0_AtelGetBasicWork() + 0x3C;
}

int func_0013A490(int id) {
    Actor *a = AtelGetBasicWork(id);
    int v = (*(u32 *)&a->flags34 >> 10) & 7; /* DEBT(CAST): 3-bit field at bit 10 of the flag word */
    int n;

    if (v >= 0) {
        if (v > 5) {
            n = 5;
        } else {
            n = v;
        }
    } else {
        n = 0;
    }
    return n;
}

int func_0013A4D8(const u8 *s) {
    int n = 0;

    while (*s++ != 0) {
        n++;
    }
    return n;
}

void func_0013A510(u8 *d, const u8 *s) {
    u8 c = *s++;

    while (*d++ != 0) {
    }
    d--;
    for (;;) {
        *d++ = c;
        if (c == 0) {
            break;
        }
        c = *s++;
    }
}

void func_0013A568(u8 *d, const u8 *s) {
    d[0] = 0;
    func_0013A510(d, s);
}

EvGameState *AtelGetCurCtrlWork(void) {
    return (EvGameState *)D_0058E3D8; /* DEBT(CAST): same block seen through Sys3D8 */
}

void *AtelGetCtrlWork(int i) {
    return &D_0058D450[i];
}

int AtelSetCurrentCtrl(int a) {
    int old = (int)D_0058E3D8; /* DEBT(CAST): callers keep the block as an int */

    D_0058E3D8 = (Sys3D8 *)a;
    return old;
}

int AtelChangeCurrentCtrl(int a) {
    return AtelSetCurrentCtrl((int)AtelGetCtrlWork(a));
}
