/* tu_357 0x2e7c68-0x2e7e60: high; unk_2E7C68 (config/tu_map.tsv) */
#include "common.h"
#include "ffx/r7.h"
#include "ffx/q7.h"
#include "ffx/w11.h"

int func_002E7C68(double x)
{
    int hx;

    GET_HIGH_WORD(hx, x);
    return (u32)((hx & 0x7fffffff) - 0x7ff00000) >> 31;
}

#define INSERT_WORDS(d, ix0, ix1) \
    do { ieee_double_shape_type iw_u; iw_u.parts.msw = (ix0); iw_u.parts.lsw = (ix1); (d) = iw_u.value; } while (0)

extern const double D_00577B78;

double func_002E7C88(double x)
{
    int i0, i1, j0;
    unsigned int i, j;

    EXTRACT_WORDS(i0, i1, x);
    j0 = ((i0 >> 20) & 0x7ff) - 0x3ff;
    if (j0 < 20) {
        if (j0 < 0) {
            if (func_002EC198(func_002EBBB0(x, D_00577B78), 0.0) > 0) {
                if (i0 >= 0) {
                    i0 = i1 = 0;
                } else if (((i0 & 0x7fffffff) | i1) != 0) {
                    i0 = 0xbff00000;
                    i1 = 0;
                }
            }
        } else {
            i = (0x000fffff) >> j0;
            if (((i0 & i) | i1) == 0) {
                return x;
            }
            if (func_002EC198(func_002EBBB0(x, D_00577B78), 0.0) > 0) {
                if (i0 < 0) {
                    i0 += (0x00100000) >> j0;
                }
                i0 &= (~i);
                i1 = 0;
            }
        }
    } else if (j0 > 51) {
        if (j0 == 0x400) {
            return func_002EBBB0(x, x);
        } else {
            return x;
        }
    } else {
        i = ((unsigned int)(0xffffffff)) >> (j0 - 20);
        if ((i1 & i) == 0) {
            return x;
        }
        if (func_002EC198(func_002EBBB0(x, D_00577B78), 0.0) > 0) {
            if (i0 < 0) {
                if (j0 == 20) {
                    i0 += 1;
                } else {
                    j = i1 + (1 << (52 - j0));
                    if (j < (unsigned int)i1) {
                        i0 += 1;
                    }
                    i1 = j;
                }
            }
            i1 &= (~i);
        }
    }
    INSERT_WORDS(x, i0, i1);
    return x;
}
