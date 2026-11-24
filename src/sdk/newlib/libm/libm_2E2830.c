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

static const double fmod_one = 1.0;
static const double fmod_Zero[] = { 0.0, -0.0, };

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
            return fmod_Zero[(u32)sx >> 31];
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
                return fmod_Zero[(u32)sx >> 31];
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
        return fmod_Zero[(u32)sx >> 31];
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

static const double
pow_bp[] = { 1.0, 1.5, },
pow_dp_h[] = { 0.0, 5.84962487220764160156e-01, },
pow_dp_l[] = { 0.0, 1.35003920212974897128e-08, },
pow_zero    =  0.0,
pow_one     =  1.0,
pow_two     =  2.0,
pow_two53   =  9007199254740992.0,
pow_huge    =  1.0e300,
pow_tiny    =  1.0e-300,
pow_L1      =  5.99999999999994648725e-01,
pow_L2      =  4.28571428578550184252e-01,
pow_L3      =  3.33333329818377432918e-01,
pow_L4      =  2.72728123808534006489e-01,
pow_L5      =  2.30660745775561754067e-01,
pow_L6      =  2.06975017800338417784e-01,
pow_P1      =  1.66666666666666019037e-01,
pow_P2      = -2.77777777770155933842e-03,
pow_P3      =  6.61375632143793436117e-05,
pow_P4      = -1.65339022054652515390e-06,
pow_P5      =  4.13813679705723846039e-08,
pow_lg2     =  6.93147180559945286227e-01,
pow_lg2_h   =  6.93147182464599609375e-01,
pow_lg2_l   = -1.90465429995776804525e-09,
pow_ovt     =  8.0085662595372944372e-0017,
pow_cp      =  9.61796693925975554329e-01,
pow_cp_h    =  9.61796700954437255859e-01,
pow_cp_l    = -7.02846165095275826516e-09,
pow_ivln2   =  1.44269504088896338700e+00,
pow_ivln2_h =  1.44269502162933349609e+00,
pow_ivln2_l =  1.92596299112661746887e-08;

double func_002E80C0(double x, int n);

