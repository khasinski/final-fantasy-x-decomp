/* tu_360 0x2eb7a0-0x2ed078: low; libgcc/fp-bit(dp) (config/tu_map.tsv) */
#include "common.h"
#include "ffx/q7.h"
#include "ffx/w11.h"
#include "ffx/r7.h"
#include "ffx/v7.h"

double func_002EB7A0(fp_number_type *src)
{
    FLO_union_type dst;
    fractype fraction = src->fraction.ll;
    int sign = src->sign;
    int exp = 0;

    if (isnan(src)) {
        exp = EXPMAX;
        fraction |= QUIET_NAN;
    } else if (isinf(src)) {
        exp = EXPMAX;
        fraction = 0;
    } else if (iszero(src)) {
        exp = 0;
        fraction = 0;
    } else if (fraction == 0) {
        exp = 0;
    } else {
        if (src->normal_exp < NORMAL_EXPMIN) {
            int shift = NORMAL_EXPMIN - src->normal_exp;

            exp = 0;
            if (shift > FRAC_NBITS - NGARDS) {
                fraction = 0;
            } else {
                fraction >>= shift;
            }
            fraction >>= NGARDS;
        } else if (src->normal_exp > EXPBIAS) {
            exp = EXPMAX;
            fraction = 0;
        } else {
            exp = src->normal_exp + EXPBIAS;
            if ((fraction & GARDMASK) == GARDMSB) {
                if (fraction & (1 << NGARDS)) {
                    fraction += GARDROUND + 1;
                }
            } else {
                fraction += GARDROUND;
            }
            if (fraction >= IMPLICIT_2) {
                fraction >>= 1;
                exp += 1;
            }
            fraction >>= NGARDS;
        }
    }

    dst.bits.fraction = fraction;
    dst.bits.exp = exp;
    dst.bits.sign = sign;
    return dst.value;
}

void func_002EB8D0(FLO_union_type *src, fp_number_type *dst)
{
    fractype fraction;
    int exp;
    int sign;

    fraction = src->bits.fraction;
    exp = src->bits.exp;
    sign = src->bits.sign;

    dst->sign = sign;
    if (exp == 0) {
        /* libgcc built with NO_DENORMALS: "fraction == 0 || 1" */
        if (fraction == 0 || 1) {
            dst->class = CLASS_ZERO;
        } else {
            dst->class = CLASS_NUMBER;
            dst->normal_exp = NORMAL_EXPMIN;
            fraction <<= NGARDS;
            while (fraction < IMPLICIT_1) {
                fraction <<= 1;
                dst->normal_exp--;
            }
            dst->fraction.ll = fraction;
        }
    } else if (exp == EXPMAX) {
        if (fraction == 0) {
            dst->class = CLASS_INFINITY;
        } else {
            if (fraction & QUIET_NAN) {
                dst->class = CLASS_QNAN;
            } else {
                dst->class = CLASS_SNAN;
            }
            dst->fraction.ll = fraction;
        }
    } else {
        dst->normal_exp = exp - EXPBIAS;
        dst->class = CLASS_NUMBER;
        dst->fraction.ll = (fraction << NGARDS) | IMPLICIT_1;
    }
}

