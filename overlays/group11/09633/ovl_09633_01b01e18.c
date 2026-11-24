#include "common.h"
#include "vu0.h"

typedef struct Ovl09633Sub {
    u8 pad00[0xC4];
    float fC4;          /* 0xC4 */
    u8 padC8[0x8];
    float pos[4];       /* 0xD0 */
    u8 padE0[0x8];
    float fE8;          /* 0xE8 */
    u8 padEC[0x44];
} Ovl09633Sub; /* size 0x130 */

typedef struct Ovl09633ObjA {
    u8 pad00[0x80];
    u8 b80;             /* 0x80 */
    u8 b81;             /* 0x81 */
    u8 b82;             /* 0x82 */
    u8 b83;             /* 0x83 */
    u8 b84;             /* 0x84 */
    u8 b85;             /* 0x85 */
    u8 b86;             /* 0x86 */
    u8 b87;             /* 0x87 */
    int w88;            /* 0x88 */
    u8 pad8C[0xC];
    u8 b98;             /* 0x98 */
    u8 b99;             /* 0x99 */
    u8 pad9A[0x6];
} Ovl09633ObjA; /* size 0xA0 */

typedef struct Ovl09633ObjB {
    u8 pad00[0xF0];
    u8 bF0;             /* 0xF0 */
    u8 bF1;             /* 0xF1 */
    u8 bF2;             /* 0xF2 */
    u8 bF3;             /* 0xF3 */
    u8 padF4[0x4];
    float fF8;          /* 0xF8 */
    float fFC;          /* 0xFC */
    int w100;           /* 0x100 */
    u8 pad104[0xC];
    int w110;           /* 0x110 */
    u8 pad114[0xC];
    int w120;           /* 0x120 */
    s16 h124;           /* 0x124 */
    u8 pad126[0x1A];
} Ovl09633ObjB; /* size 0x140 */

typedef struct Ovl09633Arg {
    u8 pad00[0x2C];
    int cnt;            /* 0x2C */
} Ovl09633Arg;

typedef struct Ovl09633Work {
    Ovl09633Sub sub[12];    /* 0x000..0xE40 */
    u8 padE40[0x104];
    int wF44;               /* 0xF44 */
    u8 padF48[0x158];
    Ovl09633Sub sub2[5];    /* 0x10A0..0x1690 */
    u8 pad1690[0x1F0];
    u8 b1880[3][0x40];      /* 0x1880 */
    u8 pad1940[0x10];
    float q1950[4];         /* 0x1950 */
    u8 pad1960[0x10];
    float q1970[4];         /* 0x1970 */
    u8 pad1980[0x10];
    float q1990[4];         /* 0x1990 */
    u8 b19A0[3][0x20];      /* 0x19A0 */
    float q1A00[4];         /* 0x1A00 */
    float q1A10[3][4];      /* 0x1A10 */
    float q1A40[3][4];      /* 0x1A40 */
    Ovl09633ObjA objA[2];   /* 0x1A70, 0x1B10 */
    u8 b1BB0[0x40];         /* 0x1BB0 */
    u8 b1BF0[0x90];         /* 0x1BF0 */
    Ovl09633ObjB objB[3];   /* 0x1C80, 0x1DC0, 0x1F00 */
    u8 pad2040[0x230];
    float f2270;            /* 0x2270 */
    u8 pad2274[0xC];
    int timer[3];           /* 0x2280 */
} Ovl09633Work;

extern float D_01B007C0[];
extern u8 D_01B0A0E8[];
extern Ovl09633Work *D_01B0A270;

void func_01B01DE8(int a0, int a1, int a2);
void func_01B04AA8(int a0, float a1);
void func_01B04AD8(int a0, void *a1, void *a2);
void func_01B05100(int *a0);
void func_01B05C08(void *a0, void *a1, int a2, int a3, int a4, int a5, float a6);
void func_01B06078(void *a0, void *a1);
void func_01B06A40(float *a0, float *a1, float *a2);
void func_01B06BB8(void *a0, float a1);
void func_01B092B8(void *a0, int a1);
void func_01B09470(void *a0, int a1, int a2, float a3, float a4);
void func_01B09C40(void *a0, int a1);

