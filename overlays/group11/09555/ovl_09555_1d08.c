#include "common.h"
#include "vu0.h"

static inline void copy_vec(void *dst, void *src)
{
    MMI_COPY_LQ_A3(dst, src);
    MMI_COPY_SQ_A3(dst);
}

typedef struct {
    u8 pad00[0x4];
    s32 w04;
    u8 pad08[0xF];
    u8 b17;
    u8 b18;
    u8 b19;
    u8 pad1A[0xAA];
    void *pC4;
    void *pC8;
    void *pCC;
} Obj1258;

typedef struct {
    u8 pad00[0x60];
    float scale[4];       /* 0x60..0x70 */
    u8 pad70[0x54];
    float fC4;            /* 0xC4 */
    u8 padC8[0x8];
    float pos[4];         /* 0xD0..0xE0 */
    u8 padE0[0x8];
    float fE8;            /* 0xE8 */
    u8 padEC[0x18];
    void *cb104;          /* 0x104 */
    u8 pad108[0x28];      /* total 0x130 */
} Sub130;

typedef struct {
    u8 pad00[0x80];
    u8 b80;
    u8 b81;
    u8 b82;
    u8 b83;
    u8 b84;
    u8 b85;
    u8 b86;
    u8 b87;
    s32 w88;
    u8 pad8C[0x8];
    s32 w94;
    u8 b98;
    u8 b99;
    u8 pad9A[0x6];
} ObjA;

typedef struct {
    u8 pad00[0x210];
    u8 b210;
    u8 b211;
    u8 b212;
    u8 b213;
    u8 pad214[0x8];
    float f21C;
    float f220;
    u8 pad224[0x4];
    s32 w228;
    u8 pad22C[0x4];
} TrailObj;

typedef struct {
    float pos[4];         /* 0x00 */
    float vel[4];         /* 0x10 */
    float acc[4];         /* 0x20 */
    u8 m30[0xC];          /* 0x30 */
    float f3C;            /* 0x3C */
    u8 pad40[0xC];
    s32 w4C;              /* 0x4C */
    s32 w50;              /* 0x50 */
} Spark;

typedef struct {
    u8 pad00[0x2C];
    s32 timer;
} TimerTask;

typedef struct {
    Sub130 sub[13];       /* 0x000..0xF70 (13 * 0x130 = 0xF70) */
    u8 padF70[0x130];     /* 0xF70..0x10A0 */
    Sub130 sub10A0[3];    /* 0x10A0, 0x11D0, 0x1300 */
    u8 pad1430[0x490];    /* 0x1430..0x18C0 */
    u8 m18C0[0x40];
    u8 m1900[0x40];
    u8 m1940[0x40];
    u8 pad1980[0x20];
    float v19A0[4];
    float v19B0[4];
    float v19C0[4];
    float v19D0[4];
    float v19E0[4];
    float v19F0[4];
    float v1A00[4];
    float v1A10[4];
    float v1A20[4];
    float v1A30[4];
    float v1A40[4];
    float v1A50[4];
    float v1A60[4];
    u8 pad1A70[0x60];
    ObjA objA[2];         /* 0x1AD0, 0x1B70 */
    u8 b1C10[0x40];
    u8 b1C50[0xB0];
    u8 pad1D00[0x3C0];
    TrailObj trail;       /* 0x20C0..0x22EC? wait 0x20C0 + 0x228 = 0x22E8! */
    float f22F0;          /* 0x22F0 */
    s32 w22F4;            /* 0x22F4 */
    s32 w22F8;            /* 0x22F8 */
    s32 w22FC;            /* 0x22FC */
} Work9555;

extern Obj1258 D_01B01258;
extern u8 D_01B0AA60[];
extern Work9555 *D_01B0ABE8;
extern u8 D_01B10320[];

extern void func_00103208(s32);
extern void func_00108910(s32, s32, float *);
extern s32 func_00110648(void *, s32);
extern void func_00173650(void *);
extern float func_002B3DB0(float);
extern void *func_002B49A0(void *, s32, s32);
extern void func_002DD128(void *);

