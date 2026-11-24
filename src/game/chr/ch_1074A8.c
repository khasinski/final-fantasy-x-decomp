/* tu_008 0x1074a8-0x10ad70: low; ~Ch (config/tu_map.tsv) */
#define Ch_ElemCalcQuaternion _hdr_Ch_ElemCalcQuaternion
#define tex_anim_no_set _hdr_tex_anim_no_set
#define Ch_ElemGetAttr _hdr_Ch_ElemGetAttr
#include "common.h"
#include "ffx/q0.h"
#include "ffx/r0.h"
#include "ffx/u0.h"
#include "ffx/g0.h"
#include "ffx/v0.h"
#undef Ch_ElemCalcQuaternion
#undef tex_anim_no_set
#undef Ch_ElemGetAttr

s32 func_001074A8(s32 i)
{
    return D_0057E9B0[i];
}

void func_001074C0(s32 i, s32 v)
{
    D_0057E9B0[i] = v;
}

float func_001074D8(float a, float b, float step)
{
    register u8 *gp __asm__("$28");
    float diff;
    register float c __asm__("$f2");
    float res;

    __asm__("lwc1 %0, -0x7F64($gp)" : "=f"(c));
    diff = a - b;
    if (diff > c) {
        do {
            diff -= *(float *)(gp - 0x7F60);
        } while (diff > c);
    }
    __asm__ volatile("" : "+r"(gp));
    c = *(float *)(gp - 0x7F5C);
    if (diff < c) {
        do {
            diff += *(float *)(gp - 0x7F58);
        } while (diff < c);
    }
    if (diff == 0.0f) {
        return b;
    }
    if (diff > 0.0f) {
        if (diff < step) {
            step = diff;
        }
        res = a - step;
    } else {
        if (diff > -step) {
            step = -diff;
        }
        res = a + step;
    }
    {
        register float c1 __asm__("$f1");
        __asm__ volatile("" : "+r"(gp));
        c1 = *(float *)(gp - 0x7F54);
        if (res > c1) {
            do {
                res -= *(float *)(gp - 0x7F50);
            } while (res > c1);
        }
        __asm__ volatile("" : "+r"(gp));
        c1 = *(float *)(gp - 0x7F4C);
        if (res < c1) {
            do {
                res += *(float *)(gp - 0x7F48);
            } while (res < c1);
        }
    }
    return res;
}

INCLUDE_ASM("build/ee_asm/game/chr/ch_1074A8", func_00107600);

void func_00107888(float v)
{
    D_0057E9D0 = v;
    D_0057E9D4 = v;
}

float Sg_GetSuimen(void)
{
    return D_0057E9D0;
}

void func_001078B0(float v)
{
    D_0057E9D4 = v;
}

INCLUDE_ASM("build/ee_asm/game/chr/ch_1074A8", func_001078C0);

s8 func_00107B18(Chr *chr)
{
    return chr->b192;
}

void JobSchedule_Ch_CalcMiddle_Batch(FloatTween *t)
{
    if (t->cur != t->dst) {
        if (t->frames != 0) {
            t->cur = t->cur + (t->dst - t->cur) / (float)t->frames;
        } else {
            t->cur = t->dst;
        }
    }
    if (t->frames != 0) {
        t->frames--;
    }
}

void func_00107B78(s32 v)
{
    D_0057E9D8 = v & 0x1;
}

s32 func_00107B88(void)
{
    return D_0057E9D8;
}

void func_00107B98(Chr *chr)
{
    if (!((s32)chr->flags & 1)) {
        chr->flags |= 8;
    }
}

void Ch_ReserveCalcNorm2(Chr *chr)
{
    if (!((s32)chr->flags & 1)) {
        chr->flags |= 0x10;
    }
}

s32 Ch_SetCalcNorm(Chr *chr, s32 v)
{
    s32 old = (s32)chr->flags & 1;

    FLAGS_SET(chr, 0, v);
    return old;
}

s32 func_00107C10(Chr *chr)
{
    return (s32)chr->flags & 0x1;
}

void func_00107C20(Chr *chr, s32 v)
{
    FLAGS_SET(chr, 2, v);
}

int func_00107C40(int v) /* DEBT(TYPE): declared int in q2.h, returns nothing */
{
    Chr *p;

    for (p = D_00300664; p != D_00300664 + D_00300668; p++) {
        if (p->active) {
            Ch_SetCalcNorm(p, v);
        }
    }
}

void Ch_AllReserveCalcNorm(void)
{
    Chr *p;

    for (p = D_00300664; p != D_00300664 + D_00300668; p++) {
        if (p->active) {
            func_00107B98(p);
        }
    }
}

void func_00107D60(void)
{
    D_0057E9DC = 0x1;
}

void Ch_CalcNormalAutoInit(void)
{
    D_0057E9E0 = 0;
}

s32 Sg_GetFuka(s32 a);

void func_00107D80(void)
{
    s32 n = 500 - Sg_GetFuka(0);
    Chr *p;

    if (n < 39) {
        return;
    }
    n /= 40;
    if (D_0057E9E0 == 0) {
        D_0057E9E0 = (s32)D_00300664;
    }
    p = (Chr *)D_0057E9E0;
    while (n != 0) {
        p++;
        if (p >= D_00300664 + D_00300668) {
            p = D_00300664;
        }
        if (p == (Chr *)D_0057E9E0) {
            break;
        }
        if (p->active && (p->flags & 6) && ((s32)((u64)p->flags >> 38) & 1)) {
            Ch_ReserveCalcNorm2(p);
            n--;
            D_0057E9E0 = (s32)p;
        }
    }
    if (n != 0) {
        D_0057E9E0 = 0;
    }
}

