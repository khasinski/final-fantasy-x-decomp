#include "p7_overlay.h"

/* F3 TU rank 60. */

float func_01B01698(int idx)
{
    return func_00110288(func_01B01630(idx));
}

float func_01B016C0(int idx)
{
    float d = 4.712389f - func_01B01698(idx);

    if (d > 3.1415927f) {
        d -= 6.2831855f;
    } else if (d < -3.1415927f) {
        d += 6.2831855f;
    }
    return d;
}
