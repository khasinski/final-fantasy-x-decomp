#include "common.h"

extern void *D_01B07154;

extern void func_002A7308(void *, void *, int, int);
extern void *func_01B021C0(int);
extern void func_01B03D08(int, int, int);

void func_01B01D88(void)
{
    void *p = func_01B021C0(-1);

    func_01B03D08(-1, 0x3C00, 0x2EE0);
    func_002A7308(D_01B07154, p, 1, 0);
    func_01B03D08(-1, -1, -1);
}
