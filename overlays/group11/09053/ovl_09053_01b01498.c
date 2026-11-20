/* Shared 09053-family helper (TU rank 36, 215 containers): init target handles. */
#include "p7_overlay.h"

void func_01B01498(int arg)
{
    P7Targets *t = &D_01B005A0;
    int i;
    int chr;

    t->arg = arg;
    t->mode = 1;
    t->handle = func_01B03AD0(t->chr);
    for (i = 0; i < t->count; i++) {
        int *handles;

        chr = t->ids[i];
        handles = (int *)t->handles;
        /* DEBT(CAST): int store aliases t->count and u32 add matches addu s0,s3,s0. */
        *(int *)((u32)handles + (u32)(chr << 2)) = (int)func_01B03AD0(chr);
    }
    t->list = t->ids;
}
