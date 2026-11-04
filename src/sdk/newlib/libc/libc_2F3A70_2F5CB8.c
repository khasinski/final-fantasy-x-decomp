/* tu_368 0x2f5cb8-0x2f8000: low; newlib/strtod; split at 0x2f5cb8: flag split: 0x2F5CB8-0x2F6D58 (newlib Bigint helpers) needs -fno-strict-aliasing, func_002F3A70 and func_002F48D0 do not (config/tu_map.tsv) */
#include "common.h"
#include "ffx/r7.h"
#include "ffx/q7.h"
#include "ffx/w11.h"
#include "ffx/v7.h"

/* Module: newlib libc (malloc/Bigint, stdio) */

void func_002F5CB8(W11Reent *ptr) {
}

void func_002F5CC0(W11Reent *ptr) {
}

int func_002F5CC8(W11Reent *ptr, char *mode, int *optr)
{
    int ret, m, o;

    switch (mode[0]) {
    case 'r':
        ret = 4;
        m = 0;
        o = 0;
        break;
    case 'w':
        ret = 8;
        m = 1;
        o = 0x600;
        break;
    case 'a':
        ret = 0x108;
        m = 1;
        o = 0x208;
        break;
    default:
        ptr->_errno = 22;
        return 0;
    }
    if (mode[1] == '+' || mode[2] == '+') {
        ret = 0x10;
        m = 2;
    }
    *optr = m | o;
    return ret;
}

int func_002F5D70(void *buf, u32 size, u32 count, W11File *fp)
{
    u32 resid;
    char *p;
    int r;
    u32 total;

    if ((resid = count * size) == 0) {
        return 0;
    }
    if (fp->_r < 0) {
        fp->_r = 0;
    }
    total = resid;
    p = buf;
    while (resid > (r = fp->_r)) {
        func_002EEF1C(p, fp->_p, r);
        fp->_p += r;
        p += r;
        resid -= r;
        if (func_002EFDC8(fp)) {
            return (total - resid) / size;
        }
    }
    func_002EEF1C(p, fp->_p, resid);
    fp->_r -= resid;
    fp->_p += resid;
    return count;
}

#define V7_MIN(a, b) ((a) < (b) ? (a) : (b))
#define COPY(n) func_002EEFCC(fp->_p, p, (n))
#define GETIOV(extra_work) \
    while (len == 0) { \
        extra_work; \
        p = iov->iov_base; \
        len = iov->iov_len; \
        iov++; \
    }
typedef int (*V7WriteFn)(void *cookie, const char *buf, int n);
/* __sfvwrite; the gotos are those of the BSD source */
int func_002F5E90(W11File *fp, V7Uio *uio)
{
    u32 len;
    const char *p;
    V7Iov *iov;
    int w, s;
    char *nl;
    int nlknown, nldist;

    if ((len = uio->uio_resid) == 0) {
        return 0;
    }
    if (((fp->_flags & 8) == 0 || fp->_bf_base == 0) && func_002F4768(fp)) {
        return -1;
    }
    iov = uio->uio_iov;
    len = 0;
    if (fp->_flags & 2) {
        do {
            GETIOV(;);
            w = ((V7WriteFn)fp->_write)(fp->_cookie, p, V7_MIN(len, 0x400));
            if (w <= 0) {
                goto err;
            }
            p += w;
            len -= w;
        } while ((uio->uio_resid -= w) != 0);
    } else if ((fp->_flags & 1) == 0) {
        do {
            GETIOV(;);
            w = fp->_w;
            if (fp->_flags & 0x200) {
                if (len < w) {
                    w = len;
                }
                COPY(w);
                fp->_w -= w;
                fp->_p += w;
                w = len;
            } else if (fp->_p > fp->_bf_base && len > w) {
                COPY(w);
                fp->_p += w;
                if (func_002ED230(fp)) {
                    goto err;
                }
            } else if (len >= (w = fp->_bf_size)) {
                w = ((V7WriteFn)fp->_write)(fp->_cookie, p, w);
                if (w <= 0) {
                    goto err;
                }
            } else {
                w = len;
                COPY(w);
                fp->_w -= w;
                fp->_p += w;
            }
            p += w;
            len -= w;
        } while ((uio->uio_resid -= w) != 0);
    } else {
        nlknown = 0;
        do {
            GETIOV(nlknown = 0);
            if (!nlknown) {
                nl = func_002EEDA8(p, '\n', len);
                nldist = nl ? nl + 1 - p : len + 1;
                nlknown = 1;
            }
            s = V7_MIN(len, nldist);
            w = fp->_w + fp->_bf_size;
            if (fp->_p > fp->_bf_base && s > w) {
                COPY(w);
                fp->_p += w;
                if (func_002ED230(fp)) {
                    goto err;
                }
            } else if (s >= (w = fp->_bf_size)) {
                w = ((V7WriteFn)fp->_write)(fp->_cookie, p, w);
                if (w <= 0) {
                    goto err;
                }
            } else {
                w = s;
                COPY(w);
                fp->_w -= w;
                fp->_p += w;
            }
            if ((nldist -= w) == 0) {
                if (func_002ED230(fp)) {
                    goto err;
                }
                nlknown = 0;
            }
            p += w;
            len -= w;
        } while ((uio->uio_resid -= w) != 0);
    }
    return 0;

err:
    fp->_flags |= 0x40;
    return -1;
}
#undef COPY
#undef GETIOV

