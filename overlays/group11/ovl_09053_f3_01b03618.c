#include "p7_overlay.h"

/* F3 TU rank 209. */

void func_01B03618(int on)
{
    if (on == 1) {
        yiRenderEnable(4);
    } else {
        yiRenderDisable(4);
    }
}