typedef struct {
    u16 h00;
    u16 h02;
    u16 h04;
    s16 h06;
    s32 w08;
} NormEntry12;

typedef struct {
    u8 pad00[6];
    u16 h06;
    u16 h08;
    u8 pad0A[10];
    NormEntry12 *p14;
    u8 pad18[12];
    NormEntry12 *p24;
} ChrHdrNormView;

void func_002DCF48(void *dst, void *src);
void func_00123EC4(s32 a, s32 b, void *m);
void func_00123CD8(s32 a, s32 b, void *m);
void func_00124260(s32 a, s32 b, void *m);
void func_00124058(s32 a, s32 b, void *m);
void func_001243E8(s32 a, s32 b);

void func_00107EC8(Chr *chr)
{
    float m0[4][4];
    float m1[4][4];
    s32 do_norm = 0;
    s32 prev;
    s32 i;

    if (D_0057E9D8 != 0 || ((s32)chr->flags & 1) || (FLAGS_BIT(chr, 3) && D_0057E9DC != 0) || FLAGS_BIT(chr, 4)) {
        s32 b4;

        do_norm = 1;
        if (FLAGS_BIT(chr, 3)) {
            chr->flags &= ~8;
            D_0057E9DC--;
        }
        b4 = FLAGS_BIT(chr, 4);
        if (b4 != 0) {
            chr->flags = (chr->flags & ~0x10) | ((s64)(b4 ^ 1) << 4);
        }
    }
    prev = -1;
    for (i = 0; i < ((ChrHdrNormView *)chr->hdr)->h08; i++) {
        NormEntry12 *e = &((ChrHdrNormView *)chr->hdr)->p14[i];

        if (prev != e->h04) {
            prev = e->h04;
            func_002DCF48(m1, chr->slots[prev].u90);
        }
        func_002DCE38(m0, m1, chr->slots[e->h00].u90);
        if (e->h06 != 0) {
            func_00123EC4(e->w08, chr->ents[e->h02].w08, m0);
        } else {
            func_00123CD8(e->w08, chr->ents[e->h02].w08, m0);
        }
        if (do_norm != 0) {
            e = &((ChrHdrNormView *)chr->hdr)->p24[i];
            if (e->w08 != 0) {
                if (e->h06 != 0) {
                    func_00124260(e->w08, chr->ents[e->h02].w04, m0);
                } else {
                    func_00124058(e->w08, chr->ents[e->h02].w04, m0);
                }
            }
        }
    }
    if (do_norm != 0) {
        for (i = 0; i < ((ChrHdrNormView *)chr->hdr)->h06; i++) {
            ChrEnt *ent = &chr->ents[i];

            func_001243E8(ent->w04, *(u16 *)((u8 *)ent->data + 0x16));
        }
    }
}

void func_00108178(Chr *chr, float a, float b)
{
    register u8 *saved_reg_gp __asm__("$28");
    float c;

    if (b != 0.0f) {
        __asm__ volatile("" : "+r"(saved_reg_gp));
        c = *(float *)(saved_reg_gp - 0x7EEC);
        if (a > c) {
            do {
                a -= *(float *)(saved_reg_gp - 0x7EE8);
            } while (a > c);
        }
        __asm__ volatile("" : "+r"(saved_reg_gp));
        c = *(float *)(saved_reg_gp - 0x7EE4);
        if (a < c) {
            do {
                a += *(float *)(saved_reg_gp - 0x7EE0);
            } while (a < c);
        }
        __asm__ volatile("" : "+r"(saved_reg_gp));
        c = *(float *)(saved_reg_gp - 0x7EDC);
        *(float *)((u8 *)chr + 0x16C) = a;
        *(float *)((u8 *)chr + 0x170) = b * c / 180.0f;
    } else {
        __asm__ volatile("" : "+r"(saved_reg_gp));
        c = *(float *)(saved_reg_gp - 0x7ED8);
        if (a > c) {
            do {
                a -= *(float *)(saved_reg_gp - 0x7ED4);
            } while (a > c);
        }
        __asm__ volatile("" : "+r"(saved_reg_gp));
        c = *(float *)(saved_reg_gp - 0x7ED0);
        if (a < c) {
            do {
                a += *(float *)(saved_reg_gp - 0x7ECC);
            } while (a < c);
        }
        *(float *)((u8 *)chr + 0x16C) = a;
        *(float *)((u8 *)chr + 0x168) = a;
        *(float *)((u8 *)chr + 0x170) = 0.0f;
    }
}

extern char D_00308100[];
extern char D_005695C0[];
void func_002DD128(void *);
void func_002DD0C0(void *, void *);
void func_002DD270(void *, void *, float);
void func_002DD318(void *, void *, float);
void func_002DD1C8(void *, void *, float);
void func_002DCE08(void *, void *, void *);
float func_001074D8(float, float, float);
void Ch_ElemCalcQuaternion(void *);

typedef union {
    u64 d[2];
    Vec4 v;
} Vec4CE;

#define SPAD_MAT ((float (*)[4])0x70000000)