fp_number_type *func_002EB970(fp_number_type *a, fp_number_type *b, fp_number_type *tmp)
{
    long long tfraction;
    int a_normal_exp, b_normal_exp;
    fractype a_fraction, b_fraction;

    if (isnan(a)) {
        return a;
    }
    if (isnan(b)) {
        return b;
    }
    if (isinf(a)) {
        /* adding infinities with opposite signs yields a NaN */
        if (isinf(b) && a->sign != b->sign) {
            return &D_00791608;
        }
        return a;
    }
    if (isinf(b)) {
        return b;
    }
    if (iszero(b)) {
        if (iszero(a)) {
            *tmp = *a;
            tmp->sign = a->sign & b->sign;
            return tmp;
        }
        return a;
    }
    if (iszero(a)) {
        return b;
    }

    {
        int diff;

        a_normal_exp = a->normal_exp;
        b_normal_exp = b->normal_exp;
        a_fraction = a->fraction.ll;
        b_fraction = b->fraction.ll;

        diff = a_normal_exp - b_normal_exp;
        if (diff < 0) {
            diff = -diff;
        }
        if (diff < FRAC_NBITS) {
            while (a_normal_exp > b_normal_exp) {
                b_normal_exp++;
                LSHIFT(b_fraction);
            }
            while (b_normal_exp > a_normal_exp) {
                a_normal_exp++;
                LSHIFT(a_fraction);
            }
        } else {
            if (a_normal_exp > b_normal_exp) {
                b_normal_exp = a_normal_exp;
                b_fraction = 0;
            } else {
                a_normal_exp = b_normal_exp;
                a_fraction = 0;
            }
        }
    }

    if (a->sign != b->sign) {
        if (a->sign) {
            tfraction = -a_fraction + b_fraction;
        } else {
            tfraction = a_fraction - b_fraction;
        }
        if (tfraction >= 0) {
            tmp->sign = 0;
            tmp->normal_exp = a_normal_exp;
            tmp->fraction.ll = tfraction;
        } else {
            tmp->sign = 1;
            tmp->normal_exp = a_normal_exp;
            tmp->fraction.ll = -tfraction;
        }
        while (tmp->fraction.ll < IMPLICIT_1 && tmp->fraction.ll) {
            tmp->fraction.ll <<= 1;
            tmp->normal_exp--;
        }
    } else {
        tmp->sign = a->sign;
        tmp->normal_exp = a_normal_exp;
        tmp->fraction.ll = a_fraction + b_fraction;
    }
    tmp->class = CLASS_NUMBER;
    if (tmp->fraction.ll >= IMPLICIT_2) {
        LSHIFT(tmp->fraction.ll);
        tmp->normal_exp++;
    }
    return tmp;
}

double func_002EBBB0(double arg_a, double arg_b)
{
    fp_number_type a;
    fp_number_type b;
    fp_number_type tmp;
    FLO_union_type au, bu;

    au.value = arg_a;
    bu.value = arg_b;
    func_002EB8D0(&au, &a);
    func_002EB8D0(&bu, &b);
    return func_002EB7A0(func_002EB970(&a, &b, &tmp));
}

double func_002EBC08(double arg_a, double arg_b)
{
    fp_number_type a;
    fp_number_type b;
    fp_number_type tmp;
    FLO_union_type au, bu;

    au.value = arg_a;
    bu.value = arg_b;
    func_002EB8D0(&au, &a);
    func_002EB8D0(&bu, &b);
    b.sign ^= 1;
    return func_002EB7A0(func_002EB970(&a, &b, &tmp));
}

/* Module: libgcc soft-float (fp-bit.c: double + single precision), newlib libm helpers */

INCLUDE_ASM("build/ee_asm/sdk/libgcc/fp_bit", func_002EBC70);

/* _fpdiv_parts from libgcc fp-bit.c, inlined into __divdf3 */
static inline fp_number_type *fpdiv_parts(fp_number_type *a, fp_number_type *b)
{
    fractype bit;
    fractype numerator;
    fractype denominator;
    fractype quotient;

    if (isnan(a)) {
        return a;
    }
    if (isnan(b)) {
        return b;
    }
    a->sign = a->sign ^ b->sign;

    if (isinf(a) || iszero(a)) {
        if (a->class == b->class) {
            return &D_00791608;
        }
        return a;
    }
    if (isinf(b)) {
        a->fraction.ll = 0;
        a->normal_exp = 0;
        return a;
    }
    if (iszero(b)) {
        a->class = CLASS_INFINITY;
        return a;
    }

    a->normal_exp = a->normal_exp - b->normal_exp;
    numerator = a->fraction.ll;
    denominator = b->fraction.ll;

    if (numerator < denominator) {
        numerator *= 2;
        a->normal_exp--;
    }
    bit = IMPLICIT_1;
    quotient = 0;
    while (bit) {
        if (numerator >= denominator) {
            quotient |= bit;
            numerator -= denominator;
        }
        bit >>= 1;
        numerator *= 2;
    }

    if ((quotient & GARDMASK) == GARDMSB) {
        if (quotient & (1 << NGARDS)) {
            quotient += GARDROUND + 1;
        } else if (numerator) {
            quotient += GARDROUND + 1;
        }
    }

    a->fraction.ll = quotient;
    return a;
}

