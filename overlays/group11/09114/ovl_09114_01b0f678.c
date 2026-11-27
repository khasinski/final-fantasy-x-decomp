#include "common.h"

extern int g_state_0044;
extern int g_sym_0048;
extern int g_sym_004c;
extern u8 g_tick_0964;
extern int g_sym_0b80;
extern u8 g_sym_0f40[];
extern u8 g_sym_0f90[];
extern u8 g_sym_0fd0[];
extern u8 g_sym_eb50[];
extern int g_sym_fbd0;
extern int g_sym_fbd4;
extern int g_sym_aca0;
extern void *D_006A3924;

extern int func_0029B830(int);
extern int func_002D0570(int);
extern int func_00294578(int);
extern void func_001CDC58(int, int);
extern int func_001CDAF8(int);
extern void func_002B37A0(void);
extern void g_fn_dbe8(void *);
extern void g_fn_31f8(void *);

typedef struct {
    void *node;
    u8 flags;
    u8 tag;
    u8 pad06[10];
} MsgF678;

int func_01B0F678(void)
{
    MsgF678 m0;
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
        if (func_002D0570(2) == 0) {
            g_state_0044++;
            goto loop;
        }
        return 0;
    case 2:
        if (func_00294578(2) != 0) {
            return 0;
        }
        func_001CDC58(g_sym_0b80, 1);
        g_state_0044++;
        goto loop;
    case 3:
        if (func_001CDAF8(g_sym_0b80) <= 0) {
            return 0;
        }
        g_state_0044++;
        break;
    }

    func_002B37A0();
    {
        register int v4c __asm__("$9") = g_sym_004c;
        register int vfbd0 __asm__("$10") = g_sym_fbd0;
        register u32 t __asm__("$6") = g_tick_0964;
        D_006A3924 = g_sym_eb50;
        g_sym_0048 = v4c;
        g_tick_0964 = t + 1;
        g_sym_aca0 = 0;
        g_sym_fbd4 = vfbd0;
    }
    m1[0] = g_sym_0f40;
    g_fn_dbe8(m1);
    m0.node = g_sym_0f90;
    m0.tag = g_tick_0964;
    g_fn_31f8(&m0);
    m0.node = g_sym_0fd0;
    m0.tag = g_tick_0964;
    g_fn_31f8(&m0);
    return 0;
}
