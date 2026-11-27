#include "vu0.h"

extern u8 *g_state_db20;
extern u8 g_sym_0aa8[];

extern void *g_fn_7ba8(int);
extern void func_00110648(void *, int);
extern void g_fn_7810(int, void *);
extern void g_fn_7d90(int, void *, void *);
extern void g_fn_72d8(int, int);
extern void func_00118098(int, u32);
extern void g_fn_cc88(void *, int, int, float, float);

void func_01B04A48(void)
{
    u8 *st = g_state_db20;
    register u8 *sym __asm__("$17") = g_sym_0aa8;
    u8 *p = st + 0xC20;
    void *h;
    u8 *dst;
    u8 *src;

    __asm__("" : "+r"(sym));
    h = g_fn_7ba8(0x3018);
    sym[0x14] = 0x20;
    *(void **)(sym + 0xC4) = h;
    func_00110648(h, 0);
    g_fn_7810(0, p);
    dst = st + 0xC80;
    src = st + 0xC60;
    MMI_COPY_LQ_A3(dst, src);
    MMI_COPY_SQ_A3(dst);
    {
        register u8 *src2 __asm__("$3") = st + 0xC70;
        st = st + 0xC90;
        MMI_COPY_LQ_A3(st, src2);
        MMI_COPY_SQ_A3(st);
    }
    g_fn_7d90(0, p, dst);
    g_fn_72d8(0, 1);
}

void func_01B04AE8(void)
{
    u8 *st = g_state_db20;

    func_00118098(0, 0x8000);
    func_00118098(1, 0x10000);
    g_fn_cc88(st + 0x17B0, 0x14, 0, 1.0f, 0.5f);
}
