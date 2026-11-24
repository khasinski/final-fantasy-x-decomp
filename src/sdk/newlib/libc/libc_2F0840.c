/* tu_366 0x2f0840-0x2f2150: medium; unk_2F0840 (config/tu_map.tsv) */
#include "common.h"
#include "ffx/r7.h"
#include "ffx/q7.h"
#include "ffx/w11.h"
#define D_005789E0 D_005789E0_v7
#include "ffx/v7.h"
#undef D_005789E0
extern const double D_005789E0[];

INCLUDE_ASM("build/ee_asm/sdk/newlib/libc/libc_2F0840", func_002F0840);

int func_002F0978(const char *s1, const char *s2, u32 n)
{
    if (n == 0) {
        return 0;
    }
    while (n-- != 0 && v7_tolower(*s1) == v7_tolower(*s2)) {
        if (n == 0 || *s1 == '\0' || *s2 == '\0') {
            break;
        }
        s1++;
        s2++;
    }
    return v7_tolower(*(u8 *)s1) - v7_tolower(*(u8 *)s2);
}

INCLUDE_ASM("build/ee_asm/sdk/newlib/libc/libc_2F0840", func_002F0A58);

INCLUDE_ASM("build/ee_asm/sdk/newlib/libc/libc_2F0840", func_002F0C10);

char *func_002F0DD0(char *s, int i)
{
    const char *last = 0;
    char c = i;

    while (*s) {
        if (*s == c) {
            last = s;
        }
        s++;
    }
    if (*s == c) {
        last = s;
    }
    return (char *)last;
}

extern const double D_00578AA8[]; /* bigtens */
extern const double D_00578AD0[]; /* tinytens */
extern const double D_00577B80[]; /* __infinity */
W11Bigint *func_002F65E8(W11Reent *ptr, const char *s, int nd0, int nd, u32 y9);
W11Bigint *func_002F6878(W11Reent *r, int i);
W11Bigint *func_002F6AE0(W11Reent *ptr, W11Bigint *b, int k);
W11Bigint *func_002F6BE0(W11Reent *ptr, W11Bigint *b, int k);
W11Bigint *func_002F6DC0(W11Reent *ptr, W11Bigint *a, W11Bigint *b);
double func_002F6F50(double _x);
W11Bigint *func_002F7168(W11Reent *ptr, double _d, int *e, int *bits);
double func_002F72E8(W11Bigint *a, W11Bigint *b);

#define word0(x) ((x).parts.msw)
#define word1(x) ((x).parts.lsw)
#define dval(x) ((x).value)
#define Bcopy(x, y) func_002EEF1C((char *)&(x)->_sign, (char *)&(y)->_sign, (y)->_wds * sizeof(u32) + 2 * sizeof(int))

