/* Twin DMA + sprite resource helpers for 09575 (0x01B02398..0x01B02458) and 09574 (0x01B023F8..0x01B024B8). */
#include "common.h"

extern void *D_01B03E50[2];
extern void *func_002B3888(int);
extern void func_002B39C0(int);
extern int func_002DA610(int, int);
extern void func_002DBA28(void *, void *);
extern void func_002DBF78(void *, int, int);

void func_01B02398(void *p)
{
    while (func_002DA610(1, 0) & 0x10) {}
    func_002DBF78((void *)0x1000A000, 0, 0);
    func_002DBA28((void *)0x1000A000, (void *)((u32)p | 0x80000000));
}

void func_01B023F8(void)
{
    D_01B03E50[0] = func_002B3888(0x90);
    D_01B03E50[1] = func_002B3888(0x90);
}

void func_01B02438(void)
{
    func_002B39C0(0x90);
    func_002B39C0(0x90);
}
