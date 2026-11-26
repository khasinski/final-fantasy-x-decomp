#include "common.h"

typedef struct {
    u8 pad00[0x10];
    s32 fn10;
} TaskSub;

typedef struct {
    u8 pad00[0x08];
    TaskSub *p08;
    u8 pad0C[0x08];
    s32 w14;
} Task1488;

extern u8 D_01B053E8[];
extern int D_01B05484;
extern int D_01B05488;
extern int D_01B0548C;

extern int func_01B03738(void *);
extern void func_01B026C0(int, int);
extern void func_01B017D8(void);
extern void func_01B02FF8(int, int);
extern void func_01B016B8(void);
extern void func_01B01670(void);
extern void func_01B02D30(int, int);
extern void func_01B004B0(void);

void ovl_09108_1488(Task1488 *t)
{
    int done = func_01B03738(D_01B053E8);

    if (D_01B0548C == 1) {
        if (D_01B05488 > 0) {
            if (--D_01B05488 == 0) {
                func_01B026C0(0, 0);
            }
        } else {
            if (++D_01B05484 >= 16) {
                func_01B017D8();
            }
            if (D_01B05484 == 70) {
                func_01B02FF8(-5, 0);
                func_01B026C0(0, -1);
            }
        }
        func_01B016B8();
    } else {
        if (D_01B05488 > 0) {
            if (--D_01B05488 == 0) {
                func_01B02FF8(-5, 0);
            }
        } else {
            D_01B05484 = 101;
        }
    }

    if (done == 1 && D_01B05484 >= 101) {
        if (D_01B0548C == 1) {
            func_01B01670();
            func_01B02D30(0, 0);
        }
        t->w14 = 3;
        t->p08->fn10 = (s32)func_01B004B0;
    }
}
