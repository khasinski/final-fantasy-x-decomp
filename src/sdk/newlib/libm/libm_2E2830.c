/* tu_355 0x2e2830-0x2e4250: medium; unk_2E2220; split at 0x2e2830: library split: 0x2E2220-0x2E2830 is libipu (IPU registers, IPU DMA channels), 0x2E2830 starts the fdlibm double math (calls fp-bit, 0x7FF00000 masks) (config/tu_map.tsv) */
#include "common.h"
#include "ffx/r7.h"
#include "ffx/q7.h"
#include "ffx/u5.h"
#include "ffx/w11.h"

#define INSERT_WORDS(d, ix0, ix1) \
    do { ieee_double_shape_type iw_u; iw_u.parts.msw = (ix0); iw_u.parts.lsw = (ix1); (d) = iw_u.value; } while (0)

extern const double D_00577038[];
double func_002EBC70(double arg_a, double arg_b);
double func_002E4770(double x);
double func_002E76D0(double x);
double func_002E7C30(double x);

#define GET_HIGH_WORD(i, d) \
    do { ieee_double_shape_type gh_u; gh_u.value = (d); (i) = gh_u.parts.msw; } while (0)
#define GET_LOW_WORD(i, d) \
    do { ieee_double_shape_type gl_u; gl_u.value = (d); (i) = gl_u.parts.lsw; } while (0)
#define SET_LOW_WORD(d, v) \
    do { ieee_double_shape_type sl_u; sl_u.value = (d); sl_u.parts.lsw = (v); (d) = sl_u.value; } while (0)
#define SET_HIGH_WORD(d, v) \
    do { ieee_double_shape_type sh_u; sh_u.value = (d); sh_u.parts.msw = (v); (d) = sh_u.value; } while (0)

#define one 1.00000000000000000000e+00
#define pi 3.14159265358979311600e+00
#define pio2_hi 1.57079632679489655800e+00
#define pio2_lo 6.12323399573676603587e-17
#define pS0 1.66666666666666657415e-01
#define pS1 -3.25565818622400915405e-01
#define pS2 2.01212532134862925881e-01
#define pS3 -4.00555345006794114027e-02
#define pS4 7.91534994289814532176e-04
#define pS5 3.47933107596021167570e-05
#define qS1 -2.40339491173441421878e+00
#define qS2 2.02094576023350569471e+00
#define qS3 -6.88283971605453293030e-01
#define qS4 7.70381505559019352791e-02

