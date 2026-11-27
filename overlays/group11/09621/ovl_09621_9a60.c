#include "common.h"

extern u8 D_01B00B80[];
extern u8 D_01B089B8[];

extern void func_01B16A98(void *);
extern void func_01B16EA0(void *);

void func_01B09A60(u8 *s0, s32 s2, s32 s1)
{
    struct {
        void *a;
        void *b;
        void *c;
    } m;

    m.a = s0;
    m.b = D_01B089B8;
    m.c = s0;
    func_01B16A98(&m);
    m.a = D_01B00B80;
    m.b = s0;
    func_01B16EA0(&m);
    *(s32 *)(s0 + 0x1400) = s1;
    *(s32 *)(s0 + 0x570) = s2;
    *(s32 *)(s0 + 0x1C) = 0;
    *(s32 *)(s0 + 0x18) = 0;
}
