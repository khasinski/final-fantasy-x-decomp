#include "common.h"

extern int D_01B001E8;
extern int D_01B00040[];

extern void func_001E4C80(int, int);
extern int func_01B015F0(void);

void ovl_09108_1328(void)
{
    func_001E4C80(0, (D_01B001E8 >> 11) & 1);
    func_001E4C80(1, D_01B00040[func_01B015F0()]);
}
