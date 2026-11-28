#include "common.h"

extern int D_01B006A8;
extern void Ch_Dispose(int);
extern void ChN_DisposeSystemMGRP(int, int);

int func_01B02210(void)
{
    Ch_Dispose(D_01B006A8);
    ChN_DisposeSystemMGRP(0x3015, 1);
    return 1;
}
