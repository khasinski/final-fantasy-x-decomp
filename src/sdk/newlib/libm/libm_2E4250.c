/* tu_356 0x2e4250-0x2e7c68: medium; unk_2E4250 (config/tu_map.tsv) */
#include "common.h"
#define D_00577A10 D_00577A10_r7
#define D_00577218 D_00577218_r7
#define D_00577320 D_00577320_r7
#include "ffx/r7.h"
#undef D_00577320
#undef D_00577218
#undef D_00577A10
extern const int D_00577A10[];
extern const int D_00577218[];
extern const int D_00577320[];

#define zero 0.0f
#define half 5.0000000000e-01f
#define two8 2.5600000000e+02f
#define invpio2 6.3661980629e-01f
#define pio2_1 1.5707855225e+00f
#define pio2_1t 1.0804334124e-05f
#define pio2_2 1.0804273188e-05f
#define pio2_2t 6.0770999344e-11f
#define pio2_3 6.0770943833e-11f
#define pio2_3t 6.1232342629e-17f
#include "ffx/q7.h"
#include "ffx/w11.h"

double func_002E7C30(double x);
int func_002E5B48(double *x, double *y, int e0, int nx, int prec, const int *ipio2);

#define GET_HIGH_WORD(i, d) \
    do { ieee_double_shape_type gh_u; gh_u.value = (d); (i) = gh_u.parts.msw; } while (0)
#define GET_LOW_WORD(i, d) \
    do { ieee_double_shape_type gl_u; gl_u.value = (d); (i) = gl_u.parts.lsw; } while (0)
#define SET_HIGH_WORD(d, v) \
    do { ieee_double_shape_type sh_u; sh_u.value = (d); sh_u.parts.msw = (v); (d) = sh_u.value; } while (0)
#define SET_LOW_WORD(d, v) \
    do { ieee_double_shape_type sl_u; sl_u.value = (d); sl_u.parts.lsw = (v); (d) = sl_u.value; } while (0)
#define INSERT_WORDS(d, ix0, ix1) \
    do { ieee_double_shape_type iw_u; iw_u.parts.msw = (ix0); iw_u.parts.lsw = (ix1); (d) = iw_u.value; } while (0)

#define d_zero 0.0
#define d_half 0.5
#define d_two24 1.67772160000000000000e+07
#define d_invpio2 6.36619772367581382433e-01
#define d_pio2_1 1.57079632673412561417e+00
#define d_pio2_1t 6.07710050650619224932e-11
#define d_pio2_2 6.07710050630396597660e-11
#define d_pio2_2t 2.02226624879595063154e-21
#define d_pio2_3 2.02226624871116645580e-21
#define d_pio2_3t 8.47842766036889956997e-32

int func_002E4250(double x, double *y)
{
    double z, w, t, r, fn;
    double tx[3];
    s32 e0, i, j, nx, n, ix, hx;
    u32 low;

    GET_HIGH_WORD(hx, x);
    ix = hx & 0x7fffffff;
    if (ix <= 0x3fe921fb) {
        y[0] = x;
        y[1] = 0;
        return 0;
    }
    if (ix < 0x4002d97c) {
        if (hx > 0) {
            z = x - d_pio2_1;
            if (ix != 0x3ff921fb) {
                y[0] = z - d_pio2_1t;
                y[1] = (z - y[0]) - d_pio2_1t;
            } else {
                z -= d_pio2_2;
                y[0] = z - d_pio2_2t;
                y[1] = (z - y[0]) - d_pio2_2t;
            }
            return 1;
        } else {
            z = x + d_pio2_1;
            if (ix != 0x3ff921fb) {
                y[0] = z + d_pio2_1t;
                y[1] = (z - y[0]) + d_pio2_1t;
            } else {
                z += d_pio2_2;
                y[0] = z + d_pio2_2t;
                y[1] = (z - y[0]) + d_pio2_2t;
            }
            return -1;
        }
    }
    if (ix <= 0x413921fb) {
        t = func_002E7C30(x);
        n = (s32)(t * d_invpio2 + d_half);
        fn = (double)n;
        r = t - fn * d_pio2_1;
        w = fn * d_pio2_1t;
        if (n < 32 && ix != D_00577320[n - 1]) {
            y[0] = r - w;
        } else {
            u32 high;
            j = ix >> 20;
            y[0] = r - w;
            GET_HIGH_WORD(high, y[0]);
            i = j - ((high >> 20) & 0x7ff);
            if (i > 16) {
                t = r;
                w = fn * d_pio2_2;
                r = t - w;
                w = fn * d_pio2_2t - ((t - r) - w);
                y[0] = r - w;
                GET_HIGH_WORD(high, y[0]);
                i = j - ((high >> 20) & 0x7ff);
                if (i > 49) {
                    t = r;
                    w = fn * d_pio2_3;
                    r = t - w;
                    w = fn * d_pio2_3t - ((t - r) - w);
                    y[0] = r - w;
                }
            }
        }
        y[1] = (r - y[0]) - w;
        if (hx < 0) {
            y[0] = -y[0];
            y[1] = -y[1];
            return -n;
        } else {
            return n;
        }
    }
    if (ix >= 0x7ff00000) {
        y[0] = y[1] = x - x;
        return 0;
    }
    GET_LOW_WORD(low, x);
    SET_LOW_WORD(z, low);
    e0 = (ix >> 20) - 1046;
    SET_HIGH_WORD(z, ix - (e0 << 20));
    for (i = 0; i < 2; i++) {
        tx[i] = (double)((s32)z);
        z = (z - tx[i]) * d_two24;
    }
    tx[2] = z;
    nx = 3;
    while (tx[nx - 1] == d_zero) {
        nx--;
    }
    n = func_002E5B48(tx, y, e0, nx, 2, D_00577218);
    if (hx < 0) {
        y[0] = -y[0];
        y[1] = -y[1];
        return -n;
    }
    return n;
}
#undef d_zero
#undef d_half
#undef d_two24
#undef d_invpio2
#undef d_pio2_1
#undef d_pio2_1t
#undef d_pio2_2
#undef d_pio2_2t
#undef d_pio2_3
#undef d_pio2_3t

