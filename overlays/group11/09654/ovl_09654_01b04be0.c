#include "common.h"

extern u8 *g_state_db20;
extern u8 g_sym_d9d8[];
extern u32 g_tbl_0770[];

extern void g_fn_6aa0(int, int, void *);
extern void g_fn_8be0(void *);
extern void g_fn_43c0(void *, void *, void *);
extern void g_fn_4398(void *);
extern void *g_fn_8b60(void *);
extern void g_fn_8d28(void *);
extern u8 *g_fn_d4a8(void);
extern float func_002B3DF8(float);
extern void g_fn_8ec0(void *, void *, int, int, int, int, float);
extern void g_fn_6a40(int, u32, int, void *);
extern float g_fn_69f0(int);
extern void *g_fn_63e8(int);
extern void func_00109030(void *, void *, void *);
extern void g_fn_4bd0(void *);

void func_01B04BE0(void *a0)
{
    u8 buf0[0x10];
    u8 buf1[0x10];
    u8 *st = g_state_db20;
    u8 *sub;

    g_fn_6aa0(0, 12, buf0);
    g_fn_6aa0(0, 11, buf1);
    sub = st + 0x1350;
    if (*(s32 *)(sub + 0x130) > 0) {
        *(s32 *)(sub + 0x130) -= 1;
    } else if (sub[0x127] >= 2) {
        sub[0x127] -= 2;
    } else {
        g_fn_8be0(a0);
        return;
    }
    g_fn_43c0(sub, buf1, buf0);
}

void func_01B04C88(void)
{
    g_fn_4398(g_state_db20 + 0x1350);
    g_fn_8d28(g_fn_8b60(func_01B04BE0));
}

void func_01B04CC0(void *a0, int a1)
{
    if (a1 < 2) {
        u8 *st = g_state_db20;
        u8 *obj = g_fn_d4a8();
        if (obj != 0) {
            float r = func_002B3DF8(1.0f);
            g_fn_8ec0(g_sym_d9d8, obj, 4, 0, 0, 0, (r + 0.5f) * 0.01f);
            {
                register u32 *tbl __asm__("$3") = g_tbl_0770;
                g_fn_6a40(-1, tbl[a1], 0, obj + 0xD0);
            }
            *(float *)(obj + 0xC4) = *(float *)(st + 0x1B08);
            *(float *)(obj + 0xD4) = g_fn_69f0(-1);
        }
    }
}

void func_01B04D98(void)
{
    func_00109030(g_fn_63e8(-1), func_01B04CC0, 0);
}

void func_01B04DC8(void)
{
    func_00109030(g_fn_63e8(-1), 0, 0);
}

void func_01B04DF0(u8 *a0)
{
    s32 cnt = *(s32 *)(a0 + 0x2C) + 1;
    *(s32 *)(a0 + 0x2C) = cnt;
    if ((cnt & 1) == 0) {
        u8 *st = g_state_db20;
        u8 *obj = g_fn_d4a8();
        if (obj != 0) {
            float r = func_002B3DF8(1.0f);
            g_fn_8ec0(g_sym_d9d8, obj, 3, 0, 0, 0, (r + 0.5f) * 0.015f);
            g_fn_4bd0(obj + 0xD0);
            *(float *)(obj + 0xC4) = *(float *)(st + 0x1B08);
            *(float *)(obj + 0xD4) = g_fn_69f0(-1);
        }
    }
}
