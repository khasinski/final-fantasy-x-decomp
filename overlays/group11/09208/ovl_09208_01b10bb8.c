#include "common.h"

typedef struct {
    u8 *obj;
} Arg0BB8;

extern void g_fn_3ee0(void *);
extern void g_fn_90a8(void *);

void func_01B10BB8(Arg0BB8 *a)
{
    void *m[2];
    u8 *obj = a->obj;
    u8 *p = obj + 0xC0;
    s32 i;

    for (i = 0; i < *(s32 *)(obj + 0x1720); i++) {
        m[0] = p;
        g_fn_3ee0(&m[0]);
        m[1] = p + 0xA0;
        g_fn_90a8(&m[1]);
        p += 0x290;
    }
}