double func_002EBC70(double arg_a, double arg_b);
int func_002EC198(double arg_a, double arg_b);
float func_002E57C0(float x);

#define SET_HIGH_WORD(d, v) \
    do { ieee_double_shape_type sh_u; sh_u.value = (d); sh_u.parts.msw = (v); (d) = sh_u.value; } while (0)
#define SET_LOW_WORD(d, v) \
    do { ieee_double_shape_type sl_u; sl_u.value = (d); sl_u.parts.lsw = (v); (d) = sl_u.value; } while (0)
#define INSERT_WORDS(d, ix0, ix1) \
    do { ieee_double_shape_type iw_u; iw_u.parts.msw = (ix0); iw_u.parts.lsw = (ix1); (d) = iw_u.value; } while (0)

double func_002E4770(double x)
{
    double z;
    s32 sign = (int)0x80000000;
    u32 r, t1, s1, ix1, q1;
    s32 ix0, s0, q, m, t, i;

    EXTRACT_WORDS(ix0, ix1, x);
    if ((ix0 & 0x7ff00000) == 0x7ff00000) {
        return func_002EBBB0(func_002EBC70(x, x), x);
    }
    if (ix0 <= 0) {
        if (((ix0 & (~sign)) | ix1) == 0) {
            return x;
        } else if (ix0 < 0) {
            double tmp = func_002EBC08(x, x);
            return func_002EBF18(tmp, tmp);
        }
    }
    m = (ix0 >> 20);
    if (m == 0) {
        while (ix0 == 0) {
            m -= 21;
            ix0 |= (ix1 >> 11);
            ix1 <<= 21;
        }
        for (i = 0; (ix0 & 0x00100000) == 0; i++) {
            ix0 <<= 1;
        }
        m -= i - 1;
        ix0 |= (ix1 >> (32 - i));
        ix1 <<= i;
    }
    m -= 1023;
    ix0 = (ix0 & 0x000fffff) | 0x00100000;
    if (m & 1) {
        ix0 += ix0 + ((ix1 & sign) >> 31);
        ix1 += ix1;
    }
    m >>= 1;
    ix0 += ix0 + ((ix1 & sign) >> 31);
    ix1 += ix1;
    q = q1 = s0 = s1 = 0;
    r = 0x00200000;
    while (r != 0) {
        t = s0 + r;
        if (t <= ix0) {
            s0 = t + r;
            ix0 -= t;
            q += r;
        }
        ix0 += ix0 + ((ix1 & sign) >> 31);
        ix1 += ix1;
        r >>= 1;
    }
    r = sign;
    while (r != 0) {
        t1 = s1 + r;
        t = s0;
        if ((t < ix0) || ((t == ix0) && (t1 <= ix1))) {
            s1 = t1 + r;
            if (((t1 & sign) == sign) && (s1 & sign) == 0) {
                s0 += 1;
            }
            ix0 -= t;
            if (ix1 < t1) {
                ix0 -= 1;
            }
            ix1 -= t1;
            q1 += r;
        }
        ix0 += ix0 + ((ix1 & sign) >> 31);
        ix1 += ix1;
        r >>= 1;
    }
    if ((ix0 | ix1) != 0) {
        z = 1.0 - 1.0e-300;
        if (func_002EC198(z, 1.0) >= 0) {
            z = 1.0 + 1.0e-300;
            if (q1 == (u32)0xffffffff) {
                q1 = 0;
                q += 1;
            } else if (func_002EC198(z, 1.0) > 0) {
                if (q1 == (u32)0xfffffffe) {
                    q += 1;
                }
                q1 += 2;
            } else {
                q1 += (q1 & 1);
            }
        }
    }
    ix0 = (q >> 1) + 0x3fe00000;
    ix1 = q1 >> 1;
    if ((q & 1) == 1) {
        ix1 |= sign;
    }
    ix0 += (m << 20);
    INSERT_WORDS(z, ix0, ix1);
    return z;
}

