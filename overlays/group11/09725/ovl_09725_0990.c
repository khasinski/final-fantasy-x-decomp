/* 09725 unique init function (632 B). */
#include "common.h"

extern u8 g_heap_base[];
extern u8 *g_ptr_5090;
extern u8 *g_ptr_63e0;
extern u8 *g_ptr_63e4;
extern u8 g_work_5098[];
extern u8 g_obj_50e0[];
extern u8 g_res_data[];
extern u8 g_hdr_40[];
extern u8 g_tbl_478[];
extern u8 g_tbl_540[];
extern struct { u8 pad[0x1E4]; int cnt; } g_tbl_590;
extern u8 g_fade_5010[];
extern u8 fn_ovl_0c90[];
extern u8 fn_ovl_0c08[];
extern u8 fn_ovl_3fa8[];

extern void *op_oef2_a_get(void *, int, int);
extern void fn_ovl_3910(void *, void *, void *, int);
extern void fn_ovl_24b8(void *);
extern float fn_ovl_0fa0(int);
extern float func_002B3DF8(float);
extern void fn_ovl_39e8(void *, void *, int, int, int, void *, float);
extern void fn_ovl_10c8(int, void *, int);
extern int fn_ovl_0e78(int);
extern void fn_ovl_3170(void *, void *, void *);
extern void fn_ovl_44e8(float, float);
extern void fn_ovl_4db8(void *, float, float, int, int);
extern void fn_ovl_2ef8(int);
extern void *fn_ovl_3688(void *);
extern void fn_ovl_3850(void *);

int ovl_09725_0990(void)
{
    s8 targets[16];
    u8 *s6 = g_heap_base;
    u8 *fp;
    u8 *s1;
    int s3;
    int s2 = 0;
    float f20;
    void **tbl;

    g_ptr_63e0 = s6;
    g_ptr_63e4 = s6 + 0x40000;
    g_ptr_5090 = s6 + 0x120000;
    fp = g_work_5098;
    *(void **)(fp + 0x2C) = op_oef2_a_get(g_res_data, 8, 0);
    fn_ovl_3910(fp, g_hdr_40, g_ptr_63e0, 0x40000);
    fn_ovl_24b8(targets);
    s1 = g_obj_50e0;
    f20 = fn_ovl_0fa0(-1);
    tbl = (void **)g_tbl_478;
    tbl[30] = fn_ovl_0c90;

    for (s3 = 0; s3 < g_tbl_590.cnt; s3++) {
        int s0 = targets[s3];
        float r = (func_002B3DF8(0.2f) + 1.0f) * 0.3f;
        u8 *buf;

        fn_ovl_39e8(fp, s1, 0, s2, 0x12, fn_ovl_3fa8, r);
        s2 += 0x2D;
        fn_ovl_10c8(s0, s1 + 0xD0, 5);
        *(float *)(s1 + 0xC4) = f20;
        *(int *)(s1 + 0x120) = fn_ovl_0e78(s0);
        buf = s6 + ((s3 << 6) + 0x200000);
        fn_ovl_3170(buf, g_res_data, g_tbl_540);
        *(void **)(s1 + 0x110) = buf;
        *(void **)(s1 + 0x108) = g_tbl_478;
        s1 += 0x130;
    }

    fn_ovl_44e8(0.0f, 0.0f);
    fn_ovl_4db8(g_fade_5010, 1.0f, 0.33f, 8, 0);
    *(float *)(g_fade_5010 + 0x18) = 0.45f;
    fn_ovl_4db8(g_fade_5010 + 0x40, 0.33f, 1.0f, 0x10, s2 + 0x14);
    *(float *)(g_fade_5010 + 0x48) = 0.45f;
    fn_ovl_2ef8(1);
    fn_ovl_3850(fn_ovl_3688(fn_ovl_0c08));
    return 0;
}
