#include "common.h"

typedef struct S6960Obj {
    u8 pad00[0x18];
    s32 s18;
    u8 pad1C[0x86C];
    void *p888;
    void *p88C;
} S6960Obj;

extern void func_01B05808(void);
extern void func_01B16A98(void *a0);
extern void func_01B16EA0(void *a0);
extern u8 D_01B00B80[];

void func_01B06960(S6960Obj *a0, void *a1, void *a2)
{
    void *m[4];

    m[0] = a0;
    m[1] = func_01B05808;
    m[2] = a0;
    func_01B16A98(m);

    m[0] = D_01B00B80;
    m[1] = a0;
    func_01B16EA0(m);

    a0->p88C = a2;
    a0->p888 = a1;
    a0->s18 = 0;
}
