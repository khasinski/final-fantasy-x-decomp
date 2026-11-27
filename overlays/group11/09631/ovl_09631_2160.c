#include "common.h"

extern u8 *D_01B0A1E0;

void func_00118098(int a0, int a1);
void func_01B09918(void *a0, int a1);

void func_01B02160(void)
{
    u8 *s0 = D_01B0A1E0;
    u8 *p;

    func_00118098(0, 0x10000);
    func_00118098(1, 0x20000);
    p = s0 + 0xAA0;
    p[0x80] = 0xFF;
    p[0x81] = 0xFF;
    p[0x82] = 0xFF;
    p[0x83] = 0x80;
    p[0x84] = 0xFF;
    p[0x85] = 0xFF;
    p[0x86] = 0xFF;
    p[0x98] = 0x48;
    p[0x87] = 0;
    *(int *)(p + 0x88) = 0;
    p[0x99] = 0;
    func_01B09918(p, 0x28);
}
