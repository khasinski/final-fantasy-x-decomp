#include "common.h"
#include "vu0.h"

static inline void copy_vec(void *dst, void *src)
{
    MMI_COPY_LQ_A3(dst, src);
    MMI_COPY_SQ_A3(dst);
}

typedef struct {
    u8 pad00[0xC4];
    float fC4;
    u8 padC8[0x8];
    float pos[4];
    u8 padE0[0x50];
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
    u8 pad8C[0xC];
    u8 b98;
    u8 b99;
    u8 pad9A[0x6];
} ObjA;

typedef struct {
    u8 pad00[0xF0];
    u8 bF0;
    u8 bF1;
    u8 bF2;
    u8 bF3;
    u8 padF4[0x4];
    float fF8;
    float fFC;
    s32 w100;
    u8 pad104[0xC];
    s32 w110;
    u8 pad114[0xC];
    s32 w120;
    s16 h124;
    u8 pad126[0x1A];
} ObjB;

typedef struct {
    Sub130 sub[12];       /* 0x000..0xE40 */
    u8 padE40[0x5F0];
    Sub130 sub2[2];       /* 0x1430..0x1690 */
    u8 pad1690[0x320];
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
    float v1A70[3][4];
    float v1AA0[3][4];
    ObjA objA[2];         /* 0x1AD0, 0x1B70 */
    u8 b1C10[0x40];
    u8 b1C50[0xB0];
    ObjB objB[3];         /* 0x1D00, 0x1E40, 0x1F80 */
    u8 pad20C0[0x230];
    float f22F0;          /* 0x22F0 */
    u8 pad22F4[0xC];
    s32 timer[3];         /* 0x2300 */
    s32 w230C;            /* 0x230C */
} Work9555;

extern float D_01B007C0[];
extern u8 D_01B0AA60[];
extern Work9555 *D_01B0ABE8;

extern void func_01B06580(void *, void *, s32, s32, s32, s32, float);
extern void func_01B069F0(void *, void *);
extern void func_01B073B8(void *, void *, void *);
extern void func_01B09C30(void *, s32);
extern void func_01B09DE8(void *, s32, s32, float, float);
extern void func_01B0A5B8(void *, s32);

void func_01B02FA8(void)
{
    Work9555 *w = D_01B0ABE8;
    u8 *mgr = D_01B0AA60;
    Sub130 *s;
    ObjA *a;
    ObjB *b;

    func_01B069F0(mgr, &w->sub[5]);
    func_01B069F0(mgr, &w->sub[8]);
    func_01B069F0(mgr, &w->sub[7]);
    func_01B069F0(mgr, &w->sub[6]);

    s = &w->sub[1];
    func_01B06580(mgr, s, 1, 6, 0, 0, 0.01f);
    copy_vec(s->pos, w->v19D0);
    s->fC4 = w->f22F0;
    s->pos[1] -= 12.0f;

    a = &w->objA[0];
    a->w88 = 10;
    a->b82 = 0x80;
    a->b81 = 0x80;
    a->b80 = 0x80;
    a->b83 = 0x80;
    a->b98 = 0x48;
    a->b87 = 0;
    a->b86 = 0;
    a->b85 = 0;
    a->b84 = 0;
    a->b99 = 0;
    func_01B09C30(a, 10);

    b = &w->objB[0];
    b->bF0 = 0x80;
    b->bF1 = 0x80;
    b->bF2 = 0x80;
    b->bF3 = 0x40;
    b->h124 = 4;
    b->fF8 = 0.02f;
    b->fFC = 0.01f;
    b->w120 = 0;
    b->w110 = 0;
    b->w100 = 0;
    func_01B0A5B8(b, 50);

    func_01B09DE8(w->b1C50, 20, 10, 0.34f, 1.0f);
}

void func_01B03130(void)
{
    register Work9555 *w __asm__("$18") = D_01B0ABE8;
    Sub130 *s = &w->sub[2];
    ObjA *a;
    ObjB *b;

    func_01B06580(D_01B0AA60, s, 2, 6, 0, 0, 0.012f);
    copy_vec(s->pos, w->v19B0);
    s->fC4 = w->f22F0;
    s->pos[1] -= 10.0f;

    a = &w->objA[0];
    a->w88 = 10;
    a->b82 = 0x80;
    a->b81 = 0x80;
    a->b80 = 0x80;
    a->b83 = 0x80;
    a->b98 = 0x48;
    a->b87 = 0;
    a->b86 = 0;
    a->b85 = 0;
    a->b84 = 0;
    a->b99 = 0;
    func_01B09C30(a, 10);

    b = &w->objB[1];
    b->bF0 = 0x80;
    b->bF1 = 0x80;
    b->bF2 = 0x80;
    b->bF3 = 0x40;
    b->h124 = 4;
    b->fF8 = 0.02f;
    b->fFC = 0.01f;
    b->w120 = 0;
    b->w110 = 0;
    b->w100 = 0;
    func_01B0A5B8(b, 50);

    func_01B09DE8(w->b1C10, 1, 0, 1.0f, 0.34f);
    func_01B09DE8(w->b1C50, 20, 10, 0.34f, 1.0f);
}

