#include "common.h"

extern u8 *D_01B0E828;
extern u8 D_01BE9C10[];

extern void *func_01B05FA8(int);
extern void func_01B07558(void *, int);
extern void func_01B07468(int, int);
extern void func_01B07588(int, int);
extern void func_01B07318(int, int);
extern void func_01B08208(void *, int, void *, int);

void func_01B05658(u8 *a0)
{
    int s0 = *(int *)(a0 + 0x120);
    u8 *s1 = D_01B0E828 + (s0 * 0xE0 + 0x1000);

    func_01B07558(func_01B05FA8(s0), 2);
    func_01B07468(s0, 0);
    func_01B07588(s0, 6);
    func_01B07318(s0, 1);
    func_01B08208(D_01BE9C10, 3, s1 + 0x90, 0x100);
    *(int *)(s1 + 0xD0) = 1;
}
