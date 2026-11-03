#include "p7_overlay.h"

/* F3 TU rank 85. */

float func_01B01BD8(int idx)
{
    float f = func_01B01B10(idx) / 17.0f;

    if (f < 1.0f) {
        f = 1.0f;
    }
    if (f > 3.0f) {
        f = 3.0f;
    }
    return f;
}