void func_01B032B0(void)
{
    register Work9555 *w __asm__("$18") = D_01B0ABE8;
    Sub130 *s = &w->sub[3];
    ObjA *a;
    ObjB *b;

    func_01B06580(D_01B0AA60, s, 3, 6, 0, 0, 0.008f);
    copy_vec(s->pos, w->v19F0);
    s->fC4 = w->f22F0;
    s->pos[1] -= 6.0f;

    a = &w->objA[0];
    a->w88 = 10;
    a->b82 = 0x80;
    a->b81 = 0x80;
    a->b80 = 0x80;
    a->b83 = 0x80;
    a->b98 = 0x48;
    a->b87 = 0;
    a->b86 = 0;
    a->b85 = 0;
    a->b84 = 0;
    a->b99 = 0;
    func_01B09C30(a, 10);

    b = &w->objB[2];
    b->bF0 = 0x80;
    b->bF1 = 0x80;
    b->bF2 = 0x80;
    b->bF3 = 0x40;
    b->h124 = 4;
    b->fF8 = 0.02f;
    b->fFC = 0.01f;
    b->w120 = 0;
    b->w110 = 0;
    b->w100 = 0;
    func_01B0A5B8(b, 50);

    func_01B09DE8(w->b1C10, 1, 0, 1.0f, 0.34f);
    func_01B09DE8(w->b1C50, 20, 10, 0.34f, 1.0f);
}

void func_01B03430(void)
{
    float v00[4];
    float v10[4];
    Work9555 *w = D_01B0ABE8;
    ObjA *a;

    func_01B06580(D_01B0AA60, &w->sub[0], 0, 0, 0, 0, 0.01f);
    copy_vec(w->sub[0].pos, w->v1A60);
    w->sub[0].fC4 = w->f22F0;
    w->sub[0].pos[1] -= 0.5f;

    a = &w->objA[1];
    a->b82 = 0xFF;
    a->b81 = 0xFF;
    a->b80 = 0xFF;
    a->b83 = 0x80;
    a->b87 = 0;
    a->b86 = 0;
    a->b85 = 0;
    a->b84 = 0;
    a->w88 = 0;
    a->b98 = 0x48;
    a->b99 = 0;
    func_01B09C30(a, 0x2D);

    v00[0] = 0.0f;
    v00[1] = w->f22F0;
    v00[2] = 0.0f;
    v00[3] = 0.0f;
    v10[1] = 0.0f;
    v10[3] = 1.0f;

    copy_vec(w->v19B0, w->v1A60);
    v10[0] = -8.5f;
    v10[2] = -0.8f;
    func_01B073B8(v00, w->v19B0, v10);

    copy_vec(w->v19D0, w->v1A60);
    v10[0] = 0.0f;
    v10[2] = 13.0f;
    func_01B073B8(v00, w->v19D0, v10);

    copy_vec(w->v19F0, w->v1A60);
    v10[0] = 8.5f;
    v10[2] = -0.8f;
    func_01B073B8(v00, w->v19F0, v10);
}

void func_01B035C0(void)
{
    float v00[4];
    float v10[4];
    Work9555 *w = D_01B0ABE8;
    Sub130 *s;

    v00[0] = 0.0f;
    v00[1] = w->f22F0;
    v00[2] = 0.0f;
    v00[3] = 0.0f;
    v10[1] = 0.0f;
    v10[3] = 1.0f;

    copy_vec(w->v1A70[0], w->v19B0);
    copy_vec(w->v1AA0[0], w->v1A60);
    v10[0] = -16.5f;
    v10[2] = -20.0f;
    func_01B073B8(v00, w->v1AA0[0], v10);

    copy_vec(w->v1A70[1], w->v19D0);
    copy_vec(w->v1AA0[1], w->v1A60);
    v10[0] = 0.0f;
    v10[2] = -25.0f;
    func_01B073B8(v00, w->v1AA0[1], v10);

    copy_vec(w->v1A70[2], w->v19F0);
    copy_vec(w->v1AA0[2], w->v1A60);
    v10[0] = 16.5f;
    v10[2] = -20.0f;
    func_01B073B8(v00, w->v1AA0[2], v10);

    w->timer[0] = 0x43;
    w->timer[1] = 0x1C;
    w->timer[2] = 0x23;

    s = &w->sub2[0];
    func_01B06580(D_01B0AA60, s, 0xD, 0x13, 0, 0, 0.015f);
    {
        register float *d __asm__("$3") = s->pos;
        __asm__ volatile("" : "+r"(d));
        copy_vec(d, w->v1AA0[0]);
    }
    s->fC4 = w->f22F0;
    s->pos[1] -= 0.5f;

    s = &w->sub2[1];
    func_01B06580(D_01B0AA60, s, 0xD, 0x1B, 0, 0, 0.015f);
    {
        register float *d __asm__("$3") = s->pos;
        __asm__ volatile("" : "+r"(d));
        copy_vec(d, w->v1AA0[1]);
    }
    s->fC4 = w->f22F0;
    s->pos[1] -= 0.5f;
}

void func_01B037B8(void)
{
    float v[3][4];
    register Work9555 *w __asm__("$3") = D_01B0ABE8;
    register float *dp __asm__("$4") = D_01B007C0;
    register float *v1 __asm__("$12") = v[1];
    register float *p19B0 __asm__("$10") = w->v19B0;
    register float *p19D0 __asm__("$11") = w->v19D0;
    register float *p19F0 __asm__("$9") = w->v19F0;
    register float *v2 __asm__("$8") = v[2];
    float (*vp)[4] = v;
    s32 *tp = w->timer;
    s32 i;

    for (i = 0; i < 3; i++) {
        float t;
        float u;
        if (*tp > 0) {
            (*tp)--;
        }
        t = (float)*tp / *dp;
        u = 1.0f - t;
        (*vp)[0] = w->v1AA0[0][0] * u + w->v1A70[0][0] * t;
        (*vp)[1] = w->v1AA0[0][1];
        (*vp)[2] = w->v1AA0[0][2] * u + w->v1A70[0][2] * t;
        (*vp)[3] = 1.0f;
        dp++;
        tp++;
        w = (Work9555 *)((u8 *)w + 0x10);
        vp++;
    }

    copy_vec(p19B0, v[0]);
    copy_vec(p19D0, v1);
    copy_vec(p19F0, v2);
}
