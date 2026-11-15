#include "p7_overlay.h"

/* F3 TU rank 70: func_01B01D68 matrix scaled by 1000 / func_01B02EE0 (rows 0..2). */

void func_01B01DA8(int idx, void *a1, float *m)
{
    float s;

    func_01B01D68(idx, a1, m);
    s = 1000.0f / func_01B02EE0(idx);
    func_002DD998(m, m, s);
    func_002DD998(m + 4, m + 4, s);
    func_002DD998(m + 8, m + 8, s);
}