static inline void copy_vec(void *dst, void *src)
{
    MMI_COPY_LQ_A3(dst, src);
    MMI_COPY_SQ_A3(dst);
}

void func_01B01E18(void)
{
    Ovl09633Work *w = D_01B0A270;
    Ovl09633Sub *s = &w->sub[11];

    func_01B05C08(D_01B0A0E8, s, 0xB, 0, 0, 0, 0.01f);
    copy_vec(s->pos, w->q1A00);
    s->pos[1] -= 5000.0f;
    s->fC4 = w->f2270;
}

void func_01B01EA8(void)
{
    Ovl09633Work *w = D_01B0A270;

    w->wF44 = 0;
    copy_vec(w->sub[11].pos, w->q1A00);
    func_01B01DE8(0x40, 0x50, 0x80);
}

void func_01B01ED8(void)
{
    Ovl09633Work *w = D_01B0A270;
    Ovl09633Sub *s = &w->sub[10];
    int col[4];

    func_01B06078(D_01B0A0E8, &w->sub[11]);
    func_01B05C08(D_01B0A0E8, s, 0xA, 0, 0, 0, 0.01f);
    copy_vec(s->pos, w->q1A00);
    s->pos[1] -= 100.0f;
    s->fC4 = w->f2270;
    func_01B05100(col);
    func_01B01DE8(col[0], col[1], col[2]);
    func_01B09470(w->b1BF0, 0x1E, 0, 0.0f, 0.34f);
}

void func_01B01FB0(void)
{
    Ovl09633Work *w = D_01B0A270;
    Ovl09633Sub *s = &w->sub[9];
    float ang;

    func_01B06078(D_01B0A0E8, &w->sub[10]);
    func_01B05C08(D_01B0A0E8, s, 9, 0, 0, 0, 0.008f);
    copy_vec(s->pos, w->q1A00);
    ang = w->f2270 + 3.1415927f;
    if (ang > 3.1415927f) {
        ang -= 6.2831855f;
    } else if (ang < -3.1415927f) {
        ang += 6.2831855f;
    }
    s->fC4 = ang;
    s->fE8 = -5.0f;
    s->pos[1] -= 0.5f;
}

void func_01B020B8(void)
{
    float rot[4];
    float ofs[4];
    Ovl09633Work *w = D_01B0A270;
    Ovl09633Sub *s;
    float ang;

    rot[0] = 0.0f;
    rot[1] = w->f2270;
    rot[2] = 0.0f;
    rot[3] = 0.0f;
    ofs[1] = 0.0f;
    ofs[3] = 1.0f;

    s = &w->sub[8];
    func_01B05C08(D_01B0A0E8, s, 8, 0, 0, 0, 0.013f);
    copy_vec(s->pos, w->q1A00);
    ofs[0] = -16.5f;
    ofs[2] = -0.8f;
    func_01B06A40(rot, s->pos, ofs);
    copy_vec(w->q1950, s->pos);
    ang = w->f2270 - 0.7853982f;
    if (ang > 3.1415927f) {
        ang -= 6.2831855f;
    } else if (ang < -3.1415927f) {
        ang += 6.2831855f;
    }
    s->fC4 = ang;
    s->pos[1] -= 0.5f;

    s = &w->sub[7];
    func_01B05C08(D_01B0A0E8, s, 7, 0, 0, 0, 0.013f);
    copy_vec(s->pos, w->q1A00);
    ofs[0] = 0.0f;
    ofs[2] = 15.5f;
    func_01B06A40(rot, s->pos, ofs);
    copy_vec(w->q1970, s->pos);
    s->fC4 = w->f2270;
    s->pos[1] -= 0.5f;

    s = &w->sub[6];
    func_01B05C08(D_01B0A0E8, s, 6, 0, 0, 0, 0.013f);
    copy_vec(s->pos, w->q1A00);
    ofs[0] = 16.5f;
    ofs[2] = -0.8f;
    func_01B06A40(rot, s->pos, ofs);
    copy_vec(w->q1990, s->pos);
    ang = w->f2270 + 0.7853982f;
    if (ang > 3.1415927f) {
        ang -= 6.2831855f;
    } else if (ang < -3.1415927f) {
        ang += 6.2831855f;
    }
    s->fC4 = ang;
    s->pos[1] -= 0.5f;
}