double func_002EBF18(double arg_a, double arg_b)
{
    fp_number_type a;
    fp_number_type b;
    FLO_union_type au, bu;

    au.value = arg_a;
    bu.value = arg_b;
    func_002EB8D0(&au, &a);
    func_002EB8D0(&bu, &b);
    return func_002EB7A0(fpdiv_parts(&a, &b));
}

int func_002EC080(fp_number_type *a, fp_number_type *b)
{
    if (isnan(a) || isnan(b)) {
        return 1;
    }
    if (isinf(a)) {
        if (isinf(b)) {
            return b->sign - a->sign;
        }
        return a->sign ? -1 : 1;
    } else if (isinf(b)) {
        return b->sign ? 1 : -1;
    }
    if (iszero(a)) {
        if (iszero(b)) {
            return 0;
        }
        return b->sign == 0 ? -1 : 1;
    } else if (iszero(b)) {
        return a->sign ? -1 : 1;
    }
    if (a->sign != b->sign) {
        return a->sign ? -1 : 1;
    }
    if (a->normal_exp > b->normal_exp) {
        return a->sign ? -1 : 1;
    }
    if (a->normal_exp < b->normal_exp) {
        return a->sign ? 1 : -1;
    }
    if (a->fraction.ll > b->fraction.ll) {
        return a->sign ? -1 : 1;
    }
    if (a->fraction.ll < b->fraction.ll) {
        return a->sign ? 1 : -1;
    }
    return 0;
}

int func_002EC198(double arg_a, double arg_b)
{
    fp_number_type a;
    fp_number_type b;
    FLO_union_type au, bu;

    au.value = arg_a;
    bu.value = arg_b;
    func_002EB8D0(&au, &a);
    func_002EB8D0(&bu, &b);
    return func_002EC080(&a, &b);
}

double func_002EC1E8(int arg_a)
{
    fp_number_type in;

    in.class = CLASS_NUMBER;
    in.sign = arg_a < 0;
    if (!arg_a) {
        in.class = CLASS_ZERO;
    } else {
        in.normal_exp = 52 + NGARDS;
        if (in.sign) {
            /* minint has no positive counterpart */
            if (arg_a == (int)0x80000000) {
                return -2147483648.0;
            }
            in.fraction.ll = -arg_a;
        } else {
            in.fraction.ll = arg_a;
        }
        while (in.fraction.ll < IMPLICIT_1) {
            in.fraction.ll <<= 1;
            in.normal_exp -= 1;
        }
    }
    return func_002EB7A0(&in);
}

int func_002EC2A0(double arg_a)
{
    fp_number_type a;
    FLO_union_type au;
    int tmp;

    au.value = arg_a;
    func_002EB8D0(&au, &a);

    if (iszero(&a)) {
        return 0;
    }
    if (isnan(&a)) {
        return 0;
    }
    if (isinf(&a)) {
        return a.sign ? 0x80000000 : 0x7fffffff;
    } else if (a.normal_exp < 0) {
        return 0;
    } else if (a.normal_exp > 30) {
        return a.sign ? 0x80000000 : 0x7fffffff;
    } else {
        tmp = a.fraction.ll >> ((52 + NGARDS) - a.normal_exp);
    }
    return a.sign ? -tmp : tmp;
}

unsigned int func_002EC338(double arg_a)
{
    fp_number_type a;
    FLO_union_type au;

    au.value = arg_a;
    func_002EB8D0(&au, &a);

    if (iszero(&a)) {
        return 0;
    }
    if (isnan(&a)) {
        return 0;
    }
    if (a.sign) {
        return 0;
    }
    if (isinf(&a)) {
        return 0xffffffff;
    } else if (a.normal_exp < 0) {
        return 0;
    } else if (a.normal_exp > 31) {
        return 0xffffffff;
    }
    if (a.normal_exp > (52 + NGARDS)) {
        return a.fraction.ll << (a.normal_exp - (52 + NGARDS));
    }
    return a.fraction.ll >> ((52 + NGARDS) - a.normal_exp);
}