char *func_002F6268(W11Reent *p, int category, const char *locale)
{
    if (locale) {
        if (func_002F05E8((int)locale, (u8 *)D_005789C8) && func_002F05E8((int)locale, (u8 *)D_005789B8)) { /* DEBT(TYPE): strcmp prototype */
            return 0;
        }
        p->_current_category = category;
        p->_current_locale = locale;
    }
    return D_005789C8;
}

u32 *func_002F62F0(W11Reent *r)
{
    return D_00578988;
}

char *func_002F6300(int category, const char *locale)
{
    return func_002F6268(D_005681A4, category, locale);
}

u32 *func_002F6330(void)
{
    return func_002F62F0(D_005681A4);
}

int func_002F6358(W11Reent *ptr, int a, int b, int c)
{
    int r;

    D_0057CBC0 = 0;
    r = func_002F8A30(a, b, c);
    if (r == -1) {
        if (D_0057CBC0 != 0) {
            ptr->_errno = D_0057CBC0;
        }
    }
    return r;
}

int func_002F63B8(W11Reent *r, int *pwc, const char *s, int n, int *state)
{
    int dummy;
    u8 *t = (u8 *)s;

    if (pwc == 0) {
        pwc = &dummy;
    }
    if (s != 0 && n == 0) {
        return -1;
    }
    if (s == 0) {
        return 0;
    }
    *pwc = *t;
    return *t != 0;
}

W11Bigint *func_002F63F8(W11Reent *ptr, int k)
{
    int x;
    W11Bigint *rv;

    if (ptr->_freelist == 0) {
        ptr->_freelist = func_002F7990(ptr, sizeof(W11Bigint *), 16);
        if (ptr->_freelist == 0) {
            return 0;
        }
    }
    if ((rv = ptr->_freelist[k]) != 0) {
        ptr->_freelist[k] = rv->_next;
    } else {
        x = 1 << k;
        rv = func_002F7990(ptr, 1, sizeof(W11Bigint) + (x - 1) * sizeof(rv->_x));
        if (rv == 0) {
            return 0;
        }
        rv->_k = k;
        rv->_maxwds = x;
    }
    rv->_sign = rv->_wds = 0;
    return rv;
}

void func_002F64A0(W11Reent *ptr, W11Bigint *v)
{
    W11Bigint **slots;

    if (v != 0)
    {
        slots = ptr->_freelist;
        v->_next = slots[v->_k];
        slots[v->_k] = v;
    }
}

