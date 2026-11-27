#include "common.h"

extern void func_01B06698(int, int, int, void *);

void func_01B02788(u8 *a0)
{
    func_01B06698(-1, *(int *)(a0 + 0x120), 0, a0 + 0xD0);
}
