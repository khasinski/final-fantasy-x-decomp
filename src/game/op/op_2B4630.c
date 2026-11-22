/* tu_329 0x2b4630-0x2b4ff8: low; ~op (config/tu_map.tsv) */
/* DEBT(NAME): module and names guessed: sound/debug dual-output dispatch wrappers (see w10.h). */
#define op_oef2_a_get _hdr_op_oef2_a_get
#include "common.h"
#include "ffx/r7.h"
#include "ffx/q7.h"
#include "ffx/w10.h"
#undef op_oef2_a_get

extern char D_00575C50[];
void func_00120108(char *fmt, ...);
void func_002EA328(s32 status) __attribute__((noreturn));

typedef struct {
    u8 type;
    u8 pad[7];
    union {
        s32 i;
        u32 u;
        u16 h[2];
    } p8;
    union {
        s32 i;
        u32 u;
        u16 h[2];
    } pC;
} Oef2Ent6;

/* DEBT(CAST): raw OEF2 header/table offsets */
void op_oef2_set(void *a, void *b)
{
    u8 *dst = (u8 *)a;
    u8 *src = (u8 *)b;
    s32 i;
    u32 *sp;
    u8 *dp;

    if (((u32)src & 0xF) != 0) {
        func_00120108(D_00575C50);
        func_002EA328(1);
    }
    if (*(u16 *)(src + 0x40) != 0) {
        return;
    }
    *(u16 *)(src + 0x40) = 1;

    if (*(u16 *)(src + 0x42) != 0) {
        sp = (u32 *)(*(u32 *)(src + 4) + (u32)src);
        dp = (u8 *)(*(u32 *)(dst + 4) + (u32)dst);
        for (i = 0; i < *(u16 *)(src + 0x42); i++, sp++, dp += 4) {
            if (*sp != 0) {
                *(u32 *)dp = *sp + (u32)src;
            }
        }
    }
    if (*(u16 *)(src + 0x44) != 0) {
        sp = (u32 *)(*(u32 *)(src + 8) + (u32)src);
        dp = (u8 *)(*(u32 *)(dst + 8) + (u32)dst);
        for (i = 0; i < *(u16 *)(src + 0x44); i++, dp += 0x20) {
            if (*sp != 0) {
                *(u32 *)(dp + 0x14) = *sp + (u32)src;
            }
            sp++;
        }
    }
    if (*(u16 *)(src + 0x46) != 0) {
        sp = (u32 *)(*(u32 *)(src + 0xC) + (u32)src);
        dp = (u8 *)(*(u32 *)(dst + 0xC) + (u32)dst);
        for (i = 0; i < *(u16 *)(src + 0x46); i++, dp += 0x10) {
            if (*sp != 0) {
                *(u32 *)(dp + 4) = *sp + (u32)src;
            }
            sp++;
        }
    }
    if (*(u16 *)(src + 0x48) != 0) {
        sp = (u32 *)(*(u32 *)(src + 0x10) + (u32)src);
        dp = (u8 *)(*(u32 *)(dst + 0x10) + (u32)dst);
        for (i = 0; i < *(u16 *)(src + 0x48); i++, dp += 4) {
            if (*sp != 0) {
                *(u32 *)dp = *sp + (u32)src;
            }
            sp++;
        }
    }
    if (*(u16 *)(src + 0x4A) != 0) {
        sp = (u32 *)(*(u32 *)(src + 0x14) + (u32)src);
        dp = (u8 *)(*(u32 *)(dst + 0x14) + (u32)dst);
        for (i = 0; i < *(u16 *)(src + 0x4A); i++, dp += 4) {
            if (*sp != 0) {
                *(u32 *)dp = *sp + (u32)src;
            }
            sp++;
        }
    }
    if (*(u16 *)(src + 0x4C) != 0) {
        Oef2Ent6 *base;
        Oef2Ent6 *ep;
        sp = (u32 *)(*(u32 *)(src + 0x18) + (u32)src);
        ep = (Oef2Ent6 *)(*(u32 *)(dst + 0x18) + (u32)dst);
        for (i = 0; i < *(u16 *)(src + 0x4C); i++, sp++, ep++) {
            if (*sp != 0) {
                s32 w8 = ep->p8.i;
                if (w8 <= 0xFFFFF) {
                    if (ep->type == 1) {
                        u32 v = *sp + (u32)src;
                        s32 wC = ep->pC.i;
                        ep->p8.u = v;
                        if (wC > 0) {
                            ep->pC.u = v + w8;
                        }
                    } else {
                        ep->p8.u = *sp + (u32)src;
                    }
                }
            }
        }
        base = (Oef2Ent6 *)(*(u32 *)(dst + 0x18) + (u32)dst);
        ep = base;
        for (i = 0; i < *(u16 *)(src + 0x4C); i++, ep++) {
            if (ep->type == 1) {
                s32 wC = ep->pC.i;
                if (wC < 0 && wC != (s32)0x80000000) {
                    ep->pC.i = *(s32 *)((u8 *)base + ((wC & 0xFF) << 4) + 0xC);
                }
            }
        }
    }
    if (*(u16 *)(src + 0x50) != 0) {
        sp = (u32 *)(*(u32 *)(src + 0x20) + (u32)src);
        dp = (u8 *)(*(u32 *)(dst + 0x20) + (u32)dst);
        for (i = 0; i < *(u16 *)(src + 0x50); i++, sp++, dp += 4) {
            if (*sp != 0) {
                *(u32 *)dp = *sp + (u32)src;
            }
        }
    }
    if (*(u16 *)(src + 0x52) != 0) {
        sp = (u32 *)(*(u32 *)(src + 0x24) + (u32)src);
        dp = (u8 *)(*(u32 *)(dst + 0x24) + (u32)dst);
        for (i = 0; i < *(u16 *)(src + 0x52); i++, dp += 4) {
            if (*sp != 0) {
                *(u32 *)dp = *sp + (u32)src;
            }
            sp++;
        }
    }
}

