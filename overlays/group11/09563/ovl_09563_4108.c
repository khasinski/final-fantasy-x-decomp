#include "common.h"

typedef struct {
    unsigned long q[22];
} Copy176;

extern Copy176 D_006F2CE0;
extern Copy176 D_01B01880;
extern void func_002B2A80(void *, int, int, int);

void func_01B004F8(void)
{
    D_01B01880 = D_006F2CE0;
    func_002B2A80(&D_01B01880, 11, 1, 0);
}
