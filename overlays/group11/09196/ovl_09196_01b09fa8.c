#include "common.h"

typedef struct {
    void *node;
    u8 dirty;
    u8 tick;
    u8 pad[10];
} Ctx9FA8;

extern s32 g_state_0044;
extern void *g_sym_0048;
extern void *g_sym_004c;
extern u8 g_tick_0738;
extern void *g_sym_073c;
extern u8 g_sym_0b00[];
extern u8 g_sym_0b50[];
extern u8 g_sym_0b90[];
extern u8 g_sym_96f0[];
extern void *D_006A3924;

extern s32 func_0029B830(s32);
extern s32 func_002D0570(s32);
extern s32 func_00294578(s32);
extern void func_001CDC58(void *, s32);
extern void func_002B37A0(void);
extern void fn_01b187a8(void *);
extern void fn_01b0ca60(Ctx9FA8 *);

s32 ovl_09196_01b09fa8(void) {
    Ctx9FA8 ctx;
    void *m1[1];

    while (1) {
        switch (g_state_0044) {
        case 0:
            if (func_0029B830(2) == 0) {
                g_state_0044++;
                continue;
            }
            return 0;
        case 1:
            if (func_002D0570(2) != 0) {
                return 0;
            }
            g_state_0044++;
            continue;
        case 2:
            if (func_00294578(2) != 0) {
                return 0;
            }
            func_001CDC58(g_sym_073c, 0);
            g_state_0044 = 4;
            break;
        }
        break;
    }

    func_002B37A0();
    D_006A3924 = g_sym_96f0;
    g_sym_0048 = g_sym_004c;
    g_tick_0738++;

    m1[0] = g_sym_0b00;
    fn_01b187a8(m1);

    ctx.node = g_sym_0b50;
    ctx.tick = g_tick_0738;
    fn_01b0ca60(&ctx);

    ctx.node = g_sym_0b90;
    ctx.tick = g_tick_0738;
    fn_01b0ca60(&ctx);

    return 0;
}