double func_002EC3D8(double arg_a)
{
    fp_number_type a;
    FLO_union_type au;

    au.value = arg_a;
    func_002EB8D0(&au, &a);
    a.sign = !a.sign;
    return func_002EB7A0(&a);
}

double func_002EC410(fp_class_type class, unsigned int sign, int exp, fractype frac)
{
    fp_number_type in;

    in.class = class;
    in.sign = sign;
    in.normal_exp = exp;
    in.fraction.ll = frac;
    return func_002EB7A0(&in);
}

float func_002EC440(double arg_a)
{
    fp_number_type in;
    FLO_union_type au;
    unsigned int sf;

    au.value = arg_a;
    func_002EB8D0(&au, &in);

    sf = in.fraction.ll >> 30;
    if (in.fraction.ll & 0x3fffffff) {
        sf |= 1; /* sticky bit */
    }
    return func_002ED008(in.class, in.sign, in.normal_exp, sf);
}

float func_002EC498(fp_number_sf *src)
{
    FLO_union_sf dst;
    unsigned int fraction = src->fraction.ll;
    int sign = src->sign;
    int exp = 0;

    if (isnan_sf(src)) {
        exp = SF_EXPMAX;
        fraction |= SF_QUIET_NAN;
    } else if (isinf_sf(src)) {
        exp = SF_EXPMAX;
        fraction = 0;
    } else if (iszero_sf(src)) {
        exp = 0;
        fraction = 0;
    } else if (fraction == 0) {
        exp = 0;
    } else {
        if (src->normal_exp < SF_NORMAL_EXPMIN) {
            int shift = SF_NORMAL_EXPMIN - src->normal_exp;

            exp = 0;
            if (shift > SF_FRAC_NBITS - SF_NGARDS) {
                fraction = 0;
            } else {
                fraction >>= shift;
            }
            fraction >>= SF_NGARDS;
        } else if (src->normal_exp > SF_EXPBIAS) {
            exp = SF_EXPMAX;
            fraction = 0;
        } else {
            exp = src->normal_exp + SF_EXPBIAS;
            if ((fraction & SF_GARDMASK) == SF_GARDMSB) {
                if (fraction & (1 << SF_NGARDS)) {
                    fraction += SF_GARDROUND + 1;
                }
            } else {
                fraction += SF_GARDROUND;
            }
            if (fraction >= SF_IMPLICIT_2) {
                fraction >>= 1;
                exp += 1;
            }
            fraction >>= SF_NGARDS;
        }
    }

    dst.bits.fraction = fraction;
    dst.bits.exp = exp;
    dst.bits.sign = sign;
    return dst.value;
}

/* DEBT(TYPE): libgcc passes a FLO_union_sf *, but only a plain float local reproduces the swc1 stores in the callers */
void func_002EC5A8(float *src_f, fp_number_sf *dst)
{
    FLO_union_sf *src = (FLO_union_sf *)src_f; /* DEBT(CAST): see above */
    unsigned int fraction;
    int exp;
    int sign;

    fraction = src->bits.fraction;
    exp = src->bits.exp;
    sign = src->bits.sign;

    dst->sign = sign;
    if (exp == 0) {
        dst->class = CLASS_ZERO;
    } else if (exp == SF_EXPMAX) {
        if (fraction == 0) {
            dst->class = CLASS_INFINITY;
        } else {
            if (fraction & SF_QUIET_NAN) {
                dst->class = CLASS_QNAN;
            } else {
                dst->class = CLASS_SNAN;
            }
            dst->fraction.ll = fraction;
        }
    } else {
        dst->normal_exp = exp - SF_EXPBIAS;
        dst->class = CLASS_NUMBER;
        dst->fraction.ll = (fraction << SF_NGARDS) | SF_IMPLICIT_1;
    }
}

