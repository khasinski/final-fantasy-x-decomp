#include "p7_overlay.h"

/* PARKED (P7): func_01B01498, the second function of F3 TU rank 45 (file09053 0x01B01498,
 * 180 B). Registered unit ovl_09053_f3_01b01428.c covers only func_01B01428.
 *
 * Best attempt below; the only remaining diff is one operand order in the handles[] store:
 *   target  sll s0,s0,0x2 ; addu s0,s3,s0 ; sw v0,0(s0)     (s3 = &t->handles hoisted)
 *   built   sll s0,s0,0x2 ; addu s0,s0,s3 ; sw v0,0(s0)
 * Findings: the count reload after the store (lw 4(s2) after sw) needs the store to alias int
 * (strict aliasing at -O2), so handles[] is stored as int here (or the real field type is int);
 * a plain t->handles[chr] folds the 68 offset into the store (sw v0,68(s0)). Tried: pointer
 * local inside/outside the loop, chr[handles], byte-offset arithmetic, u32 chr. */

void func_01B01498(int arg)
{
    P7Targets *t = &D_01B005A0;
    u8 *ids;
    void **handles;
    int i;
    int chr;

    t->arg = arg;
    t->mode = 1;
    t->handle = func_01B03AD0(t->chr);
    for (i = 0; i < t->count; i++) {
        int *handles;

        chr = t->ids[i];
        handles = (int *)t->handles;
        *(int *)((u8 *)handles + chr * 4) = (int)func_01B03AD0(chr);
    }
    t->list = t->ids;
}
