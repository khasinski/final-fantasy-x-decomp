#include "common.h"

extern u8 *g_state_db20;
extern void *g_sym_db2c;
extern void *g_sym_0cb4;
extern u8 g_sym_da20[];
extern u8 g_sym_da80[];
extern u8 g_sym_dae0[];
extern u8 g_sym_db00[];

extern void g_fn_a7a8(void);
extern int g_fn_c9d0(void *);
extern void g_fn_8040(void *);
extern void g_fn_afd0(void);
extern void g_fn_42c0(void);
extern void g_fn_8be0(void *);

void func_01B05D58(void *a0)
{
    u8 *st = g_state_db20;
    int r;

    g_fn_a7a8();
    g_sym_0cb4 = g_sym_db2c;
    r = g_fn_c9d0(g_sym_da20);
    g_fn_c9d0(g_sym_da80);
    if (r == 0) {
        {
            register u_long128 *dst __asm__("$3") = (u_long128 *)(st + 0xC10);
            register u_long128 *src __asm__("$2") = (u_long128 *)(st + 0xC70);
            register u_long128 q __asm__("$7");
            __asm__("" : "+r"(dst), "+r"(src));
            q = *src;
            *dst = q;
        }
        __asm__ volatile("");
        {
            register u_long128 *src __asm__("$4") = (u_long128 *)(st + 0xC90);
            register u_long128 *dst __asm__("$2") = (u_long128 *)(st + 0xC50);
            register u_long128 q __asm__("$7");
            __asm__("" : "+r"(src));
            __asm__("" : "+r"(dst));
            q = *src;
            *dst = q;
        }
        __asm__ volatile("");
        g_fn_8040(g_sym_dae0);
        g_fn_8040(g_sym_db00);
        g_fn_afd0();
    } else {
        *(int *)(st + 0x1B2C) = 1;
        g_fn_42c0();
        g_fn_8be0(a0);
    }
}
