#include "vu0.h"

extern u8 *g_state_db20;
extern void g_fn_ae58(int);
extern u8 *g_fn_b188(int);
extern void func_002DD128(void *);
extern void func_002DD318(void *, void *, float);

void func_01B04250(void)
{
    u8 *st = g_state_db20;
    u8 *obj;
    u8 *dst;
    u8 *src;

    g_fn_ae58(0);
    obj = g_fn_b188(0);
    obj[0x146] = 1;
    func_002DD128(obj);
    func_002DD318(obj, obj, *(float *)(st + 0x1B08));
    dst = obj + 0x30;
    src = st + 0xC70;
    MMI_COPY_LQ_A3(dst, src);
    MMI_COPY_SQ_A3(dst);
}