void op_oef2_set2(char *a) {
    op_oef2_set(a, a + *(s32 *)(a + 0x3C)); /* DEBT(CAST): header type unknown, offset word at +0x3C */
}

void op_oef2_set2_16(char *a) {
    a += 0x10;
    op_oef2_set(a, a + *(s32 *)(a + 0x3C)); /* DEBT(CAST): see op_oef2_set2 */
}

typedef struct {
    u32 off[16];
    s16 cnt[16];
} Oef2Hdr;

/* DEBT(CAST): raw OEF2 table offsets */
/* DEBT(FAKE): register pins for idx ($v1), off/p ($a0), default off ($v0) */
void *op_oef2_a_get(Oef2Hdr *base, int b, int c)
{
    register u32 idx __asm__("$3") = c & 0xFF;

    switch (b) {
    case 2: {
        register u32 off __asm__("$4") = idx << 5;
        u8 *p = (u8 *)(base->off[2] + (u32)base) + off;
        if (*(s32 *)(p + 0x10) != 0) {
            return p;
        }
        return 0;
    }
    case 3: {
        register u32 off __asm__("$4") = idx << 4;
        u8 *p = (u8 *)(base->off[3] + (u32)base) + off;
        if (*(u16 *)(p + 2) != 0) {
            return p;
        }
        return 0;
    }
    case 6: {
        register u32 off __asm__("$5") = idx << 4;
        register u8 *p __asm__("$4");
        register s32 lim __asm__("$2") = 0xFFFFF;
        __asm__("" : "+r"(off));
        p = (u8 *)(base->off[6] + (u32)base) + off;
        __asm__("" : "+r"(p), "+r"(lim));
        if (*(s32 *)(p + 8) <= lim) {
            p = 0;
        }
        return p;
    }
    default: {
        register u32 boff __asm__("$2") = b << 2;
        register u32 off __asm__("$2");
        __asm__("" : "+r"(boff));
        off = *(u32 *)((u8 *)base + boff);
        __asm__("" : "+r"(off));
        return ((void **)(off + (u32)base))[idx];
    }
    }
}

