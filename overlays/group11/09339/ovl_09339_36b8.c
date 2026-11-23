/* Shared 09339-family -O0 update helper (136 B, 6 containers). */
#include "common.h"

typedef struct {
    u8 pad00[0x20];
    u8 pos20[0x10];
    u32 w30;
    u32 w34;
} OvlObj;

typedef struct {
    OvlObj *obj;
    u8 flag04;
} OvlArgs;

extern void fn_ovl_3840(OvlArgs *);
extern void Ch_OptposGet(u32, u32, void *);

void ovl_09339_36b8(register OvlArgs *a0)
{
    OvlObj *p;
    int dummy;

    fn_ovl_3840(a0);
    if (!(a0->flag04 & 1)) {
        return;
    }
    p = a0->obj;
    Ch_OptposGet(p->w30, p->w34, p->pos20);
    dummy = 0;
}
