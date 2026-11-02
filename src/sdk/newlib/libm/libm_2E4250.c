/* tu_356 0x2e4250-0x2e7c68: medium; unk_2E4250 (config/tu_map.tsv) */
#include "common.h"
#include "ffx/r7.h"

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

INCLUDE_ASM("build/ee_asm/sdk/newlib/libm/libm_2E4250", func_002E4250);

INCLUDE_ASM("build/ee_asm/sdk/newlib/libm/libm_2E4250", func_002E4770);

INCLUDE_ASM("build/ee_asm/sdk/newlib/libm/libm_2E4250", func_002E4A78);

INCLUDE_ASM("build/ee_asm/sdk/newlib/libm/libm_2E4250", func_002E4EA8);

INCLUDE_ASM("build/ee_asm/sdk/newlib/libm/libm_2E4250", func_002E5190);
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

INCLUDE_ASM("build/ee_asm/sdk/newlib/libm/libm_2E4250", func_002E69E0);

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

INCLUDE_ASM("build/ee_asm/sdk/newlib/libm/libm_2E4250", func_002E76D0);

INCLUDE_ASM("build/ee_asm/sdk/newlib/libm/libm_2E4250", func_002E7AE0);

INCLUDE_ASM("build/ee_asm/sdk/newlib/libm/libm_2E4250", func_002E7B28);

double func_002E7C30(double x)
{
    u32 high;

    GET_HIGH_WORD(high, x);
    SET_HIGH_WORD(x, high & 0x7fffffff);
    return x;
}
