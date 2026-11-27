#include "common.h"

typedef struct {
    u8 *obj;
    void *dst;
} ArgE040;

extern int func_002DD0B0(void *, void *);

void func_01B0E040(ArgE040 *a)
{
    volatile u8 pad[0x30];
    int r;
    (void)pad;
    r = func_002DD0B0(a->dst, a->obj + 0x16A0);
    __asm__("" : : "r"(r));
}