fp_number_sf *func_002EC638(fp_number_sf *a, fp_number_sf *b, fp_number_sf *tmp)
{
    int tfraction;
    int a_normal_exp, b_normal_exp;
    unsigned int a_fraction, b_fraction;

    if (isnan_sf(a)) {
        return a;
    }
    if (isnan_sf(b)) {
        return b;
    }
    if (isinf_sf(a)) {
        if (isinf_sf(b) && a->sign != b->sign) {
            return &D_00791620;
        }
        return a;
    }
    if (isinf_sf(b)) {
        return b;
    }
    if (iszero_sf(b)) {
        if (iszero_sf(a)) {
            *tmp = *a;
            tmp->sign = a->sign & b->sign;
            return tmp;
        }
        return a;
    }
    if (iszero_sf(a)) {
        return b;
    }

    {
        int diff;

        a_normal_exp = a->normal_exp;
        b_normal_exp = b->normal_exp;
        a_fraction = a->fraction.ll;
        b_fraction = b->fraction.ll;

        diff = a_normal_exp - b_normal_exp;
        if (diff < 0) {
            diff = -diff;
        }
        if (diff < SF_FRAC_NBITS) {
            while (a_normal_exp > b_normal_exp) {
                b_normal_exp++;
                LSHIFT(b_fraction);
            }
            while (b_normal_exp > a_normal_exp) {
                a_normal_exp++;
                LSHIFT(a_fraction);
            }
        } else {
            if (a_normal_exp > b_normal_exp) {
                b_normal_exp = a_normal_exp;
                b_fraction = 0;
            } else {
                a_normal_exp = b_normal_exp;
                a_fraction = 0;
            }
        }
    }

    if (a->sign != b->sign) {
        if (a->sign) {
            tfraction = -a_fraction + b_fraction;
        } else {
            tfraction = a_fraction - b_fraction;
        }
        if (tfraction >= 0) {
            tmp->sign = 0;
            tmp->normal_exp = a_normal_exp;
            tmp->fraction.ll = tfraction;
        } else {
            tmp->sign = 1;
            tmp->normal_exp = a_normal_exp;
            tmp->fraction.ll = -tfraction;
        }
        while (tmp->fraction.ll < SF_IMPLICIT_1 && tmp->fraction.ll) {
            tmp->fraction.ll <<= 1;
            tmp->normal_exp--;
        }
    } else {
        tmp->sign = a->sign;
        tmp->normal_exp = a_normal_exp;
        tmp->fraction.ll = a_fraction + b_fraction;
    }
    tmp->class = CLASS_NUMBER;
    if (tmp->fraction.ll >= SF_IMPLICIT_2) {
        LSHIFT(tmp->fraction.ll);
        tmp->normal_exp++;
    }
    return tmp;
}

float func_002EC870(float arg_a, float arg_b)
{
    fp_number_sf a;
    fp_number_sf b;
    fp_number_sf tmp;
    float au, bu;

    au = arg_a;
    bu = arg_b;
    func_002EC5A8(&au, &a);
    func_002EC5A8(&bu, &b);
    return func_002EC498(func_002EC638(&a, &b, &tmp));
}

float func_002EC8C8(float arg_a, float arg_b)
{
    fp_number_sf a;
    fp_number_sf b;
    fp_number_sf tmp;
    float au, bu;

    au = arg_a;
    bu = arg_b;
    func_002EC5A8(&au, &a);
    func_002EC5A8(&bu, &b);
    b.sign ^= 1;
    return func_002EC498(func_002EC638(&a, &b, &tmp));
}