double func_002E3528(double x, double y)
{
    double z, ax, z_h, z_l, p_h, p_l;
    double y1, t1, t2, r, s, t, u, v, w;
    s32 i, j, k, yisint, n;
    s32 hx, hy, ix, iy;
    u32 lx, ly;

    EXTRACT_WORDS(hx, lx, x);
    EXTRACT_WORDS(hy, ly, y);
    ix = hx & 0x7fffffff;
    iy = hy & 0x7fffffff;

    if ((iy | ly) == 0) {
        return pow_one;
    }

    if (ix > 0x7ff00000 || ((ix == 0x7ff00000) && (lx != 0)) ||
        iy > 0x7ff00000 || ((iy == 0x7ff00000) && (ly != 0))) {
        return x + y;
    }

    yisint = 0;
    if (hx < 0) {
        if (iy >= 0x43400000) {
            yisint = 2;
        } else if (iy >= 0x3ff00000) {
            k = (iy >> 20) - 0x3ff;
            if (k > 20) {
                j = ly >> (52 - k);
                if ((j << (52 - k)) == ly) {
                    yisint = 2 - (j & 1);
                }
            } else if (ly == 0) {
                j = iy >> (20 - k);
                if ((j << (20 - k)) == iy) {
                    yisint = 2 - (j & 1);
                }
            }
        }
    }

    if (ly == 0) {
        if (iy == 0x7ff00000) {
            if (((ix - 0x3ff00000) | lx) == 0) {
                return y - y;
            } else if (ix >= 0x3ff00000) {
                return (hy >= 0) ? y : pow_zero;
            } else {
                return (hy < 0) ? -y : pow_zero;
            }
        }
        if (iy == 0x3ff00000) {
            if (hy < 0) {
                return pow_one / x;
            } else {
                return x;
            }
        }
        if (hy == 0x40000000) {
            return x * x;
        }
        if (hy == 0x3fe00000) {
            if (hx >= 0) {
                return func_002E4770(x);
            }
        }
    }

    ax = func_002E7C30(x);
    if (lx == 0) {
        if (ix == 0x7ff00000 || ix == 0 || ix == 0x3ff00000) {
            z = ax;
            if (hy < 0) {
                z = pow_one / z;
            }
            if (hx < 0) {
                if (((ix - 0x3ff00000) | yisint) == 0) {
                    z = (z - z) / (z - z);
                } else if (yisint == 1) {
                    z = -z;
                }
            }
            return z;
        }
    }

    if (((((u32)hx >> 31) - 1) | yisint) == 0) {
        return (x - x) / (x - x);
    }

    if (iy > 0x41e00000) {
        if (iy > 0x43f00000) {
            if (ix <= 0x3fefffff) {
                return (hy < 0) ? pow_huge * pow_huge : pow_tiny * pow_tiny;
            }
            if (ix >= 0x3ff00000) {
                return (hy > 0) ? pow_huge * pow_huge : pow_tiny * pow_tiny;
            }
        }
        if (ix < 0x3fefffff) {
            return (hy < 0) ? pow_huge * pow_huge : pow_tiny * pow_tiny;
        }
        if (ix > 0x3ff00000) {
            return (hy > 0) ? pow_huge * pow_huge : pow_tiny * pow_tiny;
        }
        t = x - 1;
        w = (t * t) * (0.5 - t * (0.33333333333333333333 - t * 0.25));
        u = pow_ivln2_h * t;
        v = t * pow_ivln2_l - w * pow_ivln2;
        t1 = u + v;
        SET_LOW_WORD(t1, 0);
        t2 = v - (t1 - u);
    } else {
        double s2, s_h, s_l, t_h, t_l;
        n = 0;
        if (ix < 0x00100000) {
            ax *= pow_two53;
            n -= 53;
            GET_HIGH_WORD(ix, ax);
        }
        n += ((ix) >> 20) - 0x3ff;
        j = ix & 0x000fffff;
        ix = j | 0x3ff00000;
        if (j <= 0x3988E) {
            k = 0;
        } else if (j < 0xBB67A) {
            k = 1;
        } else {
            k = 0;
            n += 1;
            ix -= 0x00100000;
        }
        SET_HIGH_WORD(ax, ix);

        u = ax - pow_bp[k];
        v = pow_one / (ax + pow_bp[k]);
        s = u * v;
        s_h = s;
        SET_LOW_WORD(s_h, 0);
        t_h = pow_zero;
        SET_HIGH_WORD(t_h, ((ix >> 1) | 0x20000000) + 0x00080000 + (k << 18));
        t_l = ax - (t_h - pow_bp[k]);
        s_l = v * ((u - s_h * t_h) - s_h * t_l);
        s2 = s * s;
        r = s2 * s2 * (pow_L1 + s2 * (pow_L2 + s2 * (pow_L3 + s2 * (pow_L4 + s2 * (pow_L5 + s2 * pow_L6)))));
        r += s_l * (s_h + s);
        s2 = s_h * s_h;
        t_h = 3.0 + s2 + r;
        SET_LOW_WORD(t_h, 0);
        t_l = r - ((t_h - 3.0) - s2);
        u = s_h * t_h;
        v = s_l * t_h + t_l * s;
        p_h = u + v;
        SET_LOW_WORD(p_h, 0);
        p_l = v - (p_h - u);
        z_h = pow_cp_h * p_h;
        z_l = pow_cp_l * p_h + p_l * pow_cp + pow_dp_l[k];
        t = (double)n;
        t1 = (((z_h + z_l) + pow_dp_h[k]) + t);
        SET_LOW_WORD(t1, 0);
        t2 = z_l - (((t1 - t) - pow_dp_h[k]) - z_h);
    }

    s = pow_one;
    if (((((u32)hx >> 31) - 1) | (yisint - 1)) == 0) {
        s = -pow_one;
    }

    y1 = y;
    SET_LOW_WORD(y1, 0);
    p_l = (y - y1) * t1 + y * t2;
    p_h = y1 * t1;
    z = p_l + p_h;
    EXTRACT_WORDS(j, i, z);
    if (j >= 0x40900000) {
        if (((j - 0x40900000) | i) != 0) {
            return s * pow_huge * pow_huge;
        } else {
            if (p_l + pow_ovt > z - p_h) {
                return s * pow_huge * pow_huge;
            }
        }
    } else if ((j & 0x7fffffff) >= 0x4090cc00) {
        if (((j - 0xc090cc00) | i) != 0) {
            return s * pow_tiny * pow_tiny;
        } else {
            if (p_l <= z - p_h) {
                return s * pow_tiny * pow_tiny;
            }
        }
    }
    i = j & 0x7fffffff;
    k = (i >> 20) - 0x3ff;
    n = 0;
    if (i > 0x3fe00000) {
        n = j + (0x00100000 >> (k + 1));
        k = ((n & 0x7fffffff) >> 20) - 0x3ff;
        t = pow_zero;
        SET_HIGH_WORD(t, n & ~(0x000fffff >> k));
        n = ((n & 0x000fffff) | 0x00100000) >> (20 - k);
        if (j < 0) {
            n = -n;
        }
        p_h -= t;
    }
    t = p_l + p_h;
    SET_LOW_WORD(t, 0);
    u = t * pow_lg2_h;
    v = (p_l - (t - p_h)) * pow_lg2 + t * pow_lg2_l;
    z = u + v;
    w = v - (z - u);
    t = z * z;
    t1 = z - t * (pow_P1 + t * (pow_P2 + t * (pow_P3 + t * (pow_P4 + t * pow_P5))));
    r = (z * t1) / (t1 - pow_two) - (w + z * w);
    z = pow_one - (r - z);
    GET_HIGH_WORD(j, z);
    j += (n << 20);
    if ((j >> 20) <= 0) {
        z = func_002E80C0(z, n);
    } else {
        SET_HIGH_WORD(z, j);
    }
    return s * z;
}

