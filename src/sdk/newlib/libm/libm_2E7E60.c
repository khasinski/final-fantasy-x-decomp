/* tu_358 0x2e7e60-0x2e9828: low; libm/acos (config/tu_map.tsv) */
#include "common.h"
#define func_002E94A0 func_002E94A0_orig
#include "ffx/r7.h"
#include "ffx/q7.h"
#include "ffx/w11.h"
#undef func_002E94A0

int func_002E7E60(double x)
{
    int hx, lx;

    EXTRACT_WORDS(hx, lx, x);
    hx &= 0x7fffffff;
    hx |= (u32)(lx | (-lx)) >> 31;
    hx = 0x7ff00000 - hx;
    return ((u32)(hx)) >> 31;
}

int func_002E7E98(V128 *value)
{
    CALL_func_002EC198_BITS(value->hi, value->hi);
    return 0;
}

INCLUDE_ASM("build/ee_asm/sdk/newlib/libm/libm_2E7E60", func_002E7EC0);

extern const double D_00577BC0;
extern const double D_00577BC8;
double func_002E7AE0(double x, double y);
double func_002EBC70(double arg_a, double arg_b);

double func_002E80C0(double x, int n)
{
    int k, hx, lx;
    double t;

    EXTRACT_WORDS(hx, lx, x);
    k = (hx & 0x7ff00000) >> 20;
    if (k == 0) {
        if ((lx | (hx & 0x7fffffff)) == 0) {
            return x;
        }
        x = func_002EBC70(x, 1.80143985094819840000e+16);
        GET_HIGH_WORD(hx, x);
        k = ((hx & 0x7ff00000) >> 20) - 54;
        if (n < -50000) {
            return func_002EBC70(x, D_00577BC0);
        }
    }
    if (k == 0x7ff) {
        return func_002EBBB0(x, x);
    }
    k = k + n;
    if (k > 0x7fe) {
        t = D_00577BC8;
        return func_002EBC70(func_002E7AE0(t, x), t);
    }
    if (k > 0) {
        SET_HIGH_WORD(x, (hx & 0x800fffff) | (k << 20));
        return x;
    }
    if (k <= -54) {
        if (n > 50000) {
            t = D_00577BC8;
            return func_002EBC70(func_002E7AE0(t, x), t);
        } else {
            t = D_00577BC0;
            return func_002EBC70(func_002E7AE0(t, x), t);
        }
    }
    k += 54;
    SET_HIGH_WORD(x, (hx & 0x800fffff) | (k << 20));
    return func_002EBC70(x, 5.55111512312578270212e-17);
}

int func_002E4250(double x, double *y);
double func_002E58F8(double x, double y);
double func_002E66B0(double x, double y, int iy);
float func_002E7438(float x, float y, int iy);
double func_002E2830(double x);
double func_002E2E00(double y, double x);
double func_002E3138(double x, double y);
double func_002E4770(double x);
float func_002E4A78(float x);
float func_002E4EA8(float y, float x);
float func_002E5190(float x, float y);
float func_002E57C0(float x);

double func_002E8278(double x)
{
    double y[2], z = 0.0;
    int n, ix;

    GET_HIGH_WORD(ix, x);
    ix &= 0x7fffffff;
    if (ix <= 0x3fe921fb) {
        return func_002E66B0(x, z, 0);
    } else if (ix >= 0x7ff00000) {
        return func_002EBC08(x, x);
    } else {
        n = func_002E4250(x, y);
        switch (n & 3) {
        case 0:
            return func_002E66B0(y[0], y[1], 1);
        case 1:
            return func_002E58F8(y[0], y[1]);
        case 2:
            return func_002EBC08(z, func_002E66B0(y[0], y[1], 1));
        default:
            return func_002EBC08(z, func_002E58F8(y[0], y[1]));
        }
    }
}

