#include "common.h"

typedef struct {
    u8 pad00[0x94];
    float f94;
    float f98;
    u8 pad9C[0x08];
    u16 fA4;
    u16 fA6;
    u16 fA8;
} Obj5DE0;

typedef struct {
    Obj5DE0 *obj;
    int count;
    u16 val;
} Arg5DE0;

void func_01B05DE0(Arg5DE0 *a0)
{
    register Obj5DE0 *o __asm__("$3") = a0->obj;
    register float cnt __asm__("$f1") = (float)a0->count;
    register float one __asm__("$f0") = 1.0f;
    u32 flags;
    u16 val;

    __asm__("" : "+f"(cnt));
    __asm__("" : "+f"(one));
    flags = o->fA4;
    __asm__("" : "+r"(flags));
    o->f94 = one;
    __asm__("" : : "m"(o->f94));
    flags |= 8;
    __asm__("" : "+r"(flags));
    one = one / cnt;
    val = a0->val;
    o->fA4 = flags;
    __asm__("" : : "m"(o->fA4));
    o->fA8 = val;
    __asm__("" : : "m"(o->fA8));
    o->f98 = one;
}
