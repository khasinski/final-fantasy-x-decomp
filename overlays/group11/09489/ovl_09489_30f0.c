#include "common.h"

typedef struct {
    u8 pad000[0x20];
    u8 sub020[0x100];   /* 0x020 */
    u8 sub120[0x20];    /* 0x120 */
    float pos140[4];    /* 0x140 */
    u8 sub150[0x20];    /* 0x150 */
    volatile float scale170[4];  /* 0x170 */
    u8 sub180[0x150];   /* 0x180 */
    float f2D0;         /* 0x2D0 */
    int w2D4;           /* 0x2D4 */
    int w2D8;           /* 0x2D8 */
    int w2DC;           /* 0x2DC */
    void *p2E0;         /* 0x2E0 */
    u8 sub2E4[4];       /* 0x2E4 */
} Work30F0;

extern void *D_01B00708;
extern u8 D_01B008A0[];
extern u8 D_01B008D0[];
extern u8 D_01B00AE0[];
extern u8 D_01B00AF8[];
extern u8 D_01B00B18[];
extern u8 D_01B0EA60[];
extern void *D_01B0EA8C;

extern void func_001ACED8(void);
extern void func_002DD0B0(void *, void *);
extern void func_01B02F78(void *);
extern void func_01B093D8(void *);
extern void func_01B0A560(void *);
extern void func_01B0BE18(void *);
extern void func_01B0BE50(void *);
extern void func_01B0C6C0(void *);
extern void func_01B0D670(void *);
extern void func_01B0DA78(void *);

extern float func_001ACED8_f(void) __asm__("func_001ACED8");

void func_01B030F0(Work30F0 *w, void *a1, float *a2, int a3, float f12)
{
    union {
        void *c[6];
        struct {
            void *pad[4];
            void *c4[6];
        } s;
    } u;
    u8 *sub180 = w->sub180;
    u8 *sub150 = w->sub150;
    u8 *sub120 = w->sub120;
    u8 *sub2E4 = w->sub2E4;

    u.c[0] = w;
    u.c[1] = (void *)func_01B02F78;
    u.c[2] = w;
    func_01B0D670(u.c);

    u.c[0] = D_01B00AE0;
    u.c[1] = w;
    func_01B0DA78(u.c);

    {
        register u8 *s0 __asm__("$16") = D_01B00AF8;
        u.c[0] = sub120;
        u.c[1] = s0;
        func_01B093D8(u.c);

        func_002DD0B0(w->pos140, a2);

        u.c[0] = sub150;
        u.c[1] = s0;
        func_01B093D8(u.c);

        {
            register float f0 __asm__("$f0") = f12 * 0.56f;
            register float f1 __asm__("$f1") = 1.0f;
            register void **v0 __asm__("$2") = u.s.c4;
            register u8 *d8a0 __asm__("$3") = D_01B008A0;
            register u8 *d8d0 __asm__("$17");
            register void *ca0 __asm__("$4");
            *(void *volatile *)&u.s.c4[0] = sub180;
            __asm__("" : "+f"(f1) : "f"(f0));
            w->scale170[2] = f1;
            *(void *volatile *)&v0[4] = d8a0;
            __asm__("" : "+f"(f0) : : "$17", "$4");
            d8d0 = D_01B008D0;
            w->scale170[3] = f0;
            *(void *volatile *)&u.s.c4[5] = sub150;
            ca0 = v0;
            __asm__("" : "+f"(f1) : "r"(d8d0));
            *(float *)&w->scale170[1] = f1;
            w->scale170[0] = f1;
            __asm__("" : "+r"(v0), "+r"(ca0));
            *(void *volatile *)&v0[1] = s0;
            *(void *volatile *)&v0[2] = d8d0;
            u.s.c4[3] = sub120;
            func_01B0A560(ca0);

            u.c[0] = w->sub020;
            u.c[1] = D_01B00B18;
            u.c[2] = sub180;
            u.c[3] = D_01B0EA8C;
            u.c[4] = D_01B0EA60;
            u.c[5] = 0;
            func_01B0C6C0(u.c);

            u.c[0] = sub2E4;
            u.c[1] = s0;
            u.c[2] = d8d0;
            u.c[3] = sub120;
            u.c[4] = D_01B00708;
            u.c[5] = (void *)2;
            func_01B0BE50(u.c);
        }
    }

    u.c[0] = sub2E4;
    u.c[1] = 0;
    func_01B0BE18(u.c);

    if (a3 == 0) {
        w->pos140[0] += (func_001ACED8_f() - 0.99f) * 80.0f + -40.0f;
        w->pos140[1] += (func_001ACED8_f() - 0.99f) * 40.0f + -20.0f;
        w->pos140[2] += (func_001ACED8_f() - 0.99f) * 80.0f + -40.0f;
    }

    w->f2D0 = f12;
    w->p2E0 = a1;
    w->w2D4 = 0;
    w->w2D8 = 0;
    w->w2DC = 0;
}
