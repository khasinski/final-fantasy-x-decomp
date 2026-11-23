#include "common.h"

typedef struct {
    u8 pad0[0x54];
    int w54;
} OvlTarget;

typedef struct {
    u8 pad00[0x108];
    int w108;
    u8 pad10C[0x14];
    u8 b120[0xE8];
    int w208;
    u8 pad20C[0x14];
    u8 b220[0x20];
    u8 b240[0x10];
    u8 b250[0x20];
    float f270;
    float f274;
    u8 pad278[0x08];
    u8 b280[0x30];
    u8 b2B0[0x20];
    float f2D0;
    float f2D4;
    float f2D8;
    float f2DC;
    u8 b2E0[0x150];
    u8 b430[0x150];
    float f580;
    float f584;
    int w588;
    int w58C;
    OvlTarget *p590;
    u8 b594[0x10];
} Ovl9727Eff;

extern void *g_ovl_ptr_814;
extern u8 g_ovl_dat_0990[];
extern u8 g_ovl_dat_09c0[];
extern u8 g_ovl_dat_0be8[];
extern u8 g_ovl_dat_0c08[];
extern u8 g_ovl_mgr[];
extern void *g_ovl_res;

extern void func_002DD0B0(void *, void *);
extern int func_001C5E90(void *, int, int);
extern void fn_ovl_9920(void *);
extern void fn_ovl_9970(void *);
extern void fn_ovl_9a68(void *);
extern void fn_ovl_aaa8(void *);
extern void fn_ovl_aaf8(void *);
extern void fn_ovl_aba0(void *);
extern void fn_ovl_c3e8(void *);
extern void fn_ovl_c4f0(void *);
extern void fn_ovl_cc08(void *);
extern void fn_ovl_dc60(void *);

void ovl_09727_3bd8(void **arg)
{
    void *m0[10];
    void *end[15];
    Ovl9727Eff *eff = (Ovl9727Eff *)arg[1];

    eff->f580 += 1.0f / 30.0f;
    switch (eff->w58C) {
    case 0:
        if (eff->f580 >= 1.0f) {
            u8 *p592 = eff->b250;
            u8 *p688;
            u8 *p1072;

            m0[0] = p592;
            m0[1] = g_ovl_dat_0be8;
            fn_ovl_9920(m0);

            func_002DD0B0(&eff->f270, eff->b240);
            eff->f274 += 20.0f;

            p688 = eff->b2B0;
            m0[0] = p688;
            m0[1] = g_ovl_dat_0be8;
            fn_ovl_9920(m0);

            p1072 = eff->b430;
            {
                void **m16;
                register float f0 __asm__("$f0") = eff->f584;
                register void *p9c0 __asm__("$3");
                register float f1 __asm__("$f1");
                register void **v0 __asm__("$2");
                register float f2 __asm__("$f2");
                register void *p990 __asm__("$5");
                __asm__("" : "+f"(f0));
                p9c0 = g_ovl_dat_09c0;
                f1 = 0.3f;
                v0 = m0 + 4;
                f2 = 0.8f;
                __asm__("" : "+r"(v0), "+f"(f2) : "f"(f1));
                __asm__("" : "+f"(f0), "+f"(f1), "+f"(f2), "+r"(v0), "+r"(p9c0));
                f0 = f0 * f1;
                __asm__ volatile("" : "+f"(f0));
                *(volatile float *)&eff->f2D8 = 1.0f;
                *(void *volatile *)&m0[4] = p1072;
                __asm__ volatile("" : : "m"(m0[4]));
                p990 = g_ovl_dat_0990;
                *(volatile float *)&eff->f2D0 = 1.0f;
                __asm__ volatile("" : "+r"(p990), "+f"(f0), "+f"(f2) : "m"(eff->f2D0));
                f0 = f0 * f2;
                *(volatile float *)&eff->f2D4 = 1.0f;
                __asm__ volatile("" : "+r"(v0), "+f"(f0));
                *(void *volatile *)&v0[1] = g_ovl_dat_0be8;
                {
                    register void **a0 __asm__("$4") = v0;
                    __asm__ volatile("" : "+r"(v0), "+f"(f0) : "r"(a0));
                    *(void *volatile *)&v0[2] = p9c0;
                    *(volatile float *)&eff->f2DC = f0;
                    *(void *volatile *)&m0[7] = p592;
                    *(void *volatile *)&v0[4] = p990;
                    m0[9] = p688;
                    m16 = a0;
                }
                fn_ovl_aaa8(m16);
            }

            m0[0] = eff->b120;
            m0[1] = g_ovl_dat_0c08;
            m0[2] = p1072;
            m0[3] = g_ovl_res;
            m0[4] = g_ovl_mgr;
            m0[5] = 0;
            fn_ovl_cc08(m0);

            func_001C5E90(g_ovl_ptr_814, eff->p590->w54, 32);
            eff->w58C++;
        }
        break;
    case 1:
        if ((eff->w108 & 4) && (eff->w208 & 4)) {
            u8 *p544 = eff->b220;
            u8 *p640 = eff->b280;
            u8 *p736 = eff->b2E0;
            u8 *p592 = eff->b250;
            u8 *p688 = eff->b2B0;
            u8 *p1072 = eff->b430;
            u8 *p1428 = eff->b594;

            end[0] = p544;
            fn_ovl_9a68(&end[0]);
            end[1] = p544;
            fn_ovl_9970(&end[1]);
            end[2] = p640;
            fn_ovl_9a68(&end[2]);
            end[3] = p640;
            fn_ovl_9970(&end[3]);
            end[4] = p736;
            fn_ovl_aba0(&end[4]);
            end[5] = p736;
            fn_ovl_aaf8(&end[5]);
            end[6] = p592;
            fn_ovl_9a68(&end[6]);
            end[7] = p592;
            fn_ovl_9970(&end[7]);
            end[8] = p688;
            fn_ovl_9a68(&end[8]);
            end[9] = p688;
            fn_ovl_9970(&end[9]);
            end[10] = p1072;
            fn_ovl_aba0(&end[10]);
            end[11] = p1072;
            fn_ovl_aaf8(&end[11]);
            end[12] = p1428;
            fn_ovl_c4f0(&end[12]);
            end[13] = p1428;
            fn_ovl_c3e8(&end[13]);
            end[14] = arg[0];
            fn_ovl_dc60(&end[14]);
            eff->w58C = 255;
        }
        break;
    }
}
