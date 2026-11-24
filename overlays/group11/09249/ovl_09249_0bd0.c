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
} Task0BD0;

typedef struct {
    u8 pad00[0x46C];
    s32 w46C;
    u8 pad470[0xD0];
    s32 w540;
    u8 pad544[0x10];
    s32 w554;
    s32 w558;
} Work62B0;

extern Work62B0 *D_01B062B0;
extern u8 D_01B062C0[];
extern void *D_01B06304;
extern u8 D_01B00A10[];
extern s32 D_01B062A4;

extern s32 func_01B040F8(void *, void *);

void ovl_09249_0bd0(Task0BD0 *s1)
{
    Work62B0 *s0 = D_01B062B0;
    s32 r = func_01B040F8(D_01B062C0, D_01B06304);

    if (r == 1 && s0->w558 == 1 && s0->w46C <= 0) {
        s1->state14 = 3;
        s1->sub08->fn10 = (s32)D_01B00A10;
    }
}

void ovl_09249_0c58(void)
{
    Work62B0 *v0 = D_01B062B0;

    v0->w540 = 0;
    v0->w554 = 0;
    v0->w558 = 0;
    D_01B062A4 = 1;
}