extern s32 func_01B03AA8(s32);
extern s32 func_01B03AE0(s32, s32);
extern void func_01B04ED0(s32, void *);
extern void func_01B051F8(s32);
extern void *func_01B05268(s32);
extern void func_01B052A8(s32);
extern void func_01B05420(s32, float);
extern void func_01B05450(s32, void *, void *);
extern void func_01B05A78(s32 *);
extern void func_01B05AB0(s32);
extern void *func_01B06220(void *);
extern void func_01B062A0(void);
extern void func_01B063E8(void *);
extern void func_01B06580(void *, void *, s32, s32, s32, s32, float);
extern void func_01B069F0(void *, void *);
extern void **func_01B06B10(void *, s32);
extern void func_01B073B8(void *, void *, void *);
extern void func_01B07530(void *, float);
extern void func_01B07948(void *, void *);
extern void func_01B07B28(void *, void *, void *);
extern void func_01B07BA8(void *, void *, void *);
extern void func_01B080F8(void);
extern void func_01B09C30(void *, s32);
extern void func_01B09DE8(void *, s32, s32, float, float);
extern Spark *func_01B0A0B8(void);
extern void func_002B2730(s32);

void func_01B01FD0(void);
void func_01B02298(s32 a0, s32 a1, s32 a2);
void func_01B02AE0(float *a0);
void func_01B02B18(Sub130 *a0);
void func_01B02B90(void);

void func_01B01D08(void)
{
    func_00103208(func_01B03AA8(3));
    func_00103208(func_01B03AA8(4));
    func_00103208(func_01B03AA8(5));
    func_01B052A8(0x301A);
    func_01B052A8(0x301B);
    func_01B052A8(0x301C);
    func_01B05AB0(1);
    func_01B080F8();
}

void func_01B01D70(void)
{
    func_01B051F8(0x301A);
    func_01B051F8(0x301B);
    func_01B051F8(0x301C);
}

void func_01B01D98(void)
{
    Work9555 *w = D_01B0ABE8;
    Obj1258 *d = &D_01B01258;
    void *p;

    p = func_01B05268(0x301A);
    d->pC4 = p;
    d->b17 = 0x20;
    func_00110648(p, 0);

    p = func_01B05268(0x301B);
    d->pC8 = p;
    d->b18 = 0x21;
    func_00110648(p, 0);

    p = func_01B05268(0x301C);
    d->pCC = p;
    d->b19 = 0x22;
    func_00110648(p, 0);

    d->w04 += 3;

    func_01B04ED0(3, w->m18C0);
    copy_vec(w->v1A00, w->v19A0);
    {
        register float *dst __asm__("$3") = w->v1A10;
        __asm__ volatile("" : "+r"(dst));
        copy_vec(dst, w->v19B0);
    }
    w->v1A10[1] -= 1.0f;
    func_01B05450(3, w->m18C0, w->v1A00);
    func_01B07530(w->m18C0, 0.0f);
    func_01B05420(3, 0.0001f);

    func_01B04ED0(4, w->m1900);
    copy_vec(w->v1A20, w->v19C0);
    {
        register float *dst __asm__("$3") = w->v1A30;
        __asm__ volatile("" : "+r"(dst));
        copy_vec(dst, w->v19D0);
    }
    w->v1A30[1] -= 1.0f;
    func_01B05450(4, w->m1900, w->v1A20);
    func_01B07530(w->m1900, 0.0f);
    func_01B05420(4, 0.0001f);

    func_01B04ED0(5, w->m1940);
    copy_vec(w->v1A40, w->v19E0);
    {
        register float *dst __asm__("$3") = w->v1A50;
        __asm__ volatile("" : "+r"(dst));
        copy_vec(dst, w->v19F0);
    }
    w->v1A50[1] -= 1.0f;
    func_01B05450(5, w->m1940, w->v1A40);
    func_01B07530(w->m1940, 0.0f);
    func_01B05420(5, 0.0001f);
}

void func_01B01FA0(void)
{
    func_01B09DE8(D_01B0ABE8->b1C10, 0x1E, 0, 1.0f, 1.2f);
}

void func_01B01FD0(void)
{
    func_002B2730(0);
}

