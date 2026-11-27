#include "common.h"

typedef struct {
    u8 *obj;
} Arg0828;

extern void g_fn_3ee0(void *);
extern void g_fn_3dd8(void *);
extern void g_fn_90a8(void *);
extern void g_fn_9000(void *);

void func_01B10828(Arg0828 *a)
{
    void *m[4];
    u8 *obj = a->obj;
    u8 *p = obj + 0xC0;
    s32 i;

    for (i = 0; i < *(s32 *)(obj + 0x1720); i++) {
        u8 *sub;
        m[0] = p;
        g_fn_3ee0(&m[0]);
        sub = p + 0xA0;
        m[1] = p;
        g_fn_3dd8(&m[1]);
        m[2] = sub;
        g_fn_90a8(&m[2]);
        p += 0x290;
        m[3] = sub;
        g_fn_9000(&m[3]);
    }
}
