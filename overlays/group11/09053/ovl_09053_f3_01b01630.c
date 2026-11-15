#include "p7_overlay.h"

/* F3 TU rank 82. */

void *func_01B01630(int idx)
{
    P7Targets *t = &D_01B005A0;

    if (idx == -1) {
        return t->handle;
    }
    return t->handles[t->list[idx]];
}

void *func_01B01668(int idx, int a1)
{
    return MsGetWeaponHandle(func_01B01598(idx), a1);
}
