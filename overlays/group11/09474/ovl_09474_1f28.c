#include "common.h"

extern void *D_01B0A488;

void *func_01B035F8(int a0);
void func_01B05140(int a0, int a1, int a2);
void *func_001038F8(void);
void func_002A7308(void *a0, void *a1, int a2, void *a3);

void func_01B01F28(void)
{
    void *s0 = func_01B035F8(0);

    func_01B05140(0, 0x3C00, 0x2EE0);
    func_002A7308(D_01B0A488, s0, 2, func_001038F8());
    func_01B05140(0, -1, -1);
}
