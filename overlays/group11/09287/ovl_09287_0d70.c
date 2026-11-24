#include "common.h"

typedef struct {
    u8 pad00[0x10];
    s32 fn10;
} SubTask;

typedef struct {
    u8 pad00[0x8];
    SubTask *sub08;
    u8 pad0C[0x8];
    s32 state14;
} Task0D70;

extern u8 D_01B069F8[];
extern void *D_01B06DD4;
extern u8 D_01B05FE8[];
extern u8 D_01B00A20[];

extern s32 func_01B040C0(void *, void *);
extern s32 func_01B03160(void *);

void ovl_09287_0d70(Task0D70 *s1)
{
    s32 s0 = func_01B040C0(D_01B069F8, D_01B06DD4);
    s32 v1 = func_01B03160(D_01B05FE8);

    if (v1 == 1 && s0 == 1) {
        s1->state14 = 3;
        s1->sub08->fn10 = (s32)D_01B00A20;
    }
}
