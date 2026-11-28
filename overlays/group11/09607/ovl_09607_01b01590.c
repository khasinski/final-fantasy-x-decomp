#include "common.h"

extern u32 D_01B0A858;
extern u8 D_01B0A860[];
extern void *D_01B0A8A4;
extern u8 *D_01B0A988;

int func_01B061C8(void *a0, void *a1);
void func_001CDDD8(u32 a0);

void func_01B01250(void)
{
    u8 *s0 = D_01B0A988;

    if (func_01B061C8(D_01B0A860, D_01B0A8A4) == 1) {
        if (*(int *)(s0 + 0x3BF8) == 1) {
            func_001CDDD8(D_01B0A858);
        }
    }
}
