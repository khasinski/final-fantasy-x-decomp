#include "common.h"

typedef struct HBlk {
    struct HBlk *next;
    struct HBlk *prev;
    int used;
    int pad;
} HBlk;

typedef struct HHead {
    HBlk *cur;
    HBlk *first;
    HBlk *last;
    int used;
} HHead;

typedef struct HeapCfg {
    u8 pad0[0x10];
    void **p10;
    int w14;
    void *tbl;
    char *p1C;
} HeapCfg;

typedef struct HeapMgrV {
    HHead main;
    HHead sub;
    int w20;
    void *tbl;
    char *p28;
} HeapMgrV;

typedef struct Slot80 {
    u8 pad00[0x1E];
    u16 h1E;
    u8 pad20[0x60];
} Slot80;

typedef struct V6HeapOwner {
    u8 pad00[0x1A];
    u16 h1A;
    u8 pad1C[2];
    u8 b1E;
    u8 pad1F[0x9C];
    u8 bBB;
    Slot80 *slot;
    u8 padC0[0x10];
    union {
        HeapCfg *cfg;
    } u;
    u8 bD4;
} V6HeapOwner;

typedef struct OvlR6Obj {
    u8 pad00[0x0C];
    void *p0C;
    u8 pad10[0x40];
    void *vt50;
    int w54;
    int w58;
    u8 pad5C[0x44];
    int wA0;
    int wA4;
    u8 *pA8;
    int wAC;
    int wB0;
} OvlR6Obj;

typedef struct Oef2Res {
    u8 pad00[0x50];
    u16 h50;
} Oef2Res;

typedef struct W10Dual {
    u8 pad0[0x10];
    s8 mirror;
    s8 b11;
} W10Dual;

typedef struct HandlePool {
    int cur;
    Oef2Res *ovl;
} HandlePool;

typedef struct HwRegs2008250 {
    u8 pad00[0x40];
    u16 h40;
    u8 pad42[0x66];
    Oef2Res *wA8;
} HwRegs2008250;

extern int D_003F3944;
extern OvlR6Obj *D_0054D5E8[];
extern u16 D_00551C98;
extern u16 D_00551CA0;
extern u8 D_004F3FD0[];
extern u8 D_004F4010[];
extern HeapMgrV *D_006A3924;
extern HandlePool D_00703E20;
extern W10Dual D_00764990;
extern s8 D_007649A0;
extern HwRegs2008250 D_2008250;

extern u8 D_01B00000[];
extern void *D_01B00648[];
extern char *D_01B006A0[];
extern char D_01B0A578[];
extern char D_01B0A5A8[];
extern void *D_01B0A5C0[64];
extern void *D_01B0A6C0[64];
extern int D_01B0A7C0[64];
extern Slot80 D_01B0A8C0[64];
extern HeapMgrV D_01B0C8C0;
extern Oef2Res D_01B0F8D0;
extern u8 D_01B78720[];

void func_00120108(char *fmt, ...);
void func_001A9EE0(void *a);
void func_001AACA0(void *a);
void _pppAllFreePObject(Slot80 *s);
void _pppStartPart(Slot80 *s, int a, void *b, int c);
int _pppInitData(void *c, void *d);
void pppInitEnv(HeapMgrV *m, int a, int b, int c);
int _pppRunPart(Slot80 *s, int b);
int func_00293CD8(u8 *p);
void func_00293D48(HeapMgrV *a, int b);
void func_00294CD8(int a, int b);
OvlR6Obj *opu_init(int a, void *b, Oef2Res *c, void *d, int e, int f, int g);
void opu_test_data_read(int a);
void func_002AC750(int a);
void func_002B22F8(int a, int b);
void op_oef2_set2(Oef2Res *a);
void *op_oef2_a_get(Oef2Res *a, int b, int c);
void func_002EA328(int a) __attribute__((noreturn));
void *func_002EF0D0(void *dst, int val, int size);
void func_206C3B8(int a);
void func_206C3F8(int a, int b, int c);

void func_01B00ED0(int a);

void func_01B00878(OvlR6Obj *o)
{
    Slot80 *s;
    int i;

    func_002B22F8(0x3400, 0x800);
    if (D_007649A0 != 0) {
        HwRegs2008250 *hw = &D_2008250;

        if (hw->h40 & 0x10) {
            s16 saved = hw->h40;

            hw->h40 = 0x10;
            opu_test_data_read(1);
            hw->h40 = saved;
        }
    }
    o->vt50 = D_01B00000;
    s = D_01B0A8C0;
    for (i = 0; i < 64; i++) {
        func_002EF0D0(s, 0, sizeof(Slot80));
        s->h1E = i;
        s++;
        D_01B0A7C0[i] = 0;
    }
    for (i = 63; i >= 0; i--) {
        D_01B0A5C0[i] = 0;
    }
    func_002EF0D0(&D_01B0C8C0, 0, sizeof(HeapMgrV));
    o->p0C = (char *)o + 0x21200;
}

