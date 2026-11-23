/* 09663 unique init function (596 B). */
#include "common.h"

extern u8 g_heap_base[];
extern u8 *g_ptr_4fb0;
extern u8 *g_ptr_6300;
extern u8 *g_ptr_6304;
extern u8 g_work_4fb8[];
extern u8 g_obj_5000[];
extern u8 g_res_data[];
extern u8 g_hdr_40[];
extern u8 g_tbl_428[];
extern u8 g_tbl_480[];
extern struct { u8 pad[0x1E4]; int cnt; } g_tbl_4d0;
extern u8 g_fade_4f30[];
extern u8 fn_ovl_0bb0[];
extern u8 fn_ovl_0b28[];
extern u8 fn_ovl_3ec8[];

extern void *op_oef2_a_get(void *, int, int);
extern void fn_ovl_3830(void *, void *, void *, int);
extern void fn_ovl_23d8(void *);
extern float fn_ovl_0ec0(int);
extern float func_002B3DF8(float);
extern void fn_ovl_3908(void *, void *, int, int, int, void *, float);
extern void fn_ovl_0fe8(int, void *, int);
extern int fn_ovl_0d98(int);
extern void fn_ovl_3090(void *, void *, void *);
extern void fn_ovl_4408(float, float);
extern void fn_ovl_4cd8(void *, float, float, int, int);
extern void fn_ovl_2e18(int);
extern void *fn_ovl_35a8(void *);
extern void fn_ovl_3770(void *);

int ovl_09663_08d0(void)
{
    s8 targets[16];
    u8 *s6 = g_heap_base;
    u8 *fp;
    u8 *s1;
    int s3;
    int s2 = 0;
    float f21;
    void **tbl;

    g_ptr_6300 = s6;
    g_ptr_6304 = s6 + 0x40000;
    g_ptr_4fb0 = s6 + 0x140000;
    fp = g_work_4fb8;
    *(void **)(fp + 0x2C) = op_oef2_a_get(g_res_data, 8, 0);
    fn_ovl_3830(fp, g_hdr_40, g_ptr_6300, 0x40000);
    fn_ovl_23d8(targets);
    s1 = g_obj_5000;
    f21 = fn_ovl_0ec0(-1);
    tbl = (void **)g_tbl_428;
    tbl[15] = fn_ovl_0bb0;

    for (s3 = 0; s3 < g_tbl_4d0.cnt; s3++) {
        int s0 = targets[s3];
        float r = func_002B3DF8(0.2f) * 0.2f + 0.2f;
        u8 *buf;

        fn_ovl_3908(fp, s1, 0, s2, 0x14, fn_ovl_3ec8, r);
        s2 += 0x14;
        fn_ovl_0fe8(s0, s1 + 0xD0, 5);
        *(float *)(s1 + 0xC4) = f21;
        *(int *)(s1 + 0x120) = fn_ovl_0d98(s0);
        buf = s6 + ((s3 << 6) + 0x1C0000);
        fn_ovl_3090(buf, g_res_data, g_tbl_480);
        *(void **)(s1 + 0x110) = buf;
        *(void **)(s1 + 0x108) = g_tbl_428;
        s1 += 0x130;
    }

    fn_ovl_4408(-0.2f, 0.0f);
    fn_ovl_4cd8(g_fade_4f30, 1.0f, 0.5f, 8, 0);
    fn_ovl_4cd8(g_fade_4f30 + 0x40, 0.5f, 1.0f, 0x10, s2 + 0x14);
    fn_ovl_2e18(1);
    fn_ovl_3770(fn_ovl_35a8(fn_ovl_0b28));
    return 0;
}