double func_002F0E20(W11Reent *ptr, const char *s00, char **se)
{
    int bb2, bb5, bbe, bd2, bd5, bbbits, bs2, c, dsign, e1, esign, i, j,
        k, nd, nd0, nf, nz, nz0, sign;
    long e;
    const char *s, *s0, *s1;
    double aadj, aadj1, adj;
    long L;
    unsigned long z;
    u32 y;
    ieee_double_shape_type rv, rv0;
    W11Bigint *bb, *bb1, *bd, *bd0, *bs, *delta;

    sign = nz0 = nz = 0;
    dval(rv) = 0.;
    for (s = s00;; s++) {
        switch (*s) {
        case '-':
            sign = 1;
            /* no break */
        case '+':
            if (*++s) {
                goto break2;
            }
            /* no break */
        case 0:
            s = s00;
            goto ret;
        case '\t':
        case '\n':
        case '\v':
        case '\f':
        case '\r':
        case ' ':
            continue;
        default:
            goto break2;
        }
    }
break2:
    if (*s == '0') {
        nz0 = 1;
        while (*++s == '0') {
        }
        if (!*s) {
            goto ret;
        }
    }
    s0 = s;
    y = z = 0;
    for (nd = nf = 0; (c = *s) >= '0' && c <= '9'; nd++, s++) {
        if (nd < 9) {
            y = 10 * y + c - '0';
        } else if (nd < 16) {
            z = 10 * z + c - '0';
        }
    }
    nd0 = nd;
    if (c == '.') {
        c = *++s;
        if (!nd) {
            for (; c == '0'; c = *++s) {
                nz++;
            }
            if (c > '0' && c <= '9') {
                s0 = s;
                nf += nz;
                nz = 0;
                goto have_dig;
            }
            goto dig_done;
        }
        for (; c >= '0' && c <= '9'; c = *++s) {
        have_dig:
            nz++;
            if (c -= '0') {
                nf += nz;
                for (i = 1; i < nz; i++) {
                    if (nd++ < 9) {
                        y *= 10;
                    } else if (nd <= 15 + 1) {
                        z *= 10;
                    }
                }
                if (nd++ < 9) {
                    y = 10 * y + c;
                } else if (nd <= 15 + 1) {
                    z = 10 * z + c;
                }
                nz = 0;
            }
        }
    }
dig_done:
    e = 0;
    if (c == 'e' || c == 'E') {
        if (!nd && !nz && !nz0) {
            s = s00;
            goto ret;
        }
        s00 = s;
        esign = 0;
        switch (c = *++s) {
        case '-':
            esign = 1;
        case '+':
            c = *++s;
        }
        if (c >= '0' && c <= '9') {
            while (c == '0') {
                c = *++s;
            }
            if (c > '0' && c <= '9') {
                e = c - '0';
                s1 = s;
                while ((c = *++s) >= '0' && c <= '9') {
                    e = 10 * e + c - '0';
                }
                if (s - s1 > 8) {
                    e = 9999999L;
                }
                if (esign) {
                    e = -e;
                }
            } else {
                e = 0;
            }
        } else {
            s = s00;
        }
    }
    if (!nd) {
        if (!nz && !nz0) {
            s = s00;
        }
        goto ret;
    }
    e1 = e -= nf;

    if (!nd0) {
        nd0 = nd;
    }
    k = nd < 15 + 1 ? nd : 15 + 1;
    dval(rv) = y;
    if (k > 9) {
        dval(rv) = D_005789E0[k - 9] * dval(rv) + z;
    }
    bd0 = 0;
    if (nd <= 15) {
        if (!e) {
            goto ret;
        }
        if (e > 0) {
            if (e <= 22) {
                dval(rv) *= D_005789E0[e];
                goto ret;
            }
            i = 15 - nd;
            if (e <= 22 + i) {
                e -= i;
                dval(rv) *= D_005789E0[i];
                dval(rv) *= D_005789E0[e];
                goto ret;
            }
        } else if (e >= -22) {
            dval(rv) /= D_005789E0[-e];
            goto ret;
        }
    }
    e1 += nd - k;

    if (e1 > 0) {
        if ((i = e1 & 15)) {
            dval(rv) *= D_005789E0[i];
        }
        if ((e1 &= ~15)) {
            if (e1 > 308) {
            ovfl:
                ptr->_errno = 34;
                dval(rv) = D_00577B80[0];
                if (bd0) {
                    goto retfree;
                }
                goto ret;
            }
            if ((e1 >>= 4)) {
                for (j = 0; e1 > 1; j++, e1 >>= 1) {
                    if (e1 & 1) {
                        dval(rv) *= D_00578AA8[j];
                    }
                }
                word0(rv) -= 53 * 0x100000;
                dval(rv) *= D_00578AA8[j];
                if ((z = word0(rv) & 0x7ff00000) > 0x7ff00000 - 53 * 0x100000) {
                    goto ovfl;
                }
                if (z > 0x7ff00000 - 54 * 0x100000) {
                    word0(rv) = 0x7fefffff;
                    word1(rv) = 0xffffffff;
                } else {
                    word0(rv) += 53 * 0x100000;
                }
            }
        }
    } else if (e1 < 0) {
        e1 = -e1;
        if ((i = e1 & 15)) {
            dval(rv) /= D_005789E0[i];
        }
        if ((e1 &= ~15)) {
            e1 >>= 4;
            if (e1 >= 1 << 5) {
                goto undfl;
            }
            for (j = 0; e1 > 1; j++, e1 >>= 1) {
                if (e1 & 1) {
                    dval(rv) *= D_00578AD0[j];
                }
            }
            dval(rv0) = dval(rv);
            dval(rv) *= D_00578AD0[j];
            if (!dval(rv)) {
                dval(rv) = 2. * dval(rv0);
                dval(rv) *= D_00578AD0[j];
                if (!dval(rv)) {
                undfl:
                    dval(rv) = 0.;
                    ptr->_errno = 34;
                    if (bd0) {
                        goto retfree;
                    }
                    goto ret;
                }
                word0(rv) = 0;
                word1(rv) = 1;
            }
        }
    }

    bb = bd0 = func_002F65E8(ptr, s0, nd0, nd, y);

    for (;;) {
        bd = func_002F63F8(ptr, bd0->_k);
        Bcopy(bd, bd0);
        bb = func_002F7168(ptr, dval(rv), &bbe, &bbbits);
        bs = func_002F6878(ptr, 1);

        if (e >= 0) {
            bb2 = bb5 = 0;
            bd2 = bd5 = e;
        } else {
            bb2 = bb5 = -e;
            bd2 = bd5 = 0;
        }
        if (bbe >= 0) {
            bb2 += bbe;
        } else {
            bd2 -= bbe;
        }
        bs2 = bb2;
        i = bbe + bbbits - 1;
        if (i < -1022) {
            j = bbe + 1022 + 53;
        } else {
            j = 53 + 1 - bbbits;
        }
        bb2 += j;
        bd2 += j;
        i = bb2 < bd2 ? bb2 : bd2;
        if (i > bs2) {
            i = bs2;
        }
        if (i > 0) {
            bb2 -= i;
            bd2 -= i;
            bs2 -= i;
        }
        if (bb5 > 0) {
            bs = func_002F6AE0(ptr, bs, bb5);
            bb1 = func_002F68B0(ptr, bs, bb);
            func_002F64A0(ptr, bb);
            bb = bb1;
        }
        if (bb2 > 0) {
            bb = func_002F6BE0(ptr, bb, bb2);
        }
        if (bd5 > 0) {
            bd = func_002F6AE0(ptr, bd, bd5);
        }
        if (bd2 > 0) {
            bd = func_002F6BE0(ptr, bd, bd2);
        }
        if (bs2 > 0) {
            bs = func_002F6BE0(ptr, bs, bs2);
        }
        delta = func_002F6DC0(ptr, bb, bd);
        dsign = delta->_sign;
        delta->_sign = 0;
        i = func_002F6D58(delta, bs);
        if (i < 0) {
            if (dsign || word1(rv) || word0(rv) & 0xfffff) {
                break;
            }
            delta = func_002F6BE0(ptr, delta, 1);
            if (func_002F6D58(delta, bs) > 0) {
                goto drop_down;
            }
            break;
        }
        if (i == 0) {
            if (dsign) {
                if ((word0(rv) & 0xfffff) == 0xfffff && word1(rv) == 0xffffffff) {
                    word0(rv) = (word0(rv) & 0x7ff00000) + 0x100000;
                    word1(rv) = 0;
                    break;
                }
            } else if (!(word0(rv) & 0xfffff) && !word1(rv)) {
            drop_down:
                L = (word0(rv) & 0x7ff00000) - 0x100000;
                word0(rv) = L | 0xfffff;
                word1(rv) = 0xffffffff;
                break;
            }
            if (!(word1(rv) & 1)) {
                break;
            }
            if (dsign) {
                dval(rv) += func_002F6F50(dval(rv));
            } else {
                dval(rv) -= func_002F6F50(dval(rv));
                if (!dval(rv)) {
                    goto undfl;
                }
            }
            break;
        }
        if ((aadj = func_002F72E8(delta, bs)) <= 2.) {
            if (dsign) {
                aadj = aadj1 = 1.;
            } else if (word1(rv) || word0(rv) & 0xfffff) {
                if (word1(rv) == 1 && !word0(rv)) {
                    goto undfl;
                }
                aadj = 1.;
                aadj1 = -1.;
            } else {
                if (aadj < 2. / 2) {
                    aadj = 1. / 2;
                } else {
                    aadj *= 0.5;
                }
                aadj1 = -aadj;
            }
        } else {
            aadj *= 0.5;
            aadj1 = dsign ? aadj : -aadj;
        }
        y = word0(rv) & 0x7ff00000;

        if (y == 0x100000 * (1024 + 1023 - 1)) {
            dval(rv0) = dval(rv);
            word0(rv) -= 53 * 0x100000;
            adj = aadj1 * func_002F6F50(dval(rv));
            dval(rv) += adj;
            if ((word0(rv) & 0x7ff00000) >= 0x100000 * (1024 + 1023 - 53)) {
                if (word0(rv0) == 0x7fefffff && word1(rv0) == 0xffffffff) {
                    goto ovfl;
                }
                word0(rv) = 0x7fefffff;
                word1(rv) = 0xffffffff;
                goto cont;
            } else {
                word0(rv) += 53 * 0x100000;
            }
        } else {
            if (y <= 52 * 0x100000) {
                if (aadj >= 1.) {
                    aadj1 = (int)(aadj + 0.5);
                    if (!dsign) {
                        aadj1 = -aadj1;
                    }
                }
            }
            adj = aadj1 * func_002F6F50(dval(rv));
            dval(rv) += adj;
        }
        z = word0(rv) & 0x7ff00000;
        if (y == z) {
            L = aadj;
            aadj -= L;
            if (dsign || word1(rv) || word0(rv) & 0xfffff) {
                if (aadj < .4999999 || aadj > .5000001) {
                    break;
                }
            } else if (aadj < .4999999 / 2) {
                break;
            }
        }
    cont:
        func_002F64A0(ptr, bb);
        func_002F64A0(ptr, bd);
        func_002F64A0(ptr, bs);
        func_002F64A0(ptr, delta);
    }
retfree:
    func_002F64A0(ptr, bb);
    func_002F64A0(ptr, bd);
    func_002F64A0(ptr, bs);
    func_002F64A0(ptr, bd0);
    func_002F64A0(ptr, delta);
ret:
    if (se) {
        *se = (char *)s;
    }
    return sign ? -dval(rv) : dval(rv);
}
#undef word0
#undef word1
#undef dval
#undef Bcopy

