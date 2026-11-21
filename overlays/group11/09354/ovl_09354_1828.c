typedef unsigned char u8;

typedef struct {
    u8 pad00[0x18];
    unsigned int w18;
    u8 pad1C[0x0C];
    int w28;
    int w2C;
} Ovl9354State;

typedef struct {
    void *p00;
    Ovl9354State *state;
} Ovl9354Ctx;

extern u8 g_ovl_dat_04f0[];
extern u8 g_ovl_dat_0550[];
extern u8 g_ovl_dat_0580[];
extern u8 g_ovl_dat_07a8[];
extern u8 g_ovl_dat_07c8[];
extern u8 g_ovl_dat_08b0[];
extern u8 g_ovl_dat_0950[];
extern u8 g_ovl_dat_0a70[];
extern u8 g_ovl_dat_0e60[];
extern u8 g_ovl_dat_1160[];
extern void *g_ovl_ptr_03c0;
extern void *g_ovl_ptr_03c8;
extern int g_ovl_flags_0f48;
extern u8 g_ovl_mgr[];
extern void *g_ovl_res;

extern void func_00299170(int);
extern void fn_ovl_2c38(void *);
extern void fn_ovl_2ca8(void *);
extern void fn_ovl_31b0(void *);
extern void fn_ovl_3250(void *);
extern void fn_ovl_3358(void *);
extern void fn_ovl_5f50(void *);
extern void fn_ovl_70d8(void *);
extern void fn_ovl_8990(void *);
extern void fn_ovl_89c8(void *);
extern void fn_ovl_9238(void *);
extern void fn_ovl_a290(void *);

void ovl_09354_1828(Ovl9354Ctx *ctx) {
    void *m0[12];
    void *m48[1];
    void *m52[1];
    void *m56[1];
    Ovl9354State *st = ctx->state;

    switch (st->w18) {
    case 0:
        m0[0] = g_ovl_dat_08b0;
        m0[1] = g_ovl_dat_07a8;
        m0[2] = g_ovl_ptr_03c8;
        ((u8 *)m0)[12] = 0;
        fn_ovl_31b0(m0);
        st->w18 = 10;
        /* fallthrough */
    case 10:
        {
            u8 *p950 = g_ovl_dat_0950;
            u8 *p7a8 = g_ovl_dat_07a8;
            u8 *pa70 = g_ovl_dat_0a70;
            u8 *pe60 = g_ovl_dat_0e60;
            u8 *p8b0 = g_ovl_dat_08b0;
            u8 *p980;
            u8 *p1160;

            m0[0] = p950;
            m0[1] = p7a8;
            fn_ovl_5f50(m0);

            m0[0] = p8b0;
            m0[1] = 0;
            m0[2] = p950 + 32;
            fn_ovl_2ca8(m0);

            *(float *)(p950 + 44) = 1.0f;
            p980 = p950 + 48;
            m0[0] = p980;
            m0[1] = p7a8;
            fn_ovl_5f50(m0);

            {
                /* DEBT(FAKE): pin v0/v1/f0/a0 for 70d8 message at 16(sp) */
                /* DEBT(ORDER): volatile stores and empty asm barriers preserve 70d8 sw/swc1 schedule */
                register void **m16 __asm__("$2");
                register float f0 __asm__("$f0") = 0.09900001f;
                __asm__("" : "+f"(f0));
                {
                    register void *v1 __asm__("$3") = g_ovl_dat_0580;
                    *(void *volatile *)&m0[4] = pa70;
                    m16 = m0 + 4;
                    __asm__("" : "+r"(v1), "+f"(f0) : "r"(m16));
                    *(volatile float *)(p980 + 40) = 1.0f;
                    *(volatile float *)(p980 + 44) = f0;
                    m16[2] = v1;
                    *(void *volatile *)&m0[7] = p950;
                    {
                        register void **a0 __asm__("$4");
                        __asm__("" : "+r"(m16) : "m"(m0[7]));
                        a0 = m16;
                        __asm__("" : "+r"(m16) : "r"(a0));
                        m16[4] = g_ovl_dat_0550;
                        *(void *volatile *)&m0[9] = p980;
                        *(volatile float *)(p980 + 32) = 1.0f;
                        *(volatile float *)(p980 + 36) = 1.0f;
                        m16[1] = p7a8;
                        fn_ovl_70d8(a0);
                    }
                }
            }

            pa70[332] = 1;
            m0[0] = pe60;
            m0[1] = g_ovl_dat_07c8;
            m0[2] = pa70;
            m0[3] = g_ovl_res;
            m0[4] = g_ovl_mgr;
            m0[5] = 0;
            fn_ovl_9238(m0);

            p1160 = g_ovl_dat_1160;
            m0[0] = p1160;
            m0[1] = p7a8;
            m0[2] = pa70;
            m0[3] = g_ovl_dat_04f0;
            m0[4] = g_ovl_ptr_03c0;
            m0[5] = 0;
            fn_ovl_89c8(m0);

            m0[0] = p1160;
            m0[1] = 0;
            fn_ovl_8990(m0);

            m0[0] = p8b0;
            m0[1] = 0;
            m0[2] = (void *)30;
            fn_ovl_2c38(m0);

            st->w2C = 0;
            st->w18 = 10000;
        }
        break;
    case 10000:
        if ((g_ovl_flags_0f48 & 4) != 0) {
            u8 *p8b0 = g_ovl_dat_08b0;
            func_00299170(*(int *)(p8b0 + 88));
            *(int *)(p8b0 + 112) = 2;
            m48[0] = p8b0;
            fn_ovl_3358(m48);
            m52[0] = p8b0;
            fn_ovl_3250(m52);
            m56[0] = ctx->p00;
            fn_ovl_a290(m56);
        }
        break;
    }

    st->w28++;
    st->w2C++;
}