void Ch_CalcElement(Chr *chr)
{
    register u8 *gp __asm__("$28");
    float m0[4][4];
    float m40[4][4];
    Vec4CE v80;
    s32 i;
    ChrSlot *slot = (ChrSlot *)chr->u1E0;

    func_002DD128(slot->u90);
    func_002DD128((u8 *)slot + 0x10);
    func_002DD128((u8 *)slot + 0x50);
    if (chr->p1A8 != 0) {
        Chr *parent;
        ChrParam *p;
        float sc;

        func_002DD128(SPAD_MAT);
        parent = chr->p1A8;
        {
            register float one __asm__("$f2") = 1.0f;
            sc = *(float *)((u8 *)chr + 0x1C0) * (one / parent->param->f30);
        }
        SPAD_MAT[2][2] = sc;
        SPAD_MAT[1][1] = sc;
        SPAD_MAT[0][0] = sc;
        func_002DCE38(m0, parent->slots[*(s32 *)((u8 *)chr + 0x1AC)].u90, SPAD_MAT);
        v80 = *(Vec4CE *)((u8 *)chr + 0x1B0);
        p = chr->p1A8->param;
        v80.v.x *= p->f30;
        v80.v.y *= p->f30;
        v80.v.z *= p->f30;
        func_002DCE08(&v80, m0, &v80);
        m0[3][0] = v80.v.x;
        m0[3][1] = v80.v.y;
        m0[3][2] = v80.v.z;
        func_002DCE38((u8 *)slot + 0x10, (u8 *)chr->p1A8 + 0x1F0, m0);
    } else if (*(void **)((u8 *)chr + 0x110) != 0) {
        func_002DD0C0((u8 *)slot + 0x10, *(void **)((u8 *)chr + 0x110));
    } else {
        register float sc __asm__("$f2");
        register float ry __asm__("$f20");
        register float ry2 __asm__("$f21");
        float pi;
        register float neg_pi __asm__("$f0");

        func_002DD128(SPAD_MAT);
        {
            register float f30 __asm__("$f0") = chr->param->f30;
            register float f38 __asm__("$f2") = chr->param->f38;
            sc = f30 / f38 * *(float *)(gp - 0x7EC8);
        }
        SPAD_MAT[0][0] = *(float *)((u8 *)chr + 0x60) * sc;
        SPAD_MAT[1][1] = *(float *)((u8 *)chr + 0x64) * sc;
        SPAD_MAT[2][2] = *(float *)((u8 *)chr + 0x68) * sc;
        if (*(float *)((u8 *)chr + 0x16C) != 0.0f) {
            *(float *)((u8 *)chr + 0x168) = func_001074D8(*(float *)((u8 *)chr + 0x168), *(float *)((u8 *)chr + 0x16C), *(float *)((u8 *)chr + 0x170));
            func_002DD270(SPAD_MAT, SPAD_MAT, *(float *)((u8 *)chr + 0x168));
        }
        {
            register float f164 __asm__("$f0") = *(float *)((u8 *)chr + 0x164);
            register float c7ec4 __asm__("$f1") = *(float *)(gp - 0x7EC4);
            ry = -f164 - c7ec4;
        }
        ry2 = ry;
        if (!(ry < *(float *)(gp - 0x7EC0) && ry > *(float *)(gp - 0x7EBC))) {
            func_002F0008(D_00308100, D_005695C0, func_002ED038(ry));
        }
        pi = *(volatile float *)(gp - 0x7EB8);
        if (ry2 > pi) {
            do {
                ry -= *(volatile float *)(gp - 0x7EB4);
            } while (ry > pi);
        }
        neg_pi = *(volatile float *)(gp - 0x7EB0);
        while (ry < neg_pi) {
            ry += *(float *)(gp - 0x7EAC);
        }
        func_002DD318(SPAD_MAT, SPAD_MAT, ry);
        SPAD_MAT[3][0] = chr->f10 + *(float *)((u8 *)chr + 0x70);
        SPAD_MAT[3][1] = chr->f14 + *(float *)((u8 *)chr + 0x74);
        SPAD_MAT[3][2] = chr->f18 + *(float *)((u8 *)chr + 0x78);
        func_002DD0C0((u8 *)slot + 0x10, SPAD_MAT);
    }
    func_002DD128(m40);
    {
        register float f114 __asm__("$f3") = *(float *)((u8 *)chr + 0x114);
        register float sx __asm__("$f2") = *(float *)((u8 *)chr + 0x60) * f114;
        register float sz __asm__("$f1") = *(float *)((u8 *)chr + 0x68) * f114;
        register float sy __asm__("$f4") = *(float *)((u8 *)chr + 0x64) * f114;
        register float f3C __asm__("$f0") = *(float *)((u8 *)chr->param + 0x3C);
        register float d2 __asm__("$f1") = f3C / sz;
        register float d0 __asm__("$f2") = f3C / sx;
        register float d1 __asm__("$f0") = f3C / sy;

        m40[2][2] = d2;
        m40[0][0] = d0;
        m40[1][1] = d1;
    }
    func_002DCE38((u8 *)slot + 0x50, (u8 *)slot + 0x10, m40);
    slot = chr->slots;
    for (i = 0; i < chr->hdr->h0A; i++, slot++) {
        if (slot->wD0 != 0) {
            func_002DD0C0(slot->u90, (void *)slot->wD0);
            slot->wD0 = 0;
        } else {
            func_002DD128(SPAD_MAT);
            SPAD_MAT[0][0] = *(float *)((u8 *)slot + 0x110);
            SPAD_MAT[1][1] = *(float *)((u8 *)slot + 0x114);
            SPAD_MAT[2][2] = *(float *)((u8 *)slot + 0x118);
            func_002DD270(SPAD_MAT, SPAD_MAT, *(float *)((u8 *)slot + 0xF0));
            func_002DD318(SPAD_MAT, SPAD_MAT, *(float *)((u8 *)slot + 0xF4));
            func_002DD1C8(SPAD_MAT, SPAD_MAT, *(float *)((u8 *)slot + 0xF8));
            SPAD_MAT[3][0] = *(float *)((u8 *)slot + 0x100);
            SPAD_MAT[3][1] = *(float *)((u8 *)slot + 0x104);
            SPAD_MAT[3][2] = *(float *)((u8 *)slot + 0x108);
            func_002DCE38(slot->u90, (u8 *)slot->data + 0x90, SPAD_MAT);
            if (slot->wD4 != 0) {
                Ch_ElemCalcQuaternion(slot);
            }
        }
    }
}