/* _fpmul_parts (single precision) from libgcc fp-bit.c, inlined into __mulsf3 */
static inline fp_number_sf *fpmul_parts_sf(fp_number_sf *a, fp_number_sf *b, fp_number_sf *tmp)
{
    unsigned int low = 0;
    unsigned int high = 0;

    if (isnan_sf(a)) {
        a->sign = a->sign != b->sign;
        return a;
    }
    if (isnan_sf(b)) {
        b->sign = a->sign != b->sign;
        return b;
    }
    if (isinf_sf(a)) {
        if (iszero_sf(b)) {
            return &D_00791620;
        }
        a->sign = a->sign != b->sign;
        return a;
    }
    if (isinf_sf(b)) {
        if (iszero_sf(a)) {
            return &D_00791620;
        }
        b->sign = a->sign != b->sign;
        return b;
    }
    if (iszero_sf(a)) {
        a->sign = a->sign != b->sign;
        return a;
    }
    if (iszero_sf(b)) {
        b->sign = a->sign != b->sign;
        return b;
    }

    {
        unsigned long long res = (unsigned long long)a->fraction.ll * b->fraction.ll;

        high = res >> 32;
        low = res;
    }

    tmp->normal_exp = a->normal_exp + b->normal_exp + SF_FRAC_NBITS - (23 + SF_NGARDS);
    tmp->sign = a->sign != b->sign;
    while (high >= SF_IMPLICIT_2) {
        tmp->normal_exp++;
        if (high & 1) {
            low >>= 1;
            low |= (unsigned int)1 << 31;
        }
        high >>= 1;
    }
    while (high < SF_IMPLICIT_1) {
        tmp->normal_exp--;
        high <<= 1;
        if (low & ((unsigned int)1 << 31)) {
            high |= 1;
        }
        low <<= 1;
    }
    if ((high & SF_GARDMASK) == SF_GARDMSB) {
        if (high & (1 << SF_NGARDS)) {
            high += SF_GARDROUND + 1;
        } else if (low) {
            high += SF_GARDROUND + 1;
        }
    }
    tmp->fraction.ll = high;
    tmp->class = CLASS_NUMBER;
    return tmp;
}

float func_002EC930(float arg_a, float arg_b)
{
    fp_number_sf a;
    fp_number_sf b;
    fp_number_sf tmp;
    float au, bu;

    au = arg_a;
    bu = arg_b;
    func_002EC5A8(&au, &a);
    func_002EC5A8(&bu, &b);
    return func_002EC498(fpmul_parts_sf(&a, &b, &tmp));
}

/* _fpdiv_parts (single precision) from libgcc fp-bit.c, inlined into __divsf3 */
static inline fp_number_sf *fpdiv_parts_sf(fp_number_sf *a, fp_number_sf *b)
{
    unsigned int bit;
    unsigned int numerator;
    unsigned int denominator;
    unsigned int quotient;

    if (isnan_sf(a)) {
        return a;
    }
    if (isnan_sf(b)) {
        return b;
    }
    a->sign = a->sign ^ b->sign;

    if (isinf_sf(a) || iszero_sf(a)) {
        if (a->class == b->class) {
            return &D_00791620;
        }
        return a;
    }
    if (isinf_sf(b)) {
        a->fraction.ll = 0;
        a->normal_exp = 0;
        return a;
    }
    if (iszero_sf(b)) {
        a->class = CLASS_INFINITY;
        return a;
    }

    a->normal_exp = a->normal_exp - b->normal_exp;
    numerator = a->fraction.ll;
    denominator = b->fraction.ll;

    if (numerator < denominator) {
        numerator *= 2;
        a->normal_exp--;
    }
    bit = SF_IMPLICIT_1;
    quotient = 0;
    while (bit) {
        if (numerator >= denominator) {
            quotient |= bit;
            numerator -= denominator;
        }
        bit >>= 1;
        numerator *= 2;
    }

    if ((quotient & SF_GARDMASK) == SF_GARDMSB) {
        if (quotient & (1 << SF_NGARDS)) {
            quotient += SF_GARDROUND + 1;
        } else if (numerator) {
            quotient += SF_GARDROUND + 1;
        }
    }

    a->fraction.ll = quotient;
    return a;
}

float func_002ECB28(float arg_a, float arg_b)
{
    fp_number_sf a;
    fp_number_sf b;
    float au, bu;

    au = arg_a;
    bu = arg_b;
    func_002EC5A8(&au, &a);
    func_002EC5A8(&bu, &b);
    return func_002EC498(fpdiv_parts_sf(&a, &b));
}

/* Module: libgcc soft-float (fp-bit.c: double + single precision), newlib libm helpers */

