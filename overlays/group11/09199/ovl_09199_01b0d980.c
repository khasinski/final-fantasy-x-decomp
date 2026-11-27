#include "common.h"

extern u8 g_sym_7090[];
extern void g_fn_1cc8(void *);
extern void g_fn_1bc0(void *);
extern u32 func_00173708(void);
extern void func_001736F0(u32);

int func_01B0D980(void)
{
    void *a[2];

    a[0] = g_sym_7090;
    g_fn_1cc8(&a[0]);
    a[1] = g_sym_7090;
    g_fn_1bc0(&a[1]);
    func_001736F0(func_00173708() | 4);
    return 0;
}
