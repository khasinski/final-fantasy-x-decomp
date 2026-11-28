#include "common.h"

extern int D_01B006A8;
extern void func_00107BE8(int, int);
extern void func_0010D720(void);

int func_01B01F68(void)
{
    func_00107BE8(D_01B006A8, 0);
    func_0010D720();
    return 1;
}
