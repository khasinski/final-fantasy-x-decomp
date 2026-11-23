/* 09137 unique init function (448 B). */
#include "common.h"

extern u8 g_heap_base[];
extern u8 *g_ptr_4ff0;
extern u8 *g_ptr_5170;
extern u8 *g_ptr_5174;
extern u8 g_work_4ff8[];
extern u8 g_obj_5040[];
extern u8 g_res_data[];
extern u8 g_hdr_40[];
extern void *g_tbl_478[];
extern u8 g_tbl_540[];
extern u8 g_fade_4f70[];
extern u8 fn_ovl_0b70[];
extern u8 fn_ovl_0bf8[];
extern u8 fn_ovl_3ef0[];

extern void *op_oef2_a_get(void *, int, int);
extern void fn_ovl_3878(void *, void *, void *, int);
extern void fn_ovl_3950(void *, void *, int, int, int, void *, float);
extern void fn_ovl_1030(int, void *, int);
extern void fn_ovl_30d8(void *, void *, void *);
extern void fn_ovl_4450(float, float);
extern void fn_ovl_4d20(void *, int, int, float, float);
extern void fn_ovl_2e60(int);
extern void *fn_ovl_35f0(void *);
extern void fn_ovl_37b8(void *);

int ovl_09137_09b0(void)
{
    u8 *s0 = g_heap_base;
    u8 *s2;
    u8 *s1;

    g_ptr_5170 = s0;
    g_ptr_5174 = s0 + 0x40000;
    g_ptr_4ff0 = s0 + 0xC0000;
    s2 = g_work_4ff8;
    *(void **)(s2 + 0x2C) = op_oef2_a_get(g_res_data, 8, 0);
    fn_ovl_3878(s2, g_hdr_40, g_ptr_5170, 0x40000);

    s1 = g_obj_5040;
    fn_ovl_3950(s2, s1, 0, 0, 0x12, fn_ovl_3ef0, 0.3f);
    fn_ovl_1030(0, s1 + 0xD0, 5);

    s0 = s0 + 0x140000;
    fn_ovl_30d8(s0, g_res_data, g_tbl_540);
    {
        register float f0 __asm__("$f12") = 0.0f;
        register void **tbl __asm__("$2");
        register void *fn __asm__("$3");
        __asm__("" : "+f"(f0));
        tbl = g_tbl_478;
        fn = fn_ovl_0bf8;
        __asm__("" : "+r"(tbl), "+r"(fn) : "f"(f0));
        *(void **)(s1 + 0x110) = s0;
        *(void **)(s1 + 0x108) = tbl;
        tbl[30] = fn;
        fn_ovl_4450(f0, f0);
    }
    fn_ovl_4d20(g_fade_4f70, 8, 0, 1.0f, 0.33f);
    *(float *)(g_fade_4f70 + 0x18) = 0.45f;
    fn_ovl_4d20(g_fade_4f70 + 0x40, 0x10, 0x46, 0.33f, 1.0f);
    *(float *)(g_fade_4f70 + 0x48) = 0.45f;
    fn_ovl_2e60(1);
    fn_ovl_37b8(fn_ovl_35f0(fn_ovl_0b70));
    return 0;
}
