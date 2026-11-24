/* tu_367 0x2f2150-0x2f3a70: medium; newlib/vfprintf (config/tu_map.tsv) */
#include "common.h"
#include "ffx/r7.h"
#include "ffx/q7.h"
#include "ffx/w11.h"
#include "ffx/v7.h"

int func_002F2150(W11File *fp, V7Uio *uio)
{
    int err;

    if (uio->uio_resid == 0) {
        uio->uio_iovcnt = 0;
        return 0;
    }
    err = func_002F5E90(fp, uio);
    uio->uio_resid = 0;
    uio->uio_iovcnt = 0;
    return err;
}

int func_002F2198(W11File *fp, const char *fmt, void *ap)
{
    int ret;
    W11File fake;
    u8 buf[0x400];

    fake._cookie54 = fp->_cookie54;
    fake._flags = fp->_flags & ~2;
    fake._file = fp->_file;
    fake._cookie = fp->_cookie;
    fake._write = fp->_write;
    fake._bf_base = fake._p = buf;
    fake._bf_size = fake._w = sizeof(buf);
    fake._lbfsize = 0;
    ret = func_002F2250(&fake, fmt, ap);
    if (ret >= 0 && func_002ED230(&fake)) {
        ret = -1;
    }
    if (fake._flags & 0x40) {
        fp->_flags |= 0x40;
    }
    return ret;
}

int func_002F2250(W11File *fp, const char *fmt0, void *ap)
{
    V7_CHECK_INIT(fp);
    return func_002F22C8(fp->_cookie54, fp, fmt0, ap);
}

extern int D_00568608;
extern const char D_005782B0[16]; /* blanks */
extern const char D_005782C0[16]; /* zeroes */
extern const char D_005782D0[];   /* "Inf" */
extern const char D_005782D8[];   /* "NaN" */
extern const char D_005782E0[];   /* "0123456789abcdef" */
extern const char D_005782F8[];   /* "(null)" */
extern const char D_00578300[];   /* "0123456789ABCDEF" */
extern const char D_00578318[];   /* "bug in vfprintf: bad base" */
extern const char D_00578338[];   /* "0" */
extern const char D_00578340[];   /* "." */
int func_002F7478(double x);
int func_002E7E60(double x);
char *func_002F37E0(W11Reent *data, double value, int ndigits, int flags, char *sign, int *decpt, int ch, int *length);
int func_002F3990(char *p0, int exp, int fmtch);
u32 *func_002F6330(void);
int func_002F63B8(W11Reent *r, int *pwc, const char *s, int n, int *state);
int func_002F0840(const char *s);

#define BUF (308 + 39 + 1)
#define DEFPREC 6
#define NIOV 8
#define PADSIZE 16

#define ALT       0x001
#define HEXPREFIX 0x002
#define LADJUST   0x004
#define LONGDBL   0x008
#define LONGINT   0x010
#define QUADINT   0x020
#define SHORTINT  0x040
#define ZEROPAD   0x080
#define FPT       0x100

#define to_digit(c) ((c) - '0')
#define is_digit(c) ((unsigned)to_digit(c) <= 9)
#define to_char(n)  ((n) + '0')

#define VA_ARG(ap, type) (*(type *)(((ap) = (char *)(ap) + 8) - 8))

#define SARG() \
    (flags & LONGINT ? VA_ARG(ap, long) : \
     flags & SHORTINT ? (long)(short)VA_ARG(ap, int) : \
     (long)VA_ARG(ap, int))
#define UARG() \
    (flags & LONGINT ? VA_ARG(ap, unsigned long) : \
     flags & SHORTINT ? (unsigned long)(unsigned short)VA_ARG(ap, int) : \
     (unsigned long)VA_ARG(ap, unsigned int))

#define PRINT(ptr, len) { \
    iovp->iov_base = (ptr); \
    iovp->iov_len = (len); \
    uio.uio_resid += (len); \
    iovp++; \
    if (++uio.uio_iovcnt >= NIOV) { \
        if (func_002F2150(fp, &uio)) \
            goto error; \
        iovp = iov; \
    } \
}
#define PAD(howmany, with) { \
    if ((n = (howmany)) > 0) { \
        while (n > PADSIZE) { \
            PRINT(with, PADSIZE); \
            n -= PADSIZE; \
        } \
        PRINT(with, n); \
    } \
}
#define FLUSH() { \
    if (uio.uio_resid && func_002F2150(fp, &uio)) \
        goto error; \
    uio.uio_iovcnt = 0; \
    iovp = iov; \
}

