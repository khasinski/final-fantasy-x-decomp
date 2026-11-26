#include "common.h"

extern void func_01B04F40(int);
extern int func_01B04F70(int);

void func_01B01428(void)
{
    func_01B04F40(0x3019);
    func_01B04F40(0x301F);
}

int func_01B01448(void)
{
    int r = func_01B04F70(0x3019);

    if (r != 1) {
        return 0;
    }
    if (func_01B04F70(0x301F) != 1) {
        r = 0;
    }
    return r;
}
