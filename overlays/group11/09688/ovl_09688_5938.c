#include "common.h"
#include "vu0.h"

static inline void copy_vec(void *dst, void *src)
{
    MMI_COPY_LQ_A3(dst, src);
    MMI_COPY_SQ_A3(dst);
}

typedef struct S5938Work {
    u8 pad00[0xC0];
    float fC0;
    float fC4;
    u8 padC8[8];
    u_long128 qD0;
    u8 padE0[4];
    float fE4;
    float fE8;
    u8 padEC[0x18];
    void *p104;
} S5938Work; /* size 0x110 */

typedef struct S5938Sub {
    u8 pad00[0xC0];
    u_long128 qC0;
    u_long128 qD0;
    u8 padE0[0x50];
    S5938Work w130;
    u8 pad240[0x20];
    float v260[4];
    float v270[4];
    u_long128 q280;
    u8 pad290[0x280];
    s32 s510;
    s32 s514;
    s32 s518;
    u8 pad51C[4];
} S5938Sub; /* size 0x520 */

typedef struct S5938List {
    u32 u00;
    s32 count;
    u8 arr[1];
} S5938List;

typedef struct S5938Task {
    u8 pad00[0x14];
    S5938Sub *sub;
    u8 pad18[0x3E];
    u8 b56;
} S5938Task;

extern u8 *D_01B0DCA8;
extern u8 D_01B0DBE0[];
extern u8 D_01B17B30[];
extern u8 D_01BFC030[];

void func_01B0A0B8(void *a0, void *a1);
void func_01B09C48(void *a0, void *a1, s32 a2, s32 a3, s32 t0, s32 t1, float f12);
void func_01B06F08(void);
void func_01B066A0(void *a0);
void func_01B06CD8(void *a0, void *a1, s32 a2);
void *func_01B070D8(u32 a0);
void func_01B08688(void *a0, s32 a1);
void func_01B095D8(void *a0, s32 a1, s32 a2);
void func_01B09338(void *a0, s32 a1, void *a2, s32 a3);
void func_01B09968(void *a0);
void func_01B07970(void *a0);
void func_01B0ABF8(void *a0, void *a1, void *a2);
void func_01B0AAF0(void *a0, void *a1, void *a2);
float func_01B0AC98(void *a0, void *a1);
S5938Task *func_01B098E8(void *fn);
void func_01B09AB0(S5938Task *t);
void func_01B066E8(void);
void *func_01B06578(void);
float func_002B3DB0(float f);
void func_00110540(void *a0, s32 a1, float f12);

void func_01B05938(void)
{
    func_01B0A0B8(D_01B0DBE0, D_01B0DCA8 + 0x11D0);
}

void func_01B05950(void)
{
    register u8 *base __asm__("$18") = D_01B0DCA8;
    register u8 *dbe0 __asm__("$17") = D_01B0DBE0;
    S5938Work *w = (S5938Work *)(base + 0x5F0);
    register u8 *b8000 __asm__("$16");

    func_01B09C48(dbe0, w, 5, 0, 0, 0, 0.4f);
    copy_vec(base + 0x6C0, base + 0x2E50);
    {
        register u32 off __asm__("$16") = 0x8000;
        register float fneg5 __asm__("$f1") = -5.0f;
        register float f008 __asm__("$f12");
        float y;
        __asm__ volatile("" : "+r"(off), "+f"(fneg5));
        b8000 = base + off;
        __asm__ volatile("" : "+r"(b8000));
        f008 = 0.08f;
        __asm__ volatile("" : "+f"(f008));
        y = *(float *)(b8000 + 0x6AD0);
        w->fE8 = fneg5;
        w->fC4 = y;
        w = (S5938Work *)(base + 0x2600);
        func_01B09C48(dbe0, w, 32, 0, 0, 0, f008);
    }
    w->fC4 = *(float *)(b8000 + 0x6AD0);
    w->p104 = (void *)func_01B06F08;
}

void func_01B05A30(void)
{
    u8 *base = D_01B0DCA8;
    S5938Work *w = (S5938Work *)(base + 0x1300);

    func_01B09C48(D_01B0DBE0, w, 16, 0, 0, 0, 0.2f);
    copy_vec(base + 0x13D0, base + 0x2E50);
    w->fC4 = *(float *)(base + 0xEAD0);
    w->fE8 = -18.0f;
    *(float *)((u8 *)w + 0xD4) += 5.0f;
}

void func_01B05AD0(void)
{
    register u8 *base __asm__("$16") = D_01B0DCA8;
    S5938Work *w = (S5938Work *)(base + 0x260);

    func_01B09C48(D_01B0DBE0, w, 2, 0, 0, 0, 0.1f);
    func_01B066A0(base + 0x330);
    {
        register float f2 __asm__("$f2") = 0.031415928f;
        register float f1 __asm__("$f1");
        __asm__ volatile("" : "+f"(f2));
        base += 0x8000;
        __asm__ volatile("" : "+r"(base));
        f1 = 4.0f;
        __asm__ volatile("" : "+f"(f1));
        w->fC0 = f2;
        w->fC4 = *(float *)(base + 0x6AD0);
        w->fE4 = f1;
    }
}

