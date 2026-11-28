#include "common.h"

extern u8 *func_001E4F58(int, int *);
extern int func_001B5810(u32, int);

void func_01B0ACA0(int s2)
{
    int cnt;
    int i;
    u8 *s0 = func_001E4F58(0x10, &cnt);

    for (i = 0; i < cnt; i++) {
        func_001B5810(*s0++, s2);
    }
}