void func_01B023A8(Ovl09633Arg *a0)
{
    Ovl09633Work *w = D_01B0A270;
    float t;
    float u;

    if (a0->cnt > 0) {
        a0->cnt--;
    }
    t = (float)a0->cnt / 20.0f;
    func_01B04AD8(3, w->b1880[0], w->b19A0[0]);
    u = 1.0f - t;
    func_01B06BB8(w->b1880[0], u * 2.2f + t * 0.0f);
    func_01B04AA8(3, u * 2.2f + t * 0.0001f);
    func_01B04AD8(4, w->b1880[1], w->b19A0[1]);
    func_01B06BB8(w->b1880[1], u * 2.0f + t * 0.0f);
    func_01B04AA8(4, u * 2.0f + t * 0.0001f);
    func_01B04AD8(5, w->b1880[2], w->b19A0[2]);
    func_01B06BB8(w->b1880[2], u * 2.0f + t * 0.0f);
    func_01B04AA8(5, u * 2.0f + t * 0.0001f);
}

void func_01B024F8(void)
{
    Ovl09633Work *w = D_01B0A270;
    Ovl09633Sub *s;

    s = &w->sub2[0];
    func_01B05C08(D_01B0A0E8, s, 4, 0, 0, 0, 0.007f);
    copy_vec(s->pos, w->q1950);
    s->fC4 = w->f2270;
    s->pos[1] -= 0.5f;

    s = &w->sub2[1];
    func_01B05C08(D_01B0A0E8, s, 4, 0, 0, 0, 0.007f);
    copy_vec(s->pos, w->q1970);
    s->fC4 = w->f2270;
    s->pos[1] -= 0.5f;

    s = &w->sub2[2];
    func_01B05C08(D_01B0A0E8, s, 4, 0, 0, 0, 0.007f);
    copy_vec(s->pos, w->q1990);
    s->fC4 = w->f2270;
    s->pos[1] -= 0.5f;
}

void func_01B02630(void)
{
    Ovl09633Work *w = D_01B0A270;
    Ovl09633Sub *s;
    Ovl09633ObjA *oa;
    Ovl09633ObjB *ob;

    func_01B06078(D_01B0A0E8, &w->sub[5]);
    func_01B06078(D_01B0A0E8, &w->sub[8]);
    func_01B06078(D_01B0A0E8, &w->sub[7]);
    func_01B06078(D_01B0A0E8, &w->sub[6]);

    s = &w->sub[1];
    func_01B05C08(D_01B0A0E8, s, 1, 6, 0, 0, 0.01f);
    copy_vec(s->pos, w->q1970);
    s->fC4 = w->f2270;
    s->pos[1] -= 12.0f;

    oa = &w->objA[0];
    oa->w88 = 0xA;
    oa->b82 = 0x80;
    oa->b81 = 0x80;
    oa->b80 = 0x80;
    oa->b83 = 0x80;
    oa->b98 = 0x48;
    oa->b87 = 0;
    oa->b86 = 0;
    oa->b85 = 0;
    oa->b84 = 0;
    oa->b99 = 0;
    func_01B092B8(oa, 0xA);

    ob = &w->objB[0];
    ob->bF0 = 0x80;
    ob->bF1 = 0x80;
    ob->bF2 = 0x80;
    ob->bF3 = 0x40;
    ob->h124 = 4;
    ob->fF8 = 0.02f;
    ob->fFC = 0.01f;
    ob->w120 = 0;
    ob->w110 = 0;
    ob->w100 = 0;
    func_01B09C40(ob, 0x32);

    func_01B09470(w->b1BF0, 0x14, 0xA, 0.34f, 1.0f);
}