void func_01B01FD8(void)
{
    Work9555 *w = D_01B0ABE8;
    Sub130 *s = &w->sub[12];

    func_01B06580(D_01B0AA60, s, 0xC, 0, 0, 0, 0.0055f);
    copy_vec(s->pos, w->v1A60);
    s->cb104 = (void *)func_01B01FD0;
    w->w22F4 = 0x28;
    s->fC4 = w->f22F0;
    s->pos[1] -= 10.0f;
}

void func_01B02078(void)
{
    Work9555 *w = D_01B0ABE8;
    Sub130 *s;
    float t;
    float sc;

    if (w->w22F4 > 0) {
        w->w22F4--;
    }
    t = (float)w->w22F4 / 40.0f;
    sc = (1.0f - t) * 0.0165f + t * 0.0055f;
    s = &w->sub[12];
    __asm__ volatile("" : "+r"(s));
    s->scale[2] = sc;
    s->scale[0] = sc;
    s->scale[1] = sc;
    s->scale[3] = sc;
}

void func_01B020F8(void)
{
    Work9555 *w = D_01B0ABE8;
    ObjA *a = &w->objA[0];

    a->b86 = 0xFF;
    a->b85 = 0xFF;
    a->b84 = 0xFF;
    a->b87 = 0x80;
    a->b98 = 0x48;
    a->b83 = 0;
    a->b82 = 0;
    a->b81 = 0;
    a->b80 = 0;
    a->w88 = 0;
    a->b99 = 0;
    func_01B09C30(a, 0x14);
    a->w94 = 1;

    a = &w->objA[1];
    a->b82 = 0xFF;
    a->b81 = 0xFF;
    a->b80 = 0xFF;
    a->b83 = 0x80;
    a->b98 = 0x48;
    a->b87 = 0;
    a->b86 = 0;
    a->b85 = 0;
    a->b84 = 0;
    a->b99 = 0;
    a->w88 = 0x15;
    func_01B09C30(a, 0x3C);
}

void func_01B021C8(void)
{
    Work9555 *w = D_01B0ABE8;
    ObjA *a = &w->objA[0];

    a->b86 = 0xFF;
    a->b85 = 0xFF;
    a->b84 = 0xFF;
    a->b87 = 0x80;
    a->b98 = 0x48;
    a->b83 = 0;
    a->b82 = 0;
    a->b81 = 0;
    a->b80 = 0;
    a->w88 = 0;
    a->b99 = 0;
    func_01B09C30(a, 0x14);
    a->w94 = 1;

    a = &w->objA[1];
    a->b82 = 0xFF;
    a->b81 = 0xFF;
    a->b80 = 0xFF;
    a->b83 = 0x80;
    a->b98 = 0x48;
    a->b87 = 0;
    a->b86 = 0;
    a->b85 = 0;
    a->b84 = 0;
    a->b99 = 0;
    a->w88 = 0x15;
    func_01B09C30(a, 0x1E);
}

void func_01B02298(s32 a0, s32 a1, s32 a2)
{
    s32 col[4];
    col[0] = a0;
    col[1] = a1;
    col[2] = a2;
    col[3] = 0x80;
    func_00173650(col);
}

void func_01B022C8(void)
{
    Work9555 *w = D_01B0ABE8;
    Sub130 *s = &w->sub[11];

    func_01B06580(D_01B0AA60, s, 0xB, 0, 0, 0, 0.01f);
    copy_vec(s->pos, w->v1A60);
    s->pos[1] -= 5000.0f;
    s->fC4 = w->f22F0;
}

void func_01B02358(void)
{
    Work9555 *w = D_01B0ABE8;

    w->sub[12].cb104 = 0;
    copy_vec(w->sub[11].pos, w->v1A60);
    func_01B02298(0x40, 0x50, 0x80);
}

void func_01B02388(void)
{
    s32 col[4];
    Work9555 *w = D_01B0ABE8;
    Sub130 *s = &w->sub[10];

    func_01B069F0(D_01B0AA60, &w->sub[11]);
    func_01B06580(D_01B0AA60, s, 0xA, 0, 0, 0, 0.01f);
    copy_vec(s->pos, w->v1A60);
    s->pos[1] -= 100.0f;
    s->fC4 = w->f22F0;
    func_01B05A78(col);
    func_01B02298(col[0], col[1], col[2]);
    func_01B09DE8(w->b1C50, 0x1E, 0, 0.0f, 0.34f);
}

