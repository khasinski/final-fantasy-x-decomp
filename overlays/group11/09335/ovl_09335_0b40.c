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
    u8 pad00[0x54];
    int w54;
    int w58;
} OvlR6Obj;

extern int D_003F3944;
extern OvlR6Obj *D_0054D5E8[];
extern HeapMgrV *D_006A3924;

extern char D_01B085B8[];
extern int D_01B087D0[64];
extern Slot80 D_01B088D0[64];
extern HeapMgrV D_01B0A8D0;

extern void _pppAllFreePObject(Slot80 *s);
extern void _pppStartPart(Slot80 *s, int a, void *b, int c);
extern int _pppRunPart(Slot80 *s, int b);
extern void func_00294CD8(int a, int b);
extern void func_002EA328(int a) __attribute__((noreturn));
extern void func_002EF240(char *fmt, ...);

void func_01B00B40(void)
{
    OvlR6Obj *o = D_0054D5E8[1];

    (void)*(volatile u32 *)0x10000000;
    if (o->w58 == 0) {
        o->w54 = D_003F3944;
    }
    func_00294CD8(1, 2);
    if (o->w58 == 0) {
        D_003F3944 = o->w54;
    }
}

void func_01B00BA0(V6HeapOwner *o)
{
    HeapCfg *c;
    s16 i;
    int key;

    c = o->u.cfg;
    D_01B0A8D0.w20 = c->w14;
    D_01B0A8D0.tbl = c->tbl;
    D_01B0A8D0.p28 = c->p1C;
    D_006A3924 = &D_01B0A8D0;
    key = (o->b1E << 16) + o->h1A;
    for (i = 0; i < 64; i++) {
        if (D_01B087D0[i] == key) {
            goto found;
        }
    }
    for (i = 0; i < 64; i++) {
        if (D_01B087D0[i] == 0) {
            goto alloc;
        }
    }
    func_002EF240(D_01B085B8);
    func_002EA328(1);
found:
    D_006A3924 = &D_01B0A8D0;
    _pppAllFreePObject(&D_01B088D0[i]);
alloc:
    D_006A3924 = &D_01B0A8D0;
    D_01B087D0[i] = key;
    o->slot = &D_01B088D0[i];
    _pppStartPart(&D_01B088D0[i], 0x1000, o->u.cfg->p10[o->bD4], 1);
}

int func_01B00D38(V6HeapOwner *o)
{
    Slot80 *s = o->slot;
    HeapCfg *c = o->u.cfg;
    HeapMgrV *m = &D_01B0A8D0;
    int r;

    D_006A3924 = m;
    m->w20 = c->w14;
    m->tbl = c->tbl;
    m->p28 = c->p1C;
    r = _pppRunPart(s, 0x30);
    if (r != 0) {
        D_006A3924 = m;
        D_01B087D0[s->h1E] = 0;
        _pppAllFreePObject(s);
    }
    return r;
}
