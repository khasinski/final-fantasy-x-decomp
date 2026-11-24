#include "common.h"

typedef struct {
    u8 pad00[0x2C];
    void *w2C;
} Ctx62C0;

typedef struct {
    u8 pad00[0x18];
    u8 b18;
} Node3CB8;

extern u8 D_01B8E400[];
extern u8 *D_01B062B0;
extern u8 *D_01B062B4;
extern u8 *D_01B062B8;
extern Ctx62C0 D_01B062C0;
extern u8 *D_01B06300;
extern u8 *D_01B06304;
extern u8 D_01B0BA10[];
extern u8 D_01B00040[];
extern u8 D_01B00BA0[];
extern u8 D_01B00C80[];
extern u8 D_01B00BD0[];

extern void func_01B02C90(s32);
extern s32 func_01B02CC0(s32);
extern void *func_002B49A0(void *, s32, s32);
extern void func_01B03F40(void *, void *, void *, s32);
extern void func_01B00C58(void);
extern void func_01B03528(s32);
extern Node3CB8 *func_01B03CB8(void *);
extern void func_01B03E80(void *);
extern void func_01B05CD0(void *, s32);

void ovl_09249_0a30(void)
{
    func_01B02C90(12308);
}

s32 ovl_09249_0a38(void)
{
    return func_01B02CC0(12308) == 1;
}

s32 ovl_09249_0a60(void)
{
    u8 *s1 = D_01B8E400;
    Ctx62C0 *s0;
    Node3CB8 *n;

    D_01B06300 = s1;
    D_01B06304 = s1 + 0x40000;
    D_01B062B8 = s1 + 0x140000;
    D_01B062B4 = s1 + 0x160000;
    D_01B062B0 = s1 + 0x1A8000;
    s0 = &D_01B062C0;
    s0->w2C = func_002B49A0(D_01B0BA10, 8, 0);
    func_01B03F40(s0, D_01B00040, D_01B06300, 0x40000);
    func_01B00C58();
    func_01B03528(1);
    n = func_01B03CB8(D_01B00BA0);
    n->b18 = 1;
    func_01B03E80(n);
    n = func_01B03CB8(D_01B00C80);
    n->b18 = 1;
    func_01B03E80(n);
    func_01B05CD0(s1 + 0x1A0000, 256);
    n = func_01B03CB8(D_01B00BD0);
    n->b18 = 2;
    func_01B03E80(n);
    return 0;
}
