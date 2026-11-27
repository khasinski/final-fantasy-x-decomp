#include "common.h"

extern u8 *g_st_e828;
extern u8 g_sym_2860[];

extern void g_fn_6698(int, int, int, void *);
extern void g_fn_2ae0(void *, void *, void *, float);
extern void *g_fn_87b8(void *);
extern void g_fn_8980(void *);
extern void g_fn_c650(void *, int);

void func_01B02CE0(void)
{
    int sp0[4];
    u8 *s0 = g_st_e828;
    u8 *s1;
    u8 *p;

    g_fn_6698(-1, 17, 0, sp0);
    s1 = s0 + 0xC40;
    g_fn_2ae0(s0 + 0xCE0, sp0, s1, 90.0f);

    g_fn_6698(-1, 55, 0, sp0);
    g_fn_2ae0(s0 + 0xE70, sp0, s1, -90.0f);

    g_fn_8980(g_fn_87b8(g_sym_2860));

    p = s0 + 0x23DC;
    *(int *)(s0 + 0x23DC) = 0;
    *(int *)(p + 4) = 60;
    *(int *)(p + 12) = 2;
    *(int *)(p + 8) = 0;
    g_fn_c650(p, 14);
}
