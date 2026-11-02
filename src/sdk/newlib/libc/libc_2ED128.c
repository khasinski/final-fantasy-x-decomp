/* tu_362 0x2ed128-0x2eef1c: low; ~set (config/tu_map.tsv) */
#include "common.h"
#include "ffx/r7.h"
#include "ffx/q7.h"
#include "ffx/w11.h"
#include "ffx/v7.h"

int func_002ED128(W11File *fp)
{
    int r;

    if (fp == 0) {
        return 0;
    }
    V7_CHECK_INIT(fp);
    if (fp->_flags == 0) {
        return 0;
    }
    r = fp->_flags & 8 ? func_002ED230(fp) : 0;
    if (fp->_close != 0 && ((int (*)(void *))fp->_close)(fp->_cookie) < 0) {
        r = -1;
    }
    if (fp->_flags & 0x80) {
        func_002ED6D8(fp->_cookie54, fp->_bf_base);
    }
    if (fp->_ub_base != 0) {
        if (fp->_ub_base != fp->_ubuf) {
            func_002ED6D8(fp->_cookie54, fp->_ub_base);
        }
        fp->_ub_base = 0;
    }
    if (fp->_lb_base != 0) {
        func_002ED6D8(fp->_cookie54, fp->_lb_base);
        fp->_lb_base = 0;
    }
    fp->_flags = 0;
    return r;
}

int func_002ED230(W11File *fp)
{
    u8 *p;
    int n, t;

    if (fp == 0) {
        return func_002EE058(D_005681A4, func_002ED230);
    }
    V7_CHECK_INIT(fp);
    t = fp->_flags;
    if ((t & 8) == 0 || (p = fp->_bf_base) == 0) {
        return 0;
    }
    n = fp->_p - p;
    fp->_p = p;
    fp->_w = t & (1 | 2) ? 0 : fp->_bf_size;
    while (n > 0) {
        t = ((int (*)(void *, char *, int))fp->_write)(fp->_cookie, (char *)p, n);
        if (t <= 0) {
            fp->_flags |= 0x40;
            return -1;
        }
        p += t;
        n -= t;
    }
    return 0;
}

void func_002ED338(W11File *ptr, int flags, int file, W11Reent *data)
{
    ptr->_p = 0;
    ptr->_r = 0;
    ptr->_w = 0;
    ptr->_flags = flags;
    ptr->_file = file;
    ptr->_bf_base = 0;
    ptr->_lbfsize = 0;
    ptr->_cookie = ptr;
    ptr->_read = func_002F0108;
    ptr->_write = func_002F0170;
    ptr->_seek = func_002F01F0;
    ptr->_close = func_002F0258;
    ptr->_cookie54 = data;
}

struct W11Glue *func_002ED390(W11Reent *d, int n)
{
    struct W11Glue *g;
    W11File *p;

    g = func_002EE630(d, sizeof(*g) + n * sizeof(W11File));
    if (g == 0) {
        return 0;
    }
    p = (W11File *)(g + 1);
    g->_next = 0;
    g->_niobs = n;
    g->_iobs = p;
    func_002EF0D0(p, 0, n * sizeof(W11File));
    return g;
}

W11File *func_002ED400(W11Reent *d)
{
    W11File *fp;
    int n;
    struct W11Glue *g;

    if (!d->__sdidinit) {
        func_002ED500(d);
    }
    for (g = &d->__sglue;; g = g->_next) {
        for (fp = g->_iobs, n = g->_niobs; --n >= 0; fp++) {
            if (fp->_flags == 0) {
                goto found;
            }
        }
        if (g->_next == 0 && (g->_next = func_002ED390(d, 4)) == 0) {
            break;
        }
    }
    d->_errno = 12;
    return 0;
found:
    fp->_flags = 1;
    fp->_p = 0;
    fp->_w = 0;
    fp->_r = 0;
    fp->_bf_base = 0;
    fp->_bf_size = 0;
    fp->_lbfsize = 0;
    fp->_file = -1;
    fp->_ub_base = 0;
    fp->_ub_size = 0;
    fp->_lb_base = 0;
    fp->_lb_size = 0;
    fp->_cookie54 = d;
    return fp;
}

void func_002ED4E0(W11Reent *r)
{
    func_002EE058(r, func_002ED230);
}

void func_002ED4F0(void)
{
    func_002ED4E0(D_005681A4);
}

