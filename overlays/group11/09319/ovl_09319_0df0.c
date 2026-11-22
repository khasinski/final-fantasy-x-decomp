#include "common.h"

typedef struct {
    u8 pad00[0x110];
    s32 w110;
} State9319;

typedef struct {
    u8 pad00[0x10];
    s32 p10;
} TaskSub;

typedef struct {
    u8 pad00[0x08];
    TaskSub *p08;
    u8 pad0C[0x08];
    s32 w14;
} OvlTask;

extern u8 D_01B00B30[];
extern u8 D_01B056C8[];
extern State9319 *D_01B056EC;
extern u8 D_01B056F8[];
extern u8 *D_01B05C04;

extern int func_01B03350(void *);
extern int func_01B042B0(void *, void *);

void ovl_09319_0df0(OvlTask *a0)
{
    int r1 = func_01B03350(D_01B056C8);
    int r2 = func_01B042B0(D_01B056F8, D_01B05C04);

    if (r2 == 1 && r1 == 1 && D_01B056EC->w110 == 1) {
        a0->w14 = 3;
        a0->p08->p10 = (s32)D_01B00B30;
    }
}
