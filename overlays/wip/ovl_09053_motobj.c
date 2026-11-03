/* PARKED (p9): func_01B056B0, F11 TU rank 133 (124 B, 99 containers). Everything matches except the
 * 32x history fill: target copies the vector with "lq a3,0(s1); sq a3,0(v1)" and an up-counting
 * slti loop, i.e. an inline-asm sceVu0CopyVector-style macro (fixed $a3, same finding as P7 in
 * ovl_09053_f3_01b03600.c), which docs/ASM_POLICY.md does not allow. u_long128 gives lq/sq via
 * v0 and a reversed loop; a 16-byte aligned struct copy gives ld/sd pairs. Same macro appears in
 * func_01B05730 (TU rank 35), which also has an inline VU0 vector-length block (lqc2/vsqrt). */

#include "p9_overlay.h"

/* Trail primitive init (family F11, TU rank 133). */

typedef struct P9MotTrail {
    P9MotHead head;
    u_long128 hist[32];
    u8 col0[4];
    u8 col1[4];
    float scale0;
    float scale1;
    float step;
    int pos;
    int len;
} P9MotTrail;

void func_01B054D0(P9MotHead *head, P9MotData *data);

void func_01B056B0(P9MotTrail *trail, P9MotData *data, u_long128 *start)
{
    int i;

    func_01B054D0(&trail->head, data);
    *(int *)trail->col0 = 0x80808080; /* DEBT(CAST): RGBA written as one word */
    *(int *)trail->col1 = 0;          /* DEBT(CAST) */
    trail->scale0 = 1.0f;
    trail->scale1 = 1.0f;
    trail->pos = 0;
    {
        u_long128 *p = trail->hist;

        for (i = 0; i < 32; i++) {
            *p++ = *start;
        }
    }
}
