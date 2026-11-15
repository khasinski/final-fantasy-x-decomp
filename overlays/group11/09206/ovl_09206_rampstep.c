#include "p9_overlay.h"

/* Ramp step dispatch (family F9, TU rank 260, file09206). */

void func_01B0A670(P9Ramp *r, float *out);
void func_01B0A728(P9Ramp *r, float *out);

void func_01B0A638(P9Ramp *r, float *out)
{
    switch (r->type) {
    case 0:
        break;
    case 1:
        func_01B0A670(r, out);
        break;
    case 2:
        func_01B0A728(r, out);
        break;
    }
}
