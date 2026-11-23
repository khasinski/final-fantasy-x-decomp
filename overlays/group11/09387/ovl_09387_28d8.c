/* 09387 init function (276 B). */
#include "common.h"

extern u8 g_ovl_50[];
extern u8 *g_ovl_4c;
extern void *g_ovl_668;
extern u8 g_ovl_a30[];
extern u8 g_ovl_a48[];
extern u8 g_ovl_a68[];
extern u8 g_ovl_19e8[];
extern u8 g_ovl_d390[];
extern void *g_ovl_d3bc;
extern u8 g_heap_b700[];
extern u8 g_heap_1ce_b700[];

extern void fn_ovl_1f30(void);
extern void fn_ovl_c2f8(void *);
extern void fn_ovl_3488(void *);
extern void func_002B4980(void *);
extern void *func_002B49A0(void *, int, int);
extern void func_002678E0(void *, void *);
extern void func_00267A68(void *, void *, void *, int);
extern void func_002D02E8(void *, int, int, int);
extern void func_002944B0(void *, int, int, int);
extern void fn_ovl_2878(void *);

int ovl_09387_28d8(void)
{
    u32 arg0[4];
    u32 arg10;
    u8 *s0;
    void *v0;

    fn_ovl_1f30();
    g_ovl_4c = g_heap_1ce_b700;
    arg10 = (u32)g_ovl_a30;
    fn_ovl_c2f8(&arg10);

    s0 = g_ovl_a48;
    arg0[0] = (u32)s0;
    arg0[1] = 0;
    fn_ovl_3488(arg0);
    s0[0x1B] = 1;

    arg0[0] = (u32)g_ovl_a68;
    arg0[1] = 0;
    fn_ovl_3488(arg0);

    func_002B4980(g_ovl_668);
    v0 = func_002B49A0(g_ovl_668, 8, 0);
    g_ovl_d3bc = v0;
    func_002678E0(v0, g_ovl_50);
    func_00267A68(g_ovl_d390, g_ovl_d3bc, g_heap_b700, 0x100000);
    func_002D02E8(g_ovl_668, 0, 7, 2);
    func_002944B0(g_ovl_668, 0, 1000, 2);
    fn_ovl_2878(g_ovl_19e8);
    return 0;
}