W11Bigint *func_002F64D0(W11Reent *ptr, W11Bigint *b, int m, int a)
{
    int i, wds;
    u32 *x, y;
    u32 xi, z;
    W11Bigint *b1;

    wds = b->_wds;
    x = b->_x;
    i = 0;
    do {
        xi = *x;
        y = (xi & 0xffff) * m + a;
        z = (xi >> 16) * m + (y >> 16);
        a = (int)(z >> 16);
        *x++ = (z << 16) + (y & 0xffff);
    } while (++i < wds);
    if (a) {
        if (wds >= b->_maxwds) {
            b1 = func_002F63F8(ptr, b->_k + 1);
            func_002EEF1C(&b1->_sign, &b->_sign, b->_wds * sizeof(int) + 2 * sizeof(int));
            func_002F64A0(ptr, b);
            b = b1;
        }
        b->_x[wds++] = a;
        b->_wds = wds;
    }
    return b;
}

W11Bigint *func_002F65E8(W11Reent *ptr, const char *s, int nd0, int nd, u32 y9)
{
    W11Bigint *b;
    int i, k;
    int x, y;

    x = (nd + 8) / 9;
    for (k = 0, y = 1; x > y; y <<= 1, k++) {
    }
    b = func_002F63F8(ptr, k);
    b->_x[0] = y9;
    b->_wds = 1;
    i = 9;
    if (9 < nd0) {
        s += 9;
        do {
            b = func_002F64D0(ptr, b, 10, *s++ - '0');
        } while (++i < nd0);
        s++;
    } else {
        s += 10;
    }
    for (; i < nd; i++) {
        b = func_002F64D0(ptr, b, 10, *s++ - '0');
    }
    return b;
}

int func_002F6730(u32 x)
{
    int k = 0;

    if (!(x & 0xffff0000)) {
        k = 16;
        x <<= 16;
    }
    if (!(x & 0xff000000)) {
        k += 8;
        x <<= 8;
    }
    if (!(x & 0xf0000000)) {
        k += 4;
        x <<= 4;
    }
    if (!(x & 0xc0000000)) {
        k += 2;
        x <<= 2;
    }
    if (!(x & 0x80000000)) {
        k++;
        if (!(x & 0x40000000)) {
            return 32;
        }
    }
    return k;
}

int func_002F67B8(u32 *y)
{
    int k;
    u32 x = *y;

    if (x & 7) {
        if (x & 1) {
            return 0;
        }
        if (x & 2) {
            *y = x >> 1;
            return 1;
        }
        *y = x >> 2;
        return 2;
    }
    k = 0;
    if (!(x & 0xffff)) {
        k = 16;
        x >>= 16;
    }
    if (!(x & 0xff)) {
        k += 8;
        x >>= 8;
    }
    if (!(x & 0xf)) {
        k += 4;
        x >>= 4;
    }
    if (!(x & 0x3)) {
        k += 2;
        x >>= 2;
    }
    if (!(x & 1)) {
        k++;
        x >>= 1;
        if (!x & 1) {
            return 32;
        }
    }
    *y = x;
    return k;
}

W11Bigint *func_002F6878(W11Reent *r, int i)
{
    W11Bigint *b = func_002F63F8(r, 1);

    b->_x[0] = i;
    b->_wds = 1;
    return b;
}

INCLUDE_ASM("build/ee_asm/sdk/newlib/libc/libc_2F3A70_2F5CB8", func_002F68B0);

W11Bigint *func_002F6AE0(W11Reent *ptr, W11Bigint *b, int k)
{
    W11Bigint *b1, *p5, *p51;
    int i;

    if ((i = k & 3) != 0) {
        b = func_002F64D0(ptr, b, D_005789D0[i - 1], 0);
    }
    if (!(k >>= 2)) {
        return b;
    }
    if (!(p5 = ptr->_p5s)) {
        p5 = ptr->_p5s = func_002F6878(ptr, 625);
        p5->_next = 0;
    }
    for (;;) {
        if (k & 1) {
            b1 = func_002F68B0(ptr, b, p5);
            func_002F64A0(ptr, b);
            b = b1;
        }
        if (!(k >>= 1)) {
            break;
        }
        if (!(p51 = p5->_next)) {
            p51 = p5->_next = func_002F68B0(ptr, p5, p5);
            p51->_next = 0;
        }
        p5 = p51;
    }
    return b;
}

