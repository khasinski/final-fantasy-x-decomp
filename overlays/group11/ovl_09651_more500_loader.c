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

extern HandlePool D_00703E20;
extern s8 D_007649A0;
extern HwRegs2008250 D_2008250;

extern Oef2Res D_01B0D200;
extern u8 D_01C394F0[];

void _pppAllFreePObject(Slot80 *s);
void _pppStartPart(Slot80 *s, int a, void *b, int c);
int _pppInitData(void *c, void *d);
void pppInitEnv(HeapMgrV *m, int a, int b, int c);
int _pppRunPart(Slot80 *s, int b);
OvlR6Obj *opu_init(int a, void *b, Oef2Res *c, void *d, int e, int f, int g);
void opu_test_data_read(int a);
void op_oef2_set2(Oef2Res *a);
void *op_oef2_a_get(Oef2Res *a, int b, int c);


void func_01B00B48(OvlR6Obj *);
void func_002B4630(Oef2Res *, void *);
extern u8 D_01B787B0[];
void func_01B01588(int a)
{
    HwRegs2008250 *hw = &D_2008250;
    void *end = D_01C394F0;
    Oef2Res *h;

    if (D_007649A0 == 0) {
        (&D_00703E20)->ovl = &D_01B0D200;
    } else if (hw->h40 & 0x10) {
        (&D_00703E20)->ovl = hw->wA8;
    } else {
        (&D_00703E20)->ovl = &D_01B0D200;
    }
    h = (&D_00703E20)->ovl;
    op_oef2_set2(h);
    func_002B4630(h, D_01B787B0);
    func_01B00B48(opu_init(1, op_oef2_a_get(h, 1, 0), h, end, 0x200, 0, a));
}
