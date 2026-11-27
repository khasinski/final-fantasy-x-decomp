#include "common.h"

extern void *g_sym_004c;
extern u8 g_sym_0050[];
extern int g_sym_0848;
extern u8 g_sym_0cc0[];
extern u8 g_sym_0cd8[];
extern u8 g_node_0cf0[];
extern u8 g_node_0d10[];
extern u8 g_node_0d30[];
extern u8 g_node_0d50[];
extern u8 g_sym_bc50[];
extern u8 g_sym_bc90[];
extern u8 g_sym_e340[];
extern int g_sym_e36c;
extern u8 g_buf_start[];
extern u8 g_buf_end[];

extern void g_fn_c2d0(void);
extern void g_fn_d288(void *);
extern void g_fn_2f08(void *);
extern void g_fn_f858(void *);
extern void g_fn_df40(void *);

extern void func_002B4980(int);
extern int func_002B49A0(int, int, int);
extern void func_002678E0(int, void *);
extern void func_00267A68(void *, int, void *, int);
extern void func_002D02E8(int, int, int, int);
extern void func_002944B0(int, int, int, int);

int func_01B0F8B8(void)
{
    void *m[4];
    void *p1;
    void *p2;

    g_fn_c2d0();
    g_sym_004c = g_buf_end;
    p1 = g_sym_0cc0;
    g_fn_d288(&p1);
    p2 = g_sym_0cd8;
    g_fn_d288(&p2);

    m[0] = g_node_0cf0;
    m[1] = 0;
    g_fn_2f08(m);
    g_node_0cf0[0x1B] = 1;

    m[0] = g_node_0d10;
    m[1] = 0;
    g_fn_2f08(m);
    g_node_0d10[0x1B] = 1;

    m[0] = g_node_0d30;
    m[1] = 0;
    g_fn_2f08(m);

    m[0] = g_node_0d50;
    m[1] = 0;
    g_fn_2f08(m);

    func_002B4980(g_sym_0848);
    g_sym_e36c = func_002B49A0(g_sym_0848, 8, 0);
    func_002678E0(g_sym_e36c, g_sym_0050);
    func_00267A68(g_sym_e340, g_sym_e36c, g_buf_start, 0x100000);
    func_002D02E8(g_sym_0848, 0, 1000, 2);
    func_002944B0(g_sym_0848, 0, 1000, 2);
    g_fn_f858(g_sym_bc90);
    g_fn_df40(g_sym_bc50);
    return 0;
}
