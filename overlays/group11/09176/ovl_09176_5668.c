/* Shared 32-vector quadword init (124 B, 99 containers). */

#include "vu0.h"

typedef unsigned int u128 __attribute__((mode(TI)));

typedef struct {
    u128 pad00;
    u128 vecs[0x20];
    u32 w210;
    int w214;
    float f218;
    float f21C;
    int pad220;
    float w224;
} OvlObj5668;

extern void fn_ovl_5488(OvlObj5668 *, int);

void ovl_09176_5668(OvlObj5668 *obj, int a1, u128 *src)
{
    int i;
    int cond;

    fn_ovl_5488(obj, a1);
    obj->w214 = 0;
    obj->w210 = 0x80808080U;
    obj->w224 = 0.0f;
    obj->f218 = 1.0f;
    obj->f21C = 1.0f;
    i = 0;
    do {
        MMI_COPY_LQ_A3(&obj->vecs[i], src);
        MMI_COPY_SQ_A3(&obj->vecs[i]);
        i++;
        cond = (i < 0x20);
        VU0_OP("nop");
    } while (cond);
}
