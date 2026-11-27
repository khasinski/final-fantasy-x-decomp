#include "common.h"

extern u8 D_01B10250[];

void func_01B03328(void *a0, void *a1, int a2);
void func_01B04688(void *a0, int a1);
void func_01B055D8(void *a0, int a1, int a2);

void func_01B02738(u8 *a0)
{
    func_01B03328(*(void **)(a0 + 0x120), a0 + 0xD0, 4);
}

void func_01B02750(u8 *a0)
{
    func_01B04688(*(void **)(a0 + 0x120), 0);
    func_01B055D8(D_01B10250, 0, 3);
}
