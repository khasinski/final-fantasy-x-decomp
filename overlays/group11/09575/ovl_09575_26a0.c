/* Twin 2D line wrapper for 09575 (0x01B026A0..0x01B02720) and 09574 (0x01B02700..0x01B02780). */
#include "common.h"

typedef unsigned long u64;

extern void func_01B023F8(void);
extern void func_01B02438(void);
extern void func_01B02580(u32 x0, u32 y0, u32 x1, u32 y1, u64 rgba);

void func_01B026A0(u32 x0, u32 y0, u32 x1, u32 y1, u64 rgba)
{
    func_01B023F8();
    func_01B02580((x0 << 4) + 0x8000, (y0 << 4) + 0x8000, (x1 << 4) + 0x8000, (y1 << 4) + 0x8000, rgba);
    func_01B02438();
}