#define one 1.0000000000e+00f
#define pi 3.1415925026e+00f
#define pio2_hi 1.5707962513e+00f
#define pio2_lo 7.5497894159e-08f
#define pS0 1.6666667163e-01f
#define pS1 -3.2556581497e-01f
#define pS2 2.0121252537e-01f
#define pS3 -4.0055535734e-02f
#define pS4 7.9153501429e-04f
#define pS5 3.4793309169e-05f
#define qS1 -2.4033949375e+00f
#define qS2 2.0209457874e+00f
#define qS3 -6.8828397989e-01f
#define qS4 7.7038154006e-02f
float func_002E4A78(float x)
{
    float z, p, q, r, w, s, c, df;
    s32 hx, ix;

    GET_FLOAT_WORD(hx, x);
    ix = hx & 0x7fffffff;
    if (ix == 0x3f800000) {
        if (hx > 0) {
            return 0.0f;
        } else {
            return pi + 2.0f * pio2_lo;
        }
    } else if (ix > 0x3f800000) {
        return (x - x) / (x - x);
    }
    if (ix < 0x3f000000) {
        if (ix <= 0x23000000) {
            return pio2_hi + pio2_lo;
        }
        z = x * x;
        p = z * (pS0 + z * (pS1 + z * (pS2 + z * (pS3 + z * (pS4 + z * pS5)))));
        q = one + z * (qS1 + z * (qS2 + z * (qS3 + z * qS4)));
        r = p / q;
        return pio2_hi - (x - (pio2_lo - x * r));
    } else if (hx < 0) {
        z = (one + x) * 0.5f;
        p = z * (pS0 + z * (pS1 + z * (pS2 + z * (pS3 + z * (pS4 + z * pS5)))));
        q = one + z * (qS1 + z * (qS2 + z * (qS3 + z * qS4)));
        s = func_002E57C0(z);
        r = p / q;
        w = r * s - pio2_lo;
        return pi - 2.0f * (s + w);
    } else {
        s32 idf;

        z = (one - x) * 0.5f;
        s = func_002E57C0(z);
        df = s;
        GET_FLOAT_WORD(idf, df);
        SET_FLOAT_WORD(df, idf & 0xfffff000);
        c = (z - df * df) / (s + df);
        p = z * (pS0 + z * (pS1 + z * (pS2 + z * (pS3 + z * (pS4 + z * pS5)))));
        q = one + z * (qS1 + z * (qS2 + z * (qS3 + z * qS4)));
        r = p / q;
        w = r * s + c;
        return 2.0f * (df + w);
    }
}
#undef one
#undef pi
#undef pio2_hi
#undef pio2_lo
#undef pS0
#undef pS1
#undef pS2
#undef pS3
#undef pS4
#undef pS5
#undef qS1
#undef qS2
#undef qS3
#undef qS4

extern const float D_005774C8;
float func_002E8370(float x);
float func_002E8730(float x);

