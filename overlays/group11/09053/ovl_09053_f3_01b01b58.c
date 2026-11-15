#include "p7_overlay.h"

/* F3 TU rank 73. */

float func_01B01B58(int idx)
{
    int chr;
    void *h;

    if (D_01B005A0.mode == 0) {
        chr = func_01B01598(idx);
        if (chr < 32) {
            return MsGetChrWidth(chr);
        }
    }
    h = func_01B01630(idx);
    return func_001109E0(h) * Ch_GetScaleZ(h);
}