void func_01B02460(void)
{
    Work9555 *w = D_01B0ABE8;
    Sub130 *s = &w->sub[9];
    float ang;

    func_01B069F0(D_01B0AA60, &w->sub[10]);
    func_01B06580(D_01B0AA60, s, 9, 0, 0, 0, 0.008f);
    copy_vec(s->pos, w->v1A60);
    ang = w->f22F0 + 3.1415927f;
    if (ang > 3.1415927f) {
        ang -= 6.2831855f;
    } else if (ang < -3.1415927f) {
        ang += 6.2831855f;
    }
    s->fC4 = ang;
    s->fE8 = -5.0f;
    s->pos[1] -= 0.5f;
}

void func_01B02568(void)
{
    float v00[4];
    float v10[4];
    Work9555 *w = D_01B0ABE8;
    Sub130 *s;
    float ang;

    v00[0] = 0.0f;
    v00[1] = w->f22F0;
    v00[2] = 0.0f;
    v00[3] = 0.0f;
    v10[1] = 0.0f;
    v10[3] = 1.0f;

    s = &w->sub[8];
    func_01B06580(D_01B0AA60, s, 8, 0, 0, 0, 0.013f);
    copy_vec(s->pos, w->v1A60);
    v10[0] = -16.5f;
    v10[2] = -0.8f;
    func_01B073B8(v00, s->pos, v10);
    copy_vec(w->v19B0, s->pos);
    ang = w->f22F0 - 0.7853982f;
    if (ang > 3.1415927f) {
        ang -= 6.2831855f;
    } else if (ang < -3.1415927f) {
        ang += 6.2831855f;
    }
    s->fC4 = ang;
    s->pos[1] -= 0.5f;

    s = &w->sub[7];
    func_01B06580(D_01B0AA60, s, 7, 0, 0, 0, 0.013f);
    copy_vec(s->pos, w->v1A60);
    v10[0] = 0.0f;
    v10[2] = 15.5f;
    func_01B073B8(v00, s->pos, v10);
    copy_vec(w->v19D0, s->pos);
    s->fC4 = w->f22F0;
    s->pos[1] -= 0.5f;

    s = &w->sub[6];
    func_01B06580(D_01B0AA60, s, 6, 0, 0, 0, 0.013f);
    copy_vec(s->pos, w->v1A60);
    v10[0] = 16.5f;
    v10[2] = -0.8f;
    func_01B073B8(v00, s->pos, v10);
    copy_vec(w->v19F0, s->pos);
    ang = w->f22F0 + 0.7853982f;
    if (ang > 3.1415927f) {
        ang -= 6.2831855f;
    } else if (ang < -3.1415927f) {
        ang += 6.2831855f;
    }
    s->fC4 = ang;
    s->pos[1] -= 0.5f;
}

void func_01B02858(TimerTask *task)
{
    Work9555 *w = D_01B0ABE8;
    float t;
    float u;

    if (task->timer > 0) {
        task->timer--;
    }
    t = (float)task->timer / 20.0f;
    func_01B05450(3, w->m18C0, w->v1A00);
    u = 1.0f - t;
    func_01B07530(w->m18C0, u * 2.2f + t * 0.0f);
    func_01B05420(3, u * 2.2f + t * 0.0001f);

    func_01B05450(4, w->m1900, w->v1A20);
    func_01B07530(w->m1900, u * 2.0f + t * 0.0f);
    func_01B05420(4, u * 2.0f + t * 0.0001f);

    func_01B05450(5, w->m1940, w->v1A40);
    func_01B07530(w->m1940, u * 2.0f + t * 0.0f);
    func_01B05420(5, u * 2.0f + t * 0.0001f);
}