s32 func_00108750(Chr *chr, s32 key)
{
    ParamTbl *t = chr->param->tbl6C;
    ParamEntry *e;
    s32 n = t->count;

    n--;
    e = t->ents;
    while (n != -1) {
        if ((e->key & 0x3FFF) == key) {
            return e->val;
        }
        e++;
        n--;
    }
    return 0;
}

s32 Ch_ElemGetAttr(Chr *chr, s32 key, s32 *out, void *vec)
{
    Vec4 *d = (Vec4 *)vec;
    ChrParam *p;
    ParamTbl *t;
    ParamEntry *e;
    s32 n;

    *out = 0;
    if (d != 0) {
        d->x = d->y = d->z = 0.0f;
        d->w = 1.0f;
    }
    p = chr->param;
    t = p->tbl6C;
    if (t == 0) {
        return 0;
    }
    n = t->count;
    n--;
    e = t->ents;
    while (n != -1) {
        if ((e->key & 0x3FFF) == key) {
            *out = e->val;
            switch (e->key & 0xC000) {
            case 0:
                if (d != 0) {
                    d->x = d->y = d->z = 0.0f;
                    d->w = 1.0f;
                }
                return 0;
            case 0x4000:
                if (d != 0) {
                    float c;
                    float s;

                    __asm__("lwc1 %0, -0x7EA8($gp)" : "=f"(c));
                    s = c / p->f30 / p->f30 * p->f38;
                    d->x = *(float *)&e->pad[0] * s;
                    d->y = *(float *)&e->pad[4] * s;
                    d->z = *(float *)&e->pad[8] * s;
                    d->w = 1.0f;
                }
                return 1;
            case 0x8000:
                return 2;
            }
            return 0;
        }
        e++;
        n--;
    }
    return 0;
}

s32 func_001088E0(Chr *chr, s32 i)
{
    return chr->fx[i].f != 0;
}

typedef union {
    V128 q;
    Vec4 v;
} OptVec;

typedef struct {
    u8 pad000[0x220];
    Vec4 pos220;
    u8 pad230[0x300];
    OptVec opt530[1];
} ChrOptView;

void Ch_OptposGet(int a, int i, int b)
{
    ChrOptView *chr = (ChrOptView *)a;
    OptVec *dst = (OptVec *)b;

    if (chr->opt530[i].v.w == 0.0f) {
        if (chr->opt530[0].v.w == 0.0f) {
            dst->v.x = chr->pos220.x;
            dst->v.y = chr->pos220.y;
            dst->v.z = chr->pos220.z;
            dst->v.w = 1.0f;
        } else {
            dst->q = chr->opt530[0].q;
        }
    } else {
        dst->q = chr->opt530[i].q;
    }
}

void func_00108990(Chr *chr, V128 *dst)
{
    *dst = chr->v6C0;
}

void func_001089A8(int a, int b)
{
    Ch_OptposGet(a, 0, b);
}

s32 Ch_OptposGetElement(Chr *a, s32 b, s32 c)
{
    s32 out;

    Ch_ElemGetAttr(a, b, &out, (void *)c);
    return out;
}

void func_001089E0(Chr *a, s32 b, s32 c, void *d)
{
    s32 out;

    Ch_ElemGetAttr(a, b, &out, (void *)c);
    func_001072F8(a, out, d);
}

void func_00108A28(Chr *chr, V128 *dst)
{
    *dst = chr->v6A0;
}

void func_00108A40(Chr *chr, V128 *dst)
{
    *dst = chr->v6B0;
}

void func_002DCE08(void *dst, void *m, void *v);

typedef union {
    u64 d[2];
    Vec4 v;
} Vec4D;

void Ch_OptposCalc(Chr *chr)
{
    register u8 *saved_reg_gp __asm__("$28");
    ChrOptView *ov = (ChrOptView *)chr;
    ChrParam *p = chr->param;
    ParamTbl *t;
    ParamEntry *e;
    s32 i;
    s32 n;
    float s;
    Vec4D v0;
    Vec4D v1;
    Vec4D v2;
    Vec4D v3;
    float m[4][4];
    float dy1;
    float dy2;

    for (i = 21; i >= 0; i--) {
        ov->opt530[i].v.w = 0.0f;
    }
    t = p->tbl6C;
    if (t == 0) {
        return;
    }
    s = *(float *)(saved_reg_gp - 0x7EA4) / p->f30 / p->f30 * p->f38;
    n = t->count;
    e = t->ents;
    for (i = 0; i < n; i++, e++) {
        s32 idx = e->key & 0x3FFF;

        func_002DCE38(m, (u8 *)chr + 0x1F0, chr->slots[e->val].u90);
        switch ((s16)e->key & 0xC000) {
        case 0:
        case 0x8000:
            ov->opt530[idx].v.x = m[3][0];
            ov->opt530[idx].v.y = m[3][1];
            ov->opt530[idx].v.z = m[3][2];
            break;
        case 0x4000:
            v1.v.x = *(float *)&e->pad[0] * s;
            v1.v.y = *(float *)&e->pad[4] * s;
            v1.v.z = *(float *)&e->pad[8] * s;
            v1.v.w = 1.0f;
            func_002DCE08(&ov->opt530[idx], m, &v1);
            break;
        }
        ov->opt530[idx].v.w = 1.0f;
    }
    Ch_OptposGet((int)chr, 0, (int)&v2);
    *(Vec4D *)((u8 *)chr + 0x6C0) = v2;
    *(float *)((u8 *)chr + 0x6C4) -= *(float *)((u8 *)chr + 0x500);
    Ch_OptposGet((int)chr, 7, (int)&v2);
    Ch_OptposGet((int)chr, 8, (int)&v3);
    v2.v.x = (v2.v.x + v3.v.x) * 0.5f;
    v2.v.z = (v2.v.z + v3.v.z) * 0.5f;
    v2.v.y = (v2.v.y > v3.v.y) ? v2.v.y : v3.v.y;
    Ch_OptposGet((int)chr, 1, (int)&v3);
    *(Vec4D *)((u8 *)chr + 0x690) = *(Vec4D *)((u8 *)chr + 0x6A0);
    v2.v.x = v3.v.x = (v3.v.x + v2.v.x) * 0.5f;
    v2.v.z = v3.v.z = (v3.v.z + v2.v.z) * 0.5f;
    *(Vec4D *)((u8 *)chr + 0x6A0) = v2;
    *(Vec4D *)((u8 *)chr + 0x6B0) = v3;
    dy1 = *(float *)((u8 *)chr + 0x6B4) - *(float *)((u8 *)chr + 0x6A4);
    if (dy1 < 0.0f) {
        dy1 = -dy1;
    }
    *(float *)((u8 *)chr + 0x51C) = dy1;
    dy2 = chr->f14 - *(float *)((u8 *)chr + 0x6A4);
    if (dy2 < 0.0f) {
        dy2 = -dy2;
    }
    v2.v.y -= dy1 * *(float *)(saved_reg_gp - 0x7EA0);
    *(float *)((u8 *)chr + 0x520) = dy2;
    *(Vec4D *)((u8 *)chr + 0x6D0) = v2;
}

