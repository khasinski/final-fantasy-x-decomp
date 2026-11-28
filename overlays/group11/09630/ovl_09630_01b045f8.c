#include "common.h"

extern u8 *D_01B0C0B0;
extern void func_01B073E8(void *);

void func_01B045F8(void)
{
    u8 *s0 = D_01B0C0B0 + 0x8000;
    if (*(void **)(s0 + 0x5C0) != 0) {
        func_01B073E8(*(void **)(s0 + 0x5C0));
        *(void **)(s0 + 0x5C0) = 0;
    }
}
