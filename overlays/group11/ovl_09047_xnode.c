#include "p6_overlay.h"

/* F2 TU rank 167: transform component node constructor. Compiled with -O0. */

extern P6NodeVt D_01B02670;

void func_01B07790(P6AttachArg *a);

void func_01B07610(P6AttachArg *a)
{
    func_01B07790(a);
    a->node->vt = &D_01B02670;
}