W11Bigint *func_002F6BE0(W11Reent *ptr, W11Bigint *b, int k)
{
    int i, k1, n, n1;
    W11Bigint *b1;
    u32 *x, *x1, *xe, z;

    n = k >> 5;
    k1 = b->_k;
    n1 = n + b->_wds + 1;
    for (i = b->_maxwds; n1 > i; i <<= 1) {
        k1++;
    }
    b1 = func_002F63F8(ptr, k1);
    x1 = b1->_x;
    for (i = 0; i < n; i++) {
        *x1++ = 0;
    }
    x = b->_x;
    xe = x + b->_wds;
    if (k &= 0x1f) {
        k1 = 32 - k;
        z = 0;
        do {
            *x1++ = *x << k | z;
            z = *x++ >> k1;
        } while (x < xe);
        if ((*x1 = z) != 0) {
            ++n1;
        }
    } else {
        do {
            *x1++ = *x++;
        } while (x < xe);
    }
    b1->_wds = n1 - 1;
    func_002F64A0(ptr, b);
    return b1;
}

/* Module: newlib libc (malloc/Bigint, stdio) */

int func_002F6D58(W11Bigint *a, W11Bigint *b)
{
    u32 *xa, *xa0, *xb, *xb0;
    int i, j;

    i = a->_wds;
    j = b->_wds;
    if (i -= j) {
        return i;
    }
    xa0 = a->_x;
    xa = xa0 + j;
    xb0 = b->_x;
    xb = xb0 + j;
    for (;;) {
        if (*--xa != *--xb) {
            return *xa < *xb ? -1 : 1;
        }
        if (xa <= xa0) {
            break;
        }
    }
    return 0;
}

W11Bigint *func_002F6DC0(W11Reent *ptr, W11Bigint *a, W11Bigint *b)
{
    W11Bigint *c;
    int i, wa, wb;
    int borrow, y;
    u32 *xa, *xae, *xb, *xbe, *xc;
    int z;

    i = func_002F6D58(a, b);
    if (!i) {
        c = func_002F63F8(ptr, 0);
        c->_wds = 1;
        c->_x[0] = 0;
        return c;
    }
    if (i < 0) {
        c = a;
        a = b;
        b = c;
        i = 1;
    } else {
        i = 0;
    }
    c = func_002F63F8(ptr, a->_k);
    c->_sign = i;
    wa = a->_wds;
    xa = a->_x;
    xae = xa + wa;
    wb = b->_wds;
    xb = b->_x;
    xbe = xb + wb;
    xc = c->_x;
    borrow = 0;
    do {
        y = (*xa & 0xffff) - (*xb & 0xffff) + borrow;
        borrow = y >> 16;
        z = (*xa++ >> 16) - (*xb++ >> 16) + borrow;
        borrow = z >> 16;
        ((u16 *)xc)[1] = z; /* Storeinc(xc, z, y) */
        ((u16 *)xc)[0] = y;
        xc++;
    } while (xb < xbe);
    while (xa < xae) {
        y = (*xa & 0xffff) + borrow;
        borrow = y >> 16;
        z = (*xa++ >> 16) + borrow;
        borrow = z >> 16;
        ((u16 *)xc)[1] = z;
        ((u16 *)xc)[0] = y;
        xc++;
    }
    while (!*--xc) {
        wa--;
    }
    c->_wds = wa;
    return c;
}

