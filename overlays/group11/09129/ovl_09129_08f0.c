/* 09129 unique init function (428 B). */
#include "common.h"

extern u8 g_heap_base[];
extern u8 *g_ptr_4f20;
extern u8 *g_ptr_50a0;
extern u8 *g_ptr_50a4;
extern u8 g_work_4f28[];
extern u8 g_obj_4f70[];
extern u8 g_res_data[];
extern u8 g_hdr_40[];
extern void *g_tbl_428[];
extern u8 g_tbl_480[];
extern u8 g_fade_4ea0[];
extern u8 fn_ovl_0aa0[];
extern u8 fn_ovl_0b28[];
extern u8 fn_ovl_3e20[];

extern void *op_oef2_a_get(void *, int, int);
extern void fn_ovl_37a8(void *, void *, void *, int);
extern void fn_ovl_3880(void *, void *, int, int, int, void *, float);
extern void fn_ovl_0f60(int, void *, int);
extern float fn_ovl_0e38(int);
extern void fn_ovl_3008(void *, void *, void *);
extern void fn_ovl_4380(float, float);
extern void fn_ovl_4c50(void *, int, int, float, float);
extern void fn_ovl_2d90(int);
extern void *fn_ovl_3520(void *);
extern void fn_ovl_36e8(void *);

int ovl_09129_08f0(void)
{
    register u8 *s2 __asm__("$18") = g_heap_base;
    u8 *s1;
    u8 *s0;

    {
        register u8 *p1 __asm__("$2") = s2 + 0x40000;
        register u8 *p2 __asm__("$3") = s2 + 0xC0000;
        g_ptr_50a0 = s2;
        g_ptr_50a4 = p1;
        g_ptr_4f20 = p2;
    }
    s1 = g_work_4f28;
    *(void **)(s1 + 0x2C) = op_oef2_a_get(g_res_data, 8, 0);
    fn_ovl_37a8(s1, g_hdr_40, g_ptr_50a0, 0x40000);

    s0 = g_obj_4f70;
    fn_ovl_3880(s1, s0, 0, 0, 0x14, fn_ovl_3e20, 0.2f);
    fn_ovl_0f60(0, s0 + 0xD0, 5);
    *(float *)(s0 + 0xC4) = fn_ovl_0e38(-1);

    s2 = s2 + 0x140000;
    fn_ovl_3008(s2, g_res_data, g_tbl_480);
    {
        register float f0 __asm__("$f12") = 0.0f;
        register void **tbl __asm__("$2");
        register void *fn __asm__("$3");
        __asm__("" : "+f"(f0));
        tbl = g_tbl_428;
        fn = fn_ovl_0b28;
        __asm__("" : "+r"(tbl), "+r"(fn) : "f"(f0));
        *(void **)(s0 + 0x110) = s2;
        *(void **)(s0 + 0x108) = tbl;
        tbl[15] = fn;
        fn_ovl_4380(f0, f0);
    }
    fn_ovl_4c50(g_fade_4ea0, 8, 0, 1.0f, 0.5f);
    fn_ovl_4c50(g_fade_4ea0 + 0x40, 0x10, 0x28, 0.5f, 1.0f);
    fn_ovl_2d90(1);
    fn_ovl_36e8(fn_ovl_3520(fn_ovl_0aa0));
    return 0;
}