/* Module: newlib libc (reent, stdio, strtod/strtol, rand) */

double func_002F1D20(const char *s, char **end)
{
    return func_002F0E20(D_005681A4, s, end);
}

float func_002F1D50(const char *s, char **end)
{
    return (float)func_002F1D20(s, end);
}

char *func_002F1D78(char *s, const char *delim)
{
    return func_002F1DA0(s, delim, &D_005681A4->_strtok_last);
}

/* strtok_r; the gotos are those of the BSD source */
char *func_002F1DA0(char *s, const char *delim, char **lasts)
{
    char *spanp;
    int c, sc;
    char *tok;

    if (s == 0 && (s = *lasts) == 0) {
        return 0;
    }
cont:
    c = *s++;
    for (spanp = (char *)delim; (sc = *spanp++) != 0;) {
        if (c == sc) {
            goto cont;
        }
    }
    if (c == 0) {
        *lasts = 0;
        return 0;
    }
    tok = s - 1;
    for (;;) {
        c = *s++;
        spanp = (char *)delim;
        do {
            if ((sc = *spanp++) == c) {
                if (c == 0) {
                    s = 0;
                } else {
                    s[-1] = 0;
                }
                *lasts = s;
                return tok;
            }
        } while (sc != 0);
    }
}

INCLUDE_ASM("build/ee_asm/sdk/newlib/libc/libc_2F0840", func_002F1E40);

long func_002F2078(const char *s, char **end, int base)
{
    return func_002F1E40(D_005681A4, s, end, base);
}

int func_002F20B0(W11Reent *ptr, int fd)
{
    if (fd == 0) {
        return 0;
    }
    func_002ED118()->_errno = 0x58;
    return -1;
}

int func_002F20E8(int fd)
{
    return func_002F20B0(D_005681A4, fd);
}

int func_002F2110(int c)
{
    return (D_005780C9[c] & 1) ? c + 0x20 : c;
}

int func_002F2130(int c)
{
    return (D_005780C9[c] & 2) ? c - 0x20 : c;
}
