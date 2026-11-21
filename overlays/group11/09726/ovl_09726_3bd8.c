typedef unsigned char u8;

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
} Ovl9726Eff;

extern void *g_ovl_ptr_814;
extern u8 g_ovl_dat_0990[];
extern u8 g_ovl_dat_09c0[];
extern u8 g_ovl_dat_0be8[];
extern u8 g_ovl_dat_0c08[];
extern u8 g_ovl_mgr[];
extern void *g_ovl_res;

extern void func_002DD0B0(void *, void *);
extern int func_001C5E90(void *, int, int);
extern int fn_ovl_3888(int);
extern void fn_ovl_9a08(void *);
extern void fn_ovl_9a58(void *);
extern void fn_ovl_9b50(void *);
extern void fn_ovl_ab90(void *);
extern void fn_ovl_abe0(void *);
extern void fn_ovl_ac88(void *);
extern void fn_ovl_c4d0(void *);
extern void fn_ovl_c5d8(void *);
extern void fn_ovl_ccf0(void *);
extern void fn_ovl_dd48(void *);

void ovl_09726_3bd8(void **arg) {
    void *m0[10];
    void *end[15];
    Ovl9726Eff *eff = (Ovl9726Eff *)arg[1];

    eff->f580 += 1.0f / 30.0f;
    switch (eff->w58C) {
    case 0:
        if (eff->f580 >= 1.0f) {
            u8 *p592 = eff->b250;
            u8 *p688;
            u8 *p1072;

            m0[0] = p592;
            m0[1] = g_ovl_dat_0be8;
            fn_ovl_9a08(m0);

            func_002DD0B0(&eff->f270, eff->b240);
            if (fn_ovl_3888(eff->p590->w54) != 0) {
                eff->f274 += 20.0f;
            } else {
                eff->f274 += 4.0f;
            }

            p688 = eff->b2B0;
            m0[0] = p688;
            m0[1] = g_ovl_dat_0be8;
            fn_ovl_9a08(m0);

            p1072 = eff->b430;
            {
                /* DEBT(FAKE): pin f0/f1/f2/f3/v0/v1/a1/a0 for ab90 message at 16(sp) */
                /* DEBT(ORDER): volatile stores and empty asm barriers preserve ab90 sw/swc1 schedule */
                void **m16;
                register float f0 __asm__("$f0") = eff->f584;
                register float f2 __asm__("$f2");
                register void **v0 __asm__("$2");
                register float f3 __asm__("$f3");
                register void *p9c0 __asm__("$3");
                register float f1 __asm__("$f1");
                register void *p990 __asm__("$5");
                __asm__("" : "+f"(f0));
                p9c0 = g_ovl_dat_09c0;
                f2 = 0.3f;
                v0 = m0 + 4;
                f3 = 0.8f;
                __asm__("" : "+r"(v0), "+f"(f3) : "f"(f2));
                __asm__("" : "+f"(f0), "+f"(f2), "+f"(f3), "+r"(v0), "+r"(p9c0));
                f0 = f0 * f2;
                __asm__ volatile("" : "+f"(f0));
                f1 = 1.0f;
                __asm__ volatile("" : "+f"(f1));
                *(void *volatile *)&m0[4] = p1072;
                __asm__ volatile("" : : "m"(m0[4]));
                p990 = g_ovl_dat_0990;
                *(volatile float *)&eff->f2D8 = f1;
                __asm__ volatile("" : "+r"(p990), "+f"(f0), "+f"(f3) : "m"(eff->f2D8));
                f0 = f0 * f3;
                __asm__ volatile("" : "+r"(v0), "+f"(f0));
                *(void *volatile *)&v0[1] = g_ovl_dat_0be8;
                *(void *volatile *)&v0[2] = p9c0;
                __asm__ volatile("" : "+r"(v0) : "m"(v0[2]));
                {
                    register void **a0 __asm__("$4") = v0;
                    __asm__ volatile("" : "+r"(v0), "+f"(f0) : "r"(a0));
                    *(volatile float *)&eff->f2DC = f0;
                    *(void *volatile *)&m0[7] = p592;
                    *(void *volatile *)&v0[4] = p990;
                    *(void *volatile *)&m0[9] = p688;
                    *(volatile float *)&eff->f2D0 = f1;
                    __asm__("" : "+f"(f1) : "m"(eff->f2D0));
                    eff->f2D4 = f1;
                    m16 = a0;
                }
                fn_ovl_ab90(m16);
            }

            m0[0] = eff->b120;
            m0[1] = g_ovl_dat_0c08;
            m0[2] = p1072;
            m0[3] = g_ovl_res;
            m0[4] = g_ovl_mgr;
            m0[5] = 0;
            fn_ovl_ccf0(m0);

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
            fn_ovl_9b50(&end[0]);
            end[1] = p544;
            fn_ovl_9a58(&end[1]);
            end[2] = p640;
            fn_ovl_9b50(&end[2]);
            end[3] = p640;
            fn_ovl_9a58(&end[3]);
            end[4] = p736;
            fn_ovl_ac88(&end[4]);
            end[5] = p736;
            fn_ovl_abe0(&end[5]);
            end[6] = p592;
            fn_ovl_9b50(&end[6]);
            end[7] = p592;
            fn_ovl_9a58(&end[7]);
            end[8] = p688;
            fn_ovl_9b50(&end[8]);
            end[9] = p688;
            fn_ovl_9a58(&end[9]);
            end[10] = p1072;
            fn_ovl_ac88(&end[10]);
            end[11] = p1072;
            fn_ovl_abe0(&end[11]);
            end[12] = p1428;
            fn_ovl_c5d8(&end[12]);
            end[13] = p1428;
            fn_ovl_c4d0(&end[13]);
            end[14] = arg[0];
            fn_ovl_dd48(&end[14]);
            eff->w58C = 255;
        }
        break;
    }
}