int func_002F22C8(W11Reent *data, W11File *fp, const char *fmt0, void *ap)
{
    register char *fmt;
    register int ch;
    register int n, m;
    register char *cp;
    register V7Iov *iovp;
    register int flags;
    int ret;
    int width;
    int prec;
    char sign;
    int wc;
    char *decimal_point = *(char **)func_002F6330();
    char softsign;
    double _double;
    int expt;
    int expsize;
    int ndig;
    char expstr[10];
    unsigned long _uquad;
    enum { OCT, DEC, HEX } base;
    int dprec;
    int realsz;
    int size;
    const char *xdigs;
    V7Uio uio;
    V7Iov iov[NIOV];
    char buf[BUF];
    char ox[2];
    int state = 0;

    if (((fp->_flags & 8) == 0 || fp->_bf_base == 0) && func_002F4768(fp)) {
        return -1;
    }

    if ((fp->_flags & (2 | 8 | 0x10)) == (2 | 8) && fp->_file >= 0) {
        return func_002F2198(fp, fmt0, ap);
    }

    fmt = (char *)fmt0;
    uio.uio_iov = iovp = iov;
    uio.uio_resid = 0;
    uio.uio_iovcnt = 0;
    ret = 0;

    for (;;) {
        cp = fmt;
        while ((n = func_002F63B8(D_005681A4, &wc, fmt, D_00568608, &state)) > 0) {
            fmt += n;
            if (wc == '%') {
                fmt--;
                break;
            }
        }
        if ((m = fmt - cp) != 0) {
            PRINT(cp, m);
            ret += m;
        }
        if (n <= 0) {
            goto done;
        }
        fmt++;

        flags = 0;
        dprec = 0;
        width = 0;
        prec = -1;
        sign = '\0';

rflag:
        ch = *fmt++;
reswitch:
        switch (ch) {
        case ' ':
            if (!sign) {
                sign = ' ';
            }
            goto rflag;
        case '#':
            flags |= ALT;
            goto rflag;
        case '*':
            if ((width = VA_ARG(ap, int)) >= 0) {
                goto rflag;
            }
            width = -width;
            /* FALLTHROUGH */
        case '-':
            flags |= LADJUST;
            goto rflag;
        case '+':
            sign = '+';
            goto rflag;
        case '.':
            if ((ch = *fmt++) == '*') {
                n = VA_ARG(ap, int);
                prec = n < 0 ? -1 : n;
                goto rflag;
            }
            n = 0;
            while (is_digit(ch)) {
                n = 10 * n + to_digit(ch);
                ch = *fmt++;
            }
            prec = n < 0 ? -1 : n;
            goto reswitch;
        case '0':
            flags |= ZEROPAD;
            goto rflag;
        case '1': case '2': case '3': case '4':
        case '5': case '6': case '7': case '8': case '9':
            n = 0;
            do {
                n = 10 * n + to_digit(ch);
                ch = *fmt++;
            } while (is_digit(ch));
            width = n;
            goto reswitch;
        case 'L':
            flags |= LONGDBL;
            goto rflag;
        case 'h':
            flags |= SHORTINT;
            goto rflag;
        case 'l':
            if (*fmt == 'l') {
                fmt++;
                flags |= QUADINT;
            } else {
                flags |= LONGINT;
            }
            goto rflag;
        case 'q':
            flags |= QUADINT;
            goto rflag;
        case 'c':
            *(cp = buf) = VA_ARG(ap, int);
            size = 1;
            sign = '\0';
            break;
        case 'D':
            flags |= LONGINT;
            /* FALLTHROUGH */
        case 'd':
        case 'i':
            _uquad = SARG();
            if ((long)_uquad < 0) {
                _uquad = -_uquad;
                sign = '-';
            }
            base = DEC;
            goto number;
        case 'e':
        case 'E':
        case 'f':
        case 'g':
        case 'G':
            if (prec == -1) {
                prec = DEFPREC;
            } else if ((ch == 'g' || ch == 'G') && prec == 0) {
                prec = 1;
            }
            if (flags & LONGDBL) {
                _double = (double)VA_ARG(ap, long double);
            } else {
                _double = VA_ARG(ap, double);
            }
            if (func_002F7478(_double)) {
                if (_double < 0) {
                    sign = '-';
                }
                cp = (char *)D_005782D0;
                size = 3;
                break;
            }
            if (func_002E7E60(_double)) {
                cp = (char *)D_005782D8;
                size = 3;
                break;
            }
            flags |= FPT;
            cp = func_002F37E0(data, _double, prec, flags, &softsign, &expt, ch, &ndig);
            if (ch == 'g' || ch == 'G') {
                if (expt <= -4 || expt > prec) {
                    ch = (ch == 'g') ? 'e' : 'E';
                } else {
                    ch = 'g';
                }
            }
            if (ch <= 'e') {
                --expt;
                expsize = func_002F3990(expstr, expt, ch);
                size = expsize + ndig;
                if (ndig > 1 || flags & ALT) {
                    ++size;
                }
            } else if (ch == 'f') {
                if (expt > 0) {
                    size = expt;
                    if (prec || flags & ALT) {
                        size += prec + 1;
                    }
                } else {
                    size = prec + 2;
                }
            } else if (expt >= ndig) {
                size = expt;
                if (flags & ALT) {
                    ++size;
                }
            } else {
                size = ndig + (expt > 0 ? 1 : 2 - expt);
            }
            if (softsign) {
                sign = '-';
            }
            break;
        case 'n':
            if (flags & LONGINT) {
                *VA_ARG(ap, long *) = ret;
            } else if (flags & SHORTINT) {
                *VA_ARG(ap, short *) = ret;
            } else {
                *VA_ARG(ap, int *) = ret;
            }
            continue;
        case 'O':
            flags |= LONGINT;
            /* FALLTHROUGH */
        case 'o':
            _uquad = UARG();
            base = OCT;
            goto nosign;
        case 'p':
            _uquad = (unsigned long)(long)VA_ARG(ap, void *);
            base = HEX;
            xdigs = D_005782E0;
            flags |= HEXPREFIX;
            ch = 'x';
            goto nosign;
        case 's':
            if ((cp = VA_ARG(ap, char *)) == 0) {
                cp = (char *)D_005782F8;
            }
            if (prec >= 0) {
                char *p = func_002EEDA8(cp, 0, prec);
                if (p != 0) {
                    size = p - cp;
                    if (size > prec) {
                        size = prec;
                    }
                } else {
                    size = prec;
                }
            } else {
                size = func_002F0840(cp);
            }
            sign = '\0';
            break;
        case 'U':
            flags |= LONGINT;
            /* FALLTHROUGH */
        case 'u':
            _uquad = UARG();
            base = DEC;
            goto nosign;
        case 'X':
            xdigs = D_00578300;
            goto hex;
        case 'x':
            xdigs = D_005782E0;
hex:
            _uquad = UARG();
            base = HEX;
            if (flags & ALT && _uquad != 0) {
                flags |= HEXPREFIX;
            }
nosign:
            sign = '\0';
number:
            if ((dprec = prec) >= 0) {
                flags &= ~ZEROPAD;
            }
            cp = buf + BUF;
            if (_uquad != 0 || prec != 0) {
                switch (base) {
                case OCT:
                    do {
                        *--cp = to_char(_uquad & 7);
                        _uquad >>= 3;
                    } while (_uquad);
                    if (flags & ALT && *cp != '0') {
                        *--cp = '0';
                    }
                    break;
                case DEC:
                    while (_uquad >= 10) {
                        *--cp = to_char(_uquad % 10);
                        _uquad /= 10;
                    }
                    *--cp = to_char(_uquad);
                    break;
                case HEX:
                    do {
                        *--cp = xdigs[_uquad & 15];
                        _uquad >>= 4;
                    } while (_uquad);
                    break;
                default:
                    cp = (char *)D_00578318;
                    size = func_002F0840(cp);
                    goto skipsize;
                }
            }
            size = buf + BUF - cp;
skipsize:
            break;
        default:
            if (ch == '\0') {
                goto done;
            }
            cp = buf;
            *cp = ch;
            size = 1;
            sign = '\0';
            break;
        }

        realsz = dprec > size ? dprec : size;
        if (sign) {
            realsz++;
        } else if (flags & HEXPREFIX) {
            realsz += 2;
        }

        if ((flags & (LADJUST | ZEROPAD)) == 0) {
            PAD(width - realsz, D_005782B0);
        }

        if (sign) {
            PRINT(&sign, 1);
        } else if (flags & HEXPREFIX) {
            ox[0] = '0';
            ox[1] = ch;
            PRINT(ox, 2);
        }

        if ((flags & (LADJUST | ZEROPAD)) == ZEROPAD) {
            PAD(width - realsz, D_005782C0);
        }

        PAD(dprec - size, D_005782C0);

        if ((flags & FPT) == 0) {
            PRINT(cp, size);
        } else {
            if (ch >= 'f') {
                if (_double == 0) {
                    PRINT(D_00578338, 1);
                    if (expt < ndig || (flags & ALT) != 0) {
                        PRINT(decimal_point, 1);
                        PAD(ndig - 1, D_005782C0);
                    }
                } else if (expt <= 0) {
                    PRINT(D_00578338, 1);
                    PRINT(decimal_point, 1);
                    PAD(-expt, D_005782C0);
                    PRINT(cp, ndig);
                } else if (expt >= ndig) {
                    PRINT(cp, ndig);
                    PAD(expt - ndig, D_005782C0);
                    if (flags & ALT) {
                        PRINT(D_00578340, 1);
                    }
                } else {
                    PRINT(cp, expt);
                    cp += expt;
                    PRINT(D_00578340, 1);
                    PRINT(cp, ndig - expt);
                }
            } else {
                if (ndig > 1 || flags & ALT) {
                    ox[0] = *cp++;
                    ox[1] = '.';
                    PRINT(ox, 2);
                    if (_double) {
                        PRINT(cp, ndig - 1);
                    } else {
                        PAD(ndig - 1, D_005782C0);
                    }
                } else {
                    PRINT(cp, 1);
                }
                PRINT(expstr, expsize);
            }
        }
        if (flags & LADJUST) {
            PAD(width - realsz, D_005782B0);
        }
        ret += width > realsz ? width : realsz;
        FLUSH();
    }
done:
    FLUSH();
error:
    return (fp->_flags & 0x40) ? -1 : ret;
}