void func_01B009A0(void)
{
    W10Dual *d = &D_00764990;

    D_0054D5E8[1] = 0;
    d->b11 = 0;
    if (d->mirror != 0) {
        func_206C3B8(1);
        func_206C3B8(2);
        func_206C3B8(0x8003);
    }
}

void func_01B009F0(void)
{
}

void func_01B009F8(void)
{
    OvlR6Obj *o = D_0054D5E8[1];
    u16 t0 = *(volatile u32 *)0x10000000;

    if (o->w58 != 0) {
        o->w54 = o->w58;
    } else {
        o->w54 = D_003F3944;
    }
    func_00294CD8(1, 0);
    if (o->w58 == 0) {
        D_003F3944 = o->w54;
    } else if (o->w58 != o->w54) {
        func_00120108(D_01B0A578);
        func_002EA328(1);
    }
    D_00551C98 = *(volatile u32 *)0x10000000 - t0;
}

void func_01B00AA8(void)
{
    OvlR6Obj *o = D_0054D5E8[1];
    u16 t0 = *(volatile u32 *)0x10000000;

    if (o->w58 != 0) {
        o->w54 = o->w58;
    } else {
        o->w54 = D_003F3944;
    }
    func_001A9EE0(D_004F3FD0);
    func_001AACA0(D_004F4010);
    func_00294CD8(1, 1);
    func_002AC750(1);
    if (o->w58 == 0) {
        D_003F3944 = o->w54;
    }
    if (D_007649A0 != 0) {
        D_00551CA0 = *(volatile u32 *)0x10000000 - t0;
        if (o->wA0 != 0) {
            func_206C3F8(o->w54 - o->w58, o->wB0, 1);
            func_206C3F8(func_00293CD8(o->pA8), o->wAC, 2);
        }
    }
}

void func_01B00BA8(void)
{
}

void func_01B00BB0(void)
{
    OvlR6Obj *o = D_0054D5E8[1];

    (void)*(volatile u32 *)0x10000000;
    if (o != 0) {
        if (o->w58 == 0) {
            o->w54 = D_003F3944;
        }
        func_00294CD8(1, 2);
        if (o->w58 == 0) {
            D_003F3944 = o->w54;
        }
    }
}

void func_01B00C18(V6HeapOwner *o)
{
    HeapCfg *c;
    s16 i;
    int key;

    c = o->u.cfg;
    D_01B0C8C0.w20 = c->w14;
    D_01B0C8C0.tbl = c->tbl;
    D_01B0C8C0.p28 = c->p1C;
    D_006A3924 = &D_01B0C8C0;
    key = (o->b1E << 16) + o->h1A;
    for (i = 0; i < 64; i++) {
        if (D_01B0A7C0[i] == key) {
            goto found;
        }
    }
    for (i = 0; i < 64; i++) {
        if (D_01B0A7C0[i] == 0) {
            goto alloc;
        }
    }
    func_00120108(D_01B0A5A8);
    func_002EA328(1);
found:
    D_006A3924 = &D_01B0C8C0;
    _pppAllFreePObject(&D_01B0A8C0[i]);
alloc:
    D_006A3924 = &D_01B0C8C0;
    D_01B0A7C0[i] = key;
    o->slot = &D_01B0A8C0[i];
    _pppStartPart(&D_01B0A8C0[i], 0x1000, o->u.cfg->p10[o->bD4], 1);
}

int func_01B00DB0(V6HeapOwner *o)
{
    Slot80 *s = o->slot;
    HeapCfg *c = o->u.cfg;
    HeapMgrV *m = &D_01B0C8C0;
    int r;

    D_006A3924 = m;
    m->w20 = c->w14;
    m->tbl = c->tbl;
    m->p28 = c->p1C;
    r = _pppRunPart(s, 0x30);
    if (r != 0) {
        D_006A3924 = m;
        D_01B0A7C0[s->h1E] = 0;
        _pppAllFreePObject(s);
    }
    return r;
}

void func_01B00E50(void)
{
    int i;

    for (i = 0; i < 64; i++) {
        D_01B0A6C0[i] = D_01B0A5C0[i];
    }
    func_01B00ED0(0);
}

void func_01B00E90(void)
{
    int i;

    for (i = 0; i < 64; i++) {
        D_01B0A5C0[i] = D_01B0A6C0[i];
    }
}

