/* tu_368 0x2f3a70-0x2f5cb8: low; newlib/strtod; split at 0x2f5cb8: flag split: 0x2F5CB8-0x2F6D58 (newlib Bigint helpers) needs -fno-strict-aliasing, func_002F3A70 and func_002F48D0 do not (config/tu_map.tsv) */
#include "common.h"
#include "ffx/q7.h"
#include "ffx/w11.h"
#include "ffx/v7.h"

extern const short D_005784C0[17]; /* basefix */
char *func_002F4578(char *tab, char *fmt);
long func_002F2078(const char *s, char **end, int base);
unsigned long func_002F76E0(const char *s, char **end, int base);
int func_002F5D70(void *buf, int size, int count, W11File *fp);
int func_002F7808(int c, W11File *fp);
double func_002ED078(const char *s);

#define VF_LONG 0x01
#define VF_LONGDBL 0x02
#define VF_SHORT 0x04
#define VF_SUPPRESS 0x08
#define VF_POINTER 0x10
#define VF_NOSKIP 0x20
#define VF_SIGNOK 0x40
#define VF_NDIGITS 0x80
#define VF_PFXOK 0x100
#define VF_NZDIGITS 0x200
#define VF_DPTOK 0x100
#define VF_EXPOK 0x200

#define VF_CT_CHAR 0
#define VF_CT_CCL 1
#define VF_CT_STRING 2
#define VF_CT_INT 3
#define VF_CT_FLOAT 4

#define VF_VA_ARG(ap, type) (*((type *)(((ap) = (char *)(ap) + 8) - 8)))

