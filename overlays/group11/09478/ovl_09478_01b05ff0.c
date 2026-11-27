#include "common.h"

extern int g_cnt_aa8[2];
extern u8 *g_state_db20;
extern u8 g_sym_dae0[];

extern void *g_fn_63e8(int);
extern void func_00103208(void *);
extern void g_fn_7be8(int);
extern void g_fn_7198(int);
extern void g_fn_7460(int);
extern void g_fn_7810(int, void *);
extern void g_fn_82e0(void *, int);
extern void g_fn_73a8(int);
extern void g_fn_af98(void);

void func_01B05FF0(void)
{
    int i;

    func_00103208(g_fn_63e8(0));
    g_fn_7be8(0x3018);
    for (i = 1; i < g_cnt_aa8[1]; i++) {
        g_fn_7198(i);
    }
    if (*(int *)(g_state_db20 + 0x1B28) == 0) {
        g_fn_7460(1);
        g_fn_7810(-1, 0);
        g_fn_82e0(g_sym_dae0, 0);
        g_fn_73a8(1);
        g_fn_af98();
    }
}