void func_01B00ED0(int a)
{
    int i;
    int j;

    D_006A3924 = &D_01B0C8C0;
    for (i = 63; i >= 0; i--) {
        D_01B0A5C0[i] = 0;
    }
    for (j = 0; j < 64; j++) {
        if (D_01B0A7C0[j] != 0) {
            D_01B0A7C0[j] = 0;
            D_006A3924 = &D_01B0C8C0;
            _pppAllFreePObject(&D_01B0A8C0[j]);
        }
    }
}

int func_01B00F90(V6HeapOwner *o)
{
    Slot80 *s;

    if (o->bBB == 3) {
        s = o->slot;
        if (s != 0) {
            HeapMgrV *m = &D_01B0C8C0;

            D_006A3924 = m;
            _pppAllFreePObject(s);
            D_01B0A7C0[s->h1E] = 0;
            o->slot = 0;
            o->bBB = 0;
        }
    }
}

void func_01B01008(Oef2Res *res)
{
    int i;
    int j;
    void *p;

    for (i = 0; i < res->h50; i++) {
        p = op_oef2_a_get(res, 8, i);
        if (p != 0) {
            for (j = 0; j < 64; j++) {
                if (D_01B0A5C0[j] == p) {
                    D_01B0A5C0[j] = 0;
                }
            }
        }
    }
}

void func_01B010B0(OvlR6Obj *o)
{
    HeapMgrV *m = &D_01B0C8C0;

    if (m->w20 == 0) {
        pppInitEnv(m, 0, o->wA0, o->wA4);
        if (D_007649A0 != 0) {
            func_00293D48(m, 0x8003);
        }
    }
}

void func_01B01118(char *base, u16 *offs)
{
    char **dst = D_01B006A0;

    if (offs[2] != 0) {
        dst[2] = base + (offs[2] + 0xA0);
    }
    if (offs[3] != 0) {
        dst[3] = base + (offs[3] + 0xA0);
    }
    if (offs[4] != 0) {
        dst[4] = base + (offs[4] + 0xA0);
    }
    if (offs[5] != 0) {
        dst[5] = base + (offs[5] + 0xA0);
    }
    if (offs[6] != 0) {
        dst[6] = base + (offs[6] + 0xA0);
    }
    if (offs[7] != 0) {
        dst[7] = base + (offs[7] + 0xA0);
    }
    if (offs[8] != 0) {
        dst[8] = base + (offs[8] + 0xA0);
    }
    if (offs[9] != 0) {
        dst[9] = base + (offs[9] + 0xA0);
    }
    if (offs[10] != 0) {
        dst[10] = base + (offs[10] + 0xA0);
    }
    if (offs[11] != 0) {
        dst[11] = base + (offs[11] + 0xA0);
    }
    if (offs[12] != 0) {
        dst[12] = base + (offs[12] + 0xA0);
    }
    if (offs[13] != 0) {
        dst[13] = base + (offs[13] + 0xA0);
    }
    if (offs[14] != 0) {
        dst[14] = base + (offs[14] + 0xA0);
    }
}

void func_01B01230(void)
{
}

int func_01B01238(void *target)
{
    Oef2Res *res = D_00703E20.ovl;
    int i;

    if (res != 0) {
        for (i = 0; i < res->h50; i++) {
            if (op_oef2_a_get(res, 8, i) == target) {
                return i;
            }
        }
    }
    return -1;
}

void func_01B012B8(int a)
{
    HwRegs2008250 *hw = &D_2008250;
    void *end = D_01B78720;
    Oef2Res *h;

    if (D_007649A0 == 0) {
        (&D_00703E20)->ovl = &D_01B0F8D0;
    } else if (hw->h40 & 0x10) {
        (&D_00703E20)->ovl = hw->wA8;
    } else {
        (&D_00703E20)->ovl = &D_01B0F8D0;
    }
    h = (&D_00703E20)->ovl;
    op_oef2_set2(h);
    func_01B00878(opu_init(1, op_oef2_a_get(h, 1, 0), h, end, 0x200, 0, a));
}

int func_01B01380(V6HeapOwner *o)
{
    HeapCfg *c;
    int i;

    c = o->u.cfg;
    D_01B0C8C0.w20 = c->w14;
    D_01B0C8C0.tbl = c->tbl;
    D_01B0C8C0.p28 = c->p1C;
    D_006A3924 = &D_01B0C8C0;
    i = func_01B01238(o->u.cfg);
    if (i >= 0 && D_01B0A5C0[i] == 0) {
        D_01B0A5C0[i] = o->u.cfg;
        return _pppInitData(o->u.cfg, D_01B00648[i]);
    }
}

void func_01B01418(void)
{
}
