#include "p7_overlay.h"

/* F3 TU rank 111 without its first function (func_01B03A88, a 16-byte lq/sq a3 copy, see
 * overlays/wip/ovl_09053_f3_01b03600.c). */

void func_01B03A98(int a0, int a1, int a2)
{
    func_0014D3F0(7, a2, op_oef2_a_get(a0, 9, a1));
}