void func_00108DA0(Chr *chr, s32 i, s32 v)
{
    chr->slots[i].wD0 = v;
}

void func_00108DB8(Chr *chr, s32 i, float f, s32 v)
{
    /* DEBT(ORDER): sw before swc1 in source, scheduler swaps them */
    chr->slots[i].wD4 = v;
    chr->slots[i].fE8 = f;
}

float func_00108DD8(float *a, float *b)
{
    float d[3];

    d[0] = b[0] - a[0];
    d[1] = b[1] - a[1];
    d[2] = b[2] - a[2];
    return sqrtf(d[0] * d[0] + d[1] * d[1] + d[2] * d[2]);
}

float func_00108E50(float *v)
{
    return sqrtf(v[0] * v[0] + v[1] * v[1] + v[2] * v[2]);
}

void Ch_IdEnableShade(Chr *chr, s32 v)
{
    FLAGS_SET(chr, 18, v);
}

typedef struct {
    u8 pad00[0x40];
    float pos40[4];
    u8 pad50[0x40];
    float pos90[4];
    float posA0[4];
    float posB0[4];
} ChrShadeView;

s32 Ch_IdGetShade0(Chr *chr);
s32 Ch_IdGetShade1(Chr *chr);
s32 Ch_IdGetShade2(Chr *chr);
void func_00110478(Chr *chr, float v, s32 frames);

void Ch_IdShadeCalc(Chr *chr)
{
    ChrShadeView *sv = (ChrShadeView *)chr;
    float v[4];

    if (Sg_IdExistShade() == 0) {
        return;
    }
    if (!FLAGS_BIT(chr, 18)) {
        return;
    }
    v[0] = func_00108DD8(sv->pos40, sv->pos90);
    v[1] = func_00108DD8(sv->pos40, sv->posA0);
    v[2] = func_00108DD8(sv->pos40, sv->posB0);
    func_002DCEC8(v, v);
    v[0] = 1.0f - v[0];
    v[1] = 1.0f - v[1];
    v[2] = 1.0f - v[2];
    func_002DCEC8(v, v);
    v[0] *= Ch_IdGetShade0(chr) / 31.0f;
    v[1] *= Ch_IdGetShade1(chr) / 31.0f;
    v[2] *= Ch_IdGetShade2(chr) / 31.0f;
    func_00110478(chr, func_00108E50(v), 3);
}

void func_00109030(Chr *chr, s32 a, s32 b)
{
    chr->w804 = a;
    chr->w808 = b;
}

void func_00109040(s8 v)
{
    D_00303634 = v;
}

s8 Ch_GetDumpMotEv(void)
{
    return D_00303634;
}

typedef struct {
    s8 b00;
    s8 b01;
    s16 h02;
    s16 h04;
    s16 h06;
} MotEv;

typedef struct {
    u8 pad000[0x198];
    s32 w198;
    u8 pad19C[0x56C];
    s32 w708;
    s32 w70C;
    u8 pad710[0x40];
    s32 w750;
    u8 pad754[0xA8];
    s16 h7FC;
    s16 h7FE;
    MotEv *p800;
    void (*p804)(s32, s32);
    s32 w808;
} ChrMotEvView;

s32 func_001E1020(s32 id, s32 a, s32 b);
void func_00106E58(Chr *chr, s32 a);
void tex_anim_no_set(s32 a, s32 b, s32 c);

void Ch_MotEvent(Chr *chr)
{
    ChrMotEvView *mv = (ChrMotEvView *)chr;
    MotEv *ev;
    s32 cur;
    s32 prev;
    s32 i;

    if (mv->p800 == 0) {
        return;
    }
    cur = mv->w750 >> 8;
    prev = mv->h7FE;
    if (prev < cur) {
        for (i = 0, ev = mv->p800; i < mv->h7FC; i++) {
            s32 step;
            if (prev < ev->h04 && cur >= ev->h02) {
                switch (ev->b00) {
                case 5:
                    func_001E1020(mv->w198, ev->h06, 0);
                    break;
                case 1:
                    func_00106E58(chr, ev->h06);
                    break;
                case 3:
                    if (mv->w708 != 0) {
                        tex_anim_no_set(mv->w70C, (u16)ev->h06 >> 8, (u16)ev->h06 & 0xFF);
                    }
                    break;
                case 2:
                    if (mv->p804 != 0) {
                        mv->p804(mv->w808, ev->h06);
                    }
                    break;
                }
            }
            step = ev->b01 * 4 + 8;
            ev = (MotEv *)((u8 *)ev + step);
        }
    }
    mv->h7FE = cur;
}