double func_002F6F50(double _x)
{
    ieee_double_shape_type x, a;
    int L;

    x.value = _x;
    L = (x.parts.msw & 0x7ff00000) - (53 - 1) * 0x100000;
    if (L > 0) {
        a.parts.msw = L;
        a.parts.lsw = 0;
    } else {
        L = -L >> 20;
        if (L < 20) {
            a.parts.msw = 0x80000 >> L;
            a.parts.lsw = 0;
        } else {
            a.parts.msw = 0;
            L -= 20;
            a.parts.lsw = L >= 31 ? 1 : 1 << (31 - L);
        }
    }
    return a.value;
}

/* b2d; the goto is the one of the dtoa source */
double func_002F6FE8(W11Bigint *a, int *e)
{
    u32 *xa, *xa0, w, y, z;
    int k;
    ieee_double_shape_type d;

    xa0 = a->_x;
    xa = xa0 + a->_wds;
    y = *--xa;
    k = func_002F6730(y);
    *e = 32 - k;
    if (k < 11) {
        d.parts.msw = 0x3ff00000 | y >> (11 - k);
        w = xa > xa0 ? *--xa : 0;
        d.parts.lsw = y << (32 - 11 + k) | w >> (11 - k);
        goto ret_d;
    }
    z = xa > xa0 ? *--xa : 0;
    if (k -= 11) {
        d.parts.msw = 0x3ff00000 | y << k | z >> (32 - k);
        y = xa > xa0 ? *--xa : 0;
        d.parts.lsw = z << k | y >> (32 - k);
    } else {
        d.parts.msw = 0x3ff00000 | y;
        d.parts.lsw = z;
    }
ret_d:
    return d.value;
}

W11Bigint *func_002F7168(W11Reent *ptr, double _d, int *e, int *bits)
{
    ieee_double_shape_type d;
    W11Bigint *b;
    int de, i, k;
    u32 *x, y, z;

    d.value = _d;
    b = func_002F63F8(ptr, 1);
    x = b->_x;
    z = d.parts.msw & 0xfffff;
    d.parts.msw &= 0x7fffffff;
    if ((de = (int)(d.parts.msw >> 20)) != 0) {
        z |= 0x100000;
    }
    if ((y = d.parts.lsw) != 0) {
        if ((k = func_002F67B8(&y)) != 0) {
            x[0] = y | z << (32 - k);
            z >>= k;
        } else {
            x[0] = y;
        }
        i = b->_wds = (x[1] = z) ? 2 : 1;
    } else {
        k = func_002F67B8(&z);
        x[0] = z;
        i = b->_wds = 1;
        k += 32;
    }
    if (de) {
        *e = de - 1023 - (53 - 1) + k;
        *bits = 53 - k;
    } else {
        *e = de - 1023 - (53 - 1) + 1 + k;
        *bits = 32 * i - func_002F6730(x[i - 1]);
    }
    return b;
}

double func_002F72E8(W11Bigint *a, W11Bigint *b)
{
    ieee_double_shape_type da, db;
    int k, ka, kb;

    da.value = func_002F6FE8(a, &ka);
    db.value = func_002F6FE8(b, &kb);
    k = ka - kb + 32 * (a->_wds - b->_wds);
    if (k > 0) {
        da.parts.msw += k * 0x100000;
    } else {
        k = -k;
        db.parts.msw += k * 0x100000;
    }
    return func_002EBF18(da.value, db.value);
}

double func_002F73A8(int dig)
{
    double v = 1.0;

    if (dig < 24) {
        return D_005789E0[dig];
    }
    while (dig > 0) {
        v = func_002EBC70(v, 10.0);
        dig--;
    }
    return v;
}

long func_002F7418(W11Reent *ptr, int a, int b, int c)
{
    int r;

    D_0057CBC0 = 0;
    r = func_002F8980(a, b, c);
    if (r == -1) {
        if (D_0057CBC0 != 0) {
            ptr->_errno = D_0057CBC0;
        }
    }
    return r;
}

