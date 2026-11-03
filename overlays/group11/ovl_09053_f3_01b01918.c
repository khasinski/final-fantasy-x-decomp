#include "p7_overlay.h"

/* F3 TU rank 62. */

void func_01B01918(int idx, float *pos)
{
    int chr;
    void *h;

    if (D_01B005A0.mode == 0) {
        chr = func_01B01598(idx);
        if (chr < 32) {
            MsSetChrPos(chr, pos);
            return;
        }
    }
    h = func_01B01630(idx);
    if (func_00110818(h) == 0) {
        Ch_SetPos3(h, pos[0], pos[1], pos[2]);
    } else {
        Ch_SetPos(h, pos[0], pos[2]);
    }
}
