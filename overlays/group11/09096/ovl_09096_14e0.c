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
} Task14E0;

extern u8 D_01B054A8[];
extern int D_01B05544;
extern int D_01B05548;
extern int D_01B0554C;
extern int D_01B05550;

extern int func_01B037F8(void *);
extern void func_01B02780(int, int);
extern void func_01B01898(void);
extern void func_01B030B8(int, int);
extern void func_01B01778(void);
extern int MsVoiceStatus(void);
extern void func_01B01730(void);
extern void func_01B02DF0(int, int);
extern void func_01B004C8(void);

void ovl_09096_14e0(Task14E0 *t)
{
    int done = func_01B037F8(D_01B054A8);

    if (D_01B05550 == 1) {
        if (D_01B05548 > 0) {
            if (--D_01B05548 == 0) {
                func_01B02780(0, 0);
            }
        } else {
            if (++D_01B05544 >= 16) {
                func_01B01898();
            }
            if (D_01B05544 == 70) {
                func_01B030B8(-5, 0);
                func_01B02780(0, -1);
            }
        }
        func_01B01778();
    } else {
        if (D_01B05548 > 0) {
            if (--D_01B05548 == 0) {
                func_01B030B8(-5, 0);
            }
        } else {
            D_01B05544 = 101;
        }
    }

    if (done == 1 && D_01B05544 >= 101) {
        D_01B05544 = 100;
        if (D_01B0554C == 1 && MsVoiceStatus() == 0) {
            if (D_01B05550 == 1) {
                func_01B01730();
                func_01B02DF0(0, 0);
            }
            t->w14 = 3;
            t->p08->fn10 = (s32)func_01B004C8;
        }
    }
}