int func_002F3A70(W11File *fp, const char *fmt0, void *ap)
{
    register const char *fmt = fmt0;
    register int c;
    register u32 width;
    register char *p;
    register int n;
    register int flags;
    char *p0;
    int nassigned;
    int nread;
    int base = 0;
    int m = 1;
    int wc;
    unsigned long (*ccfn)(const char *, char **, int) = 0;
    char ccltab[256];
    char buf[350];
    short *sp;
    int *ip;
    long *lp;

    nassigned = 0;
    nread = 0;
    for (;;) {
        wc = *fmt;
        fmt += m;
        if (wc == 0) {
            return nassigned;
        }
        if (m == 1 && (D_005780C9[wc] & 8)) {
            for (;;) {
                if (fp->_r <= 0 && func_002EFDC8(fp)) {
                    return nassigned;
                }
                if (!(D_005780C9[*fp->_p] & 8)) {
                    break;
                }
                nread++;
                fp->_r--;
                fp->_p++;
            }
            continue;
        }
        if (wc != '%') {
            goto literal;
        }
        width = 0;
        flags = 0;

    again:
        c = *fmt++;
        switch (c) {
        case '%':
        literal:
            p = (char *)fmt - m;
            for (n = 0; n < m; n++) {
                if (fp->_r <= 0 && func_002EFDC8(fp)) {
                    goto input_failure;
                }
                if (*fp->_p != *p) {
                    goto match_failure;
                }
                fp->_r--;
                fp->_p++;
                nread++;
                p++;
            }
            continue;

        case '*':
            flags |= VF_SUPPRESS;
            goto again;
        case 'l':
            flags |= VF_LONG;
            goto again;
        case 'L':
            flags |= VF_LONGDBL;
            goto again;
        case 'h':
            flags |= VF_SHORT;
            goto again;

        case '0':
        case '1':
        case '2':
        case '3':
        case '4':
        case '5':
        case '6':
        case '7':
        case '8':
        case '9':
            width = width * 10 + c - '0';
            goto again;

        case 'D':
            flags |= VF_LONG;
            /* FALLTHROUGH */
        case 'd':
            c = VF_CT_INT;
            ccfn = (unsigned long (*)(const char *, char **, int))func_002F2078;
            base = 10;
            break;

        case 'i':
            c = VF_CT_INT;
            ccfn = (unsigned long (*)(const char *, char **, int))func_002F2078;
            base = 0;
            break;

        case 'O':
            flags |= VF_LONG;
            /* FALLTHROUGH */
        case 'o':
            c = VF_CT_INT;
            ccfn = func_002F76E0;
            base = 8;
            break;

        case 'u':
            c = VF_CT_INT;
            ccfn = func_002F76E0;
            base = 10;
            break;

        case 'X':
        case 'x':
            flags |= VF_PFXOK;
            c = VF_CT_INT;
            ccfn = func_002F76E0;
            base = 16;
            break;

        case 'E':
        case 'G':
        case 'e':
        case 'f':
        case 'g':
            c = VF_CT_FLOAT;
            break;

        case 's':
            c = VF_CT_STRING;
            break;

        case '[':
            fmt = func_002F4578(ccltab, (char *)fmt);
            flags |= VF_NOSKIP;
            c = VF_CT_CCL;
            break;

        case 'c':
            flags |= VF_NOSKIP;
            c = VF_CT_CHAR;
            break;

        case 'p':
            flags |= VF_POINTER | VF_PFXOK;
            c = VF_CT_INT;
            ccfn = func_002F76E0;
            base = 16;
            break;

        case 'n':
            if (flags & VF_SUPPRESS) {
                continue;
            }
            if (flags & VF_SHORT) {
                sp = VF_VA_ARG(ap, short *);
                *sp = nread;
            } else if (flags & VF_LONG) {
                lp = VF_VA_ARG(ap, long *);
                *lp = nread;
            } else {
                ip = VF_VA_ARG(ap, int *);
                *ip = nread;
            }
            continue;

        case '\0':
            return -1;

        default:
            if (D_005780C9[c] & 1) {
                flags |= VF_LONG;
            }
            c = VF_CT_INT;
            ccfn = (unsigned long (*)(const char *, char **, int))func_002F2078;
            base = 10;
            break;
        }

        if (fp->_r <= 0 && func_002EFDC8(fp)) {
            goto input_failure;
        }

        if ((flags & VF_NOSKIP) == 0) {
            while (D_005780C9[*fp->_p] & 8) {
                nread++;
                if (--fp->_r > 0) {
                    fp->_p++;
                } else if (func_002EFDC8(fp)) {
                    goto input_failure;
                }
            }
        }

        switch (c) {
        case VF_CT_CHAR:
            if (width == 0) {
                width = 1;
            }
            if (flags & VF_SUPPRESS) {
                u32 sum = 0;
                for (;;) {
                    if ((n = fp->_r) < width) {
                        sum += n;
                        width -= n;
                        fp->_p += n;
                        if (func_002EFDC8(fp)) {
                            if (sum == 0) {
                                goto input_failure;
                            }
                            break;
                        }
                    } else {
                        sum += width;
                        fp->_r -= width;
                        fp->_p += width;
                        break;
                    }
                }
                nread += sum;
            } else {
                u32 r = func_002F5D70(VF_VA_ARG(ap, char *), 1, width, fp);
                if (r == 0) {
                    goto input_failure;
                }
                nread += r;
                nassigned++;
            }
            break;

        case VF_CT_CCL:
            if (width == 0) {
                width = ~0;
            }
            if (flags & VF_SUPPRESS) {
                n = 0;
                while (ccltab[*fp->_p]) {
                    n++;
                    fp->_r--;
                    fp->_p++;
                    if (--width == 0) {
                        break;
                    }
                    if (fp->_r <= 0 && func_002EFDC8(fp)) {
                        if (n == 0) {
                            goto input_failure;
                        }
                        break;
                    }
                }
                if (n == 0) {
                    goto match_failure;
                }
            } else {
                p0 = p = VF_VA_ARG(ap, char *);
                while (ccltab[*fp->_p]) {
                    fp->_r--;
                    *p++ = *fp->_p++;
                    if (--width == 0) {
                        break;
                    }
                    if (fp->_r <= 0 && func_002EFDC8(fp)) {
                        if (p == p0) {
                            goto input_failure;
                        }
                        break;
                    }
                }
                n = p - p0;
                if (n == 0) {
                    goto match_failure;
                }
                *p = 0;
                nassigned++;
            }
            nread += n;
            break;

        case VF_CT_STRING:
            if (width == 0) {
                width = ~0;
            }
            if (flags & VF_SUPPRESS) {
                n = 0;
                while (!(D_005780C9[*fp->_p] & 8)) {
                    n++;
                    fp->_r--;
                    fp->_p++;
                    if (--width == 0) {
                        break;
                    }
                    if (fp->_r <= 0 && func_002EFDC8(fp)) {
                        break;
                    }
                }
                nread += n;
            } else {
                p0 = p = VF_VA_ARG(ap, char *);
                while (!(D_005780C9[*fp->_p] & 8)) {
                    fp->_r--;
                    *p++ = *fp->_p++;
                    if (--width == 0) {
                        break;
                    }
                    if (fp->_r <= 0 && func_002EFDC8(fp)) {
                        break;
                    }
                }
                *p = 0;
                nread += p - p0;
                nassigned++;
            }
            break;

        case VF_CT_INT:
            if (--width > 349 - 1) {
                width = 349 - 1;
            }
            width++;
            flags |= VF_SIGNOK | VF_NDIGITS | VF_NZDIGITS;
            for (p = buf; width; width--) {
                c = *fp->_p;
                switch (c) {
                case '0':
                    if (base == 0) {
                        base = 8;
                        flags |= VF_PFXOK;
                    }
                    if (flags & VF_NZDIGITS) {
                        flags &= ~(VF_SIGNOK | VF_NZDIGITS | VF_NDIGITS);
                    } else {
                        flags &= ~(VF_SIGNOK | VF_PFXOK | VF_NDIGITS);
                    }
                    goto ok;

                case '1':
                case '2':
                case '3':
                case '4':
                case '5':
                case '6':
                case '7':
                    base = D_005784C0[base];
                    flags &= ~(VF_PFXOK | VF_SIGNOK | VF_NDIGITS);
                    goto ok;

                case '8':
                case '9':
                    base = D_005784C0[base];
                    if (base <= 8) {
                        break;
                    }
                    flags &= ~(VF_PFXOK | VF_SIGNOK | VF_NDIGITS);
                    goto ok;

                case 'A':
                case 'B':
                case 'C':
                case 'D':
                case 'E':
                case 'F':
                case 'a':
                case 'b':
                case 'c':
                case 'd':
                case 'e':
                case 'f':
                    if (base <= 10) {
                        break;
                    }
                    flags &= ~(VF_PFXOK | VF_SIGNOK | VF_NDIGITS);
                    goto ok;

                case '+':
                case '-':
                    if (flags & VF_SIGNOK) {
                        flags &= ~VF_SIGNOK;
                        goto ok;
                    }
                    break;

                case 'x':
                case 'X':
                    if ((flags & VF_PFXOK) && p == buf + 1) {
                        base = 16;
                        flags &= ~VF_PFXOK;
                        goto ok;
                    }
                    break;
                }
                break;

            ok:
                *p++ = c;
                if (--fp->_r > 0) {
                    fp->_p++;
                } else if (func_002EFDC8(fp)) {
                    break;
                }
            }

            if (flags & VF_NDIGITS) {
                if (p > buf) {
                    func_002F7808(*--p, fp);
                }
                goto match_failure;
            }
            c = p[-1];
            if (c == 'x' || c == 'X') {
                --p;
                func_002F7808(c, fp);
            }
            if ((flags & VF_SUPPRESS) == 0) {
                unsigned long res;
                *p = 0;
                res = (*ccfn)(buf, (char **)0, base);
                if (flags & VF_POINTER) {
                    *VF_VA_ARG(ap, void **) = (void *)(unsigned int)res;
                } else if (flags & VF_SHORT) {
                    sp = VF_VA_ARG(ap, short *);
                    *sp = res;
                } else if (flags & VF_LONG) {
                    lp = VF_VA_ARG(ap, long *);
                    *lp = res;
                } else {
                    ip = VF_VA_ARG(ap, int *);
                    *ip = res;
                }
                nassigned++;
            }
            nread += p - buf;
            break;

        case VF_CT_FLOAT:
            if (--width > 349 - 1) {
                width = 349 - 1;
            }
            width++;
            flags |= VF_SIGNOK | VF_NDIGITS | VF_DPTOK | VF_EXPOK;
            for (p = buf; width; width--) {
                c = *fp->_p;
                switch (c) {
                case '0':
                case '1':
                case '2':
                case '3':
                case '4':
                case '5':
                case '6':
                case '7':
                case '8':
                case '9':
                    flags &= ~(VF_SIGNOK | VF_NDIGITS);
                    goto fok;

                case '+':
                case '-':
                    if (flags & VF_SIGNOK) {
                        flags &= ~VF_SIGNOK;
                        goto fok;
                    }
                    break;
                case '.':
                    if (flags & VF_DPTOK) {
                        flags &= ~(VF_SIGNOK | VF_DPTOK);
                        goto fok;
                    }
                    break;
                case 'e':
                case 'E':
                    if ((flags & (VF_EXPOK | VF_NDIGITS)) == VF_EXPOK) {
                        flags = (flags & ~(VF_EXPOK | VF_DPTOK)) | VF_SIGNOK | VF_NDIGITS;
                        goto fok;
                    }
                    break;
                }
                break;
            fok:
                *p++ = c;
                if (--fp->_r > 0) {
                    fp->_p++;
                } else if (func_002EFDC8(fp)) {
                    break;
                }
            }
            if (flags & VF_NDIGITS) {
                if (flags & VF_EXPOK) {
                    while (p > buf) {
                        func_002F7808(*--p, fp);
                    }
                    goto match_failure;
                }
                c = *--p;
                if (c != 'e' && c != 'E') {
                    func_002F7808(c, fp);
                    c = *--p;
                }
                func_002F7808(c, fp);
            }
            if ((flags & VF_SUPPRESS) == 0) {
                double res;
                *p = 0;
                res = func_002ED078(buf);
                if (flags & VF_LONG) {
                    *VF_VA_ARG(ap, double *) = res;
                } else if (flags & VF_LONGDBL) {
                    *VF_VA_ARG(ap, double *) = res;
                } else {
                    *VF_VA_ARG(ap, float *) = (float)res;
                }
                nassigned++;
            }
            nread += p - buf;
            break;
        }
    }
input_failure:
    return nassigned ? nassigned : -1;
match_failure:
    return nassigned;
}

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