#define one 1.0f
#define huge 1.0e30f
#define atanhi D_00577BD0
#define atanlo D_00577BE0
#define aT D_00577BF0
float func_002E8370(float x)
{
    float w, s1, s2, z;
    int ix, hx, id;

    GET_FLOAT_WORD(hx, x);
    ix = hx & 0x7fffffff;
    if (ix >= 0x50800000) {
        if (ix > 0x7f800000) {
            return x + x;
        }
        if (hx > 0) {
            return atanhi[3] + atanlo[3];
        } else {
            return -atanhi[3] - atanlo[3];
        }
    }
    if (ix < 0x3ee00000) {
        if (ix < 0x31000000) {
            if (huge + x > one) {
                return x;
            }
        }
        id = -1;
    } else {
        x = func_002E8730(x);
        if (ix < 0x3f980000) {
            if (ix < 0x3f300000) {
                id = 0;
                x = (2.0f * x - one) / (2.0f + x);
            } else {
                id = 1;
                x = (x - one) / (x + one);
            }
        } else {
            if (ix < 0x401c0000) {
                id = 2;
                x = (x - 1.5f) / (one + 1.5f * x);
            } else {
                id = 3;
                x = -1.0f / x;
            }
        }
    }
    z = x * x;
    w = z * z;
    s1 = z * (aT[0] + w * (aT[2] + w * (aT[4] + w * (aT[6] + w * (aT[8] + w * aT[10])))));
    s2 = w * (aT[1] + w * (aT[3] + w * (aT[5] + w * (aT[7] + w * aT[9]))));
    if (id < 0) {
        return x - x * (s1 + s2);
    } else {
        z = atanhi[id] - ((x * (s1 + s2) - atanlo[id]) - x);
        return (hx < 0) ? -z : z;
    }
}
#undef one
#undef huge
#undef atanhi
#undef atanlo
#undef aT

float func_002E8618(float x, float y)
{
    u32 ix, iy;

    GET_FLOAT_WORD(ix, x);
    GET_FLOAT_WORD(iy, y);
    SET_FLOAT_WORD(x, (ix & 0x7fffffff) | (iy & 0x80000000));
    return x;
}

float func_002E8648(float x)
{
    float y[2];
    float z = 0.0f;
    int n, ix;

    GET_FLOAT_WORD(ix, x);
    ix &= 0x7fffffff;
    if (ix <= 0x3f490fd8) {
        return func_002E6888(x, z);
    } else if (ix > 0x7f7fffff) {
        return x - x;
    } else {
        n = func_002E53E0(x, y);
        switch (n & 3) {
        case 0:
            return func_002E6888(y[0], y[1]);
        case 1:
            return -func_002E7330(y[0], y[1], 1);
        case 2:
            return -func_002E6888(y[0], y[1]);
        default:
            return func_002E7330(y[0], y[1], 1);
        }
    }
}

/* Module: sound/misc glue, VU0 helpers */

float func_002E8730(float x)
{
    u32 ix;

    GET_FLOAT_WORD(ix, x);
    SET_FLOAT_WORD(x, ix & 0x7fffffff);
    return x;
}

float func_002E8750(float x)
{
    int i0, j0;
    unsigned int i;

    GET_FLOAT_WORD(i0, x);
    j0 = ((i0 >> 23) & 0xff) - 0x7f;
    if (j0 < 23) {
        if (j0 < 0) {
            if (1.0e30f + x > 0.0f) {
                if (i0 >= 0) {
                    i0 = 0;
                } else if ((i0 & 0x7fffffff) != 0) {
                    i0 = 0xbf800000;
                }
            }
        } else {
            i = 0x007fffff >> j0;
            if ((i0 & i) == 0) {
                return x;
            }
            if (1.0e30f + x > 0.0f) {
                if (i0 < 0) {
                    i0 += 0x00800000 >> j0;
                }
                i0 &= ~i;
            }
        }
    } else {
        if (j0 == 0x80) {
            return x + x;
        }
        return x;
    }
    SET_FLOAT_WORD(x, i0);
    return x;
}

int func_002E8838(float x)
{
    int ix;

    GET_FLOAT_WORD(ix, x);
    ix &= 0x7fffffff;
    ix = 0x7f800000 - ix;
    return ((u32)(ix)) >> 31;
}

