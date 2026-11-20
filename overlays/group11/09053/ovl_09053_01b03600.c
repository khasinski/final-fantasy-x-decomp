/* Shared 09053-family helper (TU rank 180, 225 containers): copy 16-byte vector from global. */
#include "p7_overlay.h"

extern u_long128 D_01B05F00;

void func_01B03600(u_long128 *out)
{
    /* DEBT(FAKE): register pin matches original $a3 temporary from sceVu0CopyVector-style copy. */
    register u_long128 v __asm__("$7") = D_01B05F00;
    *out = v;
}
