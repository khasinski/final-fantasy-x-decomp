typedef unsigned char u8;

typedef struct {
    u8 pad00[0x20];
    u8 b20[0x100];
    u8 b120[0x20];
    float f140;
    float f144;
    float f148;
    float f14C;
    u8 b150[0x20];
    float f170;
    float f174;
    float f178;
    float f17C;
    u8 b180[0x150];
    int w2D0;
    float f2D4;
    int w2D8;
    int w2DC;
    void *p2E0;
    u8 b2E4[0x10];
} Ovl9729Eff;

extern void *g_ovl_ptr_05a0;
extern u8 g_ovl_dat_0740[];
extern u8 g_ovl_dat_0770[];
extern u8 g_ovl_dat_0980[];
extern u8 g_ovl_dat_0998[];
extern u8 g_ovl_dat_09b8[];
extern u8 g_ovl_mgr[];
extern void *g_ovl_res;

extern float func_001ACED8(void);
extern void fn_ovl_2968(void);
extern void fn_ovl_4808(void *);
extern void fn_ovl_8500(void *);
extern void fn_ovl_9688(void *);
extern void fn_ovl_af40(void *);
extern void fn_ovl_af78(void *);
extern void fn_ovl_b7e8(void *);
extern void fn_ovl_c798(void *);
extern void fn_ovl_cba0(void *);

void ovl_09729_2ab8(Ovl9729Eff *eff, void *tgt, float scale) {
    void *m0[10];
    u8 *p288 = eff->b120;
    u8 *p336 = eff->b150;
    u8 *p384 = eff->b180;
    u8 *p740 = eff->b2E4;
    /* DEBT(FAKE): pin s1 for g_ovl_dat_0998 so g_ovl_dat_0770 stays in s2 */
    register u8 *p998 __asm__("$17");

    m0[0] = eff;
    m0[1] = (void *)fn_ovl_2968;
    m0[2] = eff;
    fn_ovl_c798(m0);

    m0[0] = g_ovl_dat_0980;
    m0[1] = eff;
    fn_ovl_cba0(m0);

    p998 = g_ovl_dat_0998;
    m0[0] = p288;
    m0[1] = p998;
    fn_ovl_8500(m0);

    m0[0] = p336;
    m0[1] = p998;
    fn_ovl_8500(m0);

    {
        /* DEBT(FAKE): pin v0/v1/f0/a0 for 9688 message at 16(sp) */
        /* DEBT(ORDER): volatile stores and empty asm barriers preserve 9688 sw/swc1 schedule */
        register void **v1 __asm__("$3");
        register float f0 __asm__("$f0") = 1.0f;
        __asm__("" : "+f"(f0));
        {
            register void *v0 __asm__("$2") = g_ovl_dat_0740;
            *(void *volatile *)&m0[4] = p384;
            v1 = m0 + 4;
            __asm__("" : "+r"(v0), "+f"(f0) : "r"(v1));
            *(volatile float *)&eff->f17C = scale;
            *(volatile float *)&eff->f178 = f0;
            v1[4] = v0;
            *(void *volatile *)&m0[9] = p336;
            {
                register void **a0 __asm__("$4");
                __asm__("" : "+r"(v1) : "m"(m0[9]));
                a0 = v1;
                __asm__("" : "+r"(v1), "+f"(f0) : "r"(a0));
                *(volatile float *)&eff->f170 = f0;
                *(volatile float *)&eff->f174 = f0;
                *(void *volatile *)&v1[1] = p998;
                *(void *volatile *)&v1[2] = g_ovl_dat_0770;
                m0[7] = p288;
                fn_ovl_9688(a0);
            }
        }
    }

    m0[0] = tgt;
    m0[1] = &eff->f140;
    m0[2] = 0;
    fn_ovl_4808(m0);

    m0[0] = eff->b20;
    m0[1] = g_ovl_dat_09b8;
    m0[2] = p384;
    m0[3] = g_ovl_res;
    m0[4] = g_ovl_mgr;
    m0[5] = (void *)1;
    fn_ovl_b7e8(m0);

    m0[0] = p740;
    m0[1] = p998;
    m0[2] = g_ovl_dat_0770;
    m0[3] = p288;
    m0[4] = g_ovl_ptr_05a0;
    m0[5] = 0;
    fn_ovl_af78(m0);

    m0[0] = p740;
    m0[1] = 0;
    fn_ovl_af40(m0);

    eff->f140 += (func_001ACED8() - 0.99f) * 10.0f + (-5.0f);
    eff->f148 += (func_001ACED8() - 0.99f) * 10.0f + (-5.0f);
    eff->f2D4 = scale;
    eff->p2E0 = tgt;
    eff->w2D0 = 0;
    eff->w2D8 = 0;
    eff->w2DC = 0;
}
