#include "p7_overlay.h"

/* F3 TU rank 13, first function. The next function (func_01B02028, average of the battle-list
 * positions) uses VU0 macro instructions (lqc2/vadd/vdiv) and stays out; the rest of the TU is
 * ovl_09053_f3_01b02128.c. */

int func_01B01F18(float *out)
{
    int v = func_001AF358();
    int idx = -1;
    int *p = D_01B00568;
    int n = 0;
    int i;

    while (*p != -1) {
        if (*p == v) {
            idx = n;
            break;
        }
        p++;
        n++;
    }
    if (idx < 0) {
        func_01B01E30(out);
        return 0;
    }
    if (idx == 0) {
        for (i = 0; i < D_01B005A0.count; i++) {
            if (func_01B01C60(i) == 4228) {
                func_01B017E8(i, out, 4);
                return i;
            }
        }
    }
    func_01B017E8(0, out, 4);
    return 0;
}
