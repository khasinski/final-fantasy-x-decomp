#include "common.h"

typedef union {
    float f[4];
    u_long128 q;
} QVec;

typedef struct {
    u8 pad00[0xC4];
    float fC4;
    u8 padC8[0x8];
    QVec vD0;
    u8 padE0[0x24];
    void *p104;
    u8 pad108[0x8];
    void *p110;
    u8 pad114[0xC];
    s32 w120;
    u8 pad124[0xC];
} Elem130;

typedef struct {
    u8 pad00[0xC4];
    float fC4;
    u8 padC8[0x8];
    QVec vD0;
    u8 padE0[0x280];
    QVec v360;
    QVec v370;
    u8 pad380[0x4];
    void *p384;
    s32 w388;
    u8 pad38C[0x8];
    s32 w394;
    u8 pad398[0x4];
    s16 h39C;
    u8 pad39E[0x2];
} Elem3A0;

typedef struct {
    u8 pad000[0x5F0];
    Elem130 arr5F0[9];
    u8 pad10A0[0x10];
    Elem3A0 arr10B0[9];
} Work8868;

typedef struct {
    s32 unk0;
    s32 count;
} Work638;

extern u8 D_01B00568[];
extern Work638 D_01B00638;
extern u8 D_01B087A0[];
extern Work8868 *D_01B08868;
extern u8 D_01B0EB10[];

extern void func_01B01E70(int, QVec *, int);
extern void func_01B016C8(void);
extern void func_01B083A0(void *, int, float);
extern float func_01B05668(QVec *, QVec *);
extern int func_01B027B0(int);
extern float func_002B3DB0(float);
extern void func_01B04D50(void);
extern void func_01B04790(void *, void *, int, int, int, void *, float);
extern void func_01B01778(void);
extern s32 func_01B01C20(int);
extern void func_01B03F18(void *, void *, void *);

static __inline__ void copy_q(void *dst, void *src)
{
    __asm__ volatile("lq $7, 0(%0)" : : "r"(src) : "$7", "memory");
    __asm__ volatile("sq $7, 0(%0)" : : "r"(dst) : "memory");
}

void func_01B017B0(void)
{
    QVec v0;
    QVec v1;
    Work8868 *w = D_01B08868;
    Elem3A0 *e1 = w->arr10B0;
    int i;

    func_01B01E70(-1, &v0, 3);
    for (i = 0; i < D_01B00638.count; i++, e1++) {
        float minY;
        float dist;
        int mode;
        float rate;
        float ang;
        Elem130 *e2;
        void *mem;

        func_01B01E70(i, &v1, 3);
        minY = v0.f[1] - 1.0f;
        v1.f[1] = v0.f[1];
        copy_q(&e1->vD0, &v0);
        copy_q(&e1->v360, &v1);

        e1->p384 = (void *)func_01B016C8;
        e1->w388 = 0;
        e1->w394 = 0;
        e1->h39C = 2;
        func_01B083A0(e1, 1, 20.0f);

        e1->v360.f[0] += e1->v370.f[0] * 4.0f;
        e1->v360.f[1] += e1->v370.f[1] * 4.0f;
        e1->v360.f[2] += e1->v370.f[2] * 4.0f;

        e2 = &w->arr5F0[i];
        dist = func_01B05668(&v0, &v1) + 10.0f;
        if (func_01B027B0(i) == 0) {
            mode = 2;
            v1.f[1] -= 1.0f;
        } else {
            func_01B01E70(i, &v1, 1);
            mode = 1;
            if (minY < v1.f[1]) {
                v1.f[1] = minY;
            }
        }

        rate = (func_002B3DB0(0.3f) + 1.0f) * 0.036f;
        func_01B04790(D_01B087A0, e2, mode, (int)(dist / 20.0f), 0, (void *)func_01B04D50, rate);
        {
            register void *fn __asm__("$3") = (void *)func_01B01778;
            e2->p104 = fn;
        }
        e2->w120 = func_01B01C20(i);
        copy_q(&e2->vD0, &v1);

        ang = e1->fC4 + 3.1415927f;
        if (ang > 3.1415927f) {
            ang -= 6.2831855f;
        } else if (ang < -3.1415927f) {
            ang += 6.2831855f;
        }
        e2->fC4 = ang;

        mem = (u8 *)w + 0x3180 + (i << 6);
        func_01B03F18(mem, D_01B0EB10, D_01B00568);
        e2->p110 = mem;
    }
}
