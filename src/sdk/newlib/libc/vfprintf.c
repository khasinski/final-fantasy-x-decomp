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

INCLUDE_ASM("build/ee_asm/sdk/newlib/libc/vfprintf", func_002F22C8);
INCLUDE_RODATA("build/ee_asm/sdk/newlib/libc/vfprintf/rodata", jtbl_00578350);

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
