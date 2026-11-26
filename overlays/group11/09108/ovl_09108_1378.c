#include "common.h"

typedef struct {
    u8 pad00[0x54];
    int w54;
} Obj5420;

extern int D_01B001E8;
extern int D_01B00040[];
extern int D_01B00060[];
extern u8 D_01B00088[];
extern u8 D_01B053E8[];
extern u8 D_01B05410[];
extern Obj5420 D_01B05420;
extern void *D_01B05480;
extern int D_01B05484;
extern int D_01B05488;
extern int D_01B0548C;
extern u8 D_01B0B510[];
extern u8 D_01B0B6C0[];

extern int func_01B015F0(void);
extern void func_01B01C98(int, void *, int);
extern void func_01B01610(void);
extern void func_01B02D30(int, int);
extern void func_01B05278(Obj5420 *, void *, int *, int);
extern void func_01B03680(int, void *, void *);
extern void *func_01B04258(void (*)(void));
extern void func_01B04420(void *);
extern void func_01B01488(void);

int ovl_09108_1378(void)
{
    int flag;
    int idx;
    int val;

    D_01B05480 = D_01B0B6C0;
    flag = (D_01B001E8 >> 11) & 1;
    D_01B0548C = flag;
    idx = func_01B015F0();
    D_01B05484 = 0;
    val = D_01B00040[idx];
    D_01B05488 = val;
    if (flag == 1) {
        func_01B01C98(0, D_01B05410, 0);
        func_01B01610();
        func_01B02D30(0, 1);
        D_01B00060[1] = D_01B05488;
        func_01B05278(&D_01B05420, D_01B0B510, D_01B00060, 1);
        D_01B05420.w54 = 0;
    } else {
        D_01B05488 = val + 0xF;
    }
    func_01B03680(-1, D_01B053E8, D_01B00088);
    func_01B04420(func_01B04258(func_01B01488));
    return 0;
}