/* Module: newlib libc (reent, stdio, strtod/strtol, rand) */

char *func_002F37E0(W11Reent *data, double value, int ndigits, int flags, char *sign, int *decpt, int ch, int *length)
{
    int mode, dsgn;
    char *digits, *bp, *rve;
    ieee_double_shape_type tmp;

    if (ch == 'f') {
        mode = 3;
    } else {
        if (ch == 'e' || ch == 'E') {
            ndigits++;
        }
        mode = 2;
    }
    tmp.value = value;
    if (tmp.parts.msw & 0x80000000) {
        value = func_002EBC08(0, value);
        *sign = '-';
    } else {
        *sign = '\000';
    }
    digits = func_002F4AE8(data, value, mode, ndigits, decpt, &dsgn, &rve);
    if ((ch != 'g' && ch != 'G') || flags & 1) {
        bp = digits + ndigits;
        if (ch == 'f') {
            if (*digits == '0' && func_002EC198(value, 0)) {
                *decpt = -ndigits + 1;
            }
            bp += *decpt;
        }
        if (func_002EC198(value, 0) == 0) {
            rve = bp;
        }
        while (rve < bp) {
            *rve++ = '0';
        }
    }
    *length = rve - digits;
    return digits;
}

int func_002F3990(char *p0, int exp, int fmtch)
{
    char *p, *t;
    char expbuf[308];

    p = p0;
    *p++ = fmtch;
    if (exp < 0) {
        exp = -exp;
        *p++ = '-';
    } else {
        *p++ = '+';
    }
    t = expbuf + 308;
    if (exp > 9) {
        do {
            *--t = exp % 10 + '0';
        } while ((exp /= 10) > 9);
        *--t = exp + '0';
        for (; t < expbuf + 308; *p++ = *t++) {
        }
    } else {
        *p++ = '0';
        *p++ = exp + '0';
    }
    return p - p0;
}
