#include "common.h"

extern int D_01B007F0;
extern int D_01B009C4;
extern int D_01B00A48;
extern void func_001C5E90(int, int, int);
extern void func_001C69C8(int, int, int);

int func_01B013E0(void)
{
    if (D_01B009C4 != 0) {
        func_001C69C8(D_01B00A48, 5, 1);
    }
    return 1;
}

int func_01B01418(void)
{
    if (D_01B009C4 == 0) {
        func_001C5E90(D_01B007F0, D_01B00A48, 0);
        return 1;
    }
}
