typedef unsigned char u8;
typedef unsigned short u16;

extern void fn_ovl_1788(void);
extern void fn_ovl_c530(void *msg);
extern void fn_ovl_c938(void *msg);
extern void fn_ovl_3258(void *msg);
extern void fn_ovl_6cb0(void *msg);
extern void fn_ovl_2fb8(void *msg);
extern void fn_ovl_9420(void *msg);
extern void fn_ovl_b580(void *msg);
extern void fn_ovl_ad10(void *msg);
extern void fn_ovl_acd8(void *msg);
extern void fn_ovl_5ff8(void *msg);
extern void fn_ovl_6128(void *msg);

extern u8 g_ovl_dat_9c0[];
extern u8 g_ovl_dat_cb0[];
extern u8 g_ovl_b_608;
extern u8 g_ovl_dat_9d8[];
extern u8 g_ovl_dat_7b0[];
extern u8 g_ovl_dat_a60[];
extern void *g_ovl_ptr_d94c;
extern u8 g_ovl_dat_9f8[];
extern u8 g_ovl_dat_d920[];
extern void *g_ovl_ptr_5f0;
extern u8 g_ovl_dat_c40[];
extern u8 g_ovl_dat_720[];
extern u8 g_ovl_dat_d50[];

typedef struct {
    void *a;
    void *b;
    int c;
    u8 d;
    u8 pad[3];
} Msg3258;

typedef struct {
    void *a;
    void *b;
    float c;
} Msg6128;

typedef struct {
    u8 pad00[0x20];
    u8 b20[0x100];
    u8 b120[0x20];
    u8 b140[0x10];
    u8 b150[0x20];
    float f170;
    float f174;
    float f178;
    float f17C;
    u8 b180[0x150];
    int w2D0;
    u16 h2D4;
} Ovl9130Eff;

void ovl_09134_1608(Ovl9130Eff *eff) {
    void *m0[10];
    void **m16;
    /* DEBT(FAKE): pin s3/s4/s5 to match ee-gcc register assignment for eff sub-objects */
    register u8 *p336 __asm__("$21") = eff->b150;
    register u8 *p288 __asm__("$20") = eff->b120;
    register u8 *p384 __asm__("$19") = eff->b180;
    u8 *pcb0;
    u8 *p9d8;
    u8 *p9f8;
    u8 *pc40;
    u8 *pd50;

    m0[0] = eff;
    m0[1] = (void *)fn_ovl_1788;
    m0[2] = eff;
    fn_ovl_c530(m0);

    m0[0] = g_ovl_dat_9c0;
    m0[1] = eff;
    fn_ovl_c938(m0);

    eff->w2D0 = 0;
    eff->h2D4 = 0;

    pcb0 = g_ovl_dat_cb0;
    p9d8 = g_ovl_dat_9d8;
    ((Msg3258 *)m0)->a = pcb0;
    ((Msg3258 *)m0)->b = p9d8;
    ((Msg3258 *)m0)->c = g_ovl_b_608;
    ((Msg3258 *)m0)->d = 0;
    fn_ovl_3258(m0);

    m0[0] = p288;
    m0[1] = p9d8;
    fn_ovl_6cb0(m0);

    m0[0] = pcb0;
    m0[1] = eff->b140;
    m0[2] = 0;
    fn_ovl_2fb8(m0);

    m0[0] = p336;
    m0[1] = p9d8;
    fn_ovl_6cb0(m0);

    {
        /* DEBT(FAKE): pin f0/f1/v0/v1/a1 for 8388 message at 16(sp) */
        /* DEBT(ORDER): volatile stores and empty asm barriers preserve 8388 sw/swc1 schedule */
        register float f0 __asm__("$f0") = 1.0f;
        register void *p7b0 __asm__("$5") = g_ovl_dat_7b0;
        register float f1 __asm__("$f1") = 0.9f;
        register void *pa60 __asm__("$3") = g_ovl_dat_a60;
        register void **v0 __asm__("$2");
        __asm__("" : "+f"(f1) : "f"(f0));
        *(void *volatile *)&m0[4] = p384;
        v0 = m0 + 4;
        __asm__("" : "+r"(p7b0), "+r"(pa60), "+f"(f0) : "r"(v0), "m"(m0[4]));
        *(volatile float *)&eff->f178 = f0;
        __asm__("" : "+r"(v0) : "m"(eff->f178));
        {
            register void **a0 __asm__("$4") = v0;
            __asm__("" : "+f"(f1) : "r"(a0));
            *(volatile float *)&eff->f17C = f1;
            *(void *volatile *)&v0[2] = p7b0;
            *(void *volatile *)&v0[4] = pa60;
            *(void *volatile *)&m0[9] = p336;
            *(volatile float *)&eff->f170 = f0;
            *(volatile float *)&eff->f174 = f0;
            *(void *volatile *)&v0[1] = p9d8;
            m0[7] = p288;
            m16 = a0;
        }
    }
    fn_ovl_9420(m16);

    p9f8 = g_ovl_dat_9f8;
    m0[0] = eff->b20;
    m0[1] = p9f8;
    m0[2] = p384;
    m0[3] = g_ovl_ptr_d94c;
    m0[4] = g_ovl_dat_d920;
    m0[5] = 0;
    fn_ovl_b580(m0);

    pc40 = g_ovl_dat_c40;
    m0[0] = pc40;
    m0[1] = p9d8;
    m0[2] = p384;
    m0[3] = p288;
    m0[4] = g_ovl_ptr_5f0;
    m0[5] = 0;
    fn_ovl_ad10(m0);

    pc40 += 56;
    m0[0] = pc40;
    m0[1] = p9d8;
    m0[2] = p384;
    m0[3] = p288;
    m0[4] = g_ovl_ptr_5f0;
    m0[5] = (void *)1;
    fn_ovl_ad10(m0);

    m0[0] = pc40;
    m0[1] = 0;
    fn_ovl_acd8(m0);

    pd50 = g_ovl_dat_d50;
    m0[0] = pd50;
    m0[1] = p9f8;
    fn_ovl_5ff8(m0);

    *(float *)(pd50 + 48) = *(float *)(pd50 + 96) = 0.5f;
    *(float *)(pd50 + 56) = *(float *)(pd50 + 100) = *(float *)(pd50 + 104) = *(float *)(pd50 + 108) = 1.0f / 3.0f;
    *(float *)(pd50 + 52) = 1.0f / 3.0f;

    ((Msg6128 *)m0)->a = pd50;
    ((Msg6128 *)m0)->b = 0;
    ((Msg6128 *)m0)->c = 0.1f;
    fn_ovl_6128(m0);
}
