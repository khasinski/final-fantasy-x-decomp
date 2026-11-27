#include "common.h"

extern u8 *g_state_db20;
extern u8 g_sym_dae0[];

extern void g_fn_8be0(void *);
extern void g_fn_7810(int, int);
extern void g_fn_82e0(void *, int);
extern void g_fn_7268(int, int);
extern void g_fn_73a8(int);
extern void g_fn_7460(int);
extern void func_001CE9A8(int);
extern void g_fn_af98(void);

int func_01B06058(void)
{
    return *(u32 *)(g_state_db20 + 0x1B20) == 0;
}

void func_01B06070(void)
{
    u8 *st = g_state_db20;
    void *p = *(void **)(st + 0x1B04);

    if (p != 0) {
        g_fn_8be0(p);
        *(u32 *)(st + 0x1B04) = 0;
    }
    g_fn_7810(-1, 0);
    g_fn_82e0(g_sym_dae0, 0);
    g_fn_7268(-1, 1);
    g_fn_73a8(1);
    g_fn_7460(1);
    func_001CE9A8(0);
    g_fn_af98();
    *(u32 *)(st + 0x1B24) = 1;
}
