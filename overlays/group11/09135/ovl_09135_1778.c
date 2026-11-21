typedef unsigned char u8;
typedef unsigned short u16;

extern void fn_ovl_1668(void);
extern void fn_ovl_c418(void *msg);
extern void fn_ovl_c820(void *msg);
extern void fn_ovl_3140(void *msg);
extern void fn_ovl_6b98(void *msg);
extern void fn_ovl_2ea0(void *msg);
extern void fn_ovl_9308(void *msg);
extern void fn_ovl_b468(void *msg);
extern void fn_ovl_abf8(void *msg);
extern void fn_ovl_abc0(void *msg);
extern void fn_ovl_5ee0(void *msg);
extern void fn_ovl_6010(void *msg);

extern u8 g_ovl_dat_08a0[];
extern u8 g_ovl_dat_0b90[];
extern u8 g_ovl_b4f0;
extern u8 g_ovl_dat_08b8[];
extern u8 g_ovl_dat_0690[];
extern u8 g_ovl_dat_0940[];
extern void *g_ovl_res;
extern u8 g_ovl_dat_08d8[];
extern u8 g_ovl_mgr[];
extern void *g_ovl_p4d8;
extern u8 g_ovl_dat_0b20[];
extern u8 g_ovl_light[];

typedef struct {
    void *a;
    void *b;
    int c;
    u8 d;
    u8 pad[3];
} Msg3140;

typedef struct {
    void *a;
    void *b;
    float c;
} Msg6010;

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
} Ovl9135Eff;

void ovl_09135_1778(Ovl9135Eff *eff) {
    void *m0[10];
    void **m16;
    /* DEBT(FAKE): pin s5/s4/s3 to match ee-gcc register assignment for eff sub-objects */
    register u8 *p288 __asm__("$21") = eff->b120;
    register u8 *p384 __asm__("$20") = eff->b180;
    register u8 *p336 __asm__("$19") = eff->b150;
    u8 *pb90;
    u8 *p8b8;
    u8 *p8d8;
    u8 *pb20;
    u8 *pb20_2;
    u8 *plight;

    m0[0] = eff;
    m0[1] = (void *)fn_ovl_1668;
    m0[2] = eff;
    fn_ovl_c418(m0);

    m0[0] = g_ovl_dat_08a0;
    m0[1] = eff;
    fn_ovl_c820(m0);

    eff->w2D0 = 0;
    eff->h2D4 = 0;

    pb90 = g_ovl_dat_0b90;
    p8b8 = g_ovl_dat_08b8;
    ((Msg3140 *)m0)->a = pb90;
    ((Msg3140 *)m0)->b = p8b8;
    ((Msg3140 *)m0)->c = g_ovl_b4f0;
    ((Msg3140 *)m0)->d = 0;
    fn_ovl_3140(m0);

    m0[0] = p288;
    m0[1] = p8b8;
    fn_ovl_6b98(m0);

    m0[0] = pb90;
    m0[1] = eff->b140;
    m0[2] = 0;
    fn_ovl_2ea0(m0);

    m0[0] = p336;
    m0[1] = p8b8;
    fn_ovl_6b98(m0);

    {
        /* DEBT(FAKE): pin f0/f1/v0/v1/a1 for 9308 message at 16(sp) */
        /* DEBT(ORDER): volatile stores and empty asm barriers preserve 9308 sw/swc1 schedule */
        register float f0 __asm__("$f0") = 1.0f;
        register void *p690 __asm__("$5") = g_ovl_dat_0690;
        register float f1 __asm__("$f1") = 0.9f;
        register void *p940 __asm__("$3") = g_ovl_dat_0940;
        register void **v0 __asm__("$2");
        __asm__("" : "+f"(f1) : "f"(f0));
        *(void *volatile *)&m0[4] = p384;
        v0 = m0 + 4;
        __asm__("" : "+r"(p690), "+r"(p940), "+f"(f0) : "r"(v0), "m"(m0[4]));
        *(volatile float *)&eff->f178 = f0;
        __asm__("" : "+r"(v0) : "m"(eff->f178));
        {
            register void **a0 __asm__("$4") = v0;
            __asm__("" : "+f"(f1) : "r"(a0));
            *(volatile float *)&eff->f17C = f1;
            *(void *volatile *)&v0[2] = p690;
            *(void *volatile *)&v0[4] = p940;
            *(void *volatile *)&m0[9] = p336;
            *(volatile float *)&eff->f170 = f0;
            *(volatile float *)&eff->f174 = f0;
            *(void *volatile *)&v0[1] = p8b8;
            m0[7] = p288;
            m16 = a0;
        }
    }
    fn_ovl_9308(m16);

    p8d8 = g_ovl_dat_08d8;
    m0[0] = eff->b20;
    m0[1] = p8d8;
    m0[2] = p384;
    m0[3] = g_ovl_res;
    m0[4] = g_ovl_mgr;
    m0[5] = 0;
    fn_ovl_b468(m0);

    pb20 = g_ovl_dat_0b20;
    pb20_2 = pb20 + 56;
    m0[0] = pb20;
    m0[1] = p8b8;
    m0[2] = p384;
    m0[3] = p288;
    m0[4] = g_ovl_p4d8;
    m0[5] = 0;
    fn_ovl_abf8(m0);

    m0[0] = pb20;
    m0[1] = 0;
    fn_ovl_abc0(m0);

    m0[0] = pb20_2;
    m0[1] = p8b8;
    m0[2] = p384;
    m0[3] = p288;
    m0[4] = g_ovl_p4d8;
    m0[5] = (void *)1;
    fn_ovl_abf8(m0);

    m0[0] = pb20_2;
    m0[1] = 0;
    fn_ovl_abc0(m0);

    plight = g_ovl_light;
    m0[0] = plight;
    m0[1] = p8d8;
    fn_ovl_5ee0(m0);

    *(float *)(plight + 48) = *(float *)(plight + 96) = 0.5f;
    *(float *)(plight + 56) = *(float *)(plight + 100) = *(float *)(plight + 104) = *(float *)(plight + 108) = 1.0f / 3.0f;
    *(float *)(plight + 52) = 1.0f / 3.0f;

    ((Msg6010 *)m0)->a = plight;
    ((Msg6010 *)m0)->b = 0;
    ((Msg6010 *)m0)->c = 0.1f;
    fn_ovl_6010(m0);
}
