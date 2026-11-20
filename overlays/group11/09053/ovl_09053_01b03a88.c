/* Shared 09053-family helper (TU rank 297, 225 containers): copy 16-byte vector. */
#include "p7_overlay.h"

void func_01B03A88(u_long128 *dst, u_long128 *src)
{
    /* DEBT(FAKE): register pin matches original $a3 temporary from sceVu0CopyVector-style copy. */
    register u_long128 v __asm__("$7") = *src;
    *dst = v;
}
