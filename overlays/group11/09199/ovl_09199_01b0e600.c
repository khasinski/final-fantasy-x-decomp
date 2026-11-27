#include "common.h"

typedef struct {
    u8 *obj;
} ArgE600;

extern void g_fn_1cc8(void *);
extern void g_fn_1bc0(void *);
extern void g_fn_6e90(void *);
extern void g_fn_6de8(void *);

void func_01B0E600(ArgE600 *a)
{
    void *m[4];
    u8 *obj = a->obj;
    u8 *p = obj + 0xB0;
    s32 i;

    for (i = 0; i < *(s32 *)(obj + 0x1710); i++) {
        u8 *sub;
        m[0] = p;
        g_fn_1cc8(&m[0]);
        sub = p + 0xA0;
        m[1] = p;
        g_fn_1bc0(&m[1]);
        m[2] = sub;
        g_fn_6e90(&m[2]);
        p += 0x290;
        m[3] = sub;
        g_fn_6de8(&m[3]);
    }
}
