/* 2D line wrapper for 09142 (0x01B03DD0..0x01B03E50) and 09395 (0x01B050D8..0x01B05158). */
#include "common.h"

typedef unsigned long u64;

extern void func_01B03B28(void);
extern void func_01B03B68(void);
extern void func_01B03CB0(u32 x0, u32 y0, u32 x1, u32 y1, u64 rgba);

void func_01B03DD0(u32 x0, u32 y0, u32 x1, u32 y1, u64 rgba)
{
    func_01B03B28();
    func_01B03CB0((x0 << 4) + 0x8000, (y0 << 4) + 0x8000, (x1 << 4) + 0x8000, (y1 << 4) + 0x8000, rgba);
    func_01B03B68();
}