int func_002ECC88(fp_number_sf *a, fp_number_sf *b)
{
    if (isnan_sf(a) || isnan_sf(b)) {
        return 1;
    }
    if (isinf_sf(a)) {
        if (isinf_sf(b)) {
            return b->sign - a->sign;
        }
        return a->sign ? -1 : 1;
    } else if (isinf_sf(b)) {
        return b->sign ? 1 : -1;
    }
    if (iszero_sf(a)) {
        if (iszero_sf(b)) {
            return 0;
        }
        return b->sign == 0 ? -1 : 1;
    } else if (iszero_sf(b)) {
        return a->sign ? -1 : 1;
    }
    if (a->sign != b->sign) {
        return a->sign ? -1 : 1;
    }
    if (a->normal_exp > b->normal_exp) {
        return a->sign ? -1 : 1;
    }
    if (a->normal_exp < b->normal_exp) {
        return a->sign ? 1 : -1;
    }
    if (a->fraction.ll > b->fraction.ll) {
        return a->sign ? -1 : 1;
    }
    if (a->fraction.ll < b->fraction.ll) {
        return a->sign ? 1 : -1;
    }
    return 0;
}

int func_002ECDA0(float arg_a, float arg_b)
{
    fp_number_sf a;
    fp_number_sf b;
    float au, bu;

    au = arg_a;
    bu = arg_b;
    func_002EC5A8(&au, &a);
    func_002EC5A8(&bu, &b);
    return func_002ECC88(&a, &b);
}

float func_002ECDF0(int arg_a)
{
    fp_number_sf in;

    in.class = CLASS_NUMBER;
    in.sign = arg_a < 0;
    if (!arg_a) {
        in.class = CLASS_ZERO;
    } else {
        in.normal_exp = 23 + SF_NGARDS;
        if (in.sign) {
            if (arg_a == (int)0x80000000) {
                return -2147483648.0f;
            }
            in.fraction.ll = -arg_a;
        } else {
            in.fraction.ll = arg_a;
        }
        while (in.fraction.ll < SF_IMPLICIT_1) {
            in.fraction.ll <<= 1;
            in.normal_exp -= 1;
        }
    }
    return func_002EC498(&in);
}

int func_002ECEA8(float arg_a)
{
    fp_number_sf a;
    float au;
    int tmp;

    au = arg_a;
    func_002EC5A8(&au, &a);

    if (iszero_sf(&a)) {
        return 0;
    }
    if (isnan_sf(&a)) {
        return 0;
    }
    if (isinf_sf(&a)) {
        return a.sign ? 0x80000000 : 0x7fffffff;
    } else if (a.normal_exp < 0) {
        return 0;
    } else if (a.normal_exp > 30) {
        return a.sign ? 0x80000000 : 0x7fffffff;
    } else {
        tmp = a.fraction.ll >> ((23 + SF_NGARDS) - a.normal_exp);
    }
    return a.sign ? -tmp : tmp;
}

unsigned int func_002ECF38(float arg_a)
{
    fp_number_sf a;
    float au;

    au = arg_a;
    func_002EC5A8(&au, &a);

    if (iszero_sf(&a)) {
        return 0;
    }
    if (isnan_sf(&a)) {
        return 0;
    }
    if (a.sign) {
        return 0;
    }
    if (isinf_sf(&a)) {
        return 0xffffffff;
    } else if (a.normal_exp < 0) {
        return 0;
    } else if (a.normal_exp > 31) {
        return 0xffffffff;
    }
    if (a.normal_exp > (23 + SF_NGARDS)) {
        return a.fraction.ll << (a.normal_exp - (23 + SF_NGARDS));
    }
    return a.fraction.ll >> ((23 + SF_NGARDS) - a.normal_exp);
}

float func_002ECFD0(float arg_a)
{
    fp_number_sf a;
    float au;

    au = arg_a;
    func_002EC5A8(&au, &a);
    a.sign = !a.sign;
    return func_002EC498(&a);
}

float func_002ED008(fp_class_type class, unsigned int sign, int exp, unsigned int frac)
{
    fp_number_sf in;

    in.class = class;
    in.sign = sign;
    in.normal_exp = exp;
    in.fraction.ll = frac;
    return func_002EC498(&in);
}

double func_002ED038(float arg_a)
{
    fp_number_sf in;
    float au;

    au = arg_a;
    func_002EC5A8(&au, &in);
    return func_002EC410(in.class, in.sign, in.normal_exp, (fractype)in.fraction.ll << 30);
}
