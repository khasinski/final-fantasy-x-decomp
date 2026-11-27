#include "common.h"

typedef struct {
    u8 *obj;
} ArgE9A0;

extern void g_fn_1cc8(void *);
extern void g_fn_6e90(void *);

void func_01B0E9A0(ArgE9A0 *a)
{
    void *m[2];
    u8 *obj = a->obj;
    u8 *p = obj + 0xB0;
    s32 i;

    for (i = 0; i < *(s32 *)(obj + 0x1710); i++) {
        m[0] = p;
        g_fn_1cc8(&m[0]);
        m[1] = p + 0xA0;
        g_fn_6e90(&m[1]);
        p += 0x290;
    }
}
