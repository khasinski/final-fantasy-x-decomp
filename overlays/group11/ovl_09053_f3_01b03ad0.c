#include "p7_overlay.h"

/* F3 TU rank 129: handle of a chr id. */

void *func_01B03AD0(int chr)
{
    if (D_01B005A0.mode == 0) {
        return MsGetChrHandle(chr);
    }
    return func_0013B0F8(chr);
}
