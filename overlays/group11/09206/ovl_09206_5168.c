#include "common.h"

extern void func_00110718(int, int);
extern int func_01B01F58(int, int);

void func_01B01CE0(void)
{
    int p = func_01B01F58(0, 1);
    if (p != 0) {
        func_00110718(p, 1);
    }
}