void func_01B027B8(void)
{
    Ovl09633Work *w = D_01B0A270;
    Ovl09633Sub *s;
    Ovl09633ObjA *oa;
    Ovl09633ObjB *ob;

    s = &w->sub[2];
    func_01B05C08(D_01B0A0E8, s, 2, 6, 0, 0, 0.012f);
    copy_vec(s->pos, w->q1950);
    s->fC4 = w->f2270;
    s->pos[1] -= 10.0f;

    oa = &w->objA[0];
    oa->w88 = 0xA;
    oa->b82 = 0x80;
    oa->b81 = 0x80;
    oa->b80 = 0x80;
    oa->b83 = 0x80;
    oa->b98 = 0x48;
    oa->b87 = 0;
    oa->b86 = 0;
    oa->b85 = 0;
    oa->b84 = 0;
    oa->b99 = 0;
    func_01B092B8(oa, 0xA);

    ob = &w->objB[1];
    ob->bF3 = 0x40;
    ob->bF0 = 0x80;
    ob->bF1 = 0x80;
    ob->bF2 = 0x80;
    ob->h124 = 4;
    ob->fF8 = 0.02f;
    ob->fFC = 0.01f;
    ob->w120 = 0;
    ob->w110 = 0;
    ob->w100 = 0;
    func_01B09C40(ob, 0x32);

    func_01B09470(w->b1BB0, 1, 0, 1.0f, 0.34f);
    func_01B09470(w->b1BF0, 0x14, 0xA, 0.34f, 1.0f);
}

void func_01B02938(void)
{
    Ovl09633Work *w = D_01B0A270;
    Ovl09633Sub *s;
    Ovl09633ObjA *oa;
    Ovl09633ObjB *ob;

    s = &w->sub[3];
    func_01B05C08(D_01B0A0E8, s, 3, 6, 0, 0, 0.008f);
    copy_vec(s->pos, w->q1990);
    s->fC4 = w->f2270;
    s->pos[1] -= 6.0f;

    oa = &w->objA[0];
    oa->w88 = 0xA;
    oa->b82 = 0x80;
    oa->b81 = 0x80;
    oa->b80 = 0x80;
    oa->b83 = 0x80;
    oa->b98 = 0x48;
    oa->b87 = 0;
    oa->b86 = 0;
    oa->b85 = 0;
    oa->b84 = 0;
    oa->b99 = 0;
    func_01B092B8(oa, 0xA);

    ob = &w->objB[2];
    ob->bF3 = 0x40;
    ob->bF0 = 0x80;
    ob->bF1 = 0x80;
    ob->bF2 = 0x80;
    ob->h124 = 4;
    ob->fF8 = 0.02f;
    ob->fFC = 0.01f;
    ob->w120 = 0;
    ob->w110 = 0;
    ob->w100 = 0;
    func_01B09C40(ob, 0x32);

    func_01B09470(w->b1BB0, 1, 0, 1.0f, 0.34f);
    func_01B09470(w->b1BF0, 0x14, 0xA, 0.34f, 1.0f);
}

void func_01B02AB8(void)
{
    float rot[4];
    float ofs[4];
    Ovl09633Work *w = D_01B0A270;
    Ovl09633Sub *s;
    Ovl09633ObjA *oa;

    s = &w->sub[0];
    func_01B05C08(D_01B0A0E8, s, 0, 0, 0, 0, 0.01f);
    copy_vec(s->pos, w->q1A00);
    s->fC4 = w->f2270;
    s->pos[1] -= 0.5f;

    oa = &w->objA[1];
    oa->b82 = 0xFF;
    oa->b81 = 0xFF;
    oa->b80 = 0xFF;
    oa->b83 = 0x80;
    oa->b87 = 0;
    oa->b86 = 0;
    oa->b85 = 0;
    oa->b84 = 0;
    oa->w88 = 0;
    oa->b98 = 0x48;
    oa->b99 = 0;
    func_01B092B8(oa, 0x2D);

    rot[0] = 0.0f;
    rot[1] = w->f2270;
    rot[2] = 0.0f;
    rot[3] = 0.0f;
    ofs[1] = 0.0f;
    ofs[3] = 1.0f;

    copy_vec(w->q1950, w->q1A00);
    ofs[0] = -8.5f;
    ofs[2] = -0.8f;
    func_01B06A40(rot, w->q1950, ofs);

    copy_vec(w->q1970, w->q1A00);
    ofs[0] = 0.0f;
    ofs[2] = 13.0f;
    func_01B06A40(rot, w->q1970, ofs);

    copy_vec(w->q1990, w->q1A00);
    ofs[0] = 8.5f;
    ofs[2] = -0.8f;
    func_01B06A40(rot, w->q1990, ofs);
}

