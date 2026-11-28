#include "common.h"

extern int g_state_0044;
extern int g_sym_0048;
extern int g_sym_004c;
extern u8 g_tick_0a74;
extern int g_sym_067c;
extern u8 g_sym_0a48[];
extern u8 g_sym_0a98[];
extern u8 g_sym_0ad8[];
extern u8 g_sym_7b58[];
extern void *D_006A3924;

extern int func_0029B830(int);
extern int func_002D0570(int);
extern int func_00294578(int);
extern void func_001CDC58(int, int);
extern void func_002B37A0(void);
extern void g_fn_6b70(void *);
extern void g_fn_bb38(void *);

typedef struct {
    void *node;
    u8 flags;
    u8 tag;
    u8 pad06[10];
} Msg77B8;

int ovl_09194_01b077b8(void)
{
    Msg77B8 m0;
    void *m1[4];

loop:
    switch (g_state_0044) {
    case 0:
        if (func_0029B830(2) == 0) {
            g_state_0044++;
            goto loop;
        }
        return 0;
    case 1:
        if (func_002D0570(2) != 0) {
            return 0;
        }
        g_state_0044++;
        goto loop;
    case 2:
        if (func_00294578(2) != 0) {
            return 0;
        }
        func_001CDC58(g_sym_067c, 0);
        g_state_0044 = 4;
        break;
    }

    func_002B37A0();
    D_006A3924 = g_sym_7b58;
    g_sym_0048 = g_sym_004c;
    g_tick_0a74++;
    m1[0] = g_sym_0a48;
    g_fn_6b70(m1);
    m0.node = g_sym_0a98;
    m0.tag = g_tick_0a74;
    g_fn_bb38(&m0);
    m0.node = g_sym_0ad8;
    m0.tag = g_tick_0a74;
    g_fn_bb38(&m0);
    return 0;
}
