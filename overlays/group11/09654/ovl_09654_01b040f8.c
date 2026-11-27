#include "common.h"

extern u8 g_sym_d9d8[];
extern u32 g_sym_da1c;
extern u8 *g_state_db20;
extern void *g_sym_d9d0;

extern u32 g_fn_8fa0(void *, u32);
extern void func_001CDDD8(void *);

void func_01B040F8(void)
{
    u8 *st = g_state_db20;
    u32 r = g_fn_8fa0(g_sym_d9d8, g_sym_da1c);

    if (r == 1 && *(u32 *)(st + 0x1B28) == r) {
        func_001CDDD8(g_sym_d9d0);
    }
}
