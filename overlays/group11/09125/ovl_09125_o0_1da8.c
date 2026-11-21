/* Shared P6 -O0 helper: set node vtable and attach (76B, -O0). */
#include "p6_overlay.h"

extern P6NodeVt D_01B00180;
extern void func_01B01F60(P6AttachArg *arg);

void func_01B01DA8(P6AttachArg *a)
{
    a->node->vt = &D_01B00180;
    func_01B01F60(a);
}