double func_002E2830(double x)
{
    double z, p, q, r, w, s, c, df;
    s32 hx, ix;

    GET_HIGH_WORD(hx, x);
    ix = hx & 0x7fffffff;
    if (ix >= 0x3ff00000) {
        u32 lx;
        GET_LOW_WORD(lx, x);
        if (((ix - 0x3ff00000) | lx) == 0) {
            if (hx > 0) {
                return 0.0;
            } else {
                return pi + 2.0 * pio2_lo;
            }
        }
        return (x - x) / (x - x);
    }
    if (ix < 0x3fe00000) {
        if (ix <= 0x3c600000) {
            return pio2_hi + pio2_lo;
        }
        z = x * x;
        p = z * (pS0 + z * (pS1 + z * (pS2 + z * (pS3 + z * (pS4 + z * pS5)))));
        q = one + z * (qS1 + z * (qS2 + z * (qS3 + z * qS4)));
        r = p / q;
        return pio2_hi - (x - (pio2_lo - x * r));
    } else if (hx < 0) {
        z = (one + x) * 0.5;
        p = z * (pS0 + z * (pS1 + z * (pS2 + z * (pS3 + z * (pS4 + z * pS5)))));
        q = one + z * (qS1 + z * (qS2 + z * (qS3 + z * qS4)));
        s = func_002E4770(z);
        r = p / q;
        w = r * s - pio2_lo;
        return pi - 2.0 * (s + w);
    } else {
        z = (one - x) * 0.5;
        s = func_002E4770(z);
        df = s;
        SET_LOW_WORD(df, 0);
        c = (z - df * df) / (s + df);
        p = z * (pS0 + z * (pS1 + z * (pS2 + z * (pS3 + z * (pS4 + z * pS5)))));
        q = one + z * (qS1 + z * (qS2 + z * (qS3 + z * qS4)));
        r = p / q;
        w = r * s + c;
        return 2.0 * (df + w);
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

static const double tiny = 1.0e-300;
static const double zero = 0.0;
static const double pi_o_4 = 7.8539816339744827900E-01;
static const double pi_o_2 = 1.5707963267948965580E+00;
static const double pi = 3.1415926535897931160E+00;
static const double pi_lo = 1.2246467991473531772E-16;

double func_002E2E00(double y, double x)
{
    double z;
    s32 k, m, hx, hy, ix, iy;
    u32 lx, ly;

    EXTRACT_WORDS(hx, lx, x);
    ix = hx & 0x7fffffff;
    EXTRACT_WORDS(hy, ly, y);
    iy = hy & 0x7fffffff;
    if (((ix | ((lx | -lx) >> 31)) > 0x7ff00000) ||
        ((iy | ((ly | -ly) >> 31)) > 0x7ff00000)) {
        return x + y;
    }
    if (((hx - 0x3ff00000) | lx) == 0) {
        return func_002E76D0(y);
    }
    m = ((hy >> 31) & 1) | ((hx >> 30) & 2);
    if ((iy | ly) == 0) {
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
    if ((ix | lx) == 0) {
        return (hy < 0) ? -pi_o_2 - tiny : pi_o_2 + tiny;
    }
    if (ix == 0x7ff00000) {
        if (iy == 0x7ff00000) {
            switch (m) {
            case 0:
                return pi_o_4 + tiny;
            case 1:
                return -pi_o_4 - tiny;
            case 2:
                return 3.0 * pi_o_4 + tiny;
            case 3:
                return -3.0 * pi_o_4 - tiny;
            }
        } else {
            switch (m) {
            case 0:
                return zero;
            case 1:
                return -zero;
            case 2:
                return pi + tiny;
            case 3:
                return -pi - tiny;
            }
        }
    }
    if (iy == 0x7ff00000) {
        return (hy < 0) ? -pi_o_2 - tiny : pi_o_2 + tiny;
    }
    k = (iy - ix) >> 20;
    if (k > 60) {
        z = pi_o_2 + 0.5 * pi_lo;
    } else if (hx < 0 && k < -60) {
        z = 0.0;
    } else {
        z = func_002E76D0(func_002E7C30(y / x));
    }
    switch (m) {
    case 0:
        return z;
    case 1: {
        u32 zh;
        GET_HIGH_WORD(zh, z);
        SET_HIGH_WORD(z, zh ^ 0x80000000);
    }
        return z;
    case 2:
        return pi - (z - pi_lo);
    default:
        return (z - pi_lo) - pi;
    }
}

double func_002E3138(double x, double y)
{
    s32 n, hx, hy, hz, ix, iy, sx, i;
    u32 lx, ly, lz;

    EXTRACT_WORDS(hx, lx, x);
    EXTRACT_WORDS(hy, ly, y);
    sx = hx & 0x80000000;
    hx ^= sx;
    hy &= 0x7fffffff;
    if ((hy | ly) == 0 || (hx >= 0x7ff00000) || ((hy | ((ly | -ly) >> 31)) > 0x7ff00000)) {
        double tmp = func_002EBC70(x, y);
        return func_002EBF18(tmp, tmp);
    }
    if (hx <= hy) {
        if ((hx < hy) || (lx < ly)) {
            return x;
        }
        if (lx == ly) {
            return D_00577038[(u32)sx >> 31];
        }
    }
    if (hx < 0x00100000) {
        if (hx == 0) {
            for (ix = -1043, i = lx; i > 0; i <<= 1) {
                ix -= 1;
            }
        } else {
            for (ix = -1022, i = (hx << 11); i > 0; i <<= 1) {
                ix -= 1;
            }
        }
    } else {
        ix = (hx >> 20) - 1023;
    }
    if (hy < 0x00100000) {
        if (hy == 0) {
            for (iy = -1043, i = ly; i > 0; i <<= 1) {
                iy -= 1;
            }
        } else {
            for (iy = -1022, i = (hy << 11); i > 0; i <<= 1) {
                iy -= 1;
            }
        }
    } else {
        iy = (hy >> 20) - 1023;
    }
    if (ix >= -1022) {
        hx = 0x00100000 | (0x000fffff & hx);
    } else {
        n = -1022 - ix;
        if (n <= 31) {
            hx = (hx << n) | (lx >> (32 - n));
            lx <<= n;
        } else {
            hx = lx << (n - 32);
            lx = 0;
        }
    }
    if (iy >= -1022) {
        hy = 0x00100000 | (0x000fffff & hy);
    } else {
        n = -1022 - iy;
        if (n <= 31) {
            hy = (hy << n) | (ly >> (32 - n));
            ly <<= n;
        } else {
            hy = ly << (n - 32);
            ly = 0;
        }
    }
    n = ix - iy;
    while (n--) {
        hz = hx - hy;
        lz = lx - ly;
        if (lx < ly) {
            hz -= 1;
        }
        if (hz < 0) {
            hx = hx + hx + (lx >> 31);
            lx = lx + lx;
        } else {
            if ((hz | lz) == 0) {
                return D_00577038[(u32)sx >> 31];
            }
            hx = hz + hz + (lz >> 31);
            lx = lz + lz;
        }
    }
    hz = hx - hy;
    lz = lx - ly;
    if (lx < ly) {
        hz -= 1;
    }
    if (hz >= 0) {
        hx = hz;
        lx = lz;
    }
    if ((hx | lx) == 0) {
        return D_00577038[(u32)sx >> 31];
    }
    while (hx < 0x00100000) {
        hx = hx + hx + (lx >> 31);
        lx = lx + lx;
        iy -= 1;
    }
    if (iy >= -1022) {
        hx = ((hx - 0x00100000) | ((iy + 1023) << 20));
        INSERT_WORDS(x, hx | sx, lx);
    } else {
        n = -1022 - iy;
        if (n <= 20) {
            lx = (lx >> n) | ((u32)hx << (32 - n));
            hx >>= n;
        } else if (n <= 31) {
            lx = (hx << (32 - n)) | (lx >> n);
            hx = sx;
        } else {
            lx = hx >> (n - 32);
            hx = sx;
        }
        INSERT_WORDS(x, hx | sx, lx);
    }
    return x;
}

INCLUDE_ASM("build/ee_asm/sdk/newlib/libm/libm_2E2830", func_002E3528);
