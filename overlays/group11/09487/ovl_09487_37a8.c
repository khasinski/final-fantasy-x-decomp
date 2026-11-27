#include "common.h"

extern int D_01B007C0;
extern int D_01B00A90;
extern int D_01B00AE0;
extern int D_01B032F0;
extern int D_01B032F4;

extern void func_001CDD38(int);
extern int func_001CE1A8(int);

int func_01B037A8(void)
{
    D_01B00AE0 = 0;
}

int func_01B037B8(void)
{
    if (D_01B00AE0 == 0) {
        if ((D_01B032F0 == 1 && D_01B032F4 == 1) || (D_01B032F0 - 1 == D_01B032F4)) {
            func_001CDD38(D_01B007C0);
            D_01B00AE0++;
        }
    } else {
        if (func_001CE1A8(D_01B00A90) == -1) {
            return 0;
        }
    }
    return 1;
}
