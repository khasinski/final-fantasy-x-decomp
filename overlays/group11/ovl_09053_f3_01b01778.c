#include "p7_overlay.h"

/* F3 TU rank 36, first function. The second one (func_01B017E8) is a switch with a .rodata
 * jump table, which verify_overlays.py cannot relocate (it links .text only). */

void func_01B01778(int idx, float dir)
{
    dir = 4.712389f - dir;
    if (dir > 3.1415927f) {
        dir -= 6.2831855f;
    } else if (dir < -3.1415927f) {
        dir += 6.2831855f;
    }
    func_01B01748(idx, dir);
}