void func_001091C8(void)
{
    Chr *p;

    for (p = D_00300664; p != D_00300664 + D_00300668; p++) {
        if (p->active) {
            p->flags &= ~(1L << 24);
            p->flags &= ~(1L << 25);
            p->flags &= ~(1L << 26);
        }
    }
}

void Ch_CbArcMapping(Rec12C *blk, s32 a);
void func_00102AF8(Chr *chr, Rec12C *blk);
void func_001603E0(s32 a, s32 b);

void Ch_MoveChrBlk(s32 a, s32 b)
{
    Rec12C *blk = 0;
    s32 i;
    Chr *chr;
    s32 diff;

    for (i = 0; i < 40; i++) {
        if (chrblk[i].w0 != -1 && chrblk[i].w6C == b) {
            blk = &chrblk[i];
        }
    }
    if (blk != 0) {
        Ch_CbArcMapping(blk, a);
        diff = a - b;
        for (chr = D_00300664; chr != D_00300664 + D_00300668; chr++) {
            if (chr->active && (Rec12C *)chr->param == blk) {
                func_00102AF8(chr, blk);
                ((s32 (*)(Chr *))Ch_TextureReMapping)(chr);
                if (chr->w708 != 0) {
                    func_001603E0(((Rec12C *)chr->param)->w14, chr->w70C);
                }
                if (*(s32 *)&chr->pad75E[6] != 0) {
                    *(s32 *)&chr->pad75E[6] += diff;
                }
            }
        }
    }
}

void Ch_ClothResetRelation(Chr *chr)
{
    Chr *p;

    for (p = D_00300664; p != D_00300664 + D_00300668; p++) {
        if (p->active && !FLAGS_BIT(p, 23) && p != chr && p->p1A8 == chr) {
            Ch_ClothReset(p);
        }
    }
}

void func_00109430(void)
{
    Chr *p;

    for (p = D_00300664; p != D_00300664 + D_00300668; p++) {
        if (p->active) {
            Ch_ClothReset(p);
        }
    }
}

s32 Sg_MemGetSize(s32 a);
void func_0011D590(s32 a, s32 b);
extern char D_005695F8[];

void MoveChrBlk_(void)
{
    s32 i;

    for (i = 0; i < 40; i++) {
        if (chrblk[i].w0 != -1) {
            s32 old = chrblk[i].w6C;
            s32 size = Sg_MemGetSize(old);
            s32 mem;

            func_0011C348(0x80);
            mem = (s32)user_malloc(size, 6, D_005695F8, 0x4B8);
            func_002EEF1C(mem, old, size);
            func_0011D590(old, 6);
            Ch_MoveChrBlk(mem, old);
        }
    }
}

void func_00109590(Chr *chr, float *out)
{
    out[0] = chr->f20 - chr->f10;
    out[1] = chr->f24 - chr->f14;
    out[2] = chr->f28 - chr->f18;
}

void func_001095C8(Chr *chr, float *out)
{
    out[0] = chr->f30 - chr->f10;
    out[1] = chr->f34 - chr->f14;
    out[2] = chr->f38 - chr->f18;
}

extern float D_00307F3C;
void func_00107600(Chr *chr);
void func_001078C0(Chr *chr);
float func_002E8648(float);
float func_002E89C0(float);
void func_00122450(void);
void func_00112F78(Chr *chr, s32 a);

typedef struct {
    u16 h00;
    s8 active;
    u8 pad03[0xD];
    Vec4D v10;
    Vec4D v20;
    u8 pad30[0x20];
    float f50;
    float f54;
    float f58;
    u8 pad5C[0x104];
    float f160;
    u8 pad164[0x10];
    float f174;
    float f178;
    float f17C;
    u8 pad180[0xC];
    s8 b18C;
    s8 b18D;
    s8 b18E;
    u8 pad18F[3];
    s8 b192;
    u8 pad193[0xD];
    s64 flags;
    u8 pad1A8[0x180];
    FloatTween tw328[7];
    u8 pad37C[0x174];
    float f4F0;
    u8 pad4F4[0x14];
    float f508;
    u8 pad50C[4];
    float f510;
    u8 pad514[0xC];
    float f520;
    u8 pad524[0x31C];
} ChrMainView;

