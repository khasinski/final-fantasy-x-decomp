#include "common.h"

typedef struct HeapCfg {
    u8 pad0[0x14];
    int w14;
    void *tbl;
    char *p1C;
} HeapCfg;

typedef struct HeapMgrV {
    u8 pad00[0x20];
    int w20;
    void *tbl;
    char *p28;
} HeapMgrV;

typedef struct V6HeapOwner {
    u8 pad00[0xD0];
    union {
        HeapCfg *cfg;
    } u;
} V6HeapOwner;

typedef struct Oef2Res {
    u8 pad00[0x50];
    u16 h50;
} Oef2Res;

typedef struct HandlePool {
    int cur;
    Oef2Res *ovl;
} HandlePool;

typedef struct HwRegs2008250 {
    u8 pad00[0xA8];
    Oef2Res *wA8;
} HwRegs2008250;

extern HeapMgrV *D_006A3924;
extern HandlePool D_00703E20;
extern s8 D_007649A0;
extern HwRegs2008250 D_2008250;

extern void *D_01B005F8[];
extern void *D_01B085D0[64];
extern HeapMgrV D_01B0A8D0;
extern Oef2Res D_01B0AE90;
extern u8 D_01BB0930[];

extern int _pppInitData(void *c, void *d);
extern void *opu_init(int a, void *b, Oef2Res *c, void *d, int e, int f, int g);
extern void op_oef2_set2(Oef2Res *a);
extern void *op_oef2_a_get(Oef2Res *a, int b, int c);
extern void func_01B00818(void *);
extern int func_01B011C0(void *);

void func_01B01240(int a)
{
    HwRegs2008250 *hw = &D_2008250;
    void *end = D_01BB0930;
    Oef2Res *h;

    if (D_007649A0 != 0) {
        (&D_00703E20)->ovl = hw->wA8;
    } else {
        (&D_00703E20)->ovl = &D_01B0AE90;
    }
    h = (&D_00703E20)->ovl;
    op_oef2_set2(h);
    func_01B00818(opu_init(1, op_oef2_a_get(h, 1, 0), h, end, 0x200, 0, a));
}

int func_01B012F8(V6HeapOwner *o)
{
    HeapCfg *c;
    int i;

    c = o->u.cfg;
    D_01B0A8D0.w20 = c->w14;
    D_01B0A8D0.tbl = c->tbl;
    D_01B0A8D0.p28 = c->p1C;
    D_006A3924 = &D_01B0A8D0;
    i = func_01B011C0(o->u.cfg);
    if (i >= 0 && D_01B085D0[i] == 0) {
        D_01B085D0[i] = o->u.cfg;
        return _pppInitData(o->u.cfg, D_01B005F8[i]);
    }
}

void func_01B01390(void)
{
}
