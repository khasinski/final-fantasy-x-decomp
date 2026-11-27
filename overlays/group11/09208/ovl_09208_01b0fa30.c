#include "common.h"

extern u8 g_sym_0a68[];
extern void g_fn_4630(void *);
extern void g_fn_4410(void *);

int func_01B0FA30(void)
{
    void *p0;
    void *p1;

    p0 = g_sym_0a68;
    g_fn_4630(&p0);
    p1 = g_sym_0a68;
    g_fn_4410(&p1);
    return 0;
}
