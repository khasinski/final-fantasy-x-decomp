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

typedef struct OvlR6Obj {
    u8 pad00[0x0C];
    void *p0C;
    u8 pad10[0x40];
    void *vt50;
} OvlR6Obj;

typedef struct HwRegs2008250 {
    u8 pad00[0x40];
    u16 h40;
} HwRegs2008250;

extern s8 D_007649A0;
extern HwRegs2008250 D_2008250;

extern u8 D_01B00000[];
extern void *D_01B0A580[64];
extern int D_01B0A780[64];
extern Slot80 D_01B0A880[64];
extern HeapMgrV D_01B0C880;

extern void opu_test_data_read(int a);
extern void *func_002EF0D0(void *dst, int val, int size);

void ovl_09754_0848(OvlR6Obj *o)
{
    Slot80 *s;
    int i;

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
    s = D_01B0A880;
    for (i = 0; i < 64; i++) {
        func_002EF0D0(s, 0, sizeof(Slot80));
        s->h1E = i;
        s++;
        D_01B0A780[i] = 0;
    }
    for (i = 63; i >= 0; i--) {
        D_01B0A580[i] = 0;
    }
    func_002EF0D0(&D_01B0C880, 0, sizeof(HeapMgrV));
    o->p0C = (char *)o + 0x21200;
}
