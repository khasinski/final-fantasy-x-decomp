#include "common.h"

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

extern Oef2Res D_01B0D110;
extern u8 D_01C54610[];
extern u8 D_01BAB4F0[];

OvlR6Obj *opu_init(int a, void *b, Oef2Res *c, void *d, int e, int f, int g);
void op_oef2_set2(Oef2Res *a);
void *op_oef2_a_get(Oef2Res *a, int b, int c);
void func_01B00A58(OvlR6Obj *);
void func_002B4630(Oef2Res *, void *);

void func_01B01498(int a)
{
    HwRegs2008250 *hw = &D_2008250;
    void *end = D_01C54610;
    Oef2Res *h;
    void *p;

    if (D_007649A0 == 0) {
        (&D_00703E20)->ovl = &D_01B0D110;
    } else if (hw->h40 & 0x10) {
        (&D_00703E20)->ovl = hw->wA8;
    } else {
        (&D_00703E20)->ovl = &D_01B0D110;
    }
    h = (&D_00703E20)->ovl;
    op_oef2_set2(h);
    p = op_oef2_a_get(h, 1, 0);
    func_002B4630(h, D_01BAB4F0);
    func_01B00A58(opu_init(1, p, h, end, 0x200, 0, a));
}