#define tiny 1.0e-30f
#define pi_o_4 7.8539818525e-01f
#define pi_o_2 1.5707963705e+00f
#define pi 3.1415925026e+00f
#define pi_lo 1.5099578832e-07f
float func_002E4EA8(float y, float x)
{
    float z;
    s32 k, m, hx, hy, ix, iy;

    GET_FLOAT_WORD(hx, x);
    ix = hx & 0x7fffffff;
    GET_FLOAT_WORD(hy, y);
    iy = hy & 0x7fffffff;
    if ((ix > 0x7f800000) || (iy > 0x7f800000)) {
        return x + y;
    }
    if (hx == 0x3f800000) {
        return func_002E8370(y);
    }
    m = ((hy >> 31) & 1) | ((hx >> 30) & 2);
    if (iy == 0) {
        switch (m) {
        case 0:
        case 1:
            return y;
        case 2:
            return pi + tiny;
        case 3:
            return -pi - tiny;
        }
    }
    if (ix == 0) {
        return (hy < 0) ? -pi_o_2 - tiny : pi_o_2 + tiny;
    }
    if (ix == 0x7f800000) {
        if (iy == 0x7f800000) {
            switch (m) {
            case 0:
                return pi_o_4 + tiny;
            case 1:
                return -pi_o_4 - tiny;
            case 2:
                return 3.0f * pi_o_4 + tiny;
            case 3:
                return -3.0f * pi_o_4 - tiny;
            }
        } else {
            switch (m) {
            case 0:
                return zero;
            case 1:
                return D_005774C8;
            case 2:
                return pi + tiny;
            case 3:
                return -pi - tiny;
            }
        }
    }
    if (iy == 0x7f800000) {
        return (hy < 0) ? -pi_o_2 - tiny : pi_o_2 + tiny;
    }
    k = (iy - ix) >> 23;
    if (k > 60) {
        z = pi_o_2 + 0.5f * pi_lo;
    } else if (hx < 0 && k < -60) {
        z = 0.0f;
    } else {
        z = func_002E8370(func_002E8730(y / x));
    }
    switch (m) {
    case 0:
        return z;
    case 1: {
        u32 zh;

        GET_FLOAT_WORD(zh, z);
        SET_FLOAT_WORD(z, zh ^ 0x80000000);
    }
        return z;
    case 2:
        return pi - (z - pi_lo);
    default:
        return (z - pi_lo) - pi;
    }
}
#undef tiny
#undef pi_o_4
#undef pi_o_2
#undef pi
#undef pi_lo

extern const float D_005774D8[];

float func_002E5190(float x, float y)
{
    s32 n, hx, hy, hz, ix, iy, sx, i;

    GET_FLOAT_WORD(hx, x);
    GET_FLOAT_WORD(hy, y);
    sx = hx & 0x80000000;
    hx ^= sx;
    hy &= 0x7fffffff;
    if (hy == 0 || (hx >= 0x7f800000) || (hy > 0x7f800000)) {
        return (x * y) / (x * y);
    }
    if (hx < hy) {
        return x;
    }
    if (hx == hy) {
        return D_005774D8[(u32)sx >> 31];
    }
    if (hx < 0x00800000) {
        for (ix = -126, i = (hx << 8); i > 0; i <<= 1) {
            ix -= 1;
        }
    } else {
        ix = (hx >> 23) - 127;
    }
    if (hy < 0x00800000) {
        for (iy = -126, i = (hy << 8); i >= 0; i <<= 1) {
            iy -= 1;
        }
    } else {
        iy = (hy >> 23) - 127;
    }
    if (ix >= -126) {
        hx = 0x00800000 | (0x007fffff & hx);
    } else {
        n = -126 - ix;
        hx = hx << n;
    }
    if (iy >= -126) {
        hy = 0x00800000 | (0x007fffff & hy);
    } else {
        n = -126 - iy;
        hy = hy << n;
    }
    n = ix - iy;
    while (n--) {
        hz = hx - hy;
        if (hz < 0) {
            hx = hx + hx;
        } else {
            if (hz == 0) {
                return D_005774D8[(u32)sx >> 31];
            }
            hx = hz + hz;
        }
    }
    hz = hx - hy;
    if (hz >= 0) {
        hx = hz;
    }
    if (hx == 0) {
        return D_005774D8[(u32)sx >> 31];
    }
    while (hx < 0x00800000) {
        hx = hx + hx;
        iy -= 1;
    }
    if (iy >= -126) {
        hx = ((hx - 0x00800000) | ((iy + 127) << 23));
        SET_FLOAT_WORD(x, hx | sx);
    } else {
        n = -126 - iy;
        hx >>= n;
        SET_FLOAT_WORD(x, hx | sx);
    }
    return x;
}
int func_002E53E0(float x, float *y)
{
    float z, w, t, r, fn;
    float tx[3];
    int e0, i, j, nx, n, ix, hx;

    GET_FLOAT_WORD(hx, x);
    ix = hx & 0x7fffffff;
    if (ix <= 0x3f490fd8) {
        y[0] = x;
        y[1] = 0;
        return 0;
    }
    if (ix < 0x4016cbe4) {
        if (hx > 0) {
            z = x - pio2_1;
            if ((ix & 0xfffffff0) != 0x3fc90fd0) {
                y[0] = z - pio2_1t;
                y[1] = (z - y[0]) - pio2_1t;
            } else {
                z -= pio2_2;
                y[0] = z - pio2_2t;
                y[1] = (z - y[0]) - pio2_2t;
            }
            return 1;
        } else {
            z = x + pio2_1;
            if ((ix & 0xfffffff0) != 0x3fc90fd0) {
                y[0] = z + pio2_1t;
                y[1] = (z - y[0]) + pio2_1t;
            } else {
                z += pio2_2;
                y[0] = z + pio2_2t;
                y[1] = (z - y[0]) + pio2_2t;
            }
            return -1;
        }
    }
    if (ix <= 0x43490f80) {
        t = func_002E8730(x);
        n = (int)(t * invpio2 + half);
        fn = (float)n;
        r = t - fn * pio2_1;
        w = fn * pio2_1t;
        if (n < 32 && (ix & 0xffffff00) != D_005777F8[n - 1]) {
            y[0] = r - w;
        } else {
            unsigned int high;

            j = ix >> 23;
            y[0] = r - w;
            GET_FLOAT_WORD(high, y[0]);
            i = j - ((high >> 23) & 0xff);
            if (i > 8) {
                t = r;
                w = fn * pio2_2;
                r = t - w;
                w = fn * pio2_2t - ((t - r) - w);
                y[0] = r - w;
                GET_FLOAT_WORD(high, y[0]);
                i = j - ((high >> 23) & 0xff);
                if (i > 25) {
                    t = r;
                    w = fn * pio2_3;
                    r = t - w;
                    w = fn * pio2_3t - ((t - r) - w);
                    y[0] = r - w;
                }
            }
        }
        y[1] = (r - y[0]) - w;
        if (hx < 0) {
            y[0] = -y[0];
            y[1] = -y[1];
            return -n;
        } else {
            return n;
        }
    }
    if (ix > 0x7f7fffff) {
        y[0] = y[1] = x - x;
        return 0;
    }
    e0 = (ix >> 23) - 134;
    SET_FLOAT_WORD(z, ix - (e0 << 23));
    for (i = 0; i < 2; i++) {
        tx[i] = (float)((int)z);
        z = (z - tx[i]) * two8;
    }
    tx[2] = z;
    nx = 3;
    while (tx[nx - 1] == zero) {
        nx--;
    }
    n = func_002E69E0(tx, y, e0, nx, 2, D_005774E0);
    if (hx < 0) {
        y[0] = -y[0];
        y[1] = -y[1];
        return -n;
    }
    return n;
}
#undef zero
#undef half
#undef two8
#undef invpio2
#undef pio2_1
#undef pio2_1t
#undef pio2_2
#undef pio2_2t
#undef pio2_3
#undef pio2_3t