void func_01B05B60(S5938Task *task)
{
    float tmp[4];
    S5938Sub *sub = task->sub;
    u8 *base = D_01B0DCA8;
    u8 *arr_base = base + 0xD640;
    s32 rem;
    float t;
    float omt;
    s32 i;
    register void *qD0 __asm__("$16");

    rem = sub->s510;
    if (rem > 0) {
        rem--;
        sub->s510 = rem;
    }

    t = (float)rem / (float)sub->s514;
    omt = 1.0f - t;
    for (i = 0; i < 3; i++) {
        tmp[i] = sub->v270[i] * omt + sub->v260[i] * t;
    }
    tmp[3] = 1.0f;
    {
        register void *q280 __asm__("$4") = &sub->q280;
        __asm__("" : "+r"(q280));
        qD0 = &sub->qD0;
        func_01B06CD8(q280, tmp, 128);
    }
    __asm__ volatile("lq $7, 0(%0)" : : "r"(tmp) : "$7", "memory");
    __asm__ volatile("sq $7, 0(%0)" : : "r"(qD0) : "memory");

    if (sub->s510 <= 0) {
        S5938Work *w;
        if (sub->s518 == 0) {
            for (i = 0; i < (*(S5938List **)(base + 0xEB74))->count; i++) {
                func_01B08688(func_01B070D8((*(S5938List **)(base + 0xEB74))->arr[i]), 0);
            }
            func_01B095D8(D_01B17B30, 1, 2);
            func_01B09338(D_01BFC030, 18, sub->v270, 256);
        }
        w = &sub->w130;
        func_01B09C48(D_01B0DBE0, w, 4, 0, 0, 0, 0.4f);
        __asm__ volatile("lq $7, 0(%0)" : : "r"(sub->v270) : "$7", "memory");
        __asm__ volatile("sq $7, 0(%0)" : : "r"(&w->qD0) : "memory");
        w->fC4 = *(float *)(base + 0xEAD0);
        *(float *)((u8 *)w + 0xD4) -= 0.5f;
        func_01B0A0B8(D_01B0DBE0, sub);
        {
            register u8 *ab __asm__("$2") = arr_base;
            __asm__("" : "+r"(ab));
            *(s32 *)(ab + 0x1484) += 1;
        }
        func_01B09968(task);
    }
}

void func_01B05DC0(void)
{
    float v0[4];
    float v1[4];
    float v2[4];
    float v3[4];
    u8 *base = D_01B0DCA8;
    S5938Sub *sub = (S5938Sub *)(base + 0xD640);
    S5938Sub *sub0 = sub;
    s32 i;

    func_01B066A0(v0);
    v2[0] = 0.0f;
    v2[1] = *(float *)(base + 0xEAD0);
    v2[2] = 0.0f;
    v2[3] = 0.0f;
    v3[3] = 1.0f;
    func_01B07970(v1);

    for (i = 0; i < 3; i++, sub++) {
        __asm__ volatile("lq $7, 0(%0)" : : "r"(v0) : "$7", "memory");
        __asm__ volatile("sq $7, 0(%0)" : : "r"(sub->v260) : "memory");
        __asm__ volatile("lq $7, 0(%0)" : : "r"(v1) : "$7", "memory");
        __asm__ volatile("sq $7, 0(%0)" : : "r"(sub->v270) : "memory");
        switch (i) {
        case 0:
            v3[0] = 0.0f;
            v3[1] = -15.0f;
            v3[2] = 0.0f;
            break;
        case 1:
            v3[0] = 40.0f;
            v3[1] = 10.0f;
            v3[2] = func_002B3DB0(15.0f);
            break;
        case 2:
            v3[0] = -40.0f;
            v3[1] = 10.0f;
            v3[2] = func_002B3DB0(15.0f);
            break;
        }
        func_01B0ABF8(v2, sub->v270, v3);
        func_01B0AAF0(&sub->q280, sub->v260, sub->v270);
        sub->s510 = (s32)(func_01B0AC98(sub->v260, sub->v270) / 10.0f);
        if (sub->s510 < 0) {
            sub->s510 = 1;
        }
        if (i == 0) {
            sub->s510 += 2;
        }
        sub->s514 = sub->s510;
        func_01B09C48(D_01B0DBE0, sub, 3, 0, 0, 0, 0.08f);
        {
            register void *dst __asm__("$3") = &sub->qC0;
            __asm__ volatile("lq $7, 0(%0)" : : "r"(&sub->q280) : "$7", "memory");
            __asm__ volatile("sq $7, 0(%0)" : : "r"(dst) : "memory");
        }
        sub->s518 = i;
        {
            S5938Task *t = func_01B098E8(func_01B05B60);
            t->sub = sub;
            func_01B09AB0(t);
        }
    }

    *(s32 *)((u8 *)sub0 + 0x1484) = 0;
    *(s32 *)((u8 *)sub0 + 0x1480) = 3;
    func_01B0A0B8(D_01B0DBE0, base + 0x2600);
    func_01B066E8();
    func_00110540(func_01B06578(), 1, 0.0f);
}

void func_01B06040(S5938Task *task)
{
    u8 *arr_base = D_01B0DCA8 + 0xD640;

    if (*(s32 *)(arr_base + 0x1480) == *(s32 *)(arr_base + 0x1484)) {
        *(s32 *)(arr_base + 0x1488) = 1;
        task->b56 = 1;
    }
}