#define two25 3.355443200e+07f
#define twom25 2.9802322388e-08f
#define huge 1.0e+30f
#define tiny 1.0e-30f
float func_002E8860(float x, int n)
{
    int k, ix;

    GET_FLOAT_WORD(ix, x);
    k = (ix & 0x7f800000) >> 23;
    if (k == 0) {
        if ((ix & 0x7fffffff) == 0) {
            return x;
        }
        x *= two25;
        GET_FLOAT_WORD(ix, x);
        k = ((ix & 0x7f800000) >> 23) - 25;
        if (n < -50000) {
            return tiny * x;
        }
    }
    if (k == 0xff) {
        return x + x;
    }
    k = k + n;
    if (k > 0xfe) {
        return huge * func_002E8618(huge, x);
    }
    if (k > 0) {
        SET_FLOAT_WORD(x, (ix & 0x807fffff) | (k << 23));
        return x;
    }
    if (k <= -25) {
        if (n > 50000) {
            return huge * func_002E8618(huge, x);
        } else {
            return tiny * func_002E8618(tiny, x);
        }
    }
    k += 25;
    SET_FLOAT_WORD(x, (ix & 0x807fffff) | (k << 23));
    return x * twom25;
}
#undef two25
#undef twom25
#undef huge
#undef tiny

float func_002E89C0(float x)
{
    float y[2];
    float z = 0.0f;
    int n, ix;

    GET_FLOAT_WORD(ix, x);
    ix &= 0x7fffffff;
    if (ix <= 0x3f490fd8) {
        return func_002E7330(x, z, 0);
    } else if (ix > 0x7f7fffff) {
        return x - x;
    } else {
        n = func_002E53E0(x, y);
        switch (n & 3) {
        case 0:
            return func_002E7330(y[0], y[1], 1);
        case 1:
            return func_002E6888(y[0], y[1]);
        case 2:
            return -func_002E7330(y[0], y[1], 1);
        default:
            return -func_002E6888(y[0], y[1]);
        }
    }
}

typedef struct {
    int type;
    char *name;
    double arg1;
    double arg2;
    double retval;
    int err;
} LibmException;

extern const int D_00577B88;
extern char D_00577C40[];
extern char D_00577C48[];
extern char D_00577C50[];
extern double D_00577C58;
extern char D_00577C80[];
extern double D_00577C88;
extern char D_00577C90[];
extern char D_00577C98[];
extern char D_00577CA0[];
extern double D_00577CA8;
extern char D_00577CB0[];
extern double D_00577CB8;

float func_002E8AB0(float x)
{
    float y[2];
    float z = 0.0f;
    int n, ix;

    GET_FLOAT_WORD(ix, x);
    ix &= 0x7fffffff;
    if (ix <= 0x3f490fda) {
        return func_002E7438(x, z, 1);
    } else if (ix > 0x7f7fffff) {
        return x - x;
    } else {
        n = func_002E53E0(x, y);
        return func_002E7438(y[0], y[1], 1 - ((n & 1) << 1));
    }
}

double func_002E8B38(double x)
{
    double z;
    LibmException exc;

    z = func_002E2830(x);
    if (D_00577B88 == -1 || func_002E7E60(x)) {
        return z;
    }
    if (func_002EC198(func_002E7C30(x), 1.0) > 0) {
        exc.type = 1;
        exc.name = D_00577C40;
        exc.err = 0;
        exc.arg1 = exc.arg2 = x;
        exc.retval = 0.0;
        if (D_00577B88 == 2) {
            func_002ED118()->_errno = 33;
        } else if (!func_002E7E98((V128 *)&exc)) {
            func_002ED118()->_errno = 33;
        }
        if (exc.err != 0) {
            func_002ED118()->_errno = exc.err;
        }
        return exc.retval;
    } else {
        return z;
    }
}

double func_002E8C28(double y, double x)
{
    double z;
    LibmException exc;

    z = func_002E2E00(y, x);
    if (D_00577B88 == -1 || func_002E7E60(x) || func_002E7E60(y)) {
        return z;
    }
    if (func_002EC198(x, 0.0) == 0 && func_002EC198(y, 0.0) == 0) {
        exc.arg1 = y;
        exc.arg2 = x;
        exc.type = 1;
        exc.name = D_00577C48;
        exc.retval = 0.0;
        exc.err = 0;
        if (D_00577B88 == 2) {
            func_002ED118()->_errno = 33;
        } else if (!func_002E7E98((V128 *)&exc)) {
            func_002ED118()->_errno = 33;
        }
        if (exc.err != 0) {
            func_002ED118()->_errno = exc.err;
        }
        return exc.retval;
    } else {
        return z;
    }
}

