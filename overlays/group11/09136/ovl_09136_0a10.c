/* 09136 unique init function (736 B). */
#include "common.h"
#include "vu0.h"

#define copy_vec(dst, src) { \
    register void *_d __asm__("$3") = (dst); \
    __asm__("" : "+r"(_d)); \
    MMI_COPY_LQ_A3(_d, (src)); \
    MMI_COPY_SQ_A3(_d); \
}

typedef struct {
    u8 pad00[0xC4];
    float fC4;
    u8 padC8[8];
    u_long128 vD0;
    u8 padE0[0x28];
    void *p108;
    u8 pad10C[4];
    void *p110;
    u8 pad114[0x1C];
} OvlObj; /* size 0x130 */

typedef struct {
    u8 pad00[8];
    float f08;
    u8 pad0C[0xC];
    float f18;
    u8 pad1C[0x24];
} OvlFade; /* size 0x40 */

extern u8 g_heap_base[];
extern u8 *g_ptr_51f0;
extern u8 *g_ptr_55d0;
extern u8 *g_ptr_55d4;
extern u8 g_work_51f8[];
extern OvlObj g_obj_5240[];
extern u8 g_res_data[];
extern u8 g_hdr_40[];
extern void *g_tbl_450[];
extern void *g_tbl_4d8[];
extern u8 g_tbl_5a0[];
extern OvlFade g_fade_5170[];
extern u8 fn_ovl_0cf0[];
extern u8 fn_ovl_0d78[];
extern u8 fn_ovl_0df0[];
extern u8 fn_ovl_40e8[];

extern void *op_oef2_a_get(void *, int, int);
extern void fn_ovl_3a70(void *, void *, void *, int);
extern float fn_ovl_1100(int);
extern void fn_ovl_1228(int, void *, int);
extern int fn_ovl_1b68(int);
extern void fn_ovl_3b48(void *, void *, int, int, int, void *, float);
extern void fn_ovl_32d0(void *, void *, void *);
extern float fn_ovl_1678(int);
extern void fn_ovl_4648(float, float);
extern void fn_ovl_4f18(void *, int, int, float, float);
extern void fn_ovl_3058(int);
extern void *fn_ovl_37e8(void *);
extern void fn_ovl_39b0(void *);

int ovl_09136_0a10(void)
{
    u_long128 pos;
    u8 *s3 = g_heap_base;
    u8 *s2;
    OvlObj *s1;
    OvlFade *fade;
    float f20;

    g_ptr_55d0 = s3;
    g_ptr_55d4 = s3 + 0x40000;
    g_ptr_51f0 = s3 + 0xC0000;
    s2 = g_work_51f8;
    *(void **)(s2 + 0x2C) = op_oef2_a_get(g_res_data, 8, 0);
    fn_ovl_3a70(s2, g_hdr_40, g_ptr_55d0, 0x40000);
    f20 = fn_ovl_1100(-1);
    fn_ovl_1228(0, &pos, 5);

    if (fn_ovl_1b68(0) == 0) {
        u8 *s0;

        s1 = &g_obj_5240[1];
        fn_ovl_3b48(s2, s1, 1, 0, 0x12, fn_ovl_40e8, 0.4f);
        copy_vec(&s1->vD0, &pos);
        s1->fC4 = f20;
        s0 = s3 + 0x140000;
        fn_ovl_32d0(s0, g_res_data, g_tbl_5a0);
        s1->p110 = s0;

        s1 = &g_obj_5240[0];
        fn_ovl_3b48(s2, s1, 0, 0x14, 0, 0, 0.3f);
        copy_vec(&s1->vD0, &pos);
        {
            float y = fn_ovl_1678(0) - 0.5f;
            register void **tbl __asm__("$2") = g_tbl_450;
            register void *fn __asm__("$3") = fn_ovl_0d78;
            register float f12 __asm__("$f12");
            register float f13 __asm__("$f13");
            s1->fC4 = f20;
            __asm__("" : "+r"(tbl), "+r"(fn), "+f"(y) : : "memory");
            f12 = 0.94f;
            f13 = 0.0f;
            __asm__("" : "+f"(f12), "+f"(f13) : "r"(tbl), "r"(fn));
            s1->p108 = tbl;
            *(float *)((u8 *)&s1->vD0 + 4) = y;
            tbl[30] = fn;
            fn_ovl_4648(f12, f13);
        }
    } else {
        u8 *s0;

        s1 = &g_obj_5240[2];
        fn_ovl_3b48(s2, s1, 2, 0, 0x12, fn_ovl_40e8, 0.3f);
        copy_vec(&s1->vD0, &pos);
        s1->fC4 = f20;
        s0 = s3 + 0x140000;
        fn_ovl_32d0(s0, g_res_data, g_tbl_5a0);
        {
            register float f0 __asm__("$f12") = 0.0f;
            register float f13 __asm__("$f13");
            register void **tbl __asm__("$2");
            register void *fn __asm__("$3");
            __asm__("" : "+f"(f0));
            tbl = g_tbl_4d8;
            fn = fn_ovl_0df0;
            __asm__("" : "+r"(tbl), "+r"(fn) : "f"(f0));
            s1->p110 = s0;
            f13 = f0;
            __asm__("" : "+f"(f13) : "r"(tbl) : "memory");
            s1->p108 = tbl;
            tbl[30] = fn;
            fn_ovl_4648(f0, f13);
        }
    }

    fade = &g_fade_5170[0];
    fn_ovl_4f18(fade, 8, 0, 1.0f, 0.33f);
    fade->f18 = 0.45f;
    fade = &g_fade_5170[1];
    fn_ovl_4f18(fade, 0x10, 0x46, 0.33f, 1.0f);
    fade->f08 = 0.45f;
    fn_ovl_3058(1);
    fn_ovl_39b0(fn_ovl_37e8(fn_ovl_0cf0));
    return 0;
}
