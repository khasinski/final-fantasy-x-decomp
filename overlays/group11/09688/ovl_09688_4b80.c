#include "common.h"
#include "vu0.h"

static inline void copy_vec(void *dst, void *src)
{
    MMI_COPY_LQ_A3(dst, src);
    MMI_COPY_SQ_A3(dst);
}

#define COPY_VEC(dst, src) do { MMI_COPY_LQ_A3(dst, src); MMI_COPY_SQ_A3(dst); } while (0)

static inline void wrap_angle(float *dst, float delta)
{
    float a = *dst + delta;
    if (a > 3.1415927f) {
        a -= 6.2831855f;
    } else if (a < -3.1415927f) {
        a += 6.2831855f;
    }
    *dst = a;
}

typedef struct S4b80Work {
    u8 pad00[0xC0];
    float fC0;
    float fC4;
    u8 padC8[8];
    u_long128 qD0;
    u8 padE0[0x40];
    u8 *p120;
} S4b80Work; /* size 0x130 */

typedef struct S4b80Sub {
    u8 pad00[0xC0];
    u_long128 qC0;
    u_long128 qD0;
    u8 padE0[0x50];
    S4b80Work w130;
    float v260[4];
    float v270[4];
    float v280[4];
    float v290[4];
    float v2A0[4];
    float v2B0[4];
    u8 pad2C0[0x250];
    s32 s510;
    s32 s514;
    s32 s518;
    s32 s51C;
} S4b80Sub; /* size 0x520 */

typedef struct S4b80List {
    u32 u00;
    s32 count;
    u8 arr[1];
} S4b80List;

typedef struct S4b80TaskVtbl {
    u8 pad00[0x10];
    void *fn10;
} S4b80TaskVtbl;

typedef struct S4b80Task {
    u8 pad00[8];
    S4b80TaskVtbl *p08;
    u8 pad0C[8];
    S4b80Sub *sub;
    u8 pad18[0x3E];
    u8 b56;
} S4b80Task;

extern u8 *D_01B0DCA8;
extern u8 D_01B0DBE0[];
extern u8 D_01B17B30[];
extern u8 D_01BFC030[];
extern s32 D_01B00DB0[];
extern float D_01B00DC8[];
extern u8 D_01B0DC88[];
extern u8 D_01B00FB8[];

void func_01B066A0(void *a0);
void func_01B07328(u32 a0, void *a1, s32 a2);
void func_01B0AAF0(void *a0, void *a1, void *a2);
float func_01B0AC98(void *a0, void *a1);
void func_01B04B40(void *a0, s32 a1);
void func_01B04A10(void);
S4b80Task *func_01B098E8(void *fn);
void func_01B09AB0(S4b80Task *t);
void func_01B0A0B8(void *a0, void *a1);
void func_01B066E8(void);
void *func_01B06578(void);
void func_00110540(void *a0, s32 a1, float f12);
void func_01B09C48(void *a0, void *a1, s32 a2, s32 a3, s32 t0, void *t1, float f12);
void *func_01B070D8(s32 a0);
s32 func_001C00A0(void *a0);
void func_01B0A208(void);
void func_01B095D8(void *a0, s32 a1, s32 a2);
void func_01B09338(void *a0, s32 a1, void *a2, s32 a3);
void func_01B06CD8(void *a0, void *a1, s32 a2);
void func_01B09968(void *a0);
void func_01B08D10(s32 a0, void *a1, void *a2);
void func_01B06710(void);
float func_01B0A8A8(float f0, float f1, float f2, float f3);
void func_01B07828(s32 a0, s32 a1, void *a2);
void func_01B0D470(void *a0, s32 a1);
float func_002B3DB0(float f);
float func_002B3DF8(float f);
void func_01B0ABF8(void *a0, void *a1, void *a2);

void func_01B04EE8(S4b80Task *task);
void func_01B050A0(S4b80Task *task);

