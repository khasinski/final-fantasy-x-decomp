#include "common.h"

typedef struct {
    u8 pad000[0xAD0];
    u_long128 mAD0[3];
    u_long128 vB00;
    u_long128 mB10[3];
    u_long128 vB40;
    u8 padB50[0x100];
    u_long128 vC50;
    u_long128 vC60;
    u_long128 vC70;
    u_long128 vC80;
    u8 padC90[0x40];
    u_long128 vCD0;
    u8 padCE0[0x1E0];
    s32 wEC0;
    s32 wEC4;
    float fEC8;
    u8 padECC[0x10];
    s32 wEDC;
} Work8A90;

typedef union {
    float f[4];
    u_long128 q;
} QVec;

extern Work8A90 *D_01B08A90;
extern s32 D_01B08A64;
extern s32 D_01B08A84;

extern void func_01B01E00(int, QVec *, int);
extern float func_01B01CD8(int);
extern void func_01B03070(int, u_long128 *);
extern void func_01B035F0(int, u_long128 *, QVec *);
extern void func_01B02B68(int, int);
extern void func_01B02AC8(int, int);

static __inline__ void copy_q(void *dst, void *src)
{
    __asm__ volatile("lq $7, 0(%0)" : : "r"(src) : "$7", "memory");
    __asm__ volatile("sq $7, 0(%0)" : : "r"(dst) : "memory");
}

void func_01B012C8(void)
{
    register Work8A90 *w __asm__("$16") = D_01B08A90;
    QVec v0;
    QVec v1;

    func_01B01E00(0, &v0, 0);
    copy_q(&w->vCD0, &v0.q);

    v1.f[0] = 0.0f;
    v1.f[1] = func_01B01CD8(0);
    __asm__("" : : : "memory");
    {
        void *pC50 = &w->vC50;
        QVec *p1;
        __asm__("" : "+r"(pC50) : : "memory");
        v1.f[2] = 0.0f;
        __asm__("" : : : "memory");
        p1 = &v1;
        __asm__("" : "+r"(p1));
        v1.f[3] = 0.0f;
        copy_q(pC50, &p1->q);
        copy_q(&w->vC60, &v0.q);
        func_01B03070(0, w->mAD0);
        func_01B035F0(0, w->mAD0, p1);
        copy_q(&w->vB00, &w->vC60);

        copy_q(&w->vC70, &p1->q);
        copy_q(&w->vC80, &v0.q);
        func_01B03070(-1, w->mB10);
        func_01B035F0(-1, w->mB10, p1);
        copy_q(&w->vB40, &w->vC80);
    }

    func_01B02B68(-1, 1);
    func_01B02AC8(-1, 0);

    {
        float fy = v1.f[1];
        *(volatile s32 *)&w->wEDC = 0;
        *(volatile float *)&w->fEC8 = fy;
        *(volatile s32 *)&w->wEC0 = 0;
        *(volatile s32 *)&w->wEC4 = 0;
        D_01B08A64 = 1;
        D_01B08A84 = 1;
    }
}