void Ch_CalcMain(void)
{
    register u8 *gp __asm__("$28");
    ChrMainView *p;
    float tmp;
    u32 t0;

    if (Sg_GetPause() != 0) {
        return;
    }
    for (p = (ChrMainView *)D_00300664; p != (ChrMainView *)(D_00300664 + D_00300668); p++) {
        if (!p->active) {
            continue;
        }
        p->b18C &= 0x13;
        if (p->b18C != 0 && p->b18D == 0) {
            continue;
        }
        if (!FLAGS_BIT(p, 6)) {
            switch (p->b192) {
            case 0:
                func_00107600((Chr *)p);
                break;
            case 2:
                func_001078C0((Chr *)p);
                break;
            }
        }
        {
            s32 gt = (p->f160 > p->f17C);
            FLAGS_SET(p, 17, gt);
        }
        if (p->f160 != 0.0f) {
            float spd;

            tmp = p->f174;
            if (Sg_GetKeepFps() == 2 && FLAGS_BIT(p, 20)) {
                spd = p->f160 * *(float *)(gp - 0x7E9C) * D_00307F3C;
            } else {
                spd = p->f160 * *(float *)(gp - 0x7E98);
            }
            p->f50 = func_002E8648(tmp) * spd;
            p->f58 = func_002E89C0(tmp) * spd;
            p->flags |= (1ULL << 25);
        } else {
            *(volatile float *)&p->f58 = 0.0f;
            *(volatile float *)&p->f50 = 0.0f;
        }
        p->v20 = p->v10;
    }
    func_00122450();
    if (D_0057E9D4 < D_0057E9D0) {
        D_0057E9D4 = D_0057E9D0;
    }
    for (p = (ChrMainView *)D_00300664; p != (ChrMainView *)(D_00300664 + D_00300668); p++) {
        if (!p->active) {
            continue;
        }
        if (p->b18C != 0 && p->b18D == 0) {
            continue;
        }
        {
            s32 sub = (D_0057E9D0 < p->v10.v.y - 8.5f);
            register s64 flg __asm__("$4") = p->flags;
            flg = (flg & ~(1LL << 29)) | ((s64)sub << 29);
            p->flags = flg;
        }
        switch (p->b18E) {
        case 0:
            p->f510 = 0.0f;
            if (!FLAGS_BIT(p, 7)) {
                if (p->f178 < p->v10.v.y) {
                    p->v10.v.y = p->f178;
                }
            }
            break;
        case 1:
            p->f510 = 0.0f;
            p->v10.v.y = p->f178;
            break;
        case 2: {
            float damp;
            float target;
            float g = *(volatile float *)(gp - 0x7E94);

            tmp = 0.0f;
            if (D_0057E9D0 < p->v10.v.y - 8.5f) {
                tmp = 1.0f;
            } else if (D_0057E9D0 < p->v10.v.y) {
                tmp = (p->v10.v.y - D_0057E9D0) / 8.5f;
            }
            if (tmp != 0.0f) {
                damp = 0.5f;
                p->f510 -= g * 0.5f;
                if (p->v10.v.y < D_0057E9D4) {
                    p->v10.v.y += (D_0057E9D4 - p->v10.v.y) / 10.0f;
                    if (p->f510 < 0.0f) {
                        p->f510 = 0.0f;
                    }
                }
            } else {
                damp = 1.0f;
                p->f510 += g;
            }
            if (p->f510 < tmp * -2.0f) {
                p->f510 = tmp * -2.0f;
            }
            target = (p->f520 < p->f4F0) ? p->f4F0 : p->f520;
            p->f508 += (target - p->f508) / 30.0f;
            if (p->f178 < p->v10.v.y + p->f510 + p->f508) {
                p->f510 = 0.0f;
                p->v10.v.y = p->f178 - p->f508;
            }
            p->v10.v.y += p->f510 * damp;
            break;
        }
        }
    }
    t0 = *(volatile u32 *)0x10000000;
    for (p = (ChrMainView *)D_00300664; p != (ChrMainView *)(D_00300664 + D_00300668); p++) {
        if (!p->active) {
            continue;
        }
        if (p->b18C != 0 && p->b18D == 0) {
            continue;
        }
        p->flags |= (1ULL << 24);
        func_00112F78((Chr *)p, FLAGS_BIT(p, 24));
        {
            s32 i;
            for (i = 0; i < 7; i++) {
                JobSchedule_Ch_CalcMiddle_Batch(&p->tw328[i]);
            }
        }
    }
    D_0057E9B0[1] = *(volatile u32 *)0x10000000 - t0;
}

void func_00109B80(void) {
}

void func_00109B88(Chr *chr, s8 v)
{
    chr->b4E0 = v;
}

s8 func_00109B90(Chr *chr)
{
    return chr->b4E0;
}

void func_00109B98(s32 v)
{
    if (v < 0) {
        v = 0;
    }
    if (v > 200) {
        v = 200;
    }
    D_00303638 = v;
}

s16 func_00109BC0(void)
{
    return D_00303638;
}

void func_00109BD0(s8 a, s8 b)
{
    D_00303636 = a;
    D_00303637 = b;
}

s8 func_00109BE8(void)
{
    return D_00303636;
}

/* DEBT(CAST) */ /* DEBT(FAKE) */
void func_00109BF8(void *arg0) {
    register u8 *saved_reg_gp __asm__("$28");
    (*(float *)((u8 *)(arg0) + (0x4E4))) = (float) (*(float *)((u8 *)(saved_reg_gp) + (-0x7E90)));
}

INCLUDE_ASM("build/ee_asm/game/chr/ch_1074A8", Ch_Mouth);