void func_01B04B80(void)
{
    float v0[4];
    u8 *base = D_01B0DCA8;
    u8 *arr_base = base + 0x5B00;
    S4b80Sub *sub = (S4b80Sub *)arr_base;
    s32 cnt;
    s32 i;

    cnt = (*(S4b80List **)(base + 0xEB74))->count;
    func_01B066A0(v0);
    for (i = 0; i < cnt; i++, sub++) {
        u8 id = (*(S4b80List **)(base + 0xEB74))->arr[i];
        copy_vec(sub->v260, v0);
        func_01B07328(id, sub->v270, 4);
        func_01B0AAF0(sub->v280, sub->v260, sub->v270);
        sub->s510 = (s32)(func_01B0AC98(sub->v260, sub->v270) * 0.125f);
        if (sub->s510 < 0) {
            sub->s510 = 1;
        }
        sub->s514 = sub->s510;
        func_01B04B40(sub, *(s32 *)(arr_base + 0x2904));
        copy_vec(&sub->qC0, sub->v280);
        sub->s51C = i;
        sub->s518 = id;
        {
            S4b80Task *t = func_01B098E8(func_01B04A10);
            t->sub = sub;
            func_01B09AB0(t);
        }
    }
    *(s32 *)(arr_base + 0x2908) = cnt;
    *(s32 *)(arr_base + 0x290C) = 0;
    func_01B0A0B8(D_01B0DBE0, *(void **)(arr_base + 0x2900));
    func_01B066E8();
    func_00110540(func_01B06578(), 1, 0.0f);
}

void func_01B04D18(S4b80Task *task)
{
    u8 *arr_base = D_01B0DCA8 + 0x5B00;

    if (*(s32 *)(arr_base + 0x2908) == *(s32 *)(arr_base + 0x290C)) {
        *(s32 *)(arr_base + 0x2910) = 1;
        task->b56 = 1;
    }
}

void func_01B04D48(void)
{
    u8 *base = D_01B0DCA8;
    S4b80Work *w = (S4b80Work *)(base + 0x11D0);

    func_01B09C48(D_01B0DBE0, w, 15, 0, 0, 0, 0.5f);
    {
        register void *dst __asm__("$4") = &w->qD0;
        COPY_VEC(dst, base + 0x2E50);
    }
    {
        register u32 off __asm__("$3") = 0x8000;
        u8 *hi;
        __asm__("" : "+r"(off));
        hi = base + off;
        *(s32 *)(hi + 0x5628) = 0;
        w->fC4 = *(float *)(hi + 0x6AD0);
    }
}

void func_01B04DC8(S4b80Sub *sub, float *ang)
{
    S4b80Work *w = &sub->w130;
    s32 idx;
    s32 id;

    idx = func_001C00A0(func_01B070D8(-1)) - 16425;
    func_01B09C48(D_01B0DBE0, w, D_01B00DB0[idx], 0, 0, func_01B0A208, D_01B00DC8[idx]);
    copy_vec(&w->qD0, sub->v270);
    w->fC0 = ang[0];
    w->fC4 = ang[1];
    {
        register u8 *p120 __asm__("$2") = func_01B070D8(sub->s518);
        register u8 *base __asm__("$2");
        register u32 off __asm__("$3");
        register s32 flag __asm__("$4");
        __asm__("" : "+r"(p120) : : "$3");
        w->p120 = p120;
        base = D_01B0DCA8;
        __asm__ volatile("" : "+r"(base));
        off = 0x8000;
        __asm__("" : "+r"(off));
        flag = *(s32 *)(base + off + 0x5628);
        __asm__("" : "+r"(flag));
        if (flag == 0) {
            id = 13;
            func_01B095D8(D_01B17B30, 1, 0);
        } else {
            id = 11;
            func_01B095D8(D_01B17B30, 1, 1);
        }
    }
    func_01B09338(D_01BFC030, id, &w->qD0, 256);
}