double func_002E8D40(double x, double y)
{
    double z;
    LibmException exc;

    z = func_002E3138(x, y);
    if (D_00577B88 == -1 || func_002E7E60(y) || func_002E7E60(x)) {
        return z;
    }
    if (func_002EC198(y, 0.0) == 0) {
        exc.type = 1;
        exc.name = D_00577C50;
        exc.arg1 = x;
        exc.arg2 = y;
        exc.err = 0;
        if (D_00577B88 == 0) {
            exc.retval = x;
        } else {
            exc.retval = D_00577C58;
        }
        if (D_00577B88 == 2) {
            func_002ED118()->_errno = 33;
        } else if (!func_002E7E98((V128 *)&exc)) {
            func_002ED118()->_errno = 33;
        }
        if (exc.err != 0) {
            func_002ED118()->_errno = exc.err;
        }
        return exc.retval;
    } else {
        return z;
    }
}

INCLUDE_ASM("build/ee_asm/sdk/newlib/libm/libm_2E7E60", func_002E8E60);

double func_002E9290(double x)
{
    double z;
    LibmException exc;

    z = func_002E4770(x);
    if (D_00577B88 == -1 || func_002E7E60(x)) {
        return z;
    }
    if (func_002EC198(x, 0.0) < 0) {
        exc.type = 1;
        exc.name = D_00577C80;
        exc.err = 0;
        exc.arg1 = exc.arg2 = x;
        if (D_00577B88 == 0) {
            exc.retval = 0.0;
        } else {
            exc.retval = D_00577C88;
        }
        if (D_00577B88 == 2) {
            func_002ED118()->_errno = 33;
        } else if (!func_002E7E98((V128 *)&exc)) {
            func_002ED118()->_errno = 33;
        }
        if (exc.err != 0) {
            func_002ED118()->_errno = exc.err;
        }
        return exc.retval;
    } else {
        return z;
    }
}

float func_002E93A0(float x)
{
    float z;
    LibmException exc;

    z = func_002E4A78(x);
    if (D_00577B88 == -1 || func_002E8838(x)) {
        return z;
    }
    if (func_002E8730(x) > 1.0f) {
        exc.type = 1;
        exc.name = D_00577C90;
        exc.err = 0;
        exc.arg1 = exc.arg2 = func_002ED038(x);
        exc.retval = 0.0;
        if (D_00577B88 == 2) {
            func_002ED118()->_errno = 33;
        } else if (!func_002E7E98((V128 *)&exc)) {
            func_002ED118()->_errno = 33;
        }
        if (exc.err != 0) {
            func_002ED118()->_errno = exc.err;
        }
        return func_002EC440(exc.retval);
    } else {
        return z;
    }
}

float func_002E94A0(float y, float x)
{
    float z;
    LibmException exc;

    z = func_002E4EA8(y, x);
    if (D_00577B88 == -1 || func_002E8838(x) || func_002E8838(y)) {
        return z;
    }
    if (x == 0.0f && y == 0.0f) {
        exc.arg1 = func_002ED038(y);
        exc.arg2 = func_002ED038(x);
        exc.type = 1;
        exc.name = D_00577C98;
        exc.retval = 0.0;
        exc.err = 0;
        if (D_00577B88 == 2) {
            func_002ED118()->_errno = 33;
        } else if (!func_002E7E98((V128 *)&exc)) {
            func_002ED118()->_errno = 33;
        }
        if (exc.err != 0) {
            func_002ED118()->_errno = exc.err;
        }
        return func_002EC440(exc.retval);
    } else {
        return z;
    }
}

float func_002E95C8(float x, float y)
{
    float z;
    LibmException exc;

    z = func_002E5190(x, y);
    if (D_00577B88 == -1 || func_002E8838(y) || func_002E8838(x)) {
        return z;
    }
    if (y == 0.0f) {
        exc.type = 1;
        exc.name = D_00577CA0;
        exc.err = 0;
        exc.arg1 = func_002ED038(x);
        exc.arg2 = func_002ED038(y);
        if (D_00577B88 == 0) {
            exc.retval = func_002ED038(x);
        } else {
            exc.retval = D_00577CA8;
        }
        if (D_00577B88 == 2) {
            func_002ED118()->_errno = 33;
        } else if (!func_002E7E98((V128 *)&exc)) {
            func_002ED118()->_errno = 33;
        }
        if (exc.err != 0) {
            func_002ED118()->_errno = exc.err;
        }
        return func_002EC440(exc.retval);
    } else {
        return z;
    }
}

INCLUDE_ASM("build/ee_asm/sdk/newlib/libm/libm_2E7E60", func_002E9708);