float func_002E57C0(float x)
{
    float z;
    int sign = (int)0x80000000;
    int ix, s, q, m, t, i;
    unsigned int r;

    GET_FLOAT_WORD(ix, x);
    if ((ix & 0x7f800000) == 0x7f800000) {
        return x * x + x;
    }
    if (ix <= 0) {
        if ((ix & (~sign)) == 0) {
            return x;
        } else if (ix < 0) {
            return (x - x) / (x - x);
        }
    }
    m = (ix >> 23);
    if (m == 0) {
        for (i = 0; (ix & 0x00800000) == 0; i++) {
            ix <<= 1;
        }
        m -= i - 1;
    }
    m -= 127;
    ix = (ix & 0x007fffff) | 0x00800000;
    if (m & 1) {
        ix += ix;
    }
    m >>= 1;
    ix += ix;
    q = s = 0;
    r = 0x01000000;
    while (r != 0) {
        t = s + r;
        if (t <= ix) {
            s = t + r;
            ix -= t;
            q += r;
        }
        ix += ix;
        r >>= 1;
    }
    if (ix != 0) {
        q += (q & 1);
    }
    ix = (q >> 1) + 0x3f000000;
    ix += (m << 23);
    SET_FLOAT_WORD(z, ix);
    return z;
}

INCLUDE_ASM("build/ee_asm/sdk/newlib/libm/libm_2E4250", func_002E58F8);

INCLUDE_ASM("build/ee_asm/sdk/newlib/libm/libm_2E4250", func_002E5B48);

INCLUDE_ASM("build/ee_asm/sdk/newlib/libm/libm_2E4250", func_002E66B0);

