#include "p9_overlay.h"

/* Point step dispatch (family F9, TU rank 370, file09206). */

void func_01B0A7D0(void *p);

void func_01B0A7A8(P9Ramp *r)
{
    switch (r->type) {
    case 0:
        break;
    case 1:
        func_01B0A7D0(r);
        break;
    }
}
