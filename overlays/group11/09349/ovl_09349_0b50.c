#include "common.h"
#include "vu0.h"

typedef struct {
    u8 pad00[0xC4];
    float fC4;
    u8 padC8[0x8];
    float pos[4];
    u8 padE0[0x8];
    float fE8;
    u8 padEC[0x18];
    void *p104;
    u8 pad108[0x8];
    void *p110;
    u8 pad114[0x1C];
} OvlObj;

typedef struct {
    u8 pad00[0xC4];
    float fC4;
    u8 padC8[0x8];
    float pos[4];
    u8 padE0[0x30];
    void *p110;
    u8 pad114[0x24C];
    float pos2[4];
    u8 pad370[0x10];
    void *mgr;
    void *cb1;
    void *cb2;
    u8 pad38C[0x8];
    int w394;
    u8 pad398[0x4];
    s16 h39C;
    u8 pad39E[0x2];
} OvlProj;

extern u8 g_heap_base[];
extern u8 *g_ptr_7010;
extern u8 *g_ptr_7014;
extern u8 *g_ptr_69d0;
extern int g_69d4;
extern int g_69d8;
extern u8 g_mgr_69e0[];
extern OvlObj g_objs_6a20[4];
extern OvlProj g_proj_65b0;
extern u8 g_fade_6950[];
extern u8 g_data_6588[];
extern u8 g_res_data[];
extern u8 g_hdr_40[];
extern u8 g_data_06a8[];
extern u8 g_data_06c0[];
extern u8 g_data_06d8[];
extern u8 fn_1070[];
extern u8 fn_10a0[];
extern u8 fn_1188[];
extern u8 fn_11a0[];
extern u8 fn_45b0[];

extern void *op_oef2_a_get(void *, int, int);
extern void fn_3f38(void *, void *, void *, int);
extern float fn_1b40(int);
extern void fn_16f0(int, void *, int);
extern void fn_4d40(void *, void *, void *);
extern void fn_4e48(void *, void *, void *);
extern void fn_4010(void *, void *, int, float, int, int, void *);
extern void fn_3798(void *, void *, void *);
extern void fn_5a48(void *, int, float);
extern float fn_4ee8(void *, void *);
extern void fn_5da8(void *, float, float, int, int);
extern void fn_3520(int);
extern void fn_30d8(int, void *, void *);
extern u8 *fn_3cb0(void *);
extern void fn_3e78(void *);
extern void fn_5fe0(void *, int);

static inline void copy_vec(void *dst, void *src)
{
    MMI_COPY_LQ_A3(dst, src);
    MMI_COPY_SQ_A3(dst);
}

#define COPY_VEC(dst_ptr, src_ptr) copy_vec((dst_ptr), (src_ptr))

int ovl_09349_0b50(void)
{
    float v00[4];
    float v10[4];
    float v20[4];
    float v30[4];
    u8 *heap = g_heap_base;
    u8 *mgr;
    OvlObj *obj;
    float y;
    int t;
    float ang;
    u8 *buf;
    u8 *p;

    register float *p10 __asm__("$19");
    register float *p20 __asm__("$20");

    g_ptr_7010 = heap;
    g_ptr_7014 = heap + 0x40000;
    g_ptr_69d0 = heap + 0x140000;
    mgr = g_mgr_69e0;
    *(void **)(mgr + 0x2C) = op_oef2_a_get(g_res_data, 8, 0);
    fn_3f38(mgr, g_hdr_40, g_ptr_7010, 0x40000);

    y = fn_1b40(0) - 10.0f;
    p10 = v10;
    fn_16f0(-1, p10, 0);
    p20 = v20;
    fn_16f0(0, p20, 4);
    v20[1] -= 2.0f;
    if (v20[1] > y) {
        v20[1] = y;
    }
    fn_4d40(v00, p10, p20);
    v30[0] = 0.0f;
    v30[1] = -13.0f;
    v30[2] = -12.0f;
    fn_4e48(v00, p10, v30);

    obj = &g_objs_6a20[2];
    fn_4010(mgr, obj, 2, 0.03f, 0, 0, 0);
    fn_16f0(-1, obj->pos, 0);
    obj->fC4 = v00[1];
    obj->p104 = fn_1188;

    obj = (OvlObj *)&g_proj_65b0;
    fn_4010(mgr, obj, 4, 0.1f, 24, 0, 0);
    {
        register void *d __asm__("$3") = ((OvlProj *)obj)->pos;
        MMI_COPY_LQ_A3(d, p10);
        MMI_COPY_SQ_A3(d);
    }
    ((OvlProj *)obj)->fC4 = v00[1];
    {
        register int off __asm__("$16") = 0x168000;
        buf = heap + off;
    }
    fn_3798(buf, g_res_data, g_data_06a8);
    ((OvlProj *)obj)->p110 = buf;
    COPY_VEC(((OvlProj *)obj)->pos2, p20);
    ((OvlProj *)obj)->mgr = mgr;
    ((OvlProj *)obj)->cb1 = fn_11a0;
    ((OvlProj *)obj)->cb2 = 0;
    ((OvlProj *)obj)->w394 = 45;
    ((OvlProj *)obj)->h39C = 0;
    fn_5a48(obj, 0, 10.0f);

    obj = &g_objs_6a20[3];
    fn_4010(mgr, obj, 3, 0.08f, 45, 0, 0);
    fn_16f0(-1, obj->pos, 0);
    COPY_VEC(obj->pos, p10);
    obj->fC4 = v00[1];

    t = (int)(fn_4ee8(p10, p20) / 10.0f) - 1;

    obj = &g_objs_6a20[1];
    fn_4010(mgr, obj, 1, 0.1f, t + 45, 0, fn_45b0);
    COPY_VEC(obj->pos, p20);
    obj->fE8 = -6.0f;
    ang = v00[1] + 3.1415927f;
    if (ang > 3.1415927f) {
        ang -= 6.2831855f;
    } else if (ang < -3.1415927f) {
        ang += 6.2831855f;
    }
    obj->fC4 = ang;
    {
        register int off __asm__("$16") = 0x168040;
        buf = heap + off;
    }
    fn_3798(buf, g_res_data, g_data_06c0);
    obj->p110 = buf;

    obj = &g_objs_6a20[0];
    fn_4010(mgr, obj, 0, 0.25f, t + 47, 0, 0);
    {
        register void *d __asm__("$3") = obj->pos;
        MMI_COPY_LQ_A3(d, p20);
        MMI_COPY_SQ_A3(d);
    }
    obj->fE8 = -6.0f;
    ang = v00[1] + 3.1415927f;
    if (ang > 3.1415927f) {
        ang -= 6.2831855f;
    } else if (ang < -3.1415927f) {
        ang += 6.2831855f;
    }
    obj->fC4 = ang;

    fn_5da8(g_fade_6950, 1.0f, 0.5f, 30, 0);
    fn_5da8(g_fade_6950 + 0x40, 0.5f, 1.0f, 16, t + 57);
    fn_3520(1);
    g_69d4 = 24;
    g_69d8 = t + 45;
    fn_30d8(-1, g_data_6588, g_data_06d8);
    p = fn_3cb0(fn_1070);
    p[0x18] = 1;
    fn_3e78(p);
    fn_5fe0(heap + 0x160000, 256);
    p = fn_3cb0(fn_10a0);
    p[0x18] = 2;
    fn_3e78(p);
    return 0;
}