#define one 1.0f
#define C1 4.1666667908e-02f
#define C2 -1.3888889225e-03f
#define C3 2.4801587642e-05f
#define C4 -2.7557314297e-07f
#define C5 2.0875723372e-09f
#define C6 -1.1359647598e-11f
float func_002E6888(float x, float y)
{
    float a, hz, z, r, qx;
    int ix;

    GET_FLOAT_WORD(ix, x);
    ix &= 0x7fffffff;
    if (ix < 0x32000000) {
        if ((int)x == 0) {
            return one;
        }
    }
    z = x * x;
    r = z * (C1 + z * (C2 + z * (C3 + z * (C4 + z * (C5 + z * C6)))));
    if (ix < 0x3e99999a) {
        return one - (0.5f * z - (z * r - x * y));
    } else {
        if (ix > 0x3f480000) {
            qx = 0.28125f;
        } else {
            SET_FLOAT_WORD(qx, ix - 0x01000000);
        }
        hz = 0.5f * z - qx;
        a = one - qx;
        return a - (hz - (z * r - x * y));
    }
}
#undef one
#undef C1
#undef C2
#undef C3
#undef C4
#undef C5
#undef C6

float func_002E8860(float x, int n); /* scalbnf */
float func_002E8750(float x); /* floorf */

#define zero 0.0f
#define one 1.0f
#define two8 2.5600000000e+02f
#define twon8 3.9062500000e-03f
int func_002E69E0(float *x, float *y, int e0, int nx, int prec, const int *ipio2)
{
    int jz, jx, jv, jp, jk, carry, n, iq[20], i, j, k, m, q0, ih;
    float z, fw, f[20], fq[20], q[20];

    jk = D_00577A10[prec];
    jp = jk;
    jx = nx - 1;
    jv = (e0 - 3) / 8;
    if (jv < 0) {
        jv = 0;
    }
    q0 = e0 - 8 * (jv + 1);
    j = jv - jx;
    m = jx + jk;
    for (i = 0; i <= m; i++, j++) {
        f[i] = (j < 0) ? zero : (float)ipio2[j];
    }
    for (i = 0; i <= jk; i++) {
        for (j = 0, fw = 0.0f; j <= jx; j++) {
            fw += x[j] * f[jx + i - j];
        }
        q[i] = fw;
    }
    jz = jk;
recompute:
    for (i = 0, j = jz, z = q[jz]; j > 0; i++, j--) {
        fw = (float)((int)(twon8 * z));
        iq[i] = (int)(z - two8 * fw);
        z = q[j - 1] + fw;
    }
    z = func_002E8860(z, q0);
    z -= 8.0f * func_002E8750(z * 0.125f);
    n = (int)z;
    z -= (float)n;
    ih = 0;
    if (q0 > 0) {
        i = (iq[jz - 1] >> (8 - q0));
        n += i;
        iq[jz - 1] -= i << (8 - q0);
        ih = iq[jz - 1] >> (7 - q0);
    } else if (q0 == 0) {
        ih = iq[jz - 1] >> 8;
    } else if (z >= 0.5f) {
        ih = 2;
    }
    if (ih > 0) {
        n += 1;
        carry = 0;
        for (i = 0; i < jz; i++) {
            j = iq[i];
            if (carry == 0) {
                if (j != 0) {
                    carry = 1;
                    iq[i] = 0x100 - j;
                }
            } else {
                iq[i] = 0xff - j;
            }
        }
        if (q0 > 0) {
            switch (q0) {
            case 1:
                iq[jz - 1] &= 0x7f;
                break;
            case 2:
                iq[jz - 1] &= 0x3f;
                break;
            }
        }
        if (ih == 2) {
            z = one - z;
            if (carry != 0) {
                z -= func_002E8860(one, q0);
            }
        }
    }
    if (z == zero) {
        j = 0;
        for (i = jz - 1; i >= jk; i--) {
            j |= iq[i];
        }
        if (j == 0) {
            for (k = 1; iq[jk - k] == 0; k++) {
            }
            for (i = jz + 1; i <= jz + k; i++) {
                f[jx + i] = (float)ipio2[jv + i];
                for (j = 0, fw = 0.0f; j <= jx; j++) {
                    fw += x[j] * f[jx + i - j];
                }
                q[i] = fw;
            }
            jz += k;
            goto recompute;
        }
    }
    if (z == 0.0f) {
        jz -= 1;
        q0 -= 8;
        while (iq[jz] == 0) {
            jz--;
            q0 -= 8;
        }
    } else {
        z = func_002E8860(z, -q0);
        if (z >= two8) {
            fw = (float)((int)(twon8 * z));
            iq[jz] = (int)(z - two8 * fw);
            jz += 1;
            q0 += 8;
            iq[jz] = (int)fw;
        } else {
            iq[jz] = (int)z;
        }
    }
    fw = func_002E8860(one, q0);
    for (i = jz; i >= 0; i--) {
        q[i] = fw * (float)iq[i];
        fw *= twon8;
    }
    for (i = jz; i >= 0; i--) {
        for (fw = 0.0f, k = 0; k <= jp && k <= jz - i; k++) {
            fw += D_00577A20[k] * q[i + k];
        }
        fq[jz - i] = fw;
    }
    switch (prec) {
    case 0:
        fw = 0.0f;
        for (i = jz; i >= 0; i--) {
            fw += fq[i];
        }
        y[0] = (ih == 0) ? fw : -fw;
        break;
    case 1:
    case 2:
        fw = 0.0f;
        for (i = jz; i >= 0; i--) {
            fw += fq[i];
        }
        y[0] = (ih == 0) ? fw : -fw;
        fw = fq[0] - fw;
        for (i = 1; i <= jz; i++) {
            fw += fq[i];
        }
        y[1] = (ih == 0) ? fw : -fw;
        break;
    case 3:
        for (i = jz; i > 0; i--) {
            fw = fq[i - 1] + fq[i];
            fq[i] += fq[i - 1] - fw;
            fq[i - 1] = fw;
        }
        for (i = jz; i > 1; i--) {
            fw = fq[i - 1] + fq[i];
            fq[i] += fq[i - 1] - fw;
            fq[i - 1] = fw;
        }
        for (fw = 0.0f, i = jz; i >= 2; i--) {
            fw += fq[i];
        }
        if (ih == 0) {
            y[0] = fq[0];
            y[1] = fq[1];
            y[2] = fw;
        } else {
            y[0] = -fq[0];
            y[1] = -fq[1];
            y[2] = -fw;
        }
    }
    return n & 7;
}
#undef zero
#undef one
#undef two8
#undef twon8

