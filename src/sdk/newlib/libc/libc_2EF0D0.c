/* tu_364 0x2ef0d0-0x2f032c: high; ~dbg (config/tu_map.tsv) */
#include "common.h"
#include "ffx/r7.h"
#include "ffx/q7.h"
#include "ffx/w11.h"
#include "ffx/v7.h"

/* Module: newlib libc (reent, stdio, strtod/strtol, rand) */

INCLUDE_ASM("build/ee_asm/sdk/newlib/libc/libc_2EF0D0", func_002EF0D0);

void func_002EF190(W11Reent *ptr) {
}

void func_002EF198(W11Reent *ptr) {
}

int func_002EF1A0(W11Reent *ptr, int a, int b, int c)
{
    int r;

    D_0057CBC0 = 0;
    r = func_002F89F8(a, b, c);
    if (r == -1) {
        if (D_0057CBC0 != 0) {
            ptr->_errno = D_0057CBC0;
        }
    }
    return r;
}

int func_002EF200(W11Reent *ptr, const char *fmt, ...)
{
    void *ap;

    R7_VA_START(ap, fmt, 6);
    return func_002F22C8(ptr, ptr->_stdout, fmt, ap);
}

int func_002EF240(char *fmt, ...)
{
    int ret;
    void *ap;

    R7_VA_START(ap, fmt, 7);
    D_005681A4->_stdout->_cookie54 = D_005681A4;
    ret = func_002F2250(D_005681A4->_stdout, fmt, ap);
    return ret;
}

int func_002EF290(W11Reent *ptr, const char *s)
{
    int c = func_002F0840(s);
    V7Uio uio;
    V7Iov iov[2];

    iov[0].iov_base = s;
    iov[0].iov_len = c;
    iov[1].iov_base = D_005781D8;
    iov[1].iov_len = 1;
    uio.uio_resid = c + 1;
    uio.uio_iov = &iov[0];
    uio.uio_iovcnt = 2;
    return func_002F5E90(ptr->_stdout, &uio) ? -1 : '\n';
}

int func_002EF318(const char *s)
{
    return func_002EF290(D_005681A4, s);
}

INCLUDE_ASM("build/ee_asm/sdk/newlib/libc/libc_2EF0D0", func_002EF340);

void func_002EFD68(u32 seed)
{
    D_005681A4->_rand_next = seed;
}

int func_002EFD78(void)
{
    W11Reent *r = D_005681A4;

    r->_rand_next = r->_rand_next * 1103515245 + 12345;
    return r->_rand_next & 0x7fffffff;
}

int func_002EFDA8(void)
{
    return func_002ED230();
}

int func_002EFDC8(W11File *fp)
{
    V7_CHECK_INIT(fp);
    fp->_r = 0;
    if (fp->_flags & 0x20) {
        return -1;
    }
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
    } else {
        if (fp->_ub_base != 0) {
            if (fp->_ub_base != fp->_ubuf) {
                func_002ED6D8(fp->_cookie54, fp->_ub_base);
            }
            fp->_ub_base = 0;
            if ((fp->_r = fp->_ur) != 0) {
                fp->_p = fp->_up;
                return 0;
            }
        }
    }
    if (fp->_bf_base == 0) {
        func_002EE288(fp);
    }
    if (fp->_flags & (1 | 2)) {
        func_002EE058(fp->_cookie54, func_002EFDA8);
    }
    fp->_p = fp->_bf_base;
    fp->_r = ((int (*)(void *, char *, int))fp->_read)(fp->_cookie, (char *)fp->_p, fp->_bf_size);
    fp->_flags &= ~0x2000;
    if (fp->_r <= 0) {
        if (fp->_r == 0) {
            fp->_flags |= 0x20;
        } else {
            fp->_r = 0;
            fp->_flags |= 0x40;
        }
        return -1;
    }
    return 0;
}

u32 func_002EFF40(W11Reent *ptr, int a)
{
    u32 r;

    D_0057CBC0 = 0;
    r = func_002F8A38(a);
    if (r == 0xFFFFFFFF) {
        if (D_0057CBC0 != 0) {
            ptr->_errno = D_0057CBC0;
        }
    }
    return r;
}

int func_002EFFA0(W11Reent *ptr, char *buf, const char *fmt, ...)
{
    W11File f;
    void *ap;
    int ret;

    R7_VA_START(ap, fmt, 5);
    f._flags = 0x208;
    f._bf_base = f._p = (u8 *)buf;
    f._bf_size = f._w = 0x7FFFFFFF;
    f._cookie54 = ptr;
    ret = func_002F2250(&f, fmt, ap);
    *f._p = 0;
    return ret;
}

int func_002F0008(char *buf, const char *fmt, ...)
{
    W11File f;
    void *ap;
    int ret;

    R7_VA_START(ap, fmt, 6);
    f._flags = 0x208;
    f._bf_base = f._p = (u8 *)buf;
    f._bf_size = f._w = 0x7FFFFFFF;
    f._cookie54 = D_005681A4;
    ret = func_002F2250(&f, fmt, ap);
    *f._p = 0;
    return ret;
}

int func_002F0078(void)
{
    return 0;
}

int func_002F0080(const char *str, const char *fmt, ...)
{
    int ret;
    void *ap;
    W11File f;

    f._flags = 4;
    f._bf_base = f._p = (u8 *)str;
    f._bf_size = f._r = func_002F0840(str);
    f._read = func_002F0078;
    f._ub_base = 0;
    f._lb_base = 0;
    f._cookie54 = D_005681A4;
    R7_VA_START(ap, fmt, 6);
    ret = func_002F3A70(&f, fmt, ap);
    return ret;
}

/* Module: newlib libc (reent, stdio, strtod/strtol, rand) */

int func_002F0108(W11File *fp, char *buf, int n)
{
    int ret = func_002F7418(fp->_cookie54, fp->_file, (int)buf, n); /* DEBT(TYPE): callee takes ints */

    if (ret >= 0) {
        fp->_offset += ret;
    } else {
        fp->_flags &= ~0x1000;
    }
    return ret;
}

int func_002F0170(void *cookie, const char *buf, int n)
{
    W11File *fp = (W11File *)cookie;
    int w;
    if (fp->_flags & 0x100) {
        func_002F6358(fp->_cookie54, fp->_file, 0, 2);
    }
    fp->_flags &= ~0x1000;
    w = func_002F4708(fp->_cookie54, fp->_file, (int)buf, n); /* DEBT(TYPE): callee takes ints */
    return w;
}

long func_002F01F0(W11File *fp, int off, int whence)
{
    long ret = func_002F6358(fp->_cookie54, fp->_file, off, whence);

    if (ret == -1) {
        fp->_flags &= ~0x1000;
    } else {
        fp->_offset = ret;
        fp->_flags |= 0x1000;
    }
    return ret;
}

int func_002F0258(W11File *fp)
{
    return func_002F4878(fp->_cookie54, fp->_file);
}

int func_002F0278(const char *s1, const char *s2)
{
    while (*s1 != '\0' && v7_tolower(*s1) == v7_tolower(*s2)) {
        s1++;
        s2++;
    }
    return v7_tolower(*(u8 *)s1) - v7_tolower(*(u8 *)s2);
}
