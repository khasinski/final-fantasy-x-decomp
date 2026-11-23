#include "common.h"

typedef struct S7438Obj {
    u8 pad00[0x10];
    u8 s10[0x18];
    s32 s28;
    u8 pad2C[4];
    s32 s30;
    u8 pad34[0x14];
    void *p48;
    void *p4C;
} S7438Obj;

extern void func_01B06FB8(void);
extern void func_01B16A98(void *a0);
extern void func_01B16EA0(void *a0);
extern u8 D_01B00B80[];

void func_01B07438(S7438Obj *a0, void *a1, void *a2)
{
    u8 pad00[0x10];
    void *m[4];
    void **s1 = m;

    (void)pad00;
    s1[1] = func_01B06FB8;
    m[0] = a0->s10;
    m[2] = a0;
    func_01B16A98(s1);

    m[0] = D_01B00B80;
    m[1] = a0->s10;
    func_01B16EA0(s1);

    a0->p4C = a2;
    a0->p48 = a1;
    a0->s30 = 0;
    a0->s28 = 0;
}