int func_002F7478(double x)
{
    int hx, lx;

    EXTRACT_WORDS(hx, lx, x);
    hx &= 0x7fffffff;
    hx |= (u32)(lx | (-lx)) >> 31;
    hx = 0x7ff00000 - hx;
    return 1 - (((u32)(hx | (-hx))) >> 31);
}

INCLUDE_ASM("build/ee_asm/sdk/newlib/libc/libc_2F3A70_2F5CB8", func_002F74C0);

int func_002F76E0(int a, int b, int c)
{
    return func_002F74C0(D_005681A4, a, b, c);
}

int func_002F7718(W11File *fp)
{
    int i;
    u8 *p;

    if (fp->_ub_base == fp->_ubuf) {
        if ((p = func_002EE630(fp->_cookie54, 0x400)) == 0) {
            return -1;
        }
        fp->_ub_base = p;
        fp->_ub_size = 0x400;
        p += 0x400 - sizeof(fp->_ubuf);
        for (i = sizeof(fp->_ubuf); --i >= 0;) {
            p[i] = fp->_ubuf[i];
        }
        fp->_p = p;
        return 0;
    }
    i = fp->_ub_size;
    p = func_002F7A50(fp->_cookie54, fp->_ub_base, i << 1);
    if (p == 0) {
        return -1;
    }
    func_002EEF1C(p + i, p, i);
    fp->_p = p + i;
    fp->_ub_base = p;
    fp->_ub_size = i << 1;
    return 0;
}

int func_002F7808(int c, W11File *fp)
{
    if (c == -1) {
        return -1;
    }
    V7_CHECK_INIT(fp);
    fp->_flags &= ~0x20;
    if ((fp->_flags & 4) == 0) {
        if ((fp->_flags & 0x10) == 0) {
            return -1;
        }
        if (fp->_flags & 8) {
            if (func_002ED230(fp)) {
                return -1;
            }
            fp->_flags &= ~8;
            fp->_w = 0;
            fp->_lbfsize = 0;
        }
        fp->_flags |= 4;
    }
    c = (u8)c;
    if (fp->_ub_base != 0) {
        if (fp->_r >= fp->_ub_size && func_002F7718(fp)) {
            return -1;
        }
        *--fp->_p = c;
        fp->_r++;
        return c;
    }
    if (fp->_bf_base != 0 && fp->_p > fp->_bf_base && fp->_p[-1] == c) {
        fp->_p--;
        fp->_r++;
        return c;
    }
    fp->_ur = fp->_r;
    fp->_up = fp->_p;
    fp->_ub_base = fp->_ubuf;
    fp->_ub_size = sizeof(fp->_ubuf);
    fp->_ubuf[sizeof(fp->_ubuf) - 1] = c;
    fp->_p = &fp->_ubuf[sizeof(fp->_ubuf) - 1];
    fp->_r = 1;
    return c;
}

INCLUDE_ASM("build/ee_asm/sdk/newlib/libc/libc_2F3A70_2F5CB8", func_002F7990);

INCLUDE_ASM("build/ee_asm/sdk/newlib/libc/libc_2F3A70_2F5CB8", func_002F7A50);

/* Module: EE kernel/syscall wrapper library, SIO, misc libc */

void func_002F7FC0(void)
{
    __asm__ volatile(
        "addiu      $3, $0, 0x0\n"
        "syscall    0 /* handwritten instruction */\n"
        "nop\n"
        :  :  : "$3");
}

void func_002F7FD0(void)
{
    __asm__ volatile(
        "addiu      $3, $0, 0x1\n"
        "syscall    0 /* handwritten instruction */\n"
        "nop\n"
        :  :  : "$3");
}

void func_002F7FE0(void)
{
    __asm__ volatile(
        "addiu      $3, $0, 0x2\n"
        "syscall    0 /* handwritten instruction */\n"
        "nop\n"
        :  :  : "$3");
}

void func_002F7FF0(void)
{
    __asm__ volatile(
        "addiu      $3, $0, 0x3\n"
        "syscall    0 /* handwritten instruction */\n"
        "nop\n"
        :  :  : "$3");
}