void func_002ED500(W11Reent *s)
{
    s->__cleanup = func_002ED4E0;
    s->__sdidinit = 1;
    func_002ED338(s->__sf + 0, 4, 0, s);
    func_002ED338(s->__sf + 1, 9, 1, s);
    func_002ED338(s->__sf + 2, 10, 2, s);
    s->__sglue._next = 0;
    s->__sglue._niobs = 3;
    s->__sglue._iobs = &s->__sf[0];
}

W11File *func_002ED590(W11Reent *ptr, const char *file, const char *mode)
{
    W11File *fp;
    int f;
    int flags, oflags;

    if ((flags = func_002F5CC8(ptr, (char *)mode, &oflags)) == 0) {
        return 0;
    }
    if ((fp = func_002ED400(ptr)) == 0) {
        return 0;
    }
    if ((f = func_002EF1A0(fp->_cookie54, (int)file, oflags, 0666)) < 0) { /* DEBT(TYPE): callee takes ints */
        fp->_flags = 0;
        return 0;
    }
    fp->_file = f;
    fp->_flags = flags;
    fp->_cookie = fp;
    fp->_read = func_002F0108;
    fp->_write = func_002F0170;
    fp->_seek = func_002F01F0;
    fp->_close = func_002F0258;
    if (fp->_flags & 0x100) {
        func_002EDB68(fp, 0, 2);
    }
    return fp;
}

int func_002ED670(char *file, char *mode)
{
    return (int)func_002ED590(D_005681A4, file, mode); /* DEBT(TYPE): t2.h declares fopen as returning int */
}

int func_002ED6A0(W11File *fp, const char *fmt, ...)
{
    void *ap;

    R7_VA_START(ap, fmt, 6);
    return func_002F2250(fp, fmt, ap);
}

/* _free_r (dlmalloc fREe) */
void func_002ED6D8(W11Reent *ptr, void *mem)
{
    V7MChunk *p;
    u32 hd;
    u32 sz;
    int idx;
    V7MChunk *next;
    u32 nextsz;
    u32 prevsz;
    V7MChunk *bck;
    V7MChunk *fwd;
    int islr;

    if (mem == 0) {
        return;
    }
    func_002EF190(ptr);
    p = (V7MChunk *)((char *)mem - 2 * sizeof(u32));
    hd = p->size;
    sz = hd & ~1;
    next = (V7MChunk *)((char *)p + sz);
    nextsz = next->size & ~3;
    if (next == V7_TOP) {
        sz += nextsz;
        if (!(hd & 1)) {
            prevsz = p->prev_size;
            p = (V7MChunk *)((char *)p - prevsz);
            sz += prevsz;
            V7_UNLINK(p, bck, fwd);
        }
        p->size = sz | 1;
        V7_TOP = p;
        if ((unsigned long)sz >= (unsigned long)D_005685B0) {
            func_002ED9F8(ptr, D_005685B8);
        }
        func_002EF198(ptr);
        return;
    }
    next->size = nextsz;
    islr = 0;
    if (!(hd & 1)) {
        prevsz = p->prev_size;
        p = (V7MChunk *)((char *)p - prevsz);
        sz += prevsz;
        if (p->fd == V7_LAST_REMAINDER) {
            islr = 1;
        } else {
            V7_UNLINK(p, bck, fwd);
        }
    }
    if (!(((V7MChunk *)((char *)next + nextsz))->size & 1)) {
        sz += nextsz;
        if (!islr && next->fd == V7_LAST_REMAINDER) {
            islr = 1;
            V7_LAST_REMAINDER->fd = V7_LAST_REMAINDER->bk = p;
            p->fd = p->bk = V7_LAST_REMAINDER;
        } else {
            V7_UNLINK(next, bck, fwd);
        }
    }
    p->size = sz | 1;
    ((V7MChunk *)((char *)p + sz))->prev_size = sz;
    if (!islr) {
        if (sz < 512) {
            idx = (unsigned long)sz >> 3;
            V7_MARK_BINBLOCK(idx);
            bck = V7_BIN_AT(idx);
            fwd = bck->fd;
            p->bk = bck;
            p->fd = fwd;
            fwd->bk = bck->fd = p;
        } else {
            idx = ((((unsigned long)sz) >> 9) == 0) ? (((unsigned long)sz) >> 3)
                : ((((unsigned long)sz) >> 9) <= 4) ? 56 + (((unsigned long)sz) >> 6)
                : ((((unsigned long)sz) >> 9) <= 20) ? 91 + (((unsigned long)sz) >> 9)
                : ((((unsigned long)sz) >> 9) <= 84) ? 110 + (((unsigned long)sz) >> 12)
                : ((((unsigned long)sz) >> 9) <= 340) ? 119 + (((unsigned long)sz) >> 15)
                : ((((unsigned long)sz) >> 9) <= 1364) ? 124 + (((unsigned long)sz) >> 18)
                : 126;
            bck = V7_BIN_AT(idx);
            fwd = bck->fd;
            if (fwd == bck) {
                V7_MARK_BINBLOCK(idx);
            } else {
                while (fwd != bck && sz < (fwd->size & ~3)) {
                    fwd = fwd->fd;
                }
                bck = fwd->bk;
            }
            p->bk = bck;
            p->fd = fwd;
            fwd->bk = bck->fd = p;
        }
    }
    func_002EF198(ptr);
}

