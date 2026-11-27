#include "common.h"

extern int D_01B0A7B4;
extern int D_01B00350;
extern int func_00219F40(void);

int func_01B0AC38(void)
{
    int r = func_00219F40();
    D_01B0A7B4 = r;
    if (r == 5) {
        D_01B00350 = 1;
        return 0;
    }
    return 1;
}