static const u32 rem_pio2_rodata_00577218[] = {
    0x00a2f983U, 0x006e4e44U, 0x001529fcU, 0x002757d1U, 0x00f534ddU, 0x00c0db62U, 0x0095993cU, 0x00439041U,
    0x00fe5163U, 0x00abdebbU, 0x00c561b7U, 0x00246e3aU, 0x00424dd2U, 0x00e00649U, 0x002eea09U, 0x00d1921cU,
    0x00fe1debU, 0x001cb129U, 0x00a73ee8U, 0x008235f5U, 0x002ebb44U, 0x0084e99cU, 0x007026b4U, 0x005f7e41U,
    0x003991d6U, 0x00398353U, 0x0039f49cU, 0x00845f8bU, 0x00bdf928U, 0x003b1ff8U, 0x0097ffdeU, 0x0005980fU,
    0x00ef2f11U, 0x008b5a0aU, 0x006d1f6dU, 0x00367ecfU, 0x0027cb09U, 0x00b74f46U, 0x003f669eU, 0x005fea2dU,
    0x007527baU, 0x00c7ebe5U, 0x00f17b3dU, 0x000739f7U, 0x008a5292U, 0x00ea6bfbU, 0x005fb11fU, 0x008d5d08U,
    0x00560330U, 0x0046fc7bU, 0x006babf0U, 0x00cfbc20U, 0x009af436U, 0x001da9e3U, 0x0091615eU, 0x00e61b08U,
    0x00659985U, 0x005f14a0U, 0x0068408dU, 0x00ffd880U, 0x004d7327U, 0x00310606U, 0x001556caU, 0x0073a8c9U,
    0x0060e27bU, 0x00c08c6bU, 0x3ff921fbU, 0x400921fbU, 0x4012d97cU, 0x401921fbU, 0x401f6a7aU, 0x4022d97cU,
    0x4025fdbbU, 0x402921fbU, 0x402c463aU, 0x402f6a7aU, 0x4031475cU, 0x4032d97cU, 0x40346b9cU, 0x4035fdbbU,
    0x40378fdbU, 0x403921fbU, 0x403ab41bU, 0x403c463aU, 0x403dd85aU, 0x403f6a7aU, 0x40407e4cU, 0x4041475cU,
    0x4042106cU, 0x4042d97cU, 0x4043a28cU, 0x40446b9cU, 0x404534acU, 0x4045fdbbU, 0x4046c6cbU, 0x40478fdbU,
    0x404858ebU, 0x404921fbU, 0x00000000U, 0x00000000U, 0x00000000U, 0x3fe00000U, 0x00000000U, 0x41700000U,
    0x6dc9c883U, 0x3fe45f30U, 0x54400000U, 0x3ff921fbU, 0x1a626331U, 0x3dd0b461U, 0x1a600000U, 0x3dd0b461U,
    0x2e037073U, 0x3ba3198aU, 0x2e000000U, 0x3ba3198aU, 0x252049c1U, 0x397b839aU,
};
