/* tu_083 0x14ce18-0x14d610: low; ~Tk (config/tu_map.tsv) */
#include "common.h"
#include "ffx/g0.h"
#include "ffx/q2.h"
#include "ffx/r1.h"
#include "ffx/s1.h"
#include "ffx/u0.h"
#include "ffx/u1.h"

static inline int ClampU8(int i)
{
    if (i >= 0) {
        if (i >= 0x100) {
            return 0xFF;
        }
        return i;
    }
    return 0;
}

Ent24 *func_0014CE18(int i)
{
    return ENT24(i);
}

void func_0014CE48(Rec14CE48 *r)
{
    r->x0 = 0;
    r->x4 = 0;
    r->x6 = 0;
    r->x8 = 0;
    r->x9 = 0;
    r->xA = 0;
}

void func_0014CE68(Ent24 *e)
{
    int i;

    e->x22 = 0;
    e->x20 = 0;
    for (i = 0; i < 2; i++) {
        func_0014CE48(&e->rec[i]);
    }
}

int func_0014CEB0(int i)
{
    return func_0014CE18(i)->x22;
}

void func_0014CED0(int bit, int on)
{
    if (bit < 0) {
        if (on) {
            D_0058F91C = 0xFF;
        } else {
            D_0058F91C = 0;
        }
    } else if (on) {
        D_0058F91C |= 1 << bit;
    } else {
        D_0058F91C &= ~(1 << bit);
    }
}

void func_0014CF38(void)
{
    int i;

    for (i = 0; i < 8; i++) {
        func_0014CE68(func_0014CE18(i));
    }
    func_0014CED0(-1, 1);
    func_0014D4E8(0);
}

Ent24 *func_0014CF88(int i)
{
    Ent24 *e = func_0014CE18(i);

    e->x22 = 0;
    e->x20++;
    return e;
}

u8 *func_0014CFB8(u32 a, int b, u8 *c)
{
    int off;
    u8 *p;
    u16 *q;

    if (a >= 0x40 || c == 0) {
        return 0;
    }
    off = ((s32 *)c)[a];
    if (off == 0) {
        return 0;
    }
    p = c + off;
    if (*(u16 *)(p + (b << 1)) == 0) {
        return 0;
    }
    if (b > 0) {
        q = (u16 *)p;
        do {
            p += *q;
            b--;
            q++;
        } while (b != 0);
    }
    return p + 4;
}

void func_0014D028(Rec14CE48 *r)
{
    r->x0 = 0;
    r->x4 = 0;
    r->x8 = 0;
    r->x9 = 0;
    r->x6 = -2;
}

void func_0014D048(Rec14CE48 *r, u8 *p)
{
    r->x4 = 0;
    r->x6 = (p[1] + 1) << 1;
    r->x8 = p[0];
    r->x9 = p[2];
    p += 2;
    r->x0 = p;
}

void func_0014D078(Rec14CE48 *r, u8 *p)
{
    if (p) {
        func_0014D048(r, p);
    } else {
        r->x0 = 0;
        r->x4 = 0;
        r->x8 = 0;
        r->x9 = 0;
        r->x6 = 0x200;
    }
}

void func_0014D0A0(Rec14CE48 *r, u8 *p, u8 *q)
{
    func_0014D078(r, p);
    func_0014D078(r + 1, q);
}

void func_0014D0D8(Ent24 *e, int on, u8 *b, u8 *c)
{
    if (on == 1) {
        func_0014D0A0(e->rec, b, c);
    } else {
        on = 0;
    }
    e->x22 = on;
}

void func_0014D130(Ent24 *e)
{
    Rec14CE48 *r0 = &e->rec[0];
    Rec14CE48 *r1 = &e->rec[1];

    switch (e->x22) {
    case 1:
        if (r0->x6 == 0x200 && r1->x6 == 0x200) {
            e->x22 = 0;
        }
        break;
    case 2:
        if (r0->x6 == -2 && r1->x6 == -2) {
            e->x22 = 0;
        }
        break;
    }
}

INCLUDE_ASM("build/ee_asm/game/atel/tk_14CE18", func_0014D180);

int func_0014D260(Ent24 *e, int idx)
{
    Rec14CE48 *r = &e->rec[idx];
    int v = 0;
    int mode = e->x22;
    int x6 = r->x6;

    if (mode >= 3 || mode == 0) {
        r->xA = 0;
        return 0;
    }
    if (x6 >= 0) {
        switch (mode) {
        case 1:
            if (x6 >= 0x200) {
                break;
            }
        case 2:
            v = func_0014D180(e, r);
            break;
        }
        r->xA = v;
        return v;
    } else {
        v = r->x8;
        r->xA = v;
        return v;
    }
}

void func_0014D2F8(int a, int idx, int v0, int v1, int dur)
{
    Ent24 *e = func_0014CF88(a);
    Rec14CE48 *r;
    int c0;
    int c1;

    idx = (idx < 0) ? 0 : ((idx >= 2) ? 1 : idx);
    r = &e->rec[idx];
    r->x0 = 0;
    e->x22 = 2;
    func_0014D028(r);
    if (v0 < 0) {
        v0 = r->xA;
    }
    if (v1 < 0) {
        v1 = 0;
    }
    c0 = (v0 < 0) ? 0 : ((v0 >= 0x80) ? 0x7F : v0);
    c1 = (v1 < 0) ? 0 : ((v1 >= 0x80) ? 0x7F : v1);
    r->x4 = 0;
    if (dur < 0) {
        dur = -1;
    }
    r->x6 = dur;
    if (r->x6 >= 0) {
        r->x9 = c1;
    } else {
        r->x9 = c0;
    }
    r->x8 = c0;
}

void func_0014D3F0(int a, int b, int c)
{
    int v1;
    int v2;

    v1 = (int)func_0014CF88(a); /* DEBT(CAST): func_0014D0D8 takes the record as an int */
    v2 = func_0014CFB8(b, 0, c);
    func_0014D0D8(v1, 1, func_0014CFB8(b, 1, c), v2);
}

void func_0014D468(int v)
{
    Ent24 *e = func_0014CE18(v);
    int i;

    e->x22 = 0;
    for (i = 0; i < 2; i++) {
        func_0014CE48(&e->rec[i]);
    }
}

void func_0014D4B0(void)
{
    int i;

    for (i = 0; i < 8; i++) {
        func_0014D468(i);
    }
}

void func_0014D4E8(u8 v)
{
    D_0058F91A = v;
}

void func_0014D4F8(void)
{
    u32 m0 = 0;
    u32 m1 = 0;
    int i;

    if (D_0058F91A == 0) {
        for (i = 0; i < 8; i++) {
            u32 v0 = 0;
            u32 v1;

            if ((D_0058F91C >> i) & 1) {
                Ent24 *e = func_0014CE18(i);

                func_0014D130(e);
                v0 = func_0014D260(e, 0);
                v1 = func_0014D260(e, 1);
            } else {
                v1 = 0;
            }
            if (m0 < v0) {
                m0 = v0;
            }
            if (m1 < v1) {
                m1 = v1;
            }
        }
        D_0058F918 = m0;
        D_0058F919 = m1;
    }
}

void func_0014D5D8(int *a, int *b)
{
    if (D_0058F91A) {
        *a = 0;
        *b = 0;
    } else {
        *a = D_0058F918;
        *b = D_0058F919;
    }
}