#define half 5.0000000000e-01f
#define S1 -1.6666667163e-01f
#define S2 8.3333337680e-03f
#define S3 -1.9841270114e-04f
#define S4 2.7557314297e-06f
#define S5 -2.5050759689e-08f
#define S6 1.5896910177e-10f
float func_002E7330(float x, float y, int iy)
{
    float z, r, v;
    int ix;

    GET_FLOAT_WORD(ix, x);
    ix &= 0x7fffffff;
    if (ix < 0x32000000) {
        if ((int)x == 0) {
            return x;
        }
    }
    z = x * x;
    v = z * x;
    r = S2 + z * (S3 + z * (S4 + z * (S5 + z * S6)));
    if (iy == 0) {
        return x + v * (S1 + z * r);
    } else {
        return x - ((z * (half * y - v * r) - y) - v * S1);
    }
}
#undef half
#undef S1
#undef S2
#undef S3
#undef S4
#undef S5
#undef S6

#define one 1.0f
#define pio4 7.8539812565e-01f
#define pio4lo 3.7748947079e-08f
#define T D_00577A88
float func_002E7438(float x, float y, int iy)
{
    float z, r, v, w, s;
    int ix, hx;

    GET_FLOAT_WORD(hx, x);
    ix = hx & 0x7fffffff;
    if (ix < 0x31800000) {
        if ((int)x == 0) {
            if ((ix | (iy + 1)) == 0) {
                return one / func_002E8730(x);
            } else {
                return (iy == 1) ? x : -one / x;
            }
        }
    }
    if (ix >= 0x3f2ca140) {
        if (hx < 0) {
            x = -x;
            y = -y;
        }
        z = pio4 - x;
        w = pio4lo - y;
        x = z + w;
        y = 0.0f;
    }
    z = x * x;
    w = z * z;
    r = T[1] + w * (T[3] + w * (T[5] + w * (T[7] + w * (T[9] + w * T[11]))));
    v = z * (T[2] + w * (T[4] + w * (T[6] + w * (T[8] + w * (T[10] + w * T[12])))));
    s = z * x;
    r = y + z * (s * (r + v) + y);
    r += T[0] * s;
    w = x + r;
    if (ix >= 0x3f2ca140) {
        v = (float)iy;
        return (float)(1 - ((hx >> 30) & 2)) * (v - 2.0f * (x - (w * w / (w + v) - r)));
    }
    if (iy == 1) {
        return w;
    } else {
        float a, t;
        int i;

        z = w;
        GET_FLOAT_WORD(i, z);
        SET_FLOAT_WORD(z, i & 0xfffff000);
        v = r - (z - x);
        t = a = -1.0f / w;
        GET_FLOAT_WORD(i, t);
        SET_FLOAT_WORD(t, i & 0xfffff000);
        s = 1.0f + t * z;
        return t + a * (s + t * v);
    }
}
#undef one
#undef pio4
#undef pio4lo
#undef T

/* Module: sound/misc glue, VU0 helpers */

