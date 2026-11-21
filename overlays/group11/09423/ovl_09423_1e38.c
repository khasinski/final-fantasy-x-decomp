typedef unsigned char u8;
typedef struct {
    u8 pad00[24];
    unsigned int state;
    u8 pad1c[16];
    int frame;
} Ovl9423Ctx;

typedef struct { void *a, *b, *c, *d; u8 e; u8 pad[3]; } Msg2758;
typedef struct { void *a, *b; } Msg2;
typedef struct { void *a, *b, *c; } Msg3;
typedef struct { void *a, *b, *c, *d, *e, *f; } Msg6;
typedef struct { void *a, *b; float c; } Msg6bd8;
typedef struct { void *a, *b; float c, d; } Msg6cb8;

extern void fn_ovl_2758(void *);
extern void fn_ovl_98f0(void *);
extern void fn_ovl_86a0(void *);
extern void fn_ovl_6aa8(void *);
extern void fn_ovl_7760(void *);
extern void fn_ovl_39f8(void *);
extern void fn_ovl_a858(void *);
extern void fn_ovl_c9b8(void *);
extern void fn_ovl_c148(void *);
extern void fn_ovl_c110(void *);
extern void fn_ovl_6bd8(void *);
extern void fn_ovl_7c30(void *);
extern void fn_ovl_8d78(void *);
extern void fn_ovl_6cb8(void *);
extern void fn_ovl_3790(void *);
extern void fn_ovl_da10(void *);
extern int fn_sys_1ce050(void *, int);
extern int fn_sys_1ce1a8(void *);

extern void *g_ovl_ptr_668;
extern void *g_ovl_ptr_66c;
extern u8 g_ovl_b_670;
extern void *g_ovl_ptr_ed7c;
extern u8 g_ovl_dat_ed50[];
extern u8 g_ovl_dat_790[];
extern u8 g_ovl_dat_7f0[];
extern u8 g_ovl_dat_820[];
extern u8 g_ovl_dat_a48[];
extern u8 g_ovl_dat_a68[];
extern u8 g_ovl_dat_a90[];
extern u8 g_ovl_dat_b50[];
extern u8 g_ovl_dat_1090[];
extern u8 g_ovl_dat_10d0[];
extern u8 g_ovl_dat_1120[];
extern u8 g_ovl_dat_1170[];
extern u8 g_ovl_dat_11c0[];
extern u8 g_ovl_dat_1220[];
extern u8 g_ovl_dat_1370[];
extern u8 g_ovl_dat_14c0[];
extern u8 g_ovl_dat_15c0[];
extern u8 g_ovl_dat_16c0[];
extern u8 g_ovl_dat_16f8[];

static __inline__ void call_2758(void *a, void *b, void *c, void *d, u8 e) { Msg2758 m; m.a=a; m.b=b; m.c=c; m.d=d; m.e=e; fn_ovl_2758(&m); }
static __inline__ void call_98f0(void *a, void *b) { Msg2 m; m.a=a; m.b=b; fn_ovl_98f0(&m); }
static __inline__ void call_86a0(void *a, void *b) { Msg2 m; m.a=a; m.b=b; fn_ovl_86a0(&m); }
static __inline__ void call_6aa8(void *a, void *b) { Msg2 m; m.a=a; m.b=b; fn_ovl_6aa8(&m); }
static __inline__ void call_7760(void *a, void *b) { Msg2 m; m.a=a; m.b=b; fn_ovl_7760(&m); }
static __inline__ void call_39f8(void *a, void *b) { Msg2 m; m.a=a; m.b=b; fn_ovl_39f8(&m); }
static __inline__ void call_a858(void *a, void *b, void *c, void *d, void *e, void *f) { Msg6 m; m.a=a; m.b=b; m.c=c; m.d=d; m.e=e; m.f=f; fn_ovl_a858(&m); }
static __inline__ void call_c9b8(void *a, void *b, void *c, void *d, void *e, void *f) { Msg6 m; m.a=a; m.b=b; m.c=c; m.d=d; m.e=e; m.f=f; fn_ovl_c9b8(&m); }
static __inline__ void call_c148(void *a, void *b, void *c, void *d, void *e, void *f) { Msg6 m; m.a=a; m.b=b; m.c=c; m.d=d; m.e=e; m.f=f; fn_ovl_c148(&m); }
static __inline__ void call_c110(void *a, void *b) { Msg2 m; m.a=a; m.b=b; fn_ovl_c110(&m); }
static __inline__ void call_6bd8(void *a, void *b, float c) { Msg6bd8 m; m.a=a; m.b=b; m.c=c; fn_ovl_6bd8(&m); }
static __inline__ void call_7c30(void *a, void *b, void *c) { Msg3 m; m.a=a; m.b=b; m.c=c; fn_ovl_7c30(&m); }
static __inline__ void call_8d78(void *a, void *b, void *c) { Msg3 m; m.a=a; m.b=b; m.c=c; fn_ovl_8d78(&m); }
static __inline__ void call_6cb8(void *a, void *b, float c, float d) { Msg6cb8 m; m.a=a; m.b=b; m.c=c; m.d=d; fn_ovl_6cb8(&m); }
static __inline__ void call_3790(void *a, void *b, void *c) { Msg3 m; m.a=a; m.b=b; m.c=c; fn_ovl_3790(&m); }

