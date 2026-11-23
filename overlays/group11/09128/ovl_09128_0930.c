/* 09128 unique init function (568 B). */
#include "common.h"

extern u8 g_heap_base[];
extern u8 *g_ptr_5060;
extern u8 *g_ptr_5440;
extern u8 *g_ptr_5444;
extern u8 g_work_5068[];
extern u8 g_obj_50b0[];
extern u8 g_obj_51e0[];
extern u8 g_res_data[];
extern u8 g_hdr_40[];
extern u8 g_tbl_428[];
extern u8 g_tbl_470[];
extern u8 g_tbl_4c0[];
extern u8 g_fade_4fe0[];
extern u8 fn_ovl_0bf0[];
extern u8 fn_ovl_0c68[];
extern u8 fn_ovl_0b68[];
extern u8 fn_ovl_3f60[];

extern void *op_oef2_a_get(void *, int, int);
extern void fn_ovl_38e8(void *, void *, void *, int);
extern int fn_ovl_19e0(int);
extern void fn_ovl_39c0(void *, void *, int, int, int, void *, float);
extern void fn_ovl_10a0(int, void *, int);
extern float fn_ovl_0f78(int);
extern void fn_ovl_3148(void *, void *, void *);
extern void fn_ovl_44c0(float, float);
extern void fn_ovl_4d90(void *, int, int, float, float);
extern void fn_ovl_2ed0(int);
extern void *fn_ovl_3660(void *);
extern void fn_ovl_3828(void *);

int ovl_09128_0930(void)
{
    u8 *s3 = g_heap_base;
    u8 *s2;
    u8 *s1;
    u8 *s0;

    g_ptr_5440 = s3;
    g_ptr_5444 = s3 + 0x40000;
    g_ptr_5060 = s3 + 0xC0000;
    s2 = g_work_5068;
    *(void **)(s2 + 0x2C) = op_oef2_a_get(g_res_data, 8, 0);
    fn_ovl_38e8(s2, g_hdr_40, g_ptr_5440, 0x40000);

    if (fn_ovl_19e0(0) == 0) {
        void **tbl;
        s1 = g_obj_50b0;
        fn_ovl_39c0(s2, s1, 0, 0, 0x14, fn_ovl_3f60, 0.2f);
        fn_ovl_10a0(0, s1 + 0xD0, 7);
        *(float *)(s1 + 0xD4) -= 0.5f;
        tbl = (void **)g_tbl_428;
        tbl[10] = fn_ovl_0bf0;
        *(void **)(s1 + 0x108) = tbl;
    } else {
        void **tbl;
        s1 = g_obj_51e0;
        fn_ovl_39c0(s2, s1, 1, 0, 0x14, fn_ovl_3f60, 0.2f);
        fn_ovl_10a0(0, s1 + 0xD0, 5);
        tbl = (void **)g_tbl_470;
        tbl[13] = fn_ovl_0c68;
        *(void **)(s1 + 0x108) = tbl;
    }

    *(float *)(s1 + 0xC4) = fn_ovl_0f78(-1);
    s0 = s3 + 0x140000;
    fn_ovl_3148(s0, g_res_data, g_tbl_4c0);
    *(void **)(s1 + 0x110) = s0;
    fn_ovl_44c0(-0.2f, 0.0f);
    fn_ovl_4d90(g_fade_4fe0, 8, 0, 1.0f, 0.5f);
    fn_ovl_4d90(g_fade_4fe0 + 0x40, 0x10, 0x28, 0.5f, 1.0f);
    fn_ovl_2ed0(1);
    fn_ovl_3828(fn_ovl_3660(fn_ovl_0b68));
    return 0;
}
