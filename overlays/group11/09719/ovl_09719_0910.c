/* 09719 unique init function (708 B). */
#include "common.h"

extern u8 g_heap_base[];
extern u8 *g_ptr_50d0;
extern u8 *g_ptr_6420;
extern u8 *g_ptr_6424;
extern u8 g_work_50d8[];
extern u8 g_obj_5120[];
extern u8 g_res_data[];
extern u8 g_hdr_40[];
extern u8 g_tbl_428[];
extern u8 g_tbl_470[];
extern u8 g_tbl_4c0[];
extern struct { u8 pad[0x1E4]; int cnt; } g_tbl_510;
extern u8 g_fade_5050[];
extern u8 fn_ovl_0c60[];
extern u8 fn_ovl_0cd8[];
extern u8 fn_ovl_0bd8[];
extern u8 fn_ovl_3ff0[];

extern void *op_oef2_a_get(void *, int, int);
extern void fn_ovl_3958(void *, void *, void *, int);
extern void fn_ovl_2500(void *);
extern float fn_ovl_0fe8(int);
extern float func_002B3DF8(float);
extern int fn_ovl_1a50(int);
extern void fn_ovl_3a30(void *, void *, int, int, int, void *, float);
extern void fn_ovl_1110(int, void *, int);
extern int fn_ovl_0ec0(int);
extern void fn_ovl_31b8(void *, void *, void *);
extern void fn_ovl_4530(float, float);
extern void fn_ovl_4e00(void *, float, float, int, int);
extern void fn_ovl_2f40(int);
extern void *fn_ovl_36d0(void *);
extern void fn_ovl_3898(void *);

int ovl_09719_0910(void)
{
    s8 targets[16];
    u8 *s7 = g_heap_base;
    u8 *s5;
    u8 *s1;
    int s3;
    int s2 = 0;
    float f21;

    g_ptr_6420 = s7;
    g_ptr_6424 = s7 + 0x40000;
    g_ptr_50d0 = s7 + 0x140000;
    s5 = g_work_50d8;
    *(void **)(s5 + 0x2C) = op_oef2_a_get(g_res_data, 8, 0);
    fn_ovl_3958(s5, g_hdr_40, g_ptr_6420, 0x40000);
    fn_ovl_2500(targets);
    s1 = g_obj_5120;
    f21 = fn_ovl_0fe8(-1);
    {
        void **tbl0 = (void **)g_tbl_428;
        void **tbl1 = (void **)g_tbl_470;
        tbl0[10] = fn_ovl_0c60;
        tbl1[13] = fn_ovl_0cd8;
    }

    for (s3 = 0; s3 < g_tbl_510.cnt; s3++) {
        int s0 = targets[s3];
        float r = func_002B3DF8(0.2f) * 0.2f + 0.2f;
        u8 *buf;

        if (fn_ovl_1a50(s0) == 0) {
            fn_ovl_3a30(s5, s1, 0, s2, 0x14, fn_ovl_3ff0, r);
            fn_ovl_1110(s0, s1 + 0xD0, 7);
            *(void **)(s1 + 0x108) = g_tbl_428;
            *(float *)(s1 + 0xD4) -= 0.5f;
        } else {
            fn_ovl_3a30(s5, s1, 1, s2, 0x14, fn_ovl_3ff0, r);
            fn_ovl_1110(s0, s1 + 0xD0, 5);
            *(void **)(s1 + 0x108) = g_tbl_470;
        }
        *(float *)(s1 + 0xC4) = f21;
        *(int *)(s1 + 0x120) = fn_ovl_0ec0(s0);
        s2 += 0x14;
        buf = s7 + ((s3 << 6) + 0x1C0000);
        fn_ovl_31b8(buf, g_res_data, g_tbl_4c0);
        *(void **)(s1 + 0x110) = buf;
        s1 += 0x130;
    }

    fn_ovl_4530(-0.2f, 0.0f);
    fn_ovl_4e00(g_fade_5050, 1.0f, 0.5f, 8, 0);
    fn_ovl_4e00(g_fade_5050 + 0x40, 0.5f, 1.0f, 0x10, s2 + 0x14);
    fn_ovl_2f40(1);
    fn_ovl_3898(fn_ovl_36d0(fn_ovl_0bd8));
    return 0;
}