void ovl_09423_1e38(void **arg) {
    Ovl9423Ctx *ctx = (Ovl9423Ctx *)arg[1];
    void *m_end;

retry:
    switch (ctx->state) {
    case 0: {
        u8 *pb50 = g_ovl_dat_b50;
        u8 *pa48 = g_ovl_dat_a48;
        u8 *p1090 = g_ovl_dat_1090;
        u8 *p10d0 = g_ovl_dat_10d0;
        call_2758(pb50, pa48, g_ovl_ptr_66c, 0, 1);
        call_98f0(p1090, pa48);
        *(int *)(p1090 + 48) = 0x8000;
        *(u8 *)(p1090 + 52) = g_ovl_b_670;
        call_86a0(p10d0, pa48);
        *(u8 *)(p10d0 + 52) = g_ovl_b_670;
        call_6aa8(g_ovl_dat_a90, g_ovl_dat_a68);
        ctx->state = 10;
        break;
    }

    case 10: {
        u8 *p11c0 = g_ovl_dat_11c0;
        u8 *pa48 = g_ovl_dat_a48;
        u8 *pb50 = g_ovl_dat_b50;
        u8 *p1370 = g_ovl_dat_1370;
        u8 *p15c0 = g_ovl_dat_15c0;
        u8 *p1090 = g_ovl_dat_1090;
        u8 *p11f0 = p11c0 + 48;
        call_7760(p11c0, pa48);
        call_39f8(pb50 + 32, p11c0 + 32);
        call_7760(p11f0, pa48);
        *(float *)(p11f0 + 32) = 1.0f;
        *(float *)(p11f0 + 36) = 1.0f;
        *(float *)(p11f0 + 40) = 1.0f;
        *(float *)(p11f0 + 44) = 2.3f;
        call_a858(p1370, pa48, g_ovl_dat_820, p11c0, p1090, p11f0);
        *(u8 *)(p1370 + 332) = 1;
        call_c9b8(p15c0, g_ovl_dat_a68, p1370, g_ovl_ptr_ed7c, g_ovl_dat_ed50, 0);
        fn_sys_1ce050(*(void **)(pb50 + 116), 64);
        call_c148(g_ovl_dat_16c0, pa48, p1370, g_ovl_dat_790, g_ovl_ptr_668, 0);
        call_c110(g_ovl_dat_16c0, 0);
        {
            u8 *pa90 = g_ovl_dat_a90;
            *(float *)(pa90 + 108) = 0.1f;
            *(float *)(pa90 + 104) = 0.1f;
            *(float *)(pa90 + 100) = 0.1f;
            *(float *)(pa90 + 96) = 0.1f;
            *(float *)(pa90 + 56) = 0.1f;
            *(float *)(pa90 + 52) = 0.1f;
            *(float *)(pa90 + 48) = 0.1f;
            call_6bd8(pa90, 0, 0.07f);
        }
        ctx->state += 1;
        break;
    }

    case 11:
        if (fn_sys_1ce1a8(*(void **)(g_ovl_dat_b50 + 116)) != 0) {
            ctx->state = 20;
            goto retry;
        }
        break;

    case 20:
        fn_sys_1ce050(*(void **)(g_ovl_dat_b50 + 116), 24);
        ctx->state += 1;
        break;

    case 21: {
        u8 *pb50 = g_ovl_dat_b50;
        if (fn_sys_1ce1a8(*(void **)(pb50 + 116)) == 0) {
            break;
        }
        {
            u8 *p1170 = g_ovl_dat_1170;
            u8 *pa48 = g_ovl_dat_a48;
            u8 *p1220 = g_ovl_dat_1220;
            u8 *p1120 = g_ovl_dat_1120;
            u8 *p10d0 = g_ovl_dat_10d0;
            u8 *p14c0 = g_ovl_dat_14c0;
            call_7c30(p1170, pa48, pb50 + 32);
            *(u8 *)(p1170 + 68) = 6;
            *(float *)(p1170 + 52) = -0.1f;
            call_8d78(p1120, pa48, p10d0);
            *(float *)(p1120 + 52) = 1.2f;
            *(float *)(p1120 + 60) = 0.1f;
            call_a858(p1220, pa48, g_ovl_dat_820, p1170, g_ovl_dat_7f0, p1120);
            *(u8 *)(p1220 + 332) = 1;
            call_c9b8(p14c0, g_ovl_dat_a68, p1220, g_ovl_ptr_ed7c, g_ovl_dat_ed50, (void *)1);
            fn_sys_1ce050(*(void **)(pb50 + 116), 25);
            call_c148(g_ovl_dat_16f8, pa48, p1220, g_ovl_dat_790, g_ovl_ptr_668, (void *)1);
        call_c110(g_ovl_dat_16f8, 0);
        {
            u8 *pa90 = g_ovl_dat_a90;
            *(float *)(pa90 + 108) = 1.0f;
            *(float *)(pa90 + 104) = 1.0f;
            *(float *)(pa90 + 100) = 1.0f;
            *(float *)(pa90 + 96) = 1.0f;
            *(float *)(pa90 + 56) = 1.0f;
            *(float *)(pa90 + 52) = 1.0f;
            *(float *)(pa90 + 48) = 1.0f;
            call_6cb8(pa90, 0, 0.02f, 1.0f);
        }
        ctx->frame = 0;
        ctx->state += 1;
        break;
        }
    }

    case 22:
        if (ctx->frame < 30) {
            break;
        }
        call_3790(g_ovl_dat_b50 + 32, 0, (void *)20);
        ctx->frame = 0;
        ctx->state += 1;
        break;

    case 23:
        if (ctx->frame < 30) {
            break;
        }
        ctx->state = 10000;
        goto retry;

    case 10000:
        m_end = arg[0];
        fn_ovl_da10(&m_end);
        break;
    }
    ctx->frame += 1;
}
