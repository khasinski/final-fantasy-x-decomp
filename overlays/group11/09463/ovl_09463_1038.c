/* 09463 callback clear helper (56 B, 09463 @ 0x01B01038). */

#include "common.h"

typedef struct {
    u8 pad00[0x104];
    void *p104;
} EffSlot;

extern u8 g_c420[];
extern void func_01B036E0(void *, int, int);

void ovl_09463_1038(EffSlot *o)
{
    func_01B036E0(g_c420, 1, 0);
    o->p104 = 0;
}