void func_01B02C48(void)
{
    float rot[4];
    float ofs[4];
    Ovl09633Work *w = D_01B0A270;
    Ovl09633Sub *s;

    rot[0] = 0.0f;
    rot[1] = w->f2270;
    rot[2] = 0.0f;
    rot[3] = 0.0f;
    ofs[1] = 0.0f;
    ofs[3] = 1.0f;

    copy_vec(w->q1A10[0], w->q1950);
    copy_vec(w->q1A40[0], w->q1A00);
    ofs[0] = -16.5f;
    ofs[2] = -20.0f;
    func_01B06A40(rot, w->q1A40[0], ofs);

    copy_vec(w->q1A10[1], w->q1970);
    copy_vec(w->q1A40[1], w->q1A00);
    ofs[0] = 0.0f;
    ofs[2] = -25.0f;
    func_01B06A40(rot, w->q1A40[1], ofs);

    copy_vec(w->q1A10[2], w->q1990);
    copy_vec(w->q1A40[2], w->q1A00);
    ofs[0] = 16.5f;
    ofs[2] = -20.0f;
    func_01B06A40(rot, w->q1A40[2], ofs);

    w->timer[0] = 0x43;
    w->timer[1] = 0x1C;
    w->timer[2] = 0x23;

    s = &w->sub2[3];
    func_01B05C08(D_01B0A0E8, s, 0xD, 0x13, 0, 0, 0.015f);
    {
        register float *d __asm__("$3") = s->pos;
        __asm__ volatile("" : "+r"(d));
        copy_vec(d, w->q1A40[0]);
    }
    s->fC4 = w->f2270;
    s->pos[1] -= 0.5f;

    s = &w->sub2[4];
    func_01B05C08(D_01B0A0E8, s, 0xD, 0x1B, 0, 0, 0.015f);
    {
        register float *d __asm__("$3") = s->pos;
        __asm__ volatile("" : "+r"(d));
        copy_vec(d, w->q1A40[1]);
    }
    s->fC4 = w->f2270;
    s->pos[1] -= 0.5f;
}

void func_01B02E40(void)
{
    float v[3][4];
    register Ovl09633Work *w __asm__("$3") = D_01B0A270;
    register float *dp __asm__("$4") = D_01B007C0;
    register float *v1 __asm__("$12") = v[1];
    register float *p1950 __asm__("$11") = w->q1950;
    register float *p1970 __asm__("$9") = w->q1970;
    register float *p1990 __asm__("$10") = w->q1990;
    register float *v2 __asm__("$8") = v[2];
    float (*vp)[4] = v;
    int *tp = w->timer;
    int i;

    for (i = 0; i < 3; i++) {
        float t;
        float u;
        if (*tp > 0) {
            (*tp)--;
        }
        t = (float)*tp / *dp;
        u = 1.0f - t;
        (*vp)[0] = w->q1A40[0][0] * u + w->q1A10[0][0] * t;
        (*vp)[1] = w->q1A40[0][1];
        (*vp)[2] = w->q1A40[0][2] * u + w->q1A10[0][2] * t;
        (*vp)[3] = 1.0f;
        dp++;
        tp++;
        w = (Ovl09633Work *)((u8 *)w + 0x10);
        vp++;
    }

    copy_vec(p1950, v[0]);
    copy_vec(p1970, v1);
    copy_vec(p1990, v2);
}