extern const double D_00577AC0[]; /* atanhi */
extern const double D_00577AE0[]; /* atanlo */
extern const double D_00577B00[]; /* aT */
extern const double D_00577B68; /* huge */
double func_002E7C30(double x);

double func_002E76D0(double x)
{
    double w, s1, s2, z;
    s32 ix, hx, id;

    GET_HIGH_WORD(hx, x);
    ix = hx & 0x7fffffff;
    if (ix >= 0x44100000) {
        u32 low;
        do {
            ieee_double_shape_type gl_u;
            gl_u.value = x;
            low = gl_u.parts.lsw;
        } while (0);
        if (ix > 0x7ff00000 || (ix == 0x7ff00000 && low != 0)) {
            return func_002EBBB0(x, x);
        }
        if (hx > 0) {
            return func_002EBBB0(D_00577AC0[3], D_00577AE0[3]);
        } else {
            return func_002EBC08(func_002EBC08(0.0, D_00577AC0[3]), D_00577AE0[3]);
        }
    }
    if (ix < 0x3fdc0000) {
        if (ix < 0x3e200000) {
            if (func_002EC198(func_002EBBB0(x, D_00577B68), 1.0) > 0) {
                return x;
            }
        }
        id = -1;
    } else {
        x = func_002E7C30(x);
        if (ix < 0x3ff30000) {
            if (ix < 0x3fe60000) {
                id = 0;
                x = func_002EBF18(func_002EBC08(func_002EBBB0(x, x), 1.0), func_002EBBB0(x, 2.0));
            } else {
                id = 1;
                x = func_002EBF18(func_002EBC08(x, 1.0), func_002EBBB0(x, 1.0));
            }
        } else {
            if (ix < 0x40038000) {
                id = 2;
                x = func_002EBF18(func_002EBC08(x, 1.5), func_002EBBB0(func_002EBC70(x, 1.5), 1.0));
            } else {
                id = 3;
                x = func_002EBF18(-1.0, x);
            }
        }
    }
    z = func_002EBC70(x, x);
    w = func_002EBC70(z, z);
    s1 = func_002EBC70(z, func_002EBBB0(D_00577B00[0], func_002EBC70(w, func_002EBBB0(D_00577B00[2], func_002EBC70(w, func_002EBBB0(D_00577B00[4], func_002EBC70(w, func_002EBBB0(D_00577B00[6], func_002EBC70(w, func_002EBBB0(D_00577B00[8], func_002EBC70(w, D_00577B00[10])))))))))));
    s2 = func_002EBC70(w, func_002EBBB0(D_00577B00[1], func_002EBC70(w, func_002EBBB0(D_00577B00[3], func_002EBC70(w, func_002EBBB0(D_00577B00[5], func_002EBC70(w, func_002EBBB0(D_00577B00[7], func_002EBC70(w, D_00577B00[9])))))))));
    if (id < 0) {
        return func_002EBC08(x, func_002EBC70(x, func_002EBBB0(s1, s2)));
    } else {
        double res = func_002EBC08(D_00577AC0[id], func_002EBC08(func_002EBC08(func_002EBC70(x, func_002EBBB0(s1, s2)), D_00577AE0[id]), x));
        if (hx < 0) {
            return func_002EBC08(0.0, res);
        }
        return res;
    }
}

double func_002E7AE0(double x, double y)
{
    u32 hx, hy;

    GET_HIGH_WORD(hx, x);
    GET_HIGH_WORD(hy, y);
    SET_HIGH_WORD(x, (hx & 0x7fffffff) | (hy & 0x80000000));
    return x;
}

int func_002E4250(double x, double *y);
double func_002E58F8(double x, double y);
double func_002E66B0(double x, double y, int iy);

double func_002E7B28(double x)
{
    double y[2], z = 0.0;
    s32 n, ix;

    GET_HIGH_WORD(ix, x);
    ix &= 0x7fffffff;
    if (ix <= 0x3fe921fb) {
        return func_002E58F8(x, z);
    } else if (ix >= 0x7ff00000) {
        return func_002EBC08(x, x);
    } else {
        n = func_002E4250(x, y);
        switch (n & 3) {
        case 0:
            return func_002E58F8(y[0], y[1]);
        case 1:
            return func_002EBC08(0.0, func_002E66B0(y[0], y[1], 1));
        case 2:
            return func_002EBC08(0.0, func_002E58F8(y[0], y[1]));
        default:
            return func_002E66B0(y[0], y[1], 1);
        }
    }
}

double func_002E7C30(double x)
{
    u32 high;

    GET_HIGH_WORD(high, x);
    SET_HIGH_WORD(x, high & 0x7fffffff);
    return x;
}
