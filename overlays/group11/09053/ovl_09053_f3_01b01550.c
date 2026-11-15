#include "p7_overlay.h"

/* F3 TU rank 77. */

void func_01B01550(int arg, int a1)
{
    func_01B03B08(arg, &D_01B005A0, MsGetTargetSortList(arg, &D_01B005A0.count, a1));
}

int func_01B01598(int idx)
{
    P7Targets *t = &D_01B005A0;
    int chr;

    if (idx == -1) {
        chr = t->chr;
    } else {
        chr = t->list[idx];
    }
    return chr;
}