int func_002B4A58(u8 *base, int arg1)
{
    int i;
    u8 *p;

    switch (arg1) {
    case 2:
        p = (u8 *)*(int *)(base + 8) + (int)base;
        for (i = 0; i < *(u16 *)(base + 0x44); i++, p += 0x20) {
            if (*(int *)(p + 0x10) != 0) {
                return *(int *)(p + 0x14);
            }
        }
        break;
    case 3:
        p = (u8 *)*(int *)(base + 0xC) + (int)base;
        for (i = 0; i < *(u16 *)(base + 0x46); i++, p += 0x10) {
            if (*(u16 *)(p + 2) != 0) {
                return *(int *)(p + 4);
            }
        }
        break;
    case 6:
        break;
    }
    return 0;
}

int op_oef2_obj_a_get(int a, int b, int c)
{
    int *t = op_oef2_a_get(a, 1, b);

    return (int)t + t[c] + c * 4;
}

/* DEBT(CAST): raw OEF2 table offsets */
/* DEBT(FAKE): register pins for base ($a0), kind ($t0), addr ($a1), ok ($v1) */
s32 op_oef2_a_set(Oef2Hdr *base_, s32 kind_, s32 idx, void *val)
{
    register Oef2Hdr *base __asm__("$4") = base_;
    register s32 kind __asm__("$8") = kind_;
    s32 n;
    s32 ret;

    switch (kind) {
    case 2:
        ret = 0;
        goto ret0;
    case 3:
        ret = 0;
        goto ret0;
    case 6:
        ret = 0;
        goto ret0;
    default: {
        register u32 off2 __asm__("$2") = kind << 1;
        register u8 *p __asm__("$5");
        register s32 n2 __asm__("$2");
        __asm__("" : "+r"(off2));
        p = (u8 *)base + off2;
        __asm__("" : "+r"(p));
        n2 = *(s16 *)(p + 0x40);
        __asm__("" : "+r"(n2));
        if (n2 != 0) {
            register s32 ok __asm__("$3") = idx < ((n2 + 3) & 0xFC);
            if (ok) {
                goto set;
            }
        }
        ret = 0;
        break;
    }
    }
ret0:
    return ret;
set: {
    register u32 koff __asm__("$2") = kind << 2;
    register u32 ioff __asm__("$3") = idx << 2;
    register u8 *ap __asm__("$5") = (u8 *)base + koff;
    register u32 p __asm__("$5");
    register s32 one __asm__("$2");
    __asm__("" : "+r"(ap));
    p = *(u32 *)ap;
    __asm__ volatile("" : "+r"(p));
    one = 1;
    __asm__ volatile("" : "+r"(one));
    p += (u32)base;
    p += ioff;
    __asm__("" : "+r"(p));
    *(void **)p = val;
    return one;
}
}

void func_002B4BA8(u8 *base, u16 a1, u16 a2, u16 a3, u16 a4)
{
    int i;
    int j;
    u8 *p;
    void *q;

    if (base == 0) {
        return;
    }
    /* DEBT(CAST): raw offset access into OEF2 header */
    for (i = 0; i < *(u16 *)(base + 0x50); i++) {
        p = op_oef2_a_get((int)base, 8, i);
        if (p != 0) {
            for (j = 0; j < *(u16 *)(p + 8); j++) {
                q = func_002B7388((void *)p, j);
                if (q != 0) {
                    func_002B6EC8(q, a1, a2, a3, a4);
                }
            }
            for (j = 0; j < *(u16 *)(p + 0xA); j++) {
                q = (void *)func_002CEF98(p, j);
                if (q != 0) {
                    func_002CEEE0(q, a1, a2, a3, a4);
                }
            }
        }
    }
    for (i = 0; i < *(u16 *)(base + 0x48); i++) {
        u8 *r = op_oef2_a_get((int)base, 4, i);
        if (r != 0) {
            if (*(s8 *)r == 0x46) {
                func_002CEEE0(r, a1, a2, a3, a4);
            } else {
                func_002B6EC8(r, a1, a2, a3, a4);
            }
        }
    }
}

