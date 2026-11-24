#include "common.h"

typedef struct {
    u8 pad00[0xC4];
    float fC4;
} ObjC4;

typedef struct {
    u8 pad00[0x2C];
    s32 w2C;
    s32 w30;
    s32 w34;
} Arg2C;

typedef struct {
    u8 pad00[0x14];
    void *p14;
} Node14;

typedef struct {
    s32 w00;
    s32 w04;
} Pair8;

extern u8 D_01B01578[];
extern u8 D_01B01368[];
extern Pair8 D_01B085B0[];

extern float func_01B01AB0(s32);
extern Node14 *func_01B04198(void *);
extern void func_01B04360(void *);
extern s32 func_01B01988(s32);
extern void func_01B02F38(s32, s32);
extern void func_01B02EE8(s32, s32, s32);

void ovl_09314_1720(ObjC4 *s0)
{
    s0->fC4 = func_01B01AB0(-1);
}

void ovl_09314_1750(Arg2C *s0)
{
    Node14 *n = func_01B04198(D_01B01578);
    n->p14 = (void *)s0->w2C;
    func_01B04360(n);
}

void ovl_09314_1788(Arg2C *s2)
{
    s32 s1 = s2->w2C;
    Pair8 *s0;
    Node14 *n;

    func_01B02F38(func_01B01988(s1), 0);
    {
        register Pair8 *tbl __asm__("$3") = D_01B085B0;
        s0 = &tbl[s1];
    }
    s0->w00 = s1;
    s0->w04 = s2->w30;
    n = func_01B04198(D_01B01368);
    n->p14 = s0;
    func_01B04360(n);
}

void ovl_09314_1800(Arg2C *a0)
{
    func_01B02EE8(a0->w2C, a0->w30, a0->w34);
}
