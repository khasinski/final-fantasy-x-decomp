#include "common.h"

extern void func_002EF0D0(void *, int, int);

void func_01B03808(void **a0, void *a1, void *a2)
{
    func_002EF0D0(a0, 0, 16);
    a0[0] = a1;
    a0[1] = a2;
}
