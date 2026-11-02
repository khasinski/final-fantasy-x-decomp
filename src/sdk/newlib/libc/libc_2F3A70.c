/* tu_368 0x2f3a70-0x2f5cb8: low; newlib/strtod; split at 0x2f5cb8: flag split: 0x2F5CB8-0x2F6D58 (newlib Bigint helpers) needs -fno-strict-aliasing, func_002F3A70 and func_002F48D0 do not (config/tu_map.tsv) */
#include "common.h"
#include "ffx/q7.h"
#include "ffx/w11.h"
#include "ffx/v7.h"

INCLUDE_ASM("build/ee_asm/sdk/newlib/libc/libc_2F3A70", func_002F3A70);
INCLUDE_RODATA("build/ee_asm/sdk/newlib/libc/libc_2F3A70/rodata", jtbl_005784F0);
INCLUDE_RODATA("build/ee_asm/sdk/newlib/libc/libc_2F3A70/rodata", jtbl_005786E0);
INCLUDE_RODATA("build/ee_asm/sdk/newlib/libc/libc_2F3A70/rodata", jtbl_00578700);
INCLUDE_RODATA("build/ee_asm/sdk/newlib/libc/libc_2F3A70/rodata", jtbl_00578840);

/* __sccl (vfscanf.c); the goto is the one of the BSD source */
char *func_002F4578(char *tab, char *fmt)
{
    int c, n, v;

    c = *fmt++;
    if (c == '^') {
        v = 1;
        c = *fmt++;
    } else {
        v = 0;
    }
    for (n = 0; n < 256; n++) {
        tab[n] = v;
    }
    if (c == 0) {
        return fmt - 1;
    }
    v = 1 - v;
    for (;;) {
        tab[c] = v;
    doswitch:
        n = *fmt++;
        switch (n) {
        case 0:
            return fmt - 1;
        case '-':
            n = *fmt;
            if (n == ']' || n < c) {
                c = '-';
                break;
            }
            fmt++;
            do {
                tab[++c] = v;
            } while (c < n);
            goto doswitch;
        case ']':
            return fmt;
        default:
            c = n;
            break;
        }
    }
}

int func_002F4680(const char *fmt, void *ap)
{
    return func_002F2250(D_005681A4->_stdout, fmt, ap);
}

int func_002F46B0(char *buf, const char *fmt, void *ap)
{
    int ret;
    W11File f;

    f._flags = 0x208;
    f._bf_base = f._p = (u8 *)buf;
    f._bf_size = f._w = 0x7FFFFFFF;
    f._cookie54 = D_005681A4;
    ret = func_002F2250(&f, fmt, ap);
    *f._p = 0;
    return ret;
}

long func_002F4708(W11Reent *ptr, int a, int b, int c)
{
    int r;

    D_0057CBC0 = 0;
    r = func_002F8900(a, b, c);
    if (r == -1) {
        if (D_0057CBC0 != 0) {
            ptr->_errno = D_0057CBC0;
        }
    }
    return r;
}

int func_002F4768(W11File *fp)
{
    V7_CHECK_INIT(fp);
    if ((fp->_flags & 8) == 0) {
        if ((fp->_flags & 0x10) == 0) {
            return -1;
        }
        if (fp->_flags & 4) {
            if (fp->_ub_base != 0) {
                if (fp->_ub_base != fp->_ubuf) {
                    func_002ED6D8(fp->_cookie54, fp->_ub_base);
                }
                fp->_ub_base = 0;
            }
            fp->_flags &= ~(4 | 0x20);
            fp->_r = 0;
            fp->_p = fp->_bf_base;
        }
        fp->_flags |= 8;
    }
    if (fp->_bf_base == 0) {
        func_002EE288(fp);
    }
    if (fp->_flags & 1) {
        fp->_w = 0;
        fp->_lbfsize = -fp->_bf_size;
    } else {
        fp->_w = fp->_flags & 2 ? 0 : fp->_bf_size;
    }
    return 0;
}

int func_002F4878(void *ptr, int a)
{
    W11Reent *re = ptr;
    int r;

    D_0057CBC0 = 0;
    r = func_002F8A20(a);
    if (r == -1) {
        if (D_0057CBC0 != 0) {
            re->_errno = D_0057CBC0;
        }
    }
    return r;
}

int func_002F48D0(W11Bigint *b, W11Bigint *S)
{
    int n;
    int borrow, y;
    u32 carry, q, ys;
    u32 *bx, *bxe, *sx, *sxe;
    int z;
    u32 si, zs;

    n = S->_wds;
    if (b->_wds < n) {
        return 0;
    }
    sx = S->_x;
    sxe = sx + --n;
    bx = b->_x;
    bxe = bx + n;
    q = *bxe / (*sxe + 1);
    if (q) {
        borrow = 0;
        carry = 0;
        do {
            si = *sx++;
            ys = (si & 0xffff) * q + carry;
            zs = (si >> 16) * q + (ys >> 16);
            carry = zs >> 16;
            y = (*bx & 0xffff) - (ys & 0xffff) + borrow;
            borrow = y >> 16;
            z = (*bx >> 16) - (zs & 0xffff) + borrow;
            borrow = z >> 16;
            ((u16 *)bx)[1] = z; /* Storeinc(bx, z, y) */
            ((u16 *)bx)[0] = y;
            bx++;
        } while (sx <= sxe);
        if (!*bxe) {
            bx = b->_x;
            while (--bxe > bx && !*bxe) {
                --n;
            }
            b->_wds = n;
        }
    }
    if (func_002F6D58(b, S) >= 0) {
        q++;
        borrow = 0;
        carry = 0;
        bx = b->_x;
        sx = S->_x;
        do {
            si = *sx++;
            ys = (si & 0xffff) + carry;
            zs = (si >> 16) + (ys >> 16);
            carry = zs >> 16;
            y = (*bx & 0xffff) - (ys & 0xffff) + borrow;
            borrow = y >> 16;
            z = (*bx >> 16) - (zs & 0xffff) + borrow;
            borrow = z >> 16;
            ((u16 *)bx)[1] = z;
            ((u16 *)bx)[0] = y;
            bx++;
        } while (sx <= sxe);
        bx = b->_x;
        bxe = bx + n;
        if (!*bxe) {
            while (--bxe > bx && !*bxe) {
                --n;
            }
            b->_wds = n;
        }
    }
    return q;
}

INCLUDE_ASM("build/ee_asm/sdk/newlib/libc/libc_2F3A70", func_002F4AE8);
INCLUDE_RODATA("build/ee_asm/sdk/newlib/libc/libc_2F3A70/rodata", jtbl_00578970);