void func_01B04EE8(S4b80Task *task)
{
    float tmp[4];
    S4b80Sub *sub = task->sub;
    u8 *arr_base = D_01B0DCA8 + 0x8420;
    float a;
    s32 alpha;

    if (sub->s510 > 0) {
        sub->s510--;
    }
    {
        float *pos = sub->v260;
        float y;
        float *vel;
        COPY_VEC(tmp, pos);
        y = sub->v2A0[1];
        __asm__ volatile("" : "+f"(y));
        vel = sub->v2A0;
        __asm__ volatile("" : "+r"(vel));
        sub->v2A0[1] = y + 0.05f;
        VU0_LQC2(1, 0, pos);
        VU0_LQC2(2, 0, vel);
        VU0_OP("vadd.xyz $vf1, $vf1, $vf2");
        VU0_SQC2(1, 0, pos);
    }

    wrap_angle(&sub->v280[0], sub->v290[0]);
    wrap_angle(&sub->v280[1], sub->v290[2]);

    alpha = 128;
    if (sub->s510 < 20) {
        alpha = (sub->s510 * 128) / 20;
    }
    func_01B06CD8(sub->v280, sub->v260, alpha);
    if (sub->s510 <= 0) {
        *(s32 *)(arr_base + 0x5210) += 1;
        func_01B09968(task);
    }
}

void func_01B050A0(S4b80Task *task)
{
    float tmp[4];
    S4b80Sub *sub = task->sub;
    u8 *arr_base = D_01B0DCA8 + 0x8420;
    float t;
    float omt;
    s32 i;

    if (sub->s510 > 0) {
        sub->s510--;
        if (sub->s510 == 8) {
            func_01B08D10(-1, D_01B0DC88, D_01B00FB8);
            *(s32 *)(arr_base + 0x5200) = 39;
        }
        if (sub->s510 == 0) {
            func_01B06710();
        }
    }

    t = (float)sub->s510 / (float)sub->s514;
    omt = 1.0f - t;
    for (i = 0; i < 3; i++) {
        tmp[i] = sub->v260[i] * omt + sub->v270[i] * t;
    }
    tmp[1] = func_01B0A8A8(sub->v260[1], sub->v260[1] - 15.0f, sub->v270[1], t);
    tmp[3] = 1.0f;

    if (sub->s510 <= 0) {
        *(s32 *)(arr_base + 0x5200) -= 1;
        func_01B07828(-1, 5, tmp);
    }
    if (sub->s510 > 0) {
        func_01B06CD8(sub->v280, tmp, 128);
    }
    if (sub->s510 <= 0 && *(s32 *)(arr_base + 0x5200) <= 0) {
        *(s32 *)(arr_base + 0x5210) += 1;
        func_01B09968(task);
    }
}

