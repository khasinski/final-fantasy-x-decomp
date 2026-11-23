/* Shared 09339-family -O0 init helper (136 B, 6 containers). */
#include "common.h"

typedef struct {
    void *vtbl;
    u8 pad04[0x28];
    float f2c;
    u32 w30;
    u32 w34;
} OvlObj;

typedef struct {
    OvlObj *obj;
    u32 w04;
    u32 w08;
    u32 w0c;
} OvlArgs;

extern u8 g_vtbl_0fb8[];
extern void fn_ovl_3580(OvlArgs *);

void ovl_09339_33c8(OvlArgs *a0)
{
    a0->obj->vtbl = g_vtbl_0fb8;
    fn_ovl_3580(a0);
    a0->obj->f2c = 1.0f;
    a0->obj->w30 = a0->w08;
    a0->obj->w34 = a0->w0c;
}
