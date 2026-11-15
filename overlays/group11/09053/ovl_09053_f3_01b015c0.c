#include "p7_overlay.h"

/* F3 TU rank 78: index of a chr id in the target list (0 if absent). */

int func_01B015C0(int chr)
{
    int n = D_01B005A0.count;
    int found = 0;
    int i;

    for (i = 0; i < n; i++) {
        if (chr == func_01B01598(i)) {
            found = i;
            break;
        }
    }
    return found;
}