void func_01B05230(S4b80Task *task)
{
    float tmp[4];
    float v1[4];
    float v2[4];
    S4b80Sub *sub = task->sub;
    u8 *base = D_01B0DCA8;
    u8 *arr_base = base + 0x8420;
    s32 rem;
    float t;
    float omt;
    s32 i;

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
    func_01B06CD8(sub->v280, tmp, 128);

    if (sub->s510 <= 0) {
        func_01B04DC8(sub, sub->v280);
        if (*(s32 *)(arr_base + 0x5208) == 1) {
            u8 *p = base + 0x2E60;
            s32 next_t;
            p[0x98] = 72;
            p[0x83] = 128;
            p[0x82] = 128;
            p[0x81] = 128;
            p[0x80] = 128;
            p[0x84] = 128;
            p[0x85] = 128;
            p[0x86] = 128;
            p[0x87] = 0;
            *(u32 *)(p + 0x88) = 0;
            p[0x99] = 0;
            func_01B0D470(p, 20);
            next_t = sub->s514 + 8;
            sub->s514 = next_t;
            sub->s510 = next_t;
            func_01B07828(-1, 11, sub->v260);
            task->p08->fn10 = (void *)func_01B050A0;
        } else {
            register float r __asm__("$f3");
            float *v2a0;
            float *v2b0;
            __asm__ volatile("lq $7, 0(%0)" : : "r"(tmp) : "$7", "memory");
            __asm__ volatile("sq $7, 0(%0)" : : "r"(sub->v260) : "memory");
            v2a0 = sub->v2A0;
            __asm__ volatile("" : "+r"(v2a0));
            v2[0] = 0.0f;
            v2[1] = 0.0f;
            v2[2] = 0.0f;
            v2[3] = 1.0f;
            __asm__ volatile("lq $7, 0(%0)" : : "r"(v2) : "$7", "memory");
            __asm__ volatile("sq $7, 0(%0)" : : "r"(v2a0) : "memory");
            tmp[0] = func_002B3DB0(0.5f);
            tmp[1] = -(func_002B3DB0(0.5f) + 1.0f);
            r = func_002B3DB0(0.05f) + 0.05f;
            __asm__("" : "+f"(r));
            if (r < 0.025f && r > -0.025f) {
                r = 0.05f;
            }
            {
                register float c10 __asm__("$f0") = 10.0f;
                register float *p0 __asm__("$4");
                register float *p1 __asm__("$5");
                register float *p2 __asm__("$6");
                float one;
                float prod;
                __asm__ volatile("" : "+f"(c10));
                p0 = sub->v280;
                __asm__ volatile("" : "+r"(p0));
                one = 1.0f;
                __asm__ volatile("" : "+f"(one));
                p1 = v2a0;
                __asm__ volatile("" : "+r"(p1));
                prod = r * c10;
                p2 = tmp;
                __asm__ volatile("" : "+f"(prod), "+r"(p2));
                tmp[3] = one;
                __asm__ volatile("" : : : "memory");
                tmp[2] = -prod;
                func_01B0ABF8(p0, p1, p2);
                func_01B0AAF0(v1, v2, tmp);
                {
                    float nz = -0.7f;
                    __asm__ volatile("" : "+f"(nz));
                    v2b0 = sub->v2B0;
                    __asm__ volatile("" : "+r"(v2b0));
                    tmp[3] = one;
                    __asm__ volatile("" : : : "memory");
                    tmp[2] = nz;
                    tmp[0] = 0.0f;
                    tmp[1] = 0.0f;
                }
            }
            __asm__ volatile("lq $7, 0(%0)" : : "r"(v2) : "$7", "memory");
            __asm__ volatile("sq $7, 0(%0)" : : "r"(v2b0) : "memory");
            func_01B0ABF8(v1, v2b0, tmp);
            __asm__ volatile("lq $7, 0(%0)" : : "r"(v2a0) : "$7", "memory");
            __asm__ volatile("sq $7, 0(%0)" : : "r"(sub->v270) : "memory");
            {
                register u32 len_bits __asm__("$7");
                float len;
                VU0_LQC2(1, 0, v2a0);
                VU0_OP("vmul.xyz $vf1, $vf1, $vf1");
                VU0_OP("vaddy.x $vf1x, $vf1x, $vf1y");
                VU0_OP("vaddz.x $vf1x, $vf1x, $vf1z");
                VU0_OP("vsqrt Q, $vf1x");
                VU0_OP("vwaitq");
                VU0_OP("vaddq.x $vf1x, $vf0x, Q");
                VU0_QMFC2(len_bits, 1);
                __asm__ volatile("mtc1 %1, %0" : "=f"(len) : "r"(len_bits));
                sub->v270[3] = len;
            }
            sub->v290[0] = (func_002B3DB0(0.1f) + 0.05f) * 3.1415927f;
            sub->v290[1] = -(func_002B3DF8(0.1f) + 0.05f) * 3.1415927f;
            sub->v290[2] = 0.0f;
            sub->s510 = 40;
            task->p08->fn10 = (void *)func_01B04EE8;
        }
    }
}

void func_01B05598(void)
{
    u8 *base = D_01B0DCA8;
    u8 *arr_base = base + 0x8420;

    if (*(s32 *)(arr_base + 0x5208) == 1) {
        func_01B066E8();
        *(s32 *)(arr_base + 0x5200) = 0;
    } else {
        *(s32 *)(arr_base + 0x5200) = 0;
    }
    *(s32 *)(arr_base + 0x5204) = 0;
    *(s32 *)(arr_base + 0x520C) = (*(S4b80List **)(base + 0xEB74))->count;
    *(s32 *)(arr_base + 0x5210) = 0;
}
