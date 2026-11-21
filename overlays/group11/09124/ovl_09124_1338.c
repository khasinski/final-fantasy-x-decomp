typedef unsigned char u8;
typedef unsigned short u16;

extern void fn_ovl_12b8(void);
extern void fn_ovl_9cc0(void *msg);
extern void fn_ovl_a0c8(void *msg);
extern void fn_ovl_2c88(void *msg);
extern void fn_ovl_5a28(void *msg);
extern void fn_ovl_6bb0(void *msg);
extern int fn_ovl_0f68(int);
extern void fn_ovl_29e8(void *msg);
extern void fn_ovl_8d10(void *msg);
extern void fn_ovl_84a0(void *msg);
extern void fn_ovl_8468(void *msg);

extern u8 g_ovl_dat_850[];
extern u8 g_ovl_dat_868[];
extern u8 g_ovl_dat_920[];
extern u8 g_ovl_b_4a0;
extern u8 g_ovl_dat_640[];
extern u8 g_ovl_dat_610[];
extern u8 g_ovl_dat_888[];
extern void *g_ovl_ptr_b0dc;
extern u8 g_ovl_dat_b0b0[];
extern void *g_ovl_ptr_488;
extern u8 g_ovl_dat_8a8[];
extern u8 g_ovl_dat_5b0[];

typedef struct {
    void *a;
    void *b;
    int c;
    u8 d;
    u8 pad[3];
} Msg2c88;

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
    float f178;
    float f17C;
    u8 b180[0x150];     /* 0x180 = 384 */
    int w2D0;           /* 0x2D0 = 720 */
    u16 h2D4;           /* 0x2D4 = 724 */
} Ovl9124Eff;

void ovl_09124_1338(Ovl9124Eff *eff)
{
    void *m0[10];
    void **m16;
    /* DEBT(FAKE): pin s0/s1/s2/s6 for eff sub-objects and g_ovl_dat_868 */
    register u8 *p384 __asm__("$22") = eff->b180;
    register u8 *p288 __asm__("$18") = eff->b120;
    register u8 *p336 __asm__("$17") = eff->b150;
    register u8 *p868 __asm__("$16") = g_ovl_dat_868;
    u8 *p920;
    u8 *p8a8;
    u8 *p8e0;
    u8 *p5b0;

    m0[0] = eff;
    m0[1] = (void *)fn_ovl_12b8;
    m0[2] = eff;
    fn_ovl_9cc0(m0);

    m0[0] = g_ovl_dat_850;
    m0[1] = eff;
    fn_ovl_a0c8(m0);

    eff->w2D0 = 0;
    eff->h2D4 = 0;

    p920 = g_ovl_dat_920;
    ((Msg2c88 *)m0)->a = p920;
    ((Msg2c88 *)m0)->b = p868;
    ((Msg2c88 *)m0)->c = g_ovl_b_4a0;
    ((Msg2c88 *)m0)->d = 0;
    fn_ovl_2c88(m0);

    m0[0] = p336;
    m0[1] = p868;
    fn_ovl_5a28(m0);

    m0[0] = p288;
    m0[1] = p868;
    fn_ovl_5a28(m0);

    {
        /* DEBT(FAKE): pin f0/f1/v0/v1/a1 for 6bb0 message at 16(sp) */
        /* DEBT(ORDER): volatile stores and empty asm barriers preserve 6bb0 sw/swc1 schedule */
        register float f0 __asm__("$f0") = 1.0f;
        register void *p640 __asm__("$3") = g_ovl_dat_640;
        register float f1 __asm__("$f1") = 1.1f;
        register void **v0 __asm__("$2");
        __asm__("" : "+f"(f1) : "f"(f0));
        v0 = m0 + 4;
        *(void *volatile *)&m0[4] = p384;
        *(volatile float *)&eff->f148 = f0;
        {
            register void *p610 __asm__("$5") = g_ovl_dat_610;
            __asm__("" : "+r"(p640), "+f"(f1) : "r"(v0));
            *(volatile float *)&eff->f14C = f1;
            *(void *volatile *)&v0[1] = p868;
            v0[2] = p640;
            *(void *volatile *)&m0[7] = p336;
            v0[4] = p610;
        }
        *(void *volatile *)&m0[9] = p288;
        *(volatile float *)&eff->f140 = f0;
        __asm__("" : "+f"(f0) : "m"(eff->f140));
        eff->f144 = f0;
        m16 = v0;
    }
    fn_ovl_6bb0(m16);

    if (fn_ovl_0f68(g_ovl_b_4a0) != 0) {
        m0[0] = p920;
        m0[1] = &eff->f170;
        m0[2] = 0;
        fn_ovl_29e8(m0);

        m0[0] = eff->b20;
        m0[1] = g_ovl_dat_888;
        m0[2] = p384;
        m0[3] = g_ovl_ptr_b0dc;
        m0[4] = g_ovl_dat_b0b0;
        m0[5] = (void *)1;
        fn_ovl_8d10(m0);
    } else {
        m0[0] = p920;
        m0[1] = &eff->f170;
        m0[2] = (void *)1;
        fn_ovl_29e8(m0);

        eff->f174 -= 0.2f;

        m0[0] = eff->b20;
        m0[1] = g_ovl_dat_888;
        m0[2] = p384;
        m0[3] = g_ovl_ptr_b0dc;
        m0[4] = g_ovl_dat_b0b0;
        m0[5] = 0;
        fn_ovl_8d10(m0);
    }

    p8a8 = g_ovl_dat_8a8;
    p5b0 = g_ovl_dat_5b0;
    p8e0 = p8a8 + 56;
    m0[0] = p8a8;
    m0[1] = g_ovl_dat_868;
    m0[2] = p384;
    m0[3] = p5b0;
    m0[4] = g_ovl_ptr_488;
    m0[5] = 0;
    fn_ovl_84a0(m0);

    m0[0] = p8a8;
    m0[1] = 0;
    fn_ovl_8468(m0);

    m0[0] = p8e0;
    m0[1] = g_ovl_dat_868;
    m0[2] = p384;
    m0[3] = p5b0;
    m0[4] = g_ovl_ptr_488;
    m0[5] = (void *)1;
    fn_ovl_84a0(m0);

    m0[0] = p8e0;
    m0[1] = 0;
    fn_ovl_8468(m0);
}
