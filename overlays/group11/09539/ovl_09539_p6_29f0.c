typedef unsigned char u8;

extern void fn_ovl_29d8(void);
extern void fn_ovl_c7f0(void *msg);
extern void fn_ovl_cbf8(void *msg);
extern void fn_ovl_8558(void *msg);
extern void fn_ovl_4860(void *msg);
extern void fn_ovl_96e0(void *msg);
extern void fn_ovl_b840(void *msg);
extern void fn_ovl_afd0(void *msg);
extern void fn_ovl_af98(void *msg);
extern void fn_sys_1c5e90(void *a0, void *a1, int a2);
extern float fn_sys_1aced8(void);

extern u8 g_ovl_dat_9f0[];
extern u8 g_ovl_dat_a08[];
extern u8 g_ovl_dat_7b0[];
extern u8 g_ovl_dat_7e0[];
extern u8 g_ovl_dat_a28[];
extern void *g_ovl_ptr_dc0c;
extern u8 g_ovl_dat_dbe0[];
extern void *g_ovl_ptr_618;
extern void *g_ovl_ptr_634;

void ovl_09539_p6_29f0(u8 *ctx, u8 *arg1, float farg) {
    void *m0[10];
    void **m16;
    u8 *p288 = ctx + 288;
    u8 *p336 = ctx + 336;
    u8 *p384 = ctx + 384;
    u8 *p740 = ctx + 740;
    u8 *p7e0;

    m0[0] = ctx;
    m0[1] = (void *)fn_ovl_29d8;
    m0[2] = ctx;
    fn_ovl_c7f0(m0);

    m0[0] = g_ovl_dat_9f0;
    m0[1] = ctx;
    fn_ovl_cbf8(m0);

    m0[0] = p288;
    m0[1] = g_ovl_dat_a08;
    fn_ovl_8558(m0);

    m0[0] = arg1;
    m0[1] = ctx + 320;
    m0[2] = 0;
    fn_ovl_4860(m0);

    m0[0] = p336;
    m0[1] = g_ovl_dat_a08;
    fn_ovl_8558(m0);

    {
        /* DEBT(FAKE): pin f0/f1/v0/v1 for 96e0 message at 16(sp) */
        /* DEBT(ORDER): volatile stores preserve sw/swc1 interleaving for 96e0 message */
        register float f0 __asm__("$f0") = farg * 0.2f;
        register void *p7b0 __asm__("$3") = g_ovl_dat_7b0;
        register float f1 __asm__("$f1") = 1.0f;
        register void **v0 __asm__("$2") = m0 + 4;
        *(void *volatile *)&m0[4] = p384;
        *(float *)(ctx + 376) = f1;
        v0[4] = p7b0;
        p7e0 = g_ovl_dat_7e0;
        *(volatile float *)(ctx + 380) = f0;
        *(void *volatile *)&m0[9] = p336;
        *(volatile float *)(ctx + 368) = f1;
        *(volatile float *)(ctx + 372) = f1;
        *(void *volatile *)&v0[1] = g_ovl_dat_a08;
        *(void *volatile *)&v0[2] = p7e0;
        m0[7] = p288;
        m16 = v0;
    }
    fn_ovl_96e0(m16);

    m0[0] = ctx + 32;
    m0[1] = g_ovl_dat_a28;
    m0[2] = p384;
    m0[3] = g_ovl_ptr_dc0c;
    m0[4] = g_ovl_dat_dbe0;
    m0[5] = 0;
    fn_ovl_b840(m0);

    m0[0] = p740;
    m0[1] = g_ovl_dat_a08;
    m0[2] = p7e0;
    m0[3] = p288;
    m0[4] = g_ovl_ptr_618;
    m0[5] = 0;
    fn_ovl_afd0(m0);

    m0[0] = p740;
    m0[1] = 0;
    fn_ovl_af98(m0);

    fn_sys_1c5e90(g_ovl_ptr_634, *(void **)(arg1 + 84), 32);

    *(float *)(ctx + 320) += (fn_sys_1aced8() - 0.99f) * 10.0f + (-5.0f);
    *(float *)(ctx + 324) += (fn_sys_1aced8() - 0.99f) * 4.0f + (-2.0f);
    *(float *)(ctx + 328) += (fn_sys_1aced8() - 0.99f) * 10.0f + (-5.0f);

    *(float *)(ctx + 724) = farg;
    *(void **)(ctx + 736) = arg1;
    *(int *)(ctx + 720) = 0;
    *(int *)(ctx + 728) = 0;
    *(int *)(ctx + 732) = 0;
}