INCLUDE_ASM("build/ee_asm/sdk/newlib/libc/libc_2ED128", func_002ED9F8);

/* fseek; the gotos are those of the BSD source */
int func_002EDB68(W11File *fp, long offset, int whence)
{
    W11Reent *data;
    V7SeekFn seekfn;
    long target, curoff;
    u32 n;
    V7Stat st;
    int havepos;

    V7_CHECK_INIT(fp);
    data = fp->_cookie54;
    if (fp->_flags & 0x100 && fp->_flags & 8) {
        func_002ED230(fp);
    }
    if ((seekfn = (V7SeekFn)fp->_seek) == 0) {
        data->_errno = 29;
        return -1;
    }
    switch (whence) {
    case 1:
        func_002ED230(fp);
        if (fp->_flags & 0x1000) {
            curoff = fp->_offset;
        } else {
            curoff = seekfn(fp->_cookie, 0, 1);
            if (curoff == -1L) {
                return -1;
            }
        }
        if (fp->_flags & 4) {
            curoff -= fp->_r;
            if (fp->_ub_base != 0) {
                curoff -= fp->_ur;
            }
        } else if (fp->_flags & 8 && fp->_p != 0) {
            curoff += fp->_p - fp->_bf_base;
        }
        offset += curoff;
        whence = 0;
        havepos = 1;
        break;
    case 0:
    case 2:
        havepos = 0;
        break;
    default:
        data->_errno = 22;
        return -1;
    }
    if (fp->_bf_base == 0) {
        func_002EE288(fp);
    }
    if (fp->_flags & (8 | 0x10 | 2 | 0x800)) {
        goto dumb;
    }
    if ((fp->_flags & 0x400) == 0) {
        if (seekfn != (V7SeekFn)func_002F01F0 || fp->_file < 0 || func_002EDFF8(data, fp->_file, (int *)&st) || (st.st_mode & 0xF000) != 0x8000) {
            fp->_flags |= 0x800;
            goto dumb;
        }
        fp->_blksize = 1024;
        fp->_flags |= 0x400;
    }
    if (whence == 0) {
        target = offset;
    } else {
        if (func_002EDFF8(data, fp->_file, (int *)&st)) {
            goto dumb;
        }
        target = st.st_size + offset;
    }
    if (!havepos) {
        if (fp->_flags & 0x1000) {
            curoff = fp->_offset;
        } else {
            curoff = seekfn(fp->_cookie, 0L, 1);
            if (curoff == -1) {
                goto dumb;
            }
        }
        curoff -= fp->_r;
        if (fp->_ub_base != 0) {
            curoff -= fp->_ur;
        }
    }
    if (fp->_ub_base != 0) {
        curoff += fp->_r;
        n = fp->_up - fp->_bf_base;
        curoff -= n;
        n += fp->_ur;
    } else {
        n = fp->_p - fp->_bf_base;
        curoff -= n;
        n += fp->_r;
    }
    if ((fp->_flags & 0x2000) == 0 && target >= curoff && target < curoff + n) {
        int o = target - curoff;

        fp->_p = fp->_bf_base + o;
        fp->_r = n - o;
        if (fp->_ub_base != 0) {
            if (fp->_ub_base != fp->_ubuf) {
                func_002ED6D8(fp->_cookie54, fp->_ub_base);
            }
            fp->_ub_base = 0;
        }
        fp->_flags &= ~0x20;
        return 0;
    }
    curoff = target & ~(fp->_blksize - 1);
    if (seekfn(fp->_cookie, curoff, 0) == -1) {
        goto dumb;
    }
    fp->_r = 0;
    if (fp->_ub_base != 0) {
        if (fp->_ub_base != fp->_ubuf) {
            func_002ED6D8(fp->_cookie54, fp->_ub_base);
        }
        fp->_ub_base = 0;
    }
    fp->_flags &= ~0x20;
    n = target - curoff;
    if (n) {
        if (func_002EFDC8(fp) || fp->_r < n) {
            goto dumb;
        }
        fp->_p += n;
        fp->_r -= n;
    }
    return 0;

dumb:
    if (func_002ED230(fp) || seekfn(fp->_cookie, offset, whence) == -1) {
        return -1;
    }
    if (fp->_ub_base != 0) {
        if (fp->_ub_base != fp->_ubuf) {
            func_002ED6D8(fp->_cookie54, fp->_ub_base);
        }
        fp->_ub_base = 0;
    }
    fp->_p = fp->_bf_base;
    fp->_r = 0;
    fp->_flags &= ~0x20;
    return 0;
}