void func_01B029A8(void)
{
    Work9555 *w = D_01B0ABE8;
    Sub130 *s;

    s = &w->sub10A0[0];
    func_01B06580(D_01B0AA60, s, 4, 0, 0, 0, 0.007f);
    copy_vec(s->pos, w->v19B0);
    s->fC4 = w->f22F0;
    s->pos[1] -= 0.5f;

    s = &w->sub10A0[1];
    func_01B06580(D_01B0AA60, s, 4, 0, 0, 0, 0.007f);
    copy_vec(s->pos, w->v19D0);
    s->fC4 = w->f22F0;
    s->pos[1] -= 0.5f;

    s = &w->sub10A0[2];
    func_01B06580(D_01B0AA60, s, 4, 0, 0, 0, 0.007f);
    copy_vec(s->pos, w->v19F0);
    s->fC4 = w->f22F0;
    s->pos[1] -= 0.5f;
}

void func_01B02AE0(float *a0)
{
    func_00108910(func_01B03AE0(0, 0), 0xE, a0);
}

void func_01B02B18(Sub130 *a0)
{
    func_01B02AE0(a0->pos);
}

void func_01B02B20(void)
{
    Work9555 *w = D_01B0ABE8;
    Sub130 *s = &w->sub[5];

    func_01B06580(D_01B0AA60, s, 5, 0, 0, 0, 0.007f);
    s->fC4 = w->f22F0;
    s->cb104 = (void *)func_01B02B18;
}

void func_01B02B90(void)
{
    float mat[4][4];
    float pos[4];
    Work9555 *w = D_01B0ABE8;
    Spark *sp;
    s32 i;

    if (w->w22F8 > 0) {
        w->w22F8--;
        if (w->w22F8 > 0) {
            goto run;
        }
    }
    if (w->trail.w228 <= 8) {
        func_01B062A0();
        return;
    }
    w->trail.w228 -= 8;

run:
    func_002DD128(mat);
    mat[2][2] = 0.04f;
    mat[1][1] = 0.04f;
    mat[0][0] = 0.04f;
    func_01B02AE0(pos);
    func_01B07BA8(&w->trail, mat, pos);
    if (w->w22FC > 0) {
        w->w22FC--;
        for (i = 0; i < 2; i++) {
            sp = func_01B0A0B8();
            if (sp == 0) {
                return;
            }
            func_01B07948(sp->m30, *func_01B06B10(D_01B0AA60, 2));
            copy_vec(sp->pos, pos);
            sp->pos[0] += func_002B3DB0(1.0f);
            sp->pos[1] += func_002B3DB0(1.0f);
            sp->pos[2] += func_002B3DB0(1.0f);
            sp->vel[0] = func_002B3DB0(0.1f);
            sp->vel[1] = func_002B3DB0(0.05f) + 0.2f;
            sp->vel[2] = func_002B3DB0(0.1f);
            sp->vel[3] = 0.0f;
            sp->acc[0] = -sp->vel[0] * 0.01f;
            sp->acc[1] = sp->vel[1] * 0.01f;
            sp->acc[2] = -sp->vel[2] * 0.01f;
            sp->acc[3] = 1.0f;
            sp->f3C = (func_002B3DB0(0.2f) + 1.0f) * 0.015f;
            sp->w50 = 0;
            sp->w4C = 0x11;
        }
        if (w->w22FC >= 9) {
            for (i = 0; i < 2; i++) {
                sp = func_01B0A0B8();
                if (sp == 0) {
                    return;
                }
                func_01B07948(sp->m30, func_002B49A0(D_01B10320, 9, 0));
                copy_vec(sp->pos, pos);
                sp->pos[0] += func_002B3DB0(1.0f);
                sp->pos[1] += func_002B3DB0(1.0f);
                sp->pos[2] += func_002B3DB0(1.0f);
                sp->vel[0] = func_002B3DB0(0.1f);
                sp->vel[1] = func_002B3DB0(0.05f) + 0.2f;
                sp->vel[2] = func_002B3DB0(0.1f);
                sp->vel[3] = 0.0f;
                sp->acc[0] = -sp->vel[0] * 0.01f;
                sp->acc[1] = sp->vel[1] * 0.01f;
                sp->acc[2] = -sp->vel[2] * 0.01f;
                sp->acc[3] = 1.0f;
                sp->f3C = (func_002B3DB0(0.2f) + 1.0f) * 0.015f;
                sp->w50 = 0;
                sp->w4C = 0x1C;
            }
        }
    }
}
