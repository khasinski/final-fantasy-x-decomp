#include "p7_overlay.h"

/* PARKED (P7): func_01B01600 / func_01B03A88 (F3 TU ranks 53 and 111): 16-byte copies
 *   func_01B03600: lui v0; addiu v0,%lo(D_01B05F00); lq a3,0(v0); jr ra; sq a3,0(a0)
 *   func_01B03A88: lq a3,0(a1); jr ra; sq a3,0(a0)
 * A u_long128 assignment gives the same code with temp v1 / v0 instead of a3; a 16-byte
 * aligned struct copy gives ld/sd pairs. The fixed a3 suggests an inline-asm vector copy
 * macro (sceVu0CopyVector style), which docs/ASM_POLICY.md does not allow. */

extern u_long128 D_01B05F00;

void func_01B03600(u_long128 *out)
{
    *out = D_01B05F00;
}

void func_01B03A88(u_long128 *dst, u_long128 *src)
{
    *dst = *src;
}