/* DEBT(CAST): raw OEF2 relocation offsets */
void func_002B4D78(u8 *old_base, u8 *new_base)
{
    u8 *hdr = new_base + *(s32 *)(new_base + 0x3C);
    s32 diff = new_base - old_base;
    s32 i;
    u32 *sp;
    u8 *dp;

    if (*(u16 *)(hdr + 0x40) == 0) {
        return;
    }
    if (*(u16 *)(hdr + 0x42) != 0) {
        sp = (u32 *)(*(u32 *)(new_base + 4) + (u32)new_base);
        for (i = 0; i < *(u16 *)(hdr + 0x42); i++, sp++) {
            if (*sp != 0) {
                *sp += diff;
            }
        }
    }
    if (*(u16 *)(hdr + 0x44) != 0) {
        sp = (u32 *)(*(u32 *)(new_base + 8) + (u32)new_base);
        dp = (u8 *)sp;
        for (i = 0; i < *(u16 *)(hdr + 0x44); i++, dp += 0x20) {
            if (*sp++ != 0) {
                *(u32 *)(dp + 0x14) += diff;
            }
        }
    }
    if (*(u16 *)(hdr + 0x46) != 0) {
        sp = (u32 *)(*(u32 *)(new_base + 0xC) + (u32)new_base);
        dp = (u8 *)sp;
        for (i = 0; i < *(u16 *)(hdr + 0x46); i++, dp += 0x10) {
            if (*sp++ != 0) {
                *(u32 *)(dp + 4) += diff;
            }
        }
    }
    if (*(u16 *)(hdr + 0x48) != 0) {
        sp = (u32 *)(*(u32 *)(new_base + 0x10) + (u32)new_base);
        for (i = 0; i < *(u16 *)(hdr + 0x48); i++, sp++) {
            if (*sp != 0) {
                *sp += diff;
            }
        }
    }
    if (*(u16 *)(hdr + 0x4A) != 0) {
        sp = (u32 *)(*(u32 *)(new_base + 0x14) + (u32)new_base);
        for (i = 0; i < *(u16 *)(hdr + 0x4A); i++, sp++) {
            if (*sp != 0) {
                *sp += diff;
            }
        }
    }
    if (*(u16 *)(hdr + 0x4C) != 0) {
        Oef2Ent6 *ep;
        sp = (u32 *)(*(u32 *)(new_base + 0x18) + (u32)new_base);
        ep = (Oef2Ent6 *)sp;
        for (i = 0; i < *(u16 *)(hdr + 0x4C); i++, sp++, ep++) {
            if (*sp != 0) {
                if (ep->type == 1) {
                    s32 wC = ep->pC.i;
                    ep->p8.u += diff;
                    if (wC > 0) {
                        ep->pC.i = wC + diff;
                    }
                } else {
                    ep->p8.u += diff;
                }
            }
        }
    }
    if (*(u16 *)(hdr + 0x50) != 0) {
        sp = (u32 *)(*(u32 *)(new_base + 0x20) + (u32)new_base);
        for (i = 0; i < *(u16 *)(hdr + 0x50); i++, sp++) {
            if (*sp != 0) {
                *sp += diff;
            }
        }
    }
    if (*(u16 *)(hdr + 0x52) != 0) {
        sp = (u32 *)(*(u32 *)(new_base + 0x24) + (u32)new_base);
        for (i = 0; i < *(u16 *)(hdr + 0x52); i++, sp++) {
            if (*sp != 0) {
                *sp += diff;
            }
        }
    }
}
