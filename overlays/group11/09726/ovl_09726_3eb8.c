typedef unsigned char u8;

typedef struct {
    u8 pad0[0x54];
    int w54;
} OvlTarget;

typedef struct {
    u8 pad00[0x20];
    u8 b20[0x200];
    u8 b220[0x20];
    float f240;
    float f244;
    float f248;
    float f24C;
    u8 pad250[0x30];
    u8 b280[0x20];
    float f2A0;
    float f2A4;
    float f2A8;
    float f2AC;
    u8 pad2B0[0x30];
    u8 b2E0[0x2A0];
    float f580;
    float f584;
    int w588;
    int w58C;
    OvlTarget *p590;
    u8 b594[0x10];
} Ovl9726Eff;

extern void *g_ovl_ptr_7f8;
extern u8 g_ovl_dat_0990[];
extern u8 g_ovl_dat_09c0[];
extern u8 g_ovl_dat_0bd0[];
extern u8 g_ovl_dat_0be8[];
extern u8 g_ovl_dat_0c08[];
extern u8 g_ovl_mgr[];
extern void *g_ovl_res;

extern float func_001ACED8(void);
extern int fn_ovl_3888(int);
extern void fn_ovl_3bd8(void);
extern void fn_ovl_5d10(void *);
extern void fn_ovl_9a08(void *);
extern void fn_ovl_ab90(void *);
extern void fn_ovl_c448(void *);
extern void fn_ovl_c480(void *);
extern void fn_ovl_ccf0(void *);
extern void fn_ovl_dca0(void *);
extern void fn_ovl_e0a8(void *);

void ovl_09726_3eb8(Ovl9726Eff *eff, OvlTarget *tgt, float scale) {
    void *m0[10];
    u8 *p544 = eff->b220;
    u8 *p736 = eff->b2E0;
    u8 *p640 = eff->b280;
    u8 *pbe8 = g_ovl_dat_0be8;
    u8 *p1428;

    m0[0] = eff;
    m0[1] = (void *)fn_ovl_3bd8;
    m0[2] = eff;
    fn_ovl_dca0(m0);

    m0[0] = g_ovl_dat_0bd0;
    m0[1] = eff;
    fn_ovl_e0a8(m0);

    m0[0] = p544;
    m0[1] = pbe8;
    fn_ovl_9a08(m0);

    m0[0] = p640;
    m0[1] = pbe8;
    fn_ovl_9a08(m0);

    {
        /* DEBT(FAKE): pin f0/v0/v1/a1/a0 for ab90 message at 16(sp) */
        /* DEBT(ORDER): volatile stores and empty asm barriers preserve ab90 sw/swc1 schedule */
        void **m16;
        register float f0 __asm__("$f0") = 1.0f;
        register void *p990 __asm__("$3") = g_ovl_dat_0990;
        register void *p9c0 __asm__("$5") = g_ovl_dat_09c0;
        register void **v0 __asm__("$2");
        __asm__("" : "+f"(f0));
        *(void *volatile *)&m0[4] = p736;
        v0 = m0 + 4;
        __asm__("" : "+r"(p990), "+r"(p9c0), "+f"(f0) : "r"(v0), "m"(m0[4]));
        *(volatile float *)&eff->f2A8 = f0;
        __asm__("" : "+r"(v0) : "m"(eff->f2A8));
        {
            register void **a0 __asm__("$4") = v0;
            __asm__("" : "+r"(v0) : "r"(a0));
            *(void *volatile *)&v0[1] = pbe8;
            *(void *volatile *)&v0[2] = p9c0;
            *(void *volatile *)&v0[4] = p990;
            *(void *volatile *)&m0[9] = p640;
            *(volatile float *)&eff->f2A0 = f0;
            *(volatile float *)&eff->f2A4 = f0;
            m0[7] = p544;
            m16 = a0;
        }
        fn_ovl_ab90(m16);
    }

    if (fn_ovl_3888(tgt->w54) != 0) {
        m0[0] = tgt;
        m0[1] = &eff->f240;
        m0[2] = 0;
        fn_ovl_5d10(m0);

        eff->f244 += (func_001ACED8() - 0.99f) * 20.0f + (-10.0f);
        eff->f2AC = (scale * 1.2f) * 0.9f;

        m0[0] = eff->b20;
        m0[1] = g_ovl_dat_0c08;
        m0[2] = p736;
        m0[3] = g_ovl_res;
        m0[4] = g_ovl_mgr;
        m0[5] = (void *)2;
        fn_ovl_ccf0(m0);
    } else {
        m0[0] = tgt;
        m0[1] = &eff->f240;
        m0[2] = (void *)1;
        fn_ovl_5d10(m0);

        eff->f244 -= 0.2f;
        eff->f2AC = (scale * 0.3f) * 0.8f;

        m0[0] = eff->b20;
        m0[1] = g_ovl_dat_0c08;
        m0[2] = p736;
        m0[3] = g_ovl_res;
        m0[4] = g_ovl_mgr;
        m0[5] = (void *)1;
        fn_ovl_ccf0(m0);
    }

    p1428 = eff->b594;
    m0[0] = p1428;
    m0[1] = g_ovl_dat_0be8;
    m0[2] = g_ovl_dat_09c0;
    m0[3] = p544;
    m0[4] = g_ovl_ptr_7f8;
    m0[5] = 0;
    fn_ovl_c480(m0);

    m0[0] = p1428;
    m0[1] = 0;
    fn_ovl_c448(m0);

    eff->f240 += (func_001ACED8() - 0.99f) * 20.0f + (-10.0f);
    eff->f248 += (func_001ACED8() - 0.99f) * 20.0f + (-10.0f);
    eff->f584 = scale;
    eff->p590 = tgt;
    eff->f580 = 0.0f;
    eff->w588 = 0;
    eff->w58C = 0;
}
