typedef unsigned char u8;
typedef unsigned short u16;

extern void fn_ovl_28c8(void);
extern void fn_ovl_c790(void *msg);
extern void fn_ovl_cb98(void *msg);
extern void fn_ovl_84f8(void *msg);
extern void fn_ovl_9680(void *msg);
extern int fn_ovl_2578(int);
extern void fn_ovl_4800(void *msg);
extern void fn_ovl_b7e0(void *msg);
extern void fn_ovl_af70(void *msg);
extern void fn_ovl_af38(void *msg);
extern float func_001ACED8(void);

extern u8 g_ovl_dat_8e0[];
extern u8 g_ovl_dat_8f8[];
extern u8 g_ovl_dat_6a0[];
extern u8 g_ovl_dat_6d0[];
extern u8 g_ovl_dat_918[];
extern void *g_ovl_ptr_dbac;
extern u8 g_ovl_dat_db80[];
extern void *g_ovl_ptr_500;

typedef struct {
    u8 pad00[0x54];
    int w54;
} Ovl9458Target;

typedef struct {
    u8 pad00[0x20];
    u8 b20[0x100];      /* 0x20 */
    u8 b120[0x20];      /* 0x120 = 288 */
    float f140;         /* 0x140 = 320 */
    float f144;         /* 0x144 = 324 */
    float f148;         /* 0x148 = 328 */
    float f14C;         /* 0x14C = 332 */
    u8 b150[0x20];      /* 0x150 = 336 */
    float f170;         /* 0x170 = 368 */
    float f174;         /* 0x174 = 372 */
    float f178;         /* 0x178 = 376 */
    float f17C;         /* 0x17C = 380 */
    u8 b180[0x150];     /* 0x180 = 384 */
    int w2D0;           /* 0x2D0 = 720 */
    float f2D4;         /* 0x2D4 = 724 */
    int w2D8;           /* 0x2D8 = 728 */
    int w2DC;           /* 0x2DC = 732 */
    void *w2E0;         /* 0x2E0 = 736 */
    u8 b2E4[0x40];      /* 0x2E4 = 740 */
} Ovl9458Eff;

void ovl_09458_2a10(Ovl9458Eff *eff, Ovl9458Target *tgt, float scale)
{
    void *m0[10];
    void **m16;
    /* DEBT(FAKE): pin s0/s1/s3/s5 for eff sub-objects and g_ovl_dat_8f8 */
    register u8 *p120 __asm__("$21") = eff->b120;
    register u8 *p180 __asm__("$19") = eff->b180;
    register u8 *p150 __asm__("$17") = eff->b150;
    register u8 *p8f8 __asm__("$16") = g_ovl_dat_8f8;
    u8 *p2e4;

    m0[0] = eff;
    m0[1] = (void *)fn_ovl_28c8;
    m0[2] = eff;
    fn_ovl_c790(m0);

    m0[0] = g_ovl_dat_8e0;
    m0[1] = eff;
    fn_ovl_cb98(m0);

    m0[0] = p120;
    m0[1] = p8f8;
    fn_ovl_84f8(m0);

    m0[0] = p150;
    m0[1] = p8f8;
    fn_ovl_84f8(m0);

    {
        /* DEBT(FAKE): pin f0/f1/v0/v1/a1 for 9680 message at 16(sp) */
        /* DEBT(ORDER): volatile stores and empty asm barriers preserve 9680 sw/swc1 schedule */
        register float f0 __asm__("$f0") = 1.1f;
        register void *p6a0 __asm__("$3") = g_ovl_dat_6a0;
        register float f1 __asm__("$f1") = 1.0f;
        register void **v0 __asm__("$2");
        f0 = scale * f0;
        __asm__("" : "+f"(f1) : "f"(f0));
        v0 = m0 + 4;
        *(void *volatile *)&m0[4] = p180;
        {
            register void *p6d0 __asm__("$5") = g_ovl_dat_6d0;
            __asm__("" : "+r"(p6a0), "+r"(p6d0), "+f"(f1) : "r"(v0), "m"(m0[4]));
            *(volatile float *)&eff->f178 = f1;
            __asm__("" : "+r"(v0) : "m"(eff->f178));
            { register void **a0 __asm__("$4") = v0;
              __asm__("" : "+f"(f0) : "r"(a0));
              *(volatile float *)&eff->f17C = f0;
              m16 = a0; }
            *(void *volatile *)&v0[1] = p8f8;
            v0[2] = p6d0;
            v0[4] = p6a0;
        }
        *(void *volatile *)&m0[9] = p150;
        *(volatile float *)&eff->f170 = f1;
        *(volatile float *)&eff->f174 = f1;
        m0[7] = p120;
    }
    fn_ovl_9680(m16);

    if (fn_ovl_2578(tgt->w54) != 0) {
        m0[0] = tgt;
        m0[1] = &eff->f140;
        m0[2] = 0;
        fn_ovl_4800(m0);

        m0[0] = eff->b20;
        m0[1] = g_ovl_dat_918;
        m0[2] = p180;
        m0[3] = g_ovl_ptr_dbac;
        m0[4] = g_ovl_dat_db80;
        m0[5] = (void *)1;
        fn_ovl_b7e0(m0);
    } else {
        m0[0] = tgt;
        m0[1] = &eff->f140;
        m0[2] = (void *)1;
        fn_ovl_4800(m0);

        eff->f144 -= 0.2f;

        m0[0] = eff->b20;
        m0[1] = g_ovl_dat_918;
        m0[2] = p180;
        m0[3] = g_ovl_ptr_dbac;
        m0[4] = g_ovl_dat_db80;
        m0[5] = 0;
        fn_ovl_b7e0(m0);
    }

    p2e4 = eff->b2E4;
    m0[0] = p2e4;
    m0[1] = g_ovl_dat_8f8;
    m0[2] = g_ovl_dat_6d0;
    m0[3] = p120;
    m0[4] = g_ovl_ptr_500;
    m0[5] = 0;
    fn_ovl_af70(m0);

    m0[0] = p2e4;
    m0[1] = 0;
    fn_ovl_af38(m0);

    eff->f140 += (func_001ACED8() - 0.99f) * 10.0f + -5.0f;
    eff->f148 += (func_001ACED8() - 0.99f) * 10.0f + -5.0f;
    eff->f2D4 = scale;
    eff->w2E0 = tgt;
    eff->w2D0 = 0;
    eff->w2D8 = 0;
    eff->w2DC = 0;
}
