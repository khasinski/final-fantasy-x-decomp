#include "common.h"

extern void *D_01B04A00[2];

extern void *func_002B3888(int);
extern void func_002B39C0(int);
extern int func_002DA610(int, int);
extern void func_002DBA28(void *, void *);
extern void func_002DBF78(void *, int, int);

void func_01B02F88(void *p)
{
    while (func_002DA610(1, 0) & 0x10) {}
    func_002DBF78((void *)0x1000A000, 0, 0);
    func_002DBA28((void *)0x1000A000, (void *)((u32)p | 0x80000000));
}

void func_01B02FE8(void)
{
    D_01B04A00[0] = func_002B3888(0x90);
    D_01B04A00[1] = func_002B3888(0x90);
}

void func_01B03028(void)
{
    func_002B39C0(0x90);
    func_002B39C0(0x90);
}