/* Module: newlib libc (reent, stdio, strtod/strtol, rand) */

int func_002EDFF8(W11Reent *ptr, int a, int *b)
{
    int r;

    D_0057CBC0 = 0;
    r = func_002F8AF0(a, b);
    if (r == -1) {
        if (D_0057CBC0 != 0) {
            ptr->_errno = D_0057CBC0;
        }
    }
    return r;
}

int func_002EE058(W11Reent *ptr, int (*function)(W11File *))
{
    W11File *fp;
    int n;
    int ret = 0;
    struct W11Glue *g;

    for (g = &ptr->__sglue; g != 0; g = g->_next) {
        for (fp = g->_iobs, n = g->_niobs; --n >= 0; fp++) {
            if (fp->_flags != 0) {
                ret |= (*function)(fp);
            }
        }
    }
    return ret;
}

char *func_002EE0F0(const char *name, int *offset)
{
    return func_002EE148(D_005681A4, name, offset);
}

char *func_002EE120(const char *name)
{
    int offset;

    return func_002EE148(D_005681A4, name, &offset);
}

char *func_002EE148(W11Reent *reent_ptr, const char *name, int *offset)
{
    int len;
    char **p;
    const char *c;

    func_002F5CB8(reent_ptr);
    if (!D_00568604) {
        return 0;
    }
    c = name;
    len = 0;
    while (*c && *c != '=') {
        c++;
        len++;
    }
    for (p = D_00568604; *p; ++p) {
        if (!func_002F0A58(*p, name, len)) {
            if (*(c = *p + len) == '=') {
                *offset = p - D_00568604;
                func_002F5CC0(reent_ptr);
                return (char *)(++c);
            }
        }
    }
    func_002F5CC0(reent_ptr);
    return 0;
}

char *func_002EE268(W11Reent *r, const char *name)
{
    int offset;

    return func_002EE148(r, name, &offset);
}

void func_002EE288(W11File *fp)
{
    u32 size, couldbetty;
    void *p;
    V7Stat st;

    if (fp->_flags & 2) {
        fp->_bf_base = fp->_p = fp->_nbuf;
        fp->_bf_size = 1;
        return;
    }
    if (fp->_file < 0 || func_002EDFF8(fp->_cookie54, fp->_file, (int *)&st) < 0) {
        couldbetty = 0;
        size = 0x400;
        fp->_flags |= 0x800;
    } else {
        couldbetty = (st.st_mode & 0xF000) == 0x2000;
        size = 0x400;
        if ((st.st_mode & 0xF000) == 0x8000 && fp->_seek == func_002F01F0) {
            fp->_flags |= 0x400;
            fp->_blksize = 1024;
        } else {
            fp->_flags |= 0x800;
        }
    }
    if ((p = func_002EE630(fp->_cookie54, size)) == 0) {
        fp->_flags |= 2;
        fp->_bf_base = fp->_p = fp->_nbuf;
        fp->_bf_size = 1;
    } else {
        fp->_cookie54->__cleanup = func_002ED4E0;
        fp->_flags |= 0x80;
        fp->_bf_base = fp->_p = p;
        fp->_bf_size = size;
        if (couldbetty && func_002F8AE8(fp->_file)) {
            fp->_flags |= 1;
        }
    }
}

INCLUDE_ASM("build/ee_asm/sdk/newlib/libc/libc_2ED128", func_002EE3D8);

INCLUDE_ASM("build/ee_asm/sdk/newlib/libc/libc_2ED128", func_002EE630);

INCLUDE_ASM("build/ee_asm/sdk/newlib/libc/libc_2ED128", func_002EEDA8);

INCLUDE_ASM("build/ee_asm/sdk/newlib/libc/libc_2ED128", func_002EEE88);