void _m2c_Ch_ElemCalcQuaternion_Sg_MatrixToQuaternion(void *, s32 *) __asm__("Sg_MatrixToQuaternion");
void _m2c_Ch_ElemCalcQuaternion_Sg_QuaternionSlerp(s32 *, s32 *, s32 *, float) __asm__("Sg_QuaternionSlerp");
void _m2c_Ch_ElemCalcQuaternion_func_00120958(s32 *, void *) __asm__("func_00120958");
void _m2c_Ch_ElemCalcQuaternion_func_002DD0C0(void *, void *) __asm__("func_002DD0C0");
/* DEBT(CAST) */
void Ch_ElemCalcQuaternion(void *arg0) {
    u8 sp[0x10];
    u8 sp10[0x10];
    float temp_f1;
    float temp_f20;
    float temp_f21;
    float temp_f22;
    void *temp_17;

    temp_f1 = (*(float *)((u8 *)(arg0) + (0xE8)));
    if (temp_f1 != 0.0f) {
        temp_f22 = (*(float *)((u8 *)(arg0) + (0xC0)));
        temp_f21 = (*(float *)((u8 *)(arg0) + (0xC4)));
        temp_f20 = (*(float *)((u8 *)(arg0) + (0xC8)));
        if (temp_f1 == 1.0f) {
            _m2c_Ch_ElemCalcQuaternion_func_002DD0C0(arg0 + 0x90, (*(void **)((u8 *)(arg0) + (0xD4))));
        } else if (temp_f1 != 0.0f) {
            temp_17 = arg0 + 0x90;
            _m2c_Ch_ElemCalcQuaternion_Sg_MatrixToQuaternion(temp_17, sp10);
            _m2c_Ch_ElemCalcQuaternion_Sg_MatrixToQuaternion((*(void **)((u8 *)(arg0) + (0xD4))), sp);
            _m2c_Ch_ElemCalcQuaternion_Sg_QuaternionSlerp(sp10, sp, sp, (*(float *)((u8 *)(arg0) + (0xE8))));
            _m2c_Ch_ElemCalcQuaternion_func_00120958(sp, temp_17);
        }
        (*(float *)((u8 *)(arg0) + (0xC0))) = temp_f22;
        (*(float *)((u8 *)(arg0) + (0xC4))) = temp_f21;
        (*(float *)((u8 *)(arg0) + (0xC8))) = temp_f20;
    }
}

typedef struct {
    s8 b00;
    s8 b01;
    s8 b02;
    u8 pad03[5];
    float f08;
    u8 pad0C[4];
    float f10;
    float f14;
    float f18;
    float f1C;
    float m20[4][4];
    float m60[4][4];
    float qA0[4];
    float fB0;
} ChrNeck;

void Ch_NeckSetEnable(void *a, int v)
{
    ChrNeck *n = (ChrNeck *)((u8 *)a + 0x410);

    n->b00 = v;
    if (v != 0) {
        n->f08 = 1.0f;
        if (n->b02 != n->b01) {
            _m2c_Ch_ElemCalcQuaternion_Sg_MatrixToQuaternion(n->m60, (s32 *)n->qA0);
            n->fB0 = 1.0f;
        }
    } else {
        n->f08 = 0.0f;
    }
    n->b02 = n->b01;
}

void Ch_NeckSetTarget(Chr *chr, s32 v)
{
    chr->u4D0.w4D0 = v;
    chr->b411 = 2;
    Ch_NeckSetEnable(chr, 1);
}

void func_0010A1F8(Chr *chr, Cmd16 *src)
{
    chr->b411 = 3;
    chr->u4D0.cmd = *src;
    Ch_NeckSetEnable(chr, 1);
}

void func_0010A220(Chr *chr)
{
    chr->b411 = 1;
    Ch_NeckSetEnable(chr, 1);
}

void func_0010A230(Chr *chr, float a, float b)
{
    chr->b411 = 4;
    chr->u4D0.f.f4D0 = a;
    chr->u4D0.f.f4D4 = b;
    Ch_NeckSetEnable(chr, 1);
}

void func_0010A250(Chr *chr, float v)
{
    if (v == 0.0f) {
        v = 6.0f;
    }
    chr->f424 = v;
}

void func_0010A270(Chr *chr, float x, float y)
{
    chr->f428 = x;
    chr->f42C = y;
}

INCLUDE_ASM("build/ee_asm/game/chr/ch_1074A8", Ch_NeckInit);

INCLUDE_ASM("build/ee_asm/game/chr/ch_1074A8", Ch_Neck);

Chr *Ch_TextureAnimGetHandle(s32 v)
{
    Chr *p;

    for (p = D_00300664; p != D_00300664 + D_00300668; p++) {
        if (p->active && p->w70C == v) {
            return p;
        }
    }
    return 0;
}

void Ch_Mouth(Chr *chr);
void Ch_Neck(Chr *chr);
void Ch_CalcElement(Chr *chr);
void Ch_OptposCalc(Chr *chr);
void chr_texanim_main(s32 a);

void Ch_CalcMiddle_Batch(void)
{
    u32 t0 = *(volatile u32 *)0x10000000;
    s32 pass;
    Chr *p;

    for (pass = 0; pass < 2; pass++) {
        for (p = D_00300664; p != D_00300664 + D_00300668; p++) {
            if (p->active) {
                if (p->p1A8 != 0) {
                    if (pass == 0) {
                        continue;
                    }
                } else {
                    if (pass != 0) {
                        continue;
                    }
                }
                if ((s32)((u64)p->flags >> 32) & 1) {
                    func_002984F8(p);
                    p->flags &= ~(1LL << 32);
                }
                if (p->b18C == 0 || p->b18D != 0) {
                    if (Sg_GetPause() == 0) {
                        Ch_Mouth(p);
                        Ch_Neck(p);
                        if (p->flags & 0x3000000) {
                            Ch_CalcElement(p);
                            Ch_OptposCalc(p);
                        }
                        Ch_IdShadeCalc(p);
                        if (FLAGS_BIT(p, 24)) {
                            Ch_MotEvent(p);
                            p->flags &= ~0x1000;
                        } else {
                            p->flags |= 0x1000;
                        }
                        if (p->w708 != 0 && Sg_GuiGetTextureAnim() != 0) {
                            chr_texanim_main(p->w70C);
                        }
                        {
                            s32 is_player = ((Chr *)Sg_GetPlayer() == p);
                            FLAGS_SET(p, 9, is_player);
                        }
                    }
                }
            }
        }
    }
    func_00107D60();
    D_0057E9B0[2] = *(volatile u32 *)0x10000000 - t0;
}
