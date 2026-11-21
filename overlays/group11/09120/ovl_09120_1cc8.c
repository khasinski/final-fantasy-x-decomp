typedef unsigned char u8;

typedef struct {
    void *a;
    void *b;
    int c;
    u8 d;
    u8 pad[3];
} Msg34e0;

typedef struct {
    u8 pad00[0x4E0];
    u8 b4E0[0x20];
    u8 b500[0x610];
    int wB10;
    int wB14;
} Ovl9120Eff;

extern void fn_ovl_19f8(void);
extern void fn_ovl_a518(void *msg);
extern void fn_ovl_a920(void *msg);
extern void fn_ovl_34e0(void *msg);
extern void fn_ovl_6280(void *msg);
extern void fn_ovl_3240(void *msg);
extern void fn_ovl_8cf8(void *msg);
extern void fn_ovl_8cc0(void *msg);

extern u8 g_ovl_dat_0750[];
extern u8 g_ovl_b398;
extern u8 g_ovl_dat_0768[];
extern u8 g_ovl_dat_0820[];
extern void *g_ovl_p370;
extern u8 g_ovl_dat_07a8[];
extern u8 g_ovl_dat_0540[];

void ovl_09120_1cc8(Ovl9120Eff *eff) {
    void *m0[10];
    u8 *p1248 = eff->b4E0;
    /* DEBT(FAKE): pin s2/s4 to match original callee-saved register assignment */
    register u8 *p768 __asm__("$18");
    u8 *p820;
    u8 *p7a8;
    register u8 *p7a8_2 __asm__("$20");
    u8 *p540;

    m0[0] = eff;
    m0[1] = (void *)fn_ovl_19f8;
    m0[2] = eff;
    fn_ovl_a518(m0);

    m0[0] = g_ovl_dat_0750;
    m0[1] = eff;
    fn_ovl_a920(m0);

    p820 = g_ovl_dat_0820;
    p768 = g_ovl_dat_0768;
    ((Msg34e0 *)m0)->a = p820;
    ((Msg34e0 *)m0)->b = p768;
    ((Msg34e0 *)m0)->c = g_ovl_b398;
    ((Msg34e0 *)m0)->d = 0;
    fn_ovl_34e0(m0);

    m0[0] = p1248;
    m0[1] = p768;
    fn_ovl_6280(m0);

    m0[0] = p820;
    m0[1] = eff->b500;
    m0[2] = 0;
    fn_ovl_3240(m0);

    {
        /* DEBT(FAKE): pin v0/a0/v1 for 8cf8 message at 16(sp) */
        /* DEBT(ORDER): volatile stores and empty asm barriers preserve 8cf8 sw schedule */
        void **m16;
        register void *p370 __asm__("$3") = g_ovl_p370;
        register void **v0 __asm__("$2");
        __asm__("" : "+r"(p370));
        p7a8 = g_ovl_dat_07a8;
        __asm__("" : "+r"(p7a8) : "r"(p370));
        p540 = g_ovl_dat_0540;
        __asm__("" : "+r"(p540) : "r"(p7a8));
        v0 = m0 + 4;
        __asm__("" : "+r"(v0) : "r"(p540));
        *(void *volatile *)&m0[4] = p7a8;
        __asm__("" : "+r"(v0) : "m"(m0[4]));
        {
            register void **a0 __asm__("$4") = v0;
            __asm__("" : "+r"(a0), "+r"(v0), "+r"(p370) : "m"(m0[4]));
            *(void *volatile *)&m0[8] = p370;
            __asm__("" : "+r"(v0), "+r"(p7a8) : "m"(m0[8]));
            p7a8_2 = p7a8 + 56;
            __asm__("" : "+r"(p7a8_2), "+r"(v0));
            *(void *volatile *)&v0[1] = p768;
            *(void *volatile *)&v0[2] = p540;
            *(void *volatile *)&m0[7] = p1248;
            m0[9] = 0;
            m16 = a0;
        }
        fn_ovl_8cf8(m16);
    }

    m0[0] = p7a8;
    m0[1] = 0;
    fn_ovl_8cc0(m0);

    m0[0] = p7a8_2;
    m0[1] = p768;
    m0[2] = p540;
    m0[3] = p1248;
    m0[4] = g_ovl_p370;
    m0[5] = (void *)1;
    fn_ovl_8cf8(m0);

    m0[0] = p7a8_2;
    m0[1] = 0;
    fn_ovl_8cc0(m0);

    eff->wB10 = 0;
    eff->wB14 = 0;
}
