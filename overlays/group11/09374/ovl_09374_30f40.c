typedef unsigned char u8;

extern void fn_ovl_30c58(void);
extern void fn_ovl_39b68(void *msg);
extern void fn_ovl_39f70(void *msg);
extern void fn_ovl_358d0(void *msg);
extern void fn_ovl_32858(void *msg);
extern void fn_ovl_38348(void *msg);
extern void fn_ovl_38310(void *msg);

extern u8 g_ovl_dat_750[];
extern u8 g_ovl_dat_768[];
extern u8 g_ovl_dat_7d0[];
extern void *g_ovl_ptr_370;
extern u8 g_ovl_dat_2ff0[];
extern u8 g_ovl_dat_540[];

static __inline__ void call_39b68(void *a, void *b, void *c) {
    void *m[3];
    m[0] = a;
    m[1] = b;
    m[2] = c;
    fn_ovl_39b68(m);
}

static __inline__ void call_39f70(void *a, void *b) {
    void *m[2];
    m[0] = a;
    m[1] = b;
    fn_ovl_39f70(m);
}

static __inline__ void call_358d0(void *a, void *b) {
    void *m[2];
    m[0] = a;
    m[1] = b;
    fn_ovl_358d0(m);
}

static __inline__ void call_32858(void *a, void *b) {
    void *m[2];
    m[0] = a;
    m[1] = b;
    fn_ovl_32858(m);
}

static __inline__ void call_38348(void *a, void *b, void *c, void *d, void *e, void *f) {
    /* DEBT(FAKE): pin v0 for 38348 message at 16(sp) */
    /* DEBT(ORDER): volatile store on m[0] preserves sw order for 38348 message */
    void *m[6];
    register void **v0 __asm__("$2") = m;
    *(void *volatile *)&m[0] = a;
    v0[1] = b;
    v0[2] = c;
    m[3] = d;
    m[4] = e;
    m[5] = f;
    fn_ovl_38348(v0);
}

static __inline__ void call_38310(void *a, void *b) {
    void *m[2];
    m[0] = a;
    m[1] = b;
    fn_ovl_38310(m);
}

void ovl_09374_30f40(u8 *ctx, int idx) {
    u8 *p5a0 = ctx + 1440;
    u8 *p768;
    u8 *p2ff0;

    call_39b68(ctx, (void *)fn_ovl_30c58, ctx);
    call_39f70(g_ovl_dat_750, ctx);

    p768 = g_ovl_dat_768;
    call_358d0(p5a0, p768);
    call_32858(g_ovl_dat_7d0 + idx * 160, ctx + 1472);

    {
        /* DEBT(FAKE): pin a2/v1 for 38348 message */
        /* DEBT(ORDER): volatile float store keeps 1.0f before 38348 message */
        register void *p370 __asm__("$6") = g_ovl_ptr_370;
        *(volatile float *)(ctx + 1484) = 1.0f;
        p2ff0 = g_ovl_dat_2ff0;
        {
            register void *p540 __asm__("$3") = g_ovl_dat_540;
            call_38348(p2ff0 + idx * 56, p768, p540, p5a0, p370, 0);
        }
    }
    call_38310(p2ff0 + idx * 56, 0);

    *(int *)(ctx + 2840) = idx;
    *(int *)(ctx + 2832) = 0;
    *(int *)(ctx + 2836) = 0;
}
