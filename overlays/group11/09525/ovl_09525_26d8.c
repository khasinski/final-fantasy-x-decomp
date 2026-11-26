#include "common.h"

typedef unsigned long u64;

extern void func_01B02570(void);
extern void func_01B025B0(void);
extern void func_01B025D0(u32, u32, u32, u32, u64);

void func_01B026D8(u32 x0, u32 y0, u32 x1, u32 y1, u64 rgba)
{
    func_01B02570();
    func_01B025D0((x0 << 4) + 0x8000, (y0 << 4) + 0x8000, (x1 << 4) + 0x8000, (y1 << 4) + 0x8000, rgba);
    func_01B025B0();
}
