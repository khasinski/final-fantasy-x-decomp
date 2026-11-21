/* Shared P6 -O0 helper: gated dispatch on node b1B flag and global enable. */
#include "p6_overlay.h"

extern int D_01B00040;
extern void func_01B02050(P6Iter *it);

void func_01B01E20(P6Iter *it)
{
    if (it->cur->b1B != 0 && D_01B00040 != 0) {
        return;
    } else {
        func_01B02050(it);
    }
}
